#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercalate(char *arr, int left, int right, char *res) {

  int i = 0;
  int j = left;
  int k = 0;

  int endLeft = left;
  int endRight = left + right;

  while (i < endLeft && j < endRight) {
    if (arr[i] <= arr[j]) {
      res[k] = arr[i];
      i++;
    } else {
      res[k] = arr[j];
      j++;
    }
    
    k++;
  }

  while (i < endLeft) {
    res[k] = arr[i];
    i++;
    k++;
  }

  while (j < endRight) {
    res[k] = arr[j];
    j++;
    k++;
  }
}

int main() {

  char *n;
  int n1, n2;
  
  n = (char*) malloc(20010 * sizeof(char));
  scanf("%s", n);
  scanf("%d %d", &n1, &n2);

  char *res = (char*) malloc((strlen(n) + 10) * sizeof(char));
  intercalate(n, n1, n2, res);
  printf("%s\n", res);

  free(n);
  free(res);

  return 0;
}
