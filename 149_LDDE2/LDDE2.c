#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  int value;
  struct Item *next;
  struct Item *prev;
} Item;

typedef struct List
{
  struct Item *first;
  struct Item *last;
} List;

Item* NewItem(int value) {
  Item *it = (Item *) malloc(sizeof(Item));
  it->value = value;
  it->next = NULL;
  it->prev = NULL;
  return it;
}

List* NewList() {
  List *l = (List *) malloc(sizeof(List));
  l->first = NULL;
  l->last = NULL;
  return l;
}

Item* first(List *l) {
  return l->first;
}

Item* last(List *l) {
  return l->last;
}

int isEmpty(List *l) {
  return first(l) == NULL && last(l) == NULL;
}

Item* search(List *l, int value) {
  Item *it = first(l);
  int found = 0;

  while(it != NULL && it->value <= value) {
    if (it->value == value) {
      found = 1;
      break;
    }
    it = it->next;
  }

  if (found) return it;

  return NULL;
}

void printListFirstLast(List *l) {
  Item* it= first(l);

  while(it != NULL) {
    printf("%d%c", it->value, it->next != NULL ? ' ' : '\n');
    it = it->next;
  }
}

void printListLastFirst(List *l) {
  Item * it = last(l);

  while(it != NULL) {
    printf("%d%c", it->value, it->prev != NULL ? ' ' : '\n');
    it = it->prev;
  }
}

void insertList(List *l, Item *it) {
  Item *prev = NULL, *actual = first(l);

  while(actual != NULL && actual->value < it->value) {
    prev = actual;
    actual = actual->next;
  }

  // actual always will be the next value, it can be NULL or an Item
  // the same logic to prev
  it->next = actual;
  it->prev = prev;

  // inserting in beginning
  if (prev == NULL) {

    if (isEmpty(l)) {
      l->last = it;
    } else {
      actual->prev = it;
    }

    l->first = it;
    return;
  }

  // Inserting in middle or end
  prev->next = it;

  if (actual == NULL) l->last = it;

  if (actual != NULL) actual->prev = it;

}

Item* removeList(List *l, int value) {
  Item* prev = NULL, *actual = first(l);
  int found = 0;

  while(actual != NULL && actual->value <= value) {
    if (actual->value == value) {
      found = 1;
      break;
    }
    prev = actual;
    actual = actual->next;
  }

  if (!found) return NULL;

  // removing from beginning
  if (prev == NULL) {
    l->first = actual->next;
  } else {
    prev->next = actual->next;
  }

  if (actual == last(l)) {
    l->last = prev;
  } else {
    actual->next->prev = prev;
  }

  // removing from middle or end
  // Cleaning references
  actual->next = NULL;
  actual->prev = NULL;

  return actual;
}

int main() {
  int v;
  char opc, *list;
  Item *it = NULL;
  List *listA = NewList();
  List *listB = NewList();

  list = (char *) malloc(10 * sizeof(char));
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'I':
      scanf("%s %d", list, &v);
      if (strcmp(list, "A") == 0) insertList(listA, NewItem(v));
      if (strcmp(list, "B") == 0) insertList(listB, NewItem(v));
      break;

    case 'E':
      scanf("%s %d", list, &v);
      if (strcmp(list, "A") == 0) it = removeList(listA, v);
      if (strcmp(list, "B") == 0) it = removeList(listB, v);
      if (it != NULL) free(it);
      break;

    case 'M':
      scanf("%s", list);
      if (strcmp(list, "A") == 0) printListFirstLast(listA);
      if (strcmp(list, "B") == 0) printListFirstLast(listB);
      break; 

    case 'R':
      scanf("%s", list);
      if (strcmp(list, "A") == 0) printListLastFirst(listA);
      if (strcmp(list, "B") == 0) printListLastFirst(listB);
      break; 
    }
  }

  return 0;
}
