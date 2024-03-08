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
int firstMeet(int & exp1, int & exp2, int e1) {
    int D;
    // TH1
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2 = exp2 + 29;
            D = 3*e1 + 7*exp1;
        }
        else if (e1 == 1) {
            exp2 = exp2 + 45;
            D = 3*e1 + 7*exp1;
        }
        else if (e1 == 2) {
            exp2 = exp2 + 75;
            D = 3*e1 + 7*exp1;
        }
        else if (e1 == 3) {
            exp2 = exp2 + 29 + 45 + 75;
            D = 3*e1 + 7*exp1;
        }
        if (D%2 == 0) {
            exp1 = exp1 + int(ceil(double(D/200.0)));
        }
        else 
            exp1 = int(ceil(double(exp1 - D/100.0)));
    }
    // TH2
    if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) {
            exp2 = exp2 + int(ceil(double(e1/4.0 + 19)));
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = exp2 + int(ceil(double(e1/9.0 + 21)));
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = exp2 + int(ceil(double(e1/16.0 + 17)));
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = exp2 + int(ceil(double(e1/4.0 + 19)));
            if (exp2 > 200) {
               exp2 = exp2 + int(ceil(double(e1/9.0 + 21)));
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = exp2 + int(ceil(double(e1/4.0 + 19)));
            exp2 = exp2 + int(ceil(double(e1/9.0 + 21)));
            if (exp2 > 400) {
                exp2 = exp2 + int(ceil(double(e1/16.0 + 17)));
                exp2 = exp2 * 1.15;
            }
        }
        exp1 = exp1 - e1;
    }
    if (exp1 > 600) {
        exp1 = 600;
    }
    if (exp2 > 600) {
        exp2 = 600;
    }
    if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp2 <0) {
        exp2 = 0;
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int a , S , m , i;
    double P1,P2,P3,x;
    i = M1;
    a = round(sqrt(EXP1));
    S = a*a;
    m = 0.5 * M1;
    // Street 1
    if (EXP1 < S) {
        P1 = (EXP1/double(S) + 80)/123; 
    }
    else {
        P1 = 1;
    }
    // Street 2
    if (E2 % 2 == 0) {
        if ((i-M1) < m) {
            if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3);
            M1 = M1 - 150;
            }
            else {
            HP1 = ceil(HP1 *1.1);
            M1 = M1 - 70;
            }
        }
        if ((i-M1) < m) {
            if (EXP1 < 400) {
            M1 = M1 - 200;
            }
            else {
            M1 = M1 - 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
        }
        if ((i-M1) < m) {
            if (EXP1 < 300) {
                M1 = M1 - 100;
                }
            else {
            M1 = M1 - 120;  
            }
        EXP1 = ceil(EXP1 * 0.9);
        }
    }
    else {
        for (int x = 0; (i-M1) < m ; x++) {
            if ((i-M1) < m) {
                if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 = M1 - 150;
                }
                else {
                HP1 = ceil(HP1 *1.1);
                M1 = M1 - 70;
                }
            }
            if ((i-M1) < m) {
                if (EXP1 < 400) {
                M1 = M1 - 200;
                }
                else {
                M1 = M1 - 120;
                }
                EXP1 = ceil(EXP1 * 1.13);
            }
            if ((i-M1) < m) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    }
                else {
                M1 = M1 - 120;  
                }
            EXP1 = ceil(EXP1 * 0.9);
            }
        }
        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    }
    a = round(sqrt (EXP1));
    S = a*a;
    if (EXP1 >= S) {
        P2 = 1;
    }
    else { 
        P2 = (EXP1/double(S)+80)/123;
    }
    // Street 3
    double arr[10] = {0.32,0.47,0.28,0.79,1,0.50,0.22,0.83,0.64,0.11};
    if (E2 >= 0 && E2 <= 9) {
        P3 = arr[E2];
    }
    else if (E2 > 9) {
        a = E2 % 10;
        m = (E2 / 10);
        S = a + m;
        i = S%10;
        P3 = arr[i];
    } 
    // End
    if (P1 + P2 + P3 == 3) {
        EXP1 = ceil(EXP1 * 0.75);
    }
    else {
        x = (P1 + P2 + P3)/3;
        if (x < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 > 660) {
        HP1 = 660;
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int arr[10][10];
    int i ,j ,a=0 ,b=0 ,x ,y ,t ,max ,Row ,Column;
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            arr[i][j] = (E3*j+i*2)*(i-j);
        }
    }
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            if (arr[i][j] > (2*E3) && arr[i][j] > 0) {
                a = a + 1;
            }
            if (arr[i][j] < (-E3) && arr[i][j] < 0) {
                b = b + 1;
            }
        }
    }
    if (a>0 && a<10){
        i = a;
    }
    else {
        x = a/10;
        y = a%10;
        i = x + y;
        if (i>9) {
            x = i/10;
            y = i%10;
            i = x + y;
        }
    }
    if (b>0 && b<10){
        j = b;
    }
    else {
        x = b/10;
        y = b%10;
        j = x + y;
        if (j>9) {
            x = j/10;
            y = j%10;
            j = x + y;
        }
    }
    t = abs(arr[i][j]);
    max = arr[i][j];
    // chéo phụ đi lên
    for (Row = i , Column = j ; Row >= 0 && Column < 10 && Row < 10 && Column >= 0 ; Row = Row - 1 , Column++) {
        if (max < arr[Row][Column]) {
            max = arr[Row][Column];
        }
    }
    // chéo phụ đi xuống
    for (Row = i , Column = j ; Row < 10 && Column >= 0 && Row >= 0 && Column < 10 ; Row++ , Column = Column -1) {
        if (max < arr[Row][Column]) {
            max = arr[Row][Column];
        }
    }
    // chéo chính đi lên
    for (Row = i , Column = j ; Row >= 0 && Column < 10 && Column >= 0 && Row < 10 ; Row = Row - 1 , Column = Column - 1) {
        if (max < arr[Row][Column]) {
            max = arr[Row][Column];
        }
    }
    // chéo chính đi xuống
    for (Row = i , Column = j ; Row >= 0 && Column < 10 && Column >= 0 && Row < 10 ; Row++ , Column++) {
        if (max < arr[Row][Column]) {
            max = arr[Row][Column];
        }
    }
    if (t > max) {
        EXP1 = EXP1 * 0.88;
        EXP2 = EXP2 * 0.88;
        HP1 = HP1 * 0.9;
        HP2 = HP2 * 0.9;
    }
    else {
        EXP1 = EXP1 * 1.12;
        EXP2 = EXP2 * 1.12;
        HP1 = HP1 * 1.1;
        HP2 = HP2 * 1.1;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    if (HP1 > 660) {
        HP1 = 660;
    }
    if (HP2 > 660) {
        HP2 = 660;
    }
    if (EXP1 < 0) {
        EXP1 = 0;
    }
    if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP2 < 0) {
        HP2 = 0;
    }
    return arr[i][j];
}

// Task 4
int checkPassword(const char * s, const char * email) {
    std::string str(email);
    std::string str1(s);
    str.erase(str.find("@"),100);
    std::string se = str;
    if (str1.length() < 8) {
        return -1;
    }
    else if (str1.length() > 20) {
        return -2;
    }
    else if (str1.find(se) > 0 && str1.find(se) < 101) {
        return -(300 + str1.find(se));
    }
    else if (str1.find("@") > 0 && str1.find("@") < 101 || str1.find("%") > 0 && str1.find("%") < 101 || str1.find("$") > 0 && str1.find("$") < 101 || str1.find("!") > 0 && str1.find("!") < 101 || str1.find("#") > 0 && str1.find("#") < 101) {
        return -5;
    }
    else {
        for (int i = 0 ; i < str1.length() ; i++) {
            if (str1[i] = str1[i+1]) {
                return i;
            }
        }
    }
    return -1;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int fre[num_pwds], maxlen, maxfre, t, max[num_pwds];
    const char* corpwd[num_pwds];
    const char* corpwds;
    maxlen = strlen(arr_pwds[0]);
    maxfre = 1;
    // Khởi trị max[]
    for (int i = 0 ; i < num_pwds ; i++) {
        max[i] = 0;
    }
    // Khởi trị corpwd[]
    for (int i = 0 ; i < num_pwds ; i++) {
        corpwd[i] = "a";
    }
    // Khởi trị fre[]
    for (int i = 0 ; i < num_pwds ; i++) {
        fre[i] = 0;
    }
    // Tìm fre[i]
    for (int i = 0 ; i < num_pwds ; i++) {
        for (int j = 0 ; j < num_pwds ; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                fre[i]++;
            }
        }
    }
    // Tìm maxfre
    for (int i = 0 ; i < num_pwds ; i++) {
        if (maxfre < fre[i]) {
            maxfre = fre[i];
        }
    }
    // Tìm corpwd[i]
    for (int i = 0 ; i < num_pwds ; i++) {
        if (fre[i] == maxfre) {
            corpwd[i] = arr_pwds[i];
        }
    }
    // Tìm max[i]
    for (int i = 0 ; i < num_pwds ; i++) {
        if (corpwd[i] != "a") {
              max[i] =   strlen(arr_pwds[i]);
        }  
    }
    // Tìm maxlen
    for (int i = 0 ; i < num_pwds ; i++) {
        if (maxlen < max[i]) {
            maxlen = max[i];
        }   
    }
    // Tìm mật khẩu đúng
    for (int i = 0 ; i < num_pwds ; i++) {
        if (strlen(corpwd[i]) == maxlen) {
            corpwds = corpwd[i];
        }
    }
    // Giá trị trả về
    for (int i = 0 ; i < num_pwds ; i++){
        if (strcmp(corpwds,arr_pwds[i]) == 0) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////