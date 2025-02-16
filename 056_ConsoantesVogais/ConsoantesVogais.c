#include <stdio.h>
#include <string.h>

int inArray(char* array, char item, int n) {
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
  char vowels[] = "aeiouAEIOU\0";

  scanf("%s", letter);

  int n1 = strlen(consoants);
  int n2 = strlen(vowels);

  if (inArray(vowels, letter[0], n2)) {
    printf("vogal\n");
  }
  
  if (inArray(consoants, letter[0], n1)) {
    printf("consoante\n");
  }

  return 0;
}
