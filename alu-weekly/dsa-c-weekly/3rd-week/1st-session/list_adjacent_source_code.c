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

struct Node* createNode(int dest, int weight) {
    // TODO: Implement this function
    return NULL; // Replace with your implementation
}

struct Graph* createGraph(int numVertices) {
    // TODO: Implement this function
    return NULL; // Replace with your implementation
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // TODO: Implement this function
    // Add an edge from src to dest
    
    // For undirected graph, add an edge from dest to src also
}

void printGraph(struct Graph* graph) {
    // TODO: Implement this function
    printf("Adjacency List Representation of the Graph:\n");
    
    // For each vertex, print its adjacency list
}


void freeGraph(struct Graph* graph) {
    // TODO: Implement this function
}

int main() {
    // Sample graph with 5 vertices
    int numVertices = 5;
    
    // Create a graph
    struct Graph* graph = createGraph(numVertices);
    
    // Sample edges to be added
    // TODO: Students should add the following edges to the graph using the addEdge function
    // Edge 0-1 with weight 10
    // Edge 0-4 with weight 20
    // Edge 1-2 with weight 30
    // Edge 1-3 with weight 40
    // Edge 1-4 with weight 50
    // Edge 2-3 with weight 60
    // Edge 3-4 with weight 70
    
    // Print the graph
    printGraph(graph);
    
    // Free the allocated memory
    freeGraph(graph);
    
    return 0;
}
