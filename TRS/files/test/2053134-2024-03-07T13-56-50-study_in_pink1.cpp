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
int nearestSquare(int EXP)
{
    int Above = ceil(sqrt(EXP)) * ceil(sqrt(EXP));
    int Below = floor(sqrt(EXP)) * floor(sqrt(EXP));
    int nearestsquare;
    if (abs(EXP - Above) < abs(EXP - Below))
        nearestsquare = Above;
    else
        nearestsquare = Below;
    return nearestsquare;
}

int bool_HP(int &hp)
{
    if (hp < 0)
    {
        hp = 0;
    }
    else if (hp > 666)
    {
        hp = 666;
    }
    return hp;
}
int bool_EXP(int &ex)
{
    if (ex < 0)
    {
        ex = 0;
    }
    else if (ex > 600)
    {
        ex = 600;
    }
    return ex;
}
int bool_M(int &m)
{

    if (m < 0)
    {
        m = 0;
    }
    else if (m > 3000)
    {
        m = 3000;
    }
    return m;
}
int sum_Number(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int transform(int n)
{
    if (n >= 10)
    {
        int hangchuc = n / 10;
        int hangdonvi = n - hangchuc * 10;
        return transform(hangchuc + hangdonvi);
    }
    return n;
}
int findMax(int sherlock, int map)
{
    if (sherlock >= map)
    {
        return sherlock;
    }
    else
    {
        return map;
    }
}
// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    // TODO: Complete this function
    int D;
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP2 < 0)
    {
        EXP2 = 0;
    }

    if (E1 >= 0 && E1 <= 3)
    {
        switch (E1)
        {
        case 0:
            /* code */
            EXP2 += 29;
            break;
        case 1:
            /* code */
            EXP2 += 45;
            break;
        case 2:
            /* code */
            EXP2 += 75;
            break;
        case 3:
            /* code */
            EXP2 += 149;
            break;

        default:
            break;
        }
        D = (E1 * 3) + (EXP1 * 7);
        if (D % 2 == 0)
        {
            EXP1 = ceil(EXP1 + static_cast<double>(D) / 200);
        }
        else
        {
            EXP1 = ceil(EXP1 - static_cast<double>(D) / 100);
        }
    }
    else if (E1 >= 4 && E1 <= 99)
    {
        if (E1 <= 19)
        {
            EXP2 = ceil(EXP2 + static_cast<double>(E1) / 4.0 + 19);
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            EXP2 = ceil(EXP2 + static_cast<double>(E1) / 9.0 + 21);
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            EXP2 = ceil(EXP2 + static_cast<double>(E1) / 16.0 + 17);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = ceil(EXP2 + static_cast<double>(E1) / 4.0 + 19);
            if (EXP2 > 200)
            {
                EXP2 = ceil(EXP2 + static_cast<double>(E1) / 9.0 + 21);
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = ceil(EXP2 + static_cast<double>(E1) / 4.0 + 19);
            EXP2 = ceil(EXP2 + static_cast<double>(E1) / 9.0 + 21);

            if (EXP2 > 400)
            {
                EXP2 = ceil(EXP2 + static_cast<double>(E1) / 16.0 + 17);
                EXP2 = ceil(EXP2 + static_cast<double>(EXP2) * 0.15);
            }
        }
        EXP1 -= E1;
    }
    else
    {
        if (E1 < 0 || E1 > 99)
            return -99;
    }
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
    {
        return -99;
    }

    bool_HP(HP1);
    bool_EXP(EXP1);
    bool_M(M1);
    bool_HP(HP1);
    bool_EXP(EXP1);
    bool_M(M1);
    if(E2 == 0 && HP1 == 0 && EXP1 == 0 && M1 ==0 ){
        return 0;
    }
    if (M1 == 0)
    {
        EXP1 = ceil(EXP1 * 117.0 / 100);
        HP1 = ceil(HP1 * 83.0 / 100);
    }

    int S = 0;
    float P1 = 0;

    float P2 = 0;
    
    float P3;
    S = nearestSquare(EXP1);
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = 100.0 * (ceil((EXP1 * 1.0 / S)) + 80) * 1.0 / 123; 
    }

    int used_m = 0;
    double half_m = M1 * 0.5;
    if ((E2 % 2) == 1)
    {
        while (used_m < half_m)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                used_m += 150;
                M1 = M1 - 150;
            }
            else if (HP1 >= 200)
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 = M1 - 70;
                used_m += 70;
            }
            if (used_m > half_m || M1 <= 0)
            {
                break;
            }
            if (EXP1 < 400)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                M1 = M1 - 200;
                used_m += 200;
            }
            else if (EXP1 >= 400)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                M1 = M1 - 120;
                used_m += 120;
            }
            if (used_m > half_m || M1 <= 0)
            {
                break;
            }
            if (EXP1 < 300)
            {
                EXP1 = ceil(EXP1 * 9.0 / 10);
                M1 = M1 - 100;
                used_m += 100;
            }
            else if (EXP1 >= 300)
            {
                EXP1 = ceil(EXP1 * 9.0 / 10);
                M1 = M1 - 120;
                used_m += 120;
            }
            if (used_m > half_m || M1 <= 0)
            {
                break;
            }
        }
    }
    else if ((E2 % 2) == 0)
    {
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                used_m += 150;
                M1 = M1 - 150;
            }
            else if (HP1 >= 200)
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 = M1 - 70;
                used_m += 70;
            }

            if (M1 > 0 || used_m < half_m)
            {
                if (EXP1 < 400)
                {
                    EXP1 = ceil(EXP1 * 113.0 / 100);
                    M1 = M1 - 200;
                    used_m += 200;
                }
                else if (EXP1 >= 400)
                {
                    EXP1 = ceil(EXP1 * 113.0 / 100);
                    M1 = M1 - 120;
                    used_m += 120;
                }
            }

            if (M1 > 0 || used_m < half_m)
            {
                if (EXP1 < 300)
                {
                    EXP1 = ceil(EXP1 * 9.0 / 10);
                    M1 = M1 - 100;
                    used_m += 100;
                }
                else if (EXP1 >= 300)
                {
                    EXP1 = ceil(EXP1 * 9.0 / 10);
                    M1 = M1 - 120;
                    used_m += 120;
                }
            }
        }
    }
    bool_HP(HP1);

    HP1 = ceil(HP1 * 83.0 / 100);
    EXP1 = ceil(EXP1 * 117.0 / 100);
    bool_EXP(EXP1);
    (float)P2;
    int S2 = nearestSquare(EXP1);
    if (EXP1 >= S2)
    {
        P2 = 100;
    }
    else
    {
        P2 = 100.0 * (ceil((EXP1 * 1.0 / S2)) + 80) * 1.0 / 123; 
    }
    (float)P3;
    float P[10] = {32.0, 47.0, 28.0, 79.0, 100.0, 50.0, 22.0, 83.0, 64.0, 11.0};
    if (E2 >= 0 && E2 <= 9)
    {
        P3 = P[E2];
    }
    else if (E2 >= 10 && E2 <= 99)
    {
        int index = (E2 / 10 + E2 % 10) % 10;
        P3 = P[index];
    }
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(EXP1 * 75.0 / 100);
    }
    else
    {
        double P_avg = ceil((P1 + P2 + P3) * 1.0 / 3);
        if (P_avg < 50.0)
        {
            HP1 = ceil(HP1 * 1.0 * 85.0 / 100);
            EXP1 = ceil(EXP1 * 1.0 * 115.0 / 100);
        }
        else if (P_avg >= 50)
        {
            HP1 = ceil(HP1 * 1.0 * 9.0 / 10);
            EXP1 = ceil(EXP1 * 1.0 * 12.0 / 10);
        }
    }

    bool_EXP(EXP1);
    bool_HP(HP1);
    bool_M(M1);

    return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function

    if (E3 > 99 || E3 < 0)
    {
        return -99;
    }
    bool_EXP(EXP1);
    bool_HP(HP1);
    bool_EXP(EXP2);
    bool_HP(HP2);

    int map[10][10] = {0};
    int i_count = 0;
    int j_count = 0;
    int calculate;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            calculate = ((E3 * j) + (i * 2)) * (i - j);
            map[i][j] = calculate;
            if (calculate > 2 * E3)
            {
                i_count++;
            }
            if (calculate < -E3)
            {
                j_count++;
            }
        }
    }
    i_count = transform(i_count);
    j_count = transform(j_count);

    int Taxi = map[i_count][j_count];
    int Sherlock = 0;

    for (int i = 0; i < 10; i++)
    {
        if (i != i_count)
        {
            for (int j = 0; j < 10; j++)
            {
                if (j == (j_count - (i_count - i)))
                {
                    Sherlock = findMax(Sherlock, map[i][j]);
                }
                if (j == (j_count + (i_count - i)))
                {
                    Sherlock = findMax(Sherlock, map[i][j]);
                }
            }
        }
    }
    if (Sherlock >= abs(map[i_count][j_count]))
    {
        if (
            Sherlock >= abs(Taxi))
        {
           
            HP1 = ceil(HP1 * 1.0 * 11.0 / 10);
            EXP1 = ceil(EXP1 * 1.0 * 112.0 / 100);
            HP2 = ceil(HP2 * 1.0 * 11.0 / 10);
            EXP2 = ceil(EXP2 * 1.0 * 112.0 / 100);
            
            bool_EXP(EXP1);
            bool_HP(HP1);
            bool_EXP(EXP2);
            bool_HP(HP2);
            return Sherlock;
        }
    }

    Sherlock = abs(Sherlock);

    HP1 = ceil(HP1 * 1.0 * 9.0 / 10);
    EXP1 = ceil(EXP1 * 1.0 * 88.0 / 100);
    HP2 = ceil(HP2 * 1.0 * 9.0 / 10);
    EXP2 = ceil(EXP2 * 1.0 * 88.0 / 100);

    bool_EXP(EXP1);
    bool_HP(HP1);
    bool_EXP(EXP2);
    bool_HP(HP2);
    return Taxi;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int len_s = (int)strlen(s);

    if (len_s < 8)
    {
        return -1;
    }
    if (len_s > 20)
    {
        return -2;
    }

    char se[101];
    int j = 0;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] != '@')
        {

            se[j] = email[i];
            j++;
        }
        else
        {
            break;
        }
    };
    se[j] = '\0';
    int len_se = strlen(se);
    if (len_se == 0)
    {
        return -300;
    }

    const char *check_s_se = strstr(s, se);
    if (check_s_se != NULL)
    {

        int pos = check_s_se - s;
        return -(300 + pos);
    }

    for (size_t i = 0; i < strlen(s) - 2; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (s[i + 1] == s[i + 2])
            {

                return -(400 + i);
            }
        }
    }

    int count_spec_char = 0;

    for (size_t i = 0; i < strlen(s); i++)
    {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
        {

            count_spec_char++;
            break;
        }
    }
    if (count_spec_char == 0)
    {
        return -5;
    }

    int pos_s;
    for (size_t i = 0; i < strlen(s); i++)
    {
        if ((s[i] == 32) || (s[i] >= 38 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 63) || (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126))
        {
            pos_s = i;
            return pos_s;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int count = 0;
    int k = 0;
    int x[num_pwds];
    int y[num_pwds];
    int len_arrI = 0;
    for (int j = 0; j < num_pwds; j++)
    {

        len_arrI = strlen(arr_pwds[j]);

        y[j] = len_arrI;
        int count = 1;
        for (int i = j + 1; i < num_pwds; i++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        x[j] = count;
    }
    int max = x[0];
    int max_length = y[0];

    for (int i = 0; i < num_pwds; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
            max_length = y[i];
            k = i;
        }
        else if (x[i] == max)
        {
            if (y[i] > max_length)
            {
                k = i;
                max_length = y[i];
            }
        }
    }

    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////