#include <stdio.h>

int main()
{
    int arr[5];  // statically allocated array

    // Initialize array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Prints array
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

