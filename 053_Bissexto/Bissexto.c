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

int main() {
  int year;

  scanf("%d", &year);

  if (isLeapYear(year)) {
    printf("ANO BISSEXTO\n");
    return 0;
  }

  printf("ANO NAO BISSEXTO\n");
  return 0;
}
