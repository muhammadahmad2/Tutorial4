/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Muhammad Ahmad, Timothy MacDougall, David McDonald, Devin Westbye
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern char* tokenize(char *input, char *tokens);

// Sorts the player array by lowest score to highest
extern void quicksort(player *players, int first, int last);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players);

#endif /* JEOPARDY_H_ */
