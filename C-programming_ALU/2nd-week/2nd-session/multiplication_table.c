#include <stdio.h>

//////////////////////////*
Task

Write a C program that:

1.Takes a number as input from the user
2.Generates its multiplication table from to 12
3.Uses a for loop to control repetition

**////////////////////



int main(void) {
    int num;

    // Take input from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Multiplication table for %d:\n", num);

    // Generate multiplication table from 1 to 12
    for (int i = 1; i <= 12; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
