#include <stdio.h>
#include <string.h>

int main() {
    // Step 1: Predefined username and password
    char storedUsername[] = "Aman";
    char storedPassword[] = "1234";

    // Step 2: User input
    char username[50];
    char password[50];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // remove newline

    // Step 3: Compare input with stored credentials
    if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
        // Step 4: Success message
        printf("Login successful! Welcome, %s.\n", username);
    } else {
        // Step 4: Failure message
        printf("Login failed! Invalid username or password.\n");
    }

    return 0;
}

