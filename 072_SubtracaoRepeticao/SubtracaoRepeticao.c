#include <stdio.h>

int main() {
  int x, y, sum;

  scanf("%d %d", &x, &y);

  sum = 0;
  for (int i = 0;i < x; i++) {
    sum++;
  }
  for (int i = 0;i < y; i++) {
    sum--;
  }

  printf("%d\n", sum);

  return 0;
}
