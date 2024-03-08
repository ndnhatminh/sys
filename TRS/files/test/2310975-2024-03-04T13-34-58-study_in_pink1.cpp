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

int CEIL(double x)
{
    int p=x+0.99999;
    return p;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(exp1<0) exp1=0;
    if(exp1>600) exp1=600;
    if(exp2<0) exp2=0;
    if(exp2>600) exp2=600;
    if(e1<0||e1>99) return -99;
    //----TH1-----
    if(e1>=0&&e1<4)
    {
        if(e1==0) exp2+=29;
        if(e1==1) exp2+=45;
        if(e1==2) exp2+=75;
        if(e1==3) exp2+=149;
        if(exp2>600) exp2=600;
        int d=3*e1+7*exp1;
        if(d%2)
        {
            double kq=1.0*exp1-1.0*d/100;
            exp1=CEIL(kq);
            if(exp1<0) exp1=0;
        }
        else
        {
            double kq=1.0*exp1+1.0*d/200;
            exp1=CEIL(kq);
            if(exp1>600) exp1=600;
        }
    }
    //-----TH2------
    if(e1>=4&&e1<=99)
    {
        if(e1>=4&&e1<=19)
        {
            double kq=1.0*e1/4+19;
            exp2+=CEIL(kq);
            if(exp2>600) exp2=600;
        }
        if(e1>=20&&e1<=49)
        {
            double kq=1.0*e1/9+21;
            exp2+=CEIL(kq);
            if(exp2>600) exp2=600;
        }
        if(e1>=50&&e1<=65)
        {
            double kq=1.0*e1/16+17;
            exp2+=CEIL(kq);
            if(exp2>600) exp2=600;
        }
        if(e1>=66&&e1<=79)
        {
            double kq=1.0*e1/4+19;
            exp2+=CEIL(kq);
            if(exp2>600) exp2=600;
            if(exp2>200)
            {
                double kq=1.0*e1/9+21;
                exp2+=CEIL(kq);
                if(exp2>600) exp2=600;
            }
        }
        if(e1>=80&&e1<=99)
        {
            double kq=1.0*e1/9+21;
            exp2+=CEIL(kq);
            kq=1.0*e1/4+19;
            exp2+=CEIL(kq);
            if(exp2>600) exp2=600;
            if(exp2>400)
            {
                kq=1.0*e1/16+17;
                exp2+=CEIL(kq);
                kq=1.0*exp2*1.15;
                exp2=CEIL(kq);
                if(exp2>600) exp2=600;
            }
        }
        exp1-=e1;
        if(exp1<0) exp1=0;
    }
    return exp1 + exp2;
}
double cal(int x)
{
    int s=sqrt(x);
    int a=x-s*s;
    int b=(s+1)*(s+1)-x;
    double p1;
    if(a<b) p1=1;
    else p1=(1.0*x/((s+1)*(s+1))+80.0)/123;
    return p1;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(E2<0||E2>99) return -99; 
    double p1,p2,p3;
    //-----road1-----
    p1=cal(EXP1);
    //-----road2----
    if(M1==0) p2=cal(EXP1);
    else
    {
        int c=(M1+1)/2;
        if(E2%2)
        {
            while(true)
            {
                if(M1<c) break;
                //_____ACTION1_____
                if(HP1>=200)
                {
                    M1-=70;
                    if(M1<0) M1=0;
                    double q=1.1*HP1;
                    HP1=CEIL(q);
                    if(HP1>666) HP1=666;
                }
                else
                {
                    M1-=150;
                    if(M1<0) M1=0;
                    double q=1.3*HP1;
                    HP1=CEIL(q);
                }
                if(M1<c) break;
                //_____ACTION2_____
                if(EXP1<400) M1-=200;
                else M1-=120;
                if(M1<0) M1=0;
                double q=1.13*EXP1;
                EXP1=CEIL(q);
                if(EXP1>600) EXP1=600;
                if(M1<c) break;
                //_____ACTION3_____
                if(EXP1<300) M1-=100;
                else M1-=120;
                q=0.9*EXP1;EXP1=CEIL(q);
                if(M1<0) M1=0;
            }
        }
        else
        {
            if(M1)
            {
                //_____ACTION1_____
                if(HP1>=200)
                {
                    M1-=70;
                    if(M1<0) M1=0;
                    double q=1.1*HP1;
                    HP1=CEIL(q);
                    if(HP1>666) HP1=666;
                }
                else
                {
                    M1-=150;
                    if(M1<0) M1=0;
                    double q=1.3*HP1;
                    HP1=CEIL(q);
                }
                //_____ACTION2_____
                if(M1)
                {
                    if(EXP1<400) M1-=200;
                    else M1-=120;
                    if(M1<0) M1=0;
                    double q=1.13*EXP1;
                    EXP1=CEIL(q);
                    if(EXP1>600) EXP1=600;
                    //_____ACTION3_____
                    if(M1)
                    {
                        if(EXP1<300) M1-=100;
                        else M1-=120;
                        q=0.9*EXP1;EXP1=CEIL(q);
                        if(M1<0) M1=0;
                    }
                }
            }
        }
        double q=0.83*HP1;
        HP1=CEIL(q);
        q=1.17*EXP1;
        EXP1=CEIL(q);
        if(EXP1>600) EXP1=600;
        p2=cal(EXP1);
    }
    //______ROAD3________
    int arr[15]={32,47,28,79,100,50,22,83,64,11};
    if(E2<10) p3=1.0*arr[E2]/100;
    else
    {
        E2=E2%10+E2/10;
        p3=1.0*arr[E2%10]/100;
    }
    //cout<<p1<<" "<<p2<<" "<<p3<<"\n";
    double p=(p1+p2+p3)/3;
    if(p==1.0)
    {
        double q=0.75*EXP1;
        EXP1=CEIL(q);
    }
    else
    {
        if(p<0.5)
        {
            double q=0.85*HP1;
            HP1=CEIL(q);
            q=1.15*EXP1;
            EXP1=CEIL(q);
            if(EXP1>600) EXP1=600;
        }
        else
        {
            double q=0.9*HP1;
            HP1=CEIL(q);
            q=1.2*EXP1;
            EXP1=CEIL(q);
            if(EXP1>600) EXP1=600;
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int _max(int x,int y)
{
    if(x>y) return x;
    else return y;
}
int a[15][15];
int _f(int x,int y,int c,int b)
{
    int cnt=a[x][y];
    while(x>=0&&x<10&&y>=0&&y<10) cnt=_max(cnt,a[x][y]),x+=c,y+=b;
    return cnt;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(HP2<0) HP2=0;
    if(HP2>666) HP2=666;
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(EXP2<0) EXP2=0;
    if(EXP2>600) EXP2=600;
    if(E3<0||E3>99) return -99; 
    int x=0,y=0;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++)
    {
        a[i][j]=(E3*j+i*2)*(i-j);
        if(a[i][j]>E3*2) x++;
        if(a[i][j]<-E3) y++;
    }
    while(x>9) x=x/10+x%10;
    while(y>9) y=y/10+y%10;
    int cnt=a[x][y];
    cnt=_max(cnt,_f(x,y,-1,-1));
    cnt=_max(cnt,_f(x,y,1,-1));
    cnt=_max(cnt,_f(x,y,-1,1));
    cnt=_max(cnt,_f(x,y,1,1));
    if(abs(cnt)>=abs(a[x][y]))
    {
        double q=1.0*EXP1*1.12;EXP1=CEIL(q);if(EXP1>600) EXP1=600;
        q=1.0*EXP2*1.12;EXP2=CEIL(q);if(EXP2>600) EXP2=600;
        q=1.0*HP1*1.1;HP1=CEIL(q);if(HP1>666) HP1=666;
        q=1.0*HP2*1.1;HP2=CEIL(q);if(HP2>666) HP2=666;
        //cout<<EXP1<<" "<<EXP2<<" "<<HP1<<" "<<HP2<<"\n";
        return cnt;
    }
    else
    {
        double q=1.0*EXP1*0.88;EXP1=CEIL(q);if(EXP1>600) EXP1=600;
        q=1.0*EXP2*0.88;EXP2=CEIL(q);if(EXP2>600) EXP2=600;
        q=1.0*HP1*0.9;HP1=CEIL(q);if(HP1>666) HP1=666;
        q=1.0*HP2*0.9;HP2=CEIL(q);if(HP2>666) HP2=666;
        //cout<<EXP1<<" "<<EXP2<<" "<<HP1<<" "<<HP2<<"\n";
        return a[x][y];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string a=string(s,strlen(s));
    string b=string(email,strlen(email));
    if(a.size()<8) return -1;
    if(a.size()>20) return -2;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]=='@')
        {
            if(i==0) b="";
            else
            b.erase(i,b.size()-1);
        }
    }
    int c=a.size()-b.size();
    for(int i=0;i<=c;i++)
    {
        int j=0;
        while(j<b.size()&&a[i+j]==b[j]&&j<b.size()) j++;
        if(j==b.size()) return -(300+i);
    }
    for(int i=0;i<a.size()-2;i++)
    {
        if(a[i]==a[i+1]&&a[i]==a[i+2]) return -(400+i);
    }
    bool ktdb=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='@'||a[i]=='#'||a[i]=='%'||a[i]=='$'||a[i]=='!') ktdb=1;
    }
    if(ktdb==0) return -5;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9') continue;
        if(a[i]>='a'&&a[i]<='z') continue;
        if(a[i]>='A'&&a[i]<='Z') continue;
       if(a[i]=='@'||a[i]=='#'||a[i]=='%'||a[i]=='$'||a[i]=='!') continue;
       return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int n=num_pwds;
    int cnt=0;
    string l[1000];
    int p[1000];
    for(int i=0;i<=900;i++) l[i]="",p[i]=0;
    for(int i=0;i<n;i++)
    {
        int kt=0;
        for(int j=1;j<=cnt;j++)
        {
            if(arr_pwds[i]==l[j])
            {
                p[j]++;kt=1;break;
            }
        }
        if(kt==0)
        {
            cnt++;l[cnt]=string(arr_pwds[i],strlen(arr_pwds[i]));p[cnt]++;
        }
    }
    int mx=0;
    for(int i=1;i<=cnt;i++) mx=max(mx,p[i]);
    int mxsiz=0;
    for(int i=1;i<=cnt;i++)
    {
        if(p[i]!=mx) continue;
        int k=l[i].size();
        mxsiz=max(mxsiz,k); 
    }
    //cout<<mx<<" "<<mxsiz<<"\n";
    for(int i=0;i<n;i++)
    {
        if(strlen(arr_pwds[i])!=mxsiz) continue;
        int vt=0;
        for(int j=1;j<=cnt;j++) if(arr_pwds[i]==l[j]) vt=j;
        if(p[vt]==mx) return i;
    }
    return -1;
}

/*
g++ -o main main.cpp study_in_pink1.cpp -I . -std=c++11
./main sa_tc_01_input
*/
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////