#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  char a[6], b[6];
  bool x, y;

  scanf("%s %s", a, b);

  x = strcmp(a, "true") == 0 ? true : false;
  y = strcmp(b, "true") == 0 ? true : false;

  if (x && y) {
    printf("true\n");
    return 0;
  }

  printf("false\n");
   return 0;

}
