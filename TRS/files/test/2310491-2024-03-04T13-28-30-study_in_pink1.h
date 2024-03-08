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

//Return HP to the correct amount
void health_points(int& HP);
//Return EXP to the correct amount
void experience_points(int& EXP);
//Return money to the correct amount
void  initial_money(int& M);

//The first meeting
int case_1(int& exp1, int& exp2, int e1);
int case_2(int& exp1, int& exp2, int e1);

//Calculation on EXP, HP
void exp_caculate(int& exp, double i, bool s_d);
void HP_caculate(int& HP, double i, bool s_d);

//Trace Luggage
double probability(int exp);
int road03(int e2);
void road02(int& HP1, int& M1, int& exp1, int e2);
void event01(int& HP1, int& M1, int& fee);
void event02(int& M1, int& exp1, int& fee);
void event03(int& exp1, int& M1, int& fee);

//Chase Taxi
int Sum_of_digits(int num);
int left_max(int array[][10], int row, int col);
int right_max(int array[][10], int row, int col);

//Check email, password
bool checkEmail(const char* email);
bool checkDigits(char s);
bool checkContain(const char* s, const char* se, int idx, int i);
bool checkRepeat(const char* s, int idx);
int checkSpecialDigits(char s);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
