#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for an N-Ary Tree Node
typedef struct Node {
    int data;
    struct Node* first_child;   
    struct Node* next_sibling;  
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->first_child = NULL;
    newNode->next_sibling = NULL;
    return newNode;
}

// 1. SEARCH OPERATION (Depth-First Search)
Node* search(Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;

    Node* found = search(root->first_child, key);
    if (found != NULL) return found;

    return search(root->next_sibling, key);
}

// 2. INSERT OPERATION
bool insert(Node* root, int parentData, int newData) {
    Node* parent = search(root, parentData);
    if (parent == NULL) {
        printf("\n[ERROR] Parent node %d not found! Cannot insert %d.\n", parentData, newData);
        return false;
    }

    // Check if the value already exists to keep data unique (optional but good practice)
    if (search(root, newData) != NULL) {
        printf("\n[ERROR] Node with value %d already exists in the tree!\n", newData);
        return false;
    }

    Node* newNode = createNode(newData);

    if (parent->first_child == NULL) {
        parent->first_child = newNode;
    } else {
        Node* temp = parent->first_child;
        while (temp->next_sibling != NULL) {
            temp = temp->next_sibling;
        }
        temp->next_sibling = newNode;
    }
    printf("\n[SUCCESS] Node %d successfully inserted under parent %d.\n", newData, parentData);
    return true;
}

// Helper function to free an entire subtree memory
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->first_child);
    freeTree(root->next_sibling);
    free(root);
}

// 3. DELETE OPERATION
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (root->data == key) {
        printf("\n[SUCCESS] Deleting root node %d and its entire tree.\n", key);
        freeTree(root->first_child);
        Node* nextRoot = root->next_sibling;
        free(root);
        return nextRoot; 
    }

    Node* current = root->first_child;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                root->first_child = current->next_sibling;
            } else {
                prev->next_sibling = current->next_sibling;
            }
            current->next_sibling = NULL; 
            freeTree(current);
            printf("\n[SUCCESS] Node %d and its subtree deleted successfully.\n", key);
            return root;
        }
        
        deleteNode(current, key);
        prev = current;
        current = current->next_sibling;
    }

    return root;
}

// Helper function to print the tree hierarchically
void printTree(Node* root, int depth) {
    if (root == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("|-- %d\n", root->data);

    printTree(root->first_child, depth + 1);
    printTree(root->next_sibling, depth);
}

// --- INTERACTIVE MENU DRIVER ---
int main() {
    int rootValue;
    printf("=========================================\n");
    printf("      N-ARY TREE INITIALIZATION          \n");
    printf("=========================================\n");
    printf("Enter the value for the ROOT node: ");
    if (scanf("%d", &rootValue) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    Node* root = createNode(rootValue);
    int choice, parentVal, childVal, searchVal, deleteVal;

    while (1) {
        printf("\n=========================================\n");
        printf("              N-ARY TREE MENU            \n");
        printf("=========================================\n");
        printf("1. Insert a Node\n");
        printf("2. Search for a Node\n");
        printf("3. Delete a Node (and its Subtree)\n");
        printf("4. Display Tree Structure\n");
        printf("5. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Cleaning up and exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the PARENT node value: ");
                scanf("%d", &parentVal);
                printf("Enter the NEW child node value to insert: ");
                scanf("%d", &childVal);
                insert(root, parentVal, childVal);
                break;

            case 2:
                printf("Enter node value to SEARCH for: ");
                scanf("%d", &searchVal);
                if (search(root, searchVal) != NULL) {
                    printf("\n[FOUND] Node %d exists in the tree.\n", searchVal);
                } else {
                    printf("\n[NOT FOUND] Node %d does not exist in the tree.\n", searchVal);
                }
                break;

            case 3:
                printf("Enter node value to DELETE: ");
                scanf("%d", &deleteVal);
                if (search(root, deleteVal) == NULL) {
                    printf("\n[ERROR] Node %d does not exist.\n", deleteVal);
                } else {
                    if (root != NULL && root->data == deleteVal) {
                        root = deleteNode(root, deleteVal);
                        printf("\nThe entire tree was cleared. Exiting program.\n");
                        return 0;
                    } else {
                        root = deleteNode(root, deleteVal);
                    }
                }
                break;

            case 4:
                printf("\n--- Current N-Ary Tree Structure ---\n");
                if (root == NULL) {
                    printf("(Tree is empty)\n");
                } else {
                    printTree(root, 0);
                }
                break;

            case 5:
                printf("Freeing memory and exiting. Goodbye!\n");
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }

    freeTree(root);
    return 0;
}
