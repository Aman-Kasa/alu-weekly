#include <stdio.h>

int main() {
    FILE *fp;
    int n, i;
    char name[50];
    int grade;

    // Ask for number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Open file for writing
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Write data to file
    for (i = 1; i <= n; i++) {
        printf("\nStudent %d Name: ", i);
        scanf("%s", name); // single word input (e.g. Alice)
        printf("Student %d Grade: ", i);
        scanf("%d", &grade);

        fprintf(fp, "%s %d\n", name, grade); // save to file
    }

    fclose(fp);
    printf("\nData saved to students.txt\n");

    // Open file for reading
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nReading Data from File -\n\n");

    // Read data back and display
    while (fscanf(fp, "%s %d", name, &grade) == 2) {
        printf("Student: %s, Grade: %d\n", name, grade);
    }

    fclose(fp);
    return 0;
}

