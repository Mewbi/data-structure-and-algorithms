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
  int x;

  scanf("%d", &x);

  if (isPrime(x)) {
    printf("PRIMO\n");
  } else {
    printf("COMPOSTO\n");
  }

  return 0;
}
