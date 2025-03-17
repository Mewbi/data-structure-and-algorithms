#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char **items;
  int size;
  int qtd;
} Stack;

Stack NewStack(int n) {
  Stack s;

  s.items = (char**) malloc(n * sizeof(char*));
  s.size = n;
  s.qtd = -1;

  return s;
}

int isFull(Stack s) {
  return s.qtd == s.size-1;
}

int isEmpty(Stack s) {
  return s.qtd == -1;
}

char* peek(Stack s) {
  return s.items[s.qtd];
}

void printStackBottomUp(Stack s) {
  for (int i = 0; i <= s.qtd; i++) {
    printf("%s%c", s.items[i], i < s.qtd ? ' ': '\n');
  }
}

void printStackUpBottom(Stack s) {
  for (int i = s.qtd; i >= 0; i--) {
    printf("%s%c", s.items[i], i > 0 ? ' ': '\n');
  }
}

void push(Stack *s, char *v) {
  if (isFull(*s)) return;

  s->items[++s->qtd] = v;
  
  return;
}

void pop(Stack *s) {
  if (isEmpty(*s)) return;
  
  s->qtd -= 1;

  return;
}

int main() {
  int n;
  char *v;
  char opc;
  Stack s;

  scanf("%d", &n);

  s = NewStack(n);
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
      case 'E':
        v = (char*) malloc(1010 * sizeof(char));
        scanf(" %s", v);
        push(&s, v);
        break;

      case 'D':
        pop(&s);
        break;

      case 'T':
        if (isEmpty(s)) break;
        printf("%s\n", peek(s));
        break;
      
      case 'X':
        printStackUpBottom(s);
        break;
      
      case 'B':
        printStackBottomUp(s);
        break;
    }
  }

  return 0;
}
