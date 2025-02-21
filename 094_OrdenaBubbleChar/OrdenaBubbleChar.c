#include <stdio.h>

void printArray(char *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", arr[i]);
    if (i < n - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}

int bubbleSort(char *arr, int n) {
  int qtd = 0;
  char aux;
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
  int x, qtd;
  char v[2];

  scanf("%d", &x);

  char arr[x];
  for (int i = 0; i < x; i++) {
    scanf("%s", v);
    arr[i] = v[0];
  }

  printArray(arr, x);
  qtd = bubbleSort(arr, x);
  printArray(arr, x);
  printf("Trocas: %d\n", qtd);

  return 0;
}
