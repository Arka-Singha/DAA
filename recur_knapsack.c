#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (wt[n - 1] > W) {
        return knapsack(W, wt, val, n - 1);
    }

    return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),knapsack(W, wt, val, n - 1));

}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int W, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    printf("Enter the    values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    int result = knapsack(W, wt, val, n);
    printf("Maximum value that can be obtained: %d\n", result);

    return 0;
}