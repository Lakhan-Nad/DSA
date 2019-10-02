//Recursive Bubble Sort

#include<stdio.h>

void recbubsort(int arr[],int n)
{
    if(n==1)
        return;
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    recbubsort(arr,n-1);
}

int main()
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    recbubsort(arr,n);

    printf("\nAfter Sorting Elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
    
}