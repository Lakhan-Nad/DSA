//Bubble Sort

#include<stdio.h>

void bubsort(int arr[],int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
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

    bubsort(arr,n);

    printf("\nAfter Sorting Elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
    
}