#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
  char a[6];
  bool x;

  scanf("%s", a);

  x = strcmp(a, "true") == 0;

  if (!x) {
    printf("true\n");
    return 0;
  }

  printf("false\n");
  return 0;

}
