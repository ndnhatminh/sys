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
int Cexp(int exp){
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
    else 
        return exp;
    return exp;
}
int firstMeet(int & exp1, int & exp2, int e1) {
if (e1 >= 0 and e1 <= 99){
    if (e1 >= 0 and e1 <= 3){
        if (e1 == 0)
            exp2 = Cexp(exp2 += 29);
        else if (e1 == 1)
            exp2 = Cexp(exp2 += 45);
        else if (e1 == 2)
            exp2 = Cexp(exp2 += 75);
        else if (e1 == 3)
            exp2 = Cexp(exp2 += 149);
        int d;
        d = e1*3 + exp1*7;
        if (d % 2 == 0)
            exp1 = Cexp(exp1 = ceil(exp1 + (float)d/200));
        else 
            exp1 = Cexp(exp1 = ceil(exp1 - (float)d/100));
    }
    else if (e1 >= 4 and e1 <= 99){
        if (e1 >= 4 and e1 <= 19)
            exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/4 + 19));
        else if (e1 >= 20 and e1 <= 49)
            exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/9 + 21));
        else if (e1 >= 50 and e1 <= 65)
            exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/16 + 17));
        else if (e1 >= 66 and e1 <= 79){
            exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/4 + 19));
            if (exp2 > 200)
                exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/9 + 21));
        }
        else if (e1 >= 80 and e1 <= 99){
            exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/4 + 19));
            exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/9 + 21));
            if (exp2 > 400){
                 exp2 = Cexp(exp2 = ceil(exp2 + (float)e1/16 + 17));
                 exp2 = Cexp(exp2 = ceil((float)exp2*1.15));
            }
        }
        exp1 = Cexp(exp1 -= e1);
    }
    else
        return -99;
    // TODO: Complete this function
    return exp1 + exp2;
}
else{
    return -99;
}
}
int CHP(int hp){
    if (hp > 666)
        hp = 666;
    else if (hp < 0)
        hp = 0;
    else 
        return hp;
    return hp;
}
int CM(int m){
    if (m > 3000)
        m = 3000;
    else if (m < 0)
        m = 0;
    else 
        return m;
    return m;
}
// Task 2

int scp(int S){
    int a = sqrt(S);
    if ((S- a*a)>((a+1)*(a+1)-S))
        return (a+1)*(a+1);
    else
        return a*a;
}
int CTT (int y, int sum){
        return sum + y; 
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
if (E2 >= 0 and E2 <= 99){
    float P1 = 1;
    float P4 = 1;
    float P2 =1;
    int P3 = 1;
    int hp1bd = HP1;
    int tienbd = M1;
     //HP1 = hp1bd;
     //M1 = tienbd;
    //conduong1
    int S = scp(EXP1);
    if (EXP1 < S)
        P1 = (((float)EXP1/S + 80)/123);
    //conduong3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2 < 10 and E2 >= 0)
        P3 = P[E2];
    else if (E2 < 100 and E2 >= 10)
        P3 = P[(E2/10 + E2%10)%10];
    P4 = (float)P3/100;
    //conduong2
//E2 la so chan
    int tientong = 0;
    int nuatien = (M1/2);
    if (E2 % 2 == 0){
    while (tienbd != 0){
    if (HP1 < 200){
        HP1 = CHP(ceil((float)(HP1*1.3)));
        M1 = CM(M1-150);
    }else{
        HP1 = CHP(ceil((float)(HP1*1.1)));
        M1 = CM(M1-70);
    }if (M1 == 0)
        break;
    
    if (EXP1 < 400){
        M1 = CM(M1-200);
    }
    else{
        M1 = CM(M1-120);
    }
    EXP1 = Cexp(ceil((float)(EXP1*1.13)));
    if (M1 == 0)
        break;
    if (EXP1 < 300){
        M1 = CM(M1-100);
    }
    else{
        M1 = CM(M1-120);
    }
    EXP1 = Cexp(ceil((float)(EXP1*0.9)));
    break;
    }
    HP1 = CHP(ceil((float)(HP1*0.83)));
    EXP1 = Cexp(ceil((float)(EXP1*1.17)));
}
// E2 la so le
    else{
    while(tientong <= nuatien){
    if (HP1 < 200){
        HP1 = CHP(ceil((float)(HP1*1.3)));
        M1 = CM(M1-150);
        tientong = CTT(150,tientong);
    }else{
        HP1 = CHP(ceil((float)(HP1*1.1)));
        M1 = CM(M1-70);
        tientong = CTT(70,tientong);
    }
    if (tientong > nuatien)
        break;
    if (EXP1 < 400){
        M1 = CM(M1-200);
        tientong = CTT(200,tientong);
    }
    else{
        M1 = CM(M1-120);
        tientong = CTT(120,tientong);
    }
    EXP1 = Cexp(ceil((float)(EXP1*1.13)));
    if (tientong > nuatien)
        break;
    
    if (EXP1 < 300){
        M1 = CM(M1-100);
        tientong = CTT(100,tientong);
    }
    else{
        M1 = CM(M1-120);
        tientong = CTT(120,tientong);
    }
    EXP1 = Cexp(ceil((float)(EXP1*0.9)));
    if (tientong > nuatien)
        break;

    }
    HP1 = CHP(ceil((float)(HP1*0.83)));
    EXP1 = Cexp(ceil((float)(EXP1*1.17)));
}
    int A = scp(EXP1);
    P2 = 1;
    if (EXP1 < A)
        P2 = (((float)(EXP1/A) + 80)/123);
    float avg;
    if ( (P1 == 1) and (P2 == 1) and (P4 == 1)){
        EXP1 = Cexp(ceil((float)(EXP1*0.75)));
    }
    else{
         avg = (P1 + P2 + P4)/3.0;
         if (avg < 0.5){
             HP1 = CHP(ceil((float)(HP1*0.85)));
             EXP1 = Cexp(ceil((float)(EXP1*1.15)));
         }else{
             HP1 = CHP(ceil((float)(HP1*0.9)));
             EXP1 = Cexp(ceil((float)(EXP1*1.2)));
         }
    }

    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}
else{
    return -99;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
if (E3 >= 0 and E3 <= 99){
    int matran[10][10]={};
    int counti = 0, countj = 0;
    //nhap mang
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            matran[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }


    // tim diem gap nhau
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){ 
            if (matran[i][j] > E3*2 and matran[i][j] > 0)
                counti++;
            if (matran[i][j] < (-1)*E3 and matran[i][j] < 0)
                countj++;
        }
    }
    while (counti > 9){
        counti = (counti/10 + counti%10);
    }
    while (countj > 9){
        countj = (countj/10 + countj%10);
    }

    //tinhdiemcuaSherlock
    int itam = counti;
    int jtam = countj;
    int MAX = matran[counti][countj];
    for (int i = counti + 1; i < 10;i++ ){
        if (MAX < matran[i][jtam + 1])
            MAX = matran[i][jtam + 1];
        jtam++;
        if (jtam >= 9)
            break;
    }
    itam = counti;
    jtam = countj;
    for (int i = counti + 1; i < 10;i++ ){
        if (MAX < matran[i][jtam - 1])
            MAX = matran[i][jtam - 1];
        jtam--;
        if (jtam < 0)
            break;
    }
    itam = counti;
    jtam = countj;
    for (int i = counti - 1; i >= 0;i-- ){
        if (MAX < matran[i][jtam - 1])
            MAX = matran[i][jtam - 1];
        jtam--;
        if (jtam < 0)
            break;
    }
    itam = counti;
    jtam = countj;
    for (int i = counti - 1; i >= 0;i-- ){
        if (MAX < matran[i][jtam + 1])
            MAX = matran[i][jtam + 1];
        jtam++;
        if (jtam >= 9)
            break;
    }

    //so sanh
    if (abs(matran[counti][countj]) > abs(MAX)){
        EXP1 = Cexp(ceil((float)(EXP1*0.88)));
        EXP2 = Cexp(ceil((float)(EXP2*0.88)));
        HP1 = CHP(ceil((float)(HP1*0.9)));
        HP2 = CHP(ceil((float)(HP2*0.9)));
        return matran[counti][countj];
       
    }
    else{
        EXP1 = Cexp(ceil((float)(EXP1*1.12)));
        EXP2 = Cexp(ceil((float)(EXP2*1.12)));
        HP1 = CHP(ceil((float)(HP1*1.1)));
        HP2 = CHP(ceil((float)(HP2*1.1))); 
        return MAX;
        
    }
    // TODO: Complete this function
}
else{
    return -99;
}

}

// Task 4
int checkPassword(const char * s, const char * email) {
// TODO: Complete this function
string se;
string S = string(s);
string EMAIL = string(email);
// tim se
  for (int i = 0; i < EMAIL.length(); i++){
      if (EMAIL[i] == 64){
          se = EMAIL.substr(0,i);
      }
  }
//check so ki tu
  int c;
  if (S.length() >= 8 and S.length() <= 20){
      c = -10;
  }else if (S.length() < 8){
      c = -1;
  }else{
      c = -2;
  }
//check mk co se khong
  if (c == -10){
    if (S.find(se) <= 20){
      c = -(300 + S.find(se));
    }
  }
  //check ki tu trung lap 
  if (c == -10){
      int k = S.length();
      for (int i = 0; i < k - 1; i++){
            if ((S[i] == S[i+1]) and (S[i+1] == S[i+2])){
                c = -(400 + i);
            }
            if (c != -10)
                break;
      }
  }
//check ki tu dac biet
  if (c == -10){
    int k = 0;
    for (int i = 0; i < S.length(); i++){
            if (S[i] == 33 or (S[i] >= 35 and S[i] <= 37) or S[i] == 64)
                k++;
    }
        if (k == 0)
            c = -5;
      
  }
  //check loi khac
  if(c == -10){
      int i = 0;
      while (i != S.length()){
            if ((S[i] >= 48 and S[i] <= 57) or (S[i] >= 65 and S[i] <= 90) or (S[i] >= 97 and S[i] <= 122) or S[i] == 33 or (S[i] >= 35 and S[i] <= 37) or S[i] == 64){
                i++;
            }
             else{
                 c = i;
            }
            if (c==i)
                break;
      }
  }
  return c;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string k("");
    int max =1;
    int kq =0;
    int b[num_pwds]={0};
    string a[num_pwds];
    for (int i = 0; i < num_pwds; i++){
         a[i] = arr_pwds[i];
    }
    for (int i = 0; i < num_pwds;i++){
        for (int j = i; j < num_pwds;j++){
            if (a[j]==a[i])
                b[i]++;
    }
}
    for (int i = 0; i < num_pwds;i++){
        if (b[i]>max)
            max=b[i];
}
    for (int i = 0; i < num_pwds;i++){
        if (b[i]==max){
            if (a[i].length() > k.length())
                k=a[i];   
    }
}
    for (int i = 0; i < num_pwds;i++){
        if (k==a[i]){
            kq=i;
            break;
        }
    }
    return kq;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////