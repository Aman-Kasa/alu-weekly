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
        
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
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
    int V = 3; 
    int E = 3; 
    
    // Ordered to allow proper relaxation passes
    struct Edge edges[] = {
        {0, 1, 4},
        {1, 2, -6},
        {2, 0, 1}
    };

    bellmanFord(edges, V, E, 0);
    return 0;
}
