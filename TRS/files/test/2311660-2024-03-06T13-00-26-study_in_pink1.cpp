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
)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
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

int cong(int in, float in2, int type)
{
    float sum;
    int out;
    sum = in + in2;
    if (sum - (int)sum >0)
        out = (int)sum + 1;
    else
        out = (int)sum;
    switch (type)
    {
    case 0:
        return out;
        break;
    case 1:
        if (out > 666) out = 666;
        if (out < 0) out = 0;
        return out;
        break;
    case 2:
        if (out > 600) out = 600;
        if (out < 0) out = 0;
        return out;
        break;
    case 3:
        if (out > 3000) out = 3000;
        if (out < 0) out = 0;
        return out;
        break;
    }
    return out;
}
int nhan(int in, float in2, int type)
{
    float sum;
    int out;
    sum = in * in2;
    if (sum - (int)sum >0)
        out = (int)sum + 1;
    else
        out = (int)sum;
    switch (type)
    {
    case 0:
        return out;
        break;
    case 1: // hp
        if (out > 666) out = 666;
        if (out < 0) out = 0;
        return out;
        break;
    case 2: // exp
        if (out > 600) out = 600;
        if (out < 0) out = 0;
        return out;
        break;
    case 3: // money
        if (out > 3000) out = 3000;
        if (out < 0) out = 0;
        return out;
        break;
    }
    return out;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    int D;
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 = cong(exp2, 29, 2);
            break;
        case 1:
            exp2 = cong(exp2, 45, 2);
            break;
        case 2:
            exp2 = cong(exp2, 75, 2);
            break;
        case 3:
            exp2 = cong(exp2, 29 + 45 + 75, 2);
            break;
        }
        D = (e1 * 3) + (exp1 * 7);
        if(D%2==0)
        {
            exp1 = cong(exp1, ((float)D/200), 2);
        }
        else
        {
            exp1 = cong(exp1, -((float)D / 100), 2);
        }
    }
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = cong(exp2, ((float)e1 / 4 + 19), 2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = cong(exp2, ((float)e1 / 9 + 21), 2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = cong(exp2, ((float)e1 / 16 + 17), 2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = cong(exp2, ((float)e1 / 4 + 19), 2);
            if (exp2 > 200)
            {
                exp2 = cong(exp2, ((float)e1 / 9 + 21), 2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = cong(exp2, ((float)e1 / 4 + 19), 2);
            exp2 = cong(exp2, ((float)e1 / 9 + 21), 2);
            if (exp2 > 400)
            {
                exp2 = cong(exp2, ((float)e1 / 16 + 17), 2);
                exp2 = nhan(exp2, 1.15, 2);
            }
        }
        exp1 = cong(exp1, -e1, 2);
    }
    if(e1>99||e1<0)
    {
        return -99;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    // TODO: Complete this function
    float p1, p2, p3 =0.0;
    for (int i = 0; i < 25; i++) // xac suat P1
    {
        if (i * i<=EXP1 && (i + 1) * (i + 1)>EXP1)
        {
            if (EXP1 - (i * i) < (i + 1) * (i + 1) - EXP1)
            {
                p1 = 1;
                break;
            }
            else
            {
                p1 = (float)((EXP1 / ((i + 1) * (i + 1))) + 80) / 123;
                break;
            }
        }
    }
    if (E2 % 2 != 0)
    {
        if (M1 == 0)
        {
            goto end2;
        }
        int TM = M1;
        while (M1 >= TM / 2)
        {
            if (HP1 < 200)
            {
                HP1 = nhan(HP1, 1.3, 1);
                M1 = cong(M1, -150, 3);
            }
            else
            {
                HP1 = nhan(HP1, 1.1, 1);
                M1 = cong(M1, -70, 3);
            }
            if (M1 < TM / 2)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 = cong(M1, -200, 3);
            }
            else
            {
                M1 = cong(M1, -120, 3);
            }
            EXP1 = nhan(EXP1, 1.13, 2);
            if (M1 < TM / 2)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 = cong(M1, -100, 3);
            }
            else
            {
                M1 = cong(M1, -120, 3);
            }
            EXP1 = nhan(EXP1, 0.9, 2);
        }
        HP1 = nhan(HP1, 0.83, 1);
        EXP1 = nhan(EXP1, 1.17, 2);
    }
    else
    {
        if (M1 == 0)
        {
            goto end2;
        }
        if (HP1 < 200)
        {
            HP1 = nhan(HP1, 1.3, 1);
            M1 = cong(M1, -150, 3);
        }
        else
        {
            HP1 = nhan(HP1, 1.1, 1);
            M1 = cong(M1, -70, 3);
        }
        if (M1 == 0)
        {
            goto end2;
        }
        if (EXP1 < 400)
        {
            M1 = cong(M1, -200, 3);
        }
        else
        {
            M1 = cong(M1, -120, 3);
        }
        EXP1 = nhan(EXP1, 1.13, 2);
        if (M1 == 0)
        {
            goto end2;
        }
        if (EXP1 < 300)
        {
            M1 = cong(M1, -100, 3);
        }
        else
        {
            M1 = cong(M1, -120, 3);
        }
        EXP1 = nhan(EXP1, 0.9, 2);
end2:
        HP1 = nhan(HP1, 0.83, 1);
        EXP1 = nhan(EXP1, 1.17, 2);
    }
    for (int i = 0; i < 25; i++) // xac suat P2
    {
        if (i * i<=EXP1 && (i + 1) * (i + 1)>EXP1)
        {
            if (EXP1 - (i * i) < (i + 1) * (i + 1) - EXP1)
            {
                p2 = 1;
                break;
            }
            else
            {
                p2 = (float)(((float)EXP1 / ((i + 1) * (i + 1))) + 80) / 123;
                break;
            }
        }
    }
    int pr[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10 && E2 >= 0)
    {
        p3 = (float)pr[E2]/100;
    }
    if (E2 < 100 && E2>9)
    {
        int j = (int)(E2 / 10);
        int i = j + E2 - j * 10;
        if (i > 9)
        {
            i = i - 10;
        }
        p3 = (float)pr[i]/100;
    }
    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        EXP1 = nhan(EXP1, 0.75, 2);
    }
    else
    {
        float pp = (p1 + p2 + p3) / 3;
        if (pp < 0.5)
        {
            HP1 = nhan(HP1, 0.85, 1);
            EXP1 = nhan(EXP1, 1.15, 2);
        }
        else
        {
            HP1 = nhan(HP1, 0.9, 1);
            EXP1 = nhan(EXP1, 1.2, 2);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    // TODO: Complete this function
    int taxi[10][10] {};
    int imeet = 0, jmeet = 0;
    int a = 0, b = 0, sh = -1000, abs = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > E3 * 2)
            {
                imeet++;
            }
            if (taxi[i][j] < -E3)
            {
                jmeet++;
            }
        }
    }
    if (imeet > 9)
    {
        imeet = (int)(imeet / 10) - (int)(imeet / 10) * 10 + imeet;
    }
    if (imeet > 9)
    {
        imeet = (int)(imeet / 10) - (int)(imeet / 10) * 10 + imeet;
    }
    if (jmeet > 9)
    {
        jmeet = (int)(jmeet / 10) - (int)(jmeet / 10) * 10 + jmeet;
    }
    if (jmeet > 9)
    {
        jmeet = (int)(jmeet / 10) - (int)(jmeet / 10) * 10 + jmeet;
    }
    a = imeet;
    b = jmeet;
    while (a<10 && a>-1 && b > -1 && b < 10)
    {
        if(taxi[a][b]>sh)
        {
            sh = taxi[a][b];
        }
        a++;
        b++;
    }
    a = imeet;
    b = jmeet;
    while (a<10 && a>-1 && b > -1 && b < 10)
    {
        if (taxi[a][b] > sh)
        {
            sh = taxi[a][b];
        }
        a--;
        b++;
    }
    a = imeet;
    b = jmeet;
    while (a<10 && a>-1 && b > -1 && b < 10)
    {
        if (taxi[a][b] > sh)
        {
            sh = taxi[a][b];
        }
        a++;
        b--;
    }
    a = imeet;
    b = jmeet;
    while (a<10 && a>-1 && b > -1 && b < 10)
    {
        if (taxi[a][b] > sh)
        {
            sh = taxi[a][b];
        }
        a--;
        b--;
    }
    if(taxi[imeet][jmeet]<0)
    {
        abs = -taxi[imeet][jmeet];
    }
    else
    {
        abs = taxi[imeet][jmeet];
    }
    if (sh < abs)
    {
        EXP1 = nhan(EXP1, 0.88, 2);
        EXP2 = nhan(EXP2, 0.88, 2);
        HP1 = nhan(HP1, 0.9, 1);
        HP2 = nhan(HP2, 0.9, 1);
        if(taxi[imeet][jmeet] < 0)
        {
            return taxi[imeet][jmeet];
        }
        else
        {
            return abs;
        }
    }
    else
    {
        EXP1 = nhan(EXP1, 1.12, 2);
        EXP2 = nhan(EXP2, 1.12, 2);
        HP1 = nhan(HP1, 1.1, 1);
        HP2 = nhan(HP2, 1.1, 1);
        return sh;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    // TODO: Complete this function
    bool special = false;
    int sizes = 0;
    while (s[sizes] != '\0')
    {
        sizes++;
    }
    if (sizes < 8)
    {
        return -1;
    }

    if (sizes > 20)
    {
        return -2;
    }
    for (int i = 0; i < sizes; i++)
    {
        if (s[i] == email[0])
        {
            for (int j = 1; j < sizes-1; j++)
            {
                if(email[j]=='@')
                {
                    return -(300+i);
                }
                if (s[i + j] != email[j])
                {
                    break;
                }
                else
                {
                    if(email[j+1]=='@')
                    {
                        return -(300 + i);
                    }
                }
            }
        }
        if (i < sizes-2)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                return -(400 + i);
            }
        }
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            special = true;
        }
    }
    if (special == false)
    {
        return -5;
    }
    else
        return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int word[50] = { 0 };
    int times[50] = { 0 };
    int most=0,lengthx=0,xloc=0,slot=1;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (times[j] == 0)
            {
                word[j] = i;
                times[j]++;
                slot++;
                if (times[j] > most)
                {
                    most = times[j];
                }
                break;
            }
            if (arr_pwds[i] == arr_pwds[word[j]])
            {
                times[j]++;
                if (times[j] > most)
                {
                    most = times[j];
                }
                break;
            }
        }
    }
    for (int j = 0; j < slot; j++)
    {
        if (times[j] == most)
        {
            int size = 0;
            while (arr_pwds[word[j]][size] != '\0')
            {
                size++;
            }
            if (lengthx < size)
            {
                lengthx = size;
                xloc = word[j];
            }

        }
    }
    return xloc;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
