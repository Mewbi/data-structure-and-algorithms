#include <stdio.h>

void printArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}

int bubbleSort(int *arr, int n) {
  int aux, qtd = 0;
  for (int i = 0; i < n; i++) {
    for (int  j = 0; j < n-1; j++) {
      if (arr[j] > arr[j+1]) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        qtd++;
        printArray(arr, n);
      }
    }
  }

  return qtd;
}

int main() {
  int x, v, qtd;

  scanf("%d", &x);

  int arr[x];
  for (int i = 0; i < x; i++) {
    scanf("%d", &v);
    arr[i] = v;
  }

  printArray(arr, x);
  qtd = bubbleSort(arr, x);
  printArray(arr, x);
  printf("Trocas: %d\n", qtd);

  return 0;
}
