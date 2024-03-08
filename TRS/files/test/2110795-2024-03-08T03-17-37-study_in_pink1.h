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

// CONSTS
const int HP_MIN = 0;
const int HP_MAX = 666;
const int EXP_MIN = 0;
const int EXP_MAX = 600;
const int M_MIN = 0;
const int M_MAX = 3000;

const int ROWS = 10;
const int COLS = 10;
// HELPERS TASK 1
double customCeil(double value, double precision);
// HELPERS TASK 2
int closestSquare(int n);
void path_2_events_loop(int & HP1, int & EXP1, int & M1, int halfM1, int & moneySpent);
void path_2_events(int & HP1, int & EXP1, int & M1);
int calculate_i(int E2, int P3_array[]);
// HELPERS TASK 3
int maxDiagonalValue(int chaseMap[ROWS][COLS], int i, int j);
int findValue_i(int chaseMap[ROWS][COLS], int E3);
int findValue_j(int chaseMap[ROWS][COLS], int E3);
// HELPERS TASK 4
string get_se(const char* email);
int find_sei(const char* s, const char* se);
int find_sci(const char* s);
int check_chars(const char* s);
bool has_special_chars(const char* s);


//!           _.-/`)
//!          // / / )
//!       .-// / / / )
//!      //`/ / / / / )
//!     // /       ` /
//!    ||           /
//!     \\         /
//!      ))      .`
//!     //      /
//!    //      /
//!  OM MANI PADME HUM

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
