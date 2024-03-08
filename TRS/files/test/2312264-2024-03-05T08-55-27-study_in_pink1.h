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
int firstMeet(int & exp1, int & exp2, int e1);
int firstMeetCase1(int &, int &, int );
int firstMeetCase2(int &, int &, int );
void checkExp(int &);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);
float traceLuggage1(int);
float traceLuggage2(int &, int &, int &, int);
void wayOfFindingLuggage(int &, int &, int &, int);
float traceLuggage3(int);
void checkMoney(int &);
void checkHP(int &);
int findPerfectNumber(int);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);
int haflUnderTriangle(int a[][10], int);
int haflAboveTriangle(int a[][10], int);
int findIndex(int);
int maxOfLeftDiagonal(int a[][10], int, int);
int maxOfRightDiagonal(int a[][10], int, int);

// Task 4
int checkPassword(const char * s, const char * email);
string beforeCharAt(string);
int checkLength(string);
int checkDuplicateString(string, string);
int checkDuplicateChar(string);
int checkChar(string);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
