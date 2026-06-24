#include <stdio.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            
            // --- COMPLETED: Edge relaxation condition ---
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        
        // --- COMPLETED: Detect negative cycle condition ---
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Graph contains a negative-weight cycle!\n");
    }

    // Print the distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    // --- COMPLETED: Test graph with positive and negative weights containing a cycle ---
    // Let's create a 3-vertex graph:
    // 0 -> 1 (weight 4)
    // 1 -> 2 (weight -2)
    // 2 -> 1 (weight -1) <-- Creates a negative cycle between 1 and 2 (total cycle weight = -3)
    int V = 3; 
    int E = 3; 
    struct Edge edges[] = {
        {0, 1, 4},
        {1, 2, -2},
        {2, 1, -1}
    };

    printf("--- Running Bellman-Ford ---\n");
    bellmanFord(edges, V, E, 0);
    return 0;
}
