#include <stdio.h>
#include <stdlib.h>

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

// Manually builds the exact tree structure to map our bits back to alphabets
struct Node* buildTree() {
    struct Node* root = createNode('$');         // Root Node
    struct Node* internalNode = createNode('$'); // Internal branch node
    
    // Create alphabet leaf nodes
    struct Node* leafA = createNode('a');
    struct Node* leafN = createNode('n');
    struct Node* leafB = createNode('b');

    // Attach nodes to match the paths:
    // Left branch = 0, Right branch = 1
    root->right = leafA;             // 'a' path is just: 1
    root->left = internalNode;       // Left branch leads to the rest
    
    internalNode->left = leafB;      // 'b' path is: 00
    internalNode->right = leafN;     // 'n' path is: 01

    return root;
}

// DECODING ENGINE: Turns the 0s and 1s into alphabets
void decodeBitsToAlphabets(struct Node* root, const char* binaryString) {
    struct Node* current = root;

    printf("Decoded Word: ");
    
    // Read the bitstream string character by character
    for (int i = 0; binaryString[i] != '\0'; i++) {
        
        if (binaryString[i] == '0') {
            current = current->left;    // Move down the left branch
        } else if (binaryString[i] == '1') {
            current = current->right;   // Move down the right branch
        }

        // Check if we hit a leaf node (contains actual alphabet data)
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data); // Output the decoded alphabet
            current = root;              // Reset back to the top of the tree!
        }
    }
    printf("\n");
}

int main() {
    // This string of bits represents "banana" based on our tree map:
    // b = 00, a = 1, n = 01, a = 1, n = 01, a = 1
    const char* bitStream = "001011011";

    printf("--- Huffman Bitstream to Alphabet Decoder ---\n");
    printf("Input Bit Stream Code: %s\n", bitStream);
    printf("Dictionary Key Mapping: [b = 00]  [n = 01]  [a = 1]\n\n");

    // Build our decoding tree framework
    struct Node* root = buildTree();

    // Run the engine to turn the bits back into words
    decodeBitsToAlphabets(root, bitStream);

    // Free allocated memory
    // (In a full lab assignment you would clean up your tree branches here)
    
    return 0;
}
