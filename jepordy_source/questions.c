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
    	strcpy(questions[i].category, categories[0]);
        questions[i].value = (i + 1) * 100;
        questions[i].answered = false;
    }

    strcpy(questions[0].question, "What is the language we learn in Operating Systems?");
    strcpy(questions[0].answer, "c");

    strcpy(questions[1].question, "What is the command to make a directory?");
    strcpy(questions[1].answer,"mkdir");

    strcpy(questions[2].question, "What is the command to print to console");
    strcpy(questions[2].answer, "printf");

    strcpy(questions[3].question, "What is the command for memory allocation?");
    strcpy(questions[3].answer, "malloc");

    // initialize algorithms category
    for (int i = 4; i < 8; i++ ) {
    	strcpy(questions[i].category, categories[1]);
        questions[i].value = (i - 3) * 100;
        questions[i].answered = false;
    }

    strcpy(questions[4].question, "What is the algorithm to find the largest number?");
    strcpy(questions[4].answer, "max");

    strcpy(questions[5].question, "What is the algorithm to find the smallest number?");
    strcpy(questions[5].answer, "min");

    strcpy(questions[6].question, "What is the algorithm to put an array in order?");
    strcpy(questions[6].answer, "sort");

    strcpy(questions[7].question, "Where was Al-Khwarizmi from?"); 
    strcpy(questions[7].answer, "persia");

    // initialize databases category
    for (int i = 8; i < 12; i++ ) {
    	strcpy(questions[i].category, categories[2]);
        questions[i].value = (i - 7) * 100;
        questions[i].answered = false;
    }

    strcpy(questions[8].question, "What is the command to select an attribute in SQL?");
    strcpy(questions[8].answer, "SELECT");

    strcpy(questions[9].question, "What is the command for conditions in SQL?");
    strcpy(questions[9].answer, "WHERE");

    strcpy(questions[10].question, "What is the command to choose a table in SQL?");
    strcpy(questions[10].answer, "FROM");

    strcpy(questions[11].question, "What is a row referred to as?");
    strcpy(questions[11].answer, "tuple");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    // add questions, points, only unanswered questions
    //for (int i = 0; i < 3; i++ ) {
    	//printf("%c ",categories[i]);
    //}

	for (int i = 0; i < 3; i++) {
		printf("/n%s: ", categories[i]);
		for (int a = 0; i < 12; a++) {
			if (strcmp(questions[a].category, categories[i]) == 0 && (!questions[a].answered)) {
				printf("%d ", questions[a].value);
			}
		}
	}
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    /*for(int i = 0; i < 12; i++){
        if((strcmp(category, &questions[i].category) == 0) && 
            value == questions[i].value && 
            strcmp(answer, &questions[i].answer) == 0){
            return true;
        }
    }
            
    return false;*/
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    /*for(int i = 0; i < 12; i++){
        if(strcmp(category, &questions[i].category) == 0 && value == questions[i].value){
            return questions[i].answered;
        }
    }
    return false;*/
}
