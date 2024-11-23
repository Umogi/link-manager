# Link Manager

Link Manager is a simple C-based program for managing links and their associated tags. You can add links with descriptive tags, save them to a file, and perform searches based on tags or keywords in the link URLs.

## Features
- Add Links: Enter URLs and assign multiple tags to each link.
- Search by URL: Search links based on keywords found within the URL.
- Search by Tags: Find links based on tags associated with each URL.
- Save & Load: Save links and tags to a file and reload them on program start.

## Getting Started
### Prerequisites
- A C compiler, such as `gcc`, to compile the program.

### Compilation

To compile the program, use the following command:
```
gcc link_manager.c -o link_manager
```

Running the Program
After compiling, run the program with:
```
./link_manager
```

## Usage
The program displays a main menu with the following options:

1. Add Link: Add a new URL with optional tags. Enter "0" when you are done adding tags.
2. Display Links: View all stored links and their associated tags.
3. Search:
   - By URL: Enter a keyword to search within the URLs.
   - By Tag: Enter a tag to find all associated URLs.

## Saving and Loading
- Links and tags are automatically saved to `links.txt` after each addition.
- On startup, `links.txt` is loaded if it exists, allowing continuity across sessions.

## File Structure
The links and tags are stored in 'links.txt' in a human-readable format. Each link entry includes:

- `ID`: The unique identifier for each link.
- `URL`: The URL of the link.
- `Tag Count`: The number of tags associated with the link.
- `Tags`: The list of tags associated with the URL.

Example:

```
1 https://example.com
2
    1 tag1
    2 tag2
```

## Code Overview
- Structures:
    - `Link`: Holds information about each link, including `id`, `url`, `tagCount`, and `tags`.
- Functions:
    - addLink: Adds a new link and tags.
    - searchName: Searches for links containing a specific keyword in the URL.
    - searchTags: Searches for links by specific tags.
    - displayLinks: Displays all saved links with their tags.
    - SaveFileWriter: Writes link data to links.txt.
    - LoadFileReader: Loads link data from links.txt.

## Example Usage
```
1. Add Link
2. Display Links
3. Search
Enter your choice: 1

Enter URL: https://example.com
Press 0 to stop adding tags
Add tag: tutorial
Add tag: C_programming

1. Add Link
2. Display Links
3. Search
Enter your choice: 2

ID: 0, URL: https://example.com
Tag Count: 2
   Tag 1: tutorial
   Tag 2: C_programming
```
## Contributing
Feel free to fork the repository and submit pull requests for improvements or additional features.

## License
This project is open-source and available under the MIT [LICENSE](LICENSE).

