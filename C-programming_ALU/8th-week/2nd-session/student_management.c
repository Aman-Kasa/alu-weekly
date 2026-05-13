#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

void printStudent(Student *s) {
    printf("ID: %d, Name: %s, GPA: %.2f\n", s->id, s->name, s->gpa);
}

void printAllStudents(Student **students, int count) {
    printf("\nAll Students:\n");
    for (int i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

void updateGPA(Student *s, float new_gpa) {
    printf("Updating %s's GPA from %.2f to %.2f\n", s->name, s->gpa, new_gpa);
    s->gpa = new_gpa;
}

int main() {
    int maxStudents = 5; // max capacity for demo
    int studentCount = 0;

    // dynamically allocate array of pointers to Student
    Student **students = malloc(maxStudents * sizeof(Student*));

    // Add first student
    students[studentCount] = malloc(sizeof(Student));
    students[studentCount]->id = 1;
    strcpy(students[studentCount]->name, "Mr.x");
    students[studentCount]->gpa = 3.9;
    studentCount++;

    // Add second student
    students[studentCount] = malloc(sizeof(Student));
    students[studentCount]->id = 2;
    strcpy(students[studentCount]->name, "Mr.y");
    students[studentCount]->gpa = 3.7;
    studentCount++;

    printAllStudents(students, studentCount);

    // Update GPA of first student
    updateGPA(students[0], 4.0);

    printAllStudents(students, studentCount);

    // Free memory
    for (int i = 0; i < studentCount; i++) {
        free(students[i]);
    }
    free(students);

    return 0;
}

