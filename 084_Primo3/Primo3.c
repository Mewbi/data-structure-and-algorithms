#include <stdio.h>

int isPrime(int n) {
  int divs = 0;
  if (n <= 1) {
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
  int x;

  while (1) {
    scanf("%d", &x);
    if (x < 0) {
      break;
    }

    if (isPrime(x)) {
      printf("SIM\n");
    } else {
      printf("NAO\n");
    }
  }

  return 0;
}
