#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *ra;
  char *name;
  int exercices;
  int time;
} Student;

void printArr(Student *arr, int n) {
  Student c;
  for (int i = 0; i < n; i++) {
    c = arr[i];
    printf("%s %s %d (%d)\n",
           c.ra,
           c.name,
           c.exercices,
           c.time);
  }
  return;
}

void freakyBubbleSort(Student *arr, int n) {
  Student aux;
  for (int i = 0; i < n; i++) {
    for (int  j = 0; j < n-1; j++) {
      if (arr[j].exercices < arr[j+1].exercices) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].exercices > arr[j+1].exercices) continue;


      if (arr[j].time > arr[j+1].time) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }
    }
  }

  return;
}

int main() {
  int n, exercices, time;
  Student *arr;

  scanf("%d", &n);

  arr = (Student*) malloc(n * sizeof(Student));

  for (int i = 0; i < n; i++) {

    char *name = (char*) malloc(110 * sizeof(char));
    char *ra = (char*) malloc(20 * sizeof(char));
    scanf("%s %s %d %d", ra, name, &exercices, &time);

    Student *c = (Student*) malloc(sizeof(Student));
    c->ra = ra;
    c->name = name;
    c->exercices = exercices;
    c->time = time;

    arr[i] = *c;
  }

  freakyBubbleSort(arr, n);
  printArr(arr, n);

  return 0;
}
