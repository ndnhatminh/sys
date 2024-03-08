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
void resetEXP(int  & exp){
    if(exp > 600) exp = 600;
    else if(exp < 0) exp = 0;
}
void resetHP(int & HP){
    if(HP > 666) HP = 666;
    else if(HP < 0) HP = 0;
}
void resetMoney(int & M){
    if(M > 3000) M = 3000;
    else if(M < 0) M = 0;
}
// Task 1
void lamtronvacong(int & exp, float & xexp){
    xexp = ceil(xexp);
    exp = exp + xexp;
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Case 1
    int D = 0;
    float xexp1 = 0, xexp2 = 0;
    if(e1 >= 0 && e1 <= 3){
        switch(e1){
            case 0:
                exp2 += 29;
                resetEXP(exp2);
                break;
            case 1:
                exp2 += 45;
                resetEXP(exp2);
                break;
            case 2:
                exp2+= 75;
                resetEXP(exp2);
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
                resetEXP(exp2);
                break;

        }
        D = e1*3 + exp1*7;
        if(D % 2 == 0) {
            exp1 = exp1 + D/200;
            resetEXP(exp1);
            } else {
            exp1 = exp1 - D/100;
            resetEXP(exp1);
            }

    }
    //Case 2
    if(e1 >= 4 && e1 <=99){
        if(e1 >= 4 && e1 <= 19) {
            xexp2 = xexp2 + (float)e1/4 + 19;
            lamtronvacong(exp2, xexp2);
            resetEXP(exp2);
        }
        if(e1 >= 20 && e1 <= 49) {
            xexp2 = xexp2 + (float)e1/9 + 21;
            lamtronvacong(exp2, xexp2);
            resetEXP(exp2);
        }
        if(e1 >= 50 && e1 <= 65) {
            xexp2 = xexp2 + (float)e1/16 + 17;
            lamtronvacong(exp2, xexp2);
            resetEXP(exp2);
        }
        if(e1 >= 66 && e1 <= 79){
            xexp2 = xexp2 + (float)e1/4 + 19;
            lamtronvacong(exp2, xexp2);
            if(exp2 > 200) {
                xexp2 = xexp2 + (float)e1/9 + 21;
                lamtronvacong(exp2,xexp2);
                resetEXP(exp2);
            }
        }
        if(e1 >= 80 && e1 <= 99) {
            xexp2 = xexp2 + (float)e1/4 + 19;
            lamtronvacong(exp2, xexp2);
            resetEXP(exp2);
            xexp2 = xexp2 + (float)e1/9 + 21;
            lamtronvacong(exp2, xexp2);
            resetEXP(exp2);
            if(exp2 > 400) {
                xexp2 = xexp2 + (float)e1/16 + 17;
                lamtronvacong(exp2, xexp2);
                resetEXP(exp2);
                xexp2 = exp2 * 1.15;
                exp2 = ceil(xexp2);
                resetEXP(exp2);
            }
        }
        exp1 = exp1 - e1;
        resetEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
float closestcp(int & EXP1){
    int cp1,cp2;
    float P;
    cp1 = pow(ceil(EXP1),2);
    cp2 = pow(floor(EXP1),2);
    if(cp1 - EXP1 >= EXP1 - cp2) {
        P = ((float)EXP1/cp1+80)/123;
    }
    else P = 1;
    return P;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int cp1,cp2, Mn = 0, MM;
    float P1;
    //Con duong 01
    P1 = closestcp(EXP1);
    //Con duong 02
    float P2;
    MM = M1;
    ////1
    quaylai: //label
    if(HP1 < 200){
        HP1 += ceil(HP1 * 0.3);
        M1 -= 150;
        Mn += 150;
        resetHP(HP1); resetMoney(M1);
        if(E2 %2 != 0) {if(Mn > 0.5*MM) goto thoatvonglap;}
        else {if(M1 == 0) goto thoatvonglap;}
    } else {
        HP1 += ceil(HP1 * 0.1);
        M1 -= 70;
        Mn += 70;
        resetHP(HP1); resetMoney(M1);
        if(E2 %2 != 0) {if(Mn > 0.5*MM) goto thoatvonglap;}
        else {if(M1 == 0) goto thoatvonglap;}
    }
    ////2
    if(EXP1 < 400) {
        M1 -= 200;
        EXP1 += ceil(EXP1*0.13);
        Mn += 200;
        resetEXP(EXP1); resetMoney(M1);
        if(E2 %2 != 0) {if(Mn > 0.5*MM) goto thoatvonglap;}
        else {if(M1 == 0) goto thoatvonglap;}
    } else {
        M1 -= 120;
        EXP1 += ceil(EXP1*0.13);
        Mn += 120;
        resetEXP(EXP1); resetMoney(M1);
        if(E2 %2 != 0) {if(Mn > 0.5*MM) goto thoatvonglap;}
        else {if(M1 == 0) goto thoatvonglap;}
    }
    ////3
    if(EXP1 < 300) {
        M1 -= 100;
        EXP1 = ceil(EXP1*0.9);
        Mn += 100;
        resetEXP(EXP1); resetMoney(M1);
        if(E2 %2 != 0) {if(Mn > 0.5*MM) goto thoatvonglap;}
        else {if(M1 == 0) goto thoatvonglap;}
    } else {
        M1 -= 120;
        EXP1 = ceil(EXP1*0.9);
        Mn += 120;
        resetEXP(EXP1); resetMoney(M1);
        if(E2 %2 != 0) {if(Mn > 0.5*MM) goto thoatvonglap;}
        else {if(M1 == 0) goto thoatvonglap;}
    }
    if(E2 % 2 != 0) goto quaylai;
    thoatvonglap:
    HP1 = ceil(HP1*0.83);
    EXP1 += ceil(EXP1*0.17);
    resetHP(HP1); resetMoney(M1); resetEXP(EXP1);
    P2 = closestcp(EXP1);
    ////Con duong 03
    int A[10]={32,47,28,79,100,50,22,83,64,11};
    int i_2chuso = 0;
    float P3;
    if(E2 < 10){
        P3 = A[E2];
    }
    if(E2 >= 10){
        i_2chuso = i_2chuso + E2%10 + (E2 - E2%10)/10;
        i_2chuso = i_2chuso % 10;
        P3 = A[i_2chuso];
    }
    if(P1 == 1 && P2 == 1 && P3 == 1) EXP1 = ceil(EXP1 * 0.75);
    else if((P1 + P2 + P3)/3 < 0.5) {
        HP1 = ceil(HP1*0.85);
        EXP1 += ceil(EXP1*0.15);
    }else{
        HP1 = ceil(HP1*0.9);
        EXP1 += ceil(EXP1*0.2);
    }
    resetEXP(EXP1); resetHP(HP1); resetMoney(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int highmatrancheotrai(int x, int y, int  arr[][10]){
    int lonnhat1;
    int i, j;
    if(x >= y){
        i = x - y;
        j = 0;
        lonnhat1 = arr[i][j];
        for(i; i <=9; i++){
            if(arr[i][j]>=lonnhat1) lonnhat1 = arr[i][j];
            j++;
        }
    } else {
        i = 0;
        j = y - x;
        lonnhat1 = arr[i][j];
        for(j; j <=9; j++){
            if(arr[i][j]>=lonnhat1) lonnhat1 = arr[i][j];
            i++;
        }
    }
    return lonnhat1;
}
int highmatrancheophai(int x, int y, int arr[][10]){
    int lonnhat1;
    int i, j;
    if(x+y <= 9){
        i = 0;
        j = y + x;
        lonnhat1 = arr[i][j];
        for(i; i <= 9; i++){
            if(arr[i][j]>=lonnhat1) lonnhat1 = arr[i][j];
            j--;
        }
    } else {
        i = x-(9-y);
        j = 9;
        lonnhat1 = arr[i][j];
        for(i; i <= 9; i++){
            if(arr[i][j]>=lonnhat1) lonnhat1 = arr[i][j];
            j--;
        }
    }
    return lonnhat1;
}
int congchuso(int a){
    while(a > 10){
        a = (a-a%10)/10 + a%10;
    }
    if(a == 10) return 1;
    return a;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int arrTaxi[10][10], arrSLH[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arrTaxi[i][j] = 0;
        }
    }
    //Khoi tao ma tran Taxi
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arrTaxi[i][j] = (E3*j + 2*i)*(i-j);
        }
    }
    //Khoi tao ma tran Sherlock
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arrSLH[i][j] = abs(max(highmatrancheophai(i, j, arrTaxi), highmatrancheotrai(i, j, arrTaxi)));
        }
    }
    int hoanh = 0, tung = 0, hoanh1, tung1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(arrTaxi[i][j] > E3*2) hoanh++;
            if(arrTaxi[i][j] < -E3) tung++;
        }
    }
    hoanh1 = hoanh; tung1 = tung;
    hoanh = congchuso(hoanh); tung = congchuso(tung);
    if(abs(arrTaxi[hoanh][tung]) > arrSLH[hoanh][tung]){
        EXP1 = ceil(EXP1*0.88); EXP2 = ceil(EXP2*0.88);
        HP1 = ceil(HP1*0.9); HP2 = ceil(HP2*0.9);
        return arrTaxi[hoanh][tung];
    }
    else {
        EXP1 += ceil(EXP1*0.12); EXP2 += ceil(EXP2*0.12);
        HP1 += ceil(HP1*0.1); HP2 += ceil(HP2*0.1);
        return arrSLH[hoanh][tung];
    }
    return -1;
}

// Task 4
bool kiemtrachuaxau(string s1, string se){
    for(int i = 0; i < s1.size(); i++){
        int a = 0;
        for(int j = 0; j < se.size(); j++){
            if(s1[i+j] == se[j]){
                a++;
            }
            else break;
        }
        if(a == se.size()) return true;
    }
    return false;
}
int inravitrixaucon(string s1, string se){
    for(int i = 0; i < s1.size(); i++){
        int a = 0;
        for(int j = 0; j < se.size(); j++){
            if(s1[i+j] == se[j]){
                a++;
            }
            else break;
        }
        if(a == se.size()) {
            return -(300 + i);
        }
    }
    return 0;
}
bool kiemtralienke(string s1){
    int b = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == s1[i+1] && s1[i+1] == s1[i+2])
            return true;
    }
    return false;
}
int inravitrilienke(string s1){
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == s1[i+1] && s1[i+1] == s1[i+2]) return -(400 + i);
    }
    return 0;
}
bool kiemtrakitudacbiet(string s1){
    for(int i = 0; i < s1.size(); i++){
        if(s1[i]=='!' || s1[i]=='@'||s1[i]=='#'||s1[i]=='$'||s1[i]=='%') return true;
    }
    return false;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s1 = s;
    string email1 = email;
    string se;
    for(int i = 0; i < email1.size(); i++){
        if(email1[i] == '@'){
            se = email1.substr(0, i);
            break;
        }
    }
    if(s1.size() < 8) return -1;
    else if(s1.size()> 20) return -2;
    else if(kiemtrachuaxau(s1, se)) return inravitrixaucon(s1, se);
    else if(kiemtralienke(s1)) return inravitrilienke(s1);
    else if(kiemtrakitudacbiet(s1)==false) return -5;
    else {
        for(int i = 0; i < s1.size(); i++){
            if(((int)s1[i]>=48 && (int)s1[i]<=57) || ((int)s1[i]>=65 && (int)s1[i]<=90) || ((int)s1[i]>=97 && (int)s1[i]<= 122)) return -10;
        }
    }
    int k = 0;
    int j = 0;
    for(int i = 0; i < email1.size(); i++){
        if(email1[i] == '@') {
            k++;
            if(k == 2) return i - j ;
        }
            if(k == 1) j++;

    }
    return -99;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string s[num_pwds];
    int arr[30];
    int l = 1, maxx = 0, maxlenght = 1;
    for(int i = 0; i < num_pwds; i++){
        s[i] = arr_pwds[i];
    }
    for(int i = 0; i < num_pwds-1; i++){
        int k = 1;
        arr[i] = k;
        if(s[i] == "&") {
            arr[i]=k;
            l++;
            continue;
        } else {
        for(int j = i + 1; j < num_pwds; j++){
            if(s[i]==s[j]) {
                s[j] = "&";
                k++;
            }
        }
        arr[i] = k;
        }
        l++;
    }
    arr[l-1]=1;
    for(int i = 0; i < l; i++){
        if(maxx < arr[i]) maxx = arr[i];
    }
    int b;
    for(int i = 0; i < l; i++){
        if(arr[i]==maxx)  {
            if(maxlenght <= s[i].size()) {
                maxlenght = s[i].size();
                b = i;
            }
        }
    }
    return b;
    return -1;
/

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
