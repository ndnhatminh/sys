#include "study_in_pink1.h"

bool readFile(const string &filename, int &HP1, int &HP2, int &EXP1, int &EXP2,
              int &M1, int &M2, int &E1, int &E2, int &E3) {
  // This function is used to read the input file,
  // DO NOT MODIFY THIS FUNTION
  ifstream ifs(filename);
  if (ifs.is_open()) {
    ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
    return true;
  } else {
    cerr << "The file is not found" << endl;
    return false;
  }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//------------------------- START OF UTILITIES FUNCTION
/*
 * Check if the a in the range of [min,max]
 * @param int a
 * @param int min
 * @param int max
 * @return true if a in the range
 */
bool inRange(int a, int min, int max) { return (a >= min && a <= max); }

/*
 * Set the value of HP. Rule: HP in range of [0,666] and has to be ceiled
 * @param int inputHP how many HP we want to set
 * @param int &HP what is the variable contains
 * @return void
 */
void setHP(float inputHP, int &HP) {
  if ((inputHP - 666) > 0)
    HP = 666;
  else if (inputHP < 0)
    HP = 0;
  else
    HP = inputHP + 0.9999;
};

/*
 * Set the value of EXP. Rule: EXP in range of [0,600] and has to be ceiled
 * @param int inputEXP how many EXP we want to set
 * @param int &EXP what is the variable contains
 * @return void
 */
void setEXP(float inputEXP, int &EXP) {
  if ((inputEXP - 600) > 0)
    EXP = 600;
  else if (inputEXP < 0)
    EXP = 0;
  else
    EXP = inputEXP + 0.9999;
};

/*
 * Set the value of Money. Rule: money in range of [0,3000] and has to be ceiled
 * @param int inputM how many money we want to set
 * @param int &M what is the variable contains
 * @return void
 */
void setM(float inputM, int &M) {
  if ((inputM - 3000) > 0)
    M = 3000;
  else if (inputM < 0)
    M = 0;
  else
    M = inputM + 0.9999;
}
//-------------------------------END OF UTILITIES FUNCTION

//******************************* START OF IMPLEMENTING CLASS TASK 1

/*
 * Sync the instance of MissonOne property to the real variable
 * @param currentExp1: the real exp1 that havn't been updated
 * @param currentExp2: the real exp2 that havn't been updated
 * @return void
 */

MissonOne::MissonOne(int &inputExp1, int &inputExp2, int inputE1) {
  setEXP(inputExp1, exp1);
  setEXP(inputExp2, exp2);
  e1 = inputE1;
};
void MissonOne::updateValue(int &currentExp1, int &currentExp2) {
  currentExp1 = exp1;
  currentExp2 = exp2;
}

/*
 * determine if in MissonOne, what is the case
 * @return 1: case one, 2: case two, -99: invalid range of e1
 */
int MissonOne::determineCase() {
  if (inRange(e1, 0, 3))
    return 1;
  else if (inRange(e1, 4, 99))
    return 2;
  else
    return -99;
}

/*
 * Base on e1 range, we determine how many exp we would set to exp2 (Watson)
 * @return void
 */
void MissonOne::handleCase1() {
  switch (e1) {
  case 0:
    setEXP(exp2 + 29, exp2);
    break;
  case 1:
    setEXP(exp2 + 45, exp2);
    break;
  case 2:
    setEXP(exp2 + 75, exp2);
    break;
  case 3:
    setEXP(exp2 + 29 + 45 + 75, exp2);
    break;
    // default:
    //   cerr << "firstMeet error";
  }
  int D = e1 * 3 + exp1 * 7;
  if (D % 2 == 0)
    setEXP(exp1 + (D / 200.0), exp1);
  else
    setEXP(exp1 - (D / 100.0), exp1);
}

/*
 * In case 2, we've got 5 info and exp got set accordingly
 * @return void
 */
void MissonOne::info1() { setEXP(exp2 + e1 / 4.0 + 19, exp2); }
void MissonOne::info2() { setEXP(exp2 + (e1 / 9.0) + 21, exp2); }
void MissonOne::info3() { setEXP(exp2 + e1 / 16.0 + 17, exp2); }
void MissonOne::info4() {
  info1();
  if (exp2 > 200)
    info2();
}
void MissonOne::info5() {
  info1();
  info2();
  if (exp2 > 400) {
    info3();
    setEXP(exp2 * 1.15, exp2);
  }
}

/*
 * Base on e1 range, we call our infox() function
 * @return void
 */
void MissonOne::handleCase2() {
  if (inRange(e1, 4, 19))
    info1();
  else if (inRange(e1, 20, 49))
    info2();
  else if (inRange(e1, 50, 65))
    info3();
  else if (inRange(e1, 66, 79))
    info4();
  else if (inRange(e1, 80, 99))
    info5();

  // Harry is sister so that Sherlock shocked and decrease in exp
  setEXP(exp1 - e1, exp1);
}

//******************************* END OF IMPLEMENT CLASS TASK 1

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
  MissonOne misson1(exp1, exp2, e1);
  int myCase = misson1.determineCase();
  if (myCase == 1) {
    misson1.handleCase1();
  } else if (myCase == 2) {
    misson1.handleCase2();
  } else {
    return -99;
  }

  misson1.updateValue(exp1, exp2);
  return exp1 + exp2;
}

//******************************* START OF IMPLEMENTING CLASS TASK 2

/*
 * @param int a
 * @return find nearest square number of int a
 * */

MissonTwo::MissonTwo(int inputHP1, int inputEXP1, int inputM1, int inputE2) {
  setHP(inputHP1, HP1);
  setEXP(inputEXP1, EXP1);
  setM(inputM1, M1);
  E2 = inputE2;
  p1 = 0;
  p2 = 0;
  p3 = 0;
  expense = 0;
};

int MissonTwo::findNearestSquareNumber(int a) {
  return std::pow(round(sqrt(a)), 2);
}

/*
 * Sync the instance of MissonTwo property to the real variable
 */
void MissonTwo::updateValue(int &currentHP1, int &currentEXP1, int &currentM1) {
  currentHP1 = HP1;
  currentEXP1 = EXP1;
  currentM1 = M1;
}

/*
 * find the p1 after Holmes go through route one
 */
void MissonTwo::routeOne() {
  int S = findNearestSquareNumber(EXP1);
  if (EXP1 >= S)
    p1 = 1;
  else
    p1 = (EXP1 * 1.0f / S + 80) / 123.0;
}

void MissonTwo::routeTwoEvent1() {
  if (HP1 < 200) {
    setHP(HP1 * 1.3, HP1);
    expense += 150;
  } else {
    setHP(HP1 * 1.1, HP1);
    expense += 70;
  }
}

void MissonTwo::routeTwoEvent2() {
  if (EXP1 < 400)
    // by taxi
    expense += 200;
  else
    // by horse
    expense += 120;

  setEXP(EXP1 * 1.13, EXP1);
}

void MissonTwo::routeTwoEvent3() {
  if (EXP1 < 300)
    expense += 100;
  else
    expense += 120;
  setEXP(EXP1 * 0.9, EXP1);
}

void MissonTwo::routeTwo() {
  if (E2 % 2 == 0 && M1 != 0) {
    if (expense < M1) {
      routeTwoEvent1();
    }
    if (expense < M1) {
      routeTwoEvent2();
    }
    if (expense < M1) {
      routeTwoEvent3();
    }
  } else {
    while (M1 != 0 && expense <= (M1 / 2.0)) {
      routeTwoEvent1();
      if ((expense > (M1 / 2.0)))
        break;

      routeTwoEvent2();
      if ((expense > (M1 / 2.0)))
        break;
      routeTwoEvent3();
    }
  }
  setHP(HP1 - 0.17 * HP1, HP1);
  setEXP(EXP1 + 0.17 * EXP1, EXP1);
  setM(M1 - expense, M1);

  int S = findNearestSquareNumber(EXP1);
  if (EXP1 >= S)
    p2 = 1;
  else
    p2 = (EXP1 * 1.0f / S + 80) / 123.0;
}

void MissonTwo::routeThree() {
  if (E2 / 10 == 0) {
    p3 = P[E2] / 100.0;
  } else {
    int sumTwoDigit = (E2 / 10) + (E2 % 10);
    int index = sumTwoDigit % 10;
    p3 = P[index] / 100.0;
  }
}

void MissonTwo::missonLogic() {
  routeOne();
  routeTwo();
  routeThree();
  if (p1 == 1 && p2 == 1 && p3 == 1) {
    setEXP(EXP1 * 0.75, EXP1);
  } else {
    double probability = (p1 + p2 + p3) / 3.0;
    if (probability < 0.5) {
      setHP(HP1 * 0.85, HP1);
      setEXP(EXP1 * 1.15, EXP1);
    } else {
      setHP(HP1 * 0.90, HP1);
      setEXP(EXP1 * 1.20, EXP1);
    }
  }
}

//******************************* END OF IMPLEMENTING CLASS TASK 2

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
  if (inRange(E2, 0, 99)) {
    MissonTwo misson2(HP1, EXP1, M1, E2);
    misson2.missonLogic();
    misson2.updateValue(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
  } else {
    return -99;
  }
}

//******************************* START OF IMPLEMENT CLASS TASK 3

MissonThree::MissonThree(int inputHP1, int inputEXP1, int inputHP2,
                         int inputEXP2, int inputE3) {
  setHP(inputHP1, HP1);
  setEXP(inputEXP1, EXP1);
  setHP(inputHP2, HP2);
  setEXP(inputEXP2, EXP2);
  E3 = inputE3;
  makeMatrix();
  getPosition();
  taxiGrade = matrix[x][y];
  SherlockWatsonGrade = findMaxDiagonal();
};

void MissonThree::updateValue(int &currentHP1, int &currentEXP1,
                              int &currentHP2, int &currentEXP2) {
  currentHP1 = HP1;
  currentEXP1 = EXP1;
  currentHP2 = HP2;
  currentEXP2 = EXP2;
}

/*
 * If a number has 2 digits, then add those two.
 * If the sum has 2 digit then add those 2 again until it has 1 digits and
 * return number.
 */
int MissonThree::reduce(int n) {
  if (n / 10 != 0) {
    n = n % 10 + n / 10;
    return reduce(n);
  } else {
    return n;
  }
}

/*
 * Just count how many element excess the milestone E3*2 and -E3
 * That will be the position of (x,y)
 */
void MissonThree::getPosition() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (matrix[i][j] > (E3 * 2)) {
        x++;
      }
      if (matrix[i][j] < -E3) {
        y++;
      }
    }
  }

  x = reduce(x);
  y = reduce(y);
}

/*
 * Make the matrix arcording to the formula
 */
void MissonThree::makeMatrix() {
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }
  }
}

/*
 * Find the max value in the left diagonal.
 * First get down from current to the lower left corner
 * Then, back to original position, get up to upper right corner
 */
int MissonThree::findMaxLeftDiagonal() {
  int max = matrix[x][y];
  for (int i = x, j = y; (i <= 9 && j >= 0); i++, j--) {
    max = std::max(max, matrix[i][j]);
  }
  for (int i = x, j = y; (j <= 9 && i >= 0); i--, j++) {
    max = std::max(max, matrix[i][j]);
  }
  return max;
}

/*
 * Find the max value in the right diagonal.
 * First get down from current to the lower right corner
 * Then, back to original position, get up to upper left corner
 */
int MissonThree::findMaxRightDiagonal() {
  int max = matrix[x][y];
  for (int i = x, j = y; (i <= 9 && j <= 9); i++, j++) {
    max = std::max(max, matrix[i][j]);
  }
  for (int i = x, j = y; (j >= 0 && i >= 0); i--, j--) {
    max = std::max(max, matrix[i][j]);
  }
  return max;
}

/*
 * Compare 2 left right max
 */
unsigned int MissonThree::findMaxDiagonal() {
  int maxLeft = findMaxLeftDiagonal();
  int maxRight = findMaxRightDiagonal();
  return abs(max(maxLeft, maxRight));
}

void MissonThree::missionLogic() {
  if (abs(taxiGrade) > SherlockWatsonGrade) {
    setEXP(EXP1 - 0.12 * EXP1, EXP1);
    setHP(HP1 - 0.1 * HP1, HP1);

    setEXP(EXP2 - 0.12 * EXP2, EXP2);
    setHP(HP2 - 0.1 * HP2, HP2);
  } else {
    setEXP(EXP1 + 0.12 * EXP1, EXP1);
    setHP(HP1 + 0.1 * HP1, HP1);

    setEXP(EXP2 + 0.12 * EXP2, EXP2);
    setHP(HP2 + 0.1 * HP2, HP2);
  }
}

//******************************* END OF IMPLEMENT CLASS TASK 3

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {

  if (inRange(E3, 0, 99)) {
    MissonThree misson3(HP1, EXP1, HP2, EXP2, E3);
    misson3.missionLogic();
    misson3.updateValue(HP1, EXP1, HP2, EXP2);
    // Return the absolute value grade which is bigger
    return (abs(misson3.taxiGrade) > abs(misson3.SherlockWatsonGrade))
               ? misson3.taxiGrade
               : misson3.SherlockWatsonGrade;

  } else
    return -99;
}

//******************************* START OF IMPLEMENTING CLASS TASK 4
MissonFour::MissonFour(const char *paramS, const char *paramEmail) {
  s = paramS;
  s_len = s.length();
  email = paramEmail;
  se = email.substr(0, email.find('@'));
}

bool MissonFour::containValidCharacter(char letter) {
  int letterAscii = (int)letter;
  if (!inRange(letterAscii, numberAscii[0], numberAscii[1]) &&
      !inRange(letterAscii, upperCaseAscii[0], upperCaseAscii[1]) &&
      !inRange(letterAscii, lowerCaseAscii[0], lowerCaseAscii[1]) &&
      !containSpeicalCharacter(letter))
    return false;
  return true;
}

bool MissonFour::containSpeicalCharacter(char letter) {
  if ((int)letter == specialCharacters[0] ||
      (int)letter == specialCharacters[1] ||
      (int)letter == specialCharacters[2] ||
      (int)letter == specialCharacters[3] ||
      (int)letter == specialCharacters[4])
    return true;
  return false;
}

int MissonFour::missonLogic() {
  // s is too short
  if (s_len < 8)
    return -1;
  // s is too long
  else if (s_len > 20)
    return -2;
  // s contains se
  if (s.find(se) != string::npos)
    return -(300 + s.find(se));

  // There are 3 (or more) same character in a row
  for (int i = 0; i < s_len - 2; i++) {
    if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
      return -(400 + i);
    }
  }

  bool isContainSpecialChar = false;
  bool invalidCharacter = false;

  int invalidIndex = 0;
  for (int i = 0; i < s_len; i++) {
    if (!isContainSpecialChar && containSpeicalCharacter(s[i])) {
      isContainSpecialChar = true;
    }

    if (!invalidCharacter && !containValidCharacter(s[i])) {
      invalidCharacter = true;
      invalidIndex = i;
    }
  }

  if (!isContainSpecialChar)
    return -5;
  if (invalidCharacter)
    return invalidIndex;

  return -10;
}
//******************************* END OF IMPLEMENTING CLASS TASK 4

// Task 4
int checkPassword(const char *s, const char *email) {
  MissonFour misson4(s, email);
  return misson4.missonLogic();
}

MissonFive::MissonFive(int intNumpwds) : num_pwds(intNumpwds){};

int MissonFive::missonLogic(const char *arr_pwds[]) {
  // Make an array to store appear time
  int *appearTimes = new int[num_pwds]();

  // count the appear time of a password from its position to end off array
  for (int i = 0; i < num_pwds; i++)
    for (int j = i; j < num_pwds; j++)
      if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
        appearTimes[i]++;

  // Find the password appear the most (if tie then the one longer)
  int index = 0;
  for (int i = 1; i < num_pwds; i++) {
    if (appearTimes[i] > appearTimes[index])
      index = i;
    else if (appearTimes[i] == appearTimes[index])
      if (strlen(arr_pwds[i]) > strlen(arr_pwds[index]))
        index = i;
  }
  delete[] appearTimes;

  return index;
}
//******************************* END OF IMPLEMENTING CLASS TASK 5

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
  MissonFive misson5(num_pwds);
  return misson5.missonLogic(arr_pwds);
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
/////////////////////////////////////////////////
