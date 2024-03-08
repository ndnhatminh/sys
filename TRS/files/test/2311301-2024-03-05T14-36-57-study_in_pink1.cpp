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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    resetEXP(exp1);
    resetEXP(exp2);
    if ( (0 <= e1) && (e1 <= 3) ) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else exp2 += 149;
        resetEXP(exp2);
        int D = e1*3 + exp1*7;
        if (D%2 == 0) exp1 = roundUp( exp1 + ((double)D/200) );
        else exp1 = roundUp( exp1 - ((double)D/100) );
        resetEXP(exp1);
    }

    else {
        if ( (4 <= e1) && (e1 <= 19) ) { exp2 = roundUp( exp2 + ((double)e1/4 + 19) ); }
        else if ( (20 <= e1) && (e1 <= 49) ) { exp2 = roundUp( exp2 + ((double)e1/9 + 21) ); }
        else if ( (50 <= e1) && (e1 <= 65) ) { exp2 = roundUp( exp2 + ((double)e1/16 + 17) ); }
        else if ( (66 <= e1) && (e1 <= 79) ) { 
            exp2 = roundUp( exp2 + ((double)e1/4 + 19) ); 
            resetEXP(exp2);
            if (exp2 > 200) exp2 = roundUp( exp2 + ((double)e1/9 + 21) );
            resetEXP(exp2);
        }
        else { 
            exp2 = roundUp( exp2 + ((double)e1/4 + 19) ); 
            resetEXP(exp2);
            exp2 = roundUp( exp2 + ((double)e1/9 + 21) );
            resetEXP(exp2);
            if (exp2 > 400) {
                exp2 = roundUp( exp2 + ((double)e1/16 + 17) );
                resetEXP(exp2);
                exp2 = roundUp( 1.15 * (double)exp2 ); 
                resetEXP(exp2);
            }
        }
        exp1 -= e1;
        resetEXP(exp1);
        resetEXP(exp2);
    }
        
    return exp1 + exp2;

}

// Task 2

double road1(int & EXP1) {
    int S = round(sqrt(EXP1)); 
    double P1;
    if ( EXP1 >= (S*S) ) P1 = 1;
    else P1 = ((double)EXP1/(double)(S*S) + 80) / (123);
    return P1;
}
double road2(int & HP1, int & EXP1, int & M1, int E2) {
    resetEXP(EXP1);
    resetHP(HP1);
    resetM(M1);
    double money = (0.5 * M1);
    if (money != 0) {
        int count{ 0 };
        if (E2%2 == 1) {
            while (count <= money) {
                if (HP1 < 200) {
                    HP1 = roundUp(1.3 * HP1);
                    M1 -= 150;
                    count += 150;
                }
                else {
                    HP1 = roundUp(1.1 * HP1);
                    M1 -= 70;
                    count += 70;
                }
                resetEXP(EXP1);
                resetHP(HP1);
                resetM(M1);
                if (count > money) break;

                if (EXP1 < 400) {
                    M1 -= 200;
                    EXP1 = roundUp(1.13 * EXP1);
                    count += 200;
                }
                else {
                    M1 -= 120;
                    EXP1 = roundUp(1.13 * EXP1);
                    count += 120;
                }
                resetEXP(EXP1);
                resetHP(HP1);
                resetM(M1);
                if (count > money) break;

                if (EXP1 < 300) {
                    M1 -= 100;
                    EXP1 = roundUp(0.9 * EXP1);
                    count += 100;
                }
                else {
                    M1 -= 120;
                    EXP1 = roundUp(0.9 * EXP1);
                    count += 120;
                }
                resetEXP(EXP1);
                resetHP(HP1);
                resetM(M1);
                if (count > money) break;
            }
        }
        else {
            while (M1 > 0) {
                if (HP1 < 200) {
                    HP1 = roundUp(1.3 * HP1);
                    M1 -= 150;
                    count += 150;
                }
                else {
                    HP1 = roundUp(1.1 * HP1);
                    M1 -= 70;
                    count += 70;
                }
                resetEXP(EXP1);
                resetHP(HP1);
                resetM(M1);
                if (M1 == 0) break;

                if (EXP1 < 400) {
                    M1 -= 200;
                    count += 200;
                }
                else {
                    M1 -= 120;
                    count += 120;
                }
                EXP1 = roundUp(1.13 * EXP1);
                resetEXP(EXP1);
                resetHP(HP1);
                resetM(M1);
                if (M1 == 0) break;

                if (EXP1 < 300) {
                    M1 -= 100;
                    count += 100;
                }
                else {
                    M1 -= 120;
                    count += 120;
                }
                EXP1 = roundUp(0.9 * EXP1); 
                resetEXP(EXP1);
                resetHP(HP1);
                resetM(M1);
                if (M1 == 0) break;
                break;
            }

        }
    }
    EXP1 = roundUp(1.17 * EXP1);
    HP1 =roundUp(0.83 * HP1);
    resetEXP(EXP1);
    resetHP(HP1);
    resetM(M1);
                
    double P2 = road1(EXP1);
    return P2;

}
double road3(int & HP1, int & EXP1, int E2) {
    double P[ 10 ] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
    double P3;
    if ( (0 <= E2) && (E2 <= 9) ) {
        P3 = P[ E2 ];
    }
    else {
        int index = (E2 / 10) + (E2 % 10);
        if (index > 9) index = (index % 10);
        P3 = P[ index ];
    }
    return P3;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    else {
        resetEXP(EXP1);
        resetHP(HP1);
        resetM(M1);
        double P1 = road1( EXP1 );
        double P2 = road2( HP1, EXP1, M1, E2);
        double P3 = road3( HP1, EXP1, E2);
        if ( (P1 == 1) && (P2 == 1) && (P3 == 1) ) EXP1 = roundUp( EXP1 * 0.75 );
        else {
            double P = (P1 + P2 + P3) / 3;
            if (P < 0.5) {
                EXP1 = roundUp( EXP1 * 1.15 );
                HP1 = roundUp( HP1 * 0.85 );
            }
            else {
                EXP1 = roundUp( EXP1 * 1.2 );
                HP1 = roundUp( HP1 * 0.9 );
            }
        }
        resetEXP(EXP1);
        resetHP(HP1);
        resetM(M1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int findMax(int a[10][10], int m ,int n) {
    int max = a[m][n];
    int i1{ m };
    int j1{ n };
    while (i1 >= 0 && i1 <=9 && j1 >= 0 && j1 <= 9) {
            if (max < a[i1][j1]) max = a[i1][j1];
            i1 += 1;
            j1 += 1;
    }
    int i2{ m };
    int j2{ n };
    while (i2 >= 0 && i2 <=9 && j2 >= 0 && j2 <= 9) {
            if (max < a[i2][j2]) max = a[i2][j2];
            i2 -= 1;
            j2 -= 1;
    }
    int i3{ m };
    int j3{ n };
    while (i3 >= 0 && i3 <=9 && j3 >= 0 && j3 <= 9) {
            if (max < a[i3][j3]) max = a[i3][j3];
            i3 += 1;
            j3 -= 1;
    }
    int i4{ m };
    int j4{ n };
    while (i4 >= 0 && i4 <=9 && j4 >= 0 && j4 <= 9) {
            if (max < a[i4][j4]) max = a[i4][j4];
            i4 -= 1;
            j4 += 1;
    }
    return abs(max);
}
int count(int & count) {
    while (count > 9) count = (count/10) + (count%10);
    return count;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    resetEXP(EXP1);
    resetEXP(EXP2);
    resetHP(HP1);
    resetHP(HP2);
    int taxi[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3*j) + i*2) * (i - j);
        }
    }
    
    int count1{ 0 };
    int count2{ 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3*2)) count1 += 1;
            if (taxi[i][j] < (-E3))  count2 += 1;
        }
    }
    int x, y;
    x = count(count1);
    y = count(count2);
    int pTaxi = abs(taxi[x][y]);
    int max = findMax(taxi, x, y);
    if (max >= pTaxi) {
        EXP1 = roundUp(EXP1 * 1.12);
        HP1 = roundUp(HP1 * 1.10);
        EXP2 = roundUp(EXP2 * 1.12);
        HP2 = roundUp(HP2 * 1.10);
        resetEXP(EXP1);
        resetEXP(EXP2);
        resetHP(HP1);
        resetHP(HP2);
        return max;
    }
    else {
        EXP1 = roundUp(EXP1 * 0.88);
        HP1 = roundUp(HP1 * 0.9);
        EXP2 = roundUp(EXP2 * 0.88);
        HP2 = roundUp(HP2 * 0.9);
        resetEXP(EXP1);
        resetEXP(EXP2);
        resetHP(HP1);
        resetHP(HP2);
        return taxi[x][y];
    }
}

// Task 4
string get_se(string email, int size) {
    string se = "";
    for (int i = 0; i < size; i++) {
        if (email[i] == '@') break; 
        se = se + email[i];
    }
    return se;
}
int check_se(string pass, string se, int l1, int l2) {
    if (l2 <= l1) {
        for (int i = 0; i < l1; i++) {
            if (se[0] == pass[i]) {
                int idx = i;
                if ((l1 - i) >= l2) {
                    int count = 0;
                    for (int j = 0; j < l2; j++) {
                        if (pass[i + j] == se[j]) count += 1;
                    }
                    if (count == l2) return -(300 + i);
                }
            }
        }
    }
    return 0;
}
int check_char1(string pass, int len) {
    for (int i = 0; i < len; i++) {
        if ((pass[i] == pass[i+1]) && (pass[i+1] == pass[i+2])) return -(400 + i);
    }
    return 0;
}
int check_char2(string pass, int len) {
    int count{ 0 };
    for (int i = 0; i < len; i++) {
        if ((pass[i] == '@') || (pass[i] == '#') || (pass[i] == '%') 
                             || (pass[i] == '$') || (pass[i] == '!')) count += 1;
    }
    if (count == 0) return -5;
    else return 0;
}
int check_char3(string pass, int len){
    for (int i = 0; i < len; i++) {
        int num = (int)pass[i];
        if ((num < 33) || ((num > 37) && (num < 48)) || ((num > 57) && (num < 64)) 
                    || ((num > 90) && (num < 97)) || ((num > 122) && (num < 256)))
        return i;    
    }
    return -5;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pass = s;
    string mail = email;
    string se = get_se(mail, mail.length());

    int l1 = pass.length();
    int l2 = se.length();
    
    if (l1 < 8) return -1;
    if (l1 > 20) return -2;
    int check1 = check_se(pass, se, l1, l2);
    if (check1) return check1;
    int  check2 = check_char1(pass, l1);
    if (check2) return check2;
    int check3 = check_char2(pass, l1);
    if (check3) return check3;
    int check4 = check_char3(pass, l1);
    if (check4 != (-5)) return check4;

    return -10;
}

// Task 5
void checkPass1(string s[], int num_pwds, int arr[]) {
    int k{ 0 };
    for (int i = 0; i < num_pwds; i++) {
        if (s[i] != "0") {
            for (int j = 0; j < num_pwds; j++) {
                if ((s[j] == s[i]) && (i !=j )) {
                        arr[k]++;
                        s[j] = "0";
                }
            }
            k += 1;
        }
    }  
}
int checkPass2(string s[], int num_pwds, int arr[]){
        int count1{ 0 };
        for (int i = 0; i < num_pwds; i++) {
            if (s[i] != "0") count1 += 1;
        }
        int max1 = arr[0];
        for (int i = 1; i < count1; i++) {
            if (max1 < arr[i]) max1 = arr[i];
        }
        int count2{0};
        for (int i = 0; i < count1; i++) {
            if (max1 == arr[i]) {
                count2 += 1;
            }
        }
        int a[100];
        for (int i = 0; i < num_pwds; i++) a[i] = 0;
        int k = 0;
        for (int i = 0; i < count1; i++) {
            if (max1 == arr[i]) {
                a[k] = i;
                k += 1;
            }
        }
        int count3{ -1 }; 
        if (count2 == 1) {
            for (int i = 0; i < num_pwds; i++) {
                if (s[i] != "0") 
                count3 += 1;
                if (count3 == a[0]) return i;
            }
        }
        int b[num_pwds];
        for (int i = 0; i < num_pwds; i++) b[i] = 0;
        for (int i = 0; i < count2; i++) {
            int count4{-1};
            for (int j = 0; j < num_pwds; j++) {
                if (s[j] != "0") {
                    count4 += 1;
                    if (count4 == a[i]) {
                        string s1 = s[j];
                        b[i] = s1.length();
                    }
                }
            }
        }
        int max2 = b[0];
        for (int i = 1; i < count1; i++) {
            if (max2 < b[i]) max2 = b[i];
        }
        int result;
        bool br{};
        for (int i = 0; i < count2; i++) {
            int count5{-1};
            for (int j = 0; j < num_pwds; j++) {
                if (s[j] != "0") {
                    count5 += 1;
                    if (count5 == a[i]) {
                        if (s[j].length() == max2) {
                            result = j;
                            br = true;
                        }
                    }
                }
            if (br) break;
            }
        if (br) break;
        }
    return result;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int arr[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        arr[i] = 1;
    }
    string s[num_pwds]; 
    for (int i = 0; i < num_pwds; i++) {
        s[i] = arr_pwds[i];
    }
    checkPass1(s, num_pwds, arr);
    return checkPass2(s, num_pwds, arr);
}

int roundUp(double x) {
    int y = (int)x;
    if ((x-y) < 0.0001) return y;
    if (x > y) y += 1;
    return y;
}
int resetEXP(int & EXP) {
    if (EXP < 0) EXP = 0;
    if (EXP > 600) EXP = 600;
    return EXP;
}
int resetHP(int & HP) {
    if (HP < 0) HP = 0;
    if (HP > 666) HP = 666;
    return HP;
}int resetM(int & M) {
    if (M < 0) M = 0;
    if (M > 3000) M = 3000;
    return M;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
