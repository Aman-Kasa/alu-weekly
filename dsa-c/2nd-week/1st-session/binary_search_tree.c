#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST (Smaller -> Left, Larger -> Right)
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal: Left, Root, Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal: Root, Left, Right
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal: Left, Right, Root
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // 1. Define the original array
    int values[] = {8, 3, 10, 1, 6, 14};
    int n = sizeof(values) / sizeof(values[0]);

    // 2. Print the original array at the very top
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
    }
    printf("\n--------------------------------\n");

    // 3. Build the Binary Search Tree
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // 4. Print the traversals
    printf("In-order Traversal:   ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal:  ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
