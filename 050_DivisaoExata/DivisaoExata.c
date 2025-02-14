#include <stdio.h>

int main() {
  long int x, y;

  scanf("%ld", &x);
  scanf("%ld", &y);

  if (x % y == 0) {
    printf("a divisao de %ld por %ld eh exata.\n",x , y);
  }

  return 0;
}
