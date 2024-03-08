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
int compareStrings(const char *a, const char *b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a != *b)
        {
            return 0; // Chuỗi khác nhau
        }
        a++;
        b++;
    }

    // Khi cả hai chuỗi đều đã kết thúc (\0) và không có sự khác biệt nào
    if (*a == '\0' && *b == '\0')
    {
        return 1; // Chuỗi giống nhau
    }
    else
    {
        return 0; // Một trong hai chuỗi vẫn chưa kết thúc
    }
}

// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{

    if (E1 >= 0 && E1 <= 3)
    {
        if (E1 == 0)
        {
            EXP2 += 29;
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
        }
        else if (E1 == 2)
        {
            EXP2 += 75;
        }
        else
        {
            EXP2 = EXP2 + (29 + 45 + 75);
        }
        int D = E1 * 3 + EXP1 * 7;
        int I = D % 2;
        if (I == 0)
        {
            EXP1 = ceil(EXP1 + (D / 200.0));
        }
        else
        {
            EXP1 = ceil(EXP1 - (D / 100.0));
        }
    }
    else if (E1 >= 4 && E1 <= 99)
    {
        if (E1 >= 4 && E1 <= 19)
        {
            EXP2 += ceil(E1 / 4.0 + 19);
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 += ceil(E1 / 9.0 + 21);
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 += ceil(E1 / 16.0 + 17);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = ceil(EXP2 + (E1 / 4.0 + 19));
            if (EXP2 <= 200)
            {
                EXP2 = 0 + EXP2;
            }
            else
            {
                EXP2 = ceil(EXP2 + (E1 / 9.0 + 21));
            }
        }
        else
        {

            EXP2 = ceil(EXP2 + (E1 / 4.0) + 19);
            EXP2 = ceil(EXP2 + (E1 / 9.0) + 21);
            if (EXP2 <= 400)
            {
                EXP2 = 0 + EXP2;
            }
            else
            {
                EXP2 = ceil(EXP2 + (E1 / 16.0 + 17));
                EXP2 = ceil(EXP2 * 1.15);
            }
        }
        EXP1 -= E1;
    }
    else
        return -99;
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 >= 0 && EXP1 <= 600)
    {
        EXP1 = 0 + EXP1;
    }
    else
    {
        EXP1 = 0;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    else if (EXP2 >= 0 && EXP2 <= 600)
    {
        EXP2 = 0 + EXP2;
    }
    else
    {
        EXP2 = 0;
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 > 99 || E2 < 0)
    {
        return -99;
    }
    int n1 = floor(sqrt(EXP1));
    int n2 = abs(EXP1 - (n1 * n1));
    int n3 = abs((n1 + 1) * (n1 + 1) - EXP1);
    int s;
    if (n2 < n3)
    {
        s = n1 * n1;
    }
    else
    {
        s = (n1 + 1) * (n1 + 1);
    }
    float p1, p2;
    if (EXP1 >= s)
    {
        p1 = 1;
    }
    else
    {
        p1 = ((float(EXP1) / s) + 80.0) / 123.0;
    }
    if(M1==0)
    {
        p1;
        HP1=ceil(HP1*0.83);
        EXP1=ceil(EXP1*1.17);
        int na = floor(sqrt(EXP1));
    int nb = abs(EXP1 - na * na);
    int nc = abs((na + 1) * (na + 1) - EXP1);
    int ss;
    if (nb < nc)
    {
        ss = na * na;
    }
    else
    {
        ss = (na + 1) * (na + 1);
    }

    if (EXP1 >= ss)
    {
        p2 = 1;
    }
    else
    {
        p2 = ((float(EXP1) / ss) + 80.0) / 123.0;
    }
    float P[] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.50, 0.22, 0.83, 0.64, 0.11};
    float rye2;
    if (E2 < 10 && E2 >= 0)
    {
        rye2 = P[E2];
    }
    else if (E2 >= 10 && E2 <= 99)
    {
        E2 = ((((E2 % 100) / 10) + ((E2 % 100) % 10)) % 100) % 10;
        rye2 = P[E2];
    }
     if (p1 == 1 && p2 == 1 && rye2 == 1)
    {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else
    {
        float pp = (p1 + p2 + rye2) / 3;
        if (pp < 0.50)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else
        {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    if (HP1 >= 666)
    {
        HP1 = 666;
    }
    else if (HP1 > 0 && HP1 < 666)
    {
        HP1 = 0 + HP1;
    }
    else
    {
        HP1 = 0;
    }
    if (EXP1 >= 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 > 0 && EXP1 < 600)
    {
        EXP1 = 0 + EXP1;
    }
    else
    {
        EXP1 = 0;
    }
    return HP1+EXP1+M1;
    }
    float div = M1 * 0.5;
    if (E2 % 2 == 0)
    {
        for (int i = 0; i < 1; i++)
        {
            if (HP1 < 200)
            {
                HP1 = ceil((int)HP1 * 13.0 / 10);
                M1 = M1 - 150;
            }
            else
            {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 = M1 - 70;
            }
            if (M1 >= 3000)
            {
                M1 = 3000;
            }
            else if (M1 > 0 && M1 < 3000)
            {
                M1 = 0 + M1;
            }
            else
            {
                M1 = 0;
            }
            if (M1 == 0)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1 * 1.13);
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 * 1.13);
            }
            if (M1 >= 3000)
            {
                M1 = 3000;
            }
            else if (M1 > 0 && M1 < 3000)
            {
                M1 = 0 + M1;
            }
            else
            {
                M1 = 0;
            }
            if (M1 == 0)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 * 0.9);
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 * 0.9);
            }
            if (M1 >= 3000)
            {
                M1 = 3000;
            }
            else if (M1 > 0 && M1 < 3000)
            {
                M1 = 0 + M1;
            }
            else
            {
                M1 = 0;
            }
            if (M1 == 0)
            {
                break;
            }
        }
        if (HP1 >= 666)
        {
            HP1 = 666;
        }
        else if (HP1 > 0 && HP1 < 666)
        {
            HP1 = 0 + HP1;
        }
        else
        {
            HP1 = 0;
        }
        if (EXP1 >= 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 > 0 && EXP1 < 600)
        {
            EXP1 = 0 + EXP1;
        }
        else
        {
            EXP1 = 0;
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    }

    else
    {
        int tien1 = 0;
        for (int i = 0; i < 20; i++)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + 0.3 * HP1);
                M1 = M1 - 150;
                tien1 += 150;
            }
            else
            {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 = M1 - 70;
                tien1 += 70;
            }
            if (tien1 > div)
            {
                break;
            }
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1 * 1.13);
                tien1 += 200;
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 * 1.13);
                tien1 += 120;
            }
            if (tien1 > div)
            {
                break;
            }
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 * 0.9);
                tien1 += 100;
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 * 0.9);
                tien1 += 120;
            }
            if (tien1 > div)
            {
                break;
            }
        }
        if (HP1 >= 666)
        {
            HP1 = 666;
        }
        else if (HP1 > 0 && HP1 < 666)
        {
            HP1 = 0 + HP1;
        }
        else
        {
            HP1 = 0;
        }
        if (EXP1 >= 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 > 0 && EXP1 < 600)
        {
            EXP1 = 0 + EXP1;
        }
        else
        {
            EXP1 = 0;
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    }
    if (HP1 >= 666)
    {
        HP1 = 666;
    }
    else if (HP1 > 0 && HP1 < 666)
    {
        HP1 = 0 + HP1;
    }
    else
    {
        HP1 = 0;
    }
    if (EXP1 >= 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 > 0 && EXP1 < 600)
    {
        EXP1 = 0 + EXP1;
    }
    else
    {
        EXP1 = 0;
    }
    if (M1 >= 3000)
    {
        M1 = 3000;
    }
    else if (M1 > 0 && M1 < 3000)
    {
        M1 = 0 + M1;
    }
    else
    {
        M1 = 0;
    }

    int n11 = floor(sqrt(EXP1));
    int n22 = abs(EXP1 - n11 * n11);
    int n33 = abs((n11 + 1) * (n11 + 1) - EXP1);
    int s2;
    if (n22 < n33)
    {
        s2 = n11 * n11;
    }
    else
    {
        s2 = (n11 + 1) * (n11 + 1);
    }

    if (EXP1 >= s2)
    {
        p2 = 1;
    }
    else
    {
        p2 = ((float(EXP1) / s2) + 80.0) / 123.0;
    }

    float P[] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.50, 0.22, 0.83, 0.64, 0.11};
    float rye;
    if (E2 < 10 && E2 >= 0)
    {
        rye = P[E2];
    }
    else if (E2 >= 10 && E2 <= 99)
    {
        E2 = ((((E2 % 100) / 10) + ((E2 % 100) % 10)) % 100) % 10;
        rye = P[E2];
    }
    if (p1 == 1 && p2 == 1 && rye == 1)
    {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else
    {
        float pp = (p1 + p2 + rye) / 3;
        if (pp < 0.50)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else
        {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    if (HP1 >= 666)
    {
        HP1 = 666;
    }
    else if (HP1 > 0 && HP1 < 666)
    {
        HP1 = 0 + HP1;
    }
    else
    {
        HP1 = 0;
    }
    if (EXP1 >= 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 > 0 && EXP1 < 600)
    {
        EXP1 = 0 + EXP1;
    }
    else
    {
        EXP1 = 0;
    }
    if (M1 >= 3000)
    {
        M1 = 3000;
    }
    else if (M1 > 0 && M1 < 3000)
    {
        M1 = 0 + M1;
    }
    else
    {
        M1 = 0;
    }
    return EXP1 + M1 + HP1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 > 99 || E3 < 0)
    {
        return -99;
    }

    const int hang = 10;
    const int cot = 10;
    int a[hang][cot];
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }}
    int count1 = 0;
    int ss = E3 * 2;
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] > ss)
                count1++;
        }
    }
    int i1 = (count1 / 10) + (count1 % 10);
    if (i1 >= 10)
    {
        i1 = (i1 / 10) + (i1 % 10);
    }
    int count2 = 0;
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            if (a[i][j] < -(E3))
                count2++;
        }
    }
    int j1 = (count2 / 10) + (count2 % 10);
    if (j1 >= 10)
    {
        j1 = (j1 / 10) + (j1 % 10);
    }
    int max=a[i1][j1];
   //hướng phải lên
for (int i = i1, j = j1; i >= 0 && j < 10; --i, ++j) 
    {
        if (a[i][j] > max) 
        {
            max = a[i][j];
        }
    }

    // hướng trái lên
    for (int i = i1, j = j1; i >= 0 && j >= 0; --i, --j) 
    {
        if (a[i][j] > max) 
        {
            max = a[i][j];
        }
    }

    // hướng trái xuống
    for (int i = i1, j = j1; i < 10 && j >= 0; ++i, --j) 
    {
        if (a[i][j] > max) 
        {
            max = a[i][j];
        }
    }

    // hướng phải dưới
    for (int i = i1, j = j1; i < 10 && j < 10; ++i, ++j) 
    {
        if (a[i][j] > max) 
        {
            max = a[i][j];
        }
    }

        int coup=max;
    int xe = ((E3 * j1) + (i1 * 2)) * (i1 - j1);

    if (abs(xe) > coup)
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        if (HP1 >= 666)
        {
            HP1 = 666;
        }
        else if (HP1 > 0 && HP1 < 666)
        {
            HP1 = 0 + HP1;
        }
        else
        {
            HP1 = 0;
        }
        if (EXP1 >= 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 > 0 && EXP1 < 600)
        {
            EXP1 = 0 + EXP1;
        }
        else
        {
            EXP1 = 0;
        }
        if (HP2 >= 666)
        {
            HP2 = 666;
        }
        else if (HP2 > 0 && HP2 < 666)
        {
            HP2 = 0 + HP2;
        }
        else
        {
            HP2 = 0;
        }
        if (EXP2 >= 600)
        {
            EXP2 = 600;
        }
        else if (EXP2 > 0 && EXP2 < 600)
        {
            EXP2 = 0 + EXP2;
        }
        else
        {
            EXP2 = 0;
        }
        return xe;
    }
    else
    {
        EXP1 = ceil(EXP1 +0.12*EXP1);
        HP1 = ceil(HP1 + 0.1 * HP1);
        EXP2 = ceil(EXP2 + 0.12*EXP2);
        HP2 = ceil(HP2 + 0.1 * HP2);
        if (HP1 >= 666)
        {
            HP1 = 666;
        }
        else if (HP1 > 0 && HP1 < 666)
        {
            HP1 = 0 + HP1;
        }
        else
        {
            HP1 = 0;
        }
        if (EXP1 >= 600)
        {
            EXP1 = 600;
        }
        else if (EXP1 > 0 && EXP1 < 600)
        {
            EXP1 = 0 + EXP1;
        }
        else
        {
            EXP1 = 0;
        }
        if (HP2 >= 666)
        {
            HP2 = 666;
        }
        else if (HP2 > 0 && HP2 < 666)
        {
            HP2 = 0 + HP2;
        }
        else
        {
            HP2 = 0;
        }
        if (EXP2 >= 600)
        {
            EXP2 = 600;
        }
        else if (EXP2 > 0 && EXP2 < 600)
        {
            EXP2 = 0 + EXP2;
        }
        else
        {
            EXP2 = 0;
        }
        return coup;
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    char se[101];
    const char *a = strchr(email, '@');
    if (a != nullptr)
    {
        int lenght1 = (a - email);

        strncpy(se, email, (lenght1));
        se[lenght1] = '\0';
    }

    int length = strlen(s);
    if (length < 8)
    {
        return -1;
    }
    if (length > 20)
    {
        return -2;
    }
    const char *b = strstr(s, se);
    if (b != nullptr)
    {
        return -(300 + (b - s));
    }
    for (int i = 0; i < length - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    bool check = 1;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            check = 0;
        }
    }
    if (check == 1)
    {
        return -5;
    }

    bool check1;
    for (int i = 0; i < length; i++)
    {

        if ((s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            check1 = 1;
            continue;
        }
        else
        {
            check1 = 0;
            return i;
        }
    }
    if (check1 == 1)
    {
        return -10;
    }
    return -1;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max = -1;
    int position =0;
    for (int i = 0; i < num_pwds; ++i)
    {

        int frequency = 0;
        for (int j = 0; j < num_pwds; ++j)
        {

            if (compareStrings(arr_pwds[i], arr_pwds[j]))
            {
                frequency++;
            }
        }

        if (max > frequency)
        {
            max = max;
        }
        else if (max < frequency)
        {
            max = frequency;
            position = i;
        }
        else
        {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[position]))
            {
                position = i;
            }
        }
    }
    return position;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////