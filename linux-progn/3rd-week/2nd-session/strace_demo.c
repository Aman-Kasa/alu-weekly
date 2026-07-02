#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>

void demonstrate_file_io() {
    printf("\n--- Executing File Operations ---\n");
    FILE *fp = fopen("demo_test.txt", "w");
    if (fp == NULL) return;
    fprintf(fp, "Writing telemetry log data for strace demo.\n");
    fclose(fp);

    // Read it back
    char buffer[100];
    fp = fopen("demo_test.txt", "r");
    if (fp != NULL) {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Data read successfully
        }
        fclose(fp);
    }
}

void demonstrate_fork() {
    printf("\n--- Executing Process Forking ---\n");
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    }
    if (pid == 0) {
        // Inside Child Process
        printf("[Child] Hello from PID %d!\n", getpid());
        sleep(1); // Give strace time to catch it
        exit(0);
    } else {
        // Inside Parent Process
        printf("[Parent] Spawned child PID %d\n", pid);
        wait(NULL); // Wait for child to finish
    }
}

void demonstrate_network() {
    printf("\n--- Executing Network Network Operations ---\n");
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        return;
    }
    
    // We just create and close a socket for the network syscall footprint
    printf("[Network] Socket created successfully (FD: %d)\n", sock_fd);
    close(sock_fd);
}

int main() {
    printf("====================================================\n");
    printf(" STRACE TARGET PROGRAM RUNNING (PID: %d)\n", getpid());
    printf("====================================================\n");
    
    // 1. ANCHOR FOR ATTACHMENT DEMO (-p)
    // The program pauses here for 15 seconds so you can attach to it live!
    printf("[Status] Pausing for 15 seconds. Run: strace -p %d\n", getpid());
    sleep(15); 
    
    // 2. Run the sub-routines
    demonstrate_file_io();
    demonstrate_fork();
    demonstrate_network();
    
    printf("\n[Status] Demo complete. Exiting.\n");
    return 0;
}
