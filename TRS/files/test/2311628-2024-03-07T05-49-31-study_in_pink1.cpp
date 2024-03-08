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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    //truong hop 1
    if (e1 >= 0 && e1 <= 3) {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += 29 + 45 + 75;
            break;
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) exp1 = ceil(exp1 + d / 200.0);
        else exp1 = ceil(exp1 - d / 100.0);
    }
    
    //truong hop 2
    if(e1>=4 && e1<=99){
        if (e1 >= 4 && e1 <= 19) exp2 += ceil(e1 / 4.0 + 19.0);
        if (e1 >= 20 && e1 <= 49) exp2 += ceil(e1 / 9.0 + 21.0);
        if (e1 >= 50 && e1 <= 65) exp2 += ceil(e1 / 16.0 + 17.0);
        if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(e1 / 4.0 + 19.0);
            if (exp2 > 200) exp2 += ceil(e1 / 9.0 + 21.0);
        }
        if (e1 >= 80 && e1 <= 99) {
            //exp2 += ceil(e1 / 4.0 + 19.0 + e1 / 9.0 + 21.0);
            exp2 += ceil(e1 / 4.0 + 19.0) + ceil(e1 / 9.0 + 21.0);
            if (exp2 > 400) {
                exp2 += ceil(e1 / 16.0 + 17.0);
                exp2 = ceil(exp2 * 115.0/100);
            }
        }
        exp1 -= e1;
    }
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;
    return exp1 + exp2;
}

int soChinhPhuongGanNhat(int n) {
    int low, up;
    double sqrtN = sqrt(n);
    low = floor(sqrtN);
    up = ceil(sqrtN);
    if ((n - low * low) <= (up * up - n)) return low * low;
    else return up * up;
}

double xacSuat(int exp, int s){
    if (exp >= s) return  1.0;
    else return (1.0 * exp / s + 80.0) / 123.0;
}

void event1(int& HP1, int& M1,int& soTienDaChi){
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 13.0 / 10);
        M1 -= 150;
        soTienDaChi+=150;
    }
    else{
        HP1 = ceil(HP1 * 11.0 / 10);
        M1 -= 70;
        soTienDaChi+=70;
    }
}

void event2(int& EXP1, int& M1,int& soTienDaChi){
    if (EXP1 < 400) {
        M1 -= 200;
        EXP1 = ceil(EXP1 * 113.0 / 100);
        soTienDaChi+=200;
    }
    else{
        M1 -= 120;
        EXP1 = ceil(EXP1 * 113.0 / 100);
        soTienDaChi+=120;
    }
}
void event3(int& EXP1, int& M1,int& soTienDaChi){
    if (EXP1 < 300) {
        M1 -= 100;
        EXP1 = ceil(EXP1 * 9.0 / 10);
        soTienDaChi+=100;
    }
    else {
        M1 -= 120;
        EXP1 = ceil(EXP1 * 9.0 / 10);
        soTienDaChi+=120;
    }
}
void hoanThanh(int& HP1, int& EXP1){
        HP1 = ceil(HP1 * 83.0 / 100);
        EXP1 = ceil(EXP1 * 117.0/100);
}
void kiemTraTask2(int& HP1, int& EXP1, int& M1){
    if (EXP1 < 0) EXP1 = 0;
    if (M1 < 0) M1 = 0;
    if (HP1 < 0) HP1 = 0;
    if (EXP1>600) EXP1 = 600;
    if (M1 > 3000) M1 = 3000;
    if (HP1 >666) HP1 = 666;
}

// Task 2

int traceLuggage(int& HP1, int& EXP1, int& M1, int E3) {
    if (E3 > 99 || E3 < 0) return -99;

    //con duong 1
    int S = soChinhPhuongGanNhat(EXP1);
    double P1 =xacSuat(EXP1, S);
    //con duong 2
    //int soTienBanDau = M1;
    int nuaTienBatDau = ceil(M1/2.0);
    int soTienDaChi = 0;
    //check so chan
    if (E3 % 2 == 0)
    {
        //sk1
        event1(HP1,M1,soTienDaChi);
        if(M1>0) event2(EXP1,M1,soTienDaChi);
        if(M1>0) event3(EXP1,M1,soTienDaChi);
        kiemTraTask2(HP1, EXP1, M1);
    }
    else{//check so le
        while (true) {
            //sk1
            event1(HP1,M1,soTienDaChi);
            kiemTraTask2(HP1, EXP1, M1);
            if (soTienDaChi > nuaTienBatDau) break;
            //sk2
            event2(EXP1, M1, soTienDaChi);
            kiemTraTask2(HP1, EXP1, M1);
            if (soTienDaChi > nuaTienBatDau) break;
            //sk3
            event3(EXP1, M1, soTienDaChi);
            kiemTraTask2(HP1, EXP1, M1);
            if (soTienDaChi > nuaTienBatDau) break;
        } 
    }
    hoanThanh(HP1,EXP1);
    kiemTraTask2(HP1, EXP1, M1);
    //tinh p2
    int S2 = soChinhPhuongGanNhat(EXP1);
    double P2=xacSuat(EXP1, S2);

    //con duong 3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int indexOfP=0;

    if (E3 < 10) indexOfP = E3;
    else indexOfP = (E3 / 10 + E3 % 10) % 10;

    double P3 = P[indexOfP]/100.0;

    if (P1==1.0 &&P2==1.0 &&P3==1.0) {
        EXP1 = ceil(EXP1 * 75.0 / 100.0);
    }
    else {
        double PtrungBinh = (P1 + P2 + P3) / 3.0;
        if (PtrungBinh < 0.5) {
            HP1 = ceil(HP1 * 85.0 / 100.0);
            EXP1 = ceil(EXP1 * 115.0 / 100.0);
        }
        else {
            HP1 = ceil(HP1 * 90.0 / 100.0);
            EXP1 = ceil(EXP1 * 120.0 / 100.0);
        }
    }
    kiemTraTask2(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

void kiemTraLai(int& HP1, int& EXP1, int& HP2, int& EXP2){
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;

    int maTran[10][10] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maTran[i][j] = ((E3 * j) + (i * 2)) *(i - j);
        }
    }
    int giaTriDuong = 0, giaTriAm = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            if (maTran[i][j] > E3 * 2) giaTriDuong++;
            if (maTran[i][j] < -E3) giaTriAm++;
        }
    }
    //kiem tra vuot qua 10
    while (giaTriDuong > 9) {
        giaTriDuong = giaTriDuong / 10 + giaTriDuong % 10;
    }
    while (giaTriAm > 9) {
        giaTriAm = giaTriAm / 10 + giaTriAm % 10;
    }
    int viTriGapNhau = maTran[giaTriDuong][giaTriAm];

    //tim gia tri max
    int maxVal = maTran[giaTriDuong][giaTriAm];
    for (int i = giaTriDuong,j=giaTriAm; i >= 0 && i <= 9 &&j>=0 &&j<=9; i++,j++) {
            if (maTran[i][j]>maxVal) maxVal = maTran[i][j];
    }
    for (int i = giaTriDuong, j = giaTriAm; i >= 0 && i <= 9 && j >= 0 && j <= 9; i--, j++) {
        if (maTran[i][j] > maxVal) maxVal = maTran[i][j];
    }
    for (int i = giaTriDuong, j = giaTriAm; i >= 0 && i <= 9 && j >= 0 && j <= 9; i++, j--) {
        if (maTran[i][j] > maxVal) maxVal = maTran[i][j];
    }
    for (int i = giaTriDuong, j = giaTriAm; i >= 0 && i <= 9 && j >= 0 && j <= 9; i--, j--) {
        if (maTran[i][j] > maxVal) maxVal = maTran[i][j];
    }
    
    if (abs(viTriGapNhau) > maxVal) {
        //khong duoi kip
        EXP1 = ceil(EXP1 * 88.0 / 100);
        EXP2 = ceil(EXP2 * 88.0 / 100);
        HP1 = ceil(HP1 * 9.0 / 10);
        HP2 = ceil(HP2 * 9.0 / 10);
        kiemTraLai(HP1,EXP1,HP2,EXP2);
        return viTriGapNhau;
        
    }
    else {
        EXP1 = ceil(EXP1 * 112.0/100.0);
        EXP2 = ceil(EXP2 * 112.0/100.0);
        HP1 = ceil(HP1 * 11.0 / 10);
        HP2 = ceil(HP2 * 11.0 / 10);
        kiemTraLai(HP1,EXP1,HP2,EXP2);
        return maxVal;
    }
    kiemTraLai(HP1,EXP1,HP2,EXP2);
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    //chuyen doi dau vao sang string
    string password(s);
    string strEmail(email);
    //tach se
    string se = strEmail.substr(0, strEmail.find('@'));
    //do dai
    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;
    //check password chua se
    size_t checkSe = password.find(se);
    if (checkSe != string::npos) return -(300+checkSe);
    //kiem tra co nhieu hon 2 ky tu lien tiep
    for (int i = 0; i < password.length()-2; i++)
    {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
            return -(400 + i);
        }
    }
    //kiem tra ky tu dac biet
    string kyTuDacBiet = "@#%$!";
    bool checkKyTuDacBiet = 0;
    for (char ch : password) {
        if(kyTuDacBiet.find(ch)!=string::npos){
            checkKyTuDacBiet=1;
            break;
        }
    }
    if (!checkKyTuDacBiet) return -5;
    
    //kiem tra cac yeu to khac: chu, so, ky tu dac biet
    for (int i = 0; i < password.length();i++) {
        if (!isalnum(password[i]) && kyTuDacBiet.find(password[i]) == string::npos) {
            return i;
        }
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string* str_arr_pwds = new string[num_pwds];
    int* viTri = new int[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        str_arr_pwds[i] = arr_pwds[i];
        viTri[i] = 1;
    }
    //dem tan suat
    for (int i = 0; i < num_pwds; i++) {
        if (viTri[i] == -1) continue;
        for (int j = i + 1; j < num_pwds; j++) { 
            if (str_arr_pwds[i] == str_arr_pwds[j]) {
                viTri[i]++;
                viTri[j] = -1;// =-1 la da dem, k can dem lai
            }
        }
    }
    //vi tri mat khau nhieu nhat
    int maxViTri = viTri[0];
    int maxIndex = 0;
    int maxLength = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (viTri[i] > maxViTri || (viTri[i] == maxViTri && str_arr_pwds[i].length() >maxLength )) {
            maxViTri = viTri[i];
            maxIndex = i;
            maxLength = str_arr_pwds[i].length();
        }
    }
    
    delete[] viTri;
    delete[] str_arr_pwds;
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////