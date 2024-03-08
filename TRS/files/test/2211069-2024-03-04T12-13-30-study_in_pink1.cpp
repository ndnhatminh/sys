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

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 > 99 || e1 < 0) return -99;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            if (exp2 > 600) exp2 = 600;
        }
        else
        {
            exp2 = exp2 + 29 + 45 + 75;
            if (exp2 > 600) exp2 = 600;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = (exp1 + (D / 200.0)) + 0.999;
            if (exp1 > 600) exp1 = 600;
        }
        else exp1 = (exp1 - (D / 100.0)) + 0.999;
        if (exp1 < 0) exp1 = 0;
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = (exp2 + (e1 / 4.0 + 19)) + 0.999;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = (exp2 + (e1 / 9.0) + 21) + 0.999;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = (exp2 + (e1 / 16.0 + 17)) + 0.999;
            if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = (exp2 + (e1 / 4.0 + 19)) + 0.999;
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 200)
            {
                exp2 = (exp2 + (e1 / 9.0 + 21)) + 0.999;
                if (exp2 > 600) exp2 = 600;
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = (exp2 + (e1 / 4.0 + 19)) + 0.999;
            if (exp2 > 600) exp2 = 600;
            exp2 = (exp2 + (e1 / 9.0 + 21)) + 0.999;
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 400)
            {
                exp2 = (exp2 + (e1 / 16.0 + 17)) + 0.999;
                if (exp2 > 600) exp2 = 600;
                exp2 = (exp2 * 1.15) + 0.999;
                if (exp2 > 600) exp2 = 600;
            }
        }
        exp1 -= e1;
        if (exp1 < 0) exp1 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 > 600) EXP1 = 600;
    // Con đường 01
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    double p1 = 0;
    int s1 = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= s1)
    {
        p1 = 1.0;
    }
    else
    {
        p1 = ((EXP1 * 1.0 / s1) + 80) / 123;
    }
    // Con đường 02
    double k = (M1 * 0.5);
    if (M1 != 0)
    {
        if (E2 % 2 != 0)
        {
            int money = 0;
            while (true)
            {
                if (HP1 < 200)
                {
                    HP1 = (HP1 * 1.3) + 0.999;
                    if (HP1 > 666) HP1 = 666;
                    if (HP1 > 666) HP1 = 666;
                    M1 -= 150;
                    if (M1 < 0) M1 = 0;
                    money += 150;
                    if (money > k) break;
                }
                else
                {
                    HP1 = (HP1 * 1.1) + 0.999;
                    if (HP1 > 666) HP1 = 666;
                    M1 -= 70;
                    if (M1 < 0) M1 = 0;
                    money += 70;
                    if (money > k) break;
                }
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    money += 200;
                }
                else
                {
                    M1 -= 120;
                    money += 120;
                }
                if (M1 < 0) M1 = 0;
                EXP1 = (EXP1 + EXP1 * 0.13) + 0.999;
                if (EXP1 > 600) EXP1 = 600;
                if (money > k) break;
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    money += 100;
                }
                else
                {
                    M1 -= 120;
                    money += 120;
                }
                if (M1 < 0) M1 = 0;
                EXP1 = (EXP1 - EXP1 / 10.0) + 0.999;
                if (money > k) break;
            }
        }
        else
        {
            if (HP1 < 200)
            {
                HP1 = (HP1 + HP1 * 0.3) + 0.999;
                if (HP1 > 666) HP1 = 666;
                M1 -= 150;
                if (M1 < 0) M1 = 0;
            }
            else
            {
                HP1 = (HP1 + HP1 / 10.0) + 0.999;
                if (HP1 > 666) HP1 = 666;
                M1 -= 70;
                if (M1 < 0) M1 = 0;
            }
            if (EXP1 < 400 && M1 != 0)
            {
                M1 -= 200;
                if (M1 < 0) M1 = 0;
                EXP1 = (EXP1 + EXP1 * 0.13) + 0.999;
                if (EXP1 > 600) EXP1 = 600;
            }
            else if (EXP1 >= 400 && M1 != 0)
            {
                M1 -= 120;
                if (M1 < 0) M1 = 0;
                EXP1 = (EXP1 + EXP1 * 0.13) + 0.999;
                if (EXP1 > 600) EXP1 = 600;
            }
            if (EXP1 < 300 && M1 != 0)
            {
                M1 -= 100;
                if (M1 < 0) M1 = 0;
                EXP1 = (EXP1 - EXP1 / 10.0) + 0.999;
            }
            else if (EXP1 >= 300 && M1 != 0)
            {
                M1 -= 120;
                if (M1 < 0) M1 = 0;
                EXP1 = (EXP1 - EXP1 / 10.0) + 0.999;
            }
        }
    }
    EXP1 = (EXP1 + EXP1 * 0.17) + 0.999;
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    HP1 = (HP1 - HP1 * 0.17) + 0.999;
    double p2 = 0;
    int s2 = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= s2)
    {
        p2 = 1;
    }
    else
    {
        p2 = ((EXP1 * 1.0 / s2) + 80) / 123;
    }
    // Con đường 3
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    double p3 = 0;
    if (E2 < 10)
    {
        p3 = P[E2];
    }
    else
    {
        int i = (E2 % 10) + (E2 / 10);
        p3 = P[i % 10];
    }
    if (p1 == 1 && p2 == 1 && p3 == 100)
    {
        EXP1 = (EXP1 - EXP1 * 0.25) + 0.999;
    }
    else
    {
        double xs = (p1 + p2 + p3 / 100.0) / 3.0;
        if (xs < 0.5)
        {
            HP1 = (HP1 - HP1 * 0.15) + 0.999;
            EXP1 = (EXP1 + EXP1 * 0.15) + 0.999;
            if (EXP1 > 600) EXP1 = 600;
        }
        else
        {
            HP1 = (HP1 - HP1 / 10.0) + 0.999;
            EXP1 = (EXP1 + EXP1 * 0.2) + 0.999;
            if (EXP1 > 600) EXP1 = 600;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) return -99;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 > 600) EXP1 = 600;
    if (HP2 < 0) HP2 = 0;
    if (EXP2 < 0) EXP2 = 0;
    if (HP2 > 666) HP2 = 666;
    if (EXP2 > 600) EXP2 = 600;
    int matrix[10][10];
    int count1 = 0; // số giá trị > E3*2
    int count2 = 0; // số giá trị < -E3
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > (E3 * 2))
            {
                count1++;
            }
            if (matrix[i][j] < (-E3))
            {
                count2++;
            }
        }
    }
    while (count1 >= 10)
    {
        count1 = (count1 / 10) + (count1 % 10);
    }
    while (count2 >= 10)
    {
        count2 = (count2 / 10) + (count2 % 10);
    }
    int point = INT_MIN;
    if (count1 > count2)
    {
        for (int i = count1 - count2, j = 0; i < 10 && j < 10; ++i, ++j)
        {
            if (point < matrix[i][j])
            {
                point = matrix[i][j];
            }
        }
    }
    else
    {
        for (int i = 0, j = count2 - count1; i < 10 && j < 10; ++i, ++j)
        {
            if (point < matrix[i][j])
            {
                point = matrix[i][j];
            }
        }
    }
    if (count1 + count2 < 9)
    {
        for (int i = count1 + count2, j = 0; i >= 0 && j < 10; i--, j++)
        {
            if (point < matrix[i][j])
            {
                point = matrix[i][j];
            }
        }
    }
    else
    {
        for (int i = 9, j = count1 + count2 - 9; i >= 0 && j < 10; i--, j++)
        {
            if (point < matrix[i][j])
            {
                point = matrix[i][j];
            }
        }
    }
    point = abs(point);
    if (abs(matrix[count1][count2]) > point)
    {
        EXP1 = (EXP1 - EXP1 * 0.12) + 0.999;
        HP1 = (HP1 - HP1 / 10.0) + 0.999;
        EXP2 = (EXP2 - EXP2 * 0.12) + 0.999;
        HP2 = (HP2 - HP2 / 10.0) + 0.999;
        return matrix[count1][count2];
    }
    else
    {
        EXP1 = (EXP1 + EXP1 * 0.12) + 0.999;
        HP1 = (HP1 + HP1 / 10.0) + 0.999;
        EXP2 = (EXP2 + EXP2 * 0.12) + 0.999;
        HP2 = (HP2 + HP2 / 10.0) + 0.999;
        if (EXP1 > 600) EXP1 = 600;
        if (HP1 > 666) HP1 = 666;
        if (EXP2 > 600) EXP2 = 600;
        if (HP2 > 666) HP2 = 666;
        return point;
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int len = strlen(email);
    int pos = 1;
    for (int i = 0; i < len; ++i)
    {
        if (email[i] == '@')
        {
            pos = i;
            break;
        }
    }
    string email2(email);
    string password(s);
    string se = email2.substr(0, pos);
    int len_s = strlen(s);
    if (len_s < 8) return -1;
    if (len_s > 20) return -2;

    size_t position = password.find(se);
    if (position != string::npos) {
        return -(300 + static_cast<int>(position));
    }
    for (int i = 0; i < len_s - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    int count = 0;
    for (int i = 0; i < len_s; ++i)
    {
        if (s[i] == '@' || s[i] == '$' || s[i] == '%' || s[i] == '#' || s[i] == '!')
        {
            continue;
        }
        else count++;
    }
    if (count == len_s)
    {
        return -5;
    }
    for (int i = 0; i < len_s; ++i)
    {
        if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == '@' || s[i] == '$' || s[i] == '%' || s[i] == '#' || s[i] == '!')
        {
            continue;
        }
        else return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq[num_pwds];
    string arr_pass[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        arr_pass[i] = arr_pwds[i];
    }
    for (int i = 0; i < num_pwds; ++i)
    {
        freq[i] = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (arr_pass[i] == arr_pass[j])
            {
                freq[i]++;
            }
        }
    }
    int max = 0;
    int lenpass = 0;
    int result = -1;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (max <= freq[i])
        {
            if (max == freq[i])
            {
                if ((arr_pass[i].length() > lenpass))
                {
                    result = i;
                    max = freq[i];
                    lenpass = (arr_pass[i].length());
                }
            }
            else
            {
                result = i;
                max = freq[i];
                lenpass = (arr_pass[i].length());
            }
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////