#include <stdio.h>

/*////////////////////////////////////////////////
Task

Write a C program that keeps asking the user for
numbers and adds them up. Stop when the user
enters -1. Print the total sum

Pair Review: Run each other's code in pairs and
suggest improvements
*////////////////////////////////////////////////

int main(void) {
    int num;
    int total = 0;

    printf("Enter numbers to sum (enter -1 to stop):\n");

    while (1) {  // infinite loop until break
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1) {  // stop condition
            break;
        }

        total += num;  // add to total
    }

    printf("Total sum: %d\n", total);

    return 0;
}
