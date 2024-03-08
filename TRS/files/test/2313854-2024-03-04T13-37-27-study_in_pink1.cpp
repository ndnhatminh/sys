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
int HP_MIN = 0, HP_MAX = 666,
    EXP_MIN = 0, EXP_MAX = 600,
    M_MIN = 0, M_MAX = 3000,
    E_MIN = 0, E_MAX = 99;

int Check(int n, int Min, int Max) // dam bao khoang gia tri
{
    if(n < Min) return Min;
    if(n > Max) return Max;
    return n;
}

int Round_Up(float n) // EXP, HP, M1
{
    if((int)( n + 0.999) == (int)n+1)
        return n+1;
    return n;
}

float Cal_P(int n) // tinh xac suat
{
    int k = round(sqrt(n));
    int S = k*k;
    if(n >= S) return 100;
    return (n*1.0/S + 80)/123*100;
}

int trans(int n) // chuyen thanh 1cs
{
    if(n < 10) return n;
    int k = 0;
    while(n > 0){
        k += n%10;
        n/=10;
    }
    return trans(k);
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if((e1 < E_MIN) || (e1 > E_MAX)) return -99;
    exp1 = Check(exp1, EXP_MIN, EXP_MAX);
    exp2 = Check(exp2, EXP_MIN, EXP_MAX);
// TH1:
    if( (0 <= e1) && (e1 <= 3)){
        int   info1 = 29,
              info2 = 45,
              info3 = 75,
              info4 = info1 + info2 + info3;

        if(e1 == 0) exp2 += info1;
        else if(e1 == 1) exp2 += info2;
        else if(e1 == 2) exp2 += info3;
        else exp2 += info4;

        int D = e1*3 + exp1*7;

        if(D%2 == 0) exp1 += Round_Up(D*1.0/200);
        else exp1 = Round_Up(exp1*1.0 - D*1.0/100);
    }
// TH2:
    else{
        float   info1 = e1*1.0/4 + 19,
                info2 = e1*1.0/9 + 21,
                info3 = e1*1.0/16 + 17;

        if(e1 <= 19) exp2 += Round_Up(info1);
        else if(e1 <= 49) exp2 += Round_Up(info2);
        else if(e1 <= 65) exp2 += Round_Up(info3);
        else if(e1 <= 79){
            exp2 += Round_Up(info1);
            if(exp2 > 200) exp2 += Round_Up(info2);
        }
        else{
            exp2 += Round_Up(info1);
            exp2 += Round_Up(info2);
            if(exp2 > 400){
                exp2 += Round_Up(info3);
                exp2 = Round_Up(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }

    exp1 = Check(exp1, EXP_MIN, EXP_MAX);
    exp2 = Check(exp2, EXP_MIN, EXP_MAX);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if((E2 < E_MIN) || (E2 > E_MAX)) return -99;
    HP1 = Check(HP1, HP_MIN, HP_MAX);
    EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);
    M1 = Check(M1, M_MIN, M_MAX);
//way1:
    float P1 = Cal_P(EXP1);
//way2:
    float P2;
    float pivot = M1*0.5;

    if(E2 % 2 == 1){
        int cost = 0;
        bool dk = 1;
        while(dk){
            if(M1 == 0) break;
    //STEP1:
            if(HP1 < 200){
                HP1 = Round_Up( HP1 * 1.3);
                M1 -= 150;
                cost += 150;
            }
            else{
                HP1 = Round_Up(HP1 * 1.1);
                M1 -= 70;
                cost += 70;
            }
        //CHECK:
            HP1 = Check(HP1, HP_MIN, HP_MAX);
            M1 = Check(M1, M_MIN, M_MAX);

            if(cost > pivot){
                dk = 0;
                continue;
            }
    //STEP2:
            if(EXP1 < 400){
                M1 -= 200;
                cost += 200;
            }
            else{
                M1 -= 120;
                cost += 120;
            }
            EXP1 = Round_Up(EXP1 * 1.13);
        //CHECK:
            M1 = Check(M1, M_MIN, M_MAX);
            EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);

            if(cost > pivot){
                dk = 0;
                continue;
            }
    //STEP3:
            if(EXP1 < 300){
                M1 -= 100;
                cost += 100;
            }
            else{
                M1 -= 120;
                cost += 120;
            }
            EXP1 = Round_Up(EXP1 * 0.9);
        //CHECK:
            M1 = Check(M1, M_MIN, M_MAX);
            EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);

            if(cost > pivot){
                dk = 0;
                continue;
            }
        }
    }
    else{
        bool dk = 1;
        while(dk){
            if(M1 == 0) break;
    //STEP1:
            if(HP1 < 200){
                HP1 = Round_Up( HP1 * 1.3);
                M1 -= 150;
            }
            else{
                HP1 = Round_Up(HP1 * 1.1);
                M1 -= 70;
            }
        //CHECK:
            HP1 = Check(HP1, HP_MIN, HP_MAX);
            M1 = Check(M1, M_MIN, M_MAX);

            if(M1 == 0){
                dk = 0;
                continue;
            }
    //STEP2:
            if(EXP1 < 400)  M1 -= 200;
            else            M1 -= 120;
            EXP1 = Round_Up(EXP1 * 1.13);
        //CHECK:
            M1 = Check(M1, M_MIN, M_MAX);
            EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);

            if(M1 == 0){
                dk = 0;
                continue;
            }
    //STEP3:
            if(EXP1 < 300)  M1 -= 100;
            else            M1 -= 120;
            EXP1 = Round_Up(EXP1 * 0.9);
        //CHECK:
            M1 = Check(M1, M_MIN, M_MAX);

            dk = 0;
        }
    }
    HP1 = Round_Up(HP1 * 0.83);
    EXP1 = Round_Up(EXP1 * 1.17);

    HP1 = Check(HP1, HP_MIN, HP_MAX);
    EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);

    P2 = Cal_P(EXP1);
//way3:
    float P3;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    int k = E2%10 + E2/10;
    P3 = P[k%10];
//last:
    if((P1 == 100) && (P2 == 100) && (P3 == 100))
        EXP1 = Round_Up(EXP1 * 0.75);
    else{
        float tb = (P1 + P2 + P3)/3.0;
        if(tb < 50){
            HP1 = Round_Up(HP1 * 0.85);
            EXP1 = Round_Up(EXP1 * 1.15);
        }
        else{
            HP1 = Round_Up(HP1 * 0.9);
            EXP1 = Round_Up(EXP1 * 1.2);
        }
    }
    HP1 = Check(HP1, HP_MIN, HP_MAX);
    EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);
    M1 = Check(M1, M_MIN, M_MAX);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < E_MIN || E3 > E_MAX) return -99;
    HP1 = Check(HP1, HP_MIN, HP_MAX);
    EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);
    HP2 = Check(HP2, HP_MIN, HP_MAX);
    EXP2 = Check(EXP2, EXP_MIN, EXP_MAX);

    int maxN = 10;
    int a[maxN][maxN];
    int dk_i = E3 * 2,  // >
        dk_j = -E3,     // <
        count_i = 0,
        count_j = 0;

    for(int i = 0; i < maxN; i++){
        for(int j = 0; j < maxN; j++){
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(a[i][j] > dk_i) count_i++;
            if(a[i][j] < dk_j) count_j++;
        }
    }
    int h = trans(count_i),
        c = trans(count_j),
        taxi = a[h][c],
        nguoi;
// trace_left:
    //tren: hang dau, cot cuoi
    if(c > h){
        int i = 0,
            j = c - h;

        nguoi = a[i][j];
        while(j < 9)
            nguoi = max(nguoi, a[++i][++j]);
    }
    //duoi: cot dau, hang cuoi
    else{
        int i = h - c,
            j = 0;

        nguoi = a[i][j];
        while(i < 9)
            nguoi = max(nguoi, a[++i][++j]);
    }
//trace_right:
    //tren: hang dau, cot dau
    if(h < (9 - c)){
        int i = h + c,
            j = 0;
        nguoi = max(nguoi, a[i][j]);
        while(i > 0)
            nguoi = max(nguoi, a[--i][++j]);
    }
    //duoi: hang cuoi, cot cuoi
    else{
        int i = 9,
            j = c - (9 - h);
        nguoi = max(nguoi, a[i][j]);
        while(j < 9)
            nguoi = max(nguoi, a[--i][++j]);
    }
    if(nguoi < 0) nguoi = -nguoi;

    bool dk = 0;
    if(abs(taxi) > nguoi){
        EXP1 = Round_Up(EXP1*0.88);
        HP1 = Round_Up(HP1*0.9);
        EXP2 = Round_Up(EXP2*0.88);
        HP2 = Round_Up(HP2*0.9);
        dk = 0;
    }
    else{
        EXP1 = Round_Up(EXP1*1.12);
        HP1 = Round_Up(HP1*1.1);
        EXP2 = Round_Up(EXP2*1.12);
        HP2 = Round_Up(HP2*1.1);
        dk = 1;
    }
    EXP1 = Check(EXP1, EXP_MIN, EXP_MAX);
    HP1 = Check(HP1, HP_MIN, HP_MAX);
    EXP2 = Check(EXP2, EXP_MIN, EXP_MAX);
    HP2 = Check(HP2, HP_MIN, HP_MAX);
    if(!dk) return taxi;
    else return nguoi;
    //return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string Email(email);
    string S(s);
    string se;
    int L_se = 0;

    for(int i = 0; i < Email.size(); i++){
        if(Email[i] == '@') break;
        se += Email[i];
        L_se++;
    }

    if(S.size() < 8) return -1;
    if(S.size() > 20) return -2;

    bool dk = 0;
    if(L_se == 0) return -300;
    else if(S.size() < se.size());
    else
    for(int  i = 0; i <= S.size() - se.size(); i++){
        if(S[i] == se[0]){
            dk = true;
            int j = i + 1;
            for(int k = 1; k < se.size(); k++){
                if(S[j] != se[k]) {
                    dk = 0;
                    break;
                }
                j++;
            }
            if(dk){
                int sei = i;
                return -(300 + sei);
            }
        }
    }

    dk = 0;
    int dem[S.size()];
    dem[0] = 1;
    for(int i = 1; i < S.size(); i++){
        if(S[i] == S[i-1]){
            dem[i] = dem[i-1] + 1;
        }
        else dem[i] = 1;
        if(dem[i] == 3){
            int sci = i - 2;
            return -(400 + sci);
        }
    }

    dk = 0;
    for(int i = 0; i < S.size(); i++){
        if((S[i] == '@') ||
           (S[i] == '#') ||
           (S[i] == '%') ||
           (S[i] == '$') ||
           (S[i] == '!'))
            dk = true;
    }
    if(!dk) return -5;

    dk = 0;
    for(int i = 0; i < S.size(); i++){
        dk = 0;
        if(('a' <= S[i]) && (S[i] <= 'z')) dk = true;
        if(('A' <= S[i]) && (S[i] <= 'Z')) dk = true;
        if(('0' <= S[i]) && (S[i] <= '9')) dk = true;
        if((S[i] == '@') ||
           (S[i] == '#') ||
           (S[i] == '%') ||
           (S[i] == '$') ||
           (S[i] == '!') )
            dk = true;
        if(!dk) return i;
    }

    return -10;
    //return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int dem[num_pwds] = {};
    for(int i = 0; i < num_pwds; i++) dem[i] = 0;
    int res, C_mx = -1, Count, L_mx = -1, Len;

    for(int i = 0; i < num_pwds; i++){
        if(dem[i]) continue;
        Count = 1;
        string s0(arr_pwds[i]);
        for(int j = i+1; j < num_pwds; j++){
            string s1(arr_pwds[j]);
            if(s0 == s1){
                Count++;
                dem[j] = 1;
            }
        }
        dem[i] = Count;
        C_mx = max(C_mx, Count);
    }
    for(int i = 0; i < num_pwds; i++){
        if(dem[i] == C_mx){
            Len = strlen(arr_pwds[i]);
            if(Len > L_mx){
                L_mx = Len;
                res = i;
            }
        }
    }
    return res;
    //return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
