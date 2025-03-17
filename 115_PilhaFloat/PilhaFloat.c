#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float *items;
  int size;
  int qtd;
} Stack;

Stack NewStack(int n) {
  Stack s;

  s.items = (float*) malloc(n * sizeof(float));
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

float peek(Stack s) {
  return s.items[s.qtd];
}

void printStackBottomUp(Stack s) {
  float v;
  for (int i = 0; i <= s.qtd; i++) {
    v = s.items[i];
    if (v == (int)v) {
        printf("%.0f%c", v, i < s.qtd ? ' ': '\n');
    } else {
        printf("%.1f%c", v, i < s.qtd ? ' ': '\n');
    }
  }
}

void printStackUpBottom(Stack s) {
  float v;
  for (int i = s.qtd; i >= 0; i--) {
    v = s.items[i];
    if (v == (int)v) {
        printf("%.0f%c", v, i > 0 ? ' ': '\n');
    } else {
        printf("%.1f%c", v, i > 0 ? ' ': '\n');
    }
  }
}

void push(Stack *s, float v) {
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
  float v, res;
  char opc;
  Stack s;

  scanf("%d", &n);

  s = NewStack(n);
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
      case 'E':
        scanf("%f", &v);
        push(&s, v);
        break;

      case 'D':
        pop(&s);
        break;

      case 'T':
        if (isEmpty(s)) break;
        res = peek(s);
        if (res == (int)res) {
          printf("%.0f\n", res);
        } else {
          printf("%.1f\n", res);
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
