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
void fixedvalueexp(int &exp)
{
    if (exp > 600)
        exp = 600;
    if (exp < 0)
        exp = 0;
}
void fixedvaluehp(int &hp)
{
    if (hp > 666)
        hp = 666;
    if (hp < 0)
        hp = 0;
}
void fixedvaluem(int &m)
{
    if (m < 0)
        m = 0;
    if (m > 3000)
        m = 3000;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    // case 1
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    else
    {
        fixedvalueexp(exp1);
        fixedvalueexp(exp2);
        if (0 <= e1 && e1 <= 3)
        {
            if (e1 == 0)
            {
                exp2 += 29;
            }
            if (e1 == 1)
            {
                exp2 += 45;
            }
            if (e1 == 2)
            {
                exp2 += 75;
            }
            if (e1 == 3)
            {
                exp2 += 149;
            }
            fixedvalueexp(exp2);
            int D;
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            {
                float a = exp1 + (D / 200.0);
                exp1 = ceil(a);
                fixedvalueexp(exp1);
            }
            else
            {
                float a = exp1 - (D / 100.0);
                exp1 = ceil(a);
                fixedvalueexp(exp1);
            }
        }
        // case 2
        if (4 <= e1 && e1 <= 99)
        {
            fixedvalueexp(exp1);
            fixedvalueexp(exp2);
            if (4 <= e1 && e1 <= 19)
            {
                float a = exp2 + (e1 / 4.0 + 19);
                exp2 = ceil(a);
                fixedvalueexp(exp2);
            }
            if (20 <= e1 && e1 <= 49)
            {
                float a = exp2 + (e1 / 9.0 + 21);
                exp2 = ceil(a);
                fixedvalueexp(exp2);
            }
            if (50 <= e1 && e1 <= 65)
            {
                float a = exp2 + (e1 / 16.0 + 17);
                exp2 = ceil(a);
                fixedvalueexp(exp2);
            }
            if (66 <= e1 && e1 <= 79)
            {
                float a = exp2 + (e1 / 4.0 + 19);
                exp2 = ceil(a);
                fixedvalueexp(exp2);
                if (exp2 > 200)
                {
                    float a = exp2 + (e1 / 9.0 + 21);
                    exp2 = ceil(a);
                    fixedvalueexp(exp2);
                }
            }
            if (80 <= e1 && e1 <= 99)
            {
                float a = exp2 + (e1 / 4.0 + 19);
                exp2 = ceil(a);
                fixedvalueexp(exp2);
                a = exp2 + (e1 / 9.0 + 21);
                exp2 = ceil(a);
                fixedvalueexp(exp2);
                if (exp2 > 400)
                {
                    float a = exp2 + (e1 / 16.0 + 17);
                    exp2 = ceil(a);
                    fixedvalueexp(exp2);
                    a = exp2 * 1.15;
                    exp2 = ceil(a);
                    fixedvalueexp(exp2);
                }
            }
            exp1 = exp1 - e1;
            fixedvalueexp(exp1);
        }
        fixedvalueexp(exp1);
        fixedvalueexp(exp2);
        return exp1 + exp2;
    }
}
// Task 2
int close1(int n)
{
    int a = sqrt(n);
    int b = sqrt(n) + 1;
    int diff1 = n - a * a;
    int diff2 = b * b - n;
    if (diff1 > diff2)
        n = b * b;
    else
        n = a * a;
    return n;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    else
    {
        fixedvalueexp(EXP1);
        fixedvaluehp(HP1);
        fixedvaluem(M1);
        double P1, P2, P3;
        int S = close1(EXP1);
        if (EXP1 >= S)
            P1 = 1.0;
        else
            P1 = (float)(((float)EXP1 / S) + 80) / 123;
        

        if (E2 % 2 == 0)
        {
            fixedvaluehp(HP1);
            fixedvalueexp(EXP1);
            fixedvaluem(M1);
            if (M1 > 0)
            {
                if (HP1 < 200)
                {
                    float a = HP1 * 1.3;
                    HP1 = ceil(a);
                    M1 -= 150;
                }
                else
                {
                    float a = HP1 * 1.1;
                    HP1 = ceil(a);
                    M1 -= 70;
                }
                fixedvaluehp(HP1);
                fixedvaluem(M1);
            }
            
            if (M1 > 0)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                float a = EXP1 * 1.13;
                EXP1 = ceil(a);
                fixedvalueexp(EXP1);
                fixedvaluem(M1);
            }
            
            if (M1 > 0)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                }
                else
                {
                    M1 -= 120;
                }
                float a = EXP1 * 0.9;
                EXP1 = ceil(a);
                fixedvalueexp(EXP1);
                fixedvaluem(M1);
            }
            
            fixedvalueexp(EXP1);
            fixedvaluem(M1);
            fixedvaluehp(HP1);
        }
        else
        {
            fixedvalueexp(EXP1);
            fixedvaluem(M1);
            fixedvaluehp(HP1);
            int M2 = M1 - (M1 % 2);
            int M = M1;
            
            while ((M - M1) * 2 <= M2 && M1 > 0)
            {
                
                if (HP1 < 200)
                {
                    float a = HP1 * 1.3;
                    HP1 = ceil(a);
                    fixedvaluehp(HP1);
                    M1 -= 150;
                }
                else
                {
                    float a = HP1 * 1.1;
                    HP1 = ceil(a);
                    fixedvaluehp(HP1);
                    M1 -= 70;
                }
                fixedvaluem(M1);

                if (M1 <= 0 || !((M - M1) * 2 <= M2))
                    break;
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                float a = EXP1 * 1.13;
                EXP1 = ceil(a);
                fixedvalueexp(EXP1);
                fixedvaluem(M1);

                if (M1 <= 0 || !((M - M1) * 2 <= M2))
                    break;

                if (EXP1 < 300)
                {
                    M1 -= 100;
                }
                else
                {
                    M1 -= 120;
                }
                a = EXP1 * 0.9;
                EXP1 = ceil(a);
                fixedvalueexp(EXP1);
                fixedvaluem(M1);

                if (M1 <= 0 || !((M - M1) * 2 <= M2))
                    break;

                fixedvaluem(M1);
            }
            fixedvalueexp(EXP1);
            fixedvaluehp(HP1);
            fixedvaluem(M1);
        }
        fixedvalueexp(EXP1);
        fixedvaluehp(HP1);
        float a = EXP1 * 1.17;
        EXP1 = ceil(a);
        a = HP1 * 0.83;
        HP1 = ceil(a);
        fixedvalueexp(EXP1);
        fixedvaluehp(HP1);

        int b = close1(EXP1);
        if (EXP1 >= b)
        {
            P2 = 1.0;
        }
        else
        {
            P2 = (((float)EXP1 / S) + 80) / 123;
        }

        double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int m = (E2 / 10 + E2 % 10) % 10;
        P3 = P[m] / 100;
        double Pavr = (P1 + P2 + P3) / 3;
        if ((int)P1 == (int)P2 && (int)P2 == (int)P3 && (int)P3 == 1)
        {
            float c = EXP1 * 0.75;
            EXP1 = ceil(c);
            fixedvalueexp(EXP1);
        }
        else
        {
            if (Pavr < 0.5)
            {
                float d = HP1 * 0.85;
                HP1 = ceil(d);
                d = EXP1 * 1.15;
                EXP1 = ceil(d);
                fixedvalueexp(EXP1);
                fixedvaluehp(HP1);
            }
            else
            {
                float e = HP1 * 0.9;
                HP1 = ceil(e);
                e = EXP1 * 1.2;
                EXP1 = ceil(e);
                fixedvalueexp(EXP1);
                fixedvaluehp(HP1);
            }
            fixedvalueexp(EXP1);
            fixedvaluehp(HP1);
            fixedvaluem(M1);
        }
    }
    fixedvalueexp(EXP1);
    fixedvaluehp(HP1);
    fixedvaluem(M1);
    return HP1 + EXP1 + M1;
}
// Task 3

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99 )
    return -99;
    fixedvalueexp(EXP1);
    fixedvalueexp(EXP2);
    fixedvaluehp(HP1);
    fixedvaluehp(HP2);
    int tx[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            tx[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }
    int big = E3 * 2;
    int small = -E3;
    int bigger = 0;
    int smaller = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (tx[i][j] > big)
            {
                bigger += 1;
            }
            else if (tx[i][j] < small)
                smaller += 1;
        }
    }
    
    while (bigger > 9)
    {
        bigger = bigger / 10 + bigger % 10;
        
    }
    while (smaller > 9)
    {
        smaller = smaller / 10 + smaller % 10;
    }
    int i, j;
    i = bigger;
    j = smaller;
    int tp, sp;
    tp = tx[i][j];
    sp = tx[i][j];
    int ii, jj;
    ii = i;
    jj = j;
    while (i < 9 && j < 9)
    {
        i++;
        j++;
        
    }
    while (i >= 0 && j >= 0)
    {
        
        if (tx[i][j] > sp)
            sp = tx[i][j];
            i--;
            j--;
            
    }
    while (ii >= 0 && jj < 10)
    {
        if (tx[ii][jj] > sp)
        sp = tx[ii][jj];
        ii--;
        jj++;
        
    }
    ii = bigger;
    jj = smaller;
    while (ii < 10 && jj >= 0)
    {
        if (tx[ii][jj] > sp)
        sp = tx[ii][jj];
        ii++;
        jj--;
        
    }
    int c;
    if (abs(tp) <= sp)
    {
        c = sp;
        float d = HP1 * 1.1;
        HP1 = ceil(d);
        fixedvaluehp(HP1);
        d = EXP1* 1.12;
        EXP1 = ceil(d);
        fixedvalueexp(EXP1);
        d = EXP2* 1.12;
        EXP2 = ceil(d);
        d = HP2* 1.1;
        HP2 = ceil(d);
        fixedvaluehp(HP2);
    }
    else
    {
        c = tp;
        float d = HP1 * 0.9;
        HP1 = ceil(d);
        fixedvaluehp(HP1);
        d = EXP1* 0.88;
        EXP1 = ceil(d);
        fixedvalueexp(EXP1);
        d = EXP2* 0.88;
        EXP2 = ceil(d);
        d = HP2* 0.9;
        HP2 = ceil(d);
        fixedvaluehp(HP2);
        fixedvalueexp(EXP1);
        fixedvaluehp(HP1);
        fixedvalueexp(EXP2);
        fixedvaluehp(HP2);
    }
    fixedvaluehp(HP2);
        fixedvalueexp(EXP1);
        fixedvaluehp(HP1);
        fixedvalueexp(EXP2);
    return c;
}

// Task 4
// TODO: Complete this function
int checkPassword(const char *s, const char *email)
{
    // TODO: implement task
   string s1(s) ;
   string mail(email);
   string se ;
   int a = mail.find('@');
   se = mail.substr(0,a);

   int len = s1.length();
   if (len < 8)
   return -1;
   if (len > 20)
   return -2;

   if (s1.find(se)!= string::npos)
   return -(300+s1.find(se));

   for (int i=0; i< len -2; i++)
   {
    if (s1[i] == s1[i+1]&& s1[i+1]==s1[i+2])
    return -(400+i);
   }
bool special = false;
   for (int j = 0; j < len; j++)
   {
     if (s1[j] == '!'|| s1[j] == '@'|| s1[j] == '#' || s1[j] == '$'|| s1[j] == '%')
     {
        special = true;
        break;
     }
   }
   if (!special)
   return -5;

    

   for (int k = 0; k < len; k++){
    char c = s[k];
        if (isdigit(c))
            continue;
        else if (islower(c))
            continue;
        else if (isupper(c))
            continue;
            else if (c == '!'|| c == '@'|| c == '#' || c == '$'|| c == '%')
            continue;
            return k;
   }
   return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_length = 0;
    int max_count = 0;
    int correct_index = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        const char *pwd = arr_pwds[i];

        int count = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(pwd, arr_pwds[j]) == 0)
            {
                count++;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            correct_index = i;
        }

        else if (count == max_count)
        {
            int length = strlen(pwd);
            if (length > strlen(arr_pwds[correct_index]))
            {
                max_length = length;
                correct_index = i;
            }
        }
    }

    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////