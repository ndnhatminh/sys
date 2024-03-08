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
    float D;
    if (!(e1 >= 0 && e1 <= 99)) return -99;
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;
    switch (e1) {
    case 0:
        exp2 = exp2 + 29;
        D = e1 * 3 + exp1 * 7;
        if (int(D) % 2 == 1) {
            exp1 = ceil(exp1 - (D / 100));
        }
        else {
            exp1 = ceil(exp1 + (D / 200));
        }
        break;
    case 1:
        exp2 = exp2 + 45;
        D = e1 * 3 + exp1 * 7;
        if (int(D) % 2 == 1) {
            exp1 = ceil(exp1 - (D / 100));
        }
        else {
            exp1 = ceil(exp1 + (D / 200));
        }
        break;
    case 2:
        exp2 = exp2 + 75;
        D = e1 * 3 + exp1 * 7;
        if (int(D) % 2 == 1) {
            exp1 = ceil(exp1 - (D / 100));
        }
        else {
            exp1 = ceil(exp1 + (D / 200));
        }
        break;
    case 3:
        exp2 = exp2 + 29 + 45 + 75;
        D = e1 * 3 + exp1 * 7;
        if (int(D) % 2 == 1) {
            exp1 = ceil(exp1 - (D / 100));
        }
        else {
            exp1 = ceil(exp1 + (D / 200));
        }
        break;
    default:
        if (4 <= e1 && e1 <= 19) {
            exp2 = exp2 + ceil((e1 * 1.0) / 4) + 19;
        }
        else if (20 <= e1 && e1 <= 49) {
            exp2 = exp2 + ceil((e1 * 1.0) / 9) + 21;
        }
        else if (50 <= e1 && e1 <= 65) {
            exp2 = exp2 + ceil((e1 * 1.0) / 16) + 17;
        }
        else if (66 <= e1 && e1 <= 79) {
            exp2 = exp2 + ceil((e1 * 1.0) / 4) + 19;
            if (exp2 > 200) {
                exp2 = exp2 + ceil((e1 * 1.0) / 9) + 21;
            }
        }
        else {
            exp2 = exp2 + ceil((e1 * 1.0) / 4) + 19 + ceil((e1 * 1.0) / 9) + 21;
            if (exp2 > 400) {
                exp2 = ceil(1.15 * (exp2 + ceil((e1 * 1.0) / 16) + 17));
            }
        }
        exp1 = exp1 - e1;
    }
    if (exp1 < 0) exp1 = 0;
    if (exp2 < 0) exp2 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 > 600) exp2 = 600;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (!(E2 >= 0 && E2 <= 99)) return -99;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;

    //1 con duong 1
    double P1, P2, P3;
    int n1 = round(sqrt(EXP1));
    long long s1 = n1 * n1;
    if (EXP1 >= s1) {
        P1 = 1;
    }
    else {
        P1 = ((EXP1 * 1.00 / s1) + 80) / 123;
    }

    //2 con duong 2
    float m1 = M1 * 0.5;
    if (E2 % 2 == 1) {
        while (1)
        {
            if (M1 == 0) break;
            // S? ki?n 1
            if (M1 >= m1)
            {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 + 0.3 * HP1);
                    M1 -= 150;
                }
                else {
                    HP1 = ceil(HP1 + 0.1 * HP1);
                    M1 -= 70;
                }
                if (HP1 > 666) HP1 = 666;
            }

            else break;

            // S? ki?n 2
            if (M1 >= m1)
            {
                if (EXP1 < 400)
                {
                    M1 -= 200;
                }
                else
                {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 + EXP1 * 0.13);
                if (EXP1 > 600) EXP1 = 600;

            }
            else break;

            // S? ki?n 3
            if (M1 >= m1)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 - EXP1 * 0.1);

            }
            else break;

        }

        HP1 = ceil(HP1 - HP1 * 0.17);
        EXP1 = ceil(EXP1 + EXP1 * 0.17);

        if (EXP1 > 600) EXP1 = 600;
        if (M1 < 0) M1 = 0;
    }

    else
    {
        // S? ki?n 1
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 0.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1 + HP1 * 0.1);
                M1 -= 70;
            }
            if (HP1 > 666) HP1 = 666;
        }

        // S? ki?n 2
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 + EXP1 * 0.13);
            if (EXP1 > 600) EXP1 = 600;
        }

        // S? ki?n 3
        if (M1 > 0) {
            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 - EXP1 * 0.1);

        }

        HP1 = ceil(HP1 - HP1 * 0.17);
        EXP1 = ceil(EXP1 + EXP1 * 0.17);

        if (EXP1 > 600) EXP1 = 600;
        if (M1 < 0) M1 = 0;
    }
    int n2 = round(sqrt(EXP1));
    long long s2 = n2 * n2;
    if (EXP1 >= s2) {
        P2 = 1;
    }
    else {
        P2 = ((EXP1 * 1.00 / s2) + 80) / 123;
    }


    //3 con duong 3
    int i;
    float P;
    int arr[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10) {
        P3 = (arr[E2] * 1.0) / 100;
    }
    else {
        i = (E2 % 10 + E2 / 10) % 10;
        P3 = (arr[i] * 1.0) / 100;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 - EXP1 * 0.25);
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = ceil(HP1 - HP1 * 0.15);
            EXP1 = ceil(EXP1 + EXP1 * 0.15);
        }
        else {
            HP1 = ceil(HP1 - HP1 * 0.1);
            EXP1 = ceil(EXP1 + EXP1 * 0.2);
        }
    }

    if (EXP1 > 600) EXP1 = 600;


    return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (!(E3 >= 0 && E3 <= 99)) return -99;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    int arr[10][10];
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > 2 * E3) a++;
            if (arr[i][j] < -E3) b++;
        }
    }
    while (a >= 10) {
        a = a / 10 + a % 10;
    }
    while (b >= 10) {
        b = b / 10 + b % 10;
    }
    int t = arr[a][b];
    int i1 = a; int j1 = b;
    int i2 = a; int j2 = b;
    int i3 = a; int j3 = b;
    int i4 = a; int j4 = b;

    while (i1 != 0 && j1 != 0) {
        i1--; j1--;
        if (arr[i1][j1] > t) t = arr[i1][j1];
    }
    while (i2 != 9 && j2 != 9) {
        i2++; j2++;
        if (arr[i2][j2] > t) t = arr[i2][j2];
    }
    while (1) {
        if (i3 == 9 || j3 == 0) break;
        i3++; j3--;
        if (arr[i3][j3] > t) t = arr[i3][j3];
    }
    while (1) {
        if (i4 == 0 || j4 == 9) break;
        i4--; j4++;
        if (arr[i4][j4] > t) t = arr[i4][j4];
    }
    if (abs(arr[a][b]) > t) {
        EXP1 = ceil(EXP1 - 0.12 * EXP1);
        EXP2 = ceil(EXP2 - 0.12 * EXP2);
        HP1 = ceil(HP1 - 0.1 * HP1);
        HP2 = ceil(HP2 - 0.1 * HP2);
    }
    else {
        EXP1 += ceil(0.12 * EXP1);
        EXP2 += ceil(0.12 * EXP2);
        HP1 += ceil(0.1 * HP1);
        HP2 += ceil(0.1 * HP2);
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 > 600) EXP2 = 600;
    if (HP1 > 666) HP1 = 666;
    if (HP2 > 666) HP2 = 666;
    if (abs(arr[a][b]) > t)
    {
        return arr[a][b];
    }
    else
    {
        return t;
    }

}



// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
        // tim se
    string str = s;
    string mail = email;
    string se = mail;
    int a = -se.find('@') + se.length();
    se.erase(se.find('@'), a);
    //yeu cau hop le
    auto found = str.find(se);
    if (str.length() < 8) return -1;
    if (str.length() > 20) return -2;
    if (found != string::npos) return -(300 + found);
    for (int i = 0; i < str.length() - 2; i++)
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2]) return -(400 + i);
    }
    int g = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '@' || str[i] == '#' || str[i] == '%' || str[i] == '$' || str[i] == '!') g++;
    }
    if (g == 0) return -5;
    for (int i = 0; i < str.length(); i++)
    {
        int a = str[i];
        if (!((a >= 48 && a <= 57) || a == 33 || a == 35 || a == 37 || a == 36 || (a >= 64 && a <= 90) || (a >= 97 && a <= 122)))
            return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        arr[i] = arr_pwds[i];
    }
    int arr1[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        arr1[i] = 1;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (i != j)
            {
                if (arr[i] == arr[j])
                {
                    arr1[i]++;
                }
            }
        }
    }
    int a = arr1[0];
    for (int i = 1; i < num_pwds; i++)
    {
        if (a < arr1[i])
        {
            a = arr1[i];
        }
    }
    int arr2[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        arr2[i] = 0;
    }
    int c = 0;
    for (int i = 0; i < num_pwds; i++)
    {

        if (arr1[i] == a)
        {

            arr2[c] = i;
            c++;
        }
    }

    int b = arr[arr2[0]].length();
    for (int i = 1; i < num_pwds; i++)
    {
        if (arr2[i] != 0)
        {
            if (b < arr[arr2[i]].length())
                b = arr[arr2[i]].length();
        }
    }
    if (arr2[0] == 0)
    {
        if (arr[arr2[0]].length() == b)
            return 0;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        if (arr2[i] != 0)
        {
            if (arr[arr2[i]].length() == b)
                return arr2[i];
        }
    }
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////