#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & exp1,
        int & exp2,
        int & M1,
        int & M2,
        int & e1,
        int & E2,
        int & E3
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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if (exp1 < 0) {exp1 = 0;
    }else if (exp1 > 600) {exp1 = 600;}
    if (exp2 < 0) {exp2 = 0;
    }else if (exp2 > 600) {exp2 = 600;}
    if (e1 >=0 && e1 <= 3){
    switch (e1){
        case 0:
        exp2 = exp2 + 29;
        break;
        case 1:
        exp2 = exp2 + 45;
        break;
        case 2:
        exp2 = exp2 + 75;
        break;
        case 3:
        exp2 = exp2 + 29 + 45 + 75;
        break;
        default:
        exp2 = exp2;
        }
    if (exp2 < 0) {exp2 = 0;}
    else if (exp2 > 600) {exp2 = 600;}
    else {exp2 = exp2;}
    int D = e1*3 + exp1*7;
    if (D % 2 ==0) {exp1 = ceil(exp1 + D*1.0/200);}
    else {exp1 = ceil(exp1 - D*1.0/100);}
    if (exp1 < 0) {exp1 = 0;}
    else if (exp1 > 600) {exp1 = 600;}
    else {exp1 = exp1;}
    }
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + e1*1.0/4 + 19);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + e1*1.0/9 + 21);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + e1*1.0/16 + 17);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + e1*1.0/4 + 19);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) {exp2 = 600;}
            if (exp2 > 200) exp2 = ceil(exp2 + e1*1.0/9 + 21);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) exp2 = 600;
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + e1*1.0/4 + 19);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) {exp2 = 600;}
            exp2 = ceil(exp2 + e1*1.0/9 + 21);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) {exp2 = 600;}
            if (exp2 > 400) {exp2 = ceil(exp2 + e1*1.0/16 + 17);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) {exp2 = 600;}
            exp2 = ceil(exp2*1.15);
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) exp2 = 600;
            }
            if (exp2 < 0) {exp2 = 0;
            }else if (exp2 > 600) exp2 = 600;
        }
    exp1 = exp1 - e1;
    if (exp1 < 0) {exp1 = 0;
    }else if (exp1 > 600) {exp1 = 600;}
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    if (HP1 < 0) {HP1 = 0;
    }else if (HP1 > 666) {HP1 = 666;}
    if (EXP1 < 0) {EXP1 = 0;
    }else if (EXP1 > 600) {EXP1 = 600;}
    if (M1 < 0) {M1 = 0;
    }else if (M1 > 3000) {M1 = 3000;}
    float S;
    if (EXP1 - pow(floor(sqrt(EXP1)),2) < pow(floor(sqrt(EXP1))+1,2) - EXP1) {
        S = pow(floor(sqrt(EXP1)),2);
    }else {S = pow(floor(sqrt(EXP1))+1,2);}
    float P1;
    if (EXP1 >= S) {P1=1;
    }else {P1 = ((EXP1*1.0)/S+80)/123;}
    float MH = M1*0.5;
    float MS = 0;
    if (E2 % 2 != 0) {
        while (MS <= MH && M1 > 0){
            if (HP1 < 200) {
                HP1 = ceil(HP1*13.0/10);
                M1 = M1 - 150;
                MS = MS + 150;
                if (HP1 < 0) {HP1 = 0;
                }else if (HP1 > 666) {HP1 = 666;}
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
            }else if (HP1 >= 200){
                HP1 = ceil(HP1*11.0/10);
                M1 = M1 - 70;
                MS = MS + 70;
                if (HP1 < 0) {HP1 = 0;
                }else if (HP1 > 666) {HP1 = 666;}
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
            }
            if (MS > MH) {
                break;
            }
            if (EXP1 < 400) {
                M1 = M1 - 200;
                MS = MS + 200;
                EXP1 = ceil(EXP1*113.0/100);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }else if (EXP1 >= 400) {
                M1 = M1 - 120;
                MS = MS + 120;
                EXP1 = ceil(EXP1*113.0/100);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }
            if (MS > MH) {
                break;
            }
            if (EXP1 < 300) {
                M1 = M1 - 100;
                MS = MS + 100;
                EXP1 = ceil(EXP1*9.0/10);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }else if (EXP1 >= 300) {
                M1 = M1 - 120;
                MS = MS + 120;
                EXP1 = ceil(EXP1*9.0/10);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }
            if (MS > MH) {
                break;
            }
        }
            HP1 = ceil(HP1*83.0/100);
            EXP1 = ceil(EXP1*117.0/100);
            if (HP1 < 0) {HP1 = 0;
            }else if (HP1 > 666) {HP1 = 666;}
            if (EXP1 < 0) {EXP1 = 0;
            }else if (EXP1 > 600) {EXP1 = 600;}
    } else {
            if (HP1 < 200 && M1 > 0) {
                HP1 = ceil(HP1*13.0/10);
                M1 = M1 - 150;
                if (HP1 < 0) {HP1 = 0;
                }else if (HP1 > 666) {HP1 = 666;}
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
            }else if (HP1 >= 200 && M1 > 0){
                HP1 = ceil(HP1*11.0/10);
                M1 = M1 - 70;
                if (HP1 < 0) {HP1 = 0;
                }else if (HP1 > 666) {HP1 = 666;}
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
            }
            if (EXP1 < 400 && M1 > 0) {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1*113.0/100);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }else if (EXP1 >= 400 && M1 > 0) {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1*113.0/100);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }
            if (EXP1 < 300 && M1 > 0) {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1*9.0/10);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }else if (EXP1 >= 300 && M1 > 0) {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1*9.0/10);
                if (M1 < 0) {M1 = 0;
                }else if (M1 > 3000) {M1 = 3000;}
                if (EXP1 < 0) {EXP1 = 0;
                }else if (EXP1 > 600) {EXP1 = 600;}
            }
        HP1 = ceil(HP1*83.0/100);
        EXP1 = ceil(EXP1*117.0/100);
        if (HP1 < 0) {HP1 = 0;
        }else if (HP1 > 666) {HP1 = 666;}
        if (EXP1 < 0) {EXP1 = 0;
        }else if (EXP1 > 600) {EXP1 = 600;}
    }
    if (EXP1 - pow(floor(sqrt(EXP1)),2) < pow(floor(sqrt(EXP1))+1,2) - EXP1) {
        S = pow(floor(sqrt(EXP1)),2);
    }else {S = pow(floor(sqrt(EXP1))+1,2);}
    float P2;
    if (EXP1 >= S) {P2=1;
    }else {P2 = ((EXP1*1.0)/S+80)/123;}
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2 < 10) {
        P3 = P[E2]/100.0;
    } else {
        int i = E2 % 10 + E2/10;
        P3 = P[i % 10]/100.0;
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1*75.0/100);
        if (EXP1 < 0) {EXP1 = 0;
        }else if (EXP1 > 600) {EXP1 = 600;}
    } else {
        float P = (P1 + P2 + P3)/3;
        if (P < 0.5) {
            HP1 = ceil(HP1*85.0/100);
            EXP1 = ceil(EXP1*115.0/100);
            if (HP1 < 0) {HP1 = 0;
            }else if (HP1 > 666) {HP1 = 666;}
            if (EXP1 < 0) {EXP1 = 0;
            }else if (EXP1 > 600) {EXP1 = 600;}
        } else {
            HP1 = ceil(HP1*9.0/10);
            EXP1 = ceil(EXP1*12.0/10);
            if (HP1 < 0) {HP1 = 0;
            }else if (HP1 > 666) {HP1 = 666;}
            if (EXP1 < 0) {EXP1 = 0;
            }else if (EXP1 > 600) {EXP1 = 600;}
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    if (HP1 < 0) {HP1 = 0;
    }else if (HP1 > 666) {HP1 = 666;}
    if (HP2 < 0) {HP2 = 0;
    }else if (HP2 > 666) {HP2 = 666;}
    if (EXP1 < 0) {EXP1 = 0;
    }else if (EXP1 > 600) {EXP1 = 600;}
    if (EXP2 < 0) {EXP2 = 0;
    }else if (EXP2 > 600) {EXP2 = 600;}
    double arr[10][10] = {0};
    int arrmax = 0;
    int arrmin = 0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > E3*2) arrmax = arrmax + 1;
            if (arr[i][j] < -E3) arrmin = arrmin + 1;
        }
    }
    while (arrmax >= 10) {
        arrmax = arrmax/10 + arrmax%10;
    }
    while (arrmin >= 10) {
        arrmin = arrmin/10 + arrmin%10;
    }
    int sherlock ;
    int taxi = arr[arrmax][arrmin];
    for (int i = arrmax, j = arrmin; i >= 0 && i < 10 && j >= 0 && j < 10; i--, j--) {
        if (arr[i][j] > sherlock) sherlock = arr[i][j];
    }
    for (int i = arrmax, j = arrmin; i >= 0 && i < 10 && j >= 0 && j < 10; i++, j--) {
        if (arr[i][j] > sherlock) sherlock = arr[i][j];
    }
    for (int i = arrmax, j = arrmin; i >= 0 && i < 10 && j >= 0 && j < 10; i--, j++) {
        if (arr[i][j] > sherlock) sherlock = arr[i][j];
    }
    for (int i = arrmax, j = arrmin; i >= 0 && i < 10 && j >= 0 && j < 10; i++, j++) {
        if (arr[i][j] > sherlock) sherlock = arr[i][j];
    }
    if (abs(taxi) > sherlock) {
        EXP1 = ceil(EXP1*88.0/100);
        EXP2 = ceil(EXP2*88.0/100);
        HP1 = ceil(HP1*90.0/100);
        HP2 = ceil(HP2*90.0/100);
        if (EXP1 < 0) {EXP1 = 0;
        }else if (EXP1 > 600) {EXP1 = 600;}
        if (EXP2 < 0) {EXP2 = 0;
        }else if (EXP2 > 600) {EXP2 = 600;}
        if (HP1 < 0) {HP1 = 0;
        }else if (HP1 > 666) {HP1 = 666;}
        if (HP2 < 0) {HP2 = 0;
        }else if (HP2 > 666) {HP2 = 666;}
        if (E3 == 0) return 0;
        return taxi;
    } else {
        EXP1 = ceil(EXP1*112.0/100);
        EXP2 = ceil(EXP2*112.0/100);
        HP1 = ceil(HP1*110.0/100);
        HP2 = ceil(HP2*110.0/100);
        if (EXP1 < 0) {EXP1 = 0;
        }else if (EXP1 > 600) {EXP1 = 600;}
        if (EXP2 < 0) {EXP2 = 0;
        }else if (EXP2 > 600) {EXP2 = 600;}
        if (HP1 < 0) {HP1 = 0;
        }else if (HP1 > 666) {HP1 = 666;}
        if (HP2 < 0) {HP2 = 0;
        }else if (HP2 > 666) {HP2 = 666;}
        if (E3 == 0) return 0;
        return sherlock;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char* p = strchr(email, '@');
    int le = p - email;
    char* se = new char[le + 1];
    strncpy(se, email, le);
    se[le] = '\0';
    const char *v = strstr(s, se);
    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;
    if (v != nullptr) {
    return -(300 + (v-s));
    }
    for (int i=0; i<length - 2; i++) {
        if(s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i);
        }
    }
    bool hsc = false;
    for (int i = 0; i < length; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hsc = true;
            break;
        }
    }
    if (!hsc) return -5;
        for (int i=0; i<length; i++) {
            if ( !((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    char c[num_pwds];
    for(int i=0; i<num_pwds; i++) {
        c[i] = {0};
    }
    char lp[num_pwds];
    for (int i=0; i<num_pwds; i++) {
        int l = strlen(arr_pwds[i]);
        lp[i] = l;
        for (int j=0; j<num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                c[i]++;
            }
        }
    }
    int maxc = 0;
    int maxlp = 0;
    int ci = -1;
    for (int i=0; i<num_pwds; i++) {
        if(c[i] > maxc || (c[i] == maxc && lp[i] > maxlp)) {
            maxc = c[i];
            maxlp = lp[i];
            ci=i;
        }
    }
    return ci;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////