#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for an N-Ary Tree Node
typedef struct Node {
    int data;
    struct Node* first_child;   // Pointer to the first child node
    struct Node* next_sibling;  // Pointer to the immediate sibling node
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

    // Search in the child subtree
    Node* found = search(root->first_child, key);
    if (found != NULL) return found;

    // Search in the sibling subtree
    return search(root->next_sibling, key);
}

// 2. INSERT OPERATION
// Inserts a new child under a specific parent node
bool insert(Node* root, int parentData, int newData) {
    // Find the parent node
    Node* parent = search(root, parentData);
    if (parent == NULL) {
        printf("Parent node %d not found! Cannot insert %d.\n", parentData, newData);
        return false;
    }

    Node* newNode = createNode(newData);

    // If parent has no children, make this the first child
    if (parent->first_child == NULL) {
        parent->first_child = newNode;
    } else {
        // Otherwise, traverse to the end of the children linked list
        Node* temp = parent->first_child;
        while (temp->next_sibling != NULL) {
            temp = temp->next_sibling;
        }
        temp->next_sibling = newNode;
    }
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
// Deletes a node and all of its descendants (subtree)
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    // Case 1: The root itself is the node to delete
    if (root->data == key) {
        // Free this entire tree branch
        // Note: In a complete application, you'd separate siblings before deleting,
        // but if the literal root is deleted, the entire tree structure changes.
        freeTree(root->first_child);
        Node* nextRoot = root->next_sibling;
        free(root);
        return nextRoot; 
    }

    // Traverse children to find if the target is an immediate child of the current root
    Node* current = root->first_child;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            // Found the node to delete among children
            if (prev == NULL) {
                // It's the first child
                root->first_child = current->next_sibling;
            } else {
                // It's a middle or last child
                prev->next_sibling = current->next_sibling;
            }
            
            // Disconnect siblings before freeing the target's internal subtree
            current->next_sibling = NULL; 
            freeTree(current);
            return root;
        }
        
        // Recurse into this child's own subtrees to see if target is deeper down
        deleteNode(current, key);
        
        prev = current;
        current = current->next_sibling;
    }

    return root;
}

// Helper function to print the tree hierarchically (for testing visual confirmation)
void printTree(Node* root, int depth) {
    if (root == NULL) return;

    // Print indentation based on depth
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("|-- %d\n", root->data);

    // Print children
    printTree(root->first_child, depth + 1);
    
    // Print siblings at the same depth level
    printTree(root->next_sibling, depth);
}

// --- Driver Program to Demonstrate Scalability and Testing ---
int main() {
    printf("Creating an N-Ary tree with Root (10)...\n");
    Node* root = createNode(10);

    // Testing Scalability: Inserting multiple varying children to form a complex N-Ary tree
    // Root children
    insert(root, 10, 20);
    insert(root, 10, 30);
    insert(root, 10, 40);

    // Sub-children under 20
    insert(root, 20, 50);
    insert(root, 20, 60);

    // Sub-children under 30
    insert(root, 30, 70);

    // Deeper sub-children under 50
    insert(root, 50, 80);
    insert(root, 50, 90);
    insert(root, 50, 100);

    printf("\n--- Initial N-Ary Tree Structure ---\n");
    printTree(root, 0);

    // Test Search Operation
    printf("\n--- Testing Search Operation ---\n");
    int target = 90;
    Node* searchResult = search(root, target);
    if (searchResult != NULL) {
        printf("Node %d found in the tree!\n", target);
    } else {
        printf("Node %d NOT found in the tree.\n", target);
    }

    target = 999; // Non-existent
    searchResult = search(root, target);
    if (searchResult != NULL) {
        printf("Node %d found in the tree!\n", target);
    } else {
        printf("Node %d NOT found in the tree.\n", target);
    }

    // Test Delete Operation (Deleting node 20 will remove 20, and all its children: 50, 60, 80, 90, 100)
    printf("\n--- Testing Delete Operation (Deleting Node 20 and its subtree) ---\n");
    root = deleteNode(root, 20);

    printf("\n--- Tree Structure After Deletion ---\n");
    printTree(root, 0);

    // Cleanup remaining tree memory
    freeTree(root);
    return 0;
}
