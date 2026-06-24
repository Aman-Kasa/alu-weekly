#include <stdio.h>

int main() {
    int num, sum = 0;

    printf("Enter numbers to add (enter -1 to stop):\n");

    while (1) {  // infinite loop, will break manually
        scanf("%d", &num);

        if (num == -1) {
            break; // breaks when user enters -1
        }

        sum += num; // add to total
    }

    printf("Total sum = %d\n", sum);

    return 0;
}
