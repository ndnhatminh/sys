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

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
//Check variable function
int checkHP(double HP);
int checkEXP(double EXP);
int checkMoney(double M);
int checkEvent(int E);
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
bool isPerfectSquare(int n);
int findNearestPerfectSquare(int exp1);
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int findMax(int matrix[10][10], int row, int col);
void printSherlockWatsonMatrix(int matrix[10][10]);
int countValuesGreaterThan(int matrix[10][10], int E3);
int countValuesLessThan(int matrix[10][10], int E3); 
int sumDigits(int num);
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
bool isDigit(char c);
bool isLowercase(char c);
bool isUppercase(char c);
bool isValidSpecialChar(char c);
int findAtSymbol(const char* email);
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
