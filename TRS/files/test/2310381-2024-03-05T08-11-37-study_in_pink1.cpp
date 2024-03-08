#include "study_in_pink1.h"

bool readFile
(
        const string & filename,
        int & HP1, int & HP2,
        int & EXP1, int & EXP2,
        int & M1, int & M2,
        int & E1, int & E2, int & E3
)
{
    ifstream ifs(filename);
    if (ifs.is_open()) 
    {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else 
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}
void checkExp(int &exp)
{
    if (exp<0) exp=0;
    if (exp>600) exp=600;
}
void checkHp(int &hp)
{
    if (hp<0) hp=0;
    if (hp>666) hp=666;
}
void checkM(int &m)
{
    if (m<0) m=0;
    if (m>3000) m=3000;
}
int firstMeet(int & EXP1, int & EXP2, int E1)
{
    if (E1<0||E1>99) return -99;
    else if (E1<=3)
    {
        switch(E1)
    {
        case 0: 
        {
            EXP2+=29;
            checkExp(EXP2);
            break;
        }
        case 1: 
        {
            EXP2+=45;
            checkExp(EXP2);
            break;
        }
        case 2: 
        {
            EXP2+=75;
            checkExp(EXP2);
            break;
        }
        case 3:
        {
            EXP2+=29+45+75;
            checkExp(EXP2);
            break;
        }
    }
    int d=E1*3+EXP1*7;
    if (d%2==0)
    {
        EXP1+=d/200;
        EXP1=ceil(EXP1);
        checkExp(EXP1);
    }
    else
    {
        EXP1-=d/100;
        EXP1=ceil(EXP1);
        checkExp(EXP1);
    }
    }
    else
    {
        EXP1-=E1; checkExp(EXP1);
        if (E1<=19)
        {
            EXP2=ceil(EXP2+1.0*E1/4+19);
            checkExp(EXP2);
        }
        else if (E1<=49)
        {
            EXP2=ceil(EXP2+1.0*E1/9+21);
            checkExp(EXP2);
        }
        else if (E1<=65)
        {
            EXP2=ceil(EXP2+1.0*E1/16+17);
            checkExp(EXP2);
        }
        else if (E1<=79)
        {
            EXP2=ceil(EXP2+1.0*E1/4+19); checkExp(EXP2);
            if (EXP2>200)
            {
                EXP2=ceil(EXP2+1.0*E1/9+21); checkExp(EXP2);
            }
        }
        else
        {
            EXP2=ceil(EXP2+1.0*E1/4+19); checkExp(EXP2);
            EXP2=ceil(EXP2+1.0*E1/9+21); checkExp(EXP2);
            if (EXP2>400)
            {
                EXP2=ceil(EXP2+1.0*E1/16+17); checkExp(EXP2);
                EXP2=ceil(1.15*EXP2); checkExp(EXP2);
            }
        }
    }
    return EXP1+EXP2;
}

double closestSquared(int exp)
{
    int sq1=pow(floor(sqrt(exp)),2);
    int sq2=pow(ceil(sqrt(exp)),2);
    if (abs(sq1-exp)<=abs(sq2-exp)||exp==sq1) return 1;
    else return 1.0*(1.0*exp/sq2+80)/123;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    double p1,p2,p3,p;

    p1=closestSquared(EXP1);
    
    if (E2%2==1)
    {
        int lim=M1/2, totalM=0;
        while (true)
        {
            if (HP1<200)
            {
                HP1=ceil(HP1*1.3); checkHp(HP1);
                totalM+=150; 
                if (totalM>lim)
                {
                    HP1=ceil(HP1*0.83); checkHp(HP1);
                    EXP1=ceil(EXP1*1.17); checkExp(EXP1);
                    break;
                }
            }
            else
            {
                HP1=ceil(HP1*1.1); checkHp(HP1);
                totalM+=70;
                if (totalM>lim)
                {
                    HP1=ceil(HP1*0.83); checkHp(HP1);
                    EXP1=ceil(EXP1*1.17); checkExp(EXP1);
                    break;
                }
            }
            if (EXP1<400)
            {
                totalM+=200;
                EXP1=ceil(EXP1*1.13); checkExp(EXP1);
                if (totalM>lim)
                {
                    HP1=ceil(HP1*0.83); checkHp(HP1);
                    EXP1=ceil(EXP1*1.17); checkExp(EXP1);
                    break;
                }
            }
            else
            {
                totalM+=120;
                EXP1=ceil(EXP1*1.13); checkExp(EXP1);
                if (totalM>lim)
                {
                    HP1=ceil(HP1*0.83); checkHp(HP1);
                    EXP1=ceil(EXP1*1.17); checkExp(EXP1);
                    break;
                }
            }
            if (EXP1<300)
            {
                totalM+=100;
                if (totalM>lim)
                {
                    HP1=ceil(HP1*0.83); checkHp(HP1);
                    EXP1=ceil(EXP1*1.17); checkExp(EXP1);
                    break;
                }
            }
            else
            {
                totalM+=120;
                if (totalM>lim)
                {
                    HP1=ceil(HP1*0.83); checkHp(HP1);
                    EXP1=ceil(EXP1*1.17); checkExp(EXP1);
                    break;
                }
            }
            EXP1=ceil(EXP1*0.9); checkExp(EXP1);
        }
        M1-=totalM;
    }
    else
    {
        int lim=M1, totalM=0;
        bool check=false;
        if (HP1<200)
        {
            HP1=ceil(HP1*1.3); checkHp(HP1);
            totalM+=150; 
            if (totalM>lim) check=true;
        }
        else
        {
            HP1=ceil(HP1*1.1); checkHp(HP1);
            totalM+=70;
            if (totalM>lim) check=true;
        }
        if (EXP1<400&&!check)
        {
            EXP1=ceil(EXP1*1.13); checkExp(EXP1);
            totalM+=200;
            if (totalM>lim) check=true;
        }
        else if(!check)
        {
            EXP1=ceil(EXP1*1.13); checkExp(EXP1);
            totalM+=120;
            if (totalM>lim) check=true;
        }
        if (EXP1<300&&!check)
        {
            EXP1=ceil(EXP1*0.9); checkExp(EXP1);
            totalM+=100;
        }
        else if(!check)
        {
            EXP1=ceil(EXP1*0.9); checkExp(EXP1);
            totalM+=120;
        }
        HP1=ceil(HP1*0.83); checkHp(HP1);
        EXP1=ceil(EXP1*1.17); checkExp(EXP1);
        M1-=totalM; checkM(M1);
    }
    p2=closestSquared(EXP1);

    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) p3=P[E2]/100;
    else
    {
        E2=E2/10+E2%10;
        p3=1.0*P[E2%10]/100;
    }

    p=1.0*(p1+p2+p3)/3;
    if (p1==1&&p2==1&&p3==1)
    {
        EXP1=ceil(EXP1*0.75);
        checkExp(EXP1);
    }
    else if (p<0.5)
    {
        HP1=ceil(HP1*0.85); checkHp(HP1);
        EXP1=ceil(EXP1*1.15); checkExp(EXP1);
    }
    else
    {
        HP1=ceil(HP1*0.9); checkHp(HP1);
        EXP1=ceil(EXP1*1.2); checkExp(EXP1);
    }

    return HP1+EXP1+M1;
}

int meetSpot(int n)
{
    while (n>9)
    {
        int sum=0;
        while (n!=0)
        {
        sum+=n%10;
        n/=10;
        }
        n=sum;
    }
    return n;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    int map[10][10], pos=0, neg=0;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            {
                map[i][j]=(E3*j+i*2)*(i-j);
                if (map[i][j]>E3*2) pos++;
                if (map[i][j]<-E3) neg++;
            }
    int x=meetSpot(pos), y=meetSpot(neg);
    int taxi=map[x][y];
    int max=map[x][y];
    {
        int a=meetSpot(pos), b=meetSpot(neg);
        while (a>0&&b>0)
        {
            if (map[--a][--b]>max) max=map[a][b];
            a--; b--;
        }
    }
    {
        int a=meetSpot(pos), b=meetSpot(neg);
        while (a<9&&b<9)
        {
            if (map[++a][++b]>max) max=map[a][b];
            a++; b++;
        }
    }
    {
            int a=meetSpot(pos), b=meetSpot(neg);
            while (a<9&&b>0)
            {
                if (map[++a][--b]>max) max=map[a][b];
                a++; b--;
            }
    }
    {
        int a=meetSpot(pos), b=meetSpot(neg);
        while (a>0&&b<9)
        {
            if (map[--a][++b]>max) max=map[a][b];
            a--; b++;
        }
    }
    if (abs(taxi)>max)
    {
        EXP1=ceil(EXP1*0.88); EXP2=ceil(EXP2*0.88);
        checkExp(EXP1); checkExp(EXP2);
        HP1=ceil(HP1*0.9); HP2=ceil(HP2*0.9);
        checkHp(HP1); checkHp(HP2);
        return taxi;
    }
    else
    {
        EXP1=ceil(EXP1*1.12); EXP2=ceil(EXP2*1.12);
        checkExp(EXP1); checkExp(EXP2);
        HP1=ceil(HP1*1.1); HP2=ceil(HP2*1.1);
        checkHp(HP1); checkHp(HP2);
        return max;
    }

    return -1;
}

int checkPassword(const char * s, const char * email) 
{
    string se="";
    for (int i=0; email[i]!='@'; i++)
        se+=email[i];

    string S=s;
    if (S.length()<8) return -1;
    if (S.length()>20) return -2;

    if (S.length()>=se.length())
    {
        bool containSe=false;
    for (int i=0; i<S.length()-se.length(); i++)
        {
            if (s[i]==se[0])
                for (int k=1; k<se.length(); k++)
                    {
                        if (!(s[i+k]==se[k])) break;
                        else if (k==se.length()-1) containSe=true;
                    }
            if (containSe) return -(300+i);
        }
    }
    
    for (int i=0; i<S.length()-2;i++)
        if (S[i]==S[i+1])
            if (S[i]==S[i+2])
                return -(400+i);

    bool containSC=false;
    for (int i=0; i<S.length(); i++) 
        if (S[i]=='@'||S[i]=='#'||S[i]=='%'||S[i]=='$'||S[i]=='!')
        {
            containSC=true;
            break;
        }
    if (!containSC) return -5;

    for (int i=0; i<S.length(); i++)
        if (S[i]<'a'||S[i]>'z')
            if(S[i]<'A'||S[i]>'Z')
                if(S[i]<'0'||S[i]>'9')
                    if(S[i]!='@'&&S[i]!='#'&&S[i]!='%'&&S[i]!='$'&&S[i]!='!')
                        return i;

    return -10;

    return -99;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    string sepPW[30]; int count[30];
    sepPW[0]=arr_pwds[0]; count[0]=1; 
    for (int i=1; i<30; i++)
    {
        sepPW[i]="";
        count[i]=0;
    }
    int k=0;
    for (int i=1; i<num_pwds; i++)
    {
        bool identical=false;
        for (int a=k; a>=0; a--)
            if (arr_pwds[i]==sepPW[a])
            {
                ++count[a];
                identical=true;
                break;
            }
        if (!identical)
        {
            sepPW[++k]=arr_pwds[i];
            count[k]=1;
        }
    }
    int mark=0;
    for (int i=1; i<30; i++)
        if (count[i]>count[mark]) mark=i;
        else if (count[i]==count[mark])
            if (sepPW[i].length()>sepPW[mark].length())
                mark=i;
    int result;
    for (int i=0; i<num_pwds; i++)
        if (arr_pwds[i]==sepPW[mark])
            {
                result=i;
                break;
            } 
    return result;
    return -1;
}