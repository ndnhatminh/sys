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

int Round(double value) {
    int a = static_cast<int>(value * 1000);
    if (a % 1000 != 0)
        return a / 1000 + 1;
    else return a / 1000;
}

int setHP(double hp) {
    if (hp < 0)
        return 0;
    else if (hp > 666)
        return 666;
    else return Round(hp);
}

int setEXP(double exp) {
    if (exp < 0)
        return 0;
    else if (exp > 600)
        return 600;
    else return Round(exp);
}

int setMoney(double money) {
    if (money < 0)
        return 0;
    else if (money > 3000)
        return 3000;
    else return Round(money);
}

int find_nearest_squareNum(double exp1) {
    return pow((round(sqrt(exp1))), 2);
}

bool isalnum(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool isnot_special_char(char c) {
    return (isalnum(c) == false && ((c != '@') && (c != '#') && (c != '%') && (c != '$') && (c != '!')));
}

int convertNum(int index) {
    if (index / 10 != 0)
    {
        index = index % 10 + index / 10;
        return convertNum(index);
    }
    else
        return index;
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    int D = 0;
    if (e1 < 0 || e1>99)
        return -99;
    else {
        exp1 = setEXP(exp1);
        exp2 = setEXP(exp2);
        if (e1 >= 0 && e1 <= 3) {
            switch (e1) {
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
                exp2 += 29 + 45 + 75;
                break;
            }
            exp2 = setEXP(exp2);
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
                exp1 = setEXP(exp1 + static_cast<double>(D) / 200);
            else exp1 = setEXP(exp1 - static_cast<double>(D) / 100);
        }
        if (e1 > 3 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19)
                exp2 = setEXP(exp2 + static_cast<double>(e1) / 4 + 19);     // info 1
            else if (e1 >= 20 && e1 <= 49)
                exp2 = setEXP(exp2 + static_cast<double>(e1) / 9 + 21);     // info 2
            else if (e1 >= 50 && e1 <= 65)
                exp2 = setEXP(exp2 + static_cast<double>(e1) / 16 + 17);    // info 3
            else if (e1 >= 66 && e1 <= 79) {                                // info 4
                exp2 = setEXP(exp2 + static_cast<double>(e1) / 4 + 19);
                if (exp2 > 200)
                    exp2 = setEXP(exp2 + static_cast<double>(e1) / 9 + 21);
            }
            else if (e1 >= 80 && e1 <= 99) {                                // info 5
                exp2 = setEXP(exp2 + static_cast<double>(e1) / 4 + 19);
                exp2 = setEXP(exp2 + static_cast<double>(e1) / 9 + 21);
                if (exp2 > 400) {
                    exp2 = setEXP(exp2 + static_cast<double>(e1) / 16 + 17);
                    exp2 = setEXP(static_cast<double>(exp2) * 1.15);
                }
            }
            exp1 = setEXP(exp1 - e1);
        }
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    int S;
    double P1, P2, P3, finalRate;
    if (E2 < 0 || E2>99)
        return -99;
    else {
        HP1 = setHP(HP1);
        EXP1 = setEXP(EXP1);
        M1 = setMoney(M1);
        S = find_nearest_squareNum(EXP1);
        // 1st way
        if (EXP1 >= S)
            P1 = 100;
        else P1 = ((static_cast<double>(EXP1) / S + 80) / 123)*100;

        // 2nd way
        int initial_money = M1, spentMoney = 0;
        if (E2 % 2 != 0) {                  // e2 odd
            while (true) {
                // event 1
                if (M1==0)
                    break;
                if (HP1 < 200) {
                    HP1 = setHP(HP1 * 1.3);
                    M1 = setMoney(M1 - 150);
                    spentMoney += 150;
                }
                else {
                    HP1 = setHP(HP1 * 1.1);
                    M1 = setMoney(M1 - 70);
                    spentMoney += 70;
                }
                if (static_cast<double>(spentMoney) / initial_money > 0.5)
                    break;
                // event 2
                if (EXP1 < 400) {
                    M1 = setMoney(M1 - 200);
                    spentMoney += 200;
                    EXP1 = setEXP(EXP1 * 1.13);
                }
                else {
                    M1 = setMoney(M1 - 120);
                    spentMoney += 120;
                    EXP1 = setEXP(EXP1 * 1.13);
                }
                if (static_cast<double>(spentMoney) / initial_money > 0.5)
                    break;
                // event 3
                if (EXP1 < 300) {
                    M1 = setMoney(M1 - 100);
                    spentMoney += 100;
                }
                else {
                    M1 = setMoney(M1 - 120);
                    spentMoney += 120;
                }
                EXP1 = setEXP(EXP1 * 0.9);             // misleading
                if (static_cast<double>(spentMoney) / initial_money > 0.5)
                    break;
            }
            HP1 = setHP(HP1 * 0.83);
            EXP1 = setEXP(EXP1 * 1.17);
        }
        else {                               // e2 even
            while (true) {
                // event 1
                if (M1 == 0)
                    break;
                if (HP1 < 200) {
                    HP1 = setHP(HP1 * 1.3);
                    M1 = setMoney(M1 - 150);
                }
                else {
                    HP1 = setHP(HP1 * 1.1);
                    M1 = setMoney(M1 - 70);
                }
                if (M1 == 0)
                    break;

                // event 2
                if (EXP1 < 400) {
                    M1 = setMoney(M1 - 200);
                    EXP1 = setEXP(EXP1 * 1.13);
                }
                else {
                    M1 = setMoney(M1 - 120);
                    EXP1 = setEXP(EXP1 * 1.13);
                }
                if (M1 == 0)
                    break;

                // event 3
                if (EXP1 < 300)
                    M1 = setMoney(M1 - 100);
                else M1 = setMoney(M1 - 120);
                EXP1 = setEXP(EXP1 * 0.9); // misleading
                if (M1 == 0)
                    break;
                break;
            }
            HP1 = setHP(HP1 * 0.83);
            EXP1 = setEXP(EXP1 * 1.17);
        }
        S = find_nearest_squareNum(EXP1);
        if (EXP1 >= S)
            P2 = 100;
        else P2 = ((static_cast<double>(EXP1) / S + 80) / 123)*100;
        // 3rd way
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int idx = 0, x = E2;
        while (x != 0) {
            idx += x % 10;
            x /= 10;
        }
        idx = idx % 10;
        P3 = P[idx];

        if ((P1 + P2 + P3) / 3 == 100) {
            EXP1 = setEXP(EXP1 * 0.75);
            //traceLuggage(HP1, EXP1, M1, E2);
        }
        else
        {
            finalRate = (P1 + P2 + P3) / 3;
            if (finalRate < 50) {
                HP1 = setHP(HP1 * 0.85);
                EXP1 = setEXP(EXP1 * 1.15);
            }
            else
            {
                HP1 = setHP(HP1 * 0.9);
                EXP1 = setEXP(EXP1 * 1.2);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;
    else {
        HP1 = setHP(HP1);
        EXP1 = setEXP(EXP1);
        HP2 = setHP(HP2);
        EXP2 = setEXP(EXP2);
        int arr[10][10], k = 0, max;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        int i = 0, j = 0, meetValue;
        for (int m = 0; m < 10; m++)
        {
            for (int n = 0; n < 10; n++)
            {
                if (arr[m][n] > E3 * 2)
                    i++;
                else if (arr[m][n] < -E3)
                    j++;
            }
        }
        i = convertNum(i);
        j = convertNum(j);
        meetValue = arr[i][j];
        max = meetValue;

        // top left
        for (int n = 1; ((i - n) >= 0) && ((j - n) >= 0); n++)
        {
            if (arr[i - n][j - n] >= max)
                max = arr[i - n][j - n];
        }
        // top right
        for (int n = 1; ((i - n) >= 0) && ((j + n) <= 9); n++)
        {
            if (arr[i - n][j + n] >= max)
                max = arr[i - n][j + n];
        }
        // bottom left
        for (int n = 1; ((i + n) <= 9) && ((j - n) >= 0); n++)
        {
            if (arr[i + n][j - n] >= max)
                max = arr[i + n][j - n];
        }

        // bottom right
        for (int n = 0; ((i + n) <= 9) && ((j + n) <= 9); n++)
        {
            if (arr[i + n][j + n] >= max)
                max = arr[i + n][j + n];
        }
        max = abs(max);

        if (abs(meetValue) > max) {
            EXP1 = setEXP(EXP1 * 0.88);
            EXP2 = setEXP(EXP2 * 0.88);
            HP1 = setHP(HP1 * 0.9);
            HP2 = setHP(HP2 * 0.9);
        }
        else
        {
            EXP1 = setEXP(EXP1 * 1.12);
            EXP2 = setEXP(EXP2 * 1.12);
            HP1 = setHP(HP1 * 1.1);
            HP2 = setHP(HP2 * 1.1);
        }

        if (max >= abs(meetValue))
            return max;
        else return meetValue;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    bool len = false, alnum = true, special_char = false, has_se = false, leap = false, invalidChar = false;
    string se = string(email).substr(0, std::string(email).find('@'));
    size_t sei, sci, invalidChar_idx;

    // check password length
    if (strlen(s) >= 8 && strlen(s) <= 20)
    {
        len = true;
    }

    // check alnum
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalnum(s[i]) == false)
        {
            alnum = false;
            break;
        }
    }

    // check special characters
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            special_char = true;
            break;
        }
    }

    // check if there is any invalid char
    for (int i = 0; i < strlen(s); i++)
    {
        if (isnot_special_char(s[i]) == true)
        {
            invalidChar = true;
            invalidChar_idx = i;
            break;
        }
    }

    // check if password has se
    if (strstr(s, se.c_str()) != NULL)
    {
        has_se = true;
        sei = strstr(s, se.c_str()) - s;
    }

    // check leap char
    for (int i = 1; i < strlen(s) - 1; i++)
    {
        if ((s[i - 1] == s[i]) && (s[i] == s[i + 1]))
        {
            leap = true;
            sci = i - 1;
            break;
        }
    }

    if (len == true && (alnum == true || special_char == true) && special_char == true && has_se == false && leap == false && invalidChar == false)
        return -10;
    else if (strlen(s) < 8)
        return -1;
    else if (strlen(s) > 20)
        return -2;
    else if (has_se == true)
        return -(300 + static_cast<int>(sei));
    else if (leap == true)
        return -(400 + static_cast<int>(sci));
    else if (special_char == false)
        return -5;
    else return static_cast<int>(invalidChar_idx);
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int result = 0, times = 0;
    int* arr_pwds_times = new int[num_pwds];

    for (int i = 0; i < num_pwds; i++)
    {
        times = 0;
        for (int j = i; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j])==0)
            {
                times++;
            }
            arr_pwds_times[i] = times;
        }
    }

    for (int i = 1; i < num_pwds; i++)
    {
        if (arr_pwds_times[result] < arr_pwds_times[i])
        {
            result = i;
        }
        else if (arr_pwds_times[result] == arr_pwds_times[i])
        {
            if (strlen(arr_pwds[result]) < strlen(arr_pwds[i]))
            {
                result = i;
            }
        }
    }

    delete[] arr_pwds_times;
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////