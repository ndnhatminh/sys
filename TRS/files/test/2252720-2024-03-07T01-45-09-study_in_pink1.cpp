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

void checkM(int& M) {
    if (M > 3000) M = 3000;
    else if (M < 0) M = 0;
}
void checkEXP(int& EXP) {
    if (EXP > 600) EXP = 600;
    else if (EXP < 0) EXP = 0;
}
void checkHP(int& HP) {
    if (HP > 666) HP = 666;
    else if (HP < 0) HP = 0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    if (e1 >= 0 && e1 <= 3) {
        checkEXP(exp1);
        checkEXP(exp2);
        switch (e1)
        {
        case 0:
            exp2 += 29;
            checkEXP(exp2);
            break;
        case 1:
            exp2 += 45;
            checkEXP(exp2);
            break;
        case 2:
            exp2 += 75;
            checkEXP(exp2);
            break;
        case 3:
            exp2 += 149;
            checkEXP(exp2);
            break;
        default:
            return -99;
        }
        D = (e1 * 3) + (exp1 * 7);
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + static_cast<float>(D)*0.005); 
        }
        else {
            exp1 = ceil(exp1 - static_cast<float>(D)*0.01);
        }
        checkEXP(exp1);
        return exp1 + exp2;
    }
    else if (e1 >= 4 && e1 <= 99) {
        checkEXP(exp1);
        checkEXP(exp2);
        if (e1 >= 4 && e1 <= 19) {
            exp2 = ceil(exp2 + 19 + (static_cast<float>(e1) / static_cast<float>(4)));
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + 21 + (static_cast<float>(e1) / static_cast < float>(9)));
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + 17 + (static_cast<float>(e1) / static_cast<float>(16)));
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2 + 19 + (static_cast<float>(e1) / static_cast<float>(4))) ;
            if (exp2 > 200) {
                exp2 = ceil(exp2 + 21 + (static_cast<float>(e1) / static_cast<float>(9)));
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2 + 19 + (static_cast<float>(e1) / static_cast<float>(4)));
            exp2 = ceil(exp2 + 21 + (static_cast<float>(e1) / static_cast<float>(9))) ;
            if (exp2 > 400) {
                exp2 = ceil(exp2 + 17 + (static_cast<float>(e1) / static_cast<float>(16))) ;
                exp2 = ceil(static_cast<float>(exp2) * 1.15);
            }
        }
        checkEXP(exp2);
        exp1 -= e1;
        checkEXP(exp1);
        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    else{
        checkHP(HP1);
        checkEXP(EXP1);
        checkM(M1);
        //conduong1
        int s, S;
        float P1, P2, P3, p;
        s = round(sqrt(EXP1));
        S = s * s; //so chinh phuong gan nhat
        if (EXP1 >= S) P1 = 1;
        else P1 = ((static_cast<float>(EXP1) / static_cast<float>(S)) + 80) / 123;
        //cout << "sochinhphuong: " << S << "P1: " << P1 << endl;

        //conduong2
        int hM = ceil(static_cast<float>(M1)) / 2; //cout << hM;
        if (E3 % 2 == 1) {
            int cM = 0;
            bool g = true;
            while (g) {
                if (HP1 < 200) {
                    HP1 = ceil(static_cast<float>(HP1) * 1.3);
                    checkHP(HP1); //cout << HP1 << ", ";
                    M1 -= 150;
                    checkM(M1); 
                    cM += 150;
                }
                else {
                    HP1 = ceil(HP1 + static_cast<float>(HP1) * 0.1);
                    checkHP(HP1); //cout << HP1 << ", ";
                    M1 -= 70;
                    checkM(M1); 
                    cM += 70;
                }if (cM > hM) break;
                if (EXP1 < 400) {
                    M1 -= 200;
                    checkM(M1); 
                    cM += 200;
                    EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                    checkEXP(EXP1);
                }
                else {
                    M1 -= 120;
                    checkM(M1); 
                    cM += 120;
                    EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                    checkEXP(EXP1);
                }if (cM > hM) break;
                if (EXP1 < 300) {
                    M1 -= 100;
                    checkM(M1); 
                    cM += 100;
                    EXP1 = ceil(static_cast<float>(EXP1) * 0.9);
                    checkEXP(EXP1);
                }
                else {
                    M1 -= 120;
                    checkM(M1); 
                    cM += 120;
                    EXP1 = ceil(static_cast<float>(EXP1) * 0.9);
                    checkEXP(EXP1);
                }if (cM > hM) break;
            }
            HP1 = ceil(static_cast<float>(HP1) * 0.83);
            checkHP(HP1); //cout << HP1 << ", ";
            EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
            checkEXP(EXP1);
            //cout << HP1 << ", " << EXP1;
            s = round(sqrt(EXP1));
            S = s * s; //so chinh phuong gan nhat
            if (EXP1 >= S) P2 = 1;
            else P2 = ((static_cast<float>(EXP1) / static_cast<float>(S)) + 80) / 123;
            //cout << "sochinhphuong: " << S << "P1: " << P1 << endl;
        }
        else {
            if (M1 <= 0) {
                checkM(M1);
                HP1 = ceil(static_cast<float>(HP1) * 0.83);
                checkHP(HP1);
                EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
                checkEXP(EXP1);
                //cout << HP1 << ", " << EXP1;
                s = round(sqrt(EXP1));
                S = s * s; //so chinh phuong gan nhat
                if (EXP1 >= S) P2 = 1;
                else P2 = ((static_cast<float>(EXP1) / static_cast<float>(S)) + 80) / 123;
                //cout << "sochinhphuong: " << S << "P1: " << P1 << endl;
            }
            else {
                if (HP1 < 200) {
                    HP1 = ceil(static_cast<float>(HP1) * 1.3);
                    checkHP(HP1);
                    M1 -= 150;
                    //checkM(M1);
                }
                else {
                    HP1 = ceil(HP1 + static_cast<float>(HP1) * 0.1);
                    checkHP(HP1);
                    M1 -= 70;
                    //checkM(M1);
                }if (M1 <= 0) {
                    checkM(M1);
                    HP1 = ceil(static_cast<float>(HP1) * 0.83);
                    checkHP(HP1);
                    EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
                    checkEXP(EXP1);
                    //cout << HP1 << ", " << EXP1;
                    s = round(sqrt(EXP1));
                    S = s * s; //so chinh phuong gan nhat
                    if (EXP1 >= S) P2 = 1;
                    else P2 = ((static_cast<float>(EXP1) / static_cast<float>(S)) + 80) / 123;
                    //cout << "sochinhphuong: " << S << "P1: " << P1 << endl;
                }
                else {
                    if (EXP1 < 400) {
                        M1 -= 200;
                        //checkM(M1);
                        EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                        checkEXP(EXP1);
                    }
                    else {
                        M1 -= 120;
                        //checkM(M1);
                        EXP1 = ceil(static_cast<float>(EXP1) * 1.13);
                        checkEXP(EXP1);
                    }if (M1 <= 0) {
                        checkM(M1);
                        HP1 = ceil(static_cast<float>(HP1) * 0.83);
                        checkHP(HP1);
                        EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
                        checkEXP(EXP1);
                        //cout << HP1 << ", " << EXP1;
                        s = round(sqrt(EXP1));
                        S = s * s; //so chinh phuong gan nhat
                        if (EXP1 >= S) P2 = 1;
                        else P2 = ((static_cast<float>(EXP1) / static_cast<float>(S)) + 80) / 123;
                        //cout << "sochinhphuong: " << S << "P1: " << P1 << endl;
                    }
                    else {
                        if (EXP1 < 300) {
                            M1 -= 100;
                            checkM(M1);
                            EXP1 = ceil(static_cast<float>(EXP1) * 0.9);
                            checkEXP(EXP1);
                        }
                        else {
                            M1 -= 120;
                            checkM(M1);
                            EXP1 = ceil(static_cast<float>(EXP1) * 0.9);
                            checkEXP(EXP1);
                        }
                        checkM(M1);
                        HP1 = ceil(static_cast<float>(HP1) * 0.83);
                        checkHP(HP1);
                        EXP1 = ceil(static_cast<float>(EXP1) * 1.17);
                        checkEXP(EXP1);
                        //cout << HP1 << ", " << EXP1;
                        s = round(sqrt(EXP1));
                        S = s * s; //so chinh phuong gan nhat
                        if (EXP1 >= S) P2 = 1;
                        else P2 = ((static_cast<float>(EXP1) / static_cast<float>(S)) + 80) / 123;
                        //cout << "sochinhphuong: " << S << "P1: " << P1 << endl;
                    }
                }
            }    
        }//conduong3
        int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        if (E3 >= 0 && E3 <= 9) {
            P3 = P[E3];
            P3 = static_cast<float>(P3) / 100;
            //cout << "P3: " << P3 << endl;
        }
        else {
            int a, b;
            a = E3 / 10;
            b = E3 % 10;
            int sum = a + b;
            int c = sum % 10;
            P3 = P[c];
            P3 = static_cast<float>(P3) / 100;
            //cout << "P3: " << P3 << endl;
        }

        //tongket
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = ceil(static_cast<float>(EXP1) * 0.75);
            checkEXP(EXP1);
        }
        else {
            p = (P1 + P2 + P3) / 3;
            //cout << "p: " << p << endl;
            if (p < 0.5) {
                HP1 = ceil(static_cast<float>(HP1) * 0.85);
                checkHP(HP1); //cout << HP1 << ", ";
                EXP1 = ceil(static_cast<float>(EXP1) * 1.15);
                checkEXP(EXP1);
            }
            else {
                HP1 = ceil(static_cast<float>(HP1) * 0.9);
                checkHP(HP1); //cout << HP1 << ", ";
                EXP1 = ceil(static_cast<float>(EXP1) * 1.2);
                checkEXP(EXP1);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    else {
        //khoi-tao-mang
        int A[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                A[i][j] = 0;
            }
        }
        //dien-gia-tri
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                A[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        //gia-tri-lon-hon-e3*2
        int count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (A[i][j] > (E3 * 2)) {
                    count++;
                }
            }
        }
        while (count > 9) {
            int x = count / 10;
            int y = count % 10;
            count = x + y;
        }
        //gia-tri-am-nho-hon-(-e3)
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (A[i][j] < (-E3)) {
                    cnt++;
                }
            }
        }
        while (cnt > 9) {
            int x = cnt / 10;
            int y = cnt % 10;
            cnt = x + y;
        }
        //diem-taxi
        int taxiP = A[count][cnt];
        //cout << taxiP << endl;
        //duong-cheo-phai
        int C[10];
        int k = 0;
        int g = count + cnt;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i + j == g) {
                    C[k] = A[i][j];
                    //cout << C[k] << ",";
                    k++;
                }
            }
        }
        int max = C[0];
        for (int i = 0; i < k; i++) {
            if (max < C[i]) {
                max = C[i];
            }
        }
        //cout << max << endl;
        //duong-cheo-trai
        int B[10];
        int h = 0;
        int i = count; int j = cnt;
        while (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
            B[h] = A[i][j];
            //cout << B[h] << "," << i << "," << j << endl;
            h++;
            i++;
            j++;
        }
        i--;
        j--;
        while (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
            B[h] = A[i][j];
            //cout << B[h] << "," << i << "," << j << endl;
            h++;
            i--;
            j--;
        }
        int MAX = B[0];
        //cout << MAX << endl;
        for (int i = 1; i < h; i++) {
            if (MAX < B[i]) {
                MAX = B[i];
            }
        }
        //cout << MAX << ", " << max;
        //ket-qua-lon-nhat-cua-2-duong-cheo
        int m;
        if (max < MAX) {
            m = MAX;
        }
        else {
            m = max;
        }
        //cout << m << endl;
        if (m < 0) {
            m *= -1;
            if (taxiP < 0) {
                taxiP *= -1;
                if (taxiP > m) {
                    EXP1 = ceil(static_cast<float>(EXP1) * 0.88);
                    checkEXP(EXP1);
                    EXP2 = ceil(static_cast<float>(EXP2) * 0.88);
                    checkEXP(EXP2);
                    HP1 = ceil(static_cast<float>(HP1) * 0.9);
                    checkHP(HP1);
                    HP2 = ceil(static_cast<float>(HP2) * 0.9);
                    checkHP(HP2);
                    return taxiP * -1;
                }
                else {
                    EXP1 = ceil(float(EXP1 * 1.12));
                    checkEXP(EXP1);
                    EXP2 = ceil(float(EXP2 * 1.12));
                    checkEXP(EXP2);
                    HP1 = ceil(HP1 + static_cast<float>(HP1) / 10);
                    checkHP(HP1);
                    HP2 = ceil(HP2 + static_cast<float>(HP2) / 10);
                    checkHP(HP2);
                    return m;
                }
            }
            else {
                if (taxiP > m) {
                    EXP1 = ceil(static_cast<float>(EXP1) * 0.88);
                    checkEXP(EXP1);
                    EXP2 = ceil(static_cast<float>(EXP2) * 0.88);
                    checkEXP(EXP2);
                    HP1 = ceil(static_cast<float>(HP1) * 0.9);
                    checkHP(HP1);
                    HP2 = ceil(static_cast<float>(HP2) * 0.9);
                    checkHP(HP2);
                    return taxiP;
                }
                else {
                    EXP1 = ceil(float(EXP1 * 1.12));
                    checkEXP(EXP1);
                    EXP2 = ceil(float(EXP2 * 1.12));
                    checkEXP(EXP2);
                    HP1 = ceil(HP1 + static_cast<float>(HP1) / 10);
                    checkHP(HP1);
                    HP2 = ceil(HP2 + static_cast<float>(HP2) / 10);
                    checkHP(HP2);
                    return m;
                }
            }
        }
        else {
            if (taxiP < 0) {
                taxiP *= -1;
                if (taxiP > m) {
                    EXP1 = ceil(static_cast<float>(EXP1) * 0.88);
                    checkEXP(EXP1);
                    EXP2 = ceil(static_cast<float>(EXP2) * 0.88);
                    checkEXP(EXP2);
                    HP1 = ceil(static_cast<float>(HP1) * 0.9);
                    checkHP(HP1);
                    HP2 = ceil(static_cast<float>(HP2) * 0.9);
                    checkHP(HP2);
                    return taxiP * -1;
                }
                else {
                    EXP1 = ceil(float(EXP1 * 1.12));
                    checkEXP(EXP1);
                    EXP2 = ceil(float(EXP2 * 1.12));
                    checkEXP(EXP2);
                    HP1 = ceil(HP1 + static_cast<float>(HP1) / 10);
                    checkHP(HP1);
                    HP2 = ceil(HP2 + static_cast<float>(HP2) / 10);
                    checkHP(HP2);
                    return m;
                }
            }
            else {
                if (taxiP > m) {
                    EXP1 = ceil(static_cast<float>(EXP1) * 0.88);
                    checkEXP(EXP1);
                    EXP2 = ceil(static_cast<float>(EXP2) * 0.88);
                    checkEXP(EXP2);
                    HP1 = ceil(static_cast<float>(HP1) * 0.9);
                    checkHP(HP1);
                    HP2 = ceil(static_cast<float>(HP2) * 0.9);
                    checkHP(HP2);
                    return taxiP;
                }
                else {
                    EXP1 = ceil(float(EXP1 * 1.12));
                    checkEXP(EXP1);
                    EXP2 = ceil(float(EXP2 * 1.12));
                    checkEXP(EXP2);
                    HP1 = ceil(HP1 + static_cast<float>(HP1) * 0.1);
                    checkHP(HP1);
                    HP2 = ceil(HP2 + static_cast<float>(HP2) * 0.1);
                    checkHP(HP2);
                    return m;
                }
            }

        }
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    const int min = 8;
    const int max = 20;

    char se[101];
    int i;
    for (i = 0; email[i] != '@'; ++i) {
        se[i] = email[i];
    }
    se[i] = '\0';

    //kiem-tra-do-dai-mat-khau
    int len = strlen(s);
    if (len < min) return -1;
    if (len > max) return -2;

    //kiem-tra-mat-khau-co-chua-se
    const char* found = strstr(s, se);
    if (found != nullptr) return -(300 + (found - s));

    //kiem-tra-xem-mat-khau-co-chua-ki-tu-lien-tiep-giong-nhau
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }

    //kiem-tra-mat-khau-co-chua-ki-tu-dac-biet 
    bool k = false;
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            k = true;
            break;
        }
    }
    if (!k) return -5;

    //kiem-tra-cac-dieu-kien-con-lai
    bool hasDigit = false;
    bool hasUpperCase = false;
    bool hasLowerCase = false;

    for (i = 0; s[i] != '\0'; ++i) {
        if (isdigit(s[i])) {
            hasDigit = true;
        }
        else if (isupper(s[i])) {
            hasUpperCase = true;
        }
        else if (islower(s[i])) {
            hasLowerCase = true;
        }

        if (hasDigit && hasUpperCase && hasLowerCase && k) {
            break;
        }
    }
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '^' || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')') {
            return i;
        }
    }
    return -10;

}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq[num_pwds];

    for (int i = 0; i < num_pwds; i++) {
        int currFreq = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                currFreq++;
            }
        }
        freq[i] = currFreq;
    }

    int maxFI = 0;
    for (int i = 1; i < num_pwds; i++) {
        if (freq[i] > freq[maxFI] || (freq[i] == freq[maxFI] && strlen(arr_pwds[i]) > strlen(arr_pwds[maxFI]))) {
            maxFI = i;
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], arr_pwds[maxFI]) == 0) {
            return i;
        }
    }

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////