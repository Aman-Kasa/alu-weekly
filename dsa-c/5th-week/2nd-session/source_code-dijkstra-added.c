#include <stdio.h>
#include <limits.h>  // For INT_MAX

#define V 5  // Number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Recursive function to print shortest path from source to j using parent array
void printPath(int parent[], int j) {
    // Base Case : If j is source (no parent)
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }

    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Updated printSolution function
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, dist[i]);
        if (i == src) {
            printf("%d\n", src);
        } else {
            printPath(parent, i);
            printf("\n");
        }
    }
}
// Dijkstra's Algorithm with parent tracking
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // dist[i] = shortest distance from src to i
    int visited[V];   // visited[i] = true if vertex i is finalized
    int parent[V];    // parent[i] = previous vertex on the shortest path from src to i

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1; // Initially, no parent
    }
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;  // Update parent of v
            }
        }
    }

    // Print the final results
    printSolution(dist, parent, src);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    int source = 0;
    printf("Dijkstra's Algorithm Starting from Vertex %d:\n\n", source);
    dijkstra(graph, source);

    return 0;
}

