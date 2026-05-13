#include <stdio.h>

int main() {
    int num = 0;

    printf("Enter numbers (stop if >= 100):\n");
    scanf("%d", &num); // first user input

    while(num < 100) { // loop continues as long as num <= 100
        if(num > 0 && num % 2 == 0) {
            printf("Positive even number: %d\n", num);
        }
        scanf("%d", &num);  // read next number
    }

    printf("Program Stopped.\n"); // output
    return 0;
}
