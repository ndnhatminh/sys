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
 int ktraexp (int n) {
        if (n<0) {
            n=0;
        } else if (n>600) {
            n=600;
        } else {
            n=n;
        }
        return n;
    }
  
      int ktrahp (int n) {
        if (n<0) {
            n=0;
        } else if (n>666) {
            n=666;
        } else {
            n=n;
        }
        return n;
    }
    
    int ktram (int n) {
        if (n<=0) {
            n=0;
        } else if (n>3000) {
            n=3000;
        } else {
            n=n;
        }
        return n;
    }
    
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int d;
    float exp11,exp22,f,ee,exp222;

if (e1 < 0 || e1 > 99) {
return -99; 
  } 
  exp1= ktraexp (exp1);
  exp2= ktraexp (exp2);
  
 if (e1>=0&&e1<=3) {
    if (e1==0) {
        exp2=exp2+29;
        exp1= ktraexp (exp1);
        exp2= ktraexp (exp2);
    } else if (e1==1) {
        exp2=exp2+45;
        exp1= ktraexp (exp1);
        exp2= ktraexp (exp2);
    } else if (e1==2) {
        exp2=exp2+75;
        exp1= ktraexp (exp1);
        exp2= ktraexp (exp2);
    } else if (e1==3) {
        exp2=exp2+29+45+75;
        exp1= ktraexp (exp1);
        exp2= ktraexp (exp2);
    }
    d=e1*3+exp1*7;
    f=d;
    if (d%2==0) {
       exp11=exp1+f/200;
       
    } else {
       exp11=exp1-f/100;
       
    }
    exp1=ceil(exp11);
    exp1= ktraexp (exp1);
    exp2= ktraexp (exp2);
  }
  
else if (e1>=4&&e1<=99) {
    ee=e1;
    exp222=exp2;
  if (e1>=4&&e1<=19) {
      exp22=exp222+ee/4+19;
      exp222=ceil(exp22);
      exp222= ktraexp (exp222);
  } else if (e1>=20&&e1<=49) {
      exp22=exp222+ee/9+21;
      exp222=ceil(exp22);
      exp222= ktraexp (exp222);
  } else if (e1>=50&&e1<=65) {
      exp22=exp222+ee/16+17;
      exp222=ceil(exp22);
      exp222= ktraexp (exp222);
  } else if (e1>=66&&e1<=79) {
      exp22=exp222+ee/4+19;
      exp222=ceil(exp22);
      exp222= ktraexp (exp222);
      if (exp222>200) {
           exp22=exp222+ee/9+21;
           exp222=ceil(exp22);
           exp222= ktraexp (exp222);
      }
  } else if (e1>=80&&e1<=99) {
      exp22=exp222+ee/4+19;
      exp222=ceil(exp22);
      exp222= ktraexp (exp222);
      exp22=exp222+ee/9+21;
      exp222=ceil(exp22);
      exp222= ktraexp (exp222);
      if (exp222>400) {
          exp22=exp222+ee/16+17;
          exp222=ceil(exp22);
          exp222= ktraexp (exp222);
          exp22=exp222+0.15*exp222;
          exp222=ceil(exp22);
          exp222= ktraexp (exp222);
      }
  }

  exp1=exp1-e1;
  exp1= ktraexp (exp1);
  exp2= ktraexp (exp222);
  }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int s,x,i;
    float a,p1,EXP11,HP11,HP111,M11,p2,p3,ptb,M111;
    
    if (E2 < 0 || E2 > 99) {
return -99; 
  } 
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    M1=ktram(M1);
//con duong 1
    a=sqrt(EXP1);
    s=round(a)*round(a);
    M11=0;
    M111=M1*0.5;
    if (EXP1>=s) {
        p1=1;
    } else {
        p1=(float(EXP1)/s+80)/123;
    }
//con duong 2 le
if (M1==0) 
{
     HP11=HP1*0.83;
     EXP11=EXP1*1.17;
     EXP1=ceil(EXP11);
     HP1=ceil(HP11);
     EXP1=ktraexp(EXP1);
     HP1=ktrahp(HP1);
     M1=ktram(M1); 
} else 
{
     if (E2%2!=0) 
    {
         do 
         {
          if (HP1<200) 
          {
        HP11=float(HP1)*1.3;
        HP1=ceil(HP11);
        M1=M1-150;
        M11=M11+150;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
           } else 
           {
        HP11=float(HP1)*1.1;
        HP1=ceil(HP11);
        M1=M1-70;
        M11=M11+70;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
          } 
         if (M11>M111) 
         {
             break;
         } else 
         {
         
         if (EXP1<400) 
         {
        M1=M1-200;
        M11=M11+200;
        M1=ktram(M1);
         } else 
          {
        M1=M1-120;
        M11=M11+120;
        M1=ktram(M1);
          }
         EXP11=float(EXP1)*1.13;
         EXP1=ceil(EXP11);
         EXP1=ktraexp(EXP1);
         HP1=ktrahp(HP1);
         M1=ktram(M1);
         }   if (M11>M111) 
         {
             break;
         } else 
         {
         if (EXP1<300) {
         M1=M1-100;
        M11=M11+100;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
         } else {
        M1=M1-120;
        M11=M11+120;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
         } 
          EXP11=float(EXP1)*0.9;
         EXP1=ceil(EXP11);
         EXP1=ktraexp(EXP1);
         HP1=ktrahp(HP1);
         M1=ktram(M1);
         }}
         while (M11<=M111);
    } 
//con duong 2 so chan
    else 
    {
    if (HP1<200) {
        HP11=float(HP1)*1.3;
        HP1=ceil(HP11);
        M1=M1-150;
        M11=M11+150;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
    } else {
        HP11=float(HP1)*1.1;
        HP1=ceil(HP11);
        M1=M1-70;
        M11=M11+70;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
    }  
    if (M1>0) 
    {
        if (EXP1<400) {
            M1=M1-200;
            M11=M11+200;
            EXP1=ktraexp(EXP1);
            HP1=ktrahp(HP1);
            M1=ktram(M1);
        } else {
            M1=M1-120;
            M11=M11+120;
            EXP1=ktraexp(EXP1);
            HP1=ktrahp(HP1);
            M1=ktram(M1);
        }
         EXP11=float(EXP1)*1.13;
         EXP1=ceil(EXP11);
         EXP1=ktraexp(EXP1);
         HP1=ktrahp(HP1);
         M1=ktram(M1);
    } 
    else 
    {
        M1=ktram(M1);
    }
    if (M1>0) 
    {
    if (EXP1<300) {
        M1=M1-100;
        M11=M11+100;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
    } else {
        M1=M1-120;
        M11=M11+120;
        EXP1=ktraexp(EXP1);
        HP1=ktrahp(HP1);
        M1=ktram(M1);
    } 
    EXP11=float(EXP1)*0.9;
    EXP1=ceil(EXP11);
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    M1=ktram(M1);
    }
    else 
    {
        M1=ktram(M1);
    }
    }
     HP11=HP1*0.83;
     EXP11=EXP1*1.17;
     EXP1=ceil(EXP11);
     HP1=ceil(HP11);
     EXP1=ktraexp(EXP1);
     HP1=ktrahp(HP1);
     M1=ktram(M1);
}
//tinh p2
a=sqrt(EXP1);
    s=round(a)*round(a);
    if (EXP1>=s) {
        p2=1;
    } else {
        p2=(float(EXP1)/s+80)/123;
    }
 //con duong 3
int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
if (E2>=0&&E2<10) {
    i=E2;
} else {
    i=(int(E2/10)+int(E2%10))%10;
}
p3=float(P[i])*0.01;
if (p1==1&&p2==1&&p3==1) {
    EXP11=float(EXP1)*0.75;
    EXP1=ceil(EXP11);
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    M1=ktram(M1);
}
    else {
        ptb=(p1+p2+p3)/3;
if (ptb<0.5) {
    HP11=float(HP1)*0.85;
    EXP11=float(EXP1)*1.15;
    EXP1=ceil(EXP11);
    HP1=ceil(HP11);
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    M1=ktram(M1);
}
 else {
     HP11=float(HP1)*0.9;
     EXP11=float(EXP1)*1.2;
     EXP1=ceil(EXP11);
     HP1=ceil(HP11);
     EXP1=ktraexp(EXP1);
     HP1=ktrahp(HP1);
     M1=ktram(M1);
 }
    }
 EXP1=ktraexp(EXP1);
 HP1=ktrahp(HP1);
 M1=ktram(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int xeotraiphai (int taxi[10][10],int i, int j) {
int taxi1=taxi[i][j];
int taxi2=taxi[i][j];
int taxi3=taxi[i][j];
int taxi4=taxi[i][j];
int l=i;
int k=j;
int m,n,a,b,diem;
m=i;
n=j;
a=i;
b=j;

while (i<10&&j<10) {
    if (taxi[i][j]>=taxi1) {
        taxi1=taxi[i][j];
    }
    i=i+1;
    j=j+1;
}

while (l>=0&&k>=0) {
    if (taxi[l][k]>=taxi2) {
         taxi2=taxi[l][k];
    }
    l=l-1;
    k=k-1;
}

while (m<10&&n>=0) {
    if (taxi[m][n]>=taxi3) {
         taxi3=taxi[m][n];
    }
    m=m+1;
    n=n-1;
}

while (a>=0&&b<10) {
    if (taxi[a][b]>=taxi4) {
         taxi4=taxi[a][b];
    }
    a=a-1;
    b=b+1;
}
//so sanh
if (taxi1>=taxi2&&taxi1>=taxi3&&taxi1>=taxi4) {
    diem=taxi1;
} else if (taxi2>=taxi1&&taxi2>=taxi3&&taxi2>=taxi4) {
    diem=taxi2;
} else if (taxi3>=taxi1&&taxi3>=taxi2&&taxi3>=taxi4) {
    diem=taxi3;
} else if (taxi4>=taxi1&&taxi4>=taxi2&&taxi4>=taxi3) {
    diem=taxi4;
}
    return diem;
}

int demduong (int taxi[10][10], int E3) {
int duong=0;
for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
        if (taxi[i][j]>E3*2) {
        duong=duong+1;
        } 
    }
}
return duong;
}

int demam (int taxi[10][10], int E3) {
int am=0;
for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
        if (taxi[i][j]<-E3) {
        am=am+1;
        } 
    }
}
return am;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
return -99; 
  } 
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    EXP2=ktraexp(EXP2);
    HP2=ktrahp(HP2);
    int taxi[10][10];
for (int i=0; i<10; i++) 
{
   for (int j=0; j<10; j++) 
   {
       taxi[i][j]=((E3*j)+(i*2))*(i-j);
   }
  
}
int duong=demduong(taxi,E3);
int am=demam(taxi,E3);
while(duong>=10) 
{
duong=(duong/10+duong%10);
}
while(am>=10) 
{
am=(am/10+am%10);
}
int diem=xeotraiphai(taxi,duong,am);
int diemtaxi=taxi[duong][am];
if (abs(diemtaxi)>abs(diem)) {
    EXP1=(EXP1*0.88)+0.9999;
    EXP2=(EXP2*0.88)+0.9999;
    HP1=(HP1*0.9)+0.9999;
    HP2=(HP2*0.9)+0.9999;
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    EXP2=ktraexp(EXP2);
    HP2=ktrahp(HP2);
    return diemtaxi;
} 
else if (abs(diemtaxi)<abs(diem))
{
    EXP1=(EXP1*1.12)+0.9999;
    EXP2=(EXP2*1.12)+0.9999;
    HP1=(HP1*1.1)+0.9999;
    HP2=(HP2*1.1)+0.9999;
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    EXP2=ktraexp(EXP2);
    HP2=ktrahp(HP2);
    return diem;
} else if (abs(diemtaxi)==abs(diem))
{
    if (diemtaxi>0) {
    EXP1=(EXP1*1.12)+0.9999;
    EXP2=(EXP2*1.12)+0.9999;
    HP1=(HP1*1.1)+0.9999;
    HP2=(HP2*1.1)+0.9999;
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    EXP2=ktraexp(EXP2);
    HP2=ktrahp(HP2);
    return diemtaxi;
}
else
{
    EXP1=(EXP1*1.12)+0.9999;
    EXP2=(EXP2*1.12)+0.9999;
    HP1=(HP1*1.1)+0.9999;
    HP2=(HP2*1.1)+0.9999;
    EXP1=ktraexp(EXP1);
    HP1=ktrahp(HP1);
    EXP2=ktraexp(EXP2);
    HP2=ktrahp(HP2);
    return diem;
}
}
return -1;
}
// Task 4
int kytu(char s1[], int n) {
    int y=0;
    int a=strlen(s1);
    for (int i=0; i<=a-3; i++) {
        if (s1[i]==s1[i+1]&&s1[i+1]==s1[i+2]) {
            y=1;
            break;
        }
    }
    return y;
}

int dem(char s1[], int n) {
    int sci=0;
    int a=strlen(s1);
    for (int i=0; i<=a-3; i++) {
        if (s1[i]==s1[i+1]&&s1[i+1]==s1[i+2]) {
            sci=i;
            break;
        }
    }
    return sci;
}

int ktrakytu(char s1[], int n) {
    int z=0;
    for (int i=0; i<=n-1; i++) {
        if (!((s1[i]>='0'&&s1[i]<='9')||(s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z')||(s1[i]=='@'||s1[i]=='#'||s1[i]=='%'||s1[i]=='$'||s1[i]=='!'))) {
            z = i;
            break;
        }
    }
    return z;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int a=strlen(s);
    int b=strlen(email);
    char email1[b];
    char s1[a];
    strcpy(s1, s);
    strcpy(email1, email);
    int c=strlen(strtok(email1, "@"));
    char se[c];
    strcpy(se, strtok(email1, "@"));
    if (strlen(s)<8) {
        return -1;
    } else if (strlen(s)>20) {
        return -2;
    } else if (strstr(s, se)!=NULL) {
        int sei=-300-(strstr(s, se)-s);
        return sei;
    } else if (kytu(s1, strlen(s))==1) {
        int sci=-400-dem(s1, strlen(s));
        return sci;
    } else if (ktrakytu(s1, strlen(s1))!=0) {
        return ktrakytu(s1, strlen(s1));
    } else if (strchr(s, '@')==NULL&&strchr(s, '#')==NULL&&strchr(s, '$')==NULL&&strchr(s, '!')==NULL&&strchr(s, '%')==NULL) {
        return -5;
    } else {
        return -10;
    }
}

// Task 5
int chuoi(int arr[], int num_pwds) {
    int y=1;
    for (int i=0; i<num_pwds; i++) {
        if (arr[i]!=arr[0]) {
            y=0;
            break;
        }
    }
    return y;    
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max=1;
    int k=0;
    int s=0;
    int arr[num_pwds];

    for (int i=0; i<num_pwds; i++) {
        arr[i]=0;
    }


    for (int i=0; i<num_pwds; i++) {
        int dem = 1;
        for (int j=i+1; j<num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j])==0) {
                dem=dem+1;
            }
        }
        arr[i]=dem;
    }


    if (chuoi(arr, num_pwds)==0) {
        for (int i=0; i<num_pwds;i++) {
            if (arr[i]>max) {
                max=arr[i];
                k=i;
                s=strlen(arr_pwds[i]);
            }
        }

        for (int i=0; i<num_pwds; i++) {
            if (arr[i]==max&&strlen(arr_pwds[i])>s) {
                s=strlen(arr_pwds[i]);
                k=i;
            }
        }
    }


    else {
        for (int i=0; i<num_pwds; i++) {
            if (strlen(arr_pwds[i])>s) {
                s=strlen(arr_pwds[i]);
                k=i;
            }
        }
    }
    return k;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////