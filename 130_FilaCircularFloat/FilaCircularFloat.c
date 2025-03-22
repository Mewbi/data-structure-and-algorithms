#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float *items;
  int size;
  int init;
  int end;
} CircularQueue;

CircularQueue NewCircularQueue(int n) {
  CircularQueue q;

  q.items = (float*) malloc(n * sizeof(float));
  q.size = n;
  q.init = 0;
  q.end = 0;

  return q;
}

int isNotFull(CircularQueue q) {
  return (q.end+1) % q.size != q.init;
}

int isEmpty(CircularQueue q) {
  return q.init == q.end;
}

void enqueue(CircularQueue *q, float n) {
  if (!isNotFull(*q)) return;

  q->items[q->end] = n;
  q->end = (q->end+1) % q->size;

  return;
}

void dequeue(CircularQueue *q) {
  // No items to dequeue
  if (isEmpty(*q)) return;

  printf("%.2f\n", q->items[q->init]);
  q->init = (q->init+1) % q->size;

  return;
}

int main() {
  int n;
  float v;
  char opc;
  CircularQueue q;

  scanf("%d", &n);

  q = NewCircularQueue(n);
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'E':
      scanf("%f", &v);
      enqueue(&q, v);
      break;

    case 'D':
      dequeue(&q);
      break;
    }
  }
  return 0;
}