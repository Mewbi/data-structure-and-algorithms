#include <stdio.h>

void bubbleSort(int *arr, int *pos, int n) {
  int aux;
  for (int i = 0; i < n; i++) {
    for (int  j = 0; j < n-1; j++) {
      if (arr[j] > arr[j+1]) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;

        aux = pos[j];
        pos[j] = pos[j+1];
        pos[j+1] = aux;
      }
    }
  }

  return;
}

void getNGreaterPosition(int *arr, int size, int n, int *nPos, int *nValue) {
  int values[n], pos[n];
  int auxValues[n], auxPos[n];
  for (int i = 0; i < n; i++) {
    values[i] = arr[i];
    pos[i] = i;
    auxValues[i] = arr[i];
    auxPos[i] = i;
  }

  bubbleSort(values, pos, n);

  for (int i = n; i < size; i++) {
    for (int j = n -1; j >= 0; j--) {
      if (arr[i] > values[j]) {
        // Push array back
        for (int k = 0; k < j; k++) {
          values[k] = auxValues[k+1];
          pos[k] = auxPos[k+1]; 
        }

        // Insert new value
        values[j] = arr[i];
        pos[j] = i;

        // Repopulate aux
        for (int k = 0; k < n; k++) {
          auxValues[k] = values[k];
          auxPos[k] = pos[k];
        }

        break;
      }
    }

  }

  *nPos = pos[0];
  *nValue = values[0];

  if (n > 1) {
    if (values[0] == values[1] && pos[0] < pos[1]) {
      *nPos = pos[1];
    }
  }
  return;
}

int main() {
  int x, v, pos, value;

  while (1)
  {
    scanf("%d", &x);
    if (x == 0) {
      break;
    }
    int arr[x];
    for (int i = 0; i < x; i++) {
      scanf("%d", &v);
      arr[i] = v;
    }

    
    getNGreaterPosition(arr, x, 1, &pos, &value);
    printf("%d %d\n", pos, value);

  }

  return 0;
}
