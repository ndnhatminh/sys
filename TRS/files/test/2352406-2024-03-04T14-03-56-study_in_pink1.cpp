#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
int firstMeet(int & exp1, int & exp2, int e1){
if (e1< 0 || e1 > 99) return -99; 
if (e1==0)
	{
		exp2+=29;
	}
	if (e1==1)
	{
		exp2+=45;
	}
	if (e1==2)
	{
		exp2+=75;
	}
	if (e1==3)
	{
		exp2+=149;
	}
	int D=ceil((e1*3)+(exp1*7));
	if (D%2==0 && e1>=0 && e1<=3)
	{
		exp1=ceil(exp1+D/200);
	}
	else if (D%2!=0 && e1>=0 && e1<=3)
	{
		exp1=ceil(exp1-D/100);
	}
    if (e1 > 3 && e1 < 100)
    {
        exp1-=e1;
    }
	if (e1>=4 && e1<=19)
	{
		exp2+=ceil((e1*1.00)/4+19);
	}
	if (e1>=20 && e1<=49)
	{
		exp2+=ceil((e1*1.00)/9+21);
	}
	if (e1>=50 && e1<=65)
	{
		exp2+=ceil((e1*1.00)/16+17);
	}
	if (e1>=66 && e1<=79)
	{
		exp2+=ceil((e1*1.00)/4+19);
		if (exp2>200)
		{
			exp2+=ceil((e1*1.00)/9+21);
		}
	}
	if (e1>=80 && e1<=99)
	{
	   exp2+=(ceil((e1*1.00)/4+19)+ceil((e1*1.00)/9+21));
	   if (exp2>400)
	   {
	   	   exp2+=ceil((e1*1.00)/16+17);
           exp2 = ceil (exp2* 1.15);
	   }	
       exp2=ceil(exp2);
    
	}
	if (exp2 > 600)
	{
		exp2=600;
	}
    if (exp2 < 0)
    {
        exp2=0;
    }
    if(exp1>600)
  {
      exp1=600;
  }
  if(exp1<0)
  {
      exp1=0;
  }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
    {
    if (E2 < 0 || E2 > 99) return -99;
    float P1, P2, P3;
    float P4[20] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    double moneyspent = 0.0;
    int S1, S2;
    S1=ceil(sqrt(EXP1))*ceil(sqrt(EXP1));
     if(S1 - EXP1>EXP1 - (floor(sqrt(EXP1))*floor(sqrt(EXP1))) )
  {
      S1=floor(sqrt(EXP1))*floor(sqrt(EXP1));
  }
  else{
      S1=(ceil(sqrt(EXP1))) * (ceil(sqrt(EXP1)));
  }
    if (EXP1>=S1)
    {
        P1=1.0;
    }
    else
    {
        P1=1.00*(EXP1/S1+80)/123;
    }
    if (E2 % 2 == 1)
    {
    do
    {
    //event1
       if (HP1<200)
    {
        HP1=(ceil(1.3*HP1));
        moneyspent+=150;
        M1-=150;
    }
    else 
    {
        HP1=(ceil(1.1*HP1));
        moneyspent+=70;
        M1-=70;
    }
    //event2
    if (EXP1<400)
    {
        moneyspent+=200;
        M1-=200;
    }
    else 
    {
        moneyspent+=120;
        M1-=120;
    }
    EXP1=(ceil(1.13*EXP1));
    //event3
    if (EXP1<300)
    {
        moneyspent+=100;
        M1-=100;
    }
    else if (EXP1>=300)
    {
        moneyspent+=120;
        M1-=120;
    }
    EXP1=(ceil(0.9*EXP1));
    }
    while ( M1 < moneyspent);
   if (HP1<200 && M1 > moneyspent)
    //event1
    {
        HP1=(ceil(1.3*HP1));
        moneyspent+=150;
        M1-=150;
    }
    else if (HP1>=200 && M1 > moneyspent)
    {
        HP1=(ceil(1.1*HP1));
        moneyspent+=70;
        M1-=70;
    }
    //event2
    if (EXP1<400 && M1 > moneyspent)
    {
        moneyspent+=200;
        M1-=200;
    }
    else if (EXP1>=400 && M1 > moneyspent)
    {
        moneyspent+=120;
        M1-=120;
    }
    EXP1=(ceil(1.13*EXP1));
    //event3
    if (EXP1<300 && M1 > moneyspent)
    {
        moneyspent+=100;
        M1-=100;
        EXP1=(ceil(0.9*EXP1));
    }
    else if (EXP1>=300 && M1 > moneyspent)
    {
        moneyspent+=120;
        M1-=120;
        EXP1=(ceil(0.9*EXP1));
    }
     if(E2%2==0)
     {
  if(HP1>200 && M1>0){
      HP1=ceil(HP1*1.1);
      M1=M1 - 70;
  }
  else if(HP1<200 && M1>0){
      HP1=ceil(HP1*1.3);
      M1=M1 - 150;
  }
  if(EXP1>400 && M1>0){
      M1=M1 - 200;
      EXP1=ceil(EXP1*1.13);
  }
  else if(EXP1<400 && M1>0){
      M1=M1 - 120;
      EXP1=ceil(EXP1*1.13);
  }
  if(EXP1>300 && M1>0){
      M1=M1 - 120;
      EXP1=ceil(EXP1*0.9);
  }
  else if(EXP1<300 && M1>0){
      M1=M1 - 100;
      EXP1=ceil(EXP1*0.9);
  }
  }
  HP1=ceil(HP1*0.83);
  EXP1=ceil(EXP1*1.17);
    }
    S2=ceil(sqrt(EXP1))*ceil(sqrt(EXP1));
    if(S2 - EXP1>EXP1 - (floor(sqrt(EXP1))*floor(sqrt(EXP1))) )
  {
      S2=floor(sqrt(EXP1))*floor(sqrt(EXP1));
  }
  else{
      S2=ceil(sqrt(EXP1)) * ceil(sqrt(EXP1));
  }
    if (EXP1>=S2)
    {
        P2=1.0;
    }
    else
    {
        P2=1.00*(EXP1/S2+80)/123;
    }
    if (E2 < 10) 
    {
        i = E2;
    } 
    else if (E2 > 10)
    {
        int Sum = E2 / 10 + E2 % 10;
        i = Sum % 10;
    }
    else 
    {
        i=1;
    }
    P3 =P4[i]/100;
    float P = 1.00*((P1 + P2 + P3)/3);
    if (P==1)
    {
        EXP1=ceil(0.75*EXP1);
    }
    if (P < 0.5 && P >= 0.0)
    {
        HP1 = ceil (0.85*HP1);
        EXP1 = ceil (1.15*EXP1);
    }
    if (P >= 0.5 && P < 1) 
    {
        HP1 = ceil (0.9*HP1);
        EXP1 = ceil (1.2*EXP1);
    }
    if(EXP1>600)
  {
      EXP1=600;
  }
  if(EXP1<0)
  {
      EXP1=0;
  }
  if(HP1>666)
  {
      HP1=666;
  }
  if(HP1<0)
  {
      HP1=0;
  }
  if(M1>3000)
  {
      M1=3000;
  }
    if(M1<0)
  {
      M1=0;
  }
    return HP1 + EXP1 + M1;
}

// Task 3
const int rows = 10;
const int cols = 10;
void displayMatrix(int matrix[rows][cols], const char* matrixName) {
    cout << matrixName << " Matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
int calculateDiagonalScore(int matrix[rows][cols], int startX, int startY, int directionX, int directionY) {
    int score = matrix[startX][startY];
    int x = startX + directionX;
    int y = startY + directionY;
    while (x >= 0 && x < rows && y >= 0 && y < cols) {
        score = max(score, matrix[x][y]);
        x += directionX;
        y += directionY;
    }
return score;
}
int calculateSherlockWatsonScore(int matrix[rows][cols], int meetingX, int meetingY) {
    int leftDiagonalScore = calculateDiagonalScore(matrix, meetingX, meetingY, 1, 1);
    int rightDiagonalScore = calculateDiagonalScore(matrix, meetingX, meetingY, 1, -1);
    return max(leftDiagonalScore, rightDiagonalScore);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 > 99 || E3 < 0) return -99;
    int map[rows][cols];
    int I = 0;
    int J = 0;

    // Create Map
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < cols; ++i) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > (E3 * 2)) {
                I++;
            }
            if (map[i][j] < (-E3)) {
                J++;
            }
        }
    }

    // Find Meeting Spot
    do {
        I = I % 10 + (I - I % 10) / 10;
    } while (I > 9);
    do {
        J = J % 10 + (J - J % 10) / 10;
    } while (J > 9);

    // Calculate Sherlock and Watson Scores
    int sherlockWatsonScore = calculateSherlockWatsonScore(map, I, J);
    
    if (abs(map[I][J]) > abs(sherlockWatsonScore)) {
        // Taxi not caught
        HP1 = ceil (HP1*0.9); 
        EXP1 = ceil (EXP1*0.88); 
        HP2 =ceil (HP2*0.9);
        EXP2 = ceil (EXP2*0.88);
    } else {
        // Taxi caught
        HP1 = ceil (HP1*1.1); 
        EXP1 =ceil (EXP1*1.12); 
        HP2 = ceil (HP2*1.1);
        EXP2 = ceil (EXP2*1.12);
    }
    if(EXP1>600)
  {
      EXP1=600;
  }
  if(EXP1<0)
  {
      EXP1=0;
  }
  if(HP1>666)
  {
      HP1=666;
  }
  if(HP1<0)
  {
      HP1=0;
  }
  if(EXP2>600)
  {
      EXP2=600;
  }
  if(EXP2<0)
  {
      EXP2=0;
  }
  if(HP2>666)
  {
      HP2=666;
  }
  if(HP2<0)
  {
      HP2=0;
  }
    return (abs(map[I][J]) > abs(sherlockWatsonScore)) ? map[I][J] : sherlockWatsonScore;
}
//task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int emailLen = strchr(email, '@') - email; 
    const char specialChars[] = {'@', '#', '%', '$', '!'};
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;

    char se[101];
    strncpy(se, email, emailLen);
    se[emailLen] = '\0';

    const char *found = strstr(s, se);
    if (found != nullptr) return -(300 + (found - s));

    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;

    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || strchr(specialChars, c))) {
            return i;
        }
    }

    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    const int MAX_PASSWORD_LENGTH = 50;
    char correctPassword[MAX_PASSWORD_LENGTH];
    int maxCount = 0;
    int maxLength = 0;
    int correctPosition = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* currentPassword = arr_pwds[i];
        int currentCount = 0;

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                currentCount++;
            }
        }

        if (currentCount > maxCount || (currentCount == maxCount && strlen(currentPassword) > maxLength)) {
            maxCount = currentCount;
            maxLength = strlen(currentPassword);
            strcpy(correctPassword, currentPassword);
            correctPosition = i;
        }
    }
    return correctPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////