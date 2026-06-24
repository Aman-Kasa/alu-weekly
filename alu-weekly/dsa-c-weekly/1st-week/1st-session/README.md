# Array Operations and Complexity Study

This session focuses on building a small array-based management program in C and analyzing the cost of searching within it. The implementation covers the core CRUD-style operations, while the accompanying reflection explains why linear search scales the way it does.

## Contents

| File | Purpose |
| --- | --- |
| `array_operations.c` | Final implementation with insert, delete, update, and search behavior |
| `source_code.c` | Starter code used before the functions were completed |
| `complexity_reflection.md` | Written analysis of the search algorithm and its time complexity |
| `array_operations` | Compiled executable for Linux or Unix systems |

## Features

- Insert elements at a specific index by shifting later values to the right.
- Delete elements by shifting the remaining values back into place.
- Update a value after validating the target index.
- Search for a value using linear search.

## Complexity Notes

Linear search is the main algorithm analyzed in this session.

- Best case: the value is found immediately at the first position.
- Average case: the value is found around the middle of the array.
- Worst case: the value is at the end of the array or not present at all.
- Time complexity: $O(n)$.

## Constraints

- Maximum size: 100 elements, defined by the `SIZE` macro.
- Safety checks are included to avoid invalid access and overflow during insert or delete operations.

## Build And Run

Compile the program with `gcc`:

```bash
gcc array_operations.c -o array_operations
./array_operations
```

## References

- Cormen, Leiserson, Rivest, and Stein, *Introduction to Algorithms*.
- Kernighan and Ritchie, *The C Programming Language*.
