#include <stdio.h>
#include <stdlib.h>

// Function to increment the binary counter
void increment(int A[], int size, int *high_order_bit, int *cost) {

    *cost++;
    int i = 0; // Start from the least significant bit

    // Flip bits until we find a 0
    while (i <= *high_order_bit && A[i] == 1) {
        A[i] = 0; // Set to 0 because of carry over
        i++;
    }
    
    // If we haven't exceeded the high-order bit, flip the next 0 to 1
    if (i < size) {
        A[i] = 1;
        // Update high_order_bit if necessary
        if (i > *high_order_bit) {
            *high_order_bit = i;
        }
    }
}

// Function to reset the binary counter to 0
void reset(int A[], int size, int *high_order_bit, int *cost) {
    *cost++;
    for (int i = 0; i <= *high_order_bit; i++) {
        A[i] = 0;
    }
    *high_order_bit = -1; // Reset the high-order bit pointer
}

// Function to print the binary counter
void printCounter(int A[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", A[i]);
    }
    printf("\n");
}

int main() {
    int cost = 0;
    int size = 5;  // Size of the counter (5 bits)
    int counter[size];  // Array to store the binary counter
    int high_order_bit = -1;  // Pointer to the most significant 1 bit (start at -1)
    
    // Initialize the counter to 0
    for (int i = 0; i < size; i++) {
        counter[i] = 0;
    }

    int choice;  // User choice for switch-case operations
    int running = 1;  // Variable to keep the loop running

    // Perform operations in a loop
    while (running) {
        // Print the current state of the counter
        printf("\nCurrent counter: ");
        printCounter(counter, size);

        // Display menu options
        printf("\nChoose an operation:\n");
        printf("1. Increment\n");
        printf("2. Reset\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                increment(counter, size, &high_order_bit, &cost);
                printf("Counter incremented.\n");
                break;
            case 2:
                reset(counter, size, &high_order_bit, &cost);
                printf("Counter reset.\n");
                break;
            case 3:
                running = 0;  // Exit the loop
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
