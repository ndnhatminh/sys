#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &e1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> e1 >> E2 >> E3;
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
void rule1(int &EXP1, int &EXP2)
{
    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                         : EXP1;
    EXP2 = (EXP2 < 0) ? 0 : (EXP2 > 600) ? 600
                                         : EXP2;
}

void rule2(int &HP1, int &EXP1, int &M1)
{
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                      : HP1;
    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                         : EXP1;
    M1 = (M1 < 0) ? 0 : (M1 > 3000) ? 3000
                                    : M1;
}

void exps(int &HP1, int &EXP1, int &M1)
{
    HP1 -= floor(float(0.17 * HP1));
    EXP1 += ceil(float(0.17 * EXP1));
    rule2(HP1, EXP1, M1);
}

void rule3(int &EXP1, int &EXP2, int &HP1, int &HP2)
{
    HP1 = (HP1 < 0) ? 0 : (HP1 > 666) ? 666
                                      : HP1;
    EXP1 = (EXP1 < 0) ? 0 : (EXP1 > 600) ? 600
                                         : EXP1;
    HP2 = (HP2 < 0) ? 0 : (HP2 > 666) ? 666
                                      : HP2;
    EXP2 = (EXP2 < 0) ? 0 : (EXP2 > 600) ? 600
                                         : EXP2;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    float d;
    rule1(exp1, exp2);
    switch (e1)
    {
    case 0 ... 3:
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 149;
        d = e1 * 3 + exp1 * 7;
        if (int(d) % 2 == 0)
            exp1 += ceil(d / 200);
        else
            exp1 -= floor(d / 100);
        break;
    case 4 ... 99:
        d = e1;
        if (e1 < 20)
            exp2 += ceil(d / 4 + 19);
        else if (e1 < 50)
            exp2 += ceil(d / 9 + 21);
        else if (e1 < 66)
            exp2 += ceil(d / 16 + 17);
        else if (e1 < 80)
        {
            exp2 += ceil(d / 4 + 19);
            if (exp2 > 200)
                exp2 += ceil(d / 9 + 21);
        }
        else
        {
            exp2 += ceil(d / 4 + 19);
            exp2 += ceil(d / 9 + 21);
            rule1(exp1, exp2);
            if (exp2 > 400)
            {
                exp2 += ceil(d / 16 + 17);
                exp2 += ceil(0.15 * exp2);
            }
        }
        exp1 -= d;
        break;
    }

    rule1(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    rule2(HP1, EXP1, M1);
    int ar[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, c;
    float p1, p2, p3, p;
    float z = M1 * 0.5, b = 0;
    // con duong 1
    p = round(sqrt(EXP1));
    if (EXP1 >= (p * p))
        p1 = 100;
    else
        p1 = 100 * (EXP1 / (p * p) + 80) / 123;
    // con duong 2
    while (E2 % 2 != 0)
    {
        if (HP1 < 200) // task 2.1.1
        {
            HP1 += ceil(float(0.3 * HP1));
            M1 -= 150;
            b += 150;
        }
        else
        {
            HP1 += ceil(float(0.1 * HP1));
            M1 -= 70;
            b += 70;
        }
        rule2(HP1, EXP1, M1);

        if (b > z) // check 2.1.1
        {
            exps(HP1, EXP1, M1);
            break;
        }
        if (EXP1 < 400) // task 2.1.2
        {
            M1 -= 200;
            b += 200;
            EXP1 += ceil(float(0.13 * EXP1));
        }
        else
        {
            M1 -= 120;
            b += 120;
            EXP1 += ceil(float(0.13 * EXP1));
        }
        rule2(HP1, EXP1, M1);
        if (b > z) // check 2.1.2
        {
            exps(HP1, EXP1, M1);
            break;
        }

        if (EXP1 < 300) // task 2.1.3
        {
            M1 -= 100;
            b += 100;
            EXP1 -= floor(float(0.1 * EXP1));
        }
        else
        {
            M1 -= 120;
            b += 120;
            EXP1 -= floor(float(0.1 * EXP1));
        }
        rule2(HP1, EXP1, M1);
        if (b > z) // check 2.1.3
        {
            exps(HP1, EXP1, M1);
            break;
        }
    }
    while (E2 % 2 == 0)
    {
        if (HP1 < 200) // task 2.2.1
        {
            HP1 += ceil(float(0.3 * HP1));
            M1 -= 150;
        }
        else
        {
            HP1 += ceil(0.1 * HP1);
            M1 -= 70;
        }
        rule2(HP1, EXP1, M1);
        if (M1 == 0) // check 2.2.1
        {
            exps(HP1, EXP1, M1);
            break;
        }

        if (EXP1 < 400) // task 2.2.2
            M1 -= 200;
        else
            M1 -= 120;
        EXP1 += ceil(float(0.13 * EXP1));
        rule2(HP1, EXP1, M1);

        if (M1 == 0) // check 2.2.2
        {
            exps(HP1, EXP1, M1);
            break;
        }

        if (EXP1 < 300) // task 2.2.3
            M1 -= 100;
        else
            M1 -= 120;
        if (M1 == 0) // check 2.2.3
        {
            exps(HP1, EXP1, M1);
            break;
        }
        EXP1 -= floor(float(0.1 * EXP1));
        exps(HP1, EXP1, M1);
        break;
    }
    p = round(sqrt(EXP1));
    if (EXP1 >= (p * p))
        p2 = 100;
    else
        p2 = 100 * (EXP1 / (p * p) + 80) / 123;
    // con duong 3
    if (E2 < 10)
        c = E2;
    else
    {
        c = E2 / 10 + E2 % 10;
        c = c % 10;
    }
    p3 = ar[c];
    // xet xac xuat
    if (p3 == 100 && p2 == 100 && p1 == 100)
        EXP1 -= floor(float(0.25 * EXP1));
    else
    {
        p = (p1 + p2 + p3) / 3;
        if (p <= 50)
        {
            HP1 -= floor(float(0.15 * HP1));
            EXP1 += ceil(float(0.15 * EXP1));
        }
        else
        {
            HP1 -= floor(float(0.1 * HP1));
            EXP1 += ceil(float(0.2 * EXP1));
        }
    }
    rule2(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    rule3(EXP1, EXP2, HP1, HP2);
    int pc[10][10] = {0}, i = 0, j = 0, c = 0, ip, jp, c1;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            pc[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        j = 0;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            if (pc[i][j] > E3 * 2)
                c++;
        j = 0;
    }
    c = ((c / 10) + (c % 10));
    c = ((c / 10) + (c % 10));
    ip = c;
    c = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            if (pc[i][j] < (-1 * E3))
                c++;
        j = 0;
    }
    c = ((c / 10) + (c % 10));
    c = ((c / 10) + (c % 10));
    jp = c;

    if (ip <= jp)
    { // duong cheo chinh
        j = jp - ip;
        i = 0;
    }
    else
    {
        i = ip - jp;
        j = 0;
    }
    c = pc[i][j];
    while (i < 10 && j < 10)
    {
        if (c < pc[i][j])
            c = pc[i][j];
        i++;
        j++;
    }
    c1 = c;
    if ((9 - jp) <= ip)
    { // duong cheo phu
        i = ip - (9 - jp);
        j = 9;
    }
    else
    {
        j = jp + ip;
        i = 0;
    }
    c = pc[i][j];
    while (i < 10 && j >= 0)
    {
        if (c < pc[i][j])
            c = pc[i][j];
        i++;
        j--;
    }
    if (c1 > c)
        c = c1;

    if (abs(pc[ip][jp]) > c)
    {
        HP1 -= floor(float(0.1 * HP1));
        EXP1 -= floor(float(0.12 * EXP1));
        HP2 -= floor(float(0.1 * HP2));
        EXP2 -= floor(float(0.12 * EXP2));
        rule3(EXP1, EXP2, HP1, HP2);
        return pc[ip][jp];
    }
    else
    {
        HP1 += ceil(float(0.1 * HP1));
        EXP1 += ceil(float(0.12 * EXP1));
        HP2 += ceil(float(0.1 * HP2));
        EXP2 += ceil(float(0.12 * EXP2));
        rule3(EXP1, EXP2, HP1, HP2);
        return c;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int c = string(email).find('@');
    string se = string(email, 0, c);
    char e1, e2;
    int str;
    if (string(s).length() < 8) // do dai
        return -1;
    if (string(s).length() > 20)
        return -2;
    if (string(s).find(se) != string::npos) // chua se
        return -(300 + string(s).find(se));
    e2 = string(s)[0]; // 2 ki tu lien tiep
    e1 = string(s)[1];
    for (int z = 2; z < string(s).length(); z++)
    {
        if (string(s)[z] == e1 && e1 == e2)
            return -(400 + z - 2);
        else
        {
            e2 = e1;
            e1 = string(s)[z];
        }
    }
    // ki tu dac biet
    if (string(s).find('@') == string::npos && string(s).find('!') == string::npos && string(s).find('$') == string::npos && string(s).find('%') == string::npos && string(s).find('#') == string::npos)
        return -5;
    for (int z = 0; z < string(s).length(); z++)
    {
        str = string(s)[z];
        if (!((str != 34 && str >= 33 && str <= 37) || (str >= 48 && str <= 57) || (str >= 64 && str <= 90) || (str >= 97 && str <= 122)))
            return z;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int cntn, cnti = 0, pi, i = 0;
    for (i; i < num_pwds; i++)
    {
        cntn = 1;
        for (int z = i + 1; z < num_pwds; z++)
            if (string(arr_pwds[i]) == string(arr_pwds[z]))
                cntn++;
        if (cntn > cnti)
        {
            pi = i;
            cnti = cntn;
        }
        else if (cntn == cnti)
            if (string(arr_pwds[i]).length() > string(arr_pwds[pi]).length())
                pi = i;
    }

    return pi;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////