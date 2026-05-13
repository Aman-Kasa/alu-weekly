/*/////////
  Task:
  1. Store a predefined username and password
  2. Accept user input for username and password
  3. Compare input against stored credentials
  4. Print success or failure messages
*////////

#include <stdio.h>
#include <string.h>

int main() {
    // Predefined credentials
    char storedUsername[] = "admin";
    char storedPassword[] = "pass123";

    // Variables to hold user input
    char username[50];
    char password[50];

    // Accept username
    printf("Enter username: ");
    scanf("%49s", username);

    // Accept password
    printf("Enter password: ");
    scanf("%49s", password);

    // Compare input with stored credentials
    if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
        printf("Login successful! Welcome, %s.\n", username);
    } else {
        printf("Login failed! Invalid username or password.\n");
    }

    return 0;
}

