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

int removeHeap(Heap *h) {
  int rem;
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

void heapSort(Heap *h, int *arr) {
  int v;
  for (int i = h->qtd; i > 0; i--) {
    printHeap(h);
    v = removeHeap(h);
    arr[i-1] = v;
  }
}

void printArr(int *arr, int n, char c1) {
  for (int i = 0; i < n; i++) {
    printf("%d%c", arr[i], i < n-1 ? c1 : '\n');
  }
}

int main() {
  int n, x, *arr;
  Heap h;

  scanf("%d", &n);
  h = NewHeap(n);
  arr = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    insertHeap(&h, x);
  }
  printHeap(&h);
  buildHeap(&h);
  heapSort(&h, arr);
  printArr(arr, n, ' ');

  return 0;
}
