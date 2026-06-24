#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return (b != 0) ? (a / b) : 0;
}

int main() {
    int num1, num2, choice;

    
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};


    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Choose operation:\n");
    printf("0 - Add\n1 - Subtract\n2 - Multiply\n3 - Divide\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    
    if (choice >= 0 && choice <= 3) {
        int result = operations[choice](num1, num2);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return (b != 0) ? (a / b) : 0;
}
