#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function prototypes
void readAdjacencyMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, const char *filename);
void primMST(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int startVertex);

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int n; // Number of vertices
    int startVertex;

    // Input file
    const char *filename = "inUnAdjMat.dat";

    // Read adjacency matrix from file
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the starting vertex (1 to %d): ", n);
    scanf("%d", &startVertex);
    startVertex--; // Convert to 0-based index

    readAdjacencyMatrix(adjMatrix, n, filename);
    primMST(adjMatrix, n, startVertex);

    return 0;
}

// Read adjacency matrix from the input file
void readAdjacencyMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &adjMatrix[i][j]);
        }
    }

    fclose(file);
}

// Function to implement Prim's algorithm
void primMST(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int startVertex) {
    int parent[MAX_VERTICES]; // Parent array to store the constructed MST
    int key[MAX_VERTICES];    // Key values to pick minimum weight edge in cut
    int inMST[MAX_VERTICES];  // Boolean array to check if vertex is in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = 0;
    }

    // Always include the first vertex in MST
    key[startVertex] = 0;
    parent[startVertex] = -1; // First node is always the root of MST

    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int min = INF, minIndex;
        for (int v = 0; v < n; v++) {
            if (inMST[v] == 0 && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        // Add the picked vertex to the MST
        int u = minIndex;
        inMST[u] = 1;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] && inMST[v] == 0 && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST and its cost
    printf("Minimum Spanning Tree (MST) cost adjacency matrix:\n");
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == parent[j] || j == parent[i]) {
                printf("%d ", adjMatrix[i][j]);
                if (i != j) totalCost += adjMatrix[i][j];
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("Total cost of MST: %d\n", totalCost / 2); // Each edge is counted twice
}
