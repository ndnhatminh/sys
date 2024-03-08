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


// Task checking
#define HP(HP1) {\
if (HP1 >= 666) HP1 = 666;\
if (HP1 <= 0) HP1 = 0;\
}

#define EXP(EXP1) {\
if (EXP1 >= 600) EXP1 = 600;\
if (EXP1 <= 0) EXP1 = 0;\
}

#define M(M1) {\
if (M1 >= 3000) M1 = 3000;\
if (M1 <= 0) M1 = 0;\
}

#define E(E1) {\
if ((E1 < 0) || (E1 > 99)) return -99;\
}

// lam trong len
int up(float a);


//Task 2: ham tim so chinh phuong gan nhat
int nearestSquare(int a);
//Task 2: Ham xu ly so cua con duong 3int onedigit(int E2) ;
int onedigit(int E2);
int onedigittask2(int E2);

// Task 3: kiem tra cheo trai va phai

int thuonghoaso(int a);


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
