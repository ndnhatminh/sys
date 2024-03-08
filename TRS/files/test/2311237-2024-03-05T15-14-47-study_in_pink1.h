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
int firstMeet(int &exp1, int &exp2, int e1);
void firstMeetCase1(int &exp1, int &exp2, int e1);
void firstMeetCase2(int &exp1, int &exp2, int e1);

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3);
float traceLuggagePath1(int &exp1);
float traceLuggagePath2(int &hp1, int &exp1, int &m1, int e2);
void traceLuggagePath2_Event1(int &hp1, int &m1, int &moneySpent);
void traceLuggagePath2_Event2(int &exp1, int &m1, int &moneySpent);
void traceLuggagePath2_Event3(int &exp1, int &m1, int &moneySpent);
float traceLuggagePath3(int e2);

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3);
void gridScoreCar(int* grid, int row, int col, int e3);
void getEncounterPos(int* grid, int row, int col, int &x, int &y, int e3);
int playerScoreAt(int* grid, int x, int y, int row, int col);

// Task 4
int checkPassword(const char* s, const char* email);
string getUsername(string email);

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds);
int countOccurrences(string arr[], int size);

bool isInRange(int e, int floor, int ceil);
void clamp(int& value, int floor, int ceil);
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
