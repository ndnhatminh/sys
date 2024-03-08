#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
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

//! Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99) return -99;
    resetexp(exp1);
    resetexp(exp2);
    if (e1 >= 0 && e1 <= 3) // case1
    {
        if (e1 == 0)
        {
            addExp(exp2, 29);
        }
        else if (e1 == 1)
        {
            addExp(exp2, 45);
        }
        else if (e1 == 2)
        {
            addExp(exp2, 75);
        }
        else if (e1 == 3)
        {
            addExp(exp2, 29 + 45 + 75);
        }
        int d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0)
            addExp(exp1, d / 200.0);
        else
            subExp(exp1, d / 100.0);
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 <= 19)
            addExp(exp2, double(e1 / 4.0) + 19);
        else if (e1 <= 49)
            addExp(exp2, double(e1 / 9.0) + 21);
        else if (e1 <= 65)
            addExp(exp2, double(e1 / 16.0) + 17);
        else if (e1 <= 79)
        {
            addExp(exp2, double(e1 / 4.0) + 19);
            if (exp2 > 200)
                addExp(exp2, double(e1 / 9.0) + 21);
        }
        else
        {
            addExp(exp2, double(e1 / 4.0) + 19);
            addExp(exp2, double(e1 / 9.0) + 21);
            if (exp2 > 400)
            {
                addExp(exp2, double(e1 / 16.0) + 17);
                addExp(exp2, double(exp2 * 15.0 / 100.0));
            }
        }
        subExp(exp1, e1);
    }
    return exp1 + exp2;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 > 99 || E2 < 0)
        return -99;
    resetHP(HP1);
    resetexp(EXP1);
    resetM(M1);
    //road1
    double P1 = 0;
    int sq = getsquareNum(EXP1);
    if (EXP1 >= sq) P1 = 1.0;
    else
    P1 = (EXP1 * 1.0 /sq + 80)/123.0;
    //road2
    if (M1 == 0) goto end;
    if (E2 % 2 == 0)
    {
        if (HP1 < 200)
        {
            changeTimes(HP1, 0.3, 666);
            subMoney(M1, 150);
        }
        else
        {
            changeTimes(HP1, 0.1, 666);
            subMoney(M1, 70);

        }
        if (M1 == 0) goto end;
        if (EXP1 < 400)
        {
            subMoney(M1, 200);
            changeTimes(EXP1, 0.13, 600);
        }
        else
        {
            subMoney(M1, 120);
            changeTimes(EXP1, 0.13, 600);
        }
        if (M1 == 0) goto end;
        if (EXP1 < 300)
        {
            subMoney(M1, 100);
            changeTimes(EXP1, -0.1, 600);
        }
        else {
            subMoney(M1, 120);
            changeTimes(EXP1, -0.1, 600);
        }
        if (M1 == 0) goto end;
    }
    else
    {
        int moneySaved = ceil (M1/2);
        again:
        if (HP1 < 200)
        {
            changeTimes(HP1, 0.3, 666);
            subMoney(M1, 150);
        }
        else
        {
            changeTimes(HP1, 0.1, 666);
            subMoney(M1, 70);

        }

        if (M1 == 0) goto end;
        if (M1 < moneySaved) goto end;
        if (EXP1 < 400)
        {
            subMoney(M1, 200);
            changeTimes(EXP1, 0.13, 600);
        }
        else
        {
            subMoney(M1, 120);
            changeTimes(EXP1, 0.13, 600);
        }

        if (M1 == 0) goto end;
            if (M1 < moneySaved) goto end;
        if (EXP1 < 300)
        {
            subMoney(M1, 100);
            changeTimes(EXP1, -0.1, 600);
        }
        else {
            subMoney(M1, 120);
            changeTimes(EXP1, -0.1, 600);
        }

        if (M1 == 0) goto end;
        if (M1 < moneySaved) goto end;
        goto again;
    }
    end:
    changeTimes(HP1,-0.17, 666);
    changeTimes(EXP1, 0.17, 600);

    double P2 = 0;
    sq = getsquareNum(EXP1);
    if (EXP1 >= sq) P2 = 1.0;
    else
        P2 = (EXP1 * 1.0 /sq + 80)/123.0;

    //road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int pos = getPi(E2);
    double P3 = P[pos]/100.0;
    if(P1 == 1 && P2 == 1 && P3 == 1 )
        changeTimes(EXP1, -0.25, 600);
    else
    {
        double res = (P1 + P2 + P3)/3.0;
        if (res < 0.5)
        {
            changeTimes(EXP1,0.15, 600);
            changeTimes(HP1,-0.15, 666);
        }
        else
        {
            changeTimes(EXP1,0.2, 600);
            changeTimes(HP1,-0.1, 666);
        }
    }

    return HP1 + EXP1 + M1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) return -99;
    int **Taximatrix = new int *[10];
    for (int i = 0; i < 10; ++i)
        Taximatrix[i] = new int[10]();
    //apply to taxi matrix
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        Taximatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
    }
    //watson + sherlock
    //vtri gap nhau
    int x = sumsum(countPositive(Taximatrix, E3));
    int y = sumsum(countNegative(Taximatrix, E3));
    int taxival = abs(Taximatrix[x][y]);
    int high = getHighest(Taximatrix, x, y);
    if (taxival <= high)
    {
        addExp(EXP1,EXP1*0.12);
        addExp(EXP2,EXP2*0.12);
        addHP(HP1, HP1*0.1);
        addHP(HP2, HP2*0.1);
        return high;
    }
    else
    {
        subExp(EXP1,EXP1*0.12);
        subExp(EXP2,EXP2*0.12);
        subHP(HP1, HP1*0.1);
        subHP(HP2, HP2*0.1);
        return Taximatrix[x][y];
    }
    return -1;
}
void increase(int &obj, double times, int max)
{
    if (double(obj * times) - int(obj * times) > 0)
    {
        obj = int(obj * (1 + times)) + 1;
        if (obj > max) obj = max;
    }
    else
    {
        obj = int(obj * (1 + times));
        if (obj > max) obj = max;
    }
}

int checkPassword(const char *s, const char *email)
{
    int len = strlen(s);
    if (len < 8)
        return -1;
    else if (len > 20)
        return -2;
    string pass(s);
    string mail(email);
    mail = mail.substr(0, mail.find('@'));
    if (pass.find(mail) != string::npos) //found
    return -(300 + pass.find(mail));
    //check ky tu lien tiep
    bool  flag = false;
    for (int i = 0; i < len - 1 ; i++)
    {
        if (s[i] == s[i+1])
        {
            if (flag) return -(400 + i - 1);
            flag = true;
        }
        else
        flag = false;
    }
    //khong chua ky tu dac biet
    if (pass.find('@') == string::npos && pass.find('#') == string::npos&& pass.find('!') == string::npos&& pass.find('$') == string::npos&& pass.find('%') == string::npos)
    return -5;

    for (int i = 0; i < len; i++)
    {
        if  (!isalnum(s[i]) && !is_Scharacter(s[i]))
        return i;
    }
    return -10;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxcount = 0;
    int maxlen = 0;
    string result;

    for (int i = 0; i < num_pwds; ++i) {
        const string& pwd = arr_pwds[i];
        int count = 0;
        int len = pwd.length();
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds[j] == pwd) {
                count++;
            }
        }
        if (count > maxcount || (count == maxcount && len > maxlen)) {
            maxcount = count;
            maxlen = len;
            result = pwd;
        }
    }
    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == result) {
            return i;
        }
    }

    return -1; 
}

void addExp(int &obj, double alpha)
{
    obj += ceil(alpha);
    if (obj > 600)
        obj = 600;
}
void subExp(int &obj, double alpha)
{
    obj -= floor(alpha);
    if (obj < 0)
        obj = 0;
}
void addHP(int &obj, double alpha)
{
    obj += ceil(alpha);
    if (obj > 666)
        obj = 666;
}
void subHP(int &obj, double alpha)
{
    obj -= floor(alpha);
    if (obj < 0)
        obj = 0;
}
void addMoney(int &obj, int alpha)
{
    obj += alpha;
    if (obj > 3000)
        obj = 3000;
}
void subMoney(int &obj, int alpha)
{
    obj -= alpha;
    if (obj < 0)
        obj = 0;
}
int getsquareNum(double num)
    {
        int a = round(sqrt(num));
        return a * a;
    }
int getPi(int n)
    {
        if (n < 10) return n;
        int a = n/10 + n%10;
        return a%10;
    }
int sumsum(int n)
{
    if (n > 99) return 1;
    if (n < 10) return n;
    int a = n/10 + n%10;
    if (a < 10) return a;
    return a/10 + a%10;
}
int countPositive(int ** m, int e3)
{
    int res = 0;
    e3 *= 2;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (m[i][j] > e3)
            res++;
        }
    }
    return res;
}
int countNegative(int ** m, int e3)
{
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (m[i][j] < -e3)
            res++;
        }
    }
    return res;
}
int getHighest(int **m, int x, int y)
{
    int highest = m[x][y];
    //left diagonal
    //above 
    for (int i = x, j = y; i >= 0 && j >= 0; i --, j--)
    if (highest < m[i][j]) highest = m[i][j];

    //under 
    for (int i = x, j = y; i < 10 && j < 10; i ++, j++)
    if (highest < m[i][j]) highest = m[i][j];
    //right diagonal
    //above
    for (int i = x, j = y; i >= 0 && j < 10; i --, j++)
    if (highest < m[i][j]) highest = m[i][j];
    //under
    for (int i = x, j = y; i < 10 && j >= 0; i ++, j--)
    if (highest < m[i][j]) highest = m[i][j];

    return highest;
}
void resetexp(int &a)
{
if (a > 600) a = 600;
if (a < 0)  a = 0;
}
void resetHP(int &a)
{
if (a > 666) a = 666;
if (a < 0) a = 0;
}
void resetM(int &a)
{
   if (a > 3000) a = 3000;
   if (a < 0) a = 0; 
}
void changeTimes(int &obj, double t, int max)
{
    if (floor (obj * t) == ceil (obj * t)) // int
    {
        obj = int (obj * 1.0 * (1 + t)) ;
    }
    else
    {
        obj = int (obj * 1.0 * (1 + t)) + 1;
    }
    if (obj > max) obj = max;
}
bool is_Scharacter(char c) {
    string alpha = "@#%$!";
    return alpha.find(c) != string::npos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////