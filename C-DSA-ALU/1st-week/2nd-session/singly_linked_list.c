#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Define the node structure
struct Node {
    int data;           // Concept (a): Each node contains data
    struct Node* next;  // Concept (a): Pointer to the next node
};

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head; // Start from head
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; // Traversal
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    // c. Implement insert (10 elements)
    for (int i = 1; i <= 10; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Concept (b): malloc
        newNode->data = i * 10;
        newNode->next = head; // Inserting at the beginning for O(1) efficiency
        head = newNode;
    }
    printf("After inserting 10 elements:\n");
    printList(head);

    // c. Implement delete (1 element - deletes the head for simplicity)
    if (head != NULL) {
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete); // Concept (b): free function
    }
    
    printf("\nAfter deleting 1 element:\n");
    printList(head);

    return 0;
}
