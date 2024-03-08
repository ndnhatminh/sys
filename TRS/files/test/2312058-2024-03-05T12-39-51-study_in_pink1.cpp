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

int checkHp(int hp){
    if(hp > 600){
        return 600;
    }
    else if(hp<0){
        return 0;
    }
    else return hp;
}

int checkExp(int exp){
    if(exp > 600){
        return 600;
    }
    else if(exp<0){
        return 0;
    }
    else return exp;
}

int checkM(int m){
    if(m > 3000){
        return 3000;
    }
    else if(m<0){
        return 0;
    }
    else return m;
}

bool isPerfect(double x){
    if(sqrt(x)-floor(sqrt(x))==0){
        return true;
    }
    else return false;
}

double getClosetPerfect(double N){
    if(isPerfect(N)){
        return N;
    }
    else{
        double aboveN, belowN;
        double n1;
        n1 = N + 1;
        while(true){
            if(isPerfect(n1)){
                aboveN = n1;
                break;
            }
            else n1++;
        }
        double diff1 = aboveN - N;
        n1 = N -1 ;
        while(true){
            if(isPerfect(n1)){
                belowN = n1;
                break;
            }
            else n1--;
        }
        double diff2 = N - belowN;
        if(diff1>diff2){
            return belowN;
        }
        else return aboveN;
    }
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1<0||E1>99) return -99;
    if(E1>=0&&E1<=3){
        switch(E1){
            case 0:
                EXP2 += 29;
                EXP2 = checkExp(EXP2);
                break;
            case 1:
                EXP2 += 45;
                EXP2 = checkExp(EXP2);
                break;
            case 2:
                EXP2 += 75;
                EXP2 = checkExp(EXP2);
                break;
            case 3:
                EXP2 += 29+75+45;
                EXP2 = checkExp(EXP2);
                break;
        }
        int D = E1*3 + EXP1*7;
        if(D%2==0){
            double exp1 = (double)EXP1 + (double)D/200;
            exp1 = ceil(exp1);
            EXP1 = checkExp(exp1); 
        }
        else{
            double exp1 = (double)EXP1 - (double)D/100;
            exp1 = ceil(exp1);
            EXP1 = checkExp(exp1);
        }
    }
    else{
        if(E1<=19){
            double exp2 = (double)EXP2 + (double)E1 / 4 +19;
            exp2 = ceil(exp2);
            EXP2 = checkExp(exp2);
        }
        else if(E1<=49){
            double exp2 = (double)EXP2 + (double)E1 / 9 + 21;
            EXP2 = checkExp(ceil(exp2));
        }
        else if(E1<=65){
            double exp2 = (double)EXP2 + (double)E1 / 16 + 17;
            EXP2 = checkExp(ceil(exp2));
        }
        else if(E1<=79){
            double exp2 =(double)EXP2 +  (double)E1 / 4 +19;
            EXP2 = checkExp(ceil(exp2));
            if(EXP2>200){
                double exp2 = (double)EXP2 + (double)E1 / 9 + 21;
                EXP2 = checkExp(ceil(exp2));
            }
        }
        else if(E1<=99){
            double exp2 = (double)EXP2 + (double)E1 / 4 +19;
            exp2 = exp2 + exp2 / 9 + 21;
            EXP2 = checkExp(ceil(exp2));
            if(EXP2>400){
                double exp2 = (double)EXP2 + (double)E1 / 16 + 17;
                EXP2 = checkExp(ceil(exp2));
                exp2 = (double)EXP2*1.15;
                EXP2 = checkExp(ceil(exp2));
            }
        }
        EXP1 -=E1;
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0||E2>99) return -99;
    //road1:
    double P1;
    double S = getClosetPerfect(EXP1);
    if(EXP1>=S){
        P1 = 100;
    }
    else{
        double exp1 = EXP1;
        P1 = (exp1/S+80)/123*100;
    }
    //road2:
    if(E2%2!=0){
        double m1 = M1;
        double budget = m1*0.5;
        double moneySpent = 0;
        while(true){
            if(HP1<200){
                double hp1 = HP1;
                hp1 = hp1*1.3;
                HP1 = checkHp(ceil(hp1));
                double m1 = M1;
                m1 = m1 - 150;
                M1 = checkM(ceil(m1));
                moneySpent += 150;
                if(moneySpent>budget) break;
            }
            else{
                double hp1 = HP1;
                hp1 *=1.1;
                HP1 = checkHp(ceil(hp1));
                double m1 = M1;
                m1 -= 70;
                M1 = checkM(ceil(m1));
                moneySpent += 70;
                if(moneySpent>budget) break;
            }

            if(EXP1<400){
                double m1 = M1;
                m1 -= 200;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 *=1.13;
                EXP1 = checkExp(ceil(exp1));
                moneySpent +=200;
                if(moneySpent>budget) break;
            }
            else{
                double m1 = M1;
                m1 -= 120;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 *=1.13;
                EXP1 = checkExp(ceil(exp1));
                moneySpent +=120;
                if(moneySpent>budget) break;
            } 

            if(EXP1<300){
                double m1 = M1;
                m1 -= 100;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 = exp1*0.9;
                EXP1 = checkExp(ceil(exp1));
                moneySpent +=100;
                if(moneySpent>budget) break;
            }
            else{
                double m1 = M1;
                m1 -= 120;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 = exp1*0.9;
                EXP1 = checkExp(ceil(exp1));
                moneySpent +=120;
                if(moneySpent>budget) break;
            }
        }
        double hp1 = HP1;
        hp1 *=0.83;
        HP1 = checkHp(ceil(hp1));
        double exp1 = EXP1;
        exp1 *= 1.17;
        EXP1 = checkExp(ceil(exp1));
    }
    else{
        while(true){
            if(HP1<200){
                double hp1 = HP1;
                hp1 = hp1*1.3;
                HP1 = checkHp(ceil(hp1));
                double m1 = M1;
                m1 = m1 - 150;
                M1 = checkM(ceil(m1));
                if(M1==0) break;
            }
            else{
                double hp1 = HP1;
                hp1 *=1.1;
                HP1 = checkHp(ceil(hp1));
                double m1 = M1;
                m1 -= 70;
                M1 = checkM(ceil(m1));
                if(M1==0) break;
            }

            if(EXP1<400){
                double m1 = M1;
                m1 -= 200;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 *=1.13;
                EXP1 = checkExp(ceil(exp1));
                if(M1=0) break;
            }
            else{
                double m1 = M1;
                m1 -= 120;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 *=1.13;
                EXP1 = checkExp(ceil(exp1));
                if(M1==0) break;
            } 

            if(EXP1<300){
                double m1 = M1;
                m1 -= 100;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 = exp1*0.9;
                EXP1 = checkExp(ceil(exp1));
                if(M1==0) break;
            }
            else{
                double m1 = M1;
                m1 -= 120;
                M1 = checkM(ceil(m1));
                double exp1 = EXP1;
                exp1 = exp1*0.9;
                EXP1 = checkExp(ceil(exp1));
                break;
            }
        }
        double hp1 = HP1;
        hp1 *=0.83;
        HP1 = checkHp(ceil(hp1));
        double exp1 = EXP1;
        exp1 *= 1.17;
        EXP1 = checkExp(ceil(exp1));
    }
    double exp1 = EXP1;
    double P2;
    S = getClosetPerfect(exp1);
    if(exp1>=S){
        P2 = 100;
    }
    else{
        P2 = (exp1/S+80)/123*100;
    }
    //road3:
    double P[10] = {32, 47,28,79,100,50,22,83,64,11};
    double P3;
    if(E2<10&&E2>=0){
        P3 = P[E2];
    }
    else{
        double e2 = E2;
        double index = floor(e2/10) + E2%10 - 10;
        int I = ceil(index);
        P3 = P[I];
    }
    //after all roads:
    if(P1==100&&P2==100&&P3==100){
        double exp1 = EXP1;
        exp1 *= 0.75;
        EXP1 = checkExp(ceil(exp1));
    }
    else{
        double avgP = (P1+P2+P3)/3;
        if(avgP<50){
            double hp1 = HP1;
            hp1 *= 0.85;
            HP1 = checkHp(ceil(hp1));
            double exp1 = EXP1;
            exp1 *= 1.15;
            EXP1 = checkExp(ceil(exp1));
        }
        else{
            double hp1 = HP1;
            hp1 *= 0.9;
            HP1 = checkHp(ceil(hp1));
            double exp1 = EXP1;
            exp1 *= 1.2;
            EXP1 = checkExp(ceil(exp1));
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0||E3>99) return -99;
    //create a 10X10 matrix
    double Matrix[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            Matrix[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }

    int x=0 ,y=0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            if(Matrix[i][j]>E3*2){
                x+=1;
            }
            else if(Matrix[i][j]<0-E3){
                y+=1;
            }
        }
    }
    while(true){
        if(x>9){
        x = x/10 + x%10;
        }
        else break;
    }
    while(true){
        if(y>9){
        y = y/10 + y%10;
        }
        else break;
    }
    double max;

    int i = x;
    int j = y;
    //find max in upper left matrix
    while(i>=0&&j>=0){
        if(max<=Matrix[i][j]){
            max = Matrix[i][j];
        }
        i-=1;
        j-=1;
    }

    //find max in upper right matrix
    i = x;
    j = y;
    while(i>=0&&j<=9){
        if(max<=Matrix[i][j]){
            max = Matrix[i][j];
        }
        i-=1;
        j+=1;
    }
    //find max in lower left matrix
    i = x;
    j = y;
    while(i<=9&&j>=0){
        if(max<=Matrix[i][j]){
            max = Matrix[i][j];
        }
        i+=1;
        j-=1;
    }

    //find max in lower right matrix
    i = x;
    j = y;
    while(i<=9&&j<=9){
        if(max<=Matrix[i][j]){
            max = Matrix[i][j];
        }
        i+=1;
        j+=1;
    }
    //calculate hp and exp
    if(abs(Matrix[x][y])>max){
        float hp1 = HP1;
        hp1 *=0.9;
        HP1 = checkHp(ceil(hp1));
        float hp2 = HP2;
        hp2 *=0.9;
        HP2 = checkHp(ceil(hp2));
        float exp1 = EXP1;
        exp1 *=0.88;
        EXP1 = checkExp(ceil(exp1));
        float exp2 = EXP2;
        exp2 *=0.88;
        EXP2 = checkExp(ceil(exp2));
        return ceil(Matrix[x][y]);
    }
    else{
        double hp1 = HP1;
        hp1 *=1.1;
        HP1 = checkHp(ceil(hp1));
        double hp2 = HP2;
        hp2 *=1.1;
        HP2 = checkHp(ceil(hp2));
        double exp1 = EXP1;
        exp1 *=1.12;
        EXP1 = checkExp(ceil(exp1));
        double exp2 = EXP2;
        exp2 *=1.12;
        EXP2 = checkExp(ceil(exp2));
        return ceil(max);
    }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string S;
    S += s;
    string Email;
    Email += email;
    string se;
    int index=0;
    bool has_special_character;
    bool is_valid_character;
    //create se string;
    for(int i = 0; i < Email.length(); i++){
        if (Email[i] != '@'){
            se += Email[i];
        }
        else if(Email[i]=='@') break;
    }
    //check password length
    if(S.size()<8) return -1;
    else if(S.size()>20) return -2;
    //does s have se
    size_t found = S.find(se);
    if(found != string::npos){
        return -(300+found);
    }
    //2 consecutive and identical character
    for(int i=0; i<S.size()-1;i++){
        if(S[i]==S[i+1]){
            return -(400+i);
        }
    }
    //does not contain one special character
    for(char c:S){
        if(c=='@'||c=='#'||c=='%'||c=='$'||c=='!'){
            has_special_character = true;
        }
        else has_special_character = false;
    }
    if(has_special_character==false) return -5;
    //The other cases
    for(int i=0;i<S.size();i++){
        char c = S[i];
        if(isupper(c)||islower(c)||isdigit(c)||c=='@'||c=='#'||c=='%'||c=='$'||c=='!'){
            is_valid_character = true;
        }
        else is_valid_character = false;
        if(is_valid_character==false) return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string correct_password;
    int count_1 = 1, count_2 = 0, count_3 = 0; 
    int length_1, length_2, length_3;
    string word_1, word_2, word_3;
    for(int i =0; i<num_pwds;i++){
        word_1 = arr_pwds[i];
        length_1 = word_1.size();
        for(int j = i+1;j<num_pwds;j++){
            if(word_1==arr_pwds[j]){
                count_1++;
            }
        }
        if(count_1>count_3){
            count_3=count_1;
            word_3 = word_1;
            length_3 = length_1;
        }
        else if(count_1==count_3){
            count_2 = count_1;
            word_2 = word_1;
            length_2 = length_1;
        }
        if(count_2==count_3){
            if(length_2>length_3){
                word_3 = word_2;
                count_3 = count_2;
                length_3 = length_2;
            }
        }
        
        correct_password = word_3;
    }
    for(int i = 0;i<num_pwds;i++){
        if(arr_pwds[i]==correct_password){
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////