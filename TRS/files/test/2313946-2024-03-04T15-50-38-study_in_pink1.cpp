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

//======================task 1==================================
int check(int n, int firstpoint, int lastpoint) {
    n = (n < firstpoint) ? firstpoint : (n > lastpoint) ? lastpoint : n;
    return n;
}

int firstMeet(int &EXP1, int &EXP2,  int E1)
{
    int firstpoint = 0, lastpoint = 600;
    //Complete this function to gain point on task 1

    //=========check the input=============
    if (E1 < 0 || E1 > 99) return -99;
    EXP1 = check(EXP1, firstpoint, lastpoint);
    EXP2 = check(EXP2, firstpoint, lastpoint);
    //=======================================

const int inform1_1 = 29, inform1_2 = 45, inform1_3 = 75;
    float inform2_1, inform2_2, inform2_3;
    inform2_1 = E1 * 1.0000 / 4 + 19;
    inform2_2 = E1 * 1.0000 / 9 + 21;
    inform2_3 = E1 * 1.0000 / 16 + 17;
    float EXP1_test = EXP1; // use float var to caculate
    float EXP2_test = EXP2;

    //========= case 1 or 2 ??==============
 // Trường hợp 1
    if (E1 >= 0 && E1 <= 3) {
        switch (E1) {
            case 0:
                EXP2 += inform1_1;
                break;
            case 1:
                EXP2 += inform1_2;
                break;
            case 2:
                EXP2 += inform1_3;
                break;
            case 3:
                EXP2 += inform1_1  + inform1_2 + inform1_3;
                break;
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1_test = ceil( EXP1_test + D*1.0 / 200);
        } else {
            EXP1_test = ceil(EXP1_test - D*1.0/ 100);
        }
            EXP1 = EXP1_test;
    }

 // Trường hợp 2
 else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2_test += inform2_1;
        } else if (E1 >= 20 && E1 <= 49) {
            EXP2_test += inform2_2;
        } else if (E1 >= 50 && E1 <= 65) {
            EXP2_test += inform2_3;
        } else if (E1 >= 66 && E1 <= 79) {
            EXP2_test = ceil(EXP2_test + inform2_1);
            EXP2 = EXP2_test;
            EXP2 = check(EXP2, firstpoint, lastpoint);
            EXP2_test = EXP2 ;
          if (EXP2_test > 200) EXP2_test += inform2_2;


     } else if (E1 >= 80 && E1 <= 99) {

           EXP2_test = ceil(EXP2_test + inform2_1);
           EXP2_test = ceil(EXP2_test + inform2_2);
           EXP2 = EXP2_test;
           EXP2 = check(EXP2, firstpoint, lastpoint);
           EXP2_test = EXP2;

      //return EXP2 to EXP2_test to continue caculate
 if (EXP2_test > 400) {
                EXP2_test = ceil(EXP2_test + inform2_3);
                EXP2 = EXP2_test;
                EXP2 = check(EXP2, firstpoint, lastpoint);
                EXP2_test = EXP2;
                EXP2_test = ceil(EXP2_test + EXP2_test * 0.15);
           }
    }
 // round up EXP2
        EXP2_test = ceil(EXP2_test);
        EXP2 = EXP2_test;
 //caculate EXP1 (need round up)
        EXP1_test = ceil(EXP1_test - E1);
        EXP1 = EXP1_test;
 }
  //check the result
 EXP1 = check(EXP1, firstpoint, lastpoint);
    EXP2 = check(EXP2, firstpoint, lastpoint);
    return (EXP1 + EXP2);
}




////////////////////////////////////======Task 2======//////////////////////////////////////////
int nearest_square(int n) {
    double X = sqrt(n);
    int int_partX = static_cast<int>(X);
    int X1 = int_partX * int_partX;
    int X2 = (int_partX + 1) * (int_partX + 1);
    if (int_partX * int_partX == n || ((int_partX + 1) * (int_partX + 1)) - n > n - (int_partX * int_partX)) {
        return (int_partX * int_partX);
    } else {
        return (int_partX + 1) * (int_partX + 1);
    }
}

double traceLuggage_Street1(int EXP1)
{
    int S;
    S =  nearest_square(EXP1);
if ( EXP1 >= S)
return 100;
else {
return ((EXP1/S + 80) / 123.0) * 100;}
}

double traceLuggage_Street2(int &HP1, int & EXP1, int &M1, int E2)
{
double half_M = M1 * 0.5;
int a = 0;
if (M1 == 0)
{
  HP1 = ceil(HP1 * 83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666);               // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);             // Kiểm tra giá trị EXP
}
else if (M1 != 0) {
while (true){

/////////////////////SỰ KIÊN SỐ 1/////////////////////////
if(HP1 < 200)
{
HP1 = ceil( HP1 * 13.0/10);
M1 -= 150;
a += 150;
}
else if ( HP1 >=200)
{
HP1 = ceil( HP1 * 11.0/10);
M1 -= 70;
a += 70;
}
  HP1 = check(HP1, 0, 666);             // Kiểm tra giá trị HP
  M1 = check(M1, 0, 3000);              // Kiểm tra giá trị M
if ( E2 % 2 != 0 && a > half_M)
{
  HP1 = ceil(HP1 * 83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666);               // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);             // Kiểm tra giá trị EXP
break;
}
else if ( E2 % 2 == 0 && M1 == 0)
{
  HP1 = ceil(HP1 *  83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666);               // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);            // Kiểm tra giá trị EXP1
break;
}

////////////////////////////// SỰ KIÊN 2/////////////////////
if (EXP1 < 400)
{
    M1 -= 200;
    a  += 200;
}
else if ( EXP1 >= 400)
{
    M1 -= 120;
    a += 120;
}
EXP1 = ceil( EXP1 * 113.0/100);

HP1 = check(HP1, 0, 666); // Kiểm tra giá trị HP
M1 = check(M1, 0, 3000);  // Kiểm tra giá trị M

if ( E2 % 2 != 0 && a > half_M)
{
  HP1 = ceil(HP1 * 83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666); // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);  // Kiểm tra giá trị EXP
break;
}
else if ( E2 % 2 == 0 && M1 == 0)
{
  HP1 = ceil(HP1 * 83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666); // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);  // Kiểm tra giá trị EXP
break;
}

//////////////////////////////////// SỰ KIỆN 3/////////////////////
if (EXP1 < 300)
{
    M1 -= 100;
    a += 100;
}
else if (EXP1 >= 300)
{
    M1 -= 120;
    a += 120;
}
EXP1 = ceil( EXP1 * 9.0/10);

HP1 = check(HP1, 0, 666); // Kiểm tra giá trị HP
M1 = check(M1, 0, 3000);  // Kiểm tra giá trị M

if ( E2 % 2 != 0 && a > half_M)
{
  HP1 = ceil(HP1 * 83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666); // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);  // Kiểm tra giá trị EXP
break;
}
else if ( E2 % 2 == 0 )
{
  HP1 = ceil(HP1 * 83.0/100);
  EXP1 = ceil( EXP1 * 117.0/100);
  HP1 = check(HP1, 0, 666); // Kiểm tra giá trị HP
  EXP1 = check(EXP1, 0, 600);  // Kiểm tra giá trị EXP
break;
}
}
}
return traceLuggage_Street1(EXP1);
}

double traceLuggage_Street3(int E2)
{
int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i;
if (E2 < 10)
{
i = E2;
}
else if (E2 >= 10 && E2 < 100) {
        // Tính tổng của hai chữ số
        int total = E2 / 10 + E2 % 10;
        i= total % 10;
}
return P[i];
}

int traceLuggage(int &HP1, int &EXP1, int &M1,  int E2) {
    //Complete this function to gain point on task 3

    //============== check input=================
    if (E2 < 0 || E2 > 99) return -99;
    HP1 = check(HP1, 0, 666);
    EXP1 = check(EXP1, 0, 600);
    M1 = check(M1, 0, 3000);

    // TODO: Complete this function
    double P1 = traceLuggage_Street1(EXP1);
    double P2 = traceLuggage_Street2(HP1, EXP1, M1, E2);
    double P3 = traceLuggage_Street3(E2);
if ( P1 == 100 && P2 == 100 & P3 == 100 )
{
EXP1 = ceil( EXP1 * 3.0/4);
}
else {
double P = ( P1 + P2 + P3) / 3;
if ( P< 50)
{
HP1 = ceil( HP1 * 17.0/20);
EXP1 = ceil( EXP1 * 23.0/20);
}
else {
HP1 = ceil( HP1 * 9.0/10);
EXP1 = ceil( EXP1 * 6.0/5);
}
}
 HP1 = check(HP1, 0, 666);    // Kiểm tra giá trị EXP
 EXP1 = check(EXP1, 0, 600);  // Kiểm tra giá trị HP
   return (HP1 + EXP1 + M1);
}


////////////////////////////////////======Task 3======//////////////////////////////////////////
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;
    int Xe_Taxi[10][10] = {0};
    int Sherlock_Watson[10][10] = {0};

    // Tính điểm cho Xe_Taxi
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
             Xe_Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính điểm cho Sherlock_Watson
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Đường chéo trái
            int Duong_Cheo_Trai_Max = Xe_Taxi[i][j];
            for (int k = 0; k < min(i, j); k++)
            {
                if ( Duong_Cheo_Trai_Max > Xe_Taxi[i - k][j - k])  Duong_Cheo_Trai_Max =  Duong_Cheo_Trai_Max;
            else  Duong_Cheo_Trai_Max = Xe_Taxi[i - k][j - k];

            }

            // Đường chéo phải
            int Duong_Cheo_Phai_Max = Xe_Taxi[i][j];
            for (int k = 0; k < min(10 - i, j); k++)
            {
                if (Duong_Cheo_Phai_Max > Xe_Taxi[i + k][j - k])  Duong_Cheo_Phai_Max = Duong_Cheo_Phai_Max;
            else  Duong_Cheo_Phai_Max = Xe_Taxi[i + k][j - k];

            }

            Sherlock_Watson[i][j] = Duong_Cheo_Trai_Max > Duong_Cheo_Phai_Max ? Duong_Cheo_Trai_Max : Duong_Cheo_Phai_Max;
            Sherlock_Watson[i][j] = abs(Sherlock_Watson[i][j]);
        }
    }

    // Tìm vị trí gặp nhau
    int I = 0, J = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (Xe_Taxi[i][j] > E3 * 2)
                I++;
            if (Xe_Taxi[i][j] < -E3)
                J++;
        }
    }

    // Nếu i hoặc j là số có 2 chữ số
    while (I >= 10 || J >= 10)
    {
        if (I >= 10)
        {
            I = I / 10 + I % 10;
        }
        if (J >= 10)
        {
            J = J / 10 + J % 10;
        }
    }
    // Tính điểm cuối cùng
    int MaxScore;
    if (abs(Xe_Taxi[I][J]) > Sherlock_Watson[I][J])
    {
        // Taxi thoát được
        EXP1 = ceil(EXP1 * 22.0/25);
        EXP2 = ceil(EXP2 * 22.0/25);
        HP1 = ceil(HP1 * 9.0/10);
        HP2 = ceil(HP2 * 9.0/10);
        MaxScore = Xe_Taxi[I][J];
    }
    else
    {
        // Sherlock và Watson bắt được taxi
        EXP1 = ceil(EXP1 * 28.0/25 );
        HP1  = ceil(HP1 * 11.0/10);
        EXP2 = ceil(EXP2 * 28.0/25 );
        HP2  = ceil(HP2 * 11.0/10);
        MaxScore = Sherlock_Watson[I][J];
    }
   HP1 = check(HP1, 0, 666);    // Kiểm tra giá trị EXP1
   EXP1 = check(EXP1, 0, 600);  // Kiểm tra giá trị HP1
   HP2 = check(HP2, 0, 666);    // Kiểm tra giá trị EXP2
   EXP2 = check(EXP2, 0, 600);  // Kiểm tra giá trị HP2
    return MaxScore;
}


//////////////////////////======Task 4======//////////////////////////////
int checkPassword(const char *s, const char *email)
{
    string Mat_Khau(s);
    string tk_Email(email);
    string se = tk_Email.substr(0, tk_Email.find('@'));

    // Kiểm tra độ dài của mật khẩu
    if (Mat_Khau.length() < 8)
        return -1;
    if (Mat_Khau.length() > 20)
        return -2;

    // Kiểm tra xem mật khẩu có chứa chuỗi 'se' không
    if (Mat_Khau.find(se) != std::string::npos)
        return -(300 + Mat_Khau.find(se));

    // Kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp không
    for (int i = 0; i < Mat_Khau.length() - 2; i++)
    {
        if (Mat_Khau[i] == Mat_Khau[i + 1] && Mat_Khau[i + 1] == Mat_Khau[i + 2])
            return -(400 + i);
    }

    // Kiểm tra xem mật khẩu có chứa ít nhất 1 ký tự đặc biệt không
    string special_chars = "@#%$!";
    bool Chua_Ki_Tu_Dac_Biet = false;
    for (char t : Mat_Khau)
    {
        if (special_chars.find(t) != std::string::npos)
        {
           Chua_Ki_Tu_Dac_Biet = true;
            break;
        }
    }
    if (!Chua_Ki_Tu_Dac_Biet)
        return -5;

    // Kiểm tra xem mật khẩu có chứa ký tự không hợp lệ không
    ///// Kiểm tra xem mỗi ký tự trong mật khẩu chỉ có thể là chữ số, hoặc chữ cái thường, hoặc chữ cái in hoa, hoặc ký tự đặc biệt
    for (char t : Mat_Khau)
    {
        if (!std::isdigit(t) && !std::isalpha(t) && special_chars.find(t) == std::string::npos)
            return Mat_Khau.find(t);
    }
    // Mật khẩu hợp lệ, trả về -10
    return -10;
}


///////////////////////////======Task 5======//////////////////////////////
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int Vi_Tri_Mat_Ma_First = 0, So_Lan_Xuat_Hien_MAX = 0, maxLength = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        int So_Lan_Xuat_Hien = 0, length = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                So_Lan_Xuat_Hien++;
            }
        }
        if (So_Lan_Xuat_Hien > So_Lan_Xuat_Hien_MAX || (So_Lan_Xuat_Hien == So_Lan_Xuat_Hien_MAX && length > maxLength))
        {
            So_Lan_Xuat_Hien_MAX = So_Lan_Xuat_Hien;
            maxLength = length;
            Vi_Tri_Mat_Ma_First = i;
        }
    }
    return Vi_Tri_Mat_Ma_First;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
