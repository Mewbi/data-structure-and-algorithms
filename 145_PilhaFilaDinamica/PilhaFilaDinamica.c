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
  if (q == NULL) return;

  ItemQ *it = first(q);
  while (it != NULL) {
    printf("%d\n", it->value);
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

int isEmptyS(Stack *s) {
  return s->top == NULL;
}

void push(Stack *s, ItemS *it) {
  it->prev = s->top;
  s->top = it;
}

ItemS* pop(Stack *s) {
  ItemS *it = peek(s);
  if (!isEmptyS(s)) {
    s->top = it->prev;
    it->prev = NULL;
  }

  return it;
}
 
void printStack(Stack *s) {
  ItemS *it = peek(s);
  while(it != NULL) {
    printf("%d\n", it->value);
    it = it->prev;
  }
  return;
}

void pushToQueue(Queue *q, ItemS *it) {
  if (it == NULL) return;
  enqueue(q, NewItemQ(it->value));
  if (it->prev != NULL) pushToQueue(q, it->prev);
}

Queue* convertStackToQueue(Stack *s) {
  Queue *q = NewQueue();
  ItemS *it = peek(s);
  pushToQueue(q, it);

  return q;
}

int main() {
  int v;
  char opc;
  Queue *q = NULL;
  Stack *s;
  ItemQ *it;

  s = NewStack();
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'E':
      scanf("%d", &v);
      push(s, NewItemS(v));
      break;

    case 'D':
      pop(s);
      break;

    case 'M':
      printQueue(q);
      break;
    
    case 'F':
      if (q != NULL) free(q);
      q = convertStackToQueue(s);
    }
  }
  return 0;
}
