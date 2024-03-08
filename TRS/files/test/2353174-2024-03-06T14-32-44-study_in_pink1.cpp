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

const int maxhp = 666, maxexp = 600, maxm = 3000;
void Plus(int a, int &x, int max)
{
    x += a;
    if (x > max)
        x = max;
}
void Plus(double a, int &x, int max)
{
    x = ceil(x + a);
    if (x > max)
        x = max;
}

void Minus(int a, int &x)
{
    x -= a;
    if (x < 0)
        x = 0;
}
void Minus(double a, int &x)
{
    x = ceil(x - a);
    if (x < 0)
        x = 0;
}

void Product(int a, int &x, int max)
{
    x *= a;
    if (x > max)
        x = max;
}
void Product(double a, int &x, int max)
{
    double ans = x*a;
    int ansint = x*a;
    if (ans - ansint < 0.0001) x = ansint;
    else x = ansint + 1;
    if (x > max)
        x = max;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    int D;
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            Plus(29, exp2, maxexp);
        else if (e1 == 1)
            Plus(45, exp2, maxexp);
        else if (e1 == 2)
            Plus(75, exp2, maxexp);
        else
            Plus(149, exp2, maxexp);
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            Plus(D / 200.0, exp1, maxexp);
        else
            Minus(D / 100.0, exp1);
    }
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 <= 19)
            Plus(e1 / 4.0 + 19, exp2, maxexp);
        else if (e1 <= 49)
            Plus(e1 / 9.0 + 21, exp2, maxexp);
        else if (e1 <= 65)
            Plus(e1 / 16.0 + 17, exp2, maxexp);
        else if (e1 <= 79)
        {
            Plus(e1 / 4.0 + 19, exp2, maxexp);
            if (exp2 > 200)
                Plus(e1 / 9.0 + 21, exp2, maxexp);
        }
        else
        {
            Plus(e1 / 4.0 + 19, exp2, maxexp);
            Plus(e1 / 9.0 + 21, exp2, maxexp);
            if (exp2 > 400)
            {
                Plus(e1 / 16.0 + 17, exp2, maxexp);
                Product(1.15, exp2, maxexp);
            }
        }
        Minus(e1, exp1);
    }

    return exp1 + exp2;
}

// Task 2

bool actroad2(int &HP1, int &EXP1, int &M1, float a)
{
    if (M1 < a || M1 == 0)
        return 0;
    if (HP1 < 200)
    {
        Product(1.3, HP1, maxhp);
        Minus(150, M1);
    }
    else
    {
        Product(1.1, HP1, maxhp);
        Minus(70, M1);
    }

    if (M1 < a || M1 == 0)
        return 0;
    if (EXP1 < 400)
        Minus(200, M1);
    else
        Minus(120, M1);
    Product(1.13, EXP1, maxexp);

    if (M1 < a || M1 == 0)
        return 0;
    if (EXP1 < 300)
        Minus(100, M1);
    else
        Minus(120, M1);
    Product(0.9, EXP1, maxexp);

    return 1;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    float p1, p2, p3, p;

    // Road 1
    int S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S)
        p1 = 100;
    else
        p1 = (double(EXP1) / S + 80) / 123 * 100;

    // Road 2
    if (E2 % 2 == 1)
    {
        float a = M1 / 2.0;
        while (actroad2(HP1, EXP1, M1, a))
            ;
    }
    else
        actroad2(HP1, EXP1, M1, 0);

    Product(1-0.17, HP1, maxhp);
    Product(1.17, EXP1, maxexp);

    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S)
        p2 = 100;
    else
        p2 = (double(EXP1) / S + 80) / 123 * 100;

    // Road 3
    int pe[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
        i = E2;
    if (E2 >= 10 && E2 <= 99)
        i = (E2 / 10 + E2 % 10) % 10;
    p3 = pe[i];

    // Calculation
    if (p1 == 100 && p2 == 100 && p3 == 100)
        Product(0.75, EXP1, maxexp);
    else
    {
        p = (p1 + p2 + p3) / 3;
        if (p < 50)
        {
            Product(0.85, HP1, maxhp);
            Product(1.15, EXP1, maxexp);
        }
        else
        {
            Product(0.9, HP1, maxhp);
            Product(1.2, EXP1, maxexp);
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
    int a[10][10] = {};
    int i, j, x = 0, y = 0, MAX, taxi;
    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > E3 * 2)
                x += 1;
            if (a[i][j] < -E3)
                y += 1;
        }
    }

    while (x >= 10)
        x = x / 10 + x % 10;
    while (y >= 10)
        y = y / 10 + y % 10;

    int b = x, c = y;
    MAX = a[x][y];
    while (x != 0 && y != 0)
    {
        if (a[x - 1][y - 1] > MAX)
            MAX = a[x - 1][y - 1];
        x -= 1;
        y -= 1;
    }
    x = b;
    y = c;
    while (x != 9 && y != 9)
    {
        if (a[x + 1][y + 1] > MAX)
            MAX = a[x + 1][y + 1];
        x += 1;
        y += 1;
    }
    x = b;
    y = c;
    while (x != 9 && y != 0)
    {
        if (a[x + 1][y - 1] > MAX)
            MAX = a[x + 1][y - 1];
        x += 1;
        y -= 1;
    }
    x = b;
    y = c;
    while (x != 0 && y != 9)
    {
        if (a[x - 1][y + 1] > MAX)
            MAX = a[x - 1][y + 1];
        x -= 1;
        y += 1;
    }
    x = b;
    y = c;

    // tu cho nay
    if (MAX < 0)
        MAX = -MAX;
    taxi = abs(a[x][y]);

    if (taxi > MAX)
    {

        Product(0.88, EXP1, maxexp);
        Product(0.88, EXP2, maxexp);
        Product(0.9, HP1, maxhp);
        Product(0.9, HP2, maxhp);
        return a[x][y];
    }
    else
    {
        Product(1.12, EXP1, maxexp);
        Product(1.12, EXP2, maxexp);
        Product(1.1, HP1, maxhp);
        Product(1.1, HP2, maxhp);
        return MAX;
    }
}

// Task 4
int checkPassword(const char *s2, const char *email2)
{
    // TODO: Complete this function
    string email = email2, s = s2;
    int a;
    a = email.find("@");
    string se = email.substr(0, a);
    int slength = s.length();
    int selength = se.length();
    if (slength < 8)
        return -1;
    if (slength > 20)
        return -2;

    for (int i = 0; i <= slength - selength + 1; i++)
    {
        string m = s.substr(i, selength);
        if (m == se)
            return -(300 + i);
    }

    for (int i = 0; i < slength - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i]== s[i + 2])
            return -(400 + i);
    }

    bool count = 0;
    for (int i = 0; i < slength; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            count = 1;
    }
    if (count == 0)
        return -5;

    for (int i = 0; i < slength; i++)
    {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i;
    }

    return -10;
}

// Task 5 OK
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    string pass[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        pass[i] = arr_pwds[i];
    }
    string c;
    int count, b[num_pwds], maxcount = 0, position = 0;
    string longest = pass[0];
    for (int a = 0; a < num_pwds; a++)
    {
        count = 0;
        c = pass[a];
        for (int m = 0; m < num_pwds; m++)
        {
            if (pass[m] == c)
                count += 1;
        }

        if (count == maxcount)
        {
            if (c.length() > longest.length())
            {
                longest = c;
                maxcount = count;
                position = a;
            }
        }

        if (count > maxcount)
        {
            longest = c;
            maxcount = count;
            position = a;
        }
    }

    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////