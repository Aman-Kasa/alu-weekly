#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 6

int main() {
    int n, i;
    char names[MAX_STUDENTS][50];
    float course1[MAX_STUDENTS], course2[MAX_STUDENTS];

    // Step 1: Number of students (3–6)
    do {
        printf("Enter number of students (3-6): ");
        scanf("%d", &n);
    } while(n < 3 || n > 6);

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Step 2: Enter details for each student
    for(i = 0; i < n; i++) {
        printf("\nEnter full name of student %d: ", i+1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // remove newline

        printf("Enter grade for Course 1: ");
        scanf("%f", &course1[i]);
        printf("Enter grade for Course 2: ");
        scanf("%f", &course2[i]);

        // Clear input buffer
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Step 3: Print all student details
    printf("\n=== Gradebook ===\n");
    printf("%-25s %-10s %-10s\n", "Student Name", "Course1", "Course2");
    for(i = 0; i < n; i++) {
        printf("%-25s %-10.2f %-10.2f\n", names[i], course1[i], course2[i]);
    }

    return 0;
}

