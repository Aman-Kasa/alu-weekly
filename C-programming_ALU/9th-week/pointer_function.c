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
    else
        return 0; 
}

int main() {
    
    int (*fp)(int, int);

    int x = 10, y = 5;

    fp = add;
    printf("Using pointer (add): %d\n", fp(x, y));
    printf("Direct call (add): %d\n\n", add(x, y));

    fp = subtract;
    printf("Using pointer (subtract): %d\n", fp(x, y));
    printf("Direct call (subtract): %d\n\n", subtract(x, y));

    fp = multiply;
    printf("Using pointer (multiply): %d\n", fp(x, y));
    printf("Direct call (multiply): %d\n\n", multiply(x, y));

    fp = divide;
    printf("Using pointer (divide): %d\n", fp(x, y));
    printf("Direct call (divide): %d\n", divide(x, y));

    return 0;
}

