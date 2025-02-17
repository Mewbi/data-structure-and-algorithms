#include <stdio.h>

int sumDivs(int x) {
  int res = 0;

  for (int i = 1; i < x; i++) {
    if (x % i == 0) {
      res += i;
    }
  }

  return res;
}

int main() {
  int x, y;

  while (1) {
    scanf("%d", &x);

    if (x == -1) {
      break;
    }

    y = sumDivs(x);

    if (y > x) {
      printf("abundante\n");
    } else if (y == x) {
      printf("perfeito\n");
    } else {
      printf("deficiente\n");
    }

  }

  return 0;
}
