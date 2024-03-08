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
int checkE(int e){
    if(e < 0 || e > 99){
        return 0;
    }
    else return 1;
}
void modifyHp(int & hp){
    if(hp < 0) hp = 0;
    if(hp > 666) hp = 666;
}
void modifyExp(int & exp){
    if(exp < 0) exp = 0;
    if(exp > 600) exp = 600;
}
void modifyM(int & m){
    if(m < 0) m = 0;
    if(m > 3000) m = 3000;
}
float findSquare(int exp1){
    float S=0;
    for(int i=0; i<=25; i++){
        
        if(abs(i*i-exp1) < abs(S-exp1)){
            S = i*i;
        }
    }
    return S;
}
int findLength(const char arr[]){
    int length=0;
    for(int i=0; i<100; i++){
        if(arr[i]=='\0') break;
        length++;
    }
    return length;
}
int roundup(float a){
    int b = a;
    if(a==b){
        return b;
    }
    else return b + 1;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(!checkE(e1)) return -99;
    else{
        if(e1>=0 && e1<=3){
            if(e1==0){
                exp2 += 29;
            }
            else if(e1==1){
                exp2 += 45;
            }
            else if(e1==2){
                exp2 += 75;
            }
            else if(e1==3){
               exp2 += 149;
            }
            modifyExp(exp2);
            int D = e1*3 + exp1*7;
            if(D%2==0){
                float ans = exp1 + D/200.0;
                exp1 = roundup(ans);
            }
            
            else{
                float ans = exp1 - D/100.0;
                exp1 = roundup(ans);
            }
            modifyExp(exp1);
        }
        else {
            if(e1>=4 && e1<=19){
                exp2 += roundup(e1/4.0+19);
            }
            else if(e1>=20 && e1<=49){
                exp2 += roundup(e1/9.0+21);
            }
            else if(e1>=50 && e1<=65){
                exp2 += roundup(e1/16.0+17);
            }
            else if(e1>=66 && e1<=79){
                exp2 += roundup(e1/4.0+19);
                if(exp1>200) exp2 += roundup(e1/9.0+21);
            }
            else if(e1>=80 && e1<=99){
                exp2 += roundup(e1/4.0+19) + roundup(e1/9.0+21);
                if(exp1>400){
                    exp2 += roundup(e1/16.0+17);
                    exp2 = roundup(exp2*1.15);
                } 
            }
            exp1 -= e1;
            modifyExp(exp1);
            modifyExp(exp2);
        }
        
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(!checkE(E2)) return -99;
    else{
        float P1;
        if(EXP1>=findSquare(EXP1)) P1=1;
        else P1=(float(EXP1/findSquare(EXP1))+80)/123.0;
        //route2
        if(E2%2==1){
        float limit = M1/2.0;
        do{
            if(HP1<200){
                HP1 = roundup(HP1*1.3);
                M1 -= 150;
                }
            else{
                HP1 = roundup(HP1*1.1);
                M1 -= 70;
            }
            modifyHp(HP1);
            modifyM(M1);
            if(M1<limit) break;
            
            if(EXP1<400){
                M1 -= 200;
            }
            else{
                M1 -= 120;
            }
            modifyM(M1);
            EXP1 = roundup(EXP1*1.13);
            modifyExp(EXP1);
            if(M1<limit) break;
            
            if(EXP1<300) M1 -= 100;
            else M1 -= 120;
            modifyM(M1);
            EXP1 = roundup(EXP1*0.9);
            if(M1<limit) break;
        }
        while(E2%2==1);
        }
        else{
            do{
            if(HP1<200){
                HP1 = roundup(HP1*1.3);
                M1 -= 150;
                }
            else{
                HP1 = roundup(HP1*1.1);
                M1 -= 70;
            }
            modifyHp(HP1);
            modifyM(M1);
            if(M1==0) break;
            
            if(EXP1<400){
                M1 -= 200;
            }
            else{
                M1 -= 120;
            }
            modifyM(M1);
            EXP1 = roundup(EXP1*1.13);
            modifyExp(EXP1);
            if(M1==0) break;
            
            if(EXP1<300) M1 -= 100;
            else M1 -= 120;
            modifyM(M1);
            EXP1 = roundup(EXP1*0.9);
            if(M1==0) break;
        }
        while(0);
        }
        HP1 = roundup(HP1*0.83);
        EXP1 = roundup(EXP1*1.17);
        modifyExp(EXP1);
        float P2;
        if(EXP1>=findSquare(EXP1)) P2=1;
        else P2=(float(EXP1/findSquare(EXP1))+80)/123.0;
        
        //route3
        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        float P3;
        if(E2/10==0) P3=P[E2]/100.0;
        else P3=P[(E2/10+E2%10)%10]/100.0;
        if(P1==P2 && P2==P3 && P3==1) EXP1 = roundup(EXP1*0.75);
        
        else if((P1+P2+P3)/3.0<0.5){
            
            HP1 = roundup(HP1*0.85);
            EXP1 = roundup(EXP1*1.15);
        }
        else{
            
            HP1 = roundup(HP1*0.9);
            
            EXP1 = roundup(EXP1*1.2);
        }
        modifyExp(EXP1);
        modifyHp(HP1);
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(!checkE(E3)) return -99;
    else{
        int a, b, matrix[10][10];
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                matrix[i][j]=((E3 * j) + (i * 2)) * (i - j);
                if (matrix[i][j]>2*E3) a++;
                if (matrix[i][j]<-E3) b++;
                }
        }
        if(a>9) a=a/10+a%10;
        if(a>9) a=a/10+a%10;
        if(b>9) b=b/10+b%10;
        if(b>9) b=b/10+b%10;
        
        int max=matrix[a][b];
        for(int i=a, j=b; i>=0 && j>=0; i--, j--){
            if (matrix[i][j]>max) max=matrix[i][j];
        }
        for(int i=a, j=b; i<=9 && j<=9; i++, j++){
            if (matrix[i][j]>max) max=matrix[i][j];
        }
        for(int i=a, j=b; i>=0 && j<=9; i--, j++){
            if (matrix[i][j]>max) max=matrix[i][j];
        }
        for(int i=a, j=b; i<=9 && j>=0; i++, j--){
            if (matrix[i][j]>max) max=matrix[i][j];
        }
        
        if(abs(matrix[a][b])>max){
            EXP1=roundup(0.88*EXP1);
            
            EXP2=roundup(0.88*EXP2);
            
            HP1=roundup(0.9*HP1);
            
            HP2=roundup(0.9*HP2);
            
            return matrix[a][b];
        }
        else{
            HP1=roundup(1.1*HP1);

            EXP1=roundup(1.12*EXP1);

            EXP2=roundup(1.12*EXP2);
            
            HP2=roundup(1.1*HP2);
            
            modifyExp(EXP1);
            modifyExp(EXP2);
            modifyHp(HP1);
            modifyHp(HP2);
            
            return max;
        }
    }
}

int checkDouble(const char arr[]){
    int result;
    for(int i=0; i<findLength(arr)-1; i++){
        if(arr[i]==arr[i+1]){
            
            result = 1;
            break;
        }
        if(i==findLength(arr)-2) result = 0;
    }
    return result;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int result = -10;
    char se[100];
    int lengthSe=0;
    for(int i=0; i<=100; i++){
        if(email[i]=='@') break;
        se[i]=email[i];
        lengthSe++;
    }
    int lengthS = findLength(s);
    if(lengthS<8) result = -1;
    else if(lengthS>20) result = -2;
    
    else if(lengthS>lengthSe){
        for(int i=0; i <= lengthS - lengthSe; i++){
            int sei=i;
            int checker=0;
            for(int j=i; j < i+lengthSe; j++){
                if(s[j]!=se[j-i]) break;
                checker ++;
            }
        if(checker==lengthSe){
                result = -(300+sei);
                break;
            }
        }
    }
    if(result == -10){
        int sci=0;
        for(int i=0; i<lengthS - 2; i++){
            if(s[i]==s[i+1] && s[i]==s[i+2]){
                sci=i;
                result=-(400+sci);
                break;
            }
        }
    }
    if(result == -10){
        for(int i=0; i < lengthS; i++){
            if(s[i]=='@' || s[i]== '#' || s[i] == '%'|| s[i] == '$'|| s[i] == '!') break;
            if(i == lengthS - 1) result=-5;
        }
    }
    if(result == -10){
        for(int i=0; i < lengthS; i++){
            if(s[i]=='^'|| s[i]== '&'|| s[i]== '*'|| s[i]== '('|| s[i]== ')'|| s[i]== '-'|| s[i]== '+'|| s[i]== '_'|| s[i]== ','|| s[i]== '.'|| s[i]== '<'|| s[i]== '>'){
                result = i;
                break;
            }
        }
    }
    return result;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char * pwds[31];
    int frequency[31], current=0;
    for(int i=0; i<31; i++){
        frequency[i]=-1;
    }
    for(int i=0; i < num_pwds; i++){
        for(int j=0; j <= current; j++){
            if(arr_pwds[i]==pwds[j]){
                frequency[j]++;
                break;
            }
            if(j == current){
                current++;
                pwds[current] = arr_pwds[i];
                frequency[current] ++;
                
            }
        }
    }
    int possition=0, biggest=0, longest=0;
    for(int i=1; i <= current; i++){
        if(frequency[i] > biggest || (frequency[i] == biggest && strlen(pwds[i]) > longest)){
            possition=i;
            biggest = frequency[i];
            longest = strlen(pwds[i]);
        }
    }
    for(int i=0; i<num_pwds; i++){
        if(arr_pwds[i]==pwds[possition]){
            possition=i;
            break;
        } 
    }
    return possition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////