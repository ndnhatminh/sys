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


int check(int n, int bot, int top) {
    if (n < bot) n = bot;
    else if (n > top) n = top;
    return n;
}
double calcP(int n){
    double P;
    int square = static_cast<int>(sqrt(n) + 0.5);
    if (n >= (square * square)) return 1.0;
    else P = ((((n * 1.00) / (square * square)) + 80.0) / 123.0);
    return P;
}
double f=1e-10; // very small number(we use it to optimize ceil function)
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    int firstpoint = 0, lastpoint = 600;
    if (e1 < 0 || e1 > 99) return -99;
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);

    const int inform1_1 = 29, inform1_2 = 45, inform1_3 = 75;
    float inform2_1, inform2_2, inform2_3, divide2;
    inform2_1 = e1*1.000/4.0 + 19;
    inform2_2 = e1*1.000/9.0 + 21;
    inform2_3 = e1*1.000/16.0 + 17;
    float exp1_test = exp1;
    float exp2_test = exp2;
    const int D = (e1*3)+(exp1*7);
    divide2= D%2;

    if (e1>=0 && e1<=3){
        if (e1 == 0) exp2 += inform1_1;
        else if (e1 == 1) exp2 += inform1_2;
        else if (e1 == 2) exp2 += inform1_3;
        else if (e1 == 3) exp2 = exp2 + inform1_1 + inform1_2 + inform1_3;
        if (divide2==0) exp1 = ceil(exp1_test + (D*1.000/200)-f);
        else exp1 = ceil(exp1_test - (D*1.000/100)-f);
    }

    if (e1>=4 && e1<=99){
        if (e1>=4 && e1<=19) exp2 = ceil(exp2_test+inform2_1);
        else if (e1>=20 && e1<=49) exp2 = ceil(exp2_test+inform2_2);
        else if (e1>=50 && e1<=65) exp2 = ceil(exp2_test+inform2_3);
        else if (e1>=66 && e1<=79){
            exp2 = ceil(exp2_test+inform2_1);
            if (exp2>200) exp2 = ceil(exp2*1.000+inform2_2-f);
        }
        else if (e1>=80 && e1<=99){
            exp2 = exp2 + ceil(inform2_1) + ceil(inform2_2);
            if (exp2>400){
                exp2 = ceil(exp2*1.000+inform2_3-f);
                exp2 = ceil(exp2*1.000*1.15-f);
            }
        }
        exp1 -= e1;
    }
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    int firstpoint = 0, lastpoint = 600; //EXP checker
    int firstpoint2 = 0, lastpoint2 = 666; //HP checker
    int firstpoint3 = 0, lastpoint3 = 3000; //M checker
    EXP1 = check(EXP1, firstpoint, lastpoint);
    HP1 = check(HP1, firstpoint2, lastpoint2);
    M1 = check(M1, firstpoint3, lastpoint3);
    double P1, P2, P3, chance;
    float moneycap = M1*0.5;
    int moneyspent = 0, i;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    P1=calcP(EXP1);

    if (E2%2!=0){
        while (moneyspent<=moneycap&&M1!=0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3-f);
                moneyspent += 150;
            } else {
                HP1 = ceil(HP1 * 1.1-f);
                moneyspent += 70;
            }
            HP1 = check(HP1, firstpoint2, lastpoint2);
            if (moneyspent > moneycap) break;
            if (EXP1 < 400) moneyspent += 200;
            else moneyspent += 120;
            EXP1 = ceil(EXP1 * 1.13-f);
            EXP1 = check(EXP1, firstpoint, lastpoint);
            if (moneyspent > moneycap) break;
            if (EXP1 < 300) moneyspent += 100;
            else moneyspent += 120;
            EXP1 = ceil(EXP1*0.9-f);
            EXP1 = check(EXP1, firstpoint, lastpoint);
            if (moneyspent > moneycap) break;
        }
        moneyspent = check(moneyspent, firstpoint3, lastpoint3);
        M1 -= moneyspent;
    }
    else {
        for(int x=0;x==0&&M1!=0;x++){
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3-f);
                M1 -= 150;
            } else {
                HP1 = ceil(HP1 * 1.1-f);
                M1 -= 70;
            }
            HP1 = check(HP1, firstpoint2, lastpoint2);
            if (M1<=0) break;
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil(EXP1 * 1.13-f);
            EXP1 = check(EXP1, firstpoint, lastpoint);
            if (M1<=0) break;
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = ceil(EXP1*0.9-f);
            EXP1 = check(EXP1, firstpoint, lastpoint);
            if (M1<=0) break;
        }
        M1=check(M1, firstpoint3, lastpoint3);
    }
    EXP1 = ceil(EXP1 * 1.17-f);
    HP1 = ceil(HP1 * 0.83-f);
    EXP1 = check(EXP1, firstpoint, lastpoint);
    HP1 = check(HP1, firstpoint2, lastpoint2);
    P2 = calcP(EXP1);


    if(E2<10) i=E2;
    else{
        int sum = (E2 / 10) + (E2 % 10);
        i= sum%10;
    }
    P3= P[i]*1.000/100;
    if(P1==1.00&&P2==1.00&&P3==1.00) EXP1 = ceil(EXP1*0.75-f);
    else{
        chance = (P1 +P2 +P3)/3;
        if(chance<0.50){
            EXP1=ceil(EXP1*1.15-f);
            HP1=ceil(HP1*0.85-f);
        }
        else{
            EXP1=ceil(EXP1*1.20-f);
            HP1=ceil(HP1*0.90-f);
        }
    }
    EXP1 = check(EXP1, firstpoint, lastpoint);
    HP1 = check(HP1, firstpoint2, lastpoint2);
    M1 = check(M1, firstpoint3, lastpoint3);

    return HP1+EXP1+M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    int firstpoint = 0, lastpoint = 600; //EXP checker
    int firstpoint2 = 0, lastpoint2 = 666; //HP checker
    EXP1 = check(EXP1, firstpoint, lastpoint);
    HP1 = check(HP1, firstpoint2, lastpoint2);
    EXP2 = check(EXP2, firstpoint, lastpoint);
    HP2 = check(HP2, firstpoint2, lastpoint2);
    int col = 10, row = 10, i = 0, j = 0, numi = 0, numj = 0;
    int mat[row][col];

    for(int r=0;r<row;r++)
        for (int c = 0; c < col; c++) mat[r][c] = ((E3 * c) + (r * 2)) * (r - c);
    for(int r=0;r<row;r++)
        for (int c = 0; c < col; c++){
            if(mat[r][c]>(E3*2)) numi++;
            else if(mat[r][c]<(-E3)) numj++;
        }
    for(int cord=numi,x=0;cord>=10;i=cord){
        x= (cord/10)+(cord%10);
        cord = x;
    }
    for(int cord=numj,x=0;cord>=10;j=cord){
        x= (cord/10)+(cord%10);
        cord = x;
    }
    int lefti=i,leftj=j,righti=i,rightj=j,maxx=0;
    maxx = mat[i][j];
    while (lefti > 0 && leftj > 0) {
        --lefti;
        --leftj;
        maxx = max(maxx, mat[lefti][leftj]);
    }
    while (lefti < row - 1 && leftj < col - 1) {
        ++lefti;
        ++leftj;
        maxx = max(maxx, mat[lefti][leftj]);
    }
    while (righti > 0 && rightj < col - 1) {
        --righti;
        ++rightj;
        maxx = max(maxx, mat[righti][rightj]);
    }
    while (righti < row - 1 && rightj > 0) {
        ++righti;
        --rightj;
        maxx = max(maxx, mat[righti][rightj]);
    }
    if(abs(mat[i][j])>maxx){
        EXP1=ceil(EXP1*0.88-f);
        HP1=ceil(HP1*0.9-f);
        EXP2=ceil(EXP2*0.88-f);
        HP2=ceil(HP2*0.9-f);
        EXP1 = check(EXP1, firstpoint, lastpoint);
        HP1 = check(HP1, firstpoint2, lastpoint2);
        EXP2 = check(EXP2, firstpoint, lastpoint);
        HP2 = check(HP2, firstpoint2, lastpoint2);
        return mat[i][j];
    }
    else {
        EXP1=ceil(EXP1*1.12-f);
        HP1=ceil(HP1*1.1-f);
        EXP2=ceil(EXP2*1.12-f);
        HP2=ceil(HP2*1.1-f);
        EXP1 = check(EXP1, firstpoint, lastpoint);
        HP1 = check(HP1, firstpoint2, lastpoint2);
        EXP2 = check(EXP2, firstpoint, lastpoint);
        HP2 = check(HP2, firstpoint2, lastpoint2);
        return maxx;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    int sepos = -1;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            sepos = i;
        }
    }

    char se[sepos + 1];
    strncpy(se, email, sepos);
    se[sepos] = '\0';

    int length = strlen(s);
    if (length < 8) {
        return -1;
    }
    if (length > 20) {
        return -2;
    }

    if (strstr(s, se) != nullptr) {
        string str(s);
        int sei=0;
        sei = str.find(se);
        return -(300 + sei);
    }

    bool specchar = false;
    char prechar = '\0';
    int count = 1;
    for (int i = 0; i < length; i++) {
        char currentchar = s[i];
        if (strchr("@#%$!", currentchar)) {
            specchar = true;
        }
        if (!(isdigit(currentchar) || islower(currentchar) || isupper(currentchar) || strchr("@#%$!", currentchar))) {
            return i;
        }
        if (i > 0 && currentchar == prechar) {
            count++;
            if (count > 2) {
                return -(400 + i - 2);
            }
        } else {
            count = 1;
        }
        prechar = currentchar;
    }
    if (!specchar) {
        return -5;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    string mpass;
    int mcount = 0;
    int mlength = 0;
    int result = -1;

    for (int i = 0; i < num_pwds; ++i) {
        string currentpass = arr_pwds[i];
        if (currentpass == mpass) {
            mlength = max(mlength, static_cast<int>(currentpass.length()));
        } else {
            int count = 1;
            for (int j = i + 1; j < num_pwds; ++j) {
                if (string(arr_pwds[j]) == currentpass) {
                    ++count;
                }
            }
            if (count > mcount) {
                mcount = count;
                mlength = static_cast<int>(currentpass.length());
                result = i;
                mpass = currentpass;
            }
            else if (count == mcount && currentpass.length() > mlength) {
                mlength = static_cast<int>(currentpass.length());
                result = i;
                mpass = currentpass;
            }
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////