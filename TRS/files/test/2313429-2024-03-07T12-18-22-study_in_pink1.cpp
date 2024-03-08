#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
int firstMeet(int & EXP1, int & EXP2, int E1)
{
    //TH3
         if (E1 < 0 || E1 > 99) return -99;
    //TH1
        else if (E1<=3)
        {
        //EXP2
            int inexp[] = {29,45,75,29+45+75};
            EXP2 += inexp[E1];
        //EXP1
         int D = E1*3 + EXP1*7;
            if (D%2==0) EXP1=ceil(EXP1+D/200.0);
            else        EXP1=ceil(EXP1-D/100.0);
        }
    //TH2
        //EXP2
    else if (E1<=19) EXP2+=ceil(E1/4.0+19);
    else if (E1<=49) EXP2+=ceil(E1/9.0+21);
    else if (E1<=65) EXP2+=ceil(E1/16.0+17);
    else if (E1<=79) 
        {
            EXP2+=ceil(E1/4.0+19);
            if (EXP2>200) EXP2+=ceil(E1/9.0+21);
        }
    else
        {
            EXP2+=ceil(E1/4.0+19);
            EXP2+=ceil(E1/9.0+21);
            if (EXP2>400) { EXP2+=ceil(E1/16.0+17);
                            EXP2=ceil(EXP2*1.15);}
        }
        //EXP1
         if (E1>=4&&E1<=99)   EXP1-=E1; 
    //setEXP
    if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;
    if (EXP2>600) EXP2=600;
    else if (EXP2<0) EXP2=0;
    return EXP1 + EXP2;
}
void set(int & EXP1, int & HP1, int & M1)
{
    if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;
    if (HP1>666) HP1=666;
    else if (HP1<0) HP1=0;
    if (M1>3000) M1=3000;
    else if (M1<0) M1=0;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if (E2 > 99 || E2 < 0) return -99;
    else {
    //Road1
        //findS
    int n = floor (sqrt(EXP1)), S = 0;
    if ((EXP1-n*n)>((n+1)*(n+1)-EXP1)) S = (n+1)*(n+1);
    else                               S = n*n;
        //findP1
        float P1 = 0;
    if (EXP1>=S) P1 = 100;
    else         P1 = ((float)EXP1/S+80)*100/123.0;
    //Road2
        //Odd
    int fee = 0;
    while (E2%2!=0)
    {   
            if (!M1) break;
        //event1
        if (HP1<200)  {HP1 = ceil(HP1*1.3);     fee+=150;}
        else          {HP1 = ceil(HP1*11.0/10); fee+=70;}
        set(EXP1, HP1, M1);
            if (fee>0.5*M1) {M1-=fee; break;}
        //event2
        if (EXP1<400) {EXP1 = ceil(EXP1*1.13); fee+=200;}
        else          {EXP1 = ceil(EXP1*1.13); fee+=120;}
        set(EXP1, HP1, M1);
            if (fee>0.5*M1) {M1-=fee; break;}
        //event3
        if (EXP1<300) {EXP1 = ceil(EXP1*0.9); fee+=100;}
        else          {EXP1 = ceil(EXP1*0.9); fee+=120;}
       set(EXP1, HP1, M1);
            if (fee>0.5*M1) {M1-=fee; break;}
    }
        //Even
    if (E2%2==0) for (int i=0; i<1; i++)
    {
            if (!M1) break;
        //event1
        if (HP1<200)  {HP1 = ceil(HP1*1.3);     M1-=150;}
        else          {HP1 = ceil(HP1*11.0/10); M1-=70;}
        set(EXP1, HP1, M1);
            if (!M1) break;
        //event2
        if (EXP1<400) {EXP1 = ceil(EXP1*1.13); M1-=200;}
        else          {EXP1 = ceil(EXP1*1.13); M1-=120;}
        set(EXP1, HP1, M1);
            if (!M1) break;
        //event3
        if (EXP1<300) {EXP1 = ceil(EXP1*0.9); M1-=100;}
        else          {EXP1 = ceil(EXP1*0.9); M1-=120;}
        set(EXP1, HP1, M1);
            if (!M1) break;
    }
    HP1  = ceil(HP1*0.83);
    EXP1 = ceil(EXP1*1.17);
        set(EXP1, HP1, M1);
        //findS2
    int n2 = floor (sqrt(EXP1)), S2 = 0;
    if ((EXP1-n2*n2)>((n2+1)*(n2+1)-EXP1)) S2 = (n2+1)*(n2+1);
    else                                   S2 = n2*n2;
        //findP2
        float P2 = 0;
    if (EXP1>=S2) P2 = 100;
    else          P2 = ((float)EXP1/S2+80)*100/123.0;
    //Road3
        //findP3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, P3 = 0;
    if (E2<10) P3 = P[E2];
    else       P3 = P[(E2%10+E2/10)%10];
    //End
    if (P1==P2&&P2==P3&&P3==100) EXP1 = ceil(EXP1*0.75);
    else {  
        int avrP = (P1+P2+P3)/3;
            if (avrP<50) {HP1  = ceil(HP1*0.85);
                          EXP1 = ceil(EXP1*1.15);}
            else         {HP1  = ceil(HP1*0.9);
                          EXP1 = ceil(EXP1*1.2);}
         }
    //setEXP
        set(EXP1, HP1, M1);
    return HP1 + EXP1 + M1;}
}
void setsw(int & EXP1, int & HP1, int & EXP2, int & HP2)
{
    if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;
    if (HP1>666) HP1=666;
    else if (HP1<0) HP1=0;
    if (EXP2>600) EXP2=600;
    else if (EXP2<0) EXP2=0;
    if (HP2>666) HP2=666;
    else if (HP2<0) HP2=0;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
if (E3 > 99 || E3 < 0) return -99;
else {
    int mat[10][10]={0}, cnt1 = 0, cnt2 = 0;
for (int i = 0; i<10; i++){
    for (int j = 0; j<10; j++)
    {
        mat[i][j]=((E3*j)+(i*2))*(i-j);
        if (mat[i][j]>0&&mat[i][j]>E3*2) cnt1++;
        if (mat[i][j]<0&&mat[i][j]<-E3) cnt2++;
    }
}
while (cnt1>9||cnt2>9)
{
    cnt1=cnt1/10+cnt1%10;
    cnt2=cnt2/10+cnt2%10;
}
int taxipt = mat[cnt1][cnt2];
int swpt   = mat[cnt1][cnt2];
for (int i=0; i<10; i++)
{
    if (mat[i][cnt1+cnt2-i]>swpt&&cnt1+cnt2-i<=9&&cnt1+cnt2-i>=0) swpt = mat[i][cnt1+cnt2-i];
    if (mat[i][cnt2-cnt1+i]>swpt&&cnt2-cnt1+i<=9&&cnt2-cnt1+i>=0) swpt = mat[i][cnt2-cnt1+i];
}
if (abs(taxipt)>abs(swpt)) { HP1  = ceil(HP1*0.9);
                        HP2  = ceil(HP2*0.9);
                        EXP1 = ceil(EXP1*0.88);
                        EXP2 = ceil(EXP2*0.88);
                        setsw(EXP1, HP1, EXP2, HP2);
                        return taxipt;
                        }
else                  { HP1  = ceil(HP1*11.0/10);
                        HP2  = ceil(HP2*11.0/10);
                        EXP1 = ceil(EXP1*112.0/100);
                        EXP2 = ceil(EXP2*112.0/100);
                        setsw(EXP1, HP1, EXP2, HP2);
                        return swpt;
                        }
}
}

// Task 4
int checkPassword(const char * s, const char * email)
{
char se[101] = {0};
const char* hook = strchr(email, '@');
strncpy(se, email, hook - email);
    //ut1
     if (strlen(s)<8)  return -1;
    //ut2
else if (strlen(s)>20) return -2;
    //ut3
if (strstr(s,se)) return -(300 + strstr(s,se)-s);
    //ut4
for ( int i=0; i<strlen(s)-2;i++)
    {
     if (s[i]==s[i+1]&&s[i+1]==s[i+2]) return -(400+i);
    }
    //ut5
char specialch[5]={'@','#','%','$','!'};
int foo = 0;
for (int j=0;j<5;j++)
{
     if (strchr(s, specialch[j])) foo++;
}
     if (!foo) return -5;
    //ut6
for (int i=0;i<strlen(s);i++)
{
bool tick = true;
for (int j=0;j<5;j++) 
if ((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||s[i]==specialch[j])
{
    tick = false;
    break;
}
if (tick) return i;
}
return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    //mảng tần suất
    int freq[1024] = {0}, maxFreq = 0, maxFreqIndex = 0;
    for (int i = 0; i < num_pwds; ++i) {
        int count = 1;
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
            freq[i] = count;
    }
    //tần suất cao nhất
    for (int i = 0; i < num_pwds; ++i) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxFreqIndex = i;
        } else if (freq[i] == maxFreq) {
            //độ dài lớn nhất
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[maxFreqIndex])) {
                maxFreqIndex = i;
            }
        }
    }
    return maxFreqIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////