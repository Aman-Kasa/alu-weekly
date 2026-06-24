/**
 * Task:
 * Define a struct Student with id, name, and grade.
 * Create 3 student records, fill data manually or through user input,
 * and print all student information clearly.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * struct Student - represents a student
 * @id: student ID
 * @name: student name
 * @grade: student grade
 */
struct Student
{
    int id;
    char name[50];
    float grade;
};

/**
 * print_student - prints the information of a student
 * @s: pointer to a struct Student
 */
void print_student(struct Student *s)
{
    printf("🎓 ID: %d\n", s->id);
    printf("👤 Name: %s\n", s->name);
    printf("📊 Grade: %.2f\n", s->grade);
    printf("-------------------------\n");
}

/**
 * main - entry point
 */
int main(void)
{
    struct Student students[3]; // Array of 3 students
    int i;

    /* Fill student data manually or through user input */
    for (i = 0; i < 3; i++)
    {
        printf("Enter details for student %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]s", students[i].name); // Read string with spaces

        printf("Grade: ");
        scanf("%f", &students[i].grade);

        printf("\n");
    }

    /* Print all student information */
    printf("\n=== Student Records ===\n");
    for (i = 0; i < 3; i++)
        print_student(&students[i]);

    return 0;
}

