#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  return newNode;
}

Node *insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->data = data;
  if (*head == NULL) {
    *head = newNode;
  } else {
    newNode->next = *head;
    *head = newNode;
  }
  return *head;
}

void printList(Node **head) {
  Node *current = *head;
  while (current != NULL) {
    printf("%d \n", current->data);
    current = current->next;
  }
}

int pop(Node **head) {
  if (head == NULL) {
    printf("Stack is empty");
    return -1;
  }
  Node *temp = *head;
  Node *next = (*head)->next;
  int popped = temp->data;
  free(temp);
  *head = next;
  return popped;
}

int main() {
  Node *head = NULL;
  insertAtBeginning(&head, 4);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 5);
  pop(&head);
  printList(&head);

  return 0;
}
