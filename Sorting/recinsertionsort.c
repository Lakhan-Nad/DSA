/*Recursive Insertion Sort*/

#include<stdio.h>

void insertionsort(int arr[],int n,int i)
{
    if(i==n)
        return;
    int j=i-1;
    int temp=arr[i];
    while(j>-1&&arr[j]>temp)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
    insertionsort(arr,n,i+1);
}

int main()
{
    int n;
    printf("\nEnter the No of elements: ");
    scanf("%d",&n);
    int arr[n];

    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n,1);

    printf("\nAfter Sorting: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

