/*/////////
  Calculate the sum of numbers from 1 to n
  Using both iterative and recursive approaches
  Students to observe:
    - Which version is easier to understand
    - Pros and cons of each
*////////

#include <stdio.h>

// Recursive function to calculate sum from 1 to n
int sumRecursive(int n) {
    if (n == 0)        // Base case
        return 0;
    else               // Recursive case
        return n + sumRecursive(n - 1);
}

int main() {
    int n = 10;        // Sum numbers from 1 to n

    // Iterative sum
    int sumIter = 0;
    for(int i = 1; i <= n; i++) {
        sumIter += i;
    }
    printf("Iterative sum from 1 to %d is: %d\n", n, sumIter);

    // Recursive sum
    int sumRec = sumRecursive(n);
    printf("Recursive sum from 1 to %d is: %d\n", n, sumRec);

    return 0;
}

