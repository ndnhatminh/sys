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
void HPcheck(int &HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    else if (HP < 0)
    {
        HP = 0;
    }
}
void echeck(int &exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    else if (exp < 0)
    {
        exp = 0;
    }
}
void mcheck(int &money)
{
    if (money > 3000)
    {
        money = 3000;
    }
    else if (money < 0)
    {
        money = 0;
    }
}
double roundUp(double number) {
    if (abs(number - (int)number)<=10e-10)
        return number;
    else return (int)number + 1;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
    
    if (e1 < 0 || e1>99)
        return -99;
    
    if (e1 == 0)
    {
        exp2 = exp2 + 29;
        echeck(exp2);
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 =  roundUp((double)(exp1 + D / 200.0));
            echeck(exp1);
        }
        else if (D % 2 != 0)
        {
            exp1 =  roundUp((double)(exp1 - D / 100.0));
            echeck(exp1);
        }
    }
    if (e1 == 1)
    {
        exp2 = exp2 + 45;
        echeck(exp2);
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 =  roundUp((double)(exp1 + D / 200.0));
            echeck(exp1);
        }
        else if (D % 2 != 0)
        {
            exp1 = roundUp((double)(exp1 - D / 100.0));
            echeck(exp1);
        }
    }
    if (e1 == 2)
    {
        exp2 = exp2 + 75;
        echeck(exp2);
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 =  roundUp((double)(exp1 + D / 200.0));
            echeck(exp1);
        }
        else if (D % 2 != 0)
        {
            exp1 =  roundUp((double)(exp1 - D / 100.0));
            echeck(exp1);
        }
    }
    if (e1 == 3)
    {
        exp2 = exp2 + (29 + 45 + 75);
        echeck(exp2);
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 =  roundUp((double)(exp1 + D / 200.0));
            echeck(exp1);
        }
        else if (D % 2 != 0)
        {
            exp1 =  roundUp((double)(exp1 - D / 100.0));
            echeck(exp1);
        }
    }
 
   
    if (e1 > 3 && e1 < 20)
    {
        exp2 = exp2 + roundUp((double)(e1 / 4.0 + 19));
        echeck(exp2);
        exp1 = exp1 - e1;
        echeck(exp1);
    }
    if (e1 > 19 && e1 < 50)
    {
        exp2 = exp2 + roundUp((double)(e1 / 9.0 + 21));
        echeck(exp2);
        exp1 = exp1 - e1;
        echeck(exp1);
    }
    if (e1 > 49 && e1 < 66)
    {
        exp2 = exp2 + roundUp((double)(e1 / 16.0 + 17));
        echeck(exp2);
        exp1 = exp1 - e1;
        echeck(exp1);
    }
    if (e1 > 65 && e1 < 80)
    {
        exp2 = exp2 + roundUp((double)(e1 / 4.0 + 19));
        echeck(exp2);
        if (exp2 > 200)
        {
            exp2 = exp2 + roundUp((double)(e1 / 9.0 + 21));
            echeck(exp2);
        }
        exp1 = exp1 - e1;
        echeck(exp1);
    }
    if (e1 > 79 && e1 < 100)
    {
        exp2 = exp2 + roundUp((double)(e1 / 4.0 + 19));
        echeck(exp2);
        exp2 = exp2 + roundUp((double)(e1 / 9.0 + 21));
        echeck(exp2);
        if (exp2 > 400)
        {
            exp2 = exp2 + roundUp((double)(e1 / 16.0 + 17));
            echeck(exp2);
            exp2 = exp2 + roundUp((double)(exp2*0.15));
            echeck(exp2);
        }
        exp1 = exp1 - e1;
        echeck(exp1);
    }
    return exp1 + exp2;
}

int NearestSquare(int number) {
    int nearestLowerSqrt = sqrt(number); 
    int lowerSquare = nearestLowerSqrt * nearestLowerSqrt;
    int higherSquare = (nearestLowerSqrt + 1) * (nearestLowerSqrt + 1);

    if (abs(number - lowerSquare) <= abs(number - higherSquare)) {
        return lowerSquare;
    }
    else {
        return higherSquare;
    }
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // con duong 1
    echeck(EXP1);
    HPcheck(HP1);
    mcheck(M1);
    int S;
    double P1;
    if (E2 < 0 || E2>99) return -99;
     S = NearestSquare(EXP1);
        if (EXP1 >= S)
        {
            P1 = 1;
        }
        else P1 = (double)((EXP1 / S + 80) / 123.0);
    // con duong 2
        int T;
        T = M1;
        double P2;
        if (E2 % 2 != 0)
        {
            do
            {
                // Thuc an
                if (HP1 < 200)
                {
                    HP1 = roundUp((double)(1.30 * HP1));
                    HPcheck(HP1);
                    M1 = M1 - 150;
                    mcheck(M1);

                }
                else
                {
                    HP1 = roundUp((double)(1.10 * HP1));
                    HPcheck(HP1);
                    M1 = M1 - 70;
                    mcheck(M1);
                }
                if ((T - M1) > 0.5 * double(T))
                {
                    break;
                }
                // Xe ngua
                if (EXP1 < 400)
                {
                    M1 = M1 - 200;
                    mcheck(M1);
                }
                else
                {
                    M1 = M1 - 120;
                    mcheck(M1);
                }
                EXP1 = roundUp(double(EXP1 * 1.13));
                if ((T - M1) > 0.5 * double(T))
                {
                    break;
                }
                // Nguoi an xin
                if (EXP1 < 300)
                {
                    M1 = M1 - 100;
                    mcheck(M1);
                }
                else 
                {
                    M1 = M1 - 120;
                    mcheck(M1);
                }
                EXP1 = roundUp(double(EXP1 * 0.9));
                echeck(EXP1);
                if ((T - M1) > 0.5 * double(T))
                {
                    break;
                }
            } while (1);
        }
        else
        {
            do {
                // Thuc an
                if (HP1 < 200)
                {
                    HP1 = roundUp((double)(1.30 * HP1));
                    HPcheck(HP1);
                    M1 = M1 - 150;
                    mcheck(M1);

                }
                else
                {
                    HP1 = roundUp((double)(1.10 * HP1));
                    HPcheck(HP1);
                    M1 = M1 - 70;
                    mcheck(M1);
                }
                if (M1 == 0)
                {
                    break;
                }
                // Xe ngua
                if (EXP1 < 400)
                {
                    M1 = M1 - 200;
                    mcheck(M1);
                }
                else
                {
                    M1 = M1 - 120;
                    mcheck(M1);
                }
                EXP1 = roundUp(double(EXP1 * 1.13));
                if (M1 == 0)
                {
                    break;
                }
                // Nguoi an xin
                if (EXP1 < 300)
                {
                    M1 = M1 - 100;
                    mcheck(M1);
                }
                else
                {
                    M1 = M1 - 120;
                    mcheck(M1);
                }
                EXP1 = roundUp(double(EXP1 * 0.9));
                echeck(EXP1);
            } while (0);
        }
    HP1 = roundUp((double)(0.83 * HP1));
    HPcheck(HP1);
    EXP1 = roundUp(double(EXP1 * 1.17));
    echeck(EXP1);
    S = NearestSquare(EXP1);
    if (EXP1 >= S)
    {
        P2 = 1;
    }
    else P2 = (double)((EXP1 / S + 80) / 123.0);
    // con duong 3
    int i;
    double P;
    double P3[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
        if ( E2 < 10)
        {
            i = E2;
        }
        else
        {
            int donvi = E2 % 10;
            int chuc = E2 / 10;
            int tong = chuc + donvi;
            i = tong % 10;
        }
    
    if (P1 == P2 && P2 == P3[i] && P1==1)
    {
        EXP1 = roundUp(double(EXP1 * 0.75));
        echeck(EXP1);
    }
    else
    {
        P = (P1 + P2 + P3[i]) / 3.0;
        if (P < 0.5)
        {
            HP1 = roundUp(double(HP1) * 0.85);
            HPcheck(HP1);
            EXP1 = roundUp(double(EXP1) * 1.15);
            echeck(EXP1);
        }
        else
        {
            HP1 = roundUp(double(HP1) * 0.9);
            HPcheck(HP1);
            EXP1 = roundUp(double(EXP1) * 1.2);
            echeck(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

int sumOfDigits(int num) {
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    int cnt = 0, cnt1 = 0, taxi, sherlock, maxL = -9999, maxR = -9999;

    // gan gia tri cho taxi
    int a[10][10] = { {0} };
    for (int i = 0; i < 10; )
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);

        }
        i++;
    }
    // tim toa do 2 xe gap nhau
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > (E3 * 2))
                cnt++;
            else if (a[i][j] < (-1 * E3))
            {
                cnt1++;
            }

        }
    }
    cnt = sumOfDigits(cnt);
    cnt1 = sumOfDigits(cnt1);
    const int x = cnt;
    const int y = cnt1;

    taxi = a[cnt][cnt1];
    // tim max tren duong cheo trai cua diem co toa do (cnt;cnt1)
   // viet duoc mot doan code de tim max tren duong cheo trai cua ma tran 
    while (cnt < 10 && cnt1 >= 0)
    {
        if (a[cnt][cnt1] > maxL)
        {
            maxL = a[cnt][cnt1];
        }
        cnt++;
        cnt1--;
    }
    cnt = x;
    cnt1 = y;
    while (cnt >= 0 && cnt1 < 10)
    {
        if (a[cnt][cnt1] > maxL)
        {
            maxL = a[cnt][cnt1];
        }
        cnt--;
        cnt1++;
    }
    // code tim max tren duong cheo phai
    cnt = x;
    cnt1 = y;
    while (cnt >= 0 && cnt1 >= 0)
    {
        if (a[cnt][cnt1] > maxR)
        {
            maxR = a[cnt][cnt1];
        }
        cnt--;
        cnt1--;
    }
    cnt = x;
    cnt1 = y;
    while (cnt < 10 && cnt1 < 10)
    {
        if (a[cnt][cnt1] > maxR)
        {
            maxR = a[cnt][cnt1];
        }
        cnt++;
        cnt1++;
    }
    sherlock = max(maxR, maxL);
    if (abs(taxi) > sherlock)
    {
        HP1 = roundUp((double)(0.9 * HP1));
        HPcheck(HP1);
        EXP1 = roundUp(double(EXP1 * 0.88));
        echeck(EXP1);
        HP2 = roundUp((double)(0.9 * HP2));
        HPcheck(HP2);
        EXP2 = roundUp(double(EXP2 * 0.88));
        echeck(EXP2);
        return taxi;
    }
    else
    {
        HP1 = roundUp((double)(1.1 * HP1));
        HPcheck(HP1);
        EXP1 = roundUp(double(EXP1 * 1.12));
        echeck(EXP1);
        HP2 = roundUp((double)(1.1 * HP2));
        HPcheck(HP2);
        EXP2 = roundUp(double(EXP2 * 1.12));
        echeck(EXP2);
        return sherlock;

    }

}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string s1;
    string e1;
    s1 = string(s);
    e1 = string(email);
    string se;
    int cnt = 0;
    int sei;
    int sci;
    // xet do ngan cua mat khau
    if (s1.length() < 8) 
    {
        return -1;
    }
    // xet do dai cua mat khau
     if (s1.length() > 20) 
    {
        return -2;
    }
     //tim chuoi se
     for (int i = 0; i < e1.length(); i++)
     {
         if (e1[i] == '@')
         {
             se = e1.substr(0, i);
             break;
         }
     }
     size_t found = s1.find(se);
     // xet chuoi se co nam trong mat khau khong
     if (found != string::npos)
     {
         sei = found;
         return -(300 + sei);
     }
     // Xet 2+ ki tu giong nhau
     for (int i = 0; i + 2 < s1.length(); i++) {

         if (s1[i] == s1[i + 1] && s1[i] == s1[i + 2]) {
             sci = i;
             return -(400 + sci);
         }

     }
    // xet so ki tu dac biet
    for (int i = 0; i < s1.length(); i++) {
        if ((s1[i] == '@') || (s1[i] == '#') || (s1[i] == '%') || (s1[i] == '$') || (s1[i] == '!')) {
            cnt++;
        }
    }
    if (cnt == 0) {
        return -5;
    }
    if (s1.length() >= 8 && s1.length() <= 20) {
        for (int i = 0; i < s1.length(); i++) {
            if (!((s1[i] >= '0' && s1[i] <= '9') ||
                (s1[i] >= 'a' && s1[i] <= 'z') ||
                (s1[i] >= 'A' && s1[i] <= 'Z') ||
                (s1[i] == '@') ||
                (s1[i] == '#') ||
                (s1[i] == '%') ||
                (s1[i] == '$') ||
                (s1[i] == '!'))) {
                return i;
            }
        }
    }
    return -10;
}  
    // Task 5
int stringcheck(string string1 , string string2) {
    if (string1 == string2) {
        return 1;
    }
    else {
        return 0;
    }
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{

    int maxfrequency = 0, maxl = 0, returnindex = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        string S;
        S = string(arr_pwds[i]);
        int length = S.size();
        int fre = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (stringcheck(arr_pwds[i], arr_pwds[j]) == 1) fre++;
            if (fre > maxfrequency || (fre == maxfrequency && length > maxl))
            {
                maxfrequency = fre;
                maxl = length;
                returnindex = i;
            }
        }
    }
    return returnindex;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////