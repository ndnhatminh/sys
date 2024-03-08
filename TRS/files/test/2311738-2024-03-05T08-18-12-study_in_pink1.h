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

//hàm làm tròn số
int roundUp(double num);

//hàm giới hạn giá trị
int limit(int value, int minValue, int maxValue);

//hàm tìm số chính phương S gần EXP1 nhất
int find_S(int EXP1);

//hàm trị tuyệt đối
int Abs(int num);

//hàm tìm số lớn hơn
int myMax(int a, int b);

// Hàm kiểm tra ký tự có phải là chữ cái (in hoa hoặc in thường) không
bool isLetter(char c);

// Hàm kiểm tra ký tự có phải là chữ số không
bool isDigit(char c);

// Hàm kiểm tra ký tự có phải là ký tự đặc biệt không
bool isSpecialChar(char c);

// Hàm so sánh hai chuỗi
int strcmp(const char *s1, const char *s2);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
