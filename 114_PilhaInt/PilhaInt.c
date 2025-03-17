#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *items;
  int size;
  int qtd;
} Stack;

Stack NewStack(int n) {
  Stack s;

  s.items = (int*) malloc(n * sizeof(int));
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

int peek(Stack s) {
  if (isEmpty(s)) return -1;
  return s.items[s.qtd];
}

void printStackBottomUp(Stack s) {
  for (int i = 0; i <= s.qtd; i++) {
    printf("%d%c", s.items[i], i < s.qtd ? ' ': '\n');
  }
}

void printStackUpBottom(Stack s) {
  for (int i = s.qtd; i >= 0; i--) {
    printf("%d%c", s.items[i], i > 0 ? ' ': '\n');
  }
}

void push(Stack *s, int v) {
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
  int n, v, res;
  char opc;
  Stack s;

  scanf("%d", &n);

  s = NewStack(n);
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
      case 'E':
        scanf("%d", &v);
        push(&s, v);
        break;

      case 'D':
        pop(&s);
        break;

      case 'T':
        res = peek(s);
        if (res != -1) {
          printf("%d\n", res);
        }
        
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
