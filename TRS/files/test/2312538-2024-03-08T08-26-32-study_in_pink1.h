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

int calculateEXP(int &EXP);
int calculateHP(int &HP);
int calculateM(int &M);
int ceilNum(float &temp, float changingAmount);

// Task 1
void theReturnFromAfghanistanOfWatson(int &exp1, int &exp2, int e1);
void brotherOfWatson(int &exp1, int &exp2, int e1);
int firstMeet(int &exp1, int &exp2, int e1);

// Task 2
int squareNum(int &EXP1, int &M1);
float probability(int &EXP1, int S);
void eventPoint(int &HP1, int &EXP1, float HP1_tmp, float EXP1_tmp, int M1, int M1_tmp, int E2, bool &eventPointWhenE2Even, bool &eventPointWhenE2Odd);
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
char *defse(const char *email, int seLength);
int calculateseLength(const char *email, int emailLength);
int calculateEmailLength(const char *email);
int calculatePassLength(const char *s);
int checkValidPass(const char *s, const char *email, const char *se, int emailLength, int passLength, int seLength, bool isValidPass);
bool checkValidEmail(const char *email, int emailLength);
void similarRespectiveTwoChar(const char *s, int passLength, int &sSimilar, int &sci);
int checkPassword(const char *s, const char *email);
bool isSEsubStrOfPass(const char *s, const char *se, int &sei);
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds);
void calculateLengthOfMaxTimesPass(const char *arr_pwds[], const int *times, const int *iRP, int num_pwds, int *maxTimesPassLength, int lengthiRP);
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
