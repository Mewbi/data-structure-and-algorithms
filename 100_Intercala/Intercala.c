#include <stdio.h>
#include <stdlib.h>

void intercalate(int *arr1, int *arr2, int n1, int n2, int *res) {

  int i = 0;
  int j = 0;
  int k = 0;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      res[k] = arr1[i];
      i++;
    } else {
      res[k] = arr2[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    res[k] = arr1[i];
    i++;
    k++;
  }

  while (j < n2) {
    res[k] = arr2[j];
    j++;
    k++;
  }
}

int main() {

  int *n, *m;
  int n1, n2;

  scanf("%d", &n1);
  scanf("%d", &n2);

  n = (int*) malloc(n1 * sizeof(int));
  m = (int*) malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++) {
    scanf("%d", &n[i]);
  }

  for (int i = 0; i < n2; i++) {
    scanf("%d", &m[i]);
  }


  int *res = (int*) malloc((n1 + n2) * sizeof(int));
  intercalate(n, m, n1, n2, res);

  for (int i = 0; i < (n1 + n2); i++)
  {
    printf("%d\n", res[i]);
  }
  
  free(n);
  free(m);

  return 0;
}
