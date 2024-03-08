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


////////////////////PRIVATE DEFINES///////////////////////////
#define MAXHP 666
#define MINHP 0

#define MAXEXP 600
#define MINEXP 0

#define MAXMONEY    3000
#define MINMONEY    0

#define MAXROW  10
#define MAXCOL  10
///////////////////////////////////////////////


#include "main.h"


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

//////////////////// Support Functions ///////////////////////////
void checkLimit(int* hp1, int* hp2, int* exp1, int* exp2, int* m1, int* m2);
bool checkValidE(int e);

bool checkPerfectSqr(int num);
int findClosestPerfectSqr(int num);

int getOnedigitCoor(int num);

int findMaxDet(int x, int y, int arr[][MAXCOL]);
//////////////////////////////////////////////////////////////////

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
