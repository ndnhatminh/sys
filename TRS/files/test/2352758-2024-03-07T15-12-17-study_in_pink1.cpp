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


// Check EXP funtion
float checkEXP(float &exp){
    if (exp > 600){
        exp=600;
    }else if(exp<0){
        exp=0;
    }
    return exp;
}
//Check HP funtion
float checkHP(float &hp){
    if (hp > 666){
        hp=666;
    }else if(hp<0){
        hp=0;
    }
    return hp;
}
//Check M funtion
float checkM(float &m){
    if (m > 3000){
        m=3000;
    }else if(m<0){
        m=0;
    }
    return m;
}

//CEIL Funtion





// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    
    float exp1=1.0*EXP1;
    float exp2=1.0*EXP2;
    float e1=1.0*E1;
    exp1=checkEXP(exp1);
    exp2=checkEXP(exp2);
    int D = E1 *3 + EXP1 *7;
    if (E1 > -1 && E1 < 4){       //Truong hop 1
        if (E1 == 0){
            exp2 = exp2 + 29;
            exp2=checkEXP(exp2);
        }else if (E1 == 1){
            exp2 = exp2 +45 ;
            exp2=checkEXP(exp2);
        }else if (E1 == 2){
            exp2 = exp2 +75 ;
            exp2=checkEXP(exp2);
        }else if (E1 == 3) {
            exp2 = exp2 +29 +45 +75 ;
            exp2=checkEXP(exp2);
        }    
        if (D % 2 == 0){
        exp1 = exp1 + (1.0*D/200);
        }else {exp1 = exp1 - (1.0*D/100);}
        exp2=ceil(exp2);
        exp2=checkEXP(exp2);
        EXP2=exp2;
        exp1=ceil(exp1);
        exp1=checkEXP(exp1);      //check EXP1
        EXP1=exp1;
    }
    else {               //Truong hop 2
        if (E1 >= 4 && E1 <= 19){
            exp2 = exp2 + e1/4 +19 ;
            exp2=ceil(exp2);
            exp2=checkEXP(exp2);
        }else if (E1 >= 20 && E1 <= 49){
            exp2 = exp2 + e1/9 +21 ;
            exp2=ceil(exp2);
            exp2=checkEXP(exp2);
        }else if (E1 >= 50 && E1 <=65){
            exp2 = exp2 + e1/16 + 17 ;
            exp2=ceil(exp2);
            exp2=checkEXP(exp2);
        }else if (E1 >= 66 && E1 <=79){
            exp2 = exp2 + e1/4 +19 ;
            exp2=ceil(exp2);
            exp2=checkEXP(exp2);
            if( exp2 > 200 ){
                exp2 = exp2 + e1/9 +21 ;
                exp2=ceil(exp2);
                exp2=checkEXP(exp2);
            }
        }else if (E1 >= 80 && E1 <=99 ){
            exp2 = exp2 + e1/4 +19 ;
            exp2=ceil(exp2);
            exp2=checkEXP(exp2);
            exp2 = exp2 + e1/9 +21 ;
            exp2=ceil(exp2);
            exp2=checkEXP(exp2);
            if ( exp2 > 400 ) {
                exp2 = exp2 + e1/16 + 17 ;
                exp2=checkEXP(exp2);
                exp2=ceil(exp2);
                exp2 = exp2 + exp2*0.15 ;
                exp2=checkEXP(exp2);
                exp2=ceil(exp2);
            }
        }else {return -99;}
        exp1 = exp1 - e1;
        exp1=ceil(exp1);
        exp2=ceil(exp2);
        exp1=checkEXP(exp1);      //check EXP1
        exp2=checkEXP(exp2);      //check EXP2
        EXP1=exp1;
        EXP2=exp2;
        
    }   
    
    return EXP1 + EXP2;
}

//Find Square Number
int findSquareNumber(int N) {
    float a= floor(sqrt(N)), b= ceil(sqrt(N));
    if (N - (a*a) < (b*b) - N ){
        return a*a;
    }else return b*b;
    
}
// Task 2

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 >=0 && E2 <=99){
        float hp1=1.0*HP1;
        float exp1=1.0*EXP1;
        float m1=1.0*M1;
        float halfM=0.5*m1;
        hp1=checkHP(hp1);
        exp1=checkEXP(exp1);
        m1=checkM(m1);
        //Con đường 1//
        float P1;
        int S =findSquareNumber(EXP1);  //tìm S nè
        if ( EXP1 >= S){
            P1=1;       
        }else{P1=(exp1/(1.0* S)+80)/123;}
        //Con đường 2//
        if (E2 % 2 == 1){        
            while ( halfM  < m1){
                if (hp1<200){        //Mua đồ ăn
                    hp1=hp1*1.3;
                    hp1=ceil(hp1);
                    hp1=checkHP(hp1);
                    m1=m1-150;
                    m1=ceil(m1);
                    checkM(m1);
                    if (m1 < halfM){break;}
                    
                }else{
                    hp1=hp1*1.1;
                    hp1=ceil(hp1);
                    hp1=checkHP(hp1);
                    m1=m1-70;
                    m1=ceil(m1);
                    checkM(m1);
                    if (m1 < halfM){break;}
                }
                if (exp1<400){        //Đi taxi hay xe ngựa
                    m1=m1-200;
                    m1=ceil(m1);
                    exp1*=1.13;
                    exp1=ceil(exp1);
                    exp1=checkEXP(exp1);
                    checkM(m1);
                    if (m1 < halfM){break;}
                }else {
                    m1=m1-120;
                    m1=ceil(m1);
                    exp1*=1.13;
                    exp1=ceil(exp1);
                    exp1=checkEXP(exp1);
                    checkM(m1);
                    if (m1 < halfM){break;}
                }
                if (exp1<300){       //Ông ăn xin
                    m1=m1-100;
                    m1=ceil(m1);
                    exp1=exp1*0.9;
                    exp1=ceil(exp1);
                    exp1=checkEXP(exp1);
                    checkM(m1);
                    if (m1 < halfM){break;}
                }else{
                    m1=m1-120;
                    m1=ceil(m1);
                    exp1=exp1*0.9;
                    exp1=ceil(exp1);
                    exp1=checkEXP(exp1);
                    checkM(m1);
                    if (m1 < halfM){break;}
                }
            }
            hp1=hp1*0.83;
            hp1=ceil(hp1);
            hp1=checkHP(hp1);
            exp1=exp1*1.17;
            exp1=ceil(exp1);
            exp1=checkEXP(exp1);
            m1=ceil(m1);
            checkM(m1);
        }else{
            for(int i=1;i==1;i++){
                if (hp1<200 ){        //Mua đồ ăn
                    hp1=hp1*1.3;
                    hp1=ceil(hp1);
                    hp1=checkHP(hp1);
                    m1=m1-150;
                    m1=ceil(m1);
                    checkM(m1);
                    if (m1 == 0){break;} 
                }else if (hp1>=200 ){
                    hp1=hp1*1.1;
                    hp1=ceil(hp1);
                    hp1=checkHP(hp1);
                    m1=m1-70;       
                    m1=ceil(m1);    
                    checkM(m1);  
                    if (m1 == 0){break;} 
                }
                if (exp1<400 ){               //Đi taxi hay xe ngựa
                    m1=m1-200;
                    m1=ceil(m1);
                    checkM(m1);
                    exp1=exp1*1.13;  
                    exp1=ceil(exp1); 
                    checkEXP(exp1);
                    if (m1 == 0){break;} 

                }else if (exp1>=400 ) {
                    m1=m1-120;
                    m1=ceil(m1);
                    checkM(m1);
                    exp1=exp1*1.13;
                    exp1=ceil(exp1);
                    checkEXP(exp1);
                    if (m1 == 0){break;} 
                }
                if (exp1<300 ){          //Ông ăn xin
                    m1=m1-100;
                    m1=ceil(m1);
                    checkM(m1);
                    exp1=exp1*0.9;
                    exp1=ceil(exp1);
                    exp1=checkEXP(exp1);
                    if (m1 == 0){break;}              
                }else if (exp1>=300 ) {
                    m1=m1-120;
                    m1=ceil(m1);
                    checkM(m1);
                    exp1=exp1*0.9;
                    exp1=ceil(exp1);
                    exp1=checkEXP(exp1);  
                    if (m1 == 0){break;}                       
                }           
            } 
            hp1=hp1*0.83;
            hp1=ceil(hp1);
            hp1=checkHP(hp1);
            exp1=exp1*1.17;
            exp1=ceil(exp1);
            exp1=checkEXP(exp1);
            m1=ceil(m1);
            checkM(m1);
        }
        EXP1=exp1;
        float P2;
        S = findSquareNumber(EXP1);  //tìm S nè
        if (EXP1 >= S){
            P2=1;       
        }else{P2=(exp1/(1.0* S)+80)/123;}
        //Con đường 3//
        float P[10]={0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11};
        float P3;
        if(E2 < 10 && E2 >= 0){
            P3 = P[E2];
        }else if (E2 >=10 && E2 <100){
            int i=E2 % 10;
            i+= E2/10;
            P3= P[i % 10];
        }
        
        float averageP= (P1 + P2 + P3)/3;           /////Tinhs trung binh
        exp1=ceil(exp1);
        EXP1=exp1;
        m1=ceil(m1);
        M1=m1;
        hp1=ceil(hp1);
        HP1=hp1;
        if (averageP == 1){
            exp1=exp1*0.75;
            exp1=ceil(exp1);
            checkEXP(exp1);
            EXP1=exp1;
        }else if(averageP < 1 && averageP > 0.5){
            hp1=hp1*0.9;
            exp1=exp1*1.2;
            hp1=ceil(hp1);
            exp1=ceil(exp1);
            hp1=checkHP(hp1);
            exp1=checkEXP(exp1);
            HP1=hp1;
            EXP1=exp1;
        }else if (averageP>=0){
            hp1=hp1*0.85;
            exp1=exp1*1.15;
            hp1=ceil(hp1);
            exp1=ceil(exp1);
            hp1=checkHP(hp1);
            exp1=checkEXP(exp1);
            HP1=hp1;
            EXP1=exp1;
        }
        return HP1 + EXP1 + M1;
    }else
    return -99;
}

//task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3>=0 && E3 <= 99){
    
        float hp1,hp2,exp1,exp2;
        hp1=HP1;
        hp2=HP2;
        exp1=EXP1;
        exp2=EXP2;
        hp1=checkHP(hp1);
        hp2=checkHP(hp2);
        exp1=checkEXP(exp1);
        exp2=checkEXP(exp2);
        int pos=0;
        int neg=0;
        int taxi[10][10];
        for (int i=0;i<10;i++){                       //Taxi Matrix
            for(int j=0;j<10;j++){
                taxi[i][j] = ((E3*j) + (i*2)) * (i-j);
                if (taxi[i][j] > 2*E3){
                    pos+=1;
                }else if (taxi[i][j] < E3*(-1)){
                    neg+=1;
                }
            }
        }
        if(pos < 10 && pos > 0){                      //Tìm điểm i
           pos = pos ;
        }else if (pos >=10 && pos <100){
            int i=pos % 10;
            i+= pos/10;
            if(i < 10 && i > 0){                      
                pos = i ;
            }else if (i >=10 && i <100){
                int j=i % 10;
                j+= i/10;
                pos= j;
            }
        }
        if(neg < 10 && neg > 0){                       //Tìm điểm j
            neg = neg ;
        }else if (neg >=10 && neg <100){
            int i=neg % 10;
            i+= neg/10;
            if(i < 10 && i > 0){                      
                neg = i ;
            }else if (i >=10 && i <100){
                int j=i % 10;
                j+= i/10;
                neg= j;
            }
        }
        int max[10][10];                              //Max Matrix        
        for (int i=0;i<10;i++){                        
            for(int j=0;j<10;j++){
                max[i][j] = ((E3*j) + (i*2)) * (i-j);             
            }
            
        }
                for(int a=1;a<10;a++){
                    if (pos+a<10 && neg+a<10){
                        if(max[pos+a][neg+a]>max[pos][neg]){
                            max[pos][neg]=max[pos+a][neg+a];
                        }
                    }
                }
                for(int a=1;a<10;a++){
                    if (pos-a>=0 && neg-a>=0){
                        if(max[pos-a][neg-a]>max[pos][neg]){
                            max[pos][neg]=max[pos-a][neg-a];
                        }
                    }
                }
                for(int a=1;a<10;a++){
                    if (pos-a>=0 && neg+a<10){
                        if(max[pos-a][neg+a]>max[pos][neg]){
                            max[pos][neg]=max[pos-a][neg+a];
                            }
                    }
                }
                for(int a=1;a<10;a++){
                    if (pos+a<10 && neg-a>=0){
                        if(max[pos+a][neg-a]>max[pos][neg]){
                            max[pos][neg]=max[pos+a][neg-a];
                        }
                    }
                }
        int taxilastNum=abs(taxi[pos][neg]);
        int maxlastNum=abs(max[pos][neg]);
        if(maxlastNum >= taxilastNum){
            exp1*=1.12;
            exp2*=1.12;
            hp1*=1.1;
            hp2*=1.1;
            hp1=ceil(hp1);
            hp2=ceil(hp2);
            exp1=ceil(exp1);
            exp2=ceil(exp2);
            checkHP(hp1);
            checkHP(hp2);
            checkEXP(exp1);
            checkEXP(exp2);
            EXP1=exp1;
            EXP2=exp2;
            HP1=hp1;
            HP2=hp2; 
            return max[pos][neg];
        }else{
            exp1*=0.88;
            exp2*=0.88;
            hp1*=0.9;
            hp2*=0.9;
            hp1=ceil(hp1);
            hp2=ceil(hp2);
            exp1=ceil(exp1);
            exp2=ceil(exp2);
            checkHP(hp1);
            checkHP(hp2);
            checkEXP(exp1);
            checkEXP(exp2);
            EXP1=exp1;
            EXP2=exp2;
            HP1=hp1;
            HP2=hp2; 
            return taxi[pos][neg];
        }       
    }
    else{return -99;}
}


int checkLen(const char * s){    //Check length
        if (strlen(s) < 8){
            return 1;
        }else if (strlen(s) > 20){
            return 2;
        }else return 0 ;
    }

bool isValid(const char * pwd, char spec[], int siz, int& vipham)
{
    bool hasSpecial = false;
    for(int i = 0; i < strlen(pwd); i++)
    {
        for(int x = 0; x < siz; x++)
            if(pwd[i] == spec[x]){
                hasSpecial = true;
                vipham = i; 
                break;   }    
    }
    return hasSpecial;
}

string makeSE(const char* mail, char* mailse) {
    int i;
    for (i = 0; mail[i] != '@'; i++) {
        mailse[i] = mail[i];
    }
    mailse[i] = '\0'; 
    return mailse;
}

bool isHasSe(const char* pass, const char* se, int& i) { ///// HAS SE CHECK
    int a = strlen(se);
    string var;
    int result;
    for ( i = 0; i < strlen(pass); i++) {
        if (pass[i] == se[0]) { 
            for (int b = 0; b < a; b++) {
                var += pass[i + b]; 
            }
            if (var == se) {
                result = -(300 + i);
                return true;
            }
        }
    }
    return false; 
}

bool sameletter(const char * pass , int& i){
    for ( i = 0; i < strlen(pass); i++){
        if (pass[i] == pass[i+1] && pass[i] == pass[i+2]){
            return true;
        }
    }
    return false;
}



// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sei=0;
    int sci=0;
    int vipham=0;
    char spe1[] = {'~','^','&','*','(',')','-','_','=','+','[',']','{','}','|','`',':',';','<',',','>','.','/','?'};
    char spe2[] = {'!','@','#','$','%'};
    int numspe1 = sizeof(spe1);
    int numspe2 = sizeof(spe2);
    char se[100]; 
    makeSE(email , se);
    if (checkLen(s) == 0){
        if( !isHasSe(s,se,sei) ){
            if(!sameletter(s,sci)){
                if(isValid(s,spe2,numspe2,vipham)){
                    if(!isValid(s,spe1,numspe1,vipham)){
                        return -10;
                    }else return vipham;
                }else return -5;
            }else return -(400+sci);
        }else return -(300+sei);

    }else if (checkLen(s) == 1){
        return -1;
    }else return -2;
    
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int freq[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                freq[i] += 1;
            }
        }
    }

    int resu = 0;
    for (int i = 1; i < num_pwds; i++) {
        if (freq[i] > freq[resu] || (freq[i] == freq[resu] && strlen(arr_pwds[i]) > strlen(arr_pwds[resu]))) {
            resu = i;
        }
    }

    return resu;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////