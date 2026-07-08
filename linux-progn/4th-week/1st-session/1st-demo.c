#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process: PID = %d, Parent PID = %d\n",
               getpid(), getppid());
        sleep(2);
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n",
               getpid(), pid);
        wait(NULL);
    }

    return 0;
}
