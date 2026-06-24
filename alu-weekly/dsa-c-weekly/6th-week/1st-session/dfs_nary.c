#include <stdio.h>
#include <stdlib.h>

// 1. STRUCTURE DEFINITIONS
struct Node {
    char data;                 // Identifier for the node (e.g., 'A')
    int num_children;          // How many children this node points to
    struct Node** children;    // Dynamically allocated array of child node pointers
};

// Helper function to create a new node cleanly
struct Node* createNode(char data, int num_children) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->num_children = num_children;
    
    if (num_children > 0) {
        newNode->children = (struct Node**)malloc(num_children * sizeof(struct Node*));
    } else {
        newNode->children = NULL; // Explicitly leaf node
    }
    return newNode;
}

// 2. RECURSIVE DFS PRE-ORDER FUNCTION
void dfs_preorder(struct Node* root) {
    // Base Case: If the node is NULL, return instantly
    if (root == NULL) {
        return;
    }

    // Pre-Order Action: Process the parent node first
    printf("%c ", root->data);

    // Recursive Case: Loop through and traverse all N children
    for (int i = 0; i < root->num_children; i++) {
        dfs_preorder(root->children[i]);
    }
}

// 3. TESTING ENVIRONMENT
int main() {
    /* Building the sample N-ary tree structure:
            A
         /  |  \
        B   C   D
       / \      |
      E   F     G
    */

    // Level 0: Allocate Root Node A (3 children)
    struct Node* root = createNode('A', 3);

    // Level 1: Allocate Nodes B, C, D
    struct Node* nodeB = createNode('B', 2); // 2 children (E, F)
    struct Node* nodeC = createNode('C', 0); // Leaf node
    struct Node* nodeD = createNode('D', 1); // 1 child (G)

    // Connect Level 1 nodes to Root
    root->children[0] = nodeB;
    root->children[1] = nodeC;
    root->children[2] = nodeD;

    // Level 2: Allocate Leaf Nodes E, F, G
    struct Node* nodeE = createNode('E', 0);
    struct Node* nodeF = createNode('F', 0);
    struct Node* nodeG = createNode('G', 0);

    // Connect Level 2 nodes to their respective parents
    nodeB->children[0] = nodeE;
    nodeB->children[1] = nodeF;
    nodeD->children[0] = nodeG;

    // Execute Traversal
    printf("Expected Output: A B E F C D G\n");
    printf("Actual Output:   ");
    dfs_preorder(root);
    printf("\n");

    // 4. CLEAN UP MEMORY (Crucial for system stability)
    free(nodeE); 
    free(nodeF); 
    free(nodeG);
    
    free(nodeB->children); 
    free(nodeB);
    
    free(nodeC);
    
    free(nodeD->children); 
    free(nodeD);
    
    free(root->children); 
    free(root);

    return 0;
}
