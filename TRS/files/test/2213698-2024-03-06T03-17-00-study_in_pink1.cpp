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
void setHP(int &HP, double temp)
{
    if (temp < 0)
    {
        temp = 0;
        HP = temp;
        return;
    }
    if (temp > 666)
    {
        temp = 666;
        HP = temp;
        return;
    }
    double a = temp - static_cast<int>(temp);
    if (a != 0)
    {
        HP = static_cast<int>(temp) + 1;
        return;
    }
    HP = temp;
    return;
}
void setEXP(int &EXP, double temp)
{
    if (temp < 0)
    {
        temp = 0;
        EXP = temp;
        return;
    }
    if (temp > 600)
    {
        temp = 600;
        EXP = temp;
        return;
    }
    double a = temp - static_cast<int>(temp);
    if (a != 0)
    {
        EXP = static_cast<int>(temp) + 1;
        return;
    }
    EXP = temp;
    return;
}
void setMoney(int &Money, double temp)
{
    if (temp < 0)
    {
        temp = 0;
        Money = temp;
        return;
    }
    if (temp > 3000)
    {
        temp = 3000;
        Money = temp;
        return;
    }
    double a = temp - static_cast<int>(temp);
    if (a != 0)
    {
        Money = static_cast<int>(temp) + 1;
        return;
    }
    Money = temp;
    return;
}
void setE(int &E, int temp)
{
    if (temp > 99 || temp < 0)
    {
        temp = -1;
        E = temp;
    }
    return;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    setE(e1, e1);
    if (e1 == -1)
        return -99;
    setEXP(exp1, exp1);
    setEXP(exp2, exp2);
    // case1

    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            setEXP(exp2, exp2 + 29);
        else if (e1 == 1)
            setEXP(exp2, exp2 + 45);
        else if (e1 == 2)
            setEXP(exp2, exp2 + 75);
        else
            setEXP(exp2, exp2 + 29 + 45 + 75);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            setEXP(exp1, exp1 + D / 200.0);
        else
            setEXP(exp1, exp1 - D / 100.0);
    }
    else
    {
        if (e1 >= 4 && e1 <= 19)
        {
            setEXP(exp2, exp2 + e1 / 4.0 + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            setEXP(exp2, exp2 + e1 / 9.0 + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            setEXP(exp2, exp2 + e1 / 16.0 + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            setEXP(exp2, exp2 + e1 / 4.0 + 19);
            if (exp2 > 200)
                setEXP(exp2, exp2 + e1 / 9.0 + 21);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            setEXP(exp2, exp2 + e1 / 4.0 + 19);
            setEXP(exp2, exp2 + e1 / 9.0 + 21);
            if (exp2 > 400)
            {
                setEXP(exp2, exp2 + e1 / 16.0 + 17);
                setEXP(exp2, exp2 + exp2 * 15.0 / 100);
            }
        }
        setEXP(exp1, exp1 - e1);
    }

    return exp1 + exp2;
}

// Task 2
int findSochinhphuong(int n)
{
    if (n == 0)
        return 0;
    int temp = 1;
    int minus = INT_MAX;
    while (temp * temp < n)
    {
        minus = abs(n - temp * temp);
        temp++;
    }
    if (minus < abs(n - temp * temp))
    {
        temp--;
    }
    return temp * temp;
}
double findP(int EXP1)
{
    int S = findSochinhphuong(EXP1);
    double P1;
    if (EXP1 >= S)
    {
        P1 = 1;
    }
    else
    {
        P1 = (EXP1 * 1.0 / S + 80) / 123;
    }
    return P1;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    setE(E2, E2);
    if (E2 == -1)
        return -99;
    setHP(HP1, HP1);
    setEXP(EXP1, EXP1);
    setMoney(M1, M1);
    // ROAD1
    double P1 = findP(EXP1);
    // ROAD2
    if (E2 % 2 == 1)
    {
        int tempMoney = M1 / 2;
        int sum = 0;
        while (sum < tempMoney)
        {
            if (HP1 < 200) // mua nuoc
            {
                setHP(HP1, HP1 + HP1 * 30.0 / 100);
                sum += 150;
                setMoney(M1, M1 - 150);
            }
            else
            {
                setHP(HP1, HP1 + HP1 * 10.0 / 100);
                sum += 70;
                setMoney(M1, M1 - 70);
            }

            if (sum > tempMoney)
            {
                break;
            }

            if (EXP1 < 400) // phuong tien
            {
                setMoney(M1, M1 - 200);
                sum += 200;
            }
            else
            {
                setMoney(M1, M1 - 120);
                sum += 120;
            }
            setEXP(EXP1, EXP1 + EXP1 * 13.0 / 100);

            if (sum > tempMoney)
            {
                break;
            }

            if (EXP1 < 300) // ng vo gia cu
            {
                setMoney(M1, M1 - 100);
                sum += 100;
            }
            else
            {
                setMoney(M1, M1 - 120);
                sum += 120;
            }
            setEXP(EXP1, EXP1 - EXP1 * 10.0 / 100);
            if (sum > tempMoney)
            {
                break;
            }
        }
    }
    else // so chan
    {
        bool stop = 0;
        if (M1 == 0)
            stop = 1;
        if (stop != 1)
        {
            if (HP1 < 200) // mua nuoc
            {
                setHP(HP1, HP1 + HP1 * 30.0 / 100);
                setMoney(M1, M1 - 150);
            }
            else
            {
                setHP(HP1, HP1 + HP1 * 10.0 / 100);
                setMoney(M1, M1 - 70);
            }
        }

        if (M1 == 0)
            stop = 1;
        if (stop != 1)
        {
            if (EXP1 < 400) // phuong tien
                setMoney(M1, M1 - 200);
            else
                setMoney(M1, M1 - 120);
            if (M1 == 0)
                stop = 1;
            setEXP(EXP1, EXP1 + EXP1 * 13.0 / 100);
        }

        if (stop != 1)
        {
            if (EXP1 < 300) // ng vo gia cu
            {
                setMoney(M1, M1 - 100);
            }
            else
                setMoney(M1, M1 - 120);
            setEXP(EXP1, EXP1 - EXP1 * 10.0 / 100);
        }
    }
    setHP(HP1, HP1 - HP1 * 17.0 / 100);
    setEXP(EXP1, EXP1 + EXP1 * 17.0 / 100);

    double P2 = findP(EXP1);

    // ROAD3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;
    if (E2 < 10)
    {
        P3 = P[E2] / 100.0;
    }
    else
    {
        int donvi = E2 % 10;
        int chuc = E2 / 10;
        int tong = donvi + chuc;
        P3 = P[tong % 10] / 100.0;
    }

    double ave = (P1 + P2 + P3) / 3;

    if (ave == 1)
    {
        setEXP(EXP1, EXP1 - EXP1 * 25.0 / 100);
    }
    else if (ave >= 0.5)
    {
        setHP(HP1, HP1 - HP1 * 10.0 / 100);
        setEXP(EXP1, EXP1 + EXP1 * 20.0 / 100);
    }
    else
    {
        setHP(HP1, HP1 - HP1 * 15.0 / 100);
        setEXP(EXP1, EXP1 + EXP1 * 15.0 / 100);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int handleTaxi(int n)
{
    if (n / 10 == 0)
    {
        return n;
    }
    else
    {
        int donvi = n % 10;
        int chuc = n / 10;

        if (donvi + chuc > 9)
            return handleTaxi(donvi + chuc);
        else
            return donvi + chuc;
    }
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    setE(E3, E3);
    if (E3 == -1)
        return -99;
    setHP(HP1, HP1);
    setHP(HP2, HP2);
    setEXP(EXP1, EXP1);
    setEXP(EXP2, EXP2);

    int arr[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int higher{0};
    int lower{0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] > E3 * 2)
                higher++;
            if (arr[i][j] < -E3)
                lower++;
        }
    }

    higher = handleTaxi(higher);
    lower = handleTaxi(lower);
    // higher:i     lower:j
    // trai +1

    int i = higher;
    int j = lower;

    while (i > 0 && j < 9)
    {
        i--;
        j++;
    }
    int max1 = arr[i][j];
    while (i < 9 && j > 0)
    {
        if (max1 < arr[++i][--j])
            max1 = arr[i][j];
    }

    i = higher;
    j = lower;

    while (i > 0 && j > 0)
    {
        i--;
        j--;
    }
    int max2 = arr[i][j];
    while (i < 9 && j < 9)
    {
        if (max2 < arr[++i][++j])
            max2 = arr[i][j];
    }

    int max = (max1 > max2) ? max1 : max2;
    if (abs(arr[higher][lower]) <= max)
    {
        setHP(HP1, HP1 + HP1 * 10.0 / 100);
        setHP(HP2, HP2 + HP2 * 10.0 / 100);
        setEXP(EXP1, EXP1 + EXP1 * 12.0 / 100);
        setEXP(EXP2, EXP2 + EXP2 * 12.0 / 100);
    }
    else
    {
        setHP(HP1, HP1 - HP1 * 10.0 / 100);
        setHP(HP2, HP2 - HP2 * 10.0 / 100);
        setEXP(EXP1, EXP1 - EXP1 * 12.0 / 100);
        setEXP(EXP2, EXP2 - EXP2 * 12.0 / 100);
    }
    return (abs(arr[higher][lower]) > abs(max)) ? arr[higher][lower] : max;
}

// Task 4
bool chuakytudacbiet(const char *s)
{
    for (int i = 0; i < 100 && s[i] != '\0'; i++)
    {
        if (s[i] == '@' || s[i] == '!' || s[i] == '#' || s[i] == '%' || s[i] == '$')
            return true;
    }
    return false;
}
bool legitChar(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= '0' && c <= '9')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    if (c == '@' || c == '!' || c == '#' || c == '%' || c == '$')
        return true;
    return false;
}
int chua3kytulientiep(const char *s)
{
    for (int i = 1; i < 100 && s[i + 1] != '\0'; i++)
    {
        if (s[i - 1] == s[i] && s[i] == s[i + 1])
            return i - 1;
    }
    return -1;
}
int chuaSE(const char *s, string SE)
{
    string S = "";
    for (int i = 0; i < 100 && s[i] != '\0'; i++)
    {
        S += s[i];
    }
    size_t found = S.find(SE);
    if (found != string::npos)
        return found;
    else
        return -1;
}
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int Ssize = 0;
    for (int i = 0; i < 25 && s[i] != '\0'; i++)
    {
        Ssize++;
    }
    if (Ssize < 8)
    {
        return -1;
    }
    else if (Ssize > 20)
        return -2;

    string se = "";
    for (int i = 0; i < 100 && email[i] != '\0' && email[i] != '@'; i++)
    {
        se += email[i];
    }
    if (chuaSE(s, se) != -1)
        return -(300 + chuaSE(s, se));
    if (chua3kytulientiep(s) != -1)
        return -(400 + chua3kytulientiep(s));
    if (!chuakytudacbiet(s))
        return -5;
    for (int i = 0; i < 25 && s[i] != '\0'; i++)
    {
        if (!legitChar(s[i]))
            return i;
    }
    return -10;
}

// Task 5
int CountAppear(const char *str[], int size, string temp)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == temp)
            count++;
    }
    return count;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxAppear = 0;
    string maxStr = "";
    for (int i = 0; i < num_pwds; i++)
    {
        string temp = arr_pwds[i];
        if (CountAppear(arr_pwds, num_pwds, temp) > maxAppear)
        {
            maxAppear = CountAppear(arr_pwds, num_pwds, temp);
            maxStr = temp;
        }
        else if (CountAppear(arr_pwds, num_pwds, temp) == maxAppear)
        {
            if (maxStr.size() < temp.size())
                maxStr = temp;
        }
    }
    int ketqua;
    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == maxStr)
        {
            ketqua = i;
            break;
        }
    }
    return ketqua;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////