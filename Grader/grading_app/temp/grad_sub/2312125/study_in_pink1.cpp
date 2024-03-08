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
// Task 1
int lamTron (int a)
{
    if (a%1.0 != 0)
    {
        a=a+1;
    }
    if (a<0)
    {
        a=0;
    }
    if (a)
    return a;
}
int gioiHanEXP(int b)
{
    if (b>600)
    {
        b=600;
    }
    return b;
}
int gioiHanHP(int c)
{
    if (c > 666)
    {
        c=666;
    }
    return c;
}
int gioiHanTien(int d)
{
    if (d>3000)
    {
        d=3000;
    }
    return d;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1>=0 & E1 <=3)
    {
        if (E1==0)
        {
            EXP2=EXP2+29;
            gioiHanEXP(EXP2);
        }
        else if  (E1==1)
        {
            EXP2=EXP2+45;
            gioiHanEXP(EXP2);
        }
        else if  (E1==2)
        {
            EXP2=EXP2+75;
            gioiHanEXP(EXP2);
        }
        else
        {
            EXP2=EXP2+29+45+75;
            gioiHanEXP(EXP2);
        }
        int D;
        D=E1*3+EXP1*7;
        if (D%2==0)
        {
            EXP1=EXP1+200;
            88 gioiHanEXP(EXP1);
        }
        else
        {
            EXP1=EXP1-D/100;
        }
        if(EXP1%1.0 != 0)
        {
            EXP1 = EXP1 +1;
            gioiHanEXP(EXP1);
        }
    }
    if (E1>=4 & E1<=99)
    {
        if (E1>=4 & E1<=19)
        {
            lamTron(EXP2 = EXP2 + E1/4 +19);
            gioiHanEXP(EXP2);
        }
        else if (E1>=19 & E1<=49)
        {
            lamTron(EXP2 = EXP2 + E1/9 + 21);
            gioiHanEXP(EXP2);
        }
        else if (E1>=50 & E1<=65)
        {
            lamTron(EXP2 = EXP2 + E1/16 +17);
            gioiHanEXP(EXP2);
        }
        else if (E1>=66 & E1<=79)
        {
            EXP2 = EXP2 + E1/4 +19;
            if(EXP2%1.0 != 0)
        {
            EXP2 = EXP2 +1;
        }
            if(EXP2>200)
            {
                lamTron(EXP2 = EXP2 + E1/9 + 21)
                gioiHanEXP(EXP2);;
            }
        }
        else
        {
            lamTron(EXP2 = EXP2 + E1/4 +19);
            gioiHanEXP(EXP2);
            lamTron(EXP2 = EXP2 + E1/9 + 21);
            gioiHanEXP(EXP2);
            if(EXP2>400)
            {
                lamTron(EXP2 = EXP2 + E1/16 +17);
                EXP2=EXP2 + EXP2*15/100;
            }
        }
        lamTron(EXP1=EXP1-E1);
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int sqrtEXP1= sqrt(EXP1),S1;
    if (sqrtEXP1*sqrtEXP1==EXP1) 
    {
     S1 = EXP1;
    }
    else
    {
        if(EXP1-(sqrtEXP1-1)(sqrtEXP1-1) > (sqrtEXP1+1)(sqrtEXP1+1)-EXP1)
        {
            S1=(sqrtEXP1+1)(sqrtEXP1+1)-EXP1;
        }
        else 
        {
            S1=EXP1-(sqrtEXP1-1)(sqrtEXP1-1);
        }
    }
    int P1;
    if (EXP1 >=S1)
    {
        P1=100;
    }
    else
    {
        P1=(EXP1/S1 + 80)/123;
    }
    if (M1%2!=0)
    {   int M=M1;
        while(M1>0)
        {
    if (HP1 < 200)
    {
        lamTron(HP1=HP1+HP1*30/100);
        lamTron(M1=M1-150);
        if (M1<50/100*M)
        {
            break;
            M1=M1+150;
        }
    
    }
    else 
    {
        lamTron(HP1=HP1+HP1*10/100);
        lamTron(M1=M1-70);
        gioiHanTien(M1);
         if (M1<50/100*M)
        {
            break;
            M1=M1+70;
        }
    }
    if ( EXP1<400)
    {
        lamTron(M1=M1-200);
         if (M1<50/100*M)
        {
            break;
            M1=M1+200;
        }
    }
    else
    {
        lamTron(M1=M1-120);
         if (M1<50/100*M)
        {
            break;
            M1=M1+120;
        }
    }
    gioiHanEXP(lamTron(EXP1=EXP1+13%));
    if (EXP1<300)
    {
        lamTron(M1=M1-100);
         if (M1<50/100*M)
        {
            break;
            M1=M1+100;
        }
    }
    else
    {
        lamTron(M1=M1-120);
         if (M1<50/100*M)
        {
            break;
            M1=M1+120;
        }
    }
    lamTron(EXP1=EXP1-EXP1*10/100);}
    lamTron(HP1=HP1-17/100*HP1);
    gioiHanEXP(lamTron(EXP1=EXP1+EXP1*17/100));
    }
    else
    {
        if (HP1 < 200)
    {
        lamTron(HP1=HP1+HP1*30/100);
        lamTron(M1=M1-150);
    
    }
    else 
    {
        lamTron(HP1=HP1+HP1*10/100);
        lamTron(M1=M1-70);
        gioiHanTien(M1);
       
    }
    if (M1>0){
    if ( EXP1<400)
    {
        lamTron(M1=M1-200);
    }
    else
    {
        lamTron(M1=M1-120);
    }
    if (M1>0){
    gioiHanEXP(lamTron(EXP1=EXP1+13%));
    if (EXP1<300)
    {
        lamTron(M1=M1-100);
    }
    else
    {
        lamTron(M1=M1-120);
    }
    lamTron(EXP1=EXP1-EXP1*10/100);}}
    lamTron(HP1=HP1-17/100*HP1);
    gioiHanEXP(lamTron(EXP1=EXP1+EXP1*17/100));
    }
        int sqrtEXP12= sqrt(EXP12),S2;
    if (sqrtEXP12*sqrtEXP12==EXP12) 
    {
     S2 = EXP12;
    }
    else
    {
        if(EXP1-(sqrtEXP12-1)(sqrtEXP12-1) > (sqrtEXP12+1)(sqrtEXP12+1)-EXP1)
        {
            S2=(sqrtEXP12+1)(sqrtEXP12+1)-EXP1;
        }
        else 
        {
            S2=EXP1-(sqrtEXP12-1)(sqrtEXP12-1);
        }
    }
    int P2;
    if (EXP1 >=S2)
    {
        P2=100;
    }
    else
    {
        P2=(EXP1/S1 + 80)/123;
    }
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11}
    if (P/10=0)
    {P3=P[E2]}
    else
    {   
        int E2'=E2,sum;
        while (E2' !=0)
        {
            sum = sum + E2%10;
            E2'=E2/10;
        }
        sum=sum%10;
        P3=P[sum];


    }
    if(P1=100 & P2=100 & P3=100)
    {
        lamTron(EXP1=EXP1-25/100*EXP1);
    }
    else
    {
        int P = (P1+P2+P3)/3;
        if (P<50)
        {
            lamTron(HP1=HP1-15/100*HP1);
            gioiHanEXP( lamTron(EXP1=EXP1+15/100*EXP1);)
        }
        else
        {
            lamTron(HP1=HP1-10/100*HP1);
            gioiHanEXP( lamTron(EXP1=EXP1+20/100*EXP1);)
        }
    }



return HP1 + EXP1 + M1;

}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int matrix[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int scoreSherlockWatson[10][10] = {0};
    for (int i = 0; i < 10; i++) 
    {
    for (int j = 0; j < 10; j++) 
    {
        int leftDiagonal[10] = {0};
        int k = i, l = j;
        int index = 0;
        while (k >= 0 && l >= 0) 
        {
            leftDiagonal[index] = matrix[k][l];
            index++;
            k--;
            l--;
        }
        int rightDiagonal[10] = {0};
        k = i, l = j;
        index = 0;
        while (k >= 0 && l < 10)
        {
        rightDiagonal[index] = matrix[k][l];
        index++;
        k--;
        l++;
        }
        int maxScore = intMin;
        for (int d : leftDiagonal)
        {
        maxScore = max(maxScore, d);
        }
        for (int d : rightDiagonal) 
        {
        maxScore = max(maxScore, d);
        }
        scoreSherlockWatson[i][j] = maxScore;
        int i = 0, j = 0;
        
    }
    }
    int i = 0, j = 0;
    while (i < 10) 
        {
        if (matrix[i][j] >= E3 * 2) 
        {
        break;
        }
        i++;
        }
        while (j < 10) 
        {
        if (matrix[i][j] <= -E3) 
        {
            break;
        }
        j++;
        }
        int taxiScore = matrix[i][j];
        int sherlockWatsonScore = scoreSherlockWatson[i][j];
        if (abs(taxiScore) > abs(sherlockWatsonScore)) 
        {
            lamTron(HP1=HP1-12/100*HP1);
            lamTron(EXP1=EXP1-10/100*EXP1);
        }
        else
        {
            gioiHanHP(lamTron(HP1=HP1+12/100*HP1));
            gioiHanEXP(lamTron(EXP1=EXP1+10/100*EXP1));
        }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////