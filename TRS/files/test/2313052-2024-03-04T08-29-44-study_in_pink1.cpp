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
void checkexp(int& exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
}
void checkhp(int& hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
}
void checkm(int& money) {
    if (money > 3000) money = 3000;
    if (money < 0) money = 0;
}

int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    checkexp(exp1);
    checkexp(exp2);

    if (e1 <= 3) {      //Truong hop 1
        switch (e1) {
        case 0:
            exp2 += 29;
            checkexp(exp2);
            break;
        case 1:
            exp2 += 45;
            checkexp(exp2);
            break;
        case 2:
            exp2 += 75;
            checkexp(exp2);
            break;
        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            checkexp(exp2);
            break;
        default:
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            float exp1_temp = exp1 + D / 200.0;
            exp1 = ceil(exp1_temp);
            checkexp(exp1);
        }
        else {
            float exp1_temp = exp1 - D / 100.0;
            exp1 = ceil(exp1_temp);
            checkexp(exp1);
        }
    }
    else {      //Truong hop 2
        if (e1 <= 19) {          //thong tin 1
            float exp2_temp = exp2 + e1 / 4.0 + 19;
            exp2 = ceil(exp2_temp);
            checkexp(exp2);
        }
        else if (e1 <= 49) {    //thong tin 2
            float exp2_temp = exp2 + e1 / 9.0 + 21;
            exp2 = ceil(exp2_temp);
            checkexp(exp2);
        }
        else if (e1 <= 65) {    //thong tin 3
            float exp2_temp = exp2 + e1 / 16.0 + 17;
            exp2 = ceil(exp2_temp);
            checkexp(exp2);
        }
        else if (e1 <= 79) {
            float exp2_temp = exp2 + e1 / 4.0 + 19;     //cap nhat thong tin 1
            exp2 = ceil(exp2_temp);
            checkexp(exp2);
            if (exp2 > 200) {       //exp2 > 200 thi cap nhap thong tin 2
                float exp2_temp = exp2 + e1 / 9.0 + 21;
                exp2 = ceil(exp2_temp);
                checkexp(exp2);
            }
        }
        else {
            if (true) {
                float exp2_temp = exp2 + e1 / 4.0 + 19; //cap nhat thong tin 1
                exp2 = ceil(exp2_temp);
                checkexp(exp2);
            }
            if (true) {
                float exp2_temp = exp2 + e1 / 9.0 + 21; //cap nhat thong tin 2
                exp2 = ceil(exp2_temp);
                checkexp(exp2);
            }
            if (exp2 > 400) {   //neu exp2 > 400 thi cap nhat thong tin 3
                float exp2_temp = exp2 + e1 / 16.0 + 17;
                exp2 = ceil(exp2_temp);
                checkexp(exp2);
                if (true) {     //neu duoc cap nhat ca 3 thong tin thi exp tang 15%
                    float exp2_temp = exp2 + exp2 * 15 / 100.0;
                    exp2 = ceil(exp2_temp);
                    checkexp(exp2);
                }
            }
        }
        exp1 -= e1;
        checkexp(exp1);
    }

    return exp1 + exp2;
}

// Task 2
bool isSquared(int n) {
    int sqr = sqrt(n);
    if (sqr * sqr == n)
        return true;
    return false;
}

int nearestSquare(int P) {
    int i = 0;
    while (!isSquared(P + i))
        i++;
    int greaterSquare = P + i;
    i = 0;
    while (!isSquared(P - i))
        i++;
    int lessSquare = P - i;
    if (greaterSquare - P > P - lessSquare)
        return lessSquare;
    return greaterSquare;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    checkhp(HP1);
    checkexp(EXP1);
    checkm(M1);

    if (E2 < 0 || E2 > 99)
        return -99;

    //traceLuggage01
    int S1 = nearestSquare(EXP1);
    float P1;
    if (EXP1 >= S1)
        P1 = 1;
    else P1 = ((float)EXP1 / S1 + 80) / 123;    //Tinh P1 dua tren S1

    //traceLuggage02
    if (E2 % 2 == 0) {
        while (true) {
            //event1
            if (HP1 < 200) {            //Neu HP < 200
                HP1 = ceil(HP1 + HP1 * 30 / 100.0);
                checkhp(HP1);
                M1 -= 150;
                checkm(M1);
            }
            else {                      //Neu HP >= 200
                HP1 = ceil(HP1 + HP1 * 10 / 100.0);
                checkhp(HP1);
                M1 -= 70;
                checkm(M1);
            }
            if (M1 == 0)
                break;      //Ket thuc vong lap neu M = 0

            //event2
            if (EXP1 < 400) {       //Neu EXP < 400
                M1 -= 200;
                checkm(M1);
            }
            else {              //Neu EXP >= 400
                M1 -= 120;
                checkm(M1);
            }
            EXP1 = ceil(EXP1 + EXP1 * 13 / 100.0);  //EXP tang 13%
            checkexp(EXP1);
            if (M1 == 0)
                break;      //Ket thuc vong lap neu M = 0

            //event3
            if (EXP1 < 300) {
                M1 -= 100;
                checkm(M1);
            }
            else {
                M1 -= 120;
                checkm(M1);
            }
            EXP1 = ceil(EXP1 - EXP1 * 10 / 100.0);      //EXP giam 10%
            checkexp(EXP1);
            break;      //Ket thuc 3 su kien
        }
    }

    else {
        int M1_initial = M1;
        while (M1 >= M1_initial * 0.5) {    //Lap den khi M1 < M1_initial: so tien phai tra > 50% so tien ban dau
            //event1
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 30 / 100.0);
                checkhp(HP1);
                M1 -= 150;
                checkm(M1);
            }
            else {
                HP1 = ceil(HP1 + HP1 * 10 / 100.0);
                checkhp(HP1);
                M1 -= 70;
                checkm(M1);
            }
            if (M1 < M1_initial * 0.5)  //So tien phai tra > 50% so tien ban dau thi khong thuc hien cac su kien tiep theo nua
                break;

            //event2
            if (EXP1 < 400) {
                M1 -= 200;
                checkm(M1);
            }
            else {
                M1 -= 120;
                checkm(M1);
            }
            EXP1 = ceil(EXP1 + EXP1 * 13 / 100.0);
            checkexp(EXP1);
            if (M1 < M1_initial * 0.5)
                break;

            //event3
            if (EXP1 < 300) {
                M1 -= 100;
                checkm(M1);
            }
            else {
                M1 -= 120;
                checkm(M1);
            }
            EXP1 = ceil(EXP1 - EXP1 * 10 / 100.0);
            checkexp(EXP1);
        }
    }
    HP1 = ceil(HP1 - HP1 * 17 / 100.0);         //Thay doi HP1 va EXP1 trong ca 2 truong hop
    checkhp(HP1);
    EXP1 = ceil(EXP1 + EXP1 * 17 / 100.0);
    checkexp(EXP1);

    float P2;
    int S2 = nearestSquare(EXP1);
    if (EXP1 >= S2)
        P2 = 1;
    else P2 = ((float)EXP1 / S2 + 80) / 123;    //Tinh P2

    //traceLuggage03
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) i = E2;
    else i = (E2 / 10 + E2 % 10) % 10;
    float P3 = P[i] / 100.0;

    //final
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 - EXP1 * 25 / 100.0);      //ca 3 truong hop P deu bang 100 (sai sot)
        checkexp(EXP1);
    }
    else {
        float Pavg = (P1 + P2 + P3) / 3;    //Tinh P trung binh
        if (Pavg < 0.5) {
            HP1 = ceil(HP1 - HP1 * 15 / 100.0);
            checkhp(HP1);
            EXP1 = ceil(EXP1 + EXP1 * 15 / 100.0);
            checkexp(EXP1);
        }
        else {
            HP1 = ceil(HP1 - HP1 * 10 / 100.0);
            checkhp(HP1);
            EXP1 = ceil(EXP1 + EXP1 * 20 / 100.0);
            checkexp(EXP1);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    checkhp(HP1);
    checkhp(HP2);
    checkexp(EXP1);
    checkexp(EXP2);

    if (E3 < 0 || E3 > 99)
        return -99;

    int taxiMatrix[10][10];
    int holmesMatrix[10][10];
    int i = 0, j = 0;
    for (int m = 0; m < 10; m++)
        for (int n = 0; n < 10; n++)
            taxiMatrix[m][n] = ((E3 * n) + (m * 2)) * (m - n);  //Gan gia tri cho ma tran taxi
    for (int m = 0; m < 10; m++)
        for (int n = 0; n < 10; n++) {            //Gan gia tri cho ma tran Sherlock Holmes
            int max = taxiMatrix[m][n];
            int k = 0;                                  //Cac duong cheo:
            while ((m + k != 9) && (n + k != 9)) {      //Di ve huong tang m, n
                k++;
                if (taxiMatrix[m + k][n + k] > max)
                    max = taxiMatrix[m + k][n + k];
            }
            k = 0;
            while ((m + k != 9) && (n - k != 0)) {      //Di ve huong tang m, giam n
                k++;
                if (taxiMatrix[m + k][n - k] > max)
                    max = taxiMatrix[m + k][n - k];
            }
            k = 0;
            while ((m - k != 0) && (n + k != 9)) {      //Di ve huong giam m, tang n
                k++;
                if (taxiMatrix[m - k][n + k] > max)
                    max = taxiMatrix[m - k][n + k];
            }
            k = 0;
            while ((m - k != 0) && (n - k != 0)) {      //Di ve huong giam m, n
                k++;
                if (taxiMatrix[m - k][n - k] > max)
                    max = taxiMatrix[m - k][n - k];
            }
            holmesMatrix[m][n] = abs(max);      //Gia tri lon nhat tren 2 duong cheo

            if (taxiMatrix[m][n] > E3 * 2)      //Tim i, j
                i++;
            if (taxiMatrix[m][n] < -1 * E3)
                j++;
        }

    while (i >= 10)
        i = i / 10 + i % 10;
    while (j >= 10)
        j = j / 10 + j % 10;

    if (abs(taxiMatrix[i][j]) > holmesMatrix[i][j]) {   //khong bat duoc
        EXP1 = ceil(EXP1 - EXP1 * 12 / 100.0);
        checkexp(EXP1);
        EXP2 = ceil(EXP2 - EXP2 * 12 / 100.0);
        checkexp(EXP2);
        HP1 = ceil(HP1 - HP1 * 10 / 100.0);
        checkhp(HP1);
        HP2 = ceil(HP2 - HP2 * 10 / 100.0);
        checkhp(HP2);
        return taxiMatrix[i][j];
    }
    else {
        EXP1 = ceil(EXP1 + EXP1 * 12 / 100.0);      //bat duoc
        checkexp(EXP1);
        EXP2 = ceil(EXP2 + EXP2 * 12 / 100.0);
        checkexp(EXP2);
        HP1 = ceil(HP1 + HP1 * 10 / 100.0);
        checkhp(HP1);
        HP2 = ceil(HP2 + HP2 * 10 / 100.0);
        checkhp(HP2);
        return holmesMatrix[i][j];
    }

}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string s_str = string(s);
    string email_str = string(email);
    string se = "";
    int i = 0;

    while (email_str[i] != '@') {   //Khoi tao se
        se = se + email_str[i];
        i++;
    }

    bool pwdsShort = false, pwdsLong = false, seContains = false, scContains = false, spcChar = false, unvalidChar = false;
    int sei = -1, sci = -1, unvi = -1;

    if (s_str.length() < 8)
        pwdsShort = true;
    if (s_str.length() > 20)
        pwdsLong = true;

    if (se.length() == 0) {
        seContains = true;
        sei = 0;
    }
    else if (s_str.length() >= se.length())
        for (int j = 0; j < s_str.length() - se.length() + 1; j++) {   //check if s contains se
            if (s_str[j] == se[0]) {    //Ki tu dau tien
                seContains = true;
                for (int k = 1; k < se.length(); k++) {     //Kiem tra cac ki tu tiep theo
                    if (s_str[j + k] != se[k]) {
                        seContains = false;
                        break;
                    }
                }
                if (seContains) {
                    sei = j;    //Gan seindex
                    break;
                }
            }
        }
    if (s_str.length() > 2)
        for (int i = 0; i < s_str.length() - 2; i++) {      //check if s contains >2 consecutive same char
            if (s_str[i] == s_str[i + 1] && s_str[i] == s_str[i + 2]) {
                scContains = true;
                sci = i;
                break;
            }
        }

    for (int i = 0; i < s_str.length(); i++) {
        if (s_str[i] == '!' || s_str[i] == '@' || (s_str[i] >= 35 && s_str[i] <= 37))   //Ki tu dac biet
            spcChar = true;
    }

    for (int i = 0; i < s_str.length(); i++) {
        if (!(s_str[i] >= 64 && s_str[i] <= 90) && !(s_str[i] >= 97 && s_str[i] <= 122) && (s_str[i] != '!') && !(s_str[i] >= 35 && s_str[i] <= 37) && !(s_str[i] >= 48 && s_str[i] <= 57)) {
            unvalidChar = true;     //Ki tu khong hop le
            unvi = i;
            break;
        }
    }

    ///////////
    if (pwdsShort) return -1;
    if (pwdsLong) return -2;
    if (seContains) return -(300 + sei);
    if (scContains) return -(400 + sci);
    if (!spcChar) return -5;
    if (unvalidChar) return unvi;
    return -10;

}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    bool mark[500];         //Bien danh dau
    int arrAmount[500];     //arrAmount[i]: So chuoi giong voi arr_pwds[i]
    int maxAmount, maxLength, maxIndex;
    for (int i = 0; i < num_pwds; i++) {    //Khoi tao gia tri cho mark[] va arrAmount[]
        mark[i] = false;
        arrAmount[i] = 1;
    }

    for (int i = 0; i < num_pwds - 1; i++) {    //Xet tung phan tu trong arr_pwds[]
        if (!mark[i]) {     //Neu arr_pwds[i] chua duoc danh dau
            for (int j = i + 1; j < num_pwds; j++) {    //So sanh voi cac phan tu phia sau
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    arrAmount[i]++;
                    mark[j] = true;     //Danh dau arr_pwds[j]
                }
            }
        }
    }

    maxAmount = arrAmount[0];       //Khoi tao maxAmount

    for (int i = 1; i < num_pwds; i++)  //Tim chuoi co so luong phan tu lon nhat
        if (!mark[i])
            if (arrAmount[i] > maxAmount)
                maxAmount = arrAmount[i];


    for (int i = 0; i < num_pwds; i++)  //Khoi tao gia tri maxLength, maxIndex
        if (!mark[i])
            if (arrAmount[i] == maxAmount) {
                maxLength = strlen(arr_pwds[i]);
                maxIndex = i;
                break;
            }

    for (int i = 0; i < num_pwds; i++)  //Neu co phan tu dai hon thi gan lai gia tri maxLength va maxIndex
        if (!mark[i])
            if (arrAmount[i] == maxAmount)
                if (strlen(arr_pwds[i]) > maxLength) {
                    maxLength = strlen(arr_pwds[i]);
                    maxIndex = i;
                }

    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////