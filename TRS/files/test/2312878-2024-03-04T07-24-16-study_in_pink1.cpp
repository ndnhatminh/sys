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
void checkEXP(int &EXP)
{
    if (EXP>600) EXP=600;
    if (EXP<0) EXP=0;
}

void checkHP(int &HP)
{
    if (HP>666) HP=666;
    if (HP<0) HP=0;
}

void checkM(int &M)
{
    if (M>3000) M=3000;
    if (M<0) M=0;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1<0 || e1>=100) return -99;
    if (e1>=0 && e1<=3)
    {
        int D=e1*3+exp1*7;
        if (e1==0) {exp2+=29; checkEXP(exp2);}
        if (e1==1) {exp2+=45; checkEXP(exp2);}
        if (e1==2) {exp2+=75; checkEXP(exp2);}
        if (e1==3) {exp2+=149; checkEXP(exp2);}
        if (D%2==0) {exp1=ceil(exp1+(D*1.0/200)); checkEXP(exp1);}
        if (D%2==1) {exp1=ceil(exp1-(D*1.0/100)); checkEXP(exp1);}
    }
    if (e1>=4 && e1<=99)
    {
        if (e1>=4 && e1<=19) {exp2=ceil(exp2+(e1*1.0/4)+19); checkEXP(exp2);}
        if (e1>=20 && e1<=49) {exp2=ceil(exp2+(e1*1.0/9)+21); checkEXP(exp2);}
        if (e1>=50 && e1<=65) {exp2=ceil(exp2+(e1*1.0/16)+17); checkEXP(exp2);}
        if (e1>=66 && e1<=79)
        {
            exp2=ceil(exp2+(e1*1.0/4)+19); checkEXP(exp2);
            if (exp2>200) {exp2=ceil(exp2+(e1*1.0/9)+21); checkEXP(exp2);}
        }
        if (e1>=80 && e1<=99)
        {
            exp2=ceil(exp2+(e1*1.0/4)+19); checkEXP(exp2);
            exp2=ceil(exp2+(e1*1.0/9)+21); checkEXP(exp2);
            if (exp2>400)
            {
                exp2=ceil(exp2+(e1*1.0/16)+17); checkEXP(exp2);
                exp2=ceil(exp2+(exp2*1.0/100*15)); checkEXP(exp2);
            }
        }
        exp1-=e1; checkEXP(exp1);
    }
    return exp1+exp2;
}

// Task 2
int findingsquare(int EXP)
{
    int a=sqrt(EXP);
    if (abs(a*a-EXP)>=abs((a+1)*(a+1)-EXP)) return (a+1)*(a+1);
    return a*a;
}
void buying(int &HP1, int &M1, int &M)
{
    if (HP1<200)
    {
        HP1=HP1+ceil(HP1*30.0/100); checkHP(HP1);
        M1-=150; checkM(M1);
        M+=150;
    }
    else if (HP1>=200)
    {
        HP1=HP1+ceil(HP1*1.0/10); checkHP(HP1);
        M1-=70; checkM(M1);
        M+=70;
    }
}

void travelling(int &EXP1, int &M1, int &M)
{
    if (EXP1<400) {M1-=200; M+=200; checkM(M1);}
    else if (EXP1>=400) {M1-=120; M+=120; checkM(M1);}
    EXP1=EXP1+ceil(EXP1*13.0/100); checkEXP(EXP1);
}

void meetingthehomeless (int &EXP1, int &M1, int &M)
{
    int m=100;
    if (EXP1>=300) m=120;
    M1-=m; checkM(M1);
    M+=m;
    EXP1=EXP1-floor(EXP1*1.0/10); checkEXP(EXP1);
}

int traceLuggage (int &HP1, int &EXP1, int &M1, int E2)
{
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    if (E2<0 || E2>99) return -99;


    double P1=100;
    int S=findingsquare(EXP1);
    if (EXP1<S) P1=(((EXP1*1.0/S)+80)/123*100);

    int M=0;
    int MM=M1;
    if (E2%2==1)
    {
        while (true)
        {
            if (((double)M>(double)(MM)/2) || M1==0) break;
            buying(HP1, M1, M);
            if (((double)M>(double)(MM)/2) || M1==0) break;
            travelling(EXP1, M1, M);
            if (((double)M>(double)(MM)/2) || M1==0) break;
            meetingthehomeless(EXP1, M1, M);
        }
        HP1=HP1-floor(HP1*17.0/100); checkHP(HP1);
        EXP1=EXP1+ceil(EXP1*17.0/100); checkEXP(EXP1);
    }

    if (E2%2==0)
    {
        for (int i=1;i<=1;i++)
        {
            if (M1==0) break;
            buying(HP1, M1, M);
            if (M1==0) break;
            travelling(EXP1, M1, M);
            if (M1==0) break;
            meetingthehomeless(EXP1, M1, M);
        }
        HP1=HP1-floor(HP1*17.0/100); checkHP(HP1);
        EXP1=EXP1+ceil(EXP1*17.0/100); checkEXP(EXP1);
    }
    double P2=100;
    int SS=findingsquare(EXP1);
    if (EXP1<SS) P2=(((EXP1*1.0/SS)+80)/123*100);

    double P3;
    int P[19]={32,47,28,79,100,50,22,83,64,11};
    if(E2>=0 && E2<=9) P3=P[E2];
    if (E2>=10)
    {
        int k=0;
        k+=E2%10; E2/=10;
        k+=E2%10; E2/=10;
        int last=k%10;
        P3=P[last]*1.0;
    }

    if (P1==100 && P2==100 && P3==100) {EXP1=EXP1-floor(EXP1*1.0/4); checkEXP(EXP1);}
    int aveP=ceil((P1+P2+P3)/3);
    if (aveP<50)
    {
        EXP1=EXP1+ceil(EXP1*15.0/100); checkEXP(EXP1);
        HP1=HP1-floor(HP1*15.0/100); checkHP(HP1);
    }
    if (aveP>=50 && aveP<100)
    {
        EXP1=EXP1+ceil(EXP1*1.0/5); checkEXP(EXP1);
        HP1=HP1-floor(HP1*1.0/10); checkHP(HP1);
    }
    return HP1+EXP1+M1;
}


// Task 3
int shortcut(int num)
{
    int sum = 0;
    while (num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int findinggreatestnum(int ii, int jj, int arr[19][19])
{
    int num=arr[ii][jj];
    //di len phai
    int i=ii-1, j=jj+1;
    while (i>=0 && j<=9)
    {
        num=max(num,arr[i][j]);
        i--;
        j++;
    }
    //di xuong trai
    i=ii+1; j=jj-1;
    while (i<=9 && j>=0)
    {
        num=max(num,arr[i][j]);
        i++;
        j--;
    }
    //di xuong trai
    i=ii+1; j=jj+1;
    while (i<=9 && j<=9)
    {
        num=max(num,arr[i][j]);
        i++;
        j++;
    }
    // di len trai
    i=ii-1; j=jj-1;
    while (i>=0 && j>=0)
    {
        num=max(num,arr[i][j]);
        i--;
        j--;
    }
    return num;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3<0 || E3>99) return -99;
    int output=0;
    int arr[19][19];
    int cntgreat=0, cntlow=0;
    for (int i=0;i<=9;i++)
    {
        for (int j=0;j<=9;j++)
        {
            arr[i][j]=((E3*j)+(i*2))*(i-j);
            if (arr[i][j]>E3*2 && arr[i][j]>0) cntgreat++;
            if (arr[i][j]<-E3 && arr[i][j]<0) cntlow++;
        }
    }
    int ii=shortcut(shortcut(cntgreat));
    int jj=shortcut(shortcut(cntlow));
    int scoreofSandW=abs(findinggreatestnum(ii,jj,arr));
    if (abs(arr[ii][jj])>scoreofSandW)
    {
        EXP1=EXP1-floor(EXP1*12.0/100); checkEXP(EXP1);
        EXP2=EXP2-floor(EXP2*12.0/100); checkEXP(EXP2);
        HP1=HP1-floor(HP1*1.0/10); checkHP(HP1);
        HP2=HP2-floor(HP2*1.0/10); checkHP(HP2);
        output=arr[ii][jj];
    }
    if (abs(arr[ii][jj])<=scoreofSandW)
    {
        EXP1=EXP1+ceil(EXP1*12.0/100); checkEXP(EXP1);
        EXP2=EXP2+ceil(EXP2*12.0/100); checkEXP(EXP2);
        HP1=HP1+ceil(HP1*1.0/10); checkHP(HP1);
        HP2=HP2+ceil(HP2*1.0/10); checkHP(HP2);
        output=scoreofSandW;
    }
    return output;
}

// Task 4
int check(string EMAIL, string ST)
{
    if(EMAIL.length()<ST.length()) return -1;
    for(int i=0;i<EMAIL.length()-ST.length()+1;++i)
    {
        bool ok=1;
        for(int j=0;j<ST.length();++j)
        if(EMAIL[i+j]!=ST[j])
        {
            ok=0;
            break;
        }
        if(ok) return i;
    }
    return -1;
}
int checkPassword(const char * s, const char * email)
{
    string EMAIL,S,ST;
    S=string(s);
    EMAIL=string(email);
    for(char i:EMAIL)
    {
        if(i=='@') break;
        ST+=i;
    }
    if(S.length()<8) return -1;
    if(S.length()>20) return -2;
    int v=check(S, ST);
    if(v!=-1) return -v-300;
    int k=1;
    for(int i=0;i<S.length()-1;++i)
    {
        if(S[i]==S[i+1]) k++;
        if(S[i]!=S[i+1]) k=1;
        if (k>2) return -i-399;
    }

    bool ok=1;
    for(char i:S)
    if(i=='@'||i=='#'||i=='%'||i=='$'||i=='!')
    {
        ok=0;
        break;
    }
    int checkk=0;
    int cnt=0;
    if(ok) return -5;
    for(char i: S)
    {
        cnt++;
        if ((int)i>=48 && (int)i<=57) continue;
        if (i=='@' || i=='#' || i=='%' || i=='$' || i=='!') continue;
        if ((int)i>=65 && (int)i<=90) continue;
        if ((int)i>=97 && (int)i<=122) continue;
        else checkk++;
        return cnt-1;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{

    int outputfre=0, outputlength=0, outputlocation=0;
    for (int i=0;i<num_pwds;i++)
    {
        int fre=0;
        string S;
        S=string(arr_pwds[i]);
        int length=S.length();
        for (int j=0;j<num_pwds;j++)
        {
            if (strcmp(arr_pwds[i],arr_pwds[j])==0) fre++;
            if (fre>outputfre || (fre==outputfre && length>outputlength))
            {
                outputfre=fre;
                outputlength=length;
                outputlocation=i;
            }
        }
    }
    return outputlocation;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////