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

// Xay dung ham thiet lap lai gia tri
int ReEx(int &Ex)
{
    if (Ex > 600)
        Ex = 600;
    if (Ex < 0)
        Ex = 0 ;
    return Ex ;
}
int ReHp ( int &Hp)
{
    if (Hp > 666)
        Hp = 666;
    if (Hp < 0)
        Hp = 0 ;
    return Hp ;
}
int ReM( int &M)
{
    if (M > 3000)
        M = 3000;
    if (M < 0)
        M = 0 ;
    return M ;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (0 <= e1 and e1 <= 3)
    {
        if( e1 == 0)
            exp2 += 29;
        if( e1 == 1)
            exp2 += 45;
        if( e1 == 2)
            exp2 += 75;
        if( e1 == 3)
            exp2 += 149 ;


        int D = e1 * 3 + exp1 * 7 ;

        if( D % 2 == 0){
            exp1 +=  ceil(1.0 * D / 200) ;
            }
       else {
            exp1 -= D / 100 ;
            }
    }


    else if(4 <= e1 and e1 <= 99)
    {
        if( 4 <= e1 and e1 <= 19)
            exp2 += ceil(1.0 * e1/4) + 19 ;
        if( 20 <= e1 and e1 <= 49)
            exp2 += ceil(1.0 * e1/9) + 21 ;
        if( 50 <= e1 and e1 <= 65 )
            exp2 += ceil(1.0 * e1/16) + 17 ;
        if( 66 <= e1 and e1 <= 79)
        {
            exp2 += ceil(1.0 * e1/4) + 19 ;
            if(exp2  >= 200)
            {
                exp2 += ceil(1.0 * e1/9) + 21 ;
            }

        }
        if(80 <= e1 and e1 <= 99)
        {
            exp2 += ceil(1.0 * e1/4 + 1.0 * e1/9) + 19 + 21 ;
            if(exp2 >= 400)
            {
                 exp2 += ceil(1.0* e1/16) + 17 ;
                 exp2 = ceil( 1.0 * 115/100 * exp2) ;
            }
        }
        exp1 = exp1 - e1;
        }
    else
        return -99 ;
    ReEx(exp1) ;
    ReEx(exp2) ;
    return exp1 + exp2;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if( E2 < 0 and E2 > 99)
        return -99 ;
    else
    {
    float P1 , P2 , P3 , P ;
    // Con duong thu nhat
    int a= sqrt(EXP1), b = ceil(sqrt(EXP1)) , S ;
    if ( (EXP1 - a * a < b * b - EXP1) or EXP1 == 0 )
    {
        S= a * a ;
        P1 = 100 ;
    }
    else
    {
        S = b * b ;
        P1 = (1.0 * EXP1 / S + 80) / 123 * 100;
    }

    //Con duong thu 2

        int MF = ceil( M1 / 2) ,MP = 0 ;
        if(E2 % 2 == 0)
        {
            if( M1 > 0){
                if(HP1 < 200)
                {
                    HP1 += ceil(0.3 * HP1) ;
                    M1-= 150 ;
                }
               else if  (HP1 >= 200)
                {
                    HP1 += ceil(0.1 * HP1);
                    M1 -= 70 ;
                }
                ReHp(HP1) ;
                ReM(M1) ;
            }
            if( M1 > 0){
                if(EXP1 < 400)
                {
                   M1 -= 200;
                }
               else
                {
                    M1 -= 120 ;
                }
                EXP1 += ceil(0.13 * EXP1) ;
                ReEx(EXP1);
                ReM(M1) ;
            }

            if( M1 > 0 )
            {
                if(EXP1 < 300)
                    M1 -= 100 ;
                else if( EXP1 >= 300)
                    M1 -= 120 ;
                EXP1 = ceil(0.9 * EXP1) ;
                ReM(M1) ;
                ReEx(EXP1) ;
            }

            HP1 = ceil(0.83 * HP1) ;
            EXP1 = ceil( 1.17 * EXP1) ;
            ReHp(HP1) ;
            ReEx(EXP1) ;

        }
        else
        {
            while( MP <= MF)
            {
                 if(HP1 < 200)
                {
                    HP1 += ceil(0.3 * HP1) ;
                    M1-= 150 ;
                    MP += 150 ;

                }
               else
                {
                    HP1 += ceil(0.1 * HP1);
                    M1 -= 70 ;
                    MP += 70;
                }
                ReM(M1) ;
                ReHp(HP1) ;
                if(MP > MF)
                    break ;

                 if(EXP1 < 400)
                {
                   M1 -= 200;
                   MP += 200 ;
                }
                else
                {
                    M1 -= 120 ;
                    MP += 120 ;
                }
                EXP1 += ceil(0.13 * EXP1) ;
                ReM(M1) ;
                ReEx(EXP1);

                if(MP > MF)
                    break ;

                if(EXP1 < 300)
                {
                    M1 -= 100 ;
                    MP += 100 ;
                }
                else
                {
                    M1 -= 120 ;
                    MP += 120 ;
                }
                EXP1 = ceil(0.9 * EXP1) ;
                ReM(M1) ;
                ReEx(EXP1);
            }
            HP1 = ceil(0.83 * HP1) ;
            EXP1 = ceil( 1.17 * EXP1) ;
            ReHp(HP1) ;
            ReEx(EXP1) ;
        }
         if ( (EXP1 - int(sqrt(EXP1)) * int(sqrt(EXP1)) <= ceil(sqrt(EXP1)) * ceil(sqrt(EXP1)) - EXP1) or EXP1 == 0 )
        {
            S= sqrt(EXP1) * sqrt(EXP1) ;
            P2 = 100 ;
        }
        else
        {
            S = sqrt(EXP1) * sqrt(EXP1) ;
            P2 = (1.0 * EXP1 / S + 80) / 123 * 100  ;
        }



        // cong duong thu 3
        int Percent[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11} ;
        if ( 0 <= E2 <= 9)
            P3 = Percent[E2] ;
        if( 10 <= E2 <= 99)
        {
            int A = 0 , B = 0 ;
            A = E2 % 10 + E2 / 10 ;
            B = A % 10 ;
            P3 = Percent[B] ;
        }

        // Xu ly yeu cau phu
        if ( P1 == 100 and  P2 == 100 and P3 == 100)
            EXP1 = ceil ( 0.75 * EXP1) ;
        else
        {
            P = (P1 + P2 + P3) / 3 ;


            if ( P < 50)
            {
                HP1 = ceil ( 0.85 * HP1) ;
                EXP1 = ceil(1.15 * EXP1) ;
            }
            else
            {
                 HP1 = ceil ( 0.9 * HP1) ;
                EXP1 = ceil(1.2 * EXP1) ;
            }

            ReHp(HP1) ;
            ReEx(EXP1) ;
        }


        return HP1 + EXP1 + M1;
        }
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //Lap bang gia tri cua xe taxi
    int a[10][10] , b = 0 ,  c = 0 ;
    for(int i = 0 ; i < 10 ; i ++)
    {
        for( int j = 0 ; j < 10 ; j ++)
        {
            a[i][j] = (E3 * j + (i * 2))*( i - j) ;

        }
    }
    // xac dinh vi tri gap nhau
    for( int i = 0 ; i < 10 ; i ++)
    {
        for( int j = 0 ; j < 10 ; j ++)
        {
            if(a[i][j] > E3 * 2)
                b += 1 ;
            if( a[i][j] < - E3)
                c += 1;
        }
    }
    while( b / 10 != 0 )
        {
            b = b / 10 + b % 10 ;
        }
        while( c / 10 != 0 )
        {
            c = c / 10 + c % 10 ;
        }
    // Xac dinh gia tri lon nhat cua duong cheo trai va phai
    int Max = a[b][c] ;

    int d1 , e1 , loop1 ;
    if ( b > c )
        {
        d1 = b - c  ; e1 = 0 ;
        loop1 = 10 - d1 ;
        }
    else if ( c > b )
        {
        d1 = 0 ; e1 = c - b ;
        loop1 = 10 - e1 ;
        }
    else if( b = c)
        {
        d1 = e1 ;
        loop1 = 10 ;
        }

    for ( int k = 0 ; k < loop1 ; k ++)
    {
        if(a[d1 + k][e1 + k] > Max)
        {

            Max = a[d1 + k ][e1 + k] ;
        }
    }

    for( int k = 0 ; b + k < 10 and c - k >= 0; k ++)
    {
        if (a[b+k][c-k] > Max)
        Max = a[b + k][c -k] ;
    }
    for( int k = 0 ; b - k >= 0 and c + k < 10; k ++)
    {
        if (a[b - k][c + k] > Max)
        Max = a[b + k][c -k] ;
    }


    if( Max * Max >= a[b][c] * a[b][c])
    {
        EXP1 = ceil( 1.12 * EXP1);
        EXP2 = ceil( 1.12 * EXP2);
        HP1 = ceil( 1.1 * HP1) ;
        HP2 = ceil( 1.1 * HP2) ;
        ReEx(EXP1) ;
        ReEx(EXP2) ;
        ReHp(HP1) ;
        ReHp(HP2);
        return Max ;

 }
    else
    {
        EXP1 = ceil( 0.88 * EXP1) ;
        EXP2 = ceil( 0.88 * EXP2);
        HP1 = ceil( 0.9 * HP1) ;
        HP2 = ceil( 0.9 * HP2) ;
        ReEx(EXP1) ;
        ReEx(EXP2) ;
        ReHp(HP1) ;
        ReHp(HP2);
        return a[b][c] ;

    }
    return -1;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100] ;
    int pos = 0;
    while(email[pos] != '@') se[pos++] = email[pos];
    se[pos] = '\0';
    const char *p = strstr(s , se) ; // tim vi tri trung nhau
    // tim vi tri co cac ki tu lien tiep trung nhau
    int sci = 0 , b ;
    for(int i = 0 ; i < strlen(s) ; i ++)
    {
        if( s[i] == s[i + 1] and s[i + 1] == s[i + 2])
        {
            sci = i ;
            b = 1 ;
            break;
        }
        else b = 0 ;
    }
    //tim xem trong se co chua cac ki tu dac biet khong
    int loop = 0 ;
    for( int i = 0 ; i < strlen(s) ; i ++)
    {
        if (s[i] == '@' or s[i] == '#' or s[i] == '%' or s[i] == '$' or s[i] == '!' )
            loop += 1 ;
    }
    //kiem tra xem trong s co chua cac ki tu khong hop le
    int kt , adr ;
    for( int i = 0 ; i < strlen(s) ; i ++)
    {
        if(( (int)s[i] >= 64 and (int)s[i] <= 90) or ( (int)s[i] >= 97 and (int)s[i] <= 122 ) or (s[i] == '@' or s[i] == '#' or s[i] == '%' or s[i] == '$' or s[i] == '!') or (s[i] >= 48 and s[i] <= 57))
        {
            kt = 0 ;
        }
        else
        {
            kt = 1 ;
            adr = i ;
            break ;
        }
    }
    // xu ly ket qua tra ve
    if(strlen(s) <8 )
        return -1 ;
    else if(strlen(s) > 20)
        return -2 ;
    else if(p)
        return -(300 + (p - s))  ;
    else if(b)
        return -(400 + sci) ;
    else if(loop == 0)
        return -5 ;
    else if( kt )
        return adr ;
    else
        return -10 ;

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int a[30] ,b[30]  ,max1 = 0 , max2 = 0 , pos ;
    for (int i = 0 ; i < num_pwds ; i++)
        a[i] = 0 ;

    for( int i = 0 ; i < num_pwds ; i++)
    {
        a[0] = 1 ;
        for( int j = 0 ; j < i ; j++)
        {
            if( arr_pwds[i] == arr_pwds[j])
            {
                a[j] += 1 ;
                a[i] = 0 ;
                break;
            }
            else
                a[i] = 1 ;
        }
    }
    for( int i = 0 ; i < num_pwds ; i++)
    {
        if( a[i] != 0)
        {
            b[i] = strlen(arr_pwds[i]);
        }
         if( a[i] > max1)
            max1 = a[i];
    }

    for ( int i = 0 ; i < num_pwds; i ++)
    {
        if( a[i] == max1)
        {
            if(b[i] > max2)
            {
                max2 = b[i] ;
                pos = i ;
            }
        }
    }
return pos ;
return -1 ;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
