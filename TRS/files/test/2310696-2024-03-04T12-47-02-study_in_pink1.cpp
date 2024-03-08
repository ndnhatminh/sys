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
int dieukien_EXP(int& EXP)
{
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;
    return EXP;
}
int dieukien_HP(int& HP)
{
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
    return HP;
}
int dieukien_M(int& M)
{
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;
    return M;
}
int lamtron(double a)
{
    if (a > (int)a)
        a = (int)a + 1;
    return (int)a;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1>99)
    {
        return -99;
    }
    dieukien_EXP(exp1);
    dieukien_EXP(exp2);
    if (e1 >= 0 && e1 <= 3) //truong hop 1
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
        }
        dieukien_EXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = lamtron(exp1 + (double)D / 200);
            dieukien_EXP(exp1);
        }
        else
        {
            exp1 = lamtron(exp1 - (double)D / 100);
            dieukien_EXP(exp1);
        }
        return exp1 + exp2;
    }


    else if (e1 >= 4 && e1 <= 99)//truong hop 2
    {
        if (e1 <= 19)
        {
            exp2 = lamtron(exp2 + (double)e1 / 4 + 19);
            dieukien_EXP(exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = lamtron(exp2 + (double)e1 / 9 + 21);
            dieukien_EXP(exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = lamtron(exp2 + (double)e1 / 16 + 17);
            dieukien_EXP(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = lamtron(exp2 + (double)e1 / 4 + 19);
            dieukien_EXP(exp2);
            if (exp2 > 200)
            {
                exp2 = lamtron(exp2 + double(e1) / 9 + 21);
                dieukien_EXP(exp2);
            }
        }
        else
        {
            exp2 = lamtron(exp2 + (double)e1 / 4 + 19);
            dieukien_EXP(exp2);
            exp2 = lamtron(exp2 + (double)e1 / 9 + 21);
            dieukien_EXP(exp2);
            if (exp2 > 400)
            {
                exp2 = lamtron(exp2 + (double)e1 / 16 + 17);
                dieukien_EXP(exp2);
                exp2 = lamtron(exp2 * 1.15);
                dieukien_EXP(exp2);
            }
        }
        exp1 -= e1;
        dieukien_EXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99)
    {
        return -99;
    }
    dieukien_EXP(EXP1);
    dieukien_HP(HP1);
    dieukien_M(M1);
    //con duong 1
    double P1, P2, P3;
    if (sqrt(EXP1) == (int)sqrt(EXP1))
    {
        P1 = 1;
    }
    else
    {
        if ((EXP1 - (int)sqrt(EXP1) * (int)sqrt(EXP1)) < (((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1) - EXP1))
            P1 = 1;
        else
            P1 = ((double)EXP1 / (((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1)) + 80) / 123;
    }
    //con duong 2
    if (E2 % 2 != 0)
    {
        double a = 0.5 * M1;
        double chitra = 0;
        while (1)
        {
            //su kien 1
            if (HP1 < 200)
            {
                HP1 = lamtron((double)HP1 * 1.3);
                dieukien_HP(HP1);
                M1 -= 150;
                dieukien_M(M1);
                chitra += 150;
            }
            else
            {
                HP1 = lamtron((double)HP1 * 1.1);
                dieukien_HP(HP1);
                M1 -= 70;
                dieukien_M(M1);
                chitra += 70;
            }
            if (chitra > a)
            {
                break;
            }
            //su kien 2
            if (EXP1 < 400)
            {
                M1 -= 200;
                dieukien_M(M1);
                chitra += 200;
            }
            else
            {
                M1 -= 120;
                dieukien_M(M1);
                chitra += 120;
            }
            EXP1 = lamtron((double)EXP1 * 1.13);
            dieukien_EXP(EXP1);
            if (chitra > a)
            {
                break;
            }
            //su kien 3
            if (EXP1 < 300)
            {
                M1 -= 100;
                dieukien_M(M1);
                chitra += 100;
            }
            else
            {
                M1 -= 120;
                dieukien_M(M1);
                chitra += 120;
            }
            EXP1 = lamtron((double)EXP1 * 0.9);
            dieukien_EXP(EXP1);
            if (chitra > a)
            {
                break;
            }
        }
        HP1 = lamtron((double)HP1 * 0.83);
        dieukien_HP(HP1);
        EXP1 = lamtron((double)EXP1 * 1.17);
        dieukien_EXP(EXP1);
    }
    else
    {
        for (int i = 0; i < 1; i++)
        {
            //su kien 1
            if (HP1 < 200)
            {
                HP1 = lamtron((double)HP1 * 1.3);
                dieukien_HP(HP1);
                M1 -= 150;
                dieukien_M(M1);
            }
            else
            {
                HP1 = lamtron((double)HP1 * 1.1);
                dieukien_HP(HP1);
                M1 -= 70;
                dieukien_M(M1);
            }
            if (M1 == 0)
            {
                break;
            }
            //su kien 2
            if (EXP1 < 400)
            {
                M1 -= 200;
                dieukien_M(M1);
            }
            else
            {
                M1 -= 120;
                dieukien_M(M1);
            }
            EXP1 = lamtron((double)EXP1 * 1.13);
            dieukien_EXP(EXP1);
            if (M1 == 0)
            {
                break;
            }
            //su kien 3
            if (EXP1 < 300)
            {
                M1 -= 100;
                dieukien_M(M1);
            }
            else
            {
                M1 -= 120;
                dieukien_M(M1);
            }
            EXP1 = lamtron((double)EXP1 * 0.9);
            dieukien_EXP(EXP1);
            if (M1 == 0)
            {
                break;
            }
        }
        HP1 = lamtron((double)HP1 * 0.83);
        dieukien_HP(HP1);
        EXP1 = lamtron((double)EXP1 * 1.17);
        dieukien_EXP(EXP1);
    }
    if (sqrt(EXP1) == (int)sqrt(EXP1))
    {
        P2 = 1;
    }
    else
    {
        if ((EXP1 - (int)sqrt(EXP1) * (int)sqrt(EXP1)) < (((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1) - EXP1))
            P2 = 1;
        else
            P2 = ((double)EXP1 / (((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1)) + 80) / 123;
    }
    int a[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10)
    {
        P3 = a[E2];
    }
    else
    {
        int b = E2, c = 0;
        c += b % 10;
        b = b / 10;
        c += b;
        P3 = a[c % 10];
    }
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = lamtron((double)EXP1 * 0.75);
        dieukien_EXP(EXP1);
    }
    else
    {
        if (((P1 + P2 + P3) / 3) < 0.5)
        {
            HP1 = lamtron((double)HP1 * 0.85);
            dieukien_HP(HP1);
            EXP1 = lamtron((double)EXP1 * 1.15);
            dieukien_EXP(EXP1);
        }
        else
        {
            HP1 = lamtron((double)HP1 * 0.9);
            dieukien_HP(HP1);
            EXP1 = lamtron((double)EXP1 * 1.2);
            dieukien_EXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99)
    {
        return -99;
    }
    dieukien_EXP(EXP1);
    dieukien_EXP(EXP2);
    dieukien_HP(HP1);
    dieukien_HP(HP2);
    int taxi[10][10], nguoi[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = 0;
            nguoi[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            int max = -9999999;
            int a = i, b = j;
            while (1)
            {
                if (taxi[a][b] > max)
                    max = taxi[a][b];
                if (a == 9 || b == 9)
                    break;
                a++;
                b++;
            }
            a = i; b = j;
            while (1)
            {
                if (taxi[a][b] > max)
                    max = taxi[a][b];
                if (a == 0 || b == 0)
                    break;
                a--;
                b--;
            }
            a = i; b = j;
            while (1)
            {
                if (taxi[a][b] > max)
                    max = taxi[a][b];
                if (a == 9 || b == 0)
                    break;
                a++;
                b--;
            }
            a = i; b = j;
            while (1)
            {
                if (taxi[a][b] > max)
                    max = taxi[a][b];
                if (a == 0 || b == 9)
                    break;
                a--;
                b++;
            }

            nguoi[i][j] = abs(max);
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (taxi[i][j] > (E3 * 2))
                x++;
            if (taxi[i][j] < (-E3))
                y++;
        }
    }
    if (x > 9)
    {

        while (x > 9)
        {
            int a = x;
            x = 0;
            x += a % 10;
            a = a / 10;
            x += a;
        }
    }
    if (y > 9)
    {

        while (y > 9)
        {
            int a = y;
            y = 0;
            y += a % 10;
            a = a / 10;
            y += a;
        }
    }
    if (abs(taxi[x][y]) > abs(nguoi[x][y]))
    {
        EXP1 = lamtron((double)EXP1 * 0.88);
        dieukien_EXP(EXP1);
        HP1 = lamtron((double)HP1 * 0.9);
        dieukien_HP(HP1);
        EXP2 = lamtron((double)EXP2 * 0.88);
        dieukien_EXP(EXP2);
        HP2 = lamtron((double)HP2 * 0.9);
        dieukien_HP(HP2);
    }
    else
    {
        EXP1 = lamtron((double)EXP1 * 1.12);
        dieukien_EXP(EXP1);
        HP1 = lamtron((double)HP1 * 1.1);
        dieukien_HP(HP1);
        EXP2 = lamtron((double)EXP2 * 1.12);
        dieukien_EXP(EXP2);
        HP2 = lamtron((double)HP2 * 1.1);
        dieukien_HP(HP2);
    }
    if (abs(taxi[x][y]) > abs(nguoi[x][y]))
        return taxi[x][y];
    else
        return nguoi[x][y];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string Email = email, S = s;
    int passwordLength = (int)S.length();
    int a[5] = { 0 };
    string se = Email.substr(0, Email.find('@'));
    if (passwordLength >= 8 && passwordLength <= 20)
        a[0] = 1;
    if (S.find(se) == string::npos)
    {
        a[1] = 1;
    }
    for (int i = 0; i < passwordLength - 2; i++) {
        if (S[i] == S[i + 1] && S[i] == S[i + 2])
            break;
        if (i == (passwordLength - 3))
            a[2] = 1;
    }
    for (int i = 0; i < passwordLength; i++)
    {
        if (S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!')
            a[3] = 1;
    }
    for (int i = 0; i < passwordLength; i++)
    {
        if ((S[i] >= 0 && S[i] <= 32) || (S[i] >= 38 && S[i] <= 47) || (S[i] >= 58 && S[i] <= 63) || S[i] == 34 || (S[i] >= 91 && S[i] <= 96) || S[i] >= 123)
        {
            a[4] = 0;
            break;
        }
        a[4] = 1;
    }
    if (a[0] && a[1] && a[2] && a[3] && a[4])
        return -10;
    if (passwordLength < 8)
        return -1;
    if (passwordLength > 20)
        return -2;
    if (S.find(se) != string::npos)
    {
        return  -(300 + (int)S.find(se));
    }
    for (int i = 0; i < passwordLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    for (int i = 0; i < passwordLength; i++)
    {
        if (S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!')
            break;
        if (i == (passwordLength - 1))
            return -5;
    }
    for (int i = 0; i < passwordLength; i++)
    {
        if ((S[i] >= 0 && S[i] <= 32) || (S[i] >= 38 && S[i] <= 47) || (S[i] >= 58 && S[i] <= 63) || S[i] == 34 || (S[i] >= 91 && S[i] <= 96) || S[i] >= 123)
        {
            return i;
        }
    }
    return -999;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    // TODO: Complete this function
    int maxOccurrences = 0;
    int maxLength = 0;
    int correctPasswordIndex = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        if (strcmp(arr_pwds[i], "?/?>::") != 0)
        {
            int currentOccurrences = 1;
            int currentLength = strlen(arr_pwds[i]);

            for (int j = i + 1; j < num_pwds; j++)
            {
                if (strcmp(arr_pwds[j], arr_pwds[i]) == 0)
                {
                    currentOccurrences++;
                    arr_pwds[j] = "?/?>::"; // Mark the password as processed
                }
            }

            if (currentOccurrences > maxOccurrences || (currentOccurrences == maxOccurrences && currentLength > maxLength))
            {
                maxOccurrences = currentOccurrences;
                maxLength = currentLength;
                correctPasswordIndex = i;
            }
        }
    }
    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////