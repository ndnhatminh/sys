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
//Function addon
int cM(int a){
    if (a<0){a=0;}
    if (a>3000){a=3000;}
    return a;
}
int cHP(int hp){
    if (hp<0){hp=0;}
    if (hp>666){hp=666;}
    return hp;
}
int cEXP(int exp){
    if(exp<0){exp=0;}
    if(exp>600){exp=600;}
    return exp;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1)
{
    //TODO: implement task
        if (E1 < 0 || E1 > 99) return -99;
    if (E1<=3){
        if (E1==0){
        EXP2 +=29;
    }else if (E1==1){
        EXP2 +=45;
    }else if (E1==2){
        EXP2+=75;
    }else {EXP2+=149;}
    int D;
    D =E1*3+EXP1*7;
    if(D%2==0){EXP1+=ceilf(float(D)/200);}
    else{EXP1-=ceilf((D)/100);}
    }else{
        if(3<E1 && E1<20){
            EXP2+=ceilf(float (E1)/4)+19;
        }else if(19<E1 && E1<50){
            EXP2+=ceilf(float (E1)/9)+21;
        }else if(49<E1 && E1<66){
            EXP2+=ceilf(float (E1)/16)+17;
        }else if(65<E1 && E1<80){
            EXP2+=ceilf(float (E1)/4)+19;
            if(EXP2>200){EXP2+=ceilf(float (E1)/9)+21;}
        }else{
            EXP2+=ceilf(float (E1)/4)+ceilf(float(E1)/9)+40;
            if(EXP2>400){
                EXP2+=ceilf(float (E1)/16)+17;
                EXP2=ceilf(float (EXP2)*1.15);
            }
        }
             EXP1-=E1;
    }
    if(EXP1>600){EXP1=600;}
    if(EXP1<0){EXP1=0;}
    if(EXP2>600){EXP2=600;}
    if(EXP2<0){EXP2=0;}    
    return EXP1+EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    //TODO: implement task
    if (E2 > 99 || E2 < 0) return -99;
    EXP1=cEXP(EXP1);
    HP1=cHP(HP1);
    M1=cM(M1);
//conduong1
    int S;
    S=pow(round(sqrt(EXP1)),2);
    float P1;
    if (S>EXP1){
        P1=((float(EXP1)/float(S))+80)/123;
    }else{
        P1=1;
    }
//conduong2
    if (E2%2==0){
        if(M1>0){
            if(HP1<200){
                HP1=ceil(float (HP1*1.3));
                M1-=150;
                HP1=cHP(HP1);
                M1=cM(M1);
            }else{
                HP1=((HP1)*1.1)+0.999;
                M1-=70;
                HP1=cHP(HP1);
                M1=cM(M1);
            }
        }
        if(M1>0){
            if(EXP1<400){
                M1-=200;
            }else{
                M1-=120;
            }
            EXP1=ceil(float(EXP1*1.13));
            M1=cM(M1);
            EXP1=cEXP(EXP1);
        }
        if(M1>0){
            if(EXP1<300){
                M1-=100;
            }else{
                M1-=120;
            }
           M1=cM(M1);
           EXP1=cEXP(EXP1);
            EXP1=ceil(float(EXP1*0.9));
        }
        if(M1<0){M1=0;}
    }else if(M1!=0){
        int m=M1;
        while(m>=float(M1)/2){
            if(m>=float(M1)/2){
                if(HP1<200){
                    HP1=ceil(float(HP1*1.3));
                    m-=150;
                }else{
                    HP1=((HP1)*1.1)+0.999;
                    m-=70;
                }
                m=cM(m);
                HP1=cHP(HP1);
            }
            if(m>=float(M1)/2){
                    if(EXP1<400){
                    m-=200;
                }else{
                    m-=120;
                   
                }
                EXP1=ceil(float(EXP1*1.13));
                m=cM(m);
                EXP1=cEXP(EXP1); 
            }
             if(m>=float(M1)/2){
                   
                if(EXP1<300){
                    m-=100;
                }else{
                    m-=120;
                }
                 EXP1=ceil(EXP1*0.9);
                m=cM(m);
                EXP1=cEXP(EXP1);
             }
        }
        if(m<0){m=0;}
        M1=m;
    }
    HP1=ceil(float(HP1*0.83));
    EXP1=ceil(float(EXP1*1.17));
    EXP1=cEXP(EXP1);
    HP1=cHP(HP1);
    int S2;
    S2=pow(round(sqrt(EXP1)),2);
    float P2;
    if (S2>EXP1){
        P2=((float(EXP1)/float(S2))+80)/123;
    }else{
        P2=1;
    }
//conduong3
    float L[]={32.0,47.0,28.0,79.0,100.0,50.0,22.0,83.0,64.0,11.0};
    int i;
    if(E2/10==0){
        i=E2;
    }else{
        i=((E2/10)+(E2%10))%10;
    }
    float P3=L[i]/100;
//hetduong
    if(P1==1.0 &&P2==1.0 && P3==1.0){
        EXP1=ceil(EXP1*0.75);
    }else{
        float P=(P1+P2+P3)/3;
        if(P<0.5){
            HP1=ceil(float(HP1*0.85));
            EXP1=ceil(float(EXP1*1.15));
        }else{
            HP1=ceil(float(HP1*0.9));
            EXP1=ceil(float(EXP1*1.2));
        }
    }
    EXP1=cEXP(EXP1);
    HP1=cHP(HP1);
    M1=cM(M1);
    return HP1 +EXP1+ M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    if (E3 > 99 || E3 < 0) return -99;
    int a[10][10];
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            a[i][j]=((E3*j)+i*2)*(i-j);
        }
    }
    int l=0,m=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(a[i][j]>E3*2){m++;}
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(a[i][j]<-E3){l++;}
        }
    }
    int i1,j1;
    if(m/10!=0){
        while(m/10!=0){
            m=(m/10)+(m%10);
        }
         i1=m;
    }else{i1=m;}
    if(l/10!=0){
        while(l/10!=0){
            l=(l/10)+(l%10);   
        }
        j1=l;
    }else{j1=l;}
    int hw=0;
    i=i1;
    j=j1;
    while((i<10) && (j<10)){
        if(a[i][j]>hw){hw=a[i][j];}
        i++;
        j++;
    }
    i=i1;
    j=j1;
    while((i>-1) && (j<10)){
        if(a[i][j]>hw){hw=a[i][j];}
        i--;
        j++;
    }
    i=i1;
    j=j1;
    while((i>-1) && (j>-1)){
        if(a[i][j]>hw){hw=a[i][j];}
        i--;
        j--;
    }
    i=i1;
    j=j1;
    while((i<10) && (j>-1)){
        if(a[i][j]>hw){hw=a[i][j];}
        i++;
        j--;
    }
    hw=abs(hw);
    int r;
    if (abs(a[i1][j1])>hw){
        EXP1=ceil(float(EXP1*0.88));
        EXP2=ceil(float(EXP2*0.88));
        HP1=ceil(float(HP1*0.9));
        HP2=ceil(float(HP2*0.9));
        r=a[i1][j1];
    }else{
        EXP1=ceil(float(EXP1*1.12));
        EXP2=ceil(float(EXP2*1.12));
        HP1=ceil(float(HP1*1.1));
        HP2=ceil(float(HP2*1.1));
        r=hw;
    }
    HP1=cHP(HP1);
    HP2=cHP(HP2);
    EXP1=cEXP(EXP1);
    EXP2=cEXP(EXP2);
    return r;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    string S=s;
    string e=email;
    string se=e.substr(0,e.find("@"));
    if(S.length()<8){return -1;}
    if(S.length()>20){return -2;}
    if(S.find(se) != string::npos){
        int sei=S.find(se);
        return -(300+sei);
    }
    for(int i=0;i+2<S.length();i++){
        if(S[i]==S[i+1] && S[i+2]==S[i] ){return -(400+i); }
    }
    int count=0;
    for(int j=0;j<S.length();j++){
        if(S[j]=='!' || S[j]=='@' || S[j]=='#' || S[j]=='$' || S[j]=='%'){count++;}
    }
    if(count==0){return -5;}
    for(int z=0; z<S.length();z++){
        if(isalpha(S[z])==0 && isdigit(S[z])==0 && S[z]!='!' && S[z]!='@' && S[z]!='#' && S[z]!='$' && S[z]!='%'){return z;}
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    //TODO: implement task
    string a[num_pwds];
    for(int i=0;i<num_pwds;i++){
        a[i]=(string) arr_pwds[i];
    }
    int b[num_pwds][2]={0};
    for(int i=0;i< num_pwds;i++){
        for(int c=0;i+c< num_pwds;c++){
            if(a[i+c]==a[i]){
                b[i][0]++;
                b[i][1]=(int)a[i].length();
            }
        }
    }
    
    int h=0;
    for(int j=0;j< num_pwds;j++){
        if(h<b[j][0]){h=b[j][0];}
    }
    int y=0, t;
    for(int z=0;z< num_pwds;z++){
        if(b[z][0]==h){
            if(b[z][1]>y){
                y=b[z][1];
                t=z;
            }
        }
    }
    return t;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////