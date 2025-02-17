#include <stdio.h>

int main() {
  long int x, sum;
  sum = 0;

  while (scanf("%ld\n", &x) != EOF)
  {
    if (x == 0) {
      printf("%ld\n", sum);
      sum = 0;
      continue;
    }
    sum += x;
  }

  return 0;
}
