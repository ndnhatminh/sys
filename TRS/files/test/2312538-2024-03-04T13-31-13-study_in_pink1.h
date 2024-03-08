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

int conditionEXP(int &EXP);
int conditionHP(int &HP);
int conditionM(int &M);
int ceilNum(float &temp);

// Task 1
void firstMeetCase1(int &exp1, int &exp2, int e1);
void firstMeetCase2(int &exp1, int &exp2, int e1);
int firstMeet(int &exp1, int &exp2, int e1);

// Task 2
int squaredNum(int &EXP1, int &M1);
float probability(int &EXP1, int S);
float traceLuggageRoad01(int &HP1, int &EXP1, int &M1, int E2);
float traceLuggageRoad02(int &HP1, int &EXP1, int &M1, int E2);
float traceLuggageRoad03(int &HP1, int &EXP1, int E2, float P1, float P2);
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2);

// Task 3
void defMapTaxi(int E3, int mapTaxi[10][10]);
int calPoints(int &EXP1, int &EXP2, int &HP1, int &HP2, int E3, int mapTaxi[10][10], int pointsHolmesWatson, int &pointsTaxi);
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3);
int defMaxDiagonalMapVal(int mapTaxi[10][10], int i, int j);

// Task 4
string checkPassword_email(const char *s, const char *email);
int checkPassword_pass(const char *s, const char *email, const char *se, bool &isValidPass, int seLength);
bool checkPassword_passDuplicate(const char *s, const char *se, int passLength, int seLength, int &sei);
int checkPassword(const char *s, const char *email);

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
