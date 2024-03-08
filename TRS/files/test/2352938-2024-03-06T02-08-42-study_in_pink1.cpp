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

void checkHP(int &hp){
    if (hp>666) hp=666;
    else if (hp<0) hp=0;
}

void checkEXP(int &exp){
    if (exp>600) exp=600;
    else if(exp<0) exp=0;
}

void checkM(int &m){
    if (m>3000) m=3000;
    else if (m<0) m=0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if (e1<0 || e1>99) return -99;

    checkEXP(exp1);
    checkEXP(exp2);

    if (e1==0)
        exp2 += 29;
    else if(e1==1)
        exp2 += 45;
    else if(e1==2)
        exp2 += 75;
    else if (e1==3)
        exp2 += (75+45+29);
    else if ((4<=e1) && (e1<=19))
        exp2 += ceil(float(e1)/4 + 19);
    else if ((20<=e1) && (e1<=49))
        exp2 += ceil(float(e1)/9 + 21);
    else if ((50<=e1) && (e1<=65))
        exp2 += ceil(float(e1)/16 + 17);
    else if ((66<=e1) && (e1<=79)){
        exp2 += ceil(float(e1)/4 + 19);
        if (exp2>200)
            exp2 += ceil(float(e1)/9 + 21);
    }
    else if ((80<=e1) && (e1<=99)){
        exp2 += ceil(float(e1)/4 + 19);
        exp2 += ceil(float(e1)/9 + 21);
        if (exp2>400){
            exp2 += ceil(float(e1)/16 + 17);
            exp2 += ceil(float(exp2)*0.15);
        }    
    }
    
    if (0<=e1 && e1<=3){    
    int D;
    D=e1*3 + exp1*7;
    if (D%2==0)
        exp1 = ceil(exp1 + (float(D)/200));
    else
        exp1 = ceil(exp1 - (float(D)/100));
    }
    
    checkEXP(exp1);
    checkEXP(exp2);
    
    if (4<=e1 && e1<=99)
    exp1 -= e1;

    checkEXP(exp1);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    if (E2<0 || E2>99) return -99;

    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);

    float P1, P2, P3;
    float S;
    if (abs(pow(ceil(sqrt(EXP1)),2)-EXP1) <= abs(pow(int(sqrt(EXP1)),2)-EXP1)) S = pow(ceil(sqrt(EXP1)),2);
    else S = pow(int(sqrt(EXP1)),2);

    if (EXP1 >= S) P1 = 1;
    else P1 = (float(EXP1)/S+80)/123;

    float inM1 = M1;
    float m = 0;

    Loop:
    
    if (E2%2!=0 && m>50*inM1/100 || M1==0) goto Next;

    if (HP1<200){
        HP1 = ceil(130*float(HP1)/100);
        M1 -= 150;
        m += 150;
    } else {
        HP1 = ceil(110*float(HP1)/100);
        M1 -= 70;
        m += 70;
    }

    checkHP(HP1);
    checkM(M1);

    if (E2%2!=0 && m>50*inM1/100 || M1==0) goto Next;

    if (EXP1<400){
        M1 -= 200;
        m += 200;
        EXP1 = ceil(113*float(EXP1)/100);
    } else {
        M1 -= 120;
        m += 120;
        EXP1 = ceil(113*float(EXP1)/100);
    }

    checkEXP(EXP1);
    checkM(M1);

    if (E2%2!=0 && m>50*inM1/100 || M1==0) goto Next;
    
    if(EXP1<300){
        M1 -= 100;
        m += 100;
        EXP1 = ceil(90*float(EXP1)/100);
    } else {
        M1 -= 120;
        m += 120;
        EXP1 = ceil(90*float(EXP1)/100);
    }

    checkEXP(EXP1);
    checkM(M1);

    if (E2%2!=0 && m<=50*inM1/100) goto Loop;

    Next:

    HP1 = ceil(83*float(HP1)/100);
    EXP1 = ceil(117*float(EXP1)/100);

    checkHP(HP1);
    checkEXP(EXP1);

    if (abs(pow(ceil(sqrt(EXP1)),2)-EXP1) <= abs(pow(int(sqrt(EXP1)),2)-EXP1)) S = pow(ceil(sqrt(EXP1)),2);
    else S = pow(int(sqrt(EXP1)),2);

    if (EXP1 >= S) P2 = 1;
    else P2 = (float(EXP1)/S+80)/123;

    int Pi[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) P3 = float(Pi[E2])/100;
    else P3 = float(Pi[(E2/10+E2%10)%10])/100;

    float P;

    if ((int(P1+P2+P3))==3){
        P = P1+P2+P3;
        EXP1 = ceil(75*float(EXP1)/100);
    } else {
        P = (P1+P2+P3)/3;
        if (P<0.5){
            HP1 = ceil(85*float(HP1)/100);
            EXP1 = ceil(115*float(EXP1)/100);
        } else {
            HP1 = ceil(90*float(HP1)/100);
            EXP1 = ceil(120*float(EXP1)/100);
        }
    }

    checkHP(HP1);
    checkEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99) return -99;

    checkHP(HP1);
    checkEXP(EXP1);
    checkHP(HP2);
    checkEXP(EXP2);

    int arr[10][10]={0};
    int pos=0, neg=0;
    int max=0;
    int x,y;

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            arr[i][j] = ((E3*j)+(i*2))*(i-j);
            if (arr[i][j] > E3*2) pos++;
            else if (arr[i][j] < -E3) neg++;
        }
    }

    while (pos>=10) pos = pos/10 + pos%10;
    while (neg>=10) neg = neg/10 + neg%10;

    x=pos;
    y=neg; 
    while (x<10 && y<10){
        if (arr[x][y]>max) max = arr[x][y];
        x++;
        y++;
    }

    x=pos;
    y=neg; 
    while (x>0 && y>0){
        if (arr[x][y]>max) max = arr[x][y];
        x--;
        y--;
    }
    
    x=pos;
    y=neg; 
    while (x<10 && y>0){
        if (arr[x][y]>max) max = arr[x][y];
        x++;
        y--;
    }

    x=pos;
    y=neg; 
    while (x>0 && y<10){
        if (arr[x][y]>max) max = arr[x][y];
        x--;
        y++;
    }

    if (abs(arr[pos][neg]) > max){
        EXP1 = ceil(88*float(EXP1)/100);
        EXP2 = ceil(88*float(EXP2)/100);
        HP1 = ceil(90*float(HP1)/100);
        HP2 = ceil(90*float(HP2)/100);
        checkHP(HP1);
        checkEXP(EXP1);
        checkHP(HP2);
        checkEXP(EXP2);
        return arr[pos][neg];
    } else {
        EXP1 = ceil(112*float(EXP1)/100);
        EXP2 = ceil(112*float(EXP2)/100);
        HP1 = ceil(110*float(HP1)/100);
        HP2 = ceil(110*float(HP2)/100);
        checkHP(HP1);
        checkEXP(EXP1);
        checkHP(HP2);
        checkEXP(EXP2);
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    string S(s);
    string stremail(email);
    int finda = stremail.find('@');
    string se=stremail.substr(0,finda);

    if (S.length()<8) return -1;

    if (S.length()>20) return -2;

    int find = S.find(se);

    if (find!=-1) return -(300+find);

    for (int i=0; i<S.length()-2; i++){
        if (s[i]==s[i+1] && s[i]==s[i+2]) return -(400+i);
    }

    if (S.find('@')==-1 && S.find('#')==-1 && S.find('%')==-1 && S.find('$')==-1 && S.find('!')==-1) return -5;

     for (int i=0; i<S.length(); i++){
        if (isalnum(S[i])==0 && S[i]!='#' && S[i]!='%' && S[i]!='$' && S[i]!='!' && S[i]!='@') return i;
    }    

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max=0;
    int count=0;
    int firsti=0;
    int length=0;
    for (int i=0; i<num_pwds; i++){
        count=0;
        string s(arr_pwds[i]);
        for (int j=0; j<num_pwds; j++){
            string b(arr_pwds[j]);
            if (s==b) count++;
        }
        if (count>max){
            max = count;
            length = s.length();
            firsti = i;
        } else if (count==max) {
            if (s.length()>length){
                length = s.length();
                firsti = i;
            }
        }
        }
    return firsti;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////