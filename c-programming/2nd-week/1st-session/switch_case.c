#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;

    // Prompt user for input
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Ask for operator
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);  // Notice the space before %c to consume any leftover newline

    // Perform operation using switch-case
    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
