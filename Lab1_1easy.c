#include <stdio.h>

int secondSmallest(int arr[],int n)
{
    int min = 100;
    int second_min = 100 ;
    int i;
    for(i = 0; i < n; i++)       
    {
       if(arr[i] < min)
       {
          second_min = min;
          min = arr[i];
       }
       else if(arr[i] < second_min && arr[i] != min)      
       {
          second_min = arr[i];
       }
    }
   return second_min;             
}
int secondLargest(int arr[],int n)
{
    int i, first, second;
    if (n < 2) {
        printf(" Invalid Input ");
        return;
    }
    first = second =arr[0];        
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > first) 
        {
            second = first;
            first = arr[i];
        }
 
        else if (arr[i] > second && arr[i] != first)      
        {
            second = arr[i];
        }
    }
    return second;                
}
int main() {
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the array elements :");
    int a[n];                   
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n<2)
    {
        printf("Invalid Input");
    }
    else
    {
        int sS=secondSmallest(a,n);
        printf("The second smallest element is %d",sS);
        printf("\n");
        int sL=secondLargest(a,n);
        printf("The second largest element is %d",sL);
    }
    return 0;
}