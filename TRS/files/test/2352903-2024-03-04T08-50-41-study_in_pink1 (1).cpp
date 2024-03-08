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

void validEXP(int & exp){
    if (exp <= 0) exp = 0;
    else if (exp >= 600) exp = 600;
}

void validHP(int & hp){
    if (hp <= 0) hp = 0;
    else if (hp >= 666) hp = 666;
}

void validMoney(int & M){
    if (M <= 0) M = 0;
    else if (M >= 3000) M = 3000;
}

int digitSum(int & a){
    if (a<10)
        return a;
    else
        return a%10 + a/10;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if (E1>=0 && E1<=3){
        validEXP(EXP1);
        validEXP(EXP2);
        switch(E1){
            case 0:
                EXP2 += 29;
                break;
            case 1:
                EXP2 += 45;
                break;
            case 2:
                EXP2 += 75;
                break;
            default:
                EXP2 += 149;
                break;
        }
        validEXP(EXP2);
        int D = E1*3 + EXP1*7;
        ((D%2) == 0) ? EXP1 += ceil((float)D/200) : EXP1 -= floor((float)D/100);
        validEXP(EXP1);
    }
    else if (E1>=4 && E1<=99){
        validEXP(EXP1);
        validEXP(EXP2);
        if (E1>=4 && E1<=19) 
            EXP2 += ceil((float)E1/4)+19;
        else if (E1<=49) 
            EXP2 += ceil((float)E1/9)+21;
        else if (E1<=65) 
            EXP2 += ceil((float)E1/16)+17;
        else if (E1<=79){
            EXP2 += ceil((float)E1/4)+19;
            validEXP(EXP2);
            if (EXP2 > 200)
                EXP2 += ceil((float)E1/9)+21;
        }
        else{
            EXP2 += ceil((float)E1/4)+19;
            validEXP(EXP2);
            EXP2 += ceil((float)E1/9)+21;
            validEXP(EXP2);
            if (EXP2 > 400){
                EXP2 += ceil((float)E1/16)+17;
                validEXP(EXP2);
                EXP2 = ceil(1.15*(float)EXP2);
            }
        }
        validEXP(EXP2);
        EXP1 -= E1;
        validEXP(EXP1);
    }
    else return -99;
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if ((E2<0)||(E2>99)) return -99;

    validMoney(M1);
    validEXP(EXP1);
    validHP(HP1);
    float P1 = 1, P2 = 1, P3;
    if ((pow(ceil(sqrt(EXP1)),2)-EXP1)<(EXP1-pow(floor(sqrt(EXP1)),2)))
        P1 = ((EXP1/pow((sqrt(EXP1)+1),2))+80)/123;
    int pay = 0;
    if ((E2%2)==1){
        if(M1!=0){
            while(pay<=((float)M1/2)){
                if (pay<=((float)M1/2)){
                    if (HP1<200){
                        HP1 = ceil((float)HP1 * (float)1.3 - 0.001);
                        pay += 150;
                        validHP(HP1);
                    }
                    else{
                        HP1 = ceil((float)HP1 * (float)1.1 - 0.001);
                        pay += 70;
                        validHP(HP1);
                    }
                }
                else break;

                if (pay<=((float)M1/2)){
                    if (EXP1<400) pay += 200;
                    else pay += 120;
                    EXP1 = ceil((float)EXP1 * (float)1.13 - 0.001);
                    validEXP(EXP1);
                }
                else break;

                if (pay<=((float)M1/2)){
                    if (EXP1<300) pay += 100;
                    else pay += 120;
                    EXP1 = ceil((float)EXP1 * (float)0.9 - 0.001);
                    validEXP(EXP1);
                }
                else break;
            }
        }
    }

    else{
        if (pay<M1){
            if (HP1<200){
                HP1 = ceil((float)HP1 * (float)1.3 - 0.001);
                pay += 150;
                validHP(HP1);
            }
            else{
                HP1 = ceil((float)HP1 * (float)1.1 - 0.001);
                pay += 70;
                validHP(HP1);
            }
        }

        if (pay<M1){
            if (EXP1<400) pay += 200;
            else pay += 120;
            EXP1 = ceil((float)EXP1 * (float)1.13 - 0.001);
            validEXP(EXP1);
        }

        if (pay<M1){
            if (EXP1<300) pay += 100;
            else pay += 120;
            EXP1 = ceil((float)EXP1 * (float)0.9 - 0.001);
            validEXP(EXP1);
        }
    }
    M1 = max(M1-pay, 0);
    HP1 = ceil((float)HP1 * (float)0.83 - 0.001);
    EXP1 = ceil((float)EXP1 * (float)1.17 - 0.001);
    validEXP(EXP1);
    validHP(HP1);
    if ((pow(ceil(sqrt(EXP1)),2)-EXP1)<(EXP1-pow(floor(sqrt(EXP1)),2)))
        P2 = ((EXP1/pow((sqrt(EXP1)+1),2))+80)/123;

    float P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i3 = E2;
    if (i3<10)
        P3 = P[i3]/100;
    else{
        i3 = E2%10 + E2/10;
        if (i3 < 10)
            P3 = P[i3]/100;
        else P3 = P[(i3-10)]/100;
    }

    if ((P1==1) && (P2==1) && (P3==1))
        EXP1 = ceil((float)EXP1 * (float)0.75 - 0.001);
    else if ((P1+P2+P3)/3<0.5){
        HP1 = ceil((float)HP1 * (float)0.85 - 0.001);
        EXP1 = ceil((float)EXP1 * (float)1.15 - 0.001);
    }
    else{
        HP1 = ceil((float)HP1 * (float)0.9 - 0.001);
        EXP1 = ceil((float)EXP1 * (float)1.2 - 0.001);
    }
    validEXP(EXP1);
    validHP(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if((E3<0)||(E3>99)) return -99;
    validEXP(EXP1);
    validHP(HP1);
    validEXP(EXP2);
    validHP(HP2);
    int matrix[10][10];
    int iIntersect=0, jIntersect=0;
    for (int i = 0; i<=9; i++){
        for (int j = 0; j<=9; j++){
            matrix[i][j]= ((E3*j)+(i*2))*(i-j);
            if(matrix[i][j]>(E3*2))
                iIntersect++;
            if(matrix[i][j]<(-E3))
                jIntersect++;
        }
    }
    while(iIntersect>9){
        iIntersect = digitSum(iIntersect);
    }
    while((jIntersect>9)){
        jIntersect = digitSum(jIntersect);
    }
    int duoScore = matrix[iIntersect][jIntersect];
    int iLDiagonal=iIntersect, jLDiagonal=jIntersect, iRDiagonal=iIntersect, jRDiagonal=jIntersect;
    while((iRDiagonal>0)&&(jRDiagonal>0)){
        iRDiagonal--;
        jRDiagonal--;
        if(matrix[iRDiagonal][jRDiagonal]>=duoScore)
            duoScore = matrix[iRDiagonal][jRDiagonal];
    }
    while((iRDiagonal<9)&&(jRDiagonal<9)){
        iRDiagonal++;
        jRDiagonal++;
        if(matrix[iRDiagonal][jRDiagonal]>=duoScore)
            duoScore = matrix[iRDiagonal][jRDiagonal];
    }
    while((iLDiagonal>0)&&(jLDiagonal>0)&&(iLDiagonal<9)&&(jLDiagonal<9)){
        iLDiagonal++;
        jLDiagonal--;
        if(matrix[iLDiagonal][jLDiagonal]>=duoScore)
            duoScore = matrix[iLDiagonal][jLDiagonal];
    }
    while((iLDiagonal>0)&&(jLDiagonal>0)&&(iLDiagonal<9)&&(jLDiagonal<9)){
        iLDiagonal--;
        jLDiagonal++;
        if(matrix[iLDiagonal][jLDiagonal]>=duoScore)
            duoScore = matrix[iLDiagonal][jLDiagonal];
    }
    duoScore = abs(duoScore);
    if(abs(matrix[iIntersect][jIntersect])>duoScore){
        EXP1=ceil((float)EXP1*(float)0.88 - 0.001);
        HP1=ceil((float)HP1*(float)0.9 - 0.001);
        EXP2=ceil((float)EXP2*(float)0.88 - 0.001);
        HP2=ceil((float)HP2*(float)0.9 - 0.001);
        validEXP(EXP1);
        validHP(HP1);
        validEXP(EXP2);
        validHP(HP2);
        return matrix[iIntersect][jIntersect];
    }
    else{
        EXP1=ceil((float)EXP1*(float)1.12 - 0.001);
        HP1=ceil((float)HP1*(float)1.1 - 0.001);
        EXP2=ceil((float)EXP2*(float)1.12 - 0.001);
        HP2=ceil((float)HP2*(float)1.1 - 0.001);
        validEXP(EXP1);
        validHP(HP1);
        validEXP(EXP2);
        validHP(HP2);
        return duoScore;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string S = s;
    string Email = email;
    string se = Email.substr(0,Email.find('@'));
    int find = S.find(se);
    bool isAdjacent = false;
    int adjacent = 0;
    bool noSpecial = true;
    int strangeChar = false;
    int strangeCharIndex = 0;
    for (int i = 0; i<S.length(); i++){
        if((S[i]==S[i+1])&&(S[i+1]==S[i+2])){
            isAdjacent = true;
            adjacent = i;
            break;
        }
    }
    for (int i = 0; i<S.length(); i++){
        if((S[i]=='@')||(S[i]=='#')||(S[i]=='$')||(S[i]=='%')||(S[i]=='!')){
            noSpecial = false;
            break;
        }
    }
    for (int i = 0; i<S.length(); i++){
        if((!(isalpha(S[i])))&&(!(isdigit(S[i])))&&(S[i]!='@')&&(S[i]!='#')&&(S[i]!='$')&&(S[i]!='%')&&(S[i]!='!')){
            strangeChar = true;
            strangeCharIndex = i;
            break;
        }
    }
    if(S.length()<8) return -1;
    else if(S.length()>20) return -2;
    else if((find>=0)&&(find<=(S.length()-se.length()))) return -(300+find);
    else if(isAdjacent) return -(400+adjacent);
    else if(noSpecial) return -5;
    else if(strangeChar) return strangeCharIndex;
    else return -10; 
}

//Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0, index = 0;
    string Arr_pwds[num_pwds];
    string password;
    for(int i = 0; i<num_pwds; i++)
        Arr_pwds[i]=*(arr_pwds+i);
    for (int i = 0; i<num_pwds; i++){
        int count = 0;
        for (int j = 0; j<num_pwds; j++){
            if(Arr_pwds[i]==Arr_pwds[j])
                count++;
        }
        if(count>maxCount){
            maxCount = count;
            password = Arr_pwds[i];
        }
        if((count==maxCount)&&(Arr_pwds[i].length()>password.length()))
            password = Arr_pwds[i];
    }

    for (int i = 0; i<num_pwds; i++){
        if(Arr_pwds[i]==password){
            index = i;
            break;
        }
    }
    return index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////