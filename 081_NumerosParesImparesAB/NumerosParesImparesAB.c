#include <stdio.h>

int main() {
  int x, y;

  scanf("%d %d", &x, &y);
  for (int i = x; i <= y; i++) {
    if (i % 2 == 0) {
      printf("%d", i);
      if (i == y || i == y - 1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }

  for (int i = x; i <= y; i++) {
    if (i % 2 == 1) {
      printf("%d", i);
      if (i == y || i == y - 1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }
  return 0;
}
