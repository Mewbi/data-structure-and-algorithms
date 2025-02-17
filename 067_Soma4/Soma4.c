#include <stdio.h>

int main() {
  
  long int sum, x;
  int n, m;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    sum = 0;
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      scanf("%ld", &x);

      sum += x;
    }
    printf("%ld\n", sum);
  }
  return 0;
}
