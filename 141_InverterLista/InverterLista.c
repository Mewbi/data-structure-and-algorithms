#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* reverseList(Node *);

Node* newNode(int value) {
  Node *n = (Node*) malloc(sizeof(Node));
  n->value = value;
  n->next = NULL;
  return n;
}

void printList(Node *n) {
  while (n != NULL) {
    printf("%d%c", n->value, n->next != NULL ? ' ' : '\n');
    n = n->next;
  }
}


Node* insertTail(Node *n, int v) {

  if (n == NULL) return newNode(v);
  
  Node *actual = n;
  while (actual->next != NULL) {
    actual = actual->next;
  }
  actual->next = newNode(v);
  return n;
}

Node* insertHead(Node *n, int v) {

  if (n == NULL) {
    n = newNode(v);
    return n;
  }

  Node *head = newNode(v);
  head->next = n;
  return head;
}

Node* reverseList(Node *n) {
  if (n == NULL) return NULL;

  Node *rev = NULL;
  while (n != NULL) {
    rev = insertHead(rev, n->value);
    n = n->next;
  }

  return rev;
}

int main() {
  int q, n, v, p;
  
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &n);
    Node *node = NULL;
    for (int j = 0; j < n; j++) {
      scanf("%d", &v);
      node = insertTail(node, v);
    }
    if (node != NULL) {
      node = reverseList(node);  
      printList(node);
    }
  }
  
  return 0;
}