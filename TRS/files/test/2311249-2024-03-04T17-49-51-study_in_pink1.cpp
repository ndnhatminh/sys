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

// Kiem Tra Gia Tri Exp[0;600], Hp[0;666], M[0;300]
int checkValueExp(int exp) {
    if (exp < 0) { exp = 0; }
    else if (exp > 600) { exp = 600; }
    return exp;
}
int checkValueHp(int HP) {
    if (HP < 0) { HP = 0; }
    else if (HP > 666) { HP = 666; }
    return HP;
}
int checkValueM(int M){
    if (M < 0) { M = 0; }
    else if (M > 3000) { M = 3000; }
    return M;
}
//Tim So Chinh Phuong Gan Nhat
int soChinhPhuongGanNhat(int S){
    if (S - sqrt(S) * sqrt(S) < ceil(sqrt(static_cast<double>(S))) * ceil(sqrt(static_cast<double>(S)) - S)) {
        return ceil(sqrt(static_cast<double>(S)))* ceil(sqrt(static_cast<double>(S)));
    }
    else return sqrt(S)* sqrt(S);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 99) {
        exp2 = checkValueExp(exp2);
        exp1 = checkValueExp(exp1);
        //case1
        if (e1 >= 0 && e1 <= 3) {
            switch (e1)
            {
            case 0:
                exp2 += 29;
                exp2 = checkValueExp(exp2);
                break;
            case 1:
                exp2 += 45;
                exp2 = checkValueExp(exp2);
                break;
            case 2:
                exp2 += 75;
                exp2 = checkValueExp(exp2);
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
                exp2 = checkValueExp(exp2);
                break;
            default:
                break;
            }
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0) {
                exp1 = ceil(static_cast<double>(exp1) + static_cast<double>(D) / 200);
                exp1 = checkValueExp(exp1);
            }
            else {
                exp1 = ceil(static_cast<double>(exp1) - static_cast<double>(D) / 100);
                exp1 = checkValueExp(exp1);
            }
        }
        //case 2
        else {
            if (e1 >= 4 && e1 <= 19) {
                exp2 = ceil(static_cast<double>(exp2) + static_cast<double>(e1) / 4 + 19);
                exp2 = checkValueExp(exp2);
            }
            else if (e1 >= 20 && e1 <= 49) {
                exp2 = ceil(static_cast<double>(exp2) + static_cast<double>(e1) / 9 + 21);
                exp2 = checkValueExp(exp2);
            }
            else if (e1 >= 50 && e1 <= 65) {
                exp2 = ceil(static_cast<double>(exp2) + static_cast<double>(e1) / 16 + 17);
                exp2 = checkValueExp(exp2);
            }
            else if (e1 >= 66 && e1 <= 79) {
                exp2 = ceil(static_cast<double>(exp2 + static_cast<double>(e1) / 4 + 19));
                if (exp2 > 200) {
                    exp2 = ceil(static_cast<double>(exp2) + static_cast<double>(e1) / 9 + 21);
                    exp2 = checkValueExp(exp2);
                }
            }
            else if (e1 >= 80 && e1 <= 99) {
                exp2 = ceil(static_cast<double>(exp2) +static_cast<double>(e1) / 4 + 19);
                exp2 = ceil(static_cast<double>(exp2) + static_cast<double>(e1) / 9 + 21);
                exp2 = checkValueExp(exp2);
                if (exp2 > 400) {
                    exp2 = ceil(static_cast<double>(exp2) + static_cast<double>(e1) / 16 + 17);
                    exp2 = ceil(static_cast<double>(exp2) *1.15);
                    exp2 = checkValueExp(exp2);
                }
            }
            exp1 -= e1;
        }
        exp1 = checkValueExp(exp1);
        exp2 = checkValueExp(exp2);
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    double P1, P2, P3, Pavg;
    HP1 = checkValueHp(HP1);
    EXP1 = checkValueExp(EXP1);
    M1 = checkValueM(M1);
    int moneyspent = 0;
    double m = M1 * 0.5;//50% So Tien Ban Dau
    if (E2 >= 0 && E2 <= 99) {
        if (EXP1 >= soChinhPhuongGanNhat(EXP1)) {
            P1 = 100;
        }
        else {
            P1 = (static_cast<double>(EXP1) / soChinhPhuongGanNhat(EXP1) + 80) * 100 / 123;
        }
        //Con Duong 02
        if (E2 % 2 == 1) {
            do {
                if (HP1 < 200) {
                    HP1 = ceil(static_cast<double>(HP1) * 1.3);
                    M1 -= 150;
                    moneyspent += 150;
                    HP1 = checkValueHp(HP1);
                    M1 = checkValueM(M1);
                }
                else {
                    HP1 = ceil(static_cast<double>(HP1) * 1.1);
                    M1 -= 70;
                    moneyspent += 70;
                    HP1 = checkValueHp(HP1);
                    M1 = checkValueM(M1);
                }
                if (moneyspent <= m) {
                    if (EXP1 < 400) {
                        EXP1 = ceil(static_cast<double>(EXP1) * 1.13);
                        M1 -= 200;
                        moneyspent += 200;
                        EXP1 = checkValueExp(EXP1);
                        M1 = checkValueM(M1);
                    }
                    else {
                        EXP1 = ceil(static_cast<double>(EXP1) * 1.13);
                        M1 -= 120;
                        moneyspent += 120;
                        EXP1 = checkValueExp(EXP1);
                        M1 = checkValueM(M1);
                    }
                }
                else {
                    break;
                }
                    if (moneyspent <= m) {
                        if (EXP1 < 300) {
                            EXP1 = ceil(static_cast<double>(EXP1) * 0.9);
                            M1 -= 100;
                            moneyspent += 100;
                            EXP1 = checkValueExp(EXP1);
                            M1 = checkValueM(M1);
                        }
                        else {
                            EXP1 = ceil(static_cast<double>(EXP1) * 0.9);
                            M1 -= 120;
                            moneyspent += 120;
                            EXP1 = checkValueExp(EXP1);
                            M1 = checkValueM(M1);
                        }
                    }
                    else { break; }
            } while (moneyspent <= m);
            HP1 = ceil(static_cast<double>(HP1) * 0.83);
            EXP1 = ceil(static_cast<double>(EXP1) * 1.17);
            HP1 = checkValueHp(HP1);
            EXP1 = checkValueExp(EXP1);
        }
        else {
            if (HP1 < 200) {
                HP1 = ceil(static_cast<double>(HP1) * 1.3);
                M1 -= 150;
                moneyspent += 150;
                HP1 = checkValueHp(HP1);
                M1 = checkValueM(M1);
            }
            else {
                HP1 = ceil(static_cast<double>(HP1) * 1.1);
                M1 -= 70;
                moneyspent += 70;
                HP1 = checkValueHp(HP1);
                M1 = checkValueM(M1);
            }
            if (M1 != 0) {
                if (EXP1 < 400) {
                    EXP1 = ceil(static_cast<double>(EXP1) * 1.13);
                    M1 -= 200;
                    moneyspent += 200;
                    EXP1 = checkValueExp(EXP1);
                    M1 = checkValueM(M1);
                }
                else {
                    EXP1 = ceil(static_cast<double>(EXP1) * 1.13);
                    M1 -= 120;
                    moneyspent += 120;
                    EXP1 = checkValueExp(EXP1);
                    M1 = checkValueM(M1);
                }
            }
                if (M1 != 0) {
                    if (EXP1 < 300) {
                        EXP1 = ceil(static_cast<double>(EXP1) * 0.9);
                        M1 -= 100;
                        moneyspent += 100;
                        EXP1 = checkValueExp(EXP1);
                        M1 = checkValueM(M1);
                    }
                    else {
                        EXP1 = ceil(static_cast<double>(EXP1) * 0.9);
                        M1 -= 120;
                        moneyspent += 120;
                        EXP1 = checkValueExp(EXP1);
                        M1 = checkValueM(M1);
                    }
                }
            HP1 = ceil(static_cast<double>(HP1) * 0.83);
            EXP1 = ceil(static_cast<double>(EXP1) * 1.17);
            HP1 = checkValueHp(HP1);
            EXP1 = checkValueExp(EXP1);
        }
        if (EXP1 >= soChinhPhuongGanNhat(EXP1)) {
            P2 = 100/100;
        }
        else {
            P2 = (static_cast<double>(EXP1) / soChinhPhuongGanNhat(EXP1) + 80) *100 / 123;
        }
        //Con duong 03
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 / 10 == 0) {
            P3 = P[E2];
        }
        else {
            int i = (E2 / 10) + (E2 % 10);
            P3 = P[(i % 10)];
        }
        //Tong ket
        if (P1 == 100 && P2 == 100 && P3 == 100) {
            EXP1 = ceil(static_cast<double>(EXP1) * 0.75);
            EXP1 = checkValueExp(EXP1);
        }
        else {
            Pavg = (P1 + P2 + P3) / 3;
            if (Pavg < 50) {
                HP1 = ceil(static_cast<double>(HP1) * 0.85);
                EXP1 = ceil(static_cast<double>(EXP1) * 1.15 );
                HP1 = checkValueHp(HP1);
                EXP1 = checkValueExp(EXP1);
            }
            else {
                HP1 = ceil(static_cast<double>(HP1) * 0.9);
                EXP1 = ceil(static_cast<double>(EXP1) * 1.2);
                HP1 = checkValueHp(HP1);
                EXP1 = checkValueExp(EXP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int result;
    if (E3 >= 0 && E3 <= 99) {
        HP1 = checkValueHp(HP1);
        HP2 = checkValueHp(HP2);
        EXP2 = checkValueExp(EXP2);
        EXP1 = checkValueExp(EXP1);
        int map[10][10];
        //nap phan tu vao ma tran
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = (E3 * j + i * 2) * (i - j);
            }
        }
        int less = 0;
        int more = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] > (E3 * 2)) {
                    more++;
                }
                else if (map[i][j] < -E3) {
                    less++;
                }
            }
        }
        do {
            more = more / 10 + more % 10;
        } while (more / 10 != 0);
        do {
            less = less / 10 + less % 10;
        } while (less / 10 != 0);
        int taxipointleft[20], taxipointright[20];
        taxipointleft[more] = map[more][less];
        if (more < less) {
                //cheo tren
                for (int i = 0; i < more; i++) {
                    for (int j = less - more; j < less; j++) {
                        taxipointleft[i] = map[i][j];
                        break;
                    }
                }
                //cheo duoi
                for (int i = more + 1; i < 10; i++) {
                    for (int j = less + 1; j < 10; j++) {
                        taxipointleft[i] = map[i][j];
                        break;
                    }
                    if (taxipointleft[i] == map[i][9]) {
                        break;
                    }
                    else { continue; }
                }
            }
        else {
                for (int i = more - less; i < more; i++) {
                    for (int j = 0; j < less; j++) {
                        taxipointleft[j] = map[i][j];
                        break;
                    }
                }
                for (int i = more + 1; i < 10; i++) {
                    for (int j = less + 1; j < 10; j++) {
                        taxipointleft[j] = map[i][j];
                        break;
                    }
                    if (taxipointleft[i] == map[i][9]) {
                        break;
                    }
                }
            }
            //cheo phai
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if ((i + j) == (more + less)) {
                        taxipointright[i] = map[i][j];
                        break;
                    }
                }
            }
        int score=0;
        for (int i = 0; i < sizeof(taxipointleft); i++) {
                if (score < taxipointleft[i]) { score = taxipointleft[i]; }
            }
        for (int i = 0; i < sizeof(taxipointright); i++) {
                if (score < taxipointright[i]) { score = taxipointright[i]; }
            }
        if (abs(map[more][less]) < score) {
                HP1 = ceil(static_cast<double>(HP1) * 1.1);
                HP2 = ceil(static_cast<double>(HP2) * 1.1);
                EXP1 = ceil(static_cast<double>(EXP1) * 1.12);
                EXP2 = ceil(static_cast<double>(EXP2) * 1.12);
                EXP1 = checkValueExp(EXP1);
                EXP2 = checkValueExp(EXP2);
                HP1 = checkValueHp(HP1);
                HP2 = checkValueHp(HP2);
                result = score;
            }
            else {
                HP1 = ceil(static_cast<double>(HP1) * 0.9);
                HP2 = ceil(static_cast<double>(HP2) * 0.9);
                EXP1 = ceil(static_cast<double>(EXP1) * 0.88);
                EXP2 = ceil(static_cast<double>(EXP2) * 0.88);
                EXP1 = checkValueExp(EXP1);
                EXP2 = checkValueExp(EXP2);
                HP1 = checkValueHp(HP1);
                HP2 = checkValueHp(HP2);
                result = map[more][less];
            }
        }
    else
    {
        result = -99;
    }
    return result;
}

// Task 4
    int checkPassword(const char* s, const char* email) {
        // TODO: Complete this function
        string se;
        int sei, sci;
        int check=0;
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] != '@') {
                se[i] = email[i];
            }
            else { 
                break; }
        }
        if (strlen(s) < 8) {
            check++;
            return -1;
        }
        else if (strlen(s) > 20) {
            check++;
            return -2;
        }
        else {
            for (int i = 0; i < strlen(s); i++) {
                if (s[i] == se[0]) {
                    sei = i;
                    check++;
                    break;
                }
            }
            return -(300 + sei);
        }
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
                check++;
                sci = i;
                break;
            }
        }
        return -(400 + sci);
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                break;
            }
            else {
                check++;
                return -5;
            }
            }
        if (check == 0) {
            return -10;
        }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Tao bien dem
    int countmax = 0;
    int lengthmax = 0;
    int a = -1;
    const char* password;
    // Tim mat khau dung
    for (int i = 0; i < num_pwds; ++i) {
        const char* password = arr_pwds[i];
        int count = 0;
        int length = strlen(password);
        // Tinh so lan xuat hien cua 1 mat khau trong mang
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds[j] == password) {
                count++;
            }
        }
        // Kiem tra mat khau
        if (count > countmax || (count == countmax && length > lengthmax)) {
            countmax = count;
            lengthmax = length;
            a = i;
        }
    }

    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////