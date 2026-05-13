#include <stdio.h>

int main() {
    int number;

    // Step 1: Take input from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Step 2 & 3: Generate multiplication table using a for loop
    printf("Multiplication table of %d:\n", number);
    for (int i = 1; i <= 12; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}

