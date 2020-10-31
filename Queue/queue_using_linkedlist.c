#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

typedef struct node node;

void enqueue(int n)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=n;
    ptr->next=NULL;
    if(front==NULL)
        front=rear=ptr;
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
}

int dequeue()
{
    if(rear==NULL)
    {
        printf("Queue is empty\n");
        return -99;
    }
    int data=front->data;
    node *ptr=front;
    if(front==rear)
    {
        free(ptr);
        front=rear=NULL;
    }
    else
    {
        front=front->next;
        free(ptr);
    }
    return data;
}

void display()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements are: ");
    node *ptr=front;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    while(1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        int choice;
        scanf("%d",&choice);
        int data;
        switch(choice)
        {
            case 1:
                printf("Enter the data: \n");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data=dequeue();
                if(data!=-99)
                    printf("The data deleted is: %d\n", data);
                break;
            case 3:
                display();
                break;
            default:printf("Thankyou\n");
                return 0;
        }
    }
    return 0;
}
