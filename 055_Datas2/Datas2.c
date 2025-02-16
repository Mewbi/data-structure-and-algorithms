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

int main() {
  int d, m, y, isLeap;

  scanf("%d %d %d", &d, &m, &y);

  isLeap = isLeapYear(y);

  if (isValidDate(d, m, y, isLeap)) {
    printf("DATA VALIDA\n");
    return 0;
  }

  printf("DATA INVALIDA\n");
  return 0;
}
