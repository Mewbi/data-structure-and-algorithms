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

int isValidDate(int d, int m, int y, int isLeap) {
  if (y < 1582) {
    return 0;
  }

  if (y == 1582) {
    if (m < 10) {
      return 0;
    }

    if (m == 10 && d < 15) {
      return 0;
    }
  }

  if (d <= 0 || d > 31 || m <= 0 || m > 12) {
    return 0;
  }

  if (m == 2 && (d > 29 || (d == 29 && !(isLeap) ))) {
    return 0;
  }

  if (d == 31 && !(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) ) {
    return 0;
  }

  return 1;
}

// jan - 01 - 31
// fev - 02 - 28 / 29
// mar - 03 - 31
// abr - 04 - 30
// may - 05 - 31
// jun - 06 - 30
// jul - 07 - 31
// aug - 08 - 31
// sep - 09 - 30
// out - 10 - 31
// nov - 11 - 30
// dez - 12 - 31

void prevDay(int* d, int* m, int* y, int isLeap) {
  if (*m == 3 && *d == 1) {
    *m -= 1;
    if (isLeap) {
      *d = 29;
    } else {
      *d = 28;
    }

    return;
  }

  if (*d == 1 && !(*m == 5 || *m == 7 || *m == 10 || *m == 12) ) {
    *d = 31;
    *m -= 1;
    if (*m == 0) {
      *m = 12;
      *y -= 1;
    }

    return;
  }


  if (*d == 1 && (*m == 5 || *m == 7 || *m == 10 || *m == 12) ) {
    *d = 30;
    *m -= 1;

    return;
  }

  *d -= 1;
  return;
}

int main() {
  int d, m, y, isLeap;

  scanf("%d %d %d", &d, &m, &y);

  isLeap = isLeapYear(y);

  prevDay(&d, &m, &y, isLeap);

  if (!isValidDate(d, m, y, isLeap)) {
    printf("nao existe dia anterior para esta data\n");
    return 0;
  }

  printf("%02d %02d %04d\n", d, m, y);
  return 0;
}
