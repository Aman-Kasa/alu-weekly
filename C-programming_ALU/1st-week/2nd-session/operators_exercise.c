#include <stdio.h>
/*///////////////////////////////////////////
Task
Write a C program that:

1.Declare two integersa and band assign
themvalues

2. Performs the following:
	a.Arithmetic: add, subtract, multiply the two integers
	b.Relational: checkifais greater thanb
	C.Logical: Check if both a and b are positive
	d. Assignment: Use +=toincreaseaby5
	e. Bitwise:show a&b,a|b and a^b

3. Print the result of each operation
*//////////////////////////////////////////

int main(void) {
    // 1. Declare two integers
    int a = 10, b = 5;

    // 2a. Arithmetic operations
    printf("Arithmetic Operations:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);

    // 2b. Relational operation
    printf("\nRelational Operation:\n");
    if (a > b)
        printf("a (%d) is greater than b (%d)\n", a, b);
    else
        printf("a (%d) is not greater than b (%d)\n", a, b);

    // 2c. Logical operation
    printf("\nLogical Operation:\n");
    if (a > 0 && b > 0)
        printf("Both a (%d) and b (%d) are positive\n", a, b);
    else
        printf("Either a or b is not positive\n");

    // 2d. Assignment operation
    printf("\nAssignment Operation:\n");
    a += 5;  // Increase a by 5
    printf("a after a += 5 is %d\n", a);

    // 2e. Bitwise operations
    printf("\nBitwise Operations:\n");
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);

    return 0;
}
