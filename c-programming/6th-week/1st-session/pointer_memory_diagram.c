/*
Task:
Draw a memory diagram based on a simple pointer program you wrote earlier.
Diagram must show:
 - Variables
 - Their memory addresses
 - Pointers pointing to variables
 - Changes in values (if any)

Pair Sharing:
In pairs, explain your diagram and note:
 - What each box represents
 - How the pointer connects to a variable
 - How values change through dereferencing
*/

#include <stdio.h>

int main(void) {
    int a = 10;     // variable a
    int *p;         // pointer p

    p = &a;         // p points to a

    printf("Before change:\n");
    printf("a = %d\n", a);
    printf("Address of a (&a) = %p\n", (void*)&a);
    printf("p (value) = %p\n", (void*)p);
    printf("*p = %d\n\n", *p);

    *p = 20;        // change value of a using pointer

    printf("After change:\n");
    printf("a = %d\n", a);
    printf("Address of a (&a) = %p\n", (void*)&a);
    printf("p (value) = %p\n", (void*)p);
    printf("*p = %d\n", *p);

    return 0;
}

