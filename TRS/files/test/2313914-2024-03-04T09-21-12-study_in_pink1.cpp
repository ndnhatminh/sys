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
int ceiling(double value)
{
    return value += 0.999;
}
void checkExp(int& exp)
{
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
}
void checkHP(int& HP)
{
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
}
void checkMoney(int& M)
{
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;
}
int findNumber(int number)
{
    if (number >= 10)
    {
        int temp;
        temp = number % 10 + number / 10;
        if (temp >= 10) temp = temp % 10 + temp / 10;
        number = temp;
    }
    return number;
}
int nearestSquareNumber(int num)
{
    return pow(round(sqrt(num)), 2);
}
// Task 1 (100%)
int firstMeet(int & exp1, int & exp2, int e1) {
    checkExp(exp1);
    checkExp(exp2);
    if (e1 < 0 || e1 > 99) return -99;
    int exp[4] = { 29, 45, 75, (29 + 45 + 75) };
    if (0 <= e1 && e1 <= 3)
    {
        exp2 += exp[e1];
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceiling(exp1 + D * 1.0 / 200);
        else exp1 = ceiling(exp1 - D * 1.0 / 100.0);
        checkExp(exp1);
    }
    else if (4 <= e1 && e1 <= 19) exp2 += ceiling(e1 * 1.0 / 4 + 19);
    else if (20 <= e1 && e1 <= 49) exp2 += ceiling(e1 * 1.0 / 9 + 21);
    else if (50 <= e1 && e1 <= 65) exp2 += ceiling(e1 * 1.0 / 16 + 17);
    else if (66 <= e1 && e1 <= 79)
    {
        exp2 += ceiling(e1 * 1.0 / 4 + 19);
        if (exp2 > 200) exp2 += ceiling(e1 * 1.0 / 9 + 21);
    }
    else
    {
        exp2 += ceiling(e1 * 1.0 / 4 + 19);
        exp2 += ceiling(e1 * 1.0 / 9 + 21);
        if (exp2 > 400) exp2 = ceiling((exp2 + ceiling(e1 * 1.0 / 16 + 17)) * 1.15);
    }
    checkExp(exp2);
    if (!(0 <= e1 && e1 <= 3)) { exp1 -= e1; checkExp(exp1);}
    return exp1 + exp2;
}

// Task 2 (Done)
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    checkHP(HP1);
    checkExp(EXP1);
    checkMoney(M1);
    if (E2 < 0 || E2 > 99) return -99;
    int S1 = nearestSquareNumber(EXP1);
    int firstMoney = M1;
    double P1;
    //Path 1
    //P1 Calculations
    if (EXP1 >= S1) P1 = 1.00;
    else P1 = (((((EXP1 * 1.0) / S1) + 80) * 1.0) / 123);
    //Path 2 //do - while 
    int moneySpent = 0;
    do
    {
        //HP1 < 200 (Food & Drinks)
        if (HP1 < 200)
        {
            HP1 = ceiling(HP1 * 1.3);
            M1 -= 150;
            moneySpent += 150;

        }
        //HP1 >= 200 (Food & Drinks)
        else
        {
            HP1 = ceiling(HP1 * 1.1);
            M1 -= 70;
            moneySpent += 70;
        }
        checkMoney(M1);
        checkHP(HP1);
        if (M1 == 0 || (E2 % 2 != 0 && moneySpent > 0.5 * firstMoney)) break;
        //EXP1 < 400 (Horse or Taxi)
        if (EXP1 < 400)
        {
            M1 -= 200;
            moneySpent += 200;
        }
        //EXP1 >= 400 (Horse or Taxi)
        else
        {
            M1 -= 120;
            moneySpent += 120;
        }
        checkMoney(M1);
        checkHP(HP1);
        //EXP1 increases by 13%
        EXP1 = ceiling(EXP1 * 1.13);
        if (M1 == 0 || (E2 % 2 != 0 && moneySpent > 0.5 * firstMoney)) break;
        //EXP1 < 300 (The homeless person)
        if (EXP1 < 300)
        {
            M1 -= 100;
            moneySpent += 100;
        }
        else
            //EXP1 >= 300 (The homeless person)
        {
            M1 -= 120;
            moneySpent += 120;
        }
        checkMoney(M1);
        checkHP(HP1);
        //EXP1 decreases by 10%
        EXP1 = ceiling(EXP1 * 0.9);
        if (M1 == 0 || (E2 % 2 != 0 && moneySpent > 0.5 * firstMoney)) break;
    } while (E2 % 2 != 0);
    //At the end of 3 events
    HP1 = ceiling(HP1 * 0.83);
    EXP1 = ceiling(EXP1 * 1.17);
    checkHP(HP1);
    checkExp(EXP1);
    //P2 Calculations
    double P2;
    int S2 = nearestSquareNumber(EXP1);
    if (EXP1 >= S2) P2 = 1;
    else P2 = (((((EXP1 * 1.0) / S2) + 80) * 1.0) / 123);
    //Path 3
    double P[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
    int i = 0;
    if (E2 < 10) 
    {
        i = E2;
    }
    else
    {
        i = E2 % 10 + E2 / 10;
        if (i > 10) i = i % 10;
    }
    double P3 = P[i];
    //The Finale
    double finalP;
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceiling(EXP1 * 0.75);
        finalP = 1;
    }
    else 
    {
        finalP = (P1 + P2 + P3) / 3;
    if (finalP < 0.5)
    {
        HP1 = ceiling(HP1 * 0.85);
        EXP1 = ceiling(EXP1 * 1.15);
    }
    else
    {
        HP1 = ceiling(HP1 * 0.9);
        EXP1 = ceiling(EXP1 * 1.2);
    }
    }
    checkHP(HP1);
    checkExp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3 (100%)
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    checkHP(HP1);
    checkExp(EXP1);
    checkHP(HP2);
    checkExp(EXP2);
    if (E3 < 0 || E3 > 99) return -99;
    int biggerNumberCount = 0;
    int smallerNumberCount = 0;
    //Taxi map initialization
    int mapTaxi[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mapTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (mapTaxi[i][j] > (E3 * 2)) biggerNumberCount++;
            if (mapTaxi[i][j] < (-E3)) smallerNumberCount++;
        }
    }
    //The Finale
    int iIndex = findNumber(biggerNumberCount);
    int jIndex = findNumber(smallerNumberCount);
    //Sherlock Holmes initialization
    int SherlockHolmes = mapTaxi[iIndex][jIndex];
    for (int i = 1; i < 10; i++)
    {
        if (iIndex + i == 10 || jIndex + i == 10) break;
        else if (SherlockHolmes < mapTaxi[iIndex + i][jIndex + i]) SherlockHolmes = mapTaxi[iIndex + i][jIndex + i];
    }
    for (int i = 1; i < 10; i++)
    {
        if (iIndex - i == -1 || jIndex - i == -1) break;
        else if (SherlockHolmes < mapTaxi[iIndex - i][jIndex - i]) SherlockHolmes = mapTaxi[iIndex - i][jIndex - i];
    }
    for (int i = 1; i < 10; i++)
    {
        if (iIndex + i == 10 || jIndex - i == -1) break;
        else if (SherlockHolmes < mapTaxi[iIndex + i][jIndex - i]) SherlockHolmes = mapTaxi[iIndex + i][jIndex - i];
    }
    for (int i = 1; i < 10; i++)
    {
        if (iIndex - i == -1 || jIndex + i == 10) break;
        else if (SherlockHolmes < mapTaxi[iIndex - i][jIndex + i]) SherlockHolmes = mapTaxi[iIndex - i][jIndex + i];
    }
    SherlockHolmes = abs(SherlockHolmes);
    if (SherlockHolmes >= abs(mapTaxi[iIndex][jIndex]))
    {
        HP1 = ceiling(HP1 * 1.1);
        EXP1 = ceiling(EXP1 * 1.12);
        HP2 = ceiling(HP2 * 1.1);
        EXP2 = ceiling(EXP2 * 1.12);
        checkHP(HP1);
        checkExp(EXP1);
        checkHP(HP2);
        checkExp(EXP2);
        return SherlockHolmes;
    }
    else
    {
        HP1 = ceiling(HP1 * 0.9);
        EXP1 = ceiling(EXP1 * 0.88);
        HP2 = ceiling(HP2 * 0.9);
        EXP2 = ceiling(EXP2 * 0.88);
        checkHP(HP1);
        checkExp(EXP1);
        checkHP(HP2);
        checkExp(EXP2);
        return mapTaxi[iIndex][jIndex];
    }
}

// Task 4 (100%)
int checkPassword(const char* s, const char* email) {
    //se Initialization
    string se;
    string sString = s;
    for (int i = 0; email[i] != '@'; i++) se += email[i];
    //Check
    if (sString.length() < 8) return -1;
    if (sString.length() > 20) return -2;
    if (sString.find(se) != string::npos) return -(300 + sString.find(se));
    for (int i = 0; i < sString.length() - 2; i++)
    {
        if (sString[i] == sString[i + 1] && sString[i + 1] == sString[i + 2]) return -(400 + i);
    }
    bool checkSpecialCharacter = false;
    for (int i = 0; i < sString.length(); i++)
    {
        if (sString[i] == '@' || sString[i] == '#' || sString[i] == '%' || sString[i] == '$' || sString[i] == '!')
        {
            checkSpecialCharacter = true;
            break;
        }
    }
    if (checkSpecialCharacter == false) return -5;
    for (int i = 0; i < sString.length(); i++) 
    {
        if (!((sString[i] >= 48 && sString[i] <= 57)
            || (sString[i] >= 65 && sString[i] <= 90)
            || (sString[i] >= 97 && sString[i] <= 122)
            || sString[i] == '@' || sString[i] == '#' || sString[i] == '%' || sString[i] == '$' || sString[i] == '!')) return i;
    }
    return -10;
}

// Task 5 (100%)
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int finalCount = 0;
    int finalLength = 0;
    const char* finalPassword = nullptr;
    for (int i = 0; i < num_pwds; i++) 
    {
        int tempCount = 0;
        for (int j = 0; j < num_pwds; j++) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) tempCount++;
        }
        if (tempCount > finalCount || (tempCount == finalCount) && strlen(arr_pwds[i]) > finalLength) 
        {
            finalCount = tempCount;
            finalPassword = arr_pwds[i];
            finalLength = strlen(arr_pwds[i]);
        }
    }
    for (int i = 0; i < num_pwds; i++) 
    {
        if (strcmp(arr_pwds[i], finalPassword) == 0) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////