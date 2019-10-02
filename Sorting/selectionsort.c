//Selection Sort

#include<stdio.h>

void selsort(int arr[],int n)
{
    int k,temp;
    for (int i = 0; i < n-1; i++)
    {
        int k=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[k]>arr[j])
            {
                k=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
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

    selsort(arr,n);

    printf("\nAfter Sorting Elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
    
}