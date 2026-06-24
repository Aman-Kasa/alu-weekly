#include <stdio.h>

int main() {
    char str1[50];
    char str2[50];

    // --------- Method 1: scanf() -----------
    printf("Enter a string using scanf(): ");
    scanf("%49s", str1);  // stops at space
    printf("You entered (scanf): %s\n", str1);

    // Clear input buffer to avoid leftover newline
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // --------- Method 2: fgets() -----------
    printf("Enter a string using fgets(): ");
    fgets(str2, sizeof(str2), stdin);  // reads whole line including spaces
    printf("You entered (fgets): %s", str2); // fgets keeps the newline

    return 0;
}

