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
int setHP(int HP){
    if(HP < 0) return 0;
    else if(HP > 666) return 666;
    else return HP;	
}

int setEXP(int EXP){
    if(EXP < 0) return 0;
    else if(EXP > 600) return  600;
    else return EXP;
}

int setM(int M){
    if(M < 0) return 0;
    if(M > 3000) return 3000;
   else return M;
}
int firstMeet(int &exp1, int &exp2, int e1){
if(e1 < 0 || e1 > 99) return -99;
if ( e1 >= 0 && e1 <= 3){
        switch(e1) {
            case 0: 
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += 29 + 45 + 75;
                break;
        }
        int D = e1*3 + exp1*7;
        if(D%2 == 0){
            if(D%200 == 0) exp1 += D/200;
            else exp1 += D/200 + 1; 
        }
        else{
            exp1 -= D/100;
        }
    }

    if(e1 >= 4 && e1 <= 99){
        bool full = true;
        if(e1 >= 4 && e1 <= 19){
            if(e1%4 == 0) exp2 += (e1/4 + 19);
            else exp2 += (e1/4 + 19 + 1); 
        }
        if(e1 >=20 && e1 <= 49){
            if(e1%9 == 0) exp2 += (e1/9 + 21);
            else exp2 += (e1/9 + 21 + 1);
        }
        if(e1 >= 50 && e1 <= 65){
            if(e1%16 == 0) exp2 += (e1/16 + 17);
            else exp2 += (e1/16 + 17 + 1);   
        }
        if(e1 >= 66 && e1 <= 79){
            if(e1%4 == 0) exp2 += (e1/4 + 19);
            else exp2 += (e1/4 +19 + 1);
            if(exp2 > 200){
                if(e1%9 == 0) exp2 += (e1/9 + 21);
                else exp2 += (e1/9 + 21 + 1);
            }
        }
        if(e1 >= 80 && e1 <= 99){
            if(e1%4 == 0) exp2 += (e1/4 + 19);
            else exp2 += (e1/4 +19 + 1);
            if(e1%9 == 0) exp2 += (e1/9 + 21);
            else exp2 += (e1/9 + 21 + 1);
            if(exp2 > 400){
                if(e1%16 == 0) exp2 += (e1/16 + 17);
                else exp2 += (e1/16 + 17 + 1);
                full= false;
            }
        }
        
        if(!full){
            exp2 = exp2*2 - int(exp2*0.85);
        }
        exp1 -=  e1;
    }

    exp1 = setEXP(exp1);
    exp2 = setEXP(exp2);
    return exp1 + exp2;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
if(E2 < 0 || E2 > 99) return -99;
    int f = sqrt(EXP1);
    int S = (pow(f+1,2) - EXP1 < EXP1 - pow(f, 2)) ? pow(f+1,2) : pow(f, 2);
    float P1 = (S <= EXP1) ? 1 : (static_cast<float>(EXP1) / S + 80) / 123;
    M1 = setM(M1);
	int tra;
 
    int paid[2]={150,70};
    float halfM1 = M1 *0.5;
    int m = M1;
    if (E2 % 2 == 1){
while (m >= halfM1) {
    if (HP1 < 200) {
        HP1 = ceil(HP1 * 1.3);
        HP1 = setHP(HP1);
        m-=paid[0];
    } else {
        HP1 = ceil(HP1 * 1.1);
        HP1 = setHP(HP1);
        m-=paid[1];
    }
    
    
    if (m < halfM1) break;

    tra = (EXP1 < 400) ? 200 : 120;
    m -= tra;
    EXP1 = ceil(EXP1 * 1.13);
    EXP1 = setEXP(EXP1);
    if (m < halfM1) break;

    tra = (EXP1 < 300) ? 100 : 120;
    m -= tra;
    EXP1 = ceil(EXP1 * 0.9);
    EXP1 = setEXP(EXP1);
    if (m < halfM1) break;
}
            HP1 =ceil( 0.83*HP1 );
            EXP1 = ceil(1.17*EXP1) ; 
            EXP1 = setEXP(EXP1);
} 
    else {
        if (HP1 < 200){
            HP1 =ceil(HP1*1.3 );
            HP1 = setHP(HP1);
           
            m -= paid[0];
        } 
        else {
            HP1 = ceil(HP1*1.1);
            HP1 = setHP(HP1);
            
            m -= paid[1];

        }
        if (m > 0 ){
            tra = (EXP1 < 400)? 200 : 120;
            m -= tra;
	        EXP1 = ceil(EXP1*1.13);
            EXP1 = setEXP(EXP1);
            if (m >0){
	            tra = (EXP1 < 300)? 100 : 120;
                m -= tra;
	            EXP1 = ceil(EXP1*0.9);
                EXP1 = setEXP(EXP1);
            
                }
        }

        HP1 =ceil( 0.83*HP1 );
        EXP1 = ceil(1.17*EXP1) ; 
        EXP1 = setEXP(EXP1);
    }
    int f2 = sqrt(EXP1);
    int S2 = (pow(f2+1,2) - EXP1 < EXP1 - pow(f2, 2)) ? pow(f2+1,2) : pow(f2, 2);
    float P2 = (S2 <= EXP1) ? 1 : (static_cast<float>(EXP1) / S2 + 80) / 123;
    int arrayP3[10] = {32,47,28, 79, 100, 50, 22, 83, 64, 11};
    float P3;
    if (E2 >= 0 && E2 <= 9) {
        P3 =  static_cast<float>(arrayP3[E2]) / 100 ;
    } else if (E2 >= 10 && E2 <= 99) {
        int sum = E2 / 10 + E2 % 10;
        int i = sum % 10;
        P3 = static_cast<float>(arrayP3[i]) /100;
    }
if (P1==P2==P3){
EXP1 -= int(EXP1*0.25);
}
float P = (P1 + P2 + P3)/3;
    if (P < 0.5){
        HP1 =ceil(HP1*0.85);
        EXP1 =ceil(EXP1*1.15);
    } else {
        HP1 =ceil(HP1*0.9);
        EXP1 =ceil(EXP1*1.20);
    }
 EXP1 = setEXP(EXP1);
    M1 = setM(m);
    return HP1+EXP1+M1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
if(E3 < 0 || E3 > 99) return -99;
    int arr[10][10] = {0};
    int di = 0, dj = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > E3 * 2) di++;
            if (arr[i][j] < E3 * (-1)) dj++;
        }
    }

    while (di >= 10) di = (di % 10) + (di / 10);
    while (dj >= 10) dj = (dj % 10) + (dj / 10);

    int TX = arr[di][dj], SL = arr[di][dj];

    // find the Sherlock's point
    for (int i = 0; i < 10; i++) { // duong cheo trai
        if (i + (dj - di) >= 0 && i + (dj - di) < 10) {
            if (arr[i][i + (dj - di)] > SL) {
		SL = arr[i][i + (dj - di)];
}
        }
    }

    for (int i = 0; i < 10; i++) { // duong cheo phai
        if (dj + (di - i) >= 0 && dj + (di - i) < 10) {
            if (arr[i][dj + (di - i)] > SL) SL = arr[i][dj + (di - i)];
        }
    }



    if (abs(TX) > abs(SL)) {
        HP1 = setHP(HP1 - static_cast<int>(HP1 * 0.1));
        HP2 = setHP(HP2 - static_cast<int>(HP2 * 0.1));
        EXP1 = setEXP(EXP1 - static_cast<int>(EXP1 * 0.12));
        EXP2 = setEXP(EXP2 - static_cast<int>(EXP2 * 0.12));
        return static_cast<double>(TX);
    } else {
        HP1 = setHP(HP1 * 2 - static_cast<int>(HP1 * 0.9));
        HP2 = setHP(HP2 * 2 - static_cast<int>(HP2 * 0.9));
        EXP1 = setEXP(EXP1 * 2 - static_cast<int>(EXP1 * 0.88));
        EXP2 = setEXP(EXP2 * 2 - static_cast<int>(EXP2 * 0.88));
        return static_cast<double>(SL);
    }
}
bool isINValidCharacter(char c) {
    if(c >= '0' && c <= '9') return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c == '@' || c == '#' || c == '%' || c =='$' || c == '!') return true;
    return false;
}

int checkPassword(const char *password, const char *email) {
    int length = strlen(password);
    
    if (length < 8) return -1; 
    if (length > 20) return -2; 

    bool hasSpecialChar = false;
    string emailPrefix = email; 
    emailPrefix = emailPrefix.substr(0, emailPrefix.find('@'));
    
    string passwordStr(password);

    for (char ch : passwordStr) {
        if (ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!')
            hasSpecialChar = true;
    }

    size_t substringIndex = passwordStr.find(emailPrefix);
    if (substringIndex != std::string::npos) {
        return static_cast<int>((substringIndex + 300) * -1);
    }

    for (size_t i = 0; i < length - 2; ++i) {
        if (passwordStr[i] == passwordStr[i + 1] && passwordStr[i + 1] == passwordStr[i + 2])
            return static_cast<int>((400 + 1) * -1); 
    }

    if (!hasSpecialChar) return -5; 

    for (size_t i = 0; i < length; ++i) {
        if (isINValidCharacter(password[i])) return static_cast<int>(i); 
    }

    return -10; 
}


int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxCount = 0, maxLength = 0, index = 0;
    bool processed[num_pwds] = {false};

    for (int i = 0; i < num_pwds; ++i) {
        if (processed[i] || arr_pwds[i] == nullptr || strlen(arr_pwds[i]) == 0) {
            continue; // Skip processed or empty passwords
        }

        int currentCount = 1; // Count for the current password

        for (int j = i + 1; j < num_pwds; ++j) {
            if (!processed[j] && arr_pwds[j] != nullptr && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++currentCount;
                processed[j] = true; // Mark the duplicate password as processed
            }
        }

        if (currentCount > maxCount || (currentCount == maxCount && strlen(arr_pwds[i]) > maxLength)) {
            maxCount = currentCount;
            maxLength = strlen(arr_pwds[i]);
            index = i;
        }
    }

    return index;
}