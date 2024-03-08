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
int cd(int a, int b) {
    int result = a / b;
    if (a % b != 0) {
        result++;
    }
    return result;
}
void check(int &exp1 , int &exp2) { //check exp
if (exp1 < 0) { exp1 = 0;}
    if (exp2 < 0) { exp2 = 0;}
    if (exp2 >600) {exp2 = 600;}
    if (exp1 >600) {exp1 = 600;}
    }
void check2(int &M1 , int &M2) { //check HP
if (M1 < 0) { M1 = 0;}
    if (M2 < 0) { M2 = 0;}
    if (M2 >666) {M2 = 666;}
    if (M1 >666) {M1 = 666;}
    }
void check3(int &M1 , int &M2) { //check money
if (M1 < 0) { M1 = 0;}
    if (M2 < 0) { M2 = 0;}
    if (M2 >3000) {M2 = 3000;}
    if (M1 >3000) {M1 = 3000;}
}

double p_result(int a){
    int S=round(sqrt(a));
    S=S*S;
    double p;
    if(a>=S) p=1;
    else p=(1.0*a/S+80)/123;
    return p;
}
bool halfbuy(int a,int b) {
    if (a >= b) {
        return false;
    }
    else {return true;}

}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    int D=0;
      switch(e1){
case 0:
    check(exp1,exp2);
    exp2 += 29;
    D = e1*3 + exp1*7;
    break;
case 1:
check(exp1,exp2);
        exp2 += 45;
        D = e1*3 + exp1*7;
    break;
case 2:
check(exp1,exp2);
        exp2 += 75;
        D = e1*3 + exp1*7;
    break;
case 3:
check(exp1,exp2);
        exp2 += 149;
        D = e1*3 + exp1*7;
        break;
case 4 ... 19:
check(exp1,exp2);
        exp2 += cd (e1,4) + 19;

    break;
case 20 ... 49:
check(exp1,exp2);
        exp2 += cd  (e1,9) + 21;
        D=0;
        break;
case 50 ... 65:
check(exp1,exp2);
        exp2 += cd (e1,16) + 17;
        D=0;
        break;


case 66 ... 79:
check(exp1,exp2);
        exp2 += cd (e1,4) + 19;
        D=0;
    if (exp2 > 200) {
          exp2 += cd (e1,9) + 21;

    }
    break;
case 80 ... 99:
check(exp1,exp2);
   exp2 += cd (e1,4) +19 ;
    exp2 += cd (e1,9)+ 21;
    if (exp2 > 400) {
    exp2 +=  cd (e1,16) + 17;
    exp2 = ceil (exp2*1.15);
    }
    break;
default:
    return -99;
    break;
    check(exp1,exp2);
      }
      if (D == 0) {
        exp1 = exp1 - e1;
      }

    else if (D % 2 == 1 && D != 0) {
        exp1 -=  D/100;
        cd (exp1,1);
    }
    else if (D % 2 == 0 && D != 0){
        exp1 +=  cd (D,200);

    }
    check(exp1,exp2);
return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int a = 1;
    if (E2 > 99 || E2 < 0 ) {
        return -99;
    }
    else {
        check(EXP1,a);
        check2(HP1,a);
        check3(M1,a);
        int halfmoney = cd (M1,2);
        double p1 = p_result(EXP1);
        for(;true;) {
            if (M1 == 0) {break;}

            if(HP1 < 200) {
        HP1 = HP1*1.3+0.999;
        M1 -= 150;

    }
    else {
        HP1 = HP1*1.1+0.999;
        M1 -= 70;
    }

        check2(HP1,a);
        check3(M1,a);

    if (halfbuy(M1,halfmoney)==true && E2 % 2 == 1) {break;}
    if (M1 == 0) {break;}
    if (EXP1 < 400) {
        M1 -= 200;
    }
    else  {
        M1 -= 120;
    }

    EXP1 = ceil (EXP1*1.13);
     check3(M1,a);
     check(EXP1,a);

     if (halfbuy(M1,halfmoney)==true && E2 % 2 == 1) {break;}
     if (M1 == 0) {break;}
    if (EXP1 < 300) {
        M1 -= 100;
    }
    else {
        M1 -= 120;
    }
     EXP1 = ceil (EXP1*0.9);
        check3(M1,a);

     if (halfbuy(M1,halfmoney)==true && E2 % 2 == 1) {break;}
     if (M1 == 0) {break;}

    if (E2 % 2 ==0) {
        break;
    }
        }
    HP1= HP1*0.83+0.999;
    EXP1= ceil (EXP1*1.17);
    check(HP1,a);
    check(EXP1,a);
    double p2=p_result(EXP1);
    double p3;
    double arr[10] ={0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    if (E2 < 10) {
        p3 = arr[E2];
    }
    else {
        int a = (E2/10 + E2%10)  ;
        p3 = arr[a%10];

    }
     if(p1==1 && p2==1 && p3==1) EXP1=ceil(EXP1*0.75);
    else {
        if((p1+p2+p3)/3<0.5) {
            HP1=HP1*0.85+0.999;
            EXP1=ceil(EXP1*1.15);
        }
        if((p1+p2+p3)/3>=0.5){
            HP1=HP1*0.9+0.999;
            EXP1=ceil(EXP1*1.2);
        }

    }
    check(EXP1,a);
        check2(HP1,a);
        check3(M1,a);
    return HP1 + EXP1 + M1;
}
}




// Task 3
int bien(int a) {
    while (a >= 10){
            a = a/10 + a%10;
    }
    return a;
    }

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   if (E3 > 99 || E3 < 0) {
    return -99;
   }
   else {
     check2(HP1,HP2);
    check(EXP1,EXP2);

        int arr[10][10] = {};
    for (int t =0; t< 10 ; t++) {
        for (int i = 0 ; i <10 ; i++) {
            arr[t][i] =  ((E3 * i) + (t * 2)) * (t-i);

    }

    }

    int cot=0,hang=0;
      for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(arr[i][j] > E3*2){
                cot++;
            }
            else if(arr[i][j] < -E3){
                hang++;
            }
        }
    }
cot = bien(cot); hang=bien(hang);
    int taxi = arr[cot][hang];
    int maxi = taxi;
    int cot1=cot,cot2=cot,hang1=hang,hang2=hang;

     while ( cot1 > 0 && hang1 > 0) {
        cot1 -- ; hang1--;
    }
    while ( cot2 > 0 && hang2 < 9) {
        cot2 -- ; hang2++;
    }

    for (;;cot1++ , hang1++) {
           if (cot1 >9 || hang1 >9){break;}
        if (maxi < arr[cot1][hang1]) {
            maxi = arr[cot1][hang1];
        }
    }
    for (;;cot2++ , hang2--) {
           if (cot2 >9 || hang2 < 0) {break;}
        if (maxi < arr[cot2][hang2]) {
                maxi = arr[cot2][hang2];
            maxi = arr[cot2][hang2];
        }
    }
   if(abs(taxi)> maxi){
        EXP1=EXP1*0.88 + 0.999;
        EXP2=EXP2*0.88 + 0.999;
        HP1=HP1*0.9 + 0.999;
        HP2=HP2*0.9 + 0.999;
         check(EXP1,EXP2);
        check2(HP1,HP2);
        return taxi;
        }
    else {
        EXP1=(EXP1*1.12) + 0.999;
        EXP2=(EXP2*1.12) + 0.999;
        HP1=HP1*1.1 +0.999;
        HP2=HP2*1.1 + 0.999;
         check(EXP1,EXP2);
        check2(HP1,HP2);
        return maxi;
    }

   }



}

// Task 4



int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string ts = s ;
    string tm = email;
     int a = -10;
    if (ts.length() < 8) {a = -1;}
    else if (ts.length() > 20) {a = -2;}
    else {
    string se(tm,0,tm.find("@"));


    string character = "!@#$%abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string character1 = "!@#$%";
    size_t vitri =ts.find_first_not_of(character);
    size_t vitri2 = ts.find_first_of(character1);
    if (vitri != string::npos) {
        a = vitri;
    }
    if (vitri2 == string::npos) {
        a = -5;
    }
    for (int i = 0; i < ts.length() - 2; i++) {
    if (ts[i] == ts[i + 1] && ts[i + 1] == ts[i + 2]) {
      a = -(400 + i); i = ts.length();
    }
    if (ts.find(se) != string::npos) a= -(300 + ts.find(se));
    if (ts.length() < 8) a = -1;
    if (ts.length() > 20) a = -2;
  }
    }

    return a;
}








// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

       string mk[num_pwds];
    for(int i=0;i<num_pwds;i++){
        mk[i]=arr_pwds[i];
    }
    int bigshot=-1;
    string sct;

    for(int i=0;i<num_pwds;i++){
        int a=1;
        if(mk[i]=="tuesiudepzai:))") continue;
        for(int j=i+1;j<num_pwds;j++){
            if(mk[i]==mk[j]) {
                mk[j]="tuesiudepzai:))";
                a++;

            }
        }

        if(a>bigshot) {
            bigshot=a;
            sct=mk[i];
        }
        if(a==bigshot) {
                int dodai=sct.size();
            if(mk[i].size()>dodai){
                    sct=mk[i];

            }
        }
    }
    int tuedz;
    for(int i=0;i<num_pwds;i++){
        if(sct==mk[i]){
            tuedz=i; break;

        }
    }
    return tuedz;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
