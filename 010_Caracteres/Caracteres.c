#include <stdio.h>

int main() {
  char x[2], y[2], z[2]; // Require array of size 2 to avoid buffer overflow. It should store char + '\0'

  scanf("%s", x);
  scanf("%s", y);
  scanf("%s", z);

  printf("%s\n%s\n%s\n", x, y, z);

  return 0;
}
