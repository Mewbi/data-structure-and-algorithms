#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  char a[6], b[6];
  bool x, y;
  char *v, *s;

  scanf("%s %s", a, b);

  x = strcmp(a, "true") == 0;
  y = strcmp(b, "true") == 0;

  v = x & y ? "true" : "false";
  s = x ^ y ? "true" : "false";

  printf("%s %s\n", v, s);

  return 0;
}
