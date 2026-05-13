/*/////////
  Task:
  1. Read a string using scanf()
  2. Read a string using fgets()
  3. Print both captured strings
  4. Compare behavior, especially with spaces
*////////

#include <stdio.h>

int main() {
    char str1[100];
    char str2[100];

    // 1. Using scanf()
    printf("Enter a string using scanf(): ");
    scanf("%99s", str1);  // Stops at first whitespace
    printf("Captured using scanf(): %s\n", str1);

    // Clear input buffer before fgets()
    int c; while ((c = getchar()) != '\n' && c != EOF);

    // 2. Using fgets()
    printf("Enter a string using fgets(): ");
    fgets(str2, sizeof(str2), stdin);  // Reads entire line including spaces
    printf("Captured using fgets(): %s\n", str2);

    return 0;
}

