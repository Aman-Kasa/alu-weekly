#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Huffman Tree Node
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Helper function to create a new tree node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Manually builds the decoding key tree framework
struct Node* buildTree() {
    struct Node* root = createNode('$');         
    struct Node* internalNode = createNode('$'); 
    
    struct Node* leafA = createNode('a');
    struct Node* leafN = createNode('n');
    struct Node* leafB = createNode('b');

    // Setup paths: Left = 0, Right = 1
    root->right = leafA;             // 'a' is reached via: 1
    root->left = internalNode;       
    
    internalNode->left = leafB;      // 'b' is reached via: 00
    internalNode->right = leafN;     // 'n' is reached via: 01

    return root;
}

// DECODING ENGINE: Converts your typed 0s and 1s into alphabets
void decodeBitsToAlphabets(struct Node* root, const char* binaryString) {
    struct Node* current = root;
    int validFlag = 1;

    printf("Decoded Alphabets Result: ");
    
    for (int i = 0; binaryString[i] != '\0'; i++) {
        // Validation: skip spaces or accidental newlines
        if (binaryString[i] == ' ' || binaryString[i] == '\n') continue;

        // Catch non-binary inputs
        if (binaryString[i] != '0' && binaryString[i] != '1') {
            printf("\n[Error: Invalid character '%c' detected! Only enter 0s and 1s.]\n", binaryString[i]);
            validFlag = 0;
            break;
        }

        // Branch traversal navigation
        if (binaryString[i] == '0') {
            current = current->left;
        } else if (binaryString[i] == '1') {
            current = current->right;
        }

        // If a leaf node is reached, print the alphabet letter and reset to top
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root; // Reset back to root for the next character sequence
        }
    }
    
    // Catch incomplete paths
    if (validFlag && current != root) {
        printf("... [Warning: The bitstream ended on an incomplete path branch]");
    }
    printf("\n");
}

int main() {
    struct Node* root = buildTree();
    char userBitstream[1000];

    printf("--- Interactive Huffman Bitstream Decoder ---\n");
    printf("Dictionary Key Map: [ b = 00 ]  [ n = 01 ]  [ a = 1 ]\n");
    printf("------------------------------------------------------\n");
    
    // Prompts user for live input tracking
    printf("Enter a stream of 0s and 1s to turn into words:\n> ");
    if (fgets(userBitstream, sizeof(userBitstream), stdin) == NULL) {
        return 1;
    }
    
    // Strip trailing newline character if present
    userBitstream[strcspn(userBitstream, "\n")] = 0;

    // Run translation logic
    decodeBitsToAlphabets(root, userBitstream);

    return 0;
}
