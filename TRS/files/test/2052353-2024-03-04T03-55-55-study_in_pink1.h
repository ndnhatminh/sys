/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"
#define IS_EVEN(n)      (((n) & 1) == 0)
#define FIRST_PIECE(n)  (n/4 + 1 + 19)
#define SECOND_PIECE(n) (n/9 + 1 + 21)
#define THIRD_PIECE(n)  (n/16 + 1 + 17)
#define NO_SPEC_CHAR    -2
#define OK              -10

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);


//Supported Data Structure
struct Password{
    std::string value = "";
    int count = 0;
};
// Supported Function
int verifyEXP(float exp);
int verifyHP(float hp);
int verifyMoney(float money);
bool verifyEvent(int event);
void whereWatsonReturn(int &exp1, int &exp2, int e);
void brotherOrSister(int &exp1, int &exp2, int e);
float firstRoute(int &exp);
float secondRoute(int &exp, int &hp, int &money, int e);
float thirdRoute(int &exp, int &hp, int e);
int foodAndBeverage(int &hp, int &money);
int taxiOrHorse(int &exp, int &money);
int poorManHelp(int &exp, int &money);
int closestSquareNumber(int num);
void initializeMatrix(int *array, int rows, int cols, int e);
int convertToOneDigit(int num);
int min(int a, int b);
int max(int a, int b);
int maxDiagonal(int *array, int rows, int cols, int xPos, int yPos);
int isAlphanumeric(std::string s);
Password* distinctList (const char* array[], int size, int& distinctCount);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
