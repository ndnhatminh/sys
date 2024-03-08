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
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if (e1 < 4){
        if (e1 == 0) exp2 += 29;
        if (e1 == 1) exp2 += 45;
        if (e1 == 2) exp2 += 75;
        if (e1 == 3) exp2 += 29 + 45 + 75;
        int d = e1*3 + exp1*7;
        if (d%2) exp1 -= d/100;
        else exp1 += (d%100 == 0? d/200: d/200 + 1);
    }
    else {
        if (e1 < 20) exp2 += 19 + (e1%4 == 0? e1/4: e1/4 + 1);
        else if (e1 < 50) exp2 += 21 + (e1%9 == 0? e1/9: e1/9 + 1);
        else if (e1 < 66) exp2 += 17 + (e1%16 == 0? e1/16: e1/16 + 1);
        else if (e1 < 80) {
            exp2 += 19 + (e1%4 == 0? e1/4: e1/4 + 1);
            if (exp2 > 200) exp2 += 21 + (e1%9 == 0? e1/9: e1/9 + 1);
        }
        else{
            exp2 += 19 + (e1%4 == 0? e1/4: e1/4 + 1);
            exp2 += 21 + (e1%9 == 0? e1/9: e1/9 + 1);
            if (exp2 > 400) {
                exp2 += 17 + (e1%16 == 0? e1/16: e1/16 + 1);
                exp2 += (exp2%20 == 0? exp2*3/20: exp2*3/20 + 1); 
            }
        }
        exp1 -= e1;
    }
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    //road 1
    int s1 = sqrt(EXP1), s2 = s1 + 1;
    s1 *= s1; s2*=s2;
    float P1 = 0;
    if (s2 - EXP1 > EXP1 - s1) P1 = 1;
    else P1 = float(EXP1/s2 + 80)/123;
    
    // road 2
    if (E2%2){
        int m = M1/2, spend = 0;
        while (spend <= m){
            if (HP1 < 200){
                M1 -= 150;
                spend += 150;
                HP1 = (HP1%10 == 0? HP1*13/10: HP1*13/10 + 1);
            }
            else {
                M1 -= 70;
                spend += 70;
                HP1 = (HP1%10 == 0? HP1*11/10: HP1*11/10 + 1);
            }
        if (spend > m) break;
            if (EXP1 < 400) {
                M1 -= 200;
                spend += 200;
            }
            else {
                M1 -= 120;
                spend += 120;
            }
            EXP1 = (EXP1%100 == 0? EXP1*113/100: EXP1*113/100 + 1);
        if (spend > m) break;
            if (EXP1 < 300){
                M1 -= 100;
                spend += 100;
            }
            else {
                M1 -= 120;
                spend += 120;
            }
            if (EXP1 > 600) EXP1 = 600;
            EXP1 = (EXP1%10 == 0? EXP1*9/10: EXP1*9/10 + 1);
        }
    }
    else {
        if (HP1 < 200){
            M1 -= 150;
            HP1 = (HP1%10 == 0? HP1*13/10: HP1*13/10 + 1);
        }
        else {
            M1 -= 70;
            HP1 = (HP1%10 == 0? HP1*11/10: HP1*11/10 + 1);
        }
    if (M1 <= 0) goto endofEven;
        if (EXP1 < 400) {
            M1 -= 200;
        }
        else {
            M1 -= 120;
        }
        EXP1 = (EXP1%100 == 0? EXP1*113/100: EXP1*113/100 + 1);
    if (M1 <= 0) goto endofEven;
        if (EXP1 < 300){
            M1 -= 100;
        }
        else {
            M1 -= 120;
        }
        if (EXP1 > 600) EXP1 = 600;
        EXP1 = (EXP1%10 == 0? EXP1*9/10: EXP1*9/10 + 1);
	endofEven: if (M1 <= 0) M1 = 0;
    }
    if (HP1 > 666) HP1 = 666;
    HP1 = (HP1%100 == 0? HP1*83/100: HP1*83/100 + 1);
    EXP1 = (EXP1%100 == 0? EXP1*117/100: EXP1*117/100 + 1);
    if (EXP1 > 600) EXP1 = 600;
    s1 = sqrt(EXP1); s2 = s1 + 1;
    s1 *= s1; s2*=s2;
    float P2 = 0;
    if (s2 - EXP1 > EXP1 - s1) P2 = 1;
    else P2 = float(EXP1/s2 + 80)/123;
    
    // road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3 = 0;
    s2 = (E2/10 + E2%10)%10;
    P3 = float(P[s2])/100;
    
    // conclusion
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = (EXP1%4 == 0? EXP1*3/4: EXP1*3/4 + 1);
    if ((P1+P2+P3)*2/3 < 1) {
        HP1 = (HP1%20 == 0? HP1*17/20: HP1*17/20 + 1);
        EXP1 = (EXP1%20 == 0? EXP1*23/20: EXP1*23/20 + 1);
    }
    else{
        HP1 = (HP1%10 == 0? HP1*9/10: HP1*9/10 + 1);
        EXP1 = (EXP1%5 == 0? EXP1*6/5: EXP1*6/5 + 1);
    }
    if (EXP1 > 600) EXP1 = 600;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    
    // j = 0
    int i = 9 - int(sqrt(E3));
    // j = 1
    i += 9 - int(sqrt(float(E3)*3/2 + float(E3 - 2)*(E3 - 2)/16) - float(E3 - 2)/4);
    // j = [2,8]
    i += (7 + 1)/2*7;
    i = i/10 + i%10;
    i = i/10 + i%10;
    
    int j = 8;
    int taxis = (E3*j + 2*i)*(i - j); if (i == 9) return taxis;

    // sherlock
    int sherlock;
    if (E3 > 2){
        float a = -float(2*(E3*j + 2*i) + (2 - E3)*(i - j))/4/(2 - E3);
        sherlock = a;
        if (sherlock != a){
            a = (a < 0? sherlock - 1: sherlock + 1);
        }
        if (a > 0){
            if (i + sherlock > 9){
                a = sherlock = 9 - i;
            }
            if (j - sherlock < 0){
                a = sherlock = j;
            }
        }
        else if (a < 0){
            if (i + sherlock < 0) {
                a = sherlock = -i;
            }
            if (j - sherlock > 9) a = sherlock = j - 9;
        }
        sherlock = (E3*(j-sherlock) + 2*(i+sherlock))*(i - j + 2*sherlock);
        a = (E3*(j-a) + 2*(i+a))*(i - j + 2*a);
        if (sherlock < a) sherlock = a;
    }
    if (E3 == 2){
        sherlock = 9 - i;
        if (j - sherlock < 0) sherlock = j;
        sherlock = (E3*(j-sherlock) + 2*(i+sherlock))*(i - j + 2*sherlock);
    }
    if (E3 < 2){
        float a = -float(2*(E3*j + 2*i) + (2 - E3)*(i - j))/4/(2 - E3);
        if (a < 0){
            sherlock = 9 - i;
            if (j - sherlock < 0) sherlock = j;
        }
        else if (a > 0){
            sherlock = -i;
            if (j - sherlock > 9) sherlock = j - 9;
        }
        else sherlock = 0;
        sherlock = (E3*(j-sherlock) + 2*(i+sherlock))*(i - j + 2*sherlock);
    }
    if (abs(taxis) > sherlock){
        HP1 -= HP1/10; if (HP1 < 0) HP1 = 0;
        EXP1 -= EXP1*3/25; if (EXP1 < 0) EXP1 = 0;
        HP2 -= HP2/10; if (HP2 < 0) HP2 = 0;
        EXP2 -= EXP2*3/25; if (EXP2 < 0) EXP2 = 0;
        return taxis;
    }
    HP1 += (HP1%10 == 0? HP1/10: HP1/10 + 1); if (HP1 > 666) HP1 = 666;
    EXP1 += (EXP1%25 == 0? EXP1*3/25: EXP1*3/25 + 1); if (EXP1 > 600) HP1 = 600;
    HP2 += (HP2%10 == 0? HP2/10: HP2/10 + 1); if (HP2 > 666) HP2 = 666;
    EXP2 += (EXP2%25 == 0? EXP2*3/25: EXP2*3/25 + 1); if (EXP2 > 600) HP1 = 600;
    return sherlock;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8)  return -1;
    if (strlen(s) > 20) return -2;
    // check for se in s
    string se;
    for (const char *c = email; *c != '@'; c++) se += c[0];
    for (const char *str = s; *str != '\0'; str++){
        char *se0 = &se[0];
        for (const char *c = str; *c == *se0; c++) se0++;
        if (*se0 == '\0') return -(300 + str - s);
    }
    // check for c > 2 in s
    for (const char *str = s; *str != '\0'; str++){
        if (*str == *(str + 1)){
            str++; if (*str == *(str + 1)) return -(400 + str - 1 - s);
        }
    }
    // check for special c in s
    for (const char *str = s; ; str++){
        if (*str == '@' || *str == '#' || *str == '%' || *str == '$' || *str == '!') break;
        if (*str == '\0') return -5;
    }
    // check for valid c in s
    for (const char *str = s; *str != '\0'; str++){
        bool b = *str >= 'A' && *str <= 'Z'||*str >= 'a' && *str <= 'z'||*str >= '0' && *str <= '9'
            ||*str == '@'||*str == '#'||*str == '%'||*str == '$'||*str == '!';
        if (!b) return str - s;
    }
    // pass is valid and return
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    int max_appear = 1, max_len = 0, pos = 0;
    bool *appeared = new bool[num_pwds];
    for (int i = 0; i < num_pwds; i++){
        // if i's appeared, skip
        if (appeared[i] == true) continue;
        
        // if i's not appeared, check its appearance and length
        int appear = 1, len = 0;
        const char *str = arr_pwds[i]; //cout << s << endl;
        
        // check rep/appearance
        for (int j = i + 1; j < num_pwds; j++){
            // if j's appeared, skip
            if (appeared[j] == true) continue;
            
            // if j has not, check matching
            const char *c = arr_pwds[j]; //cout << c;
            const char *s = str;
            while (*c != '\0' && *c == *s){
                c++; s++;
            }
            
            // if matched, appear+1, find length of i, mark its appearance
            if (*c == *s){
                appear++;
                appeared[j] = 1;
                if (len == 0) len = s - str;
            }
        }
        // check for more appearance/rep
        if (appear > max_appear){
            max_appear = appear; max_len = len; pos = i;
        }
        
        // check for max length
        else if (appear == max_appear){
            // if appear = 1
            if(len == 0) while (*str != '\0'){
                len++; str++;
            }
            
            if (len > max_len){
                max_len = len; pos = i;
            }
        }
    }
    delete []appeared;
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////