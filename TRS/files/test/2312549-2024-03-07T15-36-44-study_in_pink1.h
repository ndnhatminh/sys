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

int checkEXP(int EXP);
int checkHP(int HP);
int checkM(int M);
//==========funtion task1=======================//
int case1(int EXP1, int EXP2, int E1);
int case2(int EXP1, int EXP2, int E1);
//=========funtion task2 =======================//
int find_least_chinhphuong(int EXP);
int chisoxs(int E);
int chiso(int E);
float xacsuatconduong1(int EXP1);
float xacsuatconduong2le(int EXP1, int HP1, int M1);
float xacsuatconduong2chan(int EXP1, int HP1, int M1);
float xacsuatconduong3(int E2);

//============== funtion task3=================//
int maxleft(int E3);
int maxright(int E3);



//============== funtion task 4================//
  




// Task 1
int firstMeet(int& exp1, int& exp2, int e1);

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E3);

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3);

// Task 4
int checkPassword(const char* s, const char* email);

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds);


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
#pragma once 
\


