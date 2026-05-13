#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[100];

    // 1. Create/Open a file for writing
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    // 2. Write to the file
    fprintf(fp, "Hello, C File Handling!\n");
    fprintf(fp, "This is a demonstration of file operations.\n");

    // 3. Close the file after writing
    fclose(fp);

    // 4. Open the file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    // 5. Read from the file and print to console
    printf("Contents of the file:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // 6. Close the file after reading
    fclose(fp);

    // 7. Delete the file (optional)
    if (remove("example.txt") == 0) {
        printf("\nFile deleted successfully.\n");
    } else {
        printf("\nFailed to delete the file.\n");
    }

    return EXIT_SUCCESS;
}

