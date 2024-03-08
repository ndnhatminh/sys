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

//Check Dieu Kien Lam Tron EXP
//Check Dieu Kien Lam Tron EXP
int checkEXP(int & exp){
    //dieukien
    if (exp<0) exp=0;
    if (exp>600) exp=600;
    return exp;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //dieukien
    if (e1<0 || e1>99){
          return -99;
    }
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    //TRUONG HOP 1
    if (e1>=0 && e1<=3){
        switch (e1){
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
            exp2=exp2+29+45+75;
            break;
        }
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);

         int d=e1*3+exp1*7;
    if (d%2==0) exp1=ceil(exp1+d*1.0/200);
     else
        exp1=ceil(exp1-d*1.0/100);

    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    }

    //TRUONG HOP 2
    if (e1>=4 && e1<=99){
        if (e1<=19) exp2=ceil(exp2+e1*1.0/4+19);
         else if (e1<=49) exp2=ceil(exp2+e1*1.0/9+21);
         else if (e1<=65) exp2=ceil(exp2+e1*1.0/16+17);
         else if (e1<=79){
            exp2=ceil(exp2+e1*1.0/4+19);
            exp2=checkEXP(exp2); //dieukien
            if (exp2>200) exp2=ceil(exp2+e1*1.0/9+21);
         }
        else if (e1<=99){
            exp2=ceil(exp2+e1*1.0/4+19);
            exp2=checkEXP(exp2); //dieukien
            exp2=ceil(exp2+e1*1.0/9+21);
            exp2=checkEXP(exp2); //dieukien
            if (exp2>400){
                exp2=ceil(exp2+e1*1.0/16+17);
                exp2=checkEXP(exp2); //dieukien
                exp2=ceil(exp2*1.15);
                exp2=checkEXP(exp2); //dieukien
            } 
         }
         exp1=checkEXP(exp1);
         exp2=checkEXP(exp2);

         //Sherlock doan sai
             exp1-=e1;
    }
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    return exp1 + exp2;
}

int timSoChinhPhuong(int & num){
    int beHon=floor(sqrt(num))*floor(sqrt(num));
    int lonHon=floor(sqrt(num)+1)*floor(sqrt(num)+1);
    if (lonHon>600||beHon==0) return beHon; 
     else if (beHon<0) return lonHon;
    if ((num-beHon)>(lonHon-num)) return lonHon;
     else return beHon;
}

//Check Dieu Kien Lam Tron M
int checkMoney(int & money){
    //dieukien
    if (money<0) money=0;
    if (money>3000) money=3000;
    return money;
}

//Check Dieu Kien Lam Tron HP
int checkHP(int & hp){
    //dieukien
    if (hp<0) hp=0;
    if (hp>666) hp=666;
    return hp;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
     if (E2<0 || E2>99){
          return -99;
    }
    M1=checkMoney(M1);
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    //CON DUONG 1
 
    //khai bao bien moi
    int moneyTieuxai=0;
    double phannuaSoTien=M1*1.0/2; 
    double P1, P2, P3=0;
    int S=timSoChinhPhuong(EXP1);
    if (EXP1>=S) P1=1;
     else P1=(EXP1*1.0/S+80)*1.0/123;

    //CON DUONG 2
    M1=checkMoney(M1);
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);


    while (E2 % 2==1){
    if (M1<=0) break;    
     if (HP1<200){
        HP1=ceil(HP1*130.0/100);
        M1-=150;
        moneyTieuxai+=150;
    } else{
        HP1=ceil(HP1*11.0/10);
        M1-=70;
        moneyTieuxai+=70;
    }
    M1=checkMoney(M1);
    HP1=checkHP(HP1);

    if (moneyTieuxai>phannuaSoTien) break;
    if (M1<=0) break;
    if (EXP1<400){
        M1-=200;
        moneyTieuxai+=200;
        EXP1=ceil(EXP1*113.0/100);
        M1=checkMoney(M1);
        EXP1=checkEXP(EXP1);
    } else{
        M1-=120;
        moneyTieuxai+=120;
        EXP1=ceil(EXP1*113.0/100);
        M1=checkMoney(M1); 
        EXP1=checkEXP(EXP1);
    }

    if (moneyTieuxai>phannuaSoTien) break;
    if (M1<=0) break;

    if (EXP1<300){
         M1-=100; 
         moneyTieuxai+=100;
    }
     else{
         M1-=120;
         moneyTieuxai+=120;
     }
     // VO GIA CU CHI SAI 
    EXP1=ceil(EXP1*90.0/100);
    M1=checkMoney(M1);
    EXP1=checkEXP(EXP1);
     //CHECK OUT CHUONG TRINH
    if (moneyTieuxai>phannuaSoTien) break;
    if (M1<=0) break;

        }
          
    while (E2 % 2==0){ 
    //TH CHAN
    //CON DUONG 2
     //check dieu kien
    if (M1<=0) break; 
    M1=checkMoney(M1);
    HP1=checkHP(HP1);
    int moneyDautien=M1;

    
    if (HP1<200){
        HP1=ceil(HP1*130.0/100);
        M1-=150;
        M1=checkMoney(M1);
        HP1=checkHP(HP1);
    } else{
        HP1=ceil(HP1*11.0/10);
        M1-=70;
        M1=checkMoney(M1);
        HP1=checkHP(HP1);
    }
    //CHECK OUT CHUONG TRINH
    if (M1<=0) break;
    if (EXP1<400){
        M1-=200;
        EXP1=ceil(EXP1*113.0/100);
        M1=checkMoney(M1);
        EXP1=checkEXP(EXP1);
    } else{ 
        M1-=120;
        EXP1=ceil(EXP1*113.0/100);
        M1=checkMoney(M1);
        EXP1=checkEXP(EXP1);
    }

    //CHECK OUT CHUONG TRINH
    if (M1<=0) break;

    if (EXP1<300) M1-=100; 
     else M1-=120;

      // VO GIA CU CHI SAI 
    EXP1=ceil(EXP1*90.0/100);
     //CHECK OUT CHUONG TRINH
    M1=checkMoney(M1);
    EXP1=checkEXP(EXP1);
    break;
}


    HP1=ceil(HP1*83.0/100);
    EXP1=ceil(EXP1*117.0/100);
        
    M1=checkMoney(M1);
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    
    S=timSoChinhPhuong(EXP1);
    if (EXP1>=S) P2=1;
     else P2=(EXP1*1.0/S+80)*1.0/123;

    // CON DUONG 3
    double P[10]={0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    if (E2*1.0/10<1) P3=P[E2];
     else{
        int chuSoDV=E2%10;
        int chuSoChuc=(E2-chuSoDV)/10;
        int tongCS=chuSoDV+chuSoChuc;
        int phanTui=tongCS%10;
        P3=P[phanTui];
     }

    double Possibility=0;
    if (P1==1 && P2==1 && P3==1){
         EXP1=ceil(EXP1*75.0/100);
         Possibility=1;
    }
     else 
         Possibility=(P1+P2+P3)*1.0/3;

    EXP1=checkEXP(EXP1);
    HP1=checkHP(HP1);
    if (Possibility < 1.0/2){
        HP1=ceil(HP1*85.0/100);
        EXP1=ceil(EXP1*115.0/100);
    } else if (Possibility > 1.0/2 && Possibility < 1){
        HP1=ceil(HP1*90.0/100);
        EXP1=ceil(EXP1*120.0/100);
    }

    M1=checkMoney(M1);
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //DIEU KIEN
    if (E3<0 || E3>99){
          return -99;
    }
    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    HP2=checkHP(HP2);
    EXP2=checkEXP(EXP2);


    //Khoi tao Ma Tran
    int maTran[10][10];
    for (int i=0; i<=9; i++){
        for (int j=0; j<=9; j++) maTran[i][j]=((E3*j)+(i*2))*(i-j);
    }

    //Khoi tao bien
    int viTrii=0, viTrij=0, counti=0, countj=0, diemThamtu=0, diemTaxi=0;
    //Vi tri gap nhau
    for (int i=0; i<=9; i++){
        for (int j=0; j<=9; j++){
            if (maTran[i][j]>(E3*2)) counti++;
            if (maTran[i][j]<(-1*E3)) countj++;
        }
    }

    while (counti*1.0/10>=1){
        counti=counti%10 + (counti-counti%10)*1.0/10;
    }

    while (countj*1.0/10>=1){
        countj=countj%10 + (countj-countj%10)*1.0/10;
    }

    viTrii=counti; viTrij=countj;

    diemTaxi=maTran[viTrii][viTrij];
    int max=maTran[viTrii][viTrij];
    // Xet duong cheo trai
    int hieu = abs(viTrii - viTrij);
    
    // i giam j giam 
    int m = viTrii, n = viTrij;
    while(m >= 0 && n >= 0 && abs(m - n) == hieu){
        if(maTran[m][n] > max) max = maTran[m][n];
        m--;
        n--;
    }
    // i tang j tang 
    m = viTrii; n = viTrij;
    while(m < 10 && n < 10 && abs( m - n ) == hieu){
        if(maTran[m][n] > max) max = maTran[m][n];
        m++;
        n++;
    }
    
    // Xet duong cheo phai 
    int tong = viTrii + viTrij;
    
    // i tang j giam
    m = viTrii; n = viTrij;
    while(m < 10 && n >= 0 && m + n == tong){
        if(maTran[m][n] > max) max = maTran[m][n];
        m++;
        n--;
    }
    // i giam j tang
    m = viTrii; n = viTrij;
    while(m >= 0 && n < 10 && m + n == tong){
        if(maTran[m][n] > max) max = maTran[m][n];
        m--;
        n++;
    }

    diemThamtu=max;

    if (abs(diemTaxi)>diemThamtu){
        max=diemTaxi;
        EXP1=ceil(EXP1*88.0/100);
        EXP2=ceil(EXP2*88.0/100);
        HP1=ceil(HP1*90.0/100);
        HP2=ceil(HP2*90.0/100);
    } else{
        max=diemThamtu;
        EXP1=ceil(EXP1*112.0/100);
        EXP2=ceil(EXP2*112.0/100);
        HP1=ceil(HP1*110.0/100);
        HP2=ceil(HP2*110.0/100);
    }

    HP1=checkHP(HP1);
    EXP1=checkEXP(EXP1);
    HP2=checkHP(HP2);
    EXP2=checkEXP(EXP2);
    
    
    return max;
}


bool checkKyTuDacBiet(const char * s){
    for (int i=0; i<strlen(s); i++){
        if (s[i]=='@'||s[i]=='!'||s[i]=='#'||s[i]=='$'||s[i]=='%') return true;
    }
    return false;
}

int checkViTriChuoiCon(string pw, string se){
    size_t pos=pw.find(se);
    if (pos>=0) return pos; else return -1;
    }


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
     
     string se="";
    int i=0;
    int vitriACong_off=0;
    for (int i=0; i<strlen(email); i++){
        if (email[i]=='@'){
            vitriACong_off=i; break;
        }
    }

    //Qua string di met roi
    string pw="";
    for (int i=0; i<strlen(s); i++){
        pw+=s[i];
    }

    for (int i=0; i<vitriACong_off; i++){
        se+=email[i];
    }

    if (strlen(s)<8) return -1;
    else if (strlen(s)>20) return -2;
    else{ 
       int viTriChuoiCon_off=checkViTriChuoiCon(pw,se);
       
        if (viTriChuoiCon_off>=0) return (-300-viTriChuoiCon_off);

        for (int i=0; i<=strlen(s)-1; i++){
            if (s[i]==s[i+1] && s[i+1]==s[i+2]) return (-400-i);
        }
        
            if (checkKyTuDacBiet(s)==false) return -5;
        
        for (int i=0; i<=strlen(s)-1; i++){
            if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')))
            return i;
            }
    }

    return -10;
}


// Task 5
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int i=0, max=0, viTriTanSuat=0, tanSuat=0;;

    for (int i=0; i<num_pwds; i++){
        tanSuat=0;
        int doDaichuoi=strlen(arr_pwds[i]);
        //dem so lan xuat hien cua tung phan tu
        for (int j=i+1; j<num_pwds; j++){
            if (strcmp(arr_pwds[j],arr_pwds[i])==0) tanSuat++;
        }
        //so sanh de gan voi max tan suat
        if (tanSuat>max){
            viTriTanSuat=i;
            max=tanSuat;
        } else if (tanSuat==max){
            if (strlen(arr_pwds[i])>strlen(arr_pwds[viTriTanSuat])) viTriTanSuat=i;
        } 
    }
    return viTriTanSuat;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////