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
    float exp1=EXP1,exp2=EXP2,e1=E1;
    if (e1==0) exp2=exp2+29; else
        if (e1==1) exp2=exp2+45; else
            if (e1==2) exp2=exp2+75; else
                if(e1==3) exp2=exp2+29+75+45; else
                    if (3<e1&&e1<20) exp2=ceil(exp2+e1/4+19-0.001); else
                        if (19<e1&&e1<50) exp2=ceil(exp2+e1/9+21-0.001); else
                            if (49<e1&&e1<66) exp2=ceil(exp2+e1/16+17-0.001); else
                                if (65<e1&&e1<80) {exp2=ceil(exp2+e1/4+19-0.001); if (exp2>200) exp2=ceil(exp2+e1/9+21-0.001);} else
                                    if (79<e1&&e1<100) {exp2=ceil(exp2+e1/4+19-0.001); exp2=ceil(exp2+e1/9+21-0.001); if (exp2>400) {exp2=ceil(exp2+e1/16+17-0.001); exp2=ceil(exp2*1.15-0.001);}}
    if (e1<100&&e1>3) exp1=exp1-e1;
    if (exp1<0) exp1=0;
    if (exp2>600) exp2=600;
    int D=e1*3+exp1*7;
    if (0<=e1&&e1<4&&D%2==0) exp1=ceil(exp1+D/200-0.001);
    if (0<=e1&&e1<4&&D%2==1) exp1=ceil(exp1-D/100-0.001);
    if (exp1>600) exp1=600; else
        if (exp1<0) exp1=0;
        EXP1=exp1;EXP2=exp2;E1=e1;
    return EXP1+EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    float S,m=M1,p,exp1=EXP1,hp1=HP1,m1=M1;
    int i,j;
    float P1,P2,P3,P[10];

    S=pow(2,2);
    for (int i=3; pow(i,2)<=exp1;i++)
        {if (exp1-pow(i,2)<exp1-S) S=pow(i,2);
        j=i;}
        if (pow(j+1,2)-exp1<exp1-S) S=pow(j+1,2);
    if (exp1>=S) P1=100; else P1=(exp1/S+80)/123*100;

    while(E2%2==0)
    {
        if (hp1<200) {hp1=ceil(hp1*1.3-0.001); m1=m1-150;} else {hp1=ceil(hp1*1.1-0.001); m1=m1-70;}
        if (hp1>666) hp1=666; if (m1<=0) {m1=0; break;}
        if (exp1<400) m1=m1-200; else m1=m1-120; exp1=ceil(exp1*1.13-0.001);
        if (exp1>600) exp1=600;
        if (m1<=0) {m1=0; break;}
        if (exp1<300) m1=m1-100; else m1=m1-120;
        exp1=ceil(exp1*0.9-0.001);
        if (m1<=0) {m1=0; break;}
        if (exp1<0) exp1=0;
        break;
    }
    while(E2%2==1)
    {
        if (hp1<200) {hp1=ceil(hp1*1.3-0.001); m1=m1-150;} else {hp1=ceil(hp1*1.1-0.001); m1=m1-70;}
        if (hp1>666) hp1=666; if (m1<=0) {m1=0; break;} if (m*0.5>m1) break;
        if (exp1<400) m1=m1-200; else m1=m1-120; exp1=ceil(exp1*1.13-0.001);
        if (exp1>600) exp1=600;
        if (m1<=0) {m1=0; break;} if (m*0.5>m1) break;
        if (exp1<300) m1=m1-100; else m1=m1-120;
        if (m1<=0) {m1=0; break;} if (m*0.5>m1) break;
        exp1=ceil(exp1*0.9-0.001);
        if (exp1<0) exp1=0;
    }
    hp1=ceil(hp1*0.83-0.001); exp1=ceil(exp1*1.17-0.001);
    if (m1<0) m1=0; if (exp1>600) exp1=600;

    S=pow(2,2);
    for (int i=3; pow(i,2)<=exp1;i++)
        {if (exp1-pow(i,2)<exp1-S) S=pow(i,2);
        j=i;}
        if (pow(j+1,2)-exp1<exp1-S) S=pow(j+1,2);
    if (exp1>=S) P2=100; else P2=(exp1/S+80)/123*100;
    /*if (hp1<200) {hp1=hp1*1.3; m1=m1-150;} else {hp1=hp1*1.1; m1=m1-70;}
    hp1=int(hp1);
    if (hp1<0) hp1=0; else if (hp1>666) hp1=666; if (m1<0) m1=0; else if (m1>3000) m1=3000;
    if (exp1<400) m1=m1-200; else m1=m1-120; exp1=exp1*1.13; exp1=int(exp1);
    if (exp1>600) exp1=600;
    if (m1<0) m1=0;
    if (exp1<300) m1=m1-100; else m1=m1-120;
    if (m1<0) m1=0;
    exp1=exp1*0.9; exp1=int(exp1);
    if (exp1<0) exp1=0;*/ //prototype 1

    P[0]=32;P[1]=47;P[2]=28;P[3]=79;P[4]=100;P[5]=50;P[6]=22;P[7]=83;P[8]=64;P[9]=11;
    if (E2>=0&&E2<10) P3=P[E2]; else {i=E2%10; j=E2/10; i=(i+j)%10; P3=P[i];}
    p=(P1+P2+P3)/3*100;
    if (p==100) exp1=ceil(exp1*0.75-0.001);
    if (p<50) {exp1=ceil(exp1*1.15-0.001); hp1=ceil(hp1*0.85-0.001);}
    if (p>50) {exp1=ceil(exp1*1.2-0.001); hp1=ceil(hp1*0.9-0.001);}
    if (exp1>600) exp1=600; else if (exp1<0) exp1=0;
    if (hp1<0) hp1=0;
    EXP1=exp1;M1=m1;HP1=hp1;
    return EXP1+HP1+M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    float exp1=EXP1,exp2=EXP2,hp1=HP1,hp2=HP2;
    int x[10][10],p=0,n=0,i,j,m;
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
        {
            x[i][j]=((E3*j)+(i*2))*(i-j);
            if (x[i][j]>0&&x[i][j]>E3*2) p++;
            if (x[i][j]<0&&x[i][j]<-E3) n++;
        }
        p=p%10+p/10; n=n%10+n/10;
        p=p%10+p/10; n=n%10+n/10;
        i=p;j=n;m=x[p][n];
        if (p+n!=9)
        {
            while (i>=0&&j>=0) {if (x[i][j]>m) m=x[i][j]; i=i-1;j=j-1;}
            i=p;j=n;
            while (j<10&&i<10) {if (x[i][j]>m) m=x[i][j]; i=i+1;j=j+1;}
        }
        if (p+n==9)
        {
            while (i>=0&&j>=0) {if (x[i][j]>m) m=x[i][j]; i=i-1;j=j-1;}
            i=p;j=n;
            while (j<10&&i<10) {if (x[i][j]>m) m=x[i][j]; i=i+1;j=j+1;}
            i=p;j=n;
            while (j>=0) {if (x[i][j]>m) m=x[i][j]; i=i+1;j=j-1;}
            i=p;j=n;
            while (i>=0) {if (x[i][j]>m) m=x[i][j]; i=i-1;j=j+1;}
        }
    if (abs(x[p][n])>m)
    {
        exp1=ceil(exp1*0.88-0.001);
        hp1=ceil(hp1*0.9-0.001);
        exp2=ceil(exp2*0.88-0.001);
        hp2=ceil(hp2*0.9-0.001);
        if (hp1<0) hp1=0; if (hp2<0) hp2=0;
        if (exp1<0) exp1=0; if (exp2<0) exp2=0;
        EXP1=exp1;EXP2=exp2;HP1=hp1;HP2=hp2;
        return x[p][n];
    }
    else
    {
        exp1=ceil(exp1*1.12-0.001);
        hp1=ceil(hp1*1.1-0.001);
        exp2=ceil(exp2*1.12-0.001);
        hp2=ceil(hp2*1.1-0.001);
        if (hp1>666) hp1=666; if (hp2>666) hp2=666;
        if (exp1>600) exp1=600; if (exp2>600) exp2=600;
        EXP1=exp1;EXP2=exp2;HP1=hp1;HP2=hp2;
        return m;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string S,E,se;
    S=s; E=email;
    se=E.substr(0,E.find("@"));
    if (S.size()<8) return -1;
    if (S.size()>20) return -2;
    if (S.find(se)!=-1) return -(300+S.find(se));
    for (int i=0;i<S.size();i++)
        if (S[i]==S[i+1]) {return -(400+i); break;}
    if (S.find("@")==-1&&S.find("#")==-1&&S.find("$")==-1&&S.find("!")==-1&&S.find("%")==-1) return -5;
    for (int i=0;i<S.size();i++)
        if (S[i]!=33&&(S[i]<35||S[i]>37)&&(S[i]<64||S[i]>90)&&(S[i]<48||S[i]>57)&&(S[i]<97||S[i]>122)) {return i; break;}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string pwd[30],n; int c=0,o[30],k=0,m;
    for (int j=0;j<30;j++)
        o[j]=0;
    for (int i=0;i<num_pwds;i++)
    {
        for (int j=0;j<30;j++)
            if (arr_pwds[i]==pwd[j])
                {o[j]++; c++;}
        if (c==0) {pwd[k]=arr_pwds[i]; o[k]++; k++;}
        c=0;
    }
    m=o[0];
    for (int i=1;i<=k;i++)
        if (o[i]>m) m=o[i];
    for (int i=0;i<=k;i++)
        if (o[i]!=m) pwd[i].erase(0,pwd[i].size()-1);
    n=pwd[0];
    for (int i=1;i<=k;i++)
        if (pwd[i].size()>n.size()) n=pwd[i];
    for (int i=0;i<num_pwds;i++)
        if (arr_pwds[i]==n) {return i; break;}
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
