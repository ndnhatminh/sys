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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    expCheck(exp1);
    expCheck(exp2);
    if (eCheck(e1))
        return -99;
    if (e1 < 4)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += 149;
            break;
        }
       int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 += ceil((D / 200) );
            
        }
        else
        {
            exp1 -= ceil((D / 100) - 0.5);  
        }
        expCheck(exp1);
        expCheck(exp2);
    }
    else
    {
        if (e1 < 20)
        {
            exp2 += ceil((float)e1 / 4 + 19);
        }
        else if (e1<50)
        {
            exp2 += ceil((float)e1 / 9 + 21);
        }
        else if (e1<66)
        {
            exp2 += ceil((float)e1 / 16 + 17);
        }
        else if (e1 < 80)
        {
            exp2 += ceil((float)e1 / 4 + 19);
            if(exp2>200)
                exp2 += ceil((float)e1 / 9 + 21);
        }
        else
        {
                exp2 += ceil((float)e1 / 4 + 19);
                expCheck(exp1);
                expCheck(exp2);
                exp2 += ceil((float)e1 / 9 + 21);
                expCheck(exp1);
                expCheck(exp2);
            if (exp2 > 400)
            {
                exp2 += ceil((float)e1 / 16 + 17);
                expCheck(exp1);
                expCheck(exp2);
                exp2 =ceil(exp2*1.15) ;
            }
        }
        exp1 -= e1;
    }
    expCheck(exp1);
    expCheck(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (eCheck(E2))
        return -99;
    double P1, P2, P3, avg;
    P1 = firstPath(EXP1);
    P2 = secondPath(HP1, EXP1, M1, E2);
    P3 = thirdPath(E2);
    avg = (P1 + P2 + P3) / 3;
    if (avg == 100)
    {
        EXP1 = ceil(EXP1 * 0.75);
        expCheck(EXP1);
        traceLuggage(HP1, EXP1, M1, E2);
    }
    else if (avg < 50)
    {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
        hpCheck(HP1);
        expCheck(EXP1);
    }
    else
    {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
        hpCheck(HP1);
        expCheck(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxiPoint[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiPoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int f = 0, g = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (taxiPoint[i][j] > (E3 * 2))
                f++;
            else if (taxiPoint[i][j] < (-E3))
                g++;
        }
    }
    convert(f), convert(g);
    int dectectivesPoint = max(maxSlantLeft(taxiPoint, f, g), maxSlantRight(taxiPoint, f, g)), taxiPointFinal = abs(taxiPoint[f][g]);
    if (dectectivesPoint < taxiPointFinal)
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        expCheck(EXP1);
        expCheck(EXP2);
        hpCheck(HP1);
        hpCheck(HP2);
        return taxiPoint[f][g];
    }
    else
    {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.10);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.10);
        expCheck(EXP1);
        expCheck(EXP2);
        hpCheck(HP1);
        hpCheck(HP2);
        return dectectivesPoint;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    // TODO: Complete this function
    char se[100];
    int length = 0, charSize = strlen(s),i=0, specialChar = 0;
    if (charSize < 8)
        return -1;
    else if (charSize > 20)
        return -2;
    
    while (email[length] != '@')
    {
        se[length] = email[length];
        length++;
    }
    se[length] = '\0';
    int find = string(s).find(string(se));
    if ( find!= string::npos)
        return -(300 + find);
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == s[i + 1])
            return -(400 + i);
        i++;
    }
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            specialChar++;
        i++;
    }
    if (specialChar == 0)
        return-5;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            i++;
        else if (48 <= s[i] && s[i] <= 57)
            i++;
        else if (65 <= s[i] && s[i] <= 90)
            i++;
        else if (97 <= s[i] && s[i] <= 122)
            i++;
        else
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int dup[num_pwds] = {}, counter;
    for (int i = 0; i < num_pwds; i++)
    {
        counter = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
            {
                counter++;
                dup[j] = -1;
            }
        }
        if (dup[i] != -1)
            dup[i] = counter;
    }
    int truePass = 0;
for(int i=1;i<num_pwds-1;i++)
  {
    if (dup[truePass] == dup[i])
    {
        if (strlen(arr_pwds[truePass]) < strlen(arr_pwds[i]))
            truePass = i;
        else
            continue;
    }
    else if (dup[truePass] < dup[i])
        truePass = i;
    else continue;
        
  }
if (num_pwds == 0)
return -1;
else 
return truePass;
}
// Checking for Hp limits
void hpCheck(int& HP)
{
    if (HP < 0)
        HP = 0;
    if (HP > 666)
        HP = 666;

}
void moneyCheck(int& M)
{
    if (M < 0)
        M = 0;
    if (M > 3000)
        M = 3000;

}
// Checking for exp limits
void expCheck(int& exp)
{
    if (exp < 0)
        exp = 0;
    if (exp > 600)
        exp = 600;

}
// Checking value e
bool eCheck(int e)
{
    if (e < 0 || e>99)
        return true;
    else return false;
}
int findSquare(int exp1)
{
    int result;
    result = pow(round(sqrt(exp1)), 2);
    return result;
}
double firstPath(int exp1)
{
    int S = findSquare(exp1);
    double P1;
    if (exp1 >= S)
        P1 = 100;
    else
        P1 = ((double)exp1 / (double)S + 80) / 123 * 100;
    return P1;
}
void pathTwoFirst(int& HP1, int& M1)
{
    hpCheck(HP1);
    moneyCheck(M1);
    if (HP1 < 200)
    {
        HP1 = ceil(HP1 * 1.3);
        M1 -= 150;
        moneyCheck(M1);
    }
    else
    {
        HP1 = ceil(HP1 * 1.1);
        M1 -= 70;
        moneyCheck(M1);
        hpCheck(HP1);
    }
}
// Path 2 task 2 second event
void pathTwoSecond(int& EXP1, int& M1)
{
    expCheck(EXP1);
    moneyCheck(M1);
    if (EXP1 < 400)
    {
        M1 -= 200;
        moneyCheck(M1);
    }
    else
    {
        M1 -= 120;
        EXP1 = ceil((double)EXP1 * 1.13);
        moneyCheck(M1);
        expCheck(EXP1);
    }
}
// Path 2 task 2 third event
void pathTwoThird(int& EXP1, int& M1)
{
    expCheck(EXP1);
    moneyCheck(M1);
    if (EXP1 < 300)
    {
        M1 -= 100;
        moneyCheck(M1);
    }
    else
    {
        M1 -= 120;
        moneyCheck(M1);
    }
    EXP1 = ceil(EXP1 * 0.9);
    expCheck(EXP1);
}
double secondPath(int& HP1, int& EXP1, int& M1, int E2)
{
    int S = findSquare(EXP1);
    double P2;
    if (E2 % 2 == 0)
    {
        do
        {
            pathTwoFirst(HP1, M1);
            if (M1 == 0)
                break;
            pathTwoSecond(EXP1, M1);
            if (M1 == 0)
                break;
            pathTwoThird(EXP1, M1);
            if (M1 == 0)
                break;
            break;
        } while (true);
    }
    else
    {
        float budget = M1 / 2;
        do
        {
            pathTwoFirst(HP1, M1);
            if (M1 < budget)
                break;
            pathTwoSecond(EXP1, M1);
            if (M1 < budget)
                break;
            pathTwoThird(EXP1, M1);
            if (M1 < budget)
                break;
        } while (true);
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    hpCheck(HP1);
    expCheck(EXP1);
    P2 = firstPath(EXP1);
    return P2;
}
double thirdPath(int E2)
{
    double P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    double P3;
    if (E2 < 10)
        P3 = P[E2];
    else
    {
        int i = (E2 % 10 + E2 / 10) % 10;
        P3 = P[i];
    }
    return P3;
}
int maxSlantRight(int taxiPoint[][10], int i, int j)
{
    int f, g, maxVal;
    if (i + j <= 9)
    {
        if (i == 0 && j == 0)
            return abs(taxiPoint[i][j]);
        else
        {
            f = 0; g = j + i;
            maxVal = taxiPoint[f][g];
            while (f <= j + i)
            {
                maxVal = std::max(maxVal, taxiPoint[f + 1][g - 1]);
                f++; g--;
            }
        }
    }
    else
    {
        f = 9; g = i + j - 9;
        maxVal = taxiPoint[f][g];
        if (i == 9 && j == 9)
            return abs(taxiPoint[i][j]);
        else
        {
            while (g <= 9)
            {
                maxVal = std::max(maxVal, taxiPoint[f - 1][g + 1]);
                f--; g++;
            }
        }
    }
    return abs(maxVal);
}
int maxSlantLeft(int taxiPoint[][10], int i, int j)
{
    int f, g, maxVal;
    if (i <= j)
    {
        if (i == 0 && j == 9)
            return abs(taxiPoint[i][j]);
        else
        {
            f = 0; g = j - i;
            maxVal = taxiPoint[f][g];
            while (g < 9)
            {
                maxVal = std::max(maxVal, taxiPoint[f + 1][g + 1]);
                f++; g++;
            }
        }
    }
    else
    {
        f = 9; g = j - i + 9;
        maxVal = taxiPoint[f][g];
        if (i == 9 && j == 0)
            return abs(taxiPoint[i][j]);
        else
        {

            while (g < 0)
            {
                maxVal = std::max(maxVal, abs(taxiPoint[f - 1][g - 1]));
                f--; g--;
            }
        }
    }
    return abs(maxVal);
}
// Convert numbers with 2 digits
void convert(int& f)
{
    if (f > 9)
        f = f % 10 + f / 10;
    if (f > 9)
        convert(f);
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
//        g++ -o main main.cpp study_in_pink1.cpp -I . -std=c++11
// 
// 
//       ./main sa_tc_01_input