/*
[A B] C D E F G H I J K L M N O P - 0: 0, 1

A [C D] E F G H I J K L M N O P - 1: 1, 2 

A C [E F] G H I J K L M N O P - 2: 2, 3 

A C E [G H] I J K L M N O P - 3: 3, 4 

A C E G [I J] K L M N O P - 4: 4, 5 

A C E G I [K L] M N O P - 5: 5, 6 

A C E G I K [M N] O P - 6: 6, 7 

A C E G I K M [O P] - 7: 7, 8 

[A C] E G I K M O - 8: 0, 1 

A [E G] I K M O - 9: 1, 2

A E [I K] M O - 10: 2, 3

A E I [M O] - 11: 3, 4

[A E] I M - 12: 0, 1

A [I M] - 13: 1, 2

[A I] - 14: 0, 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  char value;
  struct Item *next;
} Item;

typedef struct {
  Item *first;
  Item *last;
  int length;
} List;

List* newList() {
  List *l = (List*) malloc(sizeof(List));
  l->first = NULL;
  l->last = NULL;
  l->length = 0;
  return l;
}

Item* newItem(char value) {
  Item *it = (Item*) malloc(sizeof(Item));
  it->value = value;
  it->next = NULL;
  return it;
}

int isEmpty(List *l) {
  return l->first == NULL;
}

void printList(List *l) {
  Item *it = l->first;
  while (it != NULL) {
    printf("%c%c", it->value, it->next != NULL ? ' ' : '\n');
    it = it->next;
  }
}

void insert(List *l, Item *it) {

  l->length++;

  if (isEmpty(l)) {
    l->first = it;
  } else {
    l->last->next = it;
  }

  l->last = it;

  return;
}

Item* removeList(List *l, int pos) {
  Item *prev = NULL;
  Item *actual = l->first;
  for (int i = 0; i < pos; i++) {
    prev = actual;
    actual = actual->next;
  }

  // item not found
  if (actual == NULL) return NULL;

  l->length--;
  // removing from beginning
  if (prev == NULL) {
    l->first = actual->next;
    return actual;
  }

  // removing from middle
  if (prev != NULL) {
    prev->next = actual->next;
    return actual;
  }

  if (actual == l->last) {
    l->last = prev;
  }

  // item not found
  return NULL;
}

int main() {
  int n = 16, team1, team2, pos = 0;
  char teams[16] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

  List *l = newList();
  for (int i = 0; i < n; i++) {
    insert(l, newItem(teams[i]));
  }

  for (int i = 0; i < n-1; i++) {
    if (pos >= l->length) pos = 0;

    scanf("%d %d", &team1, &team2);
    if (team1 < team2) {
      removeList(l, pos);
    } else {
      removeList(l, pos + 1);
    }
    pos++;
  }

  printf("%c\n", l->first->value);

  return 0;
}
