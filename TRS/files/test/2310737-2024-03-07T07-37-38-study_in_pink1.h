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

int roundUp(float Num);
void moneyCheck(int* M);
void expCheck(int* EXP);
void hpCheck(int* HP);
int maxArray(int* Array, int n);

// Task 1
void sherlockGuess(int* EXP1, int E1);
int branch(int E1);

int firstMeet(int & exp1, int & exp2, int e1);
// Task 2
static int TotalSpend = 0;

void findSquare(int* Array);
float firstRoad(int EXP1);
void roadAction1(int* HP1, int* M1);
void roadAction2(int* EXP1, int* HP1, int* M1);
void roadAction3(int* EXP1, int* HP1, int* M1);
float secondRoad(int* EXP1, int* M1, int* HP1, int* E2);
float thirdRoad(int E2);

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2);
// Task 3
static int PositiveNumber = 0;
static int NegativeNumber = 0;
void fillArraywith(int* Arr, int MaxSize, int Value);

void taxiFill(int Taxi[10][10], int E3);
void findLeftCross(int Taxi[10][10], int PosX, int PosY, int* SizeLeft, int* LeftCross);
void findRightCross(int Taxi[10][10], int PosX, int PosY, int* SizeRight, int* RightCross);
void countPos(int Taxi[10][10], int E3);
void countNeg(int Taxi[10][10], int E3);
void sherlockFill(int SherlockWatson[10][10], int Taxi[10][10]);

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);
// Task 4
bool checkSEI(const char* S, const char* SE, int* SEI, int SizeS, int SizeSE);
bool checkSCI(const char* S, int* SCI);
bool checkSpecial(const char* S);
bool checkOther(const char* S, int* OT);

int checkPassword(const char* s, const char* email);
// Task 5
bool checkDupe(const char* Arr_pwds[], int* i, int Position);
int findDupeinArray(int* Pos, int OriginalDupePos);
int findLength(const char* Pwds);
void findMaxesinArray(int* Arr, int* ResultArr, int* NumberOfMaxes);

int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
