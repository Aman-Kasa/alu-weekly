#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDER 4 // Max children = 4, Max keys = 3

typedef struct BPlusNode {
    bool is_leaf;
    int num_keys;
    int keys[ORDER];                // Overallocated by 1 to temporarily hold overflow
    struct BPlusNode* children[ORDER + 1]; // Overallocated to handle overflow during split
    struct BPlusNode* next;         // Linked-list pointer for leaf nodes
} BPlusNode;

// Helper to create a new node
BPlusNode* create_node(bool is_leaf) {
    BPlusNode* node = (BPlusNode*)malloc(sizeof(BPlusNode));
    node->is_leaf = is_leaf;
    node->num_keys = 0;
    node->next = NULL;
    for (int i = 0; i < ORDER + 1; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Core Logic: Splitting a child node that has overflowed
void split_child(BPlusNode* parent, int idx, BPlusNode* child) {
    int mid = ORDER / 2;
    BPlusNode* new_node = create_node(child->is_leaf);

    if (child->is_leaf) {
        // --- LEAF SPLIT ---
        // 1. Copy the right half of keys to the new leaf node
        new_node->num_keys = child->num_keys - mid;
        for (int i = 0; i < new_node->num_keys; i++) {
            new_node->keys[i] = child->keys[mid + i];
        }
        child->num_keys = mid;

        // 2. Maintain the leaf linked-list chain
        new_node->next = child->next;
        child->next = new_node;

        // 3. Bring a COPY of the first key of the right node up to the parent
        for (int i = parent->num_keys; i > idx; i--) {
            parent->keys[i] = parent->keys[i - 1];
        }
        parent->keys[idx] = new_node->keys[0];
    } 
    else {
        // --- INTERNAL SPLIT ---
        // 1. Copy the right half of keys and children to the new internal node
        new_node->num_keys = child->num_keys - mid - 1; // -1 because median moves up completely
        for (int i = 0; i < new_node->num_keys; i++) {
            new_node->keys[i] = child->keys[mid + 1 + i];
        }
        for (int i = 0; i <= new_node->num_keys; i++) {
            new_node->children[i] = child->children[mid + 1 + i];
        }
        child->num_keys = mid;

        // 2. PUSH UP the median key to the parent (it leaves the child node completely)
        for (int i = parent->num_keys; i > idx; i--) {
            parent->keys[i] = parent->keys[i - 1];
        }
        parent->keys[idx] = child->keys[mid];
    }

    // Insert the new child pointer into the parent's child array
    for (int i = parent->num_keys + 1; i > idx + 1; i--) {
        parent->children[i] = parent->children[i - 1];
    }
    parent->children[idx + 1] = new_node;
    parent->num_keys++;
}

// Helper function to insert into a non-full node
void insert_non_full(BPlusNode* node, int key) {
    int i = node->num_keys - 1;

    if (node->is_leaf) {
        // Shift keys to insert the new key in sorted order
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        // Find which child gets the key
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++; // Index of the correct child

        // If that child is full, split it first
        if (node->children[i]->num_keys == ORDER - 1) {
            split_child(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insert_non_full(node->children[i], key);
    }
}

// Global root pointer wrapper for simplicity
BPlusNode* root = NULL;

void insert(int key) {
    if (root == NULL) {
        root = create_node(true);
        root->keys[0] = key;
        root->num_keys = 1;
        return;
    }

    // If the root is full, the entire tree grows upwards
    if (root->num_keys == ORDER - 1) {
        BPlusNode* new_root = create_node(false);
        new_root->children[0] = root;
        split_child(new_root, 0, root);
        root = new_root;
    }

    insert_non_full(root, key);
}

// Print function to visualize the tree layers
void display(BPlusNode* node, int level) {
    if (node == NULL) return;
    
    printf("Level %d: [", level);
    for (int i = 0; i < node->num_keys; i++) {
        printf("%d", node->keys[i]);
        if (i < node->num_keys - 1) printf(", ");
    }
    printf("] %s\n", node->is_leaf ? "(Leaf)" : "(Internal)");

    if (!node->is_leaf) {
        for (int i = 0; i <= node->num_keys; i++) {
            display(node->children[i], level + 1);
        }
    }
}

int main() {
    printf("--- Building B+ Tree in C (Order %d) ---\n\n", ORDER);

    // 1. Fill a single leaf node
    insert(10);
    insert(20);
    insert(30);
    printf("Initial full leaf structure:\n");
    display(root, 0);

    // 2. Trigger a Leaf Split by adding a 4th element
    printf("\n--- Inserting 40 (Triggers LEAF SPLIT) ---\n");
    insert(40);
    display(root, 0);

    // 3. Trigger an Internal Split by cascading keys up
    printf("\n--- Inserting 50, 60, 70 (Triggers INTERNAL SPLIT) ---\n");
    insert(50);
    insert(60);
    insert(70);
    display(root, 0);

    return 0;
}
