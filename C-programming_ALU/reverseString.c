#include <stdio.h>
#include <string.h>

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    if (start >= end)      // Base case: reached the middle
        return;

    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the next inner pair
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "ALU";      // Example string
    int len = strlen(str);

    printf("Original string: %s\n", str);

    reverseString(str, 0, len - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
