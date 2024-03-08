#include "study_in_pink1.h"
#define epsilon 0.00001

int new_int(double x);
void roundHP(int & HP);
void roundEXP(int & EXP);
void roundM(int & M);
void roundE(int & E);
int recur_short_number(int number);
bool ischaracter(char c, int & count_spe);

typedef struct
{
    char password[30];
    int time_showup;
    int length;
    int place;
} PASSWORD;

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
)
{
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
int firstMeet(int & exp1, int & exp2, int e1)
{
    // TODO: Complete this function
    roundE(e1); roundEXP(exp1); roundEXP(exp2);
    if (e1 <= 3)
    {
        switch(e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 +=75;
            break;
        case 3:
            exp2 += (29 + 45 + 75);
            break;
        }
        roundEXP(exp2);

        int d = e1 * 3 + exp1 * 7;

        if (d % 2 == 0)
        {
            exp1 = new_int(exp1 + d/200.0);
        }
        else
        {
            exp1 = new_int(exp1 - d/100.0);
        }
        roundEXP(exp1);
    }
    else
    {
        if (e1 <= 19)
        {
            exp2 += new_int(e1/4.0 + 19);
        }
        else if (e1 <= 49)
        {
            exp2 += new_int(e1/9.0 + 21);
        }
        else if (e1 <= 65)
        {
            exp2 += new_int(e1/16.0 + 17);
        }
        else if (e1 <= 79)
        {
            exp2 += new_int(e1/4.0 + 19); roundEXP(exp2);
            exp2 += (exp2 > 200) ? (new_int(e1/9.0 + 21)) : 0;
        }
        else if (e1 <= 99)
        {
            exp2 += new_int(e1/4.0 + 19); roundEXP(exp2);
            exp2 += new_int(e1/9.0 + 21); roundEXP(exp2);
            if (exp2 > 400)
            {
                exp2 += new_int(e1/16.0 + 17); roundEXP(exp2);
                exp2 = new_int(exp2 * 1.15);
            }
        }
        roundEXP(exp2);
        exp1 -= e1; roundEXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    // TODO: Complete this function
    roundHP(HP1); roundEXP(EXP1); roundM(M1); roundE(E2);
    // first way
    double P1, P2;
    int s = sqrt(EXP1);
    if (EXP1 - (s * s) <= (s + 1)  * (s + 1) - EXP1)
    {
        P1 = 100;
    }
    else
    {
        P1 = new_int((float(EXP1) / ((s + 1) * (s + 1)) + 80) / 123 * 100);
    }

    // second way
    int money_lose = 0;
    if (E2 % 2 == 1)
    {
        double  max = M1 / 2.0;
        for(int i = 0; money_lose <= max; i++)
        {
            switch (i % 3)
            {
            case 0:
                // su kien 1
                if (HP1 < 200)
                {
                    HP1 = new_int(HP1 * 1.3);
                    M1 -= 150;
                    money_lose += 150;
                }
                else
                {
                    HP1 = new_int(HP1 * 1.1);
                    M1 -= 70;
                    money_lose += 70;
                }
                break;
            case 1:
                // su kien 2
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    money_lose += 200;
                }
                else
                {
                    M1 -= 120;
                    money_lose += 120;
                }
                EXP1 = new_int(EXP1 * 1.13);
                break;
            case 2:
                // su kien 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    money_lose += 100;
                }
                else
                {
                    M1 -= 120;
                    money_lose += 120;
                }
                EXP1 = new_int(EXP1 * 0.9);
                break;
            }
            roundHP(HP1);
            roundEXP(EXP1);
            roundM(M1);
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            switch (i % 3)
            {
            case 0:
                // su kien 1
                if (HP1 < 200)
                {
                    HP1 = new_int(HP1 * 1.3);
                    M1 -= 150;
                }
                else
                {
                    HP1 = new_int(HP1 * 1.1);
                    M1 -= 70;
                }
                break;
            case 1:
                // su kien 2
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                EXP1 = new_int(EXP1 * 1.13);
                break;
            case 2:
                // su kien 3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                }
                else
                {
                    M1 -= 120;
                }
                EXP1 = new_int(EXP1 * 0.9);
                break;
            }
            roundHP(HP1);
            roundEXP(EXP1);
            roundM(M1);
            if (M1 == 0)
            {
                break;
            }
        }
    }

    HP1 = new_int(HP1 * 0.83); roundHP(HP1);
    EXP1 = new_int(EXP1 * 1.17); roundEXP(EXP1);

    s = sqrt(EXP1);
    if (EXP1 - (s * s) <= (s + 1)  * (s + 1) - EXP1)
    {
        P2 = 100;
    }
    else
    {
        P2 = new_int((float(EXP1) / ((s + 1) * (s + 1)) + 80) / 123 * 100);
    }
    // third way
    int i;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    if (E2 < 10)
    {
        i = E2;
    }
    else 
    {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    int P3 = P[i];

    if (P1 + P2 + P3 == 300)
    {
        EXP1 = new_int(EXP1 * 0.75);
    }
    else
    {
        double P_average = (P1 + P2 + P3) / 3.0;
        if (P_average < 50)
        {
            HP1 = new_int(HP1 * 0.85);
            EXP1 = new_int(EXP1 * 1.15);
        }
        else
        {
            HP1 = new_int(HP1 * 0.9);
            EXP1 = new_int(EXP1 * 1.2);
        }
        roundHP(HP1);
        roundEXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    // TODO: Complete this function
    int matrix[10][10] = {}; // Set all to zero
    int greater_count = 0;
    int less_count = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3 * 2)
            {
                greater_count += 1;
            }
            else if (matrix[i][j] < -E3)
            {
                less_count += 1;
            }
        }
    }
    int row_idx = recur_short_number(greater_count);
    int col_idx = recur_short_number(less_count);

    int taxi_point = matrix[row_idx][col_idx];

    int sherlock_point = 0;
    for (int i = 0,
            check_point_right = row_idx + col_idx,
            check_point_left = row_idx - col_idx; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((i + j == check_point_right) || (i - j == check_point_left))
            {
                if(sherlock_point < matrix[i][j])
                {
                    sherlock_point = matrix[i][j];
                }
            }
        }
    }

    if (abs(sherlock_point) < abs(taxi_point))
    {
        EXP1 = new_int(EXP1 * 0.88); EXP2 = new_int(EXP2 * 0.88);
        HP1 = new_int(HP1 * 0.9); HP2 = new_int(HP2 * 0.9);
        roundEXP(EXP1); roundEXP(EXP2);
        roundHP(HP1); roundHP(HP2);
        return taxi_point;
    }
    else
    {
        EXP1 = new_int(EXP1 * 1.12); EXP2 = new_int(EXP2 * 1.12);
        HP1 = new_int(HP1 * 1.1); HP2 = new_int(HP2 * 1.1);
        roundEXP(EXP1); roundEXP(EXP2);
        roundHP(HP1); roundHP(HP2);
        return sherlock_point;
    }
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    // TODO: Complete this function

    // Valid length
    int length = strlen(s);
    if (length < 8)
    {
        return -1;
    }
    if (length > 20)
    {
        return -2;
    }
    // Check se sub-string
    char email_fake[50];
    for(int i = 0, max=strlen(email); i <= max; i++)
    {
        email_fake[i] = email[i];
    }

        // Get the sub-string se
        char * token = strtok(email_fake, "@");

        const char * isin = strstr(s, token);
        if (isin)
        {
            int index = isin - s;
            return - 300 - index;
        }

    // Check for multiple character
    for (int i = 1, max = length - 2; i <= max; i++)
    {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2]))
        {
            return - 400 - i;
        }
    }

    // Check for valif special-character
    int count_spe = 0;

    for (int i = 0; i < length; i++)
    {
        if(!ischaracter(s[i], count_spe))
        {
            return i; // Check for a valid password (number and alphabet)
        }
    }

    if (count_spe == 0)
    {
        return -5;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    PASSWORD pwd_db[30]; // Thay doi so 30 de tranh bi loi qua it mat khau
    int db_size = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        // Neu da co trong db thi tang len 1
        int flag = -1;
        for (int j = 0; j < db_size; j++)
        {
            if (strcmp(pwd_db[j].password, arr_pwds[i]) == 0)
            {
                pwd_db[j].time_showup +=1;
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            continue;
        }
        // Khong co trong db
        strcpy(pwd_db[db_size].password, arr_pwds[i]);
        pwd_db[db_size].time_showup = 1;
        pwd_db[db_size].place = i;
        db_size += 1;
    }

    int max_idx = 0;
    for (int i = 0; i < db_size; i++)
    {
        if (pwd_db[i].time_showup > pwd_db[max_idx].time_showup)
        {
            max_idx = i;
        }
        if (pwd_db[i].time_showup == pwd_db[max_idx].time_showup)
        {
            max_idx = (pwd_db[i].length >= pwd_db[max_idx].length) ? i : max_idx;
        }
    }

    return pwd_db[max_idx].place;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
int recur_short_number(int number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        return recur_short_number(number / 10 + number % 10);
    }
}
void roundHP(int & HP)
{
    if (HP >= 666)
    {
        HP = 666;
    }
    if (HP <= 0)
    {
        HP = 0;
    }
}

void roundEXP(int & EXP)
{
    if (EXP >= 600)
    {
        EXP = 600;
    }
    if (EXP <= 0)
    {
        EXP = 0;
    }
}

void roundM(int & M)
{
    if (M >= 3000)
    {
        M = 3000;
    }
    if (M <= 0)
    {
        M = 0;
    }
}

void roundE(int & E)
{
    if (E >= 666)
    {
        E = 666;
    }
    if (E <= 0)
    {
        E = 0;
    }
}

int new_int(double x)
{
    if(abs(x - int(x)) <= epsilon)
    {
        return int(x);
    }
    if(abs(x - (int(x) + 1)) <= epsilon)
    {
        return int(x) + 1;
    }
    return floor(x) + 1;
}
bool ischaracter(char c, int & count_spe)
{
    if(isalpha(c))
    {
        return true;
    }

    char special_character[5] = {'@', '#', '%', '$', '!'};

    for (int i = 0; i < 5; i++)
    {
        if (c == special_character[i])
        {
            count_spe += 1;
            return true;
        }
    }
    return false;
}
