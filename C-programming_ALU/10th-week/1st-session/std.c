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
    FILE *fptr;
    int num, i;

    // Open the file in write mode ("w")
    fptr = fopen("student.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    printf("Enter number of students: ");
    scanf("%d", &num);

    for (i = 0; i < num; ++i) {
        printf("For student %d,\n", i + 1);
        printf("Enter name: ");
        // Clear input buffer before reading string to avoid issues with previous scanf
        while (getchar() != '\n'); 
        fgets(s.name, sizeof(s.name), stdin);
        // Remove the newline character added by fgets
        s.name[strcspn(s.name, "\n")] = 0; 

        printf("Enter grade: ");
        scanf("%d", &s.grade);

        // Write data to the file in a formatted way
        fprintf(fptr, "%s %d\n", s.name, s.grade);
    }

    fclose(fptr);
    printf("\nStudent data successfully written to student.txt\n");
}

void read_students_from_file() {
    struct Student s;
    FILE *fptr;

    // Open the file in read mode ("r")
    fptr = fopen("student.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file for reading or file does not exist!\n");
        return;
    }

    printf("\n--- Student Data from student.txt ---\n");
    printf("Name\t\tGrade\n");
    printf("-------------------------------------\n");

    // Read data back from the file using fscanf in a loop
    while (fscanf(fptr, "%s %d", s.name, &s.grade) == 2) {
        printf("%s\t\t%d\n", s.name, s.grade);
    }

    fclose(fptr);
    printf("-------------------------------------\n");
}

int main() {
    write_students_to_file();
    read_students_from_file();

    return 0;
}
