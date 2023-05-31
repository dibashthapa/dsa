#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 40

typedef struct Queue {
  int front;
  int rear;
  int elements[MAX_SIZE];
} Queue;

int is_full(Queue *q) {
  if (q->rear == MAX_SIZE - 1) {
    return 0;
  }
  return 1;
}

int is_empty(Queue *q) {
  if (q->front == -1) {
    return 0;
  }
  return 1;
}

Queue *initQueue() {
  Queue *new_queue = malloc(sizeof(Queue));

  if (new_queue != NULL) {
    new_queue->front = -1;
    new_queue->rear = -1;
  }

  return new_queue;
}

void enqueue(Queue *q, int element) {
  if (is_full(q) == 0) {
    printf("Queue is full");
  } else {
    q->rear += 1;
    q->elements[q->rear] = element;
  }
}

int main() {}
