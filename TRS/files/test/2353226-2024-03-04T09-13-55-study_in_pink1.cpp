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

void check_HP (int &HP)
{
    if(HP<0) HP=0;
    if(HP>666) HP=666;
}

void check_EXP (int &EXP)
{
    if(EXP<0) EXP=0;
    if(EXP>600) EXP=600;
}

void check_M (int &M)
{
    if(M<0) M=0;
    if(M>3000) M=3000;
}

void update_EXP(int &EXP,double &exp)
{
    exp=ceil(exp);
    EXP=int(exp);
    check_EXP(EXP);
    exp=EXP;
}

void update_HP(int &HP,double &hp)
{
    hp=ceil(hp);
    HP=int(hp);
    check_HP(HP);
    hp=HP;
}

void update_M(int &M,int &m)
{
    m=ceil(m);
    M=int(m);
    check_M(M);
    m=M;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0||e1>99) return -99;
    check_EXP(exp1); check_EXP(exp2);
    double exp1t=exp1,exp2t=exp2;
    if(e1<4)
    {
        if(e1==0) exp2t+=29;
        else if(e1==1) exp2t+=45;
        else if(e1==2) exp2t+=75;
        else exp2t+=29+45+75;
        int D=e1*3+exp1t*7;
        if(D%2==0) exp1t+=D*1.0/200;
        else exp1t-=D*1.0/100;
        update_EXP(exp1,exp1t);
        update_EXP(exp2,exp2t);
    }
    else
    {
        if((4<=e1&&e1<=19)||(66<=e1&&e1<=79)||(80<=e1&&e1<=99)) exp2t+=e1*1.0/4+19;
        update_EXP(exp2,exp2t);
        if((20<=e1&&e1<=49)||(80<=e1&&e1<=99)) exp2t+=e1*1.0/9+21;
        update_EXP(exp2,exp2t);
        if(50<=e1&&e1<=65) exp2t+=e1*1.0/16+17;
        update_EXP(exp2,exp2t);
        if(66<=e1&&e1<=79) if(exp2t>200) exp2t+=e1*1.0/9+21;
        update_EXP(exp2,exp2t);
        if(80<=e1&&e1<=99) if(exp2t>400)
        {
            exp2t+=e1*1.0/16+17;
            update_EXP(exp2,exp2t);
            exp2t=exp2t*115/100;
            update_EXP(exp2,exp2t);
        }
        exp1-=e1;
        check_EXP(exp1);
        // cout << exp1 << " " << exp2 << " ";
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99) return -99;
    check_HP(HP1);check_EXP(EXP1);check_M(M1);
    double p1,p2,p3,p;
    double hp1t=HP1,exp1t=EXP1;
    int m1t=M1,m1i=M1;
    int S;
    S=round(sqrt(EXP1));
    if(EXP1>=S*S) p1=1;
    else p1=(EXP1*1.0/(S*S)+80)/123;

    do
    {
        if((E2%2==0)&&(m1t==0)) break;
        if((E2%2==1)&&(((m1t<m1i*0.5)&&(m1i>0))||((m1i==0)&&(m1t<=m1i)))) break;
        if(HP1<200)
        {
            hp1t=hp1t*13/10;
            m1t-=150;
        }
        else
        {
            hp1t=hp1t*11.0/10;
            m1t-=70;
        }
        update_HP(HP1,hp1t);
        update_M(M1,m1t);
        if((E2%2==0)&&(m1t==0)) break;
        if((E2%2==1)&&(((m1t<m1i*0.5)&&(m1i>0))||((m1i==0)&&(m1t<=m1i)))) break;
        if(EXP1<400) m1t-=200;
        else m1t-=120;
        update_M(M1,m1t);
        exp1t=exp1t*113/100;
        update_EXP(EXP1,exp1t);
        if((E2%2==0)&&(m1t==0)) break;
        if((E2%2==1)&&(((m1t<m1i*0.5)&&(m1i>0))||((m1i==0)&&(m1t<=m1i)))) break;
        if(EXP1<300) m1t-=100;
        else m1t-=120;
        exp1t=exp1t*9/10;
        update_M(M1,m1t);
        update_EXP(EXP1,exp1t);
        if((E2%2==0)&&(m1t==0)) break;
        if((E2%2==1)&&(((m1t<m1i*0.5)&&(m1i>0))||((m1i==0)&&(m1t<=m1i)))) break;
    } while(E2%2==1);
    hp1t=hp1t*83.0/100;
    exp1t=exp1t*117/100;
    update_HP(HP1,hp1t);
    update_EXP(EXP1,exp1t);
    S=round(sqrt(EXP1));
    if(EXP1>=S*S) p2=1.0;
    else p2=(EXP1*1.0/(S*S)+80)/123;

    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<10) p3=P[E2];
    else p3=P[(E2/10+E2%10)%10];
    p3=p3/100;

    p=(p1+p2+p3)*1.0/3;
    if(p==1) exp1t=exp1t*75/100;
    else if(p<(5.0/10)) {hp1t=hp1t*85/100;exp1t=exp1t*115/100;}
    else {hp1t=hp1t*9.0/10;exp1t=exp1t*12/10;}
    update_EXP(EXP1,exp1t);
    update_HP(HP1,hp1t);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) return -99;
    check_EXP(EXP1);check_HP(HP1);check_HP(HP2);check_EXP(EXP2);
    double hp1t=HP1,exp1t=EXP1,hp2t=HP2,exp2t=EXP2;
    int taxi[12][12],SnW[12][12],cnti=0,cntj=0;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) taxi[i][j]=((E3*j)+(i*2))*(i-j);
    for(int i=0;i<10;i++) for(int j=0;j<10;j++)
    {
        int maxVal=taxi[i][j];
        for(int k=0;k<10;k++)
        {
            if((i-k>=0)&&(j-k)>=0) maxVal=max(maxVal,taxi[i-k][j-k]);
            if((i-k>=0)&&(j+k)<10) maxVal=max(maxVal,taxi[i-k][j+k]);
            if((i+k<10)&&(j-k)>=0) maxVal=max(maxVal,taxi[i+k][j-k]);
            if((i+k<10)&&(j+k)<10) maxVal=max(maxVal,taxi[i+k][j+k]);
        }
        SnW[i][j]=abs(maxVal);
        if(taxi[i][j]>E3*2) cnti++;
        if(taxi[i][j]<-1*E3) cntj++;
    }
    while(cnti>9) cnti=cnti/10+cnti%10;
    while(cntj>9) cntj=cntj/10+cntj%10;
    if(abs(taxi[cnti][cntj])>SnW[cnti][cntj])
    {
        exp1t=exp1t*88/100;exp2t=exp2t*88/100;
        hp1t=hp1t*9/10;hp2t=hp2t*9/10;
    }
    else
    {
        exp1t=exp1t*112/100;exp2t=exp2t*112/100;
        hp1t=hp1t*11/10;hp2t=hp2t*11/10;
    }
    update_EXP(EXP1,exp1t);
    update_EXP(EXP2,exp2t);
    update_HP(HP1,hp1t);
    update_HP(HP2,hp2t);
    
    if(abs(taxi[cnti][cntj])>SnW[cnti][cntj]) return taxi[cnti][cntj];
    else return SnW[cnti][cntj];
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if(strlen(s)<8) return -1;
    
    if(strlen(s)>20) return -2;
    
    for(int i=0;i<strlen(s);i++)
    {
        int tmp=0;
        while(s[i+tmp]==email[tmp])
        {
            tmp++;
            if(email[tmp]=='@') return -(300+i);
        }
    }
    
    for(int i=0;i<strlen(s)-2;i++) if((s[i]==s[i+1])&&(s[i+1]==s[i+2])) return -(400+i);

    bool specialChar=0;
    for(int i=0;i<strlen(s);i++) if((s[i]<48)||((57<s[i])&&(s[i]<65))||((90<s[i])&&(s[i]<97))||(122<s[i])) specialChar=1;
    if(!specialChar) return -5;

    for(int i=0;i<strlen(s);i++) if(((s[i]<48)||((57<s[i])&&(s[i]<65))||((90<s[i])&&(s[i]<97))||(122<s[i]))&&((s[i]!='@')&&(s[i]!='#')&&(s[i]!='%')&&(s[i]!='$')&&(s[i]!='!'))) return i;
    
    return -10;
    
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int check[num_pwds],ansI=num_pwds-1,ansCnt=1;
    check[num_pwds-1]=1;
    for(int i=num_pwds-2;i>=0;i--)
    {
        check[i]=0;
        for(int j=i+1;j<num_pwds;j++)
        {
            if(arr_pwds[j]==arr_pwds[i])
            {
                check[i]=check[j]+1;
                break;
            }
            if(j==(num_pwds-1)) check[i]=1;
        }
        
        if(check[i]>ansCnt)
        {
            ansCnt=check[i];
            ansI=i;
        }
        else if(check[i]==ansCnt) if(strlen(arr_pwds[i])>=strlen(arr_pwds[ansI])) ansI=i;
    }
    // for(int i=0;i<num_pwds;i++) cout << arr_pwds[i] << " " << check[i] << endl;
    return ansI;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////