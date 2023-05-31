#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Stack {
  int elements[MAX_SIZE];
  int tos;
} Stack;

Stack *initStack() {
  Stack *new_stack = malloc(sizeof(Stack));

  if (new_stack != NULL) {
    new_stack->tos = -1;
  }

  return new_stack;
};

int is_full(Stack *s) {
  if (s->tos == MAX_SIZE - 1) {
    return 0;
  }
  return 1;
}

int is_empty(Stack *s) {
  if (s->tos == -1) {
    return 0;
  }
  return 1;
}

void push(Stack *s, int element) {
  if (is_full(s) == 0) {
    printf("STACK OVERFLOW");
    exit(1);
  } else {
    s->tos += 1;
    s->elements[s->tos] = element;
  }
}

int pop(Stack *s) {
  if (is_empty(s) == 0) {
    printf("STACK UNDERFLOW");
    exit(1);
  } else {
    s->tos -= 1;

    return s->elements[s->tos + 1];
  }
}

void printStack(Stack *s) {
  for (int i = 0; i <= s->tos; i++) {
    printf("%d\t", s->elements[i]);
  }
  printf("\n");
}

void destroyStack(Stack *s) { free(s); }
int main() {
  Stack *stack = initStack();
  int removed;

  push(stack, 1);
  removed = pop(stack);
  printf("removed is %d \n", removed);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  push(stack, 6);
  push(stack, 7);
  removed = pop(stack);
  printf("removed is %d \n", removed);
  push(stack, 8);
  push(stack, 8);
  push(stack, 8);
  push(stack, 8);
  push(stack, 8);
  push(stack, 8);
  push(stack, 8);

  printStack(stack);
  destroyStack(stack);
  return 0;
}
