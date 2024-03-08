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
    if(e1<0 || e1 > 99) return -99;
    else{
        if (exp1>600) exp1 = min(exp1,600);
        else exp1 = max(exp1,0);
        if (exp2>600) exp2 = min(exp2,600);
        else exp2 = max(exp2,0);
        //Truong hop 1
        if (0 <=e1 && e1<=3){
            if (e1==0) exp2+=29;
            else if (e1==1) exp2+=45;
            else if (e1==2) exp2+=75;
            else exp2+=149;
            int D = e1*3 + exp1*7;
            if (D%2 == 0) exp1+=ceil(double(D)/200);
            else exp1-=(D/100);
        }
        //Truong hop 2
        else {
            if (e1<=19) exp2+=ceil(double(e1)/4) + 19;
            else if (e1<=49) exp2+=ceil(double(e1)/9) + 21;
            else if (e1<=65) exp2+=ceil(double(e1)/16) + 17;
            else if (e1<=79) {
                exp2+=ceil(double(e1)/4) + 19;
                if (exp2>200) exp2+=ceil(double(e1)/9) + 21;
            }
            else {
                exp2+=ceil(double(e1)/4) + 19 + ceil(double(e1)/9) + 21;
                if (exp2>400) {exp2+=(ceil(double(e1)/16) + 17);
                exp2+=ceil(0.15*exp2);
                }
            }
            exp1-=e1;
        }
    if (exp1 > 600) exp1 = min(exp1,600);
    else exp1 = max(exp1,0);
    if (exp2 > 600) exp2 = min(exp2,600);
    else exp2 = max(exp2,0);
    return exp1 + exp2;
    }
}
//Task2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double P1, P2, P3;
    if (E2<0 || E2>99) return -99;
    else{
        if (HP1 > 666) HP1 = min(HP1,666);
        else HP1 = max(HP1,0);
        if (EXP1 > 600) EXP1 = min(EXP1,600);
        else EXP1 = max(EXP1,0);
        if (M1 > 3000) M1 = min (M1,3000);
        else M1 = max(M1,0);
        //Con duong 01
        double a1 = round(sqrt(EXP1));
        int S = a1*a1;
        if (EXP1 >=S) P1=1;
        else P1 = (double(EXP1)/S +80)/123;
        //Con duong 02
        if (E2%2==0) {
            while (true){
            if (M1<=0) {M1 = max(M1,0); break;}
            //TH1
            if (HP1 < 200) {
            HP1 = HP1+ ceil(0.3*double(HP1));
            M1 -= 150;
            }
            else {
            HP1=HP1 + ceil(0.1*double(HP1));
            M1-=70;
            }
            if (HP1 > 666) HP1 = min(HP1,666);
            else HP1 = max(HP1,0);
            if (M1<=0) {M1 = max(M1,0); break;}
            //TH2
            if (EXP1 < 400) M1-=200;
            else M1-=120;
            EXP1+=ceil(0.13*double(EXP1));
            if (M1 >3000) M1 = min(M1,3000);
            else M1 = max(M1,0);
            if (EXP1 > 600) EXP1 = min(EXP1,600);
            else EXP1 = max(EXP1,0);
            if (M1<=0)  break;
            
            //TH3
            if (EXP1 <300) M1-=100;
            else M1-=120;
            EXP1=ceil(0.9*double(EXP1));
                if (M1 >3000) M1 = min(M1,3000);
                else M1 = max(M1,0);
                if (EXP1 > 600) EXP1 = min(EXP1,600);
                else EXP1 = max(EXP1,0);
                if (M1<=0)  break;
                break;
            }
            HP1 = ceil(0.83 * double(HP1));
            EXP1 = ceil(1.17 * double(EXP1));
            if (EXP1 > 600) EXP1 = min(EXP1,600);
            else EXP1 = max(EXP1,0);
            if (HP1 > 666) HP1 = min(HP1,666);
            else HP1 = max(HP1,0);
        }
        else {
            int M = M1;
            while(true) {
                if(M1<=0) break;
                //TH1
                if (HP1 < 200) {
                HP1 = ceil(1.3*double(HP1)); 
                M1 -= 150;
                }
                else {
                HP1=HP1 + ceil(0.1*double(HP1));
                M1-=70;
                }
                if (HP1 > 666) HP1 = min(HP1,666);
                else HP1 = max(HP1,0);
                if (M1 >3000) M1 = min(M1,3000);
                else M1 = max(M1,0);
                if ((M-M1) > 0.5*M) break;

                //TH2
                if (EXP1 < 400) M1-=200;
                else M1-=120;
                EXP1+=ceil(0.13*double(EXP1));
                if (EXP1 > 600) EXP1 = min(EXP1,600);
                else EXP1 = max(EXP1,0);
                if (M1 >3000) M1 = min(M1,3000);
                else M1 = max(M1,0); 
                if ((M-M1) > 0.5*M) break;

                //TH3
                if (EXP1 <300) M1-=100;
                else M1-=120;
                EXP1=ceil(0.9*double(EXP1));
                if (EXP1 > 600) EXP1 = min(EXP1,600);
                else EXP1 = max(EXP1,0);
                if (M1 >3000) M1 = min(M1,3000);
                else M1 = max(M1,0);
                if ((M-M1) > 0.5*M) break;
            }
            HP1 = ceil(0.83 * double(HP1));
            EXP1 = ceil(1.17 * double(EXP1));
            if (EXP1 > 600) EXP1 = min(EXP1,600);
            else EXP1 = max(EXP1,0);
            if (HP1 > 666) HP1 = min(HP1,666);
            else HP1 = max(HP1,0);
        }
 
        double a2 = round(sqrt(EXP1));
        int S2 = a2*a2;
        if (EXP1 >=S2) P2=1;
        else P2 = (double(EXP1)/S2 +80)/123; 
        //Con duong 03
    double P[10]={32,47,28,79,100,50,22,83,64,11};
        int hangchuc = E2/10;
        int hangdonvi = E2%10;
        int tong2chuso = hangchuc + hangdonvi;
        int y = tong2chuso%10;
        int i = y;
        double P3 = P[i]/100;
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(0.75 *double(EXP1));
    else if ( (P1+P2+P3)/3 <0.5) {
        HP1=ceil(0.85*double(HP1));
        EXP1=ceil(1.15*double(EXP1));
    }
    else {
        HP1=ceil(0.9*double(HP1));
        EXP1=ceil(1.2*double(EXP1));
    }
    if (EXP1 > 600) EXP1 = min(EXP1,600);
    else EXP1 = max(EXP1,0);
    if (HP1 > 666) HP1 = min(HP1,666);
    else HP1 = max(HP1,0);
    if (M1 >3000) M1 = min(M1,3000);
    else M1 = max(M1,0);
    return HP1 + EXP1 + M1;
    }
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    
    int matrix1[10][10];
    if (E3<0 || E3>99) return -99;
    else {
        if (EXP1 > 600) EXP1 = min(EXP1,600);
        else EXP1 = max(EXP1,0);
        if (HP1 > 666) HP1 = min(HP1,666);
        else HP1 = max(HP1,0);
        if (EXP2 > 600) EXP2 = min(EXP2,600);
        else EXP2 = max(EXP2,0);
        if (HP2 > 666) HP2 = min(HP2,666);
        else HP2 = max(HP2,0);
        int countbigger, countsmaller;
        int matrixTaxi[10][10];
        int meeti =0, meetj =0;
        int maxcross = ((E3 * 9) + (0 * 2)) * (0 - 9);
    for (int i = 0; i < 10; i++) {					
        for (int j = 0; j < 10; j++) {					
            matrixTaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);					
        }					
					
    }
    for (int a = 0; a < 10; a++) {					
        for (int b = 0; b < 10; b++) {					
            int test1 = matrixTaxi[a][b];
            if (test1 > E3*2) meeti +=1;
            else if (test1 < -E3) meetj+=1;
        }					
    }
    if ((meeti > 9 && meeti <100) || (meetj > 9 && meetj <100)) {
        meeti = (meeti%10)+(meeti/10);
        meetj = (meetj%10)+(meetj/10);
        if ((meeti > 9 && meeti <100) || (meetj > 9 && meetj <100)) {
            meeti = (meeti%10)+(meeti/10);
            meetj = (meetj%10)+(meetj/10);
        }
    }
    for (int i = meeti, j = meetj; i <10 && j <10; i++, j++){
        int now = matrixTaxi[i][j];
        maxcross = max(now, maxcross);
    }
    for (int i = meeti, j = meetj; i >=0 && j >=0; i--, j--){
        int now = matrixTaxi[i][j];
        maxcross = max(now, maxcross);
    }
    for (int i = meeti, j = meetj; i >=0 && j <10; i--, j++){
        int now = matrixTaxi[i][j];
        maxcross = max(now, maxcross);
    }
    for (int i = meeti, j = meetj; i <10 && j >=0; i++, j--){
        int now = matrixTaxi[i][j];
        maxcross = max(now, maxcross);
    }
    int meetTaxi = matrixTaxi[meeti][meetj];
    int biggest;
    if(maxcross >= abs(meetTaxi)) {
        EXP1+=ceil(0.12*double(EXP1));
        EXP2+=ceil(0.12*double(EXP2));
        HP1+=ceil(0.1*double(HP1));
        HP2+=ceil(0.1*double(HP2));
        biggest=maxcross;
    }
    else {
        EXP1=ceil(0.88*double(EXP1));
        EXP2=ceil(0.88*double(EXP2));
        HP1=ceil(0.9*double(HP1));
        HP2=ceil(0.9*double(HP2));
        biggest=meetTaxi;
    }
        if (EXP1 > 600) EXP1 = min(EXP1,600);
        else EXP1 = max(EXP1,0);
        if (HP1 > 666) HP1 = min(HP1,666);
        else HP1 = max(HP1,0);
        if (EXP2 > 600) EXP2 = min(EXP2,600);
        else EXP2 = max(EXP2,0);
        if (HP2 > 666) HP2 = min(HP2,666);
        else HP2 = max(HP2,0);
    return biggest;}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
   string S = s;
   string E = email;
   string se;
   if (S.size()<8) return -1;
   else if (S.size()>20) return -2;
   for (int i=0; i<20; i++){
       if (E[i] != '@') se += E[i];
       else break;
   }
   int sei = S.find(se);
   if (sei >= 0 && sei<S.size()) return -(300+sei);
   for (int i = 0; i<S.size(); i++){
       if (S[i] == S[i + 1] && S[i + 1] == S[i + 2]) return -(400+i);
   }
   if (S.find('@') == string::npos && S.find('#') == string::npos && S.find('%') == string::npos && S.find('$') == string::npos && S.find('!') == string::npos) return -5;
   for (int beg = 0; beg <=S.size(); beg++) {
       int a = int(S[beg]);
       if ((a > 33 && a<=47 && a!=37 && a!=35 && a!=36) || (a >= 58 && a<64)|| (a>=91 && a <97) ||(a>=123 && a<=126))
       {
       return beg;}
   }
   return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxtimes = 0, maxlength = 0, position = 0;
    for (int i = 0; i < num_pwds; i++){
           int nowcount = 1;
           string d = arr_pwds[i];
           int nowlength = d.size();
        for (int j = i + 1; j < num_pwds; j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                nowcount++;
            }
        }
        if (nowcount>maxtimes || (maxtimes==nowcount && nowlength > maxlength)){
            maxtimes = nowcount;
            maxlength = nowlength;
            position = i;
        }
    }
    return position;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////