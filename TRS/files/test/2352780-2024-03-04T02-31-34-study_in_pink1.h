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
int checkVarEXP(int n);
int checkVarHP(int n);
int checkVarM(int n);
int case1W (int & exp2, int e1);
int case1S (int & exp1, int e1);
int case2W (int & exp2, int e1);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);
int nearSquare(int exp1);
void Road02Energy(int & HP1, int & M1, int & Paid);
void Road02Drive(int & EXP1, int & M1, int & Paid);
void Road02Home(int & EXP1, int & M1, int & Paid);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);
int twotoONE(int a);
int findMAXtwo(int num1, int num2);
int findMAX(int a, int b, int c, int d);

// Task 4
int checkPassword(const char * s, const char * email);
int isValid(const string& str);
int checkTriple(const char* s);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
