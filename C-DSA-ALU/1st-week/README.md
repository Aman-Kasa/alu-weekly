# Array Operations & DSA Complexity Project

This project demonstrates fundamental array-based operations (CRUD) and provides a performance analysis of searching algorithms in C. The codebase was developed collaboratively, divided into functional groups as per the assignment instructions.

## 📂 Project Structure

*   **`array_operations.c`**: The final, complete source code containing all implemented CRUD operations.
*   **`source_code.c`**: The initial boilerplate code used as a starting point before function implementation.
*   **`complexity_reflection.md`**: A detailed analysis of the search algorithm's time complexity.
*   **`array_operations`**: The compiled executable file for Linux/Unix systems.

---

## 👥 Group Responsibilities

the project functions are divided as follows:

### Group 1: Structural Operations
*   **`insertItem`**: Responsible for adding elements at a specific index by shifting existing elements to the right.
*   **`deleteItem`**: Responsible for removing elements and shifting subsequent elements to the left to fill the gap.

### Group 2: Data Retrieval & Modification
*   **`updateItem`**: Modifies the value of an element at a verified index.
*   **`searchItem`**: Implements a Linear Search to find the index of a specific value within the array.

---

## 📊 Performance Analysis (Linear Search)

Based on the requirements, the searching algorithm performs as follows:

*   **Best Case**: Finding the element at the **first position** requires only **1 operation**.
*   **Middle Case**: Finding an element in the **middle** requires approximately **n/2 operations**.
*   **Worst Case**: Finding an element at the **end** (or not finding it at all) requires **n operations**.
*   **Big O Notation**: The algorithm has a complexity of **O(n)**, known as Linear Time Complexity.

---

## 📚 References & Literature

This project was developed using the following core texts for algorithmic logic and C implementation:

1.  **Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).** *Introduction to Algorithms* (3rd ed.). MIT Press. 
    *   **pp. 22–35**: Covers the foundations of algorithm analysis, insertion sort logic (relevant to element shifting), and the growth of functions (Big O notation).

2.  **Kernighan, B. W., & Ritchie, D. M. (1988).** *The C Programming Language* (2nd ed.). Prentice Hall.
    *   **pp. 110–122**: Covers Pointers and Arrays, addressing how arrays are passed to functions and the relationship between pointers and array indexing—critical for the `insertItem` and `deleteItem` implementations.

---

## 🛠 Compilation and Usage

To compile the program from the source code, use a C compiler like `gcc`:

```bash
gcc array_operations.c -o array_operations

---

## To run the programm
./array_operations
--------------------------------------------------------


## 📝 Constraints

** Maximum Size: 100 elements (Defined via SIZE macro).

** Safety: The program includes bounds checking to prevent inserting into a full array or accessing invalid memory positions.

------------------------------------//-------------------------------------------
