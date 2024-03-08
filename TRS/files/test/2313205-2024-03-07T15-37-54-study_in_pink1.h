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

//Hàm phụ cho toàn bài
void CheckHP(int& HP);
void CheckEXP(int& EXP);
void CheckMoney(int& M);
void ThayDoi(int& m, float n);
//Hàm phụ cho Task1
void Task1_D1(int& exp2, int e1);
void Task1_D2(int& exp2, int e1);
void Task1_D3(int& exp2, int e1);

//Hàm phụ cho Task2
bool ifNearBy(int n);
void Task2_R2(int& M1, int& HP1, int& EXP1, double condition);

//Hàm phụ cho Task3
int MaxCheoTrai(int Matrix[10][10], int i, int j);
int MaxCheoPhai(int Matrix[10][10], int i, int j);

//Hàm phụ cho Task4
bool KyTuDacBiet(const char* s);

//Hàm phụ cho Task5
//Không có

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
