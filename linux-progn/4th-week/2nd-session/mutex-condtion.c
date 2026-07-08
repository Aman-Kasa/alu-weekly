#include <stdio.h>
#include <pthread.h>

int counter = 0; // Shared resource
pthread_mutex_t lock; // 1. Declare the mutex globally

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);   // 3. Acquire the lock
        counter++;                    // Critical Section (Safe now)
        pthread_mutex_unlock(&lock); // 4. Release the lock
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 2. Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed\n");
        return 1;
    }

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 5. Clean up and destroy the mutex
    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter); // Will ALWAYS be 200000

    return 0;
}
