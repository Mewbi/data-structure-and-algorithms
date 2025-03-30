#include <stdio.h>
#include <stdlib.h>

// Merge and count inversions
void mergeAndCount(double arr[], double temp[], int left, int mid, int right, int *count) {
  int i = left, j = mid + 1, k = left;
  int invCount = 0;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      invCount += (mid - i + 1);  // Count inversions
    }
  }

  while (i <= mid) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];

  for (i = left; i <= right; i++) arr[i] = temp[i];

  *count += invCount;
  return;
}


void mergeSortAndCount(double *arr, double *temp, int left, int right, int *count) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSortAndCount(arr, temp, left, mid, count);
    mergeSortAndCount(arr, temp, mid + 1, right, count);
    mergeAndCount(arr, temp, left, mid, right, count);
  }
  return;
}

int countSwaps(double *arr, int n) {
  double *temp = (double *)malloc(n * sizeof(double));
  int count = 0;
  mergeSortAndCount(arr, temp, 0, n - 1, &count);
  free(temp);
  return count;
}

int main() {
  int n, carNum, res;
  char name[50];
  char team[50];


  scanf("%d", &n);

  double *arr = (double*) malloc(n * sizeof(double));

  for (int i = 0; i < n; i++) {
    scanf("%d %s %s %lf", &carNum, name, team, &arr[i]);
  }

  res = countSwaps(arr, n);
  
  printf("%d\n", res);

  return 0;
}
