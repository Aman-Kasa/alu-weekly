#include <stdio.h>
#include <stdlib.h>

// Node representation using the Left-Child / Right-Sibling linked list approach
typedef struct Node {
    int data;
    struct Node* first_child;   // Pointer to the first child (linked list head)
    struct Node* next_sibling;  // Pointer to the next sibling in the linked list
} Node;

// Helper to allocate a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->first_child = NULL;
    newNode->next_sibling = NULL;
    return newNode;
}

// 1. SEARCH OPERATION (Depth-First Search traversal)
Node* search(Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;

    // First search down the child's branch
    Node* found = search(root->first_child, key);
    if (found != NULL) return found;

    // If not found, search across the sibling chain
    return search(root->next_sibling, key);
}

// 2. INSERT OPERATION
void insert(Node* root, int parentData, int newData) {
    Node* parent = search(root, parentData);
    if (parent == NULL) {
        printf("Parent %d not found. Cannot insert %d.\n", parentData, newData);
        return;
    }

    Node* newNode = createNode(newData);

    // If parent has no children yet, this becomes the first child
    if (parent->first_child == NULL) {
        parent->first_child = newNode;
    } else {
        // Otherwise, traverse to the end of the children's linked list
        Node* temp = parent->first_child;
        while (temp->next_sibling != NULL) {
            temp = temp->next_sibling;
        }
        temp->next_sibling = newNode; // Append to the linked list
    }
}

// Helper function to recursively free memory
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->first_child);
    freeTree(root->next_sibling);
    free(root);
}

// 3. DELETE OPERATION (Deletes a node and its entire sub-hierarchy)
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    // If the root node itself matches the key
    if (root->data == key) {
        freeTree(root->first_child);
        Node* nextRoot = root->next_sibling;
        free(root);
        return nextRoot;
    }

    Node* current = root->first_child;
    Node* prev = NULL;

    // Loop through the immediate children linked list
    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                root->first_child = current->next_sibling;
            } else {
                prev->next_sibling = current->next_sibling;
            }
            current->next_sibling = NULL;
            freeTree(current); // Free the deleted node and its children
            return root;
        }
        
        // Recursively check deeper levels
        deleteNode(current, key);
        prev = current;
        current = current->next_sibling;
    }
    return root;
}

// Visual presentation helper
void displayTree(Node* root, int level) {
    if (root == NULL) return;
    for (int i = 0; i < level; i++) printf("    ");
    printf("|-- %d\n", root->data);
    
    displayTree(root->first_child, level + 1);
    displayTree(root->next_sibling, level);
}

// TEST ENVIRONMENT
int main() {
    printf("--- Step 1: Initializing N-Ary Tree Root (10) ---\n");
    Node* root = createNode(10);

    printf("--- Step 2: Testing Scalability (Inserting multiple levels of nodes) ---\n");
    insert(root, 10, 20);
    insert(root, 10, 30);
    insert(root, 10, 40); // 10 now has 3 children (demonstrates N-ary scalability)
    
    insert(root, 20, 50);
    insert(root, 20, 60);
    insert(root, 30, 70);

    displayTree(root, 0);

    printf("\n--- Step 3: Testing Search Operation ---\n");
    Node* foundNode = search(root, 60);
    if (foundNode) printf("Search Result: Node %d was successfully located.\n", foundNode->data);

    printf("\n--- Step 4: Testing Delete Operation (Pruning Node 20 and its children) ---\n");
    root = deleteNode(root, 20);
    displayTree(root, 0);

    // Clean up memory
    freeTree(root);
    return 0;
}
