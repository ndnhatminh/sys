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



#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void checkEXP(int& EXP) {
    if (EXP > 600) {
        EXP = 600;
    }
    else if (EXP < 0) {
        EXP = 0;
    }
}

void checkHP(int& HP) {
    if (HP > 666) {
        HP = 666;
    }
    else if (HP < 0) {
        HP = 0;
    }
}

void checkM(int& M) {
    if (M > 3000) {
        M = 3000;
    }
    else if (M < 0) {
        M = 0;
    }
}
void checkE(int& E) {  // Hàm này chỉ kiểm tra và không trả về giá trị
    if (E < 0 || E > 99) {
        E = -99;
    }
}

int roundUp(int num) {
    num += 1;
    return num;
}
int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (E1 < 0 || E1 > 99) {
        E1 = -99;
        return E1;
    };
    checkEXP(EXP1);
    checkEXP(EXP2);

    // Trường hợp e1 thuộc [0,3]
    if (E1 >= 0 && E1 <= 3) {
        switch (E1) {
        case 0:
            EXP2 += 29;
            checkEXP(EXP2);
            break;
        case 1:
            EXP2 += 45;
            checkEXP(EXP2);
            break;
        case 2:
            EXP2 += 75;
            checkEXP(EXP2);
            break;
        case 3:
            EXP2 += (29 + 45 + 75); // Tổng của 3 trường hợp trước đó 
            checkEXP(EXP2);
            break;
        }

        int D = E1 * 3.0 + EXP1 * 7.0;

        if (D % 2 == 0.0) {
            EXP1 = ceil(EXP1 + D / 200.0);
            checkEXP(EXP1);
        }
        else {
            EXP1 = ceil(EXP1 - D / 100.0);
            checkEXP(EXP1);
        }
    }
    // Trường hợp e1 thuộc [4,99]
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(E1 / 4.0 + 19);
            checkEXP(EXP2);
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil(E1 / 9.0 + 21);
            checkEXP(EXP2);
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(E1 / 16.0 + 17);
            checkEXP(EXP2);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil(E1 / 4.0 + 19);
            checkEXP(EXP2);
            if (EXP2 > 200) {
                EXP2 += ceil(E1 / 9.0 + 21);
                checkEXP(EXP2);
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil(E1 / 4.0 + 19);
            checkEXP(EXP2);
            EXP2 += ceil(E1 / 9.0 + 21);
            checkEXP(EXP2);
            if (EXP2 > 400) {
                EXP2 += ceil(E1 / 16.0 + 17);
                checkEXP(EXP2);
                EXP2 += ceil(EXP2 * 0.15); // Thêm 15% của exp2 cũ
                checkEXP(EXP2);
            }
        }
        EXP1 -= E1;
        checkEXP(EXP1);
        checkEXP(EXP2);
    }

    return EXP1 + EXP2;
}

// Task 2
double traceLuggage_Street1(int& EXP1) {
    checkEXP(EXP1);
    if (EXP1 == 0) {
        return 80.0 / 123.0; // Trả về giá trị khác nếu EXP1 bằng 0
    }
    else if (576 <= EXP1 && EXP1 <= 600) {
        return 1;
    }
    else {
        float P1 = 0.0;
        int a = ceil(float(sqrt(EXP1)));
        int b = a - 1;
        if ((b * b) <= EXP1 && EXP1 <= ((a * a + b * b) / 2)) {
            P1 = 1;
        }
        else if (((a * a + b * b) / 2) <= EXP1 && EXP1 <= (a * a)) {
            P1 = (EXP1 / (a * a * 1.0) + 80) / 123;
        }
        return P1;
    }
}
double traceLuggage_Street2(int& HP1, int& EXP1, int& M1, int& E2) {
    checkHP(HP1);
    checkM(M1);
    checkEXP(EXP1);
    float P2 = 0.0;
    int MN = M1;
    if (E2 % 2 != 0) {
        for (int i = 0; i < 100; i++) {
            if (M1 == 0) {
                break;
            }
    
            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                checkHP(HP1);
              //  cout << HP1 << endl;
                M1 -= 150;
                checkM(M1);
              //      cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                if (0.5 * MN >= M1 ) {
                    break;
                }
            }
            else {
                HP1 = ceil(float(HP1 * 1.1));
                checkHP(HP1);
              //  cout << HP1 << endl;
                M1 -= 70;
                checkM(M1);
               //     cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                if (0.5 * MN >= M1 ) {
                    break;
                }
            };
            if (EXP1 < 400) {
                M1 -= 200;
                checkM(M1);
              //      cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 1.13));
                checkEXP(EXP1);
                if (0.5 * MN >= M1 ) {
                    break;
                }
            }
            else {
                M1 -= 120;
                checkM(M1);
              //      cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 1.13));
                checkEXP(EXP1);
                if (0.5 * MN >= M1 ) {
                    break;
                }
            }
            //   cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
            if (EXP1 < 300) {
                M1 -= 100;
                checkM(M1);
               //       cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 0.9));
                checkEXP(EXP1);
                if (0.5 * MN >= M1 ) {
                    break;
                }
            }
            else {
                M1 -= 120;
                checkM(M1);
              //         cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 0.9));
                checkEXP(EXP1);
                if (0.5 * MN >= M1 ) {
                    break;
                }
            }
            //   cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
        }
    }
    else {
        for (int i = 0; i < 1; i++) {
            if (M1 == 0) {
                break;
            }

            if (HP1 < 200) {
                HP1 = ceil(float(HP1 * 1.3));
                checkHP(HP1);
                M1 -= 150;
                checkM(M1);
                //    cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                if ( M1 == 0) {
                    break;
                }
            }
            else {
                HP1 = ceil(float(HP1 * 1.1));
                checkHP(HP1);
                M1 -= 70;
                checkM(M1);
                //    cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                if (M1 == 0) {
                    break;
                }
            };
            if (EXP1 < 400) {
                M1 -= 200;
                checkM(M1);
                //    cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 1.13));
                checkEXP(EXP1);
                if (M1 == 0) {
                    break;
                }
            }
            else {
                M1 -= 120;
                checkM(M1);
                //    cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 1.13));
                checkEXP(EXP1);
                if (M1 == 0) {
                    break;
                }
            }
            //   cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
            if (EXP1 < 300) {
                M1 -= 100;
                checkM(M1);
                //       cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 0.9));
                checkEXP(EXP1);
                if (M1 == 0) {
                    break;
                }
            }
            else {
                M1 -= 120;
                checkM(M1);
                //       cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
                EXP1 = ceil(float(EXP1 * 0.9));
                checkEXP(EXP1);
                if (M1 == 0) {
                    break;
                }
            }
            //   cout << HP1 << " " << EXP1 << " " << M1 << " " << E2 << endl;/////////////
        }
    }
    checkE(E2);
    checkHP(HP1);
    checkM(M1);
    checkEXP(EXP1);
   // cout << HP1 << endl;
    HP1 = ceil(float(HP1 * 0.83));
    EXP1 = ceil(float(EXP1 * 1.17));
  //  cout << HP1 << endl;
    checkHP(HP1);
    checkEXP(EXP1);
  //  cout << HP1 << endl;
    //  cout << EXP1 << endl;
    // cout << M1 << endl;
    //  cout << HP1 << endl;
    P2 = traceLuggage_Street1(EXP1);
    return P2;
}
double traceLuggage_Street3(int& E2) {
    //  checkE(E2);
    float P3 = 0.0;
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (0 <= E2 && E2 <= 9) {
        P3 = P[E2];
   //     cout << P3 << endl;
    }
    else if (10 <= E2 && E2 <= 99) {
        int a = E2 % 10;
        int b = (E2 - a) / 10;
        int c = (a + b) % 10;
        P3 = P[c];
        //   cout << P3<<endl;
    }
    else {
        E2 = -99;
    }
    return P3;
}
double traceLuggage(int& HP1, int& EXP1, int& M1, int& E2) {
    if (E2 < 0 || E2 > 99) {
        E2 = -99;
        return E2;
    };
    double a1 = traceLuggage_Street1(EXP1);
    double a2 = traceLuggage_Street2(HP1, EXP1, M1, E2);
    double a3 = traceLuggage_Street3(E2);
  //    cout << HP1 << " " << EXP1 << " " << M1 << endl;
 //     cout << a1 << " " << a2 << " " << a3 << endl; 
    if (a1 == a2 && a2 * 100 == a3 && a3 == 100) {
        EXP1 = ceil(float(EXP1 * 0.75));
        checkEXP(EXP1);
    }
    else {
        float P = (a1 * 100 + a2 * 100 + a3) / 3.0;
        if (P < 50) {
            HP1 = ceil(float(HP1 * 0.85));
            checkHP(HP1);
            EXP1 = ceil(float(EXP1 * 1.15));
            checkEXP(EXP1);
   //            cout << HP1 << " " << EXP1 << " " << M1 << endl;
        }
        else if (P > 50) {
            HP1 = ceil(float(HP1 * 0.9));
            checkHP(HP1);
            EXP1 = ceil(float(EXP1 * 1.2));
            checkEXP(EXP1);
    //          cout << HP1 << " " << EXP1 << " " << M1 << endl;
        }
    }
    checkE(E2);
    checkHP(HP1);
    checkM(M1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}
// Task 3
int timtoado(int& a) {
    int a1 = 0;
    if (0<=a&&a<10) {
        a1 = a;
    }
    else if (10 <= a && a <= 100) {
        int a2 = a % 10;
        int a3 = a /10;
        int b = a2 + a3;
        if (0 <= b && b < 10) {
            a1 = b;
        }
        else if (10 <= b && b < 100){
            int a4 = b % 10;
            int a5 = b /10;
            a1 = (a4 + a5);
        } 
    }
    return a1;
}
int matran1i(int& E3) {
    checkE(E3);
    double matran[10][10];
    int a = 0;
    int b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matran[i][j] > (2 * E3)) {
                a += 1;
            }
            else if (matran[i][j] < -E3) {
                b += 1;
            }
        }
    }
   /* for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(8) << matran[i][j];
        }
        cout << endl;
    }*/
    return timtoado(a);

}
//void matran2(int E3)
int matran1j(int& E3) {
    checkE(E3);
    double matran[10][10];
    int a = 0;
    int b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matran[i][j] > (2 * E3)) {
                a += 1;
            }
            else if (matran[i][j] < -E3) {
                b += 1;
            }
        }
    }
   /* for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(8) << matran[i][j];
        }
        cout << endl;
    }*/
    return timtoado(b);

}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    checkE(E3);
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    int i = matran1i(E3);
    int j = matran1j(E3);
    //  cout << i << " " << j << endl;
    int a = i;
    int b = j;
    int c = i;
    int d = j;
    int n = 0;

    double matran[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int cross[40];

    for (int k = -9; k < 10; k++) {
        a = i + k; b = j + k; c = i + k; d = j - k;
        if (a >= 0 && a <= 9 && b >= 0 && b <= 9) {
            cross[n++] = matran[a][b];
        }
        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            cross[n++] = matran[c][d];
        }
    }

    int scoreS = cross[0];
    //  for (int i = 1; i < n; i++) {
    //     cout << cross[i] << " ";
    //  }
    for (int i = 1; i < n; i++) {
        if (scoreS < cross[i]) {
            scoreS = cross[i];
        }
    }
    //  cout << scoreS << endl;
    scoreS = abs(scoreS);

    int Re;
    // So sánh scoreS và scoreT
    if (scoreS > abs(matran[i][j])) {
        Re = scoreS;
        EXP1 = ceil(1.12 * EXP1);
        HP1 = ceil(1.10 * HP1);
        EXP2 = ceil(1.12 * EXP2);
        HP2 = ceil(1.10 * HP2);
    }
    else if (scoreS < abs(matran[i][j])) {
        Re = matran[i][j];
        EXP1 = ceil(0.88 * EXP1);
        HP1 = ceil(0.9 * HP1);
        EXP2 = ceil(0.88 * EXP2);
        HP2 = ceil(0.9 * HP2);
    }
    checkE(E3);
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    return Re;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    string se;
    int sei = -1, sci = -1; // Khởi tạo các biến sai số cần đếm
    int n = 0;

    // Lấy phần tên người dùng từ email
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] != '@') {
            se += email[i];
        } else { 
            break; 
        }
    }

    // Kiểm tra độ dài của mật khẩu
    if (strlen(s) < 8) {
        n++;
        return -1; // Mật khẩu quá ngắn
    } else if (strlen(s) > 20) {
        n++;
        return -2; // Mật khẩu quá dài
    }

    // Kiểm tra sự trùng lặp của ký tự trong mật khẩu
    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            n++;
            sci = i;
            break;
        }
    }

    // Kiểm tra xem mật khẩu có chứa ký tự từ email không
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == se[0]) {
            sei = i;
            n++;
            break;
        }
    }

    // Kiểm tra xem mật khẩu có chứa ký tự đặc biệt không
    bool check1 = false;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            check1 = true;
            break;
        }
    }
    if (!check1) {
        n++;
        return -5; // Mật khẩu không chứa ký tự đặc biệt
    }

    // Kiểm tra xem mật khẩu có thỏa mãn các điều kiện không
    if (n == 0) {
        return -10; // Mật khẩu hợp lệ
    }

    // Trả về sai số cuối cùng (trong trường hợp không hợp lệ)
    if (sei != -1) {
        return -(300 + sei); // Mật khẩu chứa ký tự từ email
    } else if (sci != -1) {
        return -(400 + sci); // Mật khẩu có sự trùng lặp ký tự
    }

    return -99; // Trường hợp mặc định
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // Khởi tạo các biến đếm
    int max_count = 0;
    int max_length = 0;
    int correct_index = -1;

    // Duyệt qua mảng để tìm mật khẩu đúng
    for (int i = 0; i < num_pwds; ++i) {
        const char *pwd = arr_pwds[i];
        int count = 0;
        int length = strlen(pwd);
        
        // Đếm số lần xuất hiện của mật khẩu hiện tại
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], pwd) == 0) {
                count++;
            }
        }

        // Kiểm tra xem mật khẩu hiện tại có phải là mật khẩu đúng không
        if (count > max_count || (count == max_count && length > max_length)) {
            max_count = count;
            max_length = length;
            correct_index = i;
        }
    }

    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

 