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
int solonnhat(int a, int b, int c, int d) {
    int max = 0;
    if (a > max) max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}// so lon nhat trong 4 so
int solonmatran(int matrix[10][10], int hang, int cot) {
    int vh = hang, bh = hang, nh = hang, mh = hang;
    int vc = cot, bc = cot, nc = cot, mc = cot;
    int maxld = 0, maxlu = 0, maxrd = 0, maxru = 0;
    while (vh <= 9 && vc <= 9) {
        int traixuong = matrix[vh][vc];
        if (traixuong > maxld) {
            maxld = traixuong;
        }
        vh++; vc++;
    }
    while (nh >= 0 && nc >= 0) {
        int trailen = matrix[nh][nc];
        if (trailen > maxlu) {
            maxlu = trailen;
        }
        nh--, nc--;
    }
    while (bh <= 9 && bc >= 0) {
        int phaixuong = matrix[bh][bc];
        if (phaixuong > maxrd) {
            maxrd = phaixuong;
        }
        bh++, bc--;
    }
    while (mh >= 0 && mc <= 9) {
        int phailen = matrix[mh][mc];
        if (phailen > maxru) {
            maxru = phailen;
        }
        mh--; mc++;
    }
    int maxmatrix = solonnhat(maxld, maxlu, maxru, maxrd);
    if (maxmatrix < 0) {
        maxmatrix = abs(maxmatrix);
    }
    return maxmatrix;
}//so lon nhat trong ma tran

int khongchetien(int c) {
    if (c > 3000) { c = 3000; };
    if (c < 0) c = 0;
    return c;
}
int khongchemau(int b) {
    if (b > 666) { b = 666; };
    if (b < 0) { b = 0; };
    return b;
}
int khongchekinhnghiem(int a) {
    if (a > 600) {
        a = 600;
    }
    else if (a < 0) { a = 0; };

    return a;
}
int dua2chusove1(int a) {
    while (a > 9) {
        a = a / 10 + a - ((a / 10) * 10);
    }
    return a;
}// dua so co 2 chu so ve 1 chu so
int  lamtron(double x) {
    return static_cast<int>(x = x + 0.999);
}

int sochinhphuong(int d) {
    int h = static_cast<int>(sqrt(d));
    int j = h * h;
    int k = (h + 1) * (h + 1);
    if (abs(d - k) < abs(d - j)) {
        return k;
    }
    else return j;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    //truong hop 1
    if (E1 > 99 || E1 < 0) {
        return -99;
    }

    EXP1 = khongchekinhnghiem(EXP1);
    EXP2 = khongchekinhnghiem(EXP2);
    if (E1 <= 3 && E1 >= 0) {
        if (E1 == 0) {
            EXP2 = EXP2 + 29;
            EXP2 = khongchekinhnghiem(EXP2);
        }
        else if (E1 == 1) {
            EXP2 = EXP2 + 45;
            EXP2 = khongchekinhnghiem(EXP2);
        }
        else if (E1 == 2) {
            EXP2 = EXP2 + 75;
            EXP2 = khongchekinhnghiem(EXP2);
        }
        else { EXP2 = EXP2 + 29 + 75 + 45; EXP2 = khongchekinhnghiem(EXP2); };

        int d;
        d = E1 * 3 + EXP1 * 7;
        if ((d % 2) == 0) {
            EXP1 = lamtron(d * 0.005 + EXP1);

            EXP1 = khongchekinhnghiem(EXP1);
        }
        else {

            EXP1 = lamtron(-d * 0.01 + EXP1);
            EXP1 = khongchekinhnghiem(EXP1);
        }
    }
    //truong hop 2
    else if (E1 >= 4 && E1 <= 19) {

        EXP2 = lamtron(EXP2 + E1 / 4.0 + 19);
        EXP2 = khongchekinhnghiem(EXP2);
        EXP1 -= E1;
        EXP1 = khongchekinhnghiem(EXP1);
    }//1
    else if (E1 >= 20 && E1 <= 49) {

        EXP2 = lamtron(EXP2 + E1 / 9.0 + 21);
        EXP2 = khongchekinhnghiem(EXP2);
        EXP1 -= E1;
        EXP1 = khongchekinhnghiem(EXP1);//2
    }
    else if (E1 >= 50 && E1 <= 65) {

        EXP2 = lamtron(EXP2 + E1 / 16.0 + 17);
        EXP2 = khongchekinhnghiem(EXP2);
        EXP1 -= E1;
        EXP1 = khongchekinhnghiem(EXP1);//3
    }
    else if (E1 >= 66 && E1 <= 79) {

        EXP2 = lamtron(EXP2 + E1 / 4.0 + 19);
        EXP2 = khongchekinhnghiem(EXP2);
        if (EXP2 > 200) {

            EXP2 = lamtron(EXP2 + E1 / 9.0 + 21);
            EXP2 = khongchekinhnghiem(EXP2);//4
        }
        EXP1 -= E1;
        EXP1 = khongchekinhnghiem(EXP1);
    }
    else if (E1 >= 80 && E1 <= 99) {

        EXP2 = lamtron(EXP2 + E1 / 4.0 + 19);
        EXP2 = khongchekinhnghiem(EXP2);


        EXP2 = lamtron(EXP2 + E1 / 9.0 + 21);
        EXP2 = khongchekinhnghiem(EXP2);

        if (EXP2 > 400) {

            EXP2 = lamtron(EXP2 + E1 / 16.0 + 17);
            EXP2 = khongchekinhnghiem(EXP2);

            EXP2 = lamtron(EXP2 * 1.15);
            EXP2 = khongchekinhnghiem(EXP2);
        };
        EXP1 -= E1;
        EXP1 = khongchekinhnghiem(EXP1);
    }
    else { return -99; };
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0 )|| (E2>99)) { return -99; };
    EXP1 = khongchekinhnghiem(EXP1);
    M1 = khongchetien(M1);
    HP1 = khongchemau(HP1);
    int s1 = sochinhphuong(EXP1);
    float p1;
    if (EXP1 >= s1) {
        p1 = 1;
    }
    else p1 = (EXP1 / static_cast<float>(s1) + 80) / 123;//con duong 1
    if (E2 % 2 == 1) {
        int q = M1;
        while (M1 > (q * 0.5)) {
            if (HP1 < 200) {
                HP1 = lamtron(HP1 * 1.3);
                M1 -= 150;
                HP1 = khongchemau(HP1);
                M1 = khongchetien(M1);
            }
            else {
                HP1 = lamtron(HP1 * 1.1);
                M1 -= 70;
                HP1 = khongchemau(HP1);
                M1 = khongchetien(M1);// Hanh dong 1
            }
            if (M1 < (q * 0.5)) { break; }
            if (EXP1 < 400) {
                M1 -= 200;
                M1 = khongchetien(M1);
            }
            else {
                M1 -= 120; M1 = khongchetien(M1);
                // Hanh dong 2
            }
            EXP1 = lamtron(EXP1 * 1.13);
            if (M1 < (q * 0.5)) { break; }
            if (EXP1 < 300) {
                M1 -= 100;
                M1 = khongchetien(M1);
                EXP1 = lamtron(EXP1 * 0.9);
            }
            else {
                M1 -= 120;
                M1 = khongchetien(M1);
                EXP1 = lamtron(EXP1 * 0.9);//Hanh dong 3
            }


        }

        HP1 = lamtron(HP1 * 0.83);
        EXP1 = lamtron(EXP1 * 1.17);
        HP1 = khongchemau(HP1);
        EXP1 = khongchekinhnghiem(EXP1);
    }//E1 la so le
    else {
        if (M1 != 0) {
            if (HP1 < 200) {
                HP1 = lamtron(HP1 * 1.3);
                M1 -= 150;
                HP1 = khongchemau(HP1);
                M1 = khongchetien(M1);
            }
            else {
                HP1 = lamtron(HP1 * 1.1);
                M1 -= 70;
                HP1 = khongchemau(HP1);
                M1 = khongchetien(M1);//hanh dong 1
            }
        }
        if (M1 != 0) {
            if (EXP1 < 400) {
                M1 -= 200;
                M1 = khongchetien(M1);
            }
            else {
                M1 -= 120; M1 = khongchetien(M1);
            }

            EXP1=lamtron(EXP1 * 1.13);//hanh dong 2
        }
        if (M1 != 0) {
            if (EXP1 < 300) {
                M1 -= 100;
                M1 = khongchetien(M1);
                EXP1 = lamtron(EXP1 * 0.9);
            }
            else {
                M1 -= 120;
                M1 = khongchetien(M1);
                EXP1 = lamtron(EXP1 * 0.9);// hanh dong 3
            }

            
        }
        HP1 = lamtron(HP1 * 0.83);
        EXP1 = lamtron(EXP1 * 1.17);
        HP1 = khongchemau(HP1);
        EXP1 = khongchekinhnghiem(EXP1);
    }// E1 la so chan

    int s2;
    s2= sochinhphuong(EXP1);
    float p2;
    if (EXP1 >= s2) {
        p2 = 1;
    }
    else p2 = (EXP1 / static_cast<float>(s2) + 80) / 123;
    //con duong 2
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int p3;
    if (E2 >= 0 && E2 <= 9) {
        p3 = P[E2];
    }
    else {
        int id = E2 / 10;
        int is = E2 - (E2 / 10 * 10);
        int i = is + id;
        if (i == 10) {
            p3 = P[0];

        }
        else if (i >10) {
            i = i - (i / 10 * 10);
            p3 = P[i];
        }
        else p3 = P[i];
    }// con duong 3
    if (p1 == 1 && p2 == 1 && p3 == 100) {
        EXP1 = lamtron(EXP1 *0.75);
      return HP1 + EXP1 + M1;
    }
    else {
        float p;
        p = (p1 * 100 + p2 * 100 + p3) / 3;
        p = lamtron(p);
        if (p < 50) {

            HP1 = lamtron(HP1 * 0.85);
            HP1 = khongchemau(HP1);
            EXP1 = lamtron(EXP1 * 1.15);
            EXP1 = khongchekinhnghiem(EXP1);
        }
        else {

            HP1 = lamtron(HP1 * 0.9);
            HP1 = khongchemau(HP1);
            EXP1 = lamtron(EXP1 * 1.2);
            EXP1 = khongchekinhnghiem(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) {
        return -99;
    }
    int diemi = 0;//diem gap nhau
    int diemj = 0;//diem gap nhau
    int taxi[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }//mang cua taxi
    int sherlock[10][10];
    for (int p = 0; p < 10; p++) {
        for (int l = 0; l < 10; l++) {
            sherlock[l][p] = solonmatran(taxi, l, p);
        }
    } // mang cua sherlock
    for (int s = 0; s < 10; s++) {
        for (int d = 0; d < 10; d++) {
            if (taxi[s][d] > (E3 * 2)) { diemi++; };
            if (taxi[s][d] < (-E3)) { diemj++; };
        }
    }
    diemi = dua2chusove1(diemi);
    diemj = dua2chusove1(diemj);
    if (abs(taxi[diemi][diemj]) > sherlock[diemi][diemj]) {
        EXP1 = lamtron(EXP1 * 0.88);
        HP1 = lamtron(HP1 * 0.9);
        EXP2 = lamtron(EXP2 * 0.88);
        HP2 = lamtron(HP2 * 0.9);
        HP2 = khongchemau(HP2);
        HP1 = khongchemau(HP1);
        EXP1 = khongchekinhnghiem(EXP1);
        EXP2 = khongchekinhnghiem(EXP2);
        return taxi[diemi][diemj];
    }
    else {
        EXP1 = lamtron(EXP1 * 1.12);
        HP1 = lamtron(HP1 * 1.1);
        EXP2 = lamtron(EXP2 * 1.12);
        HP2 = lamtron(HP2 * 1.1);
        HP2 = khongchemau(HP2);
        HP1 = khongchemau(HP1);
        EXP1 = khongchekinhnghiem(EXP1);
        EXP2 = khongchekinhnghiem(EXP2);
        return sherlock[diemi][diemj];
    };

    return -99;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    const char* diachi = strchr(email, '@');//tìm vị trí @
    if (diachi == nullptr) {
        return 0;
    }
    int seLength = diachi - email;
    char se[seLength + 1];
    strncpy(se, email, seLength);//sao chép kí tự từ chuỗi email vào se với độ dài selength
    se[seLength] = '\0';
    int length = strlen(s);
    char ss[length + 1];
    strncpy(ss, s, length);
    ss[length] = '\0';
    string str_ss(ss);
    string str_se(se);
    if (length < 8) {
        return -1;
    }
    else if (length > 20) {
        return -2;
    };
    bool inhoa = true, inthuong = true, so = true, kitudacbiet = false;
    for (char c : ss) {
        if (!isupper(c)) {
            inhoa = false;
        }
        else if (!islower(c)) {
            inthuong = false;
        }
        else if (!isdigit(c)) {
            so = false;
        }
    }
    for (char c : ss) {
        if ((c == '@') || (c == '#') || (c == '%') || (c == '$') || (c == '!')) {
            kitudacbiet = true;
            break; // Thêm lệnh break để dừng vòng lặp khi tìm thấy kí tự đặc biệt
        }
    }

    size_t sei = str_ss.find(se);
    if (sei != string::npos) {
        return -(300 + sei);
    }

    for (int i = 0; i < length; ++i) {
        char c = ss[i];
        if (i > 1 && c == ss[i - 1] && c == ss[i - 2]) {
            return -(400 + i - 2);
        }
    }

    if (kitudacbiet == false) {
        return -5;
    }
    for (int i = 0; i < length; ++i) {
        if (!isalnum(ss[i]) && ss[i] != '@' && ss[i] != '#' && ss[i] != '%' && ss[i] != '$' && ss[i] != '!')
        {
            return i;
        }
    }

    if ((inhoa == true) && (inthuong == true) && (so == true) && (kitudacbiet == true)) {
        return -10;
    }
    return -10;
}
int countOccurrences(const char* arr_pwds[], int num_pwds, const char* pwd) {
    int count = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], pwd) == 0) {
            count++;
        }
    }
    return count;
}
// đếm số lần xuất hiện trong mảng 
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    int result_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int count = countOccurrences(arr_pwds, num_pwds, pwd);
        int length = strlen(pwd);

        if (count > max_count || (count == max_count && length > max_length)) {
            max_count = count;
            max_length = length;
            result_index = i;
        }
    }

    return result_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////