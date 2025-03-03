#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n, char c1) {
  for (int i = 0; i < n; i++) {
    printf("%d%c", arr[i], i < n-1 ? c1 : '\n');
  }
}

void particiona(int *arr, int init, int end) {
  
  int aux;
  int pm = init - 1;
  int pivot = end - 1;

  for (int i = init; i < end-1; i++) {
    if (arr[i] <= arr[pivot]) {
      pm++;
      aux = arr[pm];
      arr[pm] = arr[i];
      arr[i] = aux;
    }
  }

  pm++;
  aux = arr[pm];
  arr[pm] = arr[pivot];
  arr[pivot] = aux;
}


int main() {
  int *arr, q, p, pivotAnt;

  scanf("%d", &q);
  scanf("%d", &p);

  arr = (int*) malloc(q * sizeof(int));
  for (int i = 0; i < q; i++) {
    scanf("%d", &arr[i]);
  }

  // move pivot
  int aux = arr[p];
  arr[p] = arr[q-1];
  arr[q-1] = aux;

  particiona(arr, 0, q);
  printArr(arr, q, '\n');

  return 0;
}
