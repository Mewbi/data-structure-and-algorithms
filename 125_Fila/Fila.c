#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int size;
    int init;
    int end;
} Queue;

Queue NewQueue(int n) {
    Queue q;

    q.items = (int*) malloc(n * sizeof(int));
    q.size = n;
    q.init = 0;
    q.end = -1;

    return q;
}

int isFull(Queue q) {
    return q.end == q.size -1;
}

int isEmpty(Queue q) {
    return q.init > q.end;
}

void enqueue(Queue *q, int n) {
    if (isFull(*q)) return;

    q->end++;
    q->items[q->end] = n;

    return;
}

void dequeue(Queue *q) {
    // No items to dequeue
    if (isEmpty(*q)) return;

    printf("%d\n", q->items[q->init]);
    q->init++;

    // We need reset queue
    if (isEmpty(*q)) {
        *q = NewQueue(q->size);
    }

    return;
}

int main() {
    int n, v;
    char opc;
    Queue q;

    scanf("%d", &n);

    q = NewQueue(n);
    while (scanf("%c", &opc) != EOF) {
        switch (opc) {
        case 'E':
            scanf("%d", &v);
            enqueue(&q, v);
            break;

        case 'D':
            dequeue(&q);
            break;
        }
    }
    return 0;
}