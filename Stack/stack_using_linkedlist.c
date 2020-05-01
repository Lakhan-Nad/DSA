#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct stack {
  node *top;
  int size;
} stack;

void push(stack *s, int data) {
  if (s->top == NULL) {
    s->size = 0;
  }
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = s->top;
  s->top = newNode;
  s->size++;
}

void pop(stack *s) {
  if (s->top != NULL) {
    node *temp = s->top;
    s->top = s->top->next;
    s->size--;
    free(temp);
  }
}

int atTop(stack *s) {
  if (s->top == NULL) {
    return NULL;
  } else {
    return s->top->data;
  }
}

void updateTop(stack *s, int data) {
  if (s->top != NULL) {
    s->top->data = data;
  }
}

void main() {}