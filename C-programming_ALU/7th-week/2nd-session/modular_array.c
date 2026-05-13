#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for an array
int* allocateArray(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return arr;
}

// Function to input array elements
void inputArray(int *arr, int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(int *arr, int n) {
    printf("\nYou entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to free allocated memory
void freeArray(int *arr) {
    free(arr);
}

int main() {
    int n;
    int *numbers;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    numbers = allocateArray(n);
    inputArray(numbers, n);
    displayArray(numbers, n);
    freeArray(numbers);

    printf("Memory freed successfully. Program finished.\n");
    return 0;
}

