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
void checkEXP(int &EXP1, int &EXP2)
{
    if(EXP1 > 600)
    EXP1 = 600;
    if(EXP2 > 600)
    EXP2 = 600;
    if(EXP1 < 0)
    EXP1 = 0;
    if(EXP2 < 0)
    EXP2 = 0;
}

// Kiem tra va dieu chinh gia tri HP neu no vuot qua hoac duoi gioi han
void checkHP(int &HP1, int &HP2)
{
    if(HP1 > 666)
    HP1 = 666;
    if(HP2 > 666)
    HP2 = 666;
    if(HP1 < 0)
    HP1 = 0;
    if(HP2 < 0)
    HP2 = 0;
}

// Kiem tra va dieu chinh gia tri M neu no vuot qua hoac duoi gioi han
void checkM(int &M1, int &M2)
{
    if(M1 > 3000)
    M1 = 3000;
    if(M2 > 3000)
    M2 = 3000;
    if(M1 < 0)
    M1 = 0;
    if(M2 < 0)
    M2 = 0; 
}

/////////////////////////// Task 1 ///////////////////////////
// Task 1
// Truong hop dau tien, dieu chinh gia tri EXP dua tren gia tri e1. EXP2 tang dua tren e1, EXP1 thay doi dua tren D (tinh tu e1 va EXP1). Cuoi cung, kiem tra gia tri EXP.
void firstMeet_Case1(int &exp1, int &exp2, int e1)
{
    if(e1 == 0)
      exp2 += 29;
      if(e1 == 1)
      exp2 += 45;
      if(e1 == 2)
      exp2 += 75;
      if(e1 == 3)
      exp2 += 29 + 45 + 75;
      int D = exp1 * 7 + e1 * 3;
      if(D % 2 == 0)
      exp1 = ceil((double)exp1 + (double)D / 200);
      else
      exp1 = ceil((double)exp1 - (double)D / 100);
}

// Truong hop thu hai, dieu chinh gia tri EXP dua tren gia tri e1. EXP tang, giam dua tren e1. Cuoi cung, kiem tra gia tri EXP.
void firstMeet_Case2(int &exp1, int &exp2, int e1)
{
    if(e1 >= 4 && e1 <= 19)
    exp2 += ceil((double)e1 / 4 + 19);
    else if(e1 >= 20 && e1 <= 49)
    exp2 += ceil((double)e1 / 9 + 21);
    else if(e1 >= 50 && e1 <= 65)
    exp2 += ceil((double)e1 / 16 + 17);
    else if(e1 >= 66 && e1 <= 79)
    {
        exp2 += ceil((double)e1 / 4 + 19);
        if(exp2 > 200)
        exp2 += ceil((double)e1 / 9 + 21);
    }
    else
    {
        exp2 += ceil((double)e1 / 9 + 21 + (double)e1 / 4 + 19);
        if(exp2 > 400)
        {
            exp2 += ceil((double)e1 / 16 + 17);
            exp2 = ceil((double)exp2 * 1.15);
        }
    }
    exp1 -= e1;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1 <=99 && e1 >= 0)
    {
        if(e1 <= 3 && e1 >= 0)
        firstMeet_Case1(exp1, exp2,e1);
        else if(e1 >= 4 && e1 <= 99)
        firstMeet_Case2(exp1, exp2, e1);
        checkEXP(exp1, exp2);
        return exp1 + exp2;
    }
    else
    return -99;
}

// Task 2
double traceLuggage_Street1(int exp1)
{
    float S = sqrt(exp1);
    S = round(S);
    if(exp1 >= S * S)
    return 100;
    else
    return (exp1 / (S * S) + 80) / 123;
}

// Xu ly hanh ly o Street2 dua tren cac gia tri HP1, EXP1, M1 va e2. Cac su kien khac nhau se thay doi gia tri cua HP1, EXP1 va M1. Cu the, su kien 1 tang HP1 va giam M1, su kien 2 giam M1 va tang EXP1, va su kien 3 giam M1 va giam EXP1. Neu M1 giam xuong duoi mot muc nhat dinh hoac M1 het, thi tang EXP1 va giam HP1. Cuoi cung, kiem tra gia tri cua EXP1 va HP1, va tra ve gia tri tu ham traceLuggage_Street1.
double traceLuggage_Street2(int &HP1, int &EXP1, int &M1, int e2)
{
    int Min = M1;
    while(e2 % 2 != 0)
    {
        if(HP1 < 200)
        {
            HP1 = ceil((double)HP1 * 1.3);
            M1 -= 150;
        }
        else
        {
            HP1 = ceil((double)HP1 * 1.1);
            M1 -= 70;
        }
        if(M1 * 2 < Min)
        break;
        if(EXP1 < 400)
        M1 -= 200;
        else
        M1 -= 120;
        EXP1 = ceil((double)EXP1 * 1.13);
        if(M1 * 2 < Min)
        break;
        if(EXP1 < 300)
        M1 -= 100;
        else
        M1 -= 120;
        EXP1 = ceil((double)EXP1 * 0.9);
        }
    if(e2 % 2 == 0)
    {
        int a = 1;
        while(a > 0)
        {
            if(HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil((double)HP1 * 1.1);
                M1 -= 70;
            }
            if(M1 <= 0)
            break;
            if(EXP1 < 400)
            M1 -= 200;
            else
            M1 -= 120;
            EXP1 = ceil((double)EXP1 * 1.13);
            if(M1 <= 0)
            break;
            if(EXP1 < 300)
            M1 -= 100;
            else
            M1 -= 120;
            EXP1 = ceil((double)EXP1 * 0.9);
            a--;
        }
    }
    EXP1 = ceil((double)EXP1 * 1.17);
    HP1 = ceil((double)HP1 * 0.83);
    return traceLuggage_Street1(EXP1); 
}

// Tra ve mot gia tri tu mang P dua tren gia tri e2. Neu e2 nho hon 10, chi so i se bang e2. Ngoc lai, i se bang tong cua chu so hang chuc va hang don vi cua e2, chia lay phan du cho 10.
double traceLuggage_Street3(int e2)
{
    int P[10] =  {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(e2 < 10)
    return P[e2];
    else
    return P[(e2 / 10 + e2 % 10) % 10];
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double P1 = traceLuggage_Street1(EXP1);
    double P2 = traceLuggage_Street2(HP1, EXP1, M1, E2);
    double P3 = traceLuggage_Street3(E2);
    if(P1 == P2 == P3 == 100)
    EXP1 = ceil((double)EXP1 * 0.75);
    else
    {
        double av = (P1 + P2 + P3) / 2;
        if(av < 50)
        {
            EXP1 = ceil((double)EXP1 * 1.15);
            HP1 = ceil((double)HP1 * 0.85);
        }
        else
        {
            EXP1 = ceil((double)EXP1 * 1.2);
            HP1 = ceil((double)HP1 * 0.9);
        }
    }
    checkEXP(EXP1, EXP1);
    checkHP(HP1, HP1);
    checkM(M1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxipoint[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        taxipoint[i][j] = (E3 * j + i * 2) * (i - j); 
    }
    int posnum = 0, negnum = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(taxipoint[i][j] < -E3)
            negnum++;
            if(taxipoint[i][j] > E3 * 2)
            posnum++;
        }
    }
    while(posnum > 9)
    {
        posnum = posnum / 10 + posnum % 10;
    }
    while(negnum > 9)
    {
        negnum = negnum / 10 + negnum % 10;
    }
    int taxi = taxipoint[posnum][negnum];
    int max = taxi;
    for(int i = posnum, j = negnum; i <= 9 && j <= 9; i++ && j++)
    {
        if(taxipoint[i][j] > max)
        max = taxipoint[i][j];
    }
    for(int i = posnum, j = negnum; i >=0 && j >= 0; i-- && j--)
    {
        if(taxipoint[i][j] > max)
        max = taxipoint[i][j];
    }
    for(int i = posnum, j = negnum; i <= 9 && j >= 0; i++ && j--)
    {
        if(taxipoint[i][j] > max)
        max = taxipoint[i][j];
    }
    for(int i = posnum, j = negnum; i >=0 && j <= 9; i-- && j++)
    {
        if(taxipoint[i][j] > max)
        max = taxipoint[i][j];
    }
    if(max < 0)
    max = abs(max);
    if(abs(taxi) > max)
    {
        EXP1 = ceil((double)EXP1 * 0.88);
        HP1 = ceil((double)HP1 * 0.9);
        EXP2 = ceil((double)EXP2 * 0.88);
        HP2 = ceil((double)HP2 * 0.9);
        return taxi;
    }
    else
    {
        EXP1 = ceil((double)EXP1 * 1.12);
        HP1 = ceil((double)HP1 * 1.1);
        EXP2 = ceil((double)EXP2 * 1.12);
        HP2 = ceil((double)HP2 * 1.1);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    size_t atPos = strchr(email, '@') - email;
    string se = string(email).substr(0, atPos);
    size_t length = strlen(s);
    if(length < 8)
    return -1;
    if(length > 20)
    return -2;
    size_t sePos = strstr(s, se.c_str()) - s;
    if (sePos != length) return -(300 + sePos);
    // Kiểm tra nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (size_t i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    bool SpeChar;
    const char speChar[] = {'@', '#', '%', '$', '!'};
    for (const char* p = s; *p; ++p) // trỏ tới vị trí nào đó trong chuỗi kí tự này
    {
        if (*p == '@' || *p == '#' || *p == '%' || *p == '$' || *p == '!') {
            SpeChar = true;
            break;
        }
    }
    if(!SpeChar) // toán tử phủ định mệnh đề đứng sau nó : "!"
    return -5;
    for (size_t i = 0; i < length; ++i) {
        if (!(isalnum(s[i]) || strchr(speChar, s[i]))) // Kiểm tra kí tự có thích hợp hay không
            return i;
    }
    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    int position = -1;

    for (int i = 0; i < num_pwds; ++i) 
    {
        const char* pwd = arr_pwds[i];
        int current_length = strlen(pwd);

        // Đếm số lần xuất hiện của mỗi mật khẩu
        int current_count = 1;
        for (int j = i + 1; j < num_pwds; ++j) 
        {
            if (strcmp(pwd, arr_pwds[j]) == 0) 
            {
                current_count++;
            }
        }
        // Cập nhật max_count và max_length nếu cần thiết
        if (current_count > max_count || (current_count == max_count && current_length > max_length)) {
            max_count = current_count;
            max_length = current_length;
            position = i;
        }
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////