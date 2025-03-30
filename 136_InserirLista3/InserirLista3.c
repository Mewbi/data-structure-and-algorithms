#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* insertPosition(Node *, int, int);

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

Node* insertPosition(Node *n, int v, int p) {

  if (n == NULL) return newNode(v);
  
  Node *prev = NULL;
  Node *actual = n;
  for (int i = 0; i < p; i++) {
    prev = actual;
    actual = actual->next;
  }
  
  Node *new = newNode(v);
  new->next = actual;

  if (prev == NULL) {
    prev = new;
    return prev;
  }

  prev->next = new;
  return n;
}

int main() {
  int n, p, v;
  Node *node = NULL;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &v, &p);
    node = insertPosition(node, v, p);
  }
  printList(node);

  return 0;
}