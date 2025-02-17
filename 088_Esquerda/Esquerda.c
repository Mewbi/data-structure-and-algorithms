#include <stdio.h>

int calcPosition(char* commands, int n) {
  int pos = 0;
  char c;
  for (int i = 0; i < n; i++) {
    c = commands[i];
    if (c == 'D') {
      pos += 1;
    } else {
      pos -= 1;
    }
  }
  return pos;
}

int main() {
  int n, pos;

  scanf("%d", &n);

  char commands[n+1];

  scanf("%s", commands);

  pos = calcPosition(commands, n);

  switch (pos % 4) {
    case 0:
      printf("N\n");
      break;
    case 1:
    case -3:
      printf("L\n");
      break;
    case 2:
    case -2:
      printf("S\n");
      break;
    case 3:
    case -1:
      printf("O\n");
      break;
  }

  return 0;
}
