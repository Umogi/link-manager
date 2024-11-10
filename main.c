#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int tagCount;
    char **tags;
    char url[256];
} Link;

const char *tags[5];

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void searchName(Link* links, int count){
    char searcher[256];
    printf("Enter search term: ");
    scanf(" %255s", searcher);
    for(int i = 0; i < count; i++){
        if (strstr(links[i].url, searcher) != NULL){
            printf("%d. %s\n", i + 1, links[i].url);
            printf("Tag Count: %d\n", links[i].tagCount);
            for (int y = 0; y < links[i].tagCount; y++) {
                printf("   Tag %d: %s\n", y + 1, links[i].tags[y]);
            }
            printf("\n");
        }
    }

    char answer[12];
    printf("continue: ");
    scanf(" %11s", answer);

}

void searchTags(Link* links, int count){
    char searcher[256];
    printf("Enter tag term: ");
    scanf(" %255s", searcher);
    for(int i = 0; i < count; i++){
        for (int j = 0; j < links[i].tagCount; j++){
            if (strcmp(links[i].tags[j], searcher) == 0){
                printf("%d. %s\n", i + 1, links[i].url);
                printf("Tag Count: %d\n", links[i].tagCount);
                for (int y = 0; y < links[i].tagCount; y++) {
                    printf("   Tag %d: %s\n", y + 1, links[i].tags[y]);
                }
            printf("\n");
            } 
        }
        
    }

    char answer[12];
    printf("continue: ");
    scanf(" %11s", answer);

}

void displayLinks(Link* links, int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, URL: %s\n", links[i].id, links[i].url);
        printf("Tag Count: %d\n", links[i].tagCount);
        
        for (int y = 0; y < links[i].tagCount; y++) {
            printf("   Tag %d: %s\n", y + 1, links[i].tags[y]);
        }
        printf("\n");
    }

    char answer[12];
    printf("continue: ");
    scanf(" %11s", answer);
}

void SaveFileWriter(Link* links, int count) {
    const char *filename = "links.txt";

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", links[i].id, links[i].url);
        fprintf(file, "%d\n", links[i].tagCount);
        for (int j = 0; j < links[i].tagCount; j++){
            fprintf(file, "    %d %s\n", j + 1, links[i].tags[j]);
        }
    }

    fclose(file);
}

int LoadFileReader(Link* links) {
    const char *filename = "links.txt";
    if (!file_exists(filename)) {
        return 0;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d %255s", &links[count].id, links[count].url) == 2) {
        fscanf(file, "%d", &links[count].tagCount);

        links[count].tags = malloc(links[count].tagCount * sizeof(char *));
        
        for (int i = 0; i < links[count].tagCount; i++) {
            int y;
            char tag[256];
            fscanf(file, "    %d %255s", &y, tag);

            links[count].tags[i] = malloc(strlen(tag) + 1);
            strcpy(links[count].tags[i], tag);
        }

        count++;

        if (count >= 100) break;
    }

    fclose(file);
    return count;
}
void addLink(Link* links, int *count) {
    printf("Enter URL: ");
    scanf("%s", links[*count].url);
    links[*count].id = *count;
    links[*count].tagCount = 0;
    links[*count].tags = malloc(10 * sizeof(char *));

    printf("Press 0 to stop adding tags\n");

    while (1) {
        char tag[256];
        printf("Add tag: ");
        scanf("%255s", tag);

        if (strcmp(tag, "0") == 0) {
            break;
        }

        links[*count].tags[links[*count].tagCount] = malloc(strlen(tag) + 1);
        strcpy(links[*count].tags[links[*count].tagCount], tag);
        links[*count].tagCount++;
    }

    (*count)++;
    SaveFileWriter(links, *count);
}

int main() {
    Link links[100];
    int count = LoadFileReader(links);
    int choice;

    while (1) {
        printf("1. Add Link\n2. Display Links\n3. Search\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addLink(links, &count);
                break;
            case 2:
                displayLinks(links, count);
                break;
            case 3:
                
                printf("1. By name\n2. By tag\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        searchName(links, count);
                        break;
                    case 2:
                        searchTags(links, count);
                        break;
                }
            break;
        }
    }
}
