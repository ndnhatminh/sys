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

void update_HP(int &HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    else if (HP < 0)
    {
        HP = 0;
    }
}

void update_EXP(int &EXP)
{
    if (EXP > 600)
    {
        EXP = 600;
    }
    else if (EXP < 0)
    {
        EXP = 0;
    }
}

void update_M(int &M)
{
    if (M > 3000)
    {
        M = 3000;
    }
    else if (M < 0)
    {
        M = 0;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    update_EXP(exp1);
    update_EXP(exp2);
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    else 
    {
        //Case 1
        if (e1 < 4)
        {
            switch (e1)
            {
                case 0:
                    exp2 += 29;
                    update_EXP(exp2);
                    break;
                case 1:
                    exp2 += 45;
                    update_EXP(exp2);
                    break;
                case 2:
                    exp2 += 75;
                    update_EXP(exp2);
                    break;
                case 3:
                    exp2 += (29+45+75);
                    update_EXP(exp2);
                    break;
            }
            int D = e1*3 + exp1*7;
            if (D % 2 == 0)
            {
                exp1 = ceil(exp1 + D/200.);
                update_EXP(exp1);
            }
            else
            {
                exp1 = ceil(exp1 - D/100.);
                update_EXP(exp1);
            }
        }
        //Case 2
        else if (e1 >= 4 && e1 <= 99)
        {
            if (e1 >= 4 && e1 <= 19)
            {
                exp2 = ceil(exp2 + e1/4. + 19);
                update_EXP(exp2);
            }
            else if (e1 >= 20 && e1 <= 49)
            {
                exp2 = ceil(exp2 + e1/9. + 21);
                update_EXP(exp2);
            }
            else if (e1 >= 50 && e1 <= 65)
            {
                exp2 = ceil(exp2 + e1/16. + 17);
                update_EXP(exp2);
            }
            else if (e1 >= 66 && e1 <= 79)
            {
                exp2 = ceil(exp2 + e1/4. + 19);
                update_EXP(exp2);
                if (exp2 > 200)
                {
                    exp2 = ceil(exp2 + e1/9. + 21);
                    update_EXP(exp2);
                }
            }
            else
            {
                exp2 = ceil(exp2 + e1/4. + 19);
                update_EXP(exp2);
                exp2 = ceil(exp2 + e1/9. + 21);
                update_EXP(exp2);
                if (exp2 > 400)
                {
                    exp2 = ceil(exp2 + e1/16. + 17);
                    update_EXP(exp2);
                    exp2 = ceil((exp2/100.)*115);
                    update_EXP(exp2);
                }
            }
            exp1 -= e1;
            update_EXP(exp1);
        }
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    else
    {
        update_EXP(EXP1);
        update_HP(HP1);
        update_M(M1);
        int S1 = 0;
        int S2 = 0;
        int a = EXP1;
        double P1 = 0;
        double P2 = 0;
        double P3 = 0;
        double final_P = 0;
            Road_1:
        for (int i = 1; i <= EXP1; i++)
        {
            if (abs(EXP1 - i*i) < a)
            {
                a = EXP1 - i*i;
                S1 = i*i;
            }
        }
        if (EXP1 >= S1)
        {
            P1 = 100;
        }
        else
        {
            P1 = ((EXP1/S1 + 80)/123.)*100;
        }
        Road_2:
        int money_start = ceil(M1/2.);
        if (E2 % 2 == 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + HP1*0.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 + HP1*0.1);
                M1 -= 70;
            }
            update_HP(HP1);
            update_M(M1);
            if (M1 == 0)
            {
                goto A;
            }
            if (EXP1 < 400)
            {
                M1 -= 200;
            }
            else
            {
                M1 -= 120;
            }
            update_M(M1);
            EXP1 = ceil(EXP1 + EXP1*0.13);
            update_EXP(EXP1);
            if (M1 == 0)
            {
                goto A;
            }
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else
            {
                M1 -= 120;
            }
            update_M(M1);
            EXP1 = ceil(EXP1 - EXP1*0.1);
            update_EXP(EXP1);
        }
        else
        {
            while (M1 >= money_start && M1 != 0)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 + HP1*0.3);
                    M1 -= 150;
                }
                else
                {
                    HP1 = ceil(HP1 + HP1*0.1);
                    M1 -= 70;
                }
                update_HP(HP1);
                update_M(M1);
                if (M1 < money_start)
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
                EXP1 = ceil(EXP1 + EXP1*0.13);
                update_EXP(EXP1);
                update_M(M1);
                if (M1 < money_start)
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
                EXP1 = ceil(EXP1 - EXP1*0.1);
                update_EXP(EXP1);
                update_M(M1);
            }
        }
        A:
        EXP1 = ceil(EXP1 + EXP1*0.17);
        update_EXP(EXP1);
        HP1 = ceil(HP1 - HP1*0.17);
        update_HP(HP1);
        int b = EXP1;
        for (int i = 1; i <= EXP1; i++)
        {
            if (abs(EXP1 - i*i) < b)
            {
                b = EXP1 - i*i;
                S2 = i*i;
            }
        }
        if (EXP1 >= S2)
        {
            P2 = 100;
        }
        else
        {
            P2 = ((EXP1/S2 + 80)/123.)*100;
        }
        Road_3:
        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int E2_copy = E2;
        if (E2_copy < 10)
        {
            P3 = P[E2];
        }
        else
        {
            int sum = E2/10 + E2%10;
            P3 = P[sum%10];
        }
        if (P1 == 100 && P2 == 100 && P3 == 100)
        {
            EXP1 = ceil(EXP1 - EXP1*0.25);
            update_EXP(EXP1);
        }
        else
        {
            final_P = (P1 + P2 + P3)/3.;
            if (final_P < 50)
            {
                HP1 = ceil(HP1 - HP1*0.15);
                update_HP(HP1);
                EXP1 = ceil(EXP1 + EXP1*0.15);
                update_EXP(EXP1);
            }
            else
            {
                HP1 = ceil(HP1 - HP1*0.1);
                update_HP(HP1);
                EXP1 = ceil(EXP1 + EXP1*0.2);
                update_EXP(EXP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    update_EXP(EXP1);
    update_EXP(EXP2);
    update_HP(HP1);
    update_HP(HP2);
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    else
    {
        int taxi_matrix[10][10] = {0};
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                taxi_matrix[i][j] = (E3*j + i*2) * (i-j);
            }
        }
        int a = 0;
        int b = 0;
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                if (taxi_matrix[m][n] > E3*2)
                {
                    a++;
                }
                if (taxi_matrix[m][n] < -E3)
                {
                    b++;
                }
            }
        }
        while (a >= 10)
        {
            a = a/10 + a%10;
        }
        while (b >= 10)
        {
            b = b/10 + b%10;
        }
        int sw = taxi_matrix[a][b];
        if (a == b)
        {
            for (int k = 0; k < 10; k++)
            {
                if (taxi_matrix[k][k] > sw)
                {
                    sw = taxi_matrix[k][k];
                }
            }
            int sum = a + b;
            int l = 0;
            while (l < 10)
            {
                if (sum - l < 10)
                {
                    if (taxi_matrix[l][sum - l] > sw)
                    {
                        sw = taxi_matrix[l][sum - l];
                    }
                }
                l++;
            }
        }
        else
        {
            int sum = a + b;
            int l = 0;
            while (l < 10)
            {
                if (sum - l < 10)
                {
                    if (taxi_matrix[l][sum - l] > sw)
                    {
                        sw = taxi_matrix[l][sum - l];
                    }
                }
                l++;
            }
            int k = 0;
            int diff = 0;
            if (a > b)
            {
                diff = a - b;
                while (k + diff < 10)
                {
                    if (taxi_matrix[k+diff][k] > sw)
                    {
                        sw = taxi_matrix[k+diff][k];
                    }
                    k++;
                }
            }
            else
            {
                diff = b - a;
                while (k + diff < 10)
                {
                    if (taxi_matrix[k][k + diff] > sw)
                    {
                        sw = taxi_matrix[k][k + diff];
                    }
                    k++;
                }
            }
        }
        sw = abs(sw);
        if (abs(taxi_matrix[a][b]) > sw)
        {
            EXP1 = ceil(EXP1 - EXP1*0.12);
            update_EXP(EXP1);
            EXP2 = ceil(EXP2 - EXP2*0.12);
            update_EXP(EXP2);
            HP1 = ceil(HP1 - HP1*0.1);
            update_HP(HP1);
            HP2 = ceil(HP2 - HP2*0.1);
            update_HP(HP2);
            return taxi_matrix[a][b];
        }
        else
        {
            EXP1 = ceil(EXP1 + EXP1*0.12);
            update_EXP(EXP1);
            EXP2 = ceil(EXP2 + EXP2*0.12);
            update_EXP(EXP2);
            HP1 = ceil(HP1 + HP1*0.1);
            update_HP(HP1);
            HP2 = ceil(HP2 + HP2*0.1);
            update_HP(HP2);
            return sw;
        }
    }
    return -1;
}

// Task 4
bool checkDuplicate(string s)
{
    for (int i = 0; i < s.length()-2; i++)
    {
        if (s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            return true;
        }
    }
    return false;
}

int getIndex_1(string s)
{
    for (int i = 0; i < s.length()-2; i++)
    {
        if (s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            return i;
        }
    }
    return -1;

}

bool checkSpecialChar(string s)
{
    string special_char[] = {"@", "#", "%", "$", "!"};
    int number_of_special_char = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s.find(special_char[i]) > s.length())
        {
            number_of_special_char++;
        }
    }
    if (number_of_special_char == 5)
    {
        return true;
    }
    return false;
}

int getIndex_2(string s)
{
    string special_char[] = {"@", "#", "%", "$", "!"};
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]) && !isalpha(s[i]))
        {
            int number_of_special_char = 0;
            for (int j = 0; j < 5; j++)
            {
                if (s[i] == special_char[j][0])
                {
                    number_of_special_char++;
                }
            }
            if (number_of_special_char == 0)
            {
                return i;
            }
        }
    }
    return -1;
}

int checkPassword(const char * s, const char * email) 
{
    // TODO: Complete this function
    string se;
    string pwd = s;
    int number_of_invalid_condition = 0;
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        se += email[i];
    }
    if (pwd.length() < 8)
    {
        return -1;
    }
    else if (pwd.length() > 20)
    {
        return -2;
    }
    else if (pwd.find(se) != string::npos)
    {
        return -(300 + pwd.find(se));
    }
    else if (checkDuplicate(pwd))
    {
        return -(400 + getIndex_1(pwd));
    }
    else if (checkSpecialChar(pwd))
    {
        return - 5;
    }
    else if (getIndex_2(pwd) != -1)
    {
        return getIndex_2(pwd);
    }
    else
    {
        return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
    int pwd_max_appear = 0;
    int pwd_max_length = 0;
    int index = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        int pwd_current_length = strlen(arr_pwds[i]);
        int pwd_current_appear = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                pwd_current_appear++;
            }
        }
        if (pwd_current_appear > pwd_max_appear || (pwd_current_appear == pwd_max_appear && pwd_current_length > pwd_max_length))
        {
            pwd_max_appear = pwd_current_appear;
            pwd_max_length = pwd_current_length;
            index = i;
        }
    }
    return index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////