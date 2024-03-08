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

int hpScope(int hp) {
    if (hp > 666) hp = 666;
    else if (hp < 0) hp = 0;
    return hp;
}
int expScope(int exp) {
    if (exp > 600) exp = 600;
    else if (exp < 0) exp = 0;
    return exp;
}
int mScope(int m) {
    if (m > 3000) m = 3000;
    else if (m < 0) m = 0;
    return m;
}
int neareastSquareNum(int num) {
    int a = int((sqrt(num) + 0.999));
    int b = a - 1;
    if (abs(num - a * a) < abs(num - b * b)) return a * a;
    else return b * b;
}
int getMaxCrossElement(int matran[][10], int i, int j) {
    int arr[100];
    int n = 0;
    int a = i; int b = j;
    while (a >= 0 && b >= 0) {
        arr[n] = matran[a][b];
        a -= 1; b -= 1; n += 1;
    }
    a = i; b = j;
    while (a >= 0 && b <= 9) {
        arr[n] = matran[a][b];
        a -= 1; b += 1; n += 1;
    }
    a = i; b = j;
    while (a <= 9 && b >= 0) {
        arr[n] = matran[a][b];
        a += 1; b -= 1; n += 1;
    }
    a = i; b = j;
    while (a <= 9 && b <= 9) {
        arr[n] = matran[a][b];
        a += 1; b += 1; n += 1;
    }
    int z = arr[0];
    for (int a = 1; a < n; a++) {
        if (z < arr[a]) z = arr[a];
    }
    return z;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    exp1 = expScope(exp1);
    exp2 = expScope(exp2);
    if (e1 >= 0 && e1 <= 99) {
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) exp2 += 29;
            else if (e1 == 1) exp2 += 45;
            else if (e1 == 2) exp2 += 75;
            else exp2 = exp2 + 29 + 45 + 75;
            exp2 = expScope(exp2);
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) exp1 = ceil(exp1 + (double)D / 200);
            else exp1 = ceil(exp1 - (double)D / 100);
            exp1 = expScope(exp1);
        }

        else if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) exp2 = expScope(ceil(exp2 + (double)e1 / 4 + 19));
            else if (e1 >= 20 && e1 <= 49) exp2 = expScope(ceil(exp2 + (double)e1 / 9 + 21));
            else if (e1 >= 50 && e1 <= 65) exp2 = expScope(ceil(exp2 + (double)e1 / 16 + 17));
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = expScope(ceil(exp2 + (double)e1 / 4 + 19));
                if (exp2 > 200) exp2 = expScope(ceil(exp2 + (double)e1 / 9 + 21));
            }
            else {
                exp2 = expScope(ceil(exp2 + (double)e1/ 4 + 19));
                exp2 = expScope(ceil(exp2 + (double)e1/ 9 + 21));
                if (exp2 > 400) {
                    exp2 = expScope(ceil(exp2 + (double)e1 / 16 + 17));
                    exp2 = expScope(int(exp2 * 1.15 + 0.999999));
                }
            }
            exp1 = expScope(exp1 - e1);
        }

        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    HP1 = hpScope(HP1);
    EXP1 = expScope(EXP1);
    M1 = mScope(M1);
    if (E2 >= 0 && E2 <= 99) {
        double P1, P2, P3, P;
        //Con duong 1
        int S = neareastSquareNum(EXP1);
        if (EXP1 >= S) P1 = 1;
        else P1 = ((double)EXP1 / S + 80) / 123;
        
        //Con duong 2
        double half = (double)M1 / 2;
        if (M1 == 0) goto label;
        if (E2 % 2 == 1) {
            while (E2 % 2 == 1) {
                //Do an thuc uong
                if (HP1 < 200) {
                    HP1 = hpScope(int(HP1 * 1.3 + 0.999999));
                    M1 = mScope(M1 - 150);
                    if (M1 < half) break;
                }
                else {
                    HP1 = hpScope(int(HP1 * 1.1 + 0.999999));
                    M1 = mScope(M1 - 70);
                    if (M1 < half) break;
                }
                //Taxi xe ngua
                if (EXP1 < 400) {
                    M1 = mScope(M1 - 200);
                    EXP1 = expScope(int(EXP1 * 1.13 + 0.999999));
                    if (M1 < half) break;
                }
                else {
                    M1 = mScope(M1 - 120);
                    EXP1 = expScope(int(EXP1 * 1.13 + 0.999999));
                    if (M1 < half) break;
                }
                //Vo gia cu
                if (EXP1 < 300) {
                    M1 = mScope(M1 - 100);
                    EXP1 = expScope(int(EXP1 * 0.9 + 0.999999));
                    if (M1 < half) break;
                }
                else {
                    M1 = mScope(M1 - 120);
                    EXP1 = expScope(int(EXP1 * 0.9 + 0.999999));
                    if (M1 < half) break;
                }
            }
        }
        
        else if (E2 % 2 == 0) {
            //Do an thuc uong
            if (HP1 < 200) {
                HP1 = hpScope(int(HP1 * 1.3 + 0.999999));
                M1 = mScope(M1 - 150);
                if (M1 == 0) goto label;
            }
            else {
                HP1 = hpScope(int(HP1 * 1.1 + 0.999999));
                M1 = mScope(M1 - 70);
                if (M1 == 0) goto label;
            }
            //Taxi xe ngua
            if (EXP1 < 400) {
                M1 = mScope(M1 - 200);
                EXP1 = expScope(int(EXP1 * 1.13 + 0.999999));
                if (M1 == 0) goto label;
            }
            else {
                M1 = mScope(M1 - 120);
                EXP1 = expScope(int(EXP1 * 1.13 + 0.999999));
                if (M1 == 0) goto label;
            }
            //Vo gia cu
            if (EXP1 < 300) {
                M1 = mScope(M1 - 100);
                EXP1 = expScope(int(EXP1 * 0.9 + 0.999999));
                if (M1 == 0) goto label;
            }
            else {
                M1 = mScope(M1 - 120);
                EXP1 = expScope(int(EXP1 * 0.9 + 0.999999));
                if (M1 == 0) goto label;
            }
        }
        label:
        HP1 = hpScope(int(HP1 * 0.83 + 0.999999));
        EXP1 = expScope(int(EXP1 * 1.17 + 0.999999));
        S = neareastSquareNum(EXP1);
        if (EXP1 >= S) P2 = 1;
        else P2 = ((double)EXP1 / S + 80) / 123;
        
        //Con duong 3
        int p[10] = { 32,47,28,79,100,50,22,83,64,11 };
        int i;
        if (E2 < 10) i = E2;
        else i = ((E2 / 10) + (E2 % 10)) % 10;
        P3 = (double)p[i] / 100;

        //Sau 3 con duong
        if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = expScope(int(EXP1 * 0.75 + 0.999999));
        else {
            P = (P1 + P2 + P3) / 3;
            if (P < 0.5) {
                HP1 = hpScope(int(HP1 * 0.85 + 0.999999));
                EXP1 = expScope(int(EXP1 * 1.15 + 0.999999));
            }
            else {
                HP1 = hpScope(int(HP1 * 0.9 + 0.999999));
                EXP1 = expScope(int(EXP1 * 1.2 + 0.999999));
            }
        }
        
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    HP1 = hpScope(HP1);
    EXP1 = expScope(EXP1);
    HP2 = hpScope(HP2);
    EXP2 = expScope(EXP2);
    if (E3 >= 0 && E3 <= 99) {
        int matran[10][10];
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                matran[x][y] = ((E3 * y) + (x * 2)) * (x - y);
            }
        }
        int i = 0, j = 0, diemtaxi, diemholmes, outval;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                if (matran[x][y] > (E3 * 2)) i += 1;
                else if (matran[x][y] < (-E3)) j += 1;
            }
        }
        while (i > 9) i = (i / 10) + (i % 10);
        while (j > 9) j = (j / 10) + (j % 10);
        diemtaxi = matran[i][j];
        diemholmes = abs(getMaxCrossElement(matran, i, j));
        if (abs(diemtaxi) > diemholmes) {
            EXP1 = expScope(int(EXP1 * 0.88 + 0.999));
            EXP2 = expScope(int(EXP2 * 0.88 + 0.999));
            HP1 = hpScope(int(HP1 * 0.9 + 0.999));
            HP2 = hpScope(int(HP2 * 0.9 + 0.999));
            outval = diemtaxi;
        }
        else {
            EXP1 = expScope(int(EXP1 * 1.12 + 0.999));
            EXP2 = expScope(int(EXP2 * 1.12 + 0.999));
            HP1 = hpScope(int(HP1 * 1.1 + 0.999));
            HP2 = hpScope(int(HP2 * 1.1 + 0.999));
            outval = diemholmes;
        }
        return outval;
    }
    else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int emlength = strlen(email);
    int slength = strlen(s);
    int outval = -10;
    string p = s; string em = email;
    int i = 0;
    while (i < emlength) {
        if (em.substr(i,1) == "@") break;
        else i += 1;
    }
    string se(email, 0, i);
    int q = p.find(se);
    int j = 0;
    int sc1 = p.find("@");
    int sc2 = p.find("#");
    int sc3 = p.find("%");
    int sc4 = p.find("$");
    int sc5 = p.find("!");
    //Do dai chuoi
    if (slength < 8) {
        outval = -1;
        goto label;
    }
    if (slength > 20) {
        outval = -2;
        goto label;
    }
    //Chua se
    if (q >= 0 && q < slength) {
        outval = -(300 + q);
        goto label;
    }
    //2 ky tu lien tiep
    while (j < slength - 2) {
        if (s[j] == s[j + 1] && s[j + 1] == s[j + 2]) break;
        else j += 1;
    }
    if (j < slength - 2) {
        outval = -(400 + j);
        goto label;
    }
    //Khong chua ky tu dac biet
    if (sc1 < 0 && sc2 < 0 && sc3 < 0 && sc4 < 0 && sc5 < 0) outval = -5;
    //Cac truong hop con lai
    for (int k = 0; k < strlen(s); k++) {
        if (p.substr(k, 1) == "`" || p.substr(k, 1) == "~" || p.substr(k, 1) == "^" || p.substr(k, 1) == " " ||
            p.substr(k, 1) == "*" || p.substr(k, 1) == "(" || p.substr(k, 1) == ")" || p.substr(k, 1) == "-" ||
            p.substr(k, 1) == "_" || p.substr(k, 1) == "=" || p.substr(k, 1) == "+" || p.substr(k, 1) == "[" ||
            p.substr(k, 1) == "]" || p.substr(k, 1) == "{" || p.substr(k, 1) == "}" || p.substr(k, 1) == "\\" ||
            p.substr(k, 1) == "|" || p.substr(k, 1) == ";" || p.substr(k, 1) == ":" || p.substr(k, 1) == "'" ||
            p.substr(k, 1) == "," || p.substr(k, 1) == "." || p.substr(k, 1) == "/" || p.substr(k, 1) == "<" ||
            p.substr(k, 1) == "<" || p.substr(k, 1) == ">" || p.substr(k, 1) == "?" || p.substr(k, 1) == "\"") {
            outval = k;
            goto label;
        }
    }
    label:
    return outval;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string mode[num_pwds];
    int highestNumOccur = 0;
    for (int i = 0; i < num_pwds - 1; i++) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) count += 1;
        }
        if (highestNumOccur < count) highestNumOccur = count;
    }
    for (int i = 0; i < num_pwds - 1; i++) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) count += 1;
        }
        if (count == highestNumOccur) {
            mode[i] = arr_pwds[i];
        }
    }
    int len = mode[0].length();
    int vitri = 0;
    for (int i = 1; i < num_pwds; i++) {
        if (len < mode[i].length()) {
            len = mode[i].length();
            vitri = i;
        }
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////