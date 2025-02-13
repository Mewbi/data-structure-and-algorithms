#include <stdio.h>

int main() {

  char university[50];
  int year;

  printf("Onde voce estuda: ");
  scanf("%s", university);
  
  printf("Quanto tempo: ");
  scanf("%d", &year);

  printf("Voce estuda na %s ha %d anos.\n", university, year);

  return 0;
}
