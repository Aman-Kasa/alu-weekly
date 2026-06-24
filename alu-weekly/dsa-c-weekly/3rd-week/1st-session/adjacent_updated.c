#include <stdio.h>
#include <stdlib.h>

// Maximum number of nodes our graph can have
#define MAX_NODES 10

// Our graph structure
typedef struct {
    int numNodes;                      // How many nodes are currently in the graph
    int matrix[MAX_NODES][MAX_NODES];  // 2D Adjacency matrix storing edge weights
    char labels[MAX_NODES];            // Node labels (A, B, C, etc.)
} Graph;

// Function to create a new empty graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    graph->numNodes = 0;
    
    // Clear out the matrix entirely (0 indicates no edge connection)
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add a new node label to our graph
void addNode(Graph* graph, char label) {
    if (graph->numNodes >= MAX_NODES) {
        printf("Cannot add more nodes, the graph is full!\n");
        return;
    }
    
    graph->labels[graph->numNodes] = label;
    graph->numNodes++;
    printf("Added node %c\n", label);
}

// Function to add a weighted edge between two index positions (Undirected)
void addEdge(Graph* graph, int from, int to, int weight) {
    if (from < 0 || from >= graph->numNodes || to < 0 || to >= graph->numNodes) {
        printf("Cannot add edge - invalid node number!\n");
        return;
    }
    
    graph->matrix[from][to] = weight;
    graph->matrix[to][from] = weight;  // Mirrors the connection for symmetric/undirected graphs
    
    printf("Added edge from %c to %c with weight %d\n", 
           graph->labels[from], graph->labels[to], weight);
}

// Function to display the compiled adjacency matrix layout
void displayMatrix(Graph* graph) {
    printf("\nAdjacency Matrix Grid:\n");
    
    // Print upper column headers
    printf("  ");
    for (int i = 0; i < graph->numNodes; i++) {
        printf("%c ", graph->labels[i]);
    }
    printf("\n");
    
    // Print rows containing weights
    for (int i = 0; i < graph->numNodes; i++) {
        printf("%c ", graph->labels[i]);
        for (int j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Dynamic lookup function: Gets an edge weight directly using character labels
int getWeightByLabel(Graph* graph, char fromLabel, char toLabel) {
    int fromIdx = -1;
    int toIdx = -1;

    // Scan labels array to locate the matching tracking indices
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->labels[i] == fromLabel) {
            fromIdx = i;
        }
        if (graph->labels[i] == toLabel) {
            toIdx = i;
        }
    }

    // Return error condition flag if either node cannot be localized
    if (fromIdx == -1 || toIdx == -1) {
        printf("Error: Node label '%c' or '%c' not found in graph!\n", fromLabel, toLabel);
        return -1; 
    }

    return graph->matrix[fromIdx][toIdx];
}

// Execution runtime
int main() {
    printf("Creating a new graph matching the slide...\n");
    Graph* myGraph = createGraph();
    
    // 1. Initialize vertices
    addNode(myGraph, 'A'); // Index 0
    addNode(myGraph, 'B'); // Index 1
    addNode(myGraph, 'C'); // Index 2
    addNode(myGraph, 'D'); // Index 3
    
    printf("\nInserting correct weights from the dark slide diagram:\n");
    // 2. Map edges using correct metrics from dark slide image
    addEdge(myGraph, 0, 1, 4); // A <--> B (Weight 4)
    addEdge(myGraph, 0, 2, 2); // A <--> C (Weight 2)
    addEdge(myGraph, 0, 3, 1); // A <--> D (Weight 1)
    addEdge(myGraph, 1, 2, 6); // B <--> C (Weight 6)
    addEdge(myGraph, 2, 3, 8); // C <--> D (Weight 8)
    
    // 3. Output structural layout matrix
    displayMatrix(myGraph);
    
    // 4. Test dynamic query routine using labels directly
    printf("Testing getWeightByLabel lookup function:\n");
    char source = 'B', destination = 'C';
    int queryWeight = getWeightByLabel(myGraph, source, destination);
    if (queryWeight != -1) {
        printf("The connection weight between %c and %c is: %d\n", source, destination, queryWeight);
    }
    
    // 5. Release heap memory resources back to the kernel safely
    free(myGraph);
    return 0;
}
