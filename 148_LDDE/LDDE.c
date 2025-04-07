#include <stdio.h>
#include <stdlib.h>

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
    printf("%d ", it->value);
    it = it->next;
  }
  printf("\n");
}

void printListLastFirst(List *l) {
  Item * it = last(l);

  while(it != NULL) {
    printf("%d ", it->value);
    it = it->prev;
  }
  printf("\n");
}

void insertList(List *l, Item *it) {
  if (search(l, it->value) != NULL) return;
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
  int n, v;
  char opc;
  Item *it = NULL;
  List *l = NewList();
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'I':
      scanf("%d", &v);
      insertList(l, NewItem(v));
      break;

    case 'E':
      scanf("%d", &v);
      it = removeList(l, v);
      if (it != NULL) free(it);
      break;

    case 'M':
      printListFirstLast(l);
      break; 

    case 'R':
      printListLastFirst(l);
      break; 
    }
  }

  return 0;
}
