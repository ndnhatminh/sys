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
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if (e1 <= 3)
    {
        if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp2 = 0;
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;
        switch (e1)
        {
        case 0: exp2 += 29.0; break;
        case 1: exp2 += 45.0; break;
        case 2: exp2 += 75.0; break;
        case 3: exp2 += 149.0; break;

        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(float(exp1 + D / 200.0));
        if (D % 2 != 0) exp1 = ceil(float(exp1 - D / 100.0));
        if (exp1 > 600.0) exp1 = 600.0;
        if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp2 = 0;
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;
    }
    else
    {
        if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp2 = 0;
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;

        if (e1 >= 4 && e1 <= 19)
        {
            exp1 -= e1;
            exp2 = ceil(float(exp2 + e1 / 4.0 + 19.0));
        }
        if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(float(exp2 + e1 / 9.0 + 21.0));
            exp1 -= e1;
        }
        if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(float(exp2 + e1 / 16.0 + 17.0));
            exp1 -= e1;
        }
        if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(float(exp2 + e1 / 4.0 + 19.0));
            if (exp2 > 200) exp2 = ceil(float(exp2 + e1 / 9.0 + 21.0));
            exp1 -= e1;
        }
        if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(float(exp2 + e1 / 4.0 + 19.0));
            exp2 = ceil(float(exp2 + e1 / 9.0 + 21.0));
            if (exp2 > 400)
            {
                exp2 = ceil(float(exp2 + e1 / 16.0 + 17.0));
                exp2 = ceil(float(exp2 * 115.0 / 100));
            }
            exp1 -= e1;
        }
        if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp2 = 0;
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& hp1, int& exp1, int& m1, int e2) {
    // TODO: Complete this function
    if (e2 < 0 || e2 > 99) return -99;
    int p1, p2, p3;
    //Road 01
    int n = round(sqrt(exp1));
    int s = n * n;
    if (exp1 >= s) p1 = 100;
    else p1 = float((exp1 / s + 80) / 1.23);
    //Road 02
    if (e2 % 2)
    {
        int spending = 0;
        int event = 2;
        int fund = ceil(float(m1 * 0.5));
        while (spending < fund)
        {
            switch (++event % 3)
            {
            case 0: 
                if (hp1 < 200)
                {
                    hp1 = ceil(float(hp1 * 1.3));
                    m1 -= 150;
                    spending += 150;
                }
                else
                {
                    hp1 = ceil(float(hp1 * 1.1));
                    m1 -= 70;
                    spending += 70;
                }
                if (hp1 > 666) hp1 = 666;
                if (m1 < 0) m1 = 0;
                break;
            case 1:
                if (exp1 < 400)
                {
                    m1 -= 200;
                    spending += 200;
                }
                else
                {
                    m1 -= 120;
                    spending += 120;
                }
                exp1 = ceil(float(exp1 * 1.13));
                if (exp1 > 600) exp1 = 600;
                if (m1 < 0) m1 = 0;
                break;
            case 2:
                if (exp1 < 300)
                {
                    m1 -= 100;
                    spending += 100;
                }
                else
                {
                    m1 -= 120;
                    spending += 120;
                }
                exp1 = ceil(float(exp1 * 0.9));
                if (m1 < 0) m1 = 0;
                break;
            }
        }
    }
    else
    {
        int event = 0;
        while (m1 != 0 && event != 3)
        {
            switch (event++)
            {
            case 0: 
                if (hp1 < 200)
                {
                    hp1 = ceil(float(hp1 * 1.3));
                    m1 -= 150;
                }
                else
                {
                    hp1 = ceil(float(hp1 * 1.1));
                    m1 -= 70;
                }
                if (hp1 > 666) hp1 = 666;
                if (m1 < 0) m1 = 0;
                break;
            case 1: 
                if (exp1 < 400) m1 -= 200;
                else m1 -= 120;
                exp1 = ceil(float(exp1 * 1.13));
                if (exp1 > 600) exp1 = 600;
                if (m1 < 0) m1 = 0;
                break;
            case 2: 
                if (exp1 < 300) m1 -= 100;
                else m1 -= 120;
                exp1 = ceil(float(exp1 * 0.9));
                if (m1 < 0) m1 = 0;
                break;
            }
        }
    }
    hp1 = ceil(float(hp1 * 0.83));
    exp1 = ceil(float(exp1 * 1.17));
    if (exp1 > 600) exp1 = 600;
    s = round(sqrt(exp1));
    s = s * s;
    if (exp1 >= s) p2 = 100;
    else p2 = float((exp1 / s + 80) / 1.23);
    //Road 03
    int i = (e2 / 10 + e2 % 10) % 10;
    int random[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    p3 = random[i];
    if (p1 == 100 && p2 == 100 && p3 == 100) exp1 = ceil(float(exp1 * 0.75));
    int p = float((p1 + p2 + p3) / 3);
    if (p < 50)
    {
        hp1 = ceil(float(hp1 * 0.85));
        exp1 = ceil(float(exp1 * 1.15));
    }
    else
    {
        hp1 = ceil(float(hp1 * 0.9));
        exp1 = ceil(float(exp1 * 1.2));
    }
    if (exp1 > 600) exp1 = 600;
    return hp1 + exp1 + m1;
}




// Task 3
int chaseTaxi(int& hp1, int& exp1, int& hp2, int& exp2, int e3)
{

    if (e3 < 0 || e3 > 99) return -99;
    int Taxi[10][10], Sherlock[10][10], Left[19] = { 0 }, Right[19] = { 0 };
    int x = 0, y = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Taxi[i][j] = ((e3 * j) + (i * 2)) * (i - j);
            Left[i - j + 9] = max(Left[i - j + 9], Taxi[i][j]);
            Right[i + j] = max(Right[i + j], Taxi[i][j]);
            x += (Taxi[i][j] > e3 * 2);
            y += (Taxi[i][j] < -e3);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Sherlock[i][j] = abs(max(Left[i - j + 9], Right[i + j]));
        }
    }
    while (x > 9)
    {
        x = x / 10 + x % 10;
    }
    while (y > 9)
    {
        y = y / 10 + y % 10;
    }
    if (abs(Taxi[x][y]) > Sherlock[x][y])
    {
        exp1 = ceil(exp1 * 0.88);
        hp1 = ceil(hp1 * 0.90);
        exp2 = ceil(exp2 * 0.88);
        hp2 = ceil(hp2 * 0.90);
        return Taxi[x][y];
    }
    else
    {
        exp1 = min(ceil(exp1 * 1.12), 600.0);
        hp1 = min(ceil(hp1 * 1.10), 666.0);
        exp2 = min(ceil(exp2 * 1.12), 600.0);
        hp2 = min(ceil(hp2 * 1.10), 666.0);
        return Sherlock[x][y];
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int n = strlen(s);
    if (n < 8) return -1;
    if (n > 20) return -2;

    const char* at = strchr(email, '@');
    std::string se(email, at);

    if (strstr(s, se.c_str())) return -(300 + (strstr(s, se.c_str()) - s));

    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
    }

    bool specialChar = false;
    for (int i = 0; i < n; ++i) {
        if (!isdigit(s[i]) && !isalpha(s[i]) && strchr("@#%$!", s[i]) == NULL) return i;
        if (strchr("@#%$!", s[i])) specialChar = true;
    }

    if (!specialChar) return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    char matkhau[256];
    int count = 0;
    int maxCount = 0;
    int pos = -1;
    int maxLen = 0;
    for (int i = 0; i < num_pwds; i++) {
        int currentCount = 0;
        int currentLen = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            strcpy(matkhau, arr_pwds[i]);
            pos = i;
            maxLen = currentLen;
        }
        else if (currentCount == maxCount && currentLen > maxLen) {
            maxLen = currentLen;
            strcpy(matkhau, arr_pwds[i]);
            pos = i;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////