#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function with the pivot as the last element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = low - 1;  // Index of the smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to choose a random pivot, swap it with the last element, and then partition
int randomizedPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);  // Generate a random number between low and high
    swap(&arr[random], &arr[high]);  // Swap the random element with the last element
    return partition(arr, low, high);
}

// Recursive Randomized Quicksort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find pivot position using randomized partition
        int pivot = randomizedPartition(arr, low, high);
        
        // Recursively sort elements before and after partition
        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));  // Seed the random number generator
    
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array:\n");
    printArray(arr, n);
    
    randomizedQuickSort(arr, 0, n - 1);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}
