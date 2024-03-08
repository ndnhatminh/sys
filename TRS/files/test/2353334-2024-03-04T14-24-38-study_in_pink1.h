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
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3);

//Task 3
int findthefinal(int n);
int max(int n, int m);
void findDiagnal(int matrix[10][10] , int rowMeet, int columnMeet, int & sherlockWatson);
void creatematrixtaxi(int matrix[10][10] , int E3 ,  int &rowMeet, int &columnMeet);
int changeEXPup(int n);
int changeEXPdown(int n);
int changeHPup(int n);
int chanegHPdown(int n);
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
bool myLength(const char *s);
bool haveSpecialChar(const char * s);
bool notHaveSe(const char * s,const char * se , int & pos);
bool notHavesSameChar(const char * c, int & pos);
void takeSe( char se[] , const string & email);
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
