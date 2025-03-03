#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d%c", arr[i], i < n-1 ? ' ' : '\n');
  }
}

void intercala(int *arr, int left, int mid, int right)  {
  int i = left;
  int j = mid;
  int k = 0;
  int size = right - left + 1;
  int *tmp;

  tmp = (int*) malloc(size * sizeof(int));

  while (i < mid && j < right) {
    if (arr[i] < arr[j]) {
      tmp[k] = arr[i];
      i++;
    } else {
      tmp[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i < mid) {
    tmp[k] = arr[i];
    i++;
    k++;
  }

  while (j < mid) {
    tmp[k] = arr[j];
    j++;
    k++;
  }

  printf("TMP: ");
  printArr(tmp, size);
  for (int t = 0, t2 = left; t < k; t++, t2++) {
    arr[t2] = tmp[t];
  }
  free(tmp);
}

void mergeSort(int *arr, int left, int right, int n) {

  int mid;

  while (left < mid) {
    mid = (left + right) / 2;
    mergeSort(arr, left, mid, n);
    mergeSort(arr, mid+1, right, n);

    printf("left %d mid %d right %d\n", left, mid, right);
    printf("ARR: ");
    printArr(arr, n);
    intercala(arr, left, mid+1, right);
  }

}

int main() {
  int n, *arr;

  scanf("%d", &n);

  arr = (int*) malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printArr(arr, n);
  mergeSort(arr, 0, n, n);

  return 0;
}
