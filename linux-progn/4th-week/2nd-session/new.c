#include <stdio.h>
#include <pthread.h>

int counter = 0;   // Shared resource
pthread_mutex_t counter_mutex; // = PTHREAD_MUTEX_INITIALIZER; // Initialize the mutex

void* increment(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&counter_mutex);   // Acquire lock before entering critical section
        counter++;                            // Critical section: now thread-safe
        pthread_mutex_unlock(&counter_mutex); // Release lock immediately after
    }

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_mutex_init(&counter_mutex, NULL);
    
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_create(&t3, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    // Destroy the mutex to free up kernel/library resources
    pthread_mutex_destroy(&counter_mutex);

    // With 3 threads doing 100,000 iterations each, this will always be exactly 300000
    printf("Final counter value: %d\n", counter);   

    return 0;
}
