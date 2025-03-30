#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  int value;
  struct Item *next;
} Item;

typedef struct {
  Item *init;
} List;

List* newList() {
  List *l = (List*) malloc(sizeof(List));
  l->init = NULL;
  return l;
}

Item* newItem(int value) {
  Item *it = (Item*) malloc(sizeof(Item));
  it->value = value;
  it->next = NULL;
  return it;
}

int emptyList(List *l) {
  return l->init == NULL;
}

void printList(List *l) {
  Item *it = l->init;
  while (it != NULL) {
    printf("%d%c", it->value, it->next != NULL ? ' ' : '\n');
    it = it->next;
  }
}

Item* search(List *l, int v) {
  Item *it = l->init;
  while(it != NULL && it->value < v) {
    it = it->next;
  }

  if (it == NULL || it->value != v) return NULL;

  return it;
}

void insert(List *l, Item *it) {
  // item already exist
  if (search(l, it->value) != NULL) return;

  Item *prev = NULL;
  Item *actual = l->init;
  while(actual != NULL && actual->value < it->value) {
    prev = actual;
    actual = actual->next;
  }

  it->next = actual;

  // inserting in beginning
  if(prev == NULL) {
    l->init = it;
    return;
  }

  prev->next = it;
  return;
}

Item* removeList(List *l, int v) {
  Item *prev = NULL;
  Item *actual = l->init;
  while(actual != NULL && actual->value < v) {
    prev = actual;
    actual = actual->next;
  }

  // item not found
  if (actual == NULL) return NULL;

  // removing from beginning
  if (actual->value == v && prev == NULL) {
    l->init = actual->next;
    return actual;
  }

  // removing from middle
  if (actual->value == v && prev != NULL) {
    prev->next = actual->next;
    return actual;
  }

  // item not found
  return NULL;
}

int main() {
  int n, v;
  char opc;

  List *l = newList();
  while (scanf("%c", &opc) != EOF) {
    switch (opc) {
    case 'I':
      scanf("%d", &v);
      insert(l, newItem(v));
      break;

    case 'R':
      scanf("%d", &v);
      removeList(l, v);
      break;

    case 'B':
      scanf("%d", &v);
      printf("%s\n", search(l, v) != NULL ? "SIM" : "NAO");
      break; 

    case 'L':
      printList(l);
      break; 
    }
  }
  return 0;
}