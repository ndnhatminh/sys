
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
) 
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) 
    {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else 
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////


   // Check limit
int limit(int n, int min, int max)
{
    if (n < min) n = min;
    if (n > max) n = max;
    return n;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) 
{
    // TODO: Complete this function

    //Check E1
    if (e1 < 0 || e1>99) return -99;
    exp1 = limit(exp1, 0, 600);
    exp2 = limit(exp2, 0, 600);
    
    //Case 1: In the case of E1 inrange [0, 3]
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0) exp2 = exp2 + 29;
        else if (e1 == 1) exp2 = exp2 + 45;
        else if (e1 == 2) exp2 = exp2 + 75;
        else if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;

        exp2 = limit(exp2, 0, 600);

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 += ceil((float)D / 200);
        else exp1 = ceil(exp1 - (float)D / 100);
        
        exp1 = limit(exp1, 0, 600);
    }
    
    //Case 2: In case that E1 is in the range of [4,99]
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += ceil((float)e1 / 4 + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 += ceil((float)e1 / 9 + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += ceil((float)e1 / 16 + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += ceil((float)e1 / 4 + 19);
            exp2 = limit(exp2, 0, 600);
            if (exp2 > 200) exp2 += ceil((float)e1 / 9 + 21);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += ceil((float)e1 / 4 + 19);
            exp2 = limit(exp2, 0, 600);
            exp2 += ceil((float)e1 / 9 + 21);
            exp2 = limit(exp2, 0, 600);
            if (exp2 > 400)
            {
                exp2 += ceil((float)e1 / 16 + 17);
                exp2 = limit(exp2, 0, 600);
                exp2 = ceil((float)exp2 * 1.15);
            }
        }
        exp2 = limit(exp2, 0, 600);
        exp1 -= e1;
        exp1 = limit(exp1, 0, 600);
    }
    return exp1 + exp2;
}

// Task 2
   // Kiem tra so nguyen n có phai là so chinh phuong
bool soCP(int n) {
    int i = 0;
    while (i * i <= n) {
        if (i * i == n) {
            return true;
        }
        ++i;
    }
    return false;
}
   // Tim so chinh phuong gan nhat cua so nguyen n 
int scpgn(int n)
{
    int i = 0;
    while (1)
    {
        if (soCP(n - i)) return n - i;
        if (soCP(n + i)) return n + i;
        i++;
    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    // TODO: Complete this function

    // Check E2 and check limit
    if (E2 < 0 || E2>99) return -99;
    EXP1 = limit(EXP1, 0, 600);
    HP1 = limit(HP1, 0, 666);
    M1 = limit(M1, 0, 3000);

  // Road 01 
    int S = scpgn(EXP1);
    float P1;
    if (EXP1 >= S) P1 = 1;
    else
    {
        float t = (float)EXP1 / (float)S + 80;
        P1 = t / 123;
    }
    
  // Road 02
    int Action1(int& HP1, int& M1)
    {
        if (HP1 < 200)
        {
            float t = (float)HP1 * 1.3;
            HP1 = ceil(t);
            M1 -= 150;
        }
        else
        {
            float t = (float)HP1 * 1.1;
            HP1 = ceil(t);
            M1 -= 70;
        }
        M1 = limit(M1, 0, 3000);
        HP1 = limit(HP1, 0, 666);
        return HP1, M1;
    }
    int Action2(int& EXP1, int& M1)
    {
        if (EXP1 < 400)
        {
            float t = (float)EXP1 * 1.13;
            EXP1 = ceil(t);
            M1 -= 200;
        }
        else
        {
            float t = (float)EXP1 * 1.13;
            EXP1 = ceil(t);
            M1 = M1 - 120;
        }
        M1 = limit(M1, 0, 3000);
        EXP1 = limit(EXP1, 0, 600);
        return EXP1, M1;
    }
    int Action3(int& EXP1, int& M1)
    {
        if (EXP1 < 300)
        {
            M1 -= 100;
        }
        else
        {
            M1 -= 120;

        }
        float t = (float)EXP1 * 0.9;
        EXP1 = ceil(t);
        M1 = limit(M1, 0, 3000);
        EXP1 = limit(EXP1, 0, 600);
        return EXP1, M1;
    }

    int M0 = M1; // M0 la so tien ban dau cua Sherlock
    while (E2 % 2 != 0)
    {
        Action1(HP1, M1);
        if ((M0 - M1) >= (0.5 * M0)) break;

        Action2(EXP1, M1);
        if ((M0 - M1) >= (0.5 * M0)) break;
        
        Action3(EXP1, M1);
        if ((M0 - M1) >= (0.5 * M0)) break;
    }
    if (E2 % 2 == 0)
    {
        if (M1 != 0)
        {
            Action1(HP1, M1);
        }
        if (M1 != 0)
        {
            Action2(EXP1, M1);
        }
        if (M1 != 0)
        {
            Action3(EXP1, M1);
        }
    }

    // Cap nhat EXP1 va HP1 o cuoi con duong
    float t = (float)HP1 * 0.83;
    HP1 = ceil(t);
    HP1 = limit(HP1, 0, 666);
    t = (float)EXP1 * 1.17;
    EXP1 = ceil(t);
    EXP1 = limit(EXP1, 0, 600);

    // Tim P2
    int S2 = scpgn(EXP1);
    float P2, Ptb;
    if (EXP1 >= S2) P2 = 1;
    else P2 = ((float)EXP1 / (float)S2 + 80) / 123;
    
  // Road 03
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    float P3;
    if (E2 / 10 == 0)  P3 = (float)P[E2] / 100;
    else if (E2 / 10 != 0)
    {
        int n = E2 % 10 + E2 / 10;
        n = n % 10;
        P3 = (float)P[n] / 100;
    }

    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        float t = (float)EXP1 * 0.75;
        EXP1 = ceil(t);
    }
    else
    {
        Ptb = (P1 + P2 + P3) / 3;
        if (Ptb < 0.5)
        {
            float t = (float)HP1 * 0.85;
            HP1 = ceil(t);
            HP1 = limit(HP1, 0, 666);
            t = (float)EXP1 * 1.15;
            EXP1 = ceil(t);
            EXP1 = limit(EXP1, 0, 600);
        }
        else
        {
            float t = (float)HP1 * 0.9;
            HP1 = ceil(t);
            HP1 = limit(HP1, 0, 666);
            t = (float)EXP1 * 1.2;
            EXP1 = ceil(t);
            EXP1 = limit(EXP1, 0, 600);
        }
    }
    EXP1 = limit(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}

// Task 3
int cong2chuso(int n) // Cong 2 chu so cho den khi con 1 chu so
{
    n = n % 10 + n / 10;
    n = n % 10 + n / 10;
    return n;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    float t;
    // TODO: Complete this function
    
    // Check E3 and check limit
    if (E3 < 0 || E3>99) return -99;
    EXP1 = limit(EXP1, 0, 600);
    HP1 = limit(HP1, 0, 666);
    EXP2 = limit(EXP2, 0, 600);
    HP2 = limit(HP2, 0, 666);

    // Khoi tao ma tran
    int M[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            M[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tim toa do taxi gap Sherlock va Watson: (r,c)
    int r = 0, c = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (M[i][j] > E3 * 2) r++;
            if (M[i][j] < -1 * E3) c++;
        }

    }
    r = cong2chuso(r);
    c = cong2chuso(c);

    // Tim diem cua Sherlock va Watson tai diem gap taxi: max
    int max = M[r][c];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i - j == r - c && M[i][j] > max) max = M[i][j];
            if (i + j == r + c && M[i][j] > max) max = M[i][j];
        }

    }
    max = abs(max);

    // Cap nhat EXP va HP cua Sherlock va Watson va tra ve ket qua
    if (abs(M[r][c]) > max)
    {
        t = (float)EXP1 * 0.88;
        EXP1 = ceil(t);
        t = (float)EXP2 * 0.88;
        EXP2 = ceil(t);
        t = (float)HP1 * 0.9;
        HP1 = ceil(t);
        t = (float)HP2 * 0.9;
        HP2 = ceil(t);
        // Check limit
        EXP1 = limit(EXP1, 0, 600);
        HP1 = limit(HP1, 0, 666);
        EXP2 = limit(EXP2, 0, 600);
        HP2 = limit(HP2, 0, 666);
        return M[r][c]; // Tra ve diem cua taxi
    }
    else
    {
        t = (float)EXP1 * 1.12;
        EXP1 = ceil(t);
        t = (float)EXP2 * 1.12;
        EXP2 = ceil(t);
        t = (float)HP1 * 1.1;
        HP1 = ceil(t);
        t = (float)HP2 * 1.1;
        HP2 = ceil(t);
        // Check limit
        EXP1 = limit(EXP1, 0, 600);
        HP1 = limit(HP1, 0, 666);
        EXP2 = limit(EXP2, 0, 600);
        HP2 = limit(HP2, 0, 666);
        return max;
    }

}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    string s1(s);
    string email1(email);

    // Yêu cầu hợp lệ của mật khẩu
    const int minLength = 8;
    const int maxLength = 20;

    // Lấy chuỗi trước ký tự '@' trong email
    string se = email1.substr(0, email1.find('@'));

    // Kiểm tra độ dài mật khẩu
    if (s1.length() < minLength) return -1;
    if (s1.length() > maxLength) return -2;

    // Kiểm tra mật khẩu có chứa chuỗi se hay không
    int sei = s1.find(se);
    if (sei != string::npos) return -(300 + sei);

    // Kiểm tra mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    for (int i = 0; i < s1.length() - 2; i++) {
        if (s1[i] == s1[i + 1] && s1[i] == s1[i + 2]) return -(400 + i);
    }

    // Kiểm tra mật khẩu có chứa ít nhất 1 ký tự đặc biệt
    bool check = false;
    for (int i = 0; i < s1.length(); i++)
    {
        char c = s1[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
        {
            check = true;
            break;
        }
    }
    if (!check) return -5;

    //Kiểm tra từng kí tự trong mật khẩu
    for (int i = 0; i < s1.length(); i++)
    {
        char c = s1[i];
        if (!(isalnum(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))
        {
            return i;
        }
    }

    // Mật khẩu hợp lệ
    return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    // TODO: Complete this function

    pair<string, int>* p = new pair<string, int>[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        p[i].first = string(arr_pwds[i]);
        p[i].second = 0;
    }
    int max = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        int dem = 0;
        for (int j = i; j < num_pwds; j++)
        {
            if (p[j].first == p[i].first)
            {
                p[i].second++;
            }
        }
        if (p[i].second > max) max = p[i].second;
    }
    int maxlength = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (p[i].second == max)
        {
            if (p[i].first.length() > maxlength) maxlength = p[i].first.length();
        }
    }
    int k;
    for (int i = 0; i < num_pwds; i++)
    {
        if (p[i].second == max && p[i].first.length() == maxlength)
        {
            k = i;
            break;
        }
    }
    return k;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////