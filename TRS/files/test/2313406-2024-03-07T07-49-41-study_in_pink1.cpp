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

int check(int x, int min, int max) 
{
    x = (x < min) ? min : (x > max) ? max : x;
    return x;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    exp1 = check(exp1, 0, 600);
    exp2 = check(exp2, 0, 600);

    if (e1 >= 0 && e1 <= 3)
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
            exp1 = ceil(exp1 + (D * 1.00 / 200));
        }
        else
        {
            exp1 = ceil(exp1 - (D * 1.00 / 100));
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + ((e1 * 1.00 / 4) + 19));
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + ((e1 * 1.00 / 9) + 21));
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + ((e1 * 1.00 / 16) + 17));
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + ((e1 * 1.00 / 4) + 19));
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + ((e1 * 1.00 / 9) + 21));
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + ((e1 * 1.00 / 4) + 19));
            exp2 = ceil(exp2 + ((e1 * 1.00 / 9) + 21));
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + ((e1 * 1.00 / 16) + 17));
                exp2 = ceil(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    exp1 = check(exp1, 0, 600);
    exp2 = check(exp2, 0, 600);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);

    double P1, P2, P3, P;
    int S = round(sqrt(EXP1));
    S = S * S;
    if (EXP1 >= S)
    {
        P1 = 1.0;
    }
    else
    {
        P1 = (EXP1 * 1.00 / S + 80) / 123;
    }

    int F1;
    int mstart = M1;
    double m1 = mstart * 0.5;
    if (E2 % 2 != 0)
    {
        while (1)
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
            HP1 = check(HP1, 0, 666);
            M1 = check(M1, 0, 3000);
            F1 = mstart - M1;
            if (F1 > m1)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            F1 = mstart - M1;
            if (F1 > m1)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            F1 = mstart - M1;
            if (F1 > m1)
            {
                break;
            }
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);

        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        M1 = check(M1, 0, 3000);
    }
    else
    {
        while (1)
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
            HP1 = check(HP1, 0, 666);
            M1 = check(M1, 0, 3000);
            if (M1 == 0) 
            {
                break;
            }           
            if (EXP1 < 400)
            {
                M1 -= 200;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            if (M1 == 0) 
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            EXP1 = check(EXP1, 0, 600);
            M1 = check(M1, 0, 3000);
            break;
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);

        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
        M1 = check(M1, 0, 3000);
    }
    int S2 = round(sqrt(EXP1));
    S2 = S2 * S2;
    if (EXP1 >= S2)
    {
        P2 = 1.00;
    }
    else
    {
        P2 = ((EXP1 * 1.00) / S2 + 80) / 123;
    }

    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 / 10 == 0)
    {
        i = E2;
        P3 = p[i];
    }
    else
    {
        E2 = E2 / 10 + E2 % 10;
        i = E2 % 10;
        P3 = p[i];
    }
    P3 = P3/100.0;

    if ((P1 == 1.00) && (P2 == 1.00) && (P3 == 1.00))
    {
        EXP1 = ceil(EXP1 * 0.75);
        EXP1 = check(EXP1, 0, 600);
    }
    else
    {
        P = (P1 + P2 + P3) / 3.0;
        P = (round(P*100.0))*0.01;
        if (P < 0.5)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else
        {
            HP1 = ceil(HP1 * 0.90);
            EXP1 = ceil(EXP1 * 1.20);
        }
        HP1 = check(HP1, 0, 666);
        EXP1 = check(EXP1, 0, 600);
    }
 
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    HP1 = check(HP1, 0, 666);
    HP2 = check(HP2, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    EXP2 = check(EXP2, 0, 600);

    int matrix[10][10];
    int countpos = 0;
    int countneg = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = (E3 * j + i * 2) * (i - j);
            if (matrix[i][j] > E3 * 2)
            {
                countpos++;
            }
            if (matrix[i][j] < -E3)
            {
                countneg++;
            }
        }
    }
    int i = countpos / 10 + countpos % 10;
    i = i / 10 + i % 10;
    int j = countneg / 10 + countneg % 10;
    j = j / 10 + j % 10;
    int taxivalue = matrix[i][j];
    int maxvalue = INT_MIN;

    int row = i;
    int col = j;
    for (int i = row, j = col; (i >= 0) && (i < 10) && (j >= 0) && (j < 10); i++, j++)
    {
        if (matrix[i][j] > maxvalue)
        {
            maxvalue = matrix[i][j];
        }
    }
    for (int i = row, j = col; (i >= 0) && (i < 10) && (j >= 0) && (j < 10); i--, j--)
    {
        if (matrix[i][j] > maxvalue)
        {
            maxvalue = matrix[i][j];
        }
    }
    for (int i = row, j = col; (i >= 0) && (i < 10) && (j >= 0) && (j < 10); i++, j--)
    {
        if (matrix[i][j] > maxvalue)
        {
            maxvalue = matrix[i][j];
        }
    }
    for (int i = row, j = col; (i >= 0) && (i < 10) && (j >= 0) && (j < 10); i--, j++)
    {
        if (matrix[i][j] > maxvalue)
        {
            maxvalue = matrix[i][j];
        }
    }
    int res;
    if (abs(taxivalue) > maxvalue)
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        res = taxivalue;
    }
    else
    {
        EXP1 = ceil(EXP1 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
        res = maxvalue;
    }
    HP1 = check(HP1, 0, 666);
    HP2 = check(HP2, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    EXP2 = check(EXP2, 0, 600);
    return res;

    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // string se(email);
    // se = se.substr(0, se.find('@'));

    // string schars = "@#%$!";
    // bool achar = false;

    // string str(s);

    // if (str.length() < 8)
    //     return -1;
    // if (str.length() > 20)
    //     return -2;
    // if (str.find(se) != string::npos)
    //     return -(300 + str.find(se));

    // for (int i = 0; i < str.length() - 2; i++)
    // {
    //     if (str[i] == str[i + 1] && str[i + 1] == str[i + 2])
    //         return -(400 + i);
    // }

    // for (char c : str)
    // {
    //     if (schars.find(c) != string::npos)
    //     {
    //         achar = true;
    //     }
    //     if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || schars.find(c) != string::npos))
    //     {
    //         return str.find(c);
    //     }
    // }

    // if (!achar)
    //     return -5;

    // return -10;

    // return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{

    int maxcount = 0;
    int maxlength = 0;
    int lct = -1;

    for (int i = 0; i < num_pwds; ++i)
    {
        int count = 0;
        const char *pw = arr_pwds[i];
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(pw, arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        if (count > maxcount || (count == maxcount && strlen(pw) > maxlength))
        {
            maxcount = count;
            maxlength = strlen(pw);
            lct = i;
        }
    }
    return lct;
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////