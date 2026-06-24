#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)calloc(5, sizeof(int)); // allocate memory for 5 ints and initialize to 0

    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Print the array
    printf("Array elements after calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory safely
    free(arr);
    arr = NULL; // avoid double-free

    return 0;
}
