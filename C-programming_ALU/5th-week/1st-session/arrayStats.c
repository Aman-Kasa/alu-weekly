/*/////////
  In Pairs:
  1. Accept array size N from the user
  2. Accept N array elements
  3. Find and print:
     - Maximum value
     - Minimum value
     - Average value
*////////

#include <stdio.h>

int main() {
    int N;

    // Ask user for array size
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];

    // Accept array elements
    for(int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Initialize max and min
    int max = arr[0];
    int min = arr[0];
    int sum = 0;

    // Calculate max, min, sum
    for(int i = 0; i < N; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
        sum += arr[i];
    }

    // Calculate average
    float avg = (float)sum / N;

    // Print results
    printf("\nMaximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Average value: %.2f\n", avg);

    return 0;
}

