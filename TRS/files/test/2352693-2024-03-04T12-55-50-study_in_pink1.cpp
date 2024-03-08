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

bool isEven(int n)
{
    return n % 2 == 0 ? true : false;
}

void newExp(int &n)
{
    if (n <= 0)
        n = 0;
    else if (n >= 600)
        n = 600;
}

void newHp(int &n)
{
    if (n <= 0)
        n = 0;
    else if (n >= 666)
        n = 666;
}

void newMoney(int &n)
{
    if (n <= 0)
        n = 0;
    else if (n >= 3000)
        n = 3000;
}

int CPGanNhat(int n)
{
    int can = sqrt(n);
    if (abs((can * can) - n) <= abs((can + 1) * (can + 1) - n))
        return can * can;
    else
        return (can + 1) * (can + 1);
}

int rutgon(int n)
{
    if (n >= 10)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n = n / 10;
        }
        return rutgon(sum);
    }
    return n;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 >= 0 && e1 <= 3)
    {
        newExp(exp1);
        newExp(exp2);
        switch (e1)
        {
        case 0:
            exp2 += 29;
            newExp(exp2);
            break;
        case 1:
            exp2 += 45;
            newExp(exp2);
            break;
        case 2:
            exp2 += 75;
            newExp(exp2);
            break;
        case 3:
            exp2 += (29 + 45 + 75);
            newExp(exp2);
            break;
        default:
            break;
        }
        if (isEven(e1 * 3 + exp1 * 7) == 1)
        {
            exp1 = ceil(exp1 + (e1 * 3 + exp1 * 7) / 200.0 - 1e-10);
            newExp(exp1);
        }
        else if (isEven(e1 * 3 + exp1 * 7) == 0)
        {
            exp1 = ceil(exp1 - (e1 * 3 + exp1 * 7) / 100.0 - 1e-10);
            newExp(exp1);
        }
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        newExp(exp1);
        newExp(exp2);
        switch (e1)
        {
        case 4 ... 19:
            exp2 = ceil(exp2 + (e1 / 4.0 + 19) - 1e-10);
            newExp(exp2);
            break;
        case 20 ... 49:
            exp2 = ceil(exp2 + (e1 / 9.0 + 21) - 1e-10);
            newExp(exp2);
            break;
        case 50 ... 65:
            exp2 = ceil(exp2 + (e1 / 16.0 + 17) - 1e-10);
            newExp(exp2);
            break;
        case 66 ... 79:
            exp2 = ceil(exp2 + (e1 / 4.0 + 19) - 1e-10);
            newExp(exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (e1 / 9.0 + 21) - 1e-10);
                newExp(exp2);
            }
            break;
        case 80 ... 99:
            exp2 = ceil(exp2 + (e1 / 4.0 + 19) - 1e-10);
            newExp(exp2);
            exp2 = ceil(exp2 + (e1 / 9.0 + 21) - 1e-10);
            newExp(exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (e1 / 16.0 + 17) - 1e-10);
                newExp(exp2);
                exp2 = ceil(exp2 * 115 / 100.0 - 1e-10);
                newExp(exp2);
            }
            break;
        default:
            break;
        }
        exp1 -= e1;
        newExp(exp1);
    }
    else
        return -99;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (0 <= E2 && E2 <= 99)
    {
        newHp(HP1);
        newExp(EXP1);
        newMoney(M1);
        double P1 = 0.0;
        if (EXP1 >= CPGanNhat(EXP1))
            P1 = 1.0;
        else if (EXP1 < CPGanNhat(EXP1))
            P1 = (EXP1 / CPGanNhat(EXP1) * 1.0 + 80) / 123.0;
        if (isEven(E2) == 0)
        {
            double Money = 0.0;
            double HalfMon = 50 / 100.0 * M1;
            while (Money <= HalfMon && M1 > 0)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 * 130 / 100.0 - 1e-10);
                    newHp(HP1);
                    Money += 150;
                }
                else
                {
                    HP1 = ceil(HP1 * 110 / 100.0 - 1e-10);
                    newHp(HP1);
                    Money += 70;
                }
                if (Money > HalfMon)
                    break;
                if (EXP1 < 400)
                {
                    EXP1 = ceil(EXP1 * 113 / 100.0 - 1e-10);
                    newExp(EXP1);
                    Money += 200;
                }
                else
                {
                    EXP1 = ceil(EXP1 * 113 / 100.0 - 1e-10);
                    newExp(EXP1);
                    Money += 120;
                }
                if (Money > HalfMon)
                    break;
                if (EXP1 < 300)
                {
                    EXP1 = ceil(EXP1 * 90 / 100.0 - 1e-10);
                    newExp(EXP1);
                    Money += 100;
                }
                else
                {
                    EXP1 = ceil(EXP1 * 90 / 100.0 - 1e-10);
                    newExp(EXP1);
                    Money += 120;
                }
                if (Money > HalfMon)
                    break;
            }
            HP1 = ceil(HP1 * 83 / 100.0 - 1e-10);
            newHp(HP1);
            EXP1 = ceil(EXP1 * 117 / 100.0 - 1e-10);
            newExp(EXP1);
            M1 = M1 - Money;
            newMoney(M1);
        }
        else
        {
            while (M1 != 0)
            {
                if (HP1 < 200)
                {
                    HP1 = ceil(HP1 * 130 / 100.0 - 1e-10);
                    newHp(HP1);
                    M1 -= 150;
                    newMoney(M1);
                    if (M1 == 0)
                        break;
                }
                else if (HP1 >= 200)
                {
                    HP1 = ceil(HP1 * 110 / 100.0 - 1e-10);
                    newHp(HP1);
                    M1 -= 70;
                    newMoney(M1);
                    if (M1 == 0)
                        break;
                }
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    newMoney(M1);
                    EXP1 = ceil(EXP1 * 113 / 100.0 - 1e-10);
                    newExp(EXP1);
                    if (M1 == 0)
                        break;
                }
                else if (EXP1 >= 400)
                {
                    M1 -= 120;
                    newMoney(M1);
                    EXP1 = ceil(EXP1 * 113 / 100.0 - 1e-10);
                    newExp(EXP1);
                    if (M1 == 0)
                        break;
                }
                // Track2.3
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    newMoney(M1);
                    EXP1 = ceil(EXP1 * 90 / 100.0 - 1e-10);
                    newExp(EXP1);
                    if (M1 == 0)
                        break;
                }
                else if (EXP1 >= 300)
                {
                    M1 -= 120;
                    newMoney(M1);
                    EXP1 = ceil(EXP1 * 90 / 100.0 - 1e-10);
                    newExp(EXP1);
                    if (M1 == 0)
                        break;
                }
                break;
            }
            HP1 = ceil(HP1 * 83 / 100.0 - 1e-10);
            newHp(HP1);
            EXP1 = ceil(EXP1 * 117 / 100.0 - 1e-10);
            newExp(EXP1);
        }
        double P2 = 0.0;
        if (EXP1 >= CPGanNhat(EXP1))
            P2 = 100 / 100.0;
        else if (EXP1 < CPGanNhat(EXP1))
            P2 = (EXP1 / CPGanNhat(EXP1) * 1.0 + 80) / 123.0;
        double P[10] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
        double P3 = 0.0;
        if (0 <= E2 && E2 <= 9)
            P3 = P[E2];
        else if (E2 >= 10)
        {
            int E = (E2 / 10 + E2 % 10) % 10;
            P3 = P[E];
        }
        double AveP = (P1 + P2 + P3) / 3.0;
        if (AveP == 1)
        {
            EXP1 = ceil(EXP1 * 75 / 100.0 - 1e-10);
            newExp(EXP1);
        }
        else if (AveP < 0.5)
        {
            HP1 = ceil(HP1 * 85 / 100.0 - 1e-10);
            newHp(HP1);
            EXP1 = ceil(EXP1 * 115 / 100.0 - 1e-10);
            newExp(EXP1);
        }
        else if (AveP >= 0.5)
        {
            HP1 = ceil(HP1 * 90 / 100.0 - 1e-10);
            newHp(HP1);
            EXP1 = ceil(EXP1 * 120 / 100.0 - 1e-10);
            newExp(EXP1);
        }
    }
    else
        return -99;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    int result = 0;
    if (0 <= E3 && E3 <= 99)
    {
        newHp(HP1);
        newHp(HP2);
        newExp(EXP1);
        newExp(EXP2);
        int matrix[10][10];
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
                matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
        int count_i = 0, count_j = 0;
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (matrix[i][j] > 2 * E3)
                    count_i++;
                else if (matrix[i][j] < -E3)
                    count_j++;
            }
        }
        count_i = rutgon(count_i);
        count_j = rutgon(count_j);
        int max_value = matrix[count_i][count_j];
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if ((i + j) == (count_i + count_j))
                {
                    if (matrix[i][j] >= max_value)
                        max_value = matrix[i][j];
                }
            }
        }
        int i = count_i;
        int j = count_j;
        while (0 <= i && i <= 9 && j <= 9 && j >= 0)
        {
            if (matrix[i][j] >= max_value)
                max_value = matrix[i][j];
            i++;
            j++;
        }
        int m = count_i;
        int n = count_j;
        while (0 <= m && m <= 9 && n <= 9 && n >= 0)
        {
            if (matrix[m][n] >= max_value)
                max_value = matrix[m][n];
            m--;
            n--;
        }
        if (abs(max_value) < abs(matrix[count_i][count_j]))
        {
            EXP1 = ceil(EXP1 * 88 / 100.0 - 1e-10);
            newExp(EXP1);
            EXP2 = ceil(EXP2 * 88 / 100.0 - 1e-10);
            newExp(EXP2);
            HP1 = ceil(HP1 * 90 / 100.0 - 1e-10);
            newHp(HP1);
            HP2 = ceil(HP2 * 90 / 100.0 - 1e-10);
            newHp(HP2);
            result = matrix[count_i][count_j];
        }
        else if (abs(max_value) >= abs(matrix[count_i][count_j]))
        {
            EXP1 = ceil(EXP1 * 112 / 100.0 - 1e-10);
            newExp(EXP1);
            EXP2 = ceil(EXP2 * 112 / 100.0 - 1e-10);
            newExp(EXP2);
            HP1 = ceil(HP1 * 110 / 100.0 - 1e-10);
            newHp(HP1);
            HP2 = ceil(HP2 * 110 / 100.0 - 1e-10);
            newHp(HP2);
            result = max_value;
        }
    }
    else
        return -99;
    return result;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string kiemtra(s);
    string emailString(email);
    int atPosition = emailString.find('@');
    string se = emailString.substr(0, atPosition);
    bool Character = false, Dup = false, Special = false, Long = false, Contain = false;
    int WrongPositon = 0, DupPositon = 0;
    for (int i = 0; i < kiemtra.length(); i++)
    {
        char c = s[i];
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
            Character = true;
        else
        {
            Character = false;
            WrongPositon = i;
            break;
        }
    }
    for (int i = 0; i < kiemtra.length() - 2; i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            Dup = true;
            DupPositon = i;
            break;
        }
    }
    if (kiemtra.find('@') == string::npos && kiemtra.find('#') == string::npos && kiemtra.find('%') == string::npos && kiemtra.find('$') == string::npos && kiemtra.find('!') == string::npos)
        Special = true;
    if (kiemtra.length() >= 8 && kiemtra.length() <= 20)
        Long = true;
    if (kiemtra.find(se) == string::npos)
        Contain = true;
    if (Long && Character && Contain && !Dup && !Special)
        return -10;
    if (kiemtra.length() < 8)
        return -1;
    if (kiemtra.length() > 20)
        return -2;
    if (!Contain)
        return -(300 + kiemtra.find(se));
    if (Dup)
        return -(400 + DupPositon);
    if (Special)
        return -5;
    return WrongPositon;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    string PasswordString[num_pwds];
    int counter[num_pwds];
    for (int i = 0; i < num_pwds; i++)
        counter[i] = 0;
    for (int i = 0; i < num_pwds; i++)
        PasswordString[i] = (string)arr_pwds[i];
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (PasswordString[i] == PasswordString[j])
                counter[i]++;
        }
    }
    int maxf = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (counter[i] > maxf)
            maxf = counter[i];
    }
    int maxc = 0;
    int indexmax = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (counter[i] == maxf)
        {
            if (PasswordString[i].length() > maxc)
            {
                maxc = PasswordString[i].length();
                indexmax = i;
            }
        }
    }
    return indexmax;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////