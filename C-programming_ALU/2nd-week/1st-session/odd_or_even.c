#include <stdio.h>

int main(void)
{
    int n;

    /* Ask user for a number */
    printf("Enter a number: ");
    scanf("%d", &n);

    /* Check if the number is even or odd */
    if (n % 2 == 0)
        printf("%d is even\n", n);
    else
        printf("%d is odd\n", n);

    return 0;
}
