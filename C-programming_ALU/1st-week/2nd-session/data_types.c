#include <stdio.h>
///////////////////////////////////////////
Task
>>Declare one ariable of each data type:char,int, float, double, long
>>Assign Values to each
>>Print them using the correct format specifiers

//////////////////////////////////////

int main(void) {
    // 1. Declare variables of different data types
    char c = 'A';          // character
    int i = 100;           // integer
    float f = 3.14f;       // floating-point number
    double d = 3.141592;   // double-precision floating-point
    long l = 1234567890;   // long integer

    // 2. Print each variable using the correct format specifier
    printf("Character: %c\n", c);      // %c for char
    printf("Integer: %d\n", i);        // %d for int
    printf("Float: %f\n", f);          // %f for float
    printf("Double: %lf\n", d);        // %lf for double
    printf("Long: %ld\n", l);          // %ld for long

    return 0;
}
