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

// Other functions
int expCheck(float exp);

int findNearSquare(int exp);

int hpCheck(float hp);

int mnCheck(float mn);

int diag1(int arr[10][10], int i, int j);

int diag2(int arr[10][10], int i, int j);

int diag3(int arr[10][10], int i, int j);

int diag4(int arr[10][10], int i, int j);

int findMax(int n1, int n2, int n3, int n4);

int findTheSame(const char* largeString, const char* smallString);

int findTheSpecial(const char* largeString);

int findTheCont(const char* largeString);

int checkErr(const char* largeString);

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

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
