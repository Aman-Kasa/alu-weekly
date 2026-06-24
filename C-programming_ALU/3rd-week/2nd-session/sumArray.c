/*/////////In Pairs:

Using the previous slide's sample cal stack table as an excample (for
factoriall, fill in a call stack table for the sumArray funiction where array
has values 23, 45,12, 0, 45, 89 and its size is 6,

How to trace,

Write down each function call
Note the parameters passed at each step
Track when the function returns a value
Fill in a cal stack table (push when calling, pop when returning))
*////////

#include <stdio.h>  // Needed for printf()

int sumArray(int arr[], int size) {
    if (size == 0)
        return 0;
    else
        return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    int arr[] = {23, 45, 12, 0, 45, 89};
    int size = 6;

    int sum = sumArray(arr, size);

    printf("The sum of the array is: %d\n", sum);

    return 0;
}

