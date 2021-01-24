/*
    A implementation of fixed buffer queue.
    This implemntation is inspired from the implementation of same in
    Node.js source code and can be found here [Node.js FixedBufferQueue](https://github.com/nodejs/node/blob/master/lib/internal/fixed_queue.js)
    For understanding better have a look at its source code.

    The idea of algorithm.

    1. We have a circular queue buffer of a max-size. These buffer works exactly like a
       circular queue. This is called a fixed_queue_buffer. These buffer maintain their own
       front and rear.
    2. All such buffers are joined using a singly linked-list. Which forms our main queue.
       These  linked-list has a head and tail and like a normal queue only allows insertion at tail
       and deletion from back.

    Benifits of using such a design:
        1. It allows for multiple deletion and insertion without 
            calling the expensive new/malloc operation, multiple times.
        2. At a time maximum of 2 * MAX_BUFFER_SIZE space is unused.
            (For the case when the head buffer has only one element present in its first
            end and rest MAX_BUFFER_SIZE - 1 elements are deleted and tail buffer has only 
            one element present in its top end and rest space in buffer is still unused.) 


    The diagram of the design can be 
           
        ------              ------              ------
        |next|------------->|next|->..........->|null|
        |----|              |----|              |----|
        |data|              |data|              |    |
        |data|              |data|       rear-->|data|
        |data|              |data|              |data|
        |data|       rear-->|data|              |data|
front-->|    |      front-->|data|  ..........  |data|
        |....|              |data|      front-->|    |   
        |    |              |....|              |    |
        |data|              |data|              |    |
 rear-->|data|              |data|              |    |
        |    |              |data|              |    |
        ------              ------              ------
          ^                                        ^
          |                                        |
        head                                      tail

        Note:-
            1) front points to the space where next data 
               should be added. rear points to the space 
               from where next data will be deleted. 
            2) All the middle buffers will always be full.
               In circular queue buffer is full when front 
               is just ahead of rear in circular fashion. 
            3) Since at max two buffers can have only single
               elements we can have max unused
               buffer of 2*MAX_BUFFER_SIZE 
            4) Head and tail points to same buffer in case of
               only one buffer. 
*/

// includes
#include <stdlib.h>  // -> malloc, free
#include <stdbool.h> // -> bool
#include <string.h>  // -> memcpy

typedef struct Fixed_Circular_Buffer
{
    int front;
    int rear;
    struct Fixed_Circular_Buffer *next;
    char *buffer;
    size_t mask;
    size_t data_size;
} Fixed_Circular_Buffer;

Fixed_Circular_Buffer *init_circular_buffer(size_t size, size_t recsize)
{
    Fixed_Circular_Buffer *new_buffer = (Fixed_Circular_Buffer *)malloc(sizeof(Fixed_Circular_Buffer));
    new_buffer->front = 0;
    new_buffer->rear = 0;
    new_buffer->next = NULL;
    new_buffer->mask = size == 0 ? 0 : size - 1;
    new_buffer->data_size = recsize;
    new_buffer->buffer = (char *)malloc(recsize * (new_buffer->mask + 1));
    return new_buffer;
}

bool is_circular_buffer_empty(Fixed_Circular_Buffer *this)
{
    return this->front == this->next;
}

bool is_circular_buffer_full(Fixed_Circular_Buffer *this)
{
    return ((this->front + 1) & this->mask) == this->rear;
}

size_t unused_circular_buffer(Fixed_Circular_Buffer *this)
{
    if (this->mask == 0)
    {
        return this->mask;
    }
    else if (this->front < this->rear)
    {
        return (this->mask + 1 - this->rear + this->front);
    }
    else if (this->rear < this->front)
    {
        return (this->front - this->rear);
    }
    return 0;
}

void enqueue_circular_buffer_safe(Fixed_Circular_Buffer *this, void *data)
{
    if (is_circular_buffer_full(this) || this->buffer == NULL)
    {
        return false;
    }
    memcpy(this->buffer[this->front * this->data_size], data, this->data_size);
    this->front = (this->front + 1) & this->mask;
    return true;
}

bool dequeue_circular_buffer_safe(Fixed_Circular_Buffer *this, void *data)
{
    if (is_circular_buffer_empty(this) || this->buffer == NULL)
    {
        return false;
    }
    memcpy(data, this->buffer, this->data_size);
    this->rear = (this->rear + 1) & this->mask;
    return true;
}

void enqueue_circular_buffer(Fixed_Circular_Buffer *this, void *data)
{
    memcpy(this->buffer[this->front * this->data_size], data, this->data_size);
    this->front = (this->front + 1) & this->mask;
}

void dequeue_circular_buffer(Fixed_Circular_Buffer *this, void *data)
{
    memcpy(data, this->buffer, this->data_size);
    this->rear = (this->rear + 1) & this->mask;
}

bool free_circular_buffer(Fixed_Circular_Buffer *this)
{
    if (this->buffer)
    {
        free(this->buffer);
    }
    this->data_size = 0;
    this->buffer = NULL;
    this->front = 0;
    this->rear = NULL;
    this->next = NULL;
}

typedef struct Fixed_Buffer_Queue
{
    Fixed_Circular_Buffer *head;
    Fixed_Circular_Buffer *tail;
} Fixed_Buffer_Queue;

void fixed_queue_init(Fixed_Buffer_Queue *this, size_t size, size_t recsize)
{
    // initialize once
    this->head = this->tail = init_circular_buffer(size, recsize);
}

void fixed_queue_in(Fixed_Buffer_Queue *this, void *data)
{
    if (is_circular_buffer_full(this->tail))
    {
        this->tail->next = init_circular_buffer(this->tail->mask + 1, this->tail->data_size);
        this->tail = this->tail->next;
    }
    enqueue_circular_buffer(this->tail, data);
}

void fixed_queue_out(Fixed_Buffer_Queue *this, void *data_store)
{
    if (is_circular_buffer_empty(this->head))
    {
        return;
    }
    dequeue_circular_buffer(this->head, data_store);
    if (is_circular_buffer_empty(this->head))
    {
        if (this->head->next)
        {
            this->head = this->head->next;
        }
    }
}

void fixed_queue_free(Fixed_Buffer_Queue *this)
{
    Fixed_Buffer_Queue *temp;
    while (this->head)
    {
        temp = this->head->next;
        free_circular_buffer(this->head);
        this->head = temp;
    }
    this->head = NULL;
    this->tail = NULL;
}