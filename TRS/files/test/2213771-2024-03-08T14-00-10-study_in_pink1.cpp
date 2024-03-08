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
int round_up(double number) 
{
    int t = static_cast<int>(number); 
    double decimal= number - t; 
    if (decimal>0.0001) {t+= 1;}
    return t;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
   if(e1>=0&&e1<=3)
{    
    if(e1==0) exp2+=29;
    else if(e1==1) exp2+=45;
    else if(e1==2) exp2+=75; 
    else {exp2=exp2+29+45+75;}
    if(exp2>600) {exp2=600;}
    int D=e1*3+exp1*7;
    if(D%2==0) 
    {
        double D1=double(exp1)+double(D)/200;
        exp1=round_up(D1);
        if(exp1>600) exp1=600;
    }
    else 
    {
        double D2=double(exp1)-double(D)/100;
        exp1=round_up(D2);
        if(exp1<0) exp1=0;
    }
} 
else if(e1>=4&&e1<=99)
{
    if(e1>=4&&e1<=19)
    {
        double e=double(exp2) + double(e1)/4 + 19;
        exp2=round_up(e);
        if(exp2>600) exp2=600;
    }
    else if(e1>=20&&e1<=49)
    {
        double e=double(exp2) + double(e1)/9 + 21;
        exp2=round_up(e);
        if(exp2>600) exp2=600;
    }
    else if(e1>=50&&e1<=65)
    {
        double e=double(exp2) + double(e1)/16 + 17;
        exp2=round_up(e);
        if(exp2>600) exp2=600;
    }
    else if(e1>=66&&e1<=79)
    {
        double e=double(exp2) + double(e1)/4 + 19;
        exp2=round_up(e);
        if(exp2>200)
        {
            double t=double(exp2) + double(e1)/9 + 21;
            exp2=round_up(t);
        }
        if(exp2>600) exp2=600;
    }
    else if(e1>=80&&e1<=99)
    {
        double e=double(exp2) + double(e1)/4 + 19;
        exp2=round_up(e);
        double t=double(exp2) + double(e1)/9 + 21;
        exp2=round_up(t);
        if(exp2>400)
        {
            double e=double(exp2) + double(e1)/16 + 17;
            exp2=round_up(e);
            double t=double(exp2)*1.15;
            exp2=round_up(t);
        }
        if(exp2>600) exp2=600;
    }
    exp1-=e1;
    if(exp1<0) exp1=0;
}
else { return -99;}
    return exp1 + exp2;
}
// Task 2
bool checkSquareNumber(int n) 
{
    if(n < 1) return false;
    int i = sqrt(n);
    if(i * i == n) return true;
    return false; 
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99) return -99;
    //cd1
    double P1,P2,P3;
    int tc=0;
    int s1 =EXP1;
    int s2 =EXP1;
    while(!checkSquareNumber(s1)) s1+=1;
    while(!checkSquareNumber(s2)) s2-=1;
    if(s1==s2) 
    {
        P1=1;
    }
    else if((s1-EXP1)<=(EXP1-s2)) 
    {
        P1 = double(double(EXP1)/s1+ 80)/123;  
    }
    else 
    {
        P1=1;    
    }
    //cd2
    bool p2;
    if(E2%2!=0) {p2 = true;}
    else p2=false;

    int t=round_up(double(M1)*0.5);
    while(p2){
    if(HP1<200)
    {
        double H=double(HP1)*1.3;
        M1-=150;
        tc+=150;
        HP1=round_up(H);
        if(M1<0) M1=0;
        if(tc>t) break;
    }
    else 
    {
        double H1=double(HP1)*1.1;
        M1-=70;
        tc+=70;
        HP1=round_up(H1);
        if(HP1>666) HP1=666;
        if(M1<0) M1=0;
        if(tc>t) break;
    }
    if(EXP1<400)
    {
        M1-=200;
        tc+=200;
        double p=double(EXP1)*1.13;
        EXP1=round_up(p);
        if(M1<0) M1=0;
        if(tc>t) break;
    }
    else 
    {
        M1-=120;
        tc+=120;
        double p1=double(EXP1)*1.13;
        EXP1=round_up(p1);
        if(EXP1>600) EXP1=600;
        if(M1<0) M1=0;
        if(tc>t) break;
    }
    if(EXP1<300)
    {
        M1-=100;
        tc+=100;
        double f=double(EXP1)*0.9;
        EXP1=round_up(f);
        if(M1<0) M1=0;
        if(tc>t) break;
    }
    else 
    {
        M1-=120;
        tc+=120;
        double f1=double(EXP1)*0.9;
        EXP1=round_up(f1);
        if(M1<0) M1=0;
        if(tc>t) break;
    }
    }
    if(p2==false)
    {
        if(HP1<200)
    {
        double H=double(HP1)*1.3;
        M1-=150;
        tc+=150;
        HP1=round_up(H);
    }
    else 
    {
        double H1=double(HP1)*1.1;
        M1-=70;
        tc+=70;
        HP1=round_up(H1);
        if(HP1>666) HP1=666;
    }
        if(M1>0)
        {
            if(EXP1<400)
    {
        M1-=200;
        tc+=200;
        double p=double(EXP1)*1.13;
        EXP1=round_up(p);
    }
    else 
    {
        M1-=120;
        tc+=120;
        double p1=double(EXP1)*1.13;
        EXP1=round_up(p1);
        if(EXP1>600) EXP1=600;
    }
       if(M1>0)
       {
        if(EXP1<300)
    {
        M1-=100;
        tc+=100;
        double f=double(EXP1)*0.9;
        EXP1=round_up(f);
    }
    else 
    {
        M1-=120;
        tc+=120;
        double f1=double(EXP1)*0.9;
        EXP1=round_up(f1);
    }
       } 
    }
    if(M1<0) M1=0;
    }
    double temp=double(EXP1)*1.17;
    EXP1=round_up(temp);
    if(EXP1>600) EXP1=600;
    double temp1=double(HP1)*0.83;
    HP1=round_up(temp1);
    int s3 =EXP1;
    int s4 =EXP1;
    while(!checkSquareNumber(s3)) s3+=1;
    while(!checkSquareNumber(s4)) s4-=1;
    if(s3==s4) 
    {
        P2=1;
    }
    else if((s3-EXP1)<=(EXP1-s4)) 
    {
        P2 = double((EXP1/s3+ 80))/123;  
    }
    else 
    {
        P2=1;    
    }
    //cd3
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2<10)
    {
        P3=p[E2];
    }
    else 
    {
        int m= E2%10+ E2/10;
        if(m>9) P3=p[m%10];
        else P3=p[m];
    }
    if(P1==1&&P2==1&&P3==100)
    {
        double temp=double(EXP1)*0.75;
        EXP1=round_up(temp);
    }
    else 
    {
        double P=(P1+P2+double(P3)/100)/3;
        if(P<0.5)
        {
            double tem=double(EXP1)*1.15;
            EXP1=round_up(tem);
            if(EXP1>600) EXP1=600;
            double tem1=double(HP1)*0.85;
            HP1=round_up(tem1);
        }
        else 
        {
            double tem=double(EXP1)*1.20;
            EXP1=round_up(tem);
            if(EXP1>600) EXP1=600;  
            double tem1=double(HP1)*0.9;
            HP1=round_up(tem1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     if(E3<0||E3>99) return -99;
    int arr[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++) arr[i][j]=0;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            arr[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    int gtd=0,gta=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++) 
        {
            if(arr[i][j]>E3*2) gtd+=1;
            if(arr[i][j]<-E3) gta+=1;
        }
    }
    int t= gtd%10+gtd/10;
    int t1=gta%10+gta/10;
    while(t>9)
    {
        t=t%10+t/10;
    }
    while(t1>9)
    {
        t1=t1%10+t1/10;
    }
    int dtx=abs(arr[t][t1]);
    int dtx1=arr[t][t1];
    int dSW;
    int maxt=arr[t][t1];
    int maxp=arr[t][t1];
    int p=t+t1;
    int n=t;
    int a=t;
    int m=t1;
    int b=t1;
    //dct
    while(n<9&&m>0)
    {
        n++;
        m--;
        if(maxt<arr[n][m]) maxt=arr[n][m];
    }
    while(a>0&&b<9)
    {
        a--;
        b++;
        if(maxt<arr[a][b]) maxt=arr[a][b];
    }
    //dcp
    int n1=t;
    int a1=t;
    int m1=t1;
    int b1=t1;
    while(n1<9&&m1<9)
    {
        n1++;
        m1++;
        if(maxp<arr[n1][m1]) maxp=arr[n1][m1];
    }
    while(a1>0&&b1>0)
    {
        a1--;
        b1--;
        if(maxp<arr[a1][b1]) maxp=arr[a1][b1];
    }
    if(maxt>=maxp) dSW=maxt;
    else dSW=maxp;
    if(dSW<0) dSW=abs(dSW);
    if(dtx>dSW)
    {
        double t=double(EXP1)*0.88;
        EXP1=round_up(t);  
        double t1=double(HP1)*0.9;
        HP1=round_up(t1);
        double t2=double(EXP2)*0.88;
        EXP2=round_up(t2);  
        double t3=double(HP2)*0.9;
        HP2=round_up(t3);
        return dtx1;
    }
    else 
    {
        double t=double(EXP1)*1.12;
        EXP1=round_up(t);
        if(EXP1>600) EXP1=600;  
        double t1=double(HP1)*1.1;
        HP1=round_up(t1);
        if(HP1>666) HP1=600;
        double t2=double(EXP2)*1.12;
        EXP2=round_up(t2); 
        if(EXP2>600) EXP2=600;  
        double t3=double(HP2)*1.1;
        HP2=round_up(t3);
        if(HP2>666) HP2=600;
        return dSW;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
     const char *se = strchr(email, '@');
    int l=strlen(se);
    int l1=strlen(email);
    char t[l1-l+1];
    int len = strlen(s);
    strncpy(t,email,l1-l);
    t[l1-l]='\0';
    if (len < 8) {
        return -1;
    }
    if (len > 20) {
        return -2; 
    }
    if (strstr(s, t)) {return -(300 + len - strlen(strstr(s, t)) ); }
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }
    bool hasSpecialChar = false;
    for (int i = 0; i < len; ++i) 
    {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {return -5; }
     for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            return i; 
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int p[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        p[i] = 0;
    }
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                p[i]++;
            }
        }
    }
    int max_freq = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (p[i] > max_freq) {
            max_freq = p[i];
        }
    }
    const char * longest_pwd = "";
    int position = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (p[i] == max_freq && strlen(arr_pwds[i]) > strlen(longest_pwd)) {
            longest_pwd = arr_pwds[i];
            position = i;
        }
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////