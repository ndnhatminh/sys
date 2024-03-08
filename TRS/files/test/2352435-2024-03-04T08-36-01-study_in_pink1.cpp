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

// Other functions
int expCheck(float exp) {
    exp = ceil(exp);
    if (exp > 600) {
        exp = 600;
    } else if (exp < 0) {
        exp = 0;
    }
    return exp;
}

int findNearSquare(int exp) {
    double root = sqrt(exp);
    double square = pow(round(root), 2);
    return square;
}

int hpCheck(float hp) {
    hp = ceil(hp);
    if (hp > 666) {
        hp = 666;
    } else if (hp < 0) {
        hp = 0;
    }
    return hp;
}

int mnCheck(float mn) {
    mn = ceil(mn);
    if (mn > 3000) {
        mn = 3000;
    } else if (mn < 0) {
        mn = 0;
    }
    return mn;
}

int diag1(int arr[10][10], int i, int j) {
    int max = arr[i][j];
    do {
        if (arr[i][j] > max) max = arr[i][j];
        --i;
        ++j;
    } while (i != -1 && j != 10);
    return max;
}

int diag2(int arr[10][10], int i, int j) {
    int max = arr[i][j];
    do {
        if (arr[i][j] > max) max = arr[i][j];
        --i;
        --j;
    } while (i != -1 && j != -1);
    return max;
}

int diag3(int arr[10][10], int i, int j) {
    int max = arr[i][j];
    do {
        if (arr[i][j] > max) max = arr[i][j];
        ++i;
        --j;
    } while (i != 10 && j != -1);
    return max;
}

int diag4(int arr[10][10], int i, int j) {
    int max = arr[i][j];
    do {
        if (arr[i][j] > max) max = arr[i][j];
        ++i;
        ++j;
    } while (i != 10 && j != 10);
    return max;
}

int findMax(int n1, int n2, int n3, int n4) {
    int MAX[4] = {n1, n2, n3, n4};
    int max = MAX[0];
    for (int i = 0; i < 4; ++i) {
        if (MAX[i] > max) {
            max = MAX[i];
        }
    }
    return max;
}

int findTheSame(const char* largeString, const char* smallString) {
    int index = 0;
    int check = 0;
    for (int i = 0; i < strlen(largeString); ++i) {
        int j;
        for (j = 0; j < strlen(smallString); ++j) {
            if (largeString[i + j] != smallString[j]) {
                break;
            }
        }
        if (j == strlen(smallString)) {
            index = i;
            check = 1;
            break;
        }
    }
    if (check == 1) {
        return index;
    } else return -1;
}

int findTheSpecial(const char* largeString) {
    int index = -1;
    int check = 0;
    const char Special[5] = {'@', '#', '%', '$', '!'};
    for (int i = 0; i < strlen(largeString); ++i) {
        for (int j = 0; j < 5; ++j) {
            if (largeString[i] == Special[j]) {
                index = i;
                check = 1;
                break;
            }
        }
    }
    return index;
}

int findTheCont(const char* largeString) {
    int index = 0;
    int check = 0;
    for (int i = 0; i < strlen(largeString); ++i) {
        if (largeString[i] == largeString[i + 1] && largeString[i] == largeString[i + 2]) {
            index = i;
            check = 1;
            break;
        }
    }
    if (check == 1) {
        return index;
    } else return -1;
}

int checkErr(const char* largeString) {
    int index = 0;
    int check = 0;
    for (int i = 0; i < strlen(largeString); ++i) {
        if ((largeString[i] >= 35 && largeString[i] <= 37) || largeString[i] == 33 || (largeString[i] >= 48 && largeString[i] <= 57) || (largeString[i] >= 64 && largeString[i] <= 90) || (largeString[i] >= 97 && largeString[i] <= 122)) {

        } else {
            index = i;
            check = 1;
            break;
        }
    }
    if (check == 0) {
        return -1;
    } else return index;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    if (e1 < 0 || e1 > 99) return -99;
    exp1 = expCheck(exp1);
    exp2 = expCheck(exp2);
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
            case 0:
                exp2 = expCheck(exp2 + 29);
                D = e1 * 3 + exp1 * 7;
                if (D % 2 == 0) {
                    exp1 = expCheck(exp1 + D/200.0);
                } else {
                    exp1 = expCheck(exp1 - D/100.0);
                }
                break;
            case 1:
                exp2 = expCheck(exp2 + 45);
                D = e1 * 3 + exp1 * 7;
                if (D % 2 == 0) {
                    exp1 = expCheck(exp1 + D/200.0);
                } else {
                    exp1 = expCheck(exp1 - D/100.0);
                }
                break;
            case 2:
                exp2 = expCheck(exp2 + 75);
                D = e1 * 3 + exp1 * 7;
                if (D % 2 == 0) {
                    exp1 = expCheck(exp1 + D/200.0);
                } else {
                    exp1 = expCheck(exp1 - D/100.0);
                }
                break;
            case 3:
                exp2 = expCheck(exp2 + 29 + 45 + 75);
                D = e1 * 3 + exp1 * 7;
                if (D % 2 == 0) {
                    exp1 = expCheck(exp1 + D/200.0);
                } else {
                    exp1 = expCheck(exp1 - D/100.0);
                }
                break;
        }
    } else if (e1 >= 4 && e1 <=19) {
        exp2 = expCheck(exp2 + e1/4.0 + 19);
        exp1 = expCheck(exp1 - e1);
    } else if (e1 >= 20 && e1 <= 49) {
        exp2 = expCheck(exp2 + e1/9.0 + 21);
        exp1 = expCheck(exp1 - e1);
    } else if (e1 >= 50 && e1 <= 65) {
        exp2 = expCheck(exp2 + e1/16.0 + 17);
        exp1 = expCheck(exp1 - e1);
    } else if (e1 >= 66 && e1 <= 79) {
        exp2 = expCheck(exp2 + e1/4.0 + 19);
        if (exp2 > 200) {
            exp2 = expCheck(exp2 + e1/9.0 + 21);
        }
        exp1 = expCheck(exp1 - e1);
    } else if (e1 >= 80 && e1 <= 99) {
        exp2 = expCheck(exp2 + e1/4.0 + 19);
        exp2 = expCheck(exp2 + e1/9.0 + 21);
        if (exp2 > 400) {
            exp2 = expCheck(exp2 + e1/16.0 + 17);
            exp2 = expCheck(exp2 * 1.15);
        }
        exp1 = expCheck(exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Road 1
    if (E2 < 0 || E2 > 99) return -99;
    HP1 = hpCheck(HP1);
    EXP1 = expCheck(EXP1);
    M1 = mnCheck(M1);
    int S = findNearSquare(EXP1);
    double P1;
    if (EXP1 >= S) {
        P1 = 1.0;
    } else {
        P1 = ((static_cast<double>(EXP1)/S) + 80) / 123.0;
    }
    // Road 2
    if (E2 % 2 != 0) {
        int totalMoneySpend = 0;
        int totalMoneyBegin = M1;
        do {
            // Event 1
            if (totalMoneySpend <= 0.5 * totalMoneyBegin && totalMoneyBegin != 0) {
                if (HP1 < 200) {
                    HP1 = hpCheck(HP1 * 1.3);
                    M1 = mnCheck(M1 - 150);
                    totalMoneySpend += 150;
                } else {
                    HP1 = hpCheck(HP1 * 1.1);
                    M1 = mnCheck(M1 - 70);
                    totalMoneySpend += 70;
                }
            } else break;
            // Event 2
            if (totalMoneySpend <= 0.5 * totalMoneyBegin && totalMoneyBegin != 0) {
                if (EXP1 < 400) {
                    M1 = mnCheck(M1 - 200);
                    totalMoneySpend += 200;
                } else {
                    M1 = mnCheck(M1 - 120);
                    totalMoneySpend += 120;
                }
                EXP1 = expCheck(EXP1 * 1.13);
            } else break;
            // Event 3
            if (totalMoneySpend <= 0.5 * totalMoneyBegin && totalMoneyBegin != 0) {
                if (EXP1 < 300) {
                    M1 = mnCheck(M1 - 100);
                    totalMoneySpend += 100;
                    EXP1 = expCheck(EXP1 * 0.9);
                } else {
                    M1 = mnCheck(M1 - 120);
                    totalMoneySpend += 120;
                    EXP1 = expCheck(EXP1 * 0.9);
                }
            } else break;
        } while(true);
    HP1 = hpCheck(HP1 * 0.83);
    EXP1 = expCheck(EXP1 * 1.17);
    } else {
        if (HP1 < 200) {
            if (M1 == 0) {
                // return true;
            } else {
                M1 = mnCheck(M1 - 150);
                HP1 = hpCheck(HP1 * 1.3);
            }
        } else {
            if (M1 == 0) {
                // return true;
            } else {
                M1 = mnCheck(M1 - 70);
                HP1 = hpCheck(HP1 * 1.1);
            }
        }
        if (EXP1 < 400) {
            if (M1 == 0) {
                // return true;
            } else {
                M1 = mnCheck(M1 - 200);
                EXP1 = expCheck(EXP1 * 1.13);
            }
        } else {
            if (M1 == 0) {
                // return true;
            } else {
                M1 = mnCheck(M1 - 120);
                EXP1 = expCheck(EXP1 * 1.13);
            }
        }
        if (EXP1 < 300) {
            if (M1 == 0) {
                // return true;
            } else {
                M1 = mnCheck(M1 - 100);
                EXP1 = expCheck(EXP1 * 0.9);
            }
        } else {
            if (M1 == 0) {
                // return true;
            } else {
                M1 = mnCheck(M1 - 120);
                EXP1 = expCheck(EXP1 * 0.9);
            } 
        }
        HP1 = hpCheck(HP1 * 0.83);
        EXP1 = expCheck(EXP1 * 1.17);
    }
    double P2;
    S = findNearSquare(EXP1);
    if (EXP1 >= S) {
        P2 = 1.0;
    } else {
        P2 = ((static_cast<double>(EXP1) / S) + 80) / 123.0;
    }
    // Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >= 0 && E2 <= 9) {
        i = E2;
    } else {
        i = ((E2 % 10) + (E2 / 10)) % 10;
    }
    double P3;
    P3 = P[i] / 100.0;
    // All the journey
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = expCheck(EXP1 * 0.75);
    } else {
        double P = (P1 + P2 + P3) / 3.0;
        if (P < 0.5) {
            HP1 = hpCheck(HP1 * 0.85);
            EXP1 = expCheck(EXP1 * 1.15);
        } else {
            HP1 = hpCheck(HP1 * 0.90);
            EXP1 = expCheck(EXP1 * 1.20);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    HP1 = hpCheck(HP1);
    HP2 = hpCheck(HP2);
    EXP1 = expCheck(EXP1);
    EXP2 = expCheck(EXP2);
    const int ROW = 10, COL = 10;
    int ROAD[ROW][COL];
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            ROAD[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Find i
    int i = 0;
    for (int a = 0; a < ROW; ++a) {
        for (int b = 0; b < COL; ++b) {
            if (ROAD[a][b] > (E3 * 2)) {
                i += 1;
            }
        }
    }
    while (i >= 10) {
        i = (i / 10) + (i % 10);
    }

    //Find j
    int j = 0;
    for (int a = 0; a < ROW; ++a) {
        for (int b = 0; b < COL; ++b) {
            if (ROAD[a][b] < (- E3)) {
                j += 1;
            }
        }
    }
    while (j >= 10) {
        j = (j / 10) + (j % 10);
    }
    int taxi = ROAD[i][j];
    int man = 0;
    int max = 0;
    // Find max
    int max1, max2, max3, max4;
    max1 = diag1(ROAD, i, j);
    max2 = diag2(ROAD, i, j);
    max3 = diag3(ROAD, i, j);
    max4 = diag4(ROAD, i, j);
    if (i == 0 && j == 0) {
        man = max4;
    } else if (i == 0 && j == 9) {
        man = max3;
    } else if (i == 9 && j == 0) {
        man = max1;
    } else if (i == 9 && j == 9) {
        man = max2;
    } else if (i == 0) {
        if (max3 > max4) {
            man = max3;
        } else man = max4;
    } else if (i == 9) {
        if (max1 > max2) {
            man = max1;
        } else man = max2;
    } else if (j == 0) {
        if (max1 > max4) {
            man = max1;
        } else man = max4;
    } else if (j == 9) {
        if (max2 > max3) {
            man = max2;
        } else man = max3;
    } else {
        man = findMax(max1, max2, max3, max4);
    }
    if (abs(taxi) > abs(man)) {
        EXP1 = expCheck(EXP1 * 0.88);
        HP1 = hpCheck(HP1 * 0.90);
        EXP2 = expCheck(EXP2 * 0.88);
        HP2 = hpCheck(HP2 * 0.90);
        max = taxi;
    } else if (abs(taxi) <= abs(man)) {
        EXP1 = expCheck(EXP1 * 1.12);
        HP1 = hpCheck(HP1 * 1.10);
        EXP2 = expCheck(EXP2 * 1.12);
        HP2 = hpCheck(HP2 * 1.10);
        max = man;
    }
    return max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const int maxLength = 20, minLength = 8;
    char se[100];
    int index = 0;
    for (int i = 0; i < strlen(email); ++i) {
        if (email[i] == '@') {
            index = i;
            break;
        }
    }
    for (int i = 0; i < index; ++i) {
        se[i] = email[i];
    }
    se[index] = '\0'; // Null-terminator
    // Check the condition
    int index1 = findTheSame(s, se);
    int index2 = findTheCont(s);
    int index3 = findTheSpecial(s);
    int index4 = checkErr(s);
    int checkPass = 0;
    bool check = true;
    if (strlen(s) < minLength) {
        checkPass = -1;
        check = false;
    } else if (strlen(s) > maxLength) {
        checkPass = -2;
        check = false;
    }
    if (check) {
        if (index1 != -1 && index2 != -1) {
            checkPass = -(300 + index1);
            check = false;
        } else if (index1 == -1 || index2 == -1) {
            if (index1 == -1 && index2 != -1) {
                checkPass = -(400 + index2);
                check = false;
            } else if (index1 != -1 && index2 == -1) {
                checkPass = -(300 + index1);
                check = false;
            }
        }
    }
    
    if (check) {
        if (index3 == -1) {
            checkPass = -5;
            check = false;
        }
    }
    if (check) {
        if (index4 != -1) {
            checkPass = index4;
        }  else {
            checkPass = -10;
        }
    }
    return checkPass;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFreq = 0;
    int index = 0;
    string maxFreqPass = arr_pwds[0];
    int lengthOfPass = 0;
    string arr_pwdss[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        arr_pwdss[i] = arr_pwds[i];
    }
    int arrOfFreq[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        arrOfFreq[i] = 0;
    }
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i; j < num_pwds; ++j) {
            if (arr_pwdss[i] == arr_pwdss[j]) {
                arrOfFreq[i] += 1;
            }
        }
    }
    for (int i = 0; i < num_pwds; ++i) {
        if (arrOfFreq[i] > maxFreq) {
            maxFreq = arrOfFreq[i];
            maxFreqPass = arr_pwdss[i];
            index = i;
        }
    }
    for (int i = 0; i < num_pwds; ++i) {
        if (arrOfFreq[i] == maxFreq) {
            if (arr_pwdss[i].size() > maxFreqPass.size()) {
                maxFreqPass = arr_pwds[i];
                index = i;
            }
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////