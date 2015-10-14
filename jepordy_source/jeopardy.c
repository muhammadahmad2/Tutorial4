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
char* tokenize(char *input, char *tokens) {
    char delim[BUFFER_LEN], answer[BUFFER_LEN];

    strcpy(delim, " ");
    tokens = strtok(input, delim);

    if (strcmp(tokens, "What") == 0 || strcmp(tokens, "what") == 0 ||
        strcmp(tokens,  "Who") == 0 || strcmp(tokens,  "who") == 0) {

        tokens = strtok(NULL, delim);
        if (strcmp(tokens, "is") == 0) {
            strcpy(delim, "\n");
            tokens = strtok(NULL, delim); // get answer
            strcpy(answer, tokens); // store the question answer in the answer variable
        } else {
            printf("Answer must be in the form of a question e.g. What is... or Who is...\n");
        }
    } else {
        printf("Answer must be in the form of a question e.g. What is... or Who is...\n");
    }
    return tokens;
}

void quicksort(player *players, int first, int last) {
    int pivot, i, j;
    player temp;
    strcpy(temp.name, "");
    temp.score = 0;

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
    char input[BUFFER_LEN], tokens[BUFFER_LEN], category[BUFFER_LEN];
    int value, playerIndex = 0, remainingQuestions = 12;

    // initialise players array
    for (int i = 0; i < (int)(sizeof(players) / sizeof(players[0])); i++) {
        strcpy(players[i].name, "");
        players[i].score = 0;
    }

    // Display the game introduction and prompt for players names
    printf("Welcome to jeopardy!\nPlease enter the names of the four players participating:\n");

    for(int i = 0; i < (int)(sizeof(players) / sizeof(players[0])); i++) {
        while (true) {
            scanf("%s", input); // get player name

            if (player_exists(players, input)) {
               printf("A player exists with that name already, please enter another\n");
            } else {
                strcpy(players[i].name, input);
                break;
            }
        }
    }

    // Call functions from the questions and players source files
    initialize_game();

    // Perform an infinite loop getting command input from users until game ends
    while (remainingQuestions != 0) {
        if (playerIndex == sizeof(players) / sizeof(players[0]))
            playerIndex = 0; // reset to first player

        do {
            // Execute the game until all questions are answered
            while (true) {
                printf("\n%s, please select a category from the following:", players[playerIndex].name);
                display_categories();

                // take input
                scanf("%s", category);
                if (is_category(category))
                    break;
            }
            while (true) {
                printf("Please select a value in the category\n");
                scanf("%d%*c", &value); // read in integer and delete newline character from buffer
                if (value == 100 || value == 200 || value == 300 || value == 400)
                    break;
            }

        } while (already_answered(category, value));

        display_question(category, value);
        printf("Please enter your answer: ");

        fgets(input, BUFFER_LEN, stdin); // get input  from console
        strcpy(tokens, tokenize(input, tokens)); // tokenize input to get answer

        if (valid_answer(category, value, tokens) == true) {
            printf("Correct!\n");
            update_score(players, players[playerIndex].name, value);
        } else {
            printf("That is the wrong answer\n");
        }

        set_answered(category, value);
        remainingQuestions--;
        playerIndex++;
    }

    // Display the final results and exit
    show_results(players);

    return EXIT_SUCCESS;
}
