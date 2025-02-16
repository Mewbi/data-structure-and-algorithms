#include <stdio.h>

int isLeapYear(int year) {

  if (year % 400 == 0) {
    return 1;
  }

  if (year % 100 == 0) {
    return 0;
  }

  if (year % 4 == 0) {
    return 1;
  }

  return 0;
}

void nextDay(int* d, int* m, int* y, int isLeap) {
  if (*m == 2 && ((isLeap && *d == 29) || (*d == 28 && !isLeap)) ) {
    *d = 01;
    *m += 1;

    return;
  }

  if (*d == 30 && !(*m == 1 || *m == 3 || *m == 5 || *m == 7 || *m == 8 || *m == 10 || *m == 12) ) { 
    *d = 01;
    *m += 1;

    return;
  }


  if (*d == 31 && (*m == 1 || *m == 3 || *m == 5 || *m == 7 || *m == 8 || *m == 10 || *m == 12) ) {
    *d = 01;
    *m += 1;
    if (*m > 12) {
      *m = 01;
      *y += 1;
    }

    return;
  }

  *d += 1;
  return;
}

int main() {
  int d, m, y, isLeap;

  scanf("%d %d %d", &d, &m, &y);

  isLeap = isLeapYear(y);

  nextDay(&d, &m, &y, isLeap);

  printf("%02d %02d %04d\n", d, m, y);
  return 0;
}
