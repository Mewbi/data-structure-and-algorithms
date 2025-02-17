#include <stdio.h>

int main() {
  int x, y, sum;

  scanf("%d %d", &x, &y);

  sum = 0;
  for (int i = 0;i < x; i++) {
    for (int j = 0;j < y; j++) {
      sum++;
    }
  }

  printf("%d\n", sum);

  return 0;
}
