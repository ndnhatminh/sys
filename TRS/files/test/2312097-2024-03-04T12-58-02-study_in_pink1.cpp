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

#define MaxHP  666
#define MaxEXP 600

#define CheckHP(a)    (a) > MaxHP  ? MaxHP  : (a) < 0 ? 0 : (a)
#define CheckEXP(a)   (a) > MaxEXP ? MaxEXP : (a) < 0 ? 0 : (a)
#define ChangeHP(a,b)  a  = CheckHP (a + ceil(b))
#define ChangeEXP(a,b) a  = CheckEXP(a + ceil(b))

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    // Kiem tra gioi han e1
    if (e1 <0 || e1 > 99)
        return -99;
    // [0,3]
    if (e1 <= 3)
    {
          e1 == 0  ?  ChangeEXP(exp2, 29)
        : e1 == 1  ?  ChangeEXP(exp2, 45)
        : e1 == 2  ?  ChangeEXP(exp2, 75)
        :             ChangeEXP(exp2, 29 + 45 + 75);

        int D = e1*3 + exp1*7;
        D % 2 == 0 ?  ChangeEXP(exp1, D/200.0)
                   :  ChangeEXP(exp1, -D/100.0);
    }
    else // [4,99]
    {
          e1 <= 19 ?  ChangeEXP(exp2, e1/4.0  + 19)
        : e1 <= 49 ?  ChangeEXP(exp2, e1/9.0  + 21)
        : e1 <= 65 ?  ChangeEXP(exp2, e1/16.0 + 17)
        : e1 <= 79 ? (ChangeEXP(exp2, e1/4.0  + 19))
                   + (exp2 > 200 ? ChangeEXP(exp2, e1/9.0 + 21)  : 0)
        :            (ChangeEXP(exp2, e1/4.0  + 19))
                   + (ChangeEXP(exp2, e1/9.0  + 21))
                   + (exp2 > 400 ? (ChangeEXP(exp2, e1/16.0 + 17)) + (ChangeEXP(exp2, exp2*15.0/100)): 0);

        ChangeEXP(exp1, -e1);
    }

    return exp1 + exp2;
}


#define S(EXP1)     (round(sqrt(EXP1)) * round(sqrt(EXP1)))
#define path1(EXP1) (EXP1   >= S(EXP1) ? 100                                     : ceil(((double) EXP1/S(EXP1) + 80)/123*100))

#define checkMoney  (E2 % 2 == 1       ? (m > M1/2 || M1 == 0 ? 1 : 0)           : (m >= M1 ? 2 : 0)                         )
#define path2_sk1   (HP1    <  200     ? (ChangeHP(HP1,HP1*30.0/100)) + (m+=150) : (ChangeHP(HP1,HP1*10.0/100)) + (m+=70)    )
#define path2_sk2   (EXP1   <  400     ?  m += 200                               :  m += 120                                 ) + (ChangeEXP(EXP1,EXP1*13.0/100))
#define path2_sk3   (EXP1   <  300     ?  m += 100                               :  m += 120                                 ) + (ChangeEXP(EXP1,-EXP1*10.0/100))

int     P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
#define path3(E2)   (E2     <  10      ?  P[E2]                                  :  P[((E2%10) + (E2/10)) % 10]              )

int path2(int & HP1, int & EXP1, int & M1, int E2, int &m)
{
    if (!checkMoney)
        path2_sk1;
    if (!checkMoney)
        path2_sk2;
    if (!checkMoney)
        path2_sk3;

    if (!checkMoney && E2 % 2 == 1)
        return path2(HP1, EXP1, M1, E2, m);

    ChangeHP(HP1,-HP1*17.0/100);
    ChangeEXP(EXP1,EXP1*17.0/100);
    M1 = M1 - m < 0 ? 0 : M1 - m;
    return path1(EXP1);
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // Kiem tra gioi han E2
    if (E2 < 0 || E2 > 99)
        return -99;

    int m = 0,
        P1 = path1(EXP1),
        P2 = path2(HP1, EXP1, M1, E2, m),
        P3 = path3(E2);

       P1 == 100 && P2 == 100 && P3 == 100 ?  ChangeEXP(EXP1,-EXP1*25.0/100)
    : (P1 + P2 + P3)/3 < 50                ? (ChangeHP(HP1,-HP1*15.0/100))
                                           + (ChangeEXP(EXP1,EXP1*15.0/100))
    :                                        (ChangeHP(HP1,-HP1*10.0/100))
                                           + (ChangeEXP(EXP1,EXP1*20.0/100));
    return HP1 + EXP1 + M1;
}

// Task 3

#define Map(i,j) ((E3*j)+(i*2))*(i-j)

int Value(int i0, int j0, int E3)
{
    int Max = Map(i0,j0);
    for (int i = i0, j = j0; i >= 0 && j >= 0; (i--)+ (j--))
        Max = Max < Map(i,j) ? Map(i,j)
                             : Max;

    for (int i = i0, j = j0; i >= 0 && j <= 9; (i--) + (j++))
        Max = Max < Map(i,j) ? Map(i,j)
                             : Max;

    for (int i = i0, j = j0; i <= 9 && j >= 0; (i++) + (j--))
        Max = Max < Map(i,j) ? Map(i,j)
                             : Max;

    for (int i = i0, j = j0; i <= 9 && j <= 9; (i++) + (j++))
        Max = Max < Map(i,j) ? Map(i,j)
                             : Max;

    return abs(Max);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    if (E3 < 0 || E3 > 99)
        return -99;

    int i0 = 0, j0 = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
              Map(i,j) >  E3*2 ? i0++
            : Map(i,j) < -E3   ? j0++
            : 0;

    while (i0 >= 10)
        i0 = i0%10 + i0/10%10 + i0/100%100;
    while (j0 >= 10)
        j0 = j0%10 + j0/10%10 + j0/100%100;


    if (abs(Map(i0,j0)) > Value(i0, j0, E3))
    {
        ChangeEXP(EXP1, -EXP1*12.0/100);
        ChangeEXP(EXP2, -EXP2*12.0/100);
        ChangeHP (HP1,  -HP1*10.0/100);
        ChangeHP (HP2,  -HP2*10.0/100);
        return    Map(i0,j0);
    }
    else
    {
        ChangeEXP(EXP1, EXP1*12.0/100);
        ChangeEXP(EXP2, EXP2*12.0/100);
        ChangeHP (HP1,  HP1*10.0/100);
        ChangeHP (HP2,  HP2*10.0/100);
        return    Value(i0, j0, E3);
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

    int Kytu_Lientuc = 1,
        Kytu_fail = -1;
    bool Kytu_Dacbiet = 0;
    for (int i = 0; i < S.size(); i++)
    {
        i != 0 && S[i] == S[i-1] ? Kytu_Lientuc++
                                 : Kytu_Lientuc = 1;
        if (Kytu_Lientuc == 3)
            return -(400 + i - 2);
        if (!((S[i] >= 48 && S[i] <= 57) || (S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122)))
            if (S[i] == '@' || S[i] == '#' || S[i] == '%' || S[i] == '$' || S[i] == '!')
                Kytu_Dacbiet = 1;
            else if (Kytu_fail == -1)
                Kytu_fail = i;
    }
    if (Kytu_Dacbiet == 0)
        return -5;
    if (Kytu_fail != -1)
        return Kytu_fail;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {

    int count_pwds[num_pwds] = {0};

    string Arr_pwds[num_pwds] = {""};
    for (int i = 0; i < num_pwds; i++)
        for (int j = 0; j < strlen(arr_pwds[i]); j++)
            Arr_pwds[i] = Arr_pwds[i] + arr_pwds[i][j];

    for (int i = 0; i < num_pwds; i++)
        for (int j = 0; j <= i; j++)
            if (Arr_pwds[i] == Arr_pwds[j])
            {
                count_pwds[j]++;
                break;
            }

    int k = 0;
    for (int i = 1; i < num_pwds; i++)
        if (count_pwds[k] < count_pwds[i] ||
            (count_pwds[i] != 0 && count_pwds[k] == count_pwds[i] && Arr_pwds[k].size() < Arr_pwds[i].size()))
            k = i;
    return k;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
