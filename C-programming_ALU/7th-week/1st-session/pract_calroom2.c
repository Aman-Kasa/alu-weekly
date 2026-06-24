#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)calloc(5, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // Prints array (should be all zeros)
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

