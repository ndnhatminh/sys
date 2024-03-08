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

 void  checkexp(int &exp){
    if (exp>600) exp=600;
    if(exp<0) exp=0;
}
void  checkhp(int &hp){
    if (hp>666) hp=666;
    if(hp<0) hp=0;
}
void  checkm(int &m){
    if (m>3000) m=3000;
    if(m<0) m=0;
}
float TinhP (int EXP1)
{
    int S;
    float P;
    if (abs((sqrt(EXP1)-(int)(sqrt(EXP1))))>abs((sqrt(EXP1)-ceil(sqrt(EXP1))))) 
        S=ceil(sqrt(EXP1))*ceil(sqrt(EXP1)); else S=(int)(sqrt(EXP1))*(int)(sqrt(EXP1));
    if (EXP1>=S) P=1; else P=(EXP1*1.0/S +80*1.0)/123*1.0;
    return P;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1>=0) && (e1<=99)) 
    {
        if ((e1>=0)&&(e1<=3))
        {
        if (e1==0) exp2=exp2+29; else
        if (e1==1) exp2=exp2+45; else
        if (e1==2) exp2=exp2+75; else
        exp2=exp2+29+45+75;
        int D=e1*3+exp1*7;
        if (D%2 ==0) exp1= ceil(exp1 + (D*1.0/200));   
             else exp1 = ceil(exp1 - (D*1.0/100));
        } else 
    {
    if ((e1>=4)&&(e1<=19)) exp2=ceil(exp2 + (e1*1.0/4+19));
     else if ((e1>=20)&&(e1<=49)) exp2=ceil(exp2 + (e1*1.0/9+21));
      else if ((e1>=50)&&(e1<=65)) exp2=ceil(exp2 + (e1*1.0/16+17));
        else if  ((e1>=66)&&(e1<=79))
       {
        exp2=ceil(exp2 + (e1*1.0/4+19));
        if (exp2 >200) exp2=ceil(exp2 + (e1*1.0/9+21));
       }
       else 
       {
            exp2=ceil(exp2 + (e1*1.0/4+19)) + ceil((e1*1.0/9+21));
            if (exp2>400) 
            {
                exp2= ceil(exp2 + (e1*1.0/16+17));
                exp2 = ceil(exp2 + (exp2*15.0/100));
            }
       }
       exp1= ceil(exp1 - e1);
    }
       checkexp(exp1);
       checkexp(exp2);
    return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
if ((E2>=0)&&(E2<=99))
{
    //TODO: implement task
int  Mbegin, i1;
float Parray[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
float P1,P2,P3, Pavg;
Mbegin=M1;
P1=TinhP(EXP1);
if ((E2%2)==1) {
    while (M1>=Mbegin/2)  
    {
        if (HP1<200) 
        {
            HP1= ceil(HP1+HP1*30/100.0);
            M1=M1-150;
        }
        else 
        {
            HP1= ceil(HP1+HP1*10/100.0);
            M1=M1-70;
        }
        if (M1<Mbegin/2) break;
        if (EXP1<400) M1=M1-200; 
            else M1=M1-120;
        EXP1=ceil(EXP1+EXP1*13.0/100);
        checkexp(EXP1);
        if (M1<Mbegin/2) break;
        if (EXP1<300) M1=M1-100; else M1=M1-120;
        EXP1=ceil(EXP1*90/100.0);
    }
    checkhp(HP1);
    checkexp(EXP1);
    checkm(M1);
    HP1=ceil(HP1*83/100.0);
    EXP1=ceil(EXP1*117/100.0);
    checkhp(HP1);
    checkexp(EXP1);
}
else   
{
    if (HP1<200) 
    {
        HP1= ceil(HP1+HP1*30/100.0);
        M1=M1-150;
    }
    else 
    {
        HP1= ceil(HP1+HP1*10/100.0);
        M1=M1-70;
    }
    if (M1>0) 
    {
        if (EXP1<400) M1=M1-200; 
            else M1=M1-120;
        EXP1=ceil(EXP1+EXP1*13.0/100);
        checkexp(EXP1);
        if (M1>0) 
        {
            if (EXP1<300) M1=M1-100; else M1=M1-120;
            EXP1=ceil(EXP1*90/100.0);
        }
    }
    checkhp(HP1);
    checkexp(EXP1);
    checkm(M1);
    HP1=ceil(HP1*83/100.0);
    EXP1=ceil(EXP1*117/100.0);
    checkhp(HP1);
    checkexp(EXP1);
}
P2=TinhP(EXP1);
if ((E2>=0)&&(E2<=9)) i1=E2;
else 
{
    i1=(E2%10+(int)E2/10)%10;
}
P3=Parray[i1];
if ((P1==1)&&(P2==1)&(P3==1)) EXP1=ceil(EXP1*75/100.0);
else 
{
    Pavg=(P1+P2+P3)/3;
    if (Pavg<0.5) 
    {
        HP1=ceil(HP1*85/100.0);
        EXP1=ceil(EXP1*115/100.0);
    }
    else 
    {
        HP1=ceil(HP1*90/100.0);
        EXP1=ceil(EXP1*120/100.0);
    }
    checkhp(HP1);
    checkexp(EXP1);
}
return HP1+EXP1+M1;
}
else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if ((E3>=0)&&(E3<=99))
    {
        //TODO: implement task
        int i1=0,j1=0, pointSW=0,tmp=0;
        int map[10][10];
        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++) map[i][j]=((E3 * j) + (i * 2)) * (i - j);
        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++)
            {
                if (map[i][j]>E3*2) i1=i1+1;
                if (map[i][j]<-E3) j1=j1+1;
            }
        while (i1>=10) i1= i1%10 + i1/10;
        while (j1>=10) j1= j1%10 + j1/10;
        while (tmp <=9) 
        {
            if (((i1+tmp)<=9)&&((i1+tmp)>=0)&&((j1+tmp)<=9)&&((j1+tmp)>=0))
                if (map[i1+tmp][j1+tmp] > pointSW) pointSW=map[i1+tmp][j1+tmp];
            if (((i1-tmp)<=9)&&((i1-tmp)>=0)&&((j1+tmp)<=9)&&((j1+tmp)>=0))
                if (map[i1-tmp][j1+tmp] > pointSW) pointSW=map[i1-tmp][j1+tmp];
            if (((i1+tmp)<=9)&&((i1+tmp)>=0)&&((j1-tmp)<=9)&&((j1-tmp)>=0))
                if (map[i1+tmp][j1-tmp] > pointSW) pointSW=map[i1+tmp][j1-tmp];
            if (((i1-tmp)<=9)&&((i1-tmp)>=0)&&((j1-tmp)<=9)&&((j1-tmp)>=0))
                if (map[i1-tmp][j1-tmp] > pointSW) pointSW=map[i1-tmp][j1-tmp];
            tmp=tmp+1;
        }
        if (abs(map[i1][j1])>abs(pointSW)) 
        {
            EXP1=ceil(EXP1*88/100.0);
            EXP2=ceil(EXP2*88/100.0);
            HP1=ceil(HP1*90/100.0);
            HP2=ceil(HP2*90/100.0);
        }
        else
        {
            EXP1=ceil(EXP1*112/100.0);
            EXP2=ceil(EXP2*112/100.0);
            HP1=ceil(HP1*110/100.0);
            HP2=ceil(HP2*110/100.0);
        }
        checkexp(EXP1);
        checkexp(EXP2);
        checkhp(HP1);
        checkhp(HP2);
        if (abs(map[i1][j1])>abs(pointSW)) return map[i1][j1];
        else return pointSW;
    }   
    else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    string se;
    int len1=0,len2=0,ktdb=0, result=-10,len3=0,len4=0;
    len1=strlen(s);
    len2=strlen(email);
    while (*(email+len4) != '@') {
        len4++;
    }
    se.assign(email, email + len4);
    while (se[len3] != '\0') {
        len3++;
    }
    for (int i=0; i<len1; i++)
        if (!(((int)*(s+i)>=48 )&& ((int)*(s+i)<=57)) && !((int)*(s+i)>=97 && ((int)*(s+i)<=122)) && !(((int)*(s+i)>=65) && ((int)*(s+i)<=90)) && !(*(s+i)=='@') && !(*(s+i)=='#')&& !(*(s+i)=='%') && !(*(s+i)=='$') && !(*(s+i)=='!')) {
            result= i;
            break;
        }
    for (int i=0; i<len1; i++)
        if ((*(s+i)=='@') || (*(s+i)=='#') || (*(s+i)=='%') || (*(s+i)=='$') || (*(s+i)=='!')) ktdb=ktdb+1;
    if (ktdb==0) result= -5;
    for (int i=0; i<len1-2; i++)
        if ((*(s+i+1)==*(s+i))&&(*(s+i+1))==*(s+i+2)) {
            result= -(400+i);
            break;
        }
    for (int i=0; i<len1; i++) {
        int tmp=0;
        if (*(s+i)==se[0]) {
            for (int k=0; k<len3; k++)
                if (*(s+i+k)!=se[k]) break;
                else tmp=tmp+1;
        }
        if (tmp == (len3)) {
            result= -(300+i);
            break;
        }
    }
    if (len3==0) result=-300;
    if (len1>20) result= -2;
    if (len1<8) result=-1;
    return result;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int count[num_pwds], len[num_pwds];
    int maxc=0,vt=-1,tmp,maxl=0;
    for (int i=0; i<num_pwds;i++)
        count[i]=0;
    for (int i=0; i<num_pwds;i++)
    {
        for (int k=0; k<num_pwds;k++)
            if (strcmp(arr_pwds[i],arr_pwds[k]))  tmp++; else count[i]=count[i]+1;
         if (count[i]>maxc) maxc=count[i];
    }
    for (int i=0; i<num_pwds;i++)
         len[i]=strlen(arr_pwds[i]);
    for (int i=0; i<num_pwds;i++)
    {
        if (count[i]==maxc) 
            if (len[i]>maxl) maxl=len[i];
    }
    for (int i=0; i<num_pwds;i++)
     if ((count[i]==maxc) && (len[i]==maxl)) {vt=i; break;}
    return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////