/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2023
 * Author: Vu Van Tien
 * Date: 02.02.2023
 */

// The library here is concretely set, students are not allowed to include any
// other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile(const string &filename, int &HP1, int &HP2, int &EXP1, int &EXP2,
              int &M1, int &M2, int &E1, int &E2, int &E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// defining setter
bool inRange(int a, int min, int max);

void setHP(float inputHP, int &HP);
void setEXP(float inputEXP, int &EXP);
void setM(float inputM, int &M);

// Task 1
class MissonOne {
private:
  int exp1;
  int exp2;
  int e1;

public:
  MissonOne(int &inputExp1, int &inputExp2, int inputE1);

  void updateValue(int &currentExp1, int &currentExp2);

  int determineCase();
  void handleCase1();

  void info1();
  void info2();
  void info3();
  void info4();
  void info5();
  void handleCase2();
};
int firstMeet(int &exp1, int &exp2, int e1);

// Task 2
class MissonTwo {
private:
  double p1, p2, p3;
  int HP1, EXP1, M1, E2;
  double expense;
  const int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

  int findNearestSquareNumber(int a);
  void routeOne();

  void routeTwo();
  void routeTwoEvent1();
  void routeTwoEvent2();
  void routeTwoEvent3();

  void routeThree();

public:
  MissonTwo(int inputHP1, int inputEXP1, int inputM1, int inputE2);
  void updateValue(int &currentHP1, int &currentEXP1, int &currentM1);
  void missonLogic();
};
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2);

// Task 3
class MissonThree {
private:
  int HP1, EXP1, HP2, EXP2, E3;
  int x = 0, y = 0;
  int matrix[10][10] = {0};

  int reduce(int n);
  void getPosition();

  void makeMatrix();

  int findMaxLeftDiagonal();
  int findMaxRightDiagonal();

public:
  int taxiGrade = 0;
  int SherlockWatsonGrade = 0;
  MissonThree(int inputHP1, int inputEXP1, int inputHP2, int inputEXP2,
              int inputE3);

  void updateValue(int &currentHP1, int &currentEXP1, int &currentHP2,
                   int &currentEXP2);

  unsigned int findMaxDiagonal();

  void missionLogic();
};
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3);

// Task 4
class MissonFour {
private:
  const int specialCharacters[5] = {64, 35, 37, 36, 33};
  const int numberAscii[2] = {48, 57};
  const int lowerCaseAscii[2] = {97, 122};
  const int upperCaseAscii[2] = {65, 90};

  string s;
  int s_len;
  string email;
  string se;

  bool containValidCharacter(char letter);
  bool containSpeicalCharacter(char letter);

public:
  MissonFour(const char *paramS, const char *paramEmail);
  int missonLogic();
};
int checkPassword(const char *s, const char *email);

// Task 5
//

class MissonFive {
private:
  int num_pwds;

public:
  MissonFive(int inputNumPwds);
  int missonLogic(const char *inputArr[]);
};
int findCorrectPassword(const char *arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
