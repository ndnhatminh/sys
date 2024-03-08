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

void explimitation(int& exp) {
    if (exp < 0) exp = 0; else if (exp > 600) exp = 600;
}

void moneylimitation(int& m) {
    if (m < 0) m = 0; else if (m > 3000) m = 3000;
}

void hplimitation(int& hp) {
    if (hp < 0) hp = 0; else if (hp > 666) hp = 666;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 >= 0 && e1 < 4) {

        explimitation(exp1);
        explimitation(exp2);

        switch (e1) {
        case 0:
            exp2 += 29;
            explimitation(exp2);
            break;
        case 1:
            exp2 += 45;
            explimitation(exp2);
            break;
        case 2:
            exp2 += 75;
            explimitation(exp2);
            break;
        case 3:
            exp2 += 29 + 45 + 75;
            explimitation(exp2);
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil((double)exp1 + (double)D / 200);
        else exp1 = ceil((double)exp1 - (double)D / 100);
        explimitation(exp1);

        return exp1 + exp2;
    }
    else if (e1 >= 4 && e1 <= 99) {

        explimitation(exp1);
        explimitation(exp2);

        if (e1 <= 19) exp2 += ceil((double)e1 / 4 + 19);

        if (e1 >= 20 && e1 <= 49) exp2 += ceil((double)e1 / 9 + 21);

        if (e1 >= 50 && e1 <= 65) exp2 += ceil((double)e1 / 16 + 17);

        if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil((double)e1 / 4 + 19);
            explimitation(exp2);
            if (exp2 > 200) exp2 += ceil((double)e1 / 9 + 21);
            explimitation(exp2);
        }

        if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil((double)e1 / 4 + 19);
            explimitation(exp2);
            exp2 += ceil((double)e1 / 9 + 21);
            explimitation(exp2);
            if (exp2 > 400) {
                exp2 += ceil((double)e1 / 16 + 17);
                explimitation(exp2);
                exp2 = ceil(exp2 * 1.15);
                explimitation(exp2);
            }
        }
        exp1 -= e1;
        explimitation(exp2);
        explimitation(exp1);

        return exp1 + exp2;
    }
    else return -99;
}

// Task 2

float percentagelmao(int exp) { //tính lượng exp nhận được sau mỗi đường
    int rot = sqrt(exp);
    if (abs(exp - pow(rot + 1, 2)) < abs(exp - pow(rot, 2))) rot++;
    float p1 = 0.0;
    if (exp >= pow(rot, 2)) p1 = 1.0;
    else p1 = (exp / pow(rot, 2) + 80) / 123;

    return p1;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {

    if (E2 >= 0 && E2 <= 99) {

        explimitation(EXP1);
        hplimitation(HP1);
        moneylimitation(M1);

        int fm = ceil(M1 / 2), expense = 0, st = 0;

        float totalp = 0.0;

        totalp += percentagelmao(EXP1);  //con đường số 1 đã xong

        if (E2 % 2 != 0) {
            while (expense <= fm && M1 > 0) {

                if (HP1 < 200) {    // uống nước
                    HP1 = ceil(HP1 + (double)HP1 * 0.3);
                    expense += 150;
                    hplimitation(HP1);
                    if (expense > fm) break;
                }
                else {
                    HP1 = ceil(HP1 + (double)HP1 * 0.1);
                    expense += 70;
                    hplimitation(HP1);
                    if (expense > fm) break;
                }

                if (EXP1 < 400) {       //đi xe ngựa
                    EXP1 = ceil(EXP1 + (double)EXP1 * 0.13);
                    expense += 200;
                    explimitation(EXP1);
                    if (expense > fm) break;
                }
                else {
                    EXP1 = ceil(EXP1 + (double)EXP1 * 0.13);
                    expense += 120;
                    explimitation(EXP1);
                    if (expense > fm) break;
                }

                if (EXP1 < 300) {      //người qua đường
                    EXP1 = ceil(EXP1 - (double)EXP1 * 0.1);
                    expense += 100;
                    explimitation(EXP1);
                    if (expense > fm) break;
                }
                else {
                    EXP1 = ceil(EXP1 - (double)EXP1 * 0.1);
                    expense += 120;
                    explimitation(EXP1);
                    if (expense > fm) break;
                }
            }
            EXP1 = ceil(EXP1 + (double)EXP1 * 0.17);
            HP1 = ceil(HP1 - (double)HP1 * 0.17);
            M1 -= expense;
            hplimitation(HP1);
            explimitation(EXP1);
            moneylimitation(M1);
        }
        else {
            if (HP1 < 200) {
                if (expense < M1 && M1 != 0) {// uống nước
                    HP1 = ceil(HP1 + (double)HP1 * 0.3);
                    expense += 150;
                    hplimitation(HP1);
                }
            }
            else {
                if (expense < M1 && M1 != 0) {
                    HP1 = ceil(HP1 + (double)HP1 * 0.1);
                    expense += 70;
                    hplimitation(HP1);
                }
            }

            if (EXP1 < 400) {
                if (expense < M1 && M1 != 0) {   // đi xe ngựa
                    EXP1 = ceil(EXP1 + (double)EXP1 * 0.13);
                    expense += 200;
                    explimitation(EXP1);
                }
            }
            else {
                if (expense < M1 && M1 != 0) {
                    EXP1 = ceil(EXP1 + (double)EXP1 * 0.13);
                    expense += 120;
                    explimitation(EXP1);
                }
            }

            if (EXP1 < 300) {      //người qua đường
                if (expense < M1 && M1 != 0) {
                    EXP1 = ceil(EXP1 - (double)EXP1 * 0.1);
                    expense += 100;
                    explimitation(EXP1);
                }
            }
            else {
                if (expense < M1 && M1 != 0) {
                    EXP1 = ceil(EXP1 - (double)EXP1 * 0.1);
                    expense += 120;
                    explimitation(EXP1);
                }
            }

            EXP1 = ceil(EXP1 + (double)EXP1 * 0.17);
            HP1 = ceil(HP1 - (double)HP1 * 0.17);
            M1 -= expense;
            hplimitation(HP1);
            explimitation(EXP1);
            moneylimitation(M1);
        }

        totalp += percentagelmao(EXP1);  // con đường số 2 đã hoàn thành

        expense = E2;

        int pe[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 <= 9) st = E2; else {
            while (expense != 0) {
                st += expense % 10;
                expense = expense / 10;
            }
            if (st > 9) st = st % 10;
        }

        totalp += (double)pe[st] / 100;                         // con đường số 3 đã hoàn thành

        if (totalp == 3.0) {
            EXP1 = ceil(EXP1 - (double)EXP1 * 0.25);
            explimitation(EXP1);
        }
        else {
            totalp = totalp / 3.0;                                      // tính tổng phần trăm có được, nếu bằng 3 thì trừ exp

            if (totalp < 0.5) {
                EXP1 = ceil(EXP1 + (double)EXP1 * 0.15);
                HP1 = ceil(HP1 - (double)HP1 * 0.15);
                hplimitation(HP1);
                explimitation(EXP1);
            }
            else {
                EXP1 = ceil(EXP1 + (double)EXP1 * 0.2);
                HP1 = ceil(HP1 - (double)HP1 * 0.1);
                hplimitation(HP1);
                explimitation(EXP1);
            }
        }
    }
    else return -99;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {

    int taxi[10][10], columnpos = 0, rowpos = 0, tcpos = 0, trpos = 0;

    // Tính giá trị mảng taxi
    if (E3 >= 0 && E3 <= 99) {

        hplimitation(HP1); hplimitation(HP2); explimitation(EXP1); explimitation(EXP2);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);

                if (taxi[i][j] > E3 * 2) {
                    rowpos++;

                }
                else if (taxi[i][j] < -E3) {
                    columnpos++;
                }
            }
        }

        // Tính vị trí gặp nhau

        while (rowpos > 9) {
            rowpos = rowpos % 10 + rowpos / 10;
        }

        while (columnpos > 9) {
            columnpos = columnpos % 10 + columnpos / 10;
        }

        // Tìm giá trị lớn nhất của đường chéo trái 

        int sherlock = taxi[rowpos][columnpos];

        if (rowpos > columnpos || rowpos == columnpos) {
            trpos = rowpos - columnpos;
            tcpos = columnpos - columnpos;
        }
        else if (rowpos < columnpos) {
            tcpos = columnpos - rowpos;
            trpos = rowpos - rowpos;
        }

        int j = tcpos;
        if (tcpos >= 0 && trpos >= 0) {
            for (int i = trpos; i < 10; i++) {
                if (taxi[i][j] >= sherlock) sherlock = taxi[i][j];
                j++;
                if (j > 9) break;
            }
        }

        // Tìm giá trị lớn nhất của đường chéo phải + so với giá trị lớn nhất ban đầu tìm được

        tcpos = columnpos;
        trpos = rowpos;

        while (tcpos > 0 && trpos < 9) {
            tcpos--;
            trpos++;
        }

        j = tcpos;
        if (trpos >= 0 && tcpos >= 0) {
            for (int i = trpos; i > 0; i--) {
                if (taxi[i][j] >= sherlock) sherlock = taxi[i][j];
                j++;
                if (j > 9) break;
            }
        }

        //Tính exp, trả về các giá trị cần thiết

        sherlock = abs(sherlock);

        if (abs(taxi[rowpos][columnpos]) > sherlock) {
            EXP2 = ceil((double)EXP2 * 88 / 100);
            HP2 = ceil((double)HP2 * 90 / 100);
            EXP1 = ceil((double)EXP1 * 88 / 100);
            HP1 = ceil((double)HP1 * 90 / 100);
            hplimitation(HP1); hplimitation(HP2); explimitation(EXP1); explimitation(EXP2);
            return taxi[rowpos][columnpos];
        }
        else {
            EXP2 = ceil((double)EXP2 * 112 / 100);
            HP2 = ceil((double)HP2 * 110 / 100);
            EXP1 = ceil((double)EXP1 * 112 / 100);
            HP1 = ceil((double)HP1 * 110 / 100);
            hplimitation(HP1); hplimitation(HP2); explimitation(EXP1); explimitation(EXP2);
            return sherlock;
        }
    }
    else return -99;
}
// Task 4
int checkPassword(const char* s, const char* email) {
    string pass(s);
    string mail(email);
    string se = "";
    int dodai = pass.length();
    int sizese = 0;

    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] == '@') {
            sizese = i;
            break;
        }
    }

    se = mail.substr(0, sizese);   //trích xuất từ chuỗi mail 1 chuỗi con se từ vị trí 0 và có độ dài bằng sizese

    int n = pass.find(se);      // tìm kiếm sự xuất hiện của chuỗi se trong chuỗi pass, trả về vị trí đầu tiên xuất hiện 

    if (dodai < 8) return -1;

    if (dodai > 20) return -2;


    if (n != -1) {     // -1 đại diện cho string::npos, hay không tìm thấy chuỗi con trong chuỗi mẹ
        return -(300 + n);
    }


    for (int i = 0; i <= dodai - 2; i++) {
        if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2]) {
            return -(400 + i);
        }
    }

    for (int i = 0; i < dodai; i++) {
        if (int(pass[i]) < 33 || int(pass[i]) == 34 || (int(pass[i]) >= 38 && int(pass[i]) < 48) || (int(pass[i]) >= 58 && int(pass[i]) <= 63) || (int(pass[i]) >= 91 && int(pass[i]) <= 96) || int(pass[i]) >= 123) {
            return i;
        }
    }

    bool cod = false;
    for (int i = 0; i < dodai; i++) {
        if (int(pass[i]) == 33 || int(pass[i]) == 64 || (int(pass[i]) >= 35 && int(pass[i]) <= 37)) {     // ==33 ==64 >=35 <=37
            cod = true;
            break;
        }
    }

    if (cod == false) return -5;

    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int mte = 0, pos = 0;
    string maxString;

    for (int i = 0; i < num_pwds; i++) {
        string temp = arr_pwds[i];
        if (temp == "") continue;
        int te = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (temp == arr_pwds[j]) {
                arr_pwds[j] = "";
                te++;
            }
        }
        if (te > mte || (te == mte && temp.length() > maxString.length())) {
            mte = te;
            maxString = arr_pwds[i];
            pos = i;
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////