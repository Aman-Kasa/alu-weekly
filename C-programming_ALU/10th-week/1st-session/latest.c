#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student data
struct Student {
    char name[50];
    int grade;
};

void write_students_to_file() {
    struct Student s;
    FILE *fptr = NULL;  // Initialize to NULL
    int num, i;

    // Step 1: Get number of students with validation
    printf("Enter number of students: ");
    if (scanf("%d", &num) != 1 || num <= 0) {
        fprintf(stderr, "Error: Invalid number of students.\n");
        exit(EXIT_FAILURE);
    }
    getchar();  // Clear newline

    // Step 2: Open file for writing (DEFENSIVE)
    fptr = fopen("student.txt", "w");
    if (fptr == NULL) {
        perror("Error opening file for writing");  // System error
        exit(EXIT_FAILURE);
    }

    printf("=== Entering %d students ===\n", num);

    // Step 3: Input loop with validation
    for (i = 0; i < num; ++i) {
        printf("For student %d,\n", i + 1);
        printf("Enter name: ");
        while (getchar() != '\n');  // Clear buffer
        if (fgets(s.name, sizeof(s.name), stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read name.\n");
            fclose(fptr);
            exit(EXIT_FAILURE);
        }
        s.name[strcspn(s.name, "\n")] = '\0';  // Remove newline

        printf("Enter grade: ");
        if (scanf("%d", &s.grade) != 1) {
            fprintf(stderr, "Error: Invalid grade input.\n");
            getchar();  // Clear bad input
            fclose(fptr);
            exit(EXIT_FAILURE);
        }
        getchar();  // Clear newline

        // Step 4: Write with error check
        if (fprintf(fptr, "%s %d\n", s.name, s.grade) < 0) {
            perror("Error writing to file");
            fclose(fptr);
            exit(EXIT_FAILURE);
        }
    }

    // Step 5: Close file with check
    if (fclose(fptr) != 0) {
        perror("Error closing file after writing");
        exit(EXIT_FAILURE);
    }
    printf("\nStudent data successfully written to student.txt\n");
}

void read_students_from_file() {
    struct Student s;
    FILE *fptr = NULL;

    // Step 1: Open file for reading (DEFENSIVE)
    fptr = fopen("student.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file for reading");  // File may not exist
        return;  // Exit function, not program (caller handles)
    }

    printf("\n--- Student Data from student.txt ---\n");
    printf("Name\t\tGrade\n");
    printf("-------------------------------------\n");

    // Step 2: Read loop with validation
    int items_read;
    while ((items_read = fscanf(fptr, "%s %d", s.name, &s.grade)) == 2) {
        printf("%s\t\t%d\n", s.name, s.grade);
    }
    if (items_read == EOF) {
        // Normal end of file
    } else if (items_read != EOF) {
        fprintf(stderr, "Warning: Corrupted data at line: %s", s.name);
        // Continue to next iteration or handle as needed
    }

    // Step 3: Close file with check
    if (fclose(fptr) != 0) {
        perror("Error closing file after reading");
        exit(EXIT_FAILURE);
    }
    printf("-------------------------------------\n");
}

int main() {
    write_students_to_file();
    read_students_from_file();
    return EXIT_SUCCESS;
}
