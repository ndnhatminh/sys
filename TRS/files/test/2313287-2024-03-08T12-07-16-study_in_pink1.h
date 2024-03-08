////////////////////////////////////////////////////////////////////////////////////////
///                                                                                  ///
///                        "A STUDY IN PINK" THE ASSIGNMENT                          ///
///                                                                                  ///
/// File name       : study_in_pink1.h                                               ///
/// Author          : NGUYEN HUNG THINH                                              ///
/// Student's ID    : 2313287                                                        ///
/// Email           : thinh.nguyen1172005@hcmut.edu.vn                               ///
/// Class           : MT23KTM1                                                       ///
/// Finish Raw Code : 28/02/2024                                                     ///
/// Finish Debug    : 01/03/2024 - 02:20 AM                                          ///
/// Code written in : Visual Studio 2022 (x64) 17.9.1 - A Study in Pink solution     ///
/// Testcase        : Author: Vo Tien (1000 testcases)                               ///
///                   Date : 20/02/2023                                              ///
///                   FB : https ://www.facebook.com/profile.php?id=100056605580171  ///
////////////////////////////////////////////////////////////////////////////////////////

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
