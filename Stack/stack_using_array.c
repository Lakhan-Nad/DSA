#include <stdio.h>

#define SUCCESS 1
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2
#define STACK_UNINITIALZED 0

#define MAX_SIZE 100

typedef struct stack {
  int arr[MAX_SIZE];
  int top;
} stack;

int initialize(stack *s) {
  if (s == NULL) {
    return STACK_UNINITIALZED;
  }
  s->top == -1;
  int i;
  for (i = 0; i < MAX_SIZE; i++) {
    s->arr[i] = 0;
  }
  return SUCCESS;
}

int push(stack *s, int value) {
  if (s == NULL) {
    return STACK_UNINITIALZED;
  }
  if (s->top < MAX_SIZE - 1) {
    s->top = s->top + 1;
    s->arr[s->top] = value;
    return SUCCESS;
  } else {
    return STACK_OVERFLOW;
  }
}

int pop(stack *s) {
  if (s == NULL) {
    return STACK_UNINITIALZED;
  }
  if (s->top > 0) {
    s->arr[s->top] = 0;
    s->top = s->top - 1;
    return SUCCESS;
  } else {
    return STACK_UNDERFLOW;
  }
}

int top(stack *s) {
  if (s == NULL) {
    return STACK_UNINITIALZED;
  }
  if (s->top > 0) {
    return s->arr[s->top];
  } else {
    return STACK_UNDERFLOW;
  }
}

void main() { stack s; }
