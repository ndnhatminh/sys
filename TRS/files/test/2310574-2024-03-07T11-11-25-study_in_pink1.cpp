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

void exp(int &exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
}

void hp(int &hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
}

void m(int &m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
}

int square(int a) {
    int b = sqrt(a);
    if (a - b*b > (b+1)*(b+1) - a) return (b + 1)*(b + 1);
    else return b * b;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    exp(exp1); exp(exp2);
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0)
            exp2 = exp2 + 29;
        else if (e1 == 1)
            exp2 = exp2 + 45;
        else if (e1 == 2)
            exp2 = exp2 + 75;
        else
            exp2 = exp2 + 29 + 45 + 75;
        exp(exp2);
        int D = e1*3 + exp1*7;
        if (D%2 == 0)
            exp1 = ceil(exp1 + D/200.0);
        else
            exp1 = ceil(exp1 - D/100.0);
        exp(exp1);
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19)
            exp2 = ceil(exp2 + e1/4.0 + 19);
        else if (e1 >= 20 && e1 <= 49)
            exp2 = ceil(exp2 + e1/9.0 + 21);
        else if (e1 >= 50 && e1 <= 65)
            exp2 = ceil(exp2 + e1/16.0 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + e1/4.0 + 19);
            if (exp2 > 200)
                exp2 = ceil(exp2 + e1/9.0 + 21);
        }
        else {
            exp2 = ceil(exp2 + e1/4.0 + 19);
            exp2 = ceil(exp2 + e1/9.0 + 21);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + e1/16.0 + 17);
                exp2 = ceil(exp2*1.15 - 0.00001);
            }
        }
        exp(exp2);
        exp1 = exp1 - e1;
        exp(exp1);
    }
    else return -99;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    hp(HP1); exp(EXP1); m(M1);
    if (E2 < 0 || E2 > 99) return -99;
    double P1;
    if (EXP1 >= square(EXP1)) P1 = 100;
    else P1 = ((EXP1*1.0/square(EXP1)) + 80)*100/123;

    if (E2%2 == 0) {
        if (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1*1.3 - 0.00001);
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil(HP1*1.1 - 0.00001);
                M1 = M1 - 70;
            }
            hp(HP1);
        }
        if (M1 > 0) {
            if (EXP1 < 400) M1 = M1 - 200;
            else M1 = M1 - 120;
            EXP1 = ceil(EXP1*1.13 - 0.00001);
            exp(EXP1);
        }
        if (M1 > 0) {
            if (EXP1 < 300) M1 = M1 - 100;
            else M1 = M1 - 120;
            EXP1 = ceil(EXP1*0.9 - 0.00001);
        }
        m(M1);
    }
    else {
        float money = M1*0.5;
        int sum = 0;
        while (sum <= money) {
            if (M1 > 0) {
                if (HP1 < 200) {
                    HP1 = ceil(HP1*1.3 - 0.00001);
                    M1 = M1 - 150;
                    sum = sum + 150;
                }
                else {
                    HP1 = ceil(HP1*1.1 - 0.00001);
                    M1 = M1 - 70;
                    sum = sum + 70;
                }
                hp(HP1);
            }
            if (sum <= money && M1 > 0) {
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    sum = sum + 200;
                }
                else {
                    M1 = M1 - 120;
                    sum = sum + 120;
                }
                EXP1 = ceil(EXP1*1.13 - 0.00001);
                exp(EXP1);
            }
            if (sum <= money && M1 > 0) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    sum = sum + 100;
                }
                else {
                    M1 = M1 - 120;
                    sum = sum + 120;
                }
                EXP1 = ceil(EXP1*0.9 - 0.00001);
            }
        }
        m(M1);
    }
    HP1 = ceil(HP1*0.83 - 0.00001);
    EXP1 = ceil(EXP1*1.17 - 0.00001);
    exp(EXP1);
    double P2;
    if (EXP1 >= square(EXP1)) P2 = 100;
    else P2 = ((EXP1*1.0/square(EXP1)) + 80)*100/123;

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3 = P[((E2%10) + (E2/10))%10];
    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = ceil(EXP1*0.75 - 0.00001);
    else {
        if ((P1 + P2 + P3)/3 < 50) {
            HP1 = ceil(HP1*0.85 - 0.00001);
            EXP1 = ceil(EXP1*1.15 - 0.00001);
        }
        else {
            HP1 = ceil(HP1*0.9 - 0.00001);
            EXP1 = ceil(EXP1*1.2 - 0.00001);
        }
        exp(EXP1);
    }
    return EXP1 + HP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    hp(HP1); hp(HP2); exp(EXP1); exp(EXP2);
    if (E3 < 0 || E3 > 99) return -99;
    int a[10][10];
    int x = 0, y = 0;
    for(int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            a[i][j] =((E3*j) + (i*2))*(i - j);
            if (a[i][j] > E3*2) x++;
            if (a[i][j] < -E3) y++;
        }

    while(x > 9)
        x = x/10 + x%10;
    while(y > 9)
        y = y/10 + y%10;
    int taxi = a[x][y];
    int max = 0;
    for (int i = 0; i <= 9; i++) {
        int j = x + y - i;
        int k = i - x + y;
        if (j >= 0 && j <= 9)
            if (a[i][j] >= max) max = a[i][j];
        if (k >= 0 && k <= 9)
            if (a[i][k] >= max) max = a[i][k];
    }

    if (abs(taxi) > max) {
        EXP1 = ceil(EXP1*0.88 - 0.00001);
        EXP2 = ceil(EXP2*0.88 - 0.00001);
        HP1 = ceil(HP1*0.9 - 0.00001);
        HP2 = ceil(HP2*0.9 - 0.00001);
        return taxi;
    }
    else {
        EXP1 = ceil(EXP1*1.12 - 0.00001);
        exp(EXP1);
        EXP2 = ceil(EXP2*1.12 - 0.00001);
        exp(EXP2);
        HP1 = ceil(HP1*1.1 - 0.00001);
        hp(HP1);
        HP2 = ceil(HP2*1.1 - 0.00001);
        hp(HP2);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string pwd, se;
    while (*s) pwd = pwd + *s++;
    while (*email != '@') se = se + *email++;

    if (pwd.size() < 8) return -1;
    if (pwd.size() > 20) return -2;

    if (se.size() == 0) return -300;
    for (int i = 0; i < pwd.size(); i++)
        if (pwd[i] == se[0]) {
            int cnt = 0;
            for (int j = 0; j < se.size(); j++)
                if (pwd[i + j] == se[j]) cnt++;
            if (cnt == se.size()) return -(300 + i);
        }

    for (int i = 0; i < pwd.size() - 2; i++)
        if (pwd[i] == pwd[i+1] && pwd[i] == pwd[i+2]) return -(400 + i);

    int cnt = 0;
    for (int i = 0; i < pwd.size(); i++)
        if ((pwd[i]=='@')||(pwd[i]=='#')||(pwd[i]=='%')||(pwd[i]=='$')||(pwd[i]=='!')) cnt++;
    if (cnt == 0) return -5;

    for (int i = 0; i < pwd.size(); i++)
         if (!((pwd[i]>='0'&&pwd[i]<='9')||(pwd[i]>='a'&&pwd[i]<='z')||(pwd[i]>='A')&&(pwd[i]<='Z')||
             (pwd[i]=='@')||(pwd[i]=='#')||(pwd[i]=='%')||(pwd[i]=='$')||(pwd[i]=='!')))
         return i;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string s[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        while(*arr_pwds[i]) s[i] = s[i] + *arr_pwds[i]++;
    }
    int max = 1, a = 0;
    for (int i = 0; i < num_pwds; i++) {
        int cnt = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (s[j] == s[i]) cnt++;
            if (i == j) cnt--;
        }
        if (cnt > max) {
            a = i;
            max = cnt;
        }
        if (cnt == max)
            if (s[i].size() > s[a].size()) a = i;
    }
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////