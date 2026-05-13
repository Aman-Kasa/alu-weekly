#include <stdio.h>

int main() {
    // Step 1: Declare and initialize the string "Hello"
    char greeting[] = "Hello";

    // Step 2: Prompt the user to input their name
    char name[50];  // Array to hold user input
    printf("Enter your name: ");
    scanf("%49s", name);  // read up to 49 characters safely

    // Step 3: Print "Hello, Name" in the console
    printf("%s, %s!\n", greeting, name);

    return 0;
}
