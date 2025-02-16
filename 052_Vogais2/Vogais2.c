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
  char vowels[] = "aeiouAEIOU\0";

  scanf("%s", letter);

  int n = strlen(vowels);
  if (in_array(vowels, letter[0], n)) {
    printf("SIM\n");
  }

  return 0;
}
