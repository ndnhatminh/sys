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

bool readFile(const string& filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int& exp1, int& exp2, int e1);

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2);

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3);

// Task 4
int checkPassword(const char* s, const char* email);

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds);

int calIndex(int);

int isAlnum(int);

int Ceil(float);

#define checkM1half(m1, temp) {\
if (m1 < temp) break;\
}
#define checkM1(m1) {\
if (m1 == 0) break;\
}
#define TESTEXP(exp) {\
  if (exp > 600) (exp = 600);\
  if (exp < 0) (exp = 0) ;\
}
#define TESTHP(hp) {\
  if (hp > 666) (hp = 666);\
  if (hp < 0) (hp = 0);\
}
#define TESTM(m) {\
  if (m > 3000) (m = 3000);\
  if (m < 0) (m = 0);\
}
#define calPoss(exp, p) {\
  int temp = sqrt(exp);\
  if ((sqrt(exp) - temp)*1.0 > (temp + 1 - sqrt(exp))*1.0) p = 1.0*(exp/((temp + 1) * (temp + 1)) + 80)/123.0;\
  if (exp == 0) p = 1;\
}

#define index(n, i) {\
    if (n < 10) i = n;\
    else {\
        int s = n % 10 + n / 10;\
        i = s % 10;\
    }\
 }
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
