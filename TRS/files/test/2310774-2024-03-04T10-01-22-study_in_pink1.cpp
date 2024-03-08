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

//Another Function
int fixEXP(int & exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
    return exp;
}
int fixHP(int & hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
    return hp;
}

int fixMoney(int & m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
    return m;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int sum_number(int n) {
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n /= 10;
    }
    if (sum > 9 ) return sum_number(sum);
    return sum;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    fixEXP(exp1); fixEXP(exp2);
    if (e1 > 99 || e1 < 0) return -99;
    
    //CASE 1: E1 = [0,3]
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        if (e1 == 1) exp2 += 45;
        if (e1 == 2) exp2 += 75;
        if (e1 == 3) exp2 += 149;
        int D = e1*3 + exp1*7;
        if (D % 2 == 0) exp1 = ceil(exp1 + (double)D/200 - 1e-6);
        else exp1 = ceil(exp1 - (double)D/100 - 1e-6);

        fixEXP(exp1); fixEXP(exp2);
    }

    //CASE 2: E1 = [4,99]
    if (e1 >= 4 && e1 <=99) {
        if (e1 <= 19) exp2 = ceil(exp2 + (double)e1/4 + 19 - 1e-6); // [4,19]
        else if (e1 <= 49) exp2 = ceil(exp2 + (double)e1/9 + 21 - 1e-6); // [20,49]
        else if (e1 <= 65) exp2 = ceil(exp2 + (double)e1/16 + 17 - 1e-6); // [50,65]
        else if (e1 <= 79) { // [66,79]
            exp2 = ceil(exp2 + (double)e1/4 + 19 - 1e-6);
            fixEXP(exp2);
            if (exp2 > 200) exp2 = ceil(exp2 + (double)e1/9 + 21 - 1e-6);
            fixEXP(exp2);
        }

        else if (e1 <= 99) { // [80,99]
            exp2 = ceil(exp2 + (double)e1/4 + 19 - 1e-6);
            exp2 = ceil(exp2 + (double)e1/9 + 21 - 1e-6);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (double)e1/16 + 17 - 1e-6);
                fixEXP(exp2);
                exp2 = ceil(exp2*1.15 - 1e-6); // Cong them 15% neu giai thich 3 thong thong tin
            }
        }
        fixEXP(exp1); fixEXP(exp2);
        exp1 -= e1;
    }
    fixEXP(exp1); fixEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    fixEXP(EXP1); fixHP(HP1); fixMoney(M1);
    if (E2 > 99 || E2 < 0) return -99;

    //Solution
    float P1 = 100, P2 = 100, P3 = 100;
        //Way 1
        int num1 = round(sqrt(EXP1));
        int S1 = num1*num1;
        if (EXP1 >= S1) P1 = 100;
        else P1 = ((EXP1/S1 + 80)/1.23);

        // Way 2
        int spend = 0, money = M1/2;
        do {
            if (HP1 < 200) { //1
                    HP1 = ceil(HP1*1.3 - 1e-6);
                    M1 -= 150; spend += 150;
                }
                else {
                    HP1 = ceil(HP1*1.1 - 1e-6);
                    M1 -= 70; spend += 70;
                }
                fixHP(HP1); fixMoney(M1);
                if (((E2 % 2 != 0) && spend > money) || ((E2 % 2 == 0) && M1 == 0)) break;

            if (EXP1 < 400) { M1 -= 200; spend += 200; } //2
                else { M1 -= 120; spend += 120;}
                EXP1 = ceil(EXP1*1.13 - 1e-6);
                fixEXP(EXP1); fixMoney(M1);
                if (((E2 % 2 != 0) && spend > money) || ((E2 % 2 == 0) && M1 == 0)) break;
               
            
            if (EXP1 < 300) { M1 -= 100; spend += 100; } //3
                else { M1 -= 120; spend += 120; }
                EXP1 = ceil(EXP1*0.9 - 1e-6);
                fixEXP(EXP1); fixMoney(M1);
                if (((E2 % 2 != 0) && spend > money) || ((E2 % 2 == 0) && M1 == 0)) break;

        } while(E2 % 2 != 0);


        HP1 = ceil(HP1*0.83 - 1e-6); EXP1 = ceil(EXP1*1.17 - 1e-6);
        fixEXP(EXP1); fixHP(HP1);

        int num2 = round(sqrt(EXP1));
        int S2 = num2*num2;
        if (EXP1 >= S2) P2 = 100;
        else P2 = ((EXP1/S2) + 80)/1.23;

        //Way 3
        int P[10] = {32,47,28,79,100,50,22,83,64,11};
        int idx = 0, s = 0;
        while (E2 != 0) {
            s += E2%10;
            E2 /= 10;
        }
        idx = s%10;
        P3 = P[idx];
    

    //-----------------------------------------------------------//
    float Pa = (P1 + P2 + P3) / 3;
    if (Pa == 100) EXP1 = ceil(EXP1*0.75 - 1e-6);
    else if (Pa < 50) {
        HP1 = ceil(HP1*0.85 - 1e-6);
        EXP1 = ceil(EXP1*1.15 - 1e-6);
    }
    else {
        HP1 = ceil(HP1*0.9 - 1e-6);
        EXP1 = ceil(EXP1*1.2 - 1e-6);
    }
    fixEXP(EXP1); fixHP(HP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
   // TODO: Complete this function
    fixEXP(EXP1); fixEXP(EXP2); fixHP(HP1); fixHP(HP2);
    if (E3 > 99 || E3 < 0) return -99;

    //Solution
    int map[10][10], pos = 0, neg = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++){
            map[i][j] = ((E3*j)+(i*2))*(i-j);
            if ((map[i][j] > 0) && (map[i][j] > E3*2)) pos++;
            if ((map[i][j] < 0) && (map[i][j] < E3*(-1))) neg++;
        }
    }

    int i = sum_number(pos);
    int j = sum_number(neg);
    
    int taxi_point = map[i][j];
    int point = 0;

    int max_val = map[i][j];
    int r = i, c = j;

    while(r <= 9 && c >= 0) {
        if (max_val < map[r][c]) max_val = map[r][c];
        r++; c--;
    }
    r = i, c = j;
    while(r >= 0 && c <= 9) {
        if (max_val < map[r][c]) max_val = map[r][c];
        r--; c++;
    }
    r = i, c = j;
    while(r <= 9 && c <= 9) {
        if (max_val < map[r][c]) max_val = map[r][c];
        ++r;++c;
    }
    r = i, c = j;
    while(r >= 0 && c >= 0) {
        if (max_val < map[r][c]) max_val = map[r][c];
        --r;--c;
    }

    if (abs(taxi_point) > max_val ) {
        HP1 = ceil(HP1*0.9 - 1e-6);
        HP2 = ceil(HP2*0.9 - 1e-6);
        EXP1 = ceil(EXP1*0.88 - 1e-6);
        EXP2 = ceil(EXP2*0.88 - 1e-6);
    }
    else {
        HP1 = ceil(HP1*1.10 - 1e-6);
        HP2 = ceil(HP2*1.10 - 1e-6);
        EXP1 = ceil(EXP1*1.12 - 1e-6);
        EXP2 = ceil(EXP2*1.12 - 1e-6);
    }
    fixEXP(EXP1); fixEXP(EXP2); fixHP(HP1); fixHP(HP2);

    if (abs(taxi_point) > abs(max_val)) return taxi_point;
    else return max_val;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S = s, Email = email;
    int t = Email.find('@');
    string se = Email.substr(0,t);
    
    if (S.size() < 8) return -1;
    if (S.size() > 20) return -2;
    
    if (se == "") return -300;
    int sei = S.find(se);
    if (sei > -1) return -(300 + sei);

    for(int i = 0; i < (S.size() - 2); i++) {
        if (S[i] == S[i+1] && S[i] == S[i+2]) return -(400 + i);
    }

    int c = 0;
    for(int i = 0; i < S.size(); i++) {
        if (S[i] == '%' || S[i] == '$' || S[i] == '#' || S[i] == '@' || S[i] =='!' ) c++;
    }
    if (c == 0) return -5;
    
    int pos = -1;
    for(int i = 0; i < S.size(); i++) {
        if (!((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z') || (S[i] >= '0' && S[i] <= '9') || (S[i] == '%' || S[i] == '$' || S[i] == '#' || S[i] == '@' || S[i] =='!' ))){
            pos = i; break;
        }
    }
    if (pos > -1) return pos;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string s[num_pwds];
    for(int i = 0; i < num_pwds; i++) {
        s[i] = arr_pwds[i];
    }
    int pos = 0, res = 0;
    for(int i = 0; i < num_pwds; i++) {
        int cnt = 0;
        if (checkPassword(arr_pwds[i],"-") == -10 ) {
            for(int j = i + 1; j < num_pwds; j++) {
                if (s[i].compare(s[j]) == 0) cnt++;
            }
        }
        if ((cnt == res) && (s[i].length() > s[pos].length())) pos = i;
        if (cnt > res) { res = cnt; pos = i;}
    }
    return pos;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////