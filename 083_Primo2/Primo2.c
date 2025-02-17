#include <stdio.h>

int isPrime(int n) {
  int divs = 0;
  if (n == 1) {
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      divs += 1;
    }

    if (divs > 1) {
      return 0;
    }
  }

  return 1;
}

int main() {
  int x, y;

  scanf("%d %d", &x, &y);

  printf("Primos entre %d e %d:", x, y);

  for (int i = x; i <= y; i++) {
    if (isPrime(i)) {
      printf(" %d", i);
    }
  }

  printf("\n");

  return 0;
}
