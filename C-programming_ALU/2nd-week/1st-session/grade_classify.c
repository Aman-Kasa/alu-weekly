#include <stdio.h>

int main(void)
{
    int grade;

    printf("Enter a numeric grade (0-100): ");
    scanf("%d", &grade);

    if (grade < 0 || grade > 100)
    {
        printf("Invalid grade! Please enter a number between 0 and 100.\n");
        return 1;
    }

    if (grade >= 90)
        printf("Grade: A\n");
    else if (grade >= 75)
        printf("Grade: B\n");
    else if (grade >= 60)
        printf("Grade: C\n");
    else if (grade >= 50)
        printf("Grade: D\n");
    else
        printf("Grade: F\n");

    return 0;
}
