#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *createNode(int data) {
  struct ListNode *newNode = malloc(sizeof(struct ListNode));
  newNode->val = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(struct ListNode **headRef, int data) {
  struct ListNode *newNode = createNode(data);

  if (*headRef == NULL) {
    *headRef = newNode;
  } else {
    struct ListNode *current = *headRef;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = newNode;
  }
}
int pop(struct ListNode **head) {
  if (*head == NULL) {
    printf("Error: The linked list is empty. Cannot pop.\n");
    return -1;
  }

  int data = (*head)->val;
  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
  return data;
}

void push(struct ListNode **headRef, int data) {
  struct ListNode *newNode = createNode(data);
  newNode->next = *headRef;
  *headRef = newNode;
}

void printPoppedList(struct ListNode *head) {
  struct ListNode *current = head;
  while (current != NULL) {
    current = current->next;
  }
  printf("NULL\n");
}
int main() {
  struct ListNode *head = NULL;
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  struct ListNode *current = head;

  while (head->next != NULL) {
    insertAtBeginning(&head, pop(&head));
  }

  printList();
}
