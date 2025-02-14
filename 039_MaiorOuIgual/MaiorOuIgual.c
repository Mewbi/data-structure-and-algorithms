#include <stdio.h>

int main() {
  long int x, y;

  scanf("%ld %ld", &x, &y);

  if (x >= y) {
    printf("true\n");
    return 0;
  }
 
  printf("false\n");
  return 0;
}
