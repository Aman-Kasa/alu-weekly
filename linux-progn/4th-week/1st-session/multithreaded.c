#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Task 1: Periodically prints a countdown
void* task_countdown(void* arg) {
    for (int i = 5; i > 0; i--) {
        printf("[Thread 1 - Countdown] Counting down: %d\n", i);
        // Sleep for 100ms to let the OS scheduler switch contexts
        usleep(100000); 
    }
    printf("[Thread 1] Countdown finished.\n");
    return NULL;
}

// Task 2: Computes and prints running squares of numbers
void* task_squares(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("[Thread 2 - Math] Square of %d is %d\n", i, i * i);
        // Sleep for 100ms to allow execution interleaving
        usleep(100000); 
    }
    printf("[Thread 2] Square tasks finished.\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    printf("[Main] Spawning threads...\n\n");

    // Create the two threads running different functions
    if (pthread_create(&thread1, NULL, task_countdown, NULL) != 0) {
        perror("Failed to create Thread 1");
        return 1;
    }
    
    if (pthread_create(&thread2, NULL, task_squares, NULL) != 0) {
        perror("Failed to create Thread 2");
        return 1;
    }

    // Wait for both threads to finish execution before exiting main
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\n[Main] Both threads completed successfully. Exiting.\n");
    return 0;
}
