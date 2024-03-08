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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    if(e1>=0&&e1<=3){
    if(e1==0){
        exp2+=29;
    } 
    if(e1==1){
        exp2+=45;
    }
    if(e1==2){
        exp2+=75;
    }
    if(e1==3){
        exp2+=149;
    }
    D=e1*3+exp1*7;
    if(D%2==0){
        exp1+=(D/200);
    }else{
        exp1-=(D/100);
    }
    }
    if(e1>=4&&e1<=99){
    if(e1>=4&&e1<=19){
        exp2+=(double(e1)/4+19)+0.9999;
    }
    if(e1>=20&&e1<=49){
        exp2+=(double(e1)/9+21)+0.9999;
    }
    if(e1>=50&&e1<=65){
        exp2+=(double(e1)/16+17)+0.9999;
    }
    if(e1>=66 && e1<=79){
        exp2+=(double(e1)/4+19)+0.9999;
        if (exp2 > 200)
        {
            exp2+=(double(e1)/9+21)+0.9999;
        }
    }
    if(e1>=80&&e1<=99){
        exp2+=(double(e1)/4+19)+0.9999;
        exp2+=(double(e1)/9+21)+0.9999;
        if(exp2>400){
            exp2+=(double(e1)/16+17)+0.9999;
            exp2+=(0.15*exp2)+0.9999;
            if(exp2>600){
                exp2=600;
            }
        }
    }exp1-=e1;
    }    if(exp1>600){
            exp1=600;
        }
        if(exp1<0){
            exp1=0;
        }
        if(exp2>600){
            exp2=600;
        }
        if(exp2<0){
            exp2=0;
        }    
        if(e1<0&&e1>99){
            return -99;
        }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double S=sqrt(EXP1);
    int closest=round(S);
    int s=closest*closest;
    double P1,P2,P3;
    float moneyhadspent =0;
    float road2moneyspent = 0.5*M1;
    double P_average;
    if(EXP1 >= s){
        P1=1;
    }else{
        P1=(float(EXP1)/s+80)/123;
        P1=ceil(float(P2));
    }
    if(E2%2==1){
    while(moneyhadspent<road2moneyspent){
        if(HP1<200){
            HP1=ceil(float(HP1+HP1*0.3));
            M1=M1-150;
            moneyhadspent+=150;
            if(moneyhadspent>road2moneyspent){
                break;
            }
        }
        else{
            HP1=ceil(float(HP1+HP1*0.1));
            M1=M1-70;
            moneyhadspent+=70;
            if(moneyhadspent>road2moneyspent){
                break;
            }
        }
        if(EXP1<400){
            M1=M1-200;
            moneyhadspent+=200;
            if(moneyhadspent>road2moneyspent){
                break;
            }
        }else{
            M1=M1-120;
            moneyhadspent+=120;
            EXP1=ceil(float(EXP1*1.13));
            if(moneyhadspent>road2moneyspent){
                break;
            }
        }
        if(EXP1<300){
            M1=M1-100;
            moneyhadspent+=100;
            if(moneyhadspent>road2moneyspent){
                break;
            }
        }else{
            M1=M1-120;
            moneyhadspent+=120;
            EXP1=ceil(float(EXP1*0.9));
            if(moneyhadspent>road2moneyspent){
                break;
            }
        }
        
        }
        if(moneyhadspent>road2moneyspent){
            HP1=ceil(float(HP1*0.83));
            EXP1=ceil(float(EXP1*1.17));
            }
    }
    if(E2&2==0){
        if(HP1<200){
            HP1=ceil(float(HP1+HP1*0.3));
            M1=M1-150;
        }
        else{
            HP1=ceil(float(HP1+HP1*0.1));
            M1=M1-70;
        }
        if(M1>0){
            if(EXP1<400){
            M1=M1-200;
        }else{
            M1=M1-120;
            EXP1=ceil(float(EXP1*1.13));
        }
        if(M1>0){
            if(EXP1<300){
            M1=M1-100;
        }else{
            M1=M1-120;
            EXP1=ceil(float(EXP1*0.9));
                }
            }
        }
    }  
     S=sqrt(EXP1);
     closest=round(S);
     s=closest*closest;
 
    if (EXP1 >= S) {
        P2 = 1;
    }
    else {
        P2=(float(EXP1)/s+80)/123;
        P2=ceil(float(P2));
    }
    if (E2 >= 0 && E2 <= 9) {
        P3 = P[E2] / 100;
    }
    else if (E2 >= 10) {
        int total = 0;
        while (E2 != 0) {
            int kq = E2 % 10;
            total = total+kq;
            E2 /= 10;
        }
        P3 = P[total % 10];
        P3 /= 100;
    }

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(float(EXP1)*0.75);
    }
    else {
       P_average = (P1 + P2 + P3) / 3;
    }
    if (P_average < 0.5) {
        HP1 = ceil(float(HP1)*0.85);
        EXP1 = ceil(float(EXP1)*1.15);
    }
    else (P_average >= 0.5); {
        HP1 = ceil(float(HP1)*0.9);
        EXP1 = ceil(float(EXP1)*1.2);
    }
        if(EXP1>600){
            EXP1=600;
        }
        if(EXP1<0){
            EXP1=0;
        }
        if(HP1>666){
            HP1=666;
        }
        if(HP1<0){
            HP1=0;
        }
        if(M1>3000){
            M1=3000;
        }
        if(M1<0){
            M1=0;
        }
        if(E2<0&&E2>99){
            return -99;
        }
    

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int a[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a[i][j]=((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int p=0;
    int n=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]>E3*2){
                p++;
            }
            if(a[i][j]< -E3){
                n++;
            }
        }
    }
    int total=0;
    int i=0;
    int j=0;
    int totalminus=0;
    while(p!=0){
        int kq=p%10;
        total+=kq;
        p/=10;
    }
    if((total%10)==0){
        while(total!=0){
        int kq=total%10;
        i+=kq;
        total/=10;
        }  
    }
    else{
        i=total;
    }
    while(n!=0){
        int dq=n%10;
        totalminus+=dq;
        n/=10;
    }
    if((totalminus%10)==0){
        while(totalminus!=0){
        int dq=totalminus%10;
        j+=dq;
        totalminus/=10;
        }
    }
    else{
        j=totalminus;
    }
    int Sherlockscore=0;
    int Sherlock1score=0;
    for(int x = i, y = j; x >= 0 && y <10; x--, y++) {
        a[x][y];
        if(a[x][y]>Sherlockscore){
            Sherlockscore=a[x][y];
        }
    }
    for(int x=i, y=j;x<10&&y>=0;x++,y--){
        a[x][y];
        if(a[x][y]>Sherlock1score){
            Sherlock1score=a[x][y];
        }
    }
    int maxscore=max(Sherlock1score,Sherlockscore);

    if(abs(a[i][j])>maxscore){
        
        EXP1 = EXP1 * 0.88;
        HP1 = HP1 * 0.9;
        EXP2 = EXP2 * 0.88;
        HP2 = HP2 * 0.9;
        return a[i][j];
    }
    if(abs(a[i][j])<maxscore){
        EXP1 = EXP1 * 0.88;
        HP1 = HP1 * 0.9;
        EXP2 = EXP2 * 0.88;
        HP2 = HP2 * 0.9;
        return maxscore;
    }
    if(EXP1>600){
            EXP1=600;
        }
        if(EXP1<0){
            EXP1=0;
        }
        if(HP1>666){
            HP1=666;
        }
        if(HP1<0){
            HP1=0;
        }
        if(EXP2>600){
            EXP2=600;
        }
        if(EXP2<0){
            EXP2=0;
        }
        if(HP2>666){
            HP2=666;
        }
        if(HP2<0){
            HP2=0;
        }
        if(E3<0&&E3>99){
            return -99;
        }
        return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string Email = email;
    string S = s;
    size_t kq=Email.find("@");
    string se=Email.substr(0,kq);
    if(Email.length()>100){
        return false;
    }
    if(S.length()<8){
        return -1;
    }
    if(S.length()>20){
        return -2;
    }
    size_t sei=S.find(se);
    if(sei!=string::npos){
        return -(300+sei);
    }
    for(int i=0;i<S.length();i++){
        if(S[i]==S[i+1]){
            if (S[i]==S[i+2]){
                return -400-i;
            }
        }else{
            continue;
        }
    }
    int a = 0;
    for (int i = 0; i < S.length(); i++){
        if (S[i] == '$'){
            a += 1;
        }
        if (S[i] == '@'){
            a += 1;
        }
        if (S[i] == '#'){
            a += 1;
        }
        if (S[i] == '!'){
            a += 1;
        }
        if (S[i] == '%'){
            a += 1;
        }
    }
    if(a == 0){
        return -5;
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcount=0;
    int maxlength=0;
    int position=-1; 
    for(int i=0;i<num_pwds;i++){
        int count=0;
        int length=strlen(arr_pwds[i]);
        for(int j=i+1;j<num_pwds;j++){
          if(arr_pwds[i]==arr_pwds[j]){
            count++;
          }
        }
        if(count>=maxcount||(maxcount==count&&maxlength==length)){
            maxcount=count;
            maxlength=length;
            position=i;
        }
    
    }
    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////