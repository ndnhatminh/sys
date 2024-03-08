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


//Range of EXP, HP, M
void limitRangeEXP(int &EXP, int a, int b);
void limitRangeHP(int &HP, int a, int b);
void limitRangeM(int &M, int a, int b);


// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

//Task 2.1: Function used to find the nearest square number
int squareNumber(int x);
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3.1: Reduce 2 digits to 1 digit
int reduce2to1(int x);
// Task 3.2: Find maximum value of two intersecting diagonals
int findMax(int a[][10], int x, int y);
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
