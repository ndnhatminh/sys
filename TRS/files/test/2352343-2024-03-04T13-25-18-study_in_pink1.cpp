#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Function Task 1
int check_E(int e1){
if (e1 < 0 or e1 > 99){
    return -99;
}
return e1;
}
// Điều kiện cho exp
int check_exp(int exp){
    if (exp < 0 or exp > 600){
        if (exp < 0){
            exp = 0;
        }
        else{
            exp = 600;
        }
    }
    return exp;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // Check E1, exp1, exp2
    e1 = check_E(e1);
    if (e1 == -99){
        return -99;
    }

    exp1 = check_exp(exp1);
    exp2 = check_exp(exp2);
    int D;


// Case 1
    if (e1 == 0){
        exp2 += 29;
        D = e1 * 3 + exp1 * 7;
        exp2 = check_exp(exp2);
    }

    else if (e1 == 1){
        exp2 += 45;
        exp2 = check_exp(exp2);
        D = e1 * 3 + exp1 * 7;
    }

    else if (e1 == 2){
        exp2 += 75;
        exp2 = check_exp(exp2);
        D = e1 * 3 + exp1 * 7;
    }

    else if (e1 == 3){
        exp2 = exp2 + 29 + 45 + 75;
        D = e1 * 3 + exp1 * 7;
        exp2 = check_exp(exp2);
    }

// D is odd or even
    if (e1 >= 0 and e1 <= 3){
        if (D % 2 == 0){
        exp1 = ceil(exp1 + static_cast<double>(D)/200);
    }
    else{
        exp1 = ceil(exp1 - static_cast<double>(D)/100);
    }
    }

    exp1 = check_exp(exp1);
    exp2 = check_exp(exp2);

// Case 2
    if (e1 >= 4 and e1 <= 99){
        if (e1 >= 4 and e1 <= 19){
        exp2 = ceil(exp2 + (static_cast<double>(e1)/4 + 19));
        exp2 = check_exp(exp2);
    }
    else if (e1 >= 20 and e1 <= 49){
        exp2 = ceil(exp2 + (static_cast<double>(e1)/9 + 21));
        exp2 = check_exp(exp2);
    }
    else if (e1 >= 50 and e1 <= 65){
        exp2 = ceil(exp2 +(static_cast<double>(e1)/16 + 17));
        exp2 = check_exp(exp2);
    }
    else if (e1 >= 66 and e1 <= 79){
        exp2 = ceil(exp2 + (static_cast<double>(e1)/4 + 19));
        if (exp2 > 200){
            exp2 = ceil(exp2 +(static_cast<double>(e1)/9 + 21));
        }
        exp2 = check_exp(exp2);
    }
    else if (e1 >= 80 and e1 <= 99){
        exp2 = ceil(exp2 + (static_cast<double>(e1)/4 + 19));
        exp2 = check_exp(exp2);
        exp2 = ceil(exp2 + (static_cast<double>(e1)/9 + 21));
        exp2 = check_exp(exp2);
        if (exp2 > 400){
            exp2 = ceil(exp2 + (static_cast<double>(e1)/16 + 17));
            exp2 = check_exp(exp2);
            exp2 = ceil(exp2 + 15.0/100 * exp2);
            exp2 = check_exp(exp2);

            // 15.0 để chuyển về float
        }
    }
    exp1 -= e1;
    exp1 = check_exp(exp1);
    }

    return exp1 + exp2;
}


// Function task 2
int check_M (int m){
    if (m < 0){
        m = 0;
    }
    else if (m>3000){
        m = 3000;
    }
    return m;
}

int check_HP (int hp){
    if (hp < 0){
        hp = 0;
    }
    else if (hp>666){
        hp = 666;
    }
    return hp;
}


int nearestPerfectSquare(int n) {
    int root = round(sqrt(n));
    return root * root;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    E2 = check_E(E2);
    if (E2 == -99){
        return -99;
    }
    HP1 = check_HP(HP1);
    EXP1 = check_exp(EXP1);
    M1 = check_M(M1);
    
    int Money_spent = 0;

    double Half_M1 = M1 / 2.0;

    //Road 01
    double P1;
    int S = nearestPerfectSquare(EXP1);
    if (EXP1 >= S){
        P1 = 1.0;
    }
    else{
        P1 = ((static_cast<double>(EXP1) / S) + 80 ) / 123.0;
    // Chỉ cần 1 trong 2 là double thì kết quả ra double
    }

    //Road 02
    double P2;
    // E2 lẻ, lặp
    if (E2 % 2 != 0){
        while (Money_spent <= Half_M1) {
        if (HP1 < 200){
            HP1 = ceil(HP1 + static_cast<double>(HP1)*30/100);
            M1 -= 150;
            Money_spent += 150;
        }
        else if (HP1 >= 200){
            HP1 = ceil(HP1 + static_cast<double>(HP1)*10/100);
            M1 -= 70;
            Money_spent += 70;
        }


        //Check M1
        HP1 = check_HP(HP1);
        M1 = check_M(M1);

        // Check if Money_spent has exceeded Half_M1
        if (Money_spent > Half_M1) {
            break;
        }

        if (EXP1 < 400){
            M1 -= 200;
            Money_spent += 200;
            EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*13/100);
            EXP1 = check_exp(EXP1);
            M1 = check_M(M1);
        }

        else if (EXP1 >= 400){
            M1 -= 120;
            Money_spent += 120;
            EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*13/100);
            EXP1 = check_exp(EXP1);
            M1 = check_M(M1);
        }



        // Check if Money_spent has exceeded Half_M1
        if (Money_spent > Half_M1) {
            break;
        }

        if (EXP1 < 300){
            M1 -= 100;
            Money_spent += 100;
            EXP1 = ceil(EXP1 - static_cast<double>(EXP1)*10/100);
            EXP1 = check_exp(EXP1);
            M1 = check_M(M1);
        }
        else if (EXP1 >= 300){
            M1 -= 120;
            Money_spent += 120;
            EXP1 = ceil(EXP1 - static_cast<double>(EXP1)*10/100);
            EXP1 = check_exp(EXP1);
            M1 = check_M(M1);
        }

        }
    }
        
    //E2 chẵn
    else{
        if (M1 != 0){
            if (HP1 < 200){
        HP1 = ceil(HP1 + static_cast<double>(HP1)*30/100);
        M1 -= 150;
        Money_spent += 150;
    }
        else if (HP1 >= 200){
            HP1 = ceil(HP1 + static_cast<double>(HP1)*10/100);
            M1 -= 70;
            Money_spent += 70;
    }

        //Check M1
        M1 = check_M(M1);
        EXP1 = check_exp(EXP1);
        HP1 = check_HP(HP1);
        }
        
        if (M1 != 0){
            if (EXP1 < 400){
            M1 -= 200;
            Money_spent += 200;
            EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*13/100);
        }

        else if (EXP1 >= 400){
            M1 -= 120;
            Money_spent += 120;
            EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*13/100);
        }

        //Check M1
        M1 = check_M(M1);
        EXP1 = check_exp(EXP1);
        
        }

        if (M1 != 0){
            if (EXP1 < 300){
                M1 -= 100;
                Money_spent += 100;
                EXP1 = ceil(EXP1 - static_cast<double>(EXP1)*10/100);
            }
            else if (EXP1 >= 300){
                M1 -= 120;
                Money_spent += 120;
                EXP1 = ceil(EXP1 - static_cast<double>(EXP1)*10/100);
            }

        //Check M1, EXP1:
        EXP1 = check_exp(EXP1);
        M1 = check_M(M1);
        }
    }

    HP1 = ceil(HP1 - static_cast<double>(HP1)*17/100);
    EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*17/100);

    HP1 = check_HP(HP1);
    EXP1 = check_exp(EXP1);
    M1 = check_M(M1);

    S = nearestPerfectSquare(EXP1);
    if (EXP1 >= S){
        P2 = 100.0/100;
    }
    else{
        P2 = ((static_cast<double>(EXP1) / S) + 80 ) / 123;
    }

    // Road 3
    const double P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    double P_average;
    if (E2 < 10){
        i = E2;
    }
    else{
        int hang_chuc = E2 / 10; 
        int hang_donvi = E2 % 10; 
        int tong = hang_chuc + hang_donvi;
        i = tong % 10;
    }
    double P3 = P[i] / 100 ;

    if (P1 == 1.0 and P2 == 1.0 and P3 == 1.0){
        EXP1 = ceil(EXP1 - static_cast<double>(EXP1)*25/100);
        EXP1 = check_exp(EXP1);
    }
    else{
        P_average = (P1 + P2 + P3) / 3.0;
    

        if (P_average < 0.5){
            HP1 = ceil(HP1 - static_cast<double>(HP1)*15/100);
            EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*15/100);
        }

        else{
            HP1 = ceil(HP1 - static_cast<double>(HP1)*10/100);
            EXP1 = ceil(EXP1 + static_cast<double>(EXP1)*20/100);
        }

        HP1 = check_HP(HP1);
        EXP1 = check_exp(EXP1);
    }
    return HP1 + EXP1 + M1;

}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    E3 = check_E(E3);
    if (E3 == -99){
        return -99;
    }
    HP1 = check_HP(HP1);
    HP2 = check_HP(HP2);
    EXP1 = check_exp(EXP1);
    EXP2 = check_exp(EXP2);

    int map[10][10];
    int point[10][10];


    //Tạo ma trận taxi
    for (int i = 0; i < 10; i++ ){
        for (int j = 0; j < 10; j++){
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    // Tạo ma trận point
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int max_val = map[i][j];
            
            // Đường chéo phải phía dưới
            for (int x = i, y = j; x < 10 and y < 10; ++x, ++y) {
                max_val = max(max_val, map[x][y]);
            }
            
            // Đường chéo trái phía dưới
            for (int x = i, y = j; x < 10 and y >= 0; ++x, --y) {
                max_val = max(max_val, map[x][y]);
            }

            // Đường chéo phải phía trên
            for (int x = i, y = j; x >= 0 and y >= 0; --x, --y) {
                max_val = max(max_val, map[x][y]);
            }

            // Đường chéo trái phía trên
            for (int x = i, y = j; x >= 0 and y < 10; --x, ++y) {
                max_val = max(max_val, map[x][y]);
            }
            
            // Trị tuyệt đối
            if (max_val < 0) {
                max_val = abs(max_val);
            }

            point[i][j] = max_val;
        }
    }

    
    // Taxi gặp Sherlock & Watson
    int i_point = 0, j_point = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j){
            if ( map[i][j] > E3 * 2 ){
                i_point += 1;
            }

            else if ( map[i][j] < -E3 ){
                j_point += 1;
            }

        }
    }
        
    // Nếu i, j là số 2 chữ số --> Giảm còn 1 chữ số
    while (i_point >= 10) {
        i_point = i_point / 10 + i_point % 10;
    }
    while (j_point >= 10) {
        j_point = j_point / 10 + j_point % 10;
    }


    int point_return;

    if (abs(map[i_point][j_point]) > point[i_point][j_point]){
        EXP1 = ceil(EXP1 -  static_cast<double>(EXP1)*12/100);
        EXP2 = ceil(EXP2 -  static_cast<double>(EXP2)*12/100);
        HP1 = ceil(HP1 -  static_cast<double>(HP1)*10/100);
        HP2 = ceil(HP2 -  static_cast<double>(HP2)*10/100);
        point_return = map[i_point][j_point];
    }
    else{
        EXP1 = ceil(EXP1 +  static_cast<double>(EXP1)*12/100);
        EXP2 = ceil(EXP2 +  static_cast<double>(EXP2)*12/100);
        HP1 = ceil(HP1 +  static_cast<double>(HP1)*10/100);
        HP2 = ceil(HP2 +  static_cast<double>(HP2)*10/100);
        point_return = point[i_point][j_point];
    }

    HP1 = check_HP(HP1);
    HP2 = check_HP(HP2);
    EXP1 = check_exp(EXP1);
    EXP2 = check_exp(EXP2);
    
    return point_return;
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string password(s);
    string emailStr(email);
    string se = emailStr.substr(0, emailStr.find('@'));
    string specialChars = "@#%$!";

    // Check length
    if (password.length() < 8) 
    return -1;
    if (password.length() > 20) 
    return -2;

    // Check for se
    if (password.find(se) != string::npos) 
    return -(300 + password.find(se));
    // string::npos có nghĩa như null, khi không tìm được sẽ trả về "npos". Ở TH này: s chứa se.

    // Check for more than 2 consecutive and identical characters
    for (int i = 0; i < password.length() - 2; i++) {
        if (password[i] == password[i+1] and password[i+1] == password[i+2]) {
            return -(400 + i);
        }
    }

    // Check for special characters
    if (password.find_first_of(specialChars) == string::npos) return -5;

    // Check for invalid characters
    for (char c : password) {
        if (!isalnum(c) and specialChars.find(c) == string::npos) {
            return password.find(c);
        }
    }

    // If all checks pass, return -10
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_freq = 0;
    int max_len = 0;
    int max_index = -1;

    for (int i = 0; i < num_pwds; i++) {
        int freq = 0;
        int len = 0;
        for (const char* c = arr_pwds[i]; *c != '\0'; ++c) {
            ++len;
        }

        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++freq;
            }
        }

        if (freq > max_freq or (freq == max_freq and len > max_len)) {
            max_freq = freq;
            max_len = len;
            max_index = i;
        }
    }

    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////