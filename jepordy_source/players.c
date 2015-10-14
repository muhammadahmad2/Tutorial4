/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Muhammad Ahmad, Timothy MacDougall, David McDonald, Devin Westbye
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Function that checks if a player exists in the players array.
bool player_exists(player *players, char *name)
{
	// Variable remains false unless player is found
	bool playerExists = false;

	// Loop through the players array comparing each name to *name
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		// Check if player name exists
	     	if(strcmp(name, players[i].name)==0)
	     	{
	     		playerExists = true; // The player was found.
	     	}
	}

	// Return the boolean holding of the player exists or not
    	return playerExists;
}

// Function that checks if a player exists then updates their score if true.
void update_score(player *players, char *name, int score)
{
	// Index that holds which index belongs to the player
    	int playerIndex = -1;
	
	// Loop through players
	for(int i = 0; i < NUM_PLAYERS; i++)
	{
		// Check if player name exists
		if(strcmp(name, players[i].name)==0)
	     	{
			// Set player index to the player to change score.
	     		playerIndex = i;
	     	}
	}
	
	// If playerIndex wasn't changed - Player not found
	if(playerIndex == -1)
	{
		// Display the player was not found.
		printf("\nError: Player not found\n");
	}
	else // Player was found
	{
	// Player was found, update the score.
	players[playerIndex].score += score;
	}
}


