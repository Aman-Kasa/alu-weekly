#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Prints array
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

