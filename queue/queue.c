#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Queue {
  int front;
  int elements[MAX_SIZE];
  int rear;
} Queue;

bool is_empty(Queue *q) { return q->front == -1 && q->rear == -1; }

bool is_full(Queue *q) { return q->rear >= MAX_SIZE - 1; }

void enqueue(Queue *q, int element) {
  if (is_full(q)) {
    printf("Queue overflow\n");
    return;
  }
  if (is_empty(q)) {
    q->front = q->rear = 0;
  } else {
    q->rear += 1;
  }

  q->elements[q->rear] = element;
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue underflow\n");
    return -1;
  }

  int dequeued_element = q->elements[q->front];

  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front += 1;
  }

  return dequeued_element;
}

void printQueue(Queue *q) {
  while (!is_empty(q)) {
    int d = dequeue(q);
    printf("%d\n", d);
  }
}

int main() {
  Queue q;
  q.rear = -1;
  q.front = -1;
  enqueue(&q, 10);
  enqueue(&q, 10);
  enqueue(&q, 10);
  enqueue(&q, 10);
  printQueue(&q);
}
