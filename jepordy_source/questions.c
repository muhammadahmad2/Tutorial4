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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array

    // initialize programming category
    for (int i = 0; i < 4; i++ ) {
    	questions[i].category = categories[0];
	    questions[i].value = (i + 1) * 100;
	    questions[i].answered = false;
    }

    questions[0].question = "What is the language we learn in Operating Systems?";
    questions[0].answer = "c";

    questions[1].question = "What is the command to make a directory?";
    questions[1].answer = "mkdir";

    questions[2].question = "What is the command to print to console";
    questions[2].answer = "printf";

    questions[3].question = "What is the command for memory allocation?";
    questions[3].answer = "malloc";

    // initialize algorithms category
    for (int i = 4; i < 8; i++ ) {
    	questions[i].category = categories[1];
	    questions[i].value = (i - 3) * 100;
	    questions[i].answered = false;
    }

    questions[4].question = "What is the algorithm to find the largest number?";
    questions[4].answer = "max";

    questions[5].question = "What is the algorithm to find the smallest number?";
    questions[5].answer = "min";

    questions[6].question = "What is the algorithm to put an array in order?";
    questions[6].answer = "sort";

    questions[7].question = "Where was Al-Khwarizmi from?"; 
    questions[7].answer = "persia";

    // initialize databases category
    for (int i = 8; i < 12; i++ ) {
    	questions[i].category = categories[2];
	    questions[i].value = (i - 7) * 100;
	    questions[i].answered = false;
    }

    questions[8].question = "What is the command to select an attribute in SQL?";
    questions[8].answer = "SELECT";

	questions[9].question = "What is the command for conditions in SQL?";
    questions[9].answer = "WHERE";

	questions[10].question = "What is the command to choose a table in SQL?";
    questions[10].answer = "FROM";

	questions[11].question = "What is a row referred to as?";
    questions[11].answer = "tuple";
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int i = 0; i < 3; i++ ) {
    	printf("%c ",categories[i]);
    }
    printf("\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for(int i = 0; i < 12; i++){
        if((strcmp(category, &questions[i].category) == 0) && 
            value == questions[i].value && 
            strcmp(answer, &questions[i].answer) == 0){
            return true;
        }
    }
            
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for(int i = 0; i < 12; i++){
        if(strcmp(category, &questions[i].category) == 0 && value == questions[i].value){
            return questions[i].answered;
        }
    }
    return false;
}
