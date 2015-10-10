/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char *tokens) {
    char delim[256], answer[256];

    strcpy(delim, " ");
    tokens = strtok(input, delim);

    while(tokens != NULL) {
        if (strcmp(tokens, "What") == 0 || strcmp(tokens, "what") == 0 ||
            strcmp(tokens,  "Who") == 0 || strcmp(tokens,  "who") == 0) {

            tokens = strtok(NULL, delim);
            if (strcmp(tokens, "is") == 0) {
                strcpy(delim, "?");
                tokens = strtok(NULL, delim);
                strcpy(answer, tokens); // store the question answer in the answer variable
            } else {
                printf("%s", "Answer must be in the form of a question e.g. What is...? or Who is...?");
                break;
            }
        } else {
             printf("%s", "Answer must be in the form of a question e.g. What is...? or Who is...?");
             break;
        }
        tokens = strtok(NULL, delim);
    }
    strcpy(tokens, answer);
}

void quicksort(player *players, int first, int last) {
    int pivot, i, j;
    player temp;
    strcpy(temp.name, "");
    temp.score = NULL;

     if(first < last) {
         pivot = first;
         i = first;
         j = last;

         while(i < j) {
             while(players[i].score <= players[pivot].score && i < last)
                 i++;
             while(players[j].score > players[pivot].score)
                 j--;
             if(i < j) {
                 temp = players[i];
                  players[i] = players[j];
                  players[j] = temp;
             }
         }

         temp = players[pivot];
         players[pivot] = players[j];
         players[j] = temp;
         quicksort(players, first, j-1);
         quicksort(players, j+1, last);
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players) {
    quicksort(players, 0, 3);
    
    printf("First: %s   Score: %d\n", players[3].name, players[3].score);
    printf("Second: %s   Score: %d\n", players[2].name, players[2].score);
    printf("Third: %s   Score: %d\n", players[1].name, players[1].score);
    printf("Fourth: %s   Score: %d\n", players[0].name, players[0].score);
}

int main(int argc, const char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[4];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and prompt for players names
    // initialize each of the players in the array
    printf("Welcome to jeopardy!\nPlease enter the names of the four players participating:\n");
    for(int i = 0; i < 4; i++) {
        scanf("%s", players[i].name);
    }

    // Call functions from the questions and players source files
    initialize_game();

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Execute the game until all questions are answered
    }

    // Display the final results and exit
    show_results(players);

    return EXIT_SUCCESS;
}
