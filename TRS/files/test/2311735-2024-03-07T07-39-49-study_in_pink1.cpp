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
int lamtron(double n){
    int tmp = n;
    if(abs(n-tmp)<1e-6)
        return tmp;
    else
        return ceil(n);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99)
        return -99;
    if(exp1<0)
        exp1 = 0;
    else if(exp1 > 600)
        exp1 = 600;
    if(exp2<0)
        exp2 = 0;
    else if(exp2>600)
        exp2 = 600;
    if(e1>=0 && e1<=3){
        if(e1==0){
            exp2 = exp2+29>600 ? 600 : exp2+29;
        }else if(e1==1){
            exp2 = exp2+45>600 ? 600 : exp2+45;
        }else if(e1==2){
            exp2 = exp2+75>600 ? 600 : exp2+75;
        }else{
            exp2 = exp2+149>600 ? 600 : exp2+149;
        }
        int tmp = e1*3 + exp1*7;
        if(!(tmp&1)){
            exp1 = lamtron(exp1*1.0 + (tmp*1.0/200));
        }else{
            exp1 = lamtron(exp1*1.0 - (tmp*1.0/100));
        }
    }else{
        if(e1>=4 && e1<=19){
            exp2 = lamtron(exp2*1.0 + (e1*1.0/4 + 19));
            if(exp2>600)
                exp2 = 600;
        }else if(e1>=20 && e1<=49){
            exp2 = lamtron(exp2*1.0 + (e1*1.0/9 + 21));
            if(exp2>600)
                exp2 = 600;
        }else if(e1>=50 && e1<=65){
            exp2 = lamtron(exp2*1.0 + (e1*1.0/16 + 17));
            if(exp2>600)
                exp2 = 600;
        }else if(e1>=66 && e1<=79){
            exp2 = lamtron(exp2*1.0 + (e1*1.0/4 + 19));
            if(exp2>200){
                exp2 = lamtron(exp2*1.0 + (e1*1.0/9 + 21));
            }
            if(exp2>600)
                exp2 = 600;
        }else if(e1>=80 && e1<=99){
            exp2 = lamtron(exp2*1.0 + (e1*1.0/4 + 19));
            exp2 = lamtron(exp2*1.0 + (e1*1.0/9 + 21));
            if(exp2>400){
                exp2 = lamtron(exp2*1.0 + (e1*1.0/16 + 17));
                exp2 = lamtron(1.15*exp2);
            }
            if(exp2>600)
                exp2 = 600;
        }
        exp1 = exp1-e1<0 ?  0:exp1-e1;
    }
    if(exp1<0)
        exp1 = 0;
    else if(exp1 > 600)
        exp1 = 600;
    if(exp2<0)
        exp2 = 0;
    else if(exp2>600)
        exp2 = 600;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99)
        return -99;
    if(HP1>666)
        HP1=666;
    else if(HP1<0)
        HP1 = 0;
    if(EXP1<0)
        EXP1 = 0;
    else if(EXP1 > 600)
        EXP1 = 600;
    if(M1 < 0)
        M1 = 0;
    else if(M1>3000)
        M1 = 3000;
    double p1,p2,p3;
    {
        int less =0, greater=0;
        less = pow(floor(sqrt(EXP1)*1.0),2);
        greater = pow(lamtron(sqrt(EXP1)*1.0),2);
        if(abs(EXP1-less)<= abs(EXP1-greater)){
            p1 = 1.000;
        }else{
            p1 = ((EXP1*1.0)/greater + 80)/123; 
        }
    }
    {
        
        if(!(E2&1)){
            bool flag = true;
            for(int i = 1 ; i <=3 && flag ;i++){
                if(i==1){//Case i == 1
                    if(HP1<200){
                        HP1 = lamtron(1.3*HP1);
                        M1-=150;
                        if(M1<=0){
                            M1=0;
                            flag = false;
                        }
                    }else{
                        HP1 = lamtron(1.1*HP1);
                        M1-=70;
                        if(M1<=0){
                            M1=0;
                            flag = false;
                        }
                    }
                    if(HP1>666)
                        HP1=666;
                }
                if(i==2){// Case i==2
                    if(EXP1<400){
                        M1-=200;
                        if(M1<0){
                            M1=0;
                            flag = false;
                        }
                    }else{
                        M1-=120;
                        if(M1<0){
                            M1=0;
                            flag = false;
                        }
                    }
                    EXP1=lamtron(1.13*EXP1);
                    if(EXP1>600)
                        EXP1 = 600;
                }
                if(i==3){ //Case i ==3
                    if(EXP1<300){
                        M1-=100;
                    }else{
                        M1-=120;
                    }
                    EXP1=lamtron(0.9*EXP1);
                    if(M1<0)
                        M1 = 0;
                }
            }
            HP1 = lamtron(0.83*HP1);
            EXP1 = lamtron(1.17*EXP1);
        }else{
            double check = (0.5*M1);
            double curr = 0;
            int i  = 1;
            while(curr <= check){
                if(i==1){//Case i == 1
                    if(HP1<200){
                        HP1 = lamtron(1.3*HP1);
                        M1-=150;
                        curr+=150;
                        if(M1<=0){
                            M1=0;
                        }
                    }else{
                        HP1 = lamtron(1.1*HP1);
                        M1-=70;
                        curr+=70;
                        if(M1<=0){
                            M1=0;
                        }
                    }
                    if(HP1>666)
                        HP1=666;
                }
                if(i==2){// Case i==2
                    if(EXP1<400){
                        M1-=200;
                        curr+=200;
                        if(M1<0){
                            M1=0;
                        }
                    }else{
                        M1-=120;
                        curr+=120;
                        if(M1<0){
                            M1=0;
                        }
                    }
                    EXP1=lamtron(1.13*EXP1);
                    if(EXP1>600)
                        EXP1 = 600;
                }
                if(i==3){ //Case i ==3
                    if(EXP1<300){
                        M1-=100;
                        curr+=100;
                    }else{
                        M1-=120;
                        curr+=120;
                    }
                    EXP1=lamtron(0.9*EXP1);
                    if(M1<0)
                        M1 = 0;
                }
                i==3 ? i = 1 : i++;
            }
            HP1 = lamtron(0.83*HP1);
            EXP1 = lamtron(1.17*EXP1);
        }
        if(EXP1>600)
            EXP1 = 600;
        int less =0, greater=0;
        less = pow(floor(sqrt(EXP1)*1.0),2);
        greater = pow(lamtron(sqrt(EXP1)*1.0),2);
        if(abs(EXP1-less)<= abs(EXP1-greater)){
            p2 = 1.000;
        }else{
            p2 = ((EXP1*1.0)/greater + 80)/123; 
        }
    }
    {
        int arr[] = {32, 47 , 28 , 79, 100, 50, 22, 83, 64, 11};
        if(E2 < 10){
            p3 = arr[E2]*1.0/100;
        }else if(E2>=10 && E2<=99){
            int i = E2%10 + (E2/10);
            p3 = arr[i%10]*1.0/100;
        }
    }
    if(p1==p2 && p1==p3 && abs(p1-1.000)<1e-5){
        EXP1 = lamtron(0.75*EXP1);
    }else{
        double p = (p1 + p2 + p3)/3;
        if(p<0.500){
            HP1 = lamtron(0.85*HP1);
            EXP1 = lamtron(EXP1*1.15);
        }else{
            HP1 = lamtron(0.9*HP1);
            EXP1 = lamtron(1.2*EXP1);
        }
    }
    if(EXP1>600)
        EXP1 = 600;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99)
        return -99;
    if(EXP1>600)
        EXP1=600;
    if(EXP2>600)
        EXP2=600;
    if(HP1>666)
        HP1=666;
    if(HP2>666)
        HP2=666;
    int pointtaxi[10][10] = {0};
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10; j++){
            pointtaxi[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    int tmp1 = E3*2;
    int ct1 =0, ct2 = 8;
    for(int i = 0 ; i < 10; i++){
        for (int j = 0 ; j < 10 ;j++){
            if(pointtaxi[i][j]>tmp1)
                ct1++;
        }
    }
    while(ct1>=10){
        ct1 = ct1%10 + ct1/10;
    }
    int currmax = INT_MIN;
    if(ct1<=ct2){
        int tmp = ct1 + ct2;
        for(int k = 0 ; k < 10 ; k++){
            if(tmp-k<=9 && tmp-k>=0){
                currmax = max(currmax ,pointtaxi[k][tmp-k]);
            }
        }
    }else{
        int tmp1 = ct1 + ct2;
        for(int k = 0 ; k < 10 ; k++){
            if(tmp1-k<=9 && tmp1-k>=0){
                currmax = max(currmax ,pointtaxi[k][tmp1-k]);
            }
        }
        int tmp2 = ct1-ct2;
        for(int k = 0 ; k < 10 ; k++){
            if(tmp2 + k <=9 && tmp2 - k <=0){
                currmax = max(currmax, pointtaxi[k][tmp2+k]);
            }
        }
    }
    if(abs(pointtaxi[ct1][ct2])<=currmax || E3==0){
        EXP1 = lamtron(1.12*EXP1);
        EXP2 = lamtron(1.12*EXP2);
        HP1 = lamtron(1.1*HP1);
        HP2 = lamtron(1.1*HP2);
        if(EXP1>600)
            EXP1=600;
        if(EXP2>600)
            EXP2=600;
        if(HP1>666)
            HP1=666;
        if(HP2>666)
            HP2=666;
        return E3==0 ? 0 : currmax;
    }else{
        EXP1 = lamtron(0.88*EXP1);
        EXP2 = lamtron(0.88*EXP2);
        HP1 = lamtron(0.9*HP1);
        HP2 = lamtron(0.9*HP2);
        if(EXP1>600)
            EXP1=600;
        if(EXP2>600)
            EXP2=600;
        if(HP1>666)
            HP1=666;
        if(HP2>666)
            HP2=666;
        return pointtaxi[ct1][ct2];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int len = strlen(s);
    if(len<8)
        return -1;
    else if(len>20)
        return -2;
    string se ="";
    for (int i = 0 ; i < strlen(email) ;i++){
        if(email[i]=='@')
            break;
        se+=email[i];
    }
    int tmp = se.length();
    if(tmp==0)
        return -300;
    int idx = -1;
    bool lientiep = false;
    bool kytudacbiet = false;
    int kytulientiep = -1;
    int firstwrong = -1;
    for(int i = 0 ; i < len ;i++){
        if(s[i]==se[0] && idx==-1){
            bool overlap = false;
            for (int j = 0 ; j < tmp ;j++){
                if(s[i+j]!=se[j]){
                    overlap = true;
                    break;
                }
            }
            if(!overlap){
                idx = i;
            }
        }
        if(s[i]>=48 && s[i]<=57 || s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!' || ((s[i]-'a')>=0 && (s[i]-'a'<26)) || ((s[i]-'A')>=0 && (s[i]-'A'<26))){}
        else if(firstwrong==-1){
            firstwrong=i;
        }
        if( s[i]==s[i+1] &&s[i]==s[i+2] && !lientiep){
            lientiep = true;
            kytulientiep = i;
        }
        if(s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!')
            kytudacbiet=true;
    }
    if(idx!=-1)
        return -(300+idx);
    else if(lientiep)
        return -(400+kytulientiep);
    else if(!kytudacbiet)
        return -5;
    else if(firstwrong != -1)
        return firstwrong;
    else
        return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int tmp = num_pwds;
    bool check[tmp];
    memset(check, false, sizeof(bool)*tmp);
    int arr[tmp];
    memset(arr, -1, sizeof(int)*tmp);
    for(int i = 0 ; i < num_pwds ;i++){
        if(check[i])
            continue;
        int res = 1;
        for(int j = i+1; j<num_pwds;j++){
            if(strcmp(arr_pwds[i],arr_pwds[j])==0){
                res++;
                check[j]=true;
            }
        }
        arr[i]=res;
    }
    int currmax = 0;
    int maxind = 0;
    int maxlen = 0;
    for(int i = 0 ; i < num_pwds ;i++){
        if(arr[i]>currmax){
            currmax=arr[i];
            maxind=i;
            maxlen=strlen(arr_pwds[i]);
        }else if(arr[i]==currmax){
            if(strlen(arr_pwds[i]) > maxlen){
                maxlen = strlen(arr_pwds[i]);
                maxind = i;
            }
        }
    }
    return maxind;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////