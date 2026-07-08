#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define NUM_THREADS 5
#define INCREMENTS 10000

// Shared resource
int shared_counter = 0;

// Mutex declaration
pthread_mutex_t counter_mutex;

// Thread function
void* increment_counter(void* arg) {
    for (int i = 0; i < INCREMENTS; i++) {
        // Lock the mutex before entering the critical section
        pthread_mutex_lock(&counter_mutex);

        // Critical section: safely increment the shared counter
	shared_counter++;

	// Unlock the mutex so other threads can access the counter
	pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct timeval start, end;

    // 1. Initialize the mutex
    if (pthread_mutex_init(&counter_mutex, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        return 1;
    }

    // Start measuring execution time
    gettimeofday(&start, NULL);

    // 2. Create 5 threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to finish execution
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Stop measuring execution time
    gettimeofday(&end, NULL);

    // 3. Cleanup the mutex
    pthread_mutex_destroy(&counter_mutex);

    // Calculate elapsed time in seconds
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

    // Print final results
    printf("Expected counter value: %d\n", NUM_THREADS * INCREMENTS);
    printf("Final counter value:    %d\n", shared_counter);
    printf("Execution time:         %.6f seconds\n", elapsed);

    return 0;
}
