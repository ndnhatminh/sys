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

// Task 1
int checkExp(int &exp);
int firstMeet(int &exp1, int &exp2, int e1);

// Task 2
int checkHP(int &HP);
float searchS(int exp1);
int checkM(int &M1);
float calculateP2(int &HP1, int &EXP1, int &M1, int E3);
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3);

// Task 3
int findSumij(int &cell);
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3);

// Task 4
int checkPassword(const char *s, const char *email);
bool checkSize(const char *s);
bool findSe(const char *email, const char *s, int &sei);
bool findduplicate(const char *s, int &sci);
bool findspecialCharacters(const char *s);
bool isValid(const char *s, int &isV);

// Task 5
bool findMaxPassword(const char *arr_pwd1, const char *arr_pwd2);
int findCorrectPassword(const char *arr_pwds[], int num_pwds);
int findDuplicatePassword(const char *arr_pwd[]);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
