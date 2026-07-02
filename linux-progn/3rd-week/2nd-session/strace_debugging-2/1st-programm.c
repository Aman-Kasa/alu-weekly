// parent_child_bug.c
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int pipefd[2];
    pipe(pipefd); // Missing error check

    if (fork() == 0) {
        // Child: write to wrong end of pipe
        close(pipefd[0]);
        write(pipefd[1], "Hello", 5);
        close(pipefd[0]); // Closing wrong fd again!
    } else {
        // Parent: read from pipe
        char buffer[10];
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        wait(NULL);
    }
    return 0;
}
