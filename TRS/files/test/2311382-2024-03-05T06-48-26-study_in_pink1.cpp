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
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if ((e1<0) && (e1>99) ) return -99; // e1 khong hop le
    if (exp1>600) exp1=600;
    if (exp2>600) exp2=600;
    if (exp1<0) exp1=0;
    if (exp2<0) exp2=0;
    
    // e1 trong doan [0,3]
    
    if ((e1 >= 0) && (e1 <= 3))
    {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;
        // chi so D
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 += ceil(D/200.0); // D chan thi cong
        else
            exp1 = exp1 - D/100.0 + 0.999; // D le thi tru
    }

    
    // e1 trong doan [4, 99]
    else if ((e1 >= 4) && (e1 <= 99))
    {
        if ((e1 >= 4) && (e1 <= 19))
            exp2 = exp2 + ceil(e1 / 4.0) + 19; // thong tin 1
        if ((e1 >= 20) && (e1 <= 49))
            exp2 = exp2 + ceil(e1 / 9.0) + 21; // thong tin 2
        if ((e1 >= 50) && (e1 <= 65))
            exp2 = exp2 + ceil(e1 / 16.0) + 17; // thong tin 3
        if ((e1 >= 66) && (e1 <= 79))
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19; // giai thich thong tin 1
            if (exp2 > 200)
                exp2 = exp2 + ceil(e1 / 9.0) + 21; // giai thich them thong tin 2
        }
        if ((e1 >= 80) && (e1 <= 99))
        {
            exp2 = exp2 + ceil(e1 / 4.0) + 19;
            exp2 = exp2 + ceil(e1 / 9.0) + 21; // giai thich thong tin 1 va 2
            if (exp2 > 400)
            {
                exp2 = exp2 + ceil(e1 / 16.0) + 17; // giai thich them thong tin 3 va dc cong them exp
                exp2 += ceil(exp2 * 0.15) ;             // cong them 15%
            }
        }
        exp1 -= e1;
    }
    
    if (exp1>600) exp1=600;
    if (exp2>600) exp2=600;
    if (exp1<0) exp1=0;
    if (exp2<0) exp2=0;
    
    return exp1 + exp2;
}

// Task 2

int NearbySquare(int &a)
{
    int lower = sqrt(a);
    int lowerSquare = lower * lower;
    int upper = lower + 1;
    int upperSquare = upper * upper;
    if (lowerSquare == a)
        return a;
    else if (abs(a - lowerSquare) < abs(a - upperSquare))
        return lowerSquare;
    else
        return upperSquare;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // dieu kien ban dau
    if (E2<0 && E2>99) return -99;
    if (M1>3000) M1 = 3000;
    double p1;
    int S1 = NearbySquare(EXP1);
    if (EXP1 >= S1) p1 = 1;
    else p1 = (EXP1 / S1 + 80) / 123.0; // xac suat tim thay vali

    // Con duong 2
    int m = 0;
    if (E2 % 2 == 0) {
        if (M1>0) {
            if (HP1 < 200)
    {
        HP1 += ceil(HP1 * 0.3); // cong them 30%
        m += 150;
        if (HP1 > 666) HP1 = 666;
    }
    else
    {
        HP1 += ceil(HP1 * 0.1); // cong them 10%
        m += 70;
        if (HP1 > 666) HP1 = 666;
    }
        }
        if (M1>0) {
            if (EXP1 < 400)
        m += 200;
    else
        m += 120;
    EXP1 += ceil(EXP1 * 0.13); // cong them 13%
    if (EXP1 > 600) EXP1 = 600;
        }
        if (M1>0) {
            if (EXP1 < 300)
        m += 100;
    else
        m += 120;
    EXP1 = ceil(EXP1 * 0.9); // tru di 10%
        }
    } 
    if (E2%2==1) {
        {
        while (m <= M1/2.0)
        {
            if (m <= M1/2.0) {
            if (HP1 < 200)
    {
        HP1 += ceil(HP1 * 0.3); // cong them 30%
        if (HP1>666) HP1 = 666;
        m += 150;
    }
    else
    {
        HP1 += ceil(HP1 * 0.1); // cong them 10%
        if (HP1>666) HP1 = 666;
        m += 70;
    }
                }     
            else break;
            if (m <= M1/2.0) {
                if (EXP1 < 400)
        m += 200;
    else
        m += 120;
    EXP1 += ceil(EXP1 * 0.13); // cong them 13%
    if (EXP1 > 600) EXP1 = 600;
            }    
            else break;
            if (m <= M1/2.0) {
                if (EXP1 < 300)
        m += 100;
    else
        m += 120;
    EXP1 = ceil(EXP1 * 0.9); // tru di 10%
            }    
            else break;
        }
    }
    }
    M1 -= m;
    if (M1 < 0) M1 = 0;
    EXP1 += ceil(EXP1 * 0.17);
    if (EXP1 > 600) EXP1 = 600;
    HP1 = ceil(HP1 * 0.83);

    double p2; // Xac suat tren con duong 2
    int S2 = NearbySquare(EXP1);
    if (EXP1 >= S2)
        p2 = 1.0;
    else
        p2 = (EXP1 / S2 + 80) / 123.0; // xac suat tim thay vali

    // con duong 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    
    int i = (E2 % 10 + E2/10)%10;
    double p3 = P[i] / 100.0;
    double p = (p1 + p2 + p3)/3.0;

    // Doi chieu voi xac suat p
    if (p == 1)
        EXP1 = ceil(EXP1 * 0.75);
    else if (p < 0.5)
    {
        HP1 = ceil(HP1 * 0.85);
        EXP1 += ceil(EXP1 * 0.15);
    }
    else
    {
        HP1 = ceil(float(HP1 * 0.9));
        EXP1 += ceil(float(EXP1 * 0.2));
    }
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 > 600)
        EXP1 = 600;
    
    return HP1 + EXP1 + M1;
}
// Task 3


int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if ((E3<0) && (E3>99)) return -99;
    // mang diem so tung vi tri di qua cua taxi
    int a[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // tim diem giao nhau
    int c1 = 0, c2 = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > E3 * 2)
                c1++;
            if (a[i][j] < -E3)
                c2++;
        }
    }

    // tim tong cac chu so
    c1 = c1/ 10 + c1%10;
    c1 = c1/ 10 + c1%10;
    c2 = c2/ 10 + c2%10;
    c2 = c2/ 10 + c2%10;
    // (c1, c2) la toa do can tim

   
    
    int x = c1, y = c2;
        int max = 0;

        // Tìm trên đường chéo trái
        if (y >= x)
        {
            for (int n = 0; n < 10; n++)
            {
                if (y - x + n < 10)
                    max = a[n][y - x + n] ? a[n][y - x + n] : max;
            }
        }
        else
        {
            for (int n = 0; n < 10; n++)
            {
                if (x - y + n < 10)
                    max = a[x - y + n][n] ? a[x - y + n][n] : max;
            }
        }
        // Tìm trên đường chéo phải
        if (x + y >= 9)
        {
            for (int n = 0; n < 10; n++)
            {
                if (x + y - 9 + n < 10)
                    max = a[x + y - 9 + n][9 - n] ? a[x + y - 9 + n][9 - n] : max;
            }
        }
        else
        {
            for (int n = 0; n < 10; n++)
            {
                if (x + y - n >= 0)
                    max = a[n][x + y - n] ? a[n][x + y - n] : max;
            }
        }
    
    if (abs(a[c1][c2]) <= abs(max))
    {
        EXP1 += ceil(EXP1 * 0.12);
        HP1 += ceil(HP1 * 0.1);
        EXP2 += ceil(EXP2 * 0.12);
        HP2 += ceil(HP2 * 0.1);
        if (EXP1>600) EXP1 = 600;
    if (EXP2>600) EXP2 = 600;
    if (HP1>666) HP1 = 666;
    if (HP2>666) HP2=666;
    if (EXP1<0) EXP1 = 0;
    if (EXP2<0) EXP2 = 0;
    if (HP1<0) HP1 = 0;
    if (HP2<0) HP2 = 0;
        return max;
    }
    else
    {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        if (EXP1>600) EXP1 = 600;
    if (EXP2>600) EXP2 = 600;
    if (HP1>666) HP1 = 666;
    if (HP2>666) HP2=666;
    if (EXP1<0) EXP1 = 0;
    if (EXP2<0) EXP2 = 0;
    if (HP1<0) HP1 = 0;
    if (HP2<0) HP2 = 0;
        return a[c1][c2];
    }
    
    
}

// Task 4
// int timkytu(const char* s, char sh) {
//     for (int i=0; i< strlen(s); i++) {
//         if (s[i] == sh) return i; // vi tri ky tu can tim
//     }
//     return -1; // khong co ky tu can tim
// }
// // chu hoa va chu thuong trong bang ma ASCII
// bool chucai(char sh) {
//     bool chuhoa = ((65 <= sh) && (sh <= 90));
//     bool chuthuong = ((97 <= sh) && (sh <= 122));
//     if (chuhoa || chuthuong) return true;
//     else return false;
// }

// bool chuso(char sh) {
//     if (48 <= sh <= 57)
//         return true;
//     return false;
// }
// // có kí tự đặc biệt cho phép hay không
// bool kytudacbiet(char sh) {
//     char special[5] = {'@', '#', '$', '%', '!'};
//     for (int i =0; i<5; i++) {
//         if (sh == special[i]) return true;
//     }
//     return false;
// }

// int checkPassword(const char * s, const char * email) {
//     std::string str = s;
//     std::string se = {};
    
//     int n = strlen(s);
//     if (n<8) return -1;
//     else if (n>20) return -2;
    
//     for (int i=0;i<timkytu(email, '@');i++) {
//         se += email[i]; // tao chuoi se
//     }
//     // kiem tra se co nam o dau chuoi hay khong

//     // Kiem tra co se tu ki tu thu 1 hay khong
//     if (0 <= str.find(se) && str.find(se) < n ) return -0 - (300 + str.find(se));
//         else {
//             for (int i=0; i<strlen(s); i++) {
//             if ((s[i] == s[i+1]) && (s[i+1] == s[i+2])) return 0 - (400 + i);
//         }
//     }
    
    
    
//     // if (valid == 0) return -5; // khong chua ki tu dac biet
//     for (int i=0; i<strlen(s); i++) {
//         if (!(chucai(s[i]) || chuso(s[i]) || kytudacbiet(s[i]))) return i;
//     }
//     int count = 0;
//     for (int i=0; i<strlen(s); i++) {
//         if (!(kytudacbiet(s[i]))) count++;
//     }
//     if (count == strlen(s)) return -5;
//     return -10; // mật khẩu hợp lệ
    
// }
int findchar(const char* s, char sp) { //tìm kí tự
    for (int i=0; i< strlen(s); i++) {
        if (s[i] == sp) return i; 
    }
    return -1; 
}
// Chữ in hoa và thường 
bool letter(char sp) {
    bool uppercaseletter = ((65 <= sp) && (sp <= 90));
    bool lowercaseletter = ((97 <= sp) && (sp <= 122));
    if (uppercaseletter || lowercaseletter) return true;
    else return false;
}

bool number(char sp) {
    if (48 <= sp <= 57)
        return true;
    return false;
}
// có kí tự đặc biệt cho phép hay không
bool specialchar(char sp) {
    char special[5] = {'@', '#', '$', '%', '!'};
    for (int i =0; i<5; i++) {
        if (sp == special[i]) return true;
    }
    return false;
}

int checkPassword(const char * s, const char * email) {
    std::string si = s;
    std::string se = {};

    for (int i=0;i<findchar(s, '@');i++) {
        se += email[i]; // tạo chuỗi se
    }
    
    int a = strlen(s);
    if (a<8) {return -1;} // độ dài s ngắn hơn yc
    else if (a>20) {return -2;} // độ dài s dài hơn yc

    if (si.find(se) >= 0 && si.find(se) < strlen(s)) { // giới hạn si.find(se) vì s ko chứa se hàm trả gtri lớn nhất của size_si
        return  -(300 + si.find(se));
        } // s chứa se
    else {
        for (int i=0; i<strlen(s); i++) {
            if ((s[i] == s[i+1]) && (s[i+1] == s[i+2])) {return 0 - (400 + i);}
        }
    } // s có chứa nhiều hơn 2 kí tự liên tiếp giống nhau ?

    
    for (int i=0; i<strlen(s); i++) {
        if (!(letter(s[i]) || number(s[i])) || specialchar(s[i])) {return i;}
    }
    int count = 0;
    for (int i=0; i<strlen(s); i++) {
        if (!(specialchar(s[i]))) count++;
    }
    if (count == strlen(s)) {return -5;} //se ko chứa kí tự đặc biệt
    else {return -10;} // mật khẩu hợp lệ
    
}
// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int num[num_pwds]; // Mảng chứa số lần lặp
    for (int i =0; i< num_pwds; i++) {
        int count = 1;
        for (int j=0; j< num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { // so sánh 2 chuỗi
                count++;
            }
        }
        num[i] = count;
    } 
    int max = 0; // tìm số lần lặp nhiều nhất
    int temp;
    for (int i=0; i<num_pwds;i++) {
        if (num[i]>max) {
            max = num[i];
            temp = i;
        }
    }
    for (int j = temp + 1; j < num_pwds; j++) {
        if ((num[j] == max) && (strlen(arr_pwds[j]) > strlen(arr_pwds[temp])))
        temp = j;
        }
    return temp;   
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////