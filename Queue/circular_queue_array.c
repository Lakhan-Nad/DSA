#include<stdio.h>

int front=-1,rear=-1;
const int size=10;
int queue[10];

void enqueue(int data)
{
    if ((front == 0 && rear == size-1) || 
            (rear == (front-1)%(size-1))) 
    { 
        printf("\nQueue is Full"); 
        return; 
    } 
  
    else if (front == -1) /* Insert First Element */
    { 
        front = rear = 0; 
        queue[rear] = data; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        queue[rear] = data; 
    } 
  
    else
    { 
        rear++; 
        queue[rear] = data; 
    } 
}

int dequeue()
{
    if(rear==-1)
    {
        printf("Queue is empty\n");
        return -99;
    }
    int data=queue[front];
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return data;
}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements are: ");
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ",queue[i]); 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", queue[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf("%d ", queue[i]); 
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
