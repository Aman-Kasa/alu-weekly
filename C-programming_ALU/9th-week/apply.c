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
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

int apply(int (*operation)(int, int), int x, int y) {
    return operation(x, y);
}

int main() {
    
    printf("Add: %d\n", apply(add, 18, 5));
    printf("Subtract: %d\n", apply(subtract, 10, 5));
    printf("Multiply: %d\n", apply(multiply, 6, 7));
    printf("Divide: %d\n", apply(divide, 20, 4));
    printf("Divide by zero: %d\n", apply(divide, 10, 0));

    return 0;
}

