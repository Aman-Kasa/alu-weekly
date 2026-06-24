#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node and Graph Structures
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;

// Stack Structure for Iterative DFS
typedef struct Stack {
    int* items;
    int top;
    int capacity;
} Stack;

// Graph-related functions
Graph* createGraph(int vertices);
Node* createNode(int vertex);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);

// DFS Iterative
Stack* createStack(int capacity);
void push(Stack* stack, int value);
int pop(Stack* stack);
bool isStackEmpty(Stack* stack);
void DFS_Iterative(Graph* graph, int startVertex);

// ==========================================
// Implementation of Graph Functions
// ==========================================

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)calloc(vertices, sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's undirected, add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ==========================================
// Implementation of Stack Functions
// ==========================================

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(capacity * sizeof(int));
    return stack;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->items[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1; // Return -1 if stack is empty
}

// ==========================================
// Implementation of Iterative DFS
// ==========================================

void DFS_Iterative(Graph* graph, int startVertex) {
    // Capacity equal to total nodes ensures the stack won't overflow
    Stack* stack = createStack(graph->numVertices * graph->numVertices); 

    // Push the starting source vertex
    push(stack, startVertex);

    while (!isStackEmpty(stack)) {
        // Pop a vertex from stack
        int currentVertex = pop(stack);

        // If the popped vertex is not visited yet, process it
        if (!graph->visited[currentVertex]) {
            printf("%d ", currentVertex);
            graph->visited[currentVertex] = true;
        }

        // Push all unvisited adjacent neighbors of the popped vertex into stack
        Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                push(stack, adjVertex);
            }
            temp = temp->next;
        }
    }
    
    // Free stack memory
    free(stack->items);
    free(stack);
}

// ==========================================
// Main Function
// ==========================================
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("\nIterative Depth-First Search starting from vertex 0:\n");
    // Memory initialization tracking is already reset using calloc inside createGraph, 
    // but resetting it here to match your code block.
    for(int i = 0; i < vertices; i++) graph->visited[i] = false; 
    
    DFS_Iterative(graph, 0);
    printf("\n");
    
    return 0;
}
