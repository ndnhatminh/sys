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

//Kiem tra HP
int checkHP(int HP) {
    if (HP > 666) {
        HP = 666;
    }
    else if (HP < 0) {
        HP = 0;
    }
    return HP;
}

//Kiem tra EXP
int checkEXP(int EXP) {
    if (EXP > 600) {
        EXP = 600;
    }
    else if (EXP < 0) {
        EXP = 0;
    }
    return EXP;
}

//Kiem tra M
int checkM(int M) {
    if (M > 3000) {
        M = 3000;
    }
    else if (M < 0) {
        M = 0;
    }
    return M;
}

int transfer2to1(int num) {
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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
 int D;
    if ((e1 <= 99) && (e1 >= 0)) {
        if ((e1 >= 0) && (e1 <= 3)) {
            switch (e1) {
                case 0: {
                    exp2 += 29;
                    break;
                }
                case 1: {
                    exp2 += 45;
                    break;
                }
                case 2: {
                    exp2 += 75;
                    break;
                }
                case 3: {
                    exp2 += 29 + 45 + 75;
                    break;
                }
            }
            D = e1*3 + exp1*7;
            if (D % 2 == 0) {
                exp1 = ceil(exp1 + (D/200.0));
            }
            else {
                exp1 = ceil(exp1 - (D/100.0));
            }
        }
        else if ((e1 >= 4) && (e1 <= 99)) {
            if ((e1 >= 4) && (e1 <= 19)) {
                exp2 += ceil((e1*1.0/4)+19);
            }
            else if ((e1 >= 20) && (e1 <= 49)) {
                exp2 += ceil((e1*1.0/9)+21);
            }
            else if ((e1 >= 50) && (e1 <= 65)) {
                exp2 += ceil((e1*1.0/16)+17);
            }
            else if ((e1 >= 66) && (e1 <= 79)) {
                exp2 += ceil((e1*1.0/4)+19);
                if (exp2 > 200) {
                    exp2 += ceil((e1*1.0/9)+21);
                }
            }
            else if ((e1 >= 80) && (e1 <= 99)) {
                exp2 += ceil((e1*1.0/4)+19) + ceil((e1*1.0/9)+21);
                if (exp2 > 400) {
                    exp2 += ceil((e1*1.0/16)+17);
                    exp2 += ceil((15*1.0/100)*exp2);
                }             
            }
            exp1 -= e1;
        }
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
        return exp1 + exp2;  
    }
    else {
        return -99;
    }
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 >= 0 && E2 <= 99) {

    double P1, P2, P3, P;

    //Con duong 01

    //Tim so chinh phuong S gan voi EXP1 nhat
    int sqrt_EXP1 = static_cast<int>(sqrt(EXP1));
    int lower_square = sqrt_EXP1*sqrt_EXP1;
    int upper_square = (sqrt_EXP1 + 1)*(sqrt_EXP1 + 1);
    int S = (abs(EXP1 - lower_square) < abs(EXP1 - upper_square)) ? lower_square : upper_square;

    if (EXP1 >= S) {
        P1 = 1.0;
    }
    else {
        P1 = ((EXP1/S) + 80)/123.0;
    }

    //Con duong 02
    int M_goc;
    M_goc = ceil(M1/2.0);
    if (E2 % 2 != 0) {
        while (true) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 + (30.0*HP1)/100.0);
                M1 = M1 - 150;
                M1 = checkM(M1);
                HP1 = checkHP(HP1);
                if (M1 < M_goc) {break;}
            }
            else {
                HP1 = ceil(HP1 + (10.0*HP1/100.0));
                M1 = M1 - 70;
                M1 = checkM(M1);
                HP1 = checkHP(HP1);
                if (M1 < M_goc) {break;}
            }       

            if (EXP1 < 400) {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1 + (13.0*EXP1)/100.0);
                M1 = checkM(M1);
                EXP1 = checkEXP(EXP1);
                if (M1 < M_goc) {break;}
            }
            else {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 + (13.0*EXP1)/100.0);
                M1 = checkM(M1);
                EXP1 = checkEXP(EXP1);
                if (M1 < M_goc) {break;}
            }

            if (EXP1 < 300) {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 - (10.0*EXP1)/100.0);
                M1 = checkM(M1);
                EXP1 = checkEXP(EXP1);
                if (M1 < M_goc) {break;}
            }
            else {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 - (10.0*EXP1)/100.0);
                M1 = checkM(M1);
                EXP1 = checkEXP(EXP1);
                if (M1 < M_goc) {break;}
            }
        }
    }
    else {
        while(true) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 + (30*HP1)/100.0);
                HP1 = checkHP(HP1);
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil(HP1 + (10*HP1/100.0));
                HP1 = checkHP(HP1);
                M1 = M1 - 70;
            }       
            M1 = checkM(M1);
            if (M1 == 0) break;

            if (EXP1 < 400) {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1 + (13*EXP1)/100.0);
                EXP1 = checkEXP(EXP1);
            }
            else {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 + (13*EXP1)/100.0);
                EXP1 = checkEXP(EXP1);
            }
            M1 = checkM(M1);
            if (M1 == 0) {break;}

            if (EXP1 < 300) {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 - (10*EXP1)/100.0);
                EXP1 = checkEXP(EXP1);
            }
            else {
                M1 = M1 -120;
                EXP1 = ceil(EXP1 - (10*EXP1)/100.0);
                EXP1 = checkEXP(EXP1);
            }
            M1 = checkM(M1);
            break;
        }
    }
    HP1 = ceil(HP1 - (17*HP1)/100.0);
    EXP1 = ceil(EXP1 + (17*EXP1)/100.0);
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);

    sqrt_EXP1 = static_cast<int>(sqrt(EXP1));
    lower_square = sqrt_EXP1*sqrt_EXP1;
    upper_square = (sqrt_EXP1 + 1)*(sqrt_EXP1 + 1);
    S = (abs(EXP1 - lower_square) < abs(EXP1 - upper_square)) ? lower_square : upper_square;
    if (EXP1 >= S) {
        P2 = 1.0;
    }
    else {
        P2 = ((EXP1/S) + 80)/123.0;
    }

    //Con duong 3

    double PM[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int E6;
    E6 = E2;
    while ( E6 >= 10) {
        E6 = ((E2/10) + E2%10)%10;
    }
    P3 = PM[E6]/100.0;

    //Ket thuc 3 con duong

    if ((P1 == 1.0) && (P2 == 1.0) && (P3 == 1.0)) {
        EXP1 = ceil(EXP1 - (25*EXP1)/100.0);
        EXP1 = checkEXP(EXP1);
    }
    else {
        P = (P1 + P2 + P3)/3.0;
        if (P < 0.5) {
            HP1 = ceil(HP1 - (15*HP1)/100.0);
            EXP1 = ceil(EXP1 + (15*EXP1)/100.0);
            EXP1 = checkEXP(EXP1);
            HP1 = checkHP(HP1);
        }
        else {
            HP1 = ceil(HP1 - (10*HP1)/100.0);
            EXP1 = ceil(EXP1 + (20*EXP1)/100.0);
            HP1 = checkHP(HP1);
            EXP1 = checkEXP(EXP1);
        }
    }
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkM(M1);

    return HP1 + EXP1 + M1;
    }

    else {
    return -99;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     if (E3 >= 0 && E3 <= 99) {
        int i, j;
        int dem_i, dem_j, max;
        dem_i = 0;
        dem_j = 0;
        //Tao mang cho taxi
        int taxi[10][10] = {};
        //Gan gia tri cho mang taxi
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++){
                taxi[i][j] = ((E3*j)+(i*2))*(i-j);
                if (taxi[i][j] > (E3*2)) {
                    dem_i = dem_i + 1;
                    }
                if (taxi[i][j] < ((-1)*E3)) {
                    dem_j = dem_j + 1;
                    }
            }
        }
        dem_i = transfer2to1(dem_i);
        dem_j = transfer2to1(dem_j);
        max = taxi[dem_i][dem_j];
        i = dem_i;
        j = dem_j;
        //Xet duong cheo phai xuong
        for (int k = i; k < 10; ++k) {
            if (taxi[k][j + (k - i)] > max) {max = taxi[k][j + (k - i)];}
        }
        //Xet cheo phai len 
        for (int k = i; k >= 0; --k) {
            if (taxi[k][j - (k - i)] > max) {max = taxi[k][j - (k - i)];}
        }
        //Xet duong cheo trai xuong
        for (int k = i; k < 10; ++k) {
            if (taxi[k][j - (k - i)]) {max = taxi[k][j - (k - i)];}
        }
        for (int k = i; k >= 0; --k) {
            if (taxi[k][j + (k - i)] > max) {max = taxi[k][j + (k - i)];}
        }
        int kq;
        if (abs(taxi[dem_i][dem_j]) > abs(max)) {
            EXP1 = ceil(EXP1 - (12/100.0)*EXP1);
            EXP1 = checkEXP(EXP1);
            HP1 = ceil(HP1 - (10/100.0)*HP1);
            HP1 = checkHP(HP1);
            EXP2 = ceil(EXP2 - (12/100.0)*EXP2);
            EXP2 = checkEXP(EXP2);
            HP2 = ceil(HP2 - (10/100.0)*HP2);
            HP2 = checkHP(HP2);
            kq = taxi[dem_i][dem_j];
        }
        else {
            EXP1 = ceil(EXP1 + (12/100.0)*EXP1);
            EXP1 = checkEXP(EXP1);
            HP1 = ceil(HP1 + (10/100.0)*HP1);
            HP1 = checkHP(HP1);
            EXP2 = ceil(EXP2 + (12/100.0)*EXP2);
            EXP2 = checkEXP(EXP2);
            HP2 = ceil(HP2 + (10/100.0)*HP2);
            HP2 = checkHP(HP2);
            kq = max;
        }
        return kq;
    }
    else {
        return -99;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string password(s);
    string emailaddress(email);
    if (password.length() < 8) {
        return -1;
    } else if (password.length() > 20) {
        return -2;
    }
    size_t index = emailaddress.find('@');
    if (index == string::npos) {
        return -3;
    }
    string prefix = emailaddress.substr(0, index);
    size_t pf_index = password.find(prefix);
    if (pf_index != string::npos) {
        return -(300 + pf_index);
    }
    for (size_t i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
            return -(400 + i);
        }
    }
    bool specialchar = false;
    for (char c : password) {
        if (c == '@' || c == '#' || c == '$' || c == '%' || c == '!') {
            specialchar = true;
            break;
        }
    }
    if (!specialchar) {
        return -5;
    }
    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (!(isalnum(c) || c == '@' || c == '#' || c == '$' || c == '%' || c == '!')) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    const char* max_count_pwd = NULL;
    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count;
            }
        }
        if (count > max_count || (count == max_count && strlen(arr_pwds[i]) > max_length)) {
            max_count = count;
            max_length = strlen(arr_pwds[i]);
            max_count_pwd = arr_pwds[i];
        }
    }
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], max_count_pwd) == 0) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////