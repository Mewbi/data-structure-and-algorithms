#include <stdio.h>
#include <stdlib.h>

typedef struct {
  float *items;
  int size;
  int qtd;
} List;

List NewList(int n) {
  List l;

  l.items = (float*) malloc(n * sizeof(float));
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

int searchList(List l, float n) {

  for (int i = 0; i < l.qtd; i++) {
    if (l.items[i] == n) {
      return i;
    }
  }

  return -1;
}

void printList(List l) {
  float v;
  for (int i = 0; i < l.qtd; i++) {
    v = l.items[i];
    if (v == (int)v) {
        printf("%.0f%c", v, i < l.qtd -1 ? ' ': '\n');
    } else {
        printf("%.1f%c", v, i < l.qtd -1 ? ' ': '\n');
    }
  }
}

void insertList(List *l, float v) {
  if (isFull(*l)) return;

  if (searchList(*l, v) != -1) return;

  int i = 0;
  while (l->items[i] < v && i < l->qtd) {
    i++;
  }

  for (int j = l->qtd-1; j >= i; j--) {
    l->items[j+1] = l->items[j];
  }

  l->items[i] = v;
  l->qtd += 1;
  
  return;
}

void removeList(List *l, float v) {
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
  float v;
  char opc;
  List l;

  scanf("%d", &n);

  l = NewList(n);
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
      case 'I':
        scanf("%f", &v);
        insertList(&l, v);
        break;

      case 'M':
        printList(l);
        break;

      case 'R':
        scanf("%f", &v);
        removeList(&l, v);
        break;
      
      case 'B':
        scanf("%f", &v);
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
