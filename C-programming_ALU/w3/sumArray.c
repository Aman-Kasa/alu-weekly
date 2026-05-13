#include <stdio.h>

// Recursive function to sum elements of an array
int sumArray(int arr[], int size) {
    if (size == 0) {           // Base case numb
        return 0;
    } else {                   // Recursive case numb
        return arr[size - 1] + sumArray(arr, size - 1);
    }
}

int main() {
    int arr[] = {23, 45, 12, 0, 45, 89};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = sumArray(arr, size);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
