//////////////////////////////////////////////////////////////////////////////////////////////
//
//
// DAY CHI LA BAN THAM KHAO CACH TAO THEM CAC HAM DE HO TRO HOAN THIEN HAM YEU CAU
// NEU MUON CO CODE MAU HOAN CHINH, TEST CASE KIEM TRA THI XEM LINK DUOI
// LINK: https://s.net.vn/oExT
// BY: QUOC ANH
//
//
///////////////////////////////////////////////////////////////////////////////////////////////


#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void lamtronEXP(int & EXP1, int & EXP2  )
{
    if(EXP1>600) EXP1=600;
    if(EXP2>600) EXP2=600;
    if(EXP1<0) EXP1=0;
    if(EXP2<0) EXP2=0;
}
void lamtronHP(int &HP1 , int &HP2)
{
    if(HP1>666) HP1=666;
    if(HP2>666) HP2=666;
    if(HP1<0) HP1=0;
    if(HP2<0) HP2=0;
}
void lamtron2( int & EXP1,int &HP1,int &M1 )
 {
     if(EXP1>600) EXP1=600;
     if(EXP1<0) EXP1=0;
     if(HP1>666) HP1=666;
     if(HP1<0) HP1=0;
    if(M1>3000) M1=3000;
    if(M1<0) M1=0;
}
void t1_th1(int & EXP1, int & EXP2, int E1)
{
    lamtronEXP(EXP1,EXP2);
    if(E1 == 0) EXP2=EXP2+29;
        else if(E1 ==1) EXP2=EXP2+45;
        else if( E1==2) EXP2=EXP2+75;
        else EXP2=EXP2+75+45+29;
   int D= E1*3+EXP1*7;
   if(D%2==0) EXP1=ceil(EXP1+(D/200.0));
     else EXP1=ceil(EXP1-(D/100.0));
    lamtronEXP(EXP1,EXP2);
}
void t1_th2(int & EXP1, int & EXP2, int E1)
{
    if(4<=E1 && E1<=19) EXP2 =EXP2+ceil(E1/4.0+19);
   else if(20<=E1 && E1<=49) EXP2 =EXP2+ceil(E1/9.0+21);
   else if(50<=E1&& E1<=65) EXP2 =EXP2+ceil(E1/16.0+17);
   else if(66<=E1 && E1<=79)
   {
       EXP2 =EXP2+ceil(E1/4.0+19);
       if(EXP2>200) EXP2=EXP2+ceil(E1/9.0+21);
    }
   else
   {
       EXP2 =EXP2+ceil(E1/4.0+19)+ceil(E1/9.0+21);
       if(EXP2>400)
       {EXP2 =EXP2+ceil(E1/16.0+17);
       EXP2=ceil(EXP2*1.15);}
   }
   EXP1=EXP1-E1;
   lamtronEXP(EXP1,EXP2);
}


float tinhP(int EXP1)
{
    int n=0; float S;
    do
    {n=n+1;}
    while (n*n<EXP1);
    if(n*n-EXP1<(EXP1-(n-1)*(n-1))) S= n*n; else S=((n-1)*(n-1));
    if(S<= EXP1) return 1; else return (float(EXP1/S)+80)/123.0;
}
void p2_1(int &HP1 , int &EXP1 ,  int &M1 , int &M)
{
    if(HP1>200){
        HP1=ceil(float(HP1*1.1));
        lamtron2(EXP1,HP1,M1);
        M1=M1-70;
        M=M+70; }
    else {
        HP1=ceil(float(HP1*1.3));
        M1=M1-150;
        M=M+150; }

}
void p2_2(int &HP1 , int &EXP1 ,  int &M1 , int &M)
{
    if(EXP1>400){
        M1=M1-120;
        M=M+120; }
    else {
        M1=M1-200;
        M=M+200; }
    EXP1=ceil(float(EXP1*1.13));
}
void p2_3(int &HP1 , int &EXP1 ,  int &M1 , int &M)
{
    if(EXP1>300){
        M1=M1-120;
        M=M+120; }
    else {
        M1=M1-100;
        M=M+100;}
    EXP1=ceil(float(EXP1*0.9));
}
void p2_cuoi(int &HP1 , int &EXP1)
{
    HP1=ceil(float(HP1*0.83));
    EXP1=ceil(float(EXP1*1.17));
}
void doanduong(int & HP1, int & EXP1, int & M1, int E2 ,int &M)
{
    p2_1(HP1,EXP1,M1,M);
    if(M1<=0) p2_cuoi(HP1,EXP1); else
    {p2_2(HP1,EXP1,M1,M);
    if(M1<=0 ) p2_cuoi(HP1,EXP1); else
    {p2_3(HP1,EXP1,M1,M);
    p2_cuoi(HP1,EXP1);}}
}

float tinhP3(int E2)
{
    int p3[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(0<=E2 && E2<=9) return p3[E2]/100.0;
     else
     {
         int x= (E2%10 + E2/10)%10;
         return p3[x]/100.0;
     }
}

int chuso(int m)
{
   do
   {m= (m/10+m%10);}
   while (m>=10);
   return m;
}




int demchu(char a[])
{
  int n=0;
    do
    {n=n+1;}
    while(a[n]!= '\0');
    return n;
}
int sosanhchuoi (char a[], char b[])
{
    int m=0;
    for (int i=0 ; i<demchu(a) ; i++)
     if(a[i]==b[i]) continue; else m=m+1;
    if(m==0) return 1; else return 0;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
if( E1<0 || E1>99) return -99;
 if(E1<=3) t1_th1(EXP1,EXP2,E1);
      else t1_th2(EXP1,EXP2, E1);
lamtronEXP(EXP1,EXP2);
   return EXP1+ EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if( E2<0 || E2>99) return -99;
    lamtron2(EXP1,HP1,M1);
    float P,P1, P2,P3;
    P1=tinhP(EXP1);
    int M=0; float m=M1/2.0;
    if(E2%2==0 && M1 >0) {doanduong(HP1,EXP1,M1,E2,M);}
      else {do
       {p2_1(HP1,EXP1,M1,M);
       {if(M1<=0 || M>m) break;
      p2_2(HP1,EXP1,M1,M);
      {if(M1<=0 || M>m ) break;
        p2_3(HP1,EXP1,M1,M);}}}
    while(M<m);
    p2_cuoi(HP1,EXP1);}
    lamtron2(EXP1,HP1,M1);
    P2=tinhP(EXP1);
    P3=tinhP3(E2);
    if(P1==1 && P2==1 && P3==1)
    {
       EXP1=ceil(float(EXP1*0.75));
       return HP1 + EXP1+M1;
    }
    P=(P1+P2+P3)/3.0;
        if(P<0.5)
        {
            HP1=ceil(float(HP1*0.85));
            EXP1=ceil(float(EXP1*1.15));
        }
        else
        {
            HP1=ceil(float(HP1*0.9));
            EXP1=ceil(float(EXP1*1.2));
        }
    lamtron2(EXP1,HP1,M1);

    return HP1 + EXP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if( E3<0 || E3>99) return -99;
    lamtronEXP(EXP1,EXP2);lamtronHP(HP1,HP2);
 int matran[10][10];
 int m=0,n=0;
 for(int i=0 ; i<=9 ; i++)
    for(int j=0; j<=9; j++)
     matran[i][j]= ((E3*j)+(i*2))*(i-j);
 for(int i=0 ; i<=9 ; i++)
    for(int j=0; j<=9; j++)
    {
        if(matran[i][j] > E3*2) m++;
        if(matran[i][j] < -E3) n++;
    }
    m= chuso(m);
    n= chuso(n);
    int Max = matran[m][n];
if(m>n)
    for(int i=0 ; i<=n;i++)
           if(Max < matran[m-n+i][i]) Max = matran[m-n+i][i];
if(m<n)
   for(int i=m; i<=9-m;i++)
       { int u=0;
        if(Max < matran[i][n+u]) Max = matran[i][n+u];
        u++;
}
for(int i=1 ; i<=9-n;i++)
    if(Max < matran[m-i][n+i]) Max = matran[m-i][n+i];
      else continue;
for(int i=1 ; i <=9-m;i++)
    if(Max < matran[m+i][n-i]) Max = matran[m+i][n-i];
      else continue;
if(Max < abs(matran[m][n]))
{
    EXP1 =ceil(float(EXP1 * 0.88)) ;
    HP1 = ceil(float(HP1 * 0.9));
    EXP2 = ceil(float(EXP2 * 0.88)) ;
    HP2 = ceil(float(HP2 * 0.9)) ;
    lamtronEXP(EXP1,EXP2);lamtronHP(HP1,HP2);
    return (matran[m][n]);
}
 else
 {
    EXP1 = ceil(float(EXP1 * 1.12)) ;
    HP1 = ceil(float(HP1 * 1.1)) ;
    EXP2 = ceil(float(EXP2 * 1.12));
    HP2 = ceil(float(HP2 * 1.1));
    lamtronEXP(EXP1,EXP2);lamtronHP(HP1,HP2);
    return(Max);
 }
}

// Task 4
int checkPassword(const char * s, const char * email) {
     char *matkhau = NULL; matkhau = (char *)s;
   char *email1 = NULL; email1 = (char *)email;
  int n=0,m=0;
  do{n=n+1;}
   while(email1[n]!= '@');
  char se[n];
  for(int i=0 ; i<n; i++)
    se[i]=email1[i];
  if (demchu(matkhau)<8) return -1;
  if (demchu(matkhau)>20) return -2;
  for(int i=0 ; i<demchu(matkhau)-n; i++)
  {
      int m=0;
   for(int j=0; j<n; j++)
     if(matkhau[j+i]==se[j])  m=m+1;
    if(m!=n) continue; else return -(300+i);
  }
  for (int i=0 ; i<demchu(matkhau)-2; i++ )
  {
      if(matkhau[i]==matkhau[i+1] && matkhau[i+1]==matkhau[i+2] )  return -(400+i);
  }
  for(int i=0; i<demchu(matkhau);i++)
  if(matkhau[i]== '@' || matkhau[i]== '#' || matkhau[i]=='$'|| matkhau[i]=='!' || matkhau[i]=='%') m=m+1;
  if(m == 0) return -5;
  for (int i=0 ; i<demchu(matkhau); i++ )
  {
 if((matkhau[i]>='a' && matkhau[i]<='z') || (matkhau[i]>='A' && matkhau[i] <= 'Z') ||matkhau[i]== '@' || matkhau[i]== '#' || matkhau[i]=='$'|| matkhau[i]=='!' || matkhau[i]=='%' ||(matkhau[i]>='0' && matkhau[i] <= '9')) continue;
       else return i;
  }
 return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int a[num_pwds],b[num_pwds];
    for (int i=0 ; i<num_pwds ; i++ ) a[i]=0;
    for (int i=0 ; i<num_pwds ; i++)
    {
        char *temp1 = NULL; temp1 = (char *)arr_pwds[i];
        for(int j=0 ; j<num_pwds ; j++)
    {
        char *temp2 = NULL; temp2 = (char *)arr_pwds[j];
        a[i]=a[i]+sosanhchuoi(temp1,temp2);
    }
       b[i]=demchu(temp1);
    }
    int Max=a[0],n=0;
    for(int i=0 ; i<num_pwds ; i++)
     if(a[i]>Max) { Max=a[i]; n=i;}
    for(int i=0; i<num_pwds; i++)
     {if(a[i]== Max && b[i] > b[n] ) n=i;}
    return n;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
