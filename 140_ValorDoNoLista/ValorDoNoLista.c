#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

int getNode(Node *, int);

Node* newNode(int value) {
  Node *n = (Node*) malloc(sizeof(Node));
  n->value = value;
  n->next = NULL;
  return n;
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

void getNodeDepth(Node *n, int p, int *depth, int *res) {
  if (n->next != NULL) {
    getNodeDepth(n->next, p, depth, res);
  }

  if (*depth == p) {
    *res = n->value; 
  }

  *depth += 1;

  return;
}

int getNode(Node *n, int p) {
  int depth = 0, res;
  getNodeDepth(n, p, &depth, &res);
  return res;
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
      scanf("%d", &p);
      v = getNode(node, p);  
      printf("%d\n", v);
    }
  }
  
  return 0;
}