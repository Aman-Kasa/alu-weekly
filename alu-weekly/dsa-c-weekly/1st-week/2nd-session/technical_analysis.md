# Singly Linked List: Technical Analysis

### 1. How does a linked list differ from arrays?
*   **Memory Structure**: Arrays use a single contiguous block of memory, while linked list nodes are scattered in memory.
*   **Size Flexibility**: Arrays have a fixed size; linked lists grow and shrink dynamically.
*   **Access Type**: Arrays allow random access, whereas linked lists require sequential traversal starting from the head node.

### 2. Why are we adding dynamic memory functions (`malloc` and `free`)?
*   **Allocation**: `malloc` is used to allocate memory for nodes at runtime as the list grows.
*   **Deallocation**: `free` is used to release memory when a node is deleted to prevent memory leaks.

### 3. What is the time complexity for adding a node in the middle?
*   **Complexity**: O(n).
*   **Reasoning**: You must traverse the list node-by-node from the head to reach the specific middle position before the insertion can occur.

### 4. What is the time complexity if you add an element at the beginning?
*   **Complexity**: O(1).
*   **Reasoning**: No traversal or shifting of elements is required; you only need to update the new node's `next` pointer and the `head` pointer.
