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


int HP (int & hp)
{
    if ( hp < 0)
    {
        hp = 0;
    }

    if ( hp > 666)
    {
        hp = 666;
    }

    return hp;

}

int EXP (int & exp)
{
    if ( exp > 600)
    exp = 600;

    if ( exp < 0)
    exp =0;

    return exp;
}

int Money (int & m)
{
    if ( m > 3000)
    m = 3000;

    if ( m < 0)
    m = 0;

    return m;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ( e1 >= 0 && e1 <= 3)
    {
        // tinh exp2
        if ( e1 == 0)
        {
            exp2 += 29;
            exp2 = EXP(exp2);
        }
        else if ( e1 == 1)
        {
            exp2 += 45;
            exp2 = EXP(exp2);
        }
        else if ( e1 == 2)
        {
            exp2 += 75;
            exp2 = EXP(exp2);
        }
        else if ( e1 == 3)
        {
            exp2 += (29+45+75);
            exp2 = EXP(exp2);
        }

        // tinh D
        int D = e1 * 3 + exp1 * 7;

        if (D%2==0)
        {
            float ex1 = float (exp1) + float(D)/200;
            exp1 = int (ceil(ex1));
            exp1 = EXP (exp1);
        }
        else 
        {
            float ex1 = float (exp1) - float (D)/100;
            exp1 = int (ceil(ex1));
            exp1 = EXP (exp1);
        }
    }
    //TH2:
    else if ( e1 >= 4 && e1 <= 99)
    {
        if ( e1 >= 4 && e1 <= 19)
        {
            float a = float(exp2) + ((float(e1)/4) + 19);
            exp2 = int (ceil(a));
            exp2 = EXP(exp2);
        }
        else if ( e1 >= 20 && e1 <= 49)
        {
            float a = float (exp2) + ((float(e1)/9) + 21);
            exp2 = int (ceil(a));
            exp2 = EXP(exp2);
        }
        else if ( e1 >= 50 && e1 <= 65)
        {
            float a = float (exp2) + ((float(e1)/16) + 17);
            exp2 = int (ceil(a));
            exp2 = EXP(exp2);
        }
        else if ( e1 >= 66 && e1 <= 79)
        {
            float a = float(exp2) +  ((float(e1)/4) + 19);
            exp2 = int (ceil(a));
            exp2 = EXP(exp2);

            if ( exp2 > 200)
            {
                float a = float (exp2) + ((float(e1)/9) + 21);
                exp2 = int (ceil(a));
                exp2 = EXP(exp2);
            }
        }
        else if ( e1 >= 80 && e1 <= 99)
        {
            float a = float(exp2) + ((float(e1)/4) + 19);
            exp2 = int (ceil(a));
            exp2 = EXP(exp2);

            float b = float (exp2) + ((float(e1)/9) + 21);
            exp2 = int (ceil(b));
            exp2 = EXP(exp2);

            if (exp2 > 400)
            {
                float a = float (exp2) + ((float(e1)/16) + 17);
                exp2 = int (ceil(a));
                exp2 = EXP(exp2);

                float b = float (exp2) + (float(exp2)*15/100);
                exp2 = int (ceil(b));
                exp2 = EXP(exp2);
            }
        }

        exp1 -= e1;
        exp1 = EXP(exp1);
    }
    else
    return -99;
    
    exp1 = EXP(exp1);
    exp2 = EXP(exp2);    
    return exp1 + exp2;
}

// Task 2

float FindS (int & EXP1)
{
    float p;
    int b = round (sqrt(EXP1));
    int S = b*b;
    if (EXP1 >= S)
    p = 100;
    else
    {
        p = ((float(EXP1)/S)+80)/123;
        p *=100;
    }
    return p; 
}
float road2odd( int & HP1, int & EXP1, int & M1)
{
    int money1 = M1 /2;
    int money2 = 0;

    while (true)
    {
        //check 
        if (money2 > money1)
        break;
        //mua do an
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 + HP1 * 0.3);
            HP1 = HP (HP1);
            money2 += 150;
            M1 -= 150;
            M1 = Money(M1);
        }
        else
        {
            HP1 = ceil (HP1 + HP1*0.1);
            HP1 = HP (HP1);
            money2 += 70;
            M1 -= 70;
            M1 = Money(M1);
        }
        //thue taxi
        if (money2 > money1)
        break;

        if (EXP1 < 400)
        {
            money2 += 200;
            M1 -= 200;
            M1 = Money(M1);
        }
        else
        {
            money2 += 120;
            M1 -= 120;
            M1 = Money(M1);
        }

        //auto cong
        EXP1 = ceil(EXP1 + EXP1*0.13);
        EXP1 = EXP(EXP1);

        //vo gia cu
        if (money2 > money1)
        break;

        if (EXP1 < 300)
        {
            money2 += 100;
            M1 -= 100;
            M1 = Money(M1);
        }
        else 
        {
            money2 += 120;
            M1 -= 120;
            M1 = Money(M1);
        }
        //auto tru
        EXP1 = ceil(EXP1 -EXP1*0.1);
        EXP1 = EXP (EXP1);
    }

    HP1 =  ceil(HP1 - HP1*0.17);
    EXP1 = ceil(EXP1 + EXP1*0.17);
    HP1 = HP(HP1);
    EXP1 = EXP(EXP1);

    return FindS(EXP1);
}

float road2even (int & HP1, int & EXP1, int & M1)
{
    for ( int i = 0 ; i < 1; i++)
    {
        if ( Money(M1)==0)
        break;

        // mua do an
        if (HP1 < 200)
        {
            HP1 = ceil(HP1 + HP1 * 0.3) ;
            HP1 = HP (HP1);
            M1 -= 150;
            M1 = Money(M1);
        }
        else
        {
            HP1 = ceil(HP1 + HP1*0.1);
            HP1 = HP (HP1);
            M1 -= 70;
            M1 = Money(M1);
        }

        // thue taxi
        if ( Money(M1) == 0)
        break;

        if (EXP1 < 400)
        {
            M1 -= 200;
            M1 = Money(M1);
        }
        else
        {
            M1 -= 120;
            M1 = Money(M1);
        }

        //auto cong
        EXP1 = ceil(EXP1 + EXP1*0.13);
        EXP1 = EXP (EXP1);

        //vo gia cu
        if ( Money(M1) == 0)
        break;

        if (EXP1 < 300)
        {
            M1 -= 100;
            M1 = Money(M1);
        }
        else 
        {
            M1 -= 120;
            M1 = Money(M1);
        }
        //auto tru
        EXP1 = ceil(EXP1 - EXP1*0.1);
        EXP1 = EXP (EXP1);
    }

    HP1 =  ceil(HP1 - HP1*0.17);
    EXP1 = ceil(EXP1 + EXP1*0.17);
    HP1 = HP(HP1);
    EXP1 = EXP(EXP1);

    return FindS(EXP1);
} 
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    //check E2:
    if ( E2 < 0 || E2 > 99)
    return -99;

    // -------------
    float p1,p2,p3;
    //con duong 01
    p1 = FindS(EXP1);
    //con duong 02
    if (E2 %2 == 0)
    p2 = road2even (HP1, EXP1, M1);
    else
    p2 = road2odd (HP1, EXP1, M1);
    //con duong 03:
    float array[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10)
    {
        p3 = array[E2];
    }
    else 
    {
        int item = (E2/10) + (E2%10);
        item = item % 10;
        p3 = array[item];
    }


    // -------------------------------------------
    if ( p1 == 100 && p2 == 100 && p3 == 100)
    {
        EXP1 = ceil(EXP1 - EXP1*0.25);
        EXP1 = EXP(EXP1);
    }
    else 
    {
        float a = (p1+p2+p3)/3;
        if ( a < 50)
        {
            HP1 = ceil(HP1 -HP1* 0.15);
            EXP1 = ceil(EXP1 +EXP1* 0.15);
            HP1 = HP(HP1);
            EXP1 = EXP(EXP1);
        }
        else 
        {
            HP1 = ceil (HP1 - HP1*0.1);
            EXP1 = ceil (EXP1 + EXP1*0.2);
            HP1 = HP(HP1);
            EXP1 = EXP(EXP1);
        }
    } 
    return HP1 + EXP1 + M1;
}

// Task 3

int matrix[10][10];

//topright
int topright (int i, int j )
{
    int max = INT_MIN;
    while ( !(i < 0 || j > 9))
    {
        if ( matrix[i][j] > max ) 
        max = matrix[i][j];

        i--;
        j++;
    }

    return max;
}

int topleft (int i, int j)
{
    int max = INT_MIN;
    while ( !(i < 0 || j < 0))
    {
        if ( matrix[i][j] > max )
        max = matrix [i][j];

        i--;
        j--;
    }

    return max;
}

int downright (int i, int j)
{
    int max = INT_MIN;
    while ( !(i > 9 || j > 9))
    {
        if ( matrix[i][j] > max )
        max = matrix[i][j];

        i++;
        j++;
    }

    return max;
}

int downleft ( int i, int j)
{
    int max = INT_MIN;
    while ( !(i > 9 || j < 0 ))
    {
        if ( matrix[i][j] > max)
        max = matrix[i][j];

        i++;
        j--;
    }

    return max;
}

int max ( int a, int b, int c, int d)
{
    int max = a;
    if (b > max)
    max = b;

    if (c > max)
    max = c;

    if (d > max)
    max = d;

    return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // create a two_dimentional arrays of taxi
    // i la hang, j la cot

    //check E3:
    if (E3 < 0 || E3 > 99)
    return -99;

    // a la e3*2, b la -e3, n la so duong, m la so am

    int n = 0;
    int m = 0;
    for ( int i = 0; i < 10; i++ )
    {
        for (int j = 0; j < 10; j ++)
        {
            int k = ((E3 * j ) + (i * 2))* (i - j);
            matrix[i][j] = k;
            if ( k > (E3*2))
            n++;
            else if ( k < -E3)
            m++;

        }
    } 

    // tinh gia tri cho n va m:
    while ( n / 10 != 0)
    {
        n = (n%10) + (n/10);
    }

    while ( m / 10 != 0)
    {
        m = (m%10) + (m/10);
    }

    // gia tri cua taxi:
    int taxi = matrix[n][m];

    // gia tri cua sherlock 
    int max1 = topleft(n, m);
    int max2 = topright(n,m);
    int max3 = downleft(n,m);
    int max4 = downright(n,m);

    int sherlock =abs(max (max1, max2, max3, max4));

    //duoi kip or k duoi kip
    if ( abs(taxi) > sherlock)
    {
        EXP1 = ceil(EXP1 - EXP1*0.12);
        EXP1 = EXP (EXP1);
        HP1 = ceil (HP1 - HP1*0.1);
        HP1 = HP (HP1);

        EXP2 = ceil(EXP2 - EXP2*0.12);
        EXP2 = EXP (EXP2);
        HP2 = ceil (HP2 - HP2*0.1);
        HP2 = HP (HP2);

        return taxi;
    }
    else 
    {
        EXP1 = ceil(EXP1 + EXP1*0.12);
        EXP1 = EXP (EXP1);
        HP1 = ceil (HP1 + HP1*0.1);
        HP1 = HP (HP1);

        EXP2 = ceil(EXP2 + EXP2*0.12);
        EXP2 = EXP (EXP2);
        HP2 = ceil (HP2 + HP2*0.1);
        HP2 = HP (HP2);

        return sherlock;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // tao chuoi se

    string s1 = s;
    string se ;
    int length = strlen(email);
    for ( auto i = 0 ; i < length ; i++)
    {
        if ( email[i] == '@')
        break;

        se += email[i];
    }

    // kiem tra email hop le
    if ( length == 100 || se.size() == length)
    return -100;

    // do dai ngan nhat
    if ( strlen(s) < 8 )
    return -1;

    // do dai dai nhat
    if ( strlen(s) > 20 )
    return -2;

    // co chua se
    size_t found = s1.find(se);
    if ( found != string::npos)
    {
        return -(300 + int(found));
    }

    // hai ki tu lien tiep 
    for (int i = 0 ; i < strlen(s); i ++)
    {
        if (s[i]== s[i+1] && s[i]== s[i+2])
        {
            return -(400+i);
        }
    }

    // ki tu dac biet
    int special = 0;
    for ( int i = 0 ; i < strlen(s); i ++)
    {
        if (s[i]=='@'|| s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!')
        {
            special ++;
        }
    }
    if (special == 0)
    {
        return -5;
    }

    // kiem tra ki tu 
    for ( int i = 0 ; i < strlen (s); i ++)
    {
        if (!(s[i]=='@'|| s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'|| (s[i] >= 48 && s[i]<=57) || (s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)))
        return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_times = 0;
    int max_length = 0;
    int result;
    string ans;
    for ( int i = 0 ; i < num_pwds ; i ++)
    {
        int times = 0;
        for ( int j = i ; j < num_pwds; j ++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0)
            {
                times++;
            }
        }

        if (times > max_times)
        {
            ans = arr_pwds[i];
            max_length = ans.size();
            max_times = times;
        }

        if ( times == max_times)
        {
            if ( strlen(arr_pwds[i]) > max_length)
            {
                ans = arr_pwds[i];
                max_length = ans.size();
                max_times = times;
            }
        }
    }

    for ( int i = 0 ; i < num_pwds; i++)
    {
        if (arr_pwds[i]==ans)
        {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////