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
int check(int n, int firstpoint, int lastpoint);
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3);
void  road2ev1(int & HP1, int & EXP1, int & M1, int E2 );
void road2ev2(int & HP1, int & EXP1, int & M1, int E2 );
void  road2ev3(int & HP1, int & EXP1, int & M1, int E2 );
int check(int n, int firstpoint, int lastpoint);
int square(int & exp1, int & s);
void digitsum(int & i);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);
int check(int n, int firstpoint, int lastpoint);
void digitsum(int & i);
// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
