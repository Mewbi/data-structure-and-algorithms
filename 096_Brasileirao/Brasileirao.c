#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int  goalsDiff;
  int  goals;
  int  goalsReceived;
  int  points;
  int  wins;
  int  draws;
  int  loses;
} Team;

void printArr(Team *arr, int n) {
  Team t;
  for (int i = 0; i < n; i++) {
    t = arr[i];
    printf("%s %d %d %d %d %d %d %d\n",
           t.name,
           t.points,
           t.wins,
           t.draws,
           t.loses,
           t.goalsDiff,
           t.goals,
           t.goalsReceived);
  }
  return;
}

void freakyBubbleSort(Team *arr, int n) {
  Team aux;
  for (int i = 0; i < n; i++) {
    for (int  j = 0; j < n-1; j++) {
      if (arr[j].points < arr[j+1].points) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].points > arr[j+1].points) continue;


      if (arr[j].wins < arr[j+1].wins) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].wins > arr[j+1].wins) continue;
      
      if (arr[j].goalsDiff < arr[j+1].goalsDiff) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].goalsDiff > arr[j+1].goalsDiff) continue;

      if (arr[j].goals < arr[j+1].goals) {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        continue;
      }

      if (arr[j].goals > arr[j+1].goals) continue;
    }
  }

  return;
}

Team* getTeam(Team *teams, int n, char *name) {
  for (int i = 0; i < n; i++) {
    if (strcmp(teams[i].name, name) == 0) {
      return &teams[i];
    }
  }

  return NULL;
}

void addResults(Team *teams, int n, char *name, int goals, int goalsReceived) {

  Team *t = getTeam(teams, n, name);
  int points = 0, win = 0, draw = 0, lose = 0;

  if (goals > goalsReceived) {
    points = 3;
    win = 1;
  } else if (goals < goalsReceived) {
    points = 0;
    lose = 1;
  } else {
    points = 1;
    draw = 1;
  }
 
  t->points += points;
  t->wins += win;
  t->draws += draw;
  t->loses += lose;
  t->goalsDiff += goals - goalsReceived;
  t->goals += goals;
  t->goalsReceived += goalsReceived;
}

int main() {
  int n, goal1, goal2;
  Team *arr;

  scanf("%d", &n);

  arr = (Team*) malloc(n * sizeof(Team));

  for (int i = 0; i < n; i++) {

    char *name = (char*) malloc(110 * sizeof(char));
    scanf("%s", name);

    Team *t = (Team*) malloc(sizeof(Team));
    t->name = name;

    arr[i] = *t;

  }

  for (int i = 0; i < n*(n-1); i++) {
    char *name1 = (char*) malloc(110 * sizeof(char));
    char *name2 = (char*) malloc(110 * sizeof(char));
    scanf("%s %d x %d %s", name1, &goal1, &goal2, name2);

    addResults(arr, n, name1, goal1, goal2);
    addResults(arr, n, name2, goal2, goal1);
  }

  freakyBubbleSort(arr, n);

  printf("CAMPEAO: %s\n", arr[0].name);
  printf("VICE-CAMPEAO: %s\n", arr[1].name);
  printf("REBAIXADOS: %s, %s, %s e %s\n", 
         arr[n-1].name,
         arr[n-2].name,
         arr[n-3].name,
         arr[n-4].name);
  printf("TABELA FINAL:\n");
  printArr(arr, n);

  return 0;
}
