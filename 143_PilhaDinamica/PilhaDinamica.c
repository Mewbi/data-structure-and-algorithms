#include <stdio.h>
#include <stdlib.h>

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
 
void printStack(Stack *s) {
  Item *it = peek(s);
  while(it != NULL) {
    printf("%d%s", it->value, it->prev != NULL?" ":"\n");
    it = it->prev;
  }
  return;
}

int main() {
  int v;
  char opc;
  Stack *s;
  Item *it;

  s = NewStack();

  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
      case 'E':
        scanf("%d", &v);
        push(s, NewItem(v));
        break;

      case 'D':
        it = pop(s);
        if (it != NULL) printf("[%d]\n", it->value);
        break;

      case 'M':
        printStack(s);
        break;
    }
  }

  return 0;
}