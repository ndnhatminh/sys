#include "study_in_pink1.h"
using namespace std;
int lamtron(double a) {
    return a + 0.999;
}
int chinhphuong(int a) {
    int mini = 600;
    for (int i = 1; i <= 24; i++) {
        int temp = mini;
        mini = min(abs(i * i - a),temp);
        if (temp > mini) continue;
        else return (i-1) * (i-1);
    }
    return 0;
}
int checkhp(int a) {
    if (a < 0) return 0;
    else if (a > 666) return 666;
    else return a;
}
int checkexp(int a) {
    if (a < 0) return 0;
    else if (a > 600) return 600;
    else return a;
}
int checkM(int a) {
    if (a < 0) return 0;
    else if (a > 3000) return 3000;
    else return a;
}
bool checkE(double a) {
    if (a < 0 || a > 99 ) return 0;
    if (a - (int)a > 0) return 0;
    else return 1;
}
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
int firstMeet(int & exp1, int & exp2, int e1) {
    if (checkE(e1) == 0) return -99;
    //4.1.1
    if (e1 >= 0 && e1 <= 3) { 
        if (e1 == 0) {
            exp2 += 29; exp2 = checkexp(exp2);
        }
        else if (e1 == 1) {
            exp2 += 45; exp2 = checkexp(exp2);
        }
        else if (e1 == 2) {
            exp2 += 75; exp2 = checkexp(exp2);
        }
        else {
            exp2 += 149; exp2 = checkexp(exp2);
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = checkexp(lamtron(exp1 + (double)D/200));
        }
        else {
            double temp = exp1 - ((double)D / 100);
            exp1 = lamtron(temp);
            exp1 = checkexp(exp1);
        }
    }
    //4.1.2
    else if (e1 >= 4 && e1 <= 99) {
        double t1, t2, t3;
        t1 = (double)e1 / 4 + 19;
        t2 = (double)e1 / 9 + 21;
        t3 = (double)e1 / 16 + 17;

        if (e1 >= 4 && e1 <= 19)exp2 = checkexp(exp2+lamtron(t1));
        else if (e1 >= 20 && e1 <= 49)exp2 = checkexp(exp2+lamtron(t2));
        else if (e1 >= 50 && e1 <= 65)exp2 = checkexp(exp2+lamtron(t3));
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = checkexp(exp2+lamtron(t1));
            if (exp2 > 200) {
                exp2 = checkexp(exp2+lamtron(t2));
            }
        }
        else {
            exp2 = checkexp(exp2+lamtron(t1));
            if (exp2 > 200) {
                exp2 = checkexp(exp2+lamtron(t2));
            }
            if (exp2 > 400) {
                exp2 = checkexp(exp2+lamtron(t3));
                exp2 = checkexp(lamtron(exp2*1.15));
            }
        }
        exp1 -= e1;
        exp1 = checkexp(exp1);
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // con duong 1
    int S = chinhphuong(EXP1);
    double P1;
    if (EXP1 >= S)P1 = 1;
    else {
        P1 = ((double)EXP1 / S + 80) / 123;
        P1 = ceil(P1 * 100) / 100;
    }
    // con duong 2
    M1 = checkM(M1);
    int mf = lamtron(M1/2);
    if (E2 % 2 == 0 && M1 > 0) {
        if (HP1 < 200) {
            HP1 = checkhp(lamtron(HP1 * 1.3));
            M1 = checkM(M1 - 150);
        }
        else {
            HP1 = checkhp(lamtron(HP1 * 1.1));
            M1 = checkM(M1 - 70);
        }
        if (M1 > 0) {
            if (EXP1 < 400) M1 = checkM(M1 - 200);
            else M1 = checkM(M1 - 120);
            EXP1 = checkexp(lamtron(EXP1 * 1.13));
        }
        if (M1 > 0) {
            if (EXP1 < 300) M1 = checkM(M1 - 100);
            else M1 = checkM(M1 - 120);
            EXP1 = checkexp(lamtron(EXP1 * 0.9));
        }
    }
    while (E2 % 2 == 1 && M1 > mf) {
        if (HP1 < 200) {
            HP1 = checkhp(lamtron(HP1 * 1.3));
            M1 = checkM(M1 - 150);
        }
        else {
            HP1 = checkhp(lamtron(HP1 * 1.1));
            M1 = checkM(M1 - 70);
        }
        if (M1 > mf) {
            if (EXP1 < 400) M1 = checkM(M1 - 200);
            else M1 = checkM(M1 - 120);
            EXP1 = checkexp(lamtron(EXP1 * 1.13));
        }
        if (M1 > mf) {
            if (EXP1 < 300) M1 = checkM(M1 - 100);
            else M1 = checkM(M1 - 120);
            EXP1 = checkexp(lamtron(EXP1 * 0.9));
        }
    }
    HP1 = checkhp(lamtron(HP1 * 0.83));
    EXP1 = checkexp(lamtron(EXP1 * 1.17));
    S = chinhphuong(EXP1);
    double P2;
    if (EXP1 >= S)P2 = 1;
    else {
        P2 = ((double)EXP1 / S + 80) / 123;
        P2 = ceil(P2 * 100) / 100;
    }
    // con duong 3
    int P[10] = {32,47,28,79,100,50,22,83,64,11};
    double P3;
    if (E2 < 10)P3 = P[E2] / 100;
    else {
            int temp = E2;
            E2 = temp / 10 + temp % 10;
            P3 = (double)P[E2 % 10] / 100;
    }
    // sau 3 con duong
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = lamtron(EXP1*0.75);
    }
    else {
        float tb = (P1 + P2 + P3) / 3;
        tb = ceil(tb * 100) / 100;
        if (tb < 0.5) {
            HP1 = lamtron(HP1*0.85);
            EXP1 = checkexp(lamtron(EXP1*1.15));
        }
        else {
            HP1 = lamtron(HP1*0.9);
            EXP1 = checkexp(lamtron(EXP1*1.2));
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     int t3[10][10] = { 0 };
     int di = 0, dj = 0;
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            t3[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (t3[i][j] > 2 * E3)di++;
            else if (t3[i][j] < (-E3))dj++;
        }
    }
    int sw[10][10] = { 0 };
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            int maxi = 0;
            for (int i = 0; i < 10; i++) {
                int ta = i, tb = i;
                if ((a + ta < 10) && (b + tb < 10)) { 
                    maxi = max(maxi, t3[a + ta][b + tb]);
                }
                if ((a + ta < 10) && (b - tb > 0)) {
                    maxi = max(maxi, t3[a + ta][b - tb]);
                }
                if ((a - ta > 0) && (b + tb < 10)) {
                    maxi = max(maxi, t3[a - ta][b + tb]);
                }
                if ((a - ta > 0) && (b - tb > 0)) {
                    maxi = max(maxi, t3[a - ta][b - tb]);
                }
            }
                sw[a][b] = maxi;         
        }
    }
    while (di > 9) {
        int temp = di;
        di = temp / 10 + temp % 10;
    }
    while (dj > 9) {
        int temp = dj;
        dj = temp / 10 + temp % 10;
    }
    int trave;
    if (abs(t3[di][dj]) > sw[di][dj]) {
        EXP1 = lamtron(EXP1*0.88); EXP2 = lamtron(EXP2*0.88);
        HP1 = lamtron(HP1*0.9); HP2 = lamtron(HP2*0.9);
        trave = t3[di][dj];
    }
    else {
        EXP1 = checkexp(lamtron(EXP1*1.12)); EXP2 = checkexp(lamtron(EXP2*1.12));
        HP1 = checkhp(lamtron(HP1*1.1)); HP2 = checkhp(lamtron(HP2*1.1));
        trave = sw[di][dj];
    }
    return trave;
}

// Task 4
bool task4(char a) {
    if (a >= 97 && a <= 122)return 1;
    else if (a >= 65 && a <= 90)return 1;
    else if (a >= 48 && a <= 57)return 1;
    else if (a == '@' || a == '#' || a == '%' || a == '$' || a == '!') return 1;
    else return 0;
}
int checkPassword(const char * s, const char * email) {
    
    const char* p = strchr(email, '@');
    char se[strlen(email) - strlen(p) + 1];
    for (int i = 0; i < strlen(email) - strlen(p); i++)se[i] = email[i];
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    // chua se
    if (strstr(s, se) != nullptr) {
        int csei = -1;
        int c = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] != se[c])c = 0;
            else if (s[i] == se[c])c++;
            if (c == strlen(se)) {
                csei = i - c + 1; break;
            }
     }
        return -300-csei;
   
    
    }
    int re = 1,ktdb=0,err=-1,sci=-1;
    // > 2 ki tu lien tiep = nhau
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1])re++;
        else re = 1;
        if (re == 3) { sci = i - 2; break; }
    }
    if (sci != -1)return -(400 + sci);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')ktdb++;
        if (!task4(s[i])) { err = i; break; }
    }
    //s ko ktdb
    if (ktdb == 0)return -5;
    //hop le
    if (ktdb > 0 && err == -1)return -10;
    // vi pham dau tien
    else return err;
}

// Task 5
bool checkt5(const char* arr[], int num, const char* a) {
    for (int i = 0; i < num; i++) {
        if (a == arr[i])return 1;
    }
    return 0;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    const char *arr[30];
    int narr[30]={0};
    int dem = 0;
    int ans = -1, mfre = -1, mnum = -1;
    // check char moi
    for (int i = 0; i < num_pwds; i++) {
        if (!checkt5(arr, dem, arr_pwds[i])) {
            dem++;
            arr[dem - 1] = arr_pwds[i];
        }
    }
    // check so lan cua char & tim maxfre
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < dem; j++) {
            if (arr_pwds[i] == arr[j])narr[j]++;
            mfre = max(mfre, narr[j]);
        }
    }
    // check maxfre co ki tu nhieu nhat
    for (int i = 0; i < dem; i++) {
        if (narr[i] == mfre) {
            if (narr[i] == mfre) {
                int temp = mnum;
                int len = strlen(arr[i]);
                mnum = max(mnum, len);
                if (temp != mnum)ans = i;
            }
        }
    }
    return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////