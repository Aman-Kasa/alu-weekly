#include <stdio.h>

int main(void) {
    double num1, num2, result;
    char op;

    // Ask user for input
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op); // Note the space before %c to skip newline

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Perform calculation based on operator
    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0)
                result = num1 / num2;
            else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    // Print the result
    printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);

    return 0;
}

