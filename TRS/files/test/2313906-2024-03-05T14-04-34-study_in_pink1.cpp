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

void checkHP(int & hp){
    if(hp > 666)
        hp = 666;
    else if(hp < 0)
        hp = 0;
}

void checkEXP(int & exp){
    if(exp > 600)
        exp = 600;
    else if(exp < 0)
        exp = 0;
}

void checkM(int & m){
    if(m > 3000)
        m = 3000;
    else if(m < 0)
        m = 0;
}

bool checkE(int & e){
    if(e < 0 || e > 99)
        return 1;
    else return 0;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(checkE(e1))
        return -99;
    else{
        checkEXP(exp1);
        checkEXP(exp2);
    int D;
    if(e1>=0 && e1<=3){
    switch(e1){
        case 0:{
        exp2 += 29;
        break;
    }
        case 1:{
        exp2 += 45;
        break;
    }
        case 2:{
        exp2 += 75;
        break;
    }
        case 3:{
        exp2 = exp2 + 29 + 45 + 75;
        break;
    }
    }

    checkEXP(exp2);

    D=e1*3 + exp1*7;
    if(D % 2 == 0)
        exp1=exp1 + D/200.0 + 0.999;
    else exp1=exp1 - D/100.0 + 0.999;

    checkEXP(exp1);
    }
    else {

    if(e1>=4 && e1<=19)                             //tt1
        exp2= exp2 + e1/4.0 +19 + 0.999;
    else if(e1>=20 && e1<=49)                       //tt2
        exp2= exp2 + e1/9.0 +21 + 0.999;
    else if(e1>=50 && e1<=65)                       //tt3
        exp2= exp2 + e1/16.0 +17 + 0.999;
    else if(e1>=66 && e1<=79){                      //tt4
        exp2= exp2 + e1/4.0 +19 + 0.999;
        if(exp2>200)
            exp2= exp2 + e1/9.0 +21 + 0.999;
    }
    else if(e1>=80 && e1<=99){                      //tt5
        exp2= exp2 + e1/4.0 + 19 + 0.999;
        exp2= exp2 + e1/9.0 +21 + 0.999;
        if(exp2>400){
            exp2= exp2 + e1/16.0 +17 + 0.999;
            exp2= exp2 * 1.15 + 0.999;
        }
    }

    exp1= exp1 - e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    return exp1 + exp2;
    }
}

//2.1
int nearestSquare(int n) {
    int a = pow(floor(sqrt(n)), 2);
    int b = pow(ceil(sqrt(n)), 2);

    if ((n-a) < (b-n))
        return a;
    else return b;
}

//2.2.1
void case1(int & HP1, int & M1, int & M1u){
    if(HP1 < 200){
        HP1 = HP1*1.3 + 0.999;
        M1 -= 150;
        M1u += 150;
    }
    else {
        HP1 = HP1*1.1 + 0.999;
        M1 -= 70;
        M1u += 70;
    }
    checkHP(HP1);
    checkM(M1);
}

//2.2.2
void case2(int & EXP1, int & M1, int & M1u){
    if(EXP1 < 400){
        M1 -= 200;
        M1u += 200;
    }
    else{
        M1 -= 120;
        M1u += 120;
    }
    EXP1 = EXP1*1.13 + 0.999;
    checkEXP(EXP1);
    checkM(M1);
}

//2.2.3
void case3(int & EXP1, int & M1, int & M1u){
    if(EXP1 < 300){
        M1 -= 100;
        M1u += 100;
    }
    else{
        M1 -= 120;
        M1u += 120;
    }
    EXP1 = EXP1*0.9 + 0.999;
    checkEXP(EXP1);
    checkM(M1);
}

bool CompareToBreak(int a, int b){
    if(a > b){
    return 1;}
    else return 0;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(checkE(E2))
        return -99;
    else{
        checkHP(HP1);
        checkEXP(EXP1);
        checkM(M1);
        double P1;
        //DUONG 1
        if(EXP1 >= nearestSquare(EXP1))
            P1 = 1;
        else P1 = (EXP1/nearestSquare(EXP1) + 80)/123.0;

        //DUONG 2
        float M1i = M1/2.0;
        int M1u=0;
        if(E2 % 2 != 0){
            while(1){
                //case 1
                case1(HP1, M1, M1u);
                if(CompareToBreak(M1u, M1i)){
                    break;
                }
                //case 2
                case2(EXP1, M1, M1u);
                if(CompareToBreak(M1u, M1i)){
                    break;
                }
                //case 3
                case3(EXP1, M1, M1u);
                if(CompareToBreak(M1u, M1i)){
                    break;
                }
            }}
        else {
                if(M1>0)
                    case1(HP1, M1, M1u);

                if(M1>0)
                    case2(EXP1, M1, M1u);

                if(M1>0)
                    case3(EXP1, M1, M1u);
        }
        HP1 = HP1*0.83 + 0.999;
        EXP1 = EXP1*1.17 + 0.999;
        checkHP(HP1);
        checkEXP(EXP1);

   
        double P2;
        if(EXP1 >= nearestSquare(EXP1))
            P2 = 1;
        else P2 = (EXP1/nearestSquare(EXP1) + 80)/123.0;

        //DUONG 3
        double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i = 0;
        if(E2 / 10 != 0)
            i = (E2/10 + E2%10)%10;
        else i = E2;
        if(P1 == 1 && P2 == 1 && (P[i]/100) == 1){
            EXP1 = EXP1*0.75 + 0.999;
        }
        else if(((P1 + P2 + (P[i]/100))/3.0) < 0.5){
            HP1 = HP1*0.85 + 0.999;
            EXP1 = EXP1*1.15 + 0.999;
        }
        else {
            HP1 = HP1*0.9 + 0.999;
            EXP1 = EXP1*1.2 + 0.999;
        }
        checkHP(HP1);
        checkEXP(EXP1);
    return HP1 + EXP1 + M1;
    }
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int result=0;
    if(checkE(E3))
        return -99;
    else{
        int a[10][10] = {0};
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                a[i][j]= ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        int i1 = 0, j1 = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(a[i][j] > E3*2)
                    i1++;
            }
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(a[i][j] < -E3)
                    j1++;
            }
        }

        while(i1 / 10 != 0){
            i1 = i1/10 + i1%10;
        }

        while(j1 / 10 != 0){
            j1 = j1/10 + j1%10;
        }

        int taxi = a[i1][j1];


        int max_score=0;
        //duong cheo trai
        for(int i=i1, j=j1; (i>= 0 && j>=0);){
            if(a[i][j] > max_score)
                    max_score = a[i][j];
            i--;
            j--;
        }

        for(int i=i1, j=j1; (i< 10 && j<10);){
            if(a[i][j] > max_score)
                    max_score = a[i][j];
            i++;
            j++;
        }

        //duong cheo phai
        for(int i=i1, j=j1; (i< 10 && j>=0);){
            if(a[i][j] > max_score)
                    max_score = a[i][j];
            i++;
            j--;
        }

        for(int i=i1, j=j1; (i>= 0 && j<10);){
            if(a[i][j] > max_score)
                    max_score = a[i][j];
            i--;
            j++;
        }


        if(max_score < 0)
            max_score = abs(max_score);


        if(abs(taxi)>max_score){
            EXP1 = EXP1*0.88 + 0.999;
            EXP2 = EXP2*0.88 + 0.999;
            HP1 = HP1*0.9 + 0.999;
            HP2 = HP2*0.9 + 0.999;
            result = taxi;
        }
        else{
            EXP1 = EXP1*1.12 + 0.999;
            EXP2 = EXP2*1.12 + 0.999;
            HP1 = HP1*1.1 + 0.999;
            HP2 = HP2*1.1 + 0.999;
            result = max_score;
        }
        checkHP(HP1);
        checkEXP(EXP1);
        checkHP(HP2);
        checkEXP(EXP2);
    }
    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s1=s;
    string email1=email;
    string se;
    se = email1.substr(0, email1.find('@'));
    if(s1.length() < 8)
        return -1;
    else if(s1.length() > 20)
        return -2;
    else if(s1.find(se) < s1.length())
        return -(300 + s1.find(se));
    
    for(int i=0; i<s1.length()-2; i++){
        if(s1[i] == s1[i+1] && s1[i+1] == s1[i+2])
            return -(400+i);
    }
    string ktdb = "@#%$!";
    bool b_ktdb = 0;
    for(int i=0; i<s1.length(); i++){
        char letter = s1[i];
        if(ktdb.find(letter) < ktdb.length()){
            b_ktdb = 1;
            break;
        }
    }
    if(!b_ktdb)
        return -5;
    for(int i=0; i<s1.length(); i++){
        if(s1[i]=='!' || s1[i]>='#' && s1[i]<='%' || s1[i]>='0' && s1[i]<='9' || s1[i]>='@' && s1[i]<='Z' || s1[i]>='a' && s1[i]<='z'){
        continue;
        }
        else return i;
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count=0;
    int max_length=0;
    string CorrectPass;
    int result=0;
    string arr1_pwds[num_pwds];
    for(int i=0; i<num_pwds; i++){
        arr1_pwds[i] = arr_pwds[i];
    }

    for(int i=0; i<num_pwds; i++){
        int counta=0;
        for(int j=0; j<num_pwds; j++){
            if(arr1_pwds[j] == arr1_pwds[i]){
                counta++;
            }
        }

    if(counta > max_count){
        max_count = counta;
        max_length = arr1_pwds[i].length();
        CorrectPass = arr1_pwds[i];
        result = i;
    }
    else if(counta == max_count && arr1_pwds[i].length() > max_length){
        max_count = counta;
        max_length = arr1_pwds[i].length();
        CorrectPass = arr1_pwds[i];
        result = i;
    }
    }
    for(int k=0; k<num_pwds; k++){
        if(arr1_pwds[k] == arr1_pwds[result]){
            result = k;
            break;
        }
    }
    return result;
}
    

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////