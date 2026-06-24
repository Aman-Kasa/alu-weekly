# Singly Linked List Implementation and Analysis

## 📌 Overview
This project demonstrates the implementation of a Singly Linked List in C, focusing on dynamic memory management (`malloc` and `free`) and the mathematical analysis of recursive structures.

## 💻 Implementation Details
The program follows the requirements to manage a dynamic list of integers.

### Core Features:
* **Dynamic Node Structure**: Created using `struct` with a data field and a pointer to the next node.
* **Insert Operation**: Efficiently adds 10 elements to the list.
* **Delete Operation**: Removes an element and releases memory using `free()`.
* **Traversal**: Prints the entire list to the console.

## 📊 Technical Q&A

### How does a linked list differ from arrays?
* **Memory Structure**: Arrays use a single contiguous block of memory, while linked list nodes are scattered.
* **Size Flexibility**: Arrays have a fixed size; linked lists grow and shrink dynamically.
* **Access Type**: Arrays allow random access, whereas linked lists require sequential traversal.

### Why use `malloc` and `free`?
* **Allocation**: `malloc` allocates memory at runtime for nodes as the list grows.
* **Deallocation**: `free` releases memory when a node is deleted to prevent memory leaks.

### Time Complexity Analysis
* **Adding in the Middle**: **O(n)** because you must traverse from the head to the specific position.
* **Adding at the Beginning**: **O(1)** because only pointers are updated; no traversal is required.

---

## 🔄 Recursion & Efficiency
In the context of algorithm analysis (referencing **CLRS**), we use summation series to understand recursive branching.

### The Summation Formula
For a recursive process that branches twice at each level (like a binary tree), the total number of operations is:
    \sum_{i=0}^{n} 2^i = 2^{n+1} - 1

* **Why 2?**: Represents binary branching (True/False or Left/Right child).
* **Proof**: Proven via the "Shift and Subtract" method, showing that the sum of all previous powers of two is always one less than the next power.

---

## 🛠️ Visualization & Tools
To better understand how the computer handles pointers and the call stack during recursion, use the following platform:

* **Visualizer**: [PythonTutor C Visualizer](https://pythontutor.com/c.html#mode=edit)
* **Instructions**: Paste the implementation code into the tool to watch the `heap` memory change as nodes are created and destroyed.

## 📖 References
* K.N. King, *C Programming: A Modern Approach* (Chapter 9 & 17)
* Cormen et al., *Introduction to Algorithms (CLRS)* (pp. 22-35)
