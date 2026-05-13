/*
Task:
Compile and run the code and note down your observations:

1. Does &arr[i] and ptr + i print the same address?
2. Is the memory step consistent (pattern in increment size)?
*/

#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50}; // Declare and initialize an array

    // Pointer to the first element of the array
    int *ptr = arr;  // equivalent to &arr[0]

    // Loop through the array
    for (int i = 0; i < 5; i++) {
     
        printf("Address using &arr[%d]: %p\n", i, (void*)&arr[i]);   // Print address using &arr[i]

        printf("Address using ptr + %d: %p\n", i, (void*)(ptr + i));  // Print address using pointer arithmetic

        printf("\n");
    }

    return 0;
}

