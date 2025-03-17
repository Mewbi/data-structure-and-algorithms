#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **items;
  int size;
  int qtd;
} List;

List NewList(int n) {
  List l;

  l.items = (char**) malloc(n * sizeof(char*));
  l.size = n;
  l.qtd = 0;

  return l;
}

int isFull(List l) {
  return l.qtd == l.size;
}

int isEmpty(List l) {
  return l.qtd == 0;
}

int searchList(List l, char *n) {

  for (int i = 0; i < l.qtd; i++) {
    if ( strcmp(l.items[i], n) == 0 ) {
      return i;
    }
  }

  return -1;
}

void printList(List l) {
  for (int i = 0; i < l.qtd; i++) {
    printf("%s%c", l.items[i], i < l.qtd -1 ? ' ': '\n');
  }
}

void insertList(List *l, char *v) {
  if (isFull(*l)) return;

  if (searchList(*l, v) != -1) return;

  int i = 0;
  while (i < l->qtd && strcmp(l->items[i], v) < 0) {
    i++;
  }

  for (int j = l->qtd-1; j >= i; j--) {
    l->items[j+1] = l->items[j];
  }

  l->items[i] = v;
  l->qtd += 1;
  
  return;
}

void removeList(List *l, char *v) {
  if (isEmpty(*l)) return;

  int idx = searchList(*l, v);

  if (idx == -1) return;

  for(int i = idx; i < l->qtd-1; i++) {
    l->items[i] = l->items[i+1];
  }
  
  l->qtd -= 1;

  return;
}

int main() {
  int n, res;
  char *v;
  char opc;
  List l;

  scanf("%d", &n);

  l = NewList(n);
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
      case 'I':
        v = (char*) malloc(1010 * sizeof(char));
        scanf(" %s", v);
        insertList(&l, v);
        break;

      case 'M':
        printList(l);
        break;

      case 'R':
        v = (char*) malloc(1010 * sizeof(char));
        scanf(" %s", v);
        removeList(&l, v);
        break;
      
      case 'B':
        v = (char*) malloc(1010 * sizeof(char));
        scanf(" %s", v);
        if (searchList(l, v) != -1) {
          printf("SIM\n");
        } else {
          printf("NAO\n");
        }

        break;
    }
  }

  return 0;
}
