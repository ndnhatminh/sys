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

// Task 2
double road1(int & EXP1);
double road2(int & HP1, int & EXP1, int & M1, int E2);
double road3(int & HP1, int & EXP1, int E2);

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

int roundUp(double x);
int resetEXP(int & EXP);
int resetHP(int & HP);
int resetM(int & M);
int findMax(int a[10][10], int m, int n);
int count(int & count);
int check_se(string pass, string se, int l1, int l2);
int check_char1(string pass, int len);
int check_char2(string pass, int len);
int check_char3(string pass, int len);
void checkPass1(const char * arr_pwds[], int num_pwds, int arr[]);
int checkPass2(const char * arr_pwds[], int num_pwds, int arr[]);
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
