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
            >> E1 >> E2 >> E3 ;
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
void checkexp(int & exp){
    if (exp<0) exp=0;
    if (exp>600) exp=600;
}
void checkExpHp(int & exp, int & hp)
{
    if (exp<0) exp=0;
    if (exp>600) exp=600;
    if (hp<0) hp=0;
    if (hp>666) hp=666;
}
void check(int & exp, int & hp, int & m){
    if (exp<0) exp=0;
    if (exp>600) exp=600;
    if (hp<0) hp=0;
    if (hp>666) hp=666;
    if (m<0) m=0;
    if(m>3000) m=3000;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0||e1>99) return -99;
    if(e1>=0 && e1<=3)
    {
        switch(e1){
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
                exp2+= 29 + 45 + 75;
                break;
        }
        int d=e1*3 + exp1*7;
        if(d%2==0) exp1+=ceil(float(d)/200);
        else exp1-=d/100;
    }
    else
    {
        
            if (e1<20)
                exp2+=ceil(float(e1)/4 + 19); //4-19
            else if (e1<50)
                exp2+=ceil(float(e1)/9 + 21); //20-49
            else if(e1<66){
                    exp2+=ceil(float(e1)/16 + 17); //50-65
                }
            else if(e1<80){
                    exp2+=ceil(float(e1)/4 + 19); //66-79
                    checkexp(exp2);
                    if(exp2>200) exp2+=ceil(float(e1)/9 + 21);
                }
            else {
                    exp2+=ceil(float(e1)/4 + 19);//80-99
                    checkexp(exp2);
                    exp2+=ceil(float(e1)/9 + 21);
                    checkexp(exp2);
                if(exp2>400){ 
                    exp2+=ceil(float(e1)/16 + 17);
                    checkexp(exp2);
                    exp2+=ceil(float(exp2)*0.15);
                    }
                }
        exp1-=e1;
        
    }
    checkexp(exp1);
    checkexp(exp2);
    return exp1 + exp2;
}

// Task 2
int closestSquare(int n) {
    int s = round(sqrt(n));
    return s*s;
}
float road01(int &EXP1) {
    float s = closestSquare(EXP1);
    float P1 = (EXP1 >= s) ? 100 : ((EXP1 / s + 80)*100 / 123);
    return P1;
}

void road02(int &HP1, int &EXP1, int &M1, int E2) {
    float hM1=M1/2;
    if (E2%2==0) {
           if (HP1 < 200) {
               HP1 = HP1*1.3 + 0.999;
               M1 -= 150;
           }
           else {
               HP1 = HP1*1.1 + 0.999;
               M1 -= 70;
           }
           check(EXP1, HP1, M1);
           if (M1 > 0) {
               if (EXP1 < 400) M1 -= 200;
               else M1 -= 120;
               EXP1 = EXP1*1.13 + 0.999;
               check(EXP1, HP1, M1);
               if (M1 > 0) {
                   if (EXP1 < 300) M1 -= 100;
                   else M1 -= 120;
                   EXP1 = EXP1*0.9 + 0.999;
               }
           }
           if (M1 < 0) M1 = 0;
       }
       else {
           while (M1 > hM1) {
               if (HP1 < 200) {
                   HP1 = HP1*1.3 + 0.999;
                   M1 -= 150;
               }
               else {
                   HP1 = HP1*1.1 + 0.999;
                   M1 -= 70;
               }
               check(EXP1, HP1, M1);
               if (M1 < hM1 || M1 <= 0) break;
               if (EXP1 < 400) M1 -= 200;
               else M1 -= 120;
               EXP1 = EXP1*1.13 + 0.999;
               if (EXP1 > 600) EXP1 = 600;
               if (M1 < hM1 || M1 <= 0) break;
               if (EXP1 < 300) M1 -= 100;
               else M1 -= 120;
               EXP1 = EXP1*0.9 + 0.999;
               check(EXP1, HP1, M1);
           }
       }
    HP1  = HP1*0.83 + 0.999;
    EXP1 = EXP1*1.17 + 0.999;
    check(EXP1, HP1, M1);
}
float road03(int E2) {
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i ;
    if(E2<10) i=E2;
    if(E2>9) i=(E2%10+E2/10)%10;
    float P3 = P[i];
    return P3;
}

  
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        if (E2 < 0 || E2 > 99) return -99;
        float P1 = road01(EXP1);
        road02(HP1,EXP1, M1, E2);
        float P2 = road01(EXP1);
        float P3 = road03(E2);
        float avgP=(P1+P2+P3)/3;;
        if (avgP==100) 
            EXP1 = EXP1*0.75 + 0.999;
        else {
            if (avgP<50) {
                HP1 = HP1*0.85+0.999;
                EXP1 = EXP1*1.15+0.999;
            }
            else {
                HP1 = HP1*0.9+0.999;
                EXP1 = EXP1*1.2+0.999;
            }
        }
        check(EXP1, HP1, M1);
        return HP1 + M1 + EXP1;
    }


// Task 3
int SOD(int num) //sumOfDigits
{
    int sum = 0;
    while (num > 0 || sum > 9) {
        if (num == 0) {
            num = sum;
            sum = 0;
        }
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
// Kiểm tra xem hai ô có cùng đường chéo hay không
bool isDiagonal(int sX, int sY, int eX, int eY) {
   
    return abs(sX - eX) == abs(sY - eY);
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3<0||E3>99) return -99;
    int m=0, n=0;
    int matrix[10][10]={};
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matrix[i][j]= (E3*j + i*2)*(i - j);
            if(matrix[i][j]>E3*2) ++m;
            if(matrix[i][j]<-E3) ++n;
        }
    }
    int i=SOD(m);
    int j=SOD(n);
    int max = matrix[i][j];
    for(int a = 0; a < 10; a++) {
        for(int b = 0; b < 10; b++) {
            if(isDiagonal(i,j,a,b))
                if(matrix[a][b]>max) max=matrix[a][b];
        }
    }
    int result=0;
    if(abs(matrix[i][j])>abs(max))
    {
        EXP1=ceil(float(EXP1)*0.88);
        HP1=ceil(float(HP1)*0.9);
        EXP2=ceil(float(EXP2)*0.88);
        HP2=ceil(float(HP2)*0.9);
        result=matrix[i][j];
    }
    else
    {
        EXP1+=ceil(float(EXP1)*0.12);
        HP1+=ceil(float(HP1)*0.1);
        EXP2+=ceil(float(EXP2)*0.12);
        HP2+=ceil(float(HP2)*0.1);
        result=max;
    }
    checkExpHp(EXP1,HP1);
    checkExpHp(EXP2,HP2);
    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    
    char se[101];
    strncpy(se, email, strchr(email, '@') - email);
    se[strchr(email, '@') - email] = '\0';
    
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;
    
    int specialCharCount = 0;
    for (int i = 0; i < len; i++) {
        if (strchr("@#$%!", s[i])) specialCharCount++;
        const char* sP = strstr(s, se);
        if (sP) return -(300 + (sP - s));
        if (i < len - 2 && s[i] == s[i+1] && s[i] == s[i+2]) return -(400+i);
    }
    if (specialCharCount == 0) return -5;
    for (int i = 0; i < len; i++) {
        if (!isdigit(s[i]) && !isalpha(s[i]) && !strchr("@#$%!", s[i])) return i;}
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0, maxLength = 0, minIndex = num_pwds;
    const char *correctPwd = NULL;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0, length = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count;
            }
        }
        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctPwd = arr_pwds[i];
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correctPwd) == 0) {
            minIndex = i;
            break;
        }
    }

    return minIndex;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
