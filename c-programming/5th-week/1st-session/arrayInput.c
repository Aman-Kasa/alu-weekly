/*/////////
  In Pairs:
  1. Declare an array to hold 5 integers
  2. Accept user input for each element
  3. Print all array elements to the console
*////////

#include <stdio.h>

int main() {
    int arr[5];  // Declare array of 5 integers

    // Accept user input
    for(int i = 0; i < 5; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print all array elements
    printf("Array elements are: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

