#include <stdio.h>

int main() {
    int n = 10; // sum from 1 to n
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Iterative sum: %d\n", sum);
    return 0;
}

