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
void check_variable(int& x, int lower_bound, int upper_bound)
{
    if (x < lower_bound)
    {
        x = lower_bound;
    }
    if (x > upper_bound)
    {
        x = upper_bound;
    }
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || e1 >= 100) return -99;
    check_variable(exp1, 0, 600);
    check_variable(exp2, 0, 600);
    // TODO: Complete this function

    if (e1 <= 3 && e1 >= 0)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            check_variable(exp2, 0, 600);
        }
        if (e1 == 1)
        {
            exp2 += 45;
            check_variable(exp2, 0, 600);
        }
        if (e1 == 2)
        {
            exp2 += 75;
            check_variable(exp2, 0, 600);
        }
        if (e1 == 3)
        {
            exp2 += (29 + 45 + 75);
            check_variable(exp2, 0, 600);
        }
        int D = 3.0 * e1 + 7.0 * exp1;
        if (D % 2 == 0)
        {
            double t = (double)D / 200.0;
            exp1 = ceil((double)exp1 + t);
            check_variable(exp1, 0, 600);
        }
        else
        {
            double t = (double)D / 100.0;
            exp1 = ceil((double)exp1 - t);
            check_variable(exp1, 0, 600);
        }
    }
    else
    {
        // brother
        int case1 = ceil((double)e1 / 4.0 + 19.0);
        int case2 = ceil((double)e1 / 9.0 + 21.0);
        int case3 = ceil((double)e1 / 16.0 + 17.0);
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += case1;
            check_variable(exp2, 0, 600);
        }
        if (e1 >= 20 && e1 <= 49)
        {
            exp2 += case2;
            check_variable(exp2, 0, 600);
        }
        if (e1 >= 50 && e1 <= 65)
        {
            exp2 += case3;
            check_variable(exp2, 0, 600);
        }
        if (e1 >= 66 && e1 <= 79)
        {
            exp2 += case1;
            check_variable(exp2, 0, 600);
            if (exp2 > 200)
            {
                exp2 += case2;
                check_variable(exp2, 0, 600);
            }
        }
        if (e1 >= 80 && e1 <= 99)
        {
            exp2 += (case1 + case2);
            check_variable(exp2, 0, 600);
            if (exp2 > 400)
            {
                exp2 += case3;
                exp2 = exp2 + ceil((double)exp2 * 0.15);
                check_variable(exp2, 0, 600);
            }
        }
        exp1 -= e1;
        check_variable(exp1, 0, 600);
    }
    check_variable(exp1, 0, 600);
    check_variable(exp2, 0, 600);
    return exp1 + exp2;
}
int nearest_square(int n)
{
    int x = sqrt(n);
    int a = x * x, b = (x + 1) * (x + 1);
    if (abs(n - a) < abs(b - n))
        return a;
    else
        return b;
}
void action_path_2_traceLuggage_odd(int& HP1, int& EXP1, int& M1, int begin_M1)
{
    check_variable(HP1, 0, 666);
    check_variable(EXP1, 0, 600);
    check_variable(M1, 0, 3000);
    begin_M1 = ceil((double)begin_M1 / 2);
    if (M1 == 0) return;
    if (HP1 < 200)
    {
        HP1 = ceil(float((double)HP1 * 1.30));
        check_variable(HP1, 0, 666);
        M1 -= 150;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }
        if (M1 < begin_M1)
        {
            return;
        }
    }
    else
    {
        HP1 = ceil(float((double)HP1 * 1.10));
        check_variable(HP1, 0, 666);
        M1 -= 70;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }
        if (M1 <begin_M1)
        {
            return;
        }
    }
    // taxi or horse
    if (EXP1 < 400)
    {
        M1 -= 200;
        EXP1 = ceil(float((double)EXP1 * 1.13));
        check_variable(EXP1, 0, 600);
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

        if (M1 < begin_M1)
        {
            return;
        }
    }
    else
    {
        M1 -= 120;
        EXP1 = ceil(float((double)EXP1 * 1.13));
        check_variable(EXP1, 0, 600);
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

        if (M1 < begin_M1)
        {
            return;
        }
    }
    // homeless
    if (EXP1 < 300)
    {
        M1 -= 100;
        EXP1 = ceil(float((double)EXP1 * 0.9));
        check_variable(EXP1, 0, 600);
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

        if (M1 < begin_M1)
        {
            return;
        }
    }
    else
    {
        M1 -= 120;
        EXP1 = ceil(float((double)EXP1 * 0.9));
        check_variable(EXP1, 0, 600);
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

        if (M1 < begin_M1)
        {
            return;
        }
    }
}
void action_path_2_traceLuggage_even(int& HP1, int& EXP1, int& M1)
{
    check_variable(HP1, 0, 666);
    check_variable(EXP1, 0, 600);
    check_variable(M1, 0, 3000);
    if (M1 == 0) return;
    if (HP1 < 200)
    {
        HP1 = ceil(float((double)HP1 * 1.30));
        check_variable(HP1, 0, 666);
        M1 -= 150;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

    }
    else
    {
        HP1 = ceil(float((double)HP1 * 1.10));
        check_variable(HP1, 0, 666);
        M1 -= 70;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

    }
    // taxi or horse
    if (EXP1 < 400)
    {
        M1 -= 200;
        EXP1 = ceil(float((double)EXP1 * 1.13));
        check_variable(EXP1, 0, 600);
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }
    }
    else
    {
        EXP1 = ceil(float((double)EXP1 * 1.13));
        check_variable(EXP1, 0, 600);
        M1 -= 120;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }

    }
    // homeless
    if (EXP1 < 300)
    {
        EXP1 = ceil(float((double)EXP1 * 0.9));
        check_variable(EXP1, 0, 600);
        M1 -= 100;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }
    }
    else
    {
        EXP1 = ceil(float((double)EXP1 * 0.9));
        check_variable(EXP1, 0, 600);
        M1 -= 120;
        if (M1 < 0)
        {
            M1 = 0;
            return;
        }
    }

}
int sum_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    // TODO: Complete this function
    double p_1 = 0.0, p_2 = 0.0, p_3 = 0.0;
    check_variable(M1, 0, 3000);
    check_variable(HP1, 0, 666);
    check_variable(EXP1, 0, 600);

    //path 01:
    int S = nearest_square(EXP1);
    if (EXP1 >= S)
    {
        p_1 = 1;
    }
    else
    {
        p_1 = ((double)EXP1 / (double)S + 80.0) / 123.0;
    }
    //path 02:
    int begin_M1 = M1;
    if (E2 % 2)
    {
        while (1)
        {
            action_path_2_traceLuggage_odd(HP1, EXP1, M1, begin_M1);
            if (M1 <= ceil((double)begin_M1 / 2))
            {
                break;
            }
        }
        HP1 = ceil(float((double)HP1 * 0.83));
        EXP1 = ceil(float((double)EXP1 * 1.17));
        check_variable(HP1, 0, 666);
        check_variable(EXP1, 0, 600);

    }
    else
    {
        action_path_2_traceLuggage_even(HP1, EXP1, M1);
        HP1 = ceil(float((double)HP1 * 0.83));
        EXP1 = ceil(float((double)EXP1 * 1.17));
        check_variable(HP1, 0, 666);
        check_variable(EXP1, 0, 600);
    }
    int S2 = nearest_square(EXP1);
    if (EXP1 >= S2)
    {
        p_2 = 1;
    }
    else
    {
        p_2 = ((double)EXP1 / (double)S2 + 80.0) / 123.0;
    }
    //path 03:
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int sum_digit = sum_digits(E2);
    p_3 = (double)P[sum_digit % 10] / 100.0;
    double average = (p_1 + p_2 + p_3) / 3.0;
    if (p_1 == 1 && p_2 == 1 && p_3 == 1)
    {

        EXP1 = ceil((double)EXP1 * 0.75);

        check_variable(EXP1, 0, 600);
        return HP1 + EXP1 + M1;
    }
    if (average >= 0.5)
    {
        HP1 = ceil((double)HP1 * 0.9);
        EXP1 = ceil((double)EXP1 * 1.2);
        check_variable(HP1, 0, 666);
        check_variable(EXP1, 0, 600);
    }
    else
    {
        HP1 = ceil((double)HP1 * 0.85);
        EXP1 = ceil((double)EXP1 * 1.15);
        check_variable(HP1, 0, 666);
        check_variable(EXP1, 0, 600);
    }
    check_variable(HP1, 0, 666);
    check_variable(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    int a[11][11];
    check_variable(HP1, 0, 666);
    check_variable(EXP1, 0, 600);
    check_variable(HP2, 0, 666);
    check_variable(EXP2, 0, 600);

    memset(a, 0, sizeof(a));
    int count_larger = 0; // > E3*2
    int count_smaller = 0; // < -E3
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > E3 * 2)
            {
                count_larger++;
            }
            if (a[i][j] < -E3)
            {
                count_smaller++;
            }
        }
    }
    while (count_larger > 9) count_larger = sum_digits(count_larger);
    while (count_smaller > 9) count_smaller = sum_digits(count_smaller);
    int taxi_score = a[count_larger][count_smaller];
    // cout<<count_larger<<" "<<count_smaller<<endl;
    // cout<<taxi_score<<endl;
    int chase_score = -10000;
    // check left dianogal
    int i = count_larger, j = count_smaller;
    while (i >= 0 && j >= 0)
    {
        chase_score = max(chase_score, a[i][j]);
        i--;
        j--;
    }
    i = count_larger, j = count_smaller;
    while (i >= 0 && j < 10)
    {
        chase_score = max(chase_score, a[i][j]);
        i--;
        j++;
    }
    i = count_larger, j = count_smaller;
    while (i < 10 && j < 10)
    {
        chase_score = max(chase_score, a[i][j]);
        i++;
        j++;
    }
    i = count_larger, j = count_smaller;
    while (i < 10 && j >= 0)
    {
        chase_score = max(chase_score, a[i][j]);
        i++;
        j--;
    }
    if (abs(taxi_score) > abs(chase_score))
    {
        HP1 = ceil(float((double)HP1 * 0.9));
        EXP1 = ceil(float((double)EXP1 * 0.88));
        EXP2 = ceil(float((double)EXP2 * 0.88));
        HP2 = ceil(float((double)HP2 * 0.9));
        check_variable(HP1, 0, 666);
        check_variable(EXP1, 0, 600);
        check_variable(EXP2, 0, 600);
        check_variable(HP2, 0, 666);

        return taxi_score;
    }
    else
    {
        HP1 = ceil(float((double)HP1 * 1.1));
        EXP1 = ceil(float((double)EXP1 * 1.12));
        EXP2 = ceil(float((double)EXP2 * 1.12));
        HP2 = ceil(float((double)HP2 * 1.1));
        check_variable(HP1, 0, 666);
        check_variable(EXP1, 0, 600);
        check_variable(EXP2, 0, 600);
        check_variable(HP2, 0, 666);

        return chase_score;
    }

    return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string alphabet_num_special = "abcdefghijklmnopqrstuvwxyz!@#$\\%\\ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int n = strlen(s);
    int m = strlen(email);
    string se = "";
    int se_len = 0;
    for (int i = 0; i < m; i++)
    {
        if (email[i] == '@')
            break;
        se_len++;
        se += email[i];
    }
    if (n < 8)
        return -1;
    if (n > 20)
        return -2;
    if(se == "")
        return -300;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == se[0])
        {
            bool flag = true;
            for (int j = 0; j < se_len; j++)
            {
                if (i + j > n - 1)
                {
                    flag = false;
                    break;
                }
                if (s[i + j] != se[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return -(300 + i);
            }
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            return -(400 + i);
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            flag = false;
        }
    }
    if (flag)
    {
        return -5;
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < (int)alphabet_num_special.size(); j++)
        {
            if (s[i] == alphabet_num_special[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return i;
        }
    }
    return -10;

}
int str_cmp(string s, string t)
{
    if (s.length() != t.length())
    {
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            return 0;
        }
    }
    return 1;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int mx = 0;
    int count = 0;
    string max_pwd;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = i; j < num_pwds; j++)
        {
            if (str_cmp(arr_pwds[i], arr_pwds[j]))
            {
                count++;

            }
        }
        if (count == mx)
        {
            if (max_pwd.length() < strlen(arr_pwds[i]))
            {
                max_pwd = arr_pwds[i];
                mx = count;
            }
        }
        else if (count > mx)
        {
            mx = count;
            max_pwd = arr_pwds[i];
        }
        // cout<<max<<" "<< max_pwd<<endl;
        count = 0;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        if (str_cmp(arr_pwds[i], max_pwd))
        {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////