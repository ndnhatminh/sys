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

//Check conditions
int EXPlimit(int &a) { return a=min(max(0, a), 600); }
int HPlimit(int &a) { return a=min(max(0, a), 666); }
int Mlimit(int &a) { return a=min(max(0, a), 3000); }
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) 
{
    // TODO: Complete this function
    EXPlimit(exp1);
    EXPlimit(exp2);
    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0: { exp2 += 29; break; }
        case 1: { exp2 += 45; break; }
        case 2: { exp2 += 75; break; }
        default: exp2 += (29 + 45 + 75);
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + (D / 200.0));
        else exp1 = ceil(exp1 - (D / 100.0));
        EXPlimit(exp1);
        EXPlimit(exp2);
    }
    else if (e1 < 100)
    {
        if (e1 >= 4 && e1 <= 19) exp2 += (ceil(e1 / 4.0) + 19);
        EXPlimit(exp2);
        if (e1 >= 20 && e1 <= 49) exp2 += (ceil(e1 / 9.0) + 21);
        EXPlimit(exp2);
        if (e1 >= 50 && e1 <= 65) exp2 += (ceil(e1 / 16.0) + 17);
        EXPlimit(exp2);
        if (e1 >= 66 && e1 <= 79)
        {
            exp2 += (ceil(e1 / 4.0) + 19);
            EXPlimit(exp2);
            if (exp2 > 200) exp2 += (ceil(e1 / 9.0) + 21);
            EXPlimit(exp2);
        }
        if (e1 >= 80 && e1 <= 99)
        {
            exp2 += (ceil(e1 / 4.0) + 19);
            EXPlimit(exp2);
            exp2 += (ceil(e1 / 9.0) + 21);
            EXPlimit(exp2);
            if (exp2 > 400) exp2 += (ceil(e1 / 16.0) + 17);
            EXPlimit(exp2);
            exp2 += ceil(exp2 * (15 / 100.0));
            EXPlimit(exp2);

        }
        exp1 -= e1;
        EXPlimit(exp1);
    }
    else return -99;
    return exp1 + exp2;
}

// Task 2

//Tim so chinh phuong gan nhat
int TimCP(int a)
{
    float sq = round(sqrt(a));
    return sq * sq;
}

//Kiem tra chi tieu
bool MoneyCheck(int remain, int owned)
{
    return ((remain*2) >= owned);
}

//main func
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) 
{
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;
    //Hanh dong 2.1
    int S = 0;
    const int owned = M1;
    float P1 = 0, P2 = 0, PAvg;
    EXPlimit(EXP1);
    S = TimCP(EXP1);
    //cout << "S: " << S << endl;
    if (EXP1 >= S) P1 = 100;
    else P1 = (100*(((EXP1 / float(S)) + 80.0) / 123.0));

    //2.2
    if (Mlimit(M1))
    {
        if (E2 % 2 == 0)
        {
            int t = 1;
            while (t == 1)
            {
                t -= 1;
                //cout << "case 2" << endl;
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                //cout << "act21 running" << endl;
                if (HP1 < 200)
                {
                    M1 -= 150;
                    HP1 = ceil(HP1 + HP1 * 0.3);
                }
                else
                {
                    M1 -= 70;
                    HP1 = ceil(HP1 + HP1 * 0.1);
                }
                if (Mlimit(M1) == 0)
                {
                    //cout << "M1: " << M1 << endl;
                    break;
                }

                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = ceil(EXP1 + (EXP1 * 0.13));
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                if (Mlimit(M1) == 0)
                {
                    //cout << "M1: " << M1 << endl;
                    break;
                }

                if (EXP1 >= 300) M1 -= 120;
                else M1 -= 100;
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                if (Mlimit(M1) == 0)
                {
                    //cout << "M1: " << M1 << endl; 
                    break;
                }
            }
            HP1 = ceil(HP1 - (HP1 * 0.17));
            EXP1 = ceil(EXP1 + (EXP1 * 0.17));
            HPlimit(HP1);
            EXPlimit(EXP1);

        }
        else
        {
            //cout << "case 1" << endl;
            //cout << MoneyCheck(M1, owned) << endl ;
            while (MoneyCheck(M1, owned))
            {
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                //cout << "act22 running" << endl;
                if (HP1 < 200)
                {
                    M1 -= 150;
                    HP1 = ceil(HP1 + (HP1 * 0.3));
                }
                else
                {
                    M1 -= 70;
                    HP1 = ceil(HP1 + (HP1 * 0.1));
                }
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                if (MoneyCheck(M1, owned) == 0)
                {
                    //cout << "M1: " << M1 << endl; 
                    break;
                }

                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = ceil(EXP1 + (EXP1 * 0.13));
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                if (MoneyCheck(M1, owned) == 0)
                {
                    //cout << "M1: " << M1 << endl; 
                    break;
                }

                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = ceil(EXP1 - EXP1 * 0.1);
                Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);
                if (MoneyCheck(M1, owned) == 0)
                {
                    //cout << "M1: " << M1 << endl; 
                    break;
                }
            }
            //act22(HP1, EXP1, M1);
            HP1 = ceil(HP1 - (HP1 * 17 / 100.0));
            EXP1 = ceil(EXP1 + (EXP1 * 17 / 100.0));
            Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);

        }
    }
    S = 0;
    EXPlimit(EXP1);
    S = TimCP(EXP1);
    if (EXP1 >= S) P2 = 100;
    else P2 = (100 * (((EXP1 / float(S)) + 80.0) / 123.0));
    //2.3
    int index=0;
    int P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) index = E2;
    else
    {
        index = 10;
        while(index>9)
            index = (E2 / 10 + E2 % 10) % 10;
    }
    if ((P1 == 100) && (P2==100) && (P3[index]==100)) 
        EXP1 = ceil(EXP1 - (EXP1 * 0.25));
    else
    {
        PAvg = (P1 + P2 + P3[index]) / 3.0;
        //cout << "PAvg: " << PAvg << endl;
        if (PAvg < 50)
        {
            HP1 = ceil(HP1 - (HP1 * 0.15));
            EXP1 = ceil(EXP1 + (EXP1 * 0.15));
        }
        else
        {
            HP1 = ceil(HP1 - (HP1 * 0.1));
            EXP1 = ceil(EXP1 + (EXP1 * 0.2));
        }
        Mlimit(M1); EXPlimit(EXP1); HPlimit(HP1);

    }
    //cout << "P1: " << P1 << endl;
    //cout << "P2: " << P2 << endl;
    //cout << "P3: " << P3[index] << endl;
    return HP1 + EXP1 + M1;
}

// Task 3
int a[10][10];
int Diagonal_Max(int x, int y)
{
    int dmax=a[x][y];
    int i = x, j = y;
    while (i < 10 && j < 10) {
        dmax = max(dmax, (a[i][j]));
        i += 1;
        j += 1;
    }
    i = x, j = y;
    while (i >= 0 && j >= 0) {
        //cout << i << " " << j;
        dmax = max(dmax, (a[i][j]));
        i -= 1;
        j -= 1;
    }
    i = x, j = y;
    while (i < 10 && j >= 0) 
    {
        dmax = max(dmax, (a[i][j]));
        i += 1;
        j -= 1;
    }
    i = x, j = y;
    while (i >= 0 && j < 10) {
        dmax = max(dmax, (a[i][j]));
        i -= 1;
        j += 1;
    }
    dmax = abs(dmax);
    return dmax;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    int max_value=0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            a[i][j] = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);

    int Xaxis =0, Yaxis = 0;
    for(int i=0;i<10;i++)
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] > E3 * 2) Xaxis += 1;
            if (a[i][j] < (-E3)) Yaxis += 1;
        }
    while (Xaxis > 9) Xaxis = Xaxis / 10 + Xaxis % 10;
    while (Yaxis > 9) Yaxis = Yaxis / 10 + Yaxis % 10;
    //cout << "Xaxis: " << Xaxis << " Yaxis: " << Yaxis << endl;
    if (abs(a[Xaxis][Yaxis]) < Diagonal_Max(Xaxis,Yaxis))
    {
        max_value = Diagonal_Max(Xaxis, Yaxis);
        HP1 = ceil(HP1 + HP1 * 0.10);
        HP2 = ceil(HP2 + HP2 * 0.10);
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
    }
    else
    {
        max_value = a[Xaxis][Yaxis];
        HP1 = ceil(HP1 - HP1 * 0.10);
        HP2 = ceil(HP2 - HP2 * 0.10);
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
    }
    HPlimit(HP1);
    HPlimit(HP2);
    EXPlimit(EXP1);
    EXPlimit(EXP2);
    return max_value;
}

// Task 4
int checkPassword(const char* s, const char* email) 
{
    // TODO: Complete this function
    const char* SpecialChars="@#$%!";
    char* e = new char[strlen(email)+1];
    //errno_t result= strcpy_s(e, strlen(email)+1,email);
    strcpy(e, email);
    char* context = NULL;
    //cout << "e: " << e << endl;
    //const char* se = strtok_s(e, "@", &context);
    //cout << "se: " << se << endl;
    //cout << "check: " << result << endl;
    const char* se = strtok(e, "@");
    int length = strlen(s);
    //Length check
    if (length < 8)
    {
        delete[] e;
        return -1;
    }
    if (length > 20) 
    { 
        delete[] e;
        return -2;
    }

    //se check
    int ans = -(300 + (strstr(s, se) - s));
    if (strstr(s, se) != NULL) { delete[] e; return ans; }

    //Repeat check
    for (int i = 0; i < length - 1; i++) {
        if (s[i] == s[i + 1]) 
        {
            delete[] e;
            return -(400 + i);
        }
    }
    //SpecialChars check
    bool check = 0;
    for (int i = 0; i < length; i++)
        if (strchr(SpecialChars, s[i]) != NULL) { check = 1; break; }//Special characters detected=>checked
    if (check == 0) 
    {
        delete[] e;  return -5;
    }
    //valid check
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || strchr(SpecialChars, c) != NULL)) 
        {
            delete[] e;
            return i + 1;
        }
    }
    delete[] e;
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
    const char* correct = NULL;
    int maxcnt = 0, maxlength = 0;

    for (int i = 0; i < num_pwds; ++i) 
    {
        int cnt = 0;
        for (int j = 0; j < num_pwds; ++j) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                cnt += 1;
            }
        }

        int length = strlen(arr_pwds[i]);
        if (cnt > maxcnt || (cnt == maxcnt && length > maxlength)) 
        {
            maxcnt = cnt;
            maxlength = length;
            correct = arr_pwds[i];
        }
    }

    for (int i = 0; i < num_pwds; ++i) 
    {
        if (correct == arr_pwds[i]) 
        {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////