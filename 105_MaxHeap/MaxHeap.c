#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *items;
  int size;
  int qtd;
} Heap;

Heap NewHeap(int size) {
  Heap h;
  h.items = (int*) malloc(size * sizeof(int));
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
  int maior = p, aux;
  
  if (filhoDir(p) < h->size && h->items[filhoDir(p)] > h->items[maior]) {
    maior = filhoDir(p);
  }

  if (filhoEsq(p) < h->size && h->items[filhoEsq(p)] > h->items[maior]) {
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

void insertHeap(Heap *h, int n) {
  int idx = h->qtd;
  h->items[idx] = n;
  h->qtd++;
}

void printHeap(Heap *h) {
  for (int i = 0; i < h->qtd; i++) {
    printf("%d%c", h->items[i], i < h->qtd -1 ? ' ' : '\n');
  }
}

int main() {
  int n, x;
  Heap h;

  scanf("%d", &n);
  while (n != 0) {
    h = NewHeap(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      insertHeap(&h, x);
    }
    buildHeap(&h);
    printHeap(&h);

    scanf("%d", &n);
  }

  return 0;
}
