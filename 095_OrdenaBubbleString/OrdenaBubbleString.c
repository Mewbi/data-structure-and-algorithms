#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char **arr, int n) {

    for (int i = 0; i < n; i++) {
        printf("%s", arr[i]);
        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

int bubbleSort(char **arr, int n) {
    int qtd = 0;
    char *aux;
    for (int i = 0; i < n; i++) {
        for (int  j = 0; j < n-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
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

  scanf("%d", &x);

  char **arr;
  arr = (char**) malloc(x * sizeof(char*));

  for (int i = 0; i < x; i++) {
    arr[i] = (char*) malloc(100 * sizeof(char));
    scanf("%s", arr[i]);
  }

  printArray(arr, x);
  qtd = bubbleSort(arr, x);
  printArray(arr, x);
  printf("Trocas: %d\n", qtd);

  return 0;
}
