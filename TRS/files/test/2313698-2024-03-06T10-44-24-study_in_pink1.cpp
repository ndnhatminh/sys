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
int Experience_Balance(int exp) {
    if (exp < 0) {
        return 0;
    }
    else if (exp > 600) {
        return 600;
    }
    else {
        return exp;
    }
}
int HP_Balance(int hp) {
    if (hp < 0) {
        return 0;
    }
    else if (hp > 666) {
        return 666;
    }
    else {
        return hp;
    }
}

int Money_Balance(int m) {
    if (m < 0) {
        return 0;
    }
    else if (m > 3000) {
        return 3000;
    }
    else {
        return m;
    }
}


int abs(int x) {
    if (x > 0) return x;
    else return -x;
}

int degrade(int x) {
    while (x >= 10)
    {
        x = ((x % 10) + (x / 10 % 10));
    }
    return x;
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {

    if (E1 > 99 || E1 < 0) 
        return -99; 
    

    EXP1 = Experience_Balance(EXP1);
    EXP2 = Experience_Balance(EXP2);

    if (E1 >= 0 && E1 <= 3) {
        switch (E1) {
        case(0): EXP2 += 29; EXP2 = Experience_Balance(EXP2); break;
        case(1): EXP2 += 45; EXP2 = Experience_Balance(EXP2); break;
        case(2): EXP2 += 75; EXP2 = Experience_Balance(EXP2); break;
        case(3): EXP2 = EXP2 + 29 + 45 + 75; EXP2 = Experience_Balance(EXP2); break;
        default: break;
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 += (D + 199) / 200;                                          // phuong phap lam tron len: so bi chia += so chia -1
        else            EXP1 -= (D) / 100;
        EXP1 = Experience_Balance(EXP1);
    }


    else {
        if (E1 >= 4 && E1 <= 19) { EXP2 += (E1 + 3) / 4 + 19; }
        else if (E1 >= 20 && E1 <= 49) { EXP2 += ((E1 + 8) / 9) + 21; EXP2 = Experience_Balance(EXP2); }
        else if (E1 >= 50 && E1 <= 65) { EXP2 += ((E1 + 15) / 16) + 17; EXP2 = Experience_Balance(EXP2); }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += (E1 + 3) / 4 + 19;
            if (EXP2 > 200)  EXP2 += ((E1 + 8) / 9) + 21; EXP2 = Experience_Balance(EXP2);
        }

        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ((E1 + 3) / 4) + 19;
            EXP2 += ((E1 + 8) / 9) + 21;
            EXP2 = Experience_Balance(EXP2);
            if (EXP2 > 400) {
                EXP2 += ((E1 + 15) / 16) + 17;
                EXP2 += ((EXP2 * 15) + 99) / 100;
                EXP2 = Experience_Balance(EXP2);
            }
        }
        EXP1 -= E1;
    }
    EXP1 = Experience_Balance(EXP1);
    EXP2 = Experience_Balance(EXP2);

    return EXP1 + EXP2;

}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 > 99 || E2 < 0) return -99;
    EXP1 = Experience_Balance(EXP1);
    HP1 = HP_Balance(HP1);
    M1 = Money_Balance(M1);
    int S = 0, M = (M1 + 1) / 2;
    double P1, P2;


    // con duong 1 //
    int min = INT_MAX;
    for (int i = 1; i <= 600; i++) {

        int CheckSquare = sqrt(i);
        if (CheckSquare * CheckSquare == i)
        {
            int NumberDifference = abs(EXP1 - i);
            if (NumberDifference < min) {
                min = NumberDifference;
                S = i;
            }
        }
    }
    if (EXP1 < S) { P1 = ((EXP1 / S + 80) * 100 + 122) / 123; }

    else { P1 = 100; }
    // con duong 2 //
    if (E2 % 2 != 0) {
        while (M1 > M) {
            // hanh dong 1
            if (HP1 < 200) {
                HP1 += (HP1 * 30 + 99) / 100; M1 -= 150; ;
            }
            else {
                HP1 += (HP1 * 10 + 99) / 100; M1 -= 70; ;
            }
            M1 = Money_Balance(M1);
            if (M1 < M) break;
            // hanh dong 2
            if (EXP1 < 400) { M1 -= 200; }
            else { M1 -= 120; }

            M1 = Money_Balance(M1);
            EXP1 += ((EXP1 * 13) + 99) / 100;
            if (M1 < M) break;
            // hanh dong 3
            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }

            M1 = Money_Balance(M1);
            EXP1 -= (EXP1 * 10) / 100;
            if (M1 < M) break;
        }
        HP1 -= (HP1 * 17) / 100;
        EXP1 += (EXP1 * 17 + 99) / 100;
        EXP1 = Experience_Balance(EXP1);
        HP1 = HP_Balance(HP1);
    }
    else {
        // hanh dong 1
        if (HP1 < 200) {
            HP1 += (HP1 * 30 + 99) / 100; HP1 = HP_Balance(HP1); M1 -= 150; M1 = Money_Balance(M1);
        }
        else {
            HP1 += (HP1 * 10 + 99) / 100; HP1 = HP_Balance(HP1); M1 -= 70; M1 = Money_Balance(M1);
        }
        if (M1 < 0) {
            M = 0; EXP1 += ((EXP1 * 13) + 99) / 100; HP1 = HP_Balance(HP1); EXP1 -= (EXP1 * 10) / 100; HP1 = HP_Balance(HP1); goto bankrupt;
        }
        // hanh dong 2
        if (EXP1 < 400) M1 -= 200;
        else M1 -= 120;
        M1 = Money_Balance(M1);
        EXP1 += ((EXP1 * 13) + 99) / 100;
        if (M1 < 0) {
            M = 0; EXP1 -= (EXP1 * 10) / 100; HP1 = HP_Balance(HP1); goto bankrupt;
        }
        // hanh dong 3
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        M1 = Money_Balance(M1);
        EXP1 -= (EXP1 * 10) / 100; HP1 = HP_Balance(HP1);
        if (M1 < 0) {
            M = 0; goto bankrupt;
        }
        HP1 -= (HP1 * 17) / 100;
        EXP1 += (EXP1 * 17 + 99) / 100;
        EXP1 = Experience_Balance(EXP1);
        HP1 = HP_Balance(HP1);
    }

bankrupt: if (M1 < 0) {
    HP1 -= (HP1 * 17) / 100;
    EXP1 += (EXP1 * 17 + 99) / 100;
    EXP1 = Experience_Balance(EXP1);
    HP1 = HP_Balance(HP1);
}
min = INT_MAX;
for (int i = 1; i <= 600; i++) {

    int CheckSquare = sqrt(i);
    if (CheckSquare * CheckSquare == i)
    {
        int NumberDifference = abs(EXP1 - i);
        if (NumberDifference < min) {
            min = NumberDifference;
            S = i;
        }
    }
}
if (EXP1 < S) { P2 = ((EXP1 / S + 80) * 100 + 122) / 123; }

else { P2 = 100; }

// con duong 3//

int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 }, i;

if (E2 < 10) i = E2;
else i = (E2 % 10 + (E2 / 10) % 100) % 10;
int P3 = P[i];

// end 3 con duong //
if (P1 == 100 && P2 == 100 && P3 == 100) {
    EXP1 -= (EXP1 * 25) / 100;
    EXP1 = Experience_Balance(EXP1);
    HP1 = HP_Balance(HP1);

}
else {
    int PE = ((P1 + P2 + P3) + 2) / 3;
    if (PE < 50) {
        HP1 -= (HP1 * 15) / 100; EXP1 += (EXP1 * 15 + 99) / 100;
        EXP1 = Experience_Balance(EXP1);
        HP1 = HP_Balance(HP1);
    }
    else {
        HP1 -= (HP1 * 10) / 100; EXP1 += (EXP1 * 20 + 99) / 100;
        EXP1 = Experience_Balance(EXP1);
        HP1 = HP_Balance(HP1);
    }
}

return HP1 + EXP1 + M1;

}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 > 99 || E3 < 0) return -99;  
    EXP1 = Experience_Balance(EXP1);
    EXP2 = Experience_Balance(EXP2);
    HP1 = HP_Balance(HP1);
    HP2 = HP_Balance(HP2);
    int x = 0, y = 0;
    const int row = 10;
    const int col = 10;

    int Matrix[row][col];
    for (int i = 0; i < row; i++) {                        // tao ma tran
        for (int j = 0; j < col; j++) {
            Matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Matrix[i][j] > (E3 * 2)) x++;
            if (Matrix[i][j] < (-E3)) y++;
        }
    }
    int i = degrade(x), j = degrade(y);
    int k = i, l = j, max = Matrix[i][j];
    // tim max //
    while (k < row && l < col) {
        if (Matrix[k][l] > max)
            max = Matrix[k][l];

        k++; l++;
    }
    k = i, l = j;
    while (k >= 0 && l >= 0) {
        if (Matrix[k][l] > max)
            max = Matrix[k][l];

        k--; l--;
    }
    k = i, l = j;
    while (k >= 0 && l < col) {
        if (Matrix[k][l] > max)
            max = Matrix[k][l];

        k--; l++;
    }
    k = i, l = j;
    while (l >= 0 && k < col) {
        if (Matrix[k][l] > max)
            max = Matrix[k][l];

        k++; l--;
    }

    if (abs(Matrix[i][j]) <= abs(max))
    {
        EXP1 += (EXP1 * 12 + 99) / 100;
        EXP2 += (EXP2 * 12 + 99) / 100;
        HP1 += (HP1 * 10 + 99) / 100;
        HP2 += (HP2 * 10 + 99) / 100;
        EXP1 = Experience_Balance(EXP1);
        EXP2 = Experience_Balance(EXP2);
        HP1 = HP_Balance(HP1);
        HP2 = HP_Balance(HP2);
        return max;
    }
    else {
        EXP1 -= (EXP1 * 12) / 100;
        EXP2 -= (EXP2 * 12) / 100;
        HP1 -= (HP1 * 10) / 100;
        HP2 -= (HP2 * 10) / 100;
        EXP1 = Experience_Balance(EXP1);
        EXP2 = Experience_Balance(EXP2);
        HP1 = HP_Balance(HP1);
        HP2 = HP_Balance(HP2);
        return Matrix[i][j];
    }
 
}

// Task 4
int checkPassword(const char* s, const char* email) {
  
    string convert_s(s);
    string convert_email(email);

    const char* No_Avalable_Chars = "^&*()-_=+{}[]|;:'\",.<>?\\/`~";
    const char* specialChars = "!@#$%";

    int se_length = 0;
    size_t find_se = convert_email.find('@');
    if (find_se != string::npos) se_length = static_cast<int>(find_se);
    string se = convert_email.substr(0, se_length);

    size_t find_se_s = convert_s.find(se);
    int find_se_s_int = 0;
    if (find_se_s != string::npos) find_se_s_int = static_cast<int>(find_se_s);

    bool is_more_than_2_same_character = false;
    int location_same;
    for (int i = 0; i < convert_email.length() - 2; ++i) {
        if (convert_email[i] == convert_email[i + 1] && convert_email[i] == convert_email[i + 2]) {
            is_more_than_2_same_character = true;
            location_same = i;
            break;
        }
    }

    if (!strpbrk(s, No_Avalable_Chars) && !(strlen(s) < 8) && !(strlen(s) > 20) && find_se_s == string::npos && !is_more_than_2_same_character && strpbrk(s, specialChars)) return -10;
    else if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;
    else if (find_se_s != string::npos) return -(300 + find_se_s_int);
    else if (is_more_than_2_same_character) return -(400 + location_same);
    else if (!strpbrk(s, specialChars)) return -5;
    else if (strpbrk(s, No_Avalable_Chars)) return strpbrk(s, No_Avalable_Chars) - s;

    return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) { 
    const int Max_num_pwds = 30;
    int Correct_Password[Max_num_pwds] = { 0 };
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds[j] == arr_pwds[i]) {
                Correct_Password[i]++;
            }
        }
    }

    int Max_Correct_Password = 0, Max_Length = 0, Frist_Position = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (Correct_Password[i] > Max_Correct_Password || ((Correct_Password[i] == Max_Correct_Password) && (strlen(arr_pwds[i]) > Max_Length))) {

            Max_Correct_Password = Correct_Password[i];
            Frist_Position = i;
            Max_Length = strlen(arr_pwds[i]);
        }
    }
    
    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == arr_pwds[Frist_Position]) {
            
            return i;
        }
    }
        return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////