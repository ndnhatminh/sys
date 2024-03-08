#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
void RoundNumber1(int& exp1, int& exp2)
{

    if (exp1 > 600)
        exp1 = 600;
    else if (exp1 < 0)
        exp1 = 0;

    if (exp2 > 600)
        exp2 = 600;
    else if (exp2 < 0)
        exp2 = 0;
}

int firstMeet(int& exp1, int& exp2, int e1) {
    //case 1
    if (e1 < 0 || e1>99)
        return -99;

    RoundNumber1(exp1, exp2);

    if (0 <= e1 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            RoundNumber1(exp1, exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            RoundNumber1(exp1, exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            RoundNumber1(exp1, exp2);
        }
        else if (e1 == 3)
        {
            exp2 = exp2 + 29 + 45 + 75;
            RoundNumber1(exp1, exp2);
        }

        int D = e1 * 3 + exp1 * 7;
        if ((D % 2) == 0)
        {
            exp1 = ceil(exp1/1.0 + (float(D / 200.0)));
            RoundNumber1(exp1, exp2);
        }
        else if ((D % 2) != 0)
        {
            exp1 = ceil(exp1/1.0 - (float(D / 100.0)));
            RoundNumber1(exp1, exp2);
        }
    }
    //case 2
    else if (4 <= e1 && e1 <= 99)
    {
        if (4 <= e1 && e1 <= 19)
        {
            exp2 = ceil(exp2 + (float(e1 / 4.0) + 19.0));
            RoundNumber1(exp1, exp2);
        }
        else if (20 <= e1 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (float(e1 / 9.0) + 21.0));
            RoundNumber1(exp1, exp2);
        }
        else if (50 <= e1 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (float(e1 / 16.0) + 17.0));
            RoundNumber1(exp1, exp2);
        }
        else if (66 <= e1 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (float(e1 / 4.0) + 19.0));
            RoundNumber1(exp1, exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (float(e1 / 9.0) + 21.0));
                RoundNumber1(exp1, exp2);
            }
        }
        else if (80 <= e1 && e1 <= 99)
        {
            RoundNumber1(exp1, exp2);
            exp2 = ceil(exp2 + (float(e1 / 4.0) + 19.0));
            RoundNumber1(exp1, exp2);
            exp2 = ceil(exp2 + (float(e1 / 9.0) + 21.0));
            RoundNumber1(exp1, exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (float(e1 / 16.0) + 17.0));
                RoundNumber1(exp1, exp2);
                exp2 = ceil(float(exp2 * 1.15));
                RoundNumber1(exp1, exp2);
            }
        }
        exp1 -= e1;
    }
    RoundNumber1(exp1, exp2);
    return exp1 + exp2;
}

// Task 2

    //Function
void RoundNumber2(int& HP1, int& EXP1, int& M1)
{
    if (HP1 > 666)
        HP1 = 666;
    else if (HP1 < 0)
        HP1 = 0;

    if (EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
        EXP1 = 0;

    if (M1 > 3000)
        M1 = 3000;
    else if (M1 < 0)
        M1 = 0;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99)
        return -99;

    RoundNumber2(HP1, EXP1, M1);

    int S=0, m, n;
    m = EXP1;
    n = EXP1;
    //Road 01
       //nearest perfect square
    while ((float(sqrt(m)) != trunc(sqrt(m))))
    {
        m++;
    }
    while ((float(sqrt(n)) != trunc(sqrt(n))))
    {
        n--;
    }
    if ((m - EXP1) > (EXP1 - n))
        S = n;
    else
        S = m;

    //Probability
    double P1;
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (((EXP1 / 1.0) / S) + 80.00) / 123.00;

    //Road 02
    int half = M1 * 0.5;
    int M0 = M1;
    if ((E2 % 2) != 0)
    {
        while ((M0 - M1) <= half)
        {
            //Event 01
            if (HP1 < 200)
            {
                if (M1 == 0)
                {
                    break;
                }
                HP1 = ceil(HP1 * 13.0 / 10.0);
                M1 -= 150;
                RoundNumber2(HP1, EXP1, M1);
            }
            else
            {
                if (M1 == 0)
                {
                    break;
                }
                HP1 = ceil(HP1 * 11.0 / 10.0);
                M1 -= 70;
                RoundNumber2(HP1, EXP1, M1);
            }
            if ((M0 - M1) > half)
                break;

            //Event 02
            if (EXP1 < 400)
            {
                if (M1 == 0)
                {
                    break;
                }
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.13);
                RoundNumber2(HP1, EXP1, M1);
            }
            else
            {
                if (M1 == 0)
                {
                    break;
                }
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.13);
                RoundNumber2(HP1, EXP1, M1);
            }
            if ((M0 - M1) > half)
                break;

            //Event 03
            if (EXP1 < 300)
            {
                if (M1 == 0)
                {
                    break;
                }
                M1 -= 100;
                EXP1 = ceil(EXP1 * 0.9);
                RoundNumber2(HP1, EXP1, M1);
            }
            else
            {
                if (M1 == 0)
                {
                    break;
                }
                M1 -= 120;
                EXP1 = ceil(EXP1 * 0.9);
                RoundNumber2(HP1, EXP1, M1);
            }
            if ((M0 - M1) > half)
                break;
        }
    }
    else
    {
        for (int i = 0; i < 1; i++)
        {
            if (M1 <= 0)
            {
                M1 = 0;
                break;
            }
            //Event 01
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13.0 / 10.0);
                M1 -= 150;
                RoundNumber2(HP1, EXP1, M1);
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10.0);
                M1 -= 70;
                RoundNumber2(HP1, EXP1, M1);
            }
            if (M1 <= 0)
            {
                M1 = 0;
                break;
            }

            //Event 02
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.13);
                RoundNumber2(HP1, EXP1, M1);
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.13);
                RoundNumber2(HP1, EXP1, M1);
            }
            if (M1 <= 0)
            {
                M1 = 0;
                break;
            }

            //Event 03
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 0.9);
                RoundNumber2(HP1, EXP1, M1);
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 0.9);
                RoundNumber2(HP1, EXP1, M1);
            }
            if (M1 <= 0)
            {
                M1 = 0;
                break;
            }
        }
    }
    HP1 = ceil(HP1 * 83.0/100.0); 
    EXP1 = ceil(EXP1 * 117.0/100.0);
    RoundNumber2(HP1, EXP1, M1);

    m = EXP1;
    n = EXP1;
    //nearest perfect square
    while ((float(sqrt(m)) != trunc(sqrt(m))))
    {
        m++;
    }
    while ((float(sqrt(n)) != trunc(sqrt(n))))
    {
        n--;
    }
    if ((m - EXP1) > (EXP1 - n))
        S = n;
    else
        S = m;

    //Probability
    double P2;
    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = (((EXP1 / 1.0) / S) + 80.00) / 123.00;

    //Road 03
    double arrP[] = { 0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11 };
    double P3;
    int tens, units;
    if ((E2 / 10) < 1)
    {
        P3 = arrP[E2];
    }
    else
    {
        tens = E2 / 10;
        units = E2 % 10;
        int sum = tens + units;
        int units_of_sum = sum % 10;
        P3 = arrP[units_of_sum];
    }

    //After 3 Roads
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil(EXP1 * 0.75);
        RoundNumber2(HP1, EXP1, M1);
    }
    else
    {
        double P123 = (P1 + P2 + P3) / 3;
        if (P123 < 0.5)
        {
            HP1 = ceil(HP1 * 85.0/100.0);
            EXP1 = ceil(EXP1 * 1.15);
            RoundNumber2(HP1, EXP1, M1);
        }
        else
        {
            HP1 = ceil(HP1 * 9.0 / 10.0);
            EXP1 = ceil(EXP1 * 1.20);
            RoundNumber2(HP1, EXP1, M1);
        }
    }
    RoundNumber2(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}

// Task 3

void RoundNumber3(int& HP1, int& EXP1, int& HP2, int& EXP2)
{
    if (HP1 > 666)
        HP1 = 666;
    else if (HP1 < 0)
        HP1 = 0;

    if (EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
        EXP1 = 0;

    if (HP2 > 666)
        HP2 = 666;
    else if (HP2 < 0)
        HP2 = 0;

    if (EXP2 > 600)
        EXP2 = 600;
    else if (EXP2 < 0)
        EXP2 = 0;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    RoundNumber3(HP1, EXP1, HP2, EXP2);
    //Matrix of Taxi
    int arrTaxi[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arrTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    //Point that Taxi meets Sherlock and Watson
    int count1 = 0, count2 = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arrTaxi[i][j] > (E3 * 2))
                count1++;

            if (arrTaxi[i][j] < (-E3))
                count2++;
        }
    }

    if (count1 / 10 < 1)
    {
        count1 = count1;
    }
    else
    {
        while (count1 >= 10)
        {
            int a = count1 / 10;
            int b = count1 % 10;
            count1 = a + b;
        }
    }

    if (count2 / 10 < 1)
    {
        count2 = count2;
    }
    else
    {
        while (count2 >= 10)
        {
            int a = count2 / 10;
            int b = count2 % 10;
            count2 = a + b;
        }
    }

    //Point of Sherlock and Watson
    int max = arrTaxi[count1][count2];
    int m = count1, n = count2;
    //Đường chéo trái
    while (m < 9 && n < 9)
    {
        m++;
        n++;
        if (max < arrTaxi[m][n])
        {
            max = arrTaxi[m][n];
        }
        else
            continue;
    }

    m = count1;
    n = count2;
    while (m >= 0 && n >= 0)
    {
        if (max < arrTaxi[m][n])
        {
            max = arrTaxi[m][n];
        }
        m--;
        n--;
    }
    //Đường chéo phải
    m = count1;
    n = count2;
    while (m < 9 && n >= 0)
    {
        m++;
        n--;
        if (max < arrTaxi[m][n])
        {
            max = arrTaxi[m][n];
        }
    }

    m = count1;
    n = count2;
    while (m >= 0 && n < 9)
    {
        if (max < arrTaxi[m][n])
        {
            max = arrTaxi[m][n];
        }
        m--;
        n++;
    }

    //After all
    if (abs(arrTaxi[count1][count2]) > max)
    {
        EXP1 = ceil(EXP1 * 88.0 / 100.0);
        HP1 = ceil(HP1 * 9.0 / 10.0);
        EXP2 = ceil(EXP2 * 88.0 / 100.0);
        HP2 = ceil(HP2 * 9.0 / 10.0);
        RoundNumber3(HP1, EXP1, HP2, EXP2);
        return arrTaxi[count1][count2];
    }
    else
    {
        EXP1 = ceil(EXP1 * 112.0 / 100.0);
        HP1 = ceil(HP1 * 11.0 / 10.0);
        EXP2 = ceil(EXP2 * 112.0 / 100.0);
        HP2 = ceil(HP2 * 11.0 / 10.0);
        RoundNumber3(HP1, EXP1, HP2, EXP2);
        return max;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {

    char* S = NULL;
    S = (char*)s;
    char se[100];
    //truyen vao se tu email
    int i = 0;
    while (email[i] != '@')
    {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';
    //case 2 + 3
    if (strlen(s) < 8)
        return -1;
    else if (strlen(s) > 20)
        return -2;

    //case 4
    char* contain_se = strstr(S, se);
    if (contain_se)
        return -(300 + (contain_se - s));

    //case 5
    for (int j = 0; j < strlen(s); j++)
    {
        if (s[j] == s[j + 1] && s[j + 1] == s[j + 2])
        {
            return -(400 + j);
        }
    }

    //case 6
    int count = 0;
    for (int m = 0; m < strlen(s); m++)
    {
        if (s[m] != '@' && s[m] != '#' && s[m] != '%' && s[m] != '$' && s[m] != '!')
            count++;
    }
    if (count == (strlen(s)))
        return -5;

    //case 7
    for (int m = 0; m < strlen(s); m++)
    {
        if (!isdigit(s[m]) && !isalpha(s[m]) && (s[m] != '@') && (s[m] != '#') && (s[m] != '%') && (s[m] != '$') && (s[m] != '!'))
            return m;
    }

    return -10;
}

// Task 5

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    int similar_appear[num_pwds] = {};
    int length[num_pwds] = {};

    int count = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        similar_appear[i] = count;
        count = 0;
    }

    int most_appear = similar_appear[0];
    for (int i = 1; i < num_pwds; i++)
    {
        if (similar_appear[i] > most_appear)
            most_appear = similar_appear[i];
    }

    for (int i = 0; i < num_pwds; i++)
    {
        if (similar_appear[i] == most_appear)
        {
            length[i] = strlen(arr_pwds[i]);
        }
    }

    int longest = length[0];
    int longest_position = 0;
    for (int k = 0; k < num_pwds; k++)
    {
        if (length[k] > longest)
        {
            longest = length[k];
            longest_position = k;
        }
    }

    int m = 0;
    for (m; m < num_pwds; m++)
    {
        if (arr_pwds[m] == arr_pwds[longest_position])
        {
            break;
        }
    }
    return m;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////