#include <stdio.h>
#include <pthread.h>

int global_counter = 0;
int target_count = 1000000;

void* increment_counter(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < target_count; i++) {
        global_counter++;
    }

    printf("Thread %d: Finished incrementing\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[2];
    int thread_ids[2] = {1, 2};

    printf("Initial counter value: %d\n", global_counter);

    // Create threads
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]);
    }

    printf("Final counter value: %d\n", global_counter);
    printf("Expected value: %d\n", target_count * 2);
    printf("Difference: %d\n", (target_count * 2) - global_counter);

    return 0;
}
