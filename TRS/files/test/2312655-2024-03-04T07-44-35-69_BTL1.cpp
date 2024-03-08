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

//! Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    if (E1 < 0 || E1 > 99) return -99;
    if (E1 >= 0 && E1 <= 3)
    {
        if(E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else if (E1 == 3) EXP2 += 29 + 45 + 75;
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 = ceil(EXP1 + (double)D / 200.0);
        else EXP1 = ceil(EXP1 - (double)D / 100.0);
    }
    else if (E1 >= 4 && E1 <= 99)
    {
        int info = 0;
        if (E1 <= 19)
        {
            EXP2 = ceil(EXP2 + (double)E1 / 4.0 + 19);
            info++;
        }
        else if (E1 <= 49)
        {
            EXP2 = ceil(EXP2 + (double)E1 / 9.0 + 21);
            info++;
        }
        else if (E1 <= 65)
        {
            EXP2 = ceil(EXP2 + (double)E1 / 16.0 + 17);
            info++;
        }
        else if (E1 <= 79)
        {
            EXP2 = ceil(EXP2 + (double)E1 / 4.0 + 19);
            info++;
            if (EXP2 > 200)
            {
                EXP2 = ceil(EXP2 + (double)E1 / 9.0 + 21);
                info++;
            }
        }
        else if (E1 <= 99)
        {
            EXP2 = ceil(EXP2 + (double)E1 / 4.0 + 19);
            EXP2 = ceil(EXP2 + (double)E1 / 9.0 + 21);
            info += 2;
            if (EXP2 > 400)
            {
                EXP2 = EXP2 = ceil(EXP2 + (double)E1 / 16.0 + 17);
                info++;
            }
        }
        if (info == 3) EXP2 = ceil(EXP2 + (double)EXP2 * 0.15);
        EXP1 = ceil(EXP1 - (double)E1 * 1.0);
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    return EXP1 + EXP2;
}

//! Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    if (E2 > 99 || E2 < 0) return -99;
    int S = 0;
    double P1 = 0, P2 = 0, P3 = 0;
    int M0 = M1;

    S = (int)sqrt(EXP1);
    if (EXP1 - (S * S) > ((S + 1) * (S + 1) - EXP1)) S = (S + 1) * (S + 1);
    else S = S * S;
    if (EXP1 >= S) P1 = 100;
    else P1 = ((EXP1 / (double)S + 80) / 123) * 100;

    if (E2 % 2 == 1)
    {
        while (true)
        {
            if (M1 == 0) break;
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + (double)HP1 * 0.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 + (double)HP1 * 0.1);
                M1 -= 70;
            }

            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < 0) M1 = 0;

            if ((M0 - M1) > M0 * 0.5) break;

            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(EXP1 + (double)EXP1 * 0.13);

            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < 0) M1 = 0;

            if ((M0 - M1) > M0 * 0.5) break;

            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(EXP1 - (double)EXP1 * 0.1);

            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < 0) M1 = 0;

            if ((M0 - M1) > M0 * 0.5) break;
        }
        HP1 = ceil(HP1 - (double)HP1 * 0.17);
        EXP1 = ceil(EXP1 + (double)EXP1 * 0.17);

        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
    }
    else
    {
        while (true)
        {
            if (M1 == 0) break;
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + (double)HP1 * 0.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 + (double)HP1 * 0.1);
                M1 -= 70;
            }

            if (HP1 > 666) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < 0) M1 = 0;

            if (M1 == 0) break;

            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(EXP1 + (double)EXP1 * 0.13);

            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < 0) M1 = 0;

            if (M1 == 0) break;

            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(EXP1 - (double)EXP1 * 0.1);

            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
            if (M1 > 3000) M1 = 3000;
            if (M1 < 0) M1 = 0;

            break;
        }
        HP1 = ceil(HP1 - (double)HP1 * 0.17);
        EXP1 = ceil(EXP1 + (double)EXP1 * 0.17);

        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
    }
    S = (int)sqrt(EXP1);
    if (EXP1 - (S * S) > ((S + 1) * (S + 1) - EXP1)) S = (S + 1) * (S + 1);
    else S = S * S;
    if (EXP1 >= S) P2 = 100;
    else P2 = ((EXP1 / (double)S + 80) / 123)*100;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    int sum = 0;
    if (E2 < 10) i = E2;
    else
    {
        sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    P3 = P[i];

    double P_final = 0;
    if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = ceil(EXP1 - (double)EXP1 * 0.25);
    else
    {
        P_final = (P1 + P2 + P3) / 3;
        if (P_final < 50)
        {
            HP1 = ceil(HP1 - (double)HP1 * 0.15);
            EXP1 = ceil(EXP1 + (double)EXP1 * 0.15);
        }
        else
        {
            HP1 = ceil(HP1 - (double)HP1 * 0.1);
            EXP1 = ceil(EXP1 + (double)EXP1 * 0.2);
        }
    }
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    return HP1 + EXP1 + M1;
}

//! Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 > 99 || E3 < 0) return -99;
    int i, j;
    int taxi[10][10];
    int sherlock[10][10];
    int meet_i, meet_j;
    int taxi_score, sherlock_score;
    
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            taxi[i][j] = 0;
        }
    }
    
    int bigger = 0;
    int smaller = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > E3 * 2) bigger++;
            if (taxi[i][j] < -E3) smaller++;
        }
    }
    
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            sherlock[i][j] = 0;
        }
    }
    
    while(bigger >= 10)
    {
        bigger = (bigger / 10) + (bigger % 10);
    }
    
    meet_i = bigger;
    
    while(smaller >= 10)
    {
        smaller = (smaller / 10) + (smaller % 10);
    }
    
    meet_j = smaller;

    int max_left = 0;
    int max_right = 0;
    for (i = 0; i < 10; i++)
    {       
        if ((meet_i - i) < 0 || (meet_j - i) < 0) break;
        if (taxi[meet_i - i][meet_j - i] > max_left) max_left = taxi[meet_i - i][meet_j - i];
    }
    for (i = 0; i < 10; i++)
    {
        if ((meet_i + i) > 9 || (meet_j + i) > 9) break;
        if (taxi[meet_i + i][meet_j + i] > max_left) max_left = taxi[meet_i + i][meet_j + i];
    }
    for (i = 0; i < 10; i++)
    {
        if ((meet_i + i) > 9 || (meet_j - i) < 0) break;
        if (taxi[meet_i + i][meet_j - i] > max_right) max_right = taxi[meet_i + i][meet_j - i];
    }
    for (i = 0; i < 10; i++)
    {
        if ((meet_i - i) < 0 || (meet_j + i) > 9) break;
        if (taxi[meet_i - i][meet_j + i] > max_right) max_right = taxi[meet_i - i][meet_j + i];
    }

    if (max_left > max_right)
    {
        sherlock[meet_i][meet_j] = max_left;
    }
    else
    {
        sherlock[meet_i][meet_j] = max_right;
    }

    if (sherlock[meet_i][meet_j] < 0)
    {
        sherlock[meet_i][meet_j] = -sherlock[meet_i][meet_j];
    }

    taxi_score = taxi[meet_i][meet_j];
    sherlock_score = sherlock[meet_i][meet_j];
    
    if (abs(taxi_score) > sherlock_score)
    {
        HP1 = ceil(HP1 - (double)HP1 * 0.1);
        EXP1 = ceil(EXP1 - (double)EXP1 * 0.12);
        HP2 = ceil(HP2 - (double)HP2 * 0.1);
        EXP2 = ceil(EXP2 - (double)EXP2 * 0.12);
    }
    else
    { 
        HP1 = ceil(HP1 + (double)HP1 * 0.1);
        EXP1 = ceil(EXP1 + (double)EXP1 * 0.12);
        HP2 = ceil(HP2 + (double)HP2 * 0.1);
        EXP2 = ceil(EXP2 + (double)EXP2 * 0.12);
    }
    
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    
    if (abs(taxi_score) > sherlock_score)
    {
        return taxi_score;
    }
    else
    {
        return sherlock_score;
    }
}

//! Task 4
int checkPassword(const char *s, const char *email)
{
    char se[101] = "";
    int len = strlen(s);
    int sei = -1;
    int sci = -1;
    int special = 0;
    int invalid = -1;
    bool valid = true;
    int output = 0;
    int i = 0;

    while (email[i] != '@' && email[i] != '\0')
    {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    if (len < 8)
    {
        output = -1;
        valid = false;
    }
    else if (len > 20)
    {
        output = -2;
        valid = false;
    }
    else
    {
        if (strstr(s, se))
        {
            sei = strstr(s, se) - s;
            output = -(300 + sei);
            valid = false;
        }

        for (i = 0; i < len - 2 && valid; i++)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                sci = i;
                output = -(400 + sci);
                valid = false;
                break;
            }
        }
    
        if (valid)
        {
            for (i = 0; i < len; i++)
            {
                if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
                {
                    special++;
                }
            }
            if (special == 0)
            {
                output = -5;
                valid = false;
            }
        }

        if (valid)
        {
            for (i = 0; i < len && valid; i++)
            {
                if (isdigit(s[i]) || islower(s[i]) || isupper(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
                {
                    //Gia tri valid khong doi
                }
                else 
                {
                    invalid = i;
                    output = invalid;
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
        {
            output = -10;
        }
    }
    return output;
}

//! Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int i, j;
    int max_count = 0;
    int max_len = 0;
    int output = -1;
    
    for (i = 0; i < num_pwds; i++)
    {
        int count = 0;
        int len = strlen(arr_pwds[i]);
        
        for (j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) count++;
        }
        
        if (count > max_count || (count == max_count && len > max_len))
        {
            max_count = count;
            max_len = len;
            output = i;
        }
    }
    return output;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////