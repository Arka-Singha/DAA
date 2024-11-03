#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements of the array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int arr2[n];
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        arr2[i]=sum + arr[i];
        sum = arr2[i];
    }

    for(int i=0; i<n; i++){
        printf("%d  ", arr2[i]);
    }
    return 0;
}