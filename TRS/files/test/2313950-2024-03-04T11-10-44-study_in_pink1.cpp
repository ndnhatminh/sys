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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (exp1 < 0){
        exp1 = 0;
    }
    if (exp1 > 600){
        exp1 = 600;
    }
    if (exp2 < 0){
        exp2 = 0;
    }
    if (exp2 > 600){
        exp2 = 600;
    }
    if (0 <= e1 && e1 <= 99) {
        if (0 <= e1 && e1 <= 3){
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
                    exp2 += (29 + 45 + 75);
                break;
            }

            if (exp2 > 600){
                exp2 = 600;
            }
        
            int d = e1 * 3 + exp1 * 7;
            if (d % 2 == 1){
                exp1 = exp1 - d/100.0 + 0.9999;
                if (exp1 < 0){
                    exp1 = 0;
                }
            }
            else {
                exp1 += d / 200.0 + 0.9999;
                if (exp1 > 600){
                    exp1 = 600;
                }
            }
        }
        else if (4 <= e1 && e1 <= 99){
            if (e1 <= 19){
                exp2 += e1 / 4.0 + 0.9999 + 19;
            }
            else if (e1 <= 49) {
                exp2 += 21 + e1 / 9.0 + 0.9999;
            }
            else if (e1 <= 65){
                exp2 += 17 + e1 / 16.0 + 0.9999;
            }
            else if (e1 <= 79){
                exp2 += 19 + e1 / 4.0 + 0.9999;
                if (exp2 > 200){
                    exp2 += 21 + e1 / 9.0 + 0.9999;
                }
            }
            else {
                exp2 += 19 + 21 + e1 / 4.0 + 0.9999;
                exp2 += e1 / 9.0 + 0.9999;
                if (exp2 > 400){
                    exp2 += e1 / 16.0 + 0.9999 + 17;
                    exp2 += exp2 * 0.15 + 0.9999;
                }
            }

            if (exp2 > 600){
                exp2 = 600;
            }
            exp1 -= e1;
            if (exp1 < 0){
                exp1 = 0;
            }
        }
    
        return exp1 + exp2;
    }
    else {
        return -99;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (HP1 < 0){
        HP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
    }
    if (EXP1 < 0){
        EXP1 = 0;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    if (M1 < 0){
        M1 = 0;
    }
    if (M1 > 3000){
        M1 = 3000;
    }
    if (0 <= E2 && E2 <= 99){
        //first route
        int s;
        double p1, p2, p3;
        int a = sqrt(EXP1);
        if (a * a == EXP1){
            s = a * a;
        }
        else {
            abs(a * a - EXP1) < pow(a + 1, 2) - EXP1 ? s = a*a : s = (a + 1)*(a + 1);
        }
        if (EXP1 >= s){
            p1 = 1;
        }
        else {
            p1 = (((double)EXP1 / s) + 80) / 123;
        }

        //second route
        if (E2 % 2 == 0){
            if (M1 > 0){
                if (HP1 < 200){
                    HP1 = HP1 * 1.3 + 0.9999;
                    M1 -= 150;
                }
                else {
                    HP1 = HP1 * 1.1 + 0.9999;
                    M1 -= 70;
                }
            }
            if (M1 > 0){
                if (EXP1 < 400){
                    M1 -= 200;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = EXP1 * 1.13 + 0.9999;
                if (EXP1 > 600){
                    EXP1 = 600;
                }
            }
            if (M1 > 0){
                if (EXP1 < 300){
                    M1 -= 100;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = EXP1 * 0.9 + 0.9999;
            }
        }
        else {
            double m_used = 0;
            while (m_used <= 0.5 * M1){
                if (HP1 < 200){
                    m_used += 150;
                    HP1 = HP1 * 1.3 + 0.9999;
                }
                else {
                    m_used += 70;
                    HP1 = HP1 * 1.1 + 0.9999;
                }
                if (m_used <= 0.5 * M1){
                    if (EXP1 < 400){
                        m_used += 200;
                    }
                    else {
                        m_used += 120;
                    }
                    EXP1 = EXP1 * 1.13 + 0.9999;
                    if (EXP1 > 600){
                        EXP1 = 600;
                    }
                    if (m_used <= M1 * 0.5){
                        if (EXP1 < 300){
                            m_used += 100;
                        }
                        else {
                            m_used += 120;
                        }
                        EXP1 = EXP1 * 0.9 + 0.9999;
                    }
                }
            }
            M1 -= m_used;
        }
        if (HP1 > 666){
            HP1 = 666;
        }
        if (M1 < 0){
            M1 = 0;
        }
        HP1 = HP1 * 0.83 + 0.9999;
        EXP1 = EXP1 * 1.17 + 0.9999;
        if (EXP1 > 600){
            EXP1 = 600;
        }
        a = sqrt(EXP1);
        if (a * a == EXP1){
            s = a * a;
        }
        else {
            abs(a * a - EXP1) < (a + 1) * (a + 1) - EXP1 ? s = a*a : s = (a + 1)*(a + 1);
        }
        if (EXP1 >= s){
            p2 = 1;
        }
        else {
            p2 = ((double)EXP1 / s + 80) / 123;
        }

        //third route
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if (E2 < 10){
            p3 = P[E2] * 0.01;
        }
        else {
            int sum = E2 / 10 + E2 % 10;
            p3 = P[sum % 10] * 0.01;
        }

        //finishing
        if (p1 == 1 && p2 == 1 && p3 == 1){
            EXP1 = EXP1 * 0.75 + 0.9999;
        }
        else {
            if (p1 + p2 + p3 < 1.5){
                HP1 = HP1 * 0.85 + 0.9999;
                EXP1 = EXP1 * 1.15 + 0.9999;
            }
            else {
                HP1 = HP1 * 0.9 + 0.9999;
                EXP1 = EXP1 * 1.2 + 0.9999;
            }

            if (EXP1 > 600){
                EXP1 = 600;
            }
        }

        return HP1 + EXP1 + M1;
    }
    else {
        return -99;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (HP1 < 0){
        HP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
    }
    if (EXP1 < 0){
        EXP1 = 0;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    if (HP2 < 0){
        HP2 = 0;
    }
    if (HP2 > 666){
        HP2 = 666;
    }
    if (EXP2 < 0){
        EXP2 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }
    if (0 <= E3 && E3 <= 99){
        int mmap[10][10] = {0};
        int i_val = 0, j_val = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                mmap[i][j] = (i - j)*(E3*j + i*2);
                if (mmap[i][j] > E3 * 2){
                    i_val++;
                }
                if (mmap[i][j] < -E3){
                    j_val++;
                }
            }
        }
        while (i_val > 9){
            i_val = i_val / 10 + i_val % 10;
        }
        while (j_val > 9){
            j_val = j_val / 10 + j_val % 10;
        }
        int i = i_val, j = j_val, SWpoint = mmap[i_val][j_val];
        //top left
        while (i > -1 && j > -1){
            if (mmap[i][j] > SWpoint){
                SWpoint = mmap[i][j];
            }
            i--;
            j--;
        }
        //top right
        i = i_val; j = j_val;
        while (i > -1 && j < 10){
            if (mmap[i][j] > SWpoint){
                SWpoint = mmap[i][j];
            }
            i--;
            j++;
        }
        //bottom left
        i = i_val; j = j_val;
        while (i < 10 && j > -1){
            if (mmap[i][j] > SWpoint){
                SWpoint = mmap[i][j];
            }
            i++;
            j--;
        }
        //bottom right
        i = i_val; j = j_val;
        while (i < 10 && j < 10){
            if (mmap[i][j] > SWpoint){
                SWpoint = mmap[i][j];
            }
            i++;
            j++;
        }
        if (abs(mmap[i_val][j_val]) > abs(SWpoint)){
            EXP1 = ceil(EXP1 * 0.88);
            EXP2 = ceil(EXP2 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            HP2 = ceil(HP2 * 0.9);
        }
        else {
            EXP1 = EXP1 * 1.12 + 0.999;
            EXP2 += ceil(EXP2 * 0.12);
            HP1 += ceil(HP1 * 0.1);
            HP2 += ceil(HP2 * 0.1);
        }
        if (EXP1 > 600){
            EXP1 = 600;
        }
        if (EXP2 > 600){
            EXP2 = 600;
        }
        if (HP1 > 666){
            HP1 = 666;
        }
        if (HP2 > 666){
            HP2 = 666;
        }


        return abs(mmap[i_val][j_val]) > abs(SWpoint) ? mmap[i_val][j_val] : abs(SWpoint);
    }
    else {
        return -99;
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char* des = strchr(email, 64);
    size_t length = des - email;
    char se[length];
    strncpy(se, email, length);
    se[length] = '\0';
    string c_s = s;
    bool hasContinuousCharacters = false;
    bool hasOtherSymbols = false;
    int c_index = -1;
    int s_index = -1;
    for (int i = 0; i < c_s.length() - 2; i++){
        if (i < c_s.length() - 2){
            if (c_s[i] == c_s[i + 1]&& c_s[i] == c_s[i + 2]){
                hasContinuousCharacters = true;
                c_index = i;
                break;
            }
        }
    }
    for (int i = 0; i < c_s.length(); i++){
        if (hasOtherSymbols == false){
            if (c_s[i] <= 32 || c_s[i] == 34 || (38 <= c_s[i] && c_s[i] <= 47) || (58 <= c_s[i] && c_s[i] <= 63) || (90 < c_s[i] && c_s[i] <= 96) || (123 <= c_s[i] && c_s[i] <= 127)){
                hasOtherSymbols = true;
                s_index = i;
            }
        }
    }
    
    if (strlen(s) <= 20 && strlen(s) >= 8){
        if (strstr(s, se) != NULL) {
            return -(300 + strlen(s) - strlen(strstr(s, se)));
        }
        else if (hasContinuousCharacters){
            return -(400 + c_index);
        }
        else if (strstr(s, "@") == NULL && strstr(s, "#") == NULL && strstr(s, "%") == NULL && strstr(s, "$") == NULL && strstr(s, "!") == NULL) {
            return -5;
        }
        else if (hasOtherSymbols) {
            return s_index;
        }
        else {
            return -10;
        }
    }
    else {
        if (strlen(s) < 8){
            return -1;
        }
        else return -2;
    }


}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string c_arr_pwds[num_pwds];
    string password;
    for (int i = 0; i < num_pwds; i++){
        c_arr_pwds[i] = arr_pwds[i];
    }
    int max = 0;
    int index;
    int count;
    for (int i = 0; i < num_pwds; i++){
        if (c_arr_pwds[i] != " "){
            count = 1;
            for (int j = i + 1; j < num_pwds; j++){
                if (c_arr_pwds[j] == c_arr_pwds[i]){
                    c_arr_pwds[j] = " ";
                    count++;
                }
            }
            if (count > max){
                max = count;
                index = i;
                password = c_arr_pwds[i];
            }
            else if (count == max){
                if (password.length() < c_arr_pwds[i].length()){
                    max = count;
                    index = i;
                    password = c_arr_pwds[i];
                }
            }
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////