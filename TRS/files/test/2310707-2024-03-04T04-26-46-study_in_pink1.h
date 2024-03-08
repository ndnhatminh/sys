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
int traceLuggage(int & HP1, int & EXP1, int & M1, int e2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int e3);

// Task 4
int checkPassword(const char * password, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);
double roundUp(double&);
int check1(const char[]);
int check2(const char[], const char[]);
int check3(const char[]);
int check4(const char[]);
int check5(const char[]);
string find_se(const char[]);
int findMax(string [], int [], int);
bool checkSqNum(int);
int findLeft(int);
int findRight(int);
int finalFind(int);
int totalDigits(int);
void taxiMatrix(int [][10], int, int);
int findOrdinate(int [][10], int, int);
int findAbscissa(int [][10], int, int);
void checkVar2(double&, double&, double&);
void checkVar1(double&, double&);
void checkVar3(double&,double&,double&,double&);


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
