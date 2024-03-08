#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
int firstMeet(int& exp1, int& exp2, int e1)
{
    // TODO: Complete this function
    // TH1
    if (e1 < 0 || e1 >99)
    {
        return -99;
    }
    exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    if (e1 >= 0 && e1 < 4) {
        if (e1 == 0) {
            exp2 += 29;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        }
        if (e1 == 1) {
            exp2 += 45;
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        }
        if (e1 == 2) {
            exp2 += 75;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        }
        if (e1 == 3) {
            exp2 += 29 + 45 + 75;
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        }

        int(D) = e1 * 3 + exp1 * 7;

        // Kiem tra neu D la so chan
        if (int(D) % 2 == 0) {
            // Dua ra du doan thien ve afghanistan va cong cho Sherlock D/200 exp
            exp1 = ceil(exp1 + D / 200.0);
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        }
        else {
            // Neu D la so le, thien ve iraq, tru di D/100 exp cua Sherlock
            exp1 = ceil(exp1 - D / 100.0);
            exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        }
    }
    //TH2
    exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    if (e1 >= 4 && e1 <= 19) {
        exp2 += ceil(e1 / 4.0 + 19);
        exp1 -= e1;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    }
    else if (e1 >= 20 && e1 <= 49) {
        exp2 += ceil(e1 / 9.0 + 21);
        exp1 -= e1;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    }
    else if (e1 >= 50 && e1 <= 65) {
        exp2 += ceil(e1 / 16.0 + 17);
        exp1 -= e1;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    }
    else if (e1 >= 66 && e1 <= 79) {
        exp2 += ceil(e1 / 4.0 + 19);
        exp1 -= e1;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        if (exp2 > 200) {
            exp2 += ceil(e1 / 9.0 + 21);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        }
    }
    else if (e1 >= 80 && e1 <= 99) {
        exp2 += ceil(e1 / 4.0 + 19);
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        exp2 += ceil(e1 / 9.0 + 21);
        exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
        exp1 -= e1;
        exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
        if (exp2 > 400) {
            exp2 += ceil(e1 / 16.0 + 17);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            exp2 += ceil(0.15 * exp2);
            exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
            // Neu Sherlock giai thich ca 3 thong tin, cong them cho Sherlock 15% exp

        }
    }
    exp1 = (exp1 > 600) ? 600 : (exp1 < 0) ? 0 : exp1;
    exp2 = (exp2 > 600) ? 600 : (exp2 < 0) ? 0 : exp2;
    return exp1 + exp2;
}


// Task 2

bool isPerfectSquare(int EXP1) {
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    int sqrtEXP1 = sqrt(EXP1);
    return sqrtEXP1 * sqrtEXP1 == EXP1;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 >99) {
        return -99;
    }
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    //case1
    int S1 = 0;
    float P1 = 0;
    int lower1 = sqrt(EXP1);
    int upper1 = sqrt(EXP1) + 1;
    if (EXP1 - lower1 * lower1 > upper1 * upper1 - EXP1) {
        S1 = upper1 * upper1;
    }
    else S1 = lower1 * lower1;
    if (EXP1 >= S1) {
        P1 = 100;
    }
    else {
        P1 = (EXP1 / S1 + 80) / 1.23;
    }
    //case 2
    int T = M1;
    if (E2 % 2 == 1) {
        while (true) {
            if (M1 <= 0) {
                break;
            }
            //1
            if (M1 < T * 0.5) {
                break;
            }
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            if (HP1 < 200) {
                //sherlock an uong hoi HP
                M1 = M1 - 150;
                // tang hp len 30%    
                HP1 = ceil(HP1 + HP1 * 3.0 / 10);
            }
            else {
                // sherlock chi mua nuoc uong
                M1 = M1 - 70;
                // tang hp len 10%    
                HP1 = ceil(HP1 + HP1 * 1.0 / 10);
            }
            if (M1 < 0) {
                break;
            }
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            //2
            if (M1 < T * 0.5) {
                break;
            }
            // thue taxi hoac xe ngua
            if (EXP1 < 400) {
                //thue taxi
                M1 = M1 - 200;
            }
            else {
                //thue xe ngua
                M1 = M1 - 120;
            }
            EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100); // tang exp len 13%
            if (M1 < 0) {
                break;
            }
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            //3
            if (M1 < T * 0.5) {
                break;
            }
            // su kien gap nguoi vo gia cu
            if (EXP1 < 300) {
                //giup do nguoi vo gia cu
                M1 = M1 - 100;
            }
            else {
                //nho nguoi vo gia cu dan duong di
                M1 = M1 - 120;
            }
            EXP1 = ceil(EXP1 - EXP1 * 1.0 / 10); // giam exp di 10%
            if (M1 < 0) {
                break;
            }
            EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
            M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
        }
    }
    else {
        while (true) {
            if (M1 < 0) {
                break;
            }
            //1
            if (M1 > 0) {
                if (HP1 < 200) {
                    //sherlock an uong hoi HP
                    M1 = M1 - 150;
                    // tang hp len 30%    
                    HP1 = ceil(HP1 + HP1 * 3.0 / 10);
                }
                else {
                    // sherlock chi mua nuoc uong
                    M1 = M1 - 70;
                    // tang hp len 10%    
                    HP1 = ceil(HP1 + HP1 * 1.0 / 10);
                }

                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
                HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
            }
            //2  
            if (M1 > 0) {
                // thue taxi hoac xe ngua
                if (EXP1 < 400) {
                    //thue taxi
                    M1 = M1 - 200;
                }
                else {
                    //thue xe ngua
                    M1 = M1 - 120;
                }
                EXP1 = ceil(EXP1 + EXP1 * 13.0 / 100); // tang exp len 13%

                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            }
            //3
            if (M1 > 0) {
                // su kien gap nguoi vo gia cu
                if (EXP1 < 300) {
                    //giup do nguoi vo gia cu
                    M1 = M1 - 100;
                }
                else {
                    //nho nguoi vo gia cu dan duong di
                    M1 = M1 - 120;
                }
                EXP1 = ceil(EXP1 - EXP1 * 1.0 / 10); // giam exp di 10%

                EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
                M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
            }
            break;
        }
    }
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    HP1 = ceil(HP1 - HP1 * 0.17); // giam hp di 17%
    EXP1 = ceil(EXP1 + EXP1 * 0.17); // tang exp len 17%
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    int S2 = 0;
    float P2 = 0;
    int lower2 = sqrt(EXP1);
    int upper2 = sqrt(EXP1) + 1;
    if (EXP1 - lower2 * lower2 > upper2 * upper2 - EXP1) {
        S2 = upper2 * upper2;
    }
    else S2 = lower2 * lower2;
    if (EXP1 >= S2) {
        P2 = 100;
    }
    else {
        P2 = (EXP1 / S2 + 80) / 1.23;
    }
    //case 3
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i; // chi so gia tri xac suat sherlock tim thay vali
    if (E2 < 10) {
        i = E2; // neu i co 1 chu so thi la E2
    }
    else {
        int sum = (E2 / 10) + (E2 % 10); // tim i neu e co 2 chu so
        i = sum % 10; //lay so hang don vi gan cho i
    }
    int P3 = P[i];
    float  avg = (P1 + P2 + P3) / 3;
    if (avg == 100) {
        EXP1 = ceil(EXP1 - EXP1 * 25.0 / 100);
    }
    else if (avg < 50) {
        HP1 = ceil(HP1 - HP1 * 15.0 / 100);
        EXP1 = ceil(EXP1 + EXP1 * 15.0 / 100);
    }
    else {
        HP1 = ceil(HP1 - HP1 * 1.0 / 10);
        EXP1 = ceil(EXP1 + EXP1 * 2.0 / 10);
    }
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;
    HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;
    int matrix[10][10], x = 0, y = 0, result = INT_MIN;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = (i - j) * (E3 * j + 2 * i);
            if (matrix[i][j] < -E3) x++; //count row
            if (matrix[i][j] > 2 * E3) y++; //count collumn
        }
    }
    while (x > 9) {
        x = x % 10 + x / 10;
    }
    while (y > 9) {
        y = y % 10 + y / 10;
    }
    for (int i = 0; i < 10; i++) {
        if (x + i <= 9 && y + i <= 9) {
            result = max(result, matrix[y + i][x + i]);
        }
        if (x - i >= 0 && y - i >= 0) {
            result = max(result, matrix[y - i][x - i]);
        }
        if (y - i >= 0 && x + i <= 9) {
            result = max(result, matrix[y - i][x + i]);
        }
        if (y + i <= 9 && x - i >= 0) {
            result = max(result, matrix[y + i][x - i]);
        }
    }
    if (abs(matrix[y][x]) > result) {
        EXP1 = ceilf(EXP1 * 0.88);
        EXP2 = ceilf(EXP2 * 0.88);
        HP1 = ceilf(HP1 * 0.9);
        HP2 = ceilf(HP2 * 0.9);
        return matrix[y][x];
    }
    EXP1 = ceilf(EXP1 * 1.12);
    EXP2 = ceilf(EXP2 * 1.12);
    HP1 = ceilf(HP1 * 1.1);
    HP2 = ceilf(HP2 * 1.1);
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;
    HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;
    return result;
}
// Task 4
bool isSPEchar(char ch) {
    // Kiem tra cac ki tu dac biet co duoc cho phep
    return (ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!');
}
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}
bool isAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int length = strlen(s);
    // Do dai mat khau qua ngan return -1
    if (length < 8) {
        return -1;
    }
    // Do dai mat khau qua dai return -2
    if (length > 20) {
        return -2;
    }
    if (email[0] == '@') return -300;
    for (int i = 0; i < length; ++i) {
        if (s[i] == email[0]) {
            for (int j = 1; email[j - 1] != '@'; ++j) {
                if (email[j] == '@') return -(300 + i);
                if (s[i + j] != email[j]) break;
            }
        }
    }
    // Kiem tra co chua 2 ky tu lien tiep giong nhau khong
    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    //Kiem tra ky tu dac biet return -5
    bool hasSPEchar = false;
    for (int i = 0; i < length; ++i) {
        if (isSPEchar(s[i])) {
            hasSPEchar = true;
            break;
        }
    }
    if (!hasSPEchar) {
        return -5;
    }
    // Kiem tra tung ky tu trong mat khau
    for (int i = 0; i < length; ++i) {
        char ch = s[i];
        // Kiem tra ky tu co phai chu hoa, chu so, dac biet?
        if (!(isDigit(ch) || isAlpha(ch) || isSPEchar(ch))) {
            return i; // Tra ve vi tri ky tu khong hop le
        }
    }
    // Mat khau hop le return -10
    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    // Gan bien de tim tan so xuat hien va do dai lon nhat
    int MaxFrequency = 0;
    int MaxLength = 0;
    // Gan bien luu vi tri dung cua password
    int Password = -1;
    // Dem de tim maxlength va maxfrequency
    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int Length = std::strlen(pwd);
        int Frequency = 0;
        // Dem so lan xuat hien cua password
        for (int j = 0; j < num_pwds; ++j) {
            if (std::strcmp(pwd, arr_pwds[j]) == 0) {
                Frequency++;
            }
        }
        //Update maxlength va maxfrequency
        if (Frequency > MaxFrequency || (Frequency == MaxFrequency && Length > MaxLength)) {
            MaxFrequency = Frequency;
            MaxLength = Length;
            Password = i;
        }
    }
    return Password;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////