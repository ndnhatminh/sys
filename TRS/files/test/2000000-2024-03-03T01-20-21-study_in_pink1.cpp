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

// kiem tra gioi han
int change(string s, int & a, double b)
{
    if (b < 0)
    {
        a += ceil(b);
        if (a < 0)
            a = 0;
        return 0;
    }
    int gh;
    if (s == "HP")
        gh = 666;
    else if (s == "EXP")
        gh = 600;
    else if (s == "M")
        gh = 3000;

    if (b > 0)
    {
        a += ceil(b);
        if (a > gh)
            a = gh;
    }
    return 0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    // Kiem tra pham vi e1
    if (e1 < 0 || e1 > 99) return -99;

    // Tach truong hop
    if (e1 < 4) // [0,3]
    {
        switch (e1)
        {
            case 0: change("EXP", exp2, 29); break;
            case 1: change("EXP", exp2, 45); break;
            case 2: change("EXP", exp2, 75); break;
            case 3: change("EXP", exp2, 29 + 45 + 75); break;
        }
        int D = e1*3 + exp1*7;
        if (D % 2 == 0)
            change("EXP", exp1, D/200.0);
        else
            change("EXP", exp1, -D/100.0);
    }
    else // [4,99]
    {
        if (e1 <= 19)
            change("EXP", exp2, e1/4.0 + 19);
        else if (e1 <= 49)
            change("EXP", exp2, e1/9.0 + 21);
        else if (e1 <= 65)
            change("EXP", exp2, e1/16.0 + 17);
        else if (e1 <= 79)
        {
            change("EXP", exp2, e1/4.0 + 19);
            if (exp2 > 200)
                change("EXP", exp2, e1/9.0 + 21);
        }
        else
        {
            change("EXP", exp2, e1/4.0 + 19);
            change("EXP", exp2, e1/9.0 + 21);
            if (exp2 > 400)
            {
                change("EXP", exp2, e1/16.0 + 17);
                change("EXP", exp2, exp2*15.0/100);
            }
        }
        change("EXP", exp1, -e1);
    }

    return exp1 + exp2;
}

// Task 2
int path1(int & HP1, int & EXP1, int & M1, int E2){
    int S = round(sqrt(EXP1))*round(sqrt(EXP1));
    if (EXP1 >= S)
        return 100;
    else
        return ceil(((double) EXP1/S + 80)/123*100);
}

int checkMoney_path2(int & M1, int E2, int m){
    if (E2 % 2 == 1 && m > M1/2)
        return 1;
    if (E2 % 2 == 0 && m > M1)
        return 2;
    return 0;
}

int path2(int & HP1, int & EXP1, int & M1, int E2, int & m){
    // Mua thuc an + nuoc uong
    if (!checkMoney_path2(M1, E2, m))
        if (HP1 < 200)
        {
            change("HP", HP1, HP1*30.0/100);
            m += 150;
        }
        else
        {
            change("HP", HP1, HP1*10.0/100);
            m += 70;
        }

    // Thue taxi + xe ngua
    if (!checkMoney_path2(M1, E2, m))
    {
        if (EXP1 < 400)
            m+= 200;
        else
            m+= 120;
        change("EXP", EXP1, EXP1*13.0/100);
    }

    // Gap nguoi tiet lo manh moi
    if (!checkMoney_path2(M1, E2, m))
    {
        if (EXP1 < 300)
            m += 100;
        else
            m += 120;
        change("EXP", EXP1, -EXP1*10.0/100);
    }

    // Tong ket
    if (E2 % 2 == 1 && m <= M1/2)
        return path2(HP1, EXP1, M1, E2, m);
    change("HP", HP1, -HP1*17.0/100);
    change("EXP", EXP1, EXP1*17.0/100);
    change("M", M1, -m);
    return path1(HP1, EXP1, M1, E2);
}

int path3(int & HP1, int & EXP1, int & M1, int E2)
{
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10)
        return P[E2];
    else
        return P[( (E2%10) + (E2/10) )%10];
}

int go(int & HP1, int & EXP1, int & M1, int E2, int &P1, int &P2, int &P3)
{
    P1 = path1(HP1, EXP1, M1, E2);
    int m = 0; P2 = path2(HP1, EXP1, M1, E2, m);
    P3 = path3(HP1, EXP1, M1, E2);
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        change("EXP", EXP1, -E2*25/100);
        return go(HP1, EXP1, M1, E2, P1, P2, P3);
    }
    return 0;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;

    // Tinh P1, P2, P3
    int P1, P2, P3;
    go(HP1, EXP1, M1, E2, P1, P2, P3);
    // Ket thuc
    int Ptb = round((P1 + P2 + P3)/3);
    if (Ptb < 50)
    {
        change("HP", HP1, -HP1*15.0/100);
        change("EXP", EXP1, EXP1*15.0/100);
    }
    else
    {
        change("HP", HP1, -HP1*10.0/100);
        change("EXP", EXP1, EXP1*20.0/100);
    }
    return HP1 + EXP1 + M1;
}


// Task 3
int Value(int MapTaxi[10][10], int i0, int j0)
{
    int i, j;
    int Max = MapTaxi[i0][j0];

    i = i0; j = j0;
    while (i !=0 && j != 0)
    {
        i--;
        j--;
        if (Max < MapTaxi[i][j])
            Max = MapTaxi[i][j];
    }

    i = i0; j = j0;
    while (i !=0 && j != 9)
    {
        i--;
        j++;
        if (Max < MapTaxi[i][j])
            Max = MapTaxi[i][j];
    }

    i = i0; j = j0;
    while (i !=9 && j != 0)
    {
        i++;
        j--;
        if (Max < MapTaxi[i][j])
            Max = MapTaxi[i][j];
    }

    i = i0; j = j0;
    while (i !=9 && j != 9)
    {
        i++;
        j++;
        if (Max < MapTaxi[i][j])
            Max = MapTaxi[i][j];
    }
    return Max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    if (E3 < 0 || E3 > 99) return -99;

    int MapTaxi[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            MapTaxi[i][j] = ((E3*j)+(i*2))*(i-j);

    int i0 = 0, j0 = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            if (MapTaxi[i][j] > E3*2)
                i0++;
            if (MapTaxi[i][j] < -E3)
                j0++;
        }
    while (i0 >= 10)
        i0 = i0%10 + i0/10%10 + i0/100%100;
    while (j0 >= 10)
        j0 = j0%10 + j0/10%10 + j0/100%100;

    if (abs(MapTaxi[i0][j0]) > abs(Value(MapTaxi, i0, j0)))
    {

        change("EXP", EXP1, -EXP1*12.0/100);
        change("EXP", EXP2, -EXP2*12.0/100);
        change("HP", HP1, -HP1*10.0/100);
        change("HP", HP2, -HP2*10.0/100);
        return MapTaxi[i0][j0];
    }
    else
    {
        change("EXP", EXP1, EXP1*12.0/100);
        change("EXP", EXP2, EXP2*12.0/100);
        change("HP", HP1, HP1*10.0/100);
        change("HP", HP2, HP2*10.0/100);
        return abs(Value(MapTaxi, i0, j0));
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // kiem tra do dai
    if (strlen(s) < 8)
        return -1;
    if (strlen(s) > 20)
        return -2;

    // chuyen thanh str
    string S = "", Email = "";
    for (int i = 0; i < strlen(s); i++)
        S = S + s[i];
    for (int i = 0; i < strlen(email); i++)
        Email = Email + email[i];

    // kiem tra chua chuoi
    string se = Email.substr(0,Email.find('@'));
    if (S.find(se) < S.size())
        return -(300 + S.find(se));

    // kiem tra ky tu lien tiep
    char kt = S[0];
    int dem = 0;
    bool ktdb = 0;
    for (int i = 1; i < S.size(); i++)
    {
        if (S[i] == kt)
            dem++;
        else
            dem = 0;
        if (dem == 3)
            return -(400 + i - 2);
        if (S[i] == '@' || S[i] == '!' || S[i] == '%' || S[i] == '$' || S[i] == '!')
            ktdb = 1;
    }
    if (ktdb == 0)
        return -5;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int count_pwds[30] = {0};
    for (int i = 0; i < num_pwds; i++)
        {
            for (int j = 0; j <= i; j++)
                if (arr_pwds[i] = arr_pwds[j])
                {
                    count_pwds[j]++;
                    break;
                }
        }

    int k = 0;
    for (int i = 1; i < 20; i++)
        if (count_pwds[k] < count_pwds[i] ||
            (count_pwds[i] != 0 && count_pwds[k] == count_pwds[i] && strlen(arr_pwds[k]) < strlen(arr_pwds[i])))
            k = i;
    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
