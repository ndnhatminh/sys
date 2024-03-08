#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& exp1,
    int& exp2,
    int& M1,
    int& M2,
    int& e1,
    int& E2,
    int& E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> exp1 >> exp2
            >> M1 >> M2
            >> e1 >> E2 >> E3;
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
int A(float ip, char b) {
    int op;
    if (int(ip) == ip) { op = ip; }
    else { op = int(ip) + 1; }
    switch (b) {
    case 1://HP
        if (op > 666) { op = 666; } if (op < 0) { op = 0; }
        break;
    case 2://EXP
        if (op > 600) { op = 600; } if (op < 0) { op = 0; }
        break;
    case 3://M
        if (op > 3000) { op = 3000; } if (op < 0) { op = 0; }
        break;
    default: break;
    }
        return op;    
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    exp1 = A(exp1, 2); exp2 = A(exp2, 2);
    if (e1 > 99 || e1 < 0) return -99;
    else {
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) {
                exp2 = A(exp2 + 29.0, 2);
            }
            else if (e1 == 1) {
                exp2 = A(exp2 + 45.0, 2);
            }
            else if (e1 == 2) {
                exp2 = A(exp2 + 75.0, 2);
            }
            else {
                exp2 = A(exp2 + 29.0 + 45.0 + 75.0, 2);
            }
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 = A(exp1 + D / 200.0, 2);
            }
            else {
                exp1 = A(exp1 - D / 100.0, 2);
            }
        }
        else if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) {
                exp2 = A(exp2 + (e1 / 4.0 + 19.0), 2);
            }
            else if (e1 >= 20 && e1 <= 49) {
                exp2 = A(exp2 + (e1 / 9.0 + 21.0), 2);
            }
            else if (e1 >= 50 && e1 <= 65) {
                exp2 = A(exp2 + (e1 / 16.0 + 17.0), 2);
            }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = A(exp2 + (e1 / 4.0 + 19.0), 2);
                if (exp2 > 200) {
                    exp2 = A(exp2 + (e1 / 9.0 + 21.0), 2);
                }
            }
            else {
                exp2 = A(exp2 + (e1 / 4.0 + 19.0), 2);
                exp2 = A(exp2 + (e1 / 9.0 + 21.0), 2);
                if (exp2 > 400) {
                    exp2 = A(exp2 + (e1 / 16.0 + 17.0), 2);
                    exp2 = A(exp2 * 1.15, 2);
                }
            }
            exp1 = A(exp1 - e1, 2);
        }
        return exp1 + exp2;
    }
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    EXP1 = A(EXP1, 2); HP1 = A(HP1, 1); M1 = A(M1, 3);
    if (E2 > 99 || E2 < 0) return -99;
    else {
        float P1;
        float n = sqrt(EXP1);
        if ((n == int(n)) || ((int(n) + 1) * (int(n) + 1) - EXP1) > (EXP1 - int(n) * int(n))) { P1 = 1; }
        else { P1 = ((EXP1 / ((int(n) + 1) * (int(n) + 1))) + 80.0) / 123.0; }

        float m = 0.5 * M1;
        if (E2 % 2 == 1) {
            while (0 != 1) {
                if (HP1 < 200) { HP1 = A(HP1 * 1.3, 1); M1 = A(M1 - 150, 3); }
                else { HP1 = A(HP1 * 1.1, 1); M1 = A(M1 - 70, 3); }
                if (M1 < m) break;
                if (EXP1 < 400) { EXP1 = A(EXP1 * 1.13, 2); M1 = A(M1 - 200, 3); }
                else { EXP1 = A(EXP1 * 1.13, 2); M1 = A(M1 - 120, 3); }
                if (M1 < m) break;
                if (EXP1 < 300) { M1 = A(M1 - 100, 3); EXP1 = A(EXP1 - EXP1 * 0.1, 2); }
                else { M1 = A(M1 - 120, 3); EXP1 = A(EXP1 - EXP1 * 0.1, 2); }
                if (M1 < m) break;
            }
            HP1 = A(HP1 * 0.83, 1); EXP1 = A(EXP1 * 1.17, 2);
        }
        else {
            if (HP1 < 200) { HP1 = A(HP1 * 1.3, 1); M1 = A(M1 - 150, 3); }
            else { HP1 = A(HP1 * 1.1, 1); M1 = A(M1 - 70, 3); }
            if (A(M1, 3) == 0) { HP1 = A(HP1 * 0.83, 1); EXP1 = A(EXP1 * 1.17, 2); }
            else {
                if (EXP1 < 400) { EXP1 = A(EXP1 * 1.13, 2); M1 = A(M1 - 200, 3); }
                else { EXP1 = A(EXP1 * 1.13, 2); M1 = A(M1 - 120, 3); }
                if (A(M1, 3) == 0) { HP1 = A(HP1 * 0.83, 1); EXP1 = A(EXP1 * 1.17, 2); }
                else {
                    if (EXP1 < 300) { M1 = A(M1 - 100, 3); EXP1 = A(EXP1 - EXP1 * 0.1, 2); }
                    else { M1 = A(M1 - 120, 3); EXP1 = A(EXP1 - EXP1 * 0.1, 2); }
                }
            }
        }
        float P2 = 1.0;
        float p = sqrt(EXP1);
        if ((p == int(p)) || ((int(p) + 1) * (int(p) + 1) - EXP1) > (EXP1 - int(p) * int(p))) { P1 = 1; }
        else { P2 = ((EXP1 / ((int(p) + 1) * (int(p) + 1))) + 80.0) / 123.0; }

        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        float P3;
        if (10 - E2 > 0) { P3 = P[E2] * 0.01; }
        else {
            int q = int(E2 / 10) + (E2 % 10);
            int r;
            if (10 - q > 0) { r = q; }
            else { r = int(q / 10); }
            P3 = P[r] * 0.01;
        }
        if (P1 == 1 && P2 == 1 && P3 == 1) { EXP1 = A(EXP1 * 0.75, 2); }
        else if ((P1 + P2 + P3) / 3 < 0.5) { HP1 = A(HP1 * 0.85, 1); EXP1 = A(EXP1 * 1.15, 2); }
        else { HP1 = A(HP1 * 0.9, 1); EXP1 = A(EXP1 * 1.2, 2); }
        return HP1 + EXP1 + M1;
    }
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
        // TODO: Complete this function
    HP1 = A(HP1, 1); EXP1 = A(EXP1, 2); HP2 = A(HP2, 1); EXP2 = A(EXP2, 2);
        if (E3 > 99 || E3 < 0) return -99;
        else {
        int B[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                B[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        int c = 0;
        int d = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (B[i][j] > E3 * 2) { c++; }
                if (B[i][j] < -E3) { d++; }
            }
        }
        int i;
        if (c < 10) { i = c; }
        else {
            if ((int(c / 10) + c % 10) < 10) { i = int(c / 10) + c % 10; }
            else { i = int((int(c / 10) + c % 10) / 10) + (int(c / 10) + c % 10) % 10; }
        }
        int j;
        if (d < 10) { j = d; }
        else {
            if ((int(d / 10) + d % 10) < 10) { j = int(d / 10) + d % 10; }
            else { j = int((int(d / 10) + d % 10) / 10) + (int(d / 10) + d % 10) % 10; }
        }

        int max[4];
        int x = i;        
        int y = j;
        max[0] = B[x][y];
        while (x > 0 && y < 9) {
            x--; y++;
            if (max[0] < B[x][y]) { max[0] = B[x][y]; }
        }
        x = i;y = j;
        max[1] = B[x][y];
        while (x < 9 && y > 0) {
            x++; y--;
            if (max[1] < B[x][y]) { max[1] = B[x][y]; }
        }
        x = i;y = j;
        max[2] = B[x][y];
        while (x > 0 && y > 0) {
            x--; y--;
            if (max[2] < B[x][y]) { max[2] = B[x][y]; }
        }
        x = i; y = j;
        max[3] = B[x][y];
        while (x < 9 && y < 9) {
            x++; y++;
            if (max[3] < B[x][y]) { max[3] = B[x][y]; }
        }
        int maxx = max[0];
        for (int a = 0; a < 4; a++) {
            if (maxx < max[a]) { maxx = max[a]; }
        }
        if (abs(B[i][j]) > abs(maxx)) { HP1 = A(HP1 * 0.9, 1); HP2 = A(HP2 * 0.9, 1); EXP1 = A(EXP1 * 0.88, 2); EXP2 = A(EXP2 * 0.88, 2); }
        else { HP1 = A(HP1 * 1.1, 1); HP2 = A(HP2 * 1.1, 1); EXP1 = A(EXP1 * 1.12, 2); EXP2 = A(EXP2 * 1.12, 2); }
        int cc;
        if (abs(B[i][j]) > abs(maxx)) { cc = B[i][j]; }
        else { cc = maxx; }      
        return cc;
    }
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string ss = s; string emaill = email;
    string se = emaill.substr(0,emaill.find('@'));
    
    int n = ss.length();
    if (n < 8) return -1;
    if (n > 20) return -2;
    
    if (ss.find(se) != std::string::npos) {
        int sei = ss.find(se);
        return -(300 + sei);
    }

    for (int i = 0; i < n - 2; i++) {
        if (ss[i] == ss[i + 1] && ss[i] == ss[i + 2]) {
            return -(400 + i);
        }
    }
    
    bool ktdb = false;
    for (int i = 0; i < n; ++i) {
        if (ss[i] == '@' || ss[i] == '#' || ss[i] == '%' || ss[i] == '$' || ss[i] == '!') {
            ktdb = true;
            break;
        }
    }
    if (!ktdb) return -5;
    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function     
    int pcount[30] = { 0 }; 
    int plength[30] = { 0 };

    for (int i = 0; i < num_pwds; i++) {
        int l = strlen(arr_pwds[i]);
        pcount[i] = 1;
        plength[i] = l;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                pcount[i]++;
            }
        }
    }

    int max_count = pcount[0];
    int max_length = plength[0];
    int result = 0;

    for (int i = 1; i < num_pwds; ++i) {
        if (pcount[i] > max_count || (pcount[i] == max_count && plength[i] > max_length)) {
            max_count = pcount[i];
            max_length = plength[i];
            result = i;
        }
    }
    return result;
}



////////////////////////////////////////////////  
/// END OF STUDENT'S ANSWER
//////////////////////////////////////////////// 