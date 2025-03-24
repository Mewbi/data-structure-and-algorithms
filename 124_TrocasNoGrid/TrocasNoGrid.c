#include <stdio.h>
#include <stdlib.h>

int bubbleSort(double *arr, int n) {
  int qtd = 0;
  double aux;
  for (int i = 0; i < n; i++) {
    for (int  j = 0; j < n-(i+1); j++) {
      if (arr[j] > arr[j+1]) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        qtd++;
      }
    }
  }

  return qtd;
}

int main() {
  int n, carNum, res;
  char name[50];
  char team[50];


  scanf("%d", &n);

  double *arr = (double*) malloc(n * sizeof(double));

  for (int i = 0; i < n; i++) {
    scanf("%d %s %s %lf", &carNum, name, team, &arr[i]);
  }

  res = bubbleSort(arr, n);
  
  printf("%d\n", res);

  return 0;
}
