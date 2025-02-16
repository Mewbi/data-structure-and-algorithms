#include <stdio.h>

int invert_num(int num) {
  int dig1, dig2, dig3, dig4;

  dig1 = num / 1000;
  dig2 = (num % 1000) / 100;
  dig3 = (num % 100) / 10;
  dig4 = (num % 10);

  return (dig4 * 1000)
        + (dig3 * 100)
        + (dig2 * 10)
        + (dig1);
}

int main() {
  int x, y;
  
  scanf("%d %d", &x, &y);

  if (x == invert_num(y)) {
    printf("espelho\n");
    return 0;
  }

  printf("nao espelho\n");
  return 0;
}
