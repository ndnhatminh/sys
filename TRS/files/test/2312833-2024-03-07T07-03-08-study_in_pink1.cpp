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

// Check HP
int check_HP(int n) {
    if (n > 666) {
        return 666;
    }
    else if (n < 0) {
        return 0;
    }
    else return n;
}

// Check EXP
int check_EXP(int n) {
    if (n > 600) {
        return 600;
    }
    else if (n < 0) {
        return 0;
    }
    else return n;
}

// Check M
int check_M(int n) {
    if (n > 3000) {
        return 3000;
    }
    else if (n < 0) {
        return 0;
    }
    else return n;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    else {
        //Truong hop 1
        if (e1 >= 0 && e1 <= 3) {
            switch (e1) {
            case 0: exp2 += 29;
                break;
            case 1: exp2 += 45;
                break;
            case 2: exp2 += 75;
                break;
            case 3: exp2 += 29 + 45 + 75;
                break;
            };
            exp2 = check_EXP(exp2);

            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 = ceil(exp1 + D / 200.0);
            }
            else exp1 = ceil(exp1 - D / 100.0);
            exp1 = check_EXP(exp1);
        };
        // Truong hop 2
        if (e1 >= 4 && e1 <= 99) {
            if (e1 >= 4 && e1 <= 19) {
                exp2 = exp2 + ceil((e1 / 4.0 + 19));
                exp2 = check_EXP(exp2);
            }
            else if (e1 >= 20 && e1 <= 49) {
                exp2 = exp2 + ceil((e1 / 9.0 + 21));
                exp2 = check_EXP(exp2);
            }
            else if (e1 >= 50 && e1 <= 65) {
                exp2 = exp2 + ceil((e1 / 16.0 + 17));
                exp2 = check_EXP(exp2);
            }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = exp2 + ceil((e1 / 4.0 + 19));
                exp2 = check_EXP(exp2);
                if (exp2 > 200) {
                    exp2 = exp2 + ceil((e1 / 9.0 + 21));
                    exp2 = check_EXP(exp2);
                };
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 = exp2 + ceil((e1 / 4.0 + 19));
                exp2 = check_EXP(exp2);
                exp2 = exp2 + ceil((e1 / 9.0 + 21));
                exp2 = check_EXP(exp2);
                if (exp2 > 400) {
                    exp2 = exp2 + ceil((e1 / 16.0 + 17));
                    exp2 = check_EXP(exp2);
                    exp2 = exp2 + ceil(exp2 * 0.15);
                    exp2 = check_EXP(exp2);
                };
            };
            exp1 -= e1;
            exp1 = check_EXP(exp1);

        };

        return exp1 + exp2;
    }
}

// Task 2

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    else {
        // Con duong 01
        int S, a;
        float P1;
        for (int i = 0; i <= sqrt(EXP1); i++) {
            if (i * i == EXP1) {
                S = EXP1;
            }
            else {
                S = i * i;
                a = (i + 1) * (i + 1);
            }
            if (EXP1 - S > a - EXP1) {
                S = a;
            }

        }
        if (EXP1 >= S) {
            P1 = 1;
        }
        else P1 = ((EXP1 * 1.0) / S + 80) / 123;

        // Con duong 02
        const int half = (M1 / 2);
        if (M1 <= 0) {

        }
        else {
            if (E2 % 2 == 0) {
                if (HP1 < 200) {
                    HP1 = HP1 + ceil(HP1 * 0.3);
                    M1 -= 150;
                    M1 = check_M(M1);
                    HP1 = check_HP(HP1);
                }
                else {
                    HP1 = HP1 + ceil(HP1 * 0.1);
                    M1 -= 70;
                    M1 = check_M(M1);
                    HP1 = check_HP(HP1);
                }
                if (M1 > 0) {
                    if (EXP1 < 400) {
                        M1 -= 200;
                        M1 = check_M(M1);
                    }
                    else {
                        M1 -= 120;
                        M1 = check_M(M1);
                    }
                    EXP1 = EXP1 + ceil(EXP1 * 0.13);
                    EXP1 = check_EXP(EXP1);

                    if (M1 > 0) {
                        if (EXP1 < 300) {
                            M1 -= 100;
                            M1 = check_M(M1);
                        }
                        else {
                            M1 -= 120;
                            M1 = check_M(M1);
                        }
                        EXP1 = ceil(EXP1 * 0.9);
                        EXP1 = check_EXP(EXP1);
                    }
                }
            }
            else {
                int spend = 0;
                for (int i = 0; ; i++) {
                    // Su kien 1
                    if (HP1 < 200) {
                        HP1 = HP1 + ceil(HP1 * 0.3);
                        M1 -= 150;
                        M1 = check_M(M1);
                        HP1 = check_HP(HP1);
                        spend += 150;
                    }
                    else {
                        HP1 = HP1 + ceil(HP1 * 0.1);
                        M1 -= 70;
                        M1 = check_M(M1);
                        HP1 = check_HP(HP1);
                        spend += 70;
                    }
                    // Su kien 2
                    if (spend > half) {
                        break;
                    }
                    else {
                        if (EXP1 < 400) {
                            M1 -= 200;
                            M1 = check_M(M1);
                            spend += 200;
                        }
                        else {
                            M1 -= 120;
                            M1 = check_M(M1);
                            spend += 120;
                        }
                        EXP1 = EXP1 + ceil(EXP1 * 0.13);
                        EXP1 = check_EXP(EXP1);

                    }
                    // Su kien 3
                    if (spend > half) {
                        break;
                    }
                    else {
                        if (EXP1 < 300) {
                            M1 -= 100;
                            M1 = check_M(M1);
                            spend += 100;
                        }
                        else {
                            M1 -= 120;
                            M1 = check_M(M1);
                            spend += 120;
                        }
                        EXP1 = ceil(EXP1 * 0.9);
                        EXP1 = check_EXP(EXP1);

                        if (spend > half) {
                            break;
                        }
                    }
                }
            }
        }

        HP1 = ceil(HP1 * 0.83);
        EXP1 = EXP1 + ceil(EXP1 * 0.17);

        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);

        // Tinh xac suat P2
        float P2;
        for (int i = 0; i <= sqrt(EXP1); i++) {
            if (i * i == EXP1) {
                S = EXP1;
                break;
            }
            else {
                S = i * i;
                a = (i + 1) * (i + 1);
                if (EXP1 - S > a - EXP1) {
                    S = a;
                }
            }
        }
        if (EXP1 >= S) {
            P2 = 1;
        }   
        else P2 = ((EXP1 * 1.0) / S + 80) / 123;

        // Con duong 03

        const int arr[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int first, second;
        for (int i = 0; i < 2; i++) {
            first = E2 / 10;
            second = E2 - first * 10;
            E2 = first + second;
        }
        float P3 = arr[second];

        if (P1 + P2 + P3 / 100 == 100) {
            EXP1 = ceil(EXP1 * 0.75);
        }
        else {
            float Ptb = (P1 + P2 + P3 / 100) / 3;

            if (Ptb < 0.5) {
                HP1 = ceil(HP1 * 0.85);
                EXP1 = EXP1 + ceil(EXP1 * 0.15);
            }
            else {
                HP1 = ceil(HP1 * 0.9);
                EXP1 = EXP1 + ceil(EXP1 * 0.2);
            }
        }
        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);
        M1 = check_M(M1);
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    else {
        int map[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        // Tim so gia tri duong
        int pos = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] > (E3 * 2)) {
                    pos++;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            int a = pos / 10;
            int b = pos - a * 10;
            pos = a + b;
        }

        // Tim so gia tri am
        int neg = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] < (-E3)) {
                    neg++;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            int a = neg / 10;
            int b = neg - a * 10;
            neg = a + b;
        }
        int maxl, maxr, max;
        int maxl1 = map[pos][neg];
        int maxl2 = map[pos][neg];
        int maxr1 = map[pos][neg];
        int maxr2 = map[pos][neg];
        // Diem Sherlock
        for (int i = 0; i < 10; i++) {

            if (pos + i > 9 || neg + i > 9) {
                break;
            }
            if (maxl1 <= map[pos + i][neg + i]) {
                maxl1 = map[pos + i][neg + i];
            }
        }
        for (int i = 0; i < 10; i++) {

            if (pos - i < 0 || neg - i < 0) {
                break;
            }
            if (maxl2 <= map[pos - i][neg - i]) {
                maxl2 = map[pos - i][neg - i];
            }
        }
        for (int i = 0; i < 10; i++) {

            if (pos + i > 9 || neg - i < 0) {
                break;
            }
            if (maxr1 <= map[pos + i][neg - i]) {
                maxr1 = map[pos + i][neg - i];
            }
        }
        for (int i = 0; i < 10; i++) {

            if (pos - i < 0 || neg + i > 9) {
                break;
            }
            if (maxr2 <= map[pos - i][neg + i]) {
                maxr2 = map[pos - i][neg + i];
            }
        }
        if (maxl1 >= maxl2) {
            maxl = maxl1;
        }
        else maxl = maxl2;
        if (maxr1 >= maxr2) {
            maxr = maxr1;
        }
        else maxr = maxr2;
        if (maxr >= maxl) {
            max = maxr;
        }
        else max = maxl;


        // Duoi kip
        if (abs(map[pos][neg]) > max) {
            EXP1 = ceil(EXP1 * 0.88);
            EXP2 = ceil(EXP2 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            HP2 = ceil(HP2 * 0.9);
        }
        else {
            EXP1 = EXP1 + ceil(EXP1 * 0.12);
            EXP2 = EXP2 + ceil(EXP2 * 0.12);
            HP1 = HP1 + ceil(HP1 * 0.1);
            HP2 = HP2 + ceil(HP2 * 0.1);
        }
        EXP1 = check_EXP(EXP1);
        EXP2 = check_EXP(EXP2);
        HP1 = check_HP(HP1);
        HP2 = check_HP(HP2);

        if (abs(map[pos][neg]) >= max) {
            return map[pos][neg];
        }
        else return max;
    }
}

// Task 4

// Tao se
string create_se(string s) {
    int position = s.find('@');
    string se = s.substr(0, position);
    return se;
}
//Check do dai password
int pass_length(string s) {
    if (s.length() < 8) {
        return -1;
    }
    else if (s.length() > 20) {
        return -2;
    }
    else return 10;
}

// Check chuoi se trong password
int check_se(string s, string se) {
    int position;
    position = s.find(se[0]);
    if (position == -1) {
        return 10;
    }
    else {
        int count = 0;
        for (int i = 0; i < se.length(); i++) {
            if (s[position + i] == se[i]) {
                count++;
            }
        }
        if (count == se.length()) {
            return -(300 + position);
        }
        else return 10;
    }
}
// Check ki tu giong nhau lien tiep
int check_char(string s) {
    int loop = 0, position;
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            loop++;
            position = s.find(s[i]);
            break;
        }
    }
    if (loop == 0) {
        return 10;
    }
    else return -(400 + position);
}

// Check ki tu dac biet
int special(string s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
            num++;
            break;
        default:;
        }
    }
    if (num == 0) {
        return -5;
    }
    else return 10;
}
// Truong hop con lai
int invalid_char(string s) {
    int found = 20;
    for (int i = 0; i < s.length(); i++) {
        switch ((int)s[i]) {
        case 32:
        case 34:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 123:
        case 124:
        case 125:
        case 126:
            found = s.find(s[i]);
            break;
        default:;
        }
        if (found != 20) {
            break;
        }
        else continue;
    }
    return found;
}

int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string pass(s);
    string mail(email);
    
    string se = create_se(mail);
    invalid_char(pass);
    pass_length(pass);
    check_se(pass, se);
    check_char(pass);
    special(pass);
    int value;

    if (pass_length(pass) == 10 && check_se(pass, se) == 10 && check_char(pass) == 10 && special(pass) == 10 && invalid_char(pass) == 20) {
        value = -10;
    }
    else if (pass_length(pass) != 10) {
        value = pass_length(pass);
    }
    else if (check_se(pass, se) != 10) {
        value = check_se(pass, se);
    }
    else if (check_char(pass) != 10) {
        value = check_char(pass);
    }
    else if (special(pass) != 10) {
        value = special(pass);
    }
    else if (invalid_char(pass) != 20) {
        value = invalid_char(pass);
    }
    return value;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[num_pwds] = { 0 };
    int maxCount = 0;
    // Dem so lan lap cua tung phan tu
    for (int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                count[i]++;
            }
        }
    }
    // Tim so lan lap nhieu nhat
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    // Tim phan tu lap nhieu nhat
    const char* repeat[num_pwds];
    const char* correct;
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount) {
            repeat[i] = arr_pwds[i];
        }
    }
    // Phan tu lap dau tien
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount) {
            correct = arr_pwds[i];
            break;
        }
    }
    
    for (int i = 0; i < num_pwds; i++) {
        if (count[i] == maxCount && repeat[i] != correct) {
            int length1 = strlen(correct);
            int length2 = strlen(repeat[i]);
            if (length1 < length2) {
                correct = repeat[i];
            }
            else if (length1 == length2) {

            }
        }
    }

    int position = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == correct) {
            position = i;
            break;
        }
    }

    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////