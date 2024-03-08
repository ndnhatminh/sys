#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
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
//g++ - o main main.cpp study_in_pink1.cpp - I . - std = c++11 && . / main
// Task 1
int Update_exp(int exp) {
    if (exp < 0) {
        return 0;
    }
    else if (exp > 600) {
        return 600;
    }
    else {
        return exp;
    }
}
int abs(int x) {
    if (x > 0) return x;
    else return -x;
}
int Update_hp(int hp) {
    if (hp < 0) {
        return 0;
    }
    else if (hp > 666) {
        return 666;
    }
    else {
        return hp;
    }
}

int Update_money(int m) {
    if (m < 0) {
        return 0;
    }
    else if (m > 3000) {
        return 3000;
    }
    else {
        return m;
    }
}


int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99)
        return -99;

    if (E1 <= 3 && E1 >= 0) {
        if (E1 == 0) {
            EXP2 += 29;
        }
        else if (E1 == 1) {
            EXP2 += 45;
        }
        else if (E1 == 2) {
            EXP2 += 75;
        }
        else {
            EXP2 += 149;
        }
        int D;
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 += D / 200;
            ceil(double(EXP1));
            EXP1 = Update_exp(EXP1);
        }
        else {
            EXP1 -= D/ 100;
            ceil(double(EXP1));
            EXP1 = Update_exp(EXP1);
        }
    }

    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(double(E1) / 4) + 19;
            EXP2 = Update_exp(EXP2);
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil(double(E1) / 9) + 21;
            EXP2 = Update_exp(EXP2);
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(double(E1) / 16) + 17;
            EXP2 = Update_exp(EXP2);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil(double(E1) / 4) + 19;
            EXP2 = Update_exp(EXP2);
            if (EXP2 > 200) {
                EXP2 += ceil(double(E1) / 9) + 21;
                EXP2 = Update_exp(EXP2);
            }
        }
        else {
            EXP2 += ceil(double(E1) / 4)  + 19;
            EXP2 += ceil(double(E1) / 9) + 21;
            EXP2 = Update_exp(EXP2);
            if (EXP2 > 400) {
                EXP2 += ceil(double(E1) / 16) + 17;
                EXP2 = ceil(double(EXP2) * 1.15);
                EXP2 = Update_exp(EXP2);
            }

        }
        EXP1 -= E1;

    }

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    int S1, S2, m;
    double P1, P2, P3;
    //path1
    S1 = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S1) {
        P1 = 1;
    }
    else {
        P1 = ((EXP1 / S1) + 80) / 123;
    }
    m =0.5 * M1;
    //path2
    if (E2 % 2 != 0) {
        while (true) {
            if (HP1 < 200) {
                HP1 = ceil(double(HP1) * 1.3);
                HP1 = Update_hp(HP1);
                
                M1 -= 150;
                if (M1 <= m) {
                    break;
                }
            }
            else {
                HP1 = ceil(double(HP1) * 1.1);
                HP1 = Update_hp(HP1);
                
                M1 -= 70;
                if (M1 <= m) {
                    break;
                }
            }
            if (EXP1 < 400) {
                M1 -= 200;
                if (M1 <= m) {
                    break;
                }
            }
            else {
                M1 -= 120;
                if (M1 <= m) {
                    break;
                }
            }
            EXP1 = ceil(double(EXP1) * 1.13);
            EXP1 = Update_exp(EXP1);
            if (EXP1 < 300) {
                M1 -= 100;
                if (M1 <= m) {
                    break;
                }
            }
            else {
                M1 -= 120;
                EXP1 = ceil(double(EXP1) * 0.9);
                EXP1 = Update_exp(EXP1);
                if (M1 <= m) {
                    break;
                }
            }
           

        }
        HP1 = ceil(double(HP1) * 0.83);
        EXP1 = ceil(double(EXP1) * 1.17);
        HP1 = Update_hp(HP1);
        EXP1 = Update_exp(EXP1);
    }
    else {
        while (true) {
            if (HP1 < 200) {
                HP1 = ceil(double(HP1) * 1.3);
                HP1 = Update_hp(HP1);
                M1 -= 150;
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }
            }
            else {
                HP1 = ceil(double(HP1) * 1.1);
                HP1 = Update_hp(HP1);
                M1 -= 70;
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }
            }
            if (EXP1 < 400) {
                M1 -= 200;
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }
            }
            else {
                M1 -= 120;
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }
            }
            EXP1 = ceil(double(EXP1) * 1.13);
            EXP1 = Update_exp(EXP1);
            if (EXP1 < 300) {
                M1 -= 100;
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }
            }
            else {
                M1 -= 120;
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }
                EXP1 = ceil(double(EXP1) * 0.9);
                EXP1 = Update_exp(EXP1);
            }
            HP1 = ceil(double(HP1) * 0.83);
            EXP1 = ceil(double(EXP1) * 1.17);
            HP1 = Update_hp(HP1);
            EXP1 = Update_exp(EXP1);
        }
        S2 = pow(round(sqrt(EXP1)), 2);
       
        if (EXP1 >= S2) {
            P2 = 1;
        }
        else {
            P2 = ((EXP1 / S2) + 80) / 123;
        }
    }
    //path3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 }, i;
    int Pa;
    if (E2 < 10) { i = E2; }
    else { i = (E2 % 10 + (E2 / 10) % 100) % 10; };
    P3 = (P[i]) ;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(double(EXP1) * 0.75);
        EXP1 = Update_exp(EXP1);
    }
    else {
        Pa = (P1 + P2 + P3) / 3;
        if (Pa < 0.5) {
            HP1 = ceil(double(HP1) * 0.85);
            EXP1 = ceil(double(EXP1) * 1.15);
            HP1 = Update_hp(HP1);
            EXP1 = Update_exp(EXP1);
        }
        else {
            HP1 = ceil(double(HP1) * 0.9);
            EXP1 = ceil(double(EXP1) * 1.20);
            HP1 = Update_hp(HP1);
            EXP1 = Update_exp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    int i;
    int TaxiMap[10][10] = { 0 };
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            TaxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);

        }
        int neg = 0, pos = 0;
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < 10; i++) {
                if (TaxiMap[i][j] > (E3 * 2)) { pos++; }
                if ((TaxiMap[i][j]) < 0 - E3) { neg++; }
            }
        }

        while ((neg / 10) != 0)
        {
            neg = (neg % 10 + neg / 10);
        }
        while ((pos / 10) != 0)
        {
            pos = (pos % 10 + pos / 10);
        }
        int max;
        max = TaxiMap[0][0];
        i = pos;
        j = neg;
        while (true)
        {
            i--;
            j--;
            if (i < 0 || j < 0) break;
            if (max < TaxiMap[i][j]) max = TaxiMap[i][j];
        }



        while (true)
        {
            i++;
            j--;
            if (i > 9 || j < 0) break;
            if (max < TaxiMap[i][j]) max = TaxiMap[i][j];
        }



        while (true)
        {
            i--;
            j++;
            if (i < 0 || j > 9) break;
            if (max < TaxiMap[i][j]) max = TaxiMap[i][j];
        }


        while (true)
        {
            i++;
            j++;
            if (i > 9 || j > 9) break;
            if (max < TaxiMap[i][j]) max = TaxiMap[i][j];
        }


        if (abs(TaxiMap[pos][neg]) > abs(max)) {
            EXP1 = ceil(EXP1 - EXP1 * 0.12);
            EXP2 = ceil(EXP2 - EXP2 * 0.12);
            HP1 = ceil(HP1 - HP1 * 0.1);
            HP2 = ceil(HP2 - HP2 * 0.1);
            HP1 = Update_hp(HP1);
            EXP1 = Update_exp(EXP1);
            HP2 = Update_hp(HP2);
            EXP2 = Update_exp(EXP2);
            max = TaxiMap[pos][neg];
        }
        else {
            EXP1 = ceil(EXP1 + EXP1 * 0.12);
            EXP2 = ceil(EXP2 + EXP2 * 0.12);
            HP1 = ceil(HP1 + HP1 * 0.1);
            HP2 = ceil(HP2 + HP2 * 0.1);
            HP1 = Update_hp(HP1);
            EXP1 = Update_exp(EXP1);
            HP2 = Update_hp(HP2);
            EXP2 = Update_exp(EXP2);
        }
        return max;
    }
        return -1;
    }


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) {
        return -1;
    } else if (strlen(s) > 20) {
        return -2;
    }

    
    size_t se_index = strchr(email, '@') - email;
char se[se_index + 1];
strncpy(se, email, se_index);
se[se_index] = '\0';

const char* se_position_in_s = strstr(s, se);
if (se_position_in_s != NULL) {
    return -(300 + (se_position_in_s - s));
}

   
    size_t s_len = strlen(s);
    for (size_t i = 0; i < s_len - 2; ++i) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i);
        }
    }

   
    bool has_special_char = false;
    for (const char *p = s; *p != '\0'; ++p) {
        char c = *p;
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            has_special_char = true;
            break;
        }
    }
    if (!has_special_char) {
        return -5;
    }

    for (size_t i = 0; i < s_len; ++i) {
        char c = s[i];
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            return i;
        }
    }

    return -10;  



    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    unordered_map<string, int> passwordCount;
    for (int i = 0; i < num_pwds; ++i) {
        string pwd = arr_pwds[i];
        passwordCount[pwd]++;
    }

    
    int maxCount = 0;
    string mostFrequentPassword;
    for (const auto& pair : passwordCount) {
        if (pair.second > maxCount || (pair.second == maxCount && pair.first.length() > mostFrequentPassword.length())) {
            maxCount = pair.second;
            mostFrequentPassword = pair.first;
        }
    }

    
    for (int i = 0; i < num_pwds; ++i) {
        if (string(arr_pwds[i]) == mostFrequentPassword) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////