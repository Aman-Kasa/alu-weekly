#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    FILE *fp = fopen("students.bin", "rb");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    int recordNum;
    char choice = 'y';
    Student s;

    while (choice == 'y' || choice == 'Y') {
        printf("Enter the record number to read: ");
        scanf("%d", &recordNum);

        // Clear EOF flag before seeking
        clearerr(fp);

        // Move file pointer to the desired record
        fseek(fp, (recordNum - 1) * sizeof(Student), SEEK_SET);

        if (fread(&s, sizeof(Student), 1, fp) == 1) {
            printf("\nStudent %d details:\n", recordNum);
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("GPA: %.2f\n", s.gpa);
        } else {
            printf("Record not found.\n");
        }

        printf("\nDo you want to read another student? (y/n): ");
        scanf(" %c", &choice);
    }

    fclose(fp);
    return 0;
}

