#include "study_in_pink1.h"

bool readFile(
        const string &filename,
        int &HP1,
        int &HP2,
        int &EXP1,
        int &EXP2,
        int &M1,
        int &M2,
        int &E1,
        int &E2,
        int &E3
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
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int checkRange(int &field, int min, int max) {
    if (field > max) {
        field = 600;
    } else if (field < min) {
        field = 0;
    }
    return field;
}

// Task 1
//exp1: Sherlock
//exp2: watson
int firstMeet(int &exp1, int &exp2, int e1) {
    // TODO: Complete this function;
    int totalExp;
    int ep0 = 29;
    int ep1 = 45;
    int ep2 = 75;
    if (e1 <= 3) {
        switch (e1) {
            case 0:
                exp2 += ep0;
                break;
            case 1:
                exp2 += ep1;
                break;
            case 2:
                exp2 += ep2;
                break;
            case 3:
                exp2 += ep0 + ep1 + ep2;
                break;
        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 += ceil(D / 200.f);
        } else {
            exp1 -= ceil(D / 100.f);
        }
        exp1 = checkRange(exp1, 0, 600);
        exp2 = checkRange(exp2, 0, 600);
        totalExp = exp1 + exp2;
    } else {
        //4.1.2
        int info1 = ceil(e1 / 4.f + 19);
        int info2 = ceil(e1 / 9.f + 21);
        int info3 = ceil(e1 / 16.f + 17);

        if (e1 >= 4 && e1 <= 19) {
            exp2 += info1;
        } else if (e1 >= 20 && e1 <= 49) {
            exp2 += info2;
        } else if (e1 >= 50 && e1 <= 65) {
            exp2 += info3;
        } else if (e1 >= 66 && e1 <= 79) {
            exp2 += info1;
            if (exp2 > 200) {
                exp2 += info2;
            }
        } else {
            exp2 += info1 + info2;
            if (exp2 > 400) {
                exp2 += info3;
            }
            exp2 *= 1.15;
        }
        exp1 -= e1;
        exp1 = checkRange(exp1, 0, 600);
        exp2 = checkRange(exp2, 0, 600);
        totalExp = exp1 + exp2;
    }

    return totalExp;
}

// Task 2
//road 1
float findP(int exp1) {
    float P;
    int S = round(sqrt(exp1));
    S = pow(S, 2);
    if (exp1 > S) {
        P = 1;
    } else {
        P = ((float) exp1 / S + 80) / 123;
    }
    return P;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // TODO: Complete this function
    float P1 = findP(EXP1);

    //road 2
    int preM1 = M1 * 0.5f;
    int x = 0;
    int meetHomeless = 0;
    do {
        meetHomeless++;
        int cost = M1;
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.30f);
            M1 -= 150;
        } else {
            HP1 = ceil(HP1 * 1.1f);
            M1 -= 70;
        }
        //check horse or taxi
        M1 -= EXP1 < 400 ? 200 : 120;
        EXP1 = ceil(EXP1 * 1.13);
        if (meetHomeless == 1) {
            //helping homeless
            M1 -= EXP1 < 300 ? 100 : 120;
            EXP1 = ceil(EXP1 * 0.9);
        }

        x += cost - M1;
    } while (E2 % 2 != 0 && x < preM1 && M1 > 0);
//    cout << "S is " << S << " " << "P1 will be " << fixed << setprecision(2) << P1 << endl;
    EXP1 = ceil(EXP1 * 1.17);
    HP1 = ceil(HP1 * 0.83);
    float P2 = findP(EXP1);

    //road 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int index = 0;
    if (E2 / 10 > 0) {
        index = E2 / 10 + E2 % 10;
        index = index % 10;
    } else {
        index = E2;
    }
    float P3 = (float) P[index] / 100;
//    cout << "--------- index " << index << " P1 " << P1 << " P2 " << P2 <<
//         " P3 " << P3 << endl;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 * 0.75);
    } else {
        int avgP = ceil(((float) (P1 + P2 + P3) / 3) * 100);
//        cout << "--------- sum P = " << (float) (P1 + P2 + P3) << " AVG P = " << avgP << endl;
        if (avgP < 50) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        } else {
            HP1 = ceil(HP1 * 0.90);
            EXP1 = ceil(EXP1 * 1.20);
        }
    }

    EXP1 = checkRange(EXP1, 0, 600);
    HP1 = checkRange(HP1, 0, 666);
    M1 = checkRange(M1, 0, 3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    // TODO: Complete this function
    int matrix[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // show up matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 1;
}

// Task 4
void getSE(char *se, const char *email) {
    bool checkSEComplete = false;
    for (int i = 0; email[i] != '\0'; ++i) {
        if (email[i] == '@') {
            checkSEComplete = true;
            continue;
        }
        if (!checkSEComplete) {
            se[i] = email[i];
            se[i + 1] = '\0';
        }
    }
}

int indexOfString(const char *s, const char *se) {
    for (int i = 0; s[i] != '\0'; ++i) {
        //012345pink ->
        int j;
        for (j = 0; se[j] != '\0'; ++j) {
            //s[i+j] = 0 + 0 => s[0] check vs se[0] and so on
            //if s[0] != se[0] -> out j loop, continue i
            if (s[i + j] != se[j]) {
                break;
            }
        }
        //loop j done that mean matched se
        if (se[j] == '\0') {
            return -(300 + i);
        }
    }
    return 0;  // not match
}

int isSpecialChar(char ch) {
    return (ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!');
}

int checkChar(const char *s, int type) {
    bool isSpecial = false;
    int countSpecial = 0;
    int specialPosition = -1;
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; ++i) {
        if (s[i] == s[i + 1] && type == 1) {
            return -(400 + i);
        }
        if (isSpecialChar(s[i]) && type == 2) {
            isSpecial = true;
            break;
        }
        if (s[i] == '@' && type == 3) {
            countSpecial++;
            if (specialPosition == -1) {
                specialPosition = i + 1;
            }
        }
    }
    if (!isSpecial && type == 2) {
        return -5;
    }
    if (countSpecial > 1) {
        return specialPosition;
    }
    return 0;
}

int checkPassword(const char *s, const char *email) {
    // TODO: Complete this function
    char se[50];
    getSE(se, email);
    int s_length = strlen(s);
    int result = -99;
    if (s_length < 8) {
        result = -1;
        return result;
    } else if (s_length > 20) {
        result = -2;
        return result;
    }
    //s match se case
    if (indexOfString(s, se) != 0) {
        result = indexOfString(s, se);
    } else if (checkChar(s, 1) != 0) {
        //more than 2
        result = checkChar(s, 1);
    } else if (checkChar(s, 2) != 0) {
        //special char
        result = checkChar(s, 2);
    } else if (checkChar(email, 3) != 0) {
        result = checkChar(email, 3);
    } else if (strlen(email) > 100) {
        result = 1;
    }
    return result;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char *most_pwd = nullptr;
    int match_count = 0;
    int match_index = -1;
    for (int i = 0; i < num_pwds; ++i) {
        int current = 1;
        const char *current_password = arr_pwds[i];
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(current_password, arr_pwds[j]) == 0) {
                ++current;
            }
        }
        if (current > match_count || (current == match_count && strlen(arr_pwds[i]) > strlen(most_pwd))) {
            match_count = current;
            most_pwd = arr_pwds[i];
            match_index = i;
        }
    }
//    cout << most_pwd << " " << match_index << endl;
    return match_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////