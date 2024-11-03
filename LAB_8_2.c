#include <stdio.h>
#include <string.h>

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive LCS function which also stores LCS length in a memoization table
int lcs(char *S1, char *S2, int m, int n, int LCS_table[100][100]) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (LCS_table[m][n] != -1) {
        return LCS_table[m][n];  // Return memoized value if already calculated
    }
    if (S1[m - 1] == S2[n - 1]) {
        return LCS_table[m][n] = 1 + lcs(S1, S2, m - 1, n - 1, LCS_table);
    } else {
        return LCS_table[m][n] = max(lcs(S1, S2, m, n - 1, LCS_table), lcs(S1, S2, m - 1, n, LCS_table));
    }
}

// Function to print the LCS by backtracking through the memoization table
void printLCS(char *S1, char *S2, int m, int n, int LCS_table[100][100]) {
    int index = LCS_table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';  // Set null terminator for the LCS string

    // Start from LCS_table[m][n] and trace back to get the LCS characters
    while (m > 0 && n > 0) {
        if (S1[m - 1] == S2[n - 1]) {
            lcs[--index] = S1[m - 1];  // If characters match, add to LCS
            m--;
            n--;
        } else if (LCS_table[m - 1][n] > LCS_table[m][n - 1]) {
            m--;
        } else {
            n--;
        }
    }

    printf("LCS: %s\n", lcs);  // Print the LCS
}

int main() {
    char S1[100], S2[100];
    
    // Input first string
    printf("Enter the first string: ");
    scanf("%s", S1);
    
    // Input second string
    printf("Enter the second string: ");
    scanf("%s", S2);

    int m = strlen(S1);
    int n = strlen(S2);
    
    // Memoization table to store LCS lengths, initialized to -1
    int LCS_table[100][100];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            LCS_table[i][j] = -1;
        }
    }

    // Find length of LCS
    int length_of_lcs = lcs(S1, S2, m, n, LCS_table);
    printf("Length of LCS is %d\n", length_of_lcs);

    // Print the LCS
    printLCS(S1, S2, m, n, LCS_table);

    return 0;
}
