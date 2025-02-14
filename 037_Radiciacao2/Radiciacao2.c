#include <stdio.h>
#include <math.h>

int main() {
  long int x;

  scanf("%ld", &x);

  printf("%.4f\n", sqrt((double)x));

  return 0;
}
