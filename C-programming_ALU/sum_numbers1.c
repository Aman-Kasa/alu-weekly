#include <stdio.h>

int main() {
    int num = 0, sum = 0;

    printf("Enter numbers to add (enter -1 to stop):\n");

    scanf("%d", &num); // first input before loop
    while (num != -1) { // loop continues only if num is not -1
        sum += num;      // add to total
        scanf("%d", &num); // read next number
    }

    printf("Total sum = %d\n", sum);

    return 0;
}
