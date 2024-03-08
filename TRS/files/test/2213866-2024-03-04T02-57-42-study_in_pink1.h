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
//Define value of index
void limitexp(int &exp1);
 void limitHP(int &hp1);
 void limitM(int &m1);
 
// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
double probaty(int exp1);
void way2_odd(int& exp1, int& hp1, int& m1, int mch);
void way2_even(int& exp1, int& hp1, int& m1);
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3);

// Task 3
void swap(int &a, int &b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void sortArray(int arr[], int size);
int max(int a, int b);
// chuyển số hàng chục thành đơn vị
int simpnum(int x);
// Lower Bound
int lower_bound(const int arr[100], int target);
// Upper Bound
int upper_bound(const int arr[100], int target);
 // make value off Sherlock ad Watso whe meet The Killer Taxi 
int valueOfSherlock(int* arr, int x, int y);
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
char* makese(string email, char* se);
bool checkSpecsign(char s);
bool checksign(const char* s);
bool checkSamesign(const char* s);
bool checkValid(const char* s,const char* se);
int checkPassword(const char * s, const char * email);

// Task 5
bool checkStringsame(string s, string ds[], int count, int& ind);
int indexMax(int arr[],int count);
int findIndstring(string s[], string max, int num_pwds);
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
