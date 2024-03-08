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
void checkEXP(int& EXP)
{
    if(EXP > 600) EXP = 600;
    if(EXP < 0) EXP = 0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    if(e1 >= 0 && e1 <= 3)
    {
        if(e1 == 0) exp2 += 29;
        else if(e1 == 1) exp2 += 45;
        else if(e1 == 2) exp2 += 75;
        else if(e1 == 3) exp2 += 149;
        int D = 0;
        D = e1 * 3 + exp1 * 7;
        if(D % 2 == 0) exp1 = ceil(exp1 * 1.0 + D / 200.0);
        else exp1 = ceil(exp1 * 1.0 - D / 100.0);
    }
    else if(e1 >= 4 && e1 <= 99)
    {
        if(e1 <= 19) exp2 = ceil(exp2 * 1.0 + e1 / 4.0 + 19);
        else if(e1 <= 49) exp2 = ceil(exp2 * 1.0 + e1 / 9.0 + 21);
        else if(e1 <= 65) exp2 = ceil(exp2 * 1.0 + e1 / 16.0 + 17);
        else if(e1 <= 79)
        {
            exp2 = ceil(exp2 * 1.0 + e1 / 4.0 + 19);
            if(exp2 > 200)
            {
                exp2 = ceil(exp2 * 1.0 + e1 / 9.0 + 21);
            }
        }
        else if(e1 <= 99)
        {
            exp2 = ceil(exp2 * 1.0 + e1 / 4.0 + 19);
            exp2 = ceil(exp2 * 1.0 + e1 / 9.0 + 21);
            if(exp2 > 400)
            {
                exp2 = exp2 = ceil(exp2 * 1.0 + e1 / 16.0 + 17);
                exp2 = ceil(exp2 * 1.0 + exp2 * 15 / 100.0);
            }
        }
        exp1 -= e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
bool checkSquareNum(int x)
{
    int a = sqrt(x);
    if(a * a == x) return true;
    else return false;
}

float findP(int EXP1)
{
    int tmp1 = EXP1;
    int tmp2 = EXP1;
    float P1 = 0;
    while(!checkSquareNum(tmp1))
    {
        tmp1--;
    }
    while(!checkSquareNum(tmp2))
    {
        tmp2++;
    }
    int s = 0;
    if(abs(tmp1 - EXP1) >= abs(tmp2 - EXP1)) s = tmp2;
    else s = tmp1;
    if(EXP1 >= s) P1 = 1;
    else P1 = ((float)EXP1 / s * 1.0 + 80 * 1.0) / 123.0;
    return P1 * 100;
}

void checkHP(int& HP)
{
    if(HP > 666) HP = 666;
    if(HP < 0) HP = 0;
}

float findP3(int P[], int E2)
{
    if(E2 % 10 == E2) return P[E2];
    else return P[(E2 % 10 + E2 / 10) % 10];
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 > 99 || E2 < 0) return -99;
    if(M1 > 3000) M1 = 3000;
    if(M1 < 0) M1 = 0;
    checkHP(HP1);
    float P1 = findP(EXP1);
    float halfPremoney = M1 / 2.0;
    int MonSpent = 0;
    if(M1 > 0)
    {
    if(E2 % 2 == 1)
    {
        while(MonSpent < halfPremoney)
        {
            if(HP1 < 200 && MonSpent <= halfPremoney)
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                checkHP(HP1);
                MonSpent += 150;
            }
            else if(HP1 >= 200 && MonSpent <= halfPremoney)
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                checkHP(HP1);
                MonSpent += 70;
            }
            if(EXP1 < 400 && MonSpent <= halfPremoney)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                MonSpent += 200;
            }
            else if(EXP1 >= 400 && MonSpent <= halfPremoney)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                MonSpent += 120;
            }
            if(EXP1 < 300 && MonSpent <= halfPremoney )
            {
                MonSpent += 100;
                EXP1 = ceil(EXP1 * 90.0 / 100);
                checkEXP(EXP1);
            }
            else if(EXP1 >= 300 && MonSpent <= halfPremoney)
            {
                MonSpent += 120;
                EXP1 = ceil(EXP1 * 90.0 / 100);
                checkEXP(EXP1);
            }
        }
        HP1 = ceil(HP1 * 83.0 / 100);
        checkHP(HP1);
        EXP1 = ceil(EXP1 * 117.0 / 100);
        checkEXP(EXP1);
    }
    else
    {
        for(int i = 1; i <= 3; i++)
        {
            if(i == 1)
            {
                if(HP1 < 200)
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                checkHP(HP1);
                MonSpent += 150;
            }
            else if(HP1 >= 200)
            {
                HP1 = ceil(HP1 * 110.0 / 100);
                checkHP(HP1);
                MonSpent += 70;
            }
            }
            else if(i == 2)
            {
                if(EXP1 < 400)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                MonSpent += 200;
            }
            else if(EXP1 >= 400)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                checkEXP(EXP1);
                MonSpent += 120;
            }
            }
            else if(i == 3)
            {
                if(EXP1 < 300) MonSpent += 100;
                else MonSpent += 120;
                EXP1 = ceil(EXP1 * 90.0 / 100);
            }
            if(M1 - MonSpent < 0) break;
         }
        HP1 = ceil(HP1 * 83.0 / 100);
        checkHP(HP1);
        EXP1 = ceil(EXP1 * 117.0 / 100);
        checkEXP(EXP1);
    }
    }
    else 
    {
        HP1 = ceil(HP1 * 83.0 / 100);
        checkHP(HP1);
        EXP1 = ceil(EXP1 * 117.0 / 100);
        checkEXP(EXP1);
    }
    float P2 = findP(EXP1);
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3 = findP3(P, E2);
    if(P3 == 100 && P1 == 100 && P2 == 100)
    {
        EXP1 = ceil(EXP1 * 75.0 / 100);
        checkEXP(EXP1);
    }
    else
    {
        float AVR = (P1 + P2 + P3) / 3;
        if(AVR < 50)
        {
            HP1 = ceil(HP1 * 85.0 / 100);
            checkHP(HP1);
            EXP1 = ceil(EXP1 * 115.0 / 100);
            checkEXP(EXP1);
        }
        else
        {
            HP1 = ceil(HP1 * 90.0 / 100);
            checkHP(HP1);
            EXP1 = ceil(EXP1 * 120.0 / 100);
            checkEXP(EXP1);
        }
    }
    M1 = M1 - MonSpent;
    if(M1 < 0) M1 = 0;
    if(M1 > 3000) M1 = 3000;
    checkHP(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int MOD = 1e9 + 7;
int f[100];

int rutgon(int x)
{
    int n = x;
    while(n >= 10)
    {
        n = n % 10 + n / 10;
    }
    return n;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 > 99 || E3 < 0) return -99;
    int a[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int demDuong = 0;
    int demAm = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(a[i][j] > E3 * 2) demDuong++;
            if(a[i][j] < (-E3)) demAm++;
        }
    }
    int x = 0;
    int y = 0;
    int cnt = 0;
    x = rutgon(demDuong);
    y = rutgon(demAm);
    for(int k = 0; k < 4; k++)
    {
    int i = x, j = y;
    if(k == 0)
        {
            while(i <= 9 && j <= 9)
            {
                f[cnt] = a[i][j];
                i++; j++;
                cnt++;
            }
        }
        else if(k == 1)
        {
            while(i >= 0 && j >= 0)
            {
                f[cnt] = a[i][j];
                i--; j--;
                cnt++;
            }
        }
        else if(k == 2)
        {
            while(i <= 9 && j >= 0)
            {
                f[cnt] = a[i][j];
                cnt++;
                i++; j--;
            }
        }
        else if(k == 3)
        {
            while(j <= 9 && i >= 0)
            {
                f[cnt] = a[i][j];
                cnt++;
                j++; i--;
            }
        }
    }
    int max_val = -MOD;
    for(int i = 0; i < cnt; i++)
    {
        if(f[i] > max_val)
        {
            max_val = f[i];
        }
    }
    if(abs(a[x][y]) > max_val) 
    {
         EXP1 = ceil(EXP1 * 88.0 / 100);
         EXP2 = ceil(EXP2 * 88.0 / 100);
         HP1 = ceil(HP1 * 90.0 / 100);
         HP2 = ceil(HP2 * 90.0 / 100);
         checkEXP(EXP1);
         checkEXP(EXP2);
         checkHP(HP1);
         checkHP(HP2);
        return a[x][y];
    }
    else 
    {
        EXP1 = ceil(EXP1 * 112.0 / 100);
        EXP2 = ceil(EXP2 * 112.0 / 100);
        HP1 = ceil(HP1 * 110.0 / 100);
        HP2 = ceil(HP2 * 110.0 / 100);
         checkEXP(EXP1);
         checkEXP(EXP2);
         checkHP(HP1);
         checkHP(HP2);
        return max_val;
    }
    return -1;
}

// Task 4
int checkSpe(string s)
{
    int dem = 0;
    for(char x : s)
    {
        if(x == '@' || x == '#' || x == '%' || x == '$' || x == '!') dem++;
    }
    return dem;
}

int checkLienTiep(string s)
{
    int l = 0;
    int dem = 0;
    for(int i = 0; i < s.size() - 2; i++)
    {
        if(s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return i;
    }
    return -1;
}

int checkOther(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        if(!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') return i;
    }
    return -1;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string tmp = email;
    string se = "";
    for(char x : tmp)
    {
        if(x != '@')
        se += x;
        else break;
    }
    string tmp_s = s;
    if((int)tmp_s.size() < 8) return -1;
    if((int)tmp_s.size() > 20) return -2;
    if(tmp_s.find(se) != string::npos) return -(300 + (int)tmp_s.find(se));
    if(checkLienTiep(tmp_s) != -1) return -(400 + checkLienTiep(tmp_s));
    if(checkSpe(tmp_s) == 0) return -5;
    if(checkOther(tmp_s) != -1) return checkOther(tmp_s);
    else return -10;
    return -99;
}

// Task 5
string s[100];
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    for(int i = 0; i < num_pwds; i++)
    {
        s[i] = arr_pwds[i];
    }
    int index = 0;
    int dem = 0;
    int length = 0;
    int tmp_len = 0;
    for(int i = 0; i < num_pwds; i++)
    {
        int res = 0;
        int tmp_len = 0;
        for(int j = i; j < num_pwds; j++)
        {
            if(s[i] == s[j])
            {
                tmp_len = (int)s[i].size();
                res++;
            }
        }
        if(res > dem)
        {
            index = i;
            dem = res;
            length = tmp_len;
        }
        else if(res == dem)
        {
            if(tmp_len > length)
            {
                index = i;
                length = tmp_len;
                dem = res;
            }
        }
    }
    return index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////