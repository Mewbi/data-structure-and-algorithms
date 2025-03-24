#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_TIME 1.0
#define MAX_TIME 999999.999
#define MAX_NAME_LENGTH 40
#define MAX_TEAM_LENGTH 40

// Possible F1 teams
char *teams[] = {"redbull", "mclaren", "alpine", "astonmartin", "ferrari", "rb",
                 "williams", "sauber", "haas", "mercedes"};

int numTeams = sizeof(teams) / sizeof(teams[0]);

// Function to generate a random floating-point lap time
double generateLapTime() {
    return MIN_TIME + ((double)rand() / RAND_MAX) * (MAX_TIME - MIN_TIME);
}

// Function to generate a random driver name
void generateRandomName(char *name, int length) {
    for (int i = 0; i < length - 1; i++) {
        name[i] = 'a' + (rand() % 26); // Random lowercase letter
    }
    name[length - 1] = '\0';
}

int generateCarNumber() {
    return rand();
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number_of_drivers> <position>\n", argv[0]);
        return 1;
    }

    // Parse input arguments
    int n = atoi(argv[1]);
    int pos = atoi(argv[2]);

    if (n <= 0 || pos <= 0 || pos > n) {
        printf("Invalid input. Ensure 0 < position <= number_of_drivers.\n");
        return 1;
    }

    srand(time(NULL)); // Seed for randomness

    printf("%d\n", n); // Print the number of drivers


    for (int i = 0; i < n; i++) {
        char name[MAX_NAME_LENGTH];
        char team[MAX_TEAM_LENGTH];
        generateRandomName(name, MAX_NAME_LENGTH - 1);
        strcpy(team, teams[rand() % numTeams]);
        int carNum = generateCarNumber();
        double time = generateLapTime();

        printf("%d %s %s %.3f\n", carNum, name, team, time);
    }

    printf("%d\n", pos); // Print the position to find

    return 0;
}
