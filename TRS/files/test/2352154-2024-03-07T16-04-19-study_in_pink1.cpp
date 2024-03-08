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
void checkhp1(int &HP1) {
    if (HP1 < 0)
        HP1 = 0;
    else if (HP1 > 666)
        HP1 = 666;
}
void checkhp2(int &HP2) {
    if (HP2 < 0)
        HP2 = 0;
    else if (HP2 > 666)
        HP2 = 666;
}
void checkexp1(int &EXP1) {
    if (EXP1 < 0)
        EXP1 = 0;
    else if (EXP1 > 600)
        EXP1 = 600;
}
void checkexp2(int &EXP2) {
    if (EXP2 < 0)
        EXP2 = 0;
    else if (EXP2 > 600)
        EXP2 = 600;
}
void checkm1(int &M1) {
    if (M1 < 0)
        M1 = 0;
    else if (M1 > 3000)
        M1 = 3000;
}
void checkm2(int &M2) {
    if (M2 < 0)
        M2 = 0;
    else if (M2 > 3000)
        M2 = 3000;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    if(e1 < 0 || e1>99 )
        return -99;
    if(e1 >=0 && e1<=3)
    {
        if(e1 == 0)
        exp2+= 29;
    if(e1 == 1)
        exp2 += 45;
    if (e1==2)
        exp2 += 75;
    if (e1 ==3)
        exp2 +=149;
    int D =e1*3+ exp1*7;
    if(D%2==0)
        exp1+= ceil(D/200.0);
    else 
        exp1= ceil(exp1-D/100.0);
    checkexp1(exp1);
    checkexp2(exp2);
    return exp1 +exp2;
    }

    if(e1>=4 && e1<=19)
    {
        exp2+= ceil(e1/4.0+19);
        checkexp2(exp2);
    }
    else if (e1>=20 && e1<=49)
    {
        exp2+= ceil(e1/9.0+21);
        checkexp2(exp2);
    }
    else if (e1>=50 && e1<=65)
    {
        exp2+= ceil(e1/16.0+17);
       checkexp2(exp2);
    }            
    else if (e1>=66 && e1<=79)
    {
        exp2+= ceil(e1/4.0+19);
        checkexp2(exp2);
        if (exp2>200)
        {
            exp2+= ceil(e1/9.0+21);
            checkexp2(exp2);
        }
    }
    else 
    {
        exp2+=ceil(e1/4.0+19);
        checkexp2(exp2);
        exp2+=ceil(e1/9.0+21);
        checkexp2(exp2);
        if(exp2>400)
        {
            exp2+= ceil(e1/16.0+17);
            checkexp2(exp2);
            exp2+= ceil(exp2*0.15);
            checkexp2(exp2);
        }
    }
    exp1 -=e1;
    checkexp1(exp1);
    return exp1+exp2;
}

void ChooseEvent(int &HP1, int &EXP1, int &M1,int Event)
{
    if (Event ==1 )
    {
         if(HP1<200)
            {
                HP1=ceil(HP1+0.3*HP1);
                checkhp1(HP1);
                M1-=150;
                checkm1(M1);
            }
            else
            {
                HP1=ceil(HP1+0.1*HP1);
                checkhp1(HP1);
                M1-=70;
                checkm1(M1);
            }
            
    }
    else if (Event ==2)
    {
        if (EXP1<400)
                M1-=200;
            else
                M1-=120;
            checkm1(M1);
            EXP1=ceil(EXP1+0.13*EXP1);
            checkexp1(EXP1);
    }
    else 
    {
        if (EXP1<300)
                M1-=100;
            else
                M1-=120;
            checkm1(M1);
            EXP1 = ceil(EXP1 - EXP1*0.1);
            checkexp1(EXP1);
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0 || E2>99)
        return -99;
    float P1,P2,P3;
    int upper=0,lower=0 ;
    //P1
    upper = ceil(sqrt(EXP1));
    lower = upper -1;
    if ( ( EXP1 - pow(lower,2)) <= (pow(upper,2) - EXP1 ))
        P1 = 100;
    else 
        P1 =((EXP1*1.0/pow(upper,2) +80)/123.0)*100;
    //P2
    int initialm1 = M1;
    if (E2%2 ==1)
    {
        int Event= 0;
        while((float)M1 >= initialm1*0.5)
        {
            Event ++;
            if(Event ==4)
                Event =1;
            ChooseEvent(HP1,EXP1, M1,Event);
        }

        HP1 = ceil(HP1 - HP1*0.17);
        checkhp1(HP1);
        EXP1= ceil(EXP1+EXP1*0.17);
        checkexp1(EXP1);
    }
    else 
    {
        //Event1
        if (M1>0)
        {
            if(HP1<200)
            {
                HP1 = ceil(HP1+HP1*0.3);
                checkhp1(HP1);
                M1-=150;
                checkm1(M1);
            }
            else
            {
                HP1 = ceil(HP1+HP1*0.1);
                checkhp1(HP1);
                M1-=70;
                checkm1(M1);
            }
            
        }
        if(M1>0)
        {
             if (EXP1<400)
                M1-=200;   
            else
                M1-=120;
            checkm1(M1);
            EXP1 = ceil(EXP1+EXP1*0.13);
            checkexp1(EXP1);
        }

        if (M1>0)
        {
             if (EXP1<300)
                M1-=100;
            else
                M1-=120;
            checkm1(M1);
            EXP1 = ceil(EXP1 - EXP1*0.1);
            checkexp1(EXP1);
        }

        HP1 = ceil(HP1 - HP1*0.17);
        checkhp1(HP1);
        EXP1=ceil(EXP1+0.17*EXP1);
        checkexp1(EXP1);
    }
    
    upper = ceil(sqrt(EXP1));
    lower = upper -1;
    if ( ( EXP1 - pow(lower,2)) <= (pow(upper,2) - EXP1 ))
        P2 = 100;
    else 
        P2 =((EXP1*1.0/pow(upper,2) +80)/123.0)*100;
    // P3
    int P[10] ={32,47,28,79,100,50,22,83,64,11};
    if(E2>10)
        E2= (E2%10 + E2/10)%10;
    P3 = P[E2%10];
    if (P1==100 && P2==100 &&P3==100)
    {
        EXP1 = ceil(EXP1 - EXP1*0.25);
        checkexp1(EXP1);
    }
    else 
    {
        float Pavg = (P1+P2+P3)/3.0;
        if (Pavg <50)
        {
            HP1 = ceil( HP1 - HP1*0.15);
            checkhp1(HP1); 
            EXP1 =ceil(EXP1+EXP1*0.15);
            checkexp1(EXP1);
            
        }
        else
        {
             HP1 = ceil( HP1 - HP1*0.1);
             checkhp1(HP1);
            EXP1 = ceil(EXP1+EXP1*0.2);
            checkexp1(EXP1);
            
        }
    }
    return HP1+EXP1 +M1;
}
// Task 3

int checkMax(int taxi[10][10] ,int i , int j)
{
    int max= taxi[i][j];
    int dx[4]={1,-1,-1,1};
    int dy[4]={1,-1,1,-1};
    for (int k =0; k <=3 ;k++)
    {
        int i1=i ,j1=j;
        while((j1+dx[k])>=0 &&(i1+dy[k])>=0 &&( j1 +dx[k])<=9&& (i1+dy[k])<=9)
        {
            j1+=dx[k]; i1+=dy[k];
            if(taxi[i1][j1]>max)
                max=taxi[i1][j1];
        }
    }
    return abs(max);
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    if(E3 < 0 || E3>99)
        return -99;
    int imeet =0 ,jmeet=0;
    int taxi[10][10];
    for(int i  = 0; i <10;i++)
    {
        for(int j =0;j< 10 ;j++)
        {
             taxi[i][j] =(E3*j+i*2)*(i-j);
             if(taxi[i][j] > E3*2)  
                imeet++;
            if(taxi[i][j] < -E3)
                jmeet++;
        }
    }
    while (imeet>=10)
        imeet =(imeet%10+imeet/10);
    
    while (jmeet>=10)
        jmeet =(jmeet%10+jmeet/10);
    int max =checkMax(taxi,imeet,jmeet) ;
    if(abs(taxi[imeet][jmeet]) > max)
    {
        EXP1 =ceil( EXP1 -EXP1*0.12);
        HP1 =ceil(HP1-HP1*0.10);
        checkexp1(EXP1);
        checkhp1(HP1);

        EXP2 =ceil(EXP2 -EXP2*0.12);
        HP2 =ceil(HP2-HP2*0.10);
        checkexp2(EXP2);
        checkhp2(HP2);
        return taxi[imeet][jmeet];
    }
    else 
    {
        EXP1 =ceil( EXP1 + EXP1*0.12);
        HP1 =ceil(HP1+ HP1*0.10);
        checkexp1(EXP1);
        checkhp1(HP1);

        EXP2 =ceil(EXP2 + EXP2*0.12);
        HP2 =ceil(HP2+ HP2*0.10);
        checkexp2(EXP2);
        checkhp2(HP2);
        return max;
    }
}

// Task 4
int checkPassword(const char *s, const char *email) {
    string se;
    for (int i =0 ;i <strlen(email);i++)
    {
        if (email[i] =='@')
            break;
        se+=email[i];
    }
    if (strlen(s) <8)
        return -1;
    if (strlen(s)>20)
        return -2;
    string scp;
    for (int i =0 ;i <strlen(s);i++)
        scp+=s[i];
    int found = scp.find(se);
    if (found !=-1)
        return -(300+found);

    for (int i =0 ;i <strlen(s) -2;i++)
    {
        if (scp[i] == scp[i+1] && scp[i] == scp[i+2])
            return -(400+i);
    }
    int specail=0;

    for (int i =0 ;i <strlen(s);i++)
        if (scp[i] == '@' || scp[i] == '#' || scp[i] == '%' || scp[i] == '$' ||scp[i] =='!')
            specail ++;
    if(specail == 0)
        return -5;
    for (int i =0 ;i<strlen(s) ; i++)
    {
        if (scp[i] == '@' || scp[i] == '#' || scp[i] == '%' || scp[i] == '$' || scp[i] =='!' || ((int)scp[i] >= 48 && (int)scp[i] <=57) || ((int)scp[i]>=65 && (int)scp[i] <= 90 ) || ((int)scp[i] >=97 && (int)scp[i]<=122))
            continue;
        return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int num[num_pwds][2]={};
    int index=0;
    int maxf =0;
    int maxl =0;
    for(int i=0; i<num_pwds; ++i){
        for(int j=0; j<num_pwds; ++j){
            if( strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                num[i][0]++;
                num[i][1]=strlen(arr_pwds[j]);
                if(num[i][0] > maxf || (num[i][0] == maxf && num[i][1] > maxl)){
                maxf=num[i][0];
                maxl=num[i][1];
                index = i;
            }
            }
        }
    }
    
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////