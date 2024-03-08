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

// condition

int Set_Money(int a)
{
    if (a < 0)
    {
        a = 0;
    }
    else if (a > 3000)
    {
        a = 3000;
    }
    return a;
}

int Set_EXP(int b)
{
    if (b < 0)
    {
        b = 0;
    }
    else if (b > 600)
    {
        b = 600;
    }
    return b;
}

int Set_HP(int c)
{
    if (c < 0)
    {
        c = 0;
    }
    else if (c > 666)
    {
        c = 666;
    }
    return c;
}
int Set_E(int d)
{
    if (d < 0 || d > 99)
    {
        d = -99;
    }
    return d;
}

// Task 1

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    // truong hop 1
    e1 = Set_E(e1);
    if (e1 == -99)
    {
        return -99;
    }
    exp1 = Set_EXP(exp1);
    exp2 = Set_EXP(exp2);

    int i = e1;
    //
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        { // case 1
            exp2 += 29;
            exp2 = Set_EXP(exp2);
        }
        else if (e1 == 1)
        { // case 2
            exp2 += 45;
            exp2 = Set_EXP(exp2);
        }
        else if (e1 == 2)
        { // case 3
            exp2 += 75;
            exp2 = Set_EXP(exp2);
        }
        else if (e1 == 3)
        { // case 4
            exp2 += 75 + 45 + 29;
            exp2 = Set_EXP(exp2);
        }
        int d = (e1 * 3) + (exp1 * 7.0);
        if (d % 2 == 0)
        {
            exp1 = ceil(exp1 + (d / 200.0));
            exp1 = Set_EXP(exp1);
        }
        else
        {
            exp1 = ceil(exp1 - (d / 100.0));
            exp1 = Set_EXP(exp1);
        }
    }
    // truong hop 2
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        { // case 1
            exp2 = exp2 + ceil(i / 4.0 + 19);
            exp2 = Set_EXP(exp2);
        }
        if (e1 >= 20 && e1 <= 49)
        { // case 2
            exp2 = exp2 + ceil(i / 9.0 + 21);
            exp2 = Set_EXP(exp2);
        }
        if (e1 >= 50 && e1 <= 65)
        { // case 3
            exp2 = ceil(exp2 + i / 16.0 + 17);
            exp2 = Set_EXP(exp2);
        }
        if (e1 >= 66 && e1 <= 79)
        { // case 4
            exp2 = ceil(exp2 + i / 4.0 + 19);
            exp2 = Set_EXP(exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + i / 9.0 + 21);
                exp2 = Set_EXP(exp2);
            }
        }
        if (e1 >= 80 && e1 <= 99)
        { // case 5
            exp2 = exp2 + ceil(i / 4.0 + 19);
            exp2 = Set_EXP(exp2);
            exp2 = exp2 + ceil(i / 9.0 + 21);
            exp2 = Set_EXP(exp2);
            if (exp2 > 400)
            {
                exp2 = exp2 + ceil(i / 16.0 + 17);
                exp2 = Set_EXP(exp2);
                exp2 = ceil(exp2 * 115.0 / 100);
                exp2 = Set_EXP(exp2);
            }
        }
        exp1 = exp1 - i;
        exp1 = Set_EXP(exp1);
        exp2 = Set_EXP(exp2);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    E2 = Set_E(E2);
    if (E2 == -99)
    {
        return -99;
    }
    M1 = Set_Money(M1);
    if (M1 == 0)
        return HP1 + EXP1 + M1;
    HP1 = Set_HP(HP1);
    EXP1 = Set_EXP(EXP1);

    /*Path 1*/

    int a = pow(round(sqrt(EXP1)), 2);
    double P1;
    if (EXP1 >= a)
    {
        P1 = 1;
    }
    else
    {
        P1 = (EXP1 / (double)a + 80) / 123;
    }

    /*Path 2*/

    // pay food and drinks
    if (E2 % 2 != 0)
    {
        int m = M1 * 0.5;
        float k = 0;
        while (E2 % 2 != 0)
        {
            EXP1 = Set_EXP(EXP1);
            M1 = Set_Money(M1);
            HP1 = Set_HP(HP1);
            if (HP1 < 200)
            {
                k += 150;
                HP1 = ceil(HP1 * 13.0 / 10);
                M1 -= 150;
                HP1 = Set_HP(HP1);
                M1 = Set_Money(M1);
                if (k > m)
                    break;
            }
            else if (HP1 >= 200)
            {
                k += 70;
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 -= 70;
                HP1 = Set_HP(HP1);
                M1 = Set_Money(M1);
                if (k > m)
                    break;
            }
            M1 = Set_Money(M1);
            HP1 = Set_HP(HP1);
            // pay taxi
            if (EXP1 < 400)
            {
                k += 200;
                M1 -= 200;
                EXP1 = ceil(EXP1 * 113 / 100.0); // check
                EXP1 = Set_EXP(EXP1);
                M1 = Set_Money(M1);
                if (k > m)
                    break;
            }
            else
            {
                k += 120;
                M1 -= 120;
                EXP1 = ceil(EXP1 * 113 / 100.0); // check
                EXP1 = Set_EXP(EXP1);
                M1 = Set_Money(M1);
                if (k > m)
                    break;
            }
            // homeless
            if (EXP1 < 300)
            {
                k += 100;
                M1 -= 100;
                EXP1 = ceil(EXP1 * 90.0 / 100.0);
                EXP1 = Set_EXP(EXP1);
                M1 = Set_Money(M1);
                if (k > m)
                    break;
            }
            else
            {
                k += 120;
                M1 -= 120;
                EXP1 = ceil(EXP1 * 90.0 / 100.0);
                EXP1 = Set_EXP(EXP1);
                M1 = Set_Money(M1);
                if (k > m)
                    break;
            }
        }
    }
    // end E2 is an odd

    // start E2 is an even
    while (E2 % 2 == 0)
    {
        // checkif
        EXP1 = Set_EXP(EXP1);
        M1 = Set_Money(M1);
        HP1 = Set_HP(HP1);
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 * 130.0 / 100);
            M1 -= 150;
            M1 = Set_Money(M1);
            HP1 = Set_HP(HP1);
            if (M1 == 0)
                break;
        }
        else
        {
            HP1 = ceil(HP1 * 110.0 / 100);
            M1 -= 70;
            M1 = Set_Money(M1);
            HP1 = Set_HP(HP1);
            if (M1 == 0)
                break;
        }
        // pay taxi
        if (EXP1 < 400)
        {
            M1 -= 200;
            M1 = Set_Money(M1);
            HP1 = Set_HP(HP1);
            EXP1 = ceil(EXP1 * 113.0 / 100);
            EXP1 = Set_EXP(EXP1);
            if (M1 == 0)
                break;
        }
        else
        {
            M1 -= 120;
            M1 = Set_Money(M1);
            HP1 = Set_HP(HP1);
            EXP1 = ceil(EXP1 * 113.0 / 100);
            EXP1 = Set_EXP(EXP1);
            if (M1 == 0)
                break;
        }
        // homeless
        if (EXP1 < 300)
        {
            M1 -= 100;
            M1 = Set_Money(M1);
            EXP1 = ceil(EXP1 * 90.0 / 100.0);
            EXP1 = Set_EXP(EXP1);
            if (M1 == 0)
                break;
        }
        else
        {
            M1 -= 120;
            M1 = Set_Money(M1);
            EXP1 = ceil(EXP1 * 90.0 / 100.0);
            EXP1 = Set_EXP(EXP1);
            if (M1 == 0)
                break;
        }
        break;
    }
    // end E2 is an even
    HP1 = ceil(HP1 * 83.0 / 100);
    EXP1 = ceil(EXP1 * 117.0 / 100);
    HP1 = Set_HP(HP1);
    EXP1 = Set_EXP(EXP1);
    // possiblity
    int b = pow(round(sqrt(EXP1)), 2);
    double P2;
    if (EXP1 >= b)
    {
        P2 = 1;
    }
    else
    {
        P2 = (EXP1 / (double)b + 80) / 123;
    }

    /*Path 3*/

    int Pos[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;
    int e;

    if (E2 >= 0 && E2 < 10)
    {
        P3 = Pos[E2];
        P3 = P3 / 100;
    }
    else if (E2 >= 10 && E2 <= 99)
    {
        e = E2 / 10 + E2 % 10;
        e = e % 10;
        P3 = Pos[e];
        P3 = P3 / 100;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil(EXP1 * 75.0 / 100.0);
        EXP1 = Set_EXP(EXP1);
    }
    else if (P1 != 1 || P2 != 1 || P3 != 1)
    {
        float Ptb = (P1 + P2 + P3) / 3;
        if (Ptb < 0.5)
        {
            HP1 = ceil(HP1 * 85.0 / 100.0);
            EXP1 = ceil(EXP1 * 115.0 / 100);
            EXP1 = Set_EXP(EXP1);
            HP1 = Set_HP(HP1);
        }
        else if (Ptb >= 0.5)
        {
            HP1 = ceil(HP1 * 90.0 / 100.0);
            EXP1 = ceil(EXP1 * 120.0 / 100);
            EXP1 = Set_EXP(EXP1);
            HP1 = Set_HP(HP1);
        }
    }
    // output
    return HP1 + EXP1 + M1;
}

// Task 3
int meet_point_x(int a)
{
    int temp = a / 10 + a % 10;
    if (temp > 9)
    {
        temp = temp / 10 + temp % 10;
    }
    return (temp);
}

int meet_point_y(int b)
{
    int temp1 = b / 10 + b % 10;
    if (temp1 > 9)
    {
        temp1 = temp1 / 10 + temp1 % 10;
    }
    return (temp1);
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    E3 = Set_E(E3);
    if (E3 == -99)
    {
        return -99;
    }
    HP1 = Set_HP(HP1);
    EXP1 = Set_EXP(EXP1);
    HP2 = Set_HP(HP2);
    EXP2 = Set_EXP(EXP2);
    // TODO: Complete this function
    int arr[10][10] = {};
    int countp = 0;
    int countn = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = 0;
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            // cout << setw(5) << arr[i][j] << " ";
            if (arr[i][j] > E3 * 2 && arr[i][j] > 0)
                countp = countp + 1; // count pos
            if (arr[i][j] < -E3 && arr[i][j] < 0)
                countn = countn + 1; // count neg
        }
        // cout << setw(5) << " " << endl;
    }
    // end array
    int i = meet_point_x(countp);
    // cout << i << endl;
    int j = meet_point_y(countn);
    // cout << j << endl;
    int a = i;
    int b = j;
    int taxi = arr[i][j];
    int human = arr[i][j];
    int temp = 0;
    bool check = true;
    bool check2 = true;

    if ((i == 9 && j == 9) || (i == 0 && j == 0))
    {
        check = false;
    }

    if ((i == 9 && j == 0) || (i == 9 && j == 0))
    {
        check2 = false;
    }

    if ((i == 0 || j == 0))
    {
        temp = 0;
    }
    else if ((i == 9 || j == 9))
    {
        temp = 1;
    }
    while (temp == 0)
    {
        if (!check2)
        {
            break;
        }
        i++;
        j++;
        if (arr[i][j] >= human)
        {
            human = arr[i][j];
        }
        if ((i == 9 || j == 9))
        {
            temp = 1;
        }
    }
    while (temp == 1)
    {
        if (!check2)
        {
            break;
        }
        i--;
        j--;
        if (arr[i][j] > human)
        {
            human = arr[i][j];
        }
        if ((i == 0 || j == 0))
        {
            break;
        }
    }
    // end left_cross
    i = a;
    j = b;
    if ((i == 9 || j == 0))
    {
        temp = 0;
    }
    else if ((i == 0 || j == 9))
    {
        temp = 1;
    }
    while (temp == 1)
    {
        if (!check)
        {
            break;
        }
        i++;
        j--;
        if (arr[i][j] > human)
        {
            human = arr[i][j];
        }
        if ((i == 9 || j == 0) || (i == 9 && j == 0))
        {
            temp = 0;
        }
    }
    while (temp == 0)
    {
        if (!check)
        {
            break;
        }
        i--;
        j++;
        if (arr[i][j] > human)
        {
            human = arr[i][j];
        }
        if ((i == 0 || j == 9) || (i == 0 && j == 9))
        {
            break;
        }
    }
    // end right_cross
    int comp = abs(taxi);
    if (comp > human)
    {
        EXP1 = ceil(EXP1 * 88.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP1 = ceil(HP1 * 90.0 / 100);
        HP2 = ceil(HP2 * 90.0 / 100);
        EXP1 = Set_EXP(EXP1);
        EXP2 = Set_EXP(EXP2);
        HP1 = Set_HP(HP1);
        HP2 = Set_HP(HP2);
        return taxi;
    }
    else
    {
        EXP1 = ceil(EXP1 * 112.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
        EXP1 = Set_EXP(EXP1);
        EXP2 = Set_EXP(EXP2);
        HP1 = Set_HP(HP1);
        HP2 = Set_HP(HP2);
        return human;
    }
    // end update static
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string s1 = string(s);
    int findc = string(email).find('@');
    string se = string(email, 0, findc);

    //<8 >20
    if (s1.length() < 8)
    {
        return -1;
    }
    if (s1.length() > 20)
    {
        return -2;
    }

    if (s1.find(se) != string::npos)
    {
        return -(300 + s1.find(se));
    }

    int mystring;

    char s2 = string(s1)[0];
    char s3 = string(s1)[1];
    for (int i = 2; i < s1.length(); i++)
    {
        if (s1[i] == s2 && s2 == s3)
        {
            return -(400 + i - 2);
        }
        else
        {
            s2 = s3;
            s3 = s1[i];
        }
    }

    if (strpbrk(s1.c_str(), "@!$%#") == nullptr)
    {
        return -5;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        mystring = string(s1)[i];
        if (!((mystring >= 33 && mystring <= 37 && mystring != 34) || (mystring >= 48 && mystring <= 57) || (mystring >= 64 && mystring <= 90) || (mystring >= 97 && mystring <= 122)))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function

    int mark = 0;
    int resultindex;
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        if (count > mark)
        {
            mark = count;
            resultindex = i;
        }
        if (count == mark)
        {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[resultindex]))
            {
                resultindex = i;
            }
        }
    }
    return resultindex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////