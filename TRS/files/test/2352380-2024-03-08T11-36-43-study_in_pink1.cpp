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
void checkHP1  (int & HP1) {
    if (HP1 > 666) {HP1 = 666;}
    else if (HP1 < 0) {HP1 = 0;}
    }
void checkHP2  (int & HP2) {
    if (HP2 > 666) {HP2 = 666;}
    else if (HP2 < 0) {HP2 = 0;}
    }    
void checkEXP1  (int & EXP1) {    
    if (EXP1 > 600) {EXP1 = 600;}
    else if (EXP1 < 0) {EXP1 = 0;}
}
void checkEXP2  (int & EXP2) {    
    if (EXP2 > 600) {EXP2 = 600;}
    else if (EXP2 < 0) {EXP2 = 0;}
}
void checkM1  (int & M1) {
    if (M1 > 3000) {M1 = 3000;}
    else if (M1 < 0) {M1 = 0;}
}
void checkM2  (int & M2) {
    if (M2 > 3000) {M2 = 3000;}
    else if (M2 < 0) {M2 = 0;}
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99) {return -99;}
if (E1 >= 0 && E1 <= 3)  {
    if (E1 == 0) {EXP2 = EXP2 + 29;}
    else if (E1 == 1) {EXP2 = EXP2 + 45;}
    else if (E1 == 2) {EXP2 = EXP2 + 75;}
    else if (E1 == 3) {EXP2 = EXP2 + 29 + 45 + 75;}
    int D;
    D = E1 * 3 + EXP1 * 7;
    if (D % 2 == 0) {EXP1 = ceil (EXP1 + D/200.0);}
    else {EXP1 = ceil (EXP1 - D/100.0);}
 }
else if (E1 >= 4 && E1 <= 99) {
    if (E1 >= 4 && E1 <= 19) {EXP2 = ceil (EXP2 + E1/4.0 + 19);}
    else if (E1 >= 20 && E1 <= 49) {EXP2 = ceil (EXP2 + E1/9.0 + 21);}
    else if (E1 >= 50 && E1 <= 65) {EXP2 = ceil (EXP2 + E1/16.0 + 17);}
    else if (E1 >= 66 && E1 <= 79) {
        EXP2 = ceil (EXP2 + E1/4.0 + 19);
        if (EXP2 > 200) {
            EXP2 = ceil (EXP2 + E1/9.0 + 21);
        }
    }
    else {
        EXP2 = ceil (EXP2 + E1/4.0 + 19); 
        EXP2 = ceil (EXP2 + E1/9.0 + 21);
        if (EXP2 > 400) {
            EXP2 = ceil (EXP2 + E1/16.0 + 17);  
            EXP2 = ceil (EXP2 * 1.15);
            }
    }
    EXP1 = EXP1 - E1;
}
checkEXP1(EXP1);
checkEXP2(EXP2);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    checkEXP1 (EXP1);
    checkHP1 (HP1);
    checkM1 (M1);  
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {return -99;}
    int S;
    double P1;
    double N = sqrt (EXP1);
    int N1 = floor (N);
    int N2 = N1 + 1;
    if ((EXP1 - N1 * N1) < (N2 * N2 - EXP1)) {
        P1 = 1.0;
    } 
    else {
        S = N2 * N2;
        P1 = ( (EXP1 / S) + 80) / 123.0;
    }
    
    int M = M1*0.5;
    if (E2 % 2 != 0) {
        while (true) {
            if (HP1 < 200) {
                HP1 = ceil (HP1 + HP1 * 0.3); 
                checkHP1 (HP1);
                M1 = M1 - 150;
                checkM1 (M1);
            }
            else {
                HP1 = ceil (HP1 + HP1 * 0.1); 
                checkHP1 (HP1);
                M1 = M1 - 70;
                checkM1 (M1);
            }
            if (M1 < M) break;
            if (EXP1 < 400) {
                M1 = M1 - 200; 
                checkM1 (M1);
                EXP1 = ceil (EXP1 + EXP1 * 0.13);
                checkEXP1 (EXP1);
            }
            else {
                M1 = M1 - 120; 
                checkM1 (M1);
                EXP1 = ceil (EXP1 + EXP1 * 0.13);
                checkEXP1 (EXP1);
            }
            if (M1 < M) break;
            if (EXP1 < 300) {
                M1 = M1 - 100; 
                checkM1 (M1);
                EXP1 = ceil ( EXP1 - EXP1 * 0.1);
                checkEXP1 (EXP1);
            }
            else {
                M1 = M1 - 120; 
                checkM1 (M1);
                EXP1 = ceil ( EXP1 - EXP1 * 0.1);
                checkEXP1 (EXP1);
            }
            if (M1 < M) break;
        }
        HP1 = ceil (HP1 - HP1 * 0.17);
        checkHP1 (HP1);
        EXP1 = ceil (EXP1 + EXP1 * 0.17);
        checkEXP1 (EXP1);
    }
    else {
        while (true) {
        if (HP1 < 200) {
            HP1 = ceil (HP1 + HP1 * 0.3);
            checkHP1 (HP1); 
            M1 = M1 - 150;
            checkM1 (M1);
        }
        else {
            HP1 = ceil (HP1 + HP1 * 0.1); 
            checkHP1 (HP1);
            M1 = M1 - 70;
            checkM1 (M1);
        } 
        if (M1 == 0) break;
        if (EXP1 < 400) {
            M1 = M1 - 200; 
            checkM1 (M1);
            EXP1 = ceil (EXP1 + EXP1 * 0.13);
            checkEXP1 (EXP1);
        }
        else {
            M1 = M1 - 120;
            checkM1 (M1); 
            EXP1 = ceil (EXP1 + EXP1 * 0.13);
            checkEXP1 (EXP1);
        } 
        if (M1 == 0) break;
        if (EXP1 < 300) {
            M1 = M1 - 100;
            checkM1 (M1); 
            EXP1 = ceil (EXP1 - EXP1 * 0.1);
            checkEXP1 (EXP1);
        }
        else {
            M1 = M1 - 120; 
            checkM1 (M1);
            EXP1 = ceil ( EXP1 - EXP1 * 0.1);
            checkEXP1 (EXP1);
        }
        if (M1 == 0) break;
            break;}
        HP1 = ceil (HP1 - HP1 * 0.17);
        checkHP1 (HP1); 
        EXP1 = ceil ( EXP1 + EXP1 * 0.17);
        checkEXP1 (EXP1);
    }
    double P2;
    double NN = sqrt (EXP1);
    int NN1 = floor (NN);
    int NN2 = NN1 + 1;
    if ((EXP1 - NN1 * NN1) < (NN2 * NN2 - EXP1)) {
        P2 = 1.0;
    } 
    else {
        S = NN2 * NN2;
        P2 = ( (EXP1 / S) + 80.0) / 123.0;
    }
    double P3;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
        if (E2 < 10) {
            i = E2;
            P3 = P[i] / 100.0;
        } else {
            i = ((E2 / 10) + (E2 % 10)) % 10;
            P3 = P[i] / 100.0; 
        } 
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = ceil ( EXP1 - EXP1 * 0.25);
        checkEXP1 (EXP1);
    }
    else {
        double P4;
        P4 = (P1 + P2 + P3)/3.0;
        if (P4 < 0.5) {
            HP1 = ceil (HP1 - HP1 * 0.15);
            checkHP1 (HP1); 
            EXP1 = ceil (EXP1 + EXP1 * 0.15);
            checkEXP1 (EXP1);
        }
        else {
            HP1 = ceil (HP1 - HP1 * 0.1);
            checkHP1 (HP1); 
            EXP1 = ceil (EXP1 + EXP1 * 0.2);
            checkEXP1 (EXP1);
        }
    }  
    return HP1 + EXP1 + M1;
}
                

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    int map[10][10] = {0};
    int taxi;
    int dem1 = 0;
    int dem2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (map[i][j] > E3 * 2) {
                dem1 += 1;
            }
            if (map[i][j] < (-E3)) {
                dem2 += 1;
            }
        }
    }     
    int a = dem1;
    int b = dem2;   
    while (a >= 10) {
        a = (a / 10) + (a % 10);
    }
    dem1 = a;
    while (b >= 10) {
        b = (b / 10) + (b % 10);
    }
    dem2 = b;

    taxi = map[dem1][dem2];
    int m1 = dem1;
    int m2 = dem2;
    int max1 = map[dem1][dem2];
    int max2 = map[dem1][dem2];
    int max3 = map[dem1][dem2];
    int max4 = map[dem1][dem2];
    for (int i = 1; i < m1 && i < m2; i++) {
        if (max1 < map[m1 - i][m2 - i]) {
            max1 = map[m1 - i][m2 - i];
        }
    }
    int m3 = dem1;
    int m4 = dem2;
    for (int i = 1; i < m3 && i < (10 - m4); i++) {
        if (max2 < map[m3 - i][m4 + i]) {
            max2 = map[m3 - i][m4 + i];
        }
    }
    int m5 = dem1;
    int m6 = dem2;
    for (int i = 1; i < (10 - m5) && i < (10 - m6); i++) {
        if (max3 < map[m5 + i][m6 + i]) {
            max3 = map[m5 + i][m6 + i];
        }
    }
    int m7 = dem1;
    int m8 = dem2;
    for (int i = 1; i < (10 - m7) && i < m8; i++) {
        if (max4 < map[m7 + i][m8 - i]) {
            max4 = map[m7 + i][m8 - i];
        }
    }
    int max = max1;
    if (max2 > max)
        max = max2;
    if (max3 > max)
        max = max3;
    if (max4 > max)
        max = max4;
    if (abs(taxi) > abs(max)) {
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        checkEXP1(EXP1);
        HP1 = ceil(HP1 - HP1 * 0.1);
        checkHP1(HP1);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
        checkEXP2(EXP2);
        HP2 = ceil(HP2 - HP2 * 0.1);
        checkHP2(HP2);
        return taxi;
    } else {
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        checkEXP1(EXP1);
        HP1 = ceil(HP1 + HP1 * 0.1);
        checkHP1(HP1);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
        checkEXP2(EXP2);
        HP2 = ceil(HP2 + HP2 * 0.1);
        checkHP2(HP2);
        return max;
    }
    return -1;
}


// Task 4
int checkPassword(const char * s, const char * e) {
    string pass(s);
    string email(e);
    if (pass.length() < 8) {
        return -1;
    } else if (pass.length() > 20) {
        return -2;
    }
    size_t pos = email.find('@');
    if (pos == string::npos) {
        return -3;
    }
    string emailname = email.substr(0, pos);
    size_t emailnameIndex = pass.find(emailname);
    if (emailnameIndex != string::npos) {
        return -(300 + emailnameIndex);
    }
    for (size_t i = 0; i < pass.length() - 2; ++i) {
        if (pass[i] == pass[i + 1] && pass[i] == pass[i + 2]) {
            return -(400 + i);
        }
    }
    bool specialchar = false;
    for (char c : pass) {
        if (c == '@' || c == '#' || c == '$' || c == '%' || c == '!') {
            specialchar = true;
            break;
        }
    }
    if (!specialchar) {
        return -5;
    }
    for (size_t i = 0; i < pass.length(); ++i) {
        char c = pass[i];
        if (!(isalnum(c) || c == '@' || c == '#' || c == '$' || c == '%' || c == '!')) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcount = 0;
    int maxlength = 0;
    const char* password = NULL;
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > maxcount || (count == maxcount && strlen(arr_pwds[i]) > maxlength)) {
            maxcount = count;
            maxlength = strlen(arr_pwds[i]);
            password = arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], password) == 0) {
            return i;
        }
    }
    return -1;
}











////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////