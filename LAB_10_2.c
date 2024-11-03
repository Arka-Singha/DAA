#include <stdio.h>

// Fibonacci numbers array up to F10 (this can be expanded as needed)
int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

// Function to find the largest Fibonacci number <= n
int largestFibonacci(int n) {
    int i = 0;
    while (fib[i] <= n) {
        i++;
    }
    return i - 1;  // Return the index of the largest Fibonacci <= n
}

// Function to convert an integer to its Fibonacci representation (fitstring)
void intToFitString(int n, int fitstring[], int length) {
    // Initialize the fitstring to all 0s
    for (int i = 0; i < length; i++) {
        fitstring[i] = 0;
    }

    // Convert to Fibonacci representation
    while (n > 0) {
        int index = largestFibonacci(n);
        fitstring[index] = 1;
        n -= fib[index];
    }
}

// Function to convert the fitstring to its integer value
int fitStringToInt(int fitstring[], int length) {
    int value = 0;
    for (int i = 0; i < length; i++) {
        if (fitstring[i] == 1) {
            value += fib[i];
        }
    }
    return value;
}

// Function to increment the fitstring in Zeckendorf representation
void incrementFitString(int fitstring[], int length) {
    int n = fitStringToInt(fitstring, length);
    n++;  // Increment the integer value
    intToFitString(n, fitstring, length);  // Convert the incremented value back to fitstring
}

// Function to decrement the fitstring in Zeckendorf representation
void decrementFitString(int fitstring[], int length) {
    int n = fitStringToInt(fitstring, length);
    if (n > 0) {
        n--;  // Decrement the integer value
        intToFitString(n, fitstring, length);  // Convert the decremented value back to fitstring
    }
}

// Function to print the fitstring
void printFitString(int fitstring[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        printf("%d", fitstring[i]);
    }
    printf("\n");
}

int main() {
    int fitstring[10];  // Array to hold the Fibonacci representation (fitstring)
    int n;
    
    // Input the integer to convert to fitstring
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Convert the integer to its Fibonacci fitstring representation
    intToFitString(n, fitstring, 10);

    printf("Fitstring representation of %d: ", n);
    printFitString(fitstring, 10);

    // Increment the fitstring
    incrementFitString(fitstring, 10);
    printf("After incrementing: ");
    printFitString(fitstring, 10);

    // Decrement the fitstring
    decrementFitString(fitstring, 10);
    printf("After decrementing: ");
    printFitString(fitstring, 10);

    return 0;
}
