#include <stdio.h>
#include <string.h>

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    // Base case: if start >= end, do nothing
    if (start >= end) {
        return;
    }

    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for inner substring
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "BREAKOUTROOMS";   // break out rooms character
    int length = strlen(str);       // length of 

    printf("Original string: %s\n", str);

    // Reverse the string
    reverseString(str, 0, length - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
