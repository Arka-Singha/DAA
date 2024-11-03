#include <stdio.h>

// Function to generate Fibonacci sequence using iteration
void fibonacciIterative(int n) {
    int a = 0, b = 1, next;

    printf("Fibonacci Sequence (Iterative):\n");
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    fibonacciIterative(n);

    return 0;
}
