#include <stdio.h>

/*Task:

WriteaCprogram that:

1. Declares variable and a pointer tothat variable

2.Modify the variable's value using onlythe
pointer (not direct assighment)*////


int main(void)
{
    int a = 10;      // declare a variable
    int *p = &a;     // declare a pointer to the variable

    // Print original value
    printf("Original value of a: %d\n", a);

    // Modify the value of a using only the pointer
    *p = 42;

    // Print the modified value
    printf("Modified value of a via pointer: %d\n", a);

    return 0;
}

