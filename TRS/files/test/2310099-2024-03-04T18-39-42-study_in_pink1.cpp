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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
     if (E1 < 0 || E1 > 99) return -99;
int D;
    if(EXP1<0) EXP1=0; if(EXP1>600) EXP1=600;
    if(EXP2<0) EXP2=0; if(EXP2>600) EXP2=600;
    //Truong hop 1
 if((0<=E1)&&(E1<=3))
   {
    switch (E1)
    {
    case 0:
        EXP2+=29;
        break;
    case 1:
        EXP2+=45;
        break;
    case 2:
        EXP2+=75;
        break;
    case 3:
        EXP2+=149;
        break;
    default:
        break;
    }
    D=E1*3+EXP1*7;
    if( (D%2) == 0)
        EXP1=ceil(EXP1+D/200.0);
    else
        EXP1=ceil(EXP1-D/100.0);
    
   }
   //Truong hop 2
if((E1>=4)&&(E1<=99))
{
if((E1>=4)&&(E1<=19))
   EXP2=EXP2+ceil(E1/4.0)+19;
else {
    if((E1>=20)&&(E1<=49))
    EXP2=EXP2+ceil(E1/9.0)+21;
    else {
        if((E1>=50)&&(E1<=65))
        EXP2=EXP2+ceil(E1/16.0)+17;
        else {
              if((E1>=66)&&(E1<=79))
                {EXP2=EXP2+ceil(E1/4.0)+19;
                if(EXP2>200) EXP2=EXP2+ceil(E1/9.0)+21;
                }
                else {
                    if(( E1>=80  )&&( E1<=99  ))
                    {
                        EXP2=EXP2+ceil(E1/4.0)+ceil(E1/9.0)+40;
                        if(EXP2>400)
                         {EXP2=EXP2+ceil(E1/16.0)+17; EXP2=ceil(1.15*EXP2);}
                    }
                     }
             }

         }
    }
EXP1=EXP1-E1;
}
if(EXP1<0) EXP1=0; if(EXP1>600) EXP1=600;
if(EXP2<0) EXP2=0; if(EXP2>600) EXP2=600;
  
    return EXP1 + EXP2;
    
}

// Task 2
void dk(int &HP1, int &EXP1 , int &M1)
{
    if(HP1>666) HP1=666; if(HP1<0) HP1=0;
    if(EXP1>600) EXP1=600; if(EXP1<0) EXP1=0;
    if(M1<0) M1=0; if(M1>3000) M1=3000;
    
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    float P1,P2,P3,Ptb;
    if(HP1>666) HP1=666; if(HP1<0) HP1=0;
    if(EXP1>600) EXP1=600; if(EXP1<0) EXP1=0;
    if(M1<0) M1=0; if(M1>3000) M1=3000;
    //ROAD_1
    int a=sqrt(EXP1);
    int S,o=1;
    if(((a+1)*(a+1)-EXP1)>(EXP1-a*a))
    {
        S=a*a;
        P1=100.0;
    }
    else {
           S=(a+1)*(a+1);
           P1=(((EXP1*1.0/S)+80.0)/123.0)*100;
         }
    //ROAD_2
    int N=round(M1/2.0);
    int tiendachi=0;
    int A,B;
    if(M1 == 0) 
    { HP1=ceil(HP1*83.0/100); EXP1=ceil(EXP1*117.0/100); dk(HP1,EXP1,M1); }
    else { 
    if((E2%2) == 1)
    {
        while(tiendachi <= N)
        {
           if(HP1<200) { HP1=ceil(HP1*13.0/10); M1-=150; tiendachi+=150; dk(HP1,EXP1,M1);  if(tiendachi>N) break;}
           else { HP1=ceil(HP1*11.0/10); M1-=70; tiendachi+=70; dk(HP1,EXP1,M1); if(tiendachi>N) break; }

           if(EXP1<400) { M1-=200; tiendachi+=200; EXP1=ceil(EXP1*113.0/100); dk(HP1,EXP1,M1); if(tiendachi>N) break; }
           else {M1-=120; tiendachi+=120; EXP1=ceil(EXP1*113.0/100); dk(HP1,EXP1,M1); if(tiendachi>N) break; }

           if(EXP1<300) { M1-=100; tiendachi+=100; EXP1=ceil(EXP1*9.0/10); dk(HP1,EXP1,M1); if(tiendachi>N) break; }
           else { M1-=120; tiendachi+=120; EXP1=ceil(EXP1*9.0/10); dk(HP1,EXP1,M1); if(tiendachi>N) break;}
        }
        HP1=ceil(HP1*83.0/100); EXP1=ceil(EXP1*117.0/100);
        dk(HP1,EXP1,M1);
    }
    else 
    {   while( o == 1 )
        {
         if(HP1<200) { HP1=ceil(HP1*13.0/10); M1-=150; dk(HP1,EXP1,M1); if(M1<=0) { M1=0; break;} }
         else { HP1=ceil(HP1*11.0/10); M1-=70; dk(HP1,EXP1,M1); if(M1<=0) { M1=0; break; } }

         if(EXP1<400) { M1-=200; EXP1=ceil(EXP1*113.0/100); dk(HP1,EXP1,M1); if(M1<=0) { M1=0; break; } }
         else {M1-=120; EXP1=ceil(EXP1*113.0/100); dk(HP1,EXP1,M1); if(M1<=0) { M1=0; break; } }

         if(EXP1<300) { M1-=100; EXP1=ceil(EXP1*9.0/10); dk(HP1,EXP1,M1); if(M1<=0) { M1=0; break; } }
         else { M1-=120; EXP1=ceil(EXP1*9.0/10); dk(HP1,EXP1,M1); if(M1<=0) { M1=0; break; } }
         o+=1;
        }
        HP1=ceil(HP1*83.0/100); EXP1=ceil(EXP1*117.0/100); dk(HP1,EXP1,M1);
    }
    }
     a=sqrt(EXP1);
    
    if(((a+1)*(a+1)-EXP1)>(EXP1-a*a))
    {
        S=a*a;
        P2=100.0;
    }
    else {
           S=(a+1)*(a+1);
           P2=(((EXP1*1.0/S)+80.0)/123.0)*100.0; 
         }
    //ROAD_3
    int m,n,p;
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if(E2<10) P3=P[E2];
    if(E2>9) { p=E2%10; //hang don vi
               n=E2-p;
               m=n/10; //hang chuc
               n=m+p;
               if(n<10) P3=P[n];
               else P3=P[n-10];
             }
    ////////////////////////////
    Ptb=(P1+P2+P3)/3.0;
    if(Ptb == 100.0) EXP1=ceil(EXP1*75.0/100);
    if(Ptb<50) { HP1=ceil(HP1*85.0/100); EXP1=ceil(EXP1*115.0/100);}
    if((Ptb>=50)&&(Ptb<100)) { HP1=ceil(HP1*90.0/100); EXP1=ceil(EXP1*120.0/100);}

    if(HP1>666) HP1=666; if(HP1<0) HP1=0;
    if(EXP1>600) EXP1=600; if(EXP1<0) EXP1=0;
    if(M1<0) M1=0; if(M1>3000) M1=3000;
    return HP1 + EXP1 + M1;
    
}

// Task 3
int ura(int a)
{
    
    int m,n,p=a;
    if(a==100) return 1;
    for(int i=0;i<2;i=i+1)
    {
        if(p<10) break;
        m=a%10; //hang don vi
        n=(a-m)/10; //hang chuc
        p=m+n;
        a=p;
    }
    return p;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
  // Tao mang
    if(EXP1<0) EXP1=0; if(EXP2<0) EXP2=0; if(EXP1>600) EXP1=600; if(EXP2>600) EXP2=600;
    if(HP1<0) HP1=0; if(HP2<0) HP2=0; if(HP1>666) HP1=666; if(HP2>666) HP2=666;
    if(E3 <0 ) return -99; if(E3>99) return -99;
    int map[10][10];
    int to=0,nho=0;
    int x;
    int it,id,jt,jd;
    for(int i=0 ; i<10 ; ++i)
    {
        for(int j=0 ; j<10 ; ++j )
        {
            map[i][j]=((E3*j)+(i*2))*(i-j);
            if(map[i][j] > (E3*2)) to+=1;
            if(map[i][j] < (-E3)) nho+=1;
        }
    }
    int a=ura(to), b=ura(nho);
    x=map[a][b];
    if(a<=b) {it=0; jt=b-a;}
    else {it=a-b; jt=0; }
    if((a+b)<=9) { id=a+b; jd=0;}
    else { id=9; jd=a-(9-b);}
    int xm1,xm2,xm;
    if( it == 0)
    {
        xm1=map[it][jt];
        for(int i=0; i<=(9-jt) ;++i)
        {
            if(map[it+i][jt+i]>xm1) xm1=map[it+i][jt+i];
        }

    }
    else
    {
        xm1=map[it][jt];
        for(int i=0;i<=(9-it);++i)
        {
            if(map[it+i][jt+i]>xm1) xm1=map[it+i][jt+i];
        }
    }
    if( id == 9)
    {
        xm2=map[id][jd];
        for(int i=0; i<=(9-jd);i++)
        {
            if(map[id-i][jd+i]>xm2) xm2=map[id-i][jd+i]; 
        }
    }
    else
    {
        xm2=map[id][jd];
        for(int i=0;i<=id;++i)
        {
            if(map[id-i][jd+i]>xm2) xm2=map[id-i][jd+i];
        }
    }
    if(xm1>=xm2) xm=xm1;
    else xm=xm2;
    if( abs(x) > xm)
    {
        EXP1=ceil(EXP1*88/100.0); EXP2=ceil(EXP2*88/100.0);
        HP1=ceil(HP1*9/10.0); HP2=ceil(HP2*9/10.0);
        if(EXP1<0) EXP1=0; if(EXP2<0) EXP2=0; if(EXP1>600) EXP1=600; if(EXP2>600) EXP2=600;
        if(HP1<0) HP1=0; if(HP2<0) HP2=0; if(HP1>666) HP1=666; if(HP2>666) HP2=666;
        return x;
    }
    else
    {
        EXP1=ceil(EXP1*112/100.0); EXP2=ceil(EXP2*112/100.0);
        HP1=ceil(HP1*11/10.0); HP2=ceil(HP2*11/10.0);
        if(EXP1<0) EXP1=0; if(EXP2<0) EXP2=0; if(EXP1>600) EXP1=600; if(EXP2>600) EXP2=600;
        if(HP1<0) HP1=0; if(HP2<0) HP2=0; if(HP1>666) HP1=666; if(HP2>666) HP2=666;
        return xm;
    }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Tim se
    char se[100];
    for(int i=0 ; email[i] != '\0' ; i++)
    {
        if(email[i] == '@')
        {
            se[i] = '\0';
            break;
        }
        se[i] = email[i];
    }
    // Do dai s
    int N=0;
    for(int i=0 ; s[i] != '\0' ; ++i)
    {
        N+=1;
    }
    // Do dai se
    int n=0;
    for(int i=0 ; se[i] != '\0' ; ++i)
    {
        n+=1;
    }
    //Dieu kien do dai
    if(N<8) return -1;
    if(N>20) return -2;
    // Kiem tra dieu kien s co chua se 
    int q=0, p=0;
    if(se[0] == '\0') return -300;
    else {
           

           for(int k=0;k<=N-n;++k)
            {
    for(int i=0 ; i<n ;++i)
    {
        
        if(s[k+i]==se[i]) {p+=1;}
    }
    if(p == n) {q=k+1; break;}
    p=0;
            }

         }
         if(q != 0) return -(300+q-1);
    
    // Kiem tra dieu kien 3 ky tu lien tiep
    for(int i=0 ; i <= N-3 ; ++i)
    {
        if((s[i] == s[i+1])&&( s[i+1] == s[i+2])) return -(400+i);
    }
    // Kiem tra s co chua ky tu dac biet
    int m=0;
    for(int i=0; s[i] != '\0';i++)
    {
        if((s[i] != '@')&&(s[i] != '#')&&(s[i] != '%')&&(s[i] != '$')&&(s[i] != '!'))
        m+=1;
    }
    if(m == N) return -5;
    // Kiem tra s co chua ky tu khac yeu cau khong
    int l;
    for(int i=0;s[i] != '\0';++i)
    {
        if( ((s[i]>='a')&&(s[i]<='z')) || ( (s[i]>='A') && (s[i]<='Z') )||( s[i] =='@' )||(s[i]=='#')||(s[i] == '%')||(s[i] == '$')||(s[i]=='!')||((s[i]>='0')&&(s[i]<='9')))
         l+=1;
        else return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int ts=0,tsm=0,vt,kt,ktm;
    int n;
    for(int i=0;i<num_pwds;++i)
    {
      // arr_pwds[i];
      kt=strlen(arr_pwds[i]);
      for(int k=0 ; k<num_pwds;++k)
      {
        n=strcmp(arr_pwds[i],arr_pwds[k]);
        if(n==0)
        {
            ts+=1;
        }
      }
      if(ts>tsm)
      {
        tsm=ts;
        vt=i;
        ktm=kt;
      }
      if((ts == tsm)&&(kt>ktm))
      {
        ktm=kt;
        vt=i;
      }
      ts=0;
    }
    
    return vt;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////