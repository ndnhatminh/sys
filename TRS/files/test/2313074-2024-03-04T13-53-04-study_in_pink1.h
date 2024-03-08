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

//check đầu vào
    inline void handleHP(int & HP1, int & HP2){
        HP1= (HP1 >666) ? 666 : (HP1<0) ? 0 :HP1;
        HP2= (HP2 >666) ? 666 : (HP2<0) ? 0 :HP2;
    }
    inline void handleHP_case(int & d){
        d= (d >666) ? 666 : (d<0) ? 0 :d;
    }
    inline void handleEXP(int & EXP1, int & EXP2){
        EXP1= (EXP1 >600) ? 600 : (EXP1<0) ? 0 :EXP1;
        EXP2= (EXP2 >600) ? 600 : (EXP2<0) ? 0 :EXP2;
    }
    inline void handleEXP_case(int & c){
        c= (c >600) ? 600 : (c<0) ? 0 :c;
    }
    inline void handleMoney(int & M1, int & M2 ){
        M1= (M1 >3000) ? 3000 : (M1<0) ? 0 :M1;
        M2= (M2 >3000) ? 3000 : (M2<0) ? 0 :M2;
    }
    inline void handleMoney_case(int & b){
        b= (b >3000) ? 3000 : (b<0) ? 0 :b;
    }
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
