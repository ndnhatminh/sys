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
void checkRange(int& v, int lowerBound, int upperBound)
{
    if (v < lowerBound)
        v = lowerBound;
    if (v > upperBound)
        v = upperBound;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1 < 0 || e1 > 99)
        return -99;
    checkRange(exp1, 0, 600);
    checkRange(exp2, 0, 600);
    if (e1 < 4)
    {
        float m_exp1 = exp1;
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += (29 + 45 + 75);
            break;
        default:
            break;
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0)
            m_exp1 += (d / 200.0);
        else
            m_exp1 -= (d / 100.0);
        exp1 = ceil(m_exp1);
    }
    else
    {
        if (e1 < 20)
            exp2 += ceil(float((e1 / 4.0) + 19));
        else if (e1 < 50)
            exp2 += ceil(float((e1 / 9.0) + 21));
        else if (e1 < 66)
            exp2 += ceil(float((e1 / 16.0) + 17));
        else if (e1 < 80)
        {
            exp2 += ceil(float((e1 / 4.0) + 19));
            checkRange(exp2, 0, 600);
            if (exp2 > 200)
                exp2 += ceil(float((e1 / 9.0) + 21));
        }
        else
        {
            exp2 += ceil(float((e1 / 4.0) + 19));
            checkRange(exp2, 0, 600);
            exp2 += ceil(float((e1 / 9.0) + 21));
            checkRange(exp2, 0, 600);
            if (exp2 > 400)
            {
                exp2 += ceil(float((e1 / 16.0) + 17));
                checkRange(exp2, 0, 600);
                exp2 = ceil(float(exp2 * 1.15));
            }
        }
        exp1 -= e1;
        //cout << exp2 << endl;
    }
    checkRange(exp1, 0, 600);
    checkRange(exp2, 0, 600);
    return exp1 + exp2;
}
int route2(int& HP1, int& EXP1, int& M1, bool odd_E2, float threshold, int spend)
{
    int spend_money = spend;
    if (M1 > 0 || odd_E2)
    {
        if (HP1 < 200)
        {
            HP1 = ceil(float(HP1 * 1.3));
            M1 -= 150;
            spend_money += 150;
        }
        else
        {
            HP1 = ceil(float(HP1 * 1.1));
            M1 -= 70;
            spend_money += 70;
        }
        checkRange(HP1, 0, 666);
        checkRange(M1, 0, 3000);
    }
    if ((spend_money > threshold) && odd_E2)
        return -1;
    if (M1 > 0 || odd_E2)
    {
        if (EXP1 < 400)
        {
            M1 -= 200; spend_money += 200;
        }
        else
        {
            M1 -= 120; spend_money += 120;
        }
        EXP1 = ceil(float(EXP1 * 1.13));
        checkRange(EXP1, 0, 600);
        checkRange(M1, 0, 3000);
    }
    if ((spend_money > threshold) && odd_E2)
        return -1;
    if (M1 > 0 || odd_E2)
    {
        if (EXP1 < 300)
        {
            M1 -= 100; spend_money += 100;
        }
        else
        {
            M1 -= 120; spend_money += 120;
        }
        EXP1 = ceil(float(EXP1 * 0.9));
        checkRange(EXP1, 0, 600);
        checkRange(M1, 0, 3000);
    }
    if ((spend_money > threshold) && odd_E2)
        return -1;
    return spend_money;
}
float roundP(float p)
{
    p *= 100;
    p = round(p);
    p /= 100;
    return p;
}
float findP(int exp)
{
    int tmp = floor(sqrt(exp));
    float tmp1 = sqrt(exp) - tmp;
    if (tmp1 < 0.5)
        return 1.0;
    else
    {
        float s = pow(tmp + 1, 2);
        return roundP(((exp / s) + 80) / 123);
    }
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;
    checkRange(HP1, 0, 666);
    checkRange(EXP1, 0, 600);
    checkRange(M1, 0, 3000);
    //route01
    float p1 = findP(EXP1);
    //route02
    if (E2 % 2 == 0)
    {
        route2(HP1, EXP1, M1, 0, 0, 0);
    }
    else
    {
        float half_money = M1 * 0.5;
        int spended = 0;
        while (true)
        {
            int r = route2(HP1, EXP1, M1, 1, half_money, spended);
            if (r == -1)
                break;
            spended = r;
        }
    }
    HP1 = ceil(float(HP1 * 0.83));
    EXP1 = ceil(float(EXP1 * 1.17));
    checkRange(HP1, 0, 666);
    checkRange(EXP1, 0, 600);
    float p2 = findP(EXP1);
    //route03
    int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    float p3;
    if (E2 < 10)
        p3 = arr[E2];
    else
    {
        int tmp2 = (E2 % 10) + (E2 / 10);
        p3 = arr[tmp2 % 10];
    }
    p3 /= 100;
    //cout << p3 << endl;
    if (p1 + p2 + p3 == 3)
        EXP1 = ceil(float(EXP1 * 0.75));
    else
    {
        float pp = roundP((p1 + p2 + p3) / 3);
        //cout << pp << endl<<HP1<<endl;
        if (pp < 0.5)
        {
            HP1 = ceil(float(HP1 * 0.85)); EXP1 = ceil(float(EXP1 * 1.15));
        }
        else
        {
            HP1 = ceil(float(HP1 * 0.9)); EXP1 = ceil(float(EXP1 * 1.2));
        }
        checkRange(HP1, 0, 666);
    }
    checkRange(EXP1, 0, 600);
    //cout << tmp1 << endl;
    return HP1 + EXP1 + M1;
}
int findMaxDiagonal(int arr[][10], int p_i, int p_j)
{
    int max = arr[p_i][p_j];
    int tmp = p_i + p_j;
    int i, j;
    bool up = 0;
    if (tmp > 9)
    {
        i = 9; j = tmp - 9; up = 1;
    }
    else
    {
        i = 0; j = tmp;
    }
    while (true)
    {
        if (arr[i][j] > max)
            max = arr[i][j];
        if (up)
            if (j == 9)
                break;
            else
            {
                i--; j++;
            }
        else
            if (j == 0)
                break;
            else
            {
                i++; j--;
            }
    }
    if (p_i >= p_j)
    {
        i = 9; j = 9 - p_i + p_j; up = 1;
    }
    else
    {
        i = 0; j = p_j - p_i; up = 0;
    }
    while (true)
    {
        if (arr[i][j] > max)
            max = arr[i][j];
        if (up)
            if (j == 0)
                break;
            else
            {
                i--; j--;
            }
        else
            if (j == 9)
                break;
            else
            {
                i++; j++;
            }
    }
    return max;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    int arr[10][10];
    int count_i = 0, count_j = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int tmp = ((E3 * j) + (i * 2)) * (i - j);
            arr[i][j] = tmp;
            if (tmp > E3 * 2)
                count_i++;
            if (tmp < -E3)
                count_j++;
        }
    }
    while (count_i > 9)
        count_i = (count_i / 10) + (count_i % 10);
    while (count_j > 9)
        count_j = (count_j / 10) + (count_j % 10);
    //cout << count_i << '\n' << count_j << '\n';
    int score = findMaxDiagonal(arr, count_i, count_j);
    //cout << score << '\n';
    checkRange(HP1, 0, 666);
    checkRange(EXP1, 0, 600);
    checkRange(HP2, 0, 666);
    checkRange(EXP2, 0, 600);
    if (abs(arr[count_i][count_j]) > score)
    {
        HP1 = ceil(float(HP1 * 0.9));
        EXP1 = ceil(float(EXP1 * 0.88));
        HP2 = ceil(float(HP2 * 0.9));
        EXP2 = ceil(float(EXP2 * 0.88));
    }
    else
    {
        HP1 = ceil(float(HP1 * 1.1));
        EXP1 = ceil(float(EXP1 * 1.12));
        HP2 = ceil(float(HP2 * 1.1));
        EXP2 = ceil(float(EXP2 * 1.12));

    }
    checkRange(HP1, 0, 666);
    checkRange(EXP1, 0, 600);
    checkRange(HP2, 0, 666);
    checkRange(EXP2, 0, 600);
    if (abs(arr[count_i][count_j]) > score)
        return arr[count_i][count_j];
    return score;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string m_email = email;
    string m_s = s;
    if (m_s.length() < 8) return -1;
    if (m_s.length() > 20) return -2;
    bool hasSpecial = 0;
    int has_invalid = -1;
    for (int i = 0; i < m_s.length(); i++)
    {
        if (!((m_s[i] == 33) || (m_s[i] > 34 && m_s[i] < 38) || (m_s[i] > 47 && m_s[i] < 58) || (m_s[i] > 63 && m_s[i] < 91) || (m_s[i] > 96 && m_s[i] < 123)) && has_invalid == -1)
            has_invalid = i;
        if ((m_s[i] == 33) || (m_s[i] > 34 && m_s[i] < 38) || (m_s[i] == 64))
            hasSpecial = 1;
    }
    int tmp = m_email.find("@");
    string se = m_email.substr(0, tmp);
    tmp = m_s.find(se);
    if (tmp != -1)
        return -300 - tmp;
    for (int i = 0; i < m_s.length() - 2; i++)
    {
        if (m_s[i] == m_s[i + 1] && m_s[i] == m_s[i + 2])
            return -400 - i;
    }
    if (!hasSpecial)
        return -5;
    if (has_invalid != -1) return has_invalid;
    
    return -10;
}
int findMax(int arr[], int num)
{
    int max = arr[0];
    for (int i = 1; i < num; i++)
    {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int counts[100] = {};
    int lengths[100] = {};
    for (int i = 0; i < num_pwds; i++)
    {
        string p1 = arr_pwds[i];
        lengths[i] = p1.length();
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (p1.compare(arr_pwds[j]) == 0) counts[i]++;
        }
    }

    int max_count = findMax(counts, num_pwds);
    for (int i = 0; i < num_pwds; i++)
    {
        if (counts[i] != max_count) lengths[i] = -1;
    }
    int max_length = findMax(lengths, num_pwds);
    for (int i = 0; i < num_pwds; i++)
    {
        if (lengths[i] == max_length) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////