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

//Created functions
int round(int & a,float & b)
{
    float c=(float)a*b;
    if(abs(c-(int)c)<0.009) return c;
    else return c+1;
}

int exp(int & a)
{
    if(a>600) return 600;
    else if(a<0) return 0;
    else return a;
}

int hp(int & a)
{
    if(a>666) return 666;
    else if(a<0) return 0;
    else return a;
}

int m(int & a)
{
    if(a>3000) return 3000;
    else if(a<0) return 0;
    else return a;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0||e1>99) return -99;
    exp1=exp(exp1);
    exp2=exp(exp2);
    int D=0;
    if(e1>=0&&e1<=3)
    {
        if(e1==0)
        {
            exp2+=29;
            exp2=exp(exp2);
            D=e1*3+exp1*7;
            if(D%2==0)
            {
                float C=(float)D/200;
                if(C==(int)C) exp1+=(int)C;
                else exp1=exp1+(int)C+1;
                exp1=exp(exp1);
            }
            else
            {
                float C=(float)D/100;
                exp1-=(int)C;
                exp1=exp(exp1);
            }
        }
        else if(e1==1)
        {
            exp2+=45;
            exp2=exp(exp2);
            D=e1*3+exp1*7;
            if(D%2==0)
            {
                float C=(float)D/200;
                if(C==(int)C) exp1+=(int)C;
                else exp1=exp1+(int)C+1;
                exp1=exp(exp1);
            }
            else
            {
                float C=(float)D/100;
                exp1-=(int)C;
                exp1=exp(exp1);
            }
        }
        else if(e1==2)
        {
            exp2+=75;
            exp2=exp(exp2);
            D=e1*3+exp1*7;
            if(D%2==0)
            {
                float C=(float)D/200;
                if(C==(int)C) exp1+=(int)C;
                else exp1=exp1+(int)C+1;
                exp1=exp(exp1);
            }
            else
            {
                float C=(float)D/100;
                exp1-=(int)C;
                exp1=exp(exp1);
            }        }
        else if(e1==3)
        {
            exp2+=149;
            exp2=exp(exp2);
            D=e1*3+exp1*7;
            if(D%2==0)
            {
                float C=(float)D/200;
                if(C==(int)C) exp1+=(int)C;
                else exp1=exp1+(int)C+1;
                exp1=exp(exp1);
            }
            else
            {
                float C=(float)D/100;
                exp1-=(int)C;
                exp1=exp(exp1);
            }
        }
    }
    else if(e1>=4&&e1<=99)
    {
        if(e1>=4&&e1<=19)
        {
            if(e1%4==0)
            {
                exp2+=e1/4+19;
                exp2=exp(exp2);
            }
            else
            {
                exp2+=e1/4+20;
                exp2=exp(exp2);
            }
        }
        else if(e1>=20&&e1<=49)
        {
            if(e1%9==0)
            {
                exp2+=e1/9+21;
                exp2=exp(exp2);
            }
            else
            {
                exp2+=e1/9+22;
                exp2=exp(exp2);
            }
        }
        else if(e1>=50&&e1<=65)
        {
            if(e1%16==0)
            {
                exp2+=e1/16+17;
                exp2=exp(exp2);
            }
            else
            {
                exp2+=e1/16+18;
                exp2=exp(exp2);
            }

        }
        else if(e1>=66&&e1<=79)
        {
            if(e1%4==0)
            {
                exp2+=e1/4+19;
                exp2=exp(exp2);
                if(exp2>200)
                {
                    if(e1%9==0)
                    {
                        exp2+=e1/9+21;
                        exp2=exp(exp2);
                    }
                    else
                    {
                        exp2+=e1/9+22;
                        exp2=exp(exp2);
                    }
                }
            }
            else
            {
                exp2+=e1/4+20;
                exp2=exp(exp2);
                if(exp2>200)
                {
                    if(e1%9==0)
                    {
                        exp2+=e1/9+21;
                        exp2=exp(exp2);
                    }
                    else
                    {
                        exp2+=e1/9+22;
                        exp2=exp(exp2);
                    }
                }
            }
        }
        else if(e1>=80&&e1<=99)
        {
            if(e1%4==0)
            {
                exp2+=e1/4+19;
                exp2=exp(exp2);
            }
            else
            {
                exp2+=e1/4+20;
                exp2=exp(exp2);
            }
            if(e1%9==0)
            {
                exp2+=e1/9+21;
                exp2=exp(exp2);
            }
            else
            {
                exp2+=e1/9+22;
                exp2=exp(exp2);
            }
            if(exp2>400)
            {
                if(e1%16==0)
                {
                    exp2+=e1/16+17;
                    exp2=exp(exp2);
                }
                else
                {
                    exp2+=e1/16+18;
                    exp2=exp(exp2);
                }
                float temp=1.15;
                exp2=round(exp2,temp);
                exp2=exp(exp2);
            }
        }
        exp1-=e1;
        exp1=exp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99) return -99;
    HP1=hp(HP1);
    EXP1=exp(EXP1);
    M1=m(M1);
    float temp=0;
    float P1=1,P2=1,P3=1;
    // Road 1
    float a=sqrt(EXP1);
    if(a==(int)a) P1=1;
    else
    {
      int b=a;
      int c=a+1;
      if(abs(c*c-EXP1)>abs(b*b-EXP1)) P1=1;
      else
      {
          float S=b*b;
          P1=((float)EXP1/S+80)/123;
      }
    }
    // Road 2
    float M=(float)M1*0.5;
    if(E2%2==0)
    {
        if(HP1<200&&M1>0)
        {
            M1-=150;
            M1=m(M1);
            temp=1.3;
            HP1=round(HP1,temp);
            HP1=hp(HP1);
        }
        else if(HP1>=200&&M1>0)
        {
            M1-=70;
            M1=m(M1);
            temp=1.1;
            HP1=round(HP1,temp);
            HP1=hp(HP1);
        }
        if(EXP1<400&&M1>0)
        {
            M1-=200;
            M1=m(M1);
            temp=1.13;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        else if(EXP1>=400&&M1>0)
        {
            M1-=120;
            M1=m(M1);
            temp=1.13;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        if(EXP1<300&&M1>0)
        {
            M1-=100;
            M1=m(M1);
            temp=0.9;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        else if(EXP1>=300&&M1>0)
        {
            M1-=120;
            M1=m(M1);
            temp=0.9;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        temp=0.83;
        HP1=round(HP1,temp);
        HP1=hp(HP1);
        temp=1.17;
        EXP1=round(EXP1,temp);
        EXP1=exp(EXP1);
        float a=sqrt(EXP1);
        if(a==(int)a) P2=1;
        else
        {
            int b=a;
            int c=a+1;
            if(abs(b*b-EXP1)<abs(c*c-EXP1)) P2=1;
            else
            {
            float S=b*b;
            P2=((float)EXP1/S+80)/123;
            }
        }
    }
    else
    {
        if(M1==0)
        {
            temp=0.83;
            HP1=round(HP1,temp);
            HP1=hp(HP1);
            temp=1.17;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        else
        {
            float spend=0;
            while(spend<=M)
            {
                if(HP1<200&&spend<=M)
                {
                    spend+=150;
                    temp=1.3;
                    HP1=round(HP1,temp);
                    HP1=hp(HP1);
                }
                else if(HP1>=200&&spend<=M)
                {
                    spend+=70;
                    temp=1.1;
                    HP1=round(HP1,temp);
                    HP1=hp(HP1);
                }
                if(EXP1<400&&spend<=M)
                {
                    spend+=200;
                    temp=1.13;
                    EXP1=round(EXP1,temp);
                    EXP1=exp(EXP1);
                }
                else if(EXP1>=400&&spend<=M)
                {
                    spend+=120;
                    temp=1.13;
                    EXP1=round(EXP1,temp);
                    EXP1=exp(EXP1);
                }
                if(EXP1<300&&spend<=M)
                {
                    spend+=100;
                    temp=0.9;
                    EXP1=round(EXP1,temp);
                    EXP1=exp(EXP1);
                }
                else if(EXP1>=300&&spend<=M)
                {
                    spend+=120;
                    temp=0.9;
                    EXP1=round(EXP1,temp);
                    EXP1=exp(EXP1);
                }
            }
            M1-=spend;
            M1=m(M1);
            temp=0.83;
            HP1=round(HP1,temp);
            HP1=hp(HP1);
            temp=1.17;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        float a=sqrt(EXP1);
        if(a==(int)a) P2=1;
        else
        {
            int b=a;
            int c=a+1;
            if(abs(b*b-EXP1)<abs(c*c-EXP1)) P2=1;
            else
            {
            float S=b*b;
            P2=((float)EXP1/S+80)/123;
            }
        }
    }
    // Road 3
    float P[10]={32,47,28,79,100,50,22,83,64,11};
    if(E2>=0&&E2<=9) P3=P[E2]/100;
    else if(E2>=10&&E2<=99)
    {
        int i=0;
        while(E2>0)
        {
            i+=E2%10;
            E2=E2/10;
        }
        if(i>9)
        {
            int j=0;
            j=i%10;
            P3=P[j]/100;
        }
        else
        {
            P3=P[i]/100;
        }
    }
    if(P1==1&&P2==1&&P3==1)
    {
        temp=0.75;
        EXP1=round(EXP1,temp);
        EXP1=exp(EXP1);
    }
    else
    {
        if((P1+P2+P3)/3<0.5)
        {
            temp=0.85;
            HP1=round(HP1,temp);
            HP1=hp(HP1);
            temp=1.15;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
        else
        {
            temp=0.9;
            HP1=round(HP1,temp);
            HP1=hp(HP1);
            temp=1.2;
            EXP1=round(EXP1,temp);
            EXP1=exp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) return -99;
    HP1=hp(HP1);
    HP2=hp(HP2);
    EXP1=exp(EXP1);
    EXP2=exp(EXP2);
    float temp=0;
    int arr[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            arr[i][j]=(E3*j+i*2)*(i-j);
        }
    }
    int c=0;
    int d=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]>E3*2) c++;
            if(arr[i][j]<0-E3) d++;
        }
    }
    int i=0,j=0;
    if(c>=0&&c<=9) i=c;
    else
    {
       while(c>0)
       {
           i+=c%10;
           c=c/10;
       }
       if(i>9)
       {
           int e=0;
           while(i>0)
           {
               e+=i%10;
               i=i/10;
           }
           i=e;
       }

    }
    if(d>=0&&d<=9) j=d;
    else
    {
       while(d>0)
       {
           j+=d%10;
           d=d/10;
           if(j>9)
           {
               int e=0;
               while(j>0)
               {
                   e+=j%10;
                   j=j/10;
               }
               j=e;
           }
       }
    }
    int brr[10][10];
    for(int k=0;k<10;k++)
    {
        for(int h=0;h<10;h++)
        {
            if(k+h==i+j) brr[k][h]=arr[k][h];
            else if(i>=j&&k-h==i-j) brr[k][h]=arr[k][h];
            else if(i<j&&h-k==j-i) brr[k][h]=arr[k][h];
            else brr[k][h]=0;
        }
    }
    int Max=brr[0][0];
    for(int m=0;m<10;m++)
    {
        for(int n=0;n<10;n++)
        {
            if(brr[m][n]>Max) Max=brr[m][n];
        }
    }
    if(abs(arr[i][j])>Max)
    {
        temp=0.88;
        EXP1=round(EXP1,temp);
        EXP1=exp(EXP1);
        temp=0.9;
        HP1=round(HP1,temp);
        HP1=hp(HP1);
        temp=0.88;
        EXP2=round(EXP2,temp);
        EXP2=exp(EXP2);
        temp=0.9;
        HP2=round(HP2,temp);
        HP2=hp(HP2);
        return arr[i][j];
    }
    else
    {
        temp=1.12;
        EXP1=round(EXP1,temp);
        EXP1=exp(EXP1);
        temp=1.1;
        HP1=round(HP1,temp);
        HP1=hp(HP1);
        temp=1.12;
        EXP2=round(EXP2,temp);
        EXP2=exp(EXP2);
        temp=1.1;
        HP2=round(HP2,temp);
        HP2=hp(HP2);
        return Max;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    bool check1=true,check2=true,check3=true,check4=true;
    string se="";
    int n=strlen(email);
    int m=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(email[i]!=64) se+=(char)email[i];
        else break;
    }
    int k=se.length();
    //DK0
    if(m<8) return -1;
    if(m>20) return -2;
    //DK1
    if(k>m) check1=false;
    int Count1=0;
    for(int i=0;i<=m-k;i++)
    {
        string temp="";
        for(int j=0;j<k;j++)
        {
            temp+=(char)s[i+j];
        }
        if(temp==se)
        {
            Count1++;
            return 0-(300+i);
            break;
        }
    }
    if(Count1==0) check1=false;
    //DK2
    int Count2=0;
    for(int i=0;i<m-2;i++)
    {
        if(s[i]==s[i+1]&&s[i+1]==s[i+2])
        {
            Count2++;
            return 0-(400+i);
            break;
        }
    }
    if(Count2==0) check2=false;
    //DK3
    int Count3=0;
    for(int i=0;i<m;i++)
    {
        if(s[i]==64||s[i]==33||s[i]==35||s[i]==36||s[i]==37)
        {
            Count3++;
        }
    }
    if(Count3==0)
    {
        return -5;
    }
    else check3=false;
    //DK4
    int Count4=0;
    for(int i=0;i<m;i++)
    {
        if(!(s[i]==64||s[i]==33||s[i]==35||s[i]==36||s[i]==37||
           (s[i]>=48&&s[i]<=57)||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)))
        {
            Count4++;
            return i;
            break;
        }
    }
    if(Count4==0) check4=false;
    if(check1==false&&check2==false&&check3==false&&check4==false) return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount=0;
    int maxLength=0;
    int Index=0;
    for(int i=0;i<num_pwds;i++)
    {
        int Count=1;
        for(int j=0;j<num_pwds;j++)
        {
            if(strcmp(arr_pwds[i],arr_pwds[j])==0) Count++;
        }
        if((Count==maxCount&&strlen(arr_pwds[i])>maxLength)||Count>maxCount)
        {
            maxCount=Count;
            maxLength=strlen(arr_pwds[i]);
            Index=i;
        }
    }
    return Index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
