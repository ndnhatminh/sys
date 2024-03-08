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

int checkExp(int exp){
    if (exp > 600) return 600;
    if (exp < 0) return 0;
    return exp;
}

int checkHp(int hp){
    if (hp > 666) return 666;
    if (hp < 0) return 0;
    return hp;
}

int checkM(int M){
    if (M<0) return 0;
    if (M>3000) return 3000;
    return M;
}

bool checkE(int E){
    if (E >= 0 && E<=99) return true;
    else return false;
}

// Task 1 
int firstMeet(int & exp1, int & exp2, int e1) {
    if (!checkE(e1)) return -99;
    exp1 = checkExp(exp1);
    exp2 = checkExp(exp2);

    //TH1 [0;3]
    if (0 <= e1 && e1 <= 3){
        switch (e1){
            case 0: 
                exp2+=29;
                break;
            case 1: 
                exp2+=45;
                break;
            case 2:
                exp2+=75;
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
                break;
        }
        exp2 = checkExp(exp2);
        exp1 = checkExp(exp1);

        int D = e1*3 + exp1*7;
        if (D % 2 == 0) exp1+= ceil(D*1.0/200);
        if (D % 2 == 1) exp1 = ceil(exp1 - D*1.0/100);
        exp1 = checkExp(exp1);
        return exp1 + exp2;
    } 

   //TH2 [4;99]
    if (4 <= e1 && e1 <= 19) exp2 = exp2 + ceil((double) e1/4 + 19);
    if (20 <= e1 && e1 <= 49) exp2 = exp2 + ceil((double) e1/9 + 21);
    if (50 <= e1 && e1 <= 65) exp2 = exp2 + ceil((double) e1/16 + 17);
    if (66 <= e1 && e1 <= 79) {
        exp2 = exp2 + ceil((double) e1/4 + 19);
        exp2 = ceil(exp2);
        if (exp2 > 200) exp2+= ceil((double) e1/9 + 21);
    }
    if (80 <= e1 && e1 <= 99) {
        exp2+= ceil((double) e1/4 + 19);
        exp2+= ceil((double) e1/9 + 21);
        if (exp2 > 400){
            exp2+= ceil((double) e1/16 + 17);
            exp2 = ceil(exp2 + 0.15*exp2);
            }
        }
    exp2 = checkExp(exp2);

    exp1 -= e1;
    exp1 = checkExp(exp1);
    return exp1 + exp2;
}

// Task 2
double calP(int exp){  //calculate P of street 1 and 2
    int s = round(sqrt(exp))*round(sqrt(exp));
    if (exp >= s) return 1;
    else return ((double)exp/s + 80)/123;
}

int sumself(int a){ //calculate sum of each number in a
    int sum = 0;
    while (a!=0){
        sum += a%10;
        a = a/10;
    }
    return sum;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (!checkE(E2)) return -99;
    EXP1 = checkExp(EXP1);
    HP1 = checkHp(HP1);
    M1 = checkM(M1);


    //Street 1
    double P1 = calP(EXP1);

    //Street 2
    double limit = M1/2;
    if (E2%2 != 0){
        while (true){
            if (M1 == 0) break;

            //part 1
            if (HP1 < 200){
                HP1 = ceil(HP1 + 0.3*HP1);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1 + 0.1*HP1);
                M1 -= 70; 
            }
            HP1 = checkHp(HP1);
            if (M1 < limit) break;
            
            //part 2
            if (EXP1 < 400) M1 -= 200;
            else  M1 -= 120;
            EXP1 = ceil(EXP1 + 0.13*EXP1);
            EXP1 = checkExp(EXP1);
            if (M1 < limit) break;    
            
            //part 3
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(EXP1*0.9);
            EXP1 = checkExp(EXP1);
            if (M1 < limit) break;
        }
    }
    else {
        while (true){
            if (M1 <= 0) break;
            
             //part 1
            if (HP1 < 200){
                HP1 = ceil(HP1 + 0.3*HP1);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1 + 0.1*HP1);
                M1 -= 70; 
            }
            HP1 = checkHp(HP1);
            if (M1 <= 0) break;

            //part 2
            if (EXP1 < 400) M1 -= 200;
            else  M1 -= 120;
            EXP1 = ceil(EXP1 + EXP1*0.13);
            EXP1 = checkExp(EXP1);
            if (M1 <= 0) break;
            
            //part 3
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(EXP1*0.9);
            EXP1 = checkExp(EXP1);
            break;
        }    
    }
    M1 = checkM(M1);

    HP1 = ceil(HP1*0.83);
    EXP1 = ceil(EXP1 + EXP1*0.17);
    EXP1 = checkExp(EXP1);
    double P2 = calP(EXP1);

    //Street 3
    int P[11] = {32,47,28,79,100,50,22,83,64,11};
    int i;
    if (E2 < 10) i = E2;
    else {
        i = sumself(E2);
        if (i >= 10) i = i%10;
    }
    double P3 = P[i];
    P3 = P3/100;

    //conclusion
    double Ptb = (P1 + P2 + P3)/3;
    if (Ptb == 1) EXP1 = ceil(EXP1*0.75);
    else if (Ptb < 0.5){
        HP1 = ceil(HP1*0.85);
        EXP1 = ceil(EXP1 + EXP1*0.15);
    }
    else if (Ptb >= 0.5){
        HP1 = ceil(HP1*0.9);
        EXP1 = ceil(EXP1 + EXP1*0.2);
    }

    HP1 = checkHp(HP1);
    EXP1 = checkExp(EXP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int maxOf(int taxi[][10], int a, int b){
    int max = taxi[a][b];
    int A = a, B = b;

    while (true){ // left down
        if (a == 0 || b == 0) break;
        a--;
        b--;
        if (max < taxi[a][b]) max = taxi[a][b];   
    }

    a = A; b = B;
    while (true){ // left up
        if (a == 9 || b == 9) break;
        a++;
        b++;
        if (max < taxi[a][b]) max = taxi[a][b];  
    }

    a = A; b = B;
    while (true){ // right down
        if (a == 9 || b == 0) break;
        a++;
        b--;
        if (max < taxi[a][b]) max = taxi[a][b];
    }

    a = A; b = B;
    while (true){ // right up
        if (a == 0 || b == 9) break;
        a--;
        b++;
        if (max < taxi[a][b]) max = taxi[a][b];
    }

    if (max > 0) return max;
    else return -max;
}

int checkIJ(int i){
    while (true){
        if (i<10) return i;
        i = sumself(i);
    }
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (!checkE(E3)) return -99;
    HP1 = checkHp(HP1);
    EXP1 = checkExp(EXP1);
    HP2 = checkHp(HP2);
    EXP2 = checkExp(EXP2);

    int taxi[10][10];
    int Vi = 0, Vj = 0;
    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            taxi[i][j] = ((E3*j) + (i*2))*(i-j);
            if (taxi[i][j] > (E3*2)) Vi++;
            if (taxi[i][j] < (-E3)) Vj++;
        }
    }

    Vi = checkIJ(Vi);
    Vj = checkIJ(Vj);
    int Sscore = maxOf(taxi, Vi, Vj);

    if (abs(taxi[Vi][Vj]) > Sscore) {
        EXP1 = checkExp(ceil(EXP1*0.88));
        HP1 = checkHp(ceil(HP1*0.9));
        EXP2 = checkExp(ceil(EXP2*0.88));
        HP2 = checkHp(ceil(HP2*0.9));
        return taxi[Vi][Vj];
    }
    else {
        EXP1 = checkExp(ceil(EXP1 + EXP1*0.12));
        HP1 = checkHp(ceil(HP1 + HP1*0.1));
        EXP2 = checkExp(ceil(EXP2 + EXP2*0.12));
        HP2 = checkHp(ceil(HP2 + HP2*0.1));
        return Sscore;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string S = string(s);
    string Email = string(email);
    string se;
    int x = 1;
    char kitu = 'a';

    for (char &c : Email){
        if (c == '@') break;
        else se+=c;  
    }

    //check size of S
    if (S.size() < 8) return -1;
    if (S.size() > 20) return -2;

    // check se in S
    if (S.find(se) != string::npos) return -(300+ S.find(se));

    //check 2 same char in S
    for (int i = 1; i < S.size() - 1; i++){
       if (S[i-1] == S[i] && S[i] == S[i+1])  return -(400 + i - 1);
    }

    // check first special char in S
    for (int i = 0; i < S.size(); i++){
        if (S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!') {
            kitu = S[i];
            break;
        }
    }
    if (kitu == 'a') return -5;

    for (int i = 0; i < S.size(); i++){
       if (S[i]!=33 && !(S[i]>=35 && S[i]<=37) && !(S[i]>=48 && S[i]<=57) && !(S[i]>=64 && S[i]<=90) && !(S[i]>=97 && S[i]<=122)){
        return i;
       }
    }
   return -10;
}

// Task 5 
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string ans[31];
    int hz[31];
    int dif = 1;
    for (int i=0; i <30; i++){
        hz[i] = 0;
        ans[i] = "o";
    }
   
    for (int i = 0; i < num_pwds; i++){
        bool flag = false;
        for (int j = 0; j < dif; j++){
            if (arr_pwds[i] == ans[j]) {
                hz[j]++;
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans[dif-1] = arr_pwds[i];
            hz[dif-1] ++;
            dif++;
        }        
    }

    string X = ans[0];
    int pasHz = hz[0];
    for (int i = 1; i < dif; i++){
        if (pasHz < hz[i] || (pasHz == hz[i] && X.size() < ans[i].size())) {
            pasHz = hz[i];
            X = ans[i];
        }
    }
    
    for (int i = 0; i < num_pwds; i++){
        if (arr_pwds[i] ==  X) return i;
    }
    return -99;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////