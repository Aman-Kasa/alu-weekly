#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler function
void sigint_handler(int sig) {
    printf("\n Caught SIGINT (signal %d)\n", sig);
    printf("Cleaning up resources...\n");
    printf("Goodbye!\n");
    exit(0);
}

int main() {
    // Register signal handler
    signal(SIGINT, sigint_handler);
    
    printf("Running... Press Ctrl+C to test signal handler\n");
    
    // Infinite loop
    while(1) {
        printf("Still running... (PID: %d)\n", getpid());
        sleep(2);
    }
    
    return 0;
}

