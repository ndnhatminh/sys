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
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);
// Hp limit check
void hpCheck(int &HP);
// Money check
void moneyCheck(int &M );
// Exp limit check
void  expCheck(int &exp);
// E value check
bool eCheck(int e);
// Nearest square number finder
int findSquare(int exp1);
// Trace luggage path 1
double firstPath(int EXP1);
// Trace luggage path 2
double secondPath(int& HP1, int& EXP1, int& M1, int E2);
// Path 2 first event
void pathTwoFirst(int& HP1, int& M1);
// Path 2 second event
void pathTwoSecond(int& EXP1, int &M1);
// Path 2 third event
void pathTwoThird(int& EXP1, int &M1);
// Trace luggage path 3
double thirdPath(int E2);
// Max value of a left slant
int maxSlantLeft(int taxiPoint[][10], int i, int j);
// Max value of a right slant
int maxSlantRight(int taxiPoint[][10], int i, int j);
//Convert number with 2 digits
void convert(int& f);
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
