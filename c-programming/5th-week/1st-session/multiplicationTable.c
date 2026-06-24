/*/////////
  Task:
  1. Take a number as input from the user
  2. Generate its multiplication table from 1 to 12
  3. Use a for loop to control repetition
*////////

#include <stdio.h>

int main() {
    int num;

    // Input from user
    printf("Enter a number to generate its multiplication table: ");
    scanf("%d", &num);

    printf("Multiplication table for %d:\n", num);

    // For loop to generate table from 1 to 12
    for(int i = 1; i <= 12; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}

