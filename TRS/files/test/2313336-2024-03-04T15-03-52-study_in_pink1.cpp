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

int check_HP(int HP) {
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
    return HP;
}
int check_EXP(int EXP) {
    if (EXP > 600) EXP = 600;
    if (EXP < 0) EXP = 0;
    return EXP;
}
int check_M(int M) {
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;
    return M;
}
int check_E(int E) {
    int a;
    if (E > 99 || E < 0) a = -99;
    return a;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    int D;
    if (check_E(E1) == -99) return -99;
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    if (E1 >= 0 && E1 <= 3) {
        switch (E1) {
        case 0:
            EXP2 = EXP2 + 29;
            break;
        case 1:
            EXP2 = EXP2 + 45;
            break;
        case 2:
            EXP2 = EXP2 + 75;
            break;
        case 3:
            EXP2 = EXP2 + 149;
            break;
        }
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 = (EXP1 + D / 200.0) + 0.999; else EXP1 = (EXP1 - D / 100.0) + 0.999;
    }
    else if (E1 >= 4 && E1 <= 19)
    {
        EXP2 = (EXP2 + E1 / 4.0 + 19) + 0.999;
        EXP1 = EXP1 - E1;
    }
    else if (E1 >= 20 && E1 <= 49)
    {
        EXP2 = (EXP2 + E1 / 9.0 + 21) + 0.999;
        EXP1 = EXP1 - E1;
    }
    else if (E1 >= 50 && E1 <= 65)
    {
        EXP2 = (EXP2 + E1 / 16.0 + 17) + 0.999;
        EXP1 = EXP1 - E1;
    }
    else if (E1 >= 66 && E1 <= 79)
    {
        EXP2 = (EXP2 + E1 / 4.0 + 19) + 0.999;
        if (EXP2 <= 200) EXP1 = EXP1 - E1;
        else {
            EXP2 = (EXP2 + E1 / 9.0 + 21) + 0.999;
            EXP1 = EXP1 - E1;
        }
    }
    else if (E1 >= 80 && E1 <= 99)
    {

        EXP2 = (EXP2 + E1 / 4.0 + 19) + 0.999;
        EXP2 = (EXP2 + E1 / 9.0 + 21) + 0.999;
        if (EXP2 <= 400) EXP1 = EXP1 - E1;
        else {
            EXP2 = (EXP2 + E1 / 16.0 + 17) + 0.999;
            EXP2 = (EXP2 * 1.15) + 0.999;
            EXP1 = EXP1 - E1;
        }
    }
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    int S, I;
    float TB, P_TB, P1, P2, P3;
    if (check_E(E2) == -99) return -99;
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    M1 = check_M(M1);
    S = pow(round(sqrt(EXP1)), 2);

    if (EXP1 >= S) P1 = 1; else P1 = (EXP1 * 1.0 / S * 1.0 + 80) / 123.0;
    TB = M1 / 2.0;

    if (M1 == 0) {
        HP1 = check_HP((HP1 * 0.83) + 0.999);
        EXP1 = check_EXP((EXP1 * 1.17) + 0.999);
    }
    else {
        if (E2 % 2 != 0) {
            while (M1 >= TB) {
                if (M1 >= TB) {
                    if (HP1 < 200) {
                        HP1 = check_HP((HP1 * 1.3) + 0.999);
                        M1 = M1 - 150;
                    }
                    else
                    {
                        HP1 = check_HP((HP1 * 1.1) + 0.999);
                        M1 = M1 - 70;
                    }
                }
                if (M1 >= TB) {
                    if (EXP1 < 400) {
                        EXP1 = check_EXP((EXP1 * 1.13) + 0.999);
                        M1 = M1 - 200;
                    }
                    else
                    {
                        EXP1 = check_EXP((EXP1 * 1.13) + 0.999);
                        M1 = M1 - 120;
                    }
                }
                if (M1 >= TB) {
                    if (EXP1 < 300) {
                        EXP1 = check_EXP((EXP1 * 0.9) + 0.999);
                        M1 = M1 - 100;
                    }
                    else
                    {
                        EXP1 = check_EXP((EXP1 * 0.9) + 0.999);
                        M1 = M1 - 120;;
                    }
                }

            }
            EXP1 = check_EXP((EXP1 * 1.17) + 0.999);
            HP1 = check_HP((HP1 * 0.83) + 0.999);
        }
        if (E2 % 2 == 0) {
            if (M1 > 0) {
                if (HP1 < 200) {
                    HP1 = check_HP((HP1 * 1.3) + 0.999);
                    M1 = check_M(M1 - 150);
                }
                else
                {
                    HP1 = check_HP((HP1 * 1.1) + 0.999);
                    M1 = check_M(M1 - 70);
                }
            }
            if (M1 > 0) {
                if (EXP1 < 400) {
                    EXP1 = check_EXP((EXP1 * 1.13) + 0.999);
                    M1 = check_M(M1 - 200);
                }
                else
                {
                    EXP1 = check_EXP((EXP1 * 1.13) + 0.999);
                    M1 = check_M(M1 - 120);
                }
            }
            if (M1 > 0) {
                if (EXP1 < 300) {
                    EXP1 = check_EXP((EXP1 * 0.9) + 0.999);
                    M1 = check_M(M1 - 100);
                }
                else
                {
                    EXP1 = check_EXP((EXP1 * 0.9) + 0.999);
                    M1 = check_M(M1 - 120);
                }
            }
            EXP1 = check_EXP((EXP1 * 1.17) + 0.999);
            HP1 = check_HP((HP1 * 0.83) + 0.999);
        }
    }
    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) P2 = 1; else P2 = (EXP1 * 1.0 / S * 1.0 + 80.0) / 123.0;
    if (E2 > 10) I = (E2 / 10 + E2 % 10) % 10;
    else I = E2;
    switch (I) {
    case 0:
        P3 = 0.32;
        break;
    case 1:
        P3 = 0.47;
        break;
    case 2:
        P3 = 0.28;
        break;
    case 3:
        P3 = 0.79;
        break;
    case 4:
        P3 = 1;
        break;
    case 5:
        P3 = 0.5;
        break;
    case 6:
        P3 = 0.22;
        break;
    case 7:
        P3 = 0.83;
        break;
    case 8:
        P3 = 0.64;
        break;
    case 9:
        P3 = 0.11;
        break;
    case 10:
        P3 = 0.32;
    }
    P_TB = (P1 + P2 + P3) / 3.0;
    if (P_TB == 0) return 0;
    if (P_TB == 1) EXP1 = (EXP1 * 0.75) + 0.999;
    if (P_TB < 0.5 && P_TB != 0) {
        HP1 = check_HP((HP1 * 0.85) + 0.999);
        EXP1 = check_EXP((EXP1 * 1.15) + 0.999);
    }
    if (P_TB >= 0.5 && P_TB != 1) {
        HP1 = check_HP((HP1 * 0.9) + 0.999);
        EXP1 = check_EXP((EXP1 * 1.2) + 0.999);
    }
    M1 = check_M(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int i, j, i_VT = 0, j_VT = 0, S;
    if (check_E(E3) == -99) return -99;
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    HP2 = check_HP(HP2);
    EXP2 = check_EXP(EXP2);
    int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] < -E3) j_VT++;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > E3 * 2) i_VT++;
        }
    }
    if (i_VT > 9) i_VT = (i_VT / 10 + i_VT % 10);
    if (i_VT > 9) i_VT = (i_VT / 10 + i_VT % 10) % 10;
    if (j_VT > 9) j_VT = (j_VT / 10 + j_VT % 10);
    if (i_VT > 9) i_VT = (i_VT / 10 + i_VT % 10) % 10;
    S = arr[i_VT][j_VT];
    i = i_VT;
    j = j_VT;
    while (i >= 0 && j >= 0) {

        if (S < arr[i][j]) S = arr[i][j];
        i--;
        j--;
    }
    i = i_VT;
    j = j_VT;
    while (i >= 0 && j <= 9) {
        if (S < arr[i][j]) S = arr[i][j];
        i--;
        j++;
    }
    i = i_VT;
    j = j_VT;
    while (i <= 9 && j >= 0) {
        if (S < arr[i][j]) S = arr[i][j];
        i++;
        j--;
    }
    i = i_VT;
    j = j_VT;
    while (i <= 9 && j <= 9) {
        if (S < arr[i][j]) S = arr[i][j];
        i++;
        j++;
    }

    if (abs(arr[i_VT][j_VT]) > S) {
        HP1 = check_HP(HP1 * 0.9 + 0.999);
        EXP1 = check_EXP(EXP1 * 0.88 + 0.999);
        HP2 = check_HP(HP2 * 0.9 + 0.999);
        EXP2 = check_EXP(EXP2 * 0.88 + 0.999);
        return arr[i_VT][j_VT];
    }
    else {
        HP1 = check_HP(HP1 * 1.1 + 0.999);
        EXP1 = check_EXP(EXP1 * 1.12 + 0.999);
        HP2 = check_HP(HP2 * 1.1 + 0.999);
        EXP2 = check_EXP(EXP2 * 1.12 + 0.999);
        return S;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string s1 = s, s2 = email, se;
    int sei;
    const char* at_VT = strchr(email, '@');
    if (at_VT == nullptr) {
        return -1;
    }
    int len = strlen(s);
    if (len < 8) {
        return -1;
    }
    if (len > 20) {
        return -2;
    }
    if (at_VT != nullptr) {
        se = s2.substr(0, s2.find("@"));
        size_t s3 = s1.find(se);
        if (s3 != string::npos) {
            sei = s1.find(se);
            return -(300 + sei);
        }
    }
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    bool kitu_DB = false;
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            kitu_DB = true;
            break;
        }
    }
    if (!kitu_DB) {
        return -5;
    }
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }
        if (i < len - 2 && c == s[i + 1] && c == s[i + 2]) {
            return -(400 + i);
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_Re = 0;
    int max_Le = 0;
    int first = -1;
    for (int i = 0; i < num_pwds; ++i) {
        const char* current_Pwd = arr_pwds[i];
        int current_Re = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(current_Pwd, arr_pwds[j]) == 0) {
                current_Re++;
            }
        }
        if (current_Re > max_Re || (current_Re == max_Re && strlen(current_Pwd) > max_Le)) {
            max_Re = current_Re;
            max_Le = strlen(current_Pwd);
            first = i;
        }
    }
    return first;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////