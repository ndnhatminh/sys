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

int check1(int exp) {
    if (exp < 0) {
        exp = 0;
    }
    else if (exp > 600) {
        exp = 600;
    }
    return exp;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

    exp1 = check1(exp1);
    exp2 = check1(exp2);
    

    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 = check1(exp2 + 29);
        }
        else if (e1 == 1) {
            exp2 = check1(exp2 + 45);
        }
        else if (e1 == 2) {
            exp2 = check1(exp2 + 75);
        }
        else if (e1 == 3) {
            exp2 = check1(exp2 + 29 + 75 + 45);
        }
        int D = 3 * e1 + 7 * exp1;
        if (D % 2 == 0) {
            exp1 = check1(ceil(exp1 + D / 200.0));
        }
        else {
            exp1 = check1(ceil(exp1 - D / 100.0));
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) {
            exp2 = check1(ceil(exp2 + e1 / 4.0 + 19));
        }
        else if (e1 <= 49) {
            exp2 = check1(ceil(exp2 + e1 / 9.0 + 21));
        }
        else if (e1 <= 65) {
            exp2 = check1(ceil(exp2 + e1 / 16.0 + 17));
        }
        else if (e1 <= 79) {
            exp2 = check1(ceil(exp2 + e1 / 4.0 + 19));
            if (exp2 > 200) {
                exp2 = check1(ceil(exp2 + e1 / 9.0 + 21));
            }
        }
        else {
            exp2 = check1(ceil(exp2 + e1 / 4.0 + 19));
            exp2 = check1(ceil(exp2 + e1 / 9.0 + 21));
            if (exp2 > 400) {
                exp2 = check1(ceil(exp2 + e1 / 16.0 + 17));
                exp2 = check1(ceil(exp2 + 0.15 * exp2));
            }
        }
        exp1 = check1(exp1 - e1);
    }
    else {
        return -99;
    }

    return exp1 + exp2;
}


int check2(int HP) {
    if (HP < 0) {
        HP = 0;
    }
    else if (HP > 666) {
        HP = 666;
    }
    return HP;
}

int check3(int M) {
    if (M < 0) {
        M = 0;
    }
    else if (M > 3000) {
        M = 3000;
    }
    return M;
}

bool check4(double Mi, int Mf) {
    if (Mf > Mi) {
        return true;
    }
    else {
        return false;
    }
}

double findP(int EXP) {
    double P;
    int s1 = pow(ceil(sqrt(EXP)), 2);
    int s2 = pow(floor(sqrt(EXP)), 2);
    if (abs(EXP - s1) >= abs(EXP - s2)) {
        if (EXP >= s2) {
            return 1;
        }
        else {
            P = (EXP / static_cast<double>(s2) + 80) / 123.0;
            return P;
        }
    }
    else {
        if (EXP >= s1) {
            return 1;
        }
        else {
            P = (EXP / static_cast<double>(s1) + 80) / 123.0;
            return P;
        }
    }
}

bool two_digit(int k) {
    if (k / 10 == 0) {
        return false;
    }
    else {
        return true;
    }
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function

    double P_avg;

    HP1 = check2(HP1);
    EXP1 = check1(EXP1);
    M1 = check3(M1);


    double P1 = findP(EXP1);

    if (E2 < 0 || E2 > 99) {
        return -99;
    }

    double Mi = (0.5 * M1);
    int M_paid = 0;
    if (E2 % 2 != 0) {
        while (1) {
            if (HP1 < 200) {
                HP1 = check2(ceil((double)((float)(1.3 * HP1))));
                M_paid += 150;
                M1 = check3(M1 - 150);
            }
            else {
                HP1 = check2(ceil((double)((float)(1.1 * HP1))));
                M_paid += 70;
                M1 = check3(M1 - 70);
            }
            if (check4(Mi, M_paid)) {
                HP1 = check2(ceil((double)((float)(0.83 * HP1))));
                EXP1 = check1(ceil((double)((float)(1.17 * EXP1))));
                break;
            }

            if (EXP1 < 400) {
                M_paid += 200;
                M1 = check3(M1 - 200);
                EXP1 = check1(ceil((double)((float)(1.13 * EXP1))));
            }
            else {
                M_paid += 120;
                M1 = check3(M1 - 120);
                EXP1 = check1(ceil((double)((float)(1.13 * EXP1))));
            }
            if (check4(Mi, M_paid)) {
                HP1 = check2(ceil((double)((float)(0.83 * HP1))));
                EXP1 = check1(ceil((double)((float)(1.17 * EXP1))));
                break;
            }

            if (EXP1 < 300) {
                M_paid += 100;
                M1 = check3(M1 - 100);
                EXP1 = check1(ceil((double)((float)(0.9 * EXP1))));
            }
            else {
                M_paid += 120;
                M1 = check3(M1 - 120);
                EXP1 = check1(ceil((double)((float)(0.9 * EXP1))));
            }
            if (check4(Mi, M_paid)) {
                HP1 = check2(ceil((double)((float)(0.83 * HP1))));
                EXP1 = check1(ceil((double)((float)(1.17 * EXP1))));
                break;
            }
        }

    }
    else {
        int i = 1;
        while (i && M1 != 0) {
            if (HP1 < 200) {
                HP1 = check2(ceil((double)((float)(1.3 * HP1))));
                M_paid += 150;
                M1 = check3(M1 - 150);
            }
            else {
                HP1 = check2(ceil((double)((float)(1.1 * HP1))));
                M_paid += 70;
                M1 = check3(M1 - 70);
            }
            if (M1 == 0) {
                break;
            }

            if (EXP1 < 400) {
                M_paid += 200;
                M1 = check3(M1 - 200);
                EXP1 = check1(ceil((double)((float)(1.13 * EXP1))));
            }
            else {
                M_paid += 120;
                M1 = check3(M1 - 120);
                EXP1 = check1(ceil((double)((float)(1.13 * EXP1))));
            }
            if (M1 == 0) {
                break;
            }

            if (EXP1 < 300) {
                M_paid += 100;
                M1 = check3(M1 - 100);
                EXP1 = check1(ceil((double)((float)(0.9 * EXP1))));
            }
            else {
                M_paid += 120;
                M1 = check3(M1 - 120);
                EXP1 = check1(ceil((double)((float)(0.9 * EXP1))));
            }

            if (M1 == 0) {
                break;
            }
            i--;
        }
        HP1 = check2(ceil((double)((float)(0.83 * HP1))));
        EXP1 = check1(ceil((double)((float)(1.17 * EXP1))));
    }

    double P2 = findP(EXP1);

    double P3;
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i = E2;

    if (two_digit(i)) {
        i = i / 10 + i % 10;
        if (two_digit(i)) {
            i = i % 10;
            P3 = P[i] / 100.0;
        }
        else {
            P3 = P[i] / 100.0;
        }
    }
    else {
        P3 = P[i] / 100.0;
    }


    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = check1(ceil((double)((float)(EXP1 * 0.75))));
    }
    else {
        P_avg = (P1 + P2 + P3) / 3.0;

        if (P_avg < 0.5) {
            HP1 = check2(ceil((double)((float)(0.85 * HP1))));
            EXP1 = check1(ceil((double)((float)(1.15 * EXP1))));
        }
        else {
            HP1 = check2(ceil((double)((float)(0.9 * HP1))));
            EXP1 = check1(ceil((double)((float)(1.2 * EXP1))));
        }
    }


    return EXP1 + HP1 + M1;
}


int process_2digit(int k) {
    while (two_digit(k)) {
        k = k % 10 + k / 10;
    }
    return k;
}

int FindMax(int m, int n, int arr[][10]) {
    int p = m;
    int q = n;
    int Max1 = arr[m][n], Max2 = arr[m][n], Max3 = arr[m][n], Max4 = arr[m][n];

    while (p >= 0 && p <= 9 && q >= 0 && q <= 9) {
        if (Max1 <= arr[p][q]) {
            Max1 = arr[p][q];
        }
        q--;
        p--;
    }

    p = m;
    q = n;
    while (p >= 0 && p <= 9 && q >= 0 && q <= 9) {
        if (Max2 <= arr[p][q]) {
            Max2 = arr[p][q];
        }
        q--;
        p++;
    }


    p = m;
    q = n;
    while (p >= 0 && p <= 9 && q >= 0 && q <= 9) {
        if (Max3 <= arr[p][q]) {
            Max3 = arr[p][q];
        }
        q++;
        p--;
    }


    p = m;
    q = n;
    while (p >= 0 && p <= 9 && q >= 0 && q <= 9) {
        if (Max4 <= arr[p][q]) {
            Max4 = arr[p][q];
        }
        q++;
        p++;
    }
    int M1 = max(Max1, Max2);
    int M2 = max(Max3, Max4);

    return max(M1, M2);
}



// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int score1, score2;
    int m = 0, n = 0;
    int arr[10][10];

    if (E3 < 0 || E3>99) {
        return -99;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > 2 * E3) {
                m++;
            }
            else if (arr[i][j] < -E3) {
                n++;
            }
        }
    }

    m = process_2digit(m);
    n = process_2digit(n);

    score1 = arr[m][n];
    score2 = FindMax(m, n, arr);

    if (abs(score1) > score2) {
        HP1 = check2(ceil((double)((float)(0.9 * HP1))));
        EXP1 = check1(ceil((double)((float)(0.88 * EXP1))));
        HP2 = check2(ceil((double)((float)(0.9 * HP2))));
        EXP2 = check1(ceil((double)((float)(0.88 * EXP2))));
    }
    else {
        HP1 = check2(ceil((double)((float)(1.1 * HP1))));
        EXP1 = check1(ceil((double)((float)(1.12 * EXP1))));
        HP2 = check2(ceil((double)((float)(1.1 * HP2))));
        EXP2 = check1(ceil((double)((float)(1.12 * EXP2))));
    }

    if (abs(score1) > score2) {
        return score1;
    }
    else {
        return score2;
    }

    return -1;

}


int found_substring_1(string s, string email) {
    int check = 0;
    email.erase(email.find("@"));
    if (s.find(email) != string::npos) {
        check = 1;
    }
    return check;
}

int found_substring_2(string s, string email) {
    int save = 0;
    email.erase(email.find("@"));
    if (s.find(email) != string::npos) {
        save = s.find(email);
    }
    return save;
}


int check_consecutive_1(string s) {
    int check = 0;
    for (int i = 0; i <= s.length() - 3; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            check = 1;
            break;
        }
        else {
            continue;
        }
    }
    return check;
}

int check_consecutive_2(string s) {
    int save;
    for (int i = 0; i <= s.length() - 3; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            save = i;
            break;
        }
        else {
            continue;
        }
    }
    return save;
}

int check_special_character(string s) {
    int check = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%') {
            check = 1;
            break;
        }
        else {
            continue;
        }
    }
    return check;
}

int check_another_word_1(string s) {
    int check = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!isalnum(s[i])) {
            if (s[i] != '!' && s[i] != '@' && s[i] != '#' && s[i] != '$' && s[i] != '%') {
                check = 1;
                break;
            }
        }
    }
    return check;
}

int check_another_word_2(string s) {
    int save;
    for (int i = 0; i < s.size(); i++) {
        if (!isalnum(s[i])) {
            if (s[i] != '!' && s[i] != '@' && s[i] != '#' && s[i] != '$' && s[i] != '%') {
                save = i;
                break;
            }
        }
    }
    return save;
}



// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string s1 = s;
    string s2 = email;
    if (s1.length() < 8) {
        return -1;
    }
    else if (s1.length() > 20) {
        return -2;
    }
    else if (found_substring_1(s1, email)) {
        return -(300 + found_substring_2(s1, email));
    }
    else if (check_consecutive_1(s1)) {
        return -(400 + check_consecutive_2(s1));
    }
    else if (!check_special_character(s1)) {
        return -5;
    }
    else if (check_another_word_1(s1)) {
        return check_another_word_2(s1);
    }
    else {
        return -10;
    }

    return -99;
}

bool Duyet(string arr_pwds[], int i) {
    bool check = true;
    for (int j = 0; j < i; j++) {
        if (arr_pwds[i] == arr_pwds[j]) {
            check = false;
            break;
        }
        else {
            continue;
        }
    }
    return check;
}

int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string s[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        s[i] = arr_pwds[i];
    }


    int k = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (Duyet(s, i)) {
            k++;
        }
    }

    int arr[k];
    int i = 0;
    int j = 0;

    while (j < k) {
        if (Duyet(s, i)) {
            arr[j] = i;
            j++;
        }
        i++;
    }

    int cnt[k];
    for (int j = 0; j < k; j++) {
        cnt[j] = 1;
        for (int i = arr[j] + 1; i < num_pwds; i++) {
            if (s[arr[j]] == s[i]) {
                cnt[j]++;
            }
        }
    }

    int Most_occur = cnt[0];
    for (int j = 0; j < k; j++) {
        if (Most_occur < cnt[j]) {
            Most_occur = cnt[j];
        }
    }

    int store[num_pwds] = { 0 };
    for (int j = 0; j < k; j++) {
        store[arr[j]] = 1;
        for (int i = arr[j] + 1; i < num_pwds; i++) {
            if (s[arr[j]] == s[i]) {
                store[arr[j]]++;
            }
        }
    }

    for (int j = 0; j < num_pwds; j++) {
        if (store[j] != Most_occur) {
            store[j] = 0;
        }
    }

    int Longest = 0;
    int save;


    for (int i = 0; i < k; i++) {
        if (store[arr[i]] == Most_occur) {
            if (Longest < s[arr[i]].size()) {
                Longest = s[arr[i]].size();
                save = arr[i];
            }
        }
    }

    return save;
    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////