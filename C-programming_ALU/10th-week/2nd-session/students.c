#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

int main() {
    FILE *fp;
    int n, i;

    printf("How many students do you want to add? ");
    scanf("%d", &n);

    Student s[n];

    // Input student data
    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name); // Read full line including spaces
        printf("GPA: ");
        scanf("%f", &s[i].gpa);
    }

    // Open binary file for writing (overwrite if exists)
    fp = fopen("students.bin", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write all student records to file
    fwrite(s, sizeof(Student), n, fp);
    fclose(fp);

    printf("\n%d student records written to students.bin successfully.\n", n);

    // OPTIONAL: Append more students
    char choice;
    printf("\nDo you want to append more students? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("How many more students to append? ");
        int m;
        scanf("%d", &m);
        Student s_append[m];

        for (i = 0; i < m; i++) {
            printf("\nStudent %d\n", i + 1);
            printf("ID: ");
            scanf("%d", &s_append[i].id);
            printf("Name: ");
            scanf(" %[^\n]", s_append[i].name);
            printf("GPA: ");
            scanf("%f", &s_append[i].gpa);
        }

        fp = fopen("students.bin", "ab"); // Append mode
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        fwrite(s_append, sizeof(Student), m, fp);
        fclose(fp);

        printf("\n%d student records appended successfully.\n", m);
    }

    // Read and display all students
    fp = fopen("students.bin", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nAll students in file:\n");
    Student temp;
    while (fread(&temp, sizeof(Student), 1, fp)) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", temp.id, temp.name, temp.gpa);
    }
    fclose(fp);

    return 0;
}

