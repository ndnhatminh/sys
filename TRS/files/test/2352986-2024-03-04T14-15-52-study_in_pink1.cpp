#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
void checkHP1(int & HP1) {
    if (HP1 < 0){
        HP1 = 0;
    }

    if (HP1 > 666){
        HP1 = 666;
    }
}
void checkHP2(int & HP2) {   
    if (HP2 < 0){
        HP2 = 0;
    }
    
    if (HP2 > 666){
        HP2 = 666;
    }
}
void checkEXP1(int & EXP1) {
    if (EXP1 < 0){
        EXP1 = 0;
    }

    if (EXP1 > 600){
        EXP1 = 600;
    }
}
void checkEXP2(int & EXP2) {
    if (EXP2 < 0){
        EXP2 = 0;
    }

    if (EXP2 > 600){
        EXP2 = 600;
    }
}
void checkM1(int & M1) {
    if (M1 < 0){
        M1 = 0;
    }

    if (M1 > 3000){
        M1 = 3000;
    }
}
void checkM2(int & M2) {
    if (M2 < 0){
        M2 = 0;
    }

    if (M2 > 3000){
        M2 = 3000;
    }
}
int squareNum(int x) {
    double squareRoot = sqrt(x);
    int roundedSquareRoot = round(squareRoot);
    int nearestSquare = roundedSquareRoot * roundedSquareRoot;
    return nearestSquare;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    //Check
    if ((e1 < 0) || (e1 > 99))
    {
        return -99;
    }
    checkEXP1(exp1);
    checkEXP2(exp2);
    //Case 1
    if (e1 <= 3) {
        if (e1 == 0) exp2 = exp2 + 29;
        if (e1 == 1) exp2 = exp2 + 45;
        if (e1 == 2) exp2 = exp2 + 75;
        if (e1 == 3) exp2 = exp2 + 149;
        int d = 0;
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0){
            exp1 = ceil(exp1 + (d/200.0)); 
        } else exp1 = ceil(exp1 - (d/100.0));
        checkEXP1(exp1);
        checkEXP2(exp2);
        return exp1 + exp2;
    }  
    //Case 2
    if (e1 <= 19){
        exp2 = ceil(exp2 + (e1/4.0 + 19));
        exp1 = exp1 - e1;
        checkEXP1(exp1);
        checkEXP2(exp2);
        return exp1 + exp2;
    }

    if (e1 <= 49){
        exp2 = ceil(exp2 + (e1/9.0 + 21));
        exp1 = exp1 - e1;
        checkEXP1(exp1);
        checkEXP2(exp2);
        return exp1 + exp2;
    }

    if (e1 <= 65){
        exp2 = ceil(exp2 + (e1/16.0 + 17));
        exp1 = exp1 - e1;
        checkEXP1(exp1);
        checkEXP2(exp2);
        return exp1 + exp2;
    }

    if (e1 <= 79){
        exp2 = ceil(exp2 + (e1/4.0 + 19));
        if (exp2 > 200)
        {
            exp2 = ceil(exp2 + (e1/9.0 + 21));
        }
        exp1 = exp1 - e1;
        checkEXP1(exp1);
        checkEXP2(exp2);
        return exp1 + exp2;
    }

    if (e1 <= 99){
        exp2 = ceil(exp2 + (e1/4.0 + 19));
        checkEXP2(exp2);
        exp2 = ceil(exp2 + (e1/9.0 + 21));
        checkEXP2(exp2);
        if (exp2 > 400)
        {
            exp2 = ceil(exp2 + (e1/16.0 + 17));
            exp2 = ceil(exp2 * 1.15);
        }
        exp1 = exp1 - e1;
        checkEXP1(exp1);
        checkEXP2(exp2);
        return exp1 + exp2;
    }
    return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //Check
    if ((E2 < 0) || (E2 > 99))
    {
        return -99;
    }
    checkEXP1(EXP1);
    checkHP1(HP1);
    checkM1(M1);

    double P1 = 0, P2 = 0, P3 = 0, PAvg = 0;

    //Road 1
    if (EXP1 >= squareNum(EXP1))
    {
        P1 = 100.0;
    } else {
        P1 = 100*((((float)EXP1/squareNum(EXP1)*1.0) + 80)/123.0);
    }

    //Road 2
    // E2 even
    if (E2 % 2 == 0) {

        for (int i = 0; i < 1; i++) {
            if (M1 == 0) break;
            //Event 1
            if (HP1 < 200)  {
                HP1 = ceil(HP1 + 0.30*HP1);
                checkHP1(HP1);
                M1 = M1 - 150;
                checkM1(M1);
                if (M1 == 0) break;
            } else {
                HP1 = ceil(HP1 + 0.10*HP1);
                checkHP1(HP1);
                M1 = M1 - 70;
                checkM1(M1);
                if (M1 == 0) break;
            }

            //Event 2
            if (EXP1 < 400)  {
                M1 = M1 - 200;
                checkM1(M1);
                EXP1 = ceil(EXP1 + 0.130*EXP1);
                if (M1 == 0) break;
            } else {
                M1 = M1 - 120;
                checkM1(M1);
                EXP1 = ceil(EXP1 + 0.130*EXP1);
                if (M1 == 0) break;
            }

            //Event 3
            if (EXP1 < 300)  {
                M1 = M1 - 100;
                checkM1(M1);
                EXP1 = ceil(EXP1 - 0.10*EXP1);
                if (M1 == 0) break;
            } else {
                M1 = M1 - 120;
                checkM1(M1);
                EXP1 = ceil(EXP1 - 0.10*EXP1);
                if (M1 == 0) break;
            }
        }
    }

    //E2 odd
        int M0 = M1;
        int MPaid = 0;
        while (E2 % 2 != 0) {
            if (M1 == 0) break;
            //Event 1
            if (HP1 < 200)  {
                HP1 = ceil(HP1 + 0.30*HP1);
                checkHP1(HP1);
                M1 = M1 - 150;
                MPaid += 150;
                checkM1(M1);
                if (MPaid > 0.50*M0) break;
            } else {
                HP1 = ceil(HP1 + 0.10*HP1);
                checkHP1(HP1);
                M1 = M1 - 70;
                MPaid += 70;
                checkM1(M1);
                if (MPaid > 0.50*M0) break;
            }
            //Event 2
            if (EXP1 < 400)  {
                M1 = M1 - 200;
                MPaid += 200;
                checkM1(M1);
                EXP1 = ceil(EXP1 + 0.130*EXP1);
                if (MPaid > 0.50*M0) break;
            } else {
                M1 = M1 - 120;
                MPaid += 120;
                checkM1(M1);
                EXP1 = ceil(EXP1 + 0.130*EXP1);
                if (MPaid > 0.50*M0) break;
            }
            //Event 3
            if (EXP1 < 300)  {
                M1 = M1 - 100;
                MPaid += 100;
                checkM1(M1);
                EXP1 = ceil(EXP1 - 0.10*EXP1);
                if (MPaid > 0.50*M0) break;
            } else {
                M1 = M1 - 120;
                MPaid += 120;
                checkM1(M1);
                EXP1 = ceil(EXP1 - 0.10*EXP1);
                if (MPaid > 0.50*M0) break;
            }
        }

    HP1 = ceil(HP1 - 0.170*HP1);
    checkHP1(HP1);
    EXP1 = ceil(EXP1 + 0.170*EXP1);
    checkEXP1(EXP1);


    if (EXP1 >= squareNum(EXP1))
    {
        P2 = 100.0;
    } else {
        P2 = 100*((((float)EXP1/squareNum(EXP1)*1.0) + 80)/123.0);
    }

    //Road 3
    int P[10] = {32,47,28,79,100,50,22,83,64,11};
    //i
    int i = 0;
    if (E2 >= 10)
    {
        int sum = (E2 / 10) + (E2 % 10);
        i = sum % 10;
    } else {
        i = E2;
    }
    //P3
    P3 = P[i];


    if ((P1 == 100) && (P2 == 100) && (P3 == 100))
    {
        EXP1 = ceil(EXP1 - 0.250*EXP1);
        checkEXP1(EXP1);
    } else {
        PAvg = (P1 + P2 + P3)/3.0;
        if (PAvg < 50)
        {
            HP1 = ceil(HP1 - 0.150*HP1);
            checkHP1(HP1);
            EXP1 = ceil(EXP1 + 0.150*EXP1);
            checkEXP1(EXP1);
        } else {
            HP1 = ceil(HP1 - 0.10*HP1);
            checkHP1(HP1);
            EXP1 = ceil(EXP1 + 0.20*EXP1);
            checkEXP1(EXP1);
        }
    }


    checkHP1(HP1);
    checkEXP1(EXP1);
    checkM1(M1);

    return HP1 + EXP1 + M1;
}

int sumDigits(int n) {
    int sum = 0;
    // sum
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
// Task 3
int LeftDiagonalMax(int a[10][10], int i, int j) {
    int score = INT_MIN;

    int i1 = i;
    int j1 = j;

    int i2 = i;
    int j2 = j;

    //Case 1
    if ((i1 == 9 && j1 == 0) || (i1 == 0 && j1 == 9))
    {
        score = a[i1][j1];
        return score;
    }
    
    //Case 2
    if (i1 == 0 || j1 == 0)
    {
        score = a[i1][j1];
        for (int q = 0; q < 10; q++)
        {
            if (a[i1][j1] <= a[i1 + 1][j1 + 1])
            {
                score = a[i1+1][j1+1];
            }
            i1++;
            j1++;
            if (i1 == 9 || j1 == 9)
            {
                break;
            }
        }
        return score;
    }
    
    //Case 3
    if (i1 == 9 || j1 == 9)
    {
        score = a[i1][j1];
        for (int q = 0; q < 10; q++)
        {
            if (a[i1][j1] <= a[i1 - 1][j1 - 1])
            {
                score = a[i1-1][j1-1];
            }
            i1--;
            j1--;
            if (i1 == 0 || j1 == 0)
            {
                break;
            }
        }
        return score;
    }
    
    //Case 4
    if (i1 != 0 && i1 != 9 && j1 != 0 && j1 != 9)
    {
        score = a[i1][j1];

        for (int q = 0; q < 10; q++)
        {
            if (a[i1][j1] <= a[i1 - 1][j1 - 1])
            {
                score = a[i1-1][j1-1];
            }
            i1--;
            j1--;
            if (i1 == 0 || j1 == 0)
            {
                break;
            }
        }

        for (int q = 0; q < 10; q++)
        {
            if (score <= a[i2 + 1][j2 + 1])
            {
                score = a[i2 + 1][j2 + 1];
            }
            i2++;
            j2++;
            if (i2 == 9 || j2 == 9)
            {
                break;
            }
        }
        return score;
    }
    return -99;        
}

int RightDiagonalMax(int a[10][10], int i, int j) {
    int score = INT32_MIN;

    int i1 = i;
    int j1 = j;

    int i2 = i;
    int j2 = j;

    //Case 1
    if ((i1 == 0 && j1 == 0) || (i1 == 9 && j1 == 9))
    {
        score = a[i1][j1];
        return score;
    }
    
    //Case 2
    if (i1 == 0 || j1 == 9)
    {
        score = a[i1][j1];
        for (int q = 0; q < 10; q++)
        {
            if (a[i1][j1] <= a[i1 + 1][j1 - 1])
            {
                score = a[i1+1][j1-1];
            }
            i1++;
            j1--;
            if (i1 == 9 || j1 == 0)
            {
                break;
            }
        }
        return score;
    }
    
    //Case 3
    if (i1 == 9 || j1 == 0)
    {
        score = a[i1][j1];
        for (int q = 0; q < 10; q++)
        {
            if (a[i1][j1] <= a[i1 - 1][j1 + 1])
            {
                score = a[i1-1][j1+1];
            }
            i1--;
            j1++;
            if (i1 == 0 || j1 == 9)
            {
                break;
            }
        }
        return score;
    }
    
    //Case 4
    if (i1 != 0 && i1 != 9 && j1 != 0 && j1 != 9)
    {
        score = a[i1][j1];

        for (int q = 0; q < 10; q++)
        {
            if (a[i1][j1] <= a[i1 - 1][j1 + 1])
            {
                score = a[i1-1][j1+1];
            }
            i1--;
            j1++;
            if (i1 == 0 || j1 == 9)
            {
                break;
            }
        }

        for (int q = 0; q < 10; q++)
        {
            if (score <= a[i2 + 1][j2 - 1])
            {
                score = a[i2 + 1][j2 - 1];
            }
            i2++;
            j2--;
            if (i2 == 9 || j2 == 0)
            {
                break;
            }
        }
        return score;
    }
    return -99;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //Check
    if ((E3 < 0) || (E3 > 99))
    {
        return -99;
    }
    checkHP1(HP1);
    checkEXP1(EXP1);
    checkHP2(HP2);
    checkEXP2(EXP2);
    
    int a[10][10] = {};
    int b[10][10] = {};
    int iindex = 0, jindex = 0;

    for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = ((E3 * j) + (i * 2))*(i - j);
            if (a[i][j] > (E3 * 2)) {
                iindex++;
            }
            if (a[i][j] < (E3 * -1)) {
                jindex++;
            }
		}
	}

    while (iindex >= 10) {
        iindex = sumDigits(iindex);
    }
    while (jindex >= 10) {
        jindex = sumDigits(jindex);
    }

    for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
            int LeftDiagonalScore = LeftDiagonalMax(a, i, j);
            int RightDiagonalScore = RightDiagonalMax(a, i, j);
            b[i][j] = abs(max(LeftDiagonalScore, RightDiagonalScore));
		}
	}

    if (abs(a[iindex][jindex]) > b[iindex][jindex]) {
        EXP1 = ceil(EXP1 - 0.12*EXP1);
        checkEXP1(EXP1);
        EXP2 = ceil(EXP2 - 0.12*EXP2);
        checkEXP2(EXP2);
        HP1 = ceil(HP1 - 0.1*HP1);
        checkHP1(HP1);
        HP2 = ceil(HP2 - 0.1*HP2);
        checkHP2(HP2);

        return a[iindex][jindex];
    } else {
        EXP1 = ceil(EXP1 + 0.12*EXP1);
        checkEXP1(EXP1);
        EXP2 = ceil(EXP2 + 0.12*EXP2);
        checkEXP2(EXP2);
        HP1 = ceil(HP1 + 0.1*HP1);
        checkHP1(HP1);
        HP2 = ceil(HP2 + 0.1*HP2);
        checkHP2(HP2);

        return b[iindex][jindex];
    }
}

// Task 4
bool isValidCharacterCheck(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!';
}

bool containsValidCharacter(const char* password) {
    for (int i = 0; i < strlen(password); ++i) {
        if (!isValidCharacterCheck(password[i])) {
            return false;
        }
    }
    return true;
}

int containsValidCharacter1(const char* password) {
    for (int i = 0; i < strlen(password); ++i) {
        if (!isValidCharacterCheck(password[i])) {
            return i;
        }
    }
    return 0;
}

bool isSpecialCharacterCheck(char ch) {
    return (ch == '@' )|| (ch == '#') || (ch == '%') || (ch == '$') || (ch == '!');
}

bool containsSpecialCharacter(const char* password) {
    for (int i = 0; i < strlen(password); ++i) {
        if (isSpecialCharacterCheck(password[i])) {
            return true;
        }
    }
    return false;
}

bool containsForbiddenSequence(const char* password, int& position,const char* se) {
    const char* forbiddenSequence = se;
    const char* result = strstr(password, forbiddenSequence);
    if (result != nullptr) {
        position = result - password;
        return true;
    }
    return false;
}

bool hasConsecutiveRepeatingCharacters(const char* password, int& position) {
    int consecutiveCount = 1;
    for (int i = 1; i < strlen(password); ++i) {
        if (password[i] == password[i - 1]) {
            consecutiveCount++;
            if (consecutiveCount > 2) {
                position = i - consecutiveCount + 1;
                return true;
            }
        } else {
            consecutiveCount = 1;
        }
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    int length = strlen(s);
    
    

    //event 2
    if (length < 8) {
        return -1; 
    }

    //event 3
    if (length > 20) {
        return -2; 
    }


    //event 4
    std::string k = email;
    size_t atSymbolPos = k.find('@');

    std::string se = k.substr(0, atSymbolPos);
    // const char * c = se.c_str();

    std::string mainString = s;
    std::string searchString = se;
    int forbiddenSeqPosition = mainString.find(searchString);


    if (containsForbiddenSequence(s, forbiddenSeqPosition, se.c_str())) {
        return -(300 + forbiddenSeqPosition); // Password contains forbidden sequence
    }

    //event 5
    int consecutivePosition;
    for (int i = 0; i < mainString.length() - 2; ++i) {
        if (mainString[i] == mainString[i + 1] && mainString[i] == mainString[i + 2]) {
            i = consecutivePosition;
            break;
        }
    }

    if (hasConsecutiveRepeatingCharacters(s, consecutivePosition)) {
        return -(400 + consecutivePosition); // Password contains consecutive repeating characters
    }

    //event 6
    if (!containsSpecialCharacter(s)) {
        return -5; 
    }

    //event 1
    if ((length>=8 && length<=20) && containsValidCharacter(s) && !(containsForbiddenSequence(s, forbiddenSeqPosition, se.c_str())) && !(hasConsecutiveRepeatingCharacters(s, consecutivePosition)) && containsSpecialCharacter(s))
    {
        return -10;
    }

    if (!containsValidCharacter(s))
    {
        return containsValidCharacter1(s);
    }

    return 0;
}
// Task 5
bool isStringSeen(const std::string& str, const std::string seen_strings[], int size) {
    for (int i = 0; i < size; ++i) {
        if (str == seen_strings[i]) {
            return true;
        }
    }
    return false;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {

  //Different passwords
  string diff_pwds[30] = {};
  int seen_count = 0;

  for (int i = 0; i < num_pwds; ++i) {
      if (!isStringSeen(arr_pwds[i], diff_pwds, seen_count)) {
          diff_pwds[seen_count++] = arr_pwds[i];
      }
  }

  int count_pwds[seen_count];
  int length_pwds[seen_count];
  int position_pwds[seen_count];

  for (int i = 0; i < seen_count; i++)
  {   
      int count = 0;
      for (int q = 0; q < num_pwds; q++)
      {
          if (diff_pwds[i] == arr_pwds[q])
          {
              count++;
          }
      }
      count_pwds[i] = count;
  }

  for (int i = 0; i < seen_count; i++)
  {
    length_pwds[i] = diff_pwds[i].length();
  }

  for (int i = 0; i < seen_count; i++)
  {
    for (int q = 0; q < num_pwds; q++)
    {
      if (diff_pwds[i] == arr_pwds[q])
      {
        position_pwds[i] = q;
        break;
      }
    }
  }

  int max_appearance = 0;
  for (int i = 0; i < seen_count; i++)
  {
    if (max_appearance <= count_pwds[i])
    {
      max_appearance = count_pwds[i];
    }
  }

  int max_count = 0;

  for (int i = 0; i < seen_count; i++)
  {
    if (max_appearance == count_pwds[i])
    {
      max_count++;
    }
  }

  if (max_count == 1) {
    int result = 0;
    for (int i = 0; i < seen_count; i++)
    {
      if (max_appearance == count_pwds[i])
      {
        result = position_pwds[i];
        break;
      }
    }
    return result;
  }

  int a[max_count];
  int b[max_count];
  int index = 0;
  for (int q = 0; q < max_count; q++)
  {
    for (int i = index; i < seen_count; i++)
    {
      if (count_pwds[i] == max_appearance)
      {
        a[q] = length_pwds[i];
        b[q] = position_pwds[i];
        index = i+1;
        break;
      }
    }
  }

  int maxNumber = a[0];
  int maxIndex = 0;

  for (int i = 1; i < max_count; ++i) {
      if (a[i] > maxNumber) {
          maxNumber = a[i];
          maxIndex = i;
      }
  }
  return b[maxIndex];
  
  return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////