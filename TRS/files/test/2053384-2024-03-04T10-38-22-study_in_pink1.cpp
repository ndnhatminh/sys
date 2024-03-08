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

//! Task 1
int checkHP1(int &hp1)
{
    if (hp1 < 0)
    {
        hp1 = 0;
    }
    if (hp1 > 666)
    {
        hp1 = 666;
    }
    return hp1;
}
int checkHP2(int &hp2)
{
    if (hp2 < 0)
    {
        hp2 = 0;
    }
    if (hp2 > 666)
    {
        hp2 = 666;
    }
    return hp2;
}
int checkEXP(int &exp)
{
    if (exp < 0)
    {
        exp = 0;
    }
    if (exp > 600)
    {
        exp = 600;
    }
    return exp;
}


int calEx03(int &exp1, int &exp2, int e1)
{
    if (e1 == 0)
    {
        exp2 += 29;
    }
    else if (e1 == 1)
    {
        exp2 += 45;
    }
    else if (e1 == 2)
    {
        exp2 += 75;
    }
    else if (e1 == 3)
    {
        exp2 += (29 + 45 + 75);
    }
    int D = e1 * 3 + exp1 * 7;
    if (D % 2 == 0)
    {
        exp1 = ceil(exp1 + (D / 200.0));
    }
    else
    {
        exp1 = ceil(exp1 - (D / 100.0));
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 <= 3 && e1 >= 0)
    {
        return calEx03(exp1, exp2, e1);
    }
    else if (e1 > 3 && e1 <= 19)
    {
        exp2 += ceil(e1 / 4.0 + 19);
    }
    else if (e1 > 19 && e1 <= 49)
    {
        exp2 += ceil(e1 / 9.0 + 21);
    }
    else if (e1 > 49 && e1 <= 65)
    {
        exp2 += ceil(e1 / 16.0 + 17);
    }
    else if (e1 > 65 && e1 <= 79)
    {
        exp2 += ceil(e1 / 4.0 + 19);
        if (exp2 > 200)
            exp2 += ceil(e1 / 9.0 + 21);
    }
    else if (e1 > 79 && e1 <= 99)
    {
        exp2 += ceil(e1 / 4.0 + 19) + ceil(e1 / 9.0 + 21);
        if (exp2 > 400)
        {
            exp2 += ceil(e1 / 16.0 + 17);
            exp2 += ceil(exp2 * 0.15); // Increase exp2 by 15%
        }
    }
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    exp1 -= e1;
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int nearestSquare(int num)
{
    double sqrtNum = sqrt(num);
    int sqrtMin = floor(sqrtNum);
    int sqrtMax = ceil(sqrtNum);
    if (abs(sqrtMin * sqrtMin - num) > abs(sqrtMax * sqrtMax - num))
    {
        return sqrtMax * sqrtMax;
    }
    else
    {
        return sqrtMin * sqrtMin;
    }
}
bool checkMoney(int &M1)
{
    if (M1 <= 0)
    {
        M1 = 0;
        return false;
    }
    else
        return true;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{

    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p1 = 0.0, p2 = 0.0, p3 = 0.0, p = 0.0;
    int nearestSquareNum = nearestSquare(EXP1);

    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }

    if (EXP1 >= nearestSquare(EXP1))
    {
        p1 = 1.0;
    }
    else
    {
        p1 = ((float)EXP1 / nearestSquare(EXP1) + 80) / 123;
    }

    if (E2 % 2 == 0)
    {
        if (checkMoney(M1))
        {
            if (HP1 < 200) // HP1 < 200 m-150
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                M1 -= 150;
                checkHP1(HP1);
            }
            else // HP1 > 200 m-70
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 -= 70;
                checkHP1(HP1);
            }
        }

        if (checkMoney(M1))
        {
            if (EXP1 < 400) // đi taxi
            {
                M1 -= 200;

                EXP1 = ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
            }
            else // đi xe ngựa
            {
                M1 -= 120;

                EXP1 = ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
            }
        }

        if (checkMoney(M1))
        {
            if (EXP1 < 300) // cho người ăn xin 100
            {
                M1 -= 100;

                EXP1 = ceil(EXP1 * 9.0 / 10);
                checkEXP(EXP1);
            }
            else // cho người ăn xin 120
            {
                M1 -= 120;

                EXP1 = ceil(EXP1 * 9.0 / 10);
                checkEXP(EXP1);
            }
        }
        HP1 = ceil(HP1 * 83.0 / 100);
        checkHP1(HP1);
        EXP1 = ceil(EXP1 * 117.0 / 100);
        checkEXP(EXP1);
    }
    else
    {
        int Money = M1;
        int MSpent = 0;
        while (MSpent < Money / 2)
        {
            if (checkMoney(M1))
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 + (HP1 * 0.3));
                    M1 -= 150;
                    MSpent += 150;
                    checkHP1(HP1);
                }
                else
                {
                    HP1 = ceil(HP1 + (HP1 * 0.1));
                    M1 -= 70;
                    MSpent += 70;
                    checkHP1(HP1);
                }
            }
            if (MSpent > Money / 2)
                break;
            if (checkMoney(M1))
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    MSpent += 200;
                    EXP1 = ceil(EXP1 + (EXP1 * 0.13));
                    checkEXP(EXP1);
                }
                else
                {
                    M1 -= 120;
                    MSpent += 120;
                    EXP1 = ceil(EXP1 + (EXP1 * 0.13));
                    checkEXP(EXP1);
                }
            }
            if (MSpent > Money / 2)
                break;
            if (checkMoney(M1))
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    MSpent += 100;
                    EXP1 = ceil(EXP1 - (EXP1 * 0.1));
                    checkEXP(EXP1);
                }
                else
                {
                    M1 -= 120;
                    MSpent += 120;
                    EXP1 = ceil(EXP1 - (EXP1 * 0.1));
                    checkEXP(EXP1);
                }
            }
            if (MSpent > Money / 2)
                break;
        }
        HP1 = ceil(HP1 - (HP1 * 0.17));
        EXP1 = ceil(EXP1 + (EXP1 * 0.17));
        checkMoney(M1);
        checkHP1(HP1);
        checkEXP(EXP1);
    }
    checkMoney(M1);
    int nearNum = nearestSquare(EXP1);
    if (EXP1 >= nearNum)
    {
        p2 = 1.0;
    }
    else
    {
        p2 = ((float)EXP1 / 200 + 80) / 123;
    }

    int i = 0;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        int a = E2 / 10;
        int b = E2 % 10;
        i = (a + b) % 10;
    }
    p3 = (float)arr[i] / 100;

    p = (p1 + p2 + p3) / 3;

    if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0)
    {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else
    {

        if (p > 0.5)
        {
            EXP1 += ceil(EXP1 * 0.2);
            HP1 = ceil(HP1 *9.0/10);
            checkHP1(HP1);
            checkEXP(EXP1);
        }
        else
        {
            EXP1 += ceil(EXP1 * 0.15);
            HP1 = ceil(HP1 *85.0/100);
            checkHP1(HP1);
            checkEXP(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int calculateScore(int E3, int i, int j) {
    return ((E3 * j) + (i * 2)) * (i - j);
}

int findBiggestScore(int E3, int matrix[10][10], int i, int j) {
    int maxDiag1 = matrix[i][j];
    int maxDiag2 = matrix[i][j];

    int row = i - 1;
    int col = j - 1;

    while (row >= 0 && col >= 0) {
        if (matrix[row][col] > maxDiag1) {
            maxDiag1 = matrix[row][col];
        }
        row--;
        col--;
    }
    row = i + 1;
    col = j + 1;
    while (row < 10 && col < 10) {
        if (matrix[row][col] > maxDiag1) {
            maxDiag1 = matrix[row][col];
        }
        row++;
        col++;
    }

    row = i - 1;
    col = j + 1;
    while (row >= 0 && col < 10) {
        if (matrix[row][col] > maxDiag2) {
            maxDiag2 = matrix[row][col];
        }
        row--;
        col++;
    }
    row = i + 1;
    col = j - 1;
    while (row < 10 && col >= 0) {
        if (matrix[row][col] > maxDiag2) {
            maxDiag2 = matrix[row][col];
        }
        row++;
        col--;
    }

    return max(maxDiag1, maxDiag2);
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int matrix[10][10] = {0};
    int countPos = 0;
    int countNeg = 0;
    int posI = 0, posJ = 0;

    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = calculateScore(E3, i, j);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] > 0 && matrix[i][j] > E3 * 2) {
                countPos++;
            }
            if (matrix[i][j] < -E3 && matrix[i][j] < 0) {
                countNeg++;
            }
        }
    }

    while (true) {
        int firstPos = countPos / 10;
        int secondPos = countPos % 10;
        posI = firstPos + secondPos;
        countPos = posI;
        if (posI < 10) {
            break;
        }
    }
    while (true) {
        int firstNeg = countNeg / 10;
        int secondNeg = countNeg % 10;
        posJ = firstNeg + secondNeg;
        countNeg = posJ;
        if (posJ < 10) {
            break;
        }
    }

    int scoreSherlock = findBiggestScore(E3, matrix, posI, posJ);

    if (scoreSherlock >= abs(matrix[posI][posJ])) {
        EXP1 = ceil(EXP1 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
        checkEXP(EXP1);
        checkHP1(HP1);
        checkEXP(EXP2);
        checkHP2(HP2);
    } else {
        EXP1 = ceil(EXP1 * 88.0 / 100);
        HP1 = ceil(HP1 * 90.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP2 = ceil(HP2 * 90.0 / 100);
        checkEXP(EXP1);
        checkHP1(HP1);
        checkEXP(EXP2);
        checkHP2(HP2);
    }

    if (scoreSherlock >= abs(matrix[posI][posJ])) {
        return scoreSherlock;
    }
    return matrix[posI][posJ];
}


// Task 4
int checkPassword(const char *s, const char *email)
{
    string se = "";
    for (int i = 0; i < strlen(email); i++)
    {
        
        if (email[i] != '@')
        {
            se += email[i];
        }
        else
        {
            break;
        }
    }
    if (strlen(s) < 8)
    {
        return -1;
    }
    if (strlen(s) > 20)
    {
        return -2;
    }
    if (email[0] == '@')
    {
        return -300;
    }
    for (int i = 0; i < strlen(s); i++)
    {

        if (s[i] == se[0])
        {
            int a = i;
            int count = 0;
            for (int j = i; se.length(); j++)
            {
                if (s[j] != se[count])
                {
                    break;
                }
                count++;
                if (count == se.length())
                {
                    return -(300 + a);
                }
            }
        }
    }
    for (int i = 0; i < strlen(s); i++)
    {
        {
            char c = s[i];
            if (c == s[i + 1]&&c==s[i+2])
            {
                return -(400 + i);
            }
        }
    }
    bool check = false;
    for (int i = 0; i < strlen(s); i++)
    {

        if (s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '&' || s[i] == '!')
        {
            
            check = true;
        }
    }
    if(check==true){
       for (int i = 0; i < strlen(s); i++)
       {
            if(s[i]<'A'&&s[i]>'9'||s[i]>'Z'&&s[i]<'a'||s[i]>'z'||s[i]<'0') {
            {
                if(s[i]!='@'&&s[i]!='#'&&s[i]!='$'&&s[i]!='%'&&s[i]!='&'&&s[i]!='!'){
                    return i;
                }
            }
            }
        }
        return -10;
    }
    return -5;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    char v[num_pwds][21] = {""}; // Assuming maximum length of password is 20 characters
    int max=0;
    int indexMax=0;
    int lenMax=0;
    for(int i=0;i<num_pwds;i++){
        strcpy(v[i], arr_pwds[i]);
    }

    for(int i=0;i<num_pwds;i++){
        int count=0;
        
        for(int j=i+1;j<num_pwds;j++){
            if(strcmp(v[i], v[j]) == 0){
                count++;
            }
        }
        if(count>max){
                max=count;
                indexMax=i;
                lenMax=strlen(v[i]);
        }
        else if(count==max){
            if(strlen(v[i])>lenMax){
                lenMax=strlen(v[i]);
                indexMax=i;
            }
        }

    }
    return indexMax;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////