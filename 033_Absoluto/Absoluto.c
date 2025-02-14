#include <stdio.h>
#include <stdlib.h>

int main() {
  long int x;

  scanf("%ld", &x);

  printf("%ld\n", labs(x)); // long absolute

  return 0;
}
