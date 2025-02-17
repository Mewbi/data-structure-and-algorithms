#include <stdio.h>

int main() {
  int x, y;

  scanf("%d %d", &x, &y);
  for (int i = x; i <= y; i++) {
    printf("%d", i);
    if (i == y) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}
