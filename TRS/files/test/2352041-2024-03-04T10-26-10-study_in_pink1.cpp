#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
void test(int& exp1, int& exp2) {
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;
}

int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || e1 > 99) return -99;
    test(exp1, exp2);

    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        if (e1 == 1) exp2 += 45;
        if (e1 == 2) exp2 += 75;
        if (e1 == 3) exp2 += 29 + 45 + 75;
        test(exp1, exp2);
        int d = ceil(e1 * 3 + exp1 * 7);
        if (d % 2 == 0) {
            exp1 += ceil(d / 200.0);
        }
        else {
            int calculation = exp1 - d / 100;
            exp1 = ceil(calculation);
        }
        test(exp1, exp2);
    }


    if (e1 >= 4 && e1 <= 99) {
        test(exp1, exp2);
        if (e1 >= 4 && e1 <= 19)  exp2 += ceil(double(e1) / 4 + 19);
        if (e1 >= 20 && e1 <= 49) exp2 += ceil(double(e1) / 9 + 21);
        if (e1 >= 50 && e1 <= 65) exp2 += ceil(double(e1) / 16 + 17);
        if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(double(e1) / 4 + 19);
            if (exp2 > 200) exp2 += ceil(double(e1) / 9 + 21);
        }

        if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(double(e1) / 4 + 19);
            exp2 += ceil(double(e1) / 9 + 21);
            if (exp2 > 400) {
                exp2 += ceil(double(e1) / 16 + 17);
                exp2 = ceil(double(exp2) * 1.15);
            }
        }
        exp1 = ceil(double(exp1) - e1);
        test(exp1, exp2);
    }

    return exp1 + exp2;
}

// Task 2
void test(int& EXP1, int& HP1, int& M1) {
    //EXP1
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    else if (EXP1 < 0) {
        EXP1 = 0;
    }
    //HP1
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;
    }
    //M1
    if (M1 < 0) {
        M1 = 0;
    }
    else if (M1 > 3000) {
        M1 = 3000;
    }
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    //E2
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    else {
        //ROAD 1
        double S;
        test(EXP1, HP1, M1);
        S = pow(round(sqrt(EXP1)), 2);
        //find P1
        double P1;
        if (EXP1 >= S) {
            P1 = 100.0;
        }
        else {
            P1 = (((EXP1 / S) + 80.0) / 123.0) * 100.0;
        }
        test(EXP1, HP1, M1);


        //ROAD 2
        //E2 LẺ
        if (E2 % 2 != 0) {
            int money = (M1 * 1.0 / 2);
            int consume = 0;
            while (consume <= money) {

                //event 1
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    consume += 150;
                    M1 -= 150;
                }
                else {
                    HP1 = ceil(HP1 * 1.1);
                    consume += 70;
                    M1 -= 70;

                }
                // so sánh chi và nửa tiền
                if (consume > money) {
                    break;
                }

                //event 2
                if (EXP1 < 400) {
                    M1 -= 200;
                    consume += 200;
                    EXP1 = ceil(EXP1 * 1.13);

                }
                else {
                    consume += 120;
                    M1 -= 120;
                    EXP1 = ceil(EXP1 * 1.13);

                }

                if (consume > money) {
                    break;
                }
                //event 3
                if (EXP1 < 300) {
                    consume += 100;
                    M1 -= 100;
                }
                else {
                    consume += 120;
                    M1 -= 120;
                }

                EXP1 = ceil(EXP1 * 0.9);

                if (consume > money) {
                    break;
                }

                //ĐI BỘ
                EXP1 = ceil(EXP1 * 1.17);
                HP1 = ceil(HP1 * 0.83);
                test(EXP1, HP1, M1);
            }
        }

        //E2 CHẴN
        else {
            test(EXP1, HP1, M1);;
            int consume = 0;
            while (M1 <= 0) {
                break;
            }
            //event 1
            if (M1 <= 0) {
                M1 = 0;
            }

            else {
                if (HP1 < 200) {
                    HP1 = ceil(HP1 * 1.3);
                    consume += 150;
                    M1 -= 150;
                }
                else {
                    HP1 = ceil(HP1 * 1.1);
                    consume += 70;
                    M1 -= 70;
                    test(EXP1, HP1, M1);;
                }
            }

            //event 2
            if (M1 <= 0) {
                M1 = 0;
            }
            else {
                if (EXP1 < 400) {
                    M1 -= 200;
                    consume += 200;
                    EXP1 = ceil(EXP1 * 1.13);

                }
                else {
                    consume += 120;
                    M1 -= 120;
                    EXP1 = ceil(EXP1 * 1.13);
                }
            }

            //event 3
            if (M1 <= 0) {
                M1 = 0;
            }
            else {
                if (EXP1 < 300) {
                    consume += 100;
                    M1 -= 100;
                }
                else {
                    consume += 120;
                    M1 -= 120;
                }
                EXP1 = ceil(EXP1 * 0.9);
            }

        }
        //ĐI BỘ
        EXP1 = ceil(EXP1 * 1.17);
        HP1 = ceil(HP1 * 0.83);
        test(EXP1, HP1, M1);;

        //Tìm P2
        double P2;
        double s = pow(round(sqrt(EXP1)), 2);

        if (EXP1 >= s) {
            P2 = 100.0;
        }
        else {
            P2 = (((EXP1 / s) + 80) / 123) * 100.0;
        }


        //ROAD 3
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int i;
        if (E2 < 10)
        {
            i = E2;
        }
        else {
            i = ceil((E2 / 10 + E2 % 10) % 10);
        }

        //Tìm P3
        double Pi;
        double P3 = P[i];


        //find P average
        Pi = (P1 + P2 + P3) / 3;
        if (Pi == 100)
        {
            EXP1 = ceil(EXP1 * 0.75);
        }

        if (Pi < 50)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else if (Pi >= 50)
        {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }

        test(EXP1, HP1, M1);;
        return HP1 + EXP1 + M1;
    }
}

//Task 3
void test(int& EXP1, int& EXP2, int& HP1, int& HP2, int& E3) {
    //EXP1
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    else if (EXP1 < 0) {
        EXP1 = 0;
    }
    //EXP2
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    else if (EXP2 < 0) {
        EXP2 = 0;
    }
    //HP1
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;
    }
    //HP2
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;
    }
    //E3
    if (E3 < 0 || E3 > 99) {
        E3 = -99;
    }
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {

    const int row = 10;
    const int column = 10;
    int matran[10][10] = { 0 };

    //khởi tạo giá trị ban đầu
    int large = 0;
    int small = 0;
    int i = 0;
    int j = 0;

    for (int k = 0; k < row; ++k) {
        for (int m = 0; m < column; ++m) {
            matran[k][m] = ((E3 * m) + (k * 2)) * (k - m);
        }
    }

    for (int k = 0; k < row; ++k) {
        for (int m = 0; m < column; ++m) {
            if (matran[k][m] > E3 * 2)
                large = large + 1;
            else if (matran[k][m] < (-E3))
                small = small + 1;
        }
    }

    //xử lý large & small 
    large = (large % 10) + (large / 10);
    small = (small % 10) + (small / 10);
    if (large >= 10)
        large = (large % 10) + (large / 10);
    if (small >= 10)
        small = (small % 10) + (small / 10);

    //Tìm score
    i = large;
    j = small;
    int score = 0;
    while (true) {
        if (i == 0 || j == 0) break;
        i--;
        j--;
    }
    while (true) {
        if (score < matran[i][j]) score = matran[i][j];
        if (i == 9 || j == 9) break;
        i++;
        j++;
    }
    i = large;
    j = small;
    while (true) {
        if (i == 0 || j == 9) break;
        i--;
        j++;
    }
    while (true) {
        if (score < matran[i][j]) score = matran[i][j];
        if (i == 9 || j == 0) break;
        i++;
        j--;
    }


    if (abs(matran[large][small]) > abs(score)) {
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        HP1 = ceil(HP1 - HP1 * 0.1);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
        HP2 = ceil(HP2 - HP2 * 0.1);
        score = matran[large][small];
    }
    else {
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        HP1 = ceil(HP1 + HP1 * 0.1);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
        HP2 = ceil(HP2 + HP2 * 0.1);
    }
    test(EXP1, EXP2, HP1, HP2, E3);
    return score;
    return -1;
}

// Task 4

int checkPassword(const char* s, const char* email) {
    //khai báo mảng
    char username[strlen(email) + 1];
    //sao chép email vào mảng username
    strcpy(username, email);

    //Độ dài chuỗi
    int length = strlen(s);
    if (length < 8) {
        return -1; // Mật khẩu ngắn hơn
    }

    if (length > 20) {
        return -2; // Mật khẩu dài hơn
    }

    // Kiểm tra se có tồn tại không
    char* se;
    se = strtok(username, "@"); //tách chuỗi
    const char* Save = strstr(s, se);
    if (Save) {
        int sei = Save - s;
        return -(300 + sei);
    }

    // Kiểm tra ký tự đặc biệc
    const char* Characters = "@#%$!";  //khai báo ký tự 
    const char* special = strpbrk(s, Characters);
    if (special == nullptr) {
        return -5;
    }

    // Kiểm tra hai ký tự liên tiếp giống nhau 
    for (int sci = 0; sci < length - 2; ++sci) {
        if (s[sci] == s[sci + 1] && s[sci] == s[sci + 2]) {
            return -(400 + sci);
        }
    }
    // Mật khẩu hợp lệ
    return -10;

    return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    int Maxcount = 0;
    int Maxlength = 0;
    int corpass = -1;
    int passcount;

    // số lần xuất hiện của mật khẩu và mật khẩu dài nhất
    for (int i = 0; i < num_pwds; i++) {
        passcount = 0;
        for (int k = 0; k < num_pwds; k++) {
            if (arr_pwds[i] == arr_pwds[k]) {
                passcount++;
            }
        }
        //tìm vị trí đầu của mật khẩu đúng
        int passlength = strlen(arr_pwds[i]);
        if (passcount > Maxcount || (passcount == Maxcount && passlength > Maxlength)) {
            Maxcount = passcount;
            Maxlength = passlength;
            corpass = i;
        }
    }
    return corpass;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////