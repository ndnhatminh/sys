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

int checkHp1(int & HP1) {
    if (HP1 > 666)
        HP1 = 666;
    if (HP1 < 0)
        HP1 = 0;
    return HP1;
}

int checkHp2(int & HP2) {
    if (HP2 > 666)
        HP2 = 666;
    if (HP2 < 0)
        HP2 = 0;
    return HP2;
}

int checkExp1(int & EXP1) {
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP1 < 0)
        EXP1 = 0;
    return EXP1;
}

int checkExp2(int & EXP2) {
    if (EXP2 > 600)
        EXP2 = 600;
    if (EXP2 < 0)
        EXP2 = 0;
    return EXP2;
}

int checkM1(int & M1) {
    if (M1 > 3000)
        M1 = 3000;
    if (M1 < 0)
        M1 = 0;
    return M1;
}

int checkM2(int & M2) {
    if (M2 > 3000)
        M2 = 3000;
    if (M2 < 0)
        M2 = 0;
    return M2;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    else if (e1 >= 0 && e1 <= 3)
    {
        checkExp1(exp1);
        checkExp2(exp2);
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += (29 + 45 + 75);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += ceil(double(D) / 200);
        else
            exp1 = ceil(exp1 - double(D) / 100);
    }
    else
    {
        checkExp1(exp1);
        checkExp2(exp2);
        if (e1 >= 4 && e1 <= 19)
            exp2 += ceil(double(e1) / 4 + 19);
        else if (e1 >= 20 && e1 <= 49)
            exp2 += ceil(double(e1) / 9 + 21);
        else if (e1 >= 50 && e1 <= 65)
            exp2 += ceil(double(e1) / 16 + 17);
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += ceil(double(e1) / 4 + 19);
            if (exp2 > 200)
                exp2 += ceil(double(e1) / 9 + 21);
        }
        else
        {
            exp2 += ceil(double(e1) / 4 + 19);
            exp2 += ceil(double(e1) / 9 + 21);
            if (exp2 > 400)
            {
                exp2 += ceil(double(e1) / 16 + 17);
                exp2 = ceil(float(exp2 * 1.15));
            }
        }
        exp1 -= e1;
    }
    checkExp1(exp1);
    checkExp2(exp2);
    return exp1 + exp2;
}

// Task 2
int findNearestSquare(int & EXP1) {
    checkExp1(EXP1);
    int sqrtExp1 = sqrt(double(EXP1));
    if (sqrtExp1 * sqrtExp1 == EXP1)
        return EXP1;
    int S0 = sqrtExp1 * sqrtExp1;
    int S1 = (sqrtExp1 + 1) * (sqrtExp1 + 1);
    int s0 = abs(EXP1 - S0);
    int s1 = abs(EXP1 - S1);
    if (s0 <= s1)
        return S0;
    else
        return S1;
}

int action1(int & HP1, int & M1) {
    checkHp1(HP1);
    checkM1(M1);
    if (HP1 < 200)
    {
        HP1 = ceil(float(HP1 * 1.3));
        M1 -= 150;
    }
    else
    {
        HP1 = ceil(float(HP1 * 1.1));
        M1 -= 70;
    }
    checkHp1(HP1);
    checkM1(M1);
    return 0;
}

int action2(int & EXP1, int & M1) {
    checkExp1(EXP1);
    checkM1(M1);
    if (EXP1 < 400)
        M1 -= 200;
    else
        M1 -= 120;
    EXP1 = ceil(float(EXP1 * 1.13));
    checkExp1(EXP1);
    checkM1(M1);
    return 0;
}

int action3(int & EXP1, int & M1) {
    checkExp1(EXP1);
    checkM1(M1);
    if (EXP1 < 300)
        M1 -= 100;
    else
        M1 -= 120;
    EXP1 = ceil(float(EXP1 * 0.9));
    checkExp1(EXP1);
    checkM1(M1);
    return 0;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Route 01
    if (E2 < 0 || E2 > 99)
        return -99;
    checkHp1(HP1);
    checkExp1(EXP1);
    checkM1(M1);
    double P1;
    int S01 = findNearestSquare(EXP1);
    if (EXP1 >= S01)
        P1 = 1;
    else
        P1 = (double(EXP1) / S01 + 80) / 123;

    // Route 02
    if (E2 % 2 == 1)
    {
        int initialM1 = M1;
        double halfM1 = M1 * 0.5;
        int totalCost = 0;
        while (totalCost <= halfM1 && M1 != 0)
        {
            action1(HP1, M1);
            totalCost = (initialM1 - M1);
            if (totalCost > halfM1)
                break;
            action2(EXP1, M1);
            totalCost = (initialM1 - M1);
            if (totalCost > halfM1)
                break;
            action3(EXP1, M1);
            totalCost = (initialM1 - M1);
        }
        HP1 = ceil(float(HP1 * 0.83));
        EXP1 = ceil(float(EXP1 * 1.17));
    }
    else
    {
        for (int i = 0; i < 1; i++)
        {
            if (M1 == 0)
                break;
            action1(HP1, M1);
            if (M1 == 0)
                break;
            action2(EXP1, M1);
            if (M1 == 0)
                break;
            action3(EXP1, M1);
        }
        HP1 = ceil(float(HP1 * 0.83));
        EXP1 = ceil(float(EXP1 * 1.17));
    }
    checkHp1(HP1);
    checkExp1(EXP1);
    double P2;
    int S02 = findNearestSquare(EXP1);
    if (EXP1 >= S02)
        P2 = 1;
    else
        P2 = (double(EXP1) / S02 + 80) / 123;

    // Route 03
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 - 10 < 0)
        i = E2;
    else
        i = (int(E2 / 10) + (E2 % 10)) % 10;
    double P3 = P[i] / 100;

    if (P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 = ceil(float(EXP1 * 0.75));
    else
    {
        double finalP = (P1 + P2 + P3) / 3;
        if (finalP < 0.5)
        {
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        }
        else
        {
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        }
    }
    checkHp1(HP1);
    checkExp1(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    checkHp1(HP1);
    checkExp1(EXP1);
    checkHp2(HP2);
    checkExp2(EXP2);
    int roadMap[10][10];
    int scoreTaxi;
    int scoreSherlockWatson;
    int higherValue = 0, lowerValue = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            roadMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (roadMap[i][j] > (E3 * 2))
                higherValue++;
            if (roadMap[i][j] < -E3)
                lowerValue++;
        }
    }
    while (higherValue - 10 >= 0)
        higherValue = (higherValue / 10) + (higherValue % 10);
    while (lowerValue - 10 >= 0)
        lowerValue = (lowerValue / 10) + (lowerValue % 10);
    int i = higherValue;
    int j = lowerValue;
    int max = roadMap[i][j];
    while (i > 0 && j > 0)
    {
        i--;
        j--;
        if (max < roadMap[i][j])
            max = roadMap[i][j];
    }
    i = higherValue;
    j = lowerValue;
    while (i < 9 && j < 9)
    {
        i++;
        j++;
        if (max < roadMap[i][j])
            max = roadMap[i][j];
    }
    i = higherValue;
    j = lowerValue;
    while (i > 0 && j < 9)
    {
        i--;
        j++;
        if (max < roadMap[i][j])
            max = roadMap[i][j];
    }
    i = higherValue;
    j = lowerValue;
    while (i < 9 && j > 0)
    {
        i++;
        j--;
        if (max < roadMap[i][j])
            max = roadMap[i][j];
    }
    scoreTaxi = roadMap[higherValue][lowerValue];
    scoreSherlockWatson = max;
    if (abs(scoreTaxi) > abs(scoreSherlockWatson))
    {
        EXP1 = ceil(float(EXP1 * 0.88));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));
        HP2 = ceil(float(HP2 * 0.9));
        checkHp1(HP1);
        checkExp1(EXP1);
        checkHp2(HP2);
        checkExp2(EXP2);
        return scoreTaxi;
    }
    else
    {
        EXP1 = ceil(float(EXP1 * 1.12));
        EXP2 = ceil(float(EXP2 * 1.12));
        HP1 = ceil(float(HP1 * 1.1));
        HP2 = ceil(float(HP2 * 1.1));
        checkHp1(HP1);
        checkExp1(EXP1);
        checkHp2(HP2);
        checkExp2(EXP2);
        return scoreSherlockWatson;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string password = s;
    string victimEmail = email;
    string se;
    for (int i = 0; i < victimEmail.length(); i++)
    {
        if (victimEmail[i] == '@')
        {
            se = victimEmail.substr(0, i);
            break;
        }
    }
    if (password.length() < 8)
        return -1;
    if (password.length() > 20)
        return -2;
    if (password.length() >= se.length())
    {
        for (int i = 0; i <= (password.length() - se.length()); i++)
        {
            if (password.substr(i, se.length()) == se)
                return -(300 + i);
        }
    }
    for (int i = 0; i < (password.length() - 2); i++)
    {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2])
            return -(400 + i);
    }
    for (int i = 0; i <= password.length(); i++)
    {
        if (i == password.length())
            return -5;
        if (password[i] != '@' && password[i] != '#' && password[i] != '%' && password[i] != '$' && password[i] != '!')
            continue;
        else
            break;
    }
    char characters[] = {'`', '~', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', '{', ']', '}', '\\', '|', ';', ':', '\'', '\"', ',', '<', '.', '>', '/', '?'};
    for (int i = 0; i < password.length(); i++)
    {
        for (int j = 0; j < sizeof characters; j++)
        {
            if (password[i] == characters[j])
                return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arrayPassword[30];
    for (int i = 0; i < num_pwds; i++)
        arrayPassword[i] = arr_pwds[i];
    int n = 0, max = 0, k;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (arrayPassword[i] == arrayPassword[j])
                n++;
        }
        if (max < n)
        {
            max = n;
            k = i;
        }
        else if (max == n)
        {
            if (arrayPassword[k].length() < arrayPassword[i].length())
               k = i;
        }
        n = 0;
    }
    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////