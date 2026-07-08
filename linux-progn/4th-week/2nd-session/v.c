#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h> // 1. Include the atomics library

atomic_int counter = 0; // 2. Declare the counter as an atomic type

void* increment(void* arg) {
    for (int i = 0; i < 10; i++) {
        counter++; // 3. This operation is now hardware-atomic
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter); // Will ALWAYS be 200000

    return 0;
}
