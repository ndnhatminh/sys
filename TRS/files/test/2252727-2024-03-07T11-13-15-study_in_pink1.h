/*
* Author: Võ Tiến
* Date: 20.02.2023
* FB: https://www.facebook.com/profile.php?id=100056605580171
* FB nhóm: https://www.facebook.com/groups/211867931379013
* khóa học KTLT1: https://www.facebook.com/photo/?fbid=845258184037693&set=gm.404500422115762&idorvanity=211867931379013
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

void copyFile(const std::string& sourcePath, const std::string& destinationPath);
void printTestFail(int i);
void comparefile(int start, int end);
bool isNumber(string str);

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Task 0
void checkTask1(int & EXP1, int & EXP2);

void checkTask2(int &HP1, int &EXP1, int &M1);

void checkTask3(int &HP1, int &EXP1, int &HP2, int &EXP2);

bool isPerfectSquare(int n);

int nearestPerfectSquare(int n);

int getPi(int E2);

const char* findForbiddenSubstring(const char* email);

int sumDigits(int n);

bool checkE(int E);
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
