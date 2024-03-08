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
int firstMeet(int& exp1, int& exp2, int e1) {
    if ((e1 >= 0) && (e1 <= 3))
    {
        return case_1(exp1, exp2, e1);
    }
    else if ((e1 >= 4) && (e1 <= 99))
    {
        return case_2(exp1, exp2, e1);
    }
    else
        return -99;
    
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if ((E2 >= 0) && (E2 <= 99))            //new
    {

        double P1 = probability(EXP1);
        road02(HP1, M1, EXP1, E2);
        double P2 = probability(EXP1);
        double P3 = road03(E2) / 100.0;
        if ((P1 == 1) && (P2 == 1) && (P3 == 1))
        {
            exp_caculate(EXP1, EXP1 * 25.0 / 100, 0);
        }
        else
        {
            double P = (P1 + P2 + P3) / 3;
            if (P < 0.5)
            {
                HP_caculate(HP1, HP1 * 15.0 / 100, 0);
                exp_caculate(EXP1, EXP1 * 15.0 / 100, 1);
            }
            else
            {
                HP_caculate(HP1, HP1 * 10.0 / 100, 0);
                exp_caculate(EXP1, EXP1 * 20.0 / 100, 1);
            }
        }
        return HP1 + EXP1 + M1;
    }
    else
    {
        return -99;
    }
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if ((E3 >= 0) && (E3 <= 99))     
    {
        //Set the matrix of taxi
        int array[10][10] = {};
        int bigger = 0, smaller = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (array[i][j] > E3 * 2)
                {
                    bigger++;
                }
                if (array[i][j] < -E3)
                {
                    smaller++;
                }
            }
        }
        //Find the meeting location
        int row = Sum_of_digits(bigger);
        int col = Sum_of_digits(smaller);
        //Find the marks of Sherlock and Watson at meeting location
        int lmax = left_max(array, row, col);
        int rmax = right_max(array, row, col);
        int SWmark;
        if (lmax > rmax)
        {
            SWmark = lmax;
        }
        else
        {
            SWmark = rmax;
        }
        if (SWmark < 0)
        {
            SWmark = abs(SWmark);
        }
        //Compare
        if (abs(array[row][col]) > SWmark)
        {
            exp_caculate(EXP1, EXP1 * 12.0 / 100, 0);
            exp_caculate(EXP2, EXP2 * 12.0 / 100, 0);
            HP_caculate(HP1, HP1 * 10.0 / 100, 0);
            HP_caculate(HP2, HP2 * 10.0 / 100, 0);
            return array[row][col];
        }
        else
        {
            exp_caculate(EXP1, EXP1 * 12.0 / 100, 1);
            exp_caculate(EXP2, EXP2 * 12.0 / 100, 1);
            HP_caculate(HP1, HP1 * 10.0 / 100, 1);
            HP_caculate(HP2, HP2 * 10.0 / 100, 1);
            return SWmark;
        }
    }
    else
        return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {

        //Find se
        char se[100];
        int i = 0;
        while (*(email + i) != '@')
        {
            *(se + i) = *(email + i);
            i++;
        }
        i -= 1;
        //Find the problem
        int idx = 0;
        int result = -10;
        int num_sp_digit = 0;
        bool digits = true;
        bool contain = true;
        bool repeat = true;
        int loc_digit = -1;
        int loc_contain = -1;
        int loc_repeat = -1;

        while (*(s + idx) != '\0')
        {
            // check digit
            if (!(checkDigits(*(s + idx))))
            {
                if (digits)
                {
                    loc_digit = idx;
                }
                digits = false;
            }
            //check contain
            if (!(checkContain(s, se, idx, i)))
            {
                if (contain)
                {
                    loc_contain = idx;
                }
                contain = false;
            }
            //check repeat
            if (!(checkRepeat(s, idx)))
            {
                if (repeat)
                {
                    loc_repeat = idx;
                }
                repeat = false;
            }
            //check the number of special digits
            num_sp_digit += checkSpecialDigits(*(s + idx));
            idx++;
        }
        if ((idx) < 8)
        {
            result = -1;
        }
        else if ((idx) > 20)
        {
            result = -2;
        }
        else if (!contain)
        {
            result = - (300 + loc_contain );
        }
        else if (!repeat)
        {
            result = -(400 + loc_repeat);
        }
        else if (num_sp_digit == 0)
        {
            result = -5;
        }
        else if (!digits)
        {
            result = loc_digit;
        }
        else
        {
            result = -10;
        }
        return result;
    }


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    
    int row = num_pwds;
    string simp_pwds[30];
    int len_pwds[30] = {};
    int num_of_pwds[30] = {};
    int loc_pwds[30] = {};

    simp_pwds[0] = arr_pwds[0];
    len_pwds[0] = strlen(arr_pwds[0]);
    num_of_pwds[0]++;
    loc_pwds[0] = 0;
    int presentMember = 1;

    for (int i = 1; i < num_pwds; i++)
    {
        bool simp = true;
        for (int iPwds = 0; iPwds < presentMember; iPwds++)
        {
            int j = 0;
            bool repeat = true;
            while (1)
            {
                if ((simp_pwds[iPwds][j]) != arr_pwds[i][j])
                {
                    repeat = false;
                    break;
                }
                else 
                {
                    if ((simp_pwds[iPwds][j] == '\0') && (arr_pwds[i][j] == '\0'))
                    {
                        num_of_pwds[iPwds]++;
                        break;
                    }
                    
                }
                if ((simp_pwds[iPwds][j] == '\0') || (arr_pwds[i][j] == '\0'))
                {
                    repeat = false;
                    break;
                }
                j++;
            }

            if (repeat)
            {
                simp = false;
            }

        }

        if (simp)
        {
            simp_pwds[presentMember] = arr_pwds[i];
            len_pwds[presentMember] = strlen(arr_pwds[i]);
            num_of_pwds[presentMember]++;
            loc_pwds[presentMember] = i;
            presentMember++;
        }
    }
    int max_num = num_of_pwds[0];
    int max_len = len_pwds[0];
    int min_loc = loc_pwds[0];
    for (int i = 0; i < presentMember; i++)
    {
        if (num_of_pwds[i] > max_num)
        {
            max_num = num_of_pwds[i];
            max_len = len_pwds[i];
            min_loc = loc_pwds[i];
        }
        else if (num_of_pwds[i] == max_num)
        {
            if (len_pwds[i] > max_len)
            {
                max_len = len_pwds[i];
                min_loc = loc_pwds[i];
            }
            else if (len_pwds[i] == max_len)
            {
                if (loc_pwds[i] < min_loc)
                {
                    min_loc = loc_pwds[i];
                }
            }
        }
    }

    return min_loc;
}

//Function to return HP, EXP, money to the correct amount
//HP
void health_points(int& HP)
{
    if (HP < 0)
    {
        HP = 0;
    }
    else if (HP > 666)
    {
        HP = 666;
    }
}
//EXP
void experience_points(int& EXP)
{
    if (EXP < 0)
    {
        EXP = 0;
    }
    else if (EXP > 600)
    {
        EXP = 600;
    }
}
//money
void  initial_money(int& M)
{
    if (M < 0)
    {
        M = 0;
    }
    else if (M > 3000)
    {
        M = 3000;
    }
}

//The first meet
//Case 1
int case_1(int& exp1, int& exp2, int e1)
{
    //Watson
        switch (e1)
        {
        case 0:
        {
            exp2 += 29;
            break;
        }
        case 1:
        {
            exp2 += 45;
            break;
        }
        case 2:
        {
            exp2 += 75;
            break;
        }
        case 3:
        {
            exp2 += 149;
            break;
        }
        default:
            break;
        }
        experience_points(exp2);
        //Sherlock
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp_caculate(exp1, (D * 1.0 / 200), 1);
        }
        else
        {
            exp_caculate(exp1, (D * 1.0 / 100), 0);
        }

        return exp1 + exp2;

}
//Case 2
int case_2(int& exp1, int& exp2, int e1)
{
    //Watson
    if ((e1 >= 4) && (e1 <= 19))
    {
        exp_caculate(exp2, (e1 * 1.0 / 4 + 19), 1);
    }
    else if (e1 <= 49)
    {
        exp_caculate(exp2, (e1 * 1.0 / 9 + 21), 1);
    }
    else if (e1 <= 65)
    {
        exp_caculate(exp2, (e1 * 1.0 / 16 + 17), 1);
    }
    else if (e1 <= 79)
    {
        exp_caculate(exp2, (e1 * 1.0 / 4 + 19), 1);
        if (exp2 > 200)
        {
            exp_caculate(exp2, (e1 * 1.0 / 9 + 21), 1);
        }
    }
    else
    {
        exp_caculate(exp2, (e1 * 1.0 / 4 + 19), 1);
        exp_caculate(exp2, (e1 * 1.0 / 9 + 21), 1);
        if (exp2 > 400)
        {
            exp_caculate(exp2, (e1 * 1.0 / 16 + 17), 1);
            exp_caculate(exp2, (exp2 * 15.0 / 100), 1);
        }
    }
    //Sherlock
    exp1 -= e1;
    experience_points(exp1);

    return exp1 + exp2;
}

//Function to caculate and round up
//EXP
void exp_caculate(int& exp, double i, bool s_d)
{
    if (s_d)
    {
        exp += int(i);
        if ((i - int(i)) != 0)
        {
            exp++;
        }
    }
    else
    {
        exp -= int(i);
    }
    experience_points(exp);
}
//HP
void HP_caculate(int& HP, double i, bool s_d)
{
    if (s_d)
    {
        HP += int(i);
        if ((i - int(i)) != 0)
        {
            HP++;
        }
    }
    else
    {
        HP -= int(i);
    }
    health_points(HP);
}


//Trace luggage
//Road 01
double probability(int exp)
{
    int sq_small, sq_big;
    for (int i = 1; i <= exp; i++)
    {
        if ((sqrt(i) - int(sqrt(i))) == 0)
        {
            sq_small = i;
        }
    }
    sq_big = exp + 1;
    while (1)
    {
        if ((sqrt(sq_big) - int(sqrt(sq_big))) == 0)
        {
            break;
        }
        else
        {
            sq_big++;
        }
    }
    if ((exp - sq_small) < (sq_big - exp))
    {
        return 1;
    }
    else
    {
        return ((exp * 1.0 / sq_big + 80) / 123);
    }
}

//Road 02
void road02(int& HP1, int& M1, int& exp1, int e2)
{
    int fee = 0;
    int M_root = M1;
    if (e2 % 2 != 0)
    {
        while (1)
        {
            if (M1 == 0)
            {
                break;
            }
            event01(HP1, M1, fee);
            if (fee > (M_root * 1.0 / 2))
            {
                break;
            }
            event02(M1, exp1, fee);
            if (fee > (M_root * 1.0 / 2))
            {
                break;
            }
            event03(exp1, M1, fee);
            if (fee > (M_root * 1.0 / 2))
            {
                break;
            }
        }
        HP_caculate(HP1, HP1 * 17.0 / 100, 0);
        exp_caculate(exp1, exp1 * 17.0 / 100, 1);
    }
    else
    {
        if (M1 != 0)
        {
            event01(HP1, M1, fee);
            if (M1 != 0)
            {
                event02(M1, exp1, fee);
                if (M1 != 0)
                {
                    event03(exp1, M1, fee);
                }
            }
        }
        HP_caculate(HP1, HP1 * 17.0 / 100, 0);
        exp_caculate(exp1, exp1 * 17.0 / 100, 1);
    }

}
//event 01
void event01(int& HP1, int& M1, int& fee)
{
    if (HP1 < 200)
    {
        HP_caculate(HP1, HP1 * 0.3, 1);
        M1 -= 150;
        fee += 150;
        initial_money(M1);
    }
    else
    {
        HP_caculate(HP1, HP1 * 0.1, 1);
        M1 -= 70;
        fee += 70;
        initial_money(M1);
    }
}
//event 02
void event02(int& M1, int& exp1, int& fee)
{
    if (exp1 < 400)
    {
        M1 -= 200;
        fee += 200;
        initial_money(M1);
    }
    else
    {
        M1 -= 120;
        fee += 120;
        initial_money(M1);
    }
    exp_caculate(exp1, exp1 * 13.0 / 100, 1);
}
//event 03
void event03(int& exp1, int& M1, int& fee)
{
    if (exp1 < 300)
    {
        M1 -= 100;
        fee += 100;
        initial_money(M1);
    }
    else
    {
        M1 -= 120;
        fee += 120;
        initial_money(M1);
    }
    exp_caculate(exp1, exp1 * 0.1, 0);
}

//Road 03
int road03(int e2)
{
    int i = 0;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if ((e2 >= 0) && (e2 <= 9))
    {
        i = e2;
        return P[i];
    }
    else
    {
        while(e2 != 0)
        {
            i += e2 % 10;
            e2 /= 10;
        }
        return P[i % 10];
    }
}

//Chase taxi
int Sum_of_digits(int num)
{
    int sum = 0;
    while (num > 9)
    {
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
        sum = 0;
    }
    return num;
}
int left_max(int array[][10], int row, int col)
{
    int i = row;
    int j = col;
    int max = array[i][j];
    while ((i >= 0) && (j >= 0))
    {
        if (max < array[i][j])
        {
            max = array[i][j];
        }
        i--;
        j--;
    }
    i = row;
    j = col;
    while ((i <= 9) && (j <= 9))
    {
        if (max < array[i][j])
        {
            max = array[i][j];
        }
        i++;
        j++;
    }
    return max;
}
int right_max(int array[][10], int row, int col)
{
    int i = row;
    int j = col;
    int max = array[i][j];
    while ((i >= 0) && (j <= 9))
    {
        if (max < array[i][j])
        {
            max = array[i][j];
        }
        i--;
        j++;
    }
    i = row;
    j = col;
    while ((i <= 9) && (j>= 0))
    {
        if (max < array[i][j])
        {
            max = array[i][j];
        }
        i++;
        j--;
    }
    return max;
}

//check Email
bool checkEmail(const char* email)
{
    int i = 0;
    int num_of_a = 0;
    while (*(email + i) != '\0')
    {
        if (*(email + i) == '@')
        {
            num_of_a++;
        }
        i++;
    }
    if ((i <= 100) && (num_of_a == 1))
    {
        return true;
    }
    else
        return false;

}


//check passwords
bool checkDigits( char s)
{
    if ((s >= '0') && (s <= '9'))
    {
        return true;
    }
    else if ((s >= 'a') && (s <= 'z'))
    {
        return true;
    }
    else if ((s >= 'A') && (s <= 'Z'))
    {
        return true;
    }
    else if ((s == '@') || (s == '#') || (s == '%') || (s == '$') || (s == '!'))
    {
        return true;
    }
    else
        return false;
}
bool checkContain(const char* s, const char* se, int idx, int i)
{
    bool result = true;
    if (i == -1)
    {
        result = false;
    }
    else
    {
        if (*(s + idx) == *se)
        {
            if (i == 0)
            {
                result = false;
            }
            else
            {
                for (int loop = 1; loop <= i; loop++)
                {
                    if (*(s + idx + loop) != *(se + loop))
                    {
                        break;
                    }
                    else
                    {
                        if (loop == i)
                        {
                            result = false;
                        }
                    }
                }
            }
        }
    }
    return result;

}
bool checkRepeat(const char* s, int idx)
{
    bool result = true;
    if ((*(s + idx) == *(s + idx + 1)) && (*(s + idx + 1) == *(s + idx + 2)))
    {
        result = false;
    }
    return result;
}
int checkSpecialDigits( char s)
{
    if ((s == '@') || (s == '#') || (s == '%') || (s == '$') || (s == '!'))
    {
        return 1;
    }
    else
        return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////