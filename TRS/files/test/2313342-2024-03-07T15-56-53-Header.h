#pragma once
/*
* Author: Võ Ti?n
* Date: 20.02.2023
* FB: https://www.facebook.com/profile.php?id=100056605580171
* FB nhóm: https://www.facebook.com/groups/211867931379013
* khóa h?c KTLT1: https://www.facebook.com/photo/?fbid=845258184037693&set=gm.404500422115762&idorvanity=211867931379013
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "Header1.h"



bool readFile(const string& filename, int& HP1, int& HP2, int& EXP1, int& EXP2, int& M1, int& M2, int& E1, int& E2, int& E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int check(int& a, int firstpoint, int lastpoint);
double check_double(double& a, int firstpoint, int lastpoint);
int check_string(std::string& str1, std::string& str2);
bool check_string_bool(std::string& str1, std::string& str2);
int vi_tri(int& n);

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

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */

