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
void check (int &HP, int &EXP, int &M, int HP_max, int EXP_max, int M_max) {
  if (HP > HP_max) HP = HP_max;
  if (HP < 0)  HP = 0;
  if (EXP > EXP_max)   EXP = EXP_max;
  if (EXP < 0)  EXP = 0;
  if (M > M_max)  M = M_max;
  if (M < 0)  M = 0;
}
void CheckAll (int &HP1, int &EXP1, int &M1, int & HP2, int & EXP2, int & M2){
  check(HP1, EXP1, M1, 666, 600, 3000);
  check(HP2, EXP2, M2, 666, 600, 3000);
}
int firstMeet(int &EXP1, int &EXP2, int E1) { 
    // Truong hop 1
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else EXP2 += (29 + 45 + 75);
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 = ceil(EXP1+D / 200.0);
        else EXP1 = ceil(EXP1- D / 100.0);
        if (EXP2>600)EXP2=600;
        if (EXP2 <0) EXP2=0;
        if (EXP1>600)EXP1=600;
        if (EXP1 <0) EXP1=0;
    }   
    // Truong hop2
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) EXP2 = ceil(EXP2+(E1 / 4.0) + 19);
        else if (E1 >= 20 && E1 <= 49) EXP2 = ceil(EXP2+(E1 / 9.0) + 21);
        else if (E1 >= 50 && E1 <= 65) EXP2 = ceil(EXP2+(E1 / 16.0) + 17);
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 =ceil( EXP2 +(E1 / 4.0) + 19);
            if (EXP2 > 200) EXP2 = ceil(EXP2 +(E1 / 9.0) + 21);
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 = ceil(EXP2+(E1 / 4.0) + 19);
            EXP2 = ceil(EXP2+(E1 / 9.0) + 21);
                if (EXP2 > 400) {
                    EXP2 = ceil(EXP2+(E1 / 16.0) + 17);
                    EXP2 = ceil(EXP2+ EXP2 * 0.15);
                } 
        } 
        EXP1 =EXP1- E1;
    if (EXP2>600)EXP2=600;
    if (EXP2 <0) EXP2=0;
    if (EXP1>600)EXP1=600;
    if (EXP1 <0) EXP1=0;
    }
    else return -99;
    return EXP1 + EXP2;
}


// Task 2
void DieuKien(int &EXP1, int &HP1, int &M1) {
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (M1 <0 ) M1=0;
    if (M1>3000) M1=3000;
}
void Street1(int EXP1,long long &S) {
    int lower = floor(sqrt(EXP1));
    int upper = ceilf(sqrt(EXP1));
    if ((EXP1 - lower * lower) <= (upper * upper - EXP1)) {
        S =( lower * lower);
    } else {
        S = upper * upper;
    }
}
void SuKien1(int &HP1, int &EXP1, int &M1, int E2){
    //su kien 1  
        if (HP1 < 200) {
            HP1 = ceilf(HP1 * 130.000 / 100);
            M1 -= 150;
        } else {
            HP1=ceilf(HP1*110.000/100);
            M1 -= 70;
        }
         DieuKien(EXP1, HP1, M1);
}
void SuKien2(int &HP1, int &EXP1, int &M1, int E2){
        //su kien 2
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1=ceilf(EXP1*113.0/100);
        } else {
            M1 -= 120;
            EXP1=ceilf(EXP1*113.0/100);
        }
         DieuKien(EXP1, HP1, M1);
          
}
void SuKien3(int &HP1, int &EXP1, int &M1, int E2){
      //su kien 3
        if (EXP1 < 300) {
            EXP1=ceilf(EXP1*90.0/100);
            M1 -= 100;
        } 
        else {
            M1 -= 120;
            EXP1=ceilf(EXP1*90.0/100);
        } 
         DieuKien(EXP1, HP1, M1);
}
void Street2(int &HP1, int &EXP1, int &M1, int E2){ 
    int M=M1;
    int MoneyChi=0;
    DieuKien(EXP1, HP1, M1);
    if (E2 % 2 != 0)  { 
        while (MoneyChi<=M/2 && M1>0) {
             DieuKien(EXP1, HP1, M1);
            SuKien1(HP1,EXP1,M1,E2);
            MoneyChi=(M-M1);
            if (MoneyChi>M*50.0/100) {
                HP1= ceilf (HP1*83.00/100);
                EXP1= ceilf(EXP1*117.00/100);
                break;
                } 
            SuKien2(HP1,EXP1,M1,E2);
            MoneyChi=(M-M1);
            if (MoneyChi>M*50.0/100) {
                HP1= ceilf(HP1*83.00/100);
                EXP1= ceilf(EXP1*117.0/100);
                break;
                } 
            SuKien3(HP1,EXP1,M1,E2);
            MoneyChi=(M-M1);
            if (MoneyChi>M*50.0/100) {
                HP1= ceilf (HP1*83.00/100);
                EXP1= ceilf(EXP1*117.00/100);
                break;
                }    
        }
    }
    else  {
        int SoSuKien=0;
        while(M1>0 && SoSuKien==0){
            SuKien1(HP1,EXP1,M1,E2);
            if (M1 <=0) break; else SoSuKien++;
            SuKien2(HP1,EXP1,M1,E2);
            if (M1 <=0) break; else SoSuKien++;
             DieuKien(EXP1, HP1, M1);
            SuKien3(HP1,EXP1,M1,E2);
            if (M1 <=0) break; else SoSuKien++;   
            SoSuKien++;
        }
         HP1= ceilf (HP1*83.00/100);
        EXP1= ceilf(EXP1*117.00/100);
    }
}
void Street3(int E2,double &P3) {
    int i;
    if (E2 < 10 && E2>=0 ) {
        i = E2;
    } else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3 =P[i];
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
      if(E2<0 ||E2>99) return -99;
    long long S;
    Street1(EXP1,S); 
    double P1,P2,P3;
    if (EXP1 >= S) {
        P1 = 100;
    } else {
        P1 = (EXP1 / S + 80)*100 / 123.0;
    }
    Street2(HP1, EXP1, M1, E2);
     DieuKien(EXP1, HP1, M1);
    Street1(EXP1, S); 
    if (EXP1 >= S) {
        P2 = 100;
    } else {
        P2 = (EXP1*1.0 / S + 80)*100 / 123.0;
    }
    Street3( E2,P3);
    if(E2<0 ||E2>99) return -99;
     DieuKien(EXP1, HP1, M1);
    if (P1 == 100 && P2 == 100 && P3 == 100) {
        EXP1=ceilf(EXP1*75.0/100);
    }
    else{
        double P=( P1+P2+P3 ) /3.0;
        if(P<50){
            HP1=ceilf(HP1*85.00/100);
            EXP1=ceilf(EXP1*115.00/100);  
             DieuKien(EXP1, HP1, M1);
        }
        else{
            HP1=ceilf(HP1*90.00/100);
            EXP1=ceilf(EXP1*120.00/100);
             DieuKien(EXP1, HP1, M1);
        }
    }
    return ceilf(HP1+EXP1+M1); 
}
// Task 3
void DieuKien3(int &EXP, int &HP) {
    if (EXP > 600) EXP = 600;
    if (EXP < 0) EXP= 0;
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
   
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {    
    if(E3<0 || E3>99) return -99;
    int duong_i=0;
    int am_j=0;
    int taxi[10][10]={0};
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            taxi[i][j]=((E3*j)+(i*2))*(i-j);
             if (taxi[i][j] > E3 * 2) duong_i++;
             if (taxi[i][j] < (-E3)) am_j++;
        }
    }
    while(duong_i>9){
        duong_i=(duong_i/10)+(duong_i%10);
        }
    while(am_j>9){
        am_j=(am_j/10)+(am_j%10);
    }
    int diemTaxi=taxi[duong_i][am_j];
    int diem_sherlock=taxi[duong_i][am_j];
//tim diem cua sherlock
    //duong cheo trai tren: i giam j giam
    for(int x=duong_i, y=am_j; x>=0 && y>=0; --x,--y){
        diem_sherlock=max(diem_sherlock,taxi[x][y]);
      if (x < 0 || x > 9 || y < 0 || y > 9) break;
    }
    // duong cheo trai duoi: i tang j giam
    for(int x=duong_i, y=am_j; x<10 && y>=0; ++x,--y){
        diem_sherlock=max(diem_sherlock,taxi[x][y]);
      if (x < 0 || x > 9 || y < 0 || y > 9) break;
    }
    // duong cheo phai tren:i tang j tang
     for(int x=duong_i, y=am_j; x<10 && y<10; ++x,++y){
        diem_sherlock=max(diem_sherlock,taxi[x][y]);
      if (x < 0 || x > 9 || y < 0 || y > 9) break;
    }
    // duong cheo phai duoi: i giam j tang
     for(int x=duong_i, y=am_j; x>=10 && y<10; --x,++y){
        diem_sherlock=max(diem_sherlock,taxi[x][y]);
      if (x < 0 || x > 9 || y < 0 || y > 9) break;
    }
    diem_sherlock=abs(diem_sherlock);
    DieuKien3(EXP1, HP1);
     DieuKien3(EXP2, HP2);
    if(diem_sherlock>=abs(diemTaxi)){
        HP1=ceil(HP1*110.0/100);
        HP2=ceil(HP2*110.0/100);
        EXP1=ceil(EXP1*112.0/100);
        EXP2=ceil(EXP2*112.0/100);
        DieuKien3(EXP1, HP1);
     DieuKien3(EXP2, HP2);
        return diem_sherlock;
    }
    else{
        HP1=ceil(HP1*90.0/100);
        HP2=ceil(HP2*90.0/100);
        EXP1=ceil(EXP1*88.0/100);
        EXP2=ceil(EXP2*88.0/100);
        DieuKien3(EXP1, HP1);
     DieuKien3(EXP2, HP2);
        return diemTaxi;
    }
}
// Task 4
int checkPassword(const char *s,const char *email)
{ 
    size_t vitri = std::string(email).find('@');
    std::string se = std::string(email).substr(0, vitri);

    if (std::strlen(s) < 8) return -1;
    if (std::strlen(s) > 20) return -2;
    //check mk co chua se khong
    if(string(s).find(se) != string::npos) {
        return -(300+string(s).find(se));
    }

    //mat khau co nhieu hon 2 ki tu lien tiep
    for (int i = 0; i < std::strlen(s) - 2; i++) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
            return -(400 + i);
        }
    }
    //check ki tu dac biet
    bool special_char = false;
    std::string specialchars = "@#%$!";
    for (int i = 0; i < std::strlen(s); i++) {
            if(s[i] == '@' || s[i] == '#' ||  s[i] == '%' || s[i] == '$' || s[i] == '!'|| s[i]=='^'||s[i]=='&'){
            special_char=true;
        }
    }
    if (!special_char) return -5;
    //check ki tu khac
    for (int i = 0; i < std::strlen(s); i++) {
        if (!isdigit(s[i]) && !islower(s[i]) && !isupper(s[i])) {
            if(specialchars.find(s[i])==string::npos){
             return i;
            }
        }
    }
       return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int tanSuat_max = 0;
    int doDai_max = 0;
    int vitri = -1;
    for (int i = 0; i < num_pwds; i++) {
        int doDai = strlen(arr_pwds[i]);
        int tanSuat = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                tanSuat++;
            }
        }
        if (tanSuat > tanSuat_max || (tanSuat == tanSuat_max && doDai > doDai_max)) {
            tanSuat_max = tanSuat;
            doDai_max = doDai;
            vitri = i;
        }
    }
    return vitri;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

