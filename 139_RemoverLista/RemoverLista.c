#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* deletePosition(Node *, int);

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

Node* deletePosition(Node *n, int p) {
  if (n == NULL) return NULL;
  
  Node *prev = NULL;
  Node *actual = n;
  for (int i = 0; i < p; i++) {
    prev = actual;
    actual = actual->next;
  }
  
  if (prev == NULL) {
    return actual->next;
  }

  prev->next = actual->next;
  return n;
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
    scanf("%d", &p);
    node = deletePosition(node, p);
    printList(node);
  }
  
  return 0;
}