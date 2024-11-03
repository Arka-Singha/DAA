#include <stdio.h>

typedef struct {
    int item_id;
    float profit;
    float weight;
    float profit_weight_ratio;
} Item;

void Sort(Item items[], int n) {
    
    for (int i = 0; i < n; i++) {
        Item key;
        key = items[i];
        int j = i - 1;

        while (j >= 0 && items[j].profit_weight_ratio < key.profit_weight_ratio) {
            items[j + 1] = items[j];
            j = j - 1;
        }
        items[j + 1] = key;
    }
}

/*void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}*/

float fractionalKnapsack(Item items[], int n, float capacity) {
    Sort(items, n);  // Sort items by profit-to-weight ratio in descending order

    float total_profit = 0.0;
    printf("\nItem No\tProfit\tWeight\tAmount to be taken\n");

    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;

        if (items[i].weight <= capacity) {
            printf("%d\t%.6f\t%.6f\t1.000000\n", items[i].item_id, items[i].profit, items[i].weight);
            total_profit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            float fraction = capacity / items[i].weight;
            printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].profit, items[i].weight, fraction);
            total_profit += items[i].profit * fraction;
            capacity = 0;
        }
    }
    return total_profit;
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].profit / items[i].weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    float max_profit = fractionalKnapsack(items, n, capacity);

    printf("\nMaximum profit: %.6f\n", max_profit);

    return 0;
}
