#include <stdio.h>

int main() {
    int num = 0;

    printf("Enter numbers (stop if >= 100):\n");
    scanf("%d", &num);

    while(num < 100) {
        if(num > 0 && num % 2 == 0) {
            printf("Positive even number: %d\n", num);
        }
        scanf("%d", &num);
    }

    printf("Program stopped.\n");
    return 0;
}
