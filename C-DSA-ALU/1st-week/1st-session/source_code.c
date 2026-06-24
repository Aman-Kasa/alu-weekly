#include <stdio.h>

#define SIZE 100

// Function declaration and definition
void insertItem(int arr[], int *length, int value, int position);
void deleteItem(int arr[], int *length, int position);
void updateItem(int arr[], int length, int position, int newValue);
int searchItem(int arr[], int length, int value);

int main() {
    int arr[SIZE];
    int length = 0; // current number of elements
    int choice, value, position, newValue;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0 to %d): ", length);
                scanf("%d", &position);
                // Call the insert function here
                insertItem(arr, &length, value, position);
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", length - 1);
                scanf("%d", &position);
                // Call the delete function here
                deleteItem(arr, &length, position);
                break;

            case 3:
                printf("Enter position to update (0 to %d): ", length - 1);
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                // Call the update function here
                updateItem(arr, length, position, newValue);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                // Call the search function here
                position = searchItem(arr, length, value);
                if (position != -1)
                    printf("Item found at position %d.\n", position);
                else
                    printf("Item not found.\n");
                break;

            case 0:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
