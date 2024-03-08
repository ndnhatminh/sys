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
int checkexp(int exp){
    if(exp<0){
        exp=0;
    }
    else if(exp>600){
        exp=600;
    }
    return exp;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99){
        return -99;
    }
    else{
    if(e1>=0 && e1<=3){
        switch(e1){
            case 0:
                exp2+=29;
                break;
            case 1:
                exp2+=45;
                break;
            case 2: 
                exp2+=75;
                break;
            case 3:
                exp2+=149;
                break;
        }
        exp2=checkexp(exp2);
        int D=(e1*3)+(exp1*7);
        exp1=(D%2==0)? exp1+ceil((double)(D/200)): exp1-ceil((double)(D/100));
        exp1=checkexp(exp1);
    }
    else if(e1>=4 && e1<=99){
        if(e1>=4 && e1<=19){
            exp2+=ceil(((double)e1/4)+19);
            exp2=checkexp(exp2);
        }
        else if(e1>=20 && e1<=49){
            exp2+=ceil(((double)e1/9)+21);
            exp2=checkexp(exp2);
        }
        else if(e1>=50 && e1<=65){
            exp2+=ceil(((double)e1/16)+17);
            exp2=checkexp(exp2);
        }
        else if(e1>=66 && e1<=79){
            exp2+=ceil(((double)e1/4)+19);
            exp2=checkexp(exp2);
            exp2=(exp2>200)? exp2+ceil(((double)e1/9)+21): exp2;
            exp2=checkexp(exp2);
        }
        else if(e1>=80 && e1<99){
            exp2+=ceil(((double)e1/4)+19);
            exp2=checkexp(exp2);
            exp2+=ceil(((double)e1/9)+21);
            exp2=checkexp(exp2);
            exp2=(exp2>400)? exp2+ceil(((double)e1/16)+17): exp2;
            exp2=checkexp(exp2);
            exp2=ceil((double)exp2*1.15);
            exp2=checkexp(exp2);
        }
        exp1-=e1;
        exp1=checkexp(exp1);
    }
    return exp1 + exp2;
    }
}

// Task 2
int findnearestsquarenumber(int exp1){
    int num=(int)sqrt(exp1); 
    int squarenum1=num*num;
    int squarenum2=(num+1)*(num+1);
    if(abs(exp1-squarenum1)<abs(exp1-squarenum2)){
        return squarenum1;
    }
    else{
        return squarenum2;
    }
}

int checkhp(int hp){
    if(hp<0){
        hp=0;
    }
    else if(hp>666){
        hp=666;
    }
    return hp;
}

int checkm(int m){
    if(m<0){
        m=0;
    }
    else if(m>3000){
        m=3000;
    }
    return m;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99){
        return -99;
    }
    else{
    int S=findnearestsquarenumber(EXP1);
    double P1=(EXP1>=S)? 100: ((double)(((EXP1/S)+80))/123)*100;
    int m=0, m1=M1;
    if(E2%2==1){
        while(m<(m1*0.5)){
            if(HP1<200){
                HP1=ceil((double)HP1*1.3);
                HP1=checkhp(HP1);
                M1-=150;
                M1=checkm(M1);
                m+=150;
            }
            else{
                HP1=ceil((double)HP1*1.099999);
                HP1=checkhp(HP1);
                M1-=70;
                M1=checkm(M1);
                m+=70;
            }
            if(m>(m1*0.5)){
                break;
            }
            else{
                M1=(EXP1<400)? M1-200: M1-120;
                M1=checkm(M1);
                m=(EXP1<400)? m+200: m+120;
                EXP1=checkexp(ceil((double)EXP1*1.13));
                if(m>(m1*0.5)){
                    break;
                }
                else{
                    M1=(EXP1<300)? M1-100: M1-120;
                    M1=checkm(M1);
                    m=(EXP1<300)? m+100: m+120;
                    EXP1=checkexp(ceil((double)EXP1*0.9));
                }
            }
        }
        HP1=checkhp(ceil((double)HP1*0.83));
        EXP1=checkexp(ceil((double)EXP1*1.17));
    }
    else{
        if(HP1<200){
            HP1=ceil((double)HP1*1.3);
            HP1=checkhp(HP1);
            M1-=150;
            M1=checkm(M1);
        }
        else{
            HP1=ceil((double)HP1*1.099999);
            HP1=checkhp(HP1);
            M1-=70;
            M1=checkm(M1);
        }
        if(M1>0){
            M1=(EXP1<400)? M1-200: M1-120;
            M1=checkm(M1);
            EXP1=checkexp(ceil((double)EXP1*1.13));
            if(M1>0){
                M1=(EXP1<300)? M1-100: M1-120;
                M1=checkm(M1);
                EXP1=checkexp(ceil((double)EXP1*0.9));
                HP1=checkhp(ceil((double)HP1*0.83));
                EXP1=checkexp(ceil((double)EXP1*1.17));
            }
            else{
                HP1=checkhp(ceil((double)HP1*0.83));
                EXP1=checkexp(ceil((double)EXP1*1.17));
            }
        }
        else{
            HP1=checkhp(ceil((double)HP1*0.83));
            EXP1=checkexp(ceil((double)EXP1*1.17));
        }
    }
    int S2=findnearestsquarenumber(EXP1);
    int P2=(EXP1>=S2)? 100: ((double)(((EXP1/S2)+80))/123)*100;
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;
    if(E2>=0 && E2<10){
        P3=P[E2];
    }
    else if(E2>=10){
        int sum=(E2%10)+(E2/10);
        int num=0;
        if(sum>=10){
            num=abs(sum-10);
        }
        else{
            num=sum;
        }
        P3=P[num];
    }
    int averageP;
    if(P1==100 && P2==100 && P3==100){
        EXP1=checkexp(ceil((double)EXP1*0.75));
    }
    else{
        averageP=(P1+P2+P3)/3;
        if(averageP<50){
            HP1=checkhp(ceil((double)HP1*0.85));
            EXP1=checkexp(ceil((double)EXP1*1.15));
        }
        else{
            HP1=checkhp(ceil((double)HP1*0.9));
            EXP1=checkexp(ceil((double)EXP1*1.2));
        }
    }
    return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99){
        return -99;
    }
    else{
        int arr[10][10]={0}, arr1[10][10]={0};
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                arr[i][j]=((E3*j)+(i*2))*(i-j);
            }
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                int maxscore=0;
                for(int k=0; k<10; k++){
                    int leftDiagonal1=(i-k>=0 && j-k>=0)? arr[i-k][j-k]:0;
                    int leftDiagonal2=(i+k<10 && j+k<10)? arr[i+k][j+k]:0;
                    int rightDiagonal1=(i-k>=0 && j+k<10)? arr[i-k][j+k]:0;
                    int rightDiagonal2=(i+k<10 && j-k>=0) ? arr[i+k][j-k]:0;
                    maxscore=(leftDiagonal1>maxscore)? leftDiagonal1: maxscore;
                    maxscore=(leftDiagonal2>maxscore)? leftDiagonal2: maxscore;
                    maxscore=(rightDiagonal1>maxscore)? rightDiagonal1: maxscore;
                    maxscore=(rightDiagonal2>maxscore)? rightDiagonal2: maxscore;
                }
                arr1[i][j]=abs(maxscore);
            }
        }
        int postimes=0, negtimes=0, sum1=0, sum2=0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(arr[i][j]>(E3*2)){
                    postimes++;
                }
                else if(arr[i][j]<(E3*(-1))){
                    negtimes++;
                }
            }
        }
        if(postimes>9){
            sum1=(postimes%10)+(postimes/10);
            if(sum1>9){
                sum1=(sum1%10)+(sum1/10);
            }
        }  
        else{
            sum1=postimes;
        }
        if(negtimes>9){
            sum2=(negtimes%10)+(negtimes/10);
            if(sum2>9){
                sum2=(sum2%10)+(sum2/10);
            }
        }
        else{
            sum2=negtimes;
        }
        int max=0;
        if(abs(arr[sum1][sum2])>abs(arr1[sum1][sum2])){
            HP1=checkhp(ceil((double)HP1*0.899999));
            HP2=checkhp(ceil((double)HP2*0.9));
            EXP1=checkexp(ceil((double)EXP1*0.88));
            EXP2=checkexp(ceil((double)EXP2*0.88));
            max=arr[sum1][sum2];
        }
        else{
            HP1=checkhp(ceil((double)HP1*1.099999));
            HP2=checkhp(ceil((double)HP2*1.1));
            EXP1=checkexp(ceil((double)EXP1*1.12));
            EXP2=checkexp(ceil((double)EXP2*1.12));
            max=arr1[sum1][sum2];
        }
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    const char * first=strchr(email, '@');
    if(first==nullptr || (first!=nullptr && strchr(first+1, '@')!=nullptr) || strlen(email)>99){
        return -99;
    }
    else{
        int pos=first-email;
        int len=strlen(s);
        char * se=new char[pos+1];
        strncpy(se, email, pos);
        se[pos]='\0';
        if(len<8){
            return -1; 
        }
        if(len>20){
            return -2; 
        }
        if(strstr(s, se)!=nullptr){
            return -(300+(strstr(s, se)-s)); 
        }
        for(int i=0; i<len-2; i++){
            if(s[i]==s[i+1] && s[i]==s[i+2]){
                return -(400+i);
            }
        }
        const char* specialChars="@#%$!";
        bool hasSpecialChar=false;
        for(int i=0; i<len; i++){
            if(strchr(specialChars, s[i])!=nullptr){
                hasSpecialChar = true;
                break;
            }
        }
        if(!hasSpecialChar){
            return -5;
        }
        int position=0;
        for(char c:(string)s){
            if(!((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z') || c=='@' || c=='#' || c=='%' || c=='$' || c=='!')){
                return position; 
            }
            else{
                position++;
            }
        }
        return -10;
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxfreq=0, maxlen=0, correctindex=-1, freq[30]={0}, len[30]={0};
    for(int i=0; i<num_pwds;i++){
        const char *pwd=arr_pwds[i];
        int pwdlen=strlen(pwd), pwdindex=-1;
        for(int j=0; j<30; j++){
            if(strcmp(arr_pwds[j], pwd)==0){
                pwdindex=j;
                break;
            }
        }
        if(pwdindex!=-1){
            freq[pwdindex]++;
            len[pwdindex]=pwdlen;
        } 
        else{
            pwdindex=i;
            freq[pwdindex]=1;
            len[pwdindex]=pwdlen;
        }
        if(freq[pwdindex]>maxfreq || (freq[pwdindex]==maxfreq && len[pwdindex]>maxlen)){
            maxfreq=freq[pwdindex];
            maxlen=len[pwdindex];
            correctindex=pwdindex;
        }
    }
    return correctindex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////