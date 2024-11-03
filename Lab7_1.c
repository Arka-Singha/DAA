#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices

// Function to find the vertex with the minimum distance value, from the set of vertices not yet processed.
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int parent[], int src) {
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("%d\t%d\t\t%d\t", src + 1, i + 1, dist[i]);
            int temp = i;
            printf("%d", i + 1);
            while (parent[temp] != - 1) {
                printf("<-%d", parent[temp] + 1);
                temp = parent[temp];
            }
            printf("\n");
        }
    }
}

// Function that implements Dijkstra's shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // dist[i] will hold the shortest distance from src to i
    int sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree
    int parent[V]; // To store the shortest path tree
    
    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1; // No parent initially
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            // Update dist[v] if it's not in sptSet, there's an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed distance array
    printSolution(dist, parent, src);
}

int main() {
    // Example adjacency matrix from the input
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int src;
    printf("Enter the source vertex (1-%d): ", V);
    scanf("%d", &src);

    // Run Dijkstra's algorithm for the given graph and source
    dijkstra(graph, src - 1);

    return 0;
}
