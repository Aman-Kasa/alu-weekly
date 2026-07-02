# Strace Debugging Investigation — Programs 1 & 2

## Source Code

### Program 1 — `1st-programm.c` (parent_child_bug.c)

### Program 2 — `2nd-programm.c`

```c
```
---

## Initial Analysis

### Program 1 — Predicted Issues

1. `pipe(pipefd)` return value is not checked. If it fails, `pipefd[0]`/`pipefd[1]` are garbage, and every subsequent syscall using them fails with `EBADF`.
2. In the child branch: `close(pipefd[0])` is called **twice**, and `pipefd[1]` (the write end) is **never closed** by the child.
3. Consequence: the child leaves its write-end reference open. In this specific single-write program the parent's `read()` still returns because the parent's own write-end copy was closed — but the pattern is unsafe: if this code were extended (loops, multiple children, or a reader waiting for EOF from *all* writers), the read could block forever waiting for EOF that never comes.
4. The second `close(pipefd[0])` operates on an already-closed fd — a double-close, which will fail (`EBADF`) and is wasted/undefined-ish behavior.

**Hypothesis for `strace -f -tt -T -o trace_A.log ./prog1`:**
- `pipe(...)` succeeds, returns two fds (typically 3 and 4)
- Child (after `fork`): `close(3)`, `write(4, "Hello", 5)`, then a second `close(3)` returning **-1 EBADF**
- Parent: `close(4)`, `read(3, ..., 10)` returning 5, `wait4(...)`

### Program 2 — Predicted Issues

1. `open("/etc/passwd", O_RDONLY)` is called 1000 times in a loop; `close(fd)` is **never called**.
2. Each successful open consumes a file-descriptor slot. Default soft `RLIMIT_NOFILE` is often 1024, so this loop sits right at the edge of exhausting the table.
3. Once the limit is hit, `open()` starts returning `-1` with `errno = EMFILE`. The `if (fd > 0)` guard prevents a crash on those failed opens, but the program silently does no work for the remaining iterations.
4. Minor secondary issue: `fd > 0` should really be `fd >= 0` (0 is technically a valid fd value, even though `open` won't return it here since stdin already occupies it).

**Hypothesis for `strace -e trace=file -c ./prog2`:**
- `open`/`openat` called ~1000 times
- Nonzero **error count** on `open`/`openat` once the fd table fills (errors column showing `EMFILE`)
- **Zero** `close` calls in the summary table — direct evidence of the leak

---

## Strace Investigation

Commands to run locally:

```bash
gcc -o prog1 1st-programm.c
strace -f -tt -T -o trace_A.log ./prog1

gcc -o prog2 2nd-programm.c
strace -e trace=file -c ./prog2
```

- `-f` follows forked children (needed for Program 1)
- `-tt` adds microsecond timestamps
- `-T` shows time spent in each syscall
- `-o trace_A.log` writes the full trace to file
- `-e trace=file` (Program 2) restricts to file-related syscalls
- `-c` produces a summary/count table instead of a full trace

**Status:** Pending — paste `trace_A.log` contents and the `-c` summary table here once run, so the Root Cause Analysis section below can be completed with exact line/timestamp correlation.

---

## Root Cause Analysis

*(To be completed once strace output is provided)*

- [ ] Correlate strace output with source code
- [ ] Identify exact line numbers causing issues
- [ ] Propose fixes for each bug

---

## Proposed Fixes (preliminary, pending confirmation from trace)

### Program 1

```c
if (pipe(pipefd) == -1) {
    perror("pipe");
    return 1;
}

if (fork() == 0) {
    close(pipefd[0]);
    write(pipefd[1], "Hello", 5);
    close(pipefd[1]); // fixed: close the write end, not read end again
} else {
    char buffer[10];
    close(pipefd[1]);
    read(pipefd[0], buffer, sizeof(buffer));
    close(pipefd[0]); // good practice: close after done reading
    wait(NULL);
}
```

### Program 2

```c
for (int i = 0; i < 1000; i++) {
    int fd = open("/etc/passwd", O_RDONLY);
    if (fd >= 0) {
        char buffer[100];
        read(fd, buffer, sizeof(buffer));
        close(fd); // fixed: release the descriptor
    }
}
```

---

## Deliverables Checklist

- [x] Bug analysis report (this document — initial analysis complete, root cause pending trace data)
- [x] Strace command sequences used
- [x] Proposed code fixes (preliminary)
- [ ] Explanation of debugging methodology (to finalize alongside root cause section)
