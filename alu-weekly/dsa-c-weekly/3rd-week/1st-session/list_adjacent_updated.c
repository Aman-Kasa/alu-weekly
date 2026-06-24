#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
struct Node {
    int dest;           // Destination vertex number
    int weight;         // Weight of the edge (for weighted graphs)
    struct Node* next;  // Pointer to the next node in the list
};

// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to allocate and initialize a new adjacency list node
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Node memory allocation failed.\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to allocate graph resources and initialize empty arrays
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Error: Graph memory allocation failed.\n");
        exit(1);
    }
    graph->numVertices = numVertices;

    // Allocate an array of adjacency lists
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    if (graph->array == NULL) {
        printf("Error: Adjacency list array allocation failed.\n");
        exit(1);
    }

    // Initialize each adjacency list head pointer as empty
    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add a weighted undirected edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // 1. Add edge from src to dest (prepend to head of list)
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // 2. Since it is an undirected graph, add edge from dest to src also
    newNode = createNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the compiled adjacency lists
void printGraph(struct Graph* graph) {
    printf("Adjacency List Representation of the Graph:\n");
    printf("===========================================\n");
    
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* crawler = graph->array[v].head;
        printf("Vertex [%d]:", v);
        
        while (crawler != NULL) {
            printf(" -> (Dest: %d, Weight: %d)", crawler->dest, crawler->weight);
            crawler = crawler->next;
        }
        printf(" -> NULL\n");
    }
}

// Function to systematically free all deep heap linked list allocations
void freeGraph(struct Graph* graph) {
    if (graph == NULL) return;

    // Free the individual nodes in every linked list
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* current = graph->array[v].head;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp); // Free individual list node
        }
    }

    // Free the master pointer array structure
    free(graph->array);
    
    // Free the overall graph structure
    free(graph);
    printf("\nGraph memory freed successfully.\n");
}

int main() {
    // Sample graph with 5 vertices
    int numVertices = 5;
    
    // Create a graph
    struct Graph* graph = createGraph(numVertices);
    
    // Core Lab Assignment: Inserting sample target edges
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 1, 4, 50);
    addEdge(graph, 2, 3, 60);
    addEdge(graph, 3, 4, 70);
    
    // Print the graph
    printGraph(graph);
    
    // Free the allocated memory
    freeGraph(graph);
    
    return 0;
}
