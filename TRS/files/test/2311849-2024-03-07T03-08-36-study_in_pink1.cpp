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
void checkHP(int &HP){
    if (HP<0) HP=0;
    else if (HP>666) HP=666;
}
void checkEXP(int &EXP){
    if (EXP<0) EXP=0;
    else if (EXP>600) EXP=600;
}
void checkM(int &M){
    if (M<0) M=0;
    if (M>3000) M=3000;
}
void checkE(int E){
    if (E<0 || E>99) E=-99;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1){
    checkE(E1);
    if (E1<0 or E1>=100)return -99;
    //TH1
    else if (E1 >= 0 && E1 <= 3){
        if (E1 == 0){
            EXP2 += 29;
        }
        else if (E1 == 1){
            EXP2 += 45;
        }
        else if (E1 == 2){
            EXP2 += 75;
        }
        else if(E1==3){
            EXP2 += (29 + 45 + 75);
        }
        double D = E1*3 + EXP1*7,j=EXP1;
        int e=D;
        if (e%2 == 0) j = ceil(j+D/200);
        else j = ceil(j-D/100);
        if(j!=EXP1)EXP1=j;
        checkEXP(EXP1);checkEXP(EXP2);
        return EXP1 + EXP2;
    }
    //TH2
    else if (E1 >= 4 && E1 <= 19) EXP2 += ceil(E1/4.0 + 19);
    else if (E1 >= 20 && E1 <= 49) EXP2 += ceil(E1/9.0 + 21);
    else if (E1 >= 50 && E1 <= 65) EXP2 += ceil(E1/16.0 + 17);
    else if (E1 >= 66 && E1 <= 79){
        EXP2 += ceil(E1/4.0 + 19);
        if (EXP2 > 200) EXP2 += ceil(E1/9.0 + 21);
    }
    else if (E1 >= 80 && E1 <= 99){
        EXP2 += ceil(E1/4.0 + 19);
        EXP2 += ceil(E1/9.0 + 21);
        if (EXP2 > 400){
            EXP2 += ceil(E1/16.0 + 17);
            EXP2 = ceil(EXP2 * 1.15);
            if(EXP2 > 600) EXP2 = 600;
        }
    }
    EXP1 -= E1;
    checkEXP(EXP1);
    checkEXP(EXP2);

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    checkEXP(EXP1);checkHP(HP1);
    if(E2<0 or E2>99)return -99;
    // con duong 1
    int S = round(sqrt(EXP1)) * round(sqrt(EXP1));
    double P1;

    if (EXP1 >= S) P1 = 1.0;
    else P1 = (EXP1/S + 80.0)/123;

// con duong 2
    if (E2%2 != 0){
        double a=M1;
        while (a-float(M1) <= a/2) {
            if (HP1 < 200){
                HP1 = ceil(HP1 * 130.0/100);
                M1 -= 150;
                checkEXP(EXP1);checkHP(HP1);
            }
    else{
                HP1 = ceil( HP1 * 110.0/100);
                M1 -= 70;
                checkEXP(EXP1);checkHP(HP1);
            }

            if (a - float(M1) > a / 2) break;

            if (EXP1 < 400){
                M1 -= 200;
            }
            else{
                M1 -= 120;
            }
            EXP1 = ceil(113.0/100 * EXP1);
            checkEXP(EXP1);checkHP(HP1);

            if (a - float(M1) > a / 2) break;

            if (EXP1 < 300) {
                M1 -= 100;
            }
            else{
                M1 -= 120;
            }
            EXP1 = ceil(90.0/100 * EXP1);
            checkEXP(EXP1);checkHP(HP1);
        }
    }

    else{
        if (HP1 < 200){
            HP1 = ceil(HP1 * 130.0/100);
            M1 -= 150;
            checkEXP(EXP1);checkHP(HP1);checkM(M1);

        }
        else{
            HP1 = ceil( HP1 * 110.0/100);
            M1 -= 70;
            checkEXP(EXP1);checkHP(HP1);checkM(M1);
        }
        if(M1==0)goto IS;
        if (EXP1 < 400) M1 -= 200;
        else M1 -= 120;
        EXP1 = ceil(113.0/100 * EXP1);
        checkEXP(EXP1);checkHP(HP1);checkM(M1);
        if(M1==0)goto IS;
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        EXP1 = ceil(90.0/100 * EXP1);
        checkEXP(EXP1);checkHP(HP1);
        if (M1 < 0) M1 = 0;

    }
    IS:
        HP1 = ceil(HP1 * 83.0/100); checkHP(HP1);
        EXP1 = ceil(117.0/100 * EXP1);
        checkEXP(EXP1);checkHP(HP1);checkM(M1);
    int S2 = round(sqrt(EXP1)) * round(sqrt(EXP1));
    double P2;
    if (EXP1 >= S2) P2 = 1.0;
    else P2 = (EXP1/S2 + 80.0)/123.0;

    // con duong 3
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;
    if (E2 < 10) P3 = P[E2];
    else P3 = P[(E2%10 + E2/10) % 10];
    P3 *= 0.01;

    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(75.0/100 * EXP1);
    else {
        double average = (P1 + P2 + P3)/3;
        if (average < 50.0/100) {
            HP1=ceil(HP1*85.0/100);
            EXP1=ceil(EXP1*115.0/100);
            checkEXP(EXP1);checkHP(HP1);
        }
        else {
            HP1=ceil(HP1*90.0/100);
            EXP1=ceil(EXP1*120.0/100);
            checkEXP(EXP1);checkHP(HP1);
        }
    }
    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);

    return HP1 + EXP1 + M1;
}
// Task 3
void sum(int& s) {s = s % 10 + s / 10;}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    checkE(E3);
    if(E3 <0 or E3>99) return -99;

    int mapp[10][10];
    int ii = 0, jj = 0;

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            mapp[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(mapp[i][j] > E3 * 2) ii++;
            if(mapp[i][j] < -E3) jj++;}
    }
    while(ii > 9) sum(ii);
    while(jj > 9) sum(jj);
    int maxx = 0, t = ii, d = jj;
    while(t < 10 and d >= 0){
            if (mapp[t][d]> maxx)
        {maxx = mapp[t][d];}
        t++; d--;
    }
    t = ii, d = jj;
    while(t < 10 and d < 10){
        if(mapp[t][d]> maxx)
        {maxx = mapp[t][d];}
        t++; d++;
    }
    t = ii, d = jj;
    while (t >= 0 and d < 10){
        if (mapp[t][d]> maxx) maxx = mapp[t][d];
        t--; d++;
    }
    t = ii, d = jj;
    while (t >= 0 and d >= 0){
        if (mapp[t][d] > maxx)
        {maxx = mapp[t][d];}
        t--; d--;
    }
    if(abs(mapp[ii][jj]) > maxx){
        EXP1 = ceil(EXP1 * 88.0/100);
        EXP2 = ceil(EXP2 * 88.0/100);
        HP1 = ceil(HP1 * 90.0/100);
        HP2 = ceil(HP2 * 90.0/100);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);

        return mapp[ii][jj];
    }
    if(abs(mapp[ii][jj]) <= maxx){
        EXP1 = ceil(EXP1 * 112.0/100);
        EXP2 = ceil(EXP2 * 112.0/100);
        HP1 = ceil(HP1 * 110.0/100);
        HP2 = ceil(HP2 * 110.0/100);
        checkEXP(EXP1);
        checkEXP(EXP2);
        checkHP(HP1);
        checkHP(HP2);
        return maxx;
    }

    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
return maxx;
}
// Task 4
int checkPassword(const char * s, const char * email){
    string ss = string(s);
    string emaill = string(email);
    if (ss.size() < 8 ) return -1;
    else if (ss.size() > 20) return -2;
    else{
        string se = "";
        for (int i = 0; i < emaill.size(); ++i){
            if (emaill[i] != '@') se += emaill[i];
            else break;
        }

        bool check1 = true;
        for (int i = 0; i < ss.size(); ++i){
            for (int j = 0; j < se.size(); ++j){
                if (se[j] != s[i + j]){
                    check1 = false;
                    break;
                }
                check1 = true;
            }
            if (check1 == true) return -(300 + i);
        }
        for (int i = 0; i < ss.size(); ++i){
            if (ss[i] == ss[i + 1] && ss[i] == ss[i + 2]) return -(400 + i);
        }
        bool check2 = false;
        for (int i = 0; i < ss.size(); ++i){
            if(ss[i] == '@' || ss[i] == '#' || ss[i] == '%' || ss[i] == '$' || ss[i] == '!'){
                check2 = true;
                break;
            }
        }
        if (check2 == false) return -5;
        for (int i = 0; i < ss.size(); ++i){
             if(ss[i]!='@' and ss[i]!='#' and ss[i]!='%' and ss[i]!='$' and ss[i]!='!' and !(ss[i]>='A' and ss[i]<='Z') and !(ss[i]>='a' and ss[i]<='z') and !(ss[i]>='0' and ss[i]<='9')){
            return i;
        }
        }
        return -10;
    }
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max_length = 0, max_count = 0;
    int res;

    for (int i = 0; i < num_pwds; ++i){
        const char* temp = arr_pwds[i];
        int length = strlen(temp);
        int countt = 0;
        for (int j = 0; j < num_pwds; ++j){
            if (strcmp(arr_pwds[j], temp) == 0) countt++;
        }
        if (countt > max_count || (countt == max_count && length > max_length)) {
            max_count = countt;
            max_length = length;
            res = i;
        }
    }
    return res;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
