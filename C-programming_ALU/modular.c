#include <stdio.h>

// Function declaration
int add(int a, int b);

int main() {
    int a, b, sum;

    printf("Enter two numbers: \n");
    scanf("%d %d", &a, &b);

    sum = add(a, b);  // function call

    printf("The sum is: %d\n", sum);

    return 0;
}

// Function definition
int add(int a, int b) {
    int added = a + b;
    return added;
}

