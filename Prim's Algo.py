import heapq
import numpy as np

def prim_algorithm(adjacency_matrix, start_vertex):
    n = len(adjacency_matrix)
    min_heap = [(0, start_vertex)]  # (weight, vertex)
    total_weight = 0
    mst_adj_matrix = np.zeros((n, n), dtype=int)
    min_weights = [float('inf')] * n
    min_weights[start_vertex] = 0
    in_mst = [False] * n

    while min_heap:
        current_weight, u = heapq.heappop(min_heap)

        if in_mst[u]:
            continue

        in_mst[u] = True
        total_weight += current_weight

        for v in range(n):
            weight = adjacency_matrix[u][v]
            if weight > 0 and not in_mst[v] and weight < min_weights[v]:
                min_weights[v] = weight
                heapq.heappush(min_heap, (weight, v))
                mst_adj_matrix[u][v] = weight
                mst_adj_matrix[v][u] = weight

    return mst_adj_matrix, total_weight

def read_adjacency_matrix(filename):
    return np.loadtxt(filename, dtype=int)

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))
    
def main():
    filename = "inUnAdjMat.dat"
    adjacency_matrix = read_adjacency_matrix(filename)

    n = int(input("Enter the Number of Vertices: "))
    start_vertex = int(input("Enter the Starting Vertex: ")) - 1

    mst_adj_matrix, total_weight = prim_algorithm(adjacency_matrix, start_vertex)

    print("Cost Adjacency Matrix of the Minimum Spanning Tree:")
    print_matrix(mst_adj_matrix)
    print(f"Total Weight of the Spanning Tree: {total_weight}")

if __name__ == "__main__":
    main()
