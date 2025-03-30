#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* insertHead(Node *, int);

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

Node* insertHead(Node *n, int v) {

  if (n == NULL) {
    n = newNode(v);
    return n;
  }

  Node *head = newNode(v);
  head->next = n;
  return head;
}

int main() {
  int q, n, v;
  
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &n);
    Node *node = NULL;
    for (int j = 0; j < n; j++) {
      scanf("%d", &v);
      node = insertHead(node, v);
    }
    printList(node);
  }
  
  return 0;
}