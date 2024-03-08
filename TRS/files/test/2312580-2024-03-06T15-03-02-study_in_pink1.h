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



void event_1(int & HP1, int & M1);
//     if(HP1 < 200) {
//     HP1 = ceil(HP1*1.3);
//     M1 -= 150;
//     } else {
//     HP1 = ceil(HP1*1.1);
//     M1 -= 70;
//     }
// }

void event_2(int & EXP1, int & M1);
//     if(EXP1 < 400) M1 -= 200;
//     else M1 -= 120;
//     EXP1 = ceil(EXP1*1.13);
// }

void event_3(int & EXP1, int & M1);
//     if(EXP1 < 300) M1 -= 100;
//     else M1 -= 120;
//     EXP1 = ceil(EXP1*0.9);
// }

bool isOverSpent(int & spentM1, int startM1, int &M1, int E2);
//     if(E2%2 != 0) {
//         spentM1 = startM1 - M1;
//         if(spentM1 > 0.5*M1) return false;
//         else return true;
//     } else {
//         if (M1 <= 0) {
//             M1 = 0;
//             return false;
//         } else return true;
//     }
// }

int getSherlockScore(int i, int j, int (&map)[10][10]);


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
