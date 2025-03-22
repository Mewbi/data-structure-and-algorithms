#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercalate(char *arr1, char *arr2, char *res) {

  int i = 0, j = 0, k = 0;
  int n1 = strlen(arr1);
  int n2 = strlen(arr2);

  while (i < n1 && j < n2) {
    res[i+j] = arr1[i];
    i++;
    if (i < n1) {
      res[i+j] = arr1[i];
      i++;
    }
    if (i < n1) {
      res[i+j] = arr1[i];
      i++;
    }

    res[i+j] = arr2[j];
    j++;
    if (j < n2) {
      res[i+j] = arr2[j];
      j++;
    }
    if (j < n2) {
      res[i+j] = arr2[j];
      j++;
    }
  }

  for (k = 0; k < n1-i; k++) {
    res[i+j+k] = arr1[i+k];
  }

  for (k = 0; k < n2-j; k++) {
    res[i+j+k] = arr2[j+k];
  }
  
}

int main() {

  char *n, *m;
  int n1 = 110, n2 = 20;

  n = (char*) malloc(n1 * sizeof(char));
  m = (char*) malloc(n2 * sizeof(char));

  while (scanf("%s %s", n, m) != EOF) {
    
    char *res = (char*) malloc((n1 + n2) * sizeof(char));
    intercalate(n, m, res);
    printf("%s\n", res);
  }

  free(n);
  free(m);

  return 0;
}
