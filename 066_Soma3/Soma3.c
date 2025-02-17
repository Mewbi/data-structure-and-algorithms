#include <stdio.h>

int main() {
  long int x, sum;
  sum = 0;

  while (scanf("%ld\n", &x) != EOF)
  {
    sum += x;
  }

  printf("%ld\n", sum);
  return 0;
}
