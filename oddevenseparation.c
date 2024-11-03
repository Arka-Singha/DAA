#include <stdio.h>

// Function to swap elements in the array
void swap(int A[], int x, int y) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int main() {
    int A[] = {1, 986, 74, 53, 64, 75, 2, 3, 4, 5};
    int i = 0, j = 9;

    // Loop to rearrange the elements so that odd numbers are on one side and even on the other
    while (i < j) {
        if (A[i] % 2 == 1)  // Skip if the number at i is odd
            i++;
        if (A[j] % 2 == 0)  // Skip if the number at j is even
            j--;
        if (A[i] % 2 == 0 && A[j] % 2 == 1) {
            swap(A, i, j);  // Swap if A[i] is even and A[j] is odd
            i++;
            j--;
        }
    }

    // Print the updated array
    for (int k = 0; k < 10; k++) {
        printf("%d  ", A[k]);
    }

    return 0;
}