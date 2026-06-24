#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Heap;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* =========================
   MIN HEAP FUNCTIONS
   ========================= */

// Heapify Up for Min Heap
void minHeapifyUp(Heap *heap, int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap->data[parent] > heap->data[index]) {
        swap(&heap->data[parent], &heap->data[index]);
        minHeapifyUp(heap, parent);
    }
}

// Heapify Down for Min Heap
void minHeapifyDown(Heap *heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size &&
        heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size &&
        heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        minHeapifyDown(heap, smallest);
    }
}

// Insert into Min Heap
void insertMin(Heap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Min Heap is full!\n");
        return;
    }

    heap->data[heap->size] = value;
    minHeapifyUp(heap, heap->size);
    heap->size++;
}

// Delete minimum
int deleteMin(Heap *heap) {
    if (heap->size == 0) {
        printf("Min Heap is empty!\n");
        return -1;
    }

    int root = heap->data[0];

    heap->data[0] = heap->data[--heap->size];

    minHeapifyDown(heap, 0);

    return root;
}

/* =========================
   MAX HEAP FUNCTIONS
   ========================= */

// Heapify Up for Max Heap
void maxHeapifyUp(Heap *heap, int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap->data[parent] < heap->data[index]) {
        swap(&heap->data[parent], &heap->data[index]);
        maxHeapifyUp(heap, parent);
    }
}

// Heapify Down for Max Heap
void maxHeapifyDown(Heap *heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap->size &&
        heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size &&
        heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        maxHeapifyDown(heap, largest);
    }
}

// Insert into Max Heap
void insertMax(Heap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Max Heap is full!\n");
        return;
    }

    heap->data[heap->size] = value;
    maxHeapifyUp(heap, heap->size);
    heap->size++;
}

// Delete maximum
int deleteMax(Heap *heap) {
    if (heap->size == 0) {
        printf("Max Heap is empty!\n");
        return -1;
    }

    int root = heap->data[0];

    heap->data[0] = heap->data[--heap->size];

    maxHeapifyDown(heap, 0);

    return root;
}

/* =========================
   PRINT FUNCTION
   ========================= */

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);

    printf("\n");
}

/* =========================
   MAIN FUNCTION
   ========================= */

int main() {

    Heap minHeap;
    minHeap.size = 0;

    Heap maxHeap;
    maxHeap.size = 0;

    // Insert elements
    int values[] = {15, 10, 20, 8, 25};

    for (int i = 0; i < 5; i++) {
        insertMin(&minHeap, values[i]);
        insertMax(&maxHeap, values[i]);
    }

    printf("Min Heap:\n");
    printHeap(&minHeap);

    printf("\nMax Heap:\n");
    printHeap(&maxHeap);

    printf("\nDeleted Min: %d\n", deleteMin(&minHeap));
    printHeap(&minHeap);

    printf("\nDeleted Max: %d\n", deleteMax(&maxHeap));
    printHeap(&maxHeap);

    return 0;
}
