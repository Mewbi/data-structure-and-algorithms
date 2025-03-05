#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n, char c1) {
  for (int i = 0; i < n; i++) {
    printf("%d%c", arr[i], i < n-1 ? c1 : '\n');
  }
}

int particiona(int *arr, int init, int end, int n) {
  
  int aux;
  int pm = init - 1;
  int pivot = end;

  for (int i = init; i < end; i++) {
    if (arr[i] <= arr[pivot]) {
      pm++;
      aux = arr[pm];
      arr[pm] = arr[i];
      arr[i] = aux;
    }
    printArr(arr, n, ' ');
  }

  pm++;
  aux = arr[pm];
  arr[pm] = arr[pivot];
  arr[pivot] = aux;
  printArr(arr, n, ' ');

  return pm;
}

void quickSort(int *arr, int init, int end, int n) {
  int pivot;
  if (init < end) {
    pivot = particiona(arr, init, end, n);
    quickSort(arr, init, pivot-1, n);
    quickSort(arr, pivot+1, end, n);
  }
}

int main() {
  int n, *arr;

  scanf("%d", &n);

  arr = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printArr(arr, n, ' ');
  quickSort(arr, 0, n-1, n);
  printArr(arr, n, ' ');

  return 0;
}

