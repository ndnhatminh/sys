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
//Task 1
int check(int n, int first, int last){
    n = (n < first) ? first : (n > last) ? last : n;
    return n;
}
const int first = 0, lastHP = 666, lastEXP = 600, lastM = 6000;

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    exp1 = check(exp1, first, lastEXP);
    exp2 = check(exp2, first, lastEXP);
    const int in1_1 = 29, in1_2 = 45, in1_3 = 75;
    float in2_1 = e1/4.0 + 19;
    float in2_2 = e1/9.0 + 21;
    float in2_3 = e1/16.0 + 17;
    float exp1_test = exp1, exp2_test = exp2;
    if(e1 < 4){
        switch(e1){
            case 0: 
            {
                exp2 += in1_1;
                break;
            }
            case 1:
            {
                exp2 += in1_2;
                break;
            }
            case 2:
            {
                exp2 += in1_3;
                break;
            }
            case 3:
            {
                exp2 += (in1_1 + in1_2 + in1_3);
                break;
            }
        }
        int d = e1*3 + exp1*7;
        if (d % 2 == 0) {
            exp1_test = exp1_test + d/200.0;
            exp1_test = ceil(exp1_test);
        }
        else {
            exp1_test = exp1_test - d/100.0;
            exp1_test = ceil(exp1_test);
        }
        exp1 = exp1_test;
    }
    else {
        if (e1 >= 4 && e1 <= 19) exp2_test += in2_1;
        if (e1 >= 20 && e1 <= 49) exp2_test += in2_2;
        if (e1 >= 50 && e1 <= 65) exp2_test += in2_3;
        if (e1 >= 66 && e1 <= 79){
            exp2_test = exp2_test + in2_1;
            exp2_test = ceil(exp2_test);
            exp2 = exp2_test;
            exp2 = check(exp2, first, lastEXP);
            exp2_test = exp2;
            if(exp2_test > 200) exp2_test += in2_2;
        }
        if (e1 >= 80 && e1 <= 99){
            exp2_test = exp2_test + in2_1;
            exp2_test = ceil(exp2_test);
            exp2 = exp2_test;
            exp2 = check(exp2, first, lastEXP);
            exp2_test = exp2;
            exp2_test = exp2_test + in2_2;
            exp2_test = ceil(exp2_test);
            exp2 = exp2_test;
            exp2 = check(exp2, first, lastEXP);
            exp2_test = exp2;
            if (exp2_test > 400){
                exp2_test = exp2_test + in2_3;
                exp2_test = ceil(exp2_test);
                exp2 = exp2_test;
                exp2 = check(exp2, first, lastEXP);
                exp2_test = exp2;
                exp2_test *= 1.15;
            }
        }
        exp2_test = ceil(exp2_test);
        exp2 = exp2_test;
        exp1_test = exp1_test - e1*1.0;
        exp1_test = ceil(exp1_test);
        exp1 = exp1_test;
    }
    exp1 = check(exp1, first, lastEXP);
    exp2 = check(exp2, first, lastEXP);
    return exp1 + exp2;
}

//Task2
int nearestSqare(int n){
    float a = sqrt(n);
    int upper = ceil(a);
    int lower = floor(a);
    if(n - (lower * lower) < (upper * upper) - n) return lower * lower;
    else return upper * upper;
}
float xacsuat(int n, int sqr){
    if (sqr > n) return ((n*1.0)/sqr + 80.0)/123;
    else return 1.0;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float p1,p2,p3,p;
    float exp1_test = EXP1;
    float hp1_test = HP1;
    EXP1 = check(EXP1, first, lastEXP);
    HP1 = check(HP1, first, lastHP);
    M1 = check(M1, first, lastM);
    if (E2 < 0 || E2 > 99) return -99;
    int sqr = nearestSqare(EXP1);
    p1 = xacsuat(EXP1, sqr);
    float m_road2 = M1 * 0.5;
    int tieu = 0;
    if(E2 % 2 == 1){
        while(1){
            if (hp1_test < 200) {
                hp1_test = hp1_test*1.3;
                hp1_test = ceil(hp1_test);
                HP1 = hp1_test;
                HP1 = check(HP1, first, lastHP);
                hp1_test = HP1;
                M1 -= 150;
                tieu += 150;
                if (tieu > m_road2) break;
            } else {
                hp1_test = hp1_test*1.1;
                hp1_test = ceil(hp1_test);
                HP1 = hp1_test;
                HP1 = check(HP1, first, lastHP);
                hp1_test = HP1;
                M1 -= 70;
                tieu += 70;
                if (tieu > m_road2) break;
            }
            if (exp1_test < 400) {
                exp1_test = exp1_test*1.13;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 200;
                tieu += 200;
                if (tieu > m_road2) break;
            } else {
                exp1_test = exp1_test*1.13;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 120;
                tieu += 120;
                if (tieu > m_road2) break;
            }
            if (exp1_test < 300) {
                exp1_test = exp1_test*0.9;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 100;
                tieu += 100;
                if (tieu > m_road2) break;
            } else {
                exp1_test = exp1_test*0.9;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 120;
                tieu += 120;
                if (tieu > m_road2) break;
            }
        }
        exp1_test = exp1_test*1.17;
        exp1_test = ceil(exp1_test);
        EXP1 = exp1_test;
        EXP1 = check(EXP1, first, lastEXP);
        exp1_test = EXP1;
        hp1_test = hp1_test*0.83;
        hp1_test = ceil(hp1_test);
        HP1 = hp1_test;
        HP1 = check(HP1, first, lastHP);
        hp1_test = HP1;
        sqr = nearestSqare(EXP1);
        p2 = xacsuat(EXP1, sqr);
    }
    else {
        for (int i=0;i<1;i++) {
            if (hp1_test < 200) {
                hp1_test = hp1_test*1.3;
                hp1_test = ceil(hp1_test);
                HP1 = hp1_test;
                HP1 = check(HP1, first, lastHP);
                hp1_test = HP1;
                M1 -= 150;
                if (M1 <= 0) break;
            } else {
                hp1_test = hp1_test*1.1;
                hp1_test = ceil(hp1_test);
                HP1 = hp1_test;
                HP1 = check(HP1, first, lastHP);
                hp1_test = HP1;
                M1 -= 70;
                if (M1 <= 0) break;
            }
            if (exp1_test < 400) {
                exp1_test = exp1_test*1.13;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 200;
                if (M1 <= 0) break;
            } else {
                exp1_test = exp1_test*1.13;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 120;
                if (M1 <= 0) break;
            }
            if (exp1_test < 300) {
                exp1_test = exp1_test*0.9;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 100;
                if (M1 <= 0) break;
            } else {
                exp1_test = exp1_test*0.9;
                exp1_test = ceil(exp1_test);
                EXP1 = exp1_test;
                EXP1 = check(EXP1, first, lastEXP);
                exp1_test = EXP1;
                M1 -= 120;
                if (M1 <= 0) break;
            }
        }
        exp1_test = exp1_test*1.17;
        exp1_test = ceil(exp1_test);
        EXP1 = exp1_test;
        EXP1 = check(EXP1, first, lastEXP);
        exp1_test = EXP1;
        hp1_test = hp1_test*0.83;
        hp1_test = ceil(hp1_test);
        HP1 = hp1_test;
        HP1 = check(HP1, first, lastHP);
        hp1_test = HP1;
        sqr = nearestSqare(EXP1);
        p2 = xacsuat(EXP1, sqr);
    }
    int k[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10){
        p3 = k[E2]/100.0;
    }
    else {
        p3 = k[(E2/10 + E2%10)%10]/100.0;
    }
    p = (p1 + p2 + p3)/3;
    if (p < 1.0){
        if (p > 0.5){
            hp1_test = hp1_test*0.9;
            hp1_test = ceil(hp1_test);
            HP1 = hp1_test;
            HP1 = check(HP1, first, lastHP);
            hp1_test = HP1;
            exp1_test = exp1_test*1.2;
            exp1_test = ceil(exp1_test);
            EXP1 = exp1_test;
            EXP1 = check(EXP1, first, lastEXP);
            exp1_test = EXP1;
        }
        else {
            hp1_test = hp1_test*0.85;
            hp1_test = ceil(hp1_test);
            HP1 = hp1_test;
            HP1 = check(HP1, first, lastHP);
            hp1_test = HP1;
            exp1_test = exp1_test*1.15;
            exp1_test = ceil(exp1_test);
            EXP1 = exp1_test;
            EXP1 = check(EXP1, first, lastEXP);
            exp1_test = EXP1;
        }
    }
    else {
        exp1_test = exp1_test*0.75;
        exp1_test = ceil(exp1_test);
        EXP1 = exp1_test;
        EXP1 = check(EXP1, first, lastEXP);
        exp1_test = EXP1;
    }
    M1 = check(M1, first, lastM);
    return HP1 + EXP1 + M1;
}
//Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int tab[10][10];
    int cntpos = 0, cntneg = 0;
    memset(tab, 0, sizeof(tab));
    HP1 = check(HP1, first, lastHP);
    HP2 = check(HP2, first, lastHP);
    EXP1 = check(EXP1, first, lastEXP);
    EXP2 = check(EXP2, first, lastEXP);
    float hp1_test = HP1;
    float hp2_test = HP2;
    float exp1_test = EXP1;
    float exp2_test = EXP2;
    if (E3 < 0 || E3 > 99) return -99;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tab[i][j] = ((E3*j) + (i*2)) * (i - j);
            if (tab[i][j] > 0) 
                if (tab[i][j] > E3*2) cntpos++;
            if (tab[i][j] < 0)
                if (tab[i][j] < -E3) cntneg++;
        }
    }
    int a = cntpos, b = cntneg;
    while(a >= 10) a = a/10 + a%10;
    while(b >= 10) b = b/10 + b%10;
    int taxi = tab[a][b];
    int sum = a + b, sub = a - b;
    int MaxN = taxi;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) 
            if((i + j == sum) || (i - j == sub)) 
                if (MaxN < tab[i][j]) MaxN = tab[i][j];
    if (abs(MaxN) < abs(taxi)){
        exp1_test = ceil(exp1_test*0.88);
        EXP1 = exp1_test;
        EXP1 = check(EXP1, first, lastEXP);
        exp2_test = ceil(exp2_test*0.88);
        EXP2 = exp2_test;
        EXP2 = check(EXP2, first, lastEXP);
        hp1_test = ceil(hp1_test*0.9);
        HP1 = hp1_test;
        HP1 = check(HP1, first, lastHP);
        hp2_test = ceil(hp2_test*0.9);
        HP2 = hp2_test;
        HP2 = check(HP2, first, lastHP);
        return taxi;
    }
    else{
        exp1_test = exp1_test*1.12;
        exp1_test = ceil(exp1_test);
        EXP1 = exp1_test;
        EXP1 = check(EXP1, first, lastEXP);
        exp2_test = exp2_test*1.12;
        exp2_test = ceil(exp2_test);
        EXP2 = exp2_test;
        EXP2 = check(EXP2, first, lastEXP);
        hp1_test = hp1_test*1.1;
        hp1_test = ceil(hp1_test);
        HP1 = hp1_test;
        HP1 = check(HP1, first, lastHP);
        hp2_test = hp2_test*1.1;
        hp2_test = ceil(hp2_test);
        HP2 = hp2_test;
        HP2 = check(HP2, first, lastHP);
        return MaxN;
    }
    return -1;
}

//Task 4
int vitri(const char * s, char * se){
    int d = -1;
    if (strstr(s, se) != NULL)
        d = strlen(s) - strlen(strstr(s, se));
    return d;
}

int trung(const char * s){
    int cnt = 1;
    for (int i = 1; i < strlen(s); i++){
        if (s[i] == s[i-1]) cnt++;
        else cnt = 1;
        if (cnt > 2) return i - 2;
    }
    return -1;
}

int demkitu(const char * s, char a){
    int count = 0;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == a) count++;
    }
    return count;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int length = strlen(s);
    int cntspe = 0;
    int i = 0;
    char * se = new char[256];
    while(email[i] != '@'){
        se[i] = email[i];
        i++;
    }
    for (int i = 0; i < length; i++)
        cntspe = demkitu(s, '@') + demkitu(s, '!') + demkitu(s, '#') + demkitu(s, '$') + demkitu(s, '%');
    if (length < 8) return -1;
    else if (length > 20) return -2;
    else if (vitri(s, se) != -1) return -(300 + vitri(s, se));
    else if (trung(s) != -1) return -(400 + trung(s));
    else if (cntspe == 0) return -5;
    else {
        for (int i = 0; i < length; i++)
            if ((s[i] < '0' || s[i] >'9') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && s[i] != '!' && s[i] != '@' && s[i] != '#' && s[i] != '$' && s[i] != '%')
                return i;
    }
    return -10;
    return -99;
}

//Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string S[num_pwds];
    int appear[num_pwds], length[num_pwds];
    int count_max = 0, length_max = 0, pos;
    memset(appear, 0, sizeof(appear));
    for (int i = 0; i < num_pwds; i++) {
        S[i] = arr_pwds[i];
        length[i] = strlen(arr_pwds[i]);
        for (int j = 0; j <= i; j++) {
            if (S[j] == S[i])
                appear[j]++;
        }
    }
    for (int i = 0; i < num_pwds; i++)
        if (appear[i] > count_max || (appear[i] == count_max && length[i] > length_max)) {
            count_max = appear[i];
            length_max = length[i];
            pos = i;
        }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
