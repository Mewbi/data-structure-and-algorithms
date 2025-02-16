#include <stdio.h>
#include <string.h>

int in_array(char* array, char item, int n) {
  for (int i = 0; i < n; i++) {
    if (item == array[i]) {
      return 1;
    }
  }

  return 0;
}

int main() {

  char letter[2];
  char consoants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ\0";

  scanf("%s", letter);

  int n = strlen(consoants);
  if (in_array(consoants, letter[0], n)) {
    printf("SIM\n");
  }

  return 0;
}
