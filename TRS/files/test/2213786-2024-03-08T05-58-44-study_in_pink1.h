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
int limitHP(int hp); //Limited HP1 and HP2
int limitEXP(int exp); //Limited EXP1 and EXP2
int limitMoney(int m); //Limited M1 and M2
bool checkEvent(int e); //Limited E1, E2 and E3
// Task 1
int infor1CaseTwoFirstMeet(int exp2, int e1);
int infor2CaseTwoFirstMeet(int exp2, int e1);
int infor3CaseTwoFirstMeet(int exp2, int e1);
int CaseOneFirstMeet(int e1); //Calculate EXP2 will be add much EXP (+0.5pts)
void CaseTwoFirstMeet(int & exp2, int e1, bool & checkInfo5CaseTwoFirstMeet); //Calculate EXP2 will be add much EXP (+1pt)
int firstMeet(int & exp1, int & exp2, int e1); //MISSION 1 (1.5pts)
// Task 2
int event1Way2TraceLuggage(int & HP1, int & M1);
int event2Way2TraceLuggage(int & EXP1, int & M1);
int event3Way2TraceLuggage(int & EXP1, int & M1);
double Way1TraceLuggage(int EXP1);
double Way2TraceLuggage(int & HP1, int & EXP1, int & M1, int E2);
int Way3TraceLuggage(int E2);
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3); //MISSION 2 (2.5pts)
// Task 3
void findIndex(int & row); //Find index Taxi meets Holmes
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3); //MISSION 3 (3pts)
// Task 4
int checkSEinS(string S, string se, int sizeS, int sizeSE); //Find first index in string S has substring sample string se
int checkSampleInit(string S, int sizeS); //Find first index in string S has least 3 sample inits 
bool checkSpecialInit(string S, int sizeS); //Check in string S hasn't special init
int checkNumAndInitIdentify(string S, int sizeS); //Find first index in string S hasn't Number, Special, Upper and Lower init
int checkPassword(const char * s, const char * email); //MISSION 4 (1.5pts)
// Task 5
int findMaxLength(char *arr_pwds[], int num_pwds); //Find max length in array of string
int * findArrayDuplicate(char *arr_pwds[], int num_pwds, int &max_duplicate); //Find array number of duplicate in array of string
char ** maxStringDuplicate(char *arr_pwds[], int num_pwds, int array_duplicate[], int max_duplicate, int & size); //Find array of string has max duplicate
bool checkMaxElement(char * maxDup, char * element); //Check max element in array of string
int findCorrectPassword(const char * arr_pwds[], int num_pwds); //MISSION 5 (1.5pts)
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
