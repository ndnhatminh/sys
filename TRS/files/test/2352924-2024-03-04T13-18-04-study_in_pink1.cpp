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

void checkHP(int & HP){
    if(HP > 666){
        HP = 666;
    }else if(HP < 0){
        HP = 0;
    }
}
void checkEXP(int & EXP){
    if(EXP > 600){
        EXP = 600;
    }else if(EXP < 0){
        EXP = 0;
    }
}
void checkM(int & M){
    if(M>3000){
        M = 3000;
    }else if(M < 0){
        M = 0;
    }
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    checkEXP(EXP1);
    checkEXP(EXP2);
    if (E1<0 || E1>99)
      return -99;

    if(0<=E1 && E1<=3){
        if(E1==0){
            EXP2 = EXP2 + 29;
        }else if(E1==1){
            EXP2 = EXP2 + 45;
        }else if(E1==2){
            EXP2 = EXP2 + 75;            
        }else if(E1==3){
            EXP2 = EXP2 + (29 + 45 + 75);        
        }
        
        int D = E1*3 + EXP1*7;
        
        if(D%2 == 0){
            EXP1 = ceil(EXP1 + D/200.0);
        }else{
            EXP1 = ceil(EXP1 - D/100.0);
        }
        

    }else if(4<=E1 && E1<=99){
        if(4<=E1 && E1<=19){
            EXP2 = ceil(EXP2 + (E1/4.0 + 19));
        }else if(20<=E1 && E1<=49){
            EXP2 = ceil(EXP2 + (E1/9.0 + 21));
        }else if(50<=E1 && E1<=65){
            EXP2 = ceil(EXP2 + (E1/16.0 + 17));
        }else if(66<=E1 && E1<=79){
            EXP2 = ceil(EXP2 + (E1/4.0 + 19)); 
            if(EXP2>200){
                EXP2 = ceil(EXP2 + (E1/9.0 + 21));
            }
        }else if(80<=E1 && E1<=99){
                EXP2 = ceil(EXP2 + (E1/4.0 + 19)); 
                EXP2 = ceil(EXP2 + (E1/9.0 + 21));
                
            if(EXP2>400){
                EXP2 = ceil(EXP2 + (E1/16.0 + 17));
                EXP2 = ceil(EXP2*1.15);
            }
               
            
        }
        EXP1 = EXP1 - E1;
    }

    if(EXP1<0){
        EXP1 = 0;
    }else if(EXP1>600){
        EXP1 = 600;
    }

    if(EXP2<0){
        EXP2 = 0;
    }else if(EXP2>600){
        EXP2 = 600;
    }

    checkEXP(EXP1);
    checkEXP(EXP2);
    return EXP1+EXP2;
}

// Task 2
void conduong21(int & HP1, int & EXP1, int & M1){
    if(HP1 < 200){
        HP1 = ceil(HP1*13.0/10);
        M1 = M1 - 150;
    }else if(HP1 >= 200){
        HP1 = ceil(HP1*11.0/10);
        M1 = M1 - 70;
    }
    checkHP(HP1);
}

void conduong22(int & HP1, int & EXP1, int & M1){
    if(EXP1 < 400){
        M1 = M1 - 200;
    }else if(EXP1 >= 400){
        M1 = M1 - 120;
    }
    EXP1 = ceil(EXP1*113.0/100);
    checkEXP(EXP1);
}    
 
void conduong23(int & HP1, int & EXP1, int & M1){
    if(EXP1 < 300){
        M1 = M1 - 100;
    }else if(EXP1 >= 300){
        M1 = M1 - 120;
    }
    EXP1 = ceil(EXP1*9.0/10);
    checkEXP(EXP1);
}     

int traceLuggage(int &HP1, int &EXP1, int &M1, int e2) {
    if(e2>99 || e2<0){
        return -99;
    }
    checkEXP(EXP1);
    checkHP(HP1);
    // Con duong 1
    float S1 = sqrt(EXP1);
    int a1, n1 = S1;
    float p1;
    if (abs(EXP1 - n1 * n1) < abs(EXP1 - (n1 + 1) * (n1 + 1))) {
        a1 = n1 * n1;
        p1 = 100;
    } else {
        a1 = (n1 + 1) * (n1 + 1);
        p1 = ((float)EXP1 / a1 + 80) * 100 / 123.0;
        p1 = round(p1*100)/100;
    }
    
    // Con duong 2
    if (e2 % 2 == 0) {
        for(int i = 0; i<1; i++){
        if(M1 == 0){
            break;
        }    
        if(M1>0){
            conduong21(HP1, EXP1, M1);
        }
        if(M1>0){
            conduong22(HP1, EXP1, M1);
        }
        if(M1>0){
            conduong23(HP1, EXP1, M1);
        }
        }
        
        
        
    } else {
        int Ms = M1; // Ms = Money spend trong vong lap
        
        while (true) {
            if(M1 == 0){
                break;
            }
            
            conduong21(HP1, EXP1, M1);
            
            if(Ms - M1 > Ms * 0.5){
                break;
            }
            
            conduong22(HP1, EXP1, M1);
            
            if(Ms - M1 > Ms * 0.5){
                break;
            }
            
            conduong23(HP1, EXP1, M1);
            
            if(Ms - M1 > Ms * 0.5){
                break;
            }
        }
    }
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);

    HP1 = ceil(HP1 * 83.0/100);
    EXP1 = ceil(EXP1 * 117.0/100);

    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);

    float S2 = sqrt(EXP1);
    int a2, n2 = S2;
    float p2;
    if(abs(EXP1 - n2 * n2) < abs(EXP1 - (n2 + 1) * (n2 + 1))) {
        a2 = n2 * n2;
        p2 = 100;
    } else {
        a2 = (n2 + 1) * (n2 + 1);
        p2 = ((float)EXP1 / a2 + 80) * 100 / 123.0;
        p2 = round(p2*100)/100;
    }
    

    // Con duong 3
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int suM = 0, n = e2;
    if(e2 < 10) {
        suM = e2;
    } else if (e2 > 9) {
        suM += (n/10 + n % 10)%10; 
    }
    float p3 = p[suM];

    // Tong ket
    float ave = (p1 + p2 + p3)* 100.0/ 300;
    if (p1 == 100 && p2 == 100 && p3 == 100) {
        EXP1 = ceil(EXP1 * 75.0/100);
    } else {
        if (ave < 50) {
            HP1 = ceil(HP1 * 85.0/100);
            EXP1 = ceil(EXP1 * 115.0/100);
        }else if(ave >= 50){
            HP1 = ceil(HP1 * 9.0/10);
            EXP1 = ceil(EXP1 * 12.0/10);
        }
    }
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int e3){
if (e3<0 || e3>99)
      return -99;
long long taxi[10][10];
for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
        taxi[i][j] = ((e3*j) + (i*2))*(i-j); 
    }
}
int M = 0, n = 0; //M = duong, n =aM
for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
        if(taxi[i][j] > 0 && taxi[i][j]>e3*2){
            M++;
        }
        if(taxi[i][j] < 0 && taxi[i][j]<-e3){
            n++;
        } 
    }
}

int a=M, b=n;
while(a>=10){
    a=a%10 + a/10;
}
while(b>=10){
    b=b%10 + b/10;
}
long long dtaxi = taxi[a][b];
long long Max = taxi[a][b];

for(int i = a, j = b; 0 <= i && i <= 9 && 0 <= j && j <= 9; i++ , j++){
    if(taxi[i][j] > Max){
            Max = taxi[i][j];
    }
}

for(int i = a, j = b; 0 <= i && i <= 9 && 0 <= j && j <= 9; i++ , j--){
    if(taxi[i][j] > Max){
            Max = taxi[i][j];
    }
}

for(int i = a, j = b; 0 <= i && i <= 9 && 0 <= j && j <= 9; i-- , j++){
    if(taxi[i][j] > Max){
            Max = taxi[i][j];
    }
}

for(int i = a, j = b; 0 <= i && i <= 9 && 0 <= j && j <= 9; i-- , j--){
    if(taxi[i][j] > Max){
            Max = taxi[i][j];
    }
}


if(abs(dtaxi)>Max){
    EXP1 = ceil(EXP1*88.0/100); 
    EXP2 = ceil(EXP2*88.0/100);
    HP1 = ceil(HP1*90.0/100);  
    HP2 = ceil(HP2*90.0/100);  
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    return dtaxi;
}else{
    EXP1 = ceil(EXP1*112.0/100); 
    EXP2 = ceil(EXP2*112.0/100);
    HP1 = ceil(HP1*110.0/100);  
    HP2 = ceil(HP2*110.0/100);  
    checkEXP(EXP1);
    checkEXP(EXP2);
    checkHP(HP1);
    checkHP(HP2);
    return Max;
    }
}

// Task 4
int checkPassword(const char *s, const char *eMail){ 
    string Mail(eMail), pass(s), se;
    size_t check1 = Mail.find('@');
    se = Mail.substr(0,check1);
   
    if(pass.length()<8){
        return -1;
    }else if(pass.length()>20){
        return -2;
    }

    int k = pass.find(se);
    if(pass.find(se)!=string::npos){
        return -(300 + k);
    }
    
    for(int i = 0; i < pass.length(); i++){
        if(pass[i] == pass[i+1] && pass[i+1] == pass[i+2]){
            return -(400+i);
        }
    }
    
    int check2=0;
    
    int M=0;
    for(int i = 0; i<pass.length(); i++){
        if(pass[i] == '@' || pass[i] == '#' || pass[i] == '$' ||  pass[i] == '%' || pass[i] == '!'){
            M++;
        }
    }
    if(M==0){
        return -5;
    }

    
    for(int i = 0; i<pass.length(); i++){
        if(!(pass[i] == '@' || pass[i] == '#' || pass[i] == '$' ||  pass[i] == '%' || pass[i] == '!' || 'A'<=pass[i] && pass[i]<='Z' ||'a'<=pass[i] && pass[i]<='z' || '1'<=pass[i]&& pass[i]<='9')){
            return i;
        }
    }
    
    return -10;
        
}
    

// Task 5
int findCorrectPassword(const char * arr_pwds[], int nuM_pwds) {
    int n=0, M=0, dodai=0, Max=0, vitri=0;
    
    for (int i = 0; i < nuM_pwds; ++i) {
        const string& arri = arr_pwds[i];
        n=0;
        for (int j = 0; j < nuM_pwds; ++j) {
            if (arr_pwds[j] == arri) {
                n++;
            }
        }

        if (n > Max || (n == Max && arri.length() > dodai)) {
            vitri = i;
            Max = n;
            dodai = arri.length();
        }
    }

    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////