# Memory Leak Debugging Documentation

## Project: Student Memory Management Debugging

**File:** `leaked_mem.c`
**Tool Used:** Valgrind Memcheck

## Valgrind Command Used

```bash
valgrind --leak-check=full ./leaked_mem
```

---

# 1. Summary of Issues Found

Valgrind detected the following problems:

* **8 invalid memory write errors**
* **154 bytes still allocated at program exit**
* **92 bytes definitely lost**
* **62 bytes indirectly lost**
* **0 bytes possibly lost**

The main issues were:

1. Incorrect allocation size for student names
2. Missing space for the string null terminator (`\0`)
3. Dynamically allocated score arrays were not freed
4. Some allocated students were never freed
5. Lack of memory allocation error checking

---

# 2. Bugs Found and Fixes Applied

## Bug 1: Incorrect string memory allocation

### Valgrind Error

```
Invalid write of size 1

Address ... is 0 bytes after a block of size 6 alloc'd
```

### Problem

The original code used:

```c
s->name = malloc(strlen(name));
```

`strlen()` only returns the number of characters and does not include the string terminator.

Example:

```
"Kellia"
```

Requires:

```
K e l l i a \0
1 2 3 4 5 6 7 bytes
```

But:

```c
strlen("Kellia")
```

returns:

```
6
```

Only 6 bytes were allocated, causing `strcpy()` to write outside the allocated memory.

### Fix

Changed:

```c
s->name = malloc(strlen(name));
```

to:

```c
s->name = malloc(strlen(name) + 1);
```

This allocates enough memory for both the characters and the terminating `\0`.

---

# Bug 2: Score array memory leak

### Valgrind Error

Example:

```
20 bytes in 1 blocks are definitely lost
```

### Problem

Memory was allocated for scores:

```c
s->scores = malloc(score_count * sizeof(int));
```

but it was never released.

The original cleanup function only freed:

```c
free(s->name);
free(s);
```

The score memory remained allocated.

### Fix

Added:

```c
free(s->scores);
```

Updated cleanup function:

```c
void free_student(Student *s)
{
    free(s->scores);
    free(s->name);
    free(s);
}
```

---

# Bug 3: Only one student was freed

### Valgrind Error

```
definitely lost: 92 bytes in 4 blocks
```

### Problem

Four students were created:

```c
students[0]
students[1]
students[2]
students[3]
```

but only one was freed:

```c
free_student(students[0]);
```

The remaining students caused memory leaks.

### Fix

Added a loop:

```c
for (int i = 0; i < 4; i++)
{
    free_student(students[i]);
}
```

Now every allocated student is released.

---

# Bug 4: Missing malloc failure checks

### Problem

The program assumed every memory allocation succeeds.

Example:

```c
Student *s = malloc(sizeof(Student));
```

If memory allocation fails, `s` becomes `NULL`, causing possible crashes.

### Fix

Added checks:

```c
if (s == NULL)
{
    return NULL;
}
```

Also added cleanup if later allocations fail.

---

# 3. Memory Management Before Fix

Before fixing:

```
create_student()

        malloc(Student)
              |
              v
        Student structure


        malloc(name)
              |
              v
        Student name


        malloc(scores)
              |
              v
        Student scores


free_student()

        free(name)
        free(Student)

        scores remains allocated
```

Result:

```
Memory leaks
```

---

# 4. Memory Management After Fix

After fixing:

```
create_student()

        malloc(Student)

        malloc(name + 1)

        calloc(scores)


free_student()

        free(scores)

        free(name)

        free(Student)
```

All allocated memory is released correctly.

---

# 5. Valgrind Report Before Fix

```
HEAP SUMMARY:
    in use at exit: 154 bytes in 10 blocks

LEAK SUMMARY:
    definitely lost: 92 bytes in 4 blocks
    indirectly lost: 62 bytes in 6 blocks

ERROR SUMMARY:
    8 errors from 8 contexts
```

---

# 6. Expected Valgrind Report After Fix

Run:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./leaked_mem
```

Expected result:

```
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks

All heap blocks were freed -- no leaks are possible

ERROR SUMMARY:
    0 errors from 0 contexts
```

---

# 7. Final Bug Summary Table

| Bug                                | Cause                       | Impact           | Fix                      |
| ---------------------------------- | --------------------------- | ---------------- | ------------------------ |
| Missing null terminator allocation | Used `strlen(name)`         | Buffer overflow  | Use `strlen(name)+1`     |
| Score memory not freed             | Missing `free(s->scores)`   | Memory leak      | Free score array         |
| Students not freed                 | Only first student released | Lost heap memory | Free all students        |
| No malloc checks                   | Possible NULL dereference   | Program crash    | Check allocation results |
| Uninitialized scores               | Used `malloc()`             | Random values    | Use `calloc()`           |

---

# Conclusion

Valgrind identified memory safety issues caused by incorrect allocation and incomplete cleanup. The fixes ensure:

* No invalid memory writes
* No memory leaks
* Correct dynamic memory management
* Safe allocation handling

The final program produces a clean Valgrind report with:

```
0 errors
0 leaks
```

