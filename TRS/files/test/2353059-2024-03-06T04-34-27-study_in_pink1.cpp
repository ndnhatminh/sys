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

// cần kiểm tra giá trị tham số đầu vào :??

// check exp
int exp(int &exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    if (exp < 0)
    {
        exp = 0;
    }
    return exp;
}

// check hp
int hp(int &hp)
{
    if (hp > 666)
    {
        hp = 666;
    }
    if (hp < 0)
    {
        hp = 0;
    }
    return hp;
}

// check money
int m(int &m)
{
    if (m > 3000)
    {
        m = 3000;
    }
    if (m < 0)
    {
        m = 0;
    }
    return m;
}

// check event
int e(int &e)
{
    if (e > 99 || e < 0)
    {
        return -99;
    }
    return e;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) // completed(need to check again //cần check lại các phép nhân phần trăm do cơ chế làm tròng của code;
{
    // TODO: Complete this function
    exp(exp1);
    exp(exp2);
    int D;
    if (e(e1) != -99)
    {
        if (e1 >= 0 && e1 <= 3)
        {
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            {
                exp1 += ceil((double)D / 200);
                exp(exp1);
                exp(exp2);
            }
            else
            {
                exp1 -= ceil((double)(D / 100));
                exp(exp1);
                exp(exp2);
            }

            switch (e1)
            {
            case 0:
                exp2 += 29;
                exp(exp1);
                exp(exp2);
                break;
            case 1:
                exp2 += 45;
                exp(exp1);
                exp(exp2);
                break;
            case 2:
                exp2 += 75;
                exp(exp1);
                exp(exp2);
                break;
            case 3:
                exp2 += 149;
                exp(exp1);
                exp(exp2);
                break;
            }
        }
        else
        {
            if (e1 >= 4 && e1 <= 19)
            {
                exp2 += (ceil((double)e1 / 4) + 19);
                exp(exp1);
                exp(exp2);
            }
            else if (e1 <= 49)
            {
                exp2 += (ceil((double)e1 / 9) + 21);
                exp(exp1);
                exp(exp2);
            }
            else if (e1 <= 65)
            {
                exp2 += (ceil((double)e1 / 16) + 17);
                exp(exp1);
                exp(exp2);
            }
            else if (e1 <= 79)
            {
                exp2 += (ceil((double)e1 / 4) + 19);
                exp(exp1);
                exp(exp2);
                if (exp2 > 200)
                {
                    exp2 += (ceil((double)e1 / 9) + 21);
                    exp(exp1);
                    exp(exp2);
                }
            }
            else
            {
                exp2 += (ceil((double)e1 / 4) + 19);
                exp2 += (ceil((double)e1 / 9) + 21);
                exp(exp1);
                exp(exp2);
                if (exp2 > 400)
                {
                    exp2 += (ceil((double)e1 / 16) + 17);
                    exp2 += ceil((double)(exp2 * (double)0.15));
                    exp(exp1);
                    exp(exp2);
                }
                // need to check again;
            }
            exp1 -= e1;
        }
    }
    else
    {
        return -99;
    }

    exp(exp1);
    exp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) // cần check lại;
{
    // TODO: Complete this function

    int S;
    double p1, p2, p3;
    S = sqrt(EXP1);

    exp(EXP1);
    hp(HP1);
    m(M1);
    if (e(E2) != -99)
    {
        if (S * S - EXP1 == 0) // road 1 && p1;
        {
            S *= S;
            p1 = 100;
        }
        else if ((S + 1) * (S + 1) - EXP1 > EXP1 - S * S)
        {
            S *= S;
            p1 = 100;
        }
        else
        {
            S += 1;
            S *= S;
            p1 = (double)(((double)(EXP1 / S) + 80) / 123); //:?
            p1 *= 100;
        }

        int m1 = 0;
        double sub;
        sub = (double)(M1 * (double)0.5);
        if (E2 % 2 != 0) // road 2;
        {
            while (m1 < sub)
            {
                if (HP1 < 200)
                {
                    HP1 += ceil((double)(HP1 * (double)0.3));
                    hp(HP1); // note coi lại cách tính tràng số ;
                    M1 -= 150;
                    m1 += 150;
                    hp(HP1);
                    m(M1);
                    if (m1 > sub)
                    {
                        HP1 -= floor((double)(HP1 * (double)0.17));
                        EXP1 += ceil((double)(EXP1 * (double)0.17));
                        exp(EXP1);
                        hp(HP1);
                        break;
                    }
                }
                else
                {
                    HP1 += ceil((double)(HP1 * (double)0.1));
                    hp(HP1);
                    M1 -= 70;
                    m1 += 70;
                    hp(HP1);
                    m(M1);
                    if (m1 > sub)
                    {
                        HP1 -= floor((double)(HP1 * (double)0.17));
                        EXP1 += ceil((double)(EXP1 * (double)0.17));
                        exp(EXP1);
                        hp(HP1);
                        break;
                    }
                }

                if (EXP1 < 400)
                {
                    EXP1 += ceil((double)(EXP1 * (double)0.13));
                    exp(EXP1);
                    M1 -= 200;
                    m1 += 200;
                    m(M1);
                    if (m1 > sub)
                    {
                        HP1 -= floor((double)(HP1 * (double)0.17));
                        EXP1 += ceil((double)(EXP1 * (double)0.17));
                        exp(EXP1);
                        hp(HP1);
                        break;
                    }
                }
                else
                {
                    EXP1 += ceil((double)(EXP1 * (double)0.13));
                    exp(EXP1);
                    M1 -= 120;
                    m1 += 120;
                    m(M1);
                    if (m1 > sub)
                    {
                        HP1 -= floor((double)(HP1 * (double)0.17));
                        EXP1 += ceil((double)(EXP1 * (double)0.17));
                        exp(EXP1);
                        hp(HP1);
                        break;
                    }
                }

                if (EXP1 < 300)
                {
                    M1 -= 100;
                    m1 += 100;
                    m(M1);
                    EXP1 -= floor((double)(EXP1 * (double)0.1));
                    exp(EXP1);
                    if (m1 > sub)
                    {
                        HP1 -= floor((double)(HP1 * (double)0.17));
                        EXP1 += ceil((double)(EXP1 * (double)0.17));
                        exp(EXP1);
                        hp(HP1);
                        break;
                    }
                }
                else
                {
                    M1 -= 120;
                    m1 += 120;
                    m(M1);
                    EXP1 -= floor((double)(EXP1 * (double)0.1));
                    exp(EXP1);
                    if (m1 > sub)
                    {
                        HP1 -= floor((double)(HP1 * (double)0.17));
                        EXP1 += ceil((double)(EXP1 * (double)0.17));
                        exp(EXP1);
                        hp(HP1);
                        break;
                    }
                }
            }
        }
        else
        {
            if (M1 != 0)
            {
                if (HP1 < 200)
                {
                    HP1 += ceil((double)(HP1 * (double)0.3)); // note coi lại cách tính tràng số ;
                    M1 -= 150;
                    hp(HP1);
                    m(M1);
                }
                else
                {
                    HP1 += ceil((double)(HP1 * (double)0.1));
                    M1 -= 70;
                    hp(HP1);
                    m(M1);
                }
            }
            if (M1 != 0)
            {
                if (EXP1 < 400)
                {
                    EXP1 += ceil((double)(EXP1 * (double)0.13));
                    M1 -= 200;
                    m(M1);
                }
                else
                {
                    EXP1 += ceil((double)(EXP1 * (double)0.13));
                    M1 -= 120;
                    m(M1);
                }
            }
            if (M1 != 0)
            {
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 -= floor((double)(EXP1 * (double)0.1));
                    m(M1);
                    exp(EXP1);
                }
                else
                {
                    M1 -= 120;
                    EXP1 -= floor((double)(EXP1 * (double)0.1));
                    m(M1);
                    exp(EXP1);
                }
            }
            HP1 -= floor((double)(HP1 * (double)0.17));
            EXP1 += ceil((double)(EXP1 * (double)0.17));
            exp(EXP1);
            hp(HP1);
        }

        int S1;
        S1 = sqrt(EXP1);
        if (S1 * S1 - EXP1 == 0) // road 1 && p1;
        {
            S1 *= S1;
            p2 = 100;
        }
        else if ((S1 + 1) * (S1 + 1) - EXP1 > EXP1 - S1 * S1)
        {
            S1 *= S1;
            p2 = 100;
        }
        else
        {
            S1 += 1;
            S1 *= S1;
            p2 = (double)(((double)(EXP1 / S1) + 80) / 123); //:?
            p2 *= 100;
        }

        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // P3;
        double p;
        if (E2 >= 0 && E2 <= 9)
        {
            p3 = P[E2];
        }
        else
        {
            int ans = 0;
            while (E2 != 0)
            {
                ans += (E2 % 10);
                E2 /= 10;
            }
            ans = (ans % 10);
            p3 = P[ans];
        }

        if (p1 == 100 && p2 == 100 && p3 == 100)
        {
            EXP1 -= floor((double)(EXP1 * (double)0.25));
            exp(EXP1);
        }
        else
        {
            p = (double)((double)((double)p1 + (double)p2 + (double)p3) / 3);
            if (p < 50)
            {
                HP1 -= floor((double)(HP1 * (double)0.15));
                EXP1 += ceil((double)(EXP1 * (double)0.15));
                exp(EXP1);
                hp(HP1);
            }
            else
            {
                HP1 -= floor((double)(HP1 * (double)0.1));
                EXP1 += ceil((double)(EXP1 * (double)0.2));
                exp(EXP1);
                hp(HP1);
            }
        }
    }
    else
    {
        return -99;
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) // còn phần cuối cùng;hoàn thành 90% //thiếu trường hợp mã event ko hợp lệ!!!;
{
    // TODO: Complete this function
    if (e(E3) != -99)
    {
        int a[10][10];
        int counti = 0;
        int countj = 0;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (a[i][j] > 0)
                {
                    if (a[i][j] > (2 * E3))
                    {
                        counti++;
                    }
                }
                else if (a[i][j] < 0)
                {
                    if (a[i][j] < (-E3))
                    {
                        countj++;
                    }
                }
            }
        }

        int ansi = 0;
        int ansj = 0;
        while (counti != 0)
        {
            ansi += counti % 10;
            counti /= 10;
            if (ansi > 9)
            {
                counti = ansi;
                ansi = 0;
            }
        }

        while (countj != 0)
        {
            ansj += countj % 10;
            countj /= 10;
            if (ansj > 9)
            {
                countj = ansj;
                ansj = 0;
            }
        }

        int pointtaxi = a[ansi][ansj];
        int i = ansi;
        int j = ansj;
        int maxx = pointtaxi;
        while (i != 0 && j != 0)
        {
            maxx = max(maxx, a[i - 1][j - 1]);
            i -= 1;
            j -= 1;
        }
        i = ansi;
        j = ansj;
        while (i != 9 && j != 9)
        {
            maxx = max(maxx, a[i + 1][j + 1]);
            i += 1;
            j += 1;
        }
        i = ansi;
        j = ansj;
        while (i != 0 && j != 9)
        {
            maxx = max(maxx, a[i - 1][j + 1]);
            i -= 1;
            j += 1;
        }
        i = ansi;
        j = ansj;
        while (i != 9 && j != 0)
        {
            maxx = max(maxx, a[i + 1][j - 1]);
            i += 1;
            j -= 1;
        }

        if (maxx >= abs(pointtaxi))
        {
            EXP1 += ceil((double)(EXP1 * (double)0.12));
            EXP2 += ceil((double)(EXP2 * (double)0.12));
            HP1 += ceil((double)(HP1 * (double)0.1));
            HP2 += ceil((double)(HP2 * (double)0.1));
            hp(HP1);
            hp(HP2);
            exp(EXP1);
            exp(EXP2);
            return maxx;
        }
        else
        {
            EXP1 -= floor((double)(EXP1 * (double)0.12));
            EXP2 -= floor((double)(EXP2 * (double)0.12));
            HP1 -= floor((double)(HP1 * (double)0.1));
            HP2 -= floor((double)(HP2 * (double)0.1));
            hp(HP1);
            hp(HP2);
            exp(EXP1);
            exp(EXP2);
            return pointtaxi;
        }
    }
    else
    {
        return -99;
    }

    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function

    string s2 = email;
    string s1 = s;
    string se;
    se = s2.erase(s2.find("@"));

    if (s1.length() < 8)
    {
        return -1;
    }
    else if (s1.length() > 20)
    {
        return -2;
    }
    else
    {
        if (s1.find(se) != string::npos)
        {
            int ans = s1.find(se);
            return -(300 + ans);
        }
        else
        {
            for (int i = 0; i < s1.length() - 2; ++i)
            {
                if (s1[i] == s1[i + 1] && s1[i + 1] == s1[i + 2])
                {
                    return -(400 + i);
                    break;
                }
            }
            bool check = false;
            for (int i = 0; i < s1.length(); ++i)
            {
                if (isalnum(s1[i]) == false)
                {
                    if (s1[i] == '@' || s1[i] == '!' || s1[i] == '#' || s1[i] == '$' || s1[i] == '%')
                    {
                        check = true;
                        break;
                    }
                }
            }
            bool check1 = false;
            if (check == true)
            {
                for (int i = 0; i < s1.length(); i++)
                {
                    if (isalnum(s1[i]) == false)
                    {
                        if (s1[i] != '@' && s1[i] != '!' && s1[i] != '#' && s1[i] != '$' && s1[i] != '%')
                        {
                            return i;
                            check1 = true;
                            break;
                        }
                    }
                }
                if (check1 == false)
                {
                    return -10;
                }
            }
            else
            {
                return -5;
            }
        }
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    string s[num_pwds];
    for (int i = 0; i < num_pwds; ++i)
    {
        s[i] = arr_pwds[i];
    }

    int cnt[num_pwds];

    for (int i = 0; i < num_pwds; ++i)
    {
        cnt[i] = 1;
        if (s[i] != "0")
        {
            for (int j = i + 1; j < num_pwds; ++j)
            {
                if (s[i] == s[j])
                {
                    cnt[i]++;
                    s[j] = "0";
                }
            }
        }
    }
    int maxx = 0, index = 0;
    for (int i = 0; i < num_pwds; ++i)
    {
        if (cnt[i] > maxx)
        {
            index = i;
            maxx = cnt[i];
        }
        else if (cnt[i] == maxx)
        {
            if (s[i].length() > s[index].length())
            {
                index = i;
            }
        }
    }
    return index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////