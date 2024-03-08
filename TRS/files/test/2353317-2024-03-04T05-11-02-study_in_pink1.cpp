#include "study_in_pink1.h"
#define stc(a) static_cast<float>(a)
#define c(b) ceil(b)

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
void checkhp(int &hp)
{
    if(hp > 666)
        hp = 666;
    if(hp < 0)
        hp = 0;
        return;
}
void checkexp(int &exp)
{
    if(exp > 600)
        exp = 600;
    if(exp < 0)
        exp = 0;
        return;
}
void checkm(int &m)
{
    if(m > 3000)
        m = 3000;
    if(m < 0)
        m = 0;
    return;
}
bool checke(int &e)
{
    if(e > 99 || e < 0)
    {
        return 0;
    }
    return 1;
}

int firstMeet(int & exp1, int & exp2, int e1)
{
    //check e
    if(checke(e1) == 0)
        return -99;
    checkexp(exp1);
    checkexp(exp2);
    //case 1
    if(e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0://tt1
            exp2 += 29;
            break;

        case 1://tt2
            exp2 += 45;
            break;

        case 2://tt3
            exp2 += 75;
            break;

        case 3://tt4
            exp2 += (29 + 45 + 75);
            break;
        }
        checkexp(exp2);

        long int D;
        D = e1 * 3 + exp1 * 7;
        if(D % 2 == 0)
        {
            exp1 = c(exp1 + D/200.0);
        }
        else
        {
            exp1 = c(exp1 - D/100.0);
        }
        checkexp(exp1);
    }

    else //case 2
    {
        if(e1 >= 4 && e1 <= 19)//tt1
        {
            exp2 += (c(stc(e1) /4.0) + 19);
        }

        if(e1 >= 20 && e1 <= 49)//tt2
        {
            exp2 += (c(stc(e1) /9.0)) + 21;
        }

        if(e1 >= 50 && e1 <= 65)//tt3
        {
            exp2 += (c(stc(e1) /16.0) + 17);
        }

        if(e1 >= 66 && e1 <= 79)//tt4
        {
            exp2 += (c(stc(e1) /4.0) + 19);
            if(exp2 > 200)
                exp2 += (c(stc(e1) /9.0) + 21);
        }

        if(e1 >= 80 && e1 <= 99)//tt5
        {
            exp2 += (c(stc(e1) /4.0) + 19);
            exp2 += (c(stc(e1) /9.0) + 21);

            if(exp2 > 400)
            {
                exp2 += (c(stc(e1) /16.0) + 17);
                exp2 = c(exp2*1.15);
            }
        }
        exp1 -= e1;
    }
    checkexp(exp1);
    checkexp(exp2);
    return exp1 + exp2;
}

bool checkM2(int &m1, int m2)
{
    if(m1 <= m2)
        return 1;
    return 0;
}

void event1(int &HP1, int &M1, int &_M1)
{
    if(HP1 < 200)
    {
        HP1 += c(stc(HP1)*0.3);
        M1 -= 150;
        _M1 += 150;
    }
    else
    {
        HP1 += c(stc(HP1)*0.1);
        M1 -= 70;
        _M1 += 70;
    }
    checkhp(HP1);
    checkm(M1);
    return;
}

void event2(int &EXP1, int &M1, int &_M1)
{
    if(EXP1 < 400)
    {
        M1 -= 200;
        _M1 += 200;
        EXP1 += c(stc(EXP1)*0.13);
    }
    else
    {
        M1 -= 120;
        _M1 += 120;
        EXP1 += c(stc(EXP1)*0.13);
    }
    checkexp(EXP1);
    checkm(M1);
    return;
}

void event3(int &EXP1, int &M1, int &_M1)
{
    if(EXP1 < 300)
    {
        M1 -= 100;
        _M1 += 100;
    }
    else
    {
        M1 -= 120;
        _M1 += 120;
    }
    EXP1 = c(stc(EXP1)*0.9);
    checkexp(EXP1);
    checkm(M1);
    return;
}

bool checkm0(int &M1)
{
    if (M1 == 0)
    {
        return 0;
    }
    else return 1;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    //check e
    if(checke(E2) == 0)
        return -99;
    checkhp(HP1);
    checkexp(EXP1);
    checkm(M1);
    //Road 1
    float S,P1;
    S = sqrt(stc(EXP1));
    if(S >= round(S))
    {
        P1 = 1;
    }
    else
    {
        P1 = ((stc(EXP1)/(S*S)) + 80) / 123.0;
    }
    //Road 2
    int in_M1 = M1; //intial money
    int _M1 = 0; //used money
    if(E2 % 2 == 1) //e2 ?
    while(M1)
    {
        //eating
            event1(HP1,M1,_M1);
            if(!checkM2(_M1, (stc(in_M1)/2)))
                break;
        //transporting
            event2(EXP1,M1,_M1);
            if(!checkM2(_M1, (stc(in_M1)/2)))
                break;
        //meeting homeless
            event3(EXP1,M1,_M1);
            if(!checkM2(_M1, (stc(in_M1)/2)))
                break;
    }
    else
    {
        if(checkm0(M1) == 0)
            goto A;
        event1(HP1,M1,_M1);
        checkm(M1);
        if(checkm0(M1) == 0)
            goto A;
        event2(EXP1,M1,_M1);
        checkm(M1);
        if(checkm0(M1) == 0)
            goto A;
        event3(EXP1,M1,_M1);
        checkm(M1);
    }
    A:HP1 = c(stc(HP1) * 0.83);
    checkhp(HP1);
    EXP1 = c(stc(EXP1) * 1.17);
    checkexp(EXP1);
    float P2;
    S = sqrt(stc(EXP1));
    if(S >= round(S))
    {
        P2 = 1;
    }
    else
    {
        P2 = ((stc(EXP1)/(S*S)) + 80) / 123.0;
    }

    //Road 3
    float P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};//given by the question
    int i = 0;
    if((E2 / 10) != 0)
    {
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    else i = E2;
    //conclusion
    if(P1 == 1 && P2 == 1 && P[i]/100 == 1)
    {
        EXP1 = c(stc(EXP1) * 0.75);
        checkexp(EXP1);
    }
    else if((stc(P1 + P2 + P[i]/100)/3.0) < 0.5)
    {
        HP1 = c(stc(HP1) * 0.85);
        checkhp(HP1);
        EXP1 = c(stc(EXP1) * 1.15);
        checkexp(EXP1);
    }
    else
    {
        HP1 = c(stc(HP1) * 0.90);
        checkhp(HP1);
        EXP1 = c(stc(EXP1) * 1.20);
        checkexp(EXP1);
    }
    return HP1 + EXP1 + M1;
}

int ce(float a)
{
    if(a - static_cast<int>(a) > 0.001)
        return static_cast<int>(a) + 1;
    else return static_cast<int>(a);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //check e
    if(checke(E3) == 0)
        return -99;
    checkhp(HP1);
    checkexp(EXP1);
    checkhp(HP2);
    checkexp(EXP2);
    //make matrix
    long long int arr[11][11];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //find i j
    int ai = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i][j] > (E3 * 2))
                ai++;
        }
    }
    while(ai >= 10)
    {
        ai = ((ai / 10) + (ai % 10));
    }

    int aj = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 9; j > i; j--)
        {
            if(arr[i][j] < -E3 )
                aj++;
        }
    } 
    while(aj >= 10)
    {
        aj = ((aj / 10) + (aj % 10));
    }
    //taxi
    int taxi = arr[ai][aj];
    //Sirlock and Whatson
    int rd = ai + aj;
    int ld = ai - aj;
    int SW = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if( i + j == rd || i - j == ld)
            {
                int num = arr[i][j];
                if(num > SW)
                    SW = num;
            }
        }
    }
    //compare
    if(abs(taxi) > SW)
    {
        EXP1 = ce(stc(EXP1) * 0.88);
        EXP2 = ce(stc(EXP2) * 0.88);
        HP1 = ce(stc(HP1) * 0.90);
        HP2 = ce(stc(HP2) * 0.90);
        checkexp(EXP1);
        checkexp(EXP2);
        checkhp(HP1);
        checkhp(HP2);
        return taxi;
    }
    else
    {
        EXP1 = ce(stc(EXP1) * 1.12);
        EXP2 = ce(stc(EXP2) * 1.12);
        HP1 = ce(stc(HP1) * 1.10);
        HP2 = ce(stc(HP2) * 1.10);
        checkexp(EXP1);
        checkexp(EXP2);
        checkhp(HP1);
        checkhp(HP2);
        return SW;
    }
}   

int checkpass(string s, string se)
{
    if(s.length() < 8)
        return -1;
    if(s.length() > 20)
        return -2;
    if(s.find(se) < s.length())
        return -300 - s.find(se);
    for(int i = 0; i < s.length() - 2; i++)
    {
        if(s[i] == s[i+1] && s[i+1] == s[i+2])
        return -400 - i;
    }
    bool _bool = 0;
    for(int i = 0; i < s.length() + 1; i++)
    {
        if(s[i] == 33 || (s[i] >= 35 && s[i] <= 37) || s[i] == 64)
           {
                _bool = 1;
                break;
           }
    }
    if(!_bool)
        return -5;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 33 || (s[i] >= 35 && s[i] <= 37) || (s[i] >= 48 && s[i] <= 57) || (s[i] >= 64 && s[i] <= 90 || (s[i] >= 97 && s[i] <= 122)))
            continue;
        else return i;
    }
        return -10;
}

int checkPassword(const char * s, const char * email) {
    string _email = email;
    string se;
    string _s = s;
    //find se
    se = _email.substr(0,_email.find('@'));

    //check condition
    return checkpass(s,se);
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds = 200) {
    string arr_pw[num_pwds]; //= {"0"};
    for(int i = 0; i < num_pwds ; i++)
    {
        arr_pw[i] = arr_pwds[i]; 
    }
    int number[num_pwds]; //= {0};//times the password appear
    for(int i = 0; i < num_pwds ; i++)
        number[i] = {0};
    string pass[num_pwds]; //= {"0"};//string to write down pass with the same max appearance
    for(int i = 0; i < num_pwds ; i++)//finding the times that the pass appear
    {
        for(int j = 0; j <= i; j++)
        {
            if(arr_pw[i] == arr_pw[j])
            {
                number[j]++;
                break;
            }
        }
    }

    int num_max = 0;//max time they appear
    for(int i = 0; i < num_pwds ; i++)
    {
        if(number[i] > num_max)
        {
            num_max = number[i];
        }
    }

    for(int i = 0; i < num_pwds ; i++)//which of them appear
    {
        if(num_max == number[i])
        {
            pass[i] = arr_pw[i];
        }
    }
    int index = 0, length = 0;//compare there length if they have the same amount of time
    for(int i = 0; i < num_pwds ; i++)
    {
        if(pass[i].length() > length)
            {
                index = i;
                length = pass[i].length();
            }
    }
    //return the value
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////