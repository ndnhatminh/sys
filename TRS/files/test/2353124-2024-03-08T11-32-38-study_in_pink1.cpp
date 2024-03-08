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
int roundup(float i){
    int j=floor(i);
    if (j<i){j++;}
    return j;
}

int minmaxEXP(int & i) {
    if (i < 0) { i = 0; }
    else if (i > 600) { i = 600; }
    return i;
}

int minmaxHP(int & i) {
    if (i < 0) { i = 0; }
    else if (i > 666) { i = 666; }
    return i;
}

int minmaxM(int & i) {
    if (i < 0) { i = 0; }
    else if (i > 3000) { i = 3000; }
    return i;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if(e1>=0 && e1<=99){
        minmaxEXP(exp1);
        minmaxEXP(exp2);
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) { exp2 += 29; }
            else if (e1 == 1) { exp2 += 45; }
            else if (e1 == 2) { exp2 += 75; }
            else if (e1 == 3) { exp2 += 149; }
            
            int D = e1 * 3 + exp1 * 7;
            if (D%2==0) { exp1=roundup(exp1 + D / 200.0); }
            else { exp1=roundup(exp1 - D / 100.0); }

        }

        else if (e1 >= 4 && e1 <= 99){
            if (e1>=4&&e1<=19){exp2+=roundup(e1/4.0+19);}
            else if (e1>=20 && e1<=49){exp2+=roundup(e1/9.0+21);}
            else if (e1>= 50 && e1<=65){exp2+=roundup(e1/16.0+17);}
            else if (e1>=66 && e1<=79){
                exp2+=roundup(e1/4.0+19);
                if (exp2>200){exp2+=roundup(e1/9.0+21);}
                }
            else if (e1>=80 && e1<=99){
                exp2+=roundup(e1/4.0+19);
                exp2+=roundup(e1/9.0+21);
                if (exp2>400){exp2+=roundup(e1/16.0+17); exp2=roundup(exp2*1.15);}
                }
            exp1=exp1-e1;
        }
        minmaxEXP(exp1);
        minmaxEXP(exp2);
    }
    else {return -99;}

    return exp1 + exp2; 
    
}

// Task 2
int npSquare(int i){
    int j=pow(roundup(sqrt(i*1.0)),2);
    int k=pow(floor(sqrt(i*1.0)),2);
    if (abs(j-i)>abs(i-k)){return k;}
    else {return j;}
}

int sumof2digitNum(int i){
    int j=(i/10)+(i%10);
    return j;
}

int road2event(int & hp, int & exp, float & m, int condition){ 
    if (m>=condition){
        if (hp<200){hp=roundup(hp*1.3); m-=150; minmaxHP(hp);
            if (m>=condition){
                if (exp<400){m-=200; exp=roundup(exp*1.13); minmaxEXP(exp);
                    if(m>=condition){
                        if (exp<300){m-=100; exp=roundup(exp*0.9); minmaxEXP(exp);}
                        else{m-=120; exp=roundup(exp*0.9); minmaxEXP(exp);}
                    }
                }
                else{m-=120; exp=roundup(exp*1.13);minmaxEXP(exp);
                    if(m>=condition){
                        if (exp<300){m-=100; exp=roundup(exp*0.9);minmaxEXP(exp);}
                        else{m-=120; exp=roundup(exp*0.9);minmaxEXP(exp);}
                    }
                }
            }
        }
        else {
            hp=roundup(hp*1.1);m-=70; minmaxHP(hp);
            if (m>=condition){
                if (exp<400){m-=200; exp=roundup(exp*1.13);minmaxEXP(exp);
                     if(m>=condition){
                         if (exp<300){m-=100; exp=roundup(exp*0.9);minmaxEXP(exp);}
                         else{m-=120; exp=roundup(exp*0.9);minmaxEXP(exp);}
                    }
                }
                else{m-=120; exp=roundup(exp*1.13);minmaxEXP(exp);
                     if(m>=condition){
                        if (exp<300){m-=100; exp=roundup(exp*0.9);minmaxEXP(exp);}
                        else{m-=120; exp=roundup(exp*0.9);minmaxEXP(exp);}
                    }
                }
            }                     
        }
    } 
    return 0;                        
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    if (E2>=0 && E2<=99){
        
        minmaxEXP(EXP1);
        minmaxHP(HP1);
        minmaxM(M1);
        float P1, P2,P3;
        
        //Road 1:
        int S1=npSquare(EXP1);
        if (EXP1>=S1){ P1=100;}
        else {P1=(1.0*EXP1/S1+80)/1.23;}

        //Road2:
        if (E2%2==0){
            float altM1=M1*1.0;
            road2event(HP1,EXP1,altM1,1);
            HP1=roundup(0.83*HP1); EXP1=roundup(1.17*EXP1);M1=altM1;
            minmaxEXP(EXP1);
            minmaxHP(HP1);
        }
        else{
            float halfM1=0.5*M1;
            if(halfM1>0){
                while(halfM1>=0){
                    road2event(HP1,EXP1,halfM1,0);
                }
            }
            HP1=roundup(0.83*HP1); EXP1=roundup(1.17*EXP1); M1=roundup(0.5*M1+halfM1);
            minmaxEXP(EXP1);
            minmaxHP(HP1);
        }
        
        int S2=npSquare(EXP1);
        if (EXP1>=S2){P2=100;}
        else {P2=(1.0*EXP1/S2+80)/1.23;}

        //Road3:
        int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        P3=P[sumof2digitNum(E2)%10];

        //Final
         if (P1 == 100  && P2 == 100  && P3 == 100){
            EXP1=roundup(0.75*EXP1);
        }
        else{
            float Average=(P1+P2+P3)/3;
            if(Average>=50){
                HP1=roundup(HP1*0.9);
                EXP1=roundup(EXP1*1.2);
            }
            else{
                HP1=roundup(HP1*0.85);
                EXP1=roundup(EXP1*1.15);
            }
        }
        minmaxEXP(EXP1);
        minmaxHP(HP1);
        minmaxM(M1);
    }

    else {return -99;}

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if(E3>=0 && E3<=99){
        minmaxEXP(EXP1);
        minmaxEXP(EXP2);
        minmaxHP(HP1);
        minmaxHP(HP2);
        int matrixT[10][10], matrixSW[10][10], A=0, B=0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                matrixT[i][j]=((E3*j)+(i*2))*(i-j);
            }
        }
        
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                int MAX=matrixT[i][j]; 
                for (int m=i, n=j; m<10 && n>=0; m++, n-- ){
                    MAX=max(matrixT[m][n],MAX);
                }
                for (int m=i, n=j; m>=0 && n<10; m--, n++ ){
                    MAX=max(matrixT[m][n],MAX);
                }
                for (int m=i, n=j; m<10 && n<10; m++, n++ ){
                    MAX=max(matrixT[m][n],MAX);
                }
                for (int m=i, n=j; m>=0 && n>=0; m--, n-- ){
                    MAX=max(matrixT[m][n],MAX);
                }
                matrixSW[i][j]=MAX;
            }
        }

        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if (matrixT[i][j]>2*E3){A++;}
                if (matrixT[i][j]<-E3){B++;}
            }
        }

        while(A>9){A=sumof2digitNum(A);}
        while(B>9){B=sumof2digitNum(B);}

        if(abs(matrixT[A][B])>matrixSW[A][B]){
            HP1=roundup(0.9*HP1);
            HP2=roundup(0.9*HP2);
            EXP1=roundup(0.88*EXP1);
            EXP2=roundup(0.88*EXP2);
            
            minmaxEXP(EXP1);
            minmaxEXP(EXP2);
            minmaxHP(HP1);
            minmaxHP(HP2);
            return matrixT[A][B];
        }
        else {
            HP1=roundup(1.1*HP1);
            HP2=roundup(1.1*HP2);
            EXP1=roundup(1.12*EXP1);
            EXP2=roundup(1.12*EXP2);
            
            minmaxEXP(EXP1);
            minmaxEXP(EXP2);
            minmaxHP(HP1);
            minmaxHP(HP2);
            return matrixSW[A][B];
        }
    }
    else {return -99;}
    
    return -1;
}

// Task 4
//contain more than 2 consecutive and identical characters.

bool consect(string a){
    for (int i = 2; i < a.length(); ++i) {
        if (a[i] == a[i - 1] && a[i] == a[i - 2]) {
            return true;  
        }
    }
        
    return false;
        
    
    
}



//find index of the first more than 2 consect

int Index(string a){
    int i;
    for (i = 2; i < a.length(); ++i) {
        if (a[i] == a[i - 1] && a[i] == a[i - 2]) {
            return i-2;  
        }

}
return i-2;
}

//check se in s

bool check(string a, string b) {
    if (b.find(a) != string::npos){
        return true;
    }
    else {
        return false;
    }

}



//find position of se

int findPosition(string a, string b) {
    
    size_t position = b.find(a);

    

        
    return static_cast<int>(position);
    
}

//tra ve vi tri sai

bool valid(char c){
    if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!'){
        return true;
    }
    else {
        return false;
    }

}

//check ki tu thuong hoa so db
void Isvalid(string &a, bool &b){
    
    for (char c:a){
        if(('0' <= c && c <= '9') && ('a' <= c && c <= 'z') && ('A' <= c && c <= 'Z') && c == '@' && c == '#' && c == '%' && c == '$' && c == '!'){
            b=true;

        }
        else{
            b=false;
        }


}
}

// Task 4
int checkPassword(const char * s, const char * email){
    //TODO: implement task
    string e(email);
    string pw(s);
    string se=e.substr(0,e.find('@'));
    bool Charspec = false;
    for (int i=0;i<pw.length();i++){
        if(pw[i] == '@' || pw[i] == '#' || pw[i] == '%' || pw[i] == '$' || pw[i] == '!'){
            Charspec =true;
        }
    }

    bool checking = false;
    Isvalid(pw, checking);
    
    if(pw.length()<8){
        return -1;
    }
    else if(pw.length()>20){
        return -2;
    }
    else if (check(se,pw)){
        int c=findPosition(se,pw);
        return -(300+c);
    }
    else if(consect(pw)){
        int a =Index(pw);
        return -(400+a);
    }
    else if(!Charspec){
        return -5;
    }      
    else if(!checking){
        for (int i=0;i<pw.length();i++){
            if(!valid(pw[i])){
                return i;
                break;
            }
                    
        }
    }
    else {
        return -10;
    }

    return -99;
}

// Task 5

int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int array1[2][num_pwds];
    string array2[num_pwds];

    for (int i = 0; i < num_pwds; i++) {
        array2[i] = arr_pwds[i];
    }

    for (int i = 0; i < num_pwds; i++) {
        array1[0][i] = array2[i].length();
        array1[1][i] = 0;  

        for (int j = 0; j < num_pwds; j++) {
            if ( array2[i] == array2[j]) {
                array1[1][i] += 1;
            }
        }
    }

    int max0 = 0;
    int max1 = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (array1[1][i] > max1) {
            max1 = array1[1][i];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (array1[1][i] == max1) {
            if (array1[0][i] > max0) {
                max0 = array1[0][i];
            }
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (array1[1][i] == max1 && array1[0][i] == max0) {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////