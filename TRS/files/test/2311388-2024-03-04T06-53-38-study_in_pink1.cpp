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

void checkHP(int& HP)
{
    if (HP > 666)
        HP = 666;
    if (HP < 0)
        HP = 0;
}
void checkEXP(int& EXP1)
{
    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP1 < 0)
        EXP1 = 0;
}
void checkM(int& M1)
{
    if (M1 > 3000)
        M1 = 3000;
    if (M1 < 0)
        M1 = 0;
}

float LuggageChance(int EXP)
{
    int i, S;
    for (i = 1; i <= 25; i++)
        if (i * i <= EXP && EXP <= (i + 1) * (i + 1))
            break;
    if (EXP - i * i < (i + 1) * (i + 1) - EXP)
    {
        S = i * i;
        return 100;
    }
    else
    {
        S = (i + 1) * (i + 1);
        return (EXP / S + 80.0) / 123.0 * 100;
    }

}

int simple(int i)
{
    while (i > 9)
        i = (i % 10) + ((i - (i % 10)) / 10);   //Cong 2 chu so cua i cho den khi chi con 1 chu so
    return i;
}
int score(int map[10][10],int i,int j)
{
    int a, b;
    int max = map[i][j];
    // Tim so lon nhat trong 2 duong cheo di qua map[i][j]
    for ( a = i , b = j ; a <= 9 && b >= 0 ; a++ , b-- )    
    {
        if (max < map[a][b])
            max = map[a][b];
    }
    for (a = i, b = j; a >= 0 && b <= 9; a--, b++)
    {
        if (max < map[a][b])
            max = map[a][b];
    }
    for (a = i, b = j; a >= 0 && b >= 0; a--, b--)
    {
        if (max < map[a][b])
            max = map[a][b];
    }
    for (a = i, b = j; a <= 9 && b <= 9; a++, b++)
    {
        if (max < map[a][b])
            max = map[a][b];
    }
    return max;
}

bool Is_ValidChar(char a)
{
    if (48 <= a && a <= 57) // ki hieu tu 0 den 9
        return true;
    else if (65 <= a && a <= 90)    // ki hieu tu A den Z
        return true;
    else if (97 <= a && a <= 122) // ki hieu tu a den z
        return true;
    else if (a == 33 || a == 35 || a == 36 || a == 37 || a == 64) // ki hieu cua !,#,$,%,@
        return true;
    else
        return false;
}
bool Is_DupStr(const char* s,const char* email, int& e)
{
    int i = 0, j = 0;
    while (i<strlen(s))
    {
       
        if (s[i] != email[j])
        {
            i++;
            j = 0;
        }
        else
        {
            i++;
            j++;
        }
        e = i - j;
        if (email[j]=='@')
            return true;
    }
    return false;

}
bool Is_DupDig(const char* s, int &e)
{
    int i;
    for (i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            e = i;
            return true;

        }
    }
    return false;
}
bool Is_Special(const char* s)
{
    int i;
    for (i = 0; i < strlen(s); i++)
        if (s[i] == 33 || s[i] == 35 || s[i] == 36 || s[i] == 37 || s[i] == 64)
                return true;
    return false;
}
bool Is_ValidPass(const char* s,int &e)
{
    int i;
    for(i=0;i<strlen(s);i++)
        if (!Is_ValidChar(s[i]))
        {
            e = i;
            return false;
        }
    return true;
}

bool Is_SamePass(const char* s, const char* t)
{
    int i;
    if (strlen(s) != strlen(t))
        return false;
    for (i = 0; i < strlen(s); i++)
        if (s[i] != t[i])
            return false;
    return true;
}
int Time_Appear(const char* arr[],int num_pwds, const char* s)
{
    int i, e = 0;
    for (i = 0; i < num_pwds; i++)
        if (Is_SamePass(arr[i], s))
            e++;
    return e;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (0 <= e1 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:exp2 += 29; break;
        case 1:exp2 += 45; break;
        case 2:exp2 += 75; break;
        case 3:exp2 += 29 + 45 + 75; break;
        }
        int d;
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0)
            exp1 = ceil(exp1 + d / 200.0);
        else
            exp1 = ceil(exp1 - d / 100.0);

    }
    else if (4 <= e1 && e1 <= 99)
    {
        if (4 <= e1 && e1 <= 19)
            exp2 += ceil(e1 / 4.0 + 19.0);
        else if (20 <= e1 && e1 <= 49)
            exp2 += ceil(e1 / 9.0 + 21.0);
        else if (50 <= e1 && e1 <= 65)
            exp2 += ceil(e1 / 16.0 + 17.0);
        else if (66 <= e1 && e1 <= 79)
        {
            exp2 += ceil(e1 / 4.0 + 19.0);
            if (exp2 > 200)
                exp2 += ceil(e1 / 9.0 + 21.0);
        }
        else
        {
            exp2 += ceil(e1 / 4.0 + 19.0);
            exp2 += ceil(e1 / 9.0 + 21.0);
            if (exp2 > 400)
                exp2 += ceil(e1 / 16.0 + 17.0);
            exp2 = ceil(exp2 * 1.15);
        }
        exp1 -= e1;
    }
    else
        return -99;
    checkEXP(exp1);
    checkEXP(exp2);
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || 99 < E2)
        return -99;
    // First Road
    float P1, P2, P3;
    int array[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    P1 = LuggageChance(EXP1);

    // Second Road
    float h_M1 = 0.5 * M1;
    if (E2 % 2 != 0)
    {
        while (true)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            }
            checkHP(HP1);
            checkM(M1);
            if (M1 < h_M1)
                break;

            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;
            EXP1 = ceil(EXP1 * 1.13);
            checkHP(HP1);
            checkM(M1);
            if (M1 < h_M1)
                break;

            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;
            EXP1 = ceil(EXP1 * 0.9);
            checkM(M1);
            checkEXP(EXP1);
            if (M1 < h_M1)
                break;
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        checkHP(HP1);
        checkEXP(EXP1);
    }
    else
    {
        if (M1 > 0)
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            }
        if (M1 > 0)
        {
            if (EXP1 < 400)
                M1 -= 200;
            else
                M1 -= 120;
            EXP1 = ceil(EXP1 * 1.13);
        }
        if (M1 > 0)
        {
            if (EXP1 < 300)
                M1 -= 100;
            else
                M1 -= 120;
            EXP1 = ceil(EXP1 * 0.9);
        }
        checkHP(HP1);
        checkEXP(EXP1);
        checkM(M1);
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        checkHP(HP1);
        checkEXP(EXP1);
     
    }
    P2 = LuggageChance(EXP1);

    // Third Road
    if (0 <= E2 && E2 <= 9)
        P3 = array[E2];
    else if (10 <= E2 && E2 <= 99)
    {
        int a;
        a = ((E2 % 10) + ((E2 - (E2 % 10)) / 10)) % 10;
        P3 = array[a];
    }
    else
        return -99;

    // Conclusion
    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = ceil(EXP1 * 0.75);
    else
        P1 = (P1 + P2 + P3) / 3;
    if (P1 < 50)
    {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
    }
    else
    {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil(EXP1 * 1.2);
    }
    checkHP(HP1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || 99 < E3)
        return -99;
    int map[10][10];
    int i, j, meeti = 0, meetj = 0;
    for (i = 0; i <= 9; i++)
        for (j = 0; j <= 9; j++)
        {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > E3 * 2)
                meeti++;
            if (map[i][j] < (-1) * E3)
                meetj++;
        }
    meeti = simple(meeti);
    meetj = simple(meetj);
    i = map[meeti][meetj];  // dung i de lam diem taxi
    j = score(map, meeti, meetj);   // dung j de lam diem Sherlock
    if (abs(i) > abs(j))
    {
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
    }
    else
    {
        EXP1 = ceil(EXP1 * 1.12);
        EXP2 = ceil(EXP2 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
        i = j;
    }
    checkEXP(EXP1); checkEXP(EXP2);
    checkHP(HP1); checkHP(HP2);
    
    return i;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int i;
    if (strlen(s) < 8)
        return -1;
    if (strlen(s) > 20)
        return -2;
    if (Is_DupStr(s, email, i))
        return -(300 + i);
    if (Is_DupDig(s, i))
        return -(400 + i);
    if (!Is_Special(s))
        return -5;
    if (!Is_ValidPass(s, i))
        return i;
    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int i, max=0;
    for (i = 0; i < num_pwds; i++)
    {
        if (Time_Appear(arr_pwds, num_pwds, arr_pwds[i]) > Time_Appear(arr_pwds, num_pwds, arr_pwds[max]))
            max = i;
        if (Time_Appear(arr_pwds, num_pwds, arr_pwds[i]) == Time_Appear(arr_pwds, num_pwds, arr_pwds[max]))
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[max]))
                max = i;
    }

    return max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////