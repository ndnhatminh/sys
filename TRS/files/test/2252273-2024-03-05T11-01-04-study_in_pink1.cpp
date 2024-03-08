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
int roundUp(float  numb){
    if((int)numb != numb){
        return (int)numb+1;
    }
    return numb;
}
void resetExp(int & exp1, int & exp2) {
    if (exp1 < 0) exp1 = 0;
    else if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    else if (exp2 > 600) exp2 = 600;
}
void resetHP(int & hp1, int & hp2){
    if(hp1 < 0) hp1 = 0;
    else if(hp1 > 666) hp1 = 666;
    if(hp2 < 0) hp2 = 0;
    else if(hp2 > 666) hp2 = 666;
}
void resetMoney(int & m1, int & m2){
    if(m1 < 0) m1 = 0;
    else if(m1 > 3000) m1 = 3000;
    if(m2 < 0) m2 = 0;
    else if(m2 > 3000) m2 = 3000;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {

    if (E1 < 0 || E1 > 99) return -99;
    else if (E1 >= 0 && E1 <= 3){
        switch (E1) {
            case 0:
                EXP2 += 29;
                break;
            case 1:
                EXP2 += 45;
                break;
            case 2:
                EXP2 += 75;
                break;
            case 3:
                EXP2 += 149;
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 = roundUp(EXP1 + (D * 1.0)/200);
        }
        else EXP1 = roundUp(EXP1 - (D * 1.0)/100);
    }
    else if( E1 >= 4 && E1 <= 99){
        if( E1 >= 4 && E1 <= 19){
            EXP2 = roundUp(EXP2 + E1/4.0 + 19);
        }
        else if (E1 >= 20 && E1 <= 49){
            EXP2 = roundUp(EXP2 + E1/9.0 + 21);
        }
        else if (E1 >= 50 && E1 <= 65){
            EXP2 = roundUp(EXP2 + E1/16.0 + 17);
        }
        else if(E1 >= 66 && E1 <= 79){
            EXP2 = roundUp(EXP2 + E1/4.0 + 19);
            if(EXP2 > 200) EXP2 = roundUp(EXP2 + E1/9.0 + 21);
        }
        else if(E1 >= 80 && E1 <= 99){
            EXP2 = roundUp(EXP2 + E1/4.0 + 19);
            EXP2 = roundUp(EXP2 + E1/9.0 + 21);
            if(EXP2 > 400){ 
                EXP2 = roundUp(EXP2 + E1/16.0 + 17);
                EXP2 = roundUp(EXP2 + EXP2 * 0.15);
            }
        }
        EXP1 -= E1;
    }
    resetExp(EXP1,EXP2);
    return EXP1 + EXP2;
}

// Task 2
int nearestSquare(int EXP1){
    float S = sqrt(EXP1);
    if (S - (int)S != 0){
        int lowerS = floor(S) * floor(S);
        int upperS = ceil(S) * ceil(S);
        S = ((EXP1 - lowerS) > (upperS - EXP1)) ?  upperS : lowerS ;   
    }
    return (int)S;
}
void resetSherLock(int& hp1,int &exp1,int&m1){
    if (exp1 < 0) exp1 = 0;
    else if (exp1 > 600) exp1 = 600;
    if(hp1 < 0) hp1 = 0;
    else if(hp1 > 666) hp1 = 666;
    if(m1 < 0) m1 = 0;
    else if(m1 > 3000) m1 = 3000;

}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2){
// TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    int S = nearestSquare(EXP1);
    float P1 = 0;
    if (EXP1 >= S) P1 = 1.0;
    else P1 = (EXP1/(S*1.0) + 80)/123;
    float init = 0.5*M1;
    if(E2 % 2 == 1 && M1 > 0){
        while(true){
            if(HP1 < 200){
                HP1 = roundUp(1.3*HP1);
                M1-=150;
            }
            else {
                HP1 = roundUp(1.1*HP1);
                M1 -= 70;
            }
            resetSherLock(HP1,EXP1,M1);
            if(init > M1) break;
            //
            if(EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = roundUp(1.13*EXP1);
            resetSherLock(HP1,EXP1,M1);
            if(init > M1) break;
            //
            if (EXP1 < 300) M1-=100;
            else M1 -=120;
            EXP1 = roundUp(0.9*EXP1);
            resetSherLock(HP1,EXP1,M1);
            if(init > M1) break;
        }
    }
    else if(E2 % 2 == 0 && M1 > 0){
        int count = 0;
        while(count<3){
            if(HP1 < 200){
                HP1 = roundUp(1.3*HP1);
                M1-=150;
            }
            else {
                HP1 = roundUp(1.1*HP1);
                M1 -= 70;
            }
            resetSherLock(HP1,EXP1,M1);
            count++;
            if(M1 <=0 ) break;
            //
            if(EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = roundUp(1.13*EXP1);
            resetSherLock(HP1,EXP1,M1);
            count++;
            if(M1 <= 0) break;
            if (EXP1 < 300) M1-=100;
            else M1 -=120;
            EXP1 = roundUp(0.9*EXP1);
            resetSherLock(HP1,EXP1,M1);
            count++;      
        }

    }
    HP1 = roundUp(0.83*HP1);
    EXP1 = roundUp(1.17*EXP1);
    resetSherLock(HP1,EXP1,M1);
    S = nearestSquare(EXP1);
    float P2 = 0;
    if (EXP1 >= S) P2 = 1.0;
    else P2 = (EXP1/(S*1.0) + 80)/123;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3 = 0;
    if(E2/10 == 0) P3 = P[E2];
    else{
        int temp = E2;
        int sum = 0;
        while(temp != 0){
            sum += temp%10;
            temp /=10;
        }
        P3 = P[sum%10];
    }
    if(P1 == 1.0 && P2 == 1.0 && P3 == 100){
        EXP1 = roundUp(0.75 * EXP1);
        resetSherLock(HP1,EXP1,M1);
    }
    float tempP3 = P3/100.0;
    float avg = (P1+P2+tempP3)/3;
    if(avg >= 0.5 && avg < 1.0){
        HP1 = roundUp(0.9*HP1);
        EXP1 = roundUp(1.2*EXP1);
    }
    else if(avg < 0.5) {
        HP1 = roundUp(0.85*HP1);
        EXP1 = roundUp(1.15*EXP1);
    }
    resetSherLock(HP1,EXP1,M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int sumNumb(int numb){
    int temp = 0;
    while(numb/10 != 0){
        temp += (numb%10);
        numb/=10;
        if(numb/10 == 0){
            temp += numb;
            numb = temp;
            temp = 0;
        }
    }
    return numb;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 > 99 || E3 < 0)
        return -99;
    int matrix[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            matrix[i][j]=0;
        }
    }
    int countP = 0;
    int countN = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            matrix[i][j] = ((E3*j)+(i*2))*(i-j);
            if(matrix[i][j] > E3*2) countP++;
            else if(matrix[i][j]<(-E3)) countN++;
        }
    }
    int positive = sumNumb(countP);
    int negative = sumNumb(countN);
    int maxValue = -2147483647;
    int tempi = positive;
    int tempj = negative;
    while(tempi > 0 && tempj > 0){
       tempi--;
       tempj--;
    }
    while(tempi != 10 && tempj!=10){
       if(maxValue < matrix[tempi][tempj]) maxValue = matrix[tempi][tempj];
       tempi++;
       tempj++;
    }
    tempi = positive;
    tempj = negative;
    while(tempi!= 0 && tempj!=9){
       tempi--;
       tempj++;
    }
    while(tempi!=10 && tempj != -1){
       if(maxValue < matrix[tempi][tempj]) maxValue = matrix[tempi][tempj];
       tempi++;
       tempj--;
    }
    maxValue = abs(maxValue);
    if(abs(matrix[positive][negative]) <= maxValue){
        EXP1 = roundUp(EXP1*1.12);
        EXP2 = roundUp(EXP2*1.12);
        HP1 = roundUp(1.1*HP1);
        HP2 = roundUp(HP2*1.1);
    }
    else {
        EXP1 = roundUp(EXP1*0.88);
        EXP2 = roundUp(EXP2*0.88);
        HP1 = roundUp(0.9*HP1);
        HP2 = roundUp(0.9*HP2);
    }
    resetExp(EXP1,EXP2);
    resetHP(HP1,HP2);
    if(abs(matrix[positive][negative]) > maxValue) return matrix[positive][negative];
    else return maxValue;

}

// Task 4
int checkPassword(const char *s, const char *email)
{   
    int emailSize = (int)strlen(email);
    char se[emailSize];
    int seLength = 0;
    while(email[seLength] !='@'){
        se[seLength] = email[seLength];
        seLength++;
    }
    se[seLength] = '\0';
    int sLength= (int)strlen(s);
    if(sLength < 8) return -1;
    else if(sLength > 20) return -2;
    if(seLength == 0) return -300;
    int sei = 0;
    bool include = 0;
    for(int i=0;i<=(int)strlen(s)-seLength;i++){
        for(int j=0;j<seLength;j++){
            if(s[i+j]!=se[j]){
                include = 0;
                break;
            } 
            else include = 1;
        }
        if(include == 1) {
            sei = i;
            return -(300+sei);
        }
    }
    for(int i=0;i<(int)strlen(s)-2;i++){
        if(s[i]==s[i+1] && s[i]==s[i+2]) return -(400+i);
    }
    bool special = 0;
    for(int i=0;i<(int)strlen(s);i++){
        char c = s[i];
        if(c=='@'||c=='#'||c=='%'||c=='$'||c=='!'){
            special = 1;
            break;
        }
    }
    if(!special) return -5;
    for(int i=0;i<(int)strlen(s);i++){
        char c = s[i];
        if(c=='@'||c=='#'||c=='%'||c=='$'||c=='!') continue;
        if(!isdigit(c) && !isalpha(c)) return i;
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{   
    int maxFreq = 0;
    char word[1000];
    int maxLength = 0;
    int earlyAp = 0;
    for(int i=0;i<num_pwds;i++){
        int temp = 0;
        for(int j=0;j<num_pwds;j++){
            if(strcmp(arr_pwds[j],arr_pwds[i]) == 0) temp++;
        }
        if(temp == maxFreq){
            if(strlen(arr_pwds[i]) > maxLength){
                maxLength = strlen(arr_pwds[i]);
                earlyAp = i;
                strcpy(word,arr_pwds[i]);
            }

        }
        else if(temp > maxFreq){
            maxFreq = temp;
            strcpy(word,arr_pwds[i]);
            earlyAp = i;
            maxLength = strlen(word);
        }
    }
    return earlyAp;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////