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
void Limit1(int& exp)
{
    if (exp > 600)
        exp = 600;
    if (exp < 0)
        exp = 0;
}
void Limit2(int& hp)
{
    if (hp > 666)
        hp = 666;
    if (hp < 0)
        hp = 0;
}
void Limit3(int& M)
{
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    if (e1 < 0 || e1 > 99)
        return -99;
    if (e1 >= 0 && e1 <= 3)
    {
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = exp1 + ceil(D / 200.0);
            Limit1(exp1);
        }
        else
        {
            exp1 = exp1 - floor(D / 100.0);
            Limit1(exp1);
        }
        if (e1 == 0)
        {
            exp2 = exp2 + 29;
            Limit1(exp2);
        }
        else if (e1 == 1)
        {
            exp2 = exp2 + 45;
            Limit1(exp2);
        }
        else if (e1 == 2)
        {
            exp2 = exp2 + 75;
            Limit1(exp2);
        }
        else if (e1 == 3)
        {
            exp2 = exp2 + 29 + 45 + 75;
            Limit1(exp2);
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        exp1 = exp1 - e1;
        Limit1(exp1);
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            Limit1(exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = exp2 + ceil(e1 / 9.0) + 21;
            Limit1(exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = exp2 + ceil(e1 / 16.0) + 17;
            Limit1(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            Limit1(exp2);
            if (exp2 > 200)
            {
                exp2 = exp2 + ceil(e1 / 9.0) + 21;
                Limit1(exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            Limit1(exp2);
            exp2 = exp2 + ceil(e1 / 9.0) + 21;
            Limit1(exp2);
            if (exp2 > 400)
            {
                exp2 = exp2 + ceil(e1 / 16.0) + 17;
                Limit1(exp2);
                exp2 = exp2 + ceil(exp2 * 0.15);
                Limit1(exp2);
            }
        }
    }
    
    return exp1 + exp2;
}

// Task 2
void FOOD(int& HPa, int& Ma)
{
    if (HPa < 200)
    {
        HPa = HPa + ceil(HPa * 0.3);
        Limit2(HPa);
        Ma = Ma - 150;
        Limit3(Ma);
    }
    else
    {
        HPa = HPa + ceil(HPa / 10.0);
        Limit2(HPa);
        Ma = Ma - 70;
        Limit3(Ma);
    }
}
void TRANSPORT(int& EXPb, int& Mb)
{
    if (EXPb < 400)
    {
        Mb = Mb - 200;
        Limit3(Mb);
    }
    else
    {
        Mb = Mb - 120;
        Limit3(Mb);
    }
    EXPb = EXPb + ceil(EXPb * 0.13);
    Limit1(EXPb);

}
void INSTRUCT(int& EXPc, int& Mc)
{
    if (EXPc < 300)
    {
        Mc = Mc - 100;
        Limit3(Mc);
    }
    else
    {
        Mc = Mc - 120;
        Limit3(Mc);
    }
    EXPc = ceil(EXPc * 0.9);
    Limit1(EXPc);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double S = 25;
    double S1 = 25;
    double M3 = M1 / 2.0;
    double P1, P2, P3, P;
    if (E2 < 0 || E2>99)
        return -99;
    while (S * S > EXP1)
    {
        S = S - 1;
    }
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1)
        P1 = 100;
    else
        P1 = ((EXP1 / (S + 1)) + 80) / 123 * 100;
    if (E2 % 2 != 0)
    {
        while (M1 > M3)
        {
            FOOD(HP1, M1);
            if (M1 < M3)
                break;
            TRANSPORT(EXP1, M1);
            if (M1 < M3)
                break;
            INSTRUCT(EXP1, M1);
            if (M1 < M3)
                break;
        }
        HP1 = ceil(HP1 * 83 / 100.0);
        Limit2(HP1);
        EXP1 = ceil(EXP1 * 117 / 100.0);
        Limit1(EXP1);
    }
    else
    {
        FOOD(HP1, M1);
        if (M1 > 0)
        {
            TRANSPORT(EXP1, M1);
            if (M1 > 0)
            {
                INSTRUCT(EXP1, M1);
                HP1 = ceil(HP1 * 83 / 100.0);
                Limit2(HP1);
                EXP1 = ceil(EXP1 * 117 / 100.0);
                Limit1(EXP1);
            }
            else
            {
                HP1 = ceil(HP1 * 83 / 100.0);
                Limit2(HP1);
                EXP1 = ceil(EXP1 * 117 / 100.0);
                Limit1(EXP1);
            }
        }
        else
        {
            HP1 = ceil(HP1 * 83 / 100.0);
            Limit2(HP1);
            EXP1 = ceil(EXP1 * 117 / 100.0);
            Limit1(EXP1);
        }
    }
    while (S1 * S1 > EXP1)
    {
        S1 = S1 - 1;
    }
    if (EXP1 - S1 * S1 < (S1 + 1) * (S1 + 1) - EXP1)
        P2 = 100;
    else
    {
        P2 = ((EXP1 / (S1 + 1)) + 80) / 123 * 100;
    }

    int a[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 >= 0 && E2 <= 9)
        P3 = a[E2];
    else
        if (E2 >= 10 && E2 <= 99)
        {
            if ((E2 / 10 + (E2 % 10) >= 0) && (E2 / 10 + (E2 % 10) <= 9))
                P3 = a[E2 / 10 + (E2 % 10)];
            else
                if ((E2 / 10 + (E2 % 10) >= 10) && (E2 / 10 + (E2 % 10) <= 18))
                    P3 = a[(E2 / 10 + (E2 % 10)) % 10];
        }
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(EXP1 * 3 / 4.0);
        Limit1(EXP1);
    }
    else
    {
        P = (P1 + P2 + P3) / 3.0;
        if (P < 50)
        {
            HP1 = ceil(HP1 * 85 / 100.0);
            Limit2(HP1);
            EXP1 = EXP1 + ceil(EXP1 * 0.15);
            Limit1(EXP1);
        }
        else
        {
            HP1 = ceil(HP1 * 90 / 100.0);
            Limit2(HP1);
            EXP1 = EXP1 + ceil(EXP1 / 5.0);
            Limit1(EXP1);
        }


    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a[10][10];
    int count = 0;
    int count1 = 0;
    int taxi, f, g, sherlock;
    if (E3 < 0 || E3 > 99)
        return -99;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > E3 * 2)
                count = count + 1;
            if (a[i][j] < (-1) * E3)
                count1 = count1 + 1;
        }
    if (count >= 0 && count <= 9)
        f = count;
    else
        if ((count / 10 + (count % 10)) >= 0 && (count / 10 + (count % 10)) <= 9)
            f = count / 10 + (count % 10);
        else
            f = count / 10 + (count % 10) - 9;

    if (count1 >= 0 && count1 <= 9)
        g = count1;
    else
        if ((count1 / 10 + (count1 % 10)) >= 0 && (count1 / 10 + (count1 % 10)) <= 9)
            g = count1 / 10 + (count1 % 10);
        else
            g = (count1 / 10 + (count1 % 10)) - 9;
    taxi = a[f][g];
    sherlock = a[f][g];
    for (int i = f, j = g; i < 10 && j < 10; i++, j++)
        if (a[i][j] > sherlock)
            sherlock = a[i][j];
    for (int i = f, j = g; i >= 0 && j >= 0; i--, j--)
        if (a[i][j] > sherlock)
            sherlock = a[i][j];
    for (int i = f, j = g; i >= 0 && j < 10; i--, j++)
        if (a[i][j] > sherlock)
            sherlock = a[i][j];
    for (int i = f, j = g; i < 10 && j >= 0; i++, j--)
        if (a[i][j] > sherlock)
            sherlock = a[i][j];
    if (abs(sherlock) >= abs(taxi))
    {
        EXP1 = EXP1 + ceil(EXP1 * 0.12);
        Limit1(EXP1);
        EXP2 = EXP2 + ceil(EXP2 * 0.12);
        Limit1(EXP2);
        HP1 = HP1 + ceil(HP1 * 0.1);
        Limit2(HP1);
        HP2 = HP2 + ceil(HP2 * 0.1);
        Limit2(HP2);

        return sherlock;
    }
    else
    {
        EXP1 = ceil(EXP1 * 88 / 100.0);
        Limit1(EXP1);
        EXP2 = ceil(EXP2 * 88 / 100.0);
        Limit1(EXP2);
        HP1 = ceil(HP1 * 90 / 100.0);
        Limit2(HP1);
        HP2 = ceil(HP2 * 90 / 100.0);
        Limit2(HP1);
        return taxi;
    }

}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int counta = 0;
    int countb = 0;
    char* pass = NULL;
    pass = (char*)s;
    char se[101];
    int n = 0;
    int m;
    while (email[n] != '@')
    {
        se[n] = email[n];
        n++;
    }
    se[n] = '\0';
    if (strlen(pass) < 8)
        return -1;
    else if (strlen(pass) > 20)
        return -2;

    if (strstr(pass, se) != NULL)
        {
            for (int i = 0; i < strlen(pass); i++)
            {
                if (strncmp(pass + i, se, n) == 0)
                {
                    m = i;
                    break;
                }
            }
            return -(300 + m);
        }
    for (int i = 0; i < strlen(pass) - 2; i++)
    {
        if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2])
            return -(400 + i);
    }

    for (int i = 0; i < strlen(pass); i++)
    {
        if (pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '!' || pass[i] == '%')
            counta = counta + 1;     
    }
    if (counta == 0)
        return -5;
    for (int i = 0; i < strlen(pass); i++)
    {
        if ((pass[i] >= '0' && pass[i] <= '9') || (pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z') || pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '!' || pass[i] == '%')
            continue;
        else
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string A[num_pwds];
    int B[num_pwds];
    int C[num_pwds];
    int count_max = 0;
    int length_max = 0;
    int pos;
    for (int i = 0; i < num_pwds; i++)
        B[i] = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        A[i] = arr_pwds[i];
        C[i] = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++)
        {
            if (A[i] == A[j])
                B[j] = B[j] + 1;
        }
    }
    for (int i = 0; i < num_pwds; i++)
        if (B[i] > count_max || (B[i] == count_max && C[i] > length_max))
        {
            count_max = B[i];
            length_max = C[i];
            pos = i;
        }

    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////