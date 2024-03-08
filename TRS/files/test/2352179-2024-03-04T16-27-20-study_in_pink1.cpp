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
void limit_exp(int &EXP)
{
    if (EXP < 0)
        EXP = 0;
    else if (EXP > 600)
        EXP = 600;
}
void limit_hp(int &HP)
{
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;
}
void limit_m(int &M)
{
    if (M < 0)
        M = 0;
    else if (M > 3000)
        M = 3000;
}
// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    int D;
    if (E1 < 0 || E1 > 99)
        return -99;
    limit_exp(EXP1);
    limit_exp(EXP2);
    if (E1 >= 0 && E1 <= 3)
    {
        switch (E1)
        {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 149;
            break;
        }
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
        {
            EXP1 = 0.999 + EXP1 + (double)D / 200.0;
            limit_exp(EXP1);
        }
        else if (D % 2 != 0)
        {
            EXP1 = 0.999 + EXP1 - (double)D / 100.0;
            limit_exp(EXP1);
        }
        limit_exp(EXP2);
    }

    if (E1 >= 4 && E1 <= 99)
    {
        if (E1 <= 19)
        {
            EXP2 = 0.999 + EXP2 + (double)E1 / 4.0 + 19.0;
            limit_exp(EXP2);
        }
        else if (E1 <= 49)
        {
            EXP2 = 0.999 + EXP2 + (double)E1 / 9.0 + 21.0;
            limit_exp(EXP2);
        }
        else if (E1 <= 65)
        {
            EXP2 = 0.999 + EXP2 + (double)E1 / 16.0 + 17.0;
            limit_exp(EXP2);
        }
        else if (E1 <= 79)
        {
            EXP2 = 0.999 + EXP2 + (double)E1 / 4.0 + 19.0;
            limit_exp(EXP2);
            if (EXP2 > 200)
            {
                EXP2 = 0.999 + EXP2 + (double)E1 / 9.0 + 21.0;
                limit_exp(EXP2);
            }
        }
        else
        {
            EXP2 = 0.999 + EXP2 + E1 / 4.0 + 19.0;
            EXP2 = 0.999 + EXP2 + E1 / 9.0 + 21.0;
            limit_exp(EXP2);
            if (EXP2 > 400)
            {
                EXP2 = 0.999 + EXP2 + ((double)E1 / 16.0 + 17.0);
                EXP2 = 0.999 + EXP2 * 115.0 / 100.0;
                limit_exp(EXP2);
            }
        }

        EXP1 -= E1;
    }
    limit_exp(EXP1);
    return EXP1 + EXP2;
}

// Task 2

double pct(int &EXP1)
{
    double S = round(sqrt(EXP1));
    if (EXP1 >= pow((S), 2))
        return 1;
    else if (EXP1 < pow((S), 2))
        return ((double)EXP1 / (double)pow(round(S), 2) + 80.0) / 123.0;
    return 0;
}

double traceLuggage_1(int &HP1, int &EXP1, int &M1, int E2)
{
    double P1 = pct(EXP1);
    return P1;
}

double traceLuggage_2_odd(int &HP1, int &EXP1, int &M1, int E2)
{
    double ref = round(M1 / 2.0);
    if (M1 == 0)
    {
        HP1 = ceil(HP1 * 0.83);
        limit_hp(HP1);
        EXP1 = ceil(EXP1 * 1.17);
        limit_exp(EXP1);
        return pct(EXP1);
    }
    while (M1 >= ref)
    {
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 * 1.3);
            limit_hp(HP1);
            M1 -= 150;
            limit_m(M1);
            if (M1 < ref)
                break;
        }
        else if (HP1 >= 200)
        {
            HP1 = ceil(HP1 * 11.0 / 10.0);
            limit_hp(HP1);
            M1 -= 70;
            limit_m(M1);
            if (M1 < ref)
                break;
        }
        if (EXP1 < 400)
        {
            M1 -= 200;
            limit_m(M1);
            EXP1 = ceil(EXP1 * 1.13);
            limit_exp(EXP1);
            if (M1 < ref)
                break;
        }
        else if (EXP1 >= 400)
        {
            M1 -= 120;
            limit_m(M1);
            EXP1 = ceil(EXP1 * 1.13);
            limit_exp(EXP1);
            if (M1 < ref)
                break;
        }
        if (EXP1 < 300)
        {
            M1 -= 100;
            limit_m(M1);
            EXP1 = ceil(EXP1 * 0.9);
            limit_exp(EXP1);
            if (M1 < ref)
                break;
        }
        else if (EXP1 >= 300)
        {
            M1 -= 120;
            limit_m(M1);
            EXP1 = ceil(EXP1 * 0.9);
            limit_exp(EXP1);
            if (M1 < ref)
                break;
        }
    }
    HP1 = ceil(HP1 * 0.83);
    limit_hp(HP1);
    EXP1 = ceil(EXP1 * 1.17);
    limit_exp(EXP1);
    return pct(EXP1);
}

double traceLuggage_2_even(int &HP1, int &EXP1, int &M1, int E2)
{
    for (int i = 0; i < 1; i++)
    {
        if (M1 == 0)
            break;
        if (M1 > 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                limit_hp(HP1);
                M1 -= 150;
                limit_m(M1);
                if (M1 <= 0)
                    break;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10.0);
                limit_hp(HP1);
                M1 -= 70;
                limit_m(M1);
                if (M1 <= 0)
                    break;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
                limit_m(M1);
                EXP1 = ceil(EXP1 * 1.13);
                limit_exp(EXP1);
                if (M1 <= 0)
                    break;
            }
            else
            {
                M1 -= 120;
                limit_m(M1);
                EXP1 = ceil(EXP1 * 1.13);
                limit_exp(EXP1);
                if (M1 <= 0)
                    break;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
                limit_m(M1);
                EXP1 = ceil(EXP1 * 0.9);
                limit_exp(EXP1);
                if (M1 <= 0)
                    break;
            }
            else
            {
                M1 -= 120;
                limit_m(M1);
                EXP1 = ceil(EXP1 * 0.9);
                limit_exp(EXP1);
                if (M1 <= 0)
                    break;
            }
        }
    }
    HP1 = ceil(HP1 * 0.83);
    limit_hp(HP1);
    EXP1 = ceil(EXP1 * 1.17);
    limit_exp(EXP1);
    return pct(EXP1);
}

double traceLuggage_3(int &HP1, int &EXP1, int &M1, int E2)
{
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    return (double)arr[(E2 % 10 + E2 / 10) % 10];
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    limit_exp(EXP1);
    limit_hp(HP1);
    limit_m(M1);
    double P1 = traceLuggage_1(HP1, EXP1, M1, E2);

    double P2, P;
    if (E2 % 2 != 0)
    {
        P2 = traceLuggage_2_odd(HP1, EXP1, M1, E2);
    }
    else if (E2 % 2 == 0)
    {
        P2 = traceLuggage_2_even(HP1, EXP1, M1, E2);
    }

    double P3 = traceLuggage_3(HP1, EXP1, M1, E2) / 100.0;

    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil(EXP1 * 0.75);
        limit_exp(EXP1);
        P = 1;
    }
    else
    {
        P = (P1 + P2 + P3) / 3.0;
        if (P < 0.5)
        {
            HP1 = ceil(HP1 * 0.85);

            limit_hp(HP1);
            EXP1 = ceil(EXP1 * 1.15);

            limit_exp(EXP1);
        }
        else if (P >= 0.5)
        {
            HP1 = ceil(HP1 * 0.9);

            limit_hp(HP1);
            EXP1 = ceil(EXP1 * 1.2);
            limit_exp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    limit_exp(EXP1);
    limit_exp(EXP2);
    limit_hp(HP1);
    limit_hp(HP2);
    int bigmap[10][10] = {};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bigmap[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    int pos = 0, neg = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (bigmap[i][j] > (E3 * 2))
                pos++;
            else if (bigmap[i][j] < (-E3))
                neg++;
        }
    }

    // Position of the taxi
    int row, col;
    row = (pos / 10 + pos % 10);
    row = (row / 10 + row % 10);
    col = (neg / 10 + neg % 10);
    col = (col / 10 + col % 10);

    // Diagonal
    int max = bigmap[0][0];
    int taxi_pt, sherlock_pt;
    // Left
    for (int k = 0; k < 10; k++)
    {
        if ((row + k) <= 9 && (row + k) >= 0 && (col + k) <= 9 && (col + k) >= 0)
        {
            if (bigmap[row + k][col + k] > max)
                max = bigmap[row + k][col + k];
        }
    }
    for (int k = 0; k < 10; k++)
    {
        if ((row - k) <= 9 && (row - k) >= 0 && (col - k) <= 9 && (col - k) >= 0)
        {
            if (bigmap[row - k][col - k] > max)
                max = bigmap[row - k][col - k];
        }
    }
    // Right
    for (int k = 0; k < 10; k++)
    {
        if ((row - k) <= 9 && (row - k) >= 0 && (col + k) <= 9 && (col + k) >= 0)
        {
            if (bigmap[row - k][col + k] > max)
                max = bigmap[row - k][col + k];
        }
    }
    for (int k = 0; k < 10; k++)
    {
        if ((row + k) <= 9 && (row + k) >= 0 && (col - k) <= 9 && (col - k) >= 0)
        {
            if (bigmap[row + k][col - k] > max)
                max = bigmap[row + k][col - k];
        }
    }

    // Absolute
    taxi_pt = abs(bigmap[row][col]);
    sherlock_pt = abs(max);
    int max_final;
    if (taxi_pt > sherlock_pt)
    {
        EXP1 = (EXP1 * 0.88 + 0.999);
        EXP2 = (EXP2 * 0.88 + 0.999);
        HP1 = (HP1 * 0.9 + 0.999);
        HP2 = (HP2 * 0.9 + 0.999);
        limit_exp(EXP1);
        limit_exp(EXP2);
        limit_hp(HP1);
        limit_hp(HP2);
        max_final = bigmap[row][col];
    }
    else if (taxi_pt <= sherlock_pt)
    {
        EXP1 = (EXP1 * 1.12 + 0.999);
        EXP2 = (EXP2 * 1.12 + 0.999);
        HP1 = (HP1 * 11.0 / 10.0 + 0.999);
        HP2 = (HP2 * 11.0 / 10.0 + 0.999);
        limit_exp(EXP1);
        limit_exp(EXP2);
        limit_hp(HP1);
        limit_hp(HP2);
        max_final = max;
    }
    return max_final;
}

// Task 4
const int symbol[5] = {33, 35, 36, 37, 64};
bool checkNotSymbol(const char *s, int &count, int &notSymbol)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!((s[i] >= 48 && s[i] <= 57) || (s[i] >= 64 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 35 && s[i] <= 37) || s[i] == 33))
        {
            notSymbol = i;
            return true;
        }
    }
    count++;
    return false;
}
int checkSymbol(const char *s, int &countSymbol, int &count)
{
    for (int i = 0; i < strlen(s); i++)
    {
        for (int k = 0; k < 5; k++)
        {
            if (s[i] == symbol[k])
                countSymbol++;
        }
    }
    if (countSymbol > 0)
        count++;
    return 0;
}
bool containSE(const char *s, string se, int &count, int &se_ref)
{
    for (int i = 0; i < strlen(s); i++)
    {
        int k;
        for (k = 0; k < se.length(); k++)
        {
            if (s[i + k] != se[k])
                break;
        }
        if (k == se.length())
        {
            se_ref = -(300 + i);
            return true;
        }
    }
    if (se == "")
    {
        se_ref = -300;
        return true;
    }
    count++;
    return false;
}

bool twoAdjacent(const char *s, int &count, int &adjacent)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
        {
            adjacent = -(400 + i);
            return true;
        }
    }
    count++;
    return false;
}

int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    // Get se
    string se;
    // separate the part before @ and after @
    int i = 0;
    while (email[i] != '@')
    {
        se += email[i];
        i++;
    }
    int se_ref = 0;
    int adjacent = 0;
    int notSymbol = 0;
    int sLength = strlen(s);    // password length
    int seLength = se.length(); // sub_string_email length
    int count = 0, countSymbol = 0, countNotSymbol = 0, countCondViolate = 0;
    // Password length return
    if (sLength < 8)
        return -1;
    else if (sLength > 20)
        return -2;

    // Valid password return
    // Valid length
    if (strlen(s) >= 8 && strlen(s) <= 20)
        count++;
    if (containSE(s, se, count, se_ref))
    {
        return se_ref;
    }
    if (twoAdjacent(s, count, adjacent))
    {
        return adjacent;
    }
    checkSymbol(s, countSymbol, count);
    if (countSymbol == 0)
        return -5;
    if (checkNotSymbol(s, count, notSymbol))
        return notSymbol;
    if (count == 5)
        return -10;
    return 0;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)

{
    // TODO: Complete this function
    // Initialize array to store appearance times
    int exist[200] = {};
    // Initialize array to store length
    int length[200] = {};
    // Check how many times pwd appears
    // Count appear times
    int exist_count = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int k = 0; k < num_pwds; k++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[k]) == 0)
            {
                exist_count++;
            }
        }
        exist[i] = exist_count;
        exist_count = 0;
    }
    // Initialize the most appearance times
    int exist_most = exist[0];
    // Insert most appear time array
    for (int i = 1; i < num_pwds; i++)
    {
        if (exist[i] > exist_most)
            exist_most = exist[i];
    }
    // Insert length array elements
    for (int i = 0; i < num_pwds; i++)
    {
        if (exist[i] == exist_most)
        {
            length[i] = strlen(arr_pwds[i]);
        }
    }
    // Check longest
    int longest = length[0];
    int longest_pos = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (length[i] > longest)
        {
            longest = length[i];
            longest_pos = i;
        }
    }
    // Iterate until meet the first element which is similar to the longest_pos' element
    int n = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == arr_pwds[longest_pos])
        {
            n = i;
            break;
        }
    }
    return n;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////