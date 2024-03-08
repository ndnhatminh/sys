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

int resetHP(int & HP){
    if (HP<0){
        HP=0;
    }else if(HP>666){
        HP=666;
    }else{
        HP=HP;
    }
    return HP;
}

int resetEXP(int & EXP){
    if (EXP<0){
        EXP=0;
    }else if(EXP>600){
        EXP=600;
    }else{
        EXP=EXP;
    }
    return EXP;
}

int resetM(int & M){
    if (M<0){
        M=0;
    }else if(M>3000){
        M=3000;
    }else{
        M=M;
    }
    return M;
}

// int checkRangeE(int E){
//     if (E<0 || E>99){
//         return -99;
//     }
// }

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    //Case 1
    if (E1<0 || E1>99){
        return -99;
    }
    resetEXP(EXP1);
    resetEXP(EXP2);
    if (E1>=0 && E1<=3){
        if (E1==0){
            EXP2=ceil(EXP2+29);
            resetEXP(EXP2);
            
        }else if (E1==1){
            EXP2=ceil(EXP2+45);
            resetEXP(EXP2);
            
        }else if (E1==2){
            EXP2=ceil(EXP2+75);
            resetEXP(EXP2);
            
        }else if (E1==3){
            EXP2=ceil(EXP2+29+45+75);
            resetEXP(EXP2);
        }
    
        int D;
        D = E1*3 + EXP1*7;
        if (D%2==0){
            EXP1=ceil(EXP1+(float)(D/200.0));
            resetEXP(EXP1);
            
        }else{
            EXP1=ceil(EXP1-(float)(D/100.0));
            resetEXP(EXP1);
        }
    }else if (E1>=4 && E1<=99){
    // Case 2    
        if (E1>=4 && E1<=19){
            EXP2=EXP2 + ceil((float)(E1/4.00)) + 19;
            resetEXP(EXP2);
            
        }else if (E1>=20 && E1<=49){
            EXP2=EXP2 + ceil((float)(E1/9.00)) + 21;
            resetEXP(EXP2);
            
        }else if (E1>=50 && E1<=65){
            EXP2=EXP2 + ceil((float)(E1/16.00)) + 17;
            resetEXP(EXP2);
            
        }else if (E1>=66 && E1<=79){
            EXP2=EXP2 + ceil((float)(E1/4.00)) + 19;
            resetEXP(EXP2);
            
            if (EXP2>200){
                EXP2=EXP2 + ceil((float)(E1/9.00)) + 21;
                resetEXP(EXP2);
            }
        }else if (E1>=80 && E1<=99){
            EXP2=EXP2 + ceil((float)(E1/4.00)) + 19;
            resetEXP(EXP2);
            
            EXP2=EXP2 + ceil((float)(E1/9.00)) + 21;
            resetEXP(EXP2);
            
            if (EXP2>400){
                EXP2=EXP2 + ceil((float)(E1/16.00)) + 17;
                resetEXP(EXP2);
                
                EXP2=ceil((float)(1.15*EXP2));
                resetEXP(EXP2);
            }
        }
        EXP1=ceil(EXP1-E1);
        resetEXP(EXP1);
    }

    return EXP1 + EXP2;
}

// Task 2
int SquareNumber(int n){
    int i=sqrt(n);
    return (i*i);
}
int countNum(int n){
    int count=0;
    while (n!=0){
        n/=10;
        count++;
    }
    return count;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99){
        return -99;
    }
    resetHP(HP1);
    resetEXP(EXP1);
    resetM(M1);
    
    //1
    double P1;
    int larger1=EXP1, smaller1=EXP1, S1;
    while (SquareNumber(larger1)!=larger1){
        larger1++;
    }
    while (SquareNumber(smaller1)!=smaller1){
        smaller1--;
    }
    int i1=abs(EXP1-larger1), j1=abs(EXP1-smaller1);
    if (i1==j1){
        S1=EXP1;
    }else if (i1<j1){
        S1=larger1;
    }else{
        S1=smaller1;
    }
    if (EXP1>=S1){
        P1=100/100;
    }else{
        P1=((EXP1/S1)*1.00+80)/123;
    }
    
    //2
    int spend=0;
    float N=M1/2;
    if (E2%2!=0){
        while (spend<=N){
            if (HP1<200){
                HP1=ceil((float)(1.3*HP1));
                resetHP(HP1);
                M1=ceil((float)(M1-150));
                resetM(M1);
                spend+=150;
            }else{
                HP1=ceil((float)(1.1*HP1));
                resetHP(HP1);
                M1=ceil((float)(M1-70));
                resetM(M1);
                spend+=70;
            }
            if (spend>N){
                break;
            }
            
            if (EXP1<400){
                M1=ceil((float)(M1-200));
                resetM(M1);
                spend+=200;
            }else{
                M1=ceil((float)(M1-120));
                resetM(M1);
                spend+=120;
            }
            EXP1=ceil((float)(1.13*EXP1));
            resetEXP(EXP1);
            if (spend>N){
                break;
            }
            
            if (EXP1<300){
                M1=ceil((float)(M1-100));
                resetM(M1);
                spend+=100;
            }else{
                M1=ceil((float)(M1-120));
                resetM(M1);
                spend+=120;
            }
            EXP1=ceil((float)(0.9*EXP1));
            resetEXP(EXP1);
            
            if (spend>N){
                break;
            }
        }
        HP1=ceil((float)(0.83*HP1));
        resetHP(HP1);
        EXP1=ceil((float)(1.17*EXP1));
        resetEXP(EXP1);
    }else if (E2%2==0){
        if (HP1<200){
            HP1=ceil((float)(1.3*HP1));
            resetHP(HP1);
            M1=ceil((float)(M1-150));
            resetM(M1);
            spend+=150;
        }else{
            HP1=ceil((float)(1.1*HP1));
            resetHP(HP1);
            M1=ceil((float)(M1-70));
            resetM(M1);
            spend+=70;
        }
        
        if (M1!=0){
            if (EXP1<400){
                M1=ceil((float)(M1-200));
                resetM(M1);
                spend+=200;
            }else{
                M1=ceil((float)(M1-120));
                resetM(M1);
                spend+=120;
            }
            EXP1=ceil((float)(1.13*EXP1));
            resetEXP(EXP1);
        }
        
        if (M1!=0){
            if (EXP1<300){
                M1=ceil((float)(M1-100));
                resetM(M1);
                spend+=100;
            }else{
                M1=ceil((float)(M1-120));
                resetM(M1);
                spend+=120;
            }
            EXP1=ceil((float)(0.9*EXP1));
            resetEXP(EXP1);
        }
        
        HP1=ceil((float)(0.83*HP1));
        resetHP(HP1);
        EXP1=ceil((float)(1.17*EXP1));
        resetEXP(EXP1);
    }
    double P2;
    int larger2=EXP1, smaller2=EXP1, S2;
    while (SquareNumber(larger2)!=larger2){
        larger2++;
    }
    while (SquareNumber(smaller2)!=smaller2){
        smaller2--;
    }
    int i2=abs(EXP1-larger2), j2=abs(EXP1-smaller2);
    if (i2==j2){
        S2=EXP1;
    }else if (i2<j2){
        S2=larger2;
    }else{
        S2=smaller2;
    }
    if (EXP1>=S2){
        P2=100/100;
    }else{
        P2=((EXP1/S2)*1.00+80)/123;
    }
    
    //3
    const double P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i, sum=0;
    switch (countNum(E2)){
        case 1:
        i=E2;

        case 2:
        sum=E2/10 + E2%10;
        i=sum%10;
    }
    double P3=P[i]/100;
    double Pa=(P1+P2+P3)/3;
    if (P1==100/100 && P2==100/100 && P3==100/100){
        EXP1=ceil((float)(0.75*EXP1));
        resetEXP(EXP1);
    }else{
        if (Pa<0.5){
            HP1=ceil((float)(0.85*HP1));
            resetHP(HP1);
            EXP1=ceil((float)(1.15*EXP1));
            resetEXP(EXP1);
        }else{
            HP1=ceil((float)(0.9*HP1));
            resetHP(HP1);
            EXP1=ceil((float)(1.2*EXP1));
            resetEXP(EXP1);
        }
    }
    resetHP(HP1);
    resetEXP(EXP1);
    resetM(M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int sumNum(int n){
    int sum=0;
    begin:;
    while (n!=0){
        sum=sum+(n%10);
        n/=10;
    }
    if (countNum(sum)!=1){
        n=sum;
        sum=0;
        goto begin;
    }
    return sum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99){
        return -99;
    }
    int map[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            map[i][j]=((E3*j) + (i*2)) * (i-j);
        }
    }
    int countl=0, counts=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (map[i][j]>(E3*2)){
                countl++;
            }else{
                countl=countl;
            }
            if (map[i][j]<(-E3)){
                counts++;
            }else{
                counts=counts;
            }
        }
    }
    int imain=sumNum(countl);
    int jmain=sumNum(counts);
    int taxi=map[imain][jmain];

    int max=map[imain][jmain];
    int j=jmain, i=imain;
    
    for (int i=imain; i>=0; i--){
        if (map[i][j]>=max){
            max=map[i][j];
        }
        if (j==0){
            break;
        }
        j--;
    }
    i=imain;
    j=jmain;
    
    for (int i=imain; i<=9; i++){
        if (map[i][j]>=max){
            max=map[i][j];
        }
        if (j==9){
            break;
        }
        j++;
    }
    i=imain;
    j=jmain;
    
    for (int i=imain; i>=0; i--){
        if (map[i][j]>=max){
            max=map[i][j];
        }
        if (j==9){
            break;
        }
        j++;
    }
    i=imain;
    j=jmain;
    
    for (int i=imain; i<=9; i++){
        if (map[i][j]>=max){
            max=map[i][j];
        }
        if (j==0){
            break;
        }
        j--;
    }

    int score=abs(max);

    if (score>=abs(taxi)){
        EXP1=ceil((float)(1.12*EXP1));
        EXP2=ceil((float)(1.12*EXP2));
        resetEXP(EXP1);
        resetEXP(EXP2);
        
        HP1=ceil((float)(1.1*HP1));
        HP2=ceil((float)(1.1*HP2));
        resetHP(HP1);
        resetHP(HP2);
        
        return max; 
    }else{
        EXP1=ceil((float)(0.88*EXP1));
        EXP2=ceil((float)(0.88*EXP2));
        resetEXP(EXP1);
        resetEXP(EXP2);
        
        HP1=ceil((float)(0.9*HP1));
        HP2=ceil((float)(0.9*HP2));
        resetHP(HP1);
        resetHP(HP2);
        
        return taxi;
    }

    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string spass=string(s);
    string mail=string(email);
    string se=mail.substr(0, mail.find("@"));
    if (spass.length()<8){
        return -1;
    }
    if (spass.length()>20){
        return -2;
    }
    if (spass.find(se)!=string::npos){
        int sei=spass.find(se);
        return -(300+sei);
    }
    for (int i=0; i<=spass.length()-3; i++){
        if (spass[i]==spass[i+1] && spass[i+1]==spass[i+2]){
            int sci=i;
            return -(400+sci);
        }
    }
    if (spass.find("@")==string::npos && spass.find("#")==string::npos && spass.find("%")==string::npos && spass.find("$")==string::npos && spass.find("!")==string::npos){
        return -5;
    }
    for (int i=0; i<=spass.length()-1; i++){
        if ((spass[i]<'0' || spass[i]>'9') && (spass[i]<'A' || spass[i]>'Z') && (spass[i]<'a' || spass[i]>'z') && spass[i]!='@' && spass[i]!='#' && spass[i]!='%' && spass[i]!='$' && spass[i]!='!'){
            return i;
        }
    }
    return -10;

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pass[num_pwds];
    for (int i=0; i<num_pwds; i++){
        pass[i]=arr_pwds[i];
    }
    
    int count=0, arr_count[num_pwds];
    for (int i=0; i<num_pwds; i++){
        for (int j=0; j<=num_pwds; j++){
            if (pass[i]==pass[j]){
                count++;
            }
        }
        arr_count[i]=count;
        count=0;
    }
    
    int maxloop=0, position=0;
    for (int i=num_pwds-1; i>=0; i--){
        if (arr_count[i]>=maxloop){
            maxloop=arr_count[i];
            position=i;
        }
    }
    
    int length[num_pwds];
    for (int i=0; i<num_pwds; i++){
        length[i]=pass[i].length();
    }
    
    int maxlength=0;
    for (int i=num_pwds-1; i>=0; i--){
        if (arr_count[i]==maxloop && length[i]>=maxlength){
            maxlength=length[i];
            position=i;
        }
    }
    return position;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////