#include <stdio.h>
#include <limits.h>

void Solution(int arr[], int n, int *sS, int *S, int *sL, int *L)
{
    int min = INT_MAX, second_min = INT_MAX, i, first = INT_MIN, second = INT_MIN;
        if (n < 2) {
        printf("Invalid Input\n");
        return;
    }
    for (i = 0; i < n; i++) // Array Traversal
    {
        if (arr[i] < min)
        {
            second_min = min;
            min = arr[i];
        }
        else if (arr[i] < second_min && arr[i] != min) // Check for second smallest
        {
            second_min = arr[i];
        }
    
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first) // Check for second largest
        {
            second = arr[i];
        }
    }
    *sS = second_min;
    *S  = min;
    *sL = second;
    *L  = first;
    
}



int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("Invalid Input\n");
        return 1; // Exit the program if invalid input
    }
    printf("Enter the array elements: ");
    int a[n]; // Array Declaration
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int S=0, sS = 0, L=0, sL = 0;
    Solution(a, n, &sS, &S, &sL, &L);
    printf("The smallest element is %d\n", S);
    printf("The second smallest element is %d\n", sS); 
    printf("The  largest element is %d\n", L);
    printf("The second largest element is %d\n", sL); 
    return 0;
}
