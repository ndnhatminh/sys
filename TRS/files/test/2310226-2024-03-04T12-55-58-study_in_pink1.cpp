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
int lamtron(int& So, int x) {
    So= So * x  / 100 + (So * x  % 100 != 0);
    return So;}
void checkHP(int & HP){
   if (HP>666) HP=666;
   else if (HP<0) HP=0; 
}
void checkEXP(int & EXP){
   if (EXP>600) EXP=600;
   else if (EXP<0) EXP=0;
   else EXP=EXP;
}
void checkM(int & M){
   if (M>3000) M=3000;
   else if (M<0) M=0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
 
    if (e1>99 ||e1<0) {return -99;}
else if(e1<4) {   checkEXP(exp1);checkEXP(exp2);
    //Trường hợp 1
    if (e1==0) exp2=exp2+29;
    else if (e1==1) exp2=exp2+45;
    else if (e1==2) exp2=exp2+75;
    else if (e1==3) exp2=exp2+149;
    int D=e1*3+exp1*7;
    if ((D%2)==0) exp1=exp1+ceil(double(D)/200);
    else if ((D%2)==1) exp1=ceil(exp1-D/100);
    }
 //Trường hợp 2
else if (e1>=4&&e1<=99) {   
    checkEXP(exp1);
    checkEXP(exp2);
if (e1>=4&&e1<=19) exp2=exp2 + ceil(double(e1)/4 +19);
else if (e1>=20&&e1<=49) exp2= exp2+ceil(double(e1)/9 +21);
else if (e1>=50&&e1<=65) exp2= exp2+ceil(double(e1)/16 +17);
else if(e1>=66&&e1<=79){
    exp2=exp2 + ceil(double(e1)/4 +19);
    checkEXP(exp2);
    if (exp2>200) exp2= exp2+ceil(double(e1)/9 +21);
}
else if(e1>=80&&e1<=99){
    exp2=exp2 + ceil(double(e1)/4 +19)+ceil(double(e1)/9 +21);
    if (exp2>400) exp2= ceil(double((exp2+ceil(double(e1)/16 +17))*1.15));
}
   exp1=exp1-e1;
}
checkEXP(exp1);
checkEXP(exp2);
return exp1+exp2;
}
// Hàm kiểm tra số chính phương
int chinhphuong(int & exp){
    int cp1=ceil(sqrt(exp));
    int cp2=cp1-1;
    if (abs(((cp2*cp2)-exp))>abs(((cp1*cp1)-exp))) return cp1*cp1;
    else return cp2*cp2;

}
void conduong2_hd1( int& HP1, int &EXP1,int & M1){
    //Hành động 1
        if(HP1<200){
        HP1=lamtron(HP1,130);
        M1=M1-150;
      }
      else{
         HP1=lamtron(HP1,110);
        M1=M1-70;
      }
        checkHP(HP1);
        checkM(M1);
        checkEXP(EXP1);
      }
void conduong2_hd2(int& HP1, int &EXP1,int & M1){
      //Hành động 2
          if (EXP1<400) M1=M1-200;
          else M1=M1-120;
          EXP1=lamtron(EXP1,113);
          checkEXP(EXP1);
            checkM(M1);
            checkHP(HP1);}
void conduong2_hd3(int& HP1, int &EXP1,int & M1 ){
      //Hành động 3
          if(EXP1 <300) M1=M1-100;
          else M1=M1-120;
          EXP1=lamtron(EXP1,90);
           checkEXP(EXP1);
            checkM(M1);
            checkHP(HP1);
          }
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
      if (E2>99 ||E2<0) {return -99;}
     else {
        checkEXP(EXP1);
        checkHP(HP1);
        checkM(M1);
    double P1,P2,P3;
        //Con đường 1
    double S1=chinhphuong(EXP1);
    if(EXP1<S1) P1=(EXP1/S1+80)/123*100;
    else P1=100;
        //Con duong 2
          if(M1==0) {
         EXP1=lamtron(EXP1,117);
        HP1=lamtron(HP1,83);
        checkEXP(EXP1);
         checkHP(HP1);
    }
    else {
    int sotien=ceil(double(M1)/2);//một nửa số tiền ban đầu
    //E2 là số lẻ
    if (E2%2==1) {
        while (M1>=sotien&&M1>0){
        conduong2_hd1(HP1,EXP1,M1);
        if (M1>=sotien) {
            conduong2_hd2(HP1,EXP1,M1);
            if (M1>=sotien) conduong2_hd3(HP1,EXP1,M1);
            else break;
        }
        else break;
        }   
        EXP1=lamtron(EXP1,117);
        HP1=lamtron(HP1,83);
        checkEXP(EXP1);
        checkHP(HP1);
    }
    //E2 là số chẵn
    else if (E2%2==0){
         conduong2_hd1(HP1,EXP1,M1);
         if (M1>0) { 
             conduong2_hd2(HP1,EXP1,M1);
             if (M1>0){
                conduong2_hd3(HP1,EXP1,M1);
                 EXP1=lamtron(EXP1,117);
                 HP1=lamtron(HP1,83);
             }
             else {EXP1=lamtron(EXP1,117);
            HP1=lamtron(HP1,83);}
            
         }
         else {
            EXP1=lamtron(EXP1,117);
            HP1=lamtron(HP1,83);
        
         }
        
         checkEXP(EXP1);
         checkHP(HP1);
    }  
    }
    
       /////Tính P2
        double S2=chinhphuong(EXP1);
        if(EXP1<S2) P2=(EXP1/S2+80)/123*100;
        else P2=100;
        ////Con đường 3
        int P[10]={32,47,28,79,100,50,22,83,64,11};
        if(E2>=0 && E2<=9) P3=P[E2];
        else if (E2>=10&&E2<=99){
           E2= ((E2/10)+(E2%10))%10;
           int i=E2;
             P3=P[i];
        }
        if (P1+P2+P3==300) EXP1= lamtron(EXP1,75);
        if (P1+P2+P3<150) {
            EXP1=lamtron(EXP1,115);
            HP1=lamtron(HP1,85);
        }
         if (P1+P2+P3>=150&&P1+P2+P3!=300) {
            EXP1=lamtron(EXP1,120);
            HP1=lamtron(HP1,90);
        }
        checkEXP(EXP1);
        checkHP(HP1);
    }
    return HP1 + EXP1 + M1;
}
void tongcs(int & x){
    while (x>=10&&x<=99) {
        x=x/10+x%10;
    }
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
if (E3>99 ||E3<0) {return -99;}
     else {
              checkHP(HP1);
              checkEXP(EXP1);
              checkHP(HP2);
              checkEXP(EXP2);
    // TODO: Complete this functions
    int taxi[10][10];//Khởi tạo ma trận
    int i=0,j=0;
    for (int a=0; a<10;++a){
        for (int b=0;b<10;++b){
            taxi[a][b]=((E3*b)+(a*2))*(a-b); 
            if (taxi[a][b]>(E3*2)) i+=1;
            if (taxi[a][b]<(-E3))  j+=1;
        }
   
    }
    tongcs(i);
    tongcs(j);
    int diemtaxi=taxi[i][j];//Diem xe taxi
    //Duong cheo phai
    for(int x=-9;x<10;++x){
        int a=i+x;
        int b=j+x;
      if ((a>=0&&a<=9)&&(b>=0&&b<=9)){
         if (taxi[i][j]<=taxi[a][b])
            taxi[i][j]=taxi[a][b];
      }
    }
    //duong cheo trai
    for(int x=-9;x<10;++x){
        int a=i-x;
        int b=j+x;
      if ((a>=0&&a<=9)&&(b>=0&&b<=9)){
         if (taxi[i][j]<=taxi[a][b])
            taxi[i][j]=taxi[a][b];
      }
    }
    int diemSW=taxi[i][j];//Diem Sherlock & Watson
    if(abs(diemtaxi)>abs(diemSW)) 
        {  
              EXP1=lamtron(EXP1,88);
              EXP2=lamtron(EXP2,88);
              HP1=lamtron(HP1,90);
              HP2=lamtron(HP2,90);
              checkHP(HP1);
              checkEXP(EXP1);
              checkHP(HP2);
              checkEXP(EXP2);
              return diemtaxi;
        }
    else 
       {
              EXP1=lamtron(EXP1,112);
              EXP2=lamtron(EXP2,112);
              HP1=lamtron(HP1,110);
              HP2=lamtron(HP2,110);
              checkHP(HP1);
              checkEXP(EXP1);
              checkHP(HP2);
              checkEXP(EXP2);
              return diemSW;
       }
    }
 }  

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
      ///Tìm chuỗi se trước @
    char se[100];
    int x = 0;
    for (int i = 0; email[i]!='\0'; ++i) {
        if (email[i] == '@') {
            x = i;
            break;
        }
    }
    for (int i = 0; i < x; ++i) {
        se[i] = email[i];
    }
    se[x] = '\0';
    const char* chua = strstr(s, se);

    int sci = -1;
    for (int i = 0; s[i]!='\0'; ++i) { //Tìm sci nếu s chứa nhiều hơn 2 kí tự liên tiếp
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2])) {
            sci = i;
            break;
        }

    }
    int kiemtra = -1;
    for (int i = 0; s[i]!='\0'; ++i) {
        if (isdigit(s[i])) continue;
        else if (islower(s[i])) continue;
        else if (isupper(s[i])) continue;
        else if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') continue;
        else {
            kiemtra = i;
            break;
        }

    }
    int kytu = 0;
    for (int i = 0;s[i]!='\0'; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') kytu += 1;
    }

 while(1){
    if (strlen(s) > 20) {
        return -2;
        break;}
   else if (strlen(s) < 8) {
        return -1;
        break;}
    else if (chua) {
        int sei = chua - s;
        return -(300 + sei);
        break;}
    else if (sci != -1) {
        return -(400 + sci);
        break;}
    else if (kytu == 0) {
        return -5;
        break;}
else if (kiemtra != -1){
     return kiemtra;
     break;}
else {return -10;break;}
}
}
    


// Task 5
  int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int x = 0, max = 0;
const char* pass = arr_pwds[0];
for (int i = 0; i < num_pwds; ++i) {
    for (int j = 0; j < num_pwds; ++j) {
        if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
            x += 1;
            if (x > max || (x == max && strlen(arr_pwds[i]) > strlen(pass))) {
                max = x;
                pass = arr_pwds[i];
            }
        }
    }
    x = 0;
}
for (int i = 0; i < num_pwds; ++i) {
    if (strcmp(arr_pwds[i], pass) == 0) {
        max = i;
        break;
    }
}
 return max;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////