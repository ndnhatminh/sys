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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    
    //Truong hop 4.1.1
    if (e1 <= 3) {
        switch (e1) {
        case 0:
            exp2 = exp2 + 29; break;
        case 1:
            exp2 = exp2 + 45; break;
        case 2:
            exp2 = exp2 + 75; break;
        case 3:
            exp2 = exp2 + 149; break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 1) exp1 = ceil(exp1 - (D / 100.0));
        else exp1 = ceil(exp1 + (D / 200.0));
    }

    //Truong hop 4.1.2
    else {                                                  
        if (e1 <= 19) exp2 = ceil(exp2 + (e1 / 4.0 + 19));
        else if (e1 <= 49) exp2 = ceil(exp2 + (e1 / 9.0 + 21));
        else if (e1 <= 65) exp2 = ceil(exp2 + (e1 / 16.0 + 17));
        else if (e1 <= 79) {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            if (exp2 > 200) exp2 = ceil(exp2 + (e1 / 9.0 + 21));
        }
        else if (e1 <= 99) {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 / 16.0 + 17));
                exp2 = exp2 * 1.15;
            }
        }
        exp1 = exp1 - e1;
    }

    //Set lai cac gia tri ve gioi han
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int& E2) {
    // TODO: Complete this function
    float P1=0.0, P2=0.0, P3=0.0;

    //4.2.1
    int S_ceil, S_floor;
    S_ceil = ceil(sqrt(EXP1)) * ceil(sqrt(EXP1));
    S_floor = floor(sqrt(EXP1)) * floor(sqrt(EXP1));
    if ((S_ceil - EXP1) > (EXP1 - S_floor)) P1 = 1.0;
    else P1 = ((EXP1 / S_ceil) + 80) / 123.0;

    //4.2.2
    int M_spent = 0;
    int even = 1;

    if (E2 % 2 == 1) do {
        switch (even) {
        case 1:
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M_spent = M_spent + 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                M_spent = M_spent + 70;
            }
            if (M_spent < M1/2) even++; else break;

        case 2:
            if (EXP1 < 400) {
                M_spent = M_spent + 200;
            }
            else {
                M_spent = M_spent + 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (M_spent < M1/2) even++; else break;

        case 3:
            if (EXP1 < 300) {
                M_spent = M_spent + 100;
            }
            else {
                M_spent = M_spent + 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            if (M_spent < M1 / 2) even=1; else break;
        }
    } while (M_spent < (M1 / 2));
    else switch (even) {
    case 1:
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M_spent = M_spent + 150;
        }
        else {
            HP1 = ceil(HP1 * 1.1);
            M_spent = M_spent + 70;
        }
        if (M_spent < M1 / 2) even++; else break;

    case 2:
        if (EXP1 < 400) {
            M_spent = M_spent + 200;
        }
        else {
            M_spent = M_spent + 120;
        }
        EXP1 = ceil(EXP1 * 1.13);
        if (M_spent < M1 / 2) even++; else break;

    case 3:
        if (EXP1 < 300) {
            M_spent = M_spent + 100;
        }
        else {
            M_spent = M_spent + 120;
        }
        EXP1 = ceil(EXP1 * 0.9);
        if (M_spent < M1 / 2) even = 1; else break;
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    M1 = M1 - M_spent;

    S_ceil = ceil(sqrt(EXP1)) * ceil(sqrt(EXP1));
    S_floor = floor(sqrt(EXP1)) * floor(sqrt(EXP1));
    if ((S_ceil - EXP1) > (EXP1 - S_floor)) P2 = 1.0;
    else P2 = ((EXP1 / S_ceil) + 80) / 123.0;

    //4.2.3
    float P[10] = { 0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11 };
    if (E2 / 10 == 0) P3 = P[E2];
    else {
        int i = ((E2 / 10) + (E2 % 10))%10;
        P3 = P[i];
    }

    //Tinh xac suat trung binh
    float avgP = (P1 + P2 + P3) / 3;
    if (avgP == 1) EXP1 = EXP1 * 0.75;
    else {
        if (avgP < 0.5) { HP1 = ceil(HP1 * 0.85); EXP1 = ceil(EXP1 * 1.15); }
        else { HP1 = ceil(HP1 * 0.9); EXP1 = ceil(EXP1 * 1.2); }
    }
    
    //Set lai cac gia tri ve gioi han
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function

    //Khoi tao ma tran 10x10

        //Ma tran tinh diem cua taxi
        int taxiScore[10][10];

        //Ma tran tinh diem cua Sherlock & Waston
        int sherlockScore[10][10];

    //Taxi bat dau di chuyen
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiScore[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //Sherlock va Watson di chuyen
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            int maxLeft = 0, maxRight = 0;

            //Duong cheo trai
            int xLeft, yLeft;
            if (i > j) {
                xLeft = 0; yLeft = i - j;
            }
            else {
                xLeft = j - i; yLeft = 0;
            }
            do {
                if (taxiScore[yLeft][xLeft] > maxLeft) maxLeft = taxiScore[yLeft][xLeft];
                yLeft++; xLeft++;
            } while (yLeft < 10 && xLeft < 10);

            //Duong cheo phai
            int xRight, yRight;
            if (i + j >= 9) {
                yRight = 9; xRight = j + i - 9;
            }
            else {
                yRight = i + j; xRight = 0;
            }
            do {
                if (taxiScore[yRight][xRight] > maxRight) maxRight = taxiScore[yRight][xRight];
                yRight--; xRight++;
            } while (yRight >= 0 && xRight < 10);

            //Tinh tong gia tri max cua 2 duong cheo cho ma tran cua Sherlock
            sherlockScore[i][j] = abs(maxLeft + maxRight);

        }
    }

    //Xac dinh vi tri gap nhau
    int meetX = 0, meetY = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (taxiScore[i][j] > (E3 * 2)) meetY++;
            if (taxiScore[i][j] < (E3 * -1)) meetX++;
        }
    }
    do meetY = (meetY / 10) + (meetY % 10);
    while (meetY / 10 > 0);
    do meetX = (meetX / 10) + (meetX % 10);
    while (meetX / 10 > 0);

    //Xet dieu kien tai vi tri gap nhau
    if (abs(taxiScore[meetY][meetX]) > sherlockScore[meetY][meetX]) {
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        EXP2 = ceil(EXP2 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        HP2 = ceil(HP2 * 1.1);
    }

    //Set lai cac gia tri ve gioi han
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP2 > 666) HP1 = 666;
    if (HP2 < 0) HP1 = 0;
    if (EXP2 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP1 = 0;

    ////Xuat ra ma tran cua taxi
    //for (int i = 0; i < 10; i++) {
    //    for (int j = 0; j < 10; j++) {
    //        cout << setw(5) << taxiScore[i][j] << " ";
    //    }
    //    cout << "\n";
    //}
    //cout << "\n";

    ////Xuat ra ma tran cua Sherlock va Watson
    //for (int i = 0; i < 10; i++) {
    //    for (int j = 0; j < 10; j++) {
    //        cout << setw(5) << sherlockScore[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    ////Xuat ra vi tri gap nhau
    //cout << "Vi tri gap nhau: " << "(" << meetY << ", " << meetX << ")" << "\n";

    //cout << "EXP1 = " << EXP1 << "\n";
    //cout << "HP1 = " << HP1 << "\n";
    //cout << "EXP2 = " << EXP2 << "\n";
    //cout << "HP2 = " << HP2 << "\n";

    if (abs(taxiScore[meetY][meetX]) > sherlockScore[meetY][meetX]) 
        return taxiScore[meetY][meetX];
        else return sherlockScore[meetY][meetX];
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string passWord = s;
    string eMail = email;
    string se;

    //Tim chuoi se trong email
    for (int i = 0; se[i] != '@'; i++) {
        se[i] = eMail[i];
    }

    // Kiem tra cac dieu kien cua email va mat khau

        //Dieu kien do dai cua mat khau
        if (passWord.length() < 8) return -1;
        if (passWord.length() > 20) return -2;

        //Kiem tra neu se xuat hien trong mat khau
        for (int i = 0; i < passWord.length(); i++) {
            if (passWord.substr(i, se.length()) == se) return -((300) + int(i));
        }

        //Kiem tra cac ky tu lien tiep trung nhau

        for (int i = 0; i < passWord.length(); i++) {
            int j = i;
            int checkRepeat = 0;
            while (passWord[i] == passWord[i + 1]) {
                j++;
                checkRepeat++;
                if (checkRepeat > 2) {
                    return -(400 + i);
                }
            }
        }

    //Kiem tra cac ky tu dac biet
    int valid = 0, not_valid = 0;
    for (int i = 0; i < passWord.length(); i++) {
        if ((passWord[i] >= 32 && passWord[i] <= 47) ||
            (passWord[i] >= 58 && passWord[i] <= 64) ||
            (passWord[i] >= 91 && passWord[i] <= 96) ||
            (passWord[i] >= 123 && passWord[i] <= 126)) {

            if (passWord[i] == 33 ||
                passWord[i] == 64 ||
                (passWord[i] >= 35 && passWord[i] <= 37)) valid++;
            else not_valid++;

        }
    }
    if (valid == 0) return -5;
    else if (not_valid > 0) return (passWord.length() - not_valid);
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int max = 0, max_i = 0;
    int b = 0;

    for (int i = 0; i < num_pwds; i++) {
        const char* pass = arr_pwds[i];
        int count = 0;
        int max_length = strlen(pass);

        for (int j = i + 1; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) count++;
        }
        if (max < count || (count == max && max_length > b)) {
            max_i = i;
            max = count;
            b = max_length;
        }
    }

    return max_i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////