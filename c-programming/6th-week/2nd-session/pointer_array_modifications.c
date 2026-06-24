/*/////////////////////////////////////////////////////////////////////////////////////////////////////
Task:
1. Run the starter code and observe how *(ptr + i) modifies each element.
2. Apply different modifications using only pointer syntax:
   a. Multiply each element by 2
   b. Add 1 to every number
   c. Set all elements to 0 if they are even
   d. Add 5 to elements greater than 9
Note: Do NOT use array indexing (arr[i]); only pointers allowed.
*////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; // pointer to the first element

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // a. Multiply each element by 2
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = *(ptr + i) * 2;
    }
    printf("After multiplying by 2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // b. Add 1 to every number
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = *(ptr + i) + 1;
    }
    printf("After adding 1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // c. Set all elements to 0 if they are even
    for (int i = 0; i < 5; i++) {
        if (*(ptr + i) % 2 == 0) {
            *(ptr + i) = 0;
        }
    }
    printf("After setting even numbers to 0: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // d. Add 5 to elements greater than 9
    for (int i = 0; i < 5; i++) {
        if (*(ptr + i) > 9) {
            *(ptr + i) = *(ptr + i) + 5;
        }
    }
    printf("After adding 5 to elements > 9: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}

