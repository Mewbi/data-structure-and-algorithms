#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercalate(char *arr1, char *arr2, char *res) {

  int i = 0, j = 0, k = 0;
  int n1 = strlen(arr1);
  int n2 = strlen(arr2);

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

  char *n, *m;
  int n1, n2;

  scanf("%d", &n1);
  n = (char*) malloc(10 + n1 * sizeof(char));
  scanf("%s", n);
  
  scanf("%d", &n2);
  m = (char*) malloc(10 + n2 * sizeof(char));
  scanf("%s", m);

  char *res = (char*) malloc((n1 + n2 + 10) * sizeof(char));
  intercalate(n, m, res);
  printf("%s\n", res);


  return 0;
}
