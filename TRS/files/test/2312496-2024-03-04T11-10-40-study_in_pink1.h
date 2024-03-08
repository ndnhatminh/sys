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
class TASK1{
private:
    int EXP1, EXP2, E1;
    void situation1();
    void situation2();
    void situation3();
    int case1_EXP1();
public:
    TASK1(int inputEXP1, int inputEXP2, int inputE1) 
    : EXP1{inputEXP1}, EXP2{inputEXP2}, E1{inputE1} {};


    void case1();
    void case2();
    void setValue(int &inputEX1, int &inputEXP2);
};

class TASK2{
private:
    int HP1, EXP1, M1, E2;
    int count();
    // bool isPerfectSquare(int a);
    // int biggerS();
    // int smallerS();
    int findSquare();
    double Find_P();
    double First_Way();
    void Second_Way_case1();
    void Second_Way_case2();
    double Second_Way();
    double Third_Way();
public:
    TASK2(int inputHP1, int inputEXP1, int inputM1, int inputE2) 
    : HP1{inputHP1}, EXP1{inputEXP1}, M1{inputM1}, E2{inputE2} {};

    void Result();
    void setValue(int &inputHP1, int &inputEXP1, int &inputM1);


};

class TASK3{
private:
    int HP1, EXP1, HP2, EXP2, E3;
    int mt[10][10];
    int Pos_i_Taxi();
    int Pos_j_Taxi();
    int TaxiPoint();
    int MaxPoint();

public:
    TASK3(int inputHP1, int inputEXP1, int inputHP2, int inputEXP2,int inputE3){ 
    HP1 = inputHP1; EXP1=inputEXP1; HP2 = inputHP2; EXP2 = inputEXP2; E3 = inputE3;
    for (int i=0; i<10; i++){
        for (int j=0;j<10;j++){
            mt[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    };
    void Result();
    int Compare();
    void SetValue(int &inputHP1, int &inputEXP1, int &inputHP2, int &inputEXP2,int &inputE3);
};



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
