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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1 < 0 || E1 > 99) return -99;

    if(EXP1 < 0) EXP1 = 0; if (EXP1 > 600) EXP1 = 600;
    if(EXP2 < 0) EXP2 = 0; if (EXP2 > 600) EXP2 = 600;

    int d = 0;

    if(E1 >= 0 && E1 <= 3) {
        // Thong tin 1
        if(E1 == 0) {
            EXP2 += 29;
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 2
        else if(E1 == 1) {
            EXP2 += 45;
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 3
        else if(E1 == 2) {
            EXP2 += 75;
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 4
        else {
            EXP2 += 149;
            if(EXP2 > 600) EXP2 = 600;
        }
        // Tinh d
        d = E1 * 3 + EXP1 * 7;
        if(d % 2 == 0) {
            EXP1 += d / 200 + (d % 200 != 0);
            if(EXP1 > 600) EXP1 = 600;
        }
        else {
            EXP1 -= floor(d/100);
            if(EXP1 < 0) EXP1 = 0;
        }
    }
    // Xong TH1
    else {
        // Thong tin 1
        if(E1 >= 4 && E1 <= 19) {
            EXP2 += E1/4 + 19 + (E1 % 4 != 0);
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 2
        else if(E1 >= 20 && E1 <= 49) {
            EXP2 += E1/9 + 21 + (E1 % 9 != 0);
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 3
        else if(E1 >= 50 && E1 <= 65) {
            EXP2 += E1/16 + 17 + (E1 % 16 != 0);
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 4
        else if(E1 >= 66 && E1 <= 79) {
            EXP2 += E1/4 + 19 + (E1 % 4 != 0);
            if(EXP2 > 200) {
                EXP2 += E1/9 + 21 + (E1 % 9 != 0);
            }
            if(EXP2 > 600) EXP2 = 600;
        }
        // Thong tin 5
        else {
            EXP2 += E1/4 + 19 + (E1 % 4 != 0);
            EXP2 += E1/9 + 21 + (E1 % 9 != 0);
            if(EXP2 > 400) {
                EXP2 += E1/16 + 17 + (E1 % 16 != 0);
                EXP2 += EXP2 * 15 / 100 + (EXP2 * 15 % 100 != 0);
            }
            if(EXP2 > 600) EXP2 = 600;
        }
        EXP1 -= E1;
        if(EXP1 < 0) EXP1 = 0;
    } 
    // Xong TH2
    return EXP1 + EXP2;
}
// Xong task 1

// Task 2
int nearestSquare(int n) {
    int root = round(sqrt(n));
    return root * root;
}

double road1(int & EXP1)
{
    double p1;
    int s = nearestSquare(EXP1);
    if(EXP1 >= s) p1 = 1;
    else p1 = ((double)EXP1/s +80) / 123;
    return p1;
}
// Xong duong 1
int buy(int & HP1, int & M1) {
    int sum = 0;

    if(HP1 < 200) {
        M1 -= 150;
        if(M1 < 0) M1 = 0;
        HP1 += HP1 * 30 / 100 + (HP1 * 30 % 100 != 0);
        sum += 150;
    }
    else {
        M1 -= 70;
        if(M1 < 0) M1 = 0;
        HP1 += HP1 * 10 / 100 + (HP1 * 10 % 100 != 0);
        sum += 70;
    }

    if(HP1 > 666) HP1 = 666;

    return sum;
}

int rent(int & EXP1, int & M1) {
    int sum = 0;

    if(EXP1 < 400) {
        M1 -= 200;
        if(M1 < 0) M1 = 0;
        sum += 200;
    }
    else {
        M1 -= 120;
        if(M1 < 0) M1 = 0;
        sum += 120;
    }

    EXP1 += EXP1 * 13 / 100 + (EXP1 * 13 % 100 != 0);
    if(EXP1 > 600) EXP1 = 600;

    return sum;
}

int help(int & EXP1, int & M1) {
    int sum = 0;

    if(EXP1 < 300) {
        M1 -= 100;
        if(M1 < 0) M1 = 0;
        sum += 100;
    }
    else {
        M1 -= 120;
        if(M1 < 0) M1 = 0;
        sum += 120;
    }

    EXP1 -= floor(EXP1 * 10 / 100);
    if(EXP1 < 0) EXP1 = 0;

    return sum;
}

double road2(int & HP1, int & EXP1, int & M1, int E2) {
    bool shouldExit = false;

    if(M1 != 0) {
        if(E2 % 2 == 0) {
            buy(HP1, M1); 
            if(M1 == 0) shouldExit = true;
            if(!shouldExit) {
                rent(EXP1, M1); 
                if(M1 == 0) shouldExit = true;
            }
            if(!shouldExit) {
                help(EXP1, M1); 
            }
        }
        else {
            int half_m = M1 / 2;
            int sum = 0;
            while (sum <= half_m) {
                sum += buy(HP1, M1);
                if(sum > half_m) break;
                sum += rent(EXP1, M1);
                if(sum > half_m) break;
                sum += help(EXP1, M1);
            }
        }
    }

    HP1 -= floor(HP1 * 17 / 100); 
    EXP1 += EXP1 * 17 / 100 + (EXP1 * 17 % 100 != 0);
    if(HP1 < 0) HP1 = 0;
    if(EXP1 > 600) EXP1 = 600; 

    double p2;
    int s = nearestSquare(EXP1);
    if(EXP1 >= s) p2 = 1;
    else p2 = ((double)EXP1/s +80) / 123;

    return p2;
}
// Xong duong 2
double road3(int E2) {
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;

    if(E2 < 10) i = E2;
    else {
        int sum = E2 / 10;
        sum += E2 % 10;
        i = sum % 10;
    }

    double p3 = (double) arr[i] / 100;

    return p3;
}
// Xong duong 3
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;

    if(HP1 < 0) HP1 = 0; if (HP1 > 666) HP1 = 666;
    if(EXP1 < 0) EXP1 = 0; if (EXP1 > 600) EXP1 = 600;
    if(M1 < 0) M1 = 0; if (M1 > 3000) M1 = 3000;

    double p1, p2, p3, p;

    p1 = road1(EXP1);
    p2 = road2(HP1, EXP1, M1, E2);
    p3 = road3(E2);
    p = (p1 + p2 + p3) / 3;
    if(p == 1) EXP1 -= EXP1 * 25 / 100;

    else if( p < 0.5) {
        HP1 -= floor(HP1 * 15 / 100);
        EXP1 += EXP1 * 15 / 100 + (EXP1 * 15 % 100 != 0);
    }
    else {
        HP1 -= floor(HP1 * 10 / 100);
        EXP1 += EXP1 * 20 / 100 + (EXP1 * 20 % 100 != 0);
    }

    if(HP1 < 0) HP1 = 0;
    if(EXP1 > 600) EXP1 = 600;

    return HP1 + EXP1 + M1;
}
// Xong task 2

// Task 3
int sumNum(int n) {
    int sum = n / 10;
    sum += n % 10;
    return sum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0 || E3 > 99) return -99;

    if(HP1 < 0) HP1 = 0; if (HP1 > 666) HP1 = 666;
    if(EXP1 < 0) EXP1 = 0; if (EXP1 > 600) EXP1 = 600;
    if(HP2 < 0) HP2 = 0; if (HP2 > 666) HP2 = 666;
    if(EXP2 < 0) EXP2 = 0; if (EXP2 > 600) EXP2 = 600;

    int taxiMatrix[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int detectiveMatrix[10][10];

    for(int j = 0; j < 10; j++) {
        for(int i = 0; i < 10; i++) {
            detectiveMatrix[i][j] = taxiMatrix[i][j];
            for(int k = i, l = j; k >= 0 && l >= 0; k--, l--) if (taxiMatrix[k][l] > detectiveMatrix[i][j]) detectiveMatrix[i][j] = taxiMatrix[k][l];
            for(int k = i, l = j; k < 10 && l < 10; k++, l++) if (taxiMatrix[k][l] > detectiveMatrix[i][j]) detectiveMatrix[i][j] = taxiMatrix[k][l];
            for(int k = i, l = j; k >= 0 && l < 10; k--, l++) if (taxiMatrix[k][l] > detectiveMatrix[i][j]) detectiveMatrix[i][j] = taxiMatrix[k][l];
            for(int k = i, l = j; k < 10 && l >= 0; k++, l--) if (taxiMatrix[k][l] > detectiveMatrix[i][j]) detectiveMatrix[i][j] = taxiMatrix[k][l];
        }
    }

    int x = 0; int y = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(taxiMatrix[i][j] > E3 * 2) x++;
            if(taxiMatrix[i][j] < -E3) y++;
        }
    }

    if(x >= 10) {
        while(x >= 10) x = sumNum(x);
    }
    if(y >= 10) {
        while(y >= 10) y = sumNum(y);
    }

    int detectivePoint, taxiPoint;
    detectivePoint = detectiveMatrix[x][y];
    taxiPoint = taxiMatrix[x][y];

    if(abs(taxiPoint) > abs(detectivePoint)) {
        HP1 -= floor(HP1 * 10 / 100);
        EXP1 -= floor(EXP1 * 12 / 100);
        HP2 -= floor(HP2 * 10 / 100);
        EXP2 -= floor(EXP2 * 12 / 100);
        if(HP1 < 0) HP1 = 0;
        if(EXP1 < 0) EXP1 = 0;
        if(HP2 < 0) HP2 = 0;
        if(EXP2 < 0) EXP2 = 0;
        return taxiPoint;
    }
    else {
        HP1 += HP1 * 10 / 100 + (HP1 * 10 % 100 != 0);
        EXP1 += EXP1 * 12 / 100 + (EXP1 * 12 % 100 != 0);
        HP2 += HP2 * 10 / 100 + (HP2 * 10 % 100 != 0);
        EXP2 += EXP2 * 12 / 100 + (EXP2 * 12 % 100 != 0);
        if(HP1 > 666) HP1 = 666;
        if(EXP1 > 600) EXP1 = 600;
        if(HP2 > 666) HP2 = 666;
        if(EXP2 > 600) EXP2 = 600;
        return detectivePoint;
    }
}
// Xong task 3

// Task 4
bool containSpecialCharacters(const string& s) {
    const string specialCharacters = "@#%$!";

    for (char c : specialCharacters) {
        if (s.find(c) != string::npos) {
            return true;
        }
    }

    return false;
}

bool isValidCharacter(char c) {
    return (isdigit(c) || islower(c) || isupper(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Kiem tra s co du do dai
    if(strlen(s) < 8) return -1;
    if(strlen(s) > 20) return -2;
    // Kiem tra s chua se
    string se;
    int count = 0;

    for (int i = 0; email[i] != '@'; i++) {
        se += email[i];
        count++;
    }

    bool found = false;
    int sei = -1; 

    for (int i = 0; i < strlen(s); i++) {
        if (se[0] == s[i]) {
            bool match = true;
            for (int j = 0; j < count; j++) {
                if (se[j] != s[i + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                found = true;
                sei = i;
                break;
            }
        }
    }

    if (found) return -(300 + sei);
    // Kiem tra neu s chua nhieu hon 2 ky tu giong nhau lien tiep 
    int n = strlen(s);
    int sci = -1; 

    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            sci = i;
            break;
        }
    }

    if(sci != -1) return -(400 + sci);
    // Kiem tra neu s chua ky tu dac biet 
    bool SpecialCharacters = containSpecialCharacters(s);
    if(!SpecialCharacters) return -5;
    // Kiem tra cac loi khac
    int invalidPosition = -1;

    for (int i = 0; i < n; i++) {
        if (!isValidCharacter(s[i])) {
            invalidPosition = i;
            break;
        }
    }

    if (invalidPosition != -1) return invalidPosition;
    // S hop le
    return -10;
}
// Xong task 4

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int max_count = 0;
    int max_length = 0;
    int index = 0;

    for (int i = 0; i < num_pwds; ++i) {
        const char *pwd = arr_pwds[i];
        int length = strlen(pwd);
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0)
                count++;
        }
        if (count > max_count) {
            max_count = count;
            max_length = length;
            index = i;
        } 
        else if (count == max_count && length > max_length) {
            max_length = length;
            index = i;
        }
    }
    
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////