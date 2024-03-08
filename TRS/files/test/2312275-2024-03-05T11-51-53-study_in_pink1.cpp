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
//check
void checkhp(int & a)
{
    if(a<0)
    {a=0;
    return;
    }
    if(a>666)
    a=666;
    return;
}
void checkexp(int & b)
{
    if((b>=0)&&(b<=600))
    return;
    if(b<0)
    {
    b=0;    
    return;
    }
    if(b>600)
    {
    b=600;    
    return; 
    }
}
void checkm(int & c)
{
    if((c>=0)&&(c<=3000))
    return;
    if(c<0)
    {
    c=0;
    return;
    }
    if(c>3000)
    {
    c=3000;
    return;
    }
}
// if((e<0)||(e>99)) return -99;
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if((e1<0)||(e1>99))
    return -99;
    checkexp(exp1);
    checkexp(exp2);
    
    
    // TH1
    if((e1>=0)&&(e1<=3))
    {
    int d;
    if(e1==0)
    exp2+=29;
    if(e1==1)
    exp2+=45;
    if(e1==2)
    exp2+=75;
    if(e1==3)
    exp2+=149;
    checkexp(exp2);
    d=e1*3+exp1*7;
    if(d%2==0)
    exp1=ceil(exp1+d*1.0/200);
    else exp1=ceil(exp1-d*1.0/100);
    checkexp(exp1);
    }
    // TH2
    if((e1>=4) && (e1<=19))
    exp2=ceilf(exp2 + (e1*1.0/4 + 19));
    if((e1>=20) && (e1<=49))
    exp2=ceilf(exp2 + (e1*1.0/9 + 21));
    if((e1>=50) && (e1<=65))
    exp2=ceilf(exp2 + (e1*1.0/16 + 17));
    if((e1>=66) && (e1<=79))
    {
      exp2=ceilf(exp2 + (e1*1.0/4 + 19));
      checkexp(exp2);
      if(exp2>200)
          exp2=ceilf(exp2 + (e1*1.0/9 + 21));
    }
    if((e1>=80) && (e1<=99))
    {
        exp2=ceilf(exp2 + (e1*1.0/4 + 19));
        checkexp(exp2);
        exp2=ceilf(exp2 + (e1*1.0/9 + 21));
        checkexp(exp2);
        if(exp2>400)
        {
        exp2=ceilf(exp2 + (e1*1.0/16 + 17));
        checkexp(exp2);
        exp2 = ceilf(exp2 * 1.15);
        checkexp(exp2);
        }
    }
    checkexp(exp2);
    if((e1>=4)&&(e1<=99))
    {
        exp1 -=e1;
    checkexp(exp1);
    }
        
        return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if((E3<0)||(E3>99))
    return -99;
    checkexp(EXP1);
    checkhp(HP1);
    checkm(M1);
    float p1,p2,p3;
    int s;
    s=0;
    //road 1
    for(int i=0;i<=sqrt(EXP1)+1;i++)
    {
        
        if(abs(EXP1-i*i)<abs(EXP1-s))
        s=i*i;
    }
    
    if(EXP1>=s)
    p1=1;
    else p1=((EXP1*1.0/s)+80)/123;
    
    //road 2
    int s2;
    s2=0;
    int Mx=0.5*M1;
    int My=0;

    
    if(E3%2!=0)
    { 
      while(1)
    {
    	if(M1==0)
    	{
    	HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;	
		}
    if(HP1<200)
    {   
        HP1=ceilf(HP1+0.3*HP1);
        checkhp(HP1);
        M1-=150;
        checkm(M1);
        My+=150;
        if((My>Mx)||(M1==0))
        {   HP1=ceilf(HP1*0.83);
    EXP1=ceilf(EXP1*1.17);
    checkhp(HP1);
    checkexp(EXP1);
        break;
        }
    }
    else
        {
        HP1=ceilf(HP1+0.1*HP1);
        checkhp(HP1);
        M1-=70;
        checkm(M1);
        My+=70;
        if((My>Mx)||(M1==0))
        {   HP1=ceilf(HP1*0.83);
    EXP1=ceilf(EXP1*1.17);
    checkhp(HP1);
    checkexp(EXP1);
        break;
        }
        }
        
    if(EXP1<400)
    {
        M1-=200;
        checkm(M1);
        My+=200;
        EXP1=ceilf(EXP1*1.13);
        checkexp(EXP1);
        if((My>Mx)||(M1==0))
        {   HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;
        }
    }
    else {
        M1-=120;
        checkm(M1);
        My+=120;  
        EXP1=ceilf(EXP1*1.13);
        checkexp(EXP1);
        if((My>Mx)||(M1==0))
        {   HP1=ceilf(HP1*0.83);
    EXP1=ceilf(EXP1*1.17);
    checkhp(HP1);
    checkexp(EXP1);
        break;
        }
    }
    
    
    if(EXP1<300)
    {
        M1-=100;
        checkm(M1);
        EXP1=ceilf(EXP1*0.9);
        checkexp(EXP1);
        My+=100;
        if((My>Mx)||(M1==0))
        {   HP1=ceilf(HP1*0.83);
    EXP1=ceilf(EXP1*1.17);
    checkhp(HP1);
    checkexp(EXP1);
        break;
        }
    }
    else {
        M1-=120;
        checkm(M1);
        EXP1=ceilf(EXP1*0.9);
        checkexp(EXP1);
        My+=120;
        if((My>Mx)||(M1==0))
        {   HP1=ceilf(HP1*0.83);
    EXP1=ceilf(EXP1*1.17);
    checkhp(HP1);
    checkexp(EXP1);
        break;
        }
   
    }
 
    }
    }
    

    else { 
        
        while(1)
    {
    	if(M1==0)
    	{
    	HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;	
		}
        
    if(HP1<200)
    { 
        HP1=ceilf(HP1+0.3*HP1);
        checkhp(HP1);
        M1-=150;
        if(M1<=0)
        {M1=0;
        HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;
        }
    }
    else
        {
        HP1=ceilf(HP1+0.1*HP1);
        checkhp(HP1);
        M1-=70;
        if(M1<=0)
        {M1=0;
        HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;
        }
        }
        
    if(EXP1<400)
    {
        M1-=200;
        EXP1=ceilf(EXP1*1.13);
    checkexp(EXP1);
        
        if(M1<=0)
        
        {M1=0;
        HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;
        }
    }
    else {
        M1-=120;
        EXP1=ceilf(EXP1*1.13);
    checkexp(EXP1);
        if(M1<=0)
        {M1=0;
        HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;
        }
    }

    
    if(EXP1<300)
    {
        M1-=100;
        EXP1=ceilf(EXP1*0.9);
        checkexp(EXP1);
        if(M1<=0)
        {M1=0;
       HP1=ceilf(HP1*0.83);
       EXP1=ceilf(EXP1*1.17);
       checkhp(HP1);
       checkexp(EXP1);
        break;
        }
    }
    else {
        M1-=120;
        EXP1=ceilf(EXP1*0.9);
        checkexp(EXP1);
        if(M1<=0)
        {M1=0;
        HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        checkhp(HP1);
        checkexp(EXP1);
        break;
        }
    }
    HP1=ceilf(HP1*0.83);
    EXP1=ceilf(EXP1*1.17);
    checkhp(HP1);
    checkexp(EXP1);
    break;
    }
    }
 
    ///////
    

    for(int j=0;j<=sqrt(EXP1)+1;j++)
    {
        
        if(abs(EXP1-j*j)<=abs(EXP1-s2))
        s2=j*j;
    }
    
   
    if(EXP1>=s2)
    p2=1;
    else p2=((EXP1*1.0/s2)+80)/123;
    
    
    
    // road3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if(E3>=10)
    { 
      int t1,t2;
      t1=E3;
      t2=t1/10+t1%10;
      E3=t2%10;
      p3=(P[E3]*1.0)/100;
        
    }
    else p3=(P[E3]*1.0)/100;
    // Cuoi con duong
    if((p1==1)&&(p2==1)&&(p3==1))
    {
        EXP1=ceilf(EXP1*0.75);
        checkexp(EXP1);
    }
    else {
        float p4=(p1+p2+p3)/3;
        if(p4<0.5)
        {
            HP1=ceilf(HP1*0.85);
            EXP1=ceilf(EXP1*1.15);
            checkexp(EXP1);
            checkhp(HP1);
            
        }
        else {
            HP1 = ceilf(HP1*0.9);
            EXP1 = ceilf(EXP1 * 1.2);
            checkexp(EXP1);
            checkhp(HP1);
        }
    }

    return HP1 + EXP1 + M1; 
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if((E3<0)||(E3>99))
    return -99;
    checkexp(EXP1);
    checkexp(EXP2);
    checkhp(HP1);
    checkhp(HP2);
    
    int mat[10][10]={0};
    int m=0,n=0;
    int max, max1=-9999999, max2=-9999999;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        mat[i][j]=(E3*j + (i*2))*(i-j);
    }
    
    // check m,n
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
        if(mat[i][j]>(E3*2))
        m+=1;
        if(mat[i][j]<(-E3))
        n+=1;
        }
    }
    
    while(m>=10)
    {  
       int temp;
       temp=m;
       m=temp%10+temp/10;
    }
    while(n>=10)
    {  
       int tmp;
       tmp=n;
       n=tmp%10+tmp/10;
    }
    int p=m;
    int u =n;
    //check sherlock point
    while((m!=0)&&(n!=0))
    {
        if((m==0)||(n==0))
        break;
        m--;
        n--;
    }
    // max1
    
    if(((m==0)&&(n==9))||((n==0)&&(m==9)))
    max1=mat[m][n];
    else while((n!=10)&&(m!=10))
    {
       if(mat[m][n]>max1)
       max1=mat[m][n];
       m++; n++;
    }
    
    // max2
    m=p;
    n=u;
    while((m!=9)&&(n!=9))
    {
        if((m==9)||(n==9))
        break;
        m--;
        n++;
    }
     if(((m==0)&&(n==0))||((n==9)&&(m==9)))
    max2=mat[m][n];
    else while((m!=10)&&(n!=-1))
    {
       if(mat[m][n]>max2)
       max2=mat[m][n];
       m++; n--;
    }
    // max
    
    max=abs(max1);
    if(abs(max2)>max)
    max=abs(max2);
    //final
    if(abs(mat[p][u])>max)
    {
        EXP1=ceilf(EXP1*0.88);
        EXP2=ceilf(EXP2*0.88);
        HP1=ceilf(HP1*0.9);
        HP2=ceilf(HP2*0.9);
        checkhp(HP2);
        checkhp(HP1);
        checkexp(EXP2);
        checkexp(EXP1);
    }
    else {
        EXP1=ceilf(EXP1*1.12);
        EXP2=ceilf(EXP2*1.12);
        HP1=ceilf(HP1*1.1);
        HP2=ceilf(HP2*1.1); 
        checkhp(HP2);
        checkhp(HP1);
        checkexp(EXP2);
        checkexp(EXP1);
    }
    if(abs(mat[p][u])>max)
    return mat[p][u];
    else  return max;
    
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int a;
    string ss;
    ss=s;
    string emaill;
    emaill=email;
    for(int i=0;i<emaill.size();i++)
    {
        if(emaill[i]=='@')
        {
            a=i;
            break;
        } 
    }
    se=emaill.erase(a);
    if(ss.size()<8)
    return -1;
    if(ss.size()>20)
    return -2;
    if(ss.find(se) != string::npos){
    
            return -(300+ss.find(se));
        
    }
    
     
     for(int i=0;i<ss.size();i++)
    {
        if((ss[i]==ss[i+1])&&(ss[i]==ss[i+2]))
        return -(400+i);
    }
    for(int i=0;i<ss.size();i++)
    {
        if((ss[i]==64)||(ss[i]==35)||(ss[i]==37)||(ss[i]==36)||(ss[i]==33))
        break;
        
         if(i==(ss.size()-1))
         return -5;
        
    }
    for(int i=0;i<ss.size();i++)
    { 
        if(((ss[i]>=97)&&(ss[i]<=122))||((ss[i]>=65)&&(ss[i]<=90))||((ss[i]>=48)&&(ss[i]<=57))||(ss[i]==64)||(ss[i]==35)||(ss[i]==37)||(ss[i]==36)||(ss[i]==33))
        continue;
        return i;
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int cnt[30]={0};
    int res=0;
    for(int i=0;i<num_pwds;i++)
    {
      for(int j=i;j<num_pwds;j++)
      {
       if(strcmp(arr_pwds[i],arr_pwds[j])==0)
       cnt[i]++;
      }
    }
    int max=cnt[0];
    for(int i=0;i<num_pwds;i++)
    {   
        
        if(cnt[i]>max)
        {
            max=cnt[i];
            res=i;
            
        }
        if(cnt[i]==max)
        {
            if(strlen(arr_pwds[i])>strlen(arr_pwds[res]))
            {
            max=cnt[i];
            res=i;
            }
        }
    }
	return res; 
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
