
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

int cExp (int n) {
    if (n < 0) return 0;
    else if (n > 600) return 600;
    else return n;
}

int cHp (int n) {
    if (n < 0) return 0;
    else if (n > 666) return 666;
    else return n;
}

int cM (int n) {
    if (n < 0) return 0;
    else if (n > 3000) return 3000;
    else return n;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if ((e1<0) || (e1>99)) return -99;
    else if (e1>=0 && e1<=3){
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else exp2 += 29+45+75;
        int d = e1*3 + exp1*7;
        if (d%2 == 0) exp1 = ceil((float)exp1 + ((float)d)/200);
        else exp1 = ceil((float)exp1 - ((float)d)/100);  
    }
    else {
        if (e1>=4 && e1<=19) exp2 = ceil((float)exp2 + ((float)e1)/4 + 19);
        else if (e1 >= 20 && e1 <= 49) exp2 = ceil((float)exp2 + ((float)e1)/9 + 21);
        else if (e1 >= 50 && e1 <= 65) exp2 = ceil((float)exp2 + ((float)e1)/16 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = cExp(ceil((float)exp2 + ((float)e1)/4 + 19));
            if (exp2 > 200) exp2 = ceil((float)exp2 + ((float)e1)/9 + 21);
        }
        else {
            exp2 = cExp(ceil((float)exp2 + ((float)e1)/4 + 19));
            exp2 = cExp(ceil((float)exp2 + ((float)e1)/9 + 21));
            if (exp2 > 400) {
                exp2 = cExp(ceil((float)exp2 + ((float)e1)/16 + 17));
                exp2 = ceil(exp2*1.15);
            }
        }
        exp1 = exp1 - e1;
    }
    exp1 = cExp(exp1);
    exp2 = cExp(exp2);
    return exp1 + exp2;
}

// Task 2
int perNum(int n) {
    int s = floor(sqrt(n));
    int b = s + 1;
    int ps = s * s;
    int pb = b * b;
    if ((n-ps) < (pb-n)) return ps;
    else return pb;
}

void road1(int EXP1, float &P1){
    int S = perNum(EXP1);
    if (EXP1 >= S) P1 = 100;
    else P1 = ((((float)EXP1)/((float)S) + 80)/123) * 100;
}

void road2(int &HP1, int &EXP1, int &M1, int E2, float &P2) {
    int mode = 0;
    if (E2%2 != 0) mode = 1;
    int HM = M1/2;
    do {
        // Stage 1
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 = M1 - 150;
        } else {
            HP1 = ((ceil(HP1*1.1) != (HP1*1.1)) && (HP1%10 == 0)) ? (ceil(HP1 * 1.1)-1) : (ceil(HP1 * 1.1));
            HP1 = cHp(HP1);
            M1 = M1 - 70;
        }
        M1 = cM(M1);
        if (((mode==1)&&(M1<HM)) || ((mode==0)&&(M1==0))) break;
        // Stage 2
        if (EXP1 < 400) M1 = M1 - 200;   
        else M1 = M1 - 120;
        EXP1 = cExp(ceil(EXP1 * 1.13));
        M1 = cM(M1);
        if (((mode==1)&&(M1<HM)) || ((mode==0)&&(M1==0))) break;
        // Stage 3
        if (EXP1 <300) M1 = M1 - 100;
        else M1 = M1 - 120;
        EXP1 =ceil(EXP1 * 0.9);
        M1 = cM(M1);
        if (((mode==1)&&(M1<HM)) || ((mode==0)&&(M1==0))) break;
    } while ((mode==1) && (M1>=HM));
    HP1 = ceil(HP1 * 0.83);
    EXP1 = cExp(ceil(EXP1 * 1.17));
    road1(EXP1, P2);
}

void road3(int E2, float &P3) {
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) P3 = P[E2];
    else P3 = P[((E2/10)+(E2%10)) % 10];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if ((E2<0) || (E2>99)) return -99;
    float P1 = 0, P2 = 0, P3 = 0;
        road1(EXP1, P1);
        road2(HP1, EXP1, M1, E2, P2);
        road3(E2, P3);
    if ((P1==100) && (P2==100) && (P3==100)) EXP1 = ceil(EXP1 * 0.75);
    else {
        float avg = (P1+P2+P3)/3;
        if (avg < 50){
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
        EXP1 = cExp(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int rDiagonal(int a, int b, int arr[][10]) {
    int sum = a + b;
    int max = arr[a][b];
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            if (i+j == sum)
                if (arr[i][j] > max) max = arr[i][j];
    return max;
}

int lDiagonal(int a, int b, int arr[][10]) {
    int hieu = a - b;
    int max = arr[a][b];
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            if (i-j == hieu)
                if (arr[i][j] > max) max = arr[i][j];
    return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if ((E3<0) || (E3>99)) return -99;
    int mat[10][10] = {0};
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            mat[i][j] = ((E3*j) + (i*2)) * (i-j);
    int I = 0, J = 0;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++) {
            if (mat[i][j] > (E3*2)) I += 1;
            if (mat[i][j] < (-E3)) J += 1;
        }
    while (I >= 10) I = (I/10) + (I%10);
    while (J >= 10) J = (J/10) + (J%10);
    int taxi = mat[I][J];
    int maxR = rDiagonal(I, J, mat);
    int maxL = lDiagonal(I, J, mat);
    int human = (maxR > maxL) ? maxR : maxL;
    if (abs(human) >= abs(taxi)) {
        EXP1 = ((ceil(EXP1*1.12) != (EXP1*1.12)) && (EXP1%25 == 0)) ? (ceil(EXP1 * 1.12)-1) : (ceil(EXP1 * 1.12));
        EXP2 = ((ceil(EXP2*1.12) != (EXP2*1.12)) && (EXP2%25 == 0)) ? (ceil(EXP2 * 1.12)-1) : (ceil(EXP2 * 1.12));
        HP1 = ((ceil(HP1*1.1) != (HP1*1.1)) && (HP1%10 == 0)) ? (ceil(HP1 * 1.1)-1) : (ceil(HP1 * 1.1));
        HP2 = ((ceil(HP2*1.1) != (HP2*1.1)) && (HP2%10 == 0)) ? (ceil(HP2 * 1.1)-1) : (ceil(HP2 * 1.1));
        EXP1 = cExp(EXP1);
        EXP2 = cExp(EXP2);
        HP1 = cHp(HP1);
        HP2 = cHp(HP2);
        return human;
    }
    else {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        return taxi;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    int a = 0;
    for (int i=0; email[i]!='\0'; i++)
        if (email[i] == '@') a=i;
    char se[100];
    strncpy(se, email, a);
    se[a] = '\0';
    int l = strlen(s);
    if (l < 8) return -1; // first criteria
    if (l > 20) return -2; // second criteria
    const char * sei = strstr(s, se);
    if (sei != nullptr) return -(300 + (sei-s)); // third criteria
    for (int i=0; i<=(l-2); i++)
        if (s[i] == s[i+1]) {
            if (s[i+1] == s[i+2]) return -(400 + i); // fourth criteria
            else i++;
        }
    const char sSb[] = "@#%$!";
    bool have_sSb = false;
    for (int i=0; i<=4; i++)
        if (strchr(s, sSb[i]) != nullptr) have_sSb = true;
    if (have_sSb == false) return -5; // fifth criteria
    for (int i = 0; s[i]!='\0'; i++)
        if ((!isalnum(s[i])) && (strchr(sSb, s[i])==nullptr)) return i;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int r = 0;
    bool e[num_pwds] = {};
    int nP[num_pwds] = {};
    for (int i=0; i<num_pwds; i++) {
        if (e[i] == true) continue;
        for (int j=i+1; j<num_pwds; j++) {
            if (e[j] == true) continue;
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                nP[i] += 1;
                e[j] = true;
            }
        }
    }
    int maxN = nP[0];
    for (int i=1; i<num_pwds; i++)
        if ((e[i]==false) && (nP[i]>maxN)) maxN = nP[i];
    int lP[num_pwds] = {};
    for (int i=0; i<num_pwds; i++)
        if ((e[i]==false) && (nP[i]==maxN)) lP[i] = strlen(arr_pwds[i]);
    int maxL = lP[0];
    for (int i=1; i<num_pwds; i++)
        if ((nP[i]==maxN) && (lP[i]>maxL)) maxL = lP[i];
    for (int i=0; i<num_pwds; i++)
        if ((nP[i]==maxN) && (lP[i]==maxL)) {
            r = i;
            break;
        }
    return r;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////