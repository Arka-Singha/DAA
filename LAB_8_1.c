#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to print the optimal parenthesization
void printOptimalParens(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Matrix Chain Multiplication function
void matrixChainOrder(int p[], int n) {
    int m[MAX][MAX], s[MAX][MAX];  // M-table and S-table
    int i, j, k, L, q;

    // Initializing diagonal of M-table to 0 because cost of multiplying one matrix is zero
    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is chain length (subproblem size)
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print M-table
    printf("M Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i <= j) {
                printf("%d\t", m[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    // Print S-table
    printf("S Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i <= j) {
                printf("%d\t", s[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n - 1]);
}

int main() {
    int n, i;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[MAX]; // p[i-1] is row, p[i] is col of matrix i
    for (i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i + 1);
        int row, col;
        scanf("%d %d", &row, &col);
        if (i == 0) {
            p[i] = row;
        }
        p[i + 1] = col; // store only column sizes for compatibility
    }

    // Call matrix chain order function
    matrixChainOrder(p, n + 1);

    return 0;
}
