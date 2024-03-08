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
void statistic(float  EXP1, float  S, float & P1)
{
    if (EXP1 >= S)
    P1 = 100;
    else
    P1 = ( ((EXP1/S) + 80) / 123 ) * 100;
}
void check_condition_EXP1(int & EXP1)
{
     if (EXP1 > 600)
    EXP1 = 600;
    else if (EXP1 < 0)
    EXP1 = 0;
}
void check_condition_EXP2(int & EXP2)
{
    if (EXP2 > 600)
    EXP2 = 600;
    else if (EXP2 < 0)
    EXP2 = 0;
}
void check_condition_HP1(int & HP1)
{
     if (HP1 > 666)
    HP1 = 666;
    else if (HP1 < 0)
    HP1 = 0;
}
void check_condition_HP2(int & HP2)
{
    if (HP2 > 666)
    HP2 = 666;
    else if (HP2 < 0)
    HP2 = 0;
}
void check_balance_M1(int & M1)
{
     if (M1 > 3000)
    M1 = 3000;
    else if (M1 < 0)
    M1 = 0;
}
void check_balance_M2(int & M2)
{
    if (M2 > 3000)
    M2 = 3000;
    else if (M2 < 0)
    M2 = 0;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    /*First of all we need to do condition 1*/
    if (e1 < 0 || e1 > 99)
    return -99;
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        exp2 = exp2 + 29;
        else if (e1 == 1)
        exp2 = exp2 + 45;
        else if (e1 == 2)
        exp2 = exp2 + 75;
        else if (e1 == 3)
        exp2 = exp2 + 29 + 45 + 75;
        int D; //D will depends on e1 and Sherlock EXP.
        D = (e1*1.00) * 3 + exp1 * 7;
        if (D % 2 == 0)
        exp1 = ceil( exp1 + D*0.005); //Afghanistan and +
        else
        exp1 = ceil( exp1 - D*0.01); //Iraq and -
    }
    else if(e1 >= 4 && e1 <= 99) /*This is for condition 2*/
    {
        if (e1 >= 4 && e1 <= 19)
        exp2 = ceil( exp2 + ( (e1*1.00)/4 + 19) );
        else if (e1 >= 20 && e1 <= 49)
        exp2 = ceil( exp2 + ( (e1*1.00)/9 + 21) );
        else if (e1 >= 50 && e1 <= 65)
        exp2 = ceil( exp2 + ( (e1*1.00)/16 + 17) );
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil( exp2 + ( (e1*1.00)/4 + 19) );
            if (exp2 > 200)
            exp2 = ceil( exp2 + ( (e1*1.00)/9 + 21) );
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + ( (e1*1.00)/4 + 19) + ( (e1*1.00)/9 +21) );
            if (exp2 > 400)
            {
            exp2 = ceil( exp2 + ( (e1*1.00)/16 + 17) );
            exp2 = ceil( exp2 + (0.15*exp2) ) ;
            }
        }
        exp1 = exp1 - e1*1.00; //Sherlock is shock about the news lol
    }
    if (exp1 > 600)
    exp1 = 600;
    else if (exp1 < 0)
    exp1 = 0;
    if (exp2 > 600)
    exp2 = 600;
    else if (exp2 < 0)
    exp2 = 0;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
     if(E2 < 0 || E2 > 99)                   //Checking condition of E2
    return -99;
    /*First of all, we need to check if the number given is the perfect square root or not*/
    int S,checking;
    float P1,P2;
    if ( sqrt(EXP1) - floor( (sqrt(EXP1)) ) == 0 )
    checking = 1;
    else
    checking = 0;
    //////////////////////////////
    /*Next up, to consider wherever if the number is not the perfect square root then this will tell us the closest number to the initial number*/
    int increase,decrease,in1,in2;              //in1 is for initial number 1 and so for the in2
    if (checking == 0)
    {
        in1 = EXP1;
        while (true)
        {
            if ( sqrt(in1) - floor( (sqrt(in1)) ) != 0 )
            in1++;
            else break;
        }
        in2 = EXP1;
        while (true)
        {
            if ( sqrt(in2) - floor( (sqrt(in2)) ) != 0 )
            in2--;
            else break;
        }
        if ( in1 - EXP1 <= EXP1 - in2)
        S = in1;                                        //S will be consider wherether if in1 or in2 will be suitable or it will equal to EXP1
        else
        S = in2;
    }
    else
    S = EXP1;
    /////////////////////////////
    /*Next up, we will divise will the road 1*/
    statistic(EXP1,S,P1);
    /*Continue to road 2*/
    check_balance_M1(M1);
    int fee = 0;
    if ( M1 == 0 ) //This is to check the codition if M1 = 0 then it will auto proceed to the end
    {
    HP1 = ceil( HP1 - HP1*0.17 );
    check_condition_HP1(HP1);
    EXP1 = ceil( EXP1 + EXP1*0.17 );
    check_condition_EXP1(EXP1);
    }
    else if (M1 != 0) //This is to check the codition if M1 != 0 then we then can proceed to road 2
    {
        if (E2 % 10 != 0) //if E2 is an odd number
        {
            int M0 = M1;
            while(true)
            {
                if (HP1 < 200)                 //First action that Serlock does
                {
                HP1 = ceil( HP1 + HP1*0.3 );
                check_condition_HP1(HP1);
                M1 = M1 - 150;
                check_balance_M1(M1);
                fee = fee + 150;
                if ( fee > (M0 * (0.5) ) )
                break;
                }
                else
                {
                HP1 = ceil( HP1 + HP1*0.1 );
                check_condition_HP1(HP1);
                M1 = M1 - 70;
                check_balance_M1(M1);
                fee = fee + 70;
                if ( fee > (M0 * 0.5 ) )
                break;
                }
                ////////////////
                if (EXP1 < 400)                //Second action that Serlock does
                {
                    M1 = M1 - 200;
                    check_balance_M1(M1);
                    EXP1 = ceil ( EXP1 + EXP1*0.13 );
                    check_condition_EXP1(EXP1);
                    fee = fee + 200;
                    if ( fee > (M0 * 0.5 ) )
                    break;
                }
                else
                {
                    M1 = M1 - 120;
                    check_balance_M1(M1);
                    EXP1 = ceil ( EXP1 + EXP1*0.13 );
                    check_condition_EXP1(EXP1);
                    fee = fee + 120;
                    if ( fee > (M0 * 0.5 ) )
                    break;
                }
                ///////////////               //Third action that Serlock does
                if (EXP1 < 300)
                {
                M1 = M1 - 100;
                check_balance_M1(M1);
                EXP1 = ceil ( EXP1 - EXP1*0.1 );
                check_condition_EXP1(EXP1);
                fee = fee + 100;
                if ( fee > (M0 * 0.5 ) )
                break;
                }
                else
                {
                M1 = M1 - 120;
                check_balance_M1(M1);
                EXP1 = ceil ( EXP1 - EXP1*0.1 );
                check_condition_EXP1(EXP1);
                fee = fee + 120;
                if ( fee > (M0 * 0.5 ) )
                break;
                }
            }
            HP1 = ceil( HP1 - HP1 * 0.17 );           //Finally checking
            check_condition_HP1(HP1);
            EXP1 = ceil( EXP1 + EXP1 * 0.17 );
            check_condition_EXP1(EXP1);
        }
        else // the other condition if E2 is an even number
        {
            while (true)
            {
                if (HP1 < 200)                 //First action that Serlock does
                {
                HP1 = ceil( HP1 + HP1*0.3 );
                check_condition_HP1(HP1);
                M1 = M1 - 150;
                check_balance_M1(M1);
                if (M1 <= 0)
                break;
                }
                else
                {
                HP1 = ceil( HP1 + HP1*0.1 );
                check_condition_HP1(HP1);
                M1 = M1 - 70;
                check_balance_M1(M1);
                if (M1 <= 0)
                break;
                }
                ////////////////
                if (EXP1 < 400)                //Second action that Serlock does
                {
                    M1 = M1 - 200;
                    check_balance_M1(M1);
                    EXP1 = ceil ( EXP1 + EXP1*0.13 );
                    check_condition_EXP1(EXP1);
                    if (M1 <= 0)
                    break;
                }
                else
                {
                    M1 = M1 - 120;
                    check_balance_M1(M1);
                    EXP1 = ceil ( EXP1 + EXP1*0.13 );
                    check_condition_EXP1(EXP1);
                    if (M1 <= 0)
                    break;
                }
                ///////////////
                if (EXP1 < 300)                //Third action that Serlock does
                {
                M1 = M1 - 100;
                check_balance_M1(M1);
                EXP1 = ceil ( EXP1 - EXP1*0.1 );
                check_condition_EXP1(EXP1);
                if (M1 <= 0)
                break;
                }
                else
                {
                M1 = M1 - 120;
                check_balance_M1(M1);
                EXP1 = ceil ( EXP1 - EXP1*0.1 );
                check_condition_EXP1(EXP1);
                if (M1 <= 0)
                break;
                }
                break;
            }
            ///////////////
            HP1 = ceil( HP1 - HP1 * 0.17 );   //Finally checking and ending of task 2
            check_condition_HP1(HP1);
            EXP1 = ceil( EXP1 + EXP1*0.17 );
            check_condition_EXP1(EXP1);
        }
        if ( sqrt(EXP1) - floor( (sqrt(EXP1)) ) == 0 )
        checking = 1;
        else
        checking = 0;
        //////////////////////////////
        /*Next up, to consider wherever if the number is not the perfect square root then this will tell us the closest number to the initial number*/
        int increase,decrease,in1,in2;              //in1 is for initial number 1 and so for the in2
        if (checking == 0)
        {
        in1 = EXP1;
        while (true)
        {
            if ( sqrt(in1) - floor( (sqrt(in1)) ) != 0 )
            in1++;
            else break;
        }
        in2 = EXP1;
        while (true)
        {
            if ( sqrt(in2) - floor( (sqrt(in2)) ) != 0 )
            in2--;
            else break;
        }
        if ( in1 - EXP1 <= EXP1 - in2)
        S = in1;                                        //S will be consider wherether if in1 or in2 will be suitable or it will equal to EXP1
        else
        S = in2;
        }
        else
        S = EXP1;
        /////////////////////////////
        /*Next up, we will divise will the road 1*/
        statistic(EXP1,S,P2);
    }
    /*Continue to road 3*/
    int i;
    float P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    // find i position of the given array P
    if (E2 < 10)
    i = E2;
    else
    i= ( E2%10 + E2/10 ) % 10;
    if (P1==P2 && P2==P[i] && P[i]==100)
    {
        EXP1= ceil( EXP1 - EXP1 * 0.25 );
        check_condition_EXP1(EXP1);
    }
    else if ( ( (P1+P2+P[i]) / 3 ) < 50)
    {
        HP1 = ceil( HP1 - HP1*0.15 );
        check_condition_HP1(HP1);
        EXP1 = ceil( EXP1 + EXP1*0.15 );
        check_condition_EXP1(EXP1);
    }
    else
    {
        HP1 = ceil( HP1 - HP1*0.1 );
        check_condition_HP1(HP1);
        EXP1 = ceil( EXP1 + EXP1*0.2 );
        check_condition_EXP1(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
     if (E3 < 0 || E3 > 99)
    return -99;
    const int rows = 10;
    const int cols = 10;
    int i,j;
    int matrix[10][10] = {0};
    int shortcut[10][10] = {0};
   for (int c = 0; c < rows; ++c) {
        for (int d = 0; d < cols; ++d) {
            matrix[c][d] = ((E3 * d) + (c * 2)) * (c - d); // Calculate taxi score at point (c, d)
        }
    }
    ////////////////////////////////
    int p,n;  /*This is use for checking taxi with condition*/
    for (int c = 0; c < rows; ++c) {
        for (int d = 0; d < cols; ++d) {
            if ( matrix[c][d] > E3*2 )
            p = p + 1;
            else if ( matrix[c][d] < (-E3) )
            n = n + 1;
        }
    }
    /////////////////////////////
    p = ( p%10 ) + ( p/10 );   //Finally checking taxi position by adding with codition
    n = ( n%10 ) + ( n/10 );
    if ( p >= 10 )
    p = ( p%10 ) + ( p/10 );
    if ( n >= 10 )
    n = ( n%10 ) + ( n/10 );
    //////////////////////////////
    i=p;
    j=n;
    int nigga=0;
    while (true)
    {
        if (i==0 || j==0) break;
        i--;
        j--;
        
    }
    while (true)
    {
        if (nigga< matrix[i][j]) nigga = matrix[i][j];
        if (i==9 || j==9) break;
        i++;
        j++;
    }
    i=p;
    j=n;
    while (true)
    {
        if (i==0 || j==9) break;
        i--;
        j++;
        
    }
    while (true)
    {
        if (nigga< matrix[i][j]) nigga = matrix[i][j];
        if (i==9 || j==0) break;
        i++;
        j--;
    }
    if ( abs( matrix[p][n] ) > abs( nigga ) ) // Oh no, ze taxi is too fast to be caught
    {
        EXP1 = ceil (EXP1 - EXP1 * 0.12);
        check_condition_EXP1(EXP1);
        HP1 = ceil (HP1 - HP1 * 0.1);
        check_condition_HP1(HP1);
        EXP2 = ceil (EXP2 - EXP2 * 0.12);
        check_condition_EXP2(EXP2);
        HP2 = ceil (HP2 - HP2 * 0.1);
        check_condition_HP2(HP2);
        nigga = matrix[p][n];
    }
    else         //i caught you in my sight you fking taxi
    {
        EXP1 = ceil (EXP1 + EXP1 * 0.12);
        check_condition_EXP1(EXP1);
        HP1 = ceil (HP1 + HP1 * 0.1);
        check_condition_HP1(HP1);
        EXP2 = ceil (EXP2 + EXP2 * 0.12);
        check_condition_EXP2(EXP2);
        HP2 = ceil (HP2 + HP2 * 0.1);
        check_condition_HP2(HP2);
    }
    return nigga;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[100];
    const char * position = strchr (email,'@');     /*Finding the position of @ by using string character*/
    int width = abs(email - position);
    const char * symbols = "!@#$%";
    strncpy (se,email,width);
    se[width]= '\0';                                /*The \0 stands for not taking the last character in the array becasue if not then the @ will be count also*/
    int passlength = strlen(s);
    if ( passlength < 8 )
    return -1;                                      //if s < 8
    else if ( passlength > 20)
    return -2;                                      //if s > 20
    const char * pim = strstr(s,se);                /*Finding substring se in s by using string string*/
    if ( pim != nullptr )                           /*nullptr stands for false in string  it's like bool type but this is for array and string and s containing se*/
    {
        return -( 300 + ( pim - s ) );
    }
    for (int n = 0; n < passlength; n++)            /*Checking if the next letter is the same as the last one or not*/
    {
        if ( s[n] == s[n+1] && s[n] == s[n+2] )
        {
            int sci = n;
            return -(400 + sci);
        }
    }
    for ( int n = 0 ; n < passlength ; n++ )
    { 
        if (strpbrk(s, symbols) == nullptr)         /*Checking if there is a special symbol that connect str1 and str2 by using strpbrk*/
        {
            return -5;
        }
    }
    for (int n = 0 ; n < passlength ; n++)
    {
        char scaning = s[n];
        if ( !(isdigit(scaning) || islower(scaning) || isupper(scaning) || scaning == '@' || scaning == '#' || scaning == '!' || scaning == '%' || scaning == '$' )) /*Checking for number capslock or symbols that appeared in email*/
        return n;
    }
        return -10;                                 //if the pass is correct then return -10
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int * times = new int[num_pwds]();              /*New fucntion is use for a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable */
    int * width = new int[num_pwds]();
    for ( int n = 0 ; n < num_pwds ; n++ )
 {
     const char * n_pass = arr_pwds[n];             
     width[n] = strlen(n_pass);
    times[n] = 1;
    for ( int m = n ; m < num_pwds ; m++)
     {
         if( strcmp (n_pass, arr_pwds[m]) == 0 )    
         {
             times[n] = times[n] + 1;
         }
     }
 }        
 int most_t = 0, most_w = 0, passposition;
 for ( int n = 0 ; n < num_pwds ; n++)
 {
     if ( times[n] > most_t )
     {
         most_t = times[n];
         most_w = width[n];
         passposition = n;
     }
     else if (times[n] == most_t && width[n] > most_w) 
        {
            most_t = times[n];
            most_w = width[n];
            passposition = n;
        }
 }
        return passposition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////