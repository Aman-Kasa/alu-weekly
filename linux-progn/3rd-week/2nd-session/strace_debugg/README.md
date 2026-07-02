# Debugging Worksheet: System Call Analysis with `strace`

This worksheet documents low-level diagnostic tracing and system call analysis performed on three test programs using the Linux `strace` utility. The objective is to correlate user-space program execution with the corresponding kernel-level system calls.

---

# Case Study 1: `program1.c` (Missing File Target)

## 1. Compilation
```bash
gcc -o program1 program1.c
```

## 2. Tracing Command
```bash
strace -e trace=file ./program1
```

## 3. Failing System Call and Error Code

**Failing System Call**
```text
openat(AT_FDCWD, "/nonexistent/file.txt", O_RDONLY)
```

**Kernel Error**
```text
-1 ENOENT (No such file or directory)
```

## 4. Correlation with Program Behavior

When `fopen()` is called in the source code, the C standard library invokes the `openat()` system call with the `O_RDONLY` flag. Since the directory `/nonexistent/` does not exist in the Linux Virtual File System (VFS), the kernel returns `-1` and sets `errno` to `ENOENT`.

The program checks whether the returned file pointer is `NULL` using:

```c
if (!fp)
```

Since the file cannot be opened, `perror("Error")` prints a human-readable description of the kernel error.

## 5. Documented Finding

The program terminates normally with exit code `0`, but its primary operation fails gracefully because the required file does not exist.

---

# Case Study 2: `program2.c` (Permission Violation Target)

## 1. Compilation
```bash
gcc -o program2 program2.c
```

## 2. Tracing Command
```bash
strace -e trace=file ./program2
```

## 3. Failing System Call and Error Code

**Failing System Call**
```text
openat(AT_FDCWD, "/root/secret.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)
```

**Kernel Error**
```text
-1 EACCES (Permission denied)
```

## 4. Correlation with Program Behavior

The program opens a file using write mode (`"w"`). Internally, the C library issues an `openat()` system call with the flags:

- `O_WRONLY`
- `O_CREAT`
- `O_TRUNC`

Although the path exists, the Linux kernel verifies the process's effective user ID (UID) and file permissions. Because the program is executed as a normal user rather than the root user, the kernel denies access and returns the `EACCES` error.

As a result, `fopen()` returns `NULL`, causing the program to execute:

```c
perror("Permission denied");
```

## 5. Documented Finding

The application behaves correctly but lacks sufficient permissions to create or modify files inside the protected `/root` directory.

---

# Case Study 3: `program3.c` (Memory Access Violation)

## 1. Compilation
```bash
gcc -o program3 program3.c
```

## 2. Tracing Command
```bash
strace -e trace=file ./program3
```

## 3. Failure Information

**Failing System Call**

None. The crash occurs entirely in user-space before any additional file-related system calls are made.

**Kernel Signal**
```text
--- SIGSEGV {si_signo=SIGSEGV, si_code=SEGV_MAPERR, si_addr=NULL} ---
```

**Process Termination**
```text
+++ killed by SIGSEGV (core dumped) +++
```

## 4. Correlation with Program Behavior

The program executes:

```c
printf("%s\n", ptr);
```

where `ptr` is a `NULL` pointer.

To print the string, `printf()` attempts to dereference the pointer and read memory starting at address `0x0`. This address is not mapped into the process's virtual address space.

The CPU's Memory Management Unit (MMU) detects the invalid memory access and raises a page fault. The Linux kernel converts this hardware exception into a `SIGSEGV` signal with the code `SEGV_MAPERR`, immediately terminating the process.

## 5. Documented Finding

The application terminates due to a null pointer dereference. The kernel sends a segmentation fault (`SIGSEGV`), preventing the program from continuing execution. No additional system calls are executed after the fault occurs.

---

# Summary

| Program | Failure | Kernel Response |
|---------|---------|-----------------|
| `program1` | Missing file | `ENOENT` (No such file or directory) |
| `program2` | Permission denied | `EACCES` (Permission denied) |
| `program3` | Null pointer dereference | `SIGSEGV (SEGV_MAPERR)` |
