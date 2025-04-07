#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Item {
  int value;
  struct Item *prev;
} Item;

typedef struct {
  struct Item *top;  
} Stack;

Item* NewItem(int v) {
  Item *it = (Item*) malloc(sizeof(Item));
  it->value = v;
  it->prev = NULL;

  return it;
}

Stack* NewStack() {
  Stack *s = (Stack*) malloc(sizeof(Stack));
  s->top = NULL;

  return s;
}

int isEmpty(Stack *s) {
  return s->top == NULL;
}

Item* peek(Stack *s) {
  return s->top;
}

void push(Stack *s, Item *it) {
  it->prev = s->top;
  s->top = it;
}

Item* pop(Stack *s) {
  Item *it = peek(s);
  if (!isEmpty(s)) {
    s->top = it->prev;
    it->prev = NULL;
  }

  return it;
}
 
void printStack(Stack *s, char end) {
  Item *it = peek(s);
  while(it != NULL) {
    printf("%d%c", it->value, it->prev != NULL ? end : '\n');
    it = it->prev;
  }
  return;
}

void swap(Stack *a, Stack *b) {
  Item *tmp = a->top;
  a->top = b->top;
  b->top = tmp;
}

int isPrime(int n) {
  if (n <= 1) return 0;
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;

  int limit = (int) sqrt((double) n);
  limit += 1;

  for (int i = 5; i < limit; i += 6) {
    if (n % i == 0 || n % (i+2) == 0) return 0;
  }

  return 1;
}

int getNextPrime(int lastPrime) {

  int candidate = lastPrime + 1;

  while (1) {
    if (isPrime(candidate)) return candidate;
    candidate++;
  }
}

int main() {
  int n, r, v;
  Stack *stackA = NewStack();
  Stack *stackAux = NewStack();
  Stack *stackB = NewStack();
  int lastPrime = 0;
  int prime = 0;
  Item *it;

  scanf("%d %d", &n, &r);

  for (int i = 0; i < n;i++) {
    scanf("%d", &v);
    push(stackA, NewItem(v));
  }

  for (int i = 0; i < r && (!isEmpty(stackA) || !isEmpty(stackAux)); i++) {

    prime = getNextPrime(lastPrime);
    it = pop(stackA);
    while (it != NULL) {
      if (it->value % prime == 0) {
        push(stackB, it);
      } else {
        push(stackAux, it);
      }

      it = pop(stackA);
    }

    it = pop(stackB);
    while (it != NULL) {
      printf("%d\n", it->value);
      it = pop(stackB);
    }

    lastPrime = prime;
    swap(stackA, stackAux);
  }
  printStack(stackA, '\n');


  return 0;
}
