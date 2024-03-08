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

void checkhp(int & h) {
    if (h > 666) h = 666;
    else if (h < 0) h = 0;
}
void checkexp(int & x)  {
    if (x > 600) x = 600;
    else if (x < 0) x = 0;
}
void checkmoney(int & m) {
    if (m > 3000) m = 3000;
    else if (m < 0) m = 0;
}
int check_e(int & e) {
    if (e < 0 || e > 99) 
    return 99;
}
int checkchar (char c)  {
    if ((c == '@') || (c == '#') || (c == '%')|| (c == '$') || (c == '!') ) {
        return 0;
    }
    return -1;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkexp(exp2); checkexp(exp1);
    check_e(e1);
    int D;
    if ((e1 >= 0 && e1 <= 3)) {
      if (e1 == 0) exp2 += 29;
      else if (e1 == 1) exp2 += 45;
      else if (e1 == 2) exp2 += 75;
      else exp2 += 29 + 45 + 75;
      D = e1*3 + exp1*7;
      if (D % 2 == 0) ceil(exp1 += double(D)/200);
      else ceil(exp1 -= double(D)/100);
    } else if (e1 >= 4 && e1 <= 99) {
        exp1 -= e1;
        if (e1 >= 4 && e1 <= 19) ceil(exp2 += (double(e1)/4) + 19);
        else if (e1 >= 20 && e1 <= 49) ceil(exp2 += (double(e1)/9) + 21);
        else if (e1 >= 50 && e1 <= 65) ceil(exp2 += double(e1)/16 + 17);
        else if (e1 >= 66 && e1 <= 79) {
            ceil(exp2 += (double(e1)/4) + 19);
            if (exp2 > 200) ceil(exp2 += (double(e1)/9) + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            ceil(exp2 += (double(e1)/4) + 19);
            ceil(exp2 += (double(e1)/9) + 21);
            if (exp2 > 400) {
                ceil(exp2 += double(e1)/16 + 17);
                ceil(exp2 += double(exp2) * 0.15);
            } 
        }
    }
   return exp1 + exp2; 
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkhp(HP1); checkexp(EXP1); checkmoney(M1); check_e(E2);
    //PATH 1
    int S, P, P1, P2, P3, t;
    S = round(double(sqrt(EXP1)))*round(double(sqrt(EXP1)));
    if (EXP1 >= S) P1 = 1; else double(P1) = (double(EXP1)/S + 80) / 123;
    //PATH 2
    int a = M1*0.5;
    while (E2 % 2 == 1 && a < M1) {
        if (HP1 < 200) {
            ceil(HP1 += double(HP1)*0.3);
            M1 -= 150; 
        } else {
            ceil(HP1 += double(HP1)*0.1);
            M1 -= 70;
        }
        if (EXP1 < 400) M1 -= 200; else M1 -= 120;
        ceil(EXP1 += 0.13*double(EXP1));
        if (EXP1 < 300) M1 -= 100; else M1 -= 120;
        ceil(EXP1 -= double(EXP1)*0.1);
    }
    while (E2 % 2 == 0 && M1 != 0) {
        if (HP1 < 200) {
            ceil(HP1 += double(HP1)*0.3);
            M1 -= 150; 
        } else {
            ceil(HP1 += double(HP1)*0.1);
            M1 -= 70;
        } checkmoney(M1);
        if (M1 = 0) break;
        if (EXP1 < 400) M1 -= 200; else M1 -= 120;
        ceil(EXP1 += 0.13*double(EXP1));
        checkmoney(M1);
        if (M1 = 0) break;
        if (EXP1 < 300) M1 -= 100; else M1 -= 120;
        ceil(EXP1 -= double(EXP1)*0.1);
        checkmoney(M1);
        if (M1 = 0) break;
    }
    ceil(HP1 += 1.7*double(HP1)); ceil(EXP1 += double(EXP1)*1.7);
    S = round(double(sqrt(EXP1)))*round(double(sqrt(EXP1)));
    if (EXP1 >= S) P2 = 1; else double(P2) = (double(EXP1)/S + 80) / 123;
    //Path3
    t = E2/10 + E2%10;
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 <= 9) double(P3) = arr[E2]/100;
    else if (E2 > 9) {
        if (t > 10) double(P3) = arr[t%10]/100;
        else if (t <= 9) double(P3) = arr[t]/100;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 -= EXP1*0.25;
    else double(P) = (P1 + P2 + P3)/3;
    if (P  < 0.5) {
        ceil(HP1 -= double(HP1)*0.15);
        ceil(EXP1 += 0.15*double(EXP1));
    } else {
        ceil(HP1 -= double(HP1)*0.1);
        ceil(EXP1 += double(EXP1)*0.2);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkhp(HP1); checkhp(HP2); checkexp(EXP1); checkexp(EXP2); check_e(E3);
    int arr[10][10];
    int i, j, k, t; int ci = 0; int cj = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            arr[i][j] = ((E3*j) + (i*2)) * (i-j);
        } 
    }
    for (i = 0; i < 10; i ++ ) {
        for (j = 0; j < 10; j++) {
            if (arr[i][j] > (E3*2)) ci++;
            if (arr[i][j] < (-E3)) cj++;
        }
    }
    while (ci > 9) {
        i = ci/10 + ci%10;
        ci = i;
    }
    while (cj > 9) {
        j = cj/10 + cj*10;
        cj = j;
    }
    t = arr[i][j]; k=t;
    for (ci = 0; ci < 10; ci++) {
        for (ci = 0; cj < 10; cj ++) {
            if ((ci-cj) == (i-j) || (ci+cj) == (i+j)) {
                if(k < arr[ci][cj]) k = arr[ci][cj];
            }
        }
    }
    if (abs(t) > k) {
        EXP1 += 1.2*EXP1; HP1 += 0.1*HP1;
        EXP2 += 1.2*EXP2; HP2 += 0.1*HP1;
    } else {
        EXP1 -= 1.2*EXP1; HP1 -= 0.1*HP1;
        EXP2 -= 1.2*EXP2; HP2 -= 0.1*HP1;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string p = s; //passneedtocheck
    string m = email;
    string se = m.substr(0, m.find("@"));
    if (p.length() < 8) return -1; 
    else if (p.length() > 20) return -2;
    else if ((int)p.find(se) != -1) return -(300 + (int)p.find(se));
    for (int i=0; i < p.length()- 2; i++) {
        if (p[i] == p[i+1] && p[i+1] == p[i+2]) return -(400 + i);
        if (checkchar(p[i])) return -5; 
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string a[100]; 
    for (int i = 0; i < num_pwds; i++) {
        string p = arr_pwds[i];
        a[i] = p;
    }
    int b[100];
    int c[100];
    for (int i=0; i<=50; i++) b[i] = 1;

    
    int max_count = 0;
    int max_length = 0;
    for (int i = 0; i < num_pwds; i++) 
    {
        for (int j = i+1; j < num_pwds; i++ ) {
            if (a[i] == a[j]) {
                b[i]++;
                if (b[i] < max_count) b[i] < max_count;              
            }
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (b[i] == max_count) {
            c[i] = a[i].length();
            if(c[i] > max_length) max_length = c[i];
        }
        
    }
    for (int i=0; i<num_pwds; i++) {
        if (c[i] == max_length) return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////