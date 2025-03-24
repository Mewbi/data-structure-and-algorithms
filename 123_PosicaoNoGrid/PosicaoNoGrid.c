#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  char team[50];
  int carNum;
  double time;
} Driver;

void printArr(Driver *arr, int n) {
  Driver c;
  for (int i = 0; i < n; i++) {
    c = arr[i];
    printf("%d %s %s %lf\n",
           c.carNum,
           c.name,
           c.team,
           c.time);
  }
  return;
}

void swap(Driver *a, Driver *b) {
  Driver temp = *a;
  *a = *b;
  *b = temp;
}

// Median-of-three pivot selection
int medianOfThree(Driver *arr, int low, int high) {
  int mid = (low + high) / 2;

  if (arr[low].time > arr[mid].time) swap(&arr[low], &arr[mid]);
  if (arr[low].time > arr[high].time) swap(&arr[low], &arr[high]);
  if (arr[mid].time > arr[high].time) swap(&arr[mid], &arr[high]);

  swap(&arr[mid], &arr[high]);  // Place median at the end
  return high;
}


int partition(Driver *arr, int init, int end) {
  int pm = init - 1;
  int pivot = medianOfThree(arr, init, end);;

  for (int i = init; i < end; i++) {
    if (arr[i].time <= arr[pivot].time) {
      pm++;
      swap(&arr[i], &arr[pm]);
    }
  }

  pm++;
  swap(&arr[pivot], &arr[pm]);
  return pm;
}

void selectQuickSort(Driver *arr, int init, int end, int pos) {
  int pivotIdx;
  while (init <= end) {
    pivotIdx = partition(arr, init, end);

    if (pivotIdx == pos) {
      return;
    } else if (pivotIdx > pos) {
      end = pivotIdx - 1;
    } else {
      init = pivotIdx + 1;
    }
    
  }
}

int main() {
  int n, carNum, pos;
  double time;

  Driver *arr;

  scanf("%d", &n);

  arr = (Driver*) malloc(n * sizeof(Driver));

  for (int i = 0; i < n; i++) {
    scanf("%d %s %s %lf", &arr[i].carNum, arr[i].name, arr[i].team, &arr[i].time);
  }

  scanf("%d", &pos);
  pos -= 1;

  selectQuickSort(arr, 0, n-1, pos);
  //printArr(arr, n);
  printf("%d %s %s\n", arr[pos].carNum, arr[pos].name, arr[pos].team);

  return 0;
}
