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
int firstMeet(int& exp1, int& exp2, int e1) {
    int D;
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 = exp2 + 29;
        else if (e1 == 1) exp2 = exp2 + 45;
        else if (e1 == 2) exp2 = exp2 + 75;
        else if (e1 == 3) exp2 = exp2 + 45 + 29 + 75;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = exp1 + ceil((float)D / 200);
        else if (D % 2 == 1) exp1 = (exp1 - floor((float)D / 100));
    }
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 = exp2 + ceil((float)e1 / 4) + 19;
        else if (e1 >= 20 && e1 <= 49) exp2 = (exp2 + ceil((float)e1 / 9) + 21);
        else if (e1 >= 50 && e1 <= 65) exp2 = (exp2 + ceil((float)e1 / 16) + 17);
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + ceil((float)e1 / 4) + 19);
            if (exp2 > 200) exp2 = (exp2 + ceil((float)e1 / 9) + 21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = (exp2 + ceil((float)e1 / 4) + 19 + ceil((float)e1 / 9) + 21);
            if (exp2 > 400) exp2 = (exp2 + ceil((float)e1 / 16) + 17);
            exp2 = ceil((float)exp2 * 1.15);
        }
        exp1 = exp1 - e1;
       
    }
     if (exp1 < 0) exp1 = 0;
        if (exp2 < 0) exp2 = 0;
        if (exp1 > 600) exp1 = 600;
        if (exp2 > 600) exp2 = 600;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    int q, q1; float p, p1, p2, p3;
    //duong1
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (HP1 > 666) HP1 = 666;
    q = round(sqrt(EXP1));
    if (EXP1 > q * q) p1 = 100;
    else p1 = round((float)((100 * EXP1) / (q * q) + 8000) / 123);
    // duong 2
    int MMM = M1;
    int m = 0;
    if (E2 % 2 == 0) {
        if (HP1 < 200) {
            HP1 = ceil((float)HP1 * 1.3);
            M1 = M1 - 150;
        }
        else {
            HP1 = ceil((float)HP1 * 1.1);
            M1 = M1 - 70;
        }
        if (M1 <= 0) M1 = 0;
        else {
            if (EXP1 < 400) M1 = M1 - 200;
            else
                M1 = M1 - 120;
            EXP1 = ceil((float)EXP1 * 1.13);


            if (M1 <= 0) M1 = 0;
            else {
                if (EXP1 < 300) M1 = M1 - 100;
                else
                    M1 = M1 - 120;
                EXP1 = ceil((float)EXP1 * 0.9);

            }
        }
        
    }
    else if (E2 % 2 == 1) {
        while (m < MMM / 2) {
            m = MMM - M1;
            if (HP1 < 200) {
                HP1 = ceil((float)HP1 * 1.3);
                M1 = M1 - 150;
            }
            else {
                HP1 = ceil((float)HP1 * 1.1);
                M1 = M1 - 70;
            }
            m = MMM - M1;
            if (m > MMM / 2) break;
            if (EXP1 < 400) M1 = M1 - 200;
            else
                M1 = M1 - 120;
            EXP1 = ceil((float)EXP1 * 1.13);

            m = MMM - M1;
            if (m > MMM / 2) break;
            if (EXP1 < 300) M1 = M1 - 100;
            else
                M1 = M1 - 120;
            EXP1 = ceil((float)EXP1 * 0.9);

        }
    }
            if (HP1 > 666) HP1 = 666;
                else if (HP1 < 0) HP1 = 0;
            HP1 = ceil((float)HP1 * 0.83);
    EXP1 = ceil((float)EXP1 * 1.17);
        if ( EXP1 >600 ) EXP1 = 600;
                else if ( EXP1 <0 ) EXP1 = 0;
                cout<< EXP1<<endl;
    q1 = round(sqrt(EXP1));
    if (EXP1 > q1 * q1) p2 = 100;
    else p2 = round((float)((100 * EXP1) / (q1 * q1) + 8000) / 123);

    //duong 3
    int mang[] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else if (E2 >= 10) {
        int bien;
        bien = E2 / 10 + E2 % 10;
        if (bien < 10) i = bien;
        else i = bien % 10;
    }
    p3 = mang[i];
    p = (p1 + p2 + p3) / 3;
    if (p == 100) {
        EXP1 = ceil((float)EXP1 * 0.75);
    }
    else {
        if (p < 50) {
            HP1 = ceil((float)HP1 * 0.85);
            EXP1 = ceil((float)EXP1 * 1.15);

        }
        else if (p >= 50) {
            HP1 = ceil((float)HP1 * 0.9);
            EXP1 = ceil((float)EXP1 * 1.2);
        }
    }
    if (M1 < 0) M1 = 0;
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3
int maxcheo(int matrix[10][10], int row, int col) {
    int maxa = matrix[row][col];

    int i = row, j = col;
    while (i < 10 && j < 10) {
        maxa = max(maxa, matrix[i][j]);
        i++;
        j++;
    }
    i = row, j = col;
    while (i < 10 && j >= 0) {
        maxa = max(maxa, matrix[i][j]);
        i++;
        j--;
    }
    i = row, j = col;
    while (i >= 0 && j < 10) {
        maxa = max(maxa, matrix[i][j]);
        i--;
        j++;
    }
    i = row, j = col;
    while (i >= 0 && j >= 0) {
        maxa = max(maxa, matrix[i][j]);
        i--;
        j--;
    }
    return maxa;
}

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int j, k, duong = 0, am = 0, a, b;
    int mang2[10][10];
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
            mang2[j][k] = (E3 * k + (j * 2)) * (j - k);
            if (mang2[j][k] > (E3) * 2) duong = duong + 1;
            else if (mang2[j][k] < (-1) * E3) am = am + 1;
        }
    }
    if (duong < 10) {
        a = duong;
    }
    else if (duong >= 10) {
        a = duong / 10 + duong % 10;
        if (a >= 0) a = a / 10 + a % 10;
    }
    if (am < 10) {
        b = am;
    }
    else if (am >= 10) {
        b = am / 10 + am % 10;
        if (b >= 0) b = b / 10 + b % 10;
    }

    int max = maxcheo(mang2, a, b);
    if (abs(max) > abs(mang2[a][b])) {
        EXP1 = ceil((float)EXP1 * 1.12);
        HP1 = ceil((float)HP1 * 1.1);
        EXP2 = ceil((float)EXP2 * 1.12);
        HP2 = ceil((float)HP2 * 1.1);

        return max;
    }
    else {
        EXP1 = ceil((float)EXP1 * 0.88);
        HP1 = ceil((float)HP1 * 0.9);
        EXP2 = ceil((float)EXP2 * 0.88);
        HP2 = ceil((float)HP2 * 0.9);

        return mang2[a][b];
    }
}

// Task 4

int checkPassword(string s, string email) {
    int i = 0; int m = 0, n = 0, p,v;
    string se;
    while (email[i] != '@')
        i++;
    se = email.substr(0, i);
    p = s.length();
    int q = se.length();
    for (int j = 0; j < p; j++) {
        if (s[j] == '@' || s[j] == '#' || s[j] == '$' || s[j] == '&' || s[j] == '!')
            m = m + 1;
    }

    for (int k = 0; k < p - 2; k++) {
        if ((s[k] == s[k + 1] && s[k + 1] == s[k + 2])){
            n = n + 1;
            v=k;
            break;
        }
    }
    int a, b, c = 0;
    for (a = 0; a <= p - q; ++a) {
        for (b = 0; b < q; ++b) {
            if (s[a + b] != se[b]) {
                break;
            }
        }
        if (b == q)  // Nếu tìm thấy chuỗi con
            c = c + 1;
    }

    size_t f = s.find(se);
    int h = f;
    if ((p >= 8 && p <= 20) && (m != 0) && (n == 0) && c == 0)
        return -10;

    if (p < 8) return -1;
    else if (p > 20) return -2;
    else {
        if (c != 0)
            return -(300 + h);
        else {
            if (n != 0) return -(400 + v);

            else if (m == 0) return -5;
        }
    }
    return -99;
}

//Task 5 
int findCorrectPassword(const char* arr_pwds[], int num_pwds) { 
    // TODO: Complete this function 
    int passwordCount[30] = { 0 };
    int passwordLength[30] = { 0 };
    int maxLength = 0; int maxCount = 0; 
    int correctPasswordIndex = -1; 
    for (int i = 0; i < num_pwds; ++i)  {
        int index = -1; for (int j = 0; j < i; ++j) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) { 
                index = j;
                break;
            } 
        } 
        if (index == -1) { 
            index = i;
        } 
        passwordCount[index]++; 
        passwordLength[index] = strlen(arr_pwds[i]);
        if (passwordCount[index] > maxCount || (passwordCount[index] == maxCount && passwordLength[index] > maxLength)) {
            maxCount = passwordCount[index]; 
            maxLength = passwordLength[index];
            correctPasswordIndex = index;
        } 
    } 
    return correctPasswordIndex; 
 }
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////