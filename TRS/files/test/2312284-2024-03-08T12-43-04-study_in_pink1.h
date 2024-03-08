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

int CheckEXP(int a);
int CheckHP(int a);
int CheckMoney(int a);
int CheckE(int a);
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int CloseSquarenum(int a);
int one_or_two(int a,int b[]);
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int largest_left_cross(int a[10][10], int i, int j);
int largest_right_cross(int a[10][10], int i, int j);
int absolute(int a);
int meeti(int a[10][10], int e3);
int meetj(int a[10][10], int e3);
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int len(const char *a);
int lens(string a);
int checkse(string a, string se);
int checkspe(const char* a);
int checksam(const char* a);
int checkremain(const char* a);
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
