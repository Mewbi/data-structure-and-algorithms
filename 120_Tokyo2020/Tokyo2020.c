#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int gold;
  int silver;
  int bronze;
} Country;

void printArr(Country *arr, int n) {
  Country c;
  for (int i = 0; i < n; i++) {
    c = arr[i];
    printf("%s %d %d %d\n",
           c.name,
           c.gold,
           c.silver,
           c.bronze);
  }
  return;
}

void freakyBubbleSort(Country *arr, int n) {
  Country aux;
  for (int i = 0; i < n; i++) {
    for (int  j = 0; j < n-1; j++) {
      if (arr[j].gold < arr[j+1].gold) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].gold > arr[j+1].gold) continue;


      if (arr[j].silver < arr[j+1].silver) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].silver > arr[j+1].silver) continue;
      
      if (arr[j].bronze < arr[j+1].bronze) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].bronze > arr[j+1].bronze) continue;

      if (strcmp(arr[j].name, arr[j+1].name) > 0){
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }
    }
  }

  return;
}

int main() {
  int n, gold, silver, bronze;
  Country *arr;

  scanf("%d", &n);

  arr = (Country*) malloc(n * sizeof(Country));

  for (int i = 0; i < n; i++) {

    char *name = (char*) malloc(110 * sizeof(char));
    scanf("%s %d %d %d", name, &gold, &silver, &bronze);

    Country *c = (Country*) malloc(sizeof(Country));
    c->name = name;
    c->gold = gold;
    c->silver = silver;
    c->bronze = bronze;

    arr[i] = *c;
  }

  freakyBubbleSort(arr, n);
  printArr(arr, n);

  return 0;
}
