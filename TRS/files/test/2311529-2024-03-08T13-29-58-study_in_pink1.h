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
//1. Ham tinh so chinh phuong gan nhat
int scp(int number);
//Ham tinh P1
double tinhP1(int &EXP1);
//Ham tinh P3
double tinhP3(int & E2);
//Ham mo ta con duong 2
//1. Ham mo ta hanh dong mua thuc an va nuoc duong
void hd1(int &HP1, int &M1, int & tiensd);
//2. Ham mo ta hanh dong di taxi hoac xe ngua
void hd2(int& EXP1, int& M1, int & tiensd);
//Ham mo ta hanh dong hoi nguoi vgc
void hd3(int& EXP1, int& M1, int & tiensd);
//Ham mo ta con duong 2
void cd2(int & HP1, int & EXP1, int & M1, int &E2);
// Ham tinh P2
double tinhP2(int &EXP1);
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
const char* before(const char* email);
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
