# C File Handling Project


--------------------------------------------------------------------------------------------------------------
\\/Discussion Topic: File Handling/\\
File handling is an essential aspect of C programming, allowing data to be stored and accessed efficiently. Discuss the significance of file handling in real-world applications and explain how C provides functionalities for managing files. Specifically, consider the following aspects: creating and storing data in files, opening and accessing stored data, closing files properly, reading from and writing to files, and deleting existing files. What challenges might arise when handling files in C, and how can they be mitigated?
------------------------------------------------------------------------------------------------------------------------



## Description
This demonstrates basic **file handling in C**, including creating, writing, reading, closing, and deleting a file. It also shows error handling to prevent issues when a file cannot be opened.

## File Operations in the Code
1. Create/Open File**: Using `fopen("example.txt", "w")`.
2. **Write Data**: Using fprintf().
3. **Close File**: Using fclose().
4. **Read Data**: Using fgets() and printing to console.
5. **Delete File**: Using remove().

## Compilation and Execution

### Linux / Mac
```bash
gcc file_handling.c -o file_handling
./file_handling

### Output 
------------------------------------------------------
```                                                  |
>>>> Contents of the file:                           |
>>>Hello, C File Handling!                           |
>>>This is a demonstration of file operations.       |
                                                     |
**File deleted successfully.**                       |
-----------------------------------------------------


