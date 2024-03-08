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

// Global helping functions
void validateHP(int&);
void validateEXP(int&);
void validateM(int&);
// End global helping functions

// Task 1
int firstMeet(int & exp1, int & exp2, int e1);
// Helping functions
void mission1case1(int&, int);
// End Task 1

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);
// Helping functions
int nearestPerfectSquare(int);
void foodAndBeverage(int&, int&);
void rentATaxiOrCarriage(int&, int&);
void homeless(int&, int&);
int findIndex(int);
// End Task 2

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);
// Helping functions
int leftDiagonal(int map[10][10][2], int, int);
int rightDiagonal(int map[10][10][2], int, int);
int findI(int map[10][10][2], int);
int findJ(int map[10][10][2], int);
// End Task 3

// Task 4
int checkPassword(const char * s, const char * email);
// Helping functions
void findSE(const char*, char se[100]);
bool isValidPassword(const char*, char se[100]);
// End Task 4

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);
// Helping functions

// End Task 5
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */