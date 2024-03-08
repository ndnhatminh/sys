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

// My function
void fix_exp(int &exp)
{
    if (exp > 600)
        exp = 600;
    
    if (exp < 0)
        exp = 0;
}

void fix_hp(int &hp)
{
    if (hp > 666)
        hp = 666;

    if (hp < 0)
        hp = 0;
}

void fix_money(int &money)
{
    if (money < 0)
        money = 0;
    
    if (money > 3000)
        money = 3000;
}

int Square(int EXP1)
{
    int tmp = sqrt(EXP1);
    
    if (tmp * tmp != EXP1)
    {
        int t1 = ceil(sqrt(EXP1));
        int t2 = floor(sqrt(EXP1));
        int square_1 = t1 * t1;
        int square_2 = t2 * t2;
        if (square_1 - EXP1 < EXP1 - square_2)
            return square_1;
        else return square_2;
    }
    return EXP1;
}

int sum_digit(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n/= 10;
    }
    return sum;
}

int reduceNum(int n)
{
    while(n > 9)
    {
        n = sum_digit(n);
    }
    return n;
}
// END my func

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
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
        else
        {
            exp2 += 29 + 45 + 75;
        }

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 != 0)
        {
            exp1 = ceil(exp1 - D/100.0);
        }
        else
        {
            exp1 = ceil(exp1 + D/200.0);
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 <= 19)
        {
            exp2 = ceil(exp2 + e1/4.0 + 19);
        }
        else if (e1 <= 49)
        {
            exp2 = ceil(exp2 + e1/9.0 + 21);
        }
        else if (e1 <= 65)
        {
            exp2 = ceil(exp2 + e1/16.0 + 17);
        }
        else if (e1 <= 79)
        {
            exp2 = ceil(exp2 + e1/4.0 + 19);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + e1/9.0 + 21);
            }
        }
        else
        {
            exp2 = ceil(exp2 + e1/4.0 + 19);
            exp2 = ceil(exp2 + e1/9.0 + 21);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + e1/16.0 + 17);
                exp2 = ceil(exp2 * 115.0 / 100);
            }
        }
        fix_exp(exp1);
        exp1 -= e1;
    }
    else
    {
        return -99;
    }
    fix_exp(exp1);
    fix_exp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    double p1,p2,p3;

    // Road 1
    int S = Square(EXP1);
    if (EXP1 >= S)
        p1 = 100.0;
    else
        p1 = (1.0 * EXP1 / S + 80) / 123 * 100;
    // End Road 1

    //Road 2
        double half = M1/2.0;
        int paid = 0;
        if (E2 % 2 == 1)
        {
            while(true)
            {
                if (M1 == 0) break;
                // food and drink
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 * 13.0 / 10);
                    fix_hp(HP1);

                    M1 -= 150;
                    fix_money(M1);
                    paid += 150;
                }
                else
                {
                    HP1 = ceil(HP1 * 11.0 / 10);//1.1
                    fix_hp(HP1);

                    M1 -= 70;
                    fix_money(M1);
                    paid += 70;
                }
                if (paid > half) break;

                // Taxi or horse
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    fix_money(M1);
                    paid += 200;
                }
                else
                {
                    M1 -= 120;
                    fix_money(M1);
                    paid += 120;
                }
                EXP1 = ceil(EXP1 * 113.0 / 100);//1.13
                fix_exp(EXP1);
                if (paid > half) break;

                // Homeless
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    fix_money(M1);
                    paid += 100;
                }
                else
                {
                    M1 -= 120;
                    fix_money(M1);
                    paid += 120;
                }
                EXP1 = ceil(EXP1 * 9.0 / 10);
                fix_exp(EXP1);
                if (paid > half) break;

            }
            HP1 = ceil(HP1 * 83.0 / 100);//0.83
            EXP1 = ceil(EXP1 * 117.0 / 100);//1.17
            fix_hp(HP1);
            fix_exp(EXP1);

        }
        else
        {
            while(true)
            {
                // food and drink
                if (M1 == 0) break;
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 * 13.0 / 10);//1.3
                    fix_hp(HP1);
                    
                    M1 -= 150;
                    fix_money(M1);
                }
                else
                {
                    HP1 = ceil(HP1 * 11.0 / 10);//1.1
                    fix_hp(HP1);

                    M1 -= 70;
                    fix_money(M1);
                }
                if (M1 == 0)
                    break;

                // Taxi or horse
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    fix_money(M1);
                }
                else
                {
                    M1 -= 120;
                    fix_money(M1);
                }
                EXP1 = ceil(EXP1 * 113.0 / 100);//1.13
                fix_exp(EXP1);
                if (M1 == 0)
                    break;

                // Homeless
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    fix_money(M1);
                }
                else
                {
                    M1 -= 120;
                    fix_money(M1);
                }
                EXP1 = ceil(EXP1 * 9.0 / 10);// 0.9
                fix_exp(EXP1);
                break;
            }
            
            HP1 = ceil(HP1 * 83.0 / 100); // 0.83
            EXP1 = ceil(EXP1 * 117.0 / 100);//1.17
            fix_hp(HP1);
            fix_exp(EXP1);
            
        }

        int S2 = Square(EXP1);
        if (EXP1 >= S2)
            p2 = 100.0;
        else
            p2 = (1.0 * EXP1 / S2 + 80) / 123 * 100;
    // End road 2

    // Road 3
        double P[] = {32.0,47.0,28.0,79.0,100.0,50.0,22.0,83.0,64.0,11.0};
        int index;

        if (E2 < 10)
            index = E2;
        else
        {
            int sum = E2 / 10 + E2 % 10;
            index = sum % 10;
        }
        p3 = P[index];

    // End road 3

    if (p1 == 100.0 && p2 == 100.0 && p3 == 100.0)
        EXP1 = ceil(EXP1 * 75.0 / 100);
    else
    {
        double avg_p = (p1 + p2 + p3)/3.0;

        if (avg_p < 50.0)
        {
            HP1 = ceil(HP1 * 85.0 / 100);// 0.85
            EXP1 = ceil(EXP1 * 115.0 / 100);
        }
        else
        {
            HP1 = ceil(HP1 * 9.0 / 10);// 0.9
            EXP1 = ceil(EXP1 * 12.0 / 10);//1.2
        }
    }

    fix_exp(EXP1);
    fix_hp(HP1);
    fix_money(M1);

    return EXP1 + HP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a[10][10];
    if (E3 < 0 || E3 > 99)
        return -99;

    for (int i = 0 ; i < 10 ; ++ i )
        for (int j = 0 ; j < 10 ; ++ j)
            a[i][j] = 0;
    
    // I --> the amount of nums that greater than E3 * 2
    // J --> the amount of nums that smaller than -E3
    int I = 0, J = 0;

    for (int i = 0 ; i < 10 ; ++ i)
    {
        for (int j = 0 ; j < 10 ; ++ j)
        {
            a[i][j] = ((E3 * j) + i * 2) * (i - j);
            if (a[i][j] > E3 * 2)
                ++I;
            if (a[i][j] < -E3)
                ++J;
        }
    }

    I = reduceNum(I);
    J = reduceNum(J);
    
    int max_right = a[I][J];
    int max_left = a[I][J];

    //Left
    int col_1 = J;
    int row_1 = I;
    while(row_1 >= 0 && col_1 >= 0)
    {
        max_left = max(max_left, a[row_1--][col_1--]);
    }
    col_1 = J; row_1 = I;
    while(col_1 <= 9 && row_1 <= 9)
    {
        max_left = max(max_left, a[row_1++][col_1++]);
    }

    //Right
    int col_2 = J;
    int row_2 = I;
    while(col_2 <= 9 && row_2 >= 0)
    {
        max_right = max(max_right, a[row_2--][col_2++]);
    }
    col_2 = J; row_2 = I;
    while(row_2 <= 9 && col_2 >= 0)
    {
        max_right = max(max_right, a[row_2 ++][col_2--]);
    }

    int my_score = max(max_right, max_left);

    if (abs(a[I][J]) <= my_score)
    {
        EXP1 = ceil(EXP1 * 112.0 / 100);//1.12
        EXP2 = ceil(EXP2 * 112.0 / 100);

        HP1 = ceil(HP1 * 11.0 / 10);//1.1
        HP2 = ceil(HP2 * 11.0 / 10);
    }
    else
    {
        EXP1 = ceil(EXP1 * 88.0 / 100);//0.88
        EXP2 = ceil(EXP2 * 88.0 / 100);

        HP1 = ceil(HP1 * 9.0 / 10);//0.9
        HP2 = ceil(HP2 * 9.0 / 10);
    }

    fix_exp(EXP1);
    fix_exp(EXP2);
    fix_hp(HP1);
    fix_hp(HP2);

    return (abs(a[I][J]) > my_score ? a[I][J] : my_score);
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int pass_len = strlen(s);
    string my_s = "";
    string my_email = "";
    for (int i = 0 ; i < strlen(s); ++ i)
        my_s += s[i];
    for (int i = 0 ; i < strlen(email) ; ++ i)
        my_email += email[i];

    if (pass_len < 8)
        return -1;
    
    if (pass_len > 20)
        return -2;
    
    string se = "";
    for (int i = 0 ; i < pass_len; ++ i)
    {
        if (email[i] == '@')
            break;
        se += email[i];
    }
    if (my_s.find(se) != string::npos)
        return -(300 + my_s.find(se));
    
    if (my_s[pass_len - 1] == '*')
        my_s.push_back('?');
    else    
        my_s.push_back('*');
    int cnt = 1;
    for (int i = 0 ; i < pass_len; ++ i)
    {
        if (my_s[i] == my_s[i + 1])
            ++cnt;
        else
        {
            if (cnt >= 3)
                return -(400 + (i - cnt + 1));
            else
                cnt = 1;
        }
    }
    my_s.pop_back();

    bool have_special = false;
    for (int i = 0 ; i < pass_len ; ++ i)
    {
        if (my_s[i] == '@' || my_s[i] == '#' || my_s[i] == '%' || my_s[i] == '$' || my_s[i] == '!')
        {
            have_special = true;
            break;
        }
    }
    if (!have_special)
        return -5;
    
    for (int i = 0 ; i < pass_len ; ++ i)
    {
        if (!isalpha(my_s[i])
            && !isdigit(my_s[i])
            && my_s[i] != '@'
            && my_s[i] != '#'
            && my_s[i] != '%'
            && my_s[i] != '$'
            && my_s[i] != '!')
                return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    pair<string, int> a[num_pwds];
    int index = 0;

    for (int i = 0 ; i < num_pwds ; ++ i)
    {
        bool isFind = false;
        for (int j = 0 ; j < i ; ++ j)
        {
            if (a[j].first == arr_pwds[i])
            {
                a[j].second++;
                isFind = true;
                break;
            }
        }
        if (!isFind)
        {
            a[index].first = arr_pwds[i];
            a[index].second = 1;
            ++index;
        }
    }

    int max_freq = INT_MIN;
    string res = "";
    for (int i = 0 ; i < index ; ++ i)
    {
        if (max_freq < a[i].second)
        {
            max_freq = a[i].second;
            res = a[i].first;
        }
    }

    for (int i = 0 ; i < index ; ++ i)
    {
        if (max_freq == a[i].second)
        {
            if (res.size() < a[i].first.size())
                res = a[i].first;
        }
    }

    for (int i = 0 ; i < num_pwds ; ++ i)
    {
        if (res == arr_pwds[i])
        {
            return i;
        }
    }
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////