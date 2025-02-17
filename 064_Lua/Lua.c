#include <stdio.h>

int main() {
  int m1, m2;

  scanf("%d %d", &m1, &m2);

  if ((m1 >= 0) && (m2 <= 2)) {
    printf("Nova\n");
  }else if ((m2 <= 96) && (m2 > m1)){
    printf("Crescente\n");
  }else if ((m2 <= 96) && (m1 > m2)){
    printf("Minguante\n");
  } else {
    printf("Cheia\n");
  }

  return 0;
}
