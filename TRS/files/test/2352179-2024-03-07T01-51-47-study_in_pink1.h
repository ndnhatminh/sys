/*
 * Author: Võ Tiến
 * Date: 20.02.2023
 * FB: https://www.facebook.com/profile.php?id=100056605580171
 * FB nhóm: https://www.facebook.com/groups/211867931379013
 * khóa học KTLT1: https://www.facebook.com/photo/?fbid=845258184037693&set=gm.404500422115762&idorvanity=211867931379013
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile(const string &filename, int &HP1, int &HP2, int &EXP1, int &EXP2, int &M1, int &M2, int &E1, int &E2, int &E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int &exp1, int &exp2, int e1);

// Task 2
double pct(int &EXP1);
double traceLuggage_1(int &HP1, int &EXP1, int &M1, int E2);
double traceLuggage_2_odd(int &HP1, int &EXP1, int &M1, int E2);
double traceLuggage_2_even(int &HP1, int &EXP1, int &M1, int E2);
double traceLuggage_3(int &HP1, int &EXP1, int &M1, int E2);
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2);

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3);

// Task 4
bool checkNotSymbol(const char *s, int &count, int &notSymbol);
int checkSymbol(const char *s, int &countSymbol, int &count);
bool containSE(const char *s, string se, int &count, int &se_ref);
bool twoAdjacent(const char *s, int &count, int &adjacent);
int checkPassword(const char *s, const char *email);

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
