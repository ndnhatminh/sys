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
void reset_HP(int & HP){
    if (HP > 666){
        HP = 666;
    }
    else if (HP < 0){
        HP = 0;
    }
}
void reset_EXP(int & EXP){
    if (EXP > 600){
        EXP = 600;
    }
    else if (EXP < 0){
        EXP = 0;
    }
}
void reset_M(int & M){
    if (M > 3000){
        M = 3000;
    }
    else if (M < 0){
        M = 0;
    }
}


int fM_info_1(int e1){
    return ceil((double)e1/4 + 19);
}
int fM_info_2(int e1){
    return ceil((double)e1/9 + 21);
}
int fM_info_3(int e1){
    return ceil((double)e1/16 + 17);

}
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99) return -99;
    reset_EXP(exp1);
    reset_EXP(exp2);
    if (e1 <= 3){
        switch (e1){
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
                exp2 += 149;
                break;
        }
        reset_EXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (1 & D){
            exp1 -= (int)(D/100);
        }
        else{
            exp1 += ceil((double)D/200.0);
        } 
        reset_EXP(exp1);
        return exp1 + exp2;
    }
    else{
        switch (e1){
            case 4 ... 19:
                exp2 += fM_info_1(e1);
                reset_EXP(exp2);
                break;
            case 20 ... 49:
                exp2 += fM_info_2(e1);
                reset_EXP(exp2);
                break;
            case 50 ... 65:
                exp2 += fM_info_3(e1);
                reset_EXP(exp2);
                break;
            case 66 ... 79:
                exp2 += fM_info_1(e1);
                reset_EXP(exp2);
                if (exp2 > 200){
                    exp2 += fM_info_2(e1);
                }
                reset_EXP(exp2);
                break;
            case 80 ... 99:
                exp2 += fM_info_1(e1);
                exp2 += fM_info_2(e1);
                if (exp2 > 400){
                    exp2 += fM_info_3(e1);
                    exp2 = ceil(exp2 * 115.0 / 100);
                }
                reset_EXP(exp2);
                break;
        }
        exp1 -= e1;
        reset_EXP(exp1);
        return exp1 + exp2;
    }
}

// Task 2
void tL_1(int & HP, int & M){
    if (HP < 200){
        HP = ceil(HP * 130.0 / 100);
        M -= 150;
    }
    else{
        HP = ceil(HP * 110.0 / 100);
        M -= 70;
    }
    reset_HP(HP);
    reset_M(M);
}

void tL_2(int & EXP, int & M){
    if (EXP < 400){
        M -= 200;
    }
    else{
        M -= 120;
    }
    EXP = ceil(EXP * 113.0 / 100);
    reset_EXP(EXP);
    reset_M(M);
}

void tL_3(int & EXP, int & M){
    if (EXP < 300){
        M -= 100;
    }
    else{
        M -= 120;
    }
    EXP = ceil(EXP * 90.0 / 100);
    reset_EXP(EXP);
    reset_M(M);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    reset_HP(HP1);
    reset_EXP(EXP1);
    reset_M(M1);
    double P1, P2, P3;

    int S = sqrt(EXP1);
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1){
        S = S * S;
    }
    else S = (S + 1) * (S + 1);
    if (EXP1 < S){
        P1 = (EXP1*1.0/S + 80.0)/123.0;
    }
    else{
        P1 = 1;
    }

    //P2
    if (E2&1){
        double temp = M1;  
        int cnt=0;
        while ((temp - M1 <= temp/2.0) && (M1 > 0)){
            cnt %= 3;
            if (cnt == 0){
                tL_1(HP1, M1);
            }
            else if (cnt == 1){
                tL_2(EXP1, M1);
            }
            else if (cnt == 2){
                tL_3(EXP1, M1);
            }
            cnt++;        
        } 
    } 
    else{
        int cnt = 0;
        while (M1 > 0 && cnt < 3){
            if (cnt == 0){
                tL_1(HP1, M1);
            }
            else if (cnt == 1){
                tL_2(EXP1, M1);
            }
            else if (cnt == 2){
                tL_3(EXP1, M1);
            }
            cnt++;
        } 
    }
    HP1 = ceil(HP1 * 83.0 /100);
    EXP1 = ceil(EXP1 * 117.0 / 100);
    reset_HP(HP1); reset_EXP(EXP1);
    S = sqrt(EXP1);
    if (EXP1 - S * S < (S + 1) * (S + 1) - EXP1){
        S = S * S;
    }
    else S = (S + 1) * (S + 1);
    if (EXP1 < S){
        P2 = (1.0 *EXP1/S + 80)/123.0;
    }
    else{
        P2 = 1;
    }

    //P3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2%10 + E2/10) % 10;
    P3 = 1.0*P[i]/100;
    if (P1 + P2 + P3 == 3){
        EXP1 = ceil(EXP1 * 75.0 / 100);
    }
    else{
        double Ave_P = (P1 + P2 + P3)/3.0;
        if (Ave_P <= 0.5){
            HP1 = ceil(HP1 * 85.0 / 100);
            EXP1 = ceil(EXP1 * 115.0 / 100);
        }
        else{
            HP1 = ceil(HP1 * 90.0 / 100);
            EXP1 = ceil(EXP1 * 120.0 / 100);
        }
    }
    reset_HP(HP1); reset_EXP(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    reset_EXP(EXP1); reset_EXP(EXP2); reset_HP(HP1); reset_HP(HP2);
    int scoreTaxi[10][10];
    int scoreSW = 0, iMeet = 0, jMeet = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            scoreTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (scoreTaxi[i][j] > 2*E3) iMeet++;
            if (scoreTaxi[i][j] < -E3 ) jMeet++;
        }
    }
    while (iMeet > 9){
        iMeet = iMeet/10 + iMeet%10;
    }
    while (jMeet > 9){
        jMeet = jMeet/10 + jMeet%10;
    }
    //calculate scoreSW
    scoreSW = scoreTaxi[iMeet][jMeet];
    int i = iMeet - 1, j = jMeet - 1;
    while (i >= 0 && j >= 0){
        scoreSW = max(scoreSW, scoreTaxi[i][j]);
        i--;
        j--;
    }
    i = iMeet + 1, j = jMeet + 1;
    while (i <= 9 && j <= 9){
        scoreSW = max(scoreSW, scoreTaxi[i][j]);
        i++;
        j++;
    }
    i = iMeet + 1, j = jMeet - 1;
    while (i <= 9 && j >= 0){
        scoreSW = max(scoreSW, scoreTaxi[i][j]);
        i++;
        j--;
    }
    i = iMeet - 1, j = jMeet + 1;
    while (i >= 0 && j <= 9){
        scoreSW = max(scoreSW, scoreTaxi[i][j]);
        i--;
        j++;
    }
    if (abs(scoreTaxi[iMeet][jMeet]) > abs(scoreSW)){
        EXP1 = ceil(EXP1 * 88.0 / 100);
        HP1 = ceil(HP1 * 90.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP2 = ceil(HP2 * 90.0 / 100);
        reset_EXP(EXP1); reset_EXP(EXP2); reset_HP(HP1); reset_HP(HP2);
        return scoreTaxi[iMeet][jMeet];
    }
    else{
        EXP1 = ceil(EXP1 * 112.0 /100);
        HP1 = ceil(HP1 * 110.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
        reset_EXP(EXP1); reset_EXP(EXP2); reset_HP(HP1); reset_HP(HP2);
        return scoreSW;
    }
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string str = s;
    string mail = email;
    if (str.size() < 8) return -1;
    if (str.size() > 20) return -2;
    string se = "";
    for (int i = 0; i < mail.size(); i++){
        if (mail[i] == '@') break;
        se += mail[i];
    }
    if (str.find(se) != -1) return (-(300 + str.find(se)));
    for (int i = 0; i < str.size() - 2; i++){
        if (str[i] == str[i+1] && str[i+1] == str[i+2]){
            return (-(400 + i));
        }
    }
    bool f = false;
    char special_c[]={'@', '#', '%', '$', '!'};
    for (int i = 0; i < 5; i++){
        if (str.find(special_c[i]) != -1){
            f = true;
            break;
        }
    }
    if (!f) return (-5);
    for (int i = 0; i < str.size(); i++){
        if ((str[i] > 'z' || str[i] < 'a') && (str[i] > 'Z' || str[i] < 'A')){
            if (str[i] != '@' && str[i] != '#' && str[i] != '%' && str[i] != '$' && str[i] != '!'){
                return i;
            }
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq[30];
    string pwds[30];
    for (int i = 0; i < 30; i++){
        freq[i] = 0;
    }
    int cnt = 0;
    for (int i = 0; i < num_pwds; i++){
        bool f = true;
        for (int j = 0; j < cnt; j++){
            if (arr_pwds[i] == pwds[j]){
                freq[j]++;
                f = false;
                break;
            }
        }
        if (f){
            pwds[cnt] = arr_pwds[i];
            cnt++;
        }
    }
    string pwd;
    int max_freq = 0;
    for (int i = 0; i < cnt; i++){
        if (freq[i] > max_freq){
            max_freq = freq[i];
            pwd = pwds[i];
        }
        else if (freq[i] == max_freq && pwds[i].size() > pwd.size()){
            pwd = pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; i++){
        if (arr_pwds[i] == pwd){
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////