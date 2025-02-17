#include <stdio.h>

int main() {
  long int sum, x;
  int n;

  scanf("%d", &n);
  sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%ld", &x);

    sum += x;
  }

  printf("%ld\n", sum);
  return 0;
}
