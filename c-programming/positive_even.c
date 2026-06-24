#include <stdio.h>

int main() {
    int num;

    printf("Enter numbers (stop if >= 100):\n");

    while(1) {
        scanf("%d", &num);

        if(num >= 100) {
            break; 
        }

        if(num > 0 && num % 2 == 0) {
            printf("Positive even number: %d\n", num);
        }
    }

    printf("Program stopped.\n");
    return 0;
}
