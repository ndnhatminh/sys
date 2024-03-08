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

//alltasks
void checktotal(int & n, int lower_bound, int upper_bound) {
    n = min(n, upper_bound);
    n = max(lower_bound, n);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    checktotal(exp1, 0, 600);
    checktotal(exp2, 0, 600);
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 += 29;
            checktotal(exp2, 0, 600);
        } else if (e1 == 1) {
            exp2 += 45;
            checktotal(exp2, 0, 600);
        } else if (e1 == 2) {
            exp2 += 75;
            checktotal(exp2, 0, 600);
        } else if (e1 == 3) {
            exp2 += 149;
            checktotal(exp2, 0, 600);
        }
        int d = 3*e1 + 7*exp1;
        if (d % 2 == 0) {
            exp1 += ceil(1.0*d/200.0);
            checktotal(exp1, 0, 600);
        } else {
            exp1 =ceil(exp1 - 1.0*d/100.0);
            checktotal(exp1, 0, 600);
        }
    } else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceil(1.0*e1/4.0 + 19.0);
            checktotal(exp2, 0, 600);
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil(1.0*e1/9.0 + 21.0);
            checktotal(exp2, 0, 600);
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil(1.0*e1/16.0 + 17.0);
            checktotal(exp2, 0, 600);
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(1.0*e1/4.0 + 19.0);
            checktotal(exp2, 0, 600);
            if (exp2 > 200) {
                exp2 += ceil(1.0*e1/9.0 + 21.0);
                checktotal(exp2, 0, 600);
            }
        } else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(1.0*e1/4.0 + 19.0);
            checktotal(exp2, 0, 600);
            exp2 += ceil(1.0*e1/9.0 + 21.0);
            checktotal(exp2, 0, 600);
            if (exp2 > 400) {
                exp2 += ceil(1.0*e1/16.0 + 17.0);
                checktotal(exp2, 0, 600);
                exp2 += ceil(1.0*exp2*0.15);
                checktotal(exp2, 0, 600);
            }
        }
        exp1 -= e1;
        checktotal(exp1, 0, 600);
    }
    checktotal(exp1, 0, 600);
    checktotal(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int perfectsqare(int n) {
    int i = sqrt(n);
    if ((abs(n - i*i)) > (abs(n - (i+1)*(i+1))))
        return (i+1)*(i+1);
    else
        return i*i;
}

void road2even(int & HP1, int & M1, int & EXP1) {
    if (M1 == 0)
        return;
    if (HP1 < 200) {
        HP1 = ceil(float(1.0*HP1*1.3));
        checktotal(HP1, 0, 666);
        M1 -= 150;
        checktotal(M1, 0, 3000);
        if (M1 == 0)
            return;
    } else {
        HP1 = ceil(float(1.0*HP1*1.1));
        checktotal(HP1, 0, 666);
        M1 -= 70;
        checktotal(M1, 0, 3000);
        if (M1 == 0)
            return;
    }
    if (EXP1 < 400) {
        EXP1 = ceil(float(1.0*EXP1*1.13));
        checktotal(EXP1, 0, 600);
        M1 -= 200;
        checktotal(M1, 0, 3000);
        if (M1 == 0)
            return;
    } else {
        EXP1 = ceil(float(1.0*EXP1*1.13));
        checktotal(EXP1, 0, 600);
        M1 -= 120;
        checktotal(M1, 0, 3000);
        if (M1 == 0)
            return;
    }
    if (EXP1 < 300) {
        M1 -= 100;
        checktotal(M1, 0, 3000);
        EXP1 = ceil(1.0*EXP1*0.9);
        checktotal(EXP1, 0, 600);
        if (M1 == 0)
            return;
    } else {
        M1 -= 120;
        checktotal(M1, 0, 3000);
        EXP1 = ceil(1.0*EXP1*0.9);
        checktotal(EXP1, 0, 600);
        if (M1 == 0)
            return;
    }
}

void road2odd(int & HP1, int & M1, int & EXP1, float tmp) {
    if (M1 == 0)
        return;
    if (HP1 < 200) {
        HP1 = ceil(float(1.0*HP1*1.3));
        checktotal(HP1, 0, 666);
        M1 -= 150;
        checktotal(M1, 0, 3000);
        if (M1 < tmp)
            return;
    } else {
        HP1 = ceil(float(1.0*HP1*1.1));
        checktotal(HP1, 0, 666);
        M1 -= 70;
        checktotal(M1, 0, 3000);
        if (M1 < tmp)
            return;
    }
    if (EXP1 < 400) {
        EXP1 = ceil(float(1.0*EXP1*1.13));
        checktotal(EXP1, 0, 600);
        M1 -= 200;
        checktotal(M1, 0, 3000);
        if (M1 < tmp)
            return;
    } else {
        EXP1 = ceil(float(1.0*EXP1*1.13));
        checktotal(EXP1, 0, 600);
        M1 -= 120;
        checktotal(M1, 0, 3000);
        if (M1 < tmp)
            return;
    }
    if (EXP1 < 300) {
        M1 -= 100;
        checktotal(M1, 0, 3000);
        EXP1 = ceil(float(1.0*EXP1*0.9));
        checktotal(EXP1, 0, 600);
        if (M1 < tmp)
            return;
    } else {
        M1 -= 120;
        checktotal(M1, 0, 3000);
        EXP1 = ceil(float(1.0*EXP1*0.9));
        checktotal(EXP1, 0, 600);
        if (M1 < tmp)
            return;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 >99)
        return -99;
    checktotal(HP1, 0, 666);
    checktotal(EXP1, 0, 600);
    checktotal(M1, 0, 3000);
    double p1 = 0, p2 = 0, p3 = 0;
    float tmp = 1.0*M1/2;
    //road 1
    int S1 = perfectsqare(EXP1);
    if (EXP1 >= S1)
        p1 = 1;
    else
        p1 = (1.0*EXP1/S1 + 80.0)/123.0;
    //road 2
    if (E2 % 2 != 0) {
        while (true) {
            if (M1 <= tmp)
                break;
            road2odd(HP1, M1, EXP1, tmp);
        }
        HP1 = ceil(float(1.0*HP1*0.83));
        checktotal(HP1, 0, 666);
        EXP1 = ceil(float(1.0*EXP1*1.17));
        checktotal(EXP1, 0, 600);
    } else {
        road2even(HP1, M1, EXP1);
        HP1 = ceil(float(1.0*HP1*0.83));
        checktotal(HP1, 0, 666);
        EXP1 = ceil(float(1.0*EXP1*1.17));
        checktotal(EXP1, 0, 600);
    }
    int S2 = perfectsqare(EXP1);
    if (EXP1 >= S2)
        p2 = 1;
    else
        p2 = (1.0*EXP1/S2 + 80)/123;
    //road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    p3 = (double)P[(E2%10 + E2/10)%10]/100.0;
    //3 roads
    if (p1 + p2 + p3 == 3) {
        EXP1 = ceil(float(1.0*EXP1*0.75));
        checktotal(EXP1, 0, 600);
    } else {
        double total = 1.0*(p1 + p2 + p3)/3.0;
        if (total < 0.5) {
            HP1 = ceil(float(1.0*HP1*0.85));
            checktotal(HP1, 0, 666);
            EXP1 = ceil(float(1.0*EXP1*1.15));
            checktotal(EXP1, 0, 600);
        } else {
            HP1 = ceil(float(1.0*HP1*0.9));
            checktotal(HP1, 0, 666);
            EXP1 = ceil(float(1.0*EXP1*1.2));
            checktotal(EXP1, 0, 600);
        }
    }
    checktotal(EXP1, 0, 600);
    checktotal(HP1, 0, 666);
    checktotal(M1, 0, 3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    checktotal(HP1, 0, 666);
    checktotal(EXP1, 0, 600);
    checktotal(HP2, 0, 666);
    checktotal(EXP2, 0, 600);
    int a[10][10];
    int count1=0, count2=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            a[i][j]=((E3*j)+2*i)*(i-j);
            if (a[i][j] > 2*E3) {
                count1++;
            }
            if (a[i][j] < (-E3)){
                count2++;
            }
        }
    }
    while (count1 > 9) count1 = sum_digits(count1);
    while (count2 > 9) count2 = sum_digits(count2);
    int x = count1;
    int y = count2;
    int mx = 0;
    if ((x+y)>=9) {
        for (int j=9; j>=0; j--) {
            int i;
            i = (x+y)-j;
            if (i>=0 && i<=9) {
                mx = max(mx, a[i][j]);
            } else break;
        }
        for (int j=9; j>=0; j--) {
            int i;
            i = j-abs(x-y);
            if (i>=0 && i<=9) {
                mx = max(mx, a[i][j]);
            } else break;
        }
    } else {
        for (int i=0; i<=9; i++) {
            int j;
            j = i+abs(x-y);
            if (j>=0 && j<=9) {
                mx = max(mx, a[i][j]);
            } else break;
        }
        for (int i=0; i<=9; i++) {
            int j;
            j = (x+y)-i;
            if (j>=0 && j<=9) {
                mx = max(mx, a[i][j]);
            } else break;
        }
    }
    if (abs(a[x][y]) > abs(mx)) {
        EXP1 = ceil(float(1.0*EXP1*0.88));
        EXP2 = ceil(float(1.0*EXP2*0.88));
        HP1 = ceil(float(1.0*HP1*0.9));
        HP2 = ceil(float(1.0*HP2*0.9));
        checktotal(EXP1, 0, 600);
        checktotal(EXP2, 0, 600);
        checktotal(HP1, 0, 666);
        checktotal(HP2, 0, 666);
        return a[x][y];
    } else {
        EXP1 = ceil(float(1.0*EXP1*1.12));
        EXP2 = ceil(float(1.0*EXP2*1.12));
        HP1 = ceil(float(1.0*HP1*1.1));
        HP2 = ceil(float(1.0*HP2*1.1));
        checktotal(EXP1, 0, 600);
        checktotal(EXP2, 0, 600);
        checktotal(HP1, 0, 666);
        checktotal(HP2, 0, 666);
        return mx;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = "";
    int selen=0;
    int n = strlen(s);
    int m = strlen(email);
    for (int i=0; i<m; i++) {
        if (email[i]=='@')
            break;
        selen++;
        se += email[i];
    }
    if (n < 8)
        return -1;
    if (n > 20)
        return -2;
    if(se == "")
        return -300;
    for (int i=0; i<n; i++) {
        if (s[i] == se[0]) {
            bool check = true;
            for (int j=0; j<selen; j++) {
                if (i + j > n - 1) {
                    check = false;
                    break;
                }
                if (s[i + j] != se[j]) {
                    check = false;
                    break;
                }
            }
            if (check)
                return -(300 + i);
        }
    }
    for (int i=0; i<n-2; i++) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            return (-(400 + i));
        }
    }
    bool check = true;
    for (int i=0; i<n; i++) {
        if (s[i] == '@' || s[i] == '!' || s[i] == '#' || s[i] == '$' || s[i] == '%') {
            check = false;
            break;
        }
    }
    if (check)
        return -5;
    for (int i=0; i<n; i++) {
        if (s[i] == '@' || s[i] == '!' || s[i] == '#' || s[i] == '$' || s[i] == '%' || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            continue;
        return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int mx = 0;
    int count = 0;
    string mxpwd;
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (!strcmp(arr_pwds[i], arr_pwds[j])) {
                count++;
            }
        }
        if (count > mx) {
            mx = count;
            mxpwd = arr_pwds[i];
        } else if (count == mx) {
            if (strlen(arr_pwds[i]) > mxpwd.length()) {
                mxpwd = arr_pwds[i];
            }
        }
        count = 0;
    }
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == mxpwd) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////