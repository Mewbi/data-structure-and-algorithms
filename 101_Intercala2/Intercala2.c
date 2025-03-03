#include <stdio.h>
#include <stdlib.h>

void intercala(int *arr, int n1, int n2, int *res) {
  int i = 0;
  int j = n1;
  int k = 0;

  n2 = n1 + n2;

  while (i < n1 && j < n2) {
    if (arr[i] < arr[j]) {
      res[k] = arr[i];
      i++;
    } else {
      res[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    res[k] = arr[i];
    i++;
    k++;
  }

  while (j < n2) {
    res[k] = arr[j];
    j++;
    k++;
  }
}

int main() {
  int *arr, *res, n1, n2;

  scanf("%d", &n1);
  scanf("%d", &n2);

  arr = (int*) malloc((n1 + n2) * sizeof(int));
  res = (int*) malloc((n1 + n2) * sizeof(int));
  for (int i = 0; i < n1 + n2; i++) {
    scanf("%d", &arr[i]);
  }

  intercala(arr, n1, n2, res);

  for (int i = 0; i < n1 + n2; i++) {
    printf("%d\n", res[i]);
  }

  return 0;
}
