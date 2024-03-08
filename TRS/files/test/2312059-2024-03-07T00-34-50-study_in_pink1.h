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


//  DECLARATION:
//Variables:
//Functions:
    //Default:
void reset_HP(int &HP1, int &HP2);
void reset_EXP(int &EXP1, int &EXP2);
void reset_M(int &M1, int &M2);
void reset_E(int &M1, int &M2);
    //Mission1:

    //Mission2:
    
int abs(int Var);
int squareRoot(int n);
int find_SquareNumber(int Var);
bool enough_Money(int Money_Had, int Money_Need, int E2, int M1);
    //Mission3:

int find_SumUnit(int Var);
int Score(int line,int row,int TaxiPoints[10][10]);
    //Mission 5:
int lenSTR(const char * Var);



// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);
int find(const char * Var, char letter);
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
