#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    FILE *fp = fopen("students.bin", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Student s[3] = {
        {1, "x", 3.5},
        {2, "y", 3.8},
        {3, "z", 3.2}
    };

    fwrite(s, sizeof(Student), 3, fp);
    fclose(fp);

    printf("3 student records written to students.bin\n");
    return 0;
}

