#include <stdio.h>

int main(void)
{
    int a = 10;
    float b = 20.5;
    char c1 = 'A';
    char c2 = 'B';

    printf("Address of int a:   %p\n", (void *)&a);
    printf("Address of float b: %p\n", (void *)&b);
    printf("Address of char c1: %p\n", (void *)&c1);
    printf("Address of char c2: %p\n", (void *)&c2);

    return 0;
}

