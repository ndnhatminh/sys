/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2023
 * Author: Vu Van Tien
 * Date: 02.02.2023
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile(const string &filename, int &HP1, int &HP2, int &EXP1, int &EXP2, int &M1, int &M2, int &E1, int &E2, int &E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkHP(int &HP);
void checkEXP(int &EXP);
void checkMoney(int &M);

////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int &exp1, int &exp2, int e1);

void caseFirst(int &exp1, int &exp2, int e1);
void caseSecond(int &exp1, int &exp2, int e1);

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2);

double pathFirst(int EXP1);
double pathSecond(int& HP1, int& EXP1, int& M1, int E2);

void pathSecondTaskFirst(int& HP1, int& M1, int& spent);
void pathSecondTaskSecond(int& EXP1, int& M1, int& spent);
void pathSecondTaskThird(int& EXP1, int& M1, int& spent);

double pathThird(int E2);

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3);

int maxRightDownDiagonal(int arr[10][10], int i, int j);
int maxLeftDownDiagonal(int arr[10][10], int i, int j);
// Task 4
int checkPassword(const char *s, const char *email);

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
