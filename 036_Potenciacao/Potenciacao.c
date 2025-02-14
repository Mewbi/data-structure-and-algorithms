#include <stdio.h>
#include <math.h>

int main() {
  int x, y;

  scanf("%d %d", &x, &y);

  printf("%.4f\n", pow((double)x, (double)y));

  return 0;
}
