#include <stdio.h>
/*//////////////////////////////////////
Task

Write a C program that reads numbers. Print only
positive even numbers. Stop reading ifthe number > 100

Peer Review: In pairs, run each other's code and
offer suggestions for improvement.
*///////////////////////////////////////////

int main(void) {
    int num;

    printf("Enter numbers (stop if number >= 100):\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num >= 100) {  // stop condition
            break;
        }

        if (num > 0 && num % 2 == 0) {  // positive even check
            printf("Positive even number: %d\n", num);
        }
    }

    printf("Program stopped as number >= 100 was entered.\n");

    return 0;
}
