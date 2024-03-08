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

int checkHP(int& HP)                                    // HAM KIEM TRA dieu kien HP ...
{
    if (HP >= 0 && HP <= 666)
    {
        return HP;
    }
    else if (HP > 666)
    {
        return HP = 666;
    }
    else
        return HP = 0;

}

int checkEXP(int& exp)                                  // HAM KIEM TRA dieu kien EXP ...
{
    if (exp >= 0 && exp <= 600)
    {
        return exp;
    }
    else if (exp > 600)
    {
        return exp = 600;
    }
    else
        return exp = 0;

}
int checkM(int& m)                                         // HAM KIEM TRA dieu kien M ...
{
    if (m >= 0 && m <= 3000)
    {
        return m;
    }
    else if (m > 3000)
    {
        return m = 3000;
    }
    else
        return m = 0;

}
int roundNum(float n)                           // HAM LAM TRON LEN ... (vd: 363.0 --> 363 ; 363.3 --> 364)
{
    if (n - (int)n != 0)
    {
        return ceil(n);
    }
    else
    {
        return (int)n;
    }
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {

    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    else if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29;
            checkEXP(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            checkEXP(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            checkEXP(exp2);
        }
        else
        {
            exp2 += 149;
            checkEXP(exp2);
        }
        int D = e1 * 3 + exp1 * 7;
        (D % 2 == 0) ? (exp1 = roundNum(exp1 + D * 1.0 / 200)) : (exp1 = roundNum(exp1 - D * 1.0 / 100));
        checkEXP(exp1);
    }

    else if (e1 >= 4 && e1 <= 99)
    {
        float EXP1, EXP2;
        if (e1 >= 4 && e1 <= 19)
        {
            EXP2 = exp2 + (e1 * 1.0 / 4 + 19);
            exp2 = roundNum(EXP2); checkEXP(exp2);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            EXP2 = exp2 + (e1 * 1.0 / 9 + 21);
            exp2 = roundNum(EXP2);  checkEXP(exp2);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            EXP2 = exp2 + (e1 * 1.0 / 16 + 17);
            exp2 = roundNum(EXP2); checkEXP(exp2);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            EXP2 = exp2 + (e1 * 1.0 / 4 + 19);
            exp2 = roundNum(EXP2); checkEXP(exp2);
            if (exp2 > 200)
            {
                EXP2 = exp2 + (e1 * 1.0 / 9 + 21);
                exp2 = roundNum(EXP2); checkEXP(exp2);
            }
        }
        else
        {
            EXP2 = exp2 + (e1 * 1.0 / 4 + 19);
            exp2 = roundNum(EXP2); checkEXP(exp2);
            EXP2 = exp2 + (e1 * 1.0 / 9 + 21);
            exp2 = roundNum(EXP2); checkEXP(exp2);
            if (exp2 > 400)
            {
                EXP2 = exp2 + (e1 * 1.0 / 16 + 17);
                exp2 = roundNum(EXP2); checkEXP(exp2);
                EXP2 = exp2 * 1.15;
                exp2 = roundNum(EXP2); checkEXP(exp2);
            }
        }
        exp1 = roundNum(exp1 - e1); checkEXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2                 ***** DONE *****
int timchinhphuong(int n)                           // tim so chinh phuong gan EXP1 nhat ...
{
    int lower = pow(floor(sqrt(n)), 2);
    int upper = pow(ceil(sqrt(n)), 2);
    int S = ((abs(lower - n) < abs(upper - n)) ? lower : upper);
    return S;
}
void hanhdong1(int& HP1, int& EXP1, int& M1)
{
    double M0 = M1 / 2;                                 // 50% so tien ban dau ...
    int M = 0;                                          // so tien da chi tieu ...
    for (int i = 0; i < 1000; i++)  
    {
        if (HP1 < 200)
        {
            HP1 = roundNum(HP1 * 1.3); checkHP(HP1);
            M1 -= 150;
            if (M1 <= 0)
            {
                M1 = 0; break;
            }
            M += 150;
            if (M > M0) break;
        }
        else if (HP1 >= 200) 
        {        
            HP1 = roundNum(HP1 * 1.1); checkHP(HP1);
            M1 -= 70;
            if (M1 <= 0)
            {
                M1 = 0; break;
            }
            M += 70;
            if (M > M0) break;
        }
        if (EXP1 < 400)
        {
            M1 -= 200;
            EXP1 = roundNum(EXP1 * 1.13); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0; break;
            }
            M += 200;
            if (M > M0) break;
        }
        else if (EXP1>=400)
        {
            M1 -= 120;
            EXP1 = roundNum(EXP1 * 1.13); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0; break;
            }
            M += 120;
            if (M > M0) break;
        }

        if (EXP1 < 300)
        {
            M1 -= 100;
            EXP1 = roundNum(EXP1 * 0.9); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0; break;
            }
            M += 100;
            if (M > M0) break;
        }
        else if (EXP1 >= 300)
        {
            M1 -= 120;
            EXP1 = roundNum(EXP1 * 0.9); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0; break;
            }
            M += 120;
            if (M > M0) break;
        }
    }
    HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
    EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1);
}
void hanhdong2(int& HP1, int& EXP1, int& M1)
{
    for (int i = 1; i < 2; i++)
    {
        if (HP1 < 200)
        {
            HP1 = roundNum(HP1 * 1.3); checkHP(HP1);
            M1 -= 150;
            if (M1 <= 0)
            {
                M1 = 0;
                HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
                EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1); break;
            }
        }
        else if (HP1 >= 200)
        {
            HP1 = roundNum(HP1 * 1.1); checkHP(HP1);
            M1 -= 70;
            if (M1 <= 0)
            {
                M1 = 0;
                HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
                EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1); break;
            }
        }
        if (EXP1 < 400)
        {
            M1 -= 200;
            EXP1 = roundNum(EXP1 * 1.13); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0;
                HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
                EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1); break;
            }
        }
        else if (EXP1 >= 400)
        {
            M1 -= 120;
            EXP1 = roundNum(EXP1 * 1.13); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0;
                HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
                EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1); break;
            }
        }

        if (EXP1 < 300)
        {
            M1 -= 100;
            EXP1 = roundNum(EXP1 * 0.9); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0;
                HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
                EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1); break;
            }
        }
        else if (EXP1 >= 300)
        {
            M1 -= 120;
            EXP1 = roundNum(EXP1 * 0.9); checkEXP(EXP1);
            if (M1 <= 0)
            {
                M1 = 0;
                HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
                EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1); break;
            }
        }
        HP1 = roundNum(HP1 * 0.83); checkHP(HP1);
        EXP1 = roundNum(EXP1 * 1.17); checkEXP(EXP1);
    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    int S = timchinhphuong(EXP1);
    double P1 = (EXP1 >= S) ? 1 : (EXP1 * 1.0 / S + 80) / 123;
    P1 *= 100;
    if (E2 >= 0 && E2 <= 99)
    {
        if (E2 % 2 != 0)
        {
            hanhdong1(HP1, EXP1, M1);
        }
        else if (E2 % 2 == 0)
        {
            hanhdong2(HP1, EXP1, M1);
        }
    }
    else
    {
        return -99;
    }

    int S2 = timchinhphuong(EXP1);
    double P2 = (EXP1 >= S2) ? 1 : (EXP1 * 1.0 / S2 + 80) / 123;
    P2 *= 100;

    double P3;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 / 10 == 0)
    {
        P3 = P[E2];
    }
    else if ((E2 / 10) >= 1 && (E2 / 10) <= 9)
    {
        int sum = (E2 / 10) + (E2 % 10);
        P3 = P[sum % 10];
    }
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        checkHP(HP1);
        EXP1 = roundNum(EXP1 * 0.75); checkEXP(EXP1);
    }
    else
    {
        double P_avg = (P1 + P2 + P3) * 1.0 / 3;
        if (P_avg < 50) {
            HP1 = roundNum(HP1 * 0.85); checkHP(HP1);
            EXP1 = roundNum(EXP1 * 1.15); checkEXP(EXP1);
        }
        else if (P_avg >= 50)
        {
            HP1 = roundNum(HP1 * 0.9); checkHP(HP1);
            EXP1 = roundNum(EXP1 * 1.2); checkEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3

int countValues(int arr[10][10], int num, bool greater)         // HAM tim so gia tri trong matran lon hon hay nho hon "num" ...
{
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (greater && (arr[i][j] > num)) {
                count++;
            }
            else if (!greater && (arr[i][j] < num)) {
                count++;
            }
        }
    }
    return count;
}
int sumDigits(int num)                          // HAM tim tong cac chu so cua mot so ...
{
    int sum = 0;
    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int sumNumbers(int num)                         // HAM tim tong cac chu so cho den khi chi con 1 CHU SO ...
{
    while (num > 9) 
    {
        num = sumDigits(num);
    }
    return num;
}
int findMax(int arr[10][10], int x, int y)                     // HAM tim GTLN trong 2 duong cheo trai va phai ...
{
    int maxVal = arr[x][y];

    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) 
    {
        maxVal = max(maxVal, arr[i][j]);
    }
    for (int i = x + 1, j = y + 1; i < 10 && j < 10; i++, j++) 
    {
        maxVal = max(maxVal, arr[i][j]);
    }

    for (int i = x - 1, j = y + 1; i >= 0 && j < 10; i--, j++) 
    {
        maxVal = max(maxVal, arr[i][j]);
    }
    for (int i = x + 1, j = y - 1; i < 10 && j >= 0; i++, j--) 
    {
        maxVal = max(maxVal, arr[i][j]);
    }
    return maxVal;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) 
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    else
    {
        int arr[10][10];
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                arr[i][j] = (2 * i + E3 * j) * (i - j);
            }
        }
        int greaterCount = countValues(arr, E3 * 2, true);
        int lesserCount = countValues(arr, -E3, false);
        int TaxiPoints = abs(arr[sumNumbers(greaterCount)][sumNumbers(lesserCount)]);
        int SherlockPoints = abs(findMax(arr, sumNumbers(greaterCount), sumNumbers(lesserCount)));
        if (TaxiPoints > SherlockPoints)
        {
            EXP1 = roundNum(0.88 * EXP1); checkEXP(EXP1);
            HP1 = roundNum(HP1 * 0.9); checkHP(HP1);
            EXP2 = roundNum(0.88 * EXP2); checkEXP(EXP2);
            HP2 = roundNum(HP2 * 0.9); checkHP(HP2);
        }
        else
        {
            EXP1 = roundNum(EXP1 * 1.12); checkEXP(EXP1);
            HP1 = roundNum(HP1 * 1.1); checkHP(HP1);
            EXP2 = roundNum(EXP2 * 1.12); checkEXP(EXP2);
            HP2 = roundNum(HP2 * 1.1); checkHP(HP2);
        }
        if (TaxiPoints > SherlockPoints)
        {
            return arr[sumNumbers(greaterCount)][sumNumbers(lesserCount)];
        }
        else
            return findMax(arr, sumNumbers(greaterCount), sumNumbers(lesserCount));
    }
    
}

// Task 4       ***** DONE *****

int checkPassword(const char* s, const char* email)
{
    int seiLength = 0;
    while (email[seiLength] != '@') 
    {
        ++seiLength;                            // do dai chuoi "se" ...
    }

    char se[1000];
    for (int i = 0; i < seiLength; i++)        // lay chuoi "se" truoc "@" trong email ...
    {
        se[i] = email[i];                      // khi nay co: se[seiLength] = '\0';
    }                                       

    int sLength = strlen(s);

    int numSpeChars = 0;
    const char SpeChars[] = "@#%$!";
    for (int i = 0; i < sLength; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[i] == SpeChars[j]) {
                numSpeChars++;              // tim truoc so ky tu dac biet trong mat khau s ...
                break;
            }
        }
    }

    if (sLength < 8) return -1;             // nho hon toi thieu thi return -1 ...
    if (sLength > 20) return -2;            // lon hon toi da thi return -2 ...
    if (sLength >= 8 && sLength <= 20)
    {
        if (seiLength == 0) return -300;        // FIRSTLY, kiem tra do dai chuoi "se" truoc ...
        else if (seiLength != 0)
        {
            for (int i = 0; i < sLength - (seiLength - 1); i++) {
                if (strncmp(&s[i], se, seiLength) == 0)
                {
                    return -(300 + i);
                    break;
                }
            }
        }

        for (int i = 0; i < sLength - 2; i++)   // SECONDLY, kiem tra >=3 ky tu lien tiep nhau ...
        { 
            if (s[i + 1] == s[i] && s[i + 1] == s[i + 2])
            {
                return -(400 + i);
            }
        }

        if (numSpeChars == 0) return -5;        // Sau khi kiem tra 2 cai tren roi kiem tra Ky tu Dac Biet ...
        else if (numSpeChars != 0)
        {
            for (int i = 0; i < sLength; i++) {
                if (!(isalnum(s[i]) || s[i] == ' ' || strchr(SpeChars, s[i])))
                {
                    return i;       // Cac truong hop vi pham con lai khac thi tra ve VI TRI BAN DAU KY TU tao loi ...
                }
            }
        }
    }
    return -10;
}

// Task 5         ***** DONE *****
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
                                            // yeu cau tim vi tri dau tien cua mat khau dai nhat trong so cac mat khau xuat hien nhieu nhat
    int maxCount = 0, maxLength = 0;        
    int x = -99;      // vi tri dau tien xuat hien (Neu ko thoa thi tra ve -99...)
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;        // tinh so lan xuat hien cac MK giong nhau
            }
        }
        if ((count > maxCount) || (count == maxCount && strlen(arr_pwds[i]) > maxLength))
        {
            maxCount = count;       // xuat hien nhieu nhat
            maxLength = strlen(arr_pwds[i]);        // do dai lon nhat
            x = i;
        }
    }
    return x;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////