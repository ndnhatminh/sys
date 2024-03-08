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
void hp_1(int &HP1){
    if (HP1<0)
    {
        HP1=0;
    }
    else if (HP1>666){
        HP1=666;
    }
    
}
void hp_2(int &HP2){
    if (HP2<0){
        HP2=0;
    }
    else if (HP2>666){
        HP2=666;
    }
    
}
void exp_1(int &EXP1){
    if (EXP1<0)
    {
        EXP1=0;
    }
    else if (EXP1>600){
        EXP1=600;
    }
}
void exp_2(int &EXP2){
    if (EXP2<0)
    {
        EXP2=0;
    }
    else if (EXP2>600){
        EXP2=600;
    }
}
void m_1(int &M1){
    if (M1<0)
    {
        M1=0;
    }
    else if (M1>3000){
        M1=3000;
    }
}
void m_2(int &M2){
    if (M2<0)
    {
        M2=0;
    }
    else if (M2>3000){
        M2=3000;
    }
}
void exp1_(int &exp1){
    if (exp1<0)
    {
        exp1=0;
    }
    else if (exp1>600){
        exp1=600;
    }
}
void exp2_(int &exp2){
    if (exp2<0)
    {
        exp2=0;
    }
    else if (exp2>600){
        exp2=600;
    }}
int finds( int EXP1 ){
    double cp, m,p1,s=0;
    cp=sqrt(EXP1);
    if(ceil(cp)==floor(cp)){
        s=EXP1;
    }
    else {cp=pow(ceil(sqrt(EXP1)),2);
          m=pow(floor(sqrt(EXP1)),2);
    abs(EXP1-cp)<abs(EXP1-m)? s=cp:s=m;
    }
    
    return s;
}

// Task 1

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    if(e1<0 || e1 >99)return -99;
    if (e1==0){
        exp2+=29;
        exp2_(exp2);
    }
    else if (e1==1){
        exp2+=45;
        exp2_(exp2);
    }
    else if (e1==2){
        exp2+=75;
        exp2_(exp2);
    }
    else if (e1==3){
        exp2+=(29+45+75);
        exp2_(exp2);
    }
    if (e1==0 || e1==1 || e1==2 || e1==3){
        D=(e1*3) + (exp1*7);
        if ( D%2==0){
        exp1=ceil((double(exp1)+ double(D)/200));
        exp_1(exp1);
        return exp1+exp2;
    }
    else if (D%2!=0){
        exp1=ceil((double(exp1) - double(D)/100));
    exp_1(exp1);
    return exp1+exp2;
    }
    
    }

    //Case2
    if (4 <= e1 && e1 <= 19){
        exp2+=(ceil(double(e1)/4) + 19);
        exp2_(exp2);
    }
    else if (20 <= e1 && e1 <= 49){
        exp2+=(ceil(double(e1)/9) +21);exp2_(exp2);
    }
    else if (50 <= e1 && e1 <= 65){
        exp2+=(ceil(double(e1)/16) +17);exp2_(exp2);
    }
    else if (66 <= e1 && e1 <= 79){
        exp2+=(ceil(double(e1)/4) +19);exp2_(exp2);
        if(exp2>200){
            exp2+=(ceil(double(e1)/9) + 21);exp2_(exp2);
        }
    }
    else if (80 <= e1 && e1 <= 99){
        exp2+=(ceil(double(e1)/4) + 19);exp2_(exp2);
        exp2+=(ceil(double(e1)/9) +21);exp2_(exp2);
        
        if(exp2>400){
            exp2+=(ceil(double(e1)/16) +17);exp2_(exp2);
            exp2+=ceil(double(exp2)*0.15);exp2_(exp2);
        }}

    exp1-=e1;
    exp1_(exp1);
    return exp1+exp2;
    
}

// Task 2

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double p1,p2,p3,m;
    double s,cp,cd=0;
    int a=0;
    if(E2<0 || E2 >99){return -99;}
    s=finds(EXP1);
    if(EXP1>=s){
        p1=100;
    }
    else if(EXP1<s){
        p1=((((double)EXP1/s)+80)/123)*100;
    } 
    //ROAD 2
    m=0.5*M1;
    //odd
    while (E2%2!=0){
        if(HP1<200){
            HP1+=ceil(HP1*0.3);
            M1-=150;
            cd+=150;
            hp_1(HP1);
            m_1(M1);
        }
        else if(HP1>=200){
            HP1+=ceil(HP1*0.1);
            M1-=70;
            cd+=70;
            hp_1(HP1);
            m_1(M1);
        }
        if(cd>m){
            HP1-=floor(0.17*HP1);
            EXP1+= EXP1*0.17 + 0.999999;;
            hp_1(HP1);
            exp_1(EXP1);
            break;
            }
        if(EXP1<400){
            M1-=200;
            EXP1+=ceil(0.13*EXP1);
            cd+=200;
            exp_1(EXP1);
            m_1(M1);
        }
        else if(EXP1>=400){
            M1-=120;
            EXP1+=ceil(0.13*EXP1);
            cd+=120;
            exp_1(EXP1);
            m_1(M1);
        }
        if(cd>m){
            HP1-=floor(0.17*HP1);
            EXP1+=ceil(0.17*EXP1);
            hp_1(HP1);
            exp_1(EXP1);
            break;
            }
        if(EXP1<300){
            M1-=100;
            EXP1-=floor(0.1*EXP1);
            cd+=100;
            exp_1(EXP1);
            m_1(M1);
        }
        else if(EXP1>=300){
            M1-=120;
            EXP1-=floor(0.1*EXP1);
            cd+=120;
            exp_1(EXP1);
            m_1(M1);
        }
        if(cd>m){
        HP1-=floor(0.17*HP1);
        EXP1+=ceil(0.17*EXP1);
        hp_1(HP1);
        exp_1(EXP1);
            break;
            }
    }
// even
    while(E2%2==0){
        if(HP1<200){
            HP1+=ceil(HP1*0.3);
            M1-=150;
            hp_1(HP1);

        }
        else if(HP1>=200){
            HP1+=ceil(HP1*0.1);
            M1-=70;
            hp_1(HP1);
            }
        if(M1<=0){
                HP1-=floor(0.17*HP1);
                EXP1+=ceil(0.17*EXP1);
                hp_1(HP1);
                exp_1(EXP1);
                m_1(M1);
                break;
            } 
        
        if(EXP1<400){
            M1-=200;
            EXP1+=ceil(0.13*EXP1);
            exp_1(EXP1);
        }
        else if(EXP1>=400){
            M1-=120;
            EXP1+=ceil(0.13*EXP1);
            exp_1(EXP1);
        }
        if(M1<=0){

                HP1-=floor(0.17*HP1);
                EXP1+=ceil(0.17*EXP1);
                hp_1(HP1);
                exp_1(EXP1);
                m_1(M1);
                break;
            }
        if(EXP1<300){
            M1-=100;
            EXP1-=floor(0.1*EXP1);
            exp_1(EXP1);
        }
        else if(EXP1>=300){
            M1-=120;
            EXP1-=floor(0.1*EXP1);
            exp_1(EXP1);
        }
        if(M1<=0){
                HP1-=floor(0.17*HP1);
                EXP1+=ceil(0.17*EXP1);
                hp_1(HP1);
                exp_1(EXP1);
                m_1(M1);
                break;
            }
        if(M1>0){
            HP1-=floor(0.17*HP1);
            EXP1+=ceil(0.17*EXP1);
            hp_1(HP1);
            exp_1(EXP1);
            
        }
        break;

    }
   //P2
    s=finds(EXP1);

    if(EXP1>=s){
        p2=100;
    }
    else if(EXP1<s){
        p2=((((double)EXP1/s)+80)/123)*100;
    } 
    
//  ROAD 3
  
  int i;
  double pi[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2<10 && E2>=0){
        i=E2;
        p3=pi[i];

    }
    else if(E2>=10){
        a+=E2/10;
        a+=E2%10;
        i=a%10;
        p3=pi[i];

    }
    // XET 3 CON DUONG
    double p;
    if( p3==100 && p2==100 && p1==100 ){
        p=100;
        EXP1-=floor(EXP1*0.25);
        hp_1(HP1);
        exp_1(EXP1);
        return HP1 + EXP1 + M1;
    }
    else {
        p=(p1+p2+p3)/3;
        
    }
//p>50
    if(p<50){
        HP1-=floor(0.15*HP1);
        EXP1+=ceil(0.15*EXP1);
        hp_1(HP1);
        exp_1(EXP1);
    }
    else if(p>=50){
        HP1-=floor(0.1*HP1);
        EXP1+=ceil(0.2*EXP1);
        hp_1(HP1);
        exp_1(EXP1);
        
    }
    return HP1 + EXP1 + M1;
}
    

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   if(E3<0 || E3 >99){return -99;}
    int taxi[10][10];
    //row by row
    for (int i=0; i<10;i++){
        for (int j=0; j<10;j++ ){
            taxi[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
int n=0, m=0,a,b;
    for (int i=0; i<10;i++){
        for (int j=0; j<10;j++ ){
            if(taxi[i][j]>(E3*2)){
            n++;}
            if(taxi[i][j]<(-1*E3)){
            m++;
            }
        }
    }
    while (n>=10){
        a=n/10;
        b=n%10;
        n=a+b;
    }
    while (m>=10){
        a=m/10;
        b=m%10;
        m=a+b;}

    int hw=-99999;  
     for(int x=0; x<10;x++){
        for(int y=0; y<10; y++){
            if ((((x+y)==(n+m) || (x-y)==(n-m)) && hw<taxi[x][y])){
                hw=taxi[x][y];
            }
        }
     }
     
     int staxi=abs(taxi[n][m]);
     if(staxi>hw){
        EXP1-=floor(EXP1*0.12);
        HP1-=floor(HP1*0.1);
        EXP2-=floor(EXP2*0.12);
        HP2-=floor(HP2*0.1);
        exp_2(EXP2);
        hp_2(HP2);
        exp_1(EXP1);
        hp_1(HP1);
        return taxi[n][m];
     }
     else if(staxi<=hw){
        EXP1+=ceil(EXP1*0.12);
        HP1+=ceil(HP1*0.1);
        EXP2+=ceil(EXP2*0.12);
        HP2+=ceil(HP2*0.1);
        exp_2(EXP2);
        hp_2(HP2);
        exp_1(EXP1);
        hp_1(HP1);
        return hw;
     }
    return 1;  
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    string S=s;//password
    string sc="@#%$!";
    string te=email;
    int e=te.find('@');
    char sp;
    int count=0;
    string se=te.erase(e,te.length()-e);
    //length
    if (S.length()<8 ){
        return -1;
    }
    else if(S.length()>20){
        return -2;
    }
    //se

    else if (S.find(se)!=string::npos){
            return -(300+S.find(se));
        }
    //2 consecutive characters
    for (int i=0;i<S.length()-2;i++){
        if(S[i]==S[i+1] && S[i]==S[i+2]){
            return -(400+i);
        }
    }
    //special characters
    if(S.find('@')==string::npos && S.find('#')==string::npos && S.find('$')==string::npos && S.find('%')==string::npos
    && S.find('!')==string::npos  ){return -5;}
    
    //remain cases
    for(int i=0; i<S.length();i++){
        if(isalpha(S[i])==0 && isdigit(S[i])==0 && S[i]!='@'&& S[i]!='#'&& S[i]!='%'&& S[i]!='$'&& S[i]!='!' )
        return i;
    }
        return -10;
    }
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max1=0;
    int max2=0;
    string arr_pw[num_pwds];
    int length[num_pwds];
    int pw[num_pwds];
    int count=0;
    for(int i=0; i<num_pwds;i++){
        arr_pw[i]=arr_pwds[i];
    }
    //password length
    for(int i=0; i<num_pwds;i++){
        length[i]=arr_pw[i].length();
    }
    //repeat
    for(int i=0;i<num_pwds;i++){
        count=0;
        for (int j=0; j<num_pwds ; j++){
            if(arr_pw[i]==arr_pw[j]){
                count++;
            }
        
        }
        pw[i]=count;
    }

    for(int i=0;i<num_pwds;i++){
        if(pw[i]>=max1) {max1=pw[i];}
    }
    for(int i=0;i<num_pwds;i++){
        if(pw[i]<max1) { length[i]=0;}
    }
    for(int i=0;i<num_pwds;i++){
        if(length[i]>=max2){
            max2=length[i];
        }}
     for(int i=0;i<num_pwds;i++){
        if(pw[i]==max1&&length[i]==max2){
            return i;
        }
     }
return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////