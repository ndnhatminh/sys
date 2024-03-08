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
    int& E3)
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
void health(int& hp)
{
    if (hp < 0)
        hp = 0;
    if (hp > 666)
        hp = 666;
}

void experience(int& exp)
{
    if (exp < 0)
        exp = 0;
    if (exp > 600)
        exp = 600;
}

void money(int& m)
{
    if (m < 0)
        m = 0;
    if (m > 3000)
        m = 3000;
}

void event(int& e)
{
    if (e < 0 || e > 99)
        e = -99;
}

// dem so gia tri DUONG thoa
int countPos(int a[][10], int E3)
{
    int demDuong = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > 0 && a[i][j] > E3 * 2)
                demDuong++;
        }
    }
    return demDuong;
}
// dem so gia tri AM thoa
int countNega(int a[][10], int E3)
{
    int demAm = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] < -E3)
                demAm++;
        }
    }
    return demAm;
}

int coordinate(int x)
{
    int coordinate;
    for (int i = 0; i < 20; i++)
    {
        if (x < 10)
        {
            coordinate = x;
            break;
        }
        else
        {
            int unit = x % 10;
            int tenth = (x / 10) % 10;
            int sum = unit + tenth;
            x = sum;
        }
    }
    return coordinate;
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
    // TODO: Complete this function
    float x;
    experience(exp1);
    experience(exp2);
    event(e1);
    if (e1 == -99)
    {
        return -99;
    }
    // case 1
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            experience(exp2);
            break;

        case 1:
            exp2 += 45;
            experience(exp2);
            break;

        case 2:
            exp2 += 75;
            experience(exp2);
            break;

        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            experience(exp2);
            break;

        default:
            break;
        }

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 != 0)
        {
            x = exp1 - (D / 100.0);
            exp1 = ceil(x);
            experience(exp1);
        }
        else if (D % 2 == 0)
        {
            x = exp1 + (D / 200.0);
            exp1 = ceil(x);
            experience(exp1);
        }
    }

    // case 2
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            x = exp2 + (e1 / 4.0 + 19);
            exp2 = ceil(x);
            experience(exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            x = exp2 + (e1 / 9.0 + 21);
            exp2 = ceil(x);
            experience(exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            x = exp2 + (e1 / 16.0 + 17);
            exp2 = ceil(x);
            experience(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            x = exp2 + (e1 / 4.0 + 19);
            exp2 = ceil(x);
            experience(exp2);

            if (exp2 > 200)
            {
                x = exp2 + (e1 / 9.0 + 21);
                exp2 = ceil(x);
                experience(exp2);
            }
        }
        else
        { // e1 in the range [80,99]
            x = exp2 + (e1 / 4.0 + 19);
            exp2 = ceil(x);
            experience(exp2);
            x = exp2 + (e1 / 9.0 + 21);
            exp2 = ceil(x);
            experience(exp2);

            if (exp2 > 400)
            {
                x = exp2 + (e1 / 16.0 + 17);
                exp2 = ceil(x);
                experience(exp2);
                x = exp2 * 1.15;
                exp2 = ceil(x);
                experience(exp2);
            }
        }

        exp1 -= e1;
        experience(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    // TODO: Complete this function
    health(HP1);
    experience(EXP1);
    money(M1);
    event(E2);
    if (E2 == -99)
    {
        return -99;
    }

    // Road 01
    float S = round(float(sqrt(EXP1))) * round(float(sqrt(EXP1)));
    float P1;
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = ((EXP1 / S + 80) / 123.0) * 100;
    }
    // Road 02
    float half_M1 = M1 * 0.5;
    // Odd event code
    if (E2 % 2 == 1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (M1 > 0)
            {
                // 1st dot
                if (HP1 < 200)
                {
                    float x = HP1 * 1.3;
                    HP1 = ceil(x);
                    health(HP1);
                    M1 -= 150;
                    money(M1);
                    if (M1 == 0 || M1 < half_M1)
                        break;
                }
                else
                {
                    float x = HP1 * 1.1;
                    HP1 = ceil(x);
                    health(HP1);
                    M1 -= 70;
                    money(M1);
                    if (M1 == 0 || M1 < half_M1)
                        break;
                }
            }
            else break;

            if (M1 > 0)
            {
                // 2nd dot
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    float x = EXP1 * 1.13;
                    EXP1 = ceil(x);
                    experience(EXP1);
                    money(M1);
                    if (M1 == 0 || M1 < half_M1)
                        break;
                }
                else
                {
                    M1 -= 120;
                    float x = EXP1 * 1.13;
                    EXP1 = ceil(x);
                    experience(EXP1);
                    money(M1);
                    if (M1 == 0 || M1 < half_M1)
                        break;
                }
            }
            else break;

            if (M1 > 0)
            {
                // 3rd dot
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    float x = EXP1 * 0.9;
                    EXP1 = ceil(x);
                    money(M1);
                    if (M1 == 0 || M1 < half_M1)
                        break;
                }
                else
                {
                    M1 -= 120;
                    float x = EXP1 * 0.9;
                    EXP1 = ceil(x);
                    money(M1);
                    if (M1 == 0 || M1 < half_M1)
                        break;
                }
            }
            else break;
        }
        float x = HP1 * 0.83;
        HP1 = ceil(x);
        health(HP1);
        float y = EXP1 * 1.17;
        EXP1 = ceil(y);
        experience(EXP1);
    }
    // Even event code
    else
    {
        for (int i = 0; i < 1; i++)
        {
            if (M1 > 0)
            {
                // 1st dot
                if (HP1 < 200)
                {
                    float x = HP1 * 1.3;
                    HP1 = ceil(x);
                    health(HP1);
                    M1 -= 150;
                    money(M1);
                }
                else
                {
                    float x = HP1 * 1.1;
                    HP1 = ceil(x);
                    health(HP1);
                    M1 -= 70;
                    money(M1);
                }
                if (M1 == 0)
                    break;
            }
            else break;

            if (M1 > 0)
            {
                // 2nd dot
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    money(M1);
                    float x = EXP1 * 1.13;
                    EXP1 = ceil(x);
                    experience(EXP1);
                    money(M1);
                }
                else
                {
                    M1 -= 120;
                    money(M1);
                    float x = EXP1 * 1.13;
                    EXP1 = ceil(x);
                    experience(EXP1);
                    money(M1);
                }
                if (M1 == 0)
                    break;
            }
            else break;

            if (M1 > 0)
            {
                // 3rd dot
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    money(M1);
                    float x = EXP1 * 0.9;
                    EXP1 = ceil(x);
                    experience(EXP1);
                    money(M1);
                }
                else
                {
                    M1 -= 120;
                    money(M1);
                    float x = EXP1 * 0.9;
                    EXP1 = ceil(x);
                    experience(EXP1);
                    money(M1);
                }
                if (M1 == 0)
                    break;
            }
            else break;
        }
        float x = HP1 * 0.83;
        HP1 = ceil(x);
        health(HP1);
        float y = EXP1 * 1.17;
        EXP1 = ceil(y);
        experience(EXP1);
    }
    float P2;
    float S2 = round(float(sqrt(EXP1))) * round(float(sqrt(EXP1)));
    if (EXP1 >= S2)
    {
        P2 = 100;
    }
    else
    {
        P2 = ((EXP1 / S2 + 80) / 123.0) * 100;
    }

    // 3rd way
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    int P3 = 0;
    if (E2 < 10)
    {
        i = E2;
        P3 = P[i];
    }
    else if (E2 >= 10 && E2 < 100)
    {
        int unit = E2 % 10;
        int tenth = (E2 / 10) % 10;
        int sum = unit + tenth;
        i = sum % 10;
        P3 = P[i];
    }

    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        float a = EXP1 * 0.75;
        EXP1 = ceil(a);
        experience(EXP1);
    }

    else if (P1 != 100 || P2 != 100 || P3 != 100)
    {
        float P_mean = (P1 + P2 + P3) / 3;
        if (P_mean < 50)
        {
            float x, y;
            x = HP1 * 0.85;
            HP1 = ceil(x);
            health(HP1);
            y = EXP1 * 1.15;
            EXP1 = ceil(y);
            experience(EXP1);
        }
        else if (P_mean > 50)
        {
            float x, y;
            x = HP1 * 0.9;
            HP1 = ceil(x);
            health(HP1);
            y = EXP1 * 1.2;
            EXP1 = ceil(y);
            experience(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    // TODO: Complete this function
    health(HP1);
    health(HP2);
    experience(EXP1);
    experience(EXP2);
    event(E3);
    if (E3 == -99)
    {
        return -99;
    }

    // diem cua taxi
    int a[10][10] = { 0 };
    for (int v = 0; v < 10; v++)
    {
        for (int l = 0; l < 10; l++)
        {
            a[v][l] = ((E3 * l) + (v * 2)) * (v - l);
        }
    }


    // tim i,j cho den khi tong con 1 chu so
    int i, j;
    i = coordinate(countPos(a, E3));
    j = coordinate(countNega(a, E3));

    // diem cua Sherlock va Watson
    int b[10][10];
    for (int c = 0; c < 10; c++)
    {
        for (int d = 0; d < 10; d++)
        {
            int e = c;
            int f = d;
            int t = c;
            int n = d;
            // cheo trai
            for (int z = 0; z < 10; z++)
            {
                if (t == 0 || n == 0)
                {
                    break;
                }
                else
                {
                    t--;
                    n--;
                }
            }
            int largest_left = a[t][n];

            // cheo phai
            for (int z = 0; z < 10; z++)
            {
                if (e == 0 || f == 9)
                {
                    break;
                }
                else
                {
                    e--;
                    f++;
                }
            }
            int largest_right = a[e][f];

            // find the largest
            //cheo trai
            for (int h1 = t + 1; h1 < 10; h1++)
            {
                for (int c1 = n + 1; c1 < 10; c1++)
                {
                    if (a[t + 1][n + 1] > largest_left)
                    {
                        largest_left = a[t + 1][n + 1];
                    }
                    else
                    {
                        t++;
                        n++;
                    }
                }
            }

            //cheo phai
            for (int h2 = e + 1; h2 < 10; h2++)
            {
                for (int c2 = f - 1; c2 > -1; c2--)
                {
                    if (a[e + 1][f - 1] > largest_right)
                    {
                        largest_right = a[e + 1][f - 1];
                    }
                    else
                    {
                        e++;
                        f--;
                    }
                }
            }

            int largest;
            // compare
            if (largest_left > largest_right)
            {
                largest = largest_left;
            }
            else
            {
                largest = largest_right;
            }

            b[c][d] = largest;

        }
    }


    if (abs(a[i][j]) <= b[i][j])
    {
        float x, y, z, w;
        x = EXP1 * 1.12;
        EXP1 = ceil(x);
        experience(EXP1);
        y = HP1 * 1.1;
        HP1 = ceil(y);
        health(HP1);
        z = EXP2 * 1.12;
        EXP2 = ceil(z);
        experience(EXP2);
        w = HP2 * 1.1;
        HP2 = ceil(w);
        health(HP2);
    }
    else
    {
        float x, y, z, w;
        x = EXP1 * 0.88;
        EXP1 = ceil(x);
        experience(EXP1);
        y = HP1 * 0.9;
        HP1 = ceil(y);
        health(HP1);
        z = EXP2 * 0.88;
        EXP2 = ceil(z);
        experience(EXP2);
        w = HP2 * 0.9;
        HP2 = ceil(w);
        health(HP2);
    }
    if (abs(a[i][j]) >= b[i][j])
    {
        return a[i][j];
    }
    else
        return b[i][j];
};
// Task 4
int checkPassword(const char* s, const char* email)
{
    // TODO: Complete this function
    int c,
        a = strlen(s),
        b = strlen(email),
        d = 0,
        e = 0;
    string se = "";
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
            se += email[i];
    }
    // Check if the length of the password is within the range

    if (a < 8)
    {
        return -1; // shorter than minimum length
    }
    if (a > 20)
    {
        return -2; // longer than maximum length
    }

    for (int i = 0; i < a; i++)
    {
        if (se == "")
        {
            return -300;
            break;
        }
        else if (s[i] == se[0])
        {
            d = 1;
            for (int j = 0; j < se.length(); j++)
            {
                if (i + j + 1 > a)
                {
                    d = 0;
                    break;
                }
                if (s[i + j] != se[j])
                {
                    d = 0;
                    break;
                }
            }
        }
        if (d != 0)
        {
            return -(300 + i);
            break;
        }
    }
    // Check if each character is valid and if there are consecutive identical characters

    for (int i = 0; i < a; i++)
    {
        if (i + 2 <= a - 1)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                return -(400 + i);
            }
        }
    }
    int z = 0;
    for (int i = 0; i < a; i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            z = 1; // Invalid character
        }
    }
    if (z == 0)
    {
        return -5;
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%!";
    for (int i = 0; i < a; i++)
    {
        int h = -1;
        for (int j = 0; j < alphabet.length(); j++)
        {
            if (s[i] == alphabet[j])
            {
                h = i;
                break;
            }
        }
        if (h == -1)
        {
            return i;
        }
    }
    return -10;
}

// Task5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    // most frequency string
    int freqArray[30] = { 0 }, freqArray1[30] = { 0 };
    int maxFreq = 0;
    string mostFreqElement[30] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    };
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                freqArray[i]++;
            }
        }

        if (maxFreq < freqArray[i])
        {
            maxFreq = freqArray[i];
        }
    }
    // location of the maxFreq
    int position = -1;
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                freqArray1[i]++;
            }
        }
        if (maxFreq == freqArray1[i])
        {
            mostFreqElement[i] = arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (mostFreqElement[i].length() >= mostFreqElement[j].length())
            {
                position = i;
            }
            else
            {
                position = -1;
                break;
            }
        }
        if (position != -1)
            break;
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

