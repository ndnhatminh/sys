#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M12,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT M1ODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M12
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
void check(int &dulieu, int kieu) // kieu 0:HP , kieu 1:EXP , kieu 2:M1
{
    if(kieu==0){ dulieu = ((dulieu>666)? 666:((dulieu<0)?0:dulieu));}
  if(kieu==1){ dulieu = ((dulieu>600)? 600:((dulieu<0)?0:dulieu));}
   if(kieu==2){ dulieu = ((dulieu>3000)? 3000:((dulieu<0)?0:dulieu));}
  } 

int Customceil(double value) {
    return static_cast<int>(value) + ((value - static_cast<int>(value)) > 0.0);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if (e1>=0 && e1<=99){
if (e1==0)  {exp2+=29;}
else if (e1==1)  {exp2+=45;}
else if (e1==2)  {exp2+=75;}
else if (e1==3)  {exp2+=149;}
    if (e1>=0 && e1<=3){int D=e1*3+exp1*7;
    if (D%2==0){
        exp1 =static_cast<int>(Customceil(exp1+static_cast<double>(D/200.0))); check(exp1,1); check(exp2,1);
    } else  { exp1 =static_cast<int>(Customceil(exp1-static_cast<double>(D/100.0)));check(exp1,1);check(exp2,1);}
    }
    if (e1>=4 && e1<=19)  {exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/4.0+19)));check(exp2,1);}
else if (e1>=20 && e1<=49) {exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/9.0+21)));check(exp2,1);}
else if (e1>=50 && e1<=65) {exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/16.0+17)));check(exp2,1);}
else if (e1>=66 && e1<=79) {exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/4.0+19))); check(exp2,1);
                            if (exp2>200){exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/9.0+21)));check(exp2,1); }}
else if (e1>=80 && e1<=99) {exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/4.0+19)));check(exp2,1);
                            exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/9.0+21)));check(exp2,1);
                            if (exp2>400){exp2 = static_cast<int>(Customceil(static_cast<double>(exp2+static_cast<double>(e1)/16.0+17)));check(exp2,1);
                            exp2 = static_cast<int>(Customceil(exp2*1.15));check(exp2,1);}}
   if (e1>=4 && e1<=99){exp1-=e1;check(exp1,1);}

     check(exp1,1);
     check(exp2,1);
    return exp1 + exp2;} else {return -99;}
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
   int S1,S2,PTB,mon;
    double P1,P2,P3;
  if(E2<0 || E2>99) {return -99;}
    
        int sonho1 = sqrt(EXP1);
    int solon1 = sqrt(EXP1)+1;
    
   if ((abs(pow(sonho1,2)-EXP1))>(pow(solon1,2)-EXP1)){ S1= solon1*solon1;
   } else { S1= sonho1*sonho1 ;}
   if (EXP1>=S1){  P1=100;}
   else {  P1=((static_cast<double>(EXP1/S1))+80)/1.23;}
    if( E2%2==1) {
        int mon= M1/2;
        while( M1>= mon){
            if (HP1<200){
                HP1 = static_cast<int>(Customceil(HP1*1.30-1e-7));
                M1-=150;
                check(HP1,0);
                check(M1,2);
                if (M1<mon){ break;}
            } else if (HP1>=200){
                HP1 = static_cast<int>(Customceil(HP1*1.10-1e-7));
                M1-=70;
                check(HP1,0);
                check(M1,2);
                if (M1<mon){ break;}
            }
            if (EXP1<400){
                M1-=200;
                  EXP1 = static_cast<int>(Customceil(EXP1*1.13-1e-7));
                  check(EXP1,1);
                check(M1,2);
                if (M1<mon){ break;}
            } else if(EXP1>400) {
                M1-=120;
                EXP1 = static_cast<int>(Customceil(EXP1*1.13-1e-7));
                check(EXP1,1);
                check(M1,2);
                if (M1<mon){ break;}

            }
            if (EXP1<300){
                M1-=100;
                  EXP1 = static_cast<int>(Customceil(EXP1*0.9-1e-7));
                  check(EXP1,1);
                check(M1,2);
                if (M1<mon){ break;}
            } else {
                M1-=120;
                  EXP1 = static_cast<int>(Customceil(EXP1*0.9-1e-7));
                  check(EXP1,1);
                check(M1,2);
                if (M1<mon){ break;}
            } 
        }
    } else if(E2%2==0) { 

            if (HP1<200){
                HP1 = static_cast<int>(Customceil(HP1*1.30-1e-7));
                M1-=150;
                check(HP1,0);
                check(M1,2);
                 
            } else if (HP1>=200){
                HP1 = static_cast<int>(Customceil(HP1*1.10-1e-7));
                M1-=70;
                check(HP1,0);
                check(M1,2);
                 
            }
              if (M1>0){
                if (EXP1<400){
                M1-=200;
                  EXP1 = static_cast<int>(Customceil(EXP1*1.13-1e-7));
                  check(EXP1,1);
                check(M1,2);
                  
            } else {
                M1-=120;
                EXP1 = static_cast<int>(Customceil(EXP1*1.13-1e-7));
                check(EXP1,1);
                check(M1,2);
                

            }} if(M1>0){
             
            if (EXP1<300){
                M1-=100;
                  EXP1 = static_cast<int>(Customceil(EXP1*0.9-1e-7));
                  check(EXP1,1);
                check(M1,2);
                 
            } else {
                M1-=120;
                  EXP1 = static_cast<int>(Customceil(EXP1*0.9-1e-7));
                  check(EXP1,1);
                check(M1,2);
                 
            }    
            }

    }     EXP1 = static_cast<int>(Customceil(EXP1*1.17-1e-7));check(EXP1,1);
              
          HP1 = static_cast<int>(Customceil(HP1*0.83-1e-7));check(HP1,0);
              

   int sonho2 = sqrt(EXP1);
   int solon2 = sqrt(EXP1)+1;
   if ((abs(pow(sonho2,2)-EXP1))>(pow(solon2,2)-EXP1)){ S2= solon2*solon2;
   } else { S2=sonho2*sonho2;}
   if (EXP1>=S2){  P2=100;}
   else {  P2=((EXP1/S2)+80)/1.23;}
   
   int P[]={32,47,28,79,100,50,22,83,64,11};
    if ( E2>=0 && E2<=9 ){
         P3=P[E2];
    } else if (E2>=0 && E2<=99){
        int nguyen =E2/10;
        int du = E2%10;
        int i= du + nguyen;
        if (i<10){
            P3=P[i];
        } else if (i>=10){
            P3=P[i%10];
        }
    }
    
     PTB = (P1+P2+P3)/3;
    
    if (P1==100 && P2==100 && P3==100){
        EXP1 = static_cast<int>(Customceil(EXP1*0.75));check(EXP1,1);
            
    } else 
      if ( PTB <50){
        HP1 = static_cast<int>(Customceil(HP1*0.85-1e-7));
        EXP1 = static_cast<int>(Customceil(EXP1*1.15-1e-7));
        check(EXP1,1);
                check(HP1,0);
         } else if(PTB>=50) {
            EXP1 = static_cast<int>(Customceil(EXP1*1.20-1e-7));
            HP1 = static_cast<int>(Customceil(HP1*0.9-1e-7));
            check(EXP1,1);
                check(HP1,0);
         } 
            
             
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99) {return -99;}

    // Declare and initialize a 10x10 matrix with 0 values
    int bando[10][10] = {0};
   int duongcheo1[10]={0};
    int duongcheo2[10]={0};
     int duongcheo3[10]={0};
      int duongcheo4[10]={0};
    int upper=0;
    int lower=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            bando[i][j] = ((E3*j)+(i*2))*(i-j);
            if (bando[i][j]>(E3*2)){ upper++;
            } else if (bando[i][j]<-E3){ lower++;}
        }
    }  
 while(upper>9){
        upper = (upper/10) + (upper%10);
    }
    while(lower>9){
        lower = (lower/10) + (lower%10);
    } 
    
 
    
    int i = upper;
    int j = lower;
    int k=0;
   
    while( i>=0 && i<10 && j >=0 && j<10){
        int cheophai1 = bando[i][j];
        duongcheo1[k++] = cheophai1;
        i++;
        j++; 
    
    }   
    i=upper;
    j=lower;
    
    while( i>=0 && i<10 && j >=0 && j<10){
        int cheophai2 = bando[i][j];
        duongcheo2[k++] = cheophai2;
        i--;
        j++;
    
     } i=upper;
    j=lower;
    
    while( i>=0 && i<10 && j >=0 && j<10){
        int cheophai3 = bando[i][j];
        duongcheo3[k++] = cheophai3;
        i++;
        j--;
    } i=upper;
    j=lower;
    while( i>=0 && i<10 && j >=0 && j<10){
        int cheophai4 = bando[i][j];
       duongcheo4[k++] = cheophai4;
        i--;
        j--;
    }
    
    int max = duongcheo1[0]; 
    for (int i = 0; i < 10; ++i) {
        if (duongcheo1[i] > max)
            max = duongcheo1[i];
        if (duongcheo2[i] > max)
            max = duongcheo2[i];
        if (duongcheo3[i] > max)
            max = duongcheo3[i];
        if (duongcheo4[i] > max)
            max = duongcheo4[i];
    }
 
    if (abs(bando[upper][lower])> max){
        EXP1 = (Customceil(EXP1*0.88-1e-7));check(EXP1,1);
        EXP2 = (Customceil(EXP2*0.88-1e-7));check(EXP2,1);
        HP1 = (Customceil(HP1*0.9-1e-7));check(HP1,1);
        HP2 = (Customceil(HP2*0.9-1e-7));check(HP2,1);
    } else {
       EXP1 = (Customceil(EXP1*1.12-1e-7));check(EXP1,1);
        EXP2 = (Customceil(EXP2*1.12-1e-7));check(EXP2,1);
        HP1 = (Customceil(HP1*1.1-1e-7));check(HP1,1);
        HP2 = (Customceil(HP2*1.1-1e-7));check(HP2,1); 
    }
    if (abs(bando[upper][lower])> max){
        return bando[upper][lower];
    } else { 
        
        return max;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = email;
    se = se.substr(0, se.find('@'));

    int s_length = strlen(s);
    int se_length = se.length();

    if (s_length < 8)
        return -1;
    else if (s_length > 20)
        return -2;
    else {
        size_t pos = string(s).find(se);
        if (pos !=string::npos)
    return -(300 + static_cast<int>(pos));

        else {
            for (int i = 0; i < s_length - 2; ++i) {
                if (s[i] == s[i + 1] && s[i] == s[i + 2])
                    return -(400 + i);
            }
        }
    }
    bool specialChar(const char* s) ;{
    int len= strlen(s);
    for (int i=0; i< len; i++) {
        if (s[i] == '!' || s[i] == '$' || s[i]== '%' || s[i]== '#' || s[i] == '@')
        return true;
    }
    return false;
}
   if (!specialChar(s))
        return -5;
    return -10;
}

  
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int appear[num_pwds] ={0};
    int length[num_pwds] ={0};
    string arr_pwds_cstr[num_pwds];


    for (int i = 0; i < num_pwds; i++) {
        arr_pwds_cstr[i] = arr_pwds[i];
    }
    for (int i=0; i<num_pwds; i++){
        string password = arr_pwds_cstr[i];
        appear[i]++;
        for (int j=0; j<i;j++){
            if(arr_pwds_cstr[j]== password){
            appear[i]++;
            
        }
    }
    length[i] = strlen(password.c_str());}
    int max_app=0;
    int max_len=0;
    string rightpass;
    for(int i=0; i<num_pwds;i++){
       if( appear[i]>max_app || (appear[i]==max_app && length[i]==max_len)){
        max_app= appear[i];
        max_len=length[i];
        rightpass = arr_pwds[i];
       }
    }
    for (int i=0; i<num_pwds; i++){
        if (rightpass == arr_pwds[i]){
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////