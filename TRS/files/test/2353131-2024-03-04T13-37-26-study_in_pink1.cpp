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

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) return -99; else
    {
        if (exp1 > 600) exp1 = 600;
        if (exp1 < 0) exp1 = 0;
        if (exp2 > 600) exp2 = 600;
        if (exp2 < 0) exp2 = 0;
        if ((e1 >= 0) && (e1 <= 3))//case1
        {
            if (e1 == 0) exp2 += 29; else
                if (e1 == 1) exp2 += 45; else
                    if (e1 == 2) exp2 += 75; else
                        if (e1 == 3) exp2 = exp2 + 29 + 45 + 75;
            if (exp2 > 600) exp2 = 600;
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            {
                exp1 += ceil(D / 200.0);
                if (exp1 > 600) exp1 = 600;
            }
            else
            {
                double temp = exp1 - D / 100.0;
                exp1 = ceil(temp);
                if (exp1 < 0) exp1 = 0;
            }

        }
        else
            if ((e1 >= 4) && (e1 <= 99))//case2
            {
                if ((e1 >= 4) && (e1 <= 19)) exp2 += ceil(e1 / 4.0) + 19; else
                    if ((e1 >= 20) && (e1 <= 49)) exp2 += ceil(e1 / 9.0) + 21; else
                        if ((e1 >= 50) && (e1 <= 65)) exp2 += ceil(e1 / 16.0) + 17; else
                            if ((e1 >= 66) && (e1 <= 79))
                            {
                                exp2 += ceil(e1 / 4.0) + 19;
                                if (exp2 > 200) exp2 += ceil(e1 / 9.0) + 21;
                            }
                            else
                                if ((e1 >= 80) && (e1 <= 99))
                                {
                                    exp2 += ceil(e1 / 4.0) + 19 + ceil(e1 / 9.0) + 21;
                                    if (exp2 > 400)
                                    {
                                        exp2 += ceil(e1 / 16.0) + 17;
                                        exp2 = ceil(exp2 * 1.15);
                                    }
                                }
                if (exp2 > 600) exp2 = 600;
                exp1 -= e1;
                if (exp1 < 0) exp1 = 0;
            }
        return exp1 + exp2;
    }
}

// Task 2
int nearestSquare(int n)
{
    if (n == 0) return 0; else
    {
        int r = ceil(sqrt(n));
        if (r * r - n > n - (r - 1) * (r - 1)) return (r - 1) * (r - 1); else return r * r;
    }
}
void actions(int& HP1, int& EXP1, int& M1, double lim)
{
    //action 1
    if (M1 >= lim)
    {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 -= 150;
        }
        else {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
        }
        if (HP1 > 666) HP1 = 666;
        if (M1 < 0) M1 = 0;
    }
    //action 2
    if (M1 >= lim)
    {
        if (EXP1 < 400) M1 -= 200; else M1 -= 120;
        EXP1 = ceil(EXP1 * 1.13);
        if (EXP1 > 600) EXP1 = 600;
        if (M1 < 0) M1 = 0;
    }
    //action 3
    if (M1 >= lim)
    {
        if (EXP1 < 300) M1 -= 100; else M1 -= 120;
        EXP1 = ceil(EXP1 * 0.9);
        if (M1 < 0) M1 = 0;
    }
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0) || (E2 > 99)) return -99; else
    {
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        if (M1 < 0) M1 = 0;
        int p1, p2, p3, S;
        //road1
        S = nearestSquare(EXP1);
        if (EXP1 >= S) p1 = 100; else p1 = ceil((EXP1 / S + 80) / 123.0 * 100);
        //road2
        double temp = M1 * 0.5;
        if (E2 % 2 == 0) {
            if (M1 > 0)
            {
                actions(HP1, EXP1, M1, 0);
                if (M1 < 0) M1 = 0;
            }
        }
        else while (M1 >= temp) actions(HP1, EXP1, M1, temp);
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
        if (EXP1 > 600) EXP1 = 600;
        S = nearestSquare(EXP1);
        if (EXP1 >= S) p2 = 100; else p2 = ceil((EXP1 / S + 80) / 123.0 * 100);
        //road3
        int p[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E2 < 10) p3 = p[E2]; else p3 = p[(E2 % 10 + E2 / 10) % 10];
        if (p1 == 100 && p2 == 100 && p3 == 100) EXP1 = ceil(EXP1 * 0.75);
        else
        {
            int P = ceil((p1 + p2 + p3) / 3.0);
            if (P < 50) {
                EXP1 = ceil(EXP1 * 1.15);
                if (EXP1 > 600) EXP1 = 600;
                HP1 = ceil(HP1 * 0.85);
            }
            else {
                EXP1 = ceil(EXP1 * 1.2);
                if (EXP1 > 600) EXP1 = 600;
                HP1 = ceil(HP1 * 0.9);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int sum(int n)
{
    if (n == 100) return 1; else
        if (n <= 9) return n; else
            return sum(n / 10 + n % 10);
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99)) return -99; else
    {
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
        if (HP1 > 666) HP1 = 666;
        if (HP1 < 0) HP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        if (EXP2 < 0) EXP2 = 0;
        if (HP2 > 666) HP2 = 666;
        if (HP2 < 0) HP2 = 0;
        int sc[10][10];
        int x = 0, y = 0;
        int temp = E3 * 2;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                sc[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (sc[i][j] > temp) x++;
                if (sc[i][j] < -E3) y++;
            }
        x = sum(x);
        y = sum(y);
        int max = sc[x][y];
        int u = x, v = y;
        while (u > 0 && v > 0)
            if (sc[--u][--v] > max) max = sc[u][v];
        u = x; v = y;
        while (u < 9 && v < 9)
            if (sc[++u][++v] > max) max = sc[u][v];
        u = x; v = y;
        while (u < 9 && v > 0)
            if (sc[++u][--v] > max) max = sc[u][v];
        u = x; v = y;
        while (u > 0 && v < 9)
            if (sc[--u][++v] > max) max = sc[u][v];
        int result;
        if (abs(max) >= abs(sc[x][y]))
        {
            result = abs(max);
            EXP1 = ceil(EXP1 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            EXP2 = ceil(EXP2 * 1.12);
            HP2 = ceil(HP2 * 1.1);
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 > 666) HP1 = 666;
            if (EXP2 > 600) EXP2 = 600;
            if (HP2 > 666) HP2 = 666;
        }
        else
        {
            result = sc[x][y];
            EXP1 = ceil(EXP1 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.9);
        }
        return result;
    }
}

// Task 4
int consecutive(string st)
{
    int re = -1;
    for (int i = 0; i <= st.size() - 3; i++)
        if ((st[i] == st[i + 1]) && (st[i + 1] == st[i + 2])) {
            re = i; break;
        }
    return re;
}
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string S = s, Email = email;
    int si = S.size();
    if (si < 8) return -1; else
        if (si > 20) return -2; else
        {
            int p1 = Email.find("@");
            string se = Email.substr(0, p1);
            int p2 = S.find(se);
            if ((p2 >= 0) && (p2 <= si - 1)) return -(300 + p2); else
            {
                int sci = consecutive(s);
                if (sci != -1) return -(400 + sci); else
                {
                    int p3 = S.find("@");
                    int p4 = S.find("#");
                    int p5 = S.find("%");
                    int p6 = S.find("$");
                    int p7 = S.find("!");
                    if (!(((p3 >= 0) && (p3 <= si - 1)) || ((p4 >= 0) && (p4 <= si - 1)) || ((p5 >= 0) && (p5 <= si - 1)) || ((p6 >= 0) && (p6 <= si - 1)) || ((p7 >= 0) && (p7 <= si - 1)))) return -5; else
                    {
                        int i;
                        for (i = 0; i < si; i++)
                            if (!(((S[i] >= '0') && (S[i] <= '9')) || ((S[i] >= 'a') && (S[i] <= 'z')) || ((S[i] >= 'A') && (S[i] <= 'Z')) || (S[i] == '@') || (S[i] == '#') || (S[i] == '%') || (S[i] == '$') || (S[i] == '!'))) break;
                        if (i < si) return i; else return -10;
                    }
                }
            }
        }
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string separate_pwds[30];
    int count[30], pos[30];
    int n = 1;
    separate_pwds[0] = arr_pwds[0];
    count[0] = 1;
    pos[0] = 1;
    for (int i = 1; i < num_pwds; i++)
    {
        int j;
        for (j = 0; j < n; j++)
            if (arr_pwds[i] == separate_pwds[j])
            {
                count[j]++;
                break;
            }
        if (j == n)
        {
            separate_pwds[n] = arr_pwds[i];
            count[n] = 1;
            pos[n] = i;
            n++;
        }
    }
    int pwd_pos = 0, max = count[0], l_max = separate_pwds[0].size();
    for (int i = 1; i < n; i++)
        if (count[i] > max)
        {
            max = count[i];
            pwd_pos = pos[i];
            l_max = separate_pwds[i].size();
        }
        else
            if ((count[i] == max) && (separate_pwds[i].size() > l_max))
            {
                pwd_pos = pos[i];
                l_max = separate_pwds[i].size();
            }
    return pwd_pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////