#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d%c", arr[i], i < n-1 ? ' ' : '\n');
  }
}

void intercala(int *arr, int s_left, int s_right, int e_right)  {

  int e_left = s_right - 1;

  int i = s_left;
  int j = s_right;

  int k = 0;
  int *tmp;

  tmp = (int*) malloc((e_right - s_left + 1) * sizeof(int));

  while (i <= e_left && j <= e_right) {
    if (arr[i] <= arr[j]) {
      tmp[k] = arr[i];
      i++;
    } else {
      tmp[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= e_left) {
    tmp[k] = arr[i];
    i++;
    k++;
  }

  while (j < e_right) {
    tmp[k] = arr[j];
    j++;
    k++;
  }

  //printArr(tmp, k);
  for (int t = 0; t < k; t++) {
    arr[s_left + t] = tmp[t];
  }

  free(tmp);
}

void mergeSort(int *arr, int left, int right, int n) {

  int mid;

  if (left < right) {
    mid = (left + right) / 2;
    mergeSort(arr, left, mid, n);
    mergeSort(arr, mid+1, right, n);

    //printf("left %d mid %d right %d\n", left, mid, right);
    // printf("ARR ANTES: ");
    printArr(arr, n);
    intercala(arr, left, mid+1, right);
    // printf("ARR DPS: ");
    // printArr(arr, n);
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
  mergeSort(arr, 0, n-1, n);
  printArr(arr, n);

  return 0;
}
