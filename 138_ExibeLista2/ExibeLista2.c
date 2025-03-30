#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* insertTail(Node *, int);
void printReverseList(Node *);

Node* newNode(int value) {
  Node *n = (Node*) malloc(sizeof(Node));
  n->value = value;
  n->next = NULL;
  return n;
}

void printReverseList(Node *n) {
  if (n != NULL) {
    printReverseList(n->next);
    printf("%d\n", n->value);
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

int main() {
  int q, n, v;
  
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &n);
    Node *node = NULL;
    for (int j = 0; j < n; j++) {
      scanf("%d", &v);
      node = insertTail(node, v);
    }
    printReverseList(node);
  }
  
  return 0;
}