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

// hàm làm tròn thành số nguyên và tăng 1 đơn vị
int roundUp(double num);

// hàm giới hạn giá trị
int limit(int value, int min, int max);

int limitHP(int HP);

int limitEXP(int EXP);

int limitM(int M);

// Hàm tính giá trị tuyệt đối:
double my_abs(double x);

// Hàm tính căn bậc hai:
double my_sqrt(double S);

// Hàm tính xác suất P của từng con đường:
double Probability(double EXP);

// hàm tính giá trị i:
int caculateI(int event);

// Hàm tìm số lớn nhất giữa hai số:
int my_max(int a, int b);

// hàm tìm kiếm chuỗi con trong chuỗi mẹ
const char* My_strstr(const char* mainString, const char* subString);

// Hàm so sánh hai chuỗi và trả về true nếu chuỗi giống nhau, ngược lại trả về false
bool my_strcmp(const char *str1, const char *str2);

// Hàm tính độ dài của chuỗi
int my_strlen(const char *str);

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

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
