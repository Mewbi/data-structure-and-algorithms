#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *items;
  int size;
  int qtd;
} Stack;

Stack NewStack(int n) {
  Stack s;

  s.items = (char*) malloc(n * sizeof(char));
  s.size = n;
  s.qtd = -1;

  return s;
}

int isEmpty(Stack s) {
  return s.qtd == -1;
}

void push(Stack *s, char v) {
  s->items[++s->qtd] = v;
  
  return;
}

int pop(Stack *s) {
  if (isEmpty(*s)) return -1;
  
  s->qtd -= 1;

  return 0;
}

int processText(Stack *s, char *text) {
  char v;
  for (int i = 0; i < strlen(text); i++) {
    v = text[i];
    if (v == '{') {
      push(s, '{');
    } else if (v == '}') {
      if (pop(s) == -1) {
        return -1;
      }
    }
  }

  return 0;
  
}

int main() {
  int n, res;
  char *line;
  
  Stack s = NewStack(100000);

  scanf("%d", &n);

  line = (char*) malloc(1024 * sizeof(char));
  
  while (fgets(line,1024,stdin)) {
    line[strcspn(line,"\n")]='\0';
    res = processText(&s, line);
    if (res == -1) {
      printf("N\n");
      return 0;
    }
  }
  
  if (s.qtd != -1) {
    printf("N\n");
  } else {
    printf("S\n");
  }
  
  
  return 0;
}
