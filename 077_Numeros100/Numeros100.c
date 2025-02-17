#include <stdio.h>

int main() {
  for (int i = 0; i <= 100; i++) {
    printf("%d", i);
    if (i == 100) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}
