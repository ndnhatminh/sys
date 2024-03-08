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
//chuong trinh con
int S(int a)
{    if (a==0) return a;
     int b = ceil(sqrt(a));
     int c=b-1;
     if ((a-c*c)>(b*b-a)) return b*b;
      else return c*c;
}
void sk1(int & HP1,int & M1)
{
     if(HP1<200)//1
    {
        HP1=ceil(HP1*130.0/100.0);
        M1=M1-150;
    }
  else
  {
      HP1=ceil(HP1*110.0/100.0);
      M1=M1-70;
  }
  if(M1<0) M1=0;
  if (HP1>666) HP1=666;
}
void sk2(int & EXP1,int & M1)
{
    if (EXP1<400){M1=M1-200;EXP1=ceil(float(EXP1)*113.0/100.0);}//2
     else
        {
            M1=M1-120;
            EXP1=ceil(float(EXP1)*113.0/100.0);
        }
   if (M1<0)  M1=0;
   if(EXP1>600) EXP1=600;
}
void sk3(int & EXP1,int & M1)
{
     if(EXP1<300){M1=M1-100; EXP1=ceil(float(EXP1)*90.0/100.0);}//3
      else
        {
           M1=M1-120;
           EXP1=ceil(float(EXP1)*90.0/100.0);
        }
   if (M1<0)M1=0;
}
int rutgon(int a)
 {
    while (a>=10)
        {a=(a/10)+(a%10);}
    return a;
 }
 int gia_tri_duong_cheo(int a,int b,int c[10][10])
 {  int x,y,x1,y1,max1,max2;
   //duong cheo trai
   if (a>=b){y=0; x=a-b;}
      else {x=0; y=b-a;}
    while ((x!=9)&&(y!=9))
    {
        x++;
        y++;
        if(c[x][y]>=c[x-1][y-1]) max1=c[x][y];
           else max1=c[x-1][y-1];
    }
//duong cheo phai
   x1=a;y1=b;
   while((x1!=0)&&(y1!=9))
   {
       x1--;
       y1++;
   }
   while ((x1!=9)&&(y1!=0))
    {
        x1++;
        y1--;
        if(c[x1][y1]>=c[x1-1][y1+1]) max2=c[x1][y1];
           else max2=c[x1-1][y1+1];
    }
if (max1>=max2) return max1;
   else return max2;

 }

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if((e1<0) ||(e1>99)) return -99;
    if ((e1>=0)&&(e1<=3))
    { switch(e1)
           { case 0: {exp2 +=29;break;}
             case 1: {exp2 += 45;break;}
             case 2: {exp2 += 75;break;}
             case 3: {exp2 = exp2 +29 +45+75;break;}
           }
           int D=e1*3 + exp1 *7;
           if (D%2==0) {exp1=ceil(exp1 +float(D)/float(200));}
           else {exp1=ceil(exp1-float(D)/float(100));}
           if (exp1>600) exp1 =600;
           if (exp2>600) exp2 =600;
           if (exp1<0) exp1=0;
    }
    else
    { if ((e1>=4)&&(e1<=19)) {exp2= ceil(exp2 + float(e1)/4+19);}
      else if ((e1>=20) && (e1<=49)) {exp2=ceil(exp2 + float(e1)/9+21);}
      else if ((e1>=50) && (e1<=65)) {exp2=ceil(exp2 + float(e1)/float(16)+17);}
      else if ((e1>=66) && (e1<=79)) { exp2=ceil(exp2 + float(e1)/float(4)+19); if (exp2>200) exp2=ceil(exp2 + float(e1)/float(9)+21); }
      else if((e1>=80) && (e1<=99))
               { exp2=ceil(exp2 + float(e1)/float(4)+19);
                 exp2=ceil(exp2 + float(e1)/float(9)+21);
                 if (exp2 >400)
                       {
                           exp2=ceil(exp2 + float(e1)/float(16)+17);
                           exp2= ceil(float(exp2)*115.0/100.0);
                       }
               } if (exp2>600) exp2=600;
                 exp1=exp1 -e1;
                 if (exp1>600) exp1 =600;
                 if (exp1<0) exp1=0;
    }
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    // TODO: Complete this function
if((E2<0) ||(E2>99)) return -99;
//con duong 1
float P1;
  if (EXP1>=S(EXP1)) P1=100;
   else P1=((float(EXP1)/S(EXP1)+80.0)/123.0)*100;
// con duong 2
 float nua_tien=float(M1)/2.0;
 if (E2%2!=0)
 {
     while ((2*nua_tien-M1)<=nua_tien)
     {
         sk1(HP1,M1);
         if((2*nua_tien-M1)>nua_tien) {break;}
         sk2(EXP1,M1);
         if((2*nua_tien-M1)>nua_tien){break;}
         sk3(EXP1,M1);
     }
 }
  else
  {
     sk1(HP1,M1);
     if (M1!=0) sk2(EXP1,M1);
     if (M1!=0) sk3(EXP1,M1);

  }
HP1=ceil(float(HP1)*83.0/100.0);
EXP1=ceil(float(EXP1)*117.0/100.0);
if (EXP1>600) EXP1=600;
float P2;
 if (EXP1>=S(EXP1)) P2=100;
   else P2=((float(EXP1)/S(EXP1)+80)/123.0)*100;

//con duong 3
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int i;
    if (E2<10) {i=E2;}
       else {i= ((E2/10)+(E2%10))%10;}
float P3=P[i];
//tong ket
if ((P1==100)&&(P2==100)&&(P3==100)) EXP1=ceil(float(EXP1)*75.0/100.0);
    else if ((float(P1+P2+P3)/3)<50){HP1=ceil(float(HP1)*85.0/100.0);EXP1=ceil(float(EXP1)*115.0/100.0);}
         else {HP1=ceil(float(HP1)*90.0/100.0);EXP1=ceil(float(EXP1)*120.0/100.0);}
if (EXP1>600) EXP1=600;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
 if((E3<0) ||(E3>99)) return -99;
int bando[10][10];
int sumi=0,sumj=0,diem_taxi,diem_Sher_Wat,toado_i,toado_j;
   for (int i=0;i<10;i++)
     for (int j=0;j<10;j++)
       {
         bando[i][j]=((E3*j)+(i*2))*(i-j);
         if (bando[i][j]>(E3*2)) sumi++;
         if(bando[i][j]<-E3)sumj++;
       }
   toado_i=rutgon(sumi);
   toado_j=rutgon(sumj);
diem_taxi=bando[toado_i][toado_j];
diem_Sher_Wat=gia_tri_duong_cheo(toado_i,toado_j,bando);

  if(abs(diem_taxi)>diem_Sher_Wat)
       {
        EXP1=ceil(EXP1*88.0/100.0);
        EXP2=ceil(EXP2*88.0/100.0);
        HP1=ceil(HP1*90.0/100.0);
        HP2=ceil(HP2*90.0/100.0);
        return diem_taxi;
       }
  else
       {
        EXP1=ceil(EXP1*112.0/100.0);
        EXP2=ceil(EXP2*112.0/100.0);
        HP1=ceil(HP1*110.0/100.0);
        HP2=ceil(HP2*110.0/100.0);
        if (EXP1>600)EXP1=600;
        if (EXP2>600)EXP2=600;
        if(HP1>666)HP1=666;
        if(HP2>666)HP2=666;
        return diem_Sher_Wat;
       }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
string se,chuoi_phu;
int i=0,k=0,do_dai_pass,phu=0,sum=0;
   while(email[i]!='@')
   {
       se=se+email[i];
       i++;
   }
int do_dai_se=se.length();
   for (int e=0;s[e]!='\0';e++)
   {
       sum++;
   }
   do_dai_pass=sum;
   if (do_dai_pass<8) return -1;
   if (do_dai_pass>20) return -2;
   for (int dem1=0;dem1<=(do_dai_pass-1);dem1++)
   {
       if (s[dem1]==se[k])
           while((k<do_dai_se)&&(s[dem1+k]==se[k]))
                  {
                        k++;
                  }
       if (k==do_dai_se) return -(300+dem1);
          else k=0;
   }
   for (int dem2=0;dem2<(do_dai_pass-2);dem2++)
      {
         if ((s[dem2]==s[dem2+1])&&(s[dem2]==s[dem2+2])) return -(400+dem2);

      }
    for (int dem3=0;dem3<=(do_dai_pass-1);dem3++)
    {
        if((s[dem3]=='@')||(s[dem3]=='#')||(s[dem3]=='%')||(s[dem3]=='$')||(s[dem3]=='!')) phu++;
    }
    if (phu==0) return -5;
      for (int dem4=0;dem4<=(do_dai_pass-1);dem4++)
    {
        if(((s[dem4]<'0')||(s[dem4]>'9'))
           && ((s[dem4]<'a')||(s[dem4]>'z'))
           &&((s[dem4]<'A')||(s[dem4]>'Z'))
           &&(s[dem4]!='@')&&(s[dem4]!='#')&&(s[dem4]!='%')&&(s[dem4]!='$')&&(s[dem4]!='!')) return dem4;

    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
 {
// TODO: Complete this function
int dinh_danh[num_pwds]={0};
string true_pass;
string pass[num_pwds];
int dem[num_pwds]; int x=0,max2=0,nho;
for(int a4=0;a4<num_pwds;a4++)
{

    pass[a4]=arr_pwds[a4];
}
for(int a2=0;a2<num_pwds;a2++)
{
     if (dinh_danh[a2]==0)
        {
            for (int a3=0;a3<num_pwds;a3++)
              {
                 if(pass[a2]==pass[a3]) {x=x+1;dem[a3]=0;dinh_danh[a3]=1;}

              }
              if (max2<x) max2=x;
               dem[a2]=x;
                x=0;
        }
}



for(int a5=0;a5<num_pwds;a5++)
{

    if((dem[a5]==max2)&&(pass[a5].length()>true_pass.length())){true_pass=pass[a5];}
}


for(int a6=0;a6<num_pwds;a6++)
{
    if(true_pass==pass[a6]){ nho=a6;break;}
}
 return nho;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
