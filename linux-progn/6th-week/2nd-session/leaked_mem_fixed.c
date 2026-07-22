#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int *scores;
    int count;
} Student;


/**
 * create_student - allocate and initialize student
 * @name: student name
 * @score_count: number of scores
 *
 * Return: pointer to new student
 */
Student *create_student(char *name, int score_count)
{
    Student *s;

    s = malloc(sizeof(Student));

    if (s == NULL)
        return NULL;

    s->name = malloc(strlen(name) + 1);

    if (s->name == NULL)
    {
        free(s);
        return NULL;
    }

    strcpy(s->name, name);

    s->scores = calloc(score_count, sizeof(int));

    if (s->scores == NULL)
    {
        free(s->name);
        free(s);
        return NULL;
    }

    s->count = score_count;

    return s;
}


/**
 * free_student - free student memory
 * @s: student pointer
 */
void free_student(Student *s)
{
    if (s == NULL)
        return;

    free(s->scores);
    free(s->name);
    free(s);
}


int main(void)
{
    Student *students[4];

    students[0] = create_student("Kellia", 5);
    students[1] = create_student("Keny", 3);
    students[2] = create_student("Aubin", 4);
    students[3] = create_student("Collettee", 4);


    for (int i = 0; i < 4; i++)
    {
        free_student(students[i]);
    }

    return 0;
}
