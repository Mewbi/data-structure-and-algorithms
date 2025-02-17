#include <stdio.h>

int main() {
  int x, y, res;

  scanf("%d %d", &x, &y);

  res = 0;
  while (1) {
    for (int j = 0;j < y; j++) {
      x--;
    }

    if (x < 0) {
      break;
    }

    res++;
  }

  printf("%d\n", res);

  return 0;
}
