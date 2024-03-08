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
int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (E1 < 0)return -99;
    if (E1 > 99)return -99;

    if ((E1 < 0) || (E1 > 99)) {
        cout << -99 << endl;
        return -99;
    }
    else {
        // truong hop 1
        if ((E1 >= 0) && (E1 <= 3)) {
            if (E1 == 0) EXP2 = EXP2 + 29;
            else if (E1 == 1) EXP2 = EXP2 + 45;
            else if (E1 == 2) EXP2 = EXP2 + 75;
            else if (E1 == 3) EXP2 = EXP2 + 29 + 45 + 75;

            int D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0) EXP1 = ceil(EXP1 + (float)D / 200);
            else EXP1 = ceil(EXP1 - (float)D / 100);
        }
        // truong hop 2
        if ((E1 >= 4) && (E1 <= 99)) {
            if ((E1 >= 4) && (E1 <= 19)) EXP2 = ceil(EXP2 + (float)E1 / 4.0 + 19);
            if ((E1 >= 20) && (E1 <= 49)) EXP2 = ceil(EXP2 + (float)E1 / 9.0 + 21);
            if ((E1 >= 50) && (E1 <= 65)) EXP2 = ceil(EXP2 + (float)E1 / 16.0 + 17);
            if ((E1 >= 66) && (E1 <= 79)) {
                EXP2 = ceil(EXP2 + (float)E1 / 4.0 + 19);
                if (EXP2 > 200) EXP2 = ceil(EXP2 + (float)E1 / 9.0 + 21);
            }
            if ((E1 >= 80) && (E1 <= 99)) {
                EXP2 = ceil(EXP2 + (float)E1 / 4.0 + 19);
                EXP2 = ceil(EXP2 + (float)E1 / 9.0 + 21);
                if (EXP2 > 400) {
                    EXP2 = ceil(EXP2 + (float)E1 / 16.0 + 17);
                    EXP2 = EXP2 + ceil(EXP2 * 0.15);
                }
            }EXP1 = EXP1 - E1;
        }
    }
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;

    return EXP1 + EXP2;

}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0)return -99;
    if (E2 > 99)return -99;
    check2(HP1, EXP1, M1, E2);
    // con duong 1
    int S1=0;
    int P1;
    float can1 = sqrt(EXP1);
    int can11 = round(can1);
    S1 = can11 * can11;
    if (EXP1 >= S1) P1 = 100;
    else  P1 = round((((EXP1 / (float)S1 + 80) / (float)123) * 100) + 0.5);
    //con duong2 
    
    if (E2 % 2 == 0) {
        while (M1 > 0) {
            // su kien 1
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 0.3);
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 = M1 - 70;
            }
            if (M1 <= 0)
                break;

            // su kien 2

            if (EXP1 < 400) {
                M1 = M1 - 200; //  taxi
                EXP1 = ceil(EXP1 + EXP1 * 0.13);
            }
            else {
                M1 = M1 - 120; // xe ngựa
                EXP1 = ceil(EXP1 + EXP1 * 0.13);
            }
            if (M1 <= 0)break;

            // su kien 3
            if (EXP1 < 300) {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 - EXP1 * 0.1);
            }
            else {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 - EXP1 * 0.1);
            }
            break;
        }
    }
    else {
        int M22 = 0.5 * M1;
        while (M1 > 0) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 + HP1 * 0.3);
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 = M1 - 70;
            }
            if (M1 <= 0 || M1 < M22) break;

            if (EXP1 < 400) {
                M1 = M1 - 200; //  taxi
                EXP1 = ceil(EXP1 + EXP1 * 0.13);
            }
            else {
                M1 = M1 - 120; // xe ngựa
                EXP1 = ceil(EXP1 + EXP1 * 0.13);
            }
            if (M1 <= 0 || M1 < M22) break;

            if (EXP1 < 300) {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 - EXP1 * 0.1);
            }
            else {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 - EXP1 * 0.1);
                if (M1 <= 0 || M1 < M22) break;
            }
        }

    }
    check2(HP1, EXP1, M1, E2);
    HP1 = ceil(HP1 * 0.83 );
    EXP1 = ceil(EXP1 * 1.17 );
    
    // Kiểm tra và cập nhật kết quả cuối cùng
    check2(HP1, EXP1, M1, E2);


        //xac suat tim duoc valy
    int S2;
    int P2;
    float can2 = sqrt(EXP1);
    int can22 = round(can2);
    S2 = can22 * can22;
    if (EXP1 >= S2) P2 = 100;
    else P2 = round(((EXP1 / (float)S2 + 80) / (float)123) * 100);
//con duong 3
    int i;
    int P31[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10)
        i = E2;
    else {
        int sum = (E2 / 10) + (E2 % 10); // Tính tổng các chữ số của E2
        i = sum % 10; // Lấy số hàng đơn vị của tổng làm giá trị cho i
    }
    int P3 = P31[i];
   
    ///kl
    if (P3 == 100 && P1 == 100 && P2 == 100) EXP1 = ceil(EXP1 - EXP1 * 0.25);
    else {
        int sum = (P1 + P2 + P3) / 3;
        if (sum < 50) {
            HP1 = ceil(HP1 - 0.15 * HP1);
            EXP1 = ceil(EXP1 + EXP1 * 0.15);
        }
        else {
            HP1 = ceil((HP1 * 0.9));
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    check2(HP1, EXP1, M1, E2);
    return HP1 + EXP1 + M1;
}

int event1(int& HP1, int& M1)
{
   

    if (HP1 < 200) {
        HP1 = round(HP1 + HP1 * 0.3);
        M1 = M1 - 150;
       
    }
    else {
        HP1 = round(HP1 + 0.1 * HP1);
        M1 = M1 - 70;
        

    }return 0;
}

int event2(int& HP1, int& EXP1, int& M1)
{
   


    if (EXP1 < 400) {
        M1 = M1 - 200; //  taxi
        EXP1 = round(EXP1 + EXP1 * 0.13);

    }
    else {
        M1 = M1 - 120; // xe ngựa
        EXP1 = round(EXP1 + EXP1 * 0.13); // 
        // 
    }return 0;
   
}

int event3(int& HP1, int& EXP1, int& M1)
{
   

    if (EXP1 < 300) {
        M1 = M1 - 100;
        EXP1 = round(EXP1 - EXP1 * 0.1);
       
    }
    else {
        M1 = M1 - 120;
        EXP1 = round(EXP1 - EXP1 * 0.1);
       
    }return 0;
   
}

int  check2(int& HP1, int& EXP1, int& M1, int& E2)
{
    if (EXP1 < 0)EXP1 = 0;
    else if (EXP1 > 600)EXP1 = 600;
    if (HP1 < 0)HP1 = 0;
    else if (HP1 > 666)HP1 = 666;
    if (M1 < 0)M1 = 0;
    else if (M1 > 3000)M1 = 3000;
    if ((E2 < 0) || (E2 > 99))
    return -99;
    return 0;
}




// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    check3;
    int chase[10][10] = { 0 };
    int countI = 0, countJ = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            chase[i][j] = ((E3 * j) + (i * 2)) * (i - j); // điểm taxi
            if (chase[i][j] > E3 * 2) {
                countI++;
            }
            if (chase[i][j] < -E3) {
                countJ++;
            }
        }
    }
    while (countI >= 10) {
        countI = countI / 10 + countI % 10;
    }
    while (countJ >= 10) {
        countJ = countJ / 10 + countJ % 10;
    }

    int diemTaxi = chase[countI][countJ];
    int diemSherlock = chase[countI][countJ];

    // Tính điểm
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i + j == countI + countJ && chase[i][j] > diemSherlock) {
                diemSherlock = chase[i][j];
            }
            if (i - j == countI - countJ && chase[i][j] > diemSherlock) {
                diemSherlock = chase[i][j];
            }
        }
    }

    diemSherlock = abs(diemSherlock);

    // So sánh
    if (diemSherlock >= abs(diemTaxi)) {
        HP1 += HP1 * 10 / 100;
        EXP1 += EXP1 * 12 / 100;
        HP2 += HP2 * 10 / 100;
        EXP2 += EXP2 * 12 / 100;
        check3(HP1, EXP1, HP2, EXP2, E3);
        return diemSherlock;
    }
    else {
        HP1 -= HP1 * 10 / 100;
        EXP1 -= EXP1 * 12 / 100;
        HP2 -= HP2 * 10 / 100;
        EXP2 -= EXP2 * 12 / 100;
        check3(HP1, EXP1, HP2, EXP2, E3);
        return diemTaxi;
    }
}

int check3(int& HP1, int& EXP1, int& HP2, int& EXP2, int& E3)
{
    
  if (EXP1 < 0)EXP1 = 0;
  else if (EXP1 > 600)EXP1 = 600;
  if (HP1 < 0)HP1 = 0;
  else if (HP1 > 666)HP1 = 666;
  if (EXP2 < 0)EXP2 = 0;
  else if (EXP2 > 600)EXP2 = 600;
  if (HP2 < 0)HP2 = 0;
  else if (HP2 > 666)HP2 = 666;
  if ((E3 < 0) || (E3 > 99))return -99;
  return -99;
 
}


// Task 4
int checkPassword(const char* s, const char* email) {
    string se(email);
    se = se.substr(0, se.find("@"));
    string str(s);

    if (str.length() < 8) {
        return -1;
    }

    if (str.length() > 20) {
        return -2;
    }

    size_t pos = str.find(se);
    if (pos != string::npos) {
        return -1*(300 + pos);
    }

    for (size_t i = 0; i < str.length() - 2; ++i) {
        if (str[i] == str[i + 1] && str[i + 1] == str[i + 2]) {
            return -1*(400 + i);
        }
    }

    if (str.find('!') == string::npos) {
        return -5;
    }

    for (size_t i = 0; i < str.length(); ++i) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9') || str[i] == '!' || str[i] == '@' ||
            str[i] == '#' || str[i] == '$' || str[i] == '%')) {
            return -1*(600 + i);
        }
    }

    return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int soLanXuatHienMax = 0;
    int viTriMax = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int soLanXuatHien = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                soLanXuatHien++;
            }
        }
        if (soLanXuatHien > soLanXuatHienMax) {
            soLanXuatHienMax = soLanXuatHien;
            viTriMax = i;
        }
        else if (soLanXuatHien == soLanXuatHienMax) {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[viTriMax])) {
                soLanXuatHienMax = soLanXuatHien;
                viTriMax = i;
            }
        }
    }

    return viTriMax;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////