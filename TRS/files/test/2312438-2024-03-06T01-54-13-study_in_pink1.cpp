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
/// HO CHI MINH CITY UNIVERSITY OF TECHNOLOGY (HCMUT)                ///     
/// FACULTY OF COMPUTER SCIENCE AND ENGINEERING                      ///
/// PROGRAMMING FUNDAMENTALS - CO1027                                ///
/// SHERLOCK - A STUDY IN PINK - Part 1                              ///
/// NGUYEN PHUC NHAN                                                 /// 
/// 2312438                                                          ///
////////////////////////////////////////////////////////////////////////

const int Max_hp = 666;      //    0 < hp < 666
const int Max_exp = 600;     //    0 < exp < 600
const int Max_m = 3000;      //    0 < m < 3000

//Check variable function
//    we need to check the variable to make sure it is in the range
//      we reset the variable to the nearest range if it is out of range
//       if the variable < 0, we set it to 0
//       if the variable > Max, we set it to Max
void checkVar(int & Var, int Max){
    if (Var < 0)         Var = 0;
    else if (Var > Max)  Var = Max;
}

//Caculate Change Of Variable
//     before change the variable, we need to make the change is integer
//     if the change make variable out of range, we need to reset it to the nearest range
//     so we need to check the variable after change
void calculateChange(int & Var, double change, int Max) {
    //cout << Var << " " << change << " " << Max << endl;
    if (abs(change - int(change)) > 1e-9) {
        change = ceil(change);
    }
    Var += (int)change;
    checkVar(Var, Max);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkVar(exp1, Max_exp);
    checkVar(exp2, Max_exp);
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    //CASE 1    0 <= e1 <= 3
    //in this case
    //exp2 have 4 case to change
    //exp1 have 2 case to change
    if (0 <= e1 && e1 <= 3){
        //change exp2
        switch (e1) {
            case 0:
                calculateChange(exp2, 29, Max_exp);
                break;
            case 1:
                calculateChange(exp2, 45, Max_exp);
                break;
            case 2:
                calculateChange(exp2, 75, Max_exp);
                break;
            case 3:
                calculateChange(exp2, 149, Max_exp);
                break;
        }

        //   D is value to effect to exp1 (Homes's Decisions)
        double D = e1 * 3 + exp1 * 7;
        //change exp1
        if ((int)D % 2 == 0) {
            //D is even, exp1 is increased by D/200
            calculateChange(exp1, D/200, Max_exp);
        } else {
            //D is odd, exp1 is decreased by D/100
            calculateChange(exp1, -D/100, Max_exp);
        }
    }

    //CASE 2    4 <= e1 <= 99
    //in this case
    //exp2 have 5 case to change
    //exp1 always decrease by e1
    else if (4 <= e1 && e1 <= 99){
        //change exp1
        calculateChange(exp1, -e1, Max_exp);

        //change exp2
        if (4 <= e1 && e1 <= 19) {
            calculateChange(exp2, e1/4.0 + 19, Max_exp);            //(Waston get information 1)
        }
        else if (20 <= e1 && e1 <= 49) {
            calculateChange(exp2, e1/9.0 + 21, Max_exp);            //(Waston get information 2)
        }
        else if (50 <= e1 && e1 <= 65) {
            calculateChange(exp2, e1/16.0 + 17, Max_exp);           //(Waston get information 3)
        }
        else if (66 <= e1 && e1 <= 79) {
            calculateChange(exp2, e1/4.0 + 19, Max_exp);           
            if (exp2 > 200) {
                calculateChange(exp2, e1/9.0 + 21, Max_exp);        
            }
        }
        else if (80 <= e1 && e1 <= 99) {
            calculateChange(exp2, e1/4.0 + 19, Max_exp);
            calculateChange(exp2, e1/9.0 + 21, Max_exp);
            if (exp2 > 400) {
                calculateChange(exp2, e1/16.0 + 17, Max_exp);
                //if Wasson get 3 informations, exp2 is increased by 15% of exp2
                calculateChange(exp2, exp2 * 0.15, Max_exp);
            }
        }
    }
    return exp1 + exp2;
}
////////////////////////////////// Complete mission 1 09:02 19/02/2024 HCMUT

//Calculate nearest perfect square
int nearestPerfectSquare(int n) {
    double sqrt_n = sqrt(n);
    sqrt_n = floor(sqrt_n);
    int lowerSquare = sqrt_n * sqrt_n;
    int upperSquare = (sqrt_n + 1) * (sqrt_n + 1);
    if (abs(upperSquare - n) < abs(lowerSquare - n)) {
        return upperSquare;
    } else {
        return lowerSquare;
    }
}

void processEventOnWay2(int & HP1, int & EXP1, int & M1, int m1_start, int E3){
    if ((M1 < m1_start * 0.5 && E3 % 2 ==1) ||(M1 == 0 && E3 % 2 == 0)) 
        return;
    // eat & drink will change HP1 and M1
    if (HP1 < 200) {                            //buy food & water
        calculateChange(HP1, HP1 * 0.3, Max_hp);     
        calculateChange(M1, -150, Max_m);
    } else {                                    //buy only water
        calculateChange(HP1, HP1 * 0.1, Max_hp);
        calculateChange(M1, -70, Max_m);
    }
    //cout << "if_way2: " << m1_start - M1 << endl;
    if ((M1 < m1_start * 0.5 && E3 % 2 ==1) ||(M1 == 0 && E3 % 2 == 0)) 
        return;
    // take taxi or horse
    if (EXP1 < 400) {                   //take taxi 
        calculateChange(M1, -200, Max_m);
    } else {                            //take horse
        calculateChange(M1, -120, Max_m);
    }
    calculateChange(EXP1, EXP1 * 0.13, Max_exp);
    //cout << "if_way3: " << m1_start - M1 << endl;
    if ((M1 < m1_start * 0.5 && E3 % 2 ==1) ||(M1 == 0 && E3 % 2 == 0)) 
        return;
    // help homeless
    if (EXP1 < 300) {                   //homeless will give information
        calculateChange(M1, -100, Max_m);
    } else {   
        //homeless give information & lead the way
        calculateChange(M1, -120, Max_m);
    }
    //exp1 always change in this way because of wrong information from homeless
    calculateChange(EXP1, -EXP1 * 0.1, Max_exp);
    //cout << "if2_way4: " << m1_start - M1 << endl;
    if ((M1 < m1_start * 0.5 && E3 % 2 ==1) ||(M1 == 0 && E3 % 2 == 0)) 
        return;
}

// Task 2
void checkEXP(int &EXP1){
    if(EXP1 < 0) EXP1 = 0;
    else if (EXP1 > 600) EXP1 = 600;
}

void checkHP(int &HP1){
    if(HP1 < 0) HP1 = 0;
    else if (HP1 > 666) HP1 = 666;
}

void checkM(int &M1){
    if(M1 < 0) M1 = 0;
    else if (M1 > 3000) M1 = 3000;
}
double ceil(double x){
    if (x - (int)x > 1e-9) 
    return (int)x + 1;
    else return (int)x;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if ( E2 < 0 || E2 >99 ) return -99;
    else{
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    // Con duong 1
    int a,b,c,S;
    a = floor(sqrt(EXP1));
    b = EXP1 - a*a;
    c = (a+1)*(a+1) - EXP1;
    if (b < c){
        S =  a*a;
    }
    else S = (a+1)*(a+1);
    double P1;
    if( EXP1 >= S) P1 = 100;
    else P1 = (((double)EXP1/S + 80)/123)*100;

    // Con duong 2
    int m = 0,n = M1;
    double P2;
    if ( E2 % 2 == 1){
        while(1){
            if(HP1 < 200){
                HP1 = ceil(1.3*HP1);
                M1 -= 150;
                m += 150;
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
            else{
                HP1 = ceil(1.1*HP1);
                M1 -= 70;
                m += 70;
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
            if( EXP1 < 400){
                M1 -= 200;
                m +=200;
                EXP1 = ceil(1.13*EXP1);
                checkEXP(EXP1);
                checkM(M1);
                if(m > 0.5*n) break; 
            }
            else{
                M1 -= 120;
                m += 120;
                checkM(M1);
                EXP1 = ceil(1.13*EXP1);
                checkEXP(EXP1);
                if(m > 0.5*n) break;
            }
            if(EXP1 < 300){
                M1 -= 100;
                m += 100;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
            else{
                M1 -= 120;
                m += 120;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
                if(m > 0.5*n) break;
            }
        }
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        checkEXP(EXP1);
        checkHP(HP1);
        checkM(M1);
        // THEM SO CHINH PHUONG
         int a1,b1,c1,S1;
    a1 = floor(sqrt(EXP1));
    b1 = EXP1 - a1*a1;
    c1 = (a1+1)*(a1+1) - EXP1;
    if (b1 < c1){
        S1 = a1*a1;
    }
    else S1 = (a1+1)*(a1+1);
        if(EXP1 >= S1) P2 = 100;
        else P2 = (((double)EXP1/S + 80) / 123)*100;
    }
    else{
        if(HP1 < 200){
                HP1 = ceil(1.3*HP1);
                M1 -= 150;
                checkHP(HP1);
                checkM(M1);
            }
            else{
                HP1 = ceil(1.1*HP1);
                M1 -= 70;
                checkHP(HP1);
                checkM(M1);   
            }
            if(M1 > 0){
if( EXP1 < 400){
                M1 -= 200;
                checkM(M1);
            }
            else{
                M1 -= 120;
                checkM(M1);
            }
            EXP1 = ceil(1.13*EXP1);
                checkEXP(EXP1);
            }
            
            if(M1 > 0){
            if(EXP1 < 300){
                M1 -= 100;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
            }
            else{
                M1 -= 120;
                EXP1 = ceil(0.9*EXP1);
                checkEXP(EXP1);
                checkHP(HP1);
                checkM(M1);
            }}
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        checkEXP(EXP1);
        checkHP(HP1);
        checkM(M1);
        int a1,b1,c1,S1;
    a1 = floor(sqrt(EXP1));
    b1 = EXP1 - a1*a1;
    c1 = (a1+1)*(a1+1) - EXP1;
    if (b1 < c1){
        S1 = a1*a1;
    }
    else S1 = (a1+1)*(a1+1);
        if(EXP1 >= S1) P2 = 100;
        else P2 = (((double)EXP1/S + 80) / 123)*100;
    }

    //Con duong 3
    double P3;
    int p3[10] = {32,47,28,79,100,50,22,83,64,11};
    if(E2 < 10){
        P3 = p3[E2];}
    else if( E2 > 10 && E2 < 99){
        int e2,e3;
        e2 = E2 % 10 + E2 /10;
        e3 = e2 % 10;
        P3 = p3[e3];
    }
    double P4;
    if( P1 == 100 && P2 == 100 && P3  == 100){
        EXP1 = ceil(0.75*EXP1);
        checkEXP(EXP1);
    }
    else{
        P4 = ( P1+ P2 + P3)/3.0;
        if(P4 < 50){
            HP1 =ceil(HP1* 0.85);
            EXP1 = ceil(EXP1* 1.15);
            checkEXP(EXP1);
        }
        else{
            HP1 = ceil(HP1* 0.9);
            EXP1 = ceil(EXP1 * 1.20);
            checkEXP(EXP1);
            checkHP(HP1);
        }
    }
    return HP1 + EXP1 + M1;
}}

///////////////////////////////////////////////////////////////////// Complete mission 2 010:21 19/02/2024 HCMUT

int sumDigits(int num) {
    int sum = num;
    while (sum > 9){
        int temp = sum;
        sum = 0;
        while (temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
    }   
    return sum;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkVar(EXP1, Max_exp);
    checkVar(EXP2, Max_exp);
    checkVar(HP1, Max_hp);
    checkVar(HP2, Max_hp);
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    int TaxiScore[10][10] = {0};
    int i_meet = 0, j_meet = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // calculate Taxi score = ((E3 ∗j) + (i ∗2)) ∗(i −j)
            TaxiScore[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (TaxiScore[i][j] > (E3 * 2)) {
                ++i_meet;
            }
            if (TaxiScore[i][j] < -E3) {
                ++j_meet;
            }
        }
    }
    i_meet = sumDigits(i_meet);
    j_meet = sumDigits(j_meet);
    int HomesandWastonScore;
    int i = i_meet, j = j_meet;
    HomesandWastonScore = TaxiScore[i][j];
    while (i >= 0 && j >= 0) {
        HomesandWastonScore = max(HomesandWastonScore, TaxiScore[i--][j--]);
    }
    i = i_meet, j = j_meet;
    while (i < 10 && j < 10) {
        HomesandWastonScore = max(HomesandWastonScore, TaxiScore[i++][j++]);
    }
    i = i_meet, j = j_meet;
    while (i >= 0 && j < 10) {
        HomesandWastonScore = max(HomesandWastonScore, TaxiScore[i--][j++]);
    }
    i = i_meet, j = j_meet;
    while (i < 10 && j >= 0) {
        HomesandWastonScore = max(HomesandWastonScore, TaxiScore[i++][j--]);
    }
    if (abs(TaxiScore[i_meet][j_meet]) > abs(HomesandWastonScore)) {
        calculateChange(HP1, -HP1 * 0.1, Max_hp);
        calculateChange(HP2, -HP2 * 0.1, Max_hp);
        calculateChange(EXP1, -EXP1 * 0.12, Max_exp);
        calculateChange(EXP2, -EXP2 * 0.12, Max_exp);
        return TaxiScore[i_meet][j_meet];
    } else {
        calculateChange(HP1, HP1 * 0.1, Max_hp);
        calculateChange(HP2, HP2 * 0.1, Max_hp);
        calculateChange(EXP1, EXP1 * 0.12, Max_exp);
        calculateChange(EXP2, EXP2 * 0.12, Max_exp);
        return HomesandWastonScore;
    }
    return TaxiScore[i_meet][j_meet];
}

/////////////////////////////////////////////////////////////////// Complete mission 3 13:45 19/02/2024 HCMUT

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // check length of s
    // convert char* to string
    string email_str = email;
    string str = s;
    int length = str.length();
    if (length < 8){
        return -1;
    } else if (length > 20){
        return -2;
    }

    //Get se from email
    string se = email_str.substr(0, email_str.find('@'));

    // Check s contains se
    const char *pos = strstr(s, se.c_str());
    if (pos != nullptr)
        return -(300 + (pos - s));
    
    // Check s contains > 2 same characters
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }

    // Chech special characters
    bool hasSpecial = false;
    string specialCharacters = "!@#$%";
    for (int i = 0; i < length; i++) {
        if (specialCharacters.find(str[i]) != string::npos) {
            hasSpecial = true;
            break;
        }
    }
    if (!hasSpecial) return -5;

    //Check valid characters
    // s contains number or lowercase or uppercase or special character, not contains other characters
    for (int i = 0; i < length; ++i) {
        if (!('0' <= str[i] && str[i] <= '9') && 
            !('a' <= str[i] && str[i] <= 'z') &&
            !('A' <= str[i] && str[i] <= 'Z') &&
            specialCharacters.find(str[i]) == string::npos) {
            return i;
        }
    }

    return -10;
}

//////////////////////////////////////////////////////////////////////// Complete mission 4 16:30 19/02/2024 HCMUT

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int maxPosition = -1;

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == nullptr) continue;
        const char *password = arr_pwds[i];
        int count = 1;
        int length = strlen(password);
        
        for (int j = i + 1; j < num_pwds; ++j) {
            if (arr_pwds[j] == nullptr) continue;
            if (strcmp(password, arr_pwds[j]) == 0) {
                ++count;
                arr_pwds[j] = nullptr;
            }
        }

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            maxPosition = i;
        }
    }

    return maxPosition;
}

///////////////////////////////////////////////////////////////////// Complete mission 5 21:25 19/02/2024 HCMUT

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER                  ///
////////////////////////////////////////////////