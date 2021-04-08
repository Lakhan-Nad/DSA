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

Node *reverseList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *lastHead = NULL;
    Node *temp;
    while (head)
    {
        temp = head->next;
        head->next = lastHead;
        lastHead = head;
        head = temp;
    }
    return lastHead;
}