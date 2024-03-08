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
// Those function is used to check the input of the testcase
void inputEXP1(int &EXP1);
void inputHP1(int &HP1);
void inputM1(int &M1);
bool inputE1(int &E1);
void inputEXP2(int &EXP2);
void inputHP2(int &HP2);
void inputM2(int &M2);
bool inputE2(int &E2);

// This function is used to check if the number is not an integer
bool isNotInteger(float x);

//Find the closest square number of integer n
int closestSquareNumber(int n);

//This function is used to calculate the percentage of the first road in task 2
double taskTwoStreet1(int exp1);

//This function is used to calculate the percentage of the second road in task 2
double taskTwoStreet2(int &HP1, int &EXP1, int &M1, int E2);

//This function is used to calculate the integer of E2, which is used in road 3
//This function only take the digit < 10 of the number
int sumOfTwoDigitNumber(int n);

//This function is used to return the P3 percentage of the road 3
double taskTwoStreet3(int E2);

//This function is used to check max number of the 4 direction of the given position, which is used in task 3
int checkMaxInTask3(int arr[10][10], int rowsArr, int colsArr);

//This function return the position i, which is the number stand for row, used in task 3
int returnIinArr(int arr[10][10], int E3);

//This function return the position j, which is the number stand for column, used in task 3
int returnJinArr(int arr[10][10], int E3);

//This function is used to calculate the sum of the digits of the number n
//This function is different to the sumOfTwoDigitNumber because it get still + even when the sum is greater than 9
int sumOfDigits(int n);

//return the substring of the email before the @
void returnSe(string &se, string email);

//This function is used to compare the substring of the email with the given password
bool compareSubString(string newS, string se, int &index);

//This function is used to check if the password has more than 2 same character
bool checkMoreThan2SameCharacter(string newS, int &index);

//This function is used to check if the password has special character
bool checkSpecialCharacter(string newS);

//This function is used to check if the password has unwanted character
bool checkUnwantedCharacter(string newS, int &index);

//This function is used to check if the email has more than 1 @
void returnDoubleACircle(string newEmail, int &index);

//This function is used to get the first index of the max number of the array, 
//and if there are more than 1 max number, it will return the first index of the longest password
int getFirstMaxIndex(const char *arr_pwds[], int index[], int num_pwds);

// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3);

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
