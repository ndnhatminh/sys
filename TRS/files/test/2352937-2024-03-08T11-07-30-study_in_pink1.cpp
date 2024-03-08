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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
int V;
V = EXP2;
if (E1 >= 0 && E1 <= 3) {
        switch (E1) {
            case 0: EXP2 += 29; break;
            case 1: EXP2 += 45; break;
            case 2: EXP2 += 75; break;
            case 3: EXP2 += 149; break;
        }
        int D = E1 * 3 + EXP1 * 7; 
        if (D % 2 == 0) {
            EXP1 += D / 200;
        } else {
            EXP1 -= D / 100;
        }
    } else if (E1 >= 4 && E1 <= 19) {
        EXP2 = ceil(V + (E1 / 4.0 + 19));
        EXP1 -= E1;
    } else if (E1 >= 20 && E1 <= 49) {
        EXP2 = ceil(V + (E1 / 9.0 + 21));
        EXP1 -= E1;
    } else if (E1 >= 50 && E1 <= 65) {
        EXP2 =  ceil(V + (E1 / 16.0+ 17));
        EXP1 -= E1;
    } else if (E1 >= 66 && E1 <= 79) {
        EXP2 = ceil(V + (E1 / 4.0 + 19));
        if (EXP2 > 200) {
            EXP2 = ceil(V + (E1 / 9.0 + 21));
        }
        EXP1 -= E1;
    } else if (E1 >= 80 && E1 <= 99) {
        EXP2 = ceil(2*V + (E1 / 4.0 + 19) + (E1 / 9.0 + 21));
        if (EXP2 > 400) {
            EXP2 +=ceil(E1 / 16.0 )+ 17;
            EXP2 = ceil(EXP2 * 1.15);
        }
        EXP1 -= E1;
    }
    
    if (EXP1 > 600) {EXP1 = 600;}
    if (EXP1 < 0) {EXP1 = 0;}
    if (EXP2 > 600) {EXP2 = 600;}
    if (EXP2 < 0) {EXP2 = 0;}
    if (E1 > 99) {return -99;}
    if (E1 < 0) {return -99;}
    return EXP1 + EXP2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
   float P1, P2, P3, Ptb;
    int T = M1 * 0.5;
    int Tm = 0;
    int S = static_cast<int>(sqrt(EXP1) + 0.5); 

    if (EXP1 >= S) {
        P1 = 1;
    } else {
        P1 = (EXP1 / static_cast<float>(S) + 80) / 123; //xong con đường 1
    }

    if (E2 % 2 != 0) { // nếu lẻ 
        while (T > Tm) {
            if (HP1 < 200) { // sự kiện 1
                HP1 = ceil(HP1 * 1.3);
                M1 = M1 - 150;
                Tm += 150;
            } else {
                HP1 = ceil(HP1 * 1.1);
                M1 = M1 - 70;
                Tm += 70;
            }

            if (T < Tm)
                break;
            else { // sự kiện 2
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    Tm += 200;
                } else {
                    M1 = M1 - 120;
                    Tm += 120;
                }
                EXP1 = ceil(EXP1 * 1.13);

                if (T < Tm)
                    break;
                else { // sự kiện 3
                    if (EXP1 < 300) {
                        M1 = M1 - 100;
                        Tm += 100;
                    } else {
                        M1 = M1 - 120;
                        Tm += 120;
                    }
                    EXP1 = ceil(EXP1 * 0.9);
                }
            }
        }
    } else { // nếu chẵn 
        while (T >= 0) {
            if (HP1 < 200) { // sự kiện 1
                HP1 = ceil(HP1 * 1.3);
                M1 = M1 - 150;
                Tm += 150;
            } else {
                HP1 = ceil(HP1 * 1.1);
                M1 = M1 - 70;
                Tm += 70;
            }
            if (M1 <= 0)
                break;
            if (EXP1 < 400) { // sự kiện 2
                M1 = M1 - 200;
                Tm += 200;
            } else {
                M1 = M1 - 120;
                Tm += 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (T <= 0)
                break;
            else { // sự kiện 3
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    Tm += 100;
                } else {
                    M1 = M1 - 120;
                    Tm += 120;
                }
                EXP1 = ceil(EXP1 * 0.9);
                break;
            }
        }
    }

    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);

    if (EXP1 >= S) {
        P2 = 1;
    } else {
        P2 = (EXP1 / static_cast<float>(S) + 80) / 123; //xong con đường 2
    }

    float P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i;
    if (E2 < 10 && E2 > 0 ) {
        i = E2;
    } else if (E2 > 10 && E2 < 99) {
        i = ((E2 - floor(E2 / 10) * 10) + floor(E2 / 10));
        if (i < 10 ) {
            i = i;
        } else if (i >= 10) {
            i = i - 9 ;
        }
    }
    P3 = P[i];
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 *= 0.75;
    } else {
        Ptb = (P1 + P2 + P3) / 3;
        if (Ptb < 0.5 && Ptb > 0) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        } else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }// xong con đường 3 
    
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    if (E2 > 99 || E2 < 0) return -99;
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
int map[10][10] = { 0 };
int numD = 0;
int numA = 0;
int sherlock_watson;
int taxiScore;

// Nhập giá trị vào mảng
int i = 0;
while (i < 10) {
    int j = 0;
    while (j < 10) {
        map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        j++;
    }
    i++;
}

// Đếm số giá trị lớn hơn E3*2 và nhỏ hơn -E3
i = 0;
while (i < 10) {
    int j = 0;
    while (j < 10) {
        if (map[i][j] > (E3 * 2)) numD += 1;
        else if (map[i][j] < (-1 * E3)) numA += 1;
        j++;
    }
    i++;
}

// Tính vị trí có điểm của taxi 
int k = 0;
while (numD > 0 || k > 9) {
    if (numD == 0) {
        numD = k;
        k = 0;
    }
    k += numD % 10;
    numD /= 10;
}

int l = 0;
while (numA > 0 || l > 9) {
    if (numA == 0) {
        numA = l;
        l = 0;
    }
    l += numA % 10;
    numA /= 10;
}

taxiScore = map[k][l];// điểm của taxi

// Tính đường chéo từ trái sang và từ phải sang
int maxLeftDiagonal = INT_MIN;
int maxRightDiagonal = INT_MIN;
i = k;
int j = l;
while (i < 10 && j < 10) {
    maxLeftDiagonal = max(maxLeftDiagonal, map[i][j]);
    i++;
    j++;
}

i = k;
j = l;
while (i >= 0 && j >= 0) {
    maxLeftDiagonal = max(maxLeftDiagonal, map[i][j]);
    i--;
    j--;
}

i = k;
j = l;
while (i < 10 && j >= 0) {
    maxRightDiagonal = max(maxRightDiagonal, map[i][j]);
    i++;
    j--;
}

i = k;
j = l;
while (i >= 0 && j < 10) {
    maxRightDiagonal = max(maxRightDiagonal, map[i][j]);
    i--;
    j++;
}

sherlock_watson = max(maxLeftDiagonal, maxRightDiagonal);
if (sherlock_watson < 0) {
    sherlock_watson = abs(sherlock_watson);
}

// So sánh điểm taxi với điểm sherlock
if (abs(taxiScore) > sherlock_watson) {
    EXP1 = ceil(EXP1 * 0.88);
    EXP2 = ceil(EXP2 * 0.88);
    HP1 = ceil(HP1 * 0.9);
    HP2 = ceil(HP2 * 0.9);
    return taxiScore;
} else {
    EXP1 = ceil(EXP1 * 1.12);
    EXP2 = ceil(EXP2 * 1.12);
    HP1 = ceil(HP1 * 1.1);
    HP2 = ceil(HP2 * 1.1);
    return sherlock_watson;
}
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Kiểm tra độ dài của mật khẩu
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    string mail(email), pass(s);
    // Kiểm tra mật khẩu có chứa se hay không
    int pos = mail.find('@');
    string se = mail.substr(0, pos);
    if (pass.find(se) != string::npos) return -(300 + pass.find(se));

    int len = pass.length();
    // Kiểm tra kí tự trùng lặp
    char c = pass[0];
    int countC = 1, inC = 0;
    for (int i = 1; i < len; i++) {
        if (pass[i] == c) {
            countC++;
            if (countC > 2) return -(400 + inC);
        }
        else {
            c = pass[i];
            countC = 1;
            inC = i;
        }
    }

    // Kiểm tra các kí tự @ # % $ !
    bool hasSpecial = false;
    for (int i = 0; i < len; i++) {
        if (pass[i] == '@' || pass[i] == '#' || pass[i] == '%' || pass[i] == '$' || pass[i] == '!') {
            hasSpecial = true;
            break;
        }
    }
    if (!hasSpecial) return -5;
    // Kiểm tra kí tự khác biệt

    for (int i = 0; i < len; i++) {
        if ((pass[i] < 'A' || pass[i] > 'Z') &&
            (pass[i] < 'a' || pass[i] > 'z') &&
            (pass[i] < '0' || pass[i] > '9')) {
                if (pass[i] != '@' && pass[i] != '#' && pass[i] != '%' && pass[i] != '$' && pass[i] != '!') return i;
        }
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
struct PasswordInfo {
    int count;
    int length;
};
 PasswordInfo maxPassInfo = {0, 0};
    int maxIdx = -1;

    for (int i = 0; i < num_pwds; i++) {
        const char *password = arr_pwds[i];
        int passLen = strlen(password);
        int count = 1;

        // Đếm số lần xuất hiện của mật khẩu
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(password, arr_pwds[j]) == 0) {
                ++count;
            }
        }

        // Kiểm tra nếu mật khẩu hiện tại có số lần xuất hiện lớn hơn mật khẩu có số lần xuất hiện nhiều nhất hiện tại
        if (count > maxPassInfo.count || (count == maxPassInfo.count && passLen > maxPassInfo.length)) {
            maxPassInfo.count = count;
            maxPassInfo.length = passLen;
            maxIdx = i;
        }
    }
    return maxIdx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////