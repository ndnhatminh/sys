#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
int checkEXP(int EXP) {
    if (EXP < 0) return  0;
    if (EXP > 600) return  600;
    else return EXP;
}
int checkHP(int HP) {
    if (HP < 0) return 0;
    if (HP > 666) return 666;
    else return HP;
}
int checkM(int M) {
    if (M < 0) return 0;
    if (M > 3000) return 3000;
    return M;
}
int round_value(double a) {
    int b = a;
    if ((a - b) > 0.000001) return b + 1;
    else return b;
}
 //============== funtion task2 ===============//  
int find_least_chinhphuong(int EXP) {
    int cp = sqrt(EXP);
    if (cp * cp == EXP) return EXP;
    if ((EXP - cp * cp) > ((cp + 1) * (cp + 1) - EXP)) return (cp + 1) * (cp + 1);
    else return cp * cp;
}
int chisoxs(int E) {
    int a = E % 10;
    int b = E / 10;
    if ((a + b) < 10) return (a + b);
    if ((a + b) >= 10) return (a + b - 10);
    return E;
}
int chiso(int E) {
    int a = E % 10;
    int b = E / 10;
    int c = a + b;
    if ((a + b) < 10) return (a + b);
    if ((a + b) >= 10)  return (c % 10 + c / 10);
    return E;
}
float xacsuatconduong1(int EXP1) {
    float P1;
    int S = find_least_chinhphuong(EXP1);
    if (EXP1 >= S) P1 = 1;
    else P1 = ((float)EXP1 / S + 80) / 123;
    return P1;
}
float xacsuatconduong2le(int EXP1, int HP1, int M1) {

    float M = (float)M1 * 0.5;
    while (M > 0) {
        //======= hanh dong 1======//
        if (HP1 < 200) {
            HP1 = ceil((float)HP1 * 1.3);  M = M - 150;
        }
        else {
            HP1 = ceil((float)HP1 * 1.1); M = M - 70;
        }

        if (M > 0) {
            //====== hanh dong 2 ======//
            if (EXP1 < 400) {
                EXP1 = ceil((float)EXP1 * 1.13); M = M - 200;
            }
            else {
                EXP1 = ceil((float)EXP1 * 1.13); M = M - 120;
            }

            if (M > 0) {
                //====== hanh dong 3=======//
                if (EXP1 < 300) {
                    EXP1 = ceil((float)EXP1 * 0.9); M = M - 100;
                }
                else {
                    EXP1 = ceil((float)EXP1 * 0.9); M = M - 120;
                }
            }
        }
    }
    if (M < 0) {
        HP1 = ceil((float)HP1 * 0.83);
        EXP1 = ceil((float)EXP1 * 1.17);
    }
    M1 = M1 - 445 + M;
    float P2;
    EXP1 = checkEXP(EXP1);
    int S = find_least_chinhphuong(EXP1);
    if (EXP1 >= S) P2 = 1;
    else P2 = ((float)EXP1 / S + 80) / 123;
    return P2;

}
float xacsuatconduong2chan(int EXP1, int HP1, int M1) {
    if (HP1 < 200) {
        HP1 = round_value((float)HP1 * 1.3);  M1 = M1 - 150; M1 = checkM(M1);
    }
    else {
        HP1 = round_value((float)HP1 * 1.1); M1 = M1 - 70; M1 = checkM(M1);
    }
    HP1 = checkHP(HP1);
    //====== hanh dong 2 ======//
    if (EXP1 < 400 && M1>0) {
        EXP1 = round_value((float)EXP1 * 1.13); M1 = M1 - 200; M1 = checkM(M1);
    }
    if (EXP1 >= 400 && M1 > 0) {
        EXP1 = round_value((float)EXP1 * 1.13); M1 = M1 - 120; M1 = checkM(M1);
    }
    EXP1 = checkEXP(EXP1);
    //====== hanh dong 3=======//
    if (EXP1 < 300 && M1>0) {
        EXP1 = round_value((float)EXP1 * 0.9); M1 = M1 - 100; M1 = checkM(M1);
    }
    if (EXP1 >= 300 && M1 > 0) {
        EXP1 = round_value((float)EXP1 * 0.9); M1 = M1 - 120; M1 = checkM(M1);
    }
    EXP1 = checkEXP(EXP1);

    HP1 = round_value((float)HP1 * 0.83);
    EXP1 = round_value((float)EXP1 * 1.17);
    float P2;
    EXP1 = checkEXP(EXP1);
    int S = find_least_chinhphuong(EXP1);
    if (EXP1 >= S) P2 = 1;
    else P2 = ((float)EXP1 / S + 80) / 123;
    return P2;
}
float xacsuatconduong3(int E2) {

    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int n = chisoxs(E2);
    float  P3 = P[n];
    return P3 / 100.0;
}
//================ funtion task 3 ===============//
int maxleft(int E3) {
    int toado[10][10] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            toado[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    int sogtduong = 0;
    int sogtam = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (toado[i][j] > (E3 * 2)) sogtduong += 1;
            if (toado[i][j] < (-E3)) sogtam += 1;
        }
    }
    int max1 = toado[chiso(sogtduong)][chiso(sogtam)];
    int max2 = toado[chiso(sogtduong)][chiso(sogtam)];
    for (int i = chiso(sogtduong), j = chiso(sogtam); i > 0 && j < 9; i--, j++) {
        if (toado[i][j] < toado[i - 1][j + 1]) max1 = toado[i - 1][j + 1];
    }
    for (int i = chiso(sogtduong), j = chiso(sogtam); i < 9 && j > 0; i++, j--) {
        if (toado[i][j] < toado[i + 1][j - 1]) max2 = toado[i + 1][j - 1];
    }
    if (max1 > max2) return max1;
    else return max2;
}
int maxright(int E3) {
    int toado[10][10] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            toado[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    int sogtduong = 0;
    int sogtam = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (toado[i][j] > (E3 * 2)) sogtduong += 1;
            if (toado[i][j] < (-E3)) sogtam += 1;
        }
    }
    int max1 = toado[chiso(sogtduong)][chiso(sogtam)];
    int max2 = toado[chiso(sogtduong)][chiso(sogtam)];
    for (int i = chiso(sogtduong), j = chiso(sogtam); i > 0 && j > 0; i--, j--) {
        if (toado[i][j] < toado[i - 1][j - 1]) max1 = toado[i - 1][j - 1];
    }
    for (int i = chiso(sogtduong), j = chiso(sogtam); i < 9 && j < 9; i++, j++) {
        if (toado[i][j] < toado[i + 1][j + 1]) max2 = toado[i + 1][j + 1];
    }
    if (max1 > max2) return max1;
    else return max2;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    //check input
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    if (e1 < 0 || e1>99) return -99;
    //=======================================================================//
    if (e1 >= 0 && e1 <= 3) {
        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) {

            exp1 = ceil(exp1 + (float)D / 200);
            exp1 = checkEXP(exp1);
        }
        else {

            exp1 = ceil(exp1 - (float)D / 100);
            exp1 = checkEXP(exp1);
        }
        if (e1 == 0)  exp2 = exp2 + 29;
        if (e1 == 1)  exp2 = exp2 + 45;
        if (e1 == 2)  exp2 = exp2 + 75;
        if (e1 == 3)  exp2 = exp2 + 29 + 45 + 75;
        exp2 = checkEXP(exp2);
    }
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
        }
        if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + (float)e1 / 9 + 21);
        }
        if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + (float)e1 / 16 + 17);
        }
        if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
            if (exp2 > 200) {
                exp2 = ceil(exp2 + (float)e1 / 9 + 21);
            }
        }
        if (e1 >= 80 && e1 <= 90) {
            exp2 = ceil(exp2 + (float)e1 * 13 / 36 + 40);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (float)e1 / 16 + 17);
                exp2 = ceil((float)exp2 * 1.15);
            }
        }
        exp1 -= e1;
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
    }
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E3) {
    // TODO: Complete this function
    //===== check input ==================//
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkM(M1);
    //======================================//

    if (E3 < 0 && E3>99) return -99;
    if (E3 % 2 != 0) {
        float P1 = xacsuatconduong1(EXP1);
        float P2 = xacsuatconduong2le(EXP1, HP1, M1);
        float P3 = xacsuatconduong3(E3);

        float M = (float)M1 * 0.5;
        while (M > 0) {
            //======= hanh dong 1======//
            if (HP1 < 200) {
                HP1 = round_value((float)HP1 * 1.3);  M = M - 150;
            }
            else {
                HP1 = round_value((float)HP1 * 1.1); M = M - 70;
            }

            if (M > 0) {
                //====== hanh dong 2 ======//
                if (EXP1 < 400) {
                    EXP1 = round_value((float)EXP1 * 1.13); M = M - 200;
                }
                else {
                    EXP1 = round_value((float)EXP1 * 1.13); M = M - 120;
                }

                if (M > 0) {
                    //====== hanh dong 3=======//
                    if (EXP1 < 300) {
                        EXP1 = round_value((float)EXP1 * 0.9); M = M - 100;
                    }
                    else {
                        EXP1 = round_value((float)EXP1 * 0.9); M = M - 120;
                    }
                }
            }
        }
        if (M < 0) {
            HP1 = round_value((float)HP1 * 0.83);
            EXP1 = round_value((float)EXP1 * 1.17);
        }
        M1 = round_value(0.5 * M1 + M);
        EXP1 = checkEXP(EXP1);

        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = round_value((float)EXP1 * 0.75);
        }
        else {
            float P = (P1 + P2 + P3) / 3.0;
            if (P < 0.5) {
                HP1 = round_value((float)HP1 * 0.85);
                EXP1 = round_value((float)EXP1 * 1.15);
            }
            else {
                HP1 = round_value((float)HP1 * 0.9);
                EXP1 = round_value((float)EXP1 * 1.2);
            }
        }


        HP1 = checkHP(HP1);
        EXP1 = checkEXP(EXP1);

    }
    if (E3 % 2 == 0) {
        if (HP1 < 200) {
            HP1 = round_value((float)HP1 * 1.3);  M1 = M1 - 150; M1 = checkM(M1);
        }
        else {
            HP1 = round_value((float)HP1 * 1.1); M1 = M1 - 70; M1 = checkM(M1);
        }
        HP1 = checkHP(HP1);
        //====== hanh dong 2 ======//
        if (EXP1 < 400 && M1>0) {
            EXP1 = round_value((float)EXP1 * 1.13); M1 = M1 - 200; M1 = checkM(M1);
        }
        if (EXP1 >= 400 && M1 > 0) {
            EXP1 = round_value((float)EXP1 * 1.13); M1 = M1 - 120; M1 = checkM(M1);
        }
        EXP1 = checkEXP(EXP1);
        //====== hanh dong 3=======//
        if (EXP1 < 300 && M1>0) {
            EXP1 = round_value((float)EXP1 * 0.9); M1 = M1 - 100; M1 = checkM(M1);
        }
        if (EXP1 >= 300 && M1 > 0) {
            EXP1 = round_value((float)EXP1 * 0.9); M1 = M1 - 120; M1 = checkM(M1);
        }
        EXP1 = checkEXP(EXP1);

        HP1 = round_value((float)HP1 * 0.83);
        EXP1 = round_value((float)EXP1 * 1.17);
        EXP1 = checkEXP(EXP1);

        float P1 = xacsuatconduong1(EXP1);
        float P2 = xacsuatconduong2chan(EXP1, HP1, M1);
        float P3 = xacsuatconduong3(E3);
        float P = (P1 + P2 + P3) / 3.0;
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = round_value(EXP1 * 0.75);
        }


        else if (P < 0.5) {
            HP1 = round_value((float)HP1 * 0.85);
            EXP1 = round_value((float)EXP1 * 1.15);
        }

        else {
            HP1 = round_value((float)HP1 * 0.9);
            EXP1 = round_value((float)EXP1 * 1.2);
        }

        EXP1 = checkEXP(EXP1);
        HP1 = checkHP(HP1);

    }
    return M1 + HP1 + EXP1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    //======= check input===========//
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    HP2 = checkHP(HP2);
    EXP2 = checkEXP(EXP2);
    if (E3 < 0 && E3>99) return -99;
    //===============================//
    else {
        int toado[10][10] = { 0 };
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                toado[i][j] = (E3 * j + i * 2) * (i - j);
            }
        }
        int sogtduong = 0;
        int sogtam = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (toado[i][j] > (E3 * 2)) sogtduong += 1;
                if (toado[i][j] < (-E3)) sogtam += 1;
            }
        }
        int i = chiso(sogtduong);
        int j = chiso(sogtam);
        int scoretaxi = toado[i][j];
        int scoreSW;
        if (maxleft(E3) < maxright(E3)) scoreSW = maxright(E3);
        else scoreSW = maxleft(E3);
        if (abs(scoretaxi) > abs(scoreSW)) {
            EXP1 = ceil((float)EXP1 * 0.88);
            EXP2 = ceil((float)EXP2 * 0.88);
            HP1 = ceil((float)HP1 * 0.9);
            HP2 = ceil((float)HP2 * 0.9);
            EXP1 = checkEXP(EXP1);
            EXP2 = checkEXP(EXP2);
            HP1 = checkHP(HP1);
            HP2 = checkHP(HP2);
            return scoretaxi;
        }
        else {
            EXP1 = ceil((float)EXP1 * 1.12);
            EXP2 = ceil((float)EXP2 * 1.12);
            HP1 = ceil((float)HP1 * 1.1);
            HP2 = ceil((float)HP2 * 1.1);
            EXP1 = checkEXP(EXP1);
            EXP2 = checkEXP(EXP2);
            HP1 = checkHP(HP1);
            HP2 = checkHP(HP2);
            return scoreSW;
        }
    }

    return -1;
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string se, password, chuoiemail;
    password = s;
    chuoiemail = email;
    int lenemail = chuoiemail.length();
    int lens = password.length();
    for (int i = 0; i < (lenemail); i++) {
        if (email[i] != '@') se = se + email[i];
        else break;
    }
    if (lens < 8) return -1;
    if (lens > 20) return -2;
    int  sei = password.find(se);
    if (sei >= 0 && sei <= (lens - 1)) return -(300 + sei);
    for (int i = 0; i < (lens - 1); i++) {
        if (password[i] == password[i + 1]) {
            return -(400 + i);
            break;
        }
    }
    for (int i = 0; i < lens; i++) {
        if (s[i] != '@' && s[i] != '#' && s[i] != '$' && s[i] != '%' && s[i] != '!') {
            return -5;
            break;
        }
    }
    for (int i = 0; i < lens; i++) {

        if (s[i] >= '0' && s[i] <= '9' || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] < 'z') || (s[i] == '!') || (s[i] >= '#' && s[i] <= '%') || (s[i] == '@'))
        {
            return -10;   break;
        }
        else {
            break;
            return i;
        }
    }



    return -99;

}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    if (num_pwds == 0) return -1;
    int repeat[num_pwds - 1];
    int count = 0;
    for (int i = 0; i < num_pwds; i++) {
        count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j])   count += 1;
        }
        repeat[i] = count - 1;

    }
    int max = repeat[0];
    int a=0;
    for (int i = 1; i < num_pwds; i++) {
        if (max < repeat[i]) {
            max = repeat[i];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (max == repeat[i]) {
            a = i;
            break;
        }
    }
    for (int j = 0; j < num_pwds; j++) {
        if (max == repeat[j]) {
            if (strlen(arr_pwds[a]) < strlen(arr_pwds[j]))  a = j;

        }
    }
    return a;  
    
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////