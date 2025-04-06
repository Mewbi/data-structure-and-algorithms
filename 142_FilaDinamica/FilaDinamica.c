#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  int value;
  struct Item *next;
} Item;

typedef struct {
  Item *first;
  Item *last;
} Queue;

Item* NewItem(int v) {
  Item *it = (Item*) malloc(sizeof(Item));
  it->value = v;
  it->next = NULL;

  return it;
}

Queue* NewQueue() {
  Queue *q = (Queue*) malloc(sizeof(Queue));
  q->first = NULL;
  q->last = NULL;
  return q;
}

int isEmpty(Queue *q) {
  return q->first == NULL && q->last == NULL;
}

Item *first(Queue *q) {
  return q->first;
}

Item *last(Queue *q) {
  return q->last;
}

void enqueue(Queue *q, Item *it) {
  if (isEmpty(q)) {
    q->first = it;
  } else {
    q->last->next = it;
  }
  q->last = it;
}

Item* dequeue(Queue *q) {
  Item *it = first(q);
  if (!isEmpty(q)) {
    q->first = it->next;
    if (q->first == NULL) {
      q->last = NULL;
    }
    it->next = NULL;
  }

  return it;
}

void printQueue(Queue *q) {
  Item *it = first(q);
  while (it != NULL) {
    printf("%d%c", it->value, it->next != NULL ? ' ': '\n');
    it = it->next;
  }
}

int main() {
  int v;
  char opc;
  Queue *q;
  Item *it;

  q = NewQueue();
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'E':
      scanf("%d", &v);
      enqueue(q, NewItem(v));
      break;

    case 'D':
      it = dequeue(q);
      if (it != NULL) printf("<%d>\n", it->value);
      break;

    case 'M':
      printQueue(q);
      break;
    }
  }
  return 0;
}