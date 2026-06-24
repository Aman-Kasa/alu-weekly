#include <stdio.h>

int main(void)
{
    int N, i;
    int max, min, sum = 0;

    printf("Enter size of the array: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int arr[N]; /* Variable Length Array (allowed in C99) */

    /* Input array elements */
    printf("Enter %d integers:\n", N);
    for (i = 0; i < N; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    /* Initialize min and max with the first element */
    max = min = arr[0];

    for (i = 0; i < N; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        sum += arr[i];
    }

    printf("\nResults:\n");
    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);
    printf("Average value = %.2f\n", (float)sum / N);

    return 0;
}

