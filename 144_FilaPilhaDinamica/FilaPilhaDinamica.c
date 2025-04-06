#include <stdio.h>
#include <stdlib.h>

typedef struct ItemQ {
  int value;
  struct ItemQ *next;
} ItemQ;

typedef struct {
  ItemQ *first;
  ItemQ *last;
} Queue;

ItemQ* NewItemQ(int v) {
  ItemQ *it = (ItemQ*) malloc(sizeof(ItemQ));
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

ItemQ *first(Queue *q) {
  return q->first;
}

ItemQ *last(Queue *q) {
  return q->last;
}


void enqueue(Queue *q, ItemQ *it) {
  if (isEmpty(q)) {
    q->first = it;
  } else {
    q->last->next = it;
  }
  q->last = it;
}

ItemQ* dequeue(Queue *q) {
  ItemQ *it = first(q);
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
  ItemQ *it = first(q);
  while (it != NULL) {
    printf("%d%c", it->value, it->next != NULL ? ' ': '\n');
    it = it->next;
  }
}

typedef struct ItemS {
  int value;
  struct ItemS *prev;
} ItemS;

typedef struct {
  struct ItemS *top;  
} Stack;

ItemS* NewItemS(int v) {
  ItemS *it = (ItemS*) malloc(sizeof(ItemS));
  it->value = v;
  it->prev = NULL;

  return it;
}

Stack* NewStack() {
  Stack *s = (Stack*) malloc(sizeof(Stack));
  s->top = NULL;

  return s;
}  

ItemS* peek(Stack *s) {
  return s->top;
}

void push(Stack *s, ItemS *it) {
  it->prev = s->top;
  s->top = it;
}
 
void printStack(Stack *s) {
  ItemS *it = peek(s);
  while(it != NULL) {
    printf("%d\n", it->value);
    it = it->prev;
  }
  return;
}

void pushToStack(Stack *s, ItemQ *it) {
  if (it == NULL) return;
  if (it->next != NULL) pushToStack(s, it->next);
  push(s, NewItemS(it->value));
}

Stack* convertQueueToStack(Queue *q) {
  Stack *s = NewStack();

  ItemQ *it = first(q);
  pushToStack(s, it);

  return s;
}

int main() {
  int v;
  char opc;
  Queue *q;
  Stack *s = NULL;
  ItemQ *it;

  q = NewQueue();
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'E':
      scanf("%d", &v);
      enqueue(q, NewItemQ(v));
      break;

    case 'D':
      dequeue(q);
      break;

    case 'M':
      printStack(s);
      break;
    
    case 'P':
      if (s != NULL) free(s);
      s = convertQueueToStack(q);
    }
  }
  return 0;
}