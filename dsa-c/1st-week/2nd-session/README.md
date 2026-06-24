# Singly Linked List and Recursion Notes

This session explores a singly linked list implementation in C and connects it with the ideas behind recursion and growth in algorithmic work. The code is designed to make pointer movement, heap allocation, and traversal easy to follow.

## Contents

| File | Purpose |
| --- | --- |
| `singly_linked_list.c` | Main linked list implementation |
| `singly_linkedlist_source_code.c` | Starter version of the program |
| `technical_analysis.md` | Written explanation of the design and complexity |
| `recursion_visualization.c` | Code used for pointer and recursion visualization |
| `recursion_visualization_platform.md` | Notes on using the visualizer |
| `singly_linked_list` | Compiled executable |

## What This Session Covers

- A node structure built with `struct` and a pointer to the next node.
- Insertion into a dynamic list.
- Deletion with proper memory cleanup using `free()`.
- Full traversal and printing of the list.
- Visual reasoning about recursive growth and heap changes.

## Why Linked Lists Matter

- Linked lists do not require a single contiguous block of memory.
- They can grow and shrink dynamically during program execution.
- Insertion and deletion are often easier to express with pointers than with array shifting.

## Complexity Highlights

- Insert at the beginning: $O(1)$.
- Insert in the middle: $O(n)$ due to traversal.
- Delete a node: $O(n)$ in the general case because the list must be searched first.

## Recursion Insight

For a process that branches twice at every level, the total number of nodes follows the series:

$$
\sum_{i=0}^{n} 2^i = 2^{n+1} - 1
$$

This is a useful model for understanding how recursive work can expand quickly.

## Visualization Tool

Use [PythonTutor C Visualizer](https://pythontutor.com/c.html#mode=edit) to step through the code and watch how the stack and heap change as nodes are created and removed.

## References

- K. N. King, *C Programming: A Modern Approach*
- Cormen et al., *Introduction to Algorithms (CLRS)*
