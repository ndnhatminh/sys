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

void cHP(int &HP){
    if (HP<0) HP=0;
    else if (HP>666) HP=666;
};
void cEXP(int &EXP){
    if (EXP<0) EXP=0;
    else if (EXP>600) EXP=600;
};
void cM(int &M){
    if (M<0) M=0;
    if (M>3000) M=3000;
};
void cE(int E){
    if (E<0 || E>99) E=-99;
};
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    cE(e1);
    //TH1
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
            exp2 += (29 + 45 + 75);
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = exp1 + ceil(D / 200);
            cEXP(exp1);
        }
        else {
            exp1 = exp1 - ceil(D / 100);
            cEXP(exp1);
        }
    }
    //TH2
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceil(e1 / 4.0 + 19);
            cEXP(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil(e1 / 9.0 + 21);
            cEXP(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil(e1 / 16.0 + 17);
            cEXP(exp2);
        }
        else if (e1 >= 66 &&e1 <= 79) {
            exp2 += ceil(e1 / 4.0 + 19);
            if (exp2 > 200) {
                exp2 += ceil(e1 * 1.0 / 9.0 + 21);
                cEXP(exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(e1 * 1.0 / 4.0 + 19);
            cEXP(exp2);
            exp2 += ceil(e1 * 1.0 / 9.0 + 21);
            cEXP(exp2);
            if (exp2 > 400) {
                exp2 += ceil(e1 * 1.0 / 16.0 + 17);
                cEXP(exp2);
            }
            exp2 = ceil(exp2 * 1.15);
            cEXP(exp2);
        }
    exp1-=e1;
    }
    cEXP(exp1);
    cEXP(exp2);
        
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    cE(E2);
    //R1
    float P1 = 0.0, P2 = 0.0, P3 = 0.0;
    float s1 = sqrt(EXP1);
    float S1 = round(s1) * round(s1);
    if (EXP1 >= S1) P1 = 1;
    else P1 = (EXP1 / S1 + 80) / 123.0;
    //R2
    int money = 0;
    int ss = 1;
    if (E2 % 2 != 0)do {
        switch (ss) {
        case 1:
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                money += 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                money += 70;
            }
            if (money < M1 / 2) ss++;
            else break;
        case 2:
            if (EXP1 < 400) {
                money += 200;
            }
            else {
                money += 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (money < M1/2) ss++;
            else break;
        case 3:
            if (EXP1 < 300) {
                money += 100;
            }
            else {
                money += 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            if (money < M1) ss = 1;
            else break;
        }
    } while (money < M1 / 2);
    else switch (ss) {
    case 1:
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            money += 150;
        }
        else {
            HP1 = ceil(HP1 * 1.1);
            money += 70;
        }
        if (money < M1 / 2) ss++;
        else break;
    case 2:
        if (EXP1 < 400) {
            money += 200;
        }
        else money += 120;
        EXP1 = ceil(EXP1 * 1.13);
        if (money < M1 / 2) ss++;
        else break;
    case 3:
        if (EXP1 < 300) {
            money += 100;
        }
        else money += 120;
        EXP1 = ceil(EXP1 * 0.9);
        if (money < M1 / 2) ss = 1;
        else break;
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    M1 = M1 - money;
    float s2 = sqrt(EXP1);
    float S2 = round(s2) * round(s2);
    if (EXP1 >= S2) P2 = 1;
    else {
        P2 = (EXP1 / S2 + 80) / 123.0;
    }
    //R3
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 >= 0 && E2 <= 9) {
        P3 = P[E2];
    }
    else if (E2 >= 10 && E2 <= 99) {
        int a = ((E2 / 10) + (E2 % 10)) % 10;
        P3 = P[a];
    }
    //End
    if (P1 == P2 && P2 * 100 == P3 && P3 == 100) {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else {
        float P = (P1 * 100 + P2 * 100 + P3) / 3.0;
        if (P < 50) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else if (P >= 50) {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }

    cHP(HP1);
    cEXP(EXP1);
    cM(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    cE(E3);
    int taxi[10][10];
    int score[10][10];
    //taxi di chuyen
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    //S va W di chuyen
    int maxt = 0, xt, yt;
    int maxp = 0, xp, yp;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //tren xuong
            if (i > j) {
                xt = 0; yt = i - j;
            }
            else {
                xt = j - i; yt = 0;
            }
            do {
                if (taxi[yt][xt] > maxt)
                    maxt = taxi[yt][xt];
                xt++; yt++;
            } while (xt < 10 && yt < 10);
            //duoi len
            if (i + j >= 9) {
                xp = i + j - 9; yp = 9;
            }
            else {
                xp = 0; yp = i + j;
            }
            do {
                if (taxi[yp][xp] > maxp)
                    maxp = taxi[yp][yp];
                xp++; yp--;
            } while (xp < 10 && yp >= 0);
            score[i][j] = abs(maxt + maxp);
        }
    }
    int gapx = 0, gapy = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3 * 2))
                gapy++;
            if (taxi[i][j] < (E3 * -1))
                gapx++;
        }
    }
    do gapy = (gapy % 10) + (gapy / 10); while (gapy / 10 > 0);
    do gapx = (gapx % 10) + (gapx / 10); while (gapx / 10 > 0);
    if (abs(taxi[gapy][gapx]) > score[gapy][gapx]) {
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        EXP2 = ceil(EXP2 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
    }

    cHP(HP1);
    cEXP(EXP1);
    cHP(HP2);
    cEXP(EXP2);

    if (abs(taxi[gapy][gapx]) > score[gapy][gapx])
        return taxi[gapy][gapx];
    else return score[gapy][gapx];
}

// Task 4
int checkPassword(const char * s, const char * email){
    string chuoi_s = string(s);
    string chuoi_email = string(email);
    if (chuoi_s.size() < 8) return -1;
    else if (chuoi_s.size() > 20) return -2;
    else{
        string se = "";
        for (int i = 0; i < chuoi_email.size(); ++i){
            if (chuoi_email[i] != '@') se += chuoi_email[i];
            else break;
        }

        bool check1 = true;
        for (int i = 0; i < chuoi_s.size(); ++i){
            for (int j = 0; j < se.size(); ++j){
                if (se[j] != s[i + j]){
                    check1 = false;
                    break;
                }
                check1 = true;
            }
            if (check1 == true) return -(300 + i);
        }
        for (int i = 0; i < chuoi_s.size(); ++i){
            if (chuoi_s[i] == chuoi_s[i + 1] && chuoi_s[i] == chuoi_s[i + 2]) return -(400 + i);
        }
        bool check2 = false;
        for (int i = 0; i < chuoi_s.size(); ++i){
            if(chuoi_s[i] == '@' || chuoi_s[i] == '#' || chuoi_s[i] == '%' || chuoi_s[i] == '$' || chuoi_s[i] == '!'){
                check2 = true;
                break;
            }
        }
        if (check2 == false) return -5;
        for (int i = 0; i < chuoi_s.size(); ++i){
            if(chuoi_s[i] < 'a' && chuoi_s[i] > 'z' && chuoi_s[i] < 'A' && chuoi_s[i] > 'Z' && chuoi_s[i] < '0' && chuoi_s[i] > '9' && chuoi_s[i] != '@' && chuoi_s[i] != '#' && chuoi_s[i] != '%' && chuoi_s[i] != '$' && chuoi_s[i] != '!'){
                return i;
            }
        }
        return -10;
    }
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    
    int a = 0;
    int b = 0;
    int correct = -1;

    
    for (int i = 0; i < num_pwds; ++i) {
        const char *pwd = arr_pwds[i];
        int count = 0;
        int length = strlen(pwd);
        
        
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], pwd) == 0) {
                count++;
            }
        }

        
        if (count > a || (count == a && length > b)) {
            a = count;
            b = length;
            correct = i;
        }
    }

    return correct;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////