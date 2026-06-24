#include <stdio.h>

// Define the structure
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Function to update GPA
void updateGPA(struct Student *s) {
    float new_gpa;

    printf("Current GPA of %s (ID: %d): %.2f\n", s->name, s->id, s->gpa);

    printf("Enter new GPA: ");
    scanf("%f", &new_gpa);

    s->gpa = new_gpa;

    printf("Updated GPA of %s (ID: %d): %.2f\n", s->name, s->id, s->gpa);
}

// Main function to test
int main(void) {
    struct Student s1 = {101, "xxx", 4.8};

    updateGPA(&s1);

    return 0;
}

