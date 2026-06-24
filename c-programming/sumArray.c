#include <stdio.h>

// Function to sum elements of an array recursively
int sumArray(int arr[], int size) {
    if (size == 0)          // Base case
        return 0;
    else
        return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}; // Array of size 6
    int size = 6;

    int sum = sumArray(arr, size);

    printf("The sum of the array is: %d\n", sum);

    return 0;
}
