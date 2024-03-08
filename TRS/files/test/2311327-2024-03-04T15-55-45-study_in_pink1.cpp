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

void ktexp(int &exp){
    if(exp < 0){
        exp = 0;
    }
    else if(exp > 600){
        exp = 600;
    }
}

void kthp(int &hp){
    if(hp < 0){
        hp = 0;
    }
    else if(hp > 666){
        hp = 666;
    }
}

void ktm(int &m){
    if(m < 0){
        m = 0;
    }
    else if(m > 3000){
        m = 3000;
    }
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    double tmp = e1;
    if(e1 < 0 || e1 > 99){
        return -99;
    }
    else if (e1 <= 3){
        int D = e1 * 3 + exp1 * 7;
        float tmp1 = D;
        if (D % 2 == 0){
            exp1 = exp1 + ceil(tmp1 / 200);
        }
        else exp1 = exp1 - floor(tmp1 / 100);
        ktexp(exp1);
        
        if(e1 == 0){
            exp2 += 29;
        }
        else if(e1 == 1){
            exp2 += 45;
        }
        else if(e1 == 2){
            exp2 += 75;
        }
        else exp2 += (29 + 45 + 75);
        ktexp(exp2);
    } 
    else{
        if(e1 >= 4 && e1 <= 19){
            exp2 = exp2 + ceil(tmp / 4 + 19);
        }
        else if(e1 >= 20 && e1 <= 49){
            exp2 = exp2 + ceil(tmp / 9 + 21);
        }
        else if(e1 >= 50 && e1 <= 65){
            exp2 = exp2 + ceil(tmp / 16 + 17);
        }
        else if(e1 >= 66 && e1 <= 79){
            exp2 = exp2 + ceil(tmp / 4 + 19);
            ktexp(exp2);
            if(exp2 > 200){
                exp2 = exp2 + ceil(tmp / 9 + 21);
            }
        }
        else if(e1 >= 80 && e1 <= 99){
            exp2 = exp2 + ceil(tmp / 4 + 19);
            ktexp(exp2);
            exp2 = exp2 + ceil(tmp / 9 + 21);
            ktexp(exp2);
            if(exp2 > 400){
                exp2 = exp2 + ceil(tmp / 16 + 17);
                ktexp(exp2);
                double tmpexp2 = exp2;
                exp2 = exp2 + (tmpexp2 * 15 / 100);
            }
        }
        ktexp(exp2);
        exp1 -= e1;
        ktexp(exp1);
    }
    return exp1 + exp2;
}

// Task 2

int sochinhphuong(int n){
    int nho = sqrt(n);
    int lon = nho + 1;
    if(n - nho * nho < lon * lon - n){
        return nho * nho;
    }
    else return lon * lon;
}

double street1(int exp1){
    float exp;
    float s = sochinhphuong(exp1);
    if(exp1 >= s){
        return 1;
    }
    else return (exp / s + 80) / 123;
}

double street2(int &hp1, int &m1, int &exp1, int e2){
    float tmphp;
    float tmpexp;
    if(e2 % 2 == 0){ 
        do{
            if(m1 == 0){break;}
            if(hp1 < 200){
                tmphp = hp1;
                hp1 = hp1 + ceil(tmphp * 30 / 100);
                m1 -= 150;
            }
            else {
                tmphp = hp1;
                hp1 = hp1 + ceil(tmphp * 10 / 100);
                m1 -= 70;
            }
            ktm(m1);
            kthp(hp1);
            if(m1 == 0){break;}

            if(exp1 < 400){
                m1 -= 200;
            }
            else m1 -= 120;
            ktm(m1);
            tmpexp = exp1;
            exp1 = exp1 + ceil(tmpexp * 13 / 100);
            ktexp(exp1);
            if(m1 == 0){break;}

            if(exp1 < 300){
                m1 -= 100;
            }
            else m1 -= 120;
            ktm(m1);
            tmpexp = exp1;
            exp1 = exp1 - floor(tmpexp *10 / 100);
            ktexp(exp1);
        } while (false);
    }
    else{
        int m = m1 / 2;
        while(m1 > m){
            if(m1 == 0){break;}
            if(hp1 < 200){
                tmphp = hp1;
                hp1 = hp1 + ceil(tmphp * 30 / 100);
                m1 -= 150;
            }
            else {
                tmphp = hp1;
                hp1 = hp1 + ceil(tmphp * 10 / 100);
                m1 -= 70;
            }
            ktm(m1);
            kthp(hp1);

            if(m1 <= m){break;}

            if(exp1 < 400){
                m1 -= 200;
            }
            else m1 -= 120;
            
            ktm(m1);
            tmpexp = exp1;
            exp1 = exp1 + ceil(tmpexp * 13 / 100);
            ktexp(exp1);

            if(m1 <= m){break;}

            if(exp1 < 300){
                m1 -= 100;
            }
            else m1 -= 120;
            
            ktm(m1);
            tmpexp = exp1;
            exp1 = exp1 - floor(tmpexp *10 / 100);
            ktexp(exp1);
        }
    }
    tmpexp = exp1;
    tmphp = hp1;
    hp1 = hp1 - floor(tmphp * 17 / 100);
    exp1 = exp1 + ceil(tmpexp * 17 / 100);
    kthp(hp1);
    ktexp(exp1);
    return street1(exp1);
}

double street3(int e2){
    double p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(e2 < 10){
        return p[e2] / 100;
    }
    else{
        int dv = e2 % 10;
        int c = e2 / 10;
        int tong = dv + c;
        return p[tong % 10] / 100;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double s1 = street1(EXP1), s2 = street2(HP1, M1, EXP1, E2), s3 = street3(E2);
    double tmpEXP = EXP1;
    double tmpHP = HP1;
    if(s1 == s2 == s3 == 1){
        EXP1 = EXP1 - floor(tmpEXP * 25 / 100);
    }
    else{
        double xstb = (s1 + s2 + s3) / 3;
        if(xstb < 0.5){
            HP1 = HP1 - floor(tmpHP * 15 / 100);
            EXP1 = EXP1 + ceil(tmpEXP * 15 / 100);
        }
        else{
            HP1 = HP1 - floor(tmpHP * 10 / 100);
            EXP1 = EXP1 + ceil(tmpEXP * 20 / 100);
        }
    }
    ktexp(EXP1);
    kthp(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int n[10][10];
    int demi = 0, demj =0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            n[i][j] = ((E3 * j)+(i * 2)) * (i - j);
            if(n[i][j] > E3 * 2){
                demi += 1;
            }
            if(n[i][j] < 0 - E3){
                demj += 1;
            }
        }
    }
    while(demi > 9){
        demi = ((demi % 10) + (demi / 10));
    }
    while(demj > 9){
        demj = ((demj % 10) + (demj / 10));
    }
    int a = demi, b = demj;
    int c = demi, d = demj;
    int e = demi, f = demj;
    int g = demi, h = demj;
    int diemsher = 0;

    // hang tang, cot tang
    while(a < 10 && b < 10){
        if(diemsher < n[a][b]){
            diemsher = n[a][b];
        }
        a++;
        b++;
    }
    // hang giam, cot giam
    while(c >= 0 && d >= 0){
        if(diemsher < n[c][d]){
            diemsher = n[c][d];
        }
        c--;
        d--;
    }
    // hang tang, cot giam
    while(e <  10 && f >= 0){
        if(diemsher < n[e][f]){
            diemsher = n[e][f];
        }
        e++;
        d--;
    }
    // hang giam, cot tang
    while(g >= 0 && h < 10){
        if(diemsher < n[g][h]){
            diemsher = n[g][h];
        }
        g--;
        h++;
    }
    float tamexp1 = EXP1, tamexp2 = EXP2;
    float tamhp1 = HP1, tamhp2 = HP2;
    if(abs(n[demi][demj]) > diemsher){
        EXP1 = EXP1 - floor(tamexp1 * 12 / 100);
        HP1 = HP1 -  floor(tamhp1 * 10 / 100);
        EXP2 = EXP2 - floor(tamexp2 * 12 / 100);
        HP2 = HP2 -  floor(tamhp2 * 10 / 100);
        ktexp(EXP1);
        kthp(HP1);
        ktexp(EXP2);
        kthp(HP2);
        return n[demi][demj];
    }
    else{
        EXP1 = EXP1 + ceil(tamexp1 * 12 / 100);
        HP1 = HP1 + ceil(tamhp2 * 10 / 100);
        EXP2 = EXP2 + ceil(tamexp2 * 12 / 100);
        HP2 = HP2 + ceil(tamhp2 * 10 / 100);
        ktexp(EXP1);
        kthp(HP1);
        ktexp(EXP2);
        kthp(HP2);
        return diemsher;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S = s, Email = email;
    int tmp = 0;
    char c = '@';
    for(int i = 0; i < Email.length(); i++){
        if(Email[i] == c){
            break;
        }
        else tmp++;
    }
    string se = Email.substr(0,tmp);

    if(S.length() < 8){
        return -1;
    }
    else if(S.length() > 20){
        return -2;
    }
    else{
        for(int k = 0; k <= S.length(); k++){
            int h = S[k];
            if(S.substr(k,tmp) == se){
                return -(300 + k);
            }
            else if((S[k] == S[k + 1]) == S[k + 2]) {
                return -(400+k);
            }
            else if(S[k] == '@' || S[k] == '#' || S[k] == '%' || S[k] == '$' || S[k] == '!'){
                return -5;
            }
            else if(h > 122 || ((h > 80) && (h < 97)) || h > 57 && h < 64 ||((h < 48) && (h != 33) && (h != 35) && (h != 36) && (h != 37) &&(h != 0))){
                return k;
            }
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    string strphu[num_pwds];
    int arr[num_pwds] = {0};
    for(int i = 0; i < num_pwds; i++){
        for(int j = i; j < num_pwds; j++){
            if(arr_pwds[i] == arr_pwds[j]){
                arr[i] = arr[i] + 1;
            }
        }
    }

    int max = arr[0];
    for(int k = 1; k < num_pwds; k++){
        if(arr[k] > max){
            max = arr[k];
        }
    }
    
    for(int h = 0; h < num_pwds; h++){
        if(arr[h] == max){
            strphu[h] = arr_pwds[h];
        }
    }
    string dainhat = strphu[0];
    int hungyeunhi = 0;
    for(int l = 1; l < num_pwds; l++){
        if(strphu[l].length() > dainhat.length()){
            dainhat = strphu[l];
        }
    }
    for(int n = 0; n < num_pwds; n++){
        if(arr_pwds[n] == dainhat){
            hungyeunhi = n;
            break;
        }
    }
    return hungyeunhi;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////