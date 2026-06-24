#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int age;
    int active;
} Record;

Record records[MAX_RECORDS];
int recordCount = 0;

void displayData();
void updateEntry();
void deleteRecord();
void exitProgram();

void (*menu[4])() = {displayData, updateEntry, deleteRecord, exitProgram};

void displayData() {
    printf("\n--- Displaying Data ---\n");
    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].active) {
            printf("Record %d: Name = %s, Age = %d\n", i, records[i].name, records[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("No active records found.\n");
    }
}

void updateEntry() {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more.\n");
        return;
    }

    int index;
    printf("Enter record index (0-%d): ", MAX_RECORDS-1);
    if (scanf("%d", &index) != 1 || index < 0 || index >= MAX_RECORDS) {
        printf("Invalid index.\n");
        while(getchar() != '\n');
        return;
    }

    printf("Enter name: ");
    while(getchar() != '\n');
    fgets(records[index].name, NAME_LEN, stdin);
    records[index].name[strcspn(records[index].name, "\n")] = 0;

    printf("Enter age: ");
    if (scanf("%d", &records[index].age) != 1) {
        printf("Invalid age.\n");
        while(getchar() != '\n');
        return;
    }

    records[index].active = 1;
    if (index >= recordCount) recordCount = index + 1;
    printf("Record updated successfully.\n");
}

void deleteRecord() {
    int index;
    printf("Enter record index to delete (0-%d): ", recordCount-1);
    if (scanf("%d", &index) != 1 || index < 0 || index >= recordCount) {
        printf("Invalid index.\n");
        while(getchar() != '\n');
        return;
    }

    if (!records[index].active) {
        printf("Record already deleted.\n");
        return;
    }

    records[index].active = 0;
    printf("Record deleted successfully.\n");
}

void exitProgram() {
    printf("Exiting program. Goodbye!\n");
    exit(0);
}

int main() {
    int choice;

    do {
        printf("\n--- Menu ---\n");
        printf("0. Display Data\n");
        printf("1. Update Entry\n");
        printf("2. Delete Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        if (choice >= 0 && choice <= 3) {
            menu[choice]();
        } else {
            printf("Invalid choice. Try again.\n");
        }

    } while (1);

    return 0;
}

