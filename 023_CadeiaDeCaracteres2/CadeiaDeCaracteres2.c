#include <stdio.h>

int main() {
  char x[51], y[51], z[51]; // Avoid buffer overflow

  scanf("%s", x);
  scanf("%s", y);
  scanf("%s", z);

  printf("%s\n%s\n%s\n", z, y, x);

  return 0;
}
