#include <stdio.h>
#include <math.h>

int calcEq(double a, double b, double c, double* x1, double* x2) {
  double delta = pow(b, 2) - (4 * a * c);
  if (delta < 0) {
    return -1;
  }

  if (delta == 0) {
    *x1 = -b / (2 * a);
    return 0;
  }

  *x1 = (-b + sqrt(delta)) / (2 * a);
  *x2 = (-b - sqrt(delta)) / (2 * a);
  
  return 1;
}

int main() {
  double a, b, c, x1, x2;
  int res;

  scanf("%lf %lf %lf", &a, &b, &c);
  
  res = calcEq(a, b, c, &x1, &x2);
  if (res == -1) {
    printf("nao ha raiz real\n");
  } else if (res == 0) {
    printf("%.4lf\n", x1);
  } else {
    printf("%.4lf %.4lf\n", x1, x2);
  }

  return 0;
}
