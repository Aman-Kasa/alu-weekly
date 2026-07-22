#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int *scores;
    int count;
} Student;

Student* create_student(char *name, int score_count) {
    Student *s = malloc(sizeof(Student));
    s->name = malloc(strlen(name));
    strcpy(s->name, name);
    s->scores = malloc(score_count * sizeof(int));
    s->count = score_count;
    return s;
}

void free_student(Student *s) {
    free(s->name);
    free(s);
}

int main() {
    Student *students[4];

    students[0] = create_student("Kellia", 5);
    students[1] = create_student("Keny", 3);
    students[2] = create_student("Aubin", 4);
    students[3] = create_student("Collettee", 4);

    free_student(students[0]);

    return 0;
}
