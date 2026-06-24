#include <stdio.h>

int sumRecursive(int n) {
    if (n == 0) {      // Base case
        return 0;
    } else {           // Recursive case
        return n + sumRecursive(n - 1);
    }
}

int main() {
    int n = 10;
    int sum = sumRecursive(n);
    printf("Recursive sum: %d\n", sum);
    return 0;
}
