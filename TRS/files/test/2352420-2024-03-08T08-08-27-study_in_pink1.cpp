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
int check1(int exp1) {
    if(exp1>600)    return 600;
    else if(exp1<0) return 0;
    else    return exp1;}
int check2(int exp2) {
    if(exp2>600)    return 600;
    else if(exp2<0) return 0;
    else    return exp2;}
int findS(int exp1) {
    int S;
    double x=sqrt(exp1);
    if(ceil(x)==floor(x))   S=exp1;
    else {
        int y=pow(ceil(x),2);
        int z=pow(floor(x),2);
        abs(exp1-y)>abs(exp1-z)?  S=z :   S=y;}
    return S;}
int check3(int hp1) {
    if(hp1>666)    return 666;
    else if(hp1<0) return 0;
    else    return hp1;}
int check4(int hp2) {
    if(hp2>666)    return 666;
    else if(hp2<0) return 0;
    else    return hp2;}
int check5(int M1) {
    if(M1>3000)    return 3000;
    else if(M1<0) return 0;
    else    return M1;}
int check6(int M2) {
    if(M2>3000)    return 3000;
    else if(M2<0) return 0;
    else    return M2;}
int checkstring(string a) {
    for(int i=0;i<a.length()-2;i++) {
        if(a[i]==a[i+1]&&a[i]==a[i+2])  return i;}
    return -1;}
const double k=0.0000001;
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1>=0&&e1<=3) {
        exp1=check1(exp1);
        exp2=check2(exp2);
        switch(e1) {
            case 0:
                exp2+=29;
                exp2=check2(exp2);
                break; 
            case 1:
                exp2+=45;
                exp2=check2(exp2);
                break;
            case 2:
                exp2+=75;
                exp2=check2(exp2);
                break;
            case 3:
                exp2+=29+45+75;
                exp2=check2(exp2);
                break;}
        int D=3*e1+7*exp1;
        D%2==0?     exp1+=ceil((float)D/200 -k) :   exp1-=floor((float)D/100 -k);
        exp1=check1(exp1);
        return exp1 + exp2;}
    else if(e1>=4&&e1<=99) {
        if(e1<=19) {
            exp2+=ceil((float)e1/4 -k)+19;
            exp2=check2(exp2);}
        else if(e1<=49) {
            exp2+=ceil((float)e1/9 -k)+21;
            exp2=check2(exp2);}
        else if(e1<=65) {
            exp2+=ceil((float)e1/16 -k)+17;
            exp2=check2(exp2);}
        else if(e1<=79) {
            exp2+=ceil((float)e1/4 -k)+19;
            exp2=check2(exp2);
            exp2>200?   exp2+=ceil((float)e1/9 -k)+21 :   exp2=exp2;
            exp2=check2(exp2);}
        else if(e1<=99) {
            exp2+=ceil((float)e1/4 -k)+19;
            exp2=check2(exp2);
            exp2+=ceil((float)e1/9 -k)+21;
            exp2=check2(exp2);
            exp2>400?   exp2=ceil((exp2+ceil((float)e1/16-k)+17)*1.15-k):   exp2=exp2;
            exp2=check2(exp2);}
        exp1-=e1;
        exp1=check1(exp1);
        return exp1 + exp2;}
    else    return -99;
    }

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P1,P2,P3,Pn;
    if(E2<0||E2>99)    return -99;
    else {
        EXP1=check1(EXP1);
        HP1=check3(HP1);
        M1=check5(M1);
        //Path 1
        int S1=findS(EXP1);
        EXP1>=S1?    P1=1    :   P1=(((float)EXP1/S1)+80)/123;
        //Path 2
        int m=floor((float)M1/2 -k);
        int t=0;
        if(E2%2==0) {
            while(1) {
                //Ac1
                if(HP1<200) {
                    M1-=150;
                    M1=check5(M1);
                    HP1+=ceil(HP1*0.3-k);
                    HP1=check3(HP1);}
                else {
                    M1-=70;
                    M1=check5(M1);
                    HP1+=ceil(HP1*0.1-k);
                    HP1=check3(HP1);}
                if(M1==0)   break;
                //Ac2
                if(EXP1<400) {
                    M1-=200;
                    M1=check5(M1);}
                else {
                    M1-=120;
                    M1=check5(M1);}
                EXP1+=ceil(EXP1*0.13-k);
                EXP1=check1(EXP1);
                if(M1==0)   break;
                //Ac3
                if(EXP1<300) {
                    M1-=100;
                    M1=check5(M1);}
                else {
                    M1-=120;
                    M1=check5(M1);}
                EXP1-=floor(EXP1*0.1-k);
                EXP1=check1(EXP1);
                break;}}
        else {
            while(t<=m) {
                //Ac1
                if(HP1<200) {
                    M1-=150;
                    M1=check5(M1);
                    HP1+=ceil(HP1*0.3-k);
                    HP1=check3(HP1);
                    t+=150;}
                else {
                    M1-=70;
                    M1=check5(M1);
                    HP1+=ceil(HP1*0.1-k);
                    HP1=check3(HP1);
                    t+=70;}
                if(t>m) break;
                //Ac2
                if(EXP1<400) {
                    M1-=200;
                    M1=check5(M1);
                    t+=200;}
                else {
                    M1-=120;
                    M1=check5(M1);
                    t+=120;}
                EXP1+=ceil(EXP1*0.13-k);
                EXP1=check1(EXP1);
                if(t>m) break;
                //Ac3
                if(EXP1<300) {
                    M1-=100;
                    M1=check5(M1);
                    t+=100;}
                else {
                    M1-=120;
                    M1=check5(M1);
                    t+=120;}
                EXP1-=floor(EXP1*0.1-k);
                EXP1=check1(EXP1);}}
        HP1-=floor(HP1*0.17-k);
        HP1=check3(HP1);
        EXP1+=ceil(EXP1*0.17-k);
        EXP1=check1(EXP1);
        int S2=findS(EXP1);
        EXP1>=S2?    P2=1    :   P2=(((float)EXP1/S2)+80)/123;
        //Path 3
        int P[10]={32,47,28,79,100,50,22,83,64,11};
        int k=E2/10 + E2%10;
        P3=(float)P[k%10]*0.01;
        if(P1==1&&P2==1&&P3==1) {
            EXP1-=floor(EXP1*0.25-k);
            EXP1=check1(EXP1);}
        else {
            Pn=(P1+P2+P3)/3;
            if(Pn<0.5) {
                EXP1+=ceil(EXP1*0.15-k);
                EXP1=check1(EXP1);
                HP1-=floor(HP1*0.15-k);
                HP1=check3(HP1);}
            else {
                EXP1+=ceil(EXP1*0.2-k);
                EXP1=check1(EXP1);
                HP1-=floor(HP1*0.1-k);
                HP1=check3(HP1);}}
        return HP1 + EXP1 + M1;}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99) return -99;
    else {
        EXP1=check1(EXP1);
        HP1=check3(HP1);
        EXP2=check2(EXP2);
        HP2=check4(HP2);
        int a[10][10];
        int count1=0;
        int count2=0;
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                a[i][j]=((E3*j)+(i*2))*(i-j);
                if(a[i][j]>2*E3)    count1++;
                if(a[i][j]<-E3)     count2++;}}
        while(count1>=10) {
            count1=count1/10+count1%10;}
        while(count2>=10) {
            count2=count2/10+count2%10;}
        int N=a[count1][count2];
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                if((i+j==count1+count2)||(i-j==count1-count2)) {
                    a[i][j]>N?  N=a[i][j]   :   N=N;}}}
        if(abs(a[count1][count2])>abs(N)) {
            EXP1-=floor(EXP1*0.12-k);
            EXP1=check1(EXP1);
            EXP2-=floor(EXP2*0.12-k);
            EXP2=check2(EXP2);
            HP1-=floor(HP1*0.1-k);
            HP1=check3(HP1);
            HP2-=floor(HP2*0.1-k);
            HP2=check4(HP2);
            return a[count1][count2];}
        else {
            EXP1+=ceil(EXP1*0.12-k);
            EXP1=check1(EXP1);
            EXP2+=ceil(EXP2*0.12-k);
            EXP2=check2(EXP2);
            HP1+=ceil(HP1*0.1-k);
            HP1=check3(HP1);
            HP2+=ceil(HP2*0.1-k);
            HP2=check4(HP2);
            return N;}
            }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string ch = email;
    string mk = s;
    int r=ch.find('@');
    string se = ch.erase(r,ch.length()-r);
    if(mk.length()<8)   return -1;
    else if(mk.length()>20) return -2;
    else if(mk.find(se)!=string::npos)  return -(300+mk.find(se));
    else if(checkstring(mk)!=-1)    return -(400+checkstring(mk));
    else if(mk.find('@')==string::npos&&mk.find('#')==string::npos&&mk.find('%')==string::npos
    &&mk.find('$')==string::npos&&mk.find('!')==string::npos)   return -5;
    for(int i=0;i<mk.length();i++) {
        if(isalpha(mk[i])==0&&isdigit(mk[i])==0&&mk[i]!='@'&&mk[i]!='#'&&mk[i]!='%'&&
        mk[i]!='$'&&mk[i]!='!') return i;}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int arr1[num_pwds];
    int arr2[num_pwds];
    string arr3[num_pwds];
    for(int i=0;i<num_pwds;i++) {
        arr3[i] = arr_pwds[i];
        arr2[i] = arr3[i].length();}
    for(int i=0;i<num_pwds;i++) {
        int count=0;
        for(int j=0;j<num_pwds;j++) {
            if(arr3[i]==arr3[j])    count++;}
        arr1[i]=count;}
    int max1=0;
    int max2=0;
    for(int i=0;i<num_pwds;i++) {
        if(arr1[i]>=max1)    max1=arr1[i];}
    for(int i=0;i<num_pwds;i++) {
        if(arr1[i]<max1)    arr2[i]-=arr2[i];}
    for(int i=0;i<num_pwds;i++) {
        if(arr2[i]>max2)    max2=arr2[i];}
    for(int i=0;i<num_pwds;i++) {
        if(arr1[i]==max1&&arr2[i]==max2)    return i;}
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////