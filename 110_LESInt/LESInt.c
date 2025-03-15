#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *items;
  int size;
  int qtd;
} List;

List NewList(int n) {
  List l;

  l.items = (int*) malloc(n * sizeof(int));
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

int searchList(List l, int n) {

  for (int i = 0; i < l.qtd; i++) {
    if (l.items[i] == n) {
      return i;
    }
  }

  return -1;


int main() {


  return 0;
}
