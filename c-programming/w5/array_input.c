#include <stdio.h>

int main(void) {
    int arr[5];  // 1. Declare an array of 5 integers
    int i;

    // 2. Accept user input
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 3. Print all elements and their addresses
    printf("\nArray elements and their addresses:\n");
    for (i = 0; i < 5; i++) {
        printf("arr[%d] = %d, Address: %p\n", i, arr[i], (void*)&arr[i]);
    }

    return 0;
}

