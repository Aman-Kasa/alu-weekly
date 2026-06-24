/*/////////
  In Pairs:
  Write a recursive function to reverse a string (character array)
  Peer-to-peer review recommended:
    - One codes
    - One verifies base case and recursive case
*////////

#include <stdio.h>
#include <string.h>

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    // Base case: if start >= end, stop recursion
    if (start >= end)
        return;

    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[] = "HelloWorld"; // Example string
    int len = strlen(str);

    printf("Original string: %s\n", str);

    reverseString(str, 0, len - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}

