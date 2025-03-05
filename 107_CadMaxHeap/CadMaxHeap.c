#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long int *items;
  int size;
  int qtd;
} Heap;

Heap NewHeap(int size) {
  Heap h;
  h.items = (long int*) malloc(size * sizeof(long int));
  h.size = size;
  h.qtd = 0;
  return h;
}

int filhoEsq(int p) {
  return (p * 2) + 1;
}

int filhoDir(int p) {
  return (p * 2) + 2;
}

int pai(int f) {
  return (f - 1) / 2;
}

int ultimoPai(int n) {
  return (n / 2) - 1;
}

void peneirar(Heap *h, int p) {
  int maior = p;
  long int aux;

  if (filhoDir(p) < h->qtd && h->items[filhoDir(p)] > h->items[maior]) {
    maior = filhoDir(p);
  }

  if (filhoEsq(p) < h->qtd && h->items[filhoEsq(p)] > h->items[maior]) {
    maior = filhoEsq(p);
  }
  

  if (maior != p) {
    aux = h->items[maior];
    h->items[maior] = h->items[p];
    h->items[p] = aux;
    peneirar(h, maior);
  }
}

void buildHeap(Heap *h) {
  for (int i = ultimoPai(h->size); i >= 0; i--) {
    peneirar(h, i);
  }
}

void insertHeap(Heap *h, long int n) {
  if (h->qtd < h->size) {
    int idx = h->qtd;
    h->items[idx] = n;
    h->qtd++;

    if (h->items[idx] > h->items[pai(idx)]) {
      buildHeap(h);
    }
  }
}

long int removeHeap(Heap *h) {
  long int rem;
  if (h->qtd > 0) {
    rem = h->items[0];
    h->items[0] = h->items[h->qtd-1];
    h->items[h->qtd-1] = rem;
    h->qtd--;
    peneirar(h, 0);
    return rem;
  }

  return -1;
}

void printHeap(Heap *h) {
  for (int i = 0; i < h->qtd; i++) {
    printf("%ld%c", h->items[i], i < h->qtd -1 ? ' ' : '\n');
  }
}

int main() {
  int n;
  long int x;
  char command;
  Heap h;

  scanf("%d", &n);
  h = NewHeap(n);
  while (scanf("%c", &command) != EOF) {
    switch (command) {
      case 'I':
        scanf("%ld", &x);
        insertHeap(&h, x);
        break;

      case 'M':
        printHeap(&h);
        break;

      case 'R':
        x = removeHeap(&h);
        if (x != -1) {
          printf("%d\n", x);
        }
        break;
    }
  }

  return 0;
}
