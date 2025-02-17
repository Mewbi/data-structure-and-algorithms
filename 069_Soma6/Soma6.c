#include <stdio.h>

int main() {
  long int x, sum;
  sum = 0;

  while (1)
  {
    scanf("%ld", &x);
    if (x == 0) {
      break;
    }
    sum += x;
  }

  printf("%ld\n", sum);
  return 0;
}
