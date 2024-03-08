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
void exp(int &exp){
    if(exp > 600){
        exp = 600;
    }else if(exp < 0){
        exp = 0;
    }
}

void money(int &m){
    if(m > 3000){
        m = 3000;
    }else if(m < 0){
        m = 0;
    }
}

void hp(int &hp){
    if(hp > 666){
        hp = 666;
    }else if(hp < 0){
        hp = 0;
    }
}

int square(int EXP1){

    int temp = sqrt(EXP1); 
    int S;
    if(pow(temp,2) == EXP1){
        S = EXP1;
    }else{
        int b = abs(pow(temp,2) - EXP1);
        int c = abs(pow(temp + 1,2) - EXP1);
        if(b < c){
            S = pow(temp,2);
        }
        else{
            S = pow(temp + 1,2);
        }
    }
    return S;
}

int twodigitinto1task2(int E2){
    int a = E2;
        int m = a / 10;
        int n = a % 10;
        a = m + n;
        return a % 10;
}

int twodigitinto1task3(int E3){
    int a = E3;
    while(a >= 10){
        int m = a / 10;
        int n = a % 10;
        a = m + n;
    }
    return a;
}
//--------------------------------------------------------------
//                          MAIN PROGRAM
//--------------------------------------------------------------
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if(e1 < 0 || e1 > 99)   return -99;
    else{
        exp(exp1);
        exp(exp2);
        if(e1 >= 0 && e1 <= 3){
            if(e1 == 0){
                exp2 += 29;
                exp(exp2);
            }else if (e1 == 1){
                exp2 += 45;
                exp(exp2);
            }else if(e1 == 2){
                exp2 += 75;
                exp(exp2);
            }else if(e1 == 3){
                exp2 += 29 + 45 + 75;
                exp(exp2);
            }
            //check Afghanistan or Iraq
            int D = e1*3 + exp1*7;
            if(D % 2 == 0){
                exp1 += ceil((double)D/200);
                exp(exp1);
            }else{
                exp1 -= ceil((int)D/100);
                exp(exp1);
            }
            return exp1 + exp2;
        }else if(e1 >= 4 && e1 <= 99){
            if(e1 <= 19){
                exp2 += ceil(((double)e1/4) + 19);
                exp(exp2);
            }else if(e1 >= 20 && e1 <= 49){
                exp2 += ceil(((double)e1/9) + 21);
                exp(exp2);
            }else if(e1 >= 50 && e1 <= 65){
                exp2 += ceil(((double)e1/16) + 17);
                exp(exp2);
            }else if(e1 >= 66 && e1 <= 79){
                exp2 += ceil(((double)e1/4) + 19);  
                exp(exp2);
                if(exp2 > 200){
                    exp2 += ceil(((double)e1/9) + 21);
                    exp(exp2);
                }
            }else if(e1 >= 80 && e1 <= 99){
                exp2 += ceil(((double)e1/4) + 19);
                exp(exp2);
                exp2 += ceil(((double)e1/9) + 21);
                exp(exp2);
                if(exp2 > 400){
                    exp2 += ceil((double)e1/16 + 17);
                    exp(exp2);
                    exp2 += ceil(0.15*exp2);
                    exp(exp2);
                }
            }
        }
        exp1 -= e1;
        exp(exp1);
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 < 0 || E2 > 99) return -99;
    else{
    hp(HP1);
    exp(EXP1);
    money(M1);
    double p1,p2,p3,p;
    // TODO: Complete this function
    //Road 01

    //algo to find the nearest square number EXP1
    int S1 = square(EXP1);
    //probability p1    
    if(EXP1 >= S1){
        p1 = 1;
    }else{
        p1 = ((EXP1*1.0 / S1) + 80)/123.0;
        
    }
   //Road 02
    const double current = (M1/2);
    int paid = 0;  
    if(E2 % 2 != 0){
        while(paid <= current){
            if(M1 <= 0){
                break;
            }
            //event 01
            if(HP1 < 200){
                HP1 = ceil(1.3*HP1 - 1e-10);
                M1 -= 150;
                paid += 150;
                hp(HP1);
                money(M1);
            }else{
                HP1 = ceil(1.1*HP1 - 1e-10);
                M1 -= 70;
                paid += 70;
                hp(HP1);
                money(M1);
            }
            //check
            if(paid > current){
                break;
            }
            //event 02
            if(EXP1 < 400){
                M1 -= 200;
                paid += 200;
                money(M1);
            }else{
                M1 -= 120;
                paid += 120;
                money(M1);
            }
            EXP1 += ceil(0.13*EXP1);
            exp(EXP1);
            //check
            if(paid > current){
                break;
            }
            //event 03
            if(EXP1 < 300){
                M1 -= 100;
                paid += 100;
                money(M1);
            }else{
                M1 -= 120;
                paid += 120;
                money(M1);
            }
            EXP1 -= floor(0.1*EXP1);
            exp(EXP1);
        }

    }
    while(E2 % 2 == 0){
        if(M1 <= 0){
            break;
        }
        //event 01
        if(HP1 < 200){
            HP1 = ceil(1.3*HP1 - 1e-10);
            M1 -= 150;
            hp(HP1);
            money(M1);
        }else{
            HP1 = ceil(1.1*HP1 - 1e-10);
            M1 -= 70;
            hp(HP1);
            money(M1);
        }
        //check
        if(M1 <= 0){
            M1 = 0;
            break;
        }
        //event 02
        if(EXP1 < 400){
            M1 -= 200;
            money(M1);
        }else{
            M1 -= 120;
            money(M1);
        }
        EXP1 += ceil(0.13*EXP1);
        exp(EXP1);
        //check
        if(M1 <= 0){
            M1 = 0;
            break;
        }
        //event 03
        if(EXP1 < 300){
            M1 -= 100;
            money(M1);
        }else{
            M1 -= 120;
            money(M1);
        }
        EXP1 -= floor(0.1*EXP1);
        exp(EXP1);
        break;
    }    
        HP1 = ceil(0.83*HP1 - 1e-10);
        EXP1 = ceil(1.17*EXP1);
        hp(HP1);
        exp(EXP1);
    //probability p2
    int S2 = square(EXP1);
    if(EXP1 >= S2){
        p2 = 1;
    }else{
        p2 = ((EXP1*1.0 / S2*1.0) + 80)/123.0;
    }
    //Road 03
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    p3 = P[twodigitinto1task2(E2)] / 100;
    //Average probability
    p = (p1 + p2 + p3)/3;
    if(p == 1){
            EXP1 -= floor(0.25*EXP1);
            exp(EXP1);
    }else{
        if(p < 0.5){
            HP1 = ceil(0.85*HP1 - 1e-10);
            EXP1 += ceil(0.15*EXP1);
            hp(HP1);
            exp(EXP1);
        }else{
            HP1 = ceil(0.9*HP1 - 1e-10);
            EXP1 = ceil(1.2*EXP1);
            hp(HP1);
            exp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        // TODO: Complete this function
    int x,y,result = 0;
    int max;
    if(E3 < 0 || E3 > 99) return -99;
    else{
        int arr[10][10];
        //Value for each index and Cout the value in comparison with E3
        int positive = 0;
        int negative = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                arr[i][j] = ((E3*j) + (i * 2)) * (i - j);
                if(arr[i][j] > 2*E3){
                    positive++;
                }else if(arr[i][j] < (-E3)){
                    negative++;
                }
            }
        }
        //check 2 digit in number
        
        if(positive > 9 && positive < 99){
            x = twodigitinto1task3(positive);
        }
        else if(positive >= 0 && positive <= 9){
            x = positive;
        }
        if(negative > 9 && negative < 99){
            y = twodigitinto1task3(negative);
        }else if(negative >= 0 && negative <= 9){
            y = negative;
        }
        //left diagonal
        max = arr[x][y];
        for(int m=0; m<10;m++){
            for(int n=0; n<10; n++){
                if(((n + m)==(x + y)) || ((m - n)==(x - y))){
                    if(max < arr[m][n]) max = arr[m][n];
                }
            }
        }
            hp(HP1);
            exp(EXP1);
            hp(HP2);
            exp(EXP2);
        if (abs(arr[x][y]) > abs(max)){
            HP1 = ceil(HP1*0.9 - 1e-10);
            EXP1 = ceil(EXP1*0.88- 1e-10);
            HP2 = ceil(HP2*0.9- 1e-10);
            EXP2 = ceil(EXP2*0.88- 1e-10);
            //check func
            hp(HP1);
            exp(EXP1);
            hp(HP2);
            exp(EXP2);

            result= arr[x][y];
        }else{
            HP1 = ceil(HP1*1.1 - 1e-10);
            EXP1 = ceil(EXP1*1.12 -1e-10);
            HP2 = ceil(HP2*1.1 - 1e-10);
            EXP2 = ceil(EXP2*1.12 -1e-10);
            //check func
            hp(HP1);
            exp(EXP1);
            hp(HP2);
            exp(EXP2);

            result = max;
        }
    }
    return result;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = {};
    string S = s;
    string EMAIL = email;

    //check length of s
    
    if(S.size() < 8){
        return -1;
    }
    if(S.size() > 20){
        return -2;
    }
    //Initialiexp1e se
    for(int i = 0;i < EMAIL.length();i++){
        if(EMAIL[0] == '@'){
            break;
        }else{
            se += EMAIL[i];
            if(EMAIL[i + 1] == '@'){
                break;
            }
        }
    }
    //check if se in S
    if(S.find(se) != string::npos){
        return -(300 + S.find(se));
    }
    //check if se have 3 similar symbol
    for(int i = 0;i < S.length() - 2;i++){
        if(S[i] == S[i + 1] && S[i + 1] == S[i + 2]){
            return  -(400 + i);
        }
    }
    //check if there is no special char
    if(S.find('@') == string::npos && S.find('!') == string::npos && S.find('%') == string::npos && S.find('$') == string::npos && S.find('#') == string::npos){
        return -5;
    }
    //check if is there any special case
    for(int i = 0;i < S.length();i++){
        if(S[i] != '@' && S[i] != '!' && S[i] != '%' && S[i] != '$' && S[i] != '#' && isalpha(S[i]) == 0 && isdigit(S[i]) == 0){
            return i;
        }
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int size = num_pwds;
    int arr_a[size],arr_b[size];
    string arr3[size];

    for(int i = 0;i < size;i++){
        arr3[i] = arr_pwds[i];
        arr_b[i] = arr3[i].length();
    }

    for(int i = 0;i < size;i++){
        int count=0;
        for(int j = 0;j < size;j++){
            if(arr3[i] == arr3[j]){
                count++;
            }
        }
        arr_a[i] = count;
    }
    int m_a = 0;
    int m_b = 0;
    for(int i = 0;i < size;i++){
        if(arr_a[i] >= m_a){
            m_a = arr_a[i];
        }
    }
    for(int i = 0;i < size;i++){
        if(m_a > arr_a[i]){
            arr_b[i] -= arr_b[i];
        }
    }
    for(int i = 0;i < size;i++){
        if(m_b < arr_b[i]){
            m_b = arr_b[i];
        }
    }
    for(int i = 0;i < size;i++){
        if(arr_a[i] == m_a && arr_b[i] == m_b){
            return i;
        }
    }
    return 0;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////