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
void check(int &hp,int&exp)
{
    if(exp>600) exp=600;
    else if(exp<0) exp=0;
    if(hp>666) hp=666;
    else if(hp<0) hp=0;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1<0 || e1>99) return -99;
    check(e1,exp1);
    check(e1,exp2);

    if(e1<=3)
    {   int d=e1*3+exp1*7;
        if(e1==0)
        exp2+=29;
        else if(e1==1)
        exp2+=45;
        else if(e1==2)
        exp2+=75;
        else if(e1==3)
        exp2+=149;
        if(d%2==0)
        exp1=exp1+d/200+(d%200!=0);
        else exp1=exp1-d/100;

    }
    else
    {
        if(e1<20) exp2+= e1/4 +19 +(e1%4!=0);
        else if(e1<50) exp2+=e1/9 +21 +(e1%9!=0);
        else if(e1<66) exp2+=e1/16 +17 +(e1%16!=0);
        else if (e1<80)
        {
            exp2+= e1/4 +19 +(e1%4!=0);
            if(exp2>200)
            exp2+=e1/9 +21 +(e1%9!=0);

        }
        else
        {
            exp2=exp2+ e1/4 +19 +(e1%4!=0);
            exp2=exp2 + e1/9 +21+(e1%9!=0);
            if(exp2>400)
            {exp2=exp2+ e1/16 +17 +(e1%16!=0);
            exp2=exp2*23/20+(exp2%20!=0);
            }

        }
        exp1-=e1;
    }
    if(exp2>600)
    exp2=600;
    if(exp1<0) exp1=0;
    else if(exp1>600) exp1=600;
    return exp1 + exp2;
}

// Task 2
int SNT(int n)
{
    int a=sqrt(n);
    if( ( n - a*a)>( (a+1)*(a+1)-n  ) ) return (a+1)*(a+1);
    else return(a*a);
}
void event(int & hp, int & exp, int & m, int &n)
{ 
 switch (n)
 {
 case 1:
 n++;
    if(hp<200)
          {
              m-=150;
              hp=hp*13/10 + (hp%10!=0);
            
            }
             else
            {
            m-=70;
            hp=hp*11/10 +(hp%10!=0);
             }
    if(hp>666) hp=666;    
    break;
 
 case 2: 
 n++;
    if(exp<400) m-=200;
    else m-=120;
    exp+=exp*13/100 + (exp%100!=0);
    if(exp>600) exp=600;
    break;

 case 3:
 n++;
   if(exp<300) m-=100;
   else m-=120;
   exp-=exp/10;
   break;

 }
}
double Fp(int exp)
{
    int s=SNT(exp);
    if(exp>=s) return 100;
    return (double(exp)/double(s) + 80)/1.23;
    
}
int traceLuggage(int & hp, int & exp, int & m, int e2) 
{if(e2<0 || e2>99) return -99;
check(hp,exp);
if(m>3000) m=3000;
    //road 1
    double p1,p2,p3;
    p1=Fp(exp);
//road 2
    int n=1;
    if(m<=0) m=0;//m=0 thi reset k lam gi ca.
    else if(e2%2==0)//th e chẵn
    {
        while(n<=3)
        {
        if(m<=0)
            {
            m=0;
            break;
            }
            event(hp,exp,m,n);
        } 
       if(m<0) m=0;
    }
    else //e lẻ
    { 
        int hm=m/2+(m%10==0);
        m-=hm;
        while (hm>=0)
        {   
            event(hp,exp,hm,n);
            if(n==4)n=1;
        }
        m+=hm;
        if(m<0) m=0;
    }
    //kthuc dù e lẻ hay chẵn đều thay doi
    hp=hp*83/100 +(hp%100!=0) ;
    exp=exp+  exp*17/100 +(exp%100!=0) ;
    check(hp,exp);
    //tìm p2:
    p2=Fp(exp);
//road 3
    int A[10]={32,47,28,79,100,50,22,83,64,11};
    int i=(e2/10+e2%10)%10;
    p3=A[i];
//sau khi di het ca 3:
    if(p1==100 && p2==100 && p3==100) exp=exp*3/4 + (exp%4!=0);
    else if( (p1+p2+p3)/3<50)
    {
        hp=hp*17/20 + (hp%20!=0);
        exp=exp*23/20 + (exp%20!=0);
    }
    else 
    {
        hp=hp*9/10 + (hp%10!=0);
        exp=exp*12/10+ (exp%5!=0);
    }
    check(hp,exp);
    return hp + exp + m;
}

// Task 3
int changeNum(int x)
{   int n=0;
    while(x>0)
    {
        n+=x%10;
        x=x/10;
    }
    if(n>9) return changeNum(n);
    else return n;
}
int chaseTaxi(int & hp1, int & exp1, int & hp2, int & exp2, int e3) {
    //check event
    if(e3<0 || e3>99) return -99;
    //check input
    check(hp1,exp1);
    check(hp2,exp2);
    //tao ma tran
    int A[10][10];
    int x=0,y=0,max=0;//max se la diem cua sherlock
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            {
                A[i][j]=((e3*j)+(i*2))*(i-j);
                if(A[i][j]>e3*2) x++;
                else if(A[i][j]<(e3*-1)) y++;
                
            }
    }
    x=changeNum(x);
    y=changeNum(y);
    int maxC=A[x][y];
    //tim diem cua Sherlock
    if(x<=y)
    {
        int j=y;
        for(int i=x;i<10;i++)
        {   if(A[i][j]>max) max=A[i][j];
            j--;
            if(j<0) break;
        }
        
    }
    else
    {   int diff=x-y;
        //duong cheo trai
        for(int j=0;diff<10;j++)
        {
         if(A[diff][j]>max) max=A[diff][j];
         diff++;
        }
        //duong cheo phai
        int total=x+y;
        if(total<=9)
        {int j=0;
        for(int i=total;i>=0;i--)
            {   if(A[i][j]>max) max=A[i][j];
                j++;

            }
        }
        else {
            int j=total-9;
            for(int i=9;j<10;i--)
            {
                if(A[i][j]>max) max=A[i][j];
                j++;
            }
        }
    }
    //max la diem cua sherlock, maxC la diem cua xe
    if(abs(maxC)>max)
    {
        exp1=exp1*22/25 +(exp1%25!=0);
        exp2=exp2*22/25 +(exp2%25!=0);
        hp1=hp1*9/10 +(hp1%10!=0);
        hp2=hp2*9/10 +(hp2%10!=0);
    if(exp1>600) exp1=600;
    if(exp2>600) exp2=600;
    if(hp1>666) hp1=666;
    if(hp2>666) hp2=666;
        return maxC;


    
    }
    else 
    {
        exp1=exp1*28/25 +(exp1%25!=0);
        exp2=exp2*28/25 +(exp2%25!=0);
        hp1=hp1*11/10 +(hp1%10!=0);
        hp2=hp2*11/10 +(hp2%10!=0);
    if(exp1>600) exp1=600;
    if(exp2>600) exp2=600;
    if(hp1>666) hp1=666;
    if(hp2>666) hp2=666;
        return max;

    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string em=email,se,ss=s;
    int kt=0;//ki tu dac biet
    if(ss.size()<8) return -1;
    else if(ss.size()>20) return -2;
    //tim se
    for(int i=0;i<em.size();i++)
    {
        if(email[i]=='@') 
        {
            se=em.substr(0,i);
            break;
        }
    }
    //se co trong s
    if(ss.find(se)<=ss.size()) return -(300+ss.find(se));
    //s co nhieu hon 2 ky tu lien tiep
    for(int i=0;i<ss.size()-1;i++)
    {   if(ss[i]=='@' || ss[i]=='#'|| ss[i]=='%' || ss[i]=='$'||ss[i]=='!') kt++;
        string m=ss.substr(i,3);
        if(m[0]==m[1]&&m[1]==m[2]) return -(400+i);
    }
    //ko co ky tu
    if(kt==0) return -5;
   return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
int a[num_pwds];
for(int i=0;i<num_pwds;i++)
{   a[i]=1;
   for(int j=i+1;j<num_pwds;j++)
   {
    if(strcmp(arr_pwds[i],arr_pwds[j]) == 0) a[i]=a[i]+1;
   }
    
}
// giờ mình có 1 mảng a chứa số lần xuất hiện
int max=-1,ans=0; //kiểu gì cũng sẽ có thằng xuất hiện nhiều hơn 0 lần mà ha?
for(int i=0;i<num_pwds;i++)
{
    if(a[i]>max)
   { max=a[i];
    ans=i;}
    else if(a[i]==max) // ok có cùng lần xuất hiện r. combat với nhau thôi
    {   if(strcmp(arr_pwds[i],arr_pwds[max])>0) ans=i; }
}
    return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////