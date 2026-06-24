#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // Required for memset

// Signal handler function
void sigint_handler(int sig) {
    // Note: Use write() or async-signal-safe functions in real handlers
    // printf is technically not async-signal-safe, but often works for simple tests
    const char msg[] = "\nCaught SIGINT (signal), cleaning up...\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
    exit(0);
}

int main() {
    struct sigaction sa;

    // Clear the structure
    memset(&sa, 0, sizeof(sa));

    // Set the handler
    sa.sa_handler = sigint_handler;

    // Register the action for SIGINT
    // sigaction returns 0 on success, -1 on error
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    
    printf("Running... Press Ctrl+C to test signal handler (PID: %d)\n", getpid());
    
    // Infinite loop
    while(1) {
        printf("Still running...\n");
        sleep(2);
    }
    
    return 0;
}
