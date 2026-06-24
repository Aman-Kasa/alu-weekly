#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function to print one student
void printStudent(Student *s) {
    printf("ID: %d, Name: %s, GPA: %.2f\n", s->id, s->name, s->gpa);
}

// Function to print all students
void printAllStudents(Student **students, int count) {
    if (count == 0) {
        printf("No students in the system.\n");
        return;
    }
    printf("\nAll Students:\n");
    for (int i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

// Function to update GPA of a student by ID
void updateGPA(Student **students, int count, int id, float new_gpa) {
    for (int i = 0; i < count; i++) {
        if (students[i]->id == id) {
            printf("Updating %s's GPA from %.2f to %.2f\n", students[i]->name, students[i]->gpa, new_gpa);
            students[i]->gpa = new_gpa;
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Main function
int main() {
    int maxStudents = 10; // initial capacity
    int studentCount = 0;
    Student **students = malloc(maxStudents * sizeof(Student*));

    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n2. Update Student GPA\n3. Print All Students\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 1) { // Add Student
            if (studentCount == maxStudents) { // expand array if needed
                maxStudents *= 2;
                students = realloc(students, maxStudents * sizeof(Student*));
            }
            students[studentCount] = malloc(sizeof(Student));
            printf("Enter student ID: ");
            scanf("%d", &students[studentCount]->id);
            getchar(); // consume newline
            printf("Enter full name: ");
            fgets(students[studentCount]->name, 50, stdin);
            students[studentCount]->name[strcspn(students[studentCount]->name, "\n")] = 0; // remove newline
            printf("Enter GPA: ");
            scanf("%f", &students[studentCount]->gpa);
            studentCount++;
            printf("Student added successfully!\n");
        }
        else if (choice == 2) { // Update GPA
            int id;
            float new_gpa;
            printf("Enter student ID to update GPA: ");
            scanf("%d", &id);
            printf("Enter new GPA: ");
            scanf("%f", &new_gpa);
            updateGPA(students, studentCount, id, new_gpa);
        }
        else if (choice == 3) { // Print all
            printAllStudents(students, studentCount);
        }
        else if (choice == 4) { // Exit
            printf("Exiting system.\n");
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    // Free memory
    for (int i = 0; i < studentCount; i++) {
        free(students[i]);
    }
    free(students);

    return 0;
}

