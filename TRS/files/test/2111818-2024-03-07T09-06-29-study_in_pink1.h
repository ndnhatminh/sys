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
void checkEXP(int &EXP);
void checkHP(int &HP);
void checkM(int &M);
// Task 1
int firstMeet(int & exp1, int & exp2, int e1);
void calexp1(int& exp1, int e1);
void firstmeet1(int &exp1, int &exp2, int e1);
void firstmeet2(int &exp1, int &exp2, int e1);
// Task2  
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);
double traceLuggage_Street1(int & exp1);
void sk1(int & hp1,int & m1);
void sk2(int & exp1 , int & m1 );
void sk3(int & exp1 , int & m1);
double traceLuggage_Street2(int &hp1, int &exp1, int &m1, int e2);
double traceLuggage_Street3(int e2);
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);
int loca( int s);
int swPoint(int arr[10][10], int x, int y);
// Task 4
int checkPassword(const char * s, const char * email);
int checkPass( string pass, string Email);
// Task 5
int vitriMK( int array1[], int array2[], int num_pwds);
int findCorrectPassword(const char * arr_pwds[], int num_pwds);
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
