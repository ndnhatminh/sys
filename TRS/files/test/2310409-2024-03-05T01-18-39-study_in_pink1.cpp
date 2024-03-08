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


void checkHp1(int & HP1){
    if(HP1>666.0) HP1=666.0;
    if(HP1<0.0) HP1=0.0;     
}
void checkHp(int & HP1,int & HP2){
    if(HP1>666.0) HP1=666.0;
    if(HP1<0.0) HP1=0.0;   
    if(HP2>666.0) HP2=666.0;
    if(HP2<0.0) HP2=0.0;
}
void checkExp1(int & EXP1){
    if(EXP1>600) EXP1=600;
    if (EXP1<0) EXP1=0;
}
void checkExp(int & EXP1,int & EXP2){
    if(EXP1>600) EXP1=600;
    if(EXP2>600) EXP2=600;
    if(EXP1<0) EXP1=0;
    if(EXP2<0) EXP2=0;
}
void checkM1(int &M1){
      if(M1<0) M1=0;
      if(M1>3000) M1=3000;
}
void checkM2(int &M2){
    if(M2>3000) M2=3000;
    if(M2<0) M2=0;
}
void checkexp(int &exp1, int &exp2){
    if(exp1>600) exp1=600;
    if(exp1<0) exp1=0;
    if(exp2<0) exp2=0;
    if(exp2>600) exp2=600;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1<0||e1>99) return -99;
    else{
    checkexp(exp1,exp2);
    if (e1 >= 0 && e1 <= 3){
        switch (e1) {
    case 0: exp2 += 29; break;
    case 1: exp2 += 45; break;
    case 2: exp2 += 75; break;
    case 3: exp2 += 149; break;
    checkexp(exp1,exp2);
    }
    int D;
    D = 3 * e1 + 7 * exp1;
    if (D % 2 == 0) exp1 = exp1 + ceilf(D / 200.0);
    else exp1 = ceilf(exp1 - D / 100.0);
    checkexp(exp1,exp2);
    }

    else if (e1 >= 4 && e1 <= 99){
    if (4 <= e1 && e1 <= 19) exp2 = exp2 + ceilf(e1 / 4.0) + 19;
    else if (e1 >= 20 && e1 <= 49) exp2 = exp2 + ceilf(e1 / 9.0) + 21;
    else if (e1 >= 50 && e1 <= 65) exp2 = exp2 + ceilf(e1 / 16.0) + 17;
    else if (e1 >= 66 && e1 <= 79) {
        exp2 = exp2 + ceilf(e1 / 4.0) + 19;
        if (exp2 > 200) exp2 = exp2 + ceilf(e1 / 9.0) + 21;
        else exp2 = exp2;
    }
    else if (e1 >= 80 && e1 <= 99) {
        exp2 = exp2 + ceilf(e1 / 4.0) +ceilf( e1 / 9.0) + 40;
        if (exp2 > 400) {
            exp2 = exp2 + ceilf(e1 / 16.0) + 17;
            exp2 = ceilf(1.15 * exp2);
        }
        else exp2 = exp2;
    }
    //checkExp(exp1,exp2);
    exp1=exp1-e1;
    checkexp(exp1,exp2);
    }
    checkexp(exp1,exp2);
    }
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0||E2>99) return -99;
    else{
    checkExp1(EXP1);
    checkHp1(HP1);
    checkM1(M1);
    double p1;
    double a=sqrt(EXP1);
    double scpnho=floor(a)*floor(a);
    double scplon=ceilf(a)*ceilf(a);
    if(scplon-EXP1>EXP1-scpnho) p1=1.00;
    else if(EXP1==0||EXP1==1) p1=1.00;
    else p1=(EXP1/scplon+80.0)/123.00;
    checkHp1(HP1);
    int m=ceilf(0.5*M1);
    if(M1==0){
        HP1=ceilf(0.83*HP1);
        EXP1=ceilf(1.17*EXP1);
        checkExp1(EXP1);
    }
    else{
    if(E2%2!=0) {
        while(M1>=m){
            if(HP1<200.0){
                HP1=ceilf(1.3*HP1);
                M1-=150;
            }
            else {
                HP1=ceilf(1.1*HP1);
                M1-=70;
            }
            checkHp1(HP1);
            checkM1(M1);
            if(M1==0) break;
            else if(M1<m) break;
            else{
                if(EXP1<400) M1-=200;
                else M1-=120;
                EXP1=ceilf(1.13*EXP1);
            }
            checkExp1(EXP1);
            checkM1(M1);
            if(M1==0) break;
            else if(M1<m) break;
            else{
                if(EXP1<300) M1-=100;
                else M1-=120;
                EXP1=ceilf(0.9*EXP1);
            }
            checkM1(M1);
        }
        HP1=ceilf(0.83*HP1);
        EXP1=ceilf(1.17*EXP1);
        checkExp1(EXP1);
    }
    else{
        while(M1!=0){
        if(HP1<200){
                HP1=ceilf(1.3*HP1);
                M1-=150;
            }
            else {
                HP1=ceilf(1.1*HP1);
                M1-=70;
            }
            checkHp1(HP1);
        checkM1(M1);
        if(M1==0) break;
        else{
        if(EXP1<400) M1-=200;
        else M1-=120;
        EXP1=ceilf(1.13*EXP1);
        }
        checkExp1(EXP1);
        checkM1(M1);
        if(M1==0) break;
        else{
        if(EXP1<300) M1-=100;
            else M1-=120;
                EXP1=ceilf(0.9*EXP1);
        }
        checkM1(M1);
        checkExp1(EXP1);
        break;
        }
        HP1=ceilf(0.83*HP1);
        EXP1=ceilf(1.17*EXP1);
        checkExp1(EXP1);  
    }      
    }
    checkExp1(EXP1);
    double p2;
    double b=sqrt(EXP1);
    double scpnho2=floor(b)*floor(b);
    double scplon2=ceilf(b)*ceilf(b);
    if(scplon2-EXP1>EXP1-scpnho2) p2=1.0;
    else if(EXP1==0||EXP1==1) p2=1.0;
    else p2=(EXP1/scplon2+80.0)/123.0;

    double P[10]{0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11};
    int i;
    if(E2<10) i=E2;
    else{
        int c=0;
        while(E2!=0){
            c+=(E2%10);
            E2/=10;
        }
        c=c%10;
        i=c;
    }
    double p3=P[i];

    if(p1==1.00&&p2==1.00&&p3==1.00)
    EXP1=ceilf(EXP1*0.75);
    else{
        double p=(p1+p2+p3)/3.00;
        if(p-0.5<0){
            HP1=ceilf(0.85*HP1);
            EXP1=ceilf(1.15*EXP1);
        }
        else{
            HP1=ceilf(0.9*HP1);
            EXP1=ceilf(1.2*EXP1);
        }
        checkExp1(EXP1);
    }
    return HP1 + EXP1 + M1;
}
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0||E3>99) return -99;
    else{
    int x[10][10]{};
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            x[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    int ci=0,cj=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(x[i][j]>(2*E3)) ci++;
            else if(x[i][j]<(-E3)) cj++;
            else{
                ci=ci;
                cj=cj;
            }
        }
    }
    int i3,j3;
    i3=ci/10+ci%10;
    if(i3>9) i3=i3/10+i3%10;
    else i3=i3;
    j3=cj/10+cj%10;
    if(j3>9) j3=j3/10+j3%10;
    else j3=j3;
    int max=x[i3][j3];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i+j==i3+j3){
                if(x[i][j]>max) max=x[i][j];
                else max=max;
            }
            else if(i-j==i3-j3){
                if(x[i][j]>max) max=x[i][j];
                else max=max;
            }  
        }
    }
    int rs;
    if(abs(x[i3][j3])>max){
        EXP1=ceilf(EXP1*0.88);
        EXP2=ceilf(EXP2*0.88);
        HP1=ceilf(HP1*0.9);
        HP2=ceilf(HP2*0.9);
        rs=x[i3][j3];
        }
    else if(abs(x[i3][j3])<=max){
        EXP1=ceilf(EXP1*1.12);
        EXP2=ceilf(EXP2*1.12);
        HP1=ceilf(HP1*1.1);
        HP2=ceilf(HP2*1.1);
        rs=max;
    }
    checkHp(HP1,HP2);
    checkExp(EXP1,EXP2);
    return rs;
}
}
// Task 4
int checkPassword(const char * s, const char * email) {
    string em=email;
    string pw=s;
    int vtra=em.find("@");
    string se=em.substr(0,vtra);
    int l=pw.length();
    if(l<8) return -1;
    if(l>20) return -2;
    int sei=pw.find(se);
    if(sei>=0&&sei<l) return -(300+sei) ;
    int d=0;
    char h=pw[0];
    int r;
    for(int i=1;i<l;i++){
        if(pw[i]==h){
            h=pw[i];
            d++;
            if(d==2){
                r=-(400+i-2);
                break;
            }
        }
        else{
            h=pw[i];
            d=0;
        }         
    }
    if(d==2) return r;
    int k=0;
    for(int i=0;i<l;i++){
        if(pw[i]=='@'||pw[i]=='#'||pw[i]=='%'||pw[i]=='$'||pw[i]=='!') break;
        else k++;
    }
    if(k==l) return -5;
    int v;
    for(int i=0;i<l;i++){
        char f=pw[i];
        if(!((f>='a'&&f<='z')||(f>='A'&&f<='Z')||(f>='0'&&f<='9')||f=='@'||f=='#'||f=='%'||f=='$'||f=='!'))
              return i;
        } 
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string pw[num_pwds];
    for(int i=0;i<num_pwds;i++){
        pw[i]=arr_pwds[i];     
    }
    int demMax = 0,daiMax=0;
    int dem = 0,dai = 0;
    int vtrd = -1;
    
    for (int i = 0; i < num_pwds; i++) {
        dem = 0;
        dai = pw[i].length();
        for (int j = 0; j < num_pwds; j++) {
            if (pw[i] == pw[j]) {
                dem++;
            }
        }
        if (dem > demMax || (dem == demMax && dai > daiMax)) {
            demMax = dem;
            daiMax = dai;
            vtrd = i;
        }
    }
    return vtrd;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////