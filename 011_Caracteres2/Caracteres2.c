#include <stdio.h>

int main() {
  char x[2], y[2], z[2]; // Avoid buffer overflow

  scanf("%s", x);
  scanf("%s", y);
  scanf("%s", z);

  printf("%s\n%s\n%s\n", z, y, x);

  return 0;
}
