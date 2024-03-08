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

void FIXEXP(int & exp1, int & exp2) { //Ép giá trị KN
    if (exp1 > 600) {
        exp1 = 600;
    }
    if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp2 < 0) {
        exp2 = 0;
    }
    if (exp2 > 600) {
        exp2 = 600;
    }
}

void FIXEXP1(int & EXP1) {
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (EXP1 < 0) {
        EXP1 = 0;
    }
}

void FIXEXP2(int & EXP2) {
    if (EXP2 < 0) {
        EXP2 = 0;
    }
    if (EXP2 > 600) {
        EXP2 = 600;
    }
}

void FIXHP1(int & HP1) {
    if (HP1 > 666) {
        HP1 = 666;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
}

void FIXHP(int & HP1, int & HP2) { //Ep gt HP
    if (HP1 > 666) {
        HP1 = 666;
    }
    if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP2 < 0) {
        HP2 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    }
}

void FIXMONEY(int & M1) { //Ep GT tien
    if (M1 > 3000) {
        M1 = 3000;
    }
    if (M1 < 0) {
        M1 = 0;
    }
}

bool checkchinhphong(int & n) {
    int sqrtn = sqrt(n);
    return sqrtn * sqrtn == n;
}

int findchinhphuong(int & EXP1) {
    int lowcheck = EXP1 - 1;
    int highcheck = EXP1 + 1;
    while (true) {
        if (checkchinhphong(lowcheck)) {
            return lowcheck;
        }
        if (checkchinhphong(highcheck)) {
            return highcheck;
        }
        lowcheck--;
        highcheck++;
    }
}

int findhighmaxleftdia(int n[10][10], int i, int j) {
        int maxVal = n[i][j];
        while ((i >= 0 && i < 10) && (j >= 0 && j < 10)) {
            maxVal = max(maxVal, n[i][j]);
            i--;
            j--;
        }
        return maxVal;
    }
int findlowmaxleftdia(int n[10][10], int i, int j) {
        int maxVal = n[i][j];
        while ((i >= 0 && i < 10) && (j >= 0 && j < 10)) {
            maxVal = max(maxVal, n[i][j]);
            i++;
            j--;
        }
        return maxVal;
    }
    int findhighmaxrightdia(int n[10][10], int i, int j) {
        int maxVal = n[i][j];
        while ((i >= 0 && i < 10) && (j >= 0 && j < 10)) {
            maxVal = max(maxVal, n[i][j]);
            i--;
            j++;
        }
        return maxVal;
    }
    int findlowmaxrightdia(int n[10][10], int i, int j) {
        int maxVal = n[i][j];
        while ((i >= 0 && i < 10) && (j >= 0 && j < 10)) {
            maxVal = max(maxVal, n[i][j]);
            i++;
            j++;
        }
        return maxVal;
    }
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 >= 100) {
        return -99;
    }
    if (e1 >= 0 && e1 < 100) {
    FIXEXP(exp1, exp2);
    int D = e1 + exp1 * 7;
    if (e1 == 0) {
        exp2 += 29;
        if (D % 2 == 0)
        exp1 += ceil((double)D/200);
        else exp1 -= floor((double)D/100);
        FIXEXP(exp1, exp2);
    }
    if (e1 == 1) {
        exp2 += 45;
        if (D % 2 == 0)
        exp1 += ceil((double)D/200);
        else exp1 -= floor((double)D/100);
        FIXEXP(exp1, exp2);
    }
    if (e1 == 2) {
        exp2 += 75;
        if (D % 2 == 0)
        exp1 += ceil((double)D/200);
        else exp1 -= floor((double)D/100);
        FIXEXP(exp1, exp2);
    }

    if (e1 == 3) {
        exp2 += 149;
        if (D % 2 == 0)
        exp1 += ceil((double)D/200);
        else exp1 -= floor((double)D/100);
        FIXEXP(exp1, exp2);
    }
    if (e1 >= 4 && e1 <= 19) {
        exp2 += ceil((double)e1/4.0 + 19); // Ép kiểu làm tròn
        exp1 -= e1;
        FIXEXP(exp1, exp2);
    }
    if (e1 >= 20 && e1 <= 49) {
        exp2 += ceil((double)e1/9 + 21);
        exp1 -= e1;
        FIXEXP(exp1, exp2);
    }
    if (e1 >= 50 && e1 <= 65) {
        exp2 += ceil((double)e1/16 + 17);
        exp1 -= e1;
        FIXEXP(exp1, exp2);
    }
    if (e1 >= 66 && e1 <= 79) {
        exp2 += ceil((double)e1/4 + 19);
        if (exp2 > 200) {
            exp2 += ceil((double)e1/9 + 21);
            exp1 -= e1;
            FIXEXP(exp1, exp2);
        }
        else {
        exp1 -= e1;
        FIXEXP(exp1, exp2);
        }
    }
    if (e1 >= 80 && e1 <= 99) {
        exp2 += ceil((double)e1/4 + 19);
        exp2 += ceil((double)e1/9 + 21);
        if (exp2 > 400) {
            exp2 += ceil((double)e1/16 + 17);
            exp2 += ceil((double)(exp2 * 0.15));
            exp1 -= e1;
            FIXEXP(exp1, exp2);
        }
        else {
        exp1 -= e1;
        FIXEXP(exp1, exp2);
        }
    }
    FIXEXP(exp1, exp2);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
 if (E2 < 0 || E2 >= 100) {
        return -99;
    }
    if (E2 >= 0 && E2 < 100) {
    FIXHP1(HP1);
    FIXEXP1(EXP1);
    FIXMONEY(M1);
    int S = 0;
    int P = 0;
    int Q = 0;
    float P1 = 0;
    float P2 = 0;
    float P3 = 0;
    int originalmoney = M1;
    int halfmoney = originalmoney / 2;
    int moneyspent = 0;
    if (checkchinhphong(EXP1)) {
        S = EXP1;
    }
    else {
        S = findchinhphuong(EXP1);
    }
    if (EXP1 >= S) {
        P1 = 100;
    }
    if (EXP1 < S) {
        float pcheck1 = (float)(((float)EXP1 / S + 80) / 123);
        P1 = pcheck1 * 100;
    }
    if (E2 % 2 != 0) {
    while (moneyspent <= halfmoney && M1 != 0) {
    FIXEXP1(EXP1);
    FIXMONEY(M1);
    FIXHP1(HP1);
    if (HP1 < 200) {
        HP1 += ceil((double)(HP1 * 0.3));
        M1 -= 150;
        moneyspent += 150;
        FIXHP1(HP1);
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    else if(HP1 >= 200) {
        HP1 += ceil((double)(HP1 * 0.1));
        M1 -= 70;
        FIXHP1(HP1);
        FIXEXP1(EXP1);
        FIXMONEY(M1);
        moneyspent += 70;
    }
    if (moneyspent > halfmoney) {
        break;
    }
    if(EXP1 < 400) {
        M1 -= 200;
        EXP1 += ceil((double)(EXP1 * 0.13));
        moneyspent += 200;
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    else if(EXP1 >= 400) {
        M1 -= 120;
        EXP1 += ceil((double)(EXP1 * 0.13));
        moneyspent += 120;
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    if (moneyspent > halfmoney) {
        break;
    }
    if (EXP1 >= 300) {
        M1 -= 120;
        EXP1 -= floor((double)(EXP1 * 0.1));
        moneyspent += 120;
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    else if (EXP1 < 300 && M1 > 0) {
        M1 -= 100;
        EXP1 -= floor((double)(EXP1 * 0.1));
        moneyspent += 100;
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
     if (moneyspent > halfmoney) {
        break;
    }
}
    HP1 -= floor((double)(HP1 * 0.17));
    EXP1 += ceil((double)(EXP1 * 0.17));
    FIXEXP1(EXP1);
    FIXMONEY(M1);
    if (checkchinhphong(EXP1)) {
        P = EXP1;
    }
    else {
        P = findchinhphuong(EXP1);
    }
    if (EXP1 >= P) {
        P2 = 100;
    }
    if (EXP1 < P) {
        float pcheckp2 = (float)(((float)EXP1 / S + 80) / 123);
        P2 = pcheckp2 * 100;
    }
}
    else if(E2 % 2 == 0) {
        FIXHP1(HP1);
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    if (HP1 < 200 && M1 > 0) { //Mua đồ
        HP1 += ceil((double)(HP1 * 0.3));
        M1 -= 150;
        FIXHP1(HP1);
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    else if(HP1 >= 200 && M1 > 0) { //Mua đồ
        HP1 += ceil((double)(HP1 * 0.1));
        M1 -= 70;
        FIXHP1(HP1);
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    if(EXP1 < 400 && M1 > 0) { //Di chuyen
        M1 -= 200;
        EXP1 += ceil((double)(EXP1 * 0.13));
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    else if(EXP1 >= 400 && M1 > 0) { //Di chuyen
        M1 -= 120;
        EXP1 += ceil((double)(EXP1 * 0.13));
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    if (EXP1 >= 300 && M1 > 0) { //Nguoi an xin
        M1 -= 120;
        EXP1 -= floor((double)(EXP1 * 0.1));
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    else if (EXP1 < 300 && M1 > 0) { //Nguoi an xin
        M1 -= 100;
        EXP1 -= floor((double)(EXP1 * 0.1));
        FIXEXP1(EXP1);
        FIXMONEY(M1);
    }
    HP1 -= floor((double)(HP1 * 0.17));
    EXP1 += ceil((double)(EXP1 * 0.17));
    FIXEXP1(EXP1);
    FIXMONEY(M1);
    if (checkchinhphong(EXP1)) {
        P = EXP1;
    }
    else {
        P = findchinhphuong(EXP1);
    }
    if (EXP1 >= P) {
        P2 = 100;
    }
    else if (EXP1 < P) {
        float pcheckp2 = (float)(((float)EXP1 / S + 80) / 123);
        P2 = pcheckp2 * 100;
    }
    }
    int H[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 < 10) {
        Q = E2;
        P3 = H[Q];
    }
    else if (E2 >= 10) {
        int sum = (E2 / 10) + (E2 % 10);
        Q = sum % 10;
        P3 = H[Q];
    }
    float avgP =((double)((P1 + P2 + P3) / 3));
    if (avgP == 100) {
        EXP1 -= floor((double)EXP1 * 0.25);
        FIXEXP1(EXP1);
        FIXHP1(HP1);
    }
    if (avgP < 50) {
        HP1 -= floor((double)HP1 * 0.15);
        EXP1 += ceil((double)EXP1 * 0.15);
        FIXHP1(HP1);
        FIXEXP1(EXP1);
    }
    if (avgP >= 50 && avgP < 100) {
        HP1 -= floor((double)HP1 * 0.1);
        EXP1 += ceil((double)EXP1 * 0.2);
        FIXHP1(HP1);
        FIXEXP1(EXP1);
    }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
     int result = 0;
    if (E3 < 0 || E3 >= 100) {
        return -99;
    }
    else {
    int matrixtaxi[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrixtaxi[i][j] = (((E3 * j) + (i * 2)) * (i - j));
        }
    }
    int counthor = 0;
    int countver = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrixtaxi[i][j] > (E3 * 2))
                counthor++;
            if (matrixtaxi[i][j] < (-E3) && matrixtaxi[i][j] < 0)
                countver++;
        }
    }
    int a = counthor;
    int b = countver;
    while (a >= 10) {
        int sum = 0;
        int temp = a;
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        a = sum;
    }
    while (b >= 10) {
        int sum = 0;
        int temp = b;
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        b = sum;
    }
    int A = max(findhighmaxleftdia(matrixtaxi,a,b), findlowmaxleftdia(matrixtaxi,a,b));
    int B = max(findhighmaxrightdia(matrixtaxi,a,b), findlowmaxrightdia(matrixtaxi,a,b));
    int C = max(A, B);
    int D = abs(matrixtaxi[a][b]);
    if (C >= D) {
        FIXEXP1(EXP1);
        FIXEXP2(EXP2);
        FIXHP(HP1, HP2);
        EXP1 += ceil((double)EXP1 * 0.12);
        HP1 += ceil((double)HP1 * 0.1);
        EXP2 += ceil((double)EXP2 * 0.12);
        HP2 += ceil((double)HP2 * 0.1);
        FIXEXP1(EXP1);
        FIXEXP2(EXP2);
        FIXHP(HP1, HP2);
        result = C;
    }
    else if (C < D) {
        FIXEXP1(EXP1);
        FIXEXP2(EXP2);
        FIXHP(HP1, HP2);
        EXP1 -= floor((double)EXP1 * 0.12);
        HP1 -= floor((double)HP1 * 0.1);
        EXP2 -= floor((double)EXP2 * 0.12);
        HP2 -= floor((double)HP2 * 0.1);
        FIXEXP1(EXP1);
        FIXEXP2(EXP2);
        FIXHP(HP1, HP2);
        result = matrixtaxi[a][b];
    }
}
    return result;
}


    


// Task 4
int checkPassword(const char * s, const char * email) {
    int lenpass = strlen(s);
    int emaillen = strlen(email);
    string se = "";
    string saveemail = "";
    string pass = "";
    for (int i = 0 ; i < lenpass ; i++)
        pass += s[i];
    for (int i = 0; i < emaillen; i++)
        saveemail += email[i];
    size_t findcheck = saveemail.find('@'); 
    se = saveemail.substr(0, findcheck); 
    if (lenpass < 8) {
        return -1;
    }
    else if (lenpass > 20) {
        return -2;
    }
    size_t foundse = pass.find(se);
    if (foundse != string::npos) { 
        return -(300 + foundse);
    }
    for (size_t i = 0; i < pass.length() - 2; i++) { 
        if(pass[i] == pass[i+1] && pass[i] == pass[i+2]){
            return -(400 + i);
        }
    }
    int cntt = 0;
    int checkk = 0;
    for (int i = 0;i < pass.size();i++)
    {
        if (pass[i] != '@' && pass[i] != '#' && pass[i] != '$' && pass[i] != '%' && pass[i] != '!') cntt++;
        if (pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '%' || pass[i] == '!') checkk++;
    }
    if (cntt + checkk == pass.size() && checkk == 0) return -5;
    int check = 0;
    int cnt = 0;
    for (int i = 0; i < pass.size(); i++)
    {
        cnt++;
        if (((int)pass[i] >= 48 && (int)pass[i] <= 57) || (pass[i] == '@' || pass[i] == '#' || pass[i] == '%' || pass[i] == '$' || pass[i] == '!') || ((int)pass[i] >= 65 && (int)pass[i] <= 90) || ((int)pass[i] >= 97 && (int)pass[i] <= 122))  continue;
        else check++;
        return cnt-1;
    }
    return -10;
    
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string n = "";
    for (int i = 0; i < num_pwds; i++) {
        n += arr_pwds[i];
    }
    int maxre = 0;
    int maxlength = 0;
    int returnpos = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (n[i] == 0)
            continue;
        int currentre = 1;
        int currentlen = strlen(arr_pwds[i]);
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                currentre++;
                n[j] = 0;
            }
        }
        if ((currentre > maxre) || (currentre == maxre && currentlen > maxlength)) {
            maxre = currentre;
            maxlength = currentlen;
            returnpos = i;
        }
    }
    return returnpos;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////