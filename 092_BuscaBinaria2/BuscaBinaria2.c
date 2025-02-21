#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int init, int end) {
  for (int i = init; i <= end; i++) {
    printf("%d", arr[i]);
    if (i <= end - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
  return;
}

int binarySearch(int *arr, int n, int x) {
  int left, right, mid;
  left = 0;
  right = n - 1;
  while (left <= right) {
    mid = (left + right) / 2;

    if (arr[mid] == x) {
      return mid;
    }

    if (arr[mid] > x) {
      printArr(arr, mid, right);
      right = mid - 1;
    } else {
      printArr(arr, left, mid);
      left = mid + 1;
    }

  }

  return -1;
}

int main() {
  int x, n, pos;
  int *arr;

  scanf("%d", &n);

  arr = (int*) malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  while (scanf("%d", &x) != EOF) {
    printf("%d\n", x);

    pos = binarySearch(arr, n, x);
    if (pos != -1) {
      printf("VALOR %d LOCALIZADO NA COLECAO\n", x);
    } else {
      printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", x);
    }
  }
  return 0;
}
