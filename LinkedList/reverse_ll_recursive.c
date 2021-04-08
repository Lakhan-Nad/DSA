#include <stdlib.h> // for NULL

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct LinkedList
{
    Node *head;
} LinkedList;

Node *reverseListUtil(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *temp = reverseListUtil(head->next);
    temp->next = head;
    return temp;
}

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    return reverseListUtil(head);
}