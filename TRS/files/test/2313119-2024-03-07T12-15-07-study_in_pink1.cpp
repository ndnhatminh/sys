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
bool checkE(int e) {
    if (e < 0)  return false;
    if (e > 99) return false;
    return true;
}
void checkHP(int &a) {
    if (a < 0)  a = 0;
    if (a > 666)    a = 666;  
}
void checkEXP(int &b) {
    if (b < 0)  b = 0;
    if (b > 600)    b = 600;
}
void checkM(int &c) {
    if (c < 0)  c = 0;
    if (c > 3000)    c = 3000;
}
int up(double a) {
    if (abs(a - int(a)) <= 10e-10)   return int(a);
    else return int(a) + 1;
}
int Sum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;  // Lấy chữ số cuối cùng và cộng vào tổng
        n /= 10;        // Loại bỏ chữ số cuối cùng
    }
    return sum;
}
void Thesecondstreet(int& HP1, int& EXP1, int& M1, int E2) {
    double  molimit = M1 / 2.0;
    if (E2 % 2 == 0) {
        // Su kien 1
        if (HP1 < 200) {
            HP1 = up(HP1 * 1.3); checkHP(HP1);
            M1 -= 150;  checkM(M1);
            if (M1 == 0) {
                HP1 = up(HP1 * 0.83);     checkHP(HP1);
                EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                return;
            }

        }
        else {
            HP1 = up(HP1 * 1.1);   checkHP(HP1);
            M1 -= 70;    checkM(M1);
            if (M1 == 0) {
                HP1 = up(HP1 * 0.83);     checkHP(HP1);
                EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                return;
            }
        }
        // Su kien 2
        if (EXP1 < 400) {
            M1 -= 200;    checkM(M1);
            EXP1 = up(EXP1 * 1.13);    checkEXP(EXP1);
            if (M1 == 0) {
                HP1 = up(HP1 * 0.83);     checkHP(HP1);
                EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                return;
            }
        }
        else {
            M1 -= 120;    checkM(M1);
            EXP1 = up(EXP1 * 1.13);    checkEXP(EXP1);
            if (M1 == 0) {
                HP1 = up(HP1 * 0.83);     checkHP(HP1);
                EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                return;
            }
        }
        // Su kien 3
        if (EXP1 < 300) {
            M1 -= 100;    checkM(M1);
            EXP1 = up(EXP1 * 0.9);    checkEXP(EXP1);
            if (M1 == 0) {
                HP1 = up(HP1 * 0.83);     checkHP(HP1);
                EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                return;
            }
        }
        else {
            M1 -= 120;    checkM(M1);
            EXP1 = up(EXP1 * 0.9);    checkEXP(EXP1);
            if (M1 == 0) {
                HP1 = up(HP1 * 0.83);     checkHP(HP1);
                EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                return;
            }
        }
    }
    else {
        do {
            // Su kien 1
            if (HP1 < 200) {
                HP1 = up(HP1 * 1.3); checkHP(HP1);
                M1 -= 150;  checkM(M1);
                if (M1 < molimit) {
                    HP1 = up(HP1 * 0.83);     checkHP(HP1);
                    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                    return;
                }

            }
            else {
                HP1 = up(HP1 * 1.1);   checkHP(HP1);
                M1 -= 70;    checkM(M1);
                if (M1 < molimit) {
                    HP1 = up(HP1 * 0.83);     checkHP(HP1);
                    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                    return;
                }
            }
            // Su kien 2
            if (EXP1 < 400) {
                M1 -= 200;    checkM(M1);
                EXP1 = up(EXP1 * 1.13);    checkEXP(EXP1);
                if (M1 < molimit) {
                    HP1 = up(HP1 * 0.83);     checkHP(HP1);
                    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                    return;
                }
            }
            else {
                M1 -= 120;    checkM(M1);
                EXP1 = up(EXP1 * 1.13);    checkEXP(EXP1);
                if (M1 < molimit) {
                    HP1 = up(HP1 * 0.83);     checkHP(HP1);
                    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                    return;
                }
            }
            // Su kien 3
            if (EXP1 < 300) {
                M1 -= 100;    checkM(M1);
                EXP1 = up(EXP1 * 0.9);    checkEXP(EXP1);
                if (M1 < molimit) {
                    HP1 = up(HP1 * 0.83);     checkHP(HP1);
                    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                    return;
                }
            }
            else {
                M1 -= 120;    checkM(M1);
                EXP1 = up(EXP1 * 0.9);    checkEXP(EXP1);
                if (M1 < molimit) {
                    HP1 = up(HP1 * 0.83);     checkHP(HP1);
                    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
                    return;
                }
            }
            if (M1 < molimit) {
                break; // Thoát khỏi vòng lặp nếu M1 không còn lớn hơn molimit
            }
        } while (true);
    }
    HP1 = up(HP1 * 0.83);     checkHP(HP1);
    EXP1 = up(EXP1 * 1.17);   checkEXP(EXP1);
    return;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (!checkE(e1)) return -99;
    if ((e1 >= 0) && (e1 < 4)) {
        int D = 0;
        switch (e1) {
        case 0: // Thong tin 1
            exp2 += 29;
            D += e1 * 3 + exp1 * 7;
            break;
        case 1: // Thong tin 2
            exp2 += 45;
            D += e1 * 3 + exp1 * 7;
            break;
        case 2: // Thong tin 3
            exp2 += 75;
            D += e1 * 3 + exp1 * 7;
            break;
        case 3: // Thong tin 4
            exp2 += 29 + 45 + 75;
            D += e1 * 3 + exp1 * 7;
            break;

        }
        if (D % 2 == 0) {
            exp1 = up(exp1 + D / 200.0);
        }
        else {
            exp1 = up(exp1 - D / 100.0);
        }
    }
    else if ((e1 >= 4) && (e1 <= 99)) {
        // Thong tin 1
        if ((e1 >= 4) && (e1 < 20)) {
            exp2 = up(exp2 + e1 / 4.0 + 19);
        }// Thong tin 2
        else if ((e1 >= 20) && (e1 < 50)) {
            exp2 = up(exp2 + e1 / 9.0 + 21);
        }// Thong tin 3
        else if ((e1 >= 50) && (e1 < 66)) {
            exp2 = up(exp2 + e1 / 16.0 + 17);
        }// Thong tin 4
        else if ((e1 >= 66) && (e1 < 80)) {
            exp2 = up(exp2 + e1 / 4.0 + 19);
            if (exp2 > 200) {
                exp2 = up(exp2 + e1 / 9.0 + 21);
            }
        }// Thong tin 5
        else {
            exp2 = up(exp2 + e1 / 4.0 + 19);
            exp2 = up(exp2 + e1 / 9.0 + 21);
            if (exp2 > 400) {
                exp2 = up(exp2 + e1 / 16.0 + 17);
                exp2 = up(exp2 * 1.15);
            }
        }
        exp1 -= e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (!checkE(E2)) return -99;
    // Duong so 1:
        //Tim so chinh phuong gan nhat
    double p1;
    int d = round(sqrt(EXP1));
    int S = d * d;
    if (EXP1 >= S) {
        p1 = 1;
    }
    else {
        p1 = (double(EXP1) / S + 80) / 123.0;
    }
    // Duong so 2:
    Thesecondstreet(HP1, EXP1, M1, E2);
    double p2;
    d = round(sqrt(EXP1));
    S = d * d;
    if (EXP1 >= S) {
        p2 = 1;
    }
    else {
        p2 = (double(EXP1) / S + 80) / 123.0;
    }
    // Duong so 3:
    double p3;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 / 10 == 0) {
        p3 = P[E2] / 100.0;
    }
    else {
        int a, b, c;
        a = E2 / 10;
        b = E2 - 10 * a;
        c = a + b;
        if (c / 10 == 0) {
            p3 = P[c] / 100.0;
        }
        else {
            c = c % 10;
            p3 = P[c] / 100.0;
        }
    }
    float p;
    if (p1 == 1 && p2 == 1 && p3 == 1) {
        EXP1 = up(EXP1 * 0.75); checkEXP(EXP1);
    }
    else {
        p = (p1 + p2 + p3) / 3.0;
        if (p < 0.5) {
            HP1 = up(HP1 * 0.85);     checkHP(HP1);
            EXP1 = up(EXP1 * 1.15);   checkEXP(EXP1);
        }
        else {
            HP1 = up(HP1 * 0.9);      checkHP(HP1);
            EXP1 = up(EXP1 * 1.20);   checkEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (!checkE(E3)) return -99;
    int neg=0, pos=0, Taxi, Sher=0;
    int T[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            T[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (T[i][j] > E3 * 2) {
                pos++;
            }
            if (T[i][j] < E3 * -1) {
                neg++;
            }
        }
    }
    // Tim toa do Taxi:
    do {
        pos = Sum(pos);
    } while (pos >= 10);
    do {
        neg = Sum(neg);
    } while (neg >= 10);
    Taxi = T[pos][neg];
    // Tim toa do People:
    for (int i = pos, j = neg; i < 10 && j < 10; i++, j++) {
        if (T[i][j] > Sher) {
            Sher = T[i][j];
        }
    }
    for (int i = pos, j = neg; i >= 0 && j >= 0; i--, j--) {
        if (T[i][j] > Sher) {
            Sher = T[i][j];
        }
    }
    for (int i = pos, j = neg; i < 10 && j >= 0; i++, j--) {
        if (T[i][j] > Sher) {
            Sher = T[i][j];
        }
    }
    for (int i = pos, j = neg; j < 10 && i >= 0; j++, i--) {
        if (T[i][j] > Sher) {
            Sher = T[i][j];
        }
    }
    if (Sher >= abs(Taxi)) {
        EXP1 = up(EXP1 * 1.12);   checkEXP(EXP1);
        EXP2 = up(EXP2 * 1.12);   checkEXP(EXP2);
        HP1 = up(HP1 * 1.1);      checkHP(HP1);
        HP2 = up(HP2 * 1.1);      checkHP(HP2);
        return Sher;
    }
    else {
        EXP1 = up(EXP1 * 0.88);   checkEXP(EXP1);
        EXP2 = up(EXP2 * 0.88);   checkEXP(EXP2);
        HP1 = up(HP1 * 0.9);      checkHP(HP1);
        HP2 = up(HP2 * 0.9);      checkHP(HP2);
        return Taxi;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string normal_s(s);
    string normal_email(email);
    size_t position = normal_email.find('@');
    string se = normal_email.substr(0,position);
   
   if (normal_s.size() < 8)             return -1;
   if (normal_s.size() > 20)            return -2;
   size_t found = normal_s.find(se);
   if (found != string::npos)           return -(300 + int(found));  
   for (int i = 0, j = 1, k = 2; i < (normal_s.size()-2) && j < (normal_s.size() - 1) && k < normal_s.size(); i++, j++, k++) {
       if ((normal_s[i] == normal_s[j]) && (normal_s[j] == normal_s[k]))  return -(400 + i);
                
   }
   int a = 0, b = -1;
   for (int i = 0; i < normal_s.size(); i++) {
       if ((normal_s[i] >= 'a' && normal_s[i] <= 'z') ||
           (normal_s[i] >= 'A' && normal_s[i] <= 'Z') ||
           (normal_s[i] >= '0' && normal_s[i] <= '9') || normal_s[i] == '@' || normal_s[i] == '#' || normal_s[i] == '%' || normal_s[i] == '$' || normal_s[i] == '!') {
           if (normal_s[i] == '@' || normal_s[i] == '#' || normal_s[i] == '%' || normal_s[i] == '$' || normal_s[i] == '!') {
               a++;
           }
           continue;
       }
       else { 
           if (b==-1) b = i;
       }
   }

   if (a == 0) return -5;
   if (b != -1) return b;

   return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0, thefirst=0;
    string normal_arr[100];
    for (int i = 0; i < num_pwds; i++)    normal_arr[i] = arr_pwds[i];
    int count[100]{};
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (normal_arr[i] == normal_arr[j]) {
                count[i]++;
                count[j]++;
                if ((count[i] > max_count) || ((count[i] == max_count) && (normal_arr[i].size() > normal_arr[thefirst].size()))) {
                    max_count = count[i];
                    thefirst = i;
                }
            }
        }
    }
    return thefirst;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////