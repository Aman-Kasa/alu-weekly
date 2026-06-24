#include <stdio.h>

// Recursive factorial function
int factorial(int n) {
    if (n == 0)  // Base case
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num = 3;
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
