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

// supproted function @_@
void expReset(int &exp)
{
    if (exp > 600)
        exp = 600;
    if (exp < 0)
        exp = 0;
}
void hpReset(int &hp)
{
    if (hp > 666)
        hp = 666;
    if (hp < 0)
        hp = 0;
}
void mReset(int &m)
{
    if (m > 3000)
        m = 3000;
    if (m < 0)
        m = 0;
}
int roundUp(float num) // there are some cases the ceil() may not be true
{
    int a;
    a = static_cast<int>(ceil(num));
    return a;
}
// supported function - task 2 @_@
int rateFind(int exp)
{ // Find square num
    int a = sqrt(exp);
    int b = sqrt(exp) + 1;
    int S, p; // S-nearest square num, p-rate
    if (abs(a * a - exp) < abs(b * b - exp))
    {
        S = a * a;
    }
    else
    {
        S = b * b;
    }

    if (exp >= S)
    {
        return 100;
    }
    else
    {
        p = 100 * ((1.0 * exp / S + 80) / 123);
        return p;
    }
}
void event1Task2(int &exp, int &hp, int &m)
{
    if (hp < 200)
    {
        hp = roundUp(hp * 1.3);
        m -= 150;
    }
    else
    {
        hp = roundUp(hp * 1.1);
        m -= 70;
    }
    hpReset(hp);
    mReset(m);
}
void event2Task2(int &exp, int &hp, int &m)
{
    if (exp < 400)
    {
        m -= 200;
    }
    else
    {
        m -= 120;
    }
    exp = roundUp(exp * 1.13);
    expReset(exp);
    mReset(m);
}
void event3Task2(int &exp, int &hp, int &m)
{
    if (exp < 300)
    {
        m -= 100;
    }
    else if (exp >= 300)
    {
        m -= 120;
    }
    exp = roundUp(exp * 0.9);
    expReset(exp);
    mReset(m);
}
void secRate(int &exp, int &hp, int &m, int e3)
{
    int a = 0;
    int b = m;
    if (m == 0)
    {
        hp = roundUp(hp * 0.83);
        exp = roundUp(exp * 1.17);
        hpReset(hp);
        expReset(exp);
        mReset(m);
        return;
    }
    if (e3 % 2 != 0)
    {
        while (true)
        {
            event1Task2(exp, hp, m);
            if ((b - m) > 0.5 * b)
            {
                break;
            }
            event2Task2(exp, hp, m);
            if ((b - m) > 0.5 * b)
            {
                break;
            }
            event3Task2(exp, hp, m);
            if ((b - m) > 0.5 * b)
            {
                break;
            }
        }
    }
    else
    {
        event1Task2(exp, hp, m);
        if (m <= 0)
        {
            hp = roundUp(hp * 0.83);
            exp = roundUp(exp * 1.17);
            hpReset(hp);
            expReset(exp);
            mReset(m);
            return;
        }
        event2Task2(exp, hp, m);
        if (m <= 0)
        {
            hp = roundUp(hp * 0.83);
            exp = roundUp(exp * 1.17);
            hpReset(hp);
            expReset(exp);
            mReset(m);
            return;
        }
        event3Task2(exp, hp, m);
        if (m <= 0)
        {
            hp = roundUp(hp * 0.83);
            exp = roundUp(exp * 1.17);
            hpReset(hp);
            expReset(exp);
            mReset(m);
            return;
        }
    }
    hp = roundUp(hp * 0.83);
    exp = roundUp(exp * 1.17);
    hpReset(hp);
    expReset(exp);
    mReset(m);
}
int meetPoint(int a)
{ // Find meeting point in task 3
    while (true)
    {
        if (a <= 9)
        {
            break;
        }
        else if (a >= 10)
        {
            a = a % 10 + a / 10;
        }
    }
    return a;
}

// supported function for task 4

bool validPass1(const char *s)
{
    if (strlen(s) < 8)
    {
        return false;
    }
    return true;
}
bool validPass2(const char *s)
{
    // second condition
    if (strlen(s) > 20)
    {
        return false;
    }
    return true;
}
bool validPass3(const char *s, const char *se, int &index3)
{
    index3 = 0;
    // third condition
    const char *len = strstr(s, se);
    if (len)
    {
        index3 = len - s;
        return false;
    }
    return true;
}
bool validPass4(const char *s, int &index4)
{
    index4 = 0;
    int length = strlen(s);
    for (int i = 0; i < length - 2; i++)
    {
        if ((s[i + 1] == s[i]) && (s[i + 2] == s[i]))
        {
            index4 = i;
            return false;
        }
    }
    return true;
}
bool validPass5(const char *s, int &index5)
{
    char it;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        it = s[i];
        if (!((it >= 'a' && it <= 'z') || (it >= '0' && it <= '9') || (it >= 'A' && it <= 'Z') || it == '@' || it == '!' || it == '#' || it == '$' || it == '%'))
        {
            index5 = i;
            return false;
        }
    }
    return true;
}
bool validPass6(const char *s)
{
    char it;
    int a = 0, length = strlen(s); // a to keep track the value of special characters

    for (int i = 0; i < length; i++)
    {
        it = s[i];
        if ((it == '@') || (it == '!') || (it == '#') || (it == '$') || (it == '%'))
        {
            a++;
        }
    }
    if (a < 1)
    {
        return false;
    }
    return true;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{

    if ((e1 < 0) || (e1 > 99))
    {
        return -99;
    }
    expReset(exp1);
    expReset(exp2);
    int D = e1 * 3 + exp1 * 7;
    if ((e1 >= 0) && (e1 <= 3))
    { // case1 in task1
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
            exp2 += 149;
            break;
        }
        expReset(exp2);
        // decision D-exp1
        if (D % 2 == 0)
        {
            exp1 += roundUp(double(D) / 200);
        }
        else
        {
            exp1 = roundUp(double(exp1) - double(D) / 100);
        }
        expReset(exp1);
    }
    else if ((e1 <= 99) && (e1 > 3))
    { // case 2 in task 1
        if (e1 <= 19)
        {
            exp2 += roundUp(1.0 * e1 / 4 + 19);
        }
        else if ((e1 > 19) && (e1 <= 49))
        {
            exp2 += roundUp(1.0 * e1 / 9 + 21);
        }
        else if ((e1 > 49) && (e1 <= 65))
        {
            exp2 += roundUp(1.0 * e1 / 16 + 17);
        }
        else if ((e1 > 65) && (e1 <= 79))
        {
            exp2 += roundUp(1.0 * e1 / 4 + 19);

            if (exp2 > 200)
            {
                exp2 += roundUp(1.0 * e1 / 9 + 21);
            }
        }
        else if ((e1 > 79) && (e1 <= 99))
        {
            exp2 += roundUp(double(e1) / 4 + double(19));
            exp2 += roundUp(1.0 * e1 / 9 + 21);
            if (exp2 > 400)
            {
                exp2 += roundUp(1.0 * e1 / 16 + 17);

                exp2 = roundUp(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    expReset(exp1);
    expReset(exp2);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3)
{
    int p1, p2, p3, p;

    if ((E3 < 0) || (E3 > 99))
    {
        return -99;
    }
    hpReset(HP1);
    expReset(EXP1);
    mReset(M1);
    // Rate p1
    p1 = rateFind(EXP1);

    // Rate p2
    secRate(EXP1, HP1, M1, E3);
    p2 = rateFind(EXP1);

    // Rate p3

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E3 <= 9)
    {
        p3 = P[E3];
    }
    else if (E3 >= 10)
    {
        int a = E3 % 10 + E3 / 10;
        p3 = P[a % 10];
    }
    p = (p1 + p2 + p3) / 3;
    if ((p1 == 100) && (p2 == 100) && (p3 == 100))
    {
        EXP1 = roundUp(EXP1 * 0.75);
    }
    else if (p < 50)
    {
        HP1 = roundUp(HP1 * 0.85);

        EXP1 = roundUp(EXP1 * 1.15);
    }
    else if (p >= 50)
    {
        HP1 = roundUp(HP1 * 0.9);

        EXP1 = roundUp(EXP1 * 1.2);
    }
    hpReset(HP1);
    expReset(EXP1);
    mReset(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{

    if ((E3 > 99) || (E3 < 0))
    {
        return -99;
    }
    hpReset(HP1);
    hpReset(HP2);
    expReset(EXP1);
    expReset(EXP2);
    // Create a 2-dimension matrix
    int a[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // Find num1=">E3*2" and num2="<-E3"
    int num1 = 0, num2 = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > E3 * 2)
            {
                num1++;
            }
            if (a[i][j] < -E3)
            {
                num2++;
            }
        }
    }

    // Find the meeting point has (meetI,meetJ)
    int meetI, meetJ; // row and column indexes of meeting-Point
    meetI = meetPoint(num1);
    meetJ = meetPoint(num2);

    // Find the maximum element in the two diagonals
    int maxE = a[meetI][meetJ]; // Max element

    if ((meetI + meetJ) <= 9) // the right diagonal
    {
        for (int i = 0; i < (meetI + meetJ); i++)
        {
            if (a[i][meetI + meetJ - i] >= maxE)
            {
                maxE = a[i][meetI + meetJ - i];
            }
        }
    }
    else if ((meetI + meetJ) > 9)
    {
        for (int j = 9; j >= (meetI + meetJ - 9); j--)
        {
            if (a[meetI + meetJ - j][j] >= maxE)
            {
                maxE = a[meetI + meetJ - j][j];
            }
        }
    }

    if (meetI >= meetJ)
    { // the left diagonal
        for (int i = 0; i <= (9 - (meetI - meetJ)); i++)
        {
            if (a[meetI - meetJ + i][i] >= maxE)
            {
                maxE = a[meetI - meetJ + i][i];
            }
        }
    }
    else if (meetI < meetJ)
    {
        for (int j = 0; j <= (9 - (meetJ - meetI)); j++)
        {

            if (a[j][meetJ - meetI + j] >= maxE)
            {
                maxE = a[j][meetJ - meetI + j];
            }
        }
    }
    int result;
    if (abs(a[meetI][meetJ]) > maxE)
    {
        result = a[meetI][meetJ];
        EXP1 = roundUp(EXP1 * 0.88);
        HP1 = roundUp(HP1 * 0.9);
        EXP2 = roundUp(EXP2 * 0.88);
        HP2 = roundUp(HP2 * 0.9);
    }
    else if (abs(a[meetI][meetJ]) <= maxE)
    {
        result = maxE;
        EXP1 = roundUp(EXP1 * 1.12);
        HP1 = roundUp(HP1 * 1.1);
        EXP2 = roundUp(EXP2 * 1.12);
        HP2 = roundUp(HP2 * 1.1);
    }
    expReset(EXP1);
    expReset(EXP2);
    hpReset(HP1);
    hpReset(HP2);
    return result;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    int a = 0, index3, index4, index5; // index-find
    // create se to store the stirng before @
    while ((email[a] != '@') && (email[a] != '\0'))
    {
        a++;
    }
    char *se = new char[a + 1]; // a+1 - 1 more pos for null
    for (int i = 0; i < a; i++)
    {
        se[i] = email[i];
    }
    se[a] = '\0'; // Null value to the last position of se
    if ((validPass1(s)) && (validPass2(s)) && (validPass3(s, se, index3)) && (validPass4(s, index4)) && (validPass5(s, index5)) && (validPass6(s)))
    {
        return -10;
    }
    if (!validPass1(s))
    {
        return -1;
    }
    if (!validPass2(s))
    {
        return -2;
    }
    if (!validPass3(s, se, index3))
    {
        return -(300 + index3);
    }
    if (!validPass4(s, index4))
    {
        return -(400 + index4);
    }
    if (!validPass6(s))
    {
        return -5;
    }

    if (!validPass5(s, index5))
    {
        return index5;
    }

    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int a = 0;   // a to count the appearance of the string in the array
    int max = 0; // max to get the maximum appearance of string
    int index = -1;
    int mLength = 0; // to check the same most appearance

    for (int i = 0; i < num_pwds; i++)
    {
        a = 0;
        for (int j = 0; j < num_pwds; j++)
        {

            if ((i != j) && strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                a++;
            }
        }
        if (a > max || (a == max && strlen(arr_pwds[i]) > mLength))
        {
            index = i;
            max = a;
            mLength = strlen(arr_pwds[i]);
        }
    }
    return index;
    // return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////