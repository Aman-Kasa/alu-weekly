#include <stdio.h>
#include <pthread.h>

int counter = 0; // Shared resource

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        counter++; // Race condition: not thread-safe
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter); // Likely less than 200000

    return 0;
}
