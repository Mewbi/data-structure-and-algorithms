#include <stdio.h>

long int factorial(long int x) {
  if (x <= 1) {
    return 1;
  }

  return x * factorial(x - 1);
}

int main() {
  long int x, res;

  scanf("%ld", &x);

  res = factorial(x);
  printf("%ld\n", res);

  return 0;
}
