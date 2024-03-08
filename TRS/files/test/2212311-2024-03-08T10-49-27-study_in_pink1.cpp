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
int checkHp(int Hp){
    if(Hp>666){Hp=666;}
    if(Hp<0){Hp=0;}
    return Hp;
}
int checkExp(int Exp){
    if(Exp>600){Exp=600;}
    if(Exp<0){Exp=0;}
    return Exp;
}
int checkMoney(int money){
    if(money<0){money=0;}
    if(money>3000){money=3000;}
    return money;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int e1) {
    // TODO: Complete this function
    
    if(e1<0 || e1>99) return -99;
    EXP1=checkExp(EXP1);
    EXP2=checkExp(EXP2);
    double DEXP1=EXP1,DEXP2=EXP2; // khởi tạo giá trị double để sử dụng hàm ceil
    //TH1 [0,3]
    if(0<=e1 && e1<=3 ){
        if(e1==0){DEXP2+=29;}
        if(e1==1){DEXP2+=45;}
        if(e1==2){DEXP2+=75;}
        if(e1==3){DEXP2=DEXP2+29+45+75;}
        int D=e1*3+DEXP1*7; //cout<<double(D)/100<<" ";
        if(D&1){DEXP1-=double(D)/100;
        // cout<<DEXP1<<" ";
        }
        else {DEXP1+=double(D)/200;}
    }
    //TH2 [4,99]
    if(4<=e1 && e1<=99){
        bool flag=false;
        if(4<=e1 && e1<=19){DEXP2+=double(e1)/4+19;}     //tt1   
        if(20<=e1 && e1<=49){DEXP2+=double(e1)/9+21;}    //tt2
        if(50<=e1 && e1<=65){DEXP2+=double(e1)/16+17;}   //tt3
        if(66<=e1 && e1<=79){                   //tt4
            DEXP2+=double(e1)/4+19;
            DEXP2=ceil(DEXP2);    
            if(DEXP2>200){DEXP2+=double(e1)/9+21;}    
            }
        if(80<=e1 && e1<=99){                   //tt5
            DEXP2+=double(e1)/4+19;
            DEXP2=ceil(DEXP2);
            DEXP2+=double(e1)/9+21;
            DEXP2=ceil(DEXP2);
            if(DEXP2>400){
                DEXP2+=double(e1)/16+17;
                DEXP2=ceil(DEXP2);
                flag=true;}
            }
        if(flag==true){DEXP2+=DEXP2*0.15;}
        DEXP1-=e1;
    }
    DEXP2=ceil(DEXP2);
    EXP2=DEXP2;
    // cout<<DEXP1<<" ";
    DEXP1=ceil(DEXP1);
    EXP1=DEXP1;
    if(EXP1>600){EXP1=600;}
    if(EXP1<0){EXP1=0;}
    if(EXP2>600){EXP2=600;}
    if(EXP2<0){EXP2=0;}
    return EXP1 + EXP2;
}
//tìm số chính phương
int squareNumber(int n){
    int b[25]={0};
    int i=0;
    while(i*i<n){
        b[i]=i*i;
        i++;
    }
    b[i]=i*i;
    // cout<<b[i]<<endl;
    if(abs(b[i]-n)>abs(b[i-1]-n)){
        return b[i-1];
    }
    else {return b[i];}
    
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99) return -99;
    HP1=checkHp(HP1);
    EXP1=checkExp(EXP1);
    M1=checkMoney(M1);
    int S=squareNumber(EXP1); //biến số chính phương gần nhất
    double P1;
    double DEXP1=EXP1,DHP1=HP1; //tao bien double de su dung ham ceil
    //                                          con duong 1
    if(DEXP1>=S){P1=100;}
    else if(S>DEXP1) {P1=(DEXP1/double(S)+80)/123;
        P1=(round(P1*100))/100;
        P1*=100;
    }
    //                                          con duong 2
    double P2;
    int M1flag=M1;
    //E2 la so le
    if(E2&1)  
    {
        while(1){
            if(DHP1<200){
                DHP1=ceil(DHP1*1.3- 0.000001);
                M1-=150;
            }
            else {
                DHP1=ceil(DHP1*1.1- 0.000001);
                if(DHP1>666){DHP1=666;}
                M1-=70;
            }
            if(M1<0){M1=0;break;}
            if(M1<M1flag/2){break;}
            if(DEXP1<400){
               M1-=200;
            }
            else{M1-=120;}
            DEXP1*=1.13;
            DEXP1=ceil(DEXP1);
            if(DEXP1>600){DEXP1=600;}
            if(M1<0){M1=0;break;}
            if(M1<M1flag/2){break;}
            if(DEXP1<300){
               M1-=100;
            }
            else {M1-=120;}
            DEXP1*=0.9;
            DEXP1=ceil(DEXP1);
            if(M1<0){M1=0;break;}
            if(M1<M1flag/2){break;}
            }
    }
    //E2 la so chan
    else {
        while(1){
        if(DHP1<200){
                DHP1=ceil(DHP1*=1.3- 0.000001);
                M1-=150;
            }
        else {
                DHP1=ceil(DHP1*=1.1- 0.000001);
                M1-=70;
                if(DHP1>666){DHP1=666;}
            }
        if(M1<0){M1=0;break;}
        if(DEXP1<400){
            M1-=200;
        }
        else{M1-=120;}
        DEXP1=ceil(DEXP1*1.13- 0.000001);
        if(DEXP1>600){DEXP1=600;}
        if(M1<0){M1=0;break;}
        if(DEXP1<300){
            M1-=100;
        }
        else {M1-=120;}
        DEXP1=ceil(DEXP1*0.9- 0.000001);
        if(M1<0){M1=0;}
        break;
        }
    }
    if(M1<0){M1=0;}
    DHP1=ceil(DHP1*0.83- 0.000001);
    DEXP1=ceil(DEXP1*1.17- 0.000001);
    if(DEXP1>600){DEXP1=600;}
    S=squareNumber(DEXP1);
    if(DEXP1>=S){P2=100;}
    else if(S>DEXP1) {P2=(DEXP1/double(S)+80)/123;
    P2=(round(P2*100))/100;
    P2*=100;
     }
    //                      con duong 3
    int arrayP[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3;double Paverage;
    int i=0;
    if(E2<10){
        i=E2;
    }
    else {
        i=E2%10+E2/10;
        i%=10;
    }
    P3=arrayP[i];
    
    // tinh trung binh xs
    if(P1==100 && P2==100 &&P3== 100){
        DEXP1*=0.75;
        DEXP1=ceil(DEXP1);
        Paverage=100;
    }
    else{
        Paverage=(P1+P2+P3)/3;
        Paverage=round(Paverage);
    }
    if(Paverage<50){
        DHP1*=0.85;
        DHP1=ceil(DHP1);
        DEXP1*=1.15;
        DEXP1=ceil(DEXP1);
    }
    else if(Paverage>=50 && Paverage<100){
        DHP1*=0.9;
        DHP1=ceil(DHP1);
        DEXP1*=1.2;
        DEXP1=ceil(DEXP1);
    }
    HP1=DHP1;
    EXP1=DEXP1;
    if(HP1>666){HP1=666;}
    if(HP1<0){HP1=0;}
    if(EXP1>600){EXP1=600;}
    if(EXP1<0){EXP1=0;}
    return HP1 + EXP1 + M1;
}

// Task 3


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99){return -99;}
    HP1=checkHp(HP1);
    HP2=checkHp(HP2);
    EXP1=checkExp(EXP1);
    EXP2=checkExp(EXP2);
    int imeet=0,jmeet=0;
    int array[10][10]={0};
    int i=0,j=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            array[i][j]=((E3*j)+(i*2))*(i-j);
            // cout<<setw(5)<<array[i][j]<<" ";
            if(array[i][j]>(E3*2)){imeet++;}
            if(E3==0){
                if(array[i][j]<E3){jmeet++;}
            }
            else {if(array[i][j]<(-E3)){jmeet++;}}
        }
        // cout<<endl;
    }
    while (imeet>=10){imeet=imeet%10+imeet/10;}
    while (jmeet>=10){jmeet=jmeet%10+jmeet/10;}
    //duong cheo trai
    int imeetold=imeet,jmeetold=jmeet;
    int leftDiagonal[10]={};
    for(i=0;i<10;i++){
        leftDiagonal[i]=-32767;
    }
    i=0;
    while(imeet>=0 && jmeet>=0){
        leftDiagonal[i++]=array[--imeet][--jmeet];
    }
    imeet=imeetold;jmeet=jmeetold;
    --i;
    while(imeet<=9 && jmeet<=9){
        leftDiagonal[i++]=array[imeet++][jmeet++];
    }
    // for(i=0;i<10;i++){
    //     cout<<leftDiagonal[i]<<" ";
    // }
    int maxleftDiagonal=leftDiagonal[0];
    for(i=0;i<10;i++){
       maxleftDiagonal=max(leftDiagonal[i],maxleftDiagonal);
    }
    //duong cheo phai 
    int rightDiagonal[10]={};
    imeet=imeetold;
    jmeet=jmeetold;
    for(i=0;i<10;i++){
        rightDiagonal[i]=-32767;
    }
    i=0;
    while (imeet>=0 && jmeet<=9){rightDiagonal[i++]=array[--imeet][++jmeet];}
    // for(i=0;i<10;i++){
    //     cout<<rightDiagonal[i]<<" ";
    // }
    i=0;
    imeet=imeetold;jmeet=jmeetold;
    while (imeet<=9 && jmeet>=0){rightDiagonal[++i]=array[imeet++][jmeet--];}
    // for(i=0;i<10;i++){
    //     cout<<rightDiagonal[i]<<" ";
    // }
    int maxrightDiagonal=rightDiagonal[0];
    for(i=0;i<10;i++){
        maxrightDiagonal=max(rightDiagonal[i],maxrightDiagonal);
    }
    int maxElement=max(maxleftDiagonal,maxrightDiagonal);
    // cout<<maxElement;
    imeet=imeetold;jmeet=jmeetold;
    if(maxElement<0){maxElement=abs(maxElement);}
    if(abs(maxElement)>=abs(array[imeet][jmeet])){
        EXP1=ceil(EXP1*1.12-0.000001);
        EXP2=ceil(EXP2*1.12-0.000001);
        HP1=ceil(HP1*1.1-0.000001);
        HP2=ceil(HP2*1.1-0.000001);
        if(EXP1>600){EXP1=600;}
        if(EXP2>600){EXP2=600;}
        if(HP1>666){HP1=666;}
        if(HP2>666){HP2=666;}
    }
    else {
        EXP1=ceil(EXP1*0.88-0.000001);
        EXP2=ceil(EXP2*0.88-0.000001);
        HP1=ceil(HP1*0.9-0.000001);
        HP2=ceil(HP2*0.9-0.000001);
        if(EXP1<0){EXP1=0;}
        if(EXP2<0){EXP2=0;}
        if(HP1<0){HP1=0;}
        if(HP2<0){HP2=0;}

    }
    return (abs(maxElement)>=abs(array[imeet][jmeet]))?maxElement:array[imeet][jmeet];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    stringstream e(email);
    getline(e,se,'@');
    // cout<<se<<" ";
    string temp=s;  
    //  
    int Maxlength=100;
    bool validpwd=false;
    bool checkword=false;
    // for(int i=0;i<strlen(s);i++){
    //     if(('A'<=s[i] && s[i]<='Z') || ('a'<=s[i]&& s[i]<='z') || s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!'
        
    //     ){checkword=true;}
    // }
    
    if(strlen(s)<8){ return -1;}
    if(strlen(s)>20){return -2;}

    if(temp.find(se)!=string::npos){return -(300+temp.find(se));};
    for(int i=0;i<strlen(s);i++){
        if(s[i]==s[i+1] && s[i]==s[i+2]){return -(400+i);break;}
    }
    
    bool specialChar=false;
    for(int i=0;i<strlen(s);i++){
        if( s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!'){specialChar=true;break;};
        
    }
    if(!specialChar){return -5;}
    for(int i=0;i<strlen(s);i++){
        if(!( 'A'<= s[i] && s[i] <= 'Z' ) && !('a'<=s[i] && s[i]<='z') && !('0'<=s[i] && s[i]<='9')
            && !( s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!')){ return i;
        }
    }
    return -10;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int countMax=0;
    int lengthMax=0;
    const char* correctpwd = nullptr;
    for(int i=0;i<num_pwds;i++){
        int counttmp=0;
        int lengthtmp=strlen(arr_pwds[i]);
        for(int j=0;j<num_pwds;j++){
            if(strcmp(arr_pwds[j],arr_pwds[i])==0){counttmp++;}
        }
        if(counttmp>countMax|| (counttmp==countMax && lengthtmp>lengthMax)){
            correctpwd=arr_pwds[i];
            countMax=counttmp;
            lengthMax=lengthtmp;
        }
    }
    for(int i=0;i<num_pwds;i++){
        if(strcmp(arr_pwds[i],correctpwd)==0){
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
