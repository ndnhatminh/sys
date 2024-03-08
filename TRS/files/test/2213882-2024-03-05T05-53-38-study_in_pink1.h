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

int updateHP(int, int);
int updateEXP(int, int);
int updateMon(int, int);

/// TASK 2
float FindP     (int );
float P_in_road2(int&, int&, int&, int);
float P_in_road3(int);
/// end TASK 2


/// TASK 3
int FindMax_in_Diagonal(int arr[][10], int, int);
/// end TASK 3


/// TASK 4   
string find_Se_inEmail(const char*);
bool check_char(char, bool &);
/// end TASK 4


//// TASK 5
struct Pass{
    const char * Pass;
    int count, index_first;
    
    bool cmpPass(const char * str)
    {
        if(strcmp(Pass, str)!=0)
            return 0;
        count ++;
        return 1; 
    }

    int size_Pass() {
        return (int) strlen(Pass);
    }
};
//// END TASK 5


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
