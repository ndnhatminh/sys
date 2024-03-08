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

// Check limits of EXP, HP and M
void checkEXP1Limit (int & exp1) {
    if (exp1 < 0) exp1 = 0;
    else if (exp1 > 600) exp1 = 600;
}

void checkEXP2Limit (int & exp2) {
    if (exp2 < 0) exp2 = 0;
    else if (exp2 > 600) exp2 = 600;
}

void checkHP1Limit(int & HP1) {
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
}

void checkM1Limit(int & M1) {
    if (M1 > 3000) M1 = 3000;
    else if (M1 < 0) M1 = 0;
}

void checkHP2Limit (int & hp2) {
    if (hp2 < 0) hp2 = 0;
    else if (hp2 > 666) hp2 = 666;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkEXP1Limit(exp1);
    checkEXP2Limit(exp2); 
    if (e1 < 0 || e1 > 99) return -99;
    else if (e1 >= 0 && e1 <= 3) { // Case 1 of firstMeet
        switch (e1) {
        case 0: // Info 1
            exp2 += 29;
            break;
        case 1: // Info 2
            exp2 += 45;
            break;
        case 2: // Info 3
            exp2 += 75;
            break;
        case 3: // Info 4
            exp2 += 149;
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = static_cast<int>(ceil(static_cast<double>(exp1) + static_cast<double>(D) / 200.0));
        else exp1 = static_cast<int>(ceil(static_cast<double>(exp1) - static_cast<double>(D) / 100.0));
        checkEXP1Limit(exp1);
        checkEXP2Limit(exp2);
    }
    else if (e1 >= 4 && e1 <= 99) { // Case 2 of firstMeet
        if (e1 >= 4 && e1 <= 19) { // Info 1
            exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 4.0)) + 19;
        }
        else if (e1 >= 20 && e1 <= 49) { // Info 2
            exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 9.0)) + 21;
        }
        else if (e1 >= 50 && e1 <= 65) { // Info 3
            exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 16.0)) + 17;
        }
        else if (e1 >= 66 && e1 <= 79) { // Info 4
            exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 4.0)) + 19;
            if (exp2 > 200) exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 9.0)) + 21;
        }
        else if (e1 >= 80 && e1 <= 99) { // Info 5
            exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 4.0)) + 19;
            exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 9.0)) + 21;
            if (exp2 > 400) {
                exp2 += static_cast<int>(ceil(static_cast<double>(e1) / 16.0)) + 17;
                exp2 = static_cast<int>(ceil(static_cast<double>(exp2) * 1.15));
            }
        }
        checkEXP2Limit(exp2);
        exp1 -= e1;
        checkEXP1Limit(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    float P1, P2, P3;
    checkHP1Limit(HP1);
    checkEXP1Limit(EXP1);
    checkM1Limit(M1);

    int S1 = 0, MinDiff1 = EXP1; // First path
    int i1 = 1, Diff1 = 0;
    while (true) {
        Diff1 = abs(EXP1 - i1 * i1);
        if (Diff1 < MinDiff1) {
            MinDiff1 = Diff1;
            S1 = i1 * i1;
            i1++;
        }
        else break;
    }
    if (EXP1 >= S1) P1 = 1.0;
    else {
        P1 = ((static_cast<double>(EXP1) / static_cast<double>(S1)) + 80.0) / 123.0;
        P1 = round(P1 * 100.0) / 100.0;
    }


    int HalfMoney = static_cast<int>(ceil(static_cast<double>(M1) * 0.5)); // Second path
    if (E2 % 2 == 1) {
        while (true) {
            if (HP1 < 200) {
                HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 1.3));
                checkHP1Limit(HP1);
                M1 -= 150;
                if (M1 < HalfMoney) break;
            }
            else {
                HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 1.1));
                checkHP1Limit(HP1);
                M1 -= 70;
                if (M1 < HalfMoney) break;
            }
            if (EXP1 < 400) {
                EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.13));
                checkEXP1Limit(EXP1);
                M1 -= 200;
                if (M1 < HalfMoney) break;
            }
            else {
                EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.13));
                checkEXP1Limit(EXP1);
                M1 -= 120;
                if (M1 < HalfMoney) break;
            }
            if (EXP1 < 300) {
                EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 0.9));
                M1 -= 100;
                if (M1 < HalfMoney) break;
            }
            else {
                EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 0.9));
                M1 -= 120;
                if (M1 < HalfMoney) break;
            }
        }
    }
    else for (int j = 0; j < 1; j++) {
        if (HP1 < 200) {
            HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 1.3));
            checkHP1Limit(HP1);
            M1 -= 150;
            if (M1 < 0) break;
    }
        else {
            HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 1.1));
            checkHP1Limit(HP1);
            M1 -= 70;
            if (M1 < 0) break;
    }
        if (EXP1 < 400) {
            EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.13));
            checkEXP1Limit(EXP1);
            M1 -= 200;
            if (M1 < 0) break;
    }
        else {
            EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.13));
            checkEXP1Limit(EXP1);
            M1 -= 120;
            if (M1 < 0) break;
    }
        if (EXP1 < 300) {
            EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 0.9));
            M1 -= 100;
        }
        else {
            EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 0.9));
            M1 -= 120;
        }
    }
    checkM1Limit(M1);
    HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 0.83));
    EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.17));
    checkEXP1Limit(EXP1);
    int S2 = 0, MinDiff2 = EXP1;
    int i2 = 1, Diff2 = 0;
    while (true) {
        Diff2 = abs(EXP1 - i2 * i2);
        if (Diff2 < MinDiff2) {
            MinDiff2 = Diff2;
            S2 = i2 * i2;
            i2++;
        }
        else break;
    }
    if (EXP1 >= S2) P2 = 1.0;
    else {
        P2 = (static_cast<double>(EXP1) / static_cast<double>(S2) + 80.0) / 123.0;
        P2 = round(P2 * 100.0) / 100.0;
    }
    
    double arr[10] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11}; // Third path
    if (E2 / 10 == 0) P3 = arr[E2];
    else {
        int TotalDigits = (E2/10) + (E2%10);
        P3 = arr[TotalDigits%10];
    }
    if (P1 == 1.0 && P1 == P2 && P1 == P3) EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 0.75));
    else {
        double AveP = (P1 + P2 + P3) / 3;
        if (AveP < 0.5) {
            HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 0.85));
            EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.15));
            checkEXP1Limit(EXP1);
        }
        else {
            HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 0.9));
            EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.2));
            checkEXP1Limit(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkEXP1Limit(EXP1);
    checkEXP2Limit(EXP2);
    checkHP1Limit(HP1);
    checkHP2Limit(HP2);
    int MapMatrix[10][10];
    int PositiveValuesCount = 0, NegativeValuesCount = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MapMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (MapMatrix[i][j] > 0 && MapMatrix[i][j] > E3 * 2) PositiveValuesCount++;
            else if (MapMatrix[i][j] < 0 && MapMatrix[i][j] < -E3) NegativeValuesCount++;
        }
    }
    int MeetingPointRow = 0, MeetingPointColumn = 0;
    while (true) {
        if (PositiveValuesCount / 10 == 0) {
            MeetingPointRow = PositiveValuesCount;
            break;
        }
        else PositiveValuesCount = (PositiveValuesCount / 10) + (PositiveValuesCount % 10);
    }
    while (true) {
        if (NegativeValuesCount / 10 == 0) {
            MeetingPointColumn = NegativeValuesCount;
            break;
        }
        else NegativeValuesCount = (NegativeValuesCount / 10) + (NegativeValuesCount % 10);
    }
    int TaxiPoint = MapMatrix[MeetingPointRow][MeetingPointColumn];
    int Diagonal = 0, MaxDiagonal = 0;
    int r = 1, c = 1;
    while (true) {
        if ((MeetingPointRow - r < 0) || (MeetingPointColumn - c < 0)) {
            r = 1; c = 1;
            break;
        }
        else Diagonal = MapMatrix[MeetingPointRow - r][MeetingPointColumn - c];
        if (Diagonal > MaxDiagonal) MaxDiagonal = Diagonal;
        ++r;
        ++c;
    }
    while (true) {
        if ((MeetingPointRow + r > 9) || (MeetingPointColumn - c < 0)) {
            r = 1; c = 1;
            break;
        }
        else Diagonal = MapMatrix[MeetingPointRow + r][MeetingPointColumn - c];
        if (Diagonal > MaxDiagonal) MaxDiagonal = Diagonal;
        ++r;
        ++c;
    }
    while (true) {
        if ((MeetingPointRow - r < 0) || (MeetingPointColumn + c > 9)) {
            r = 1; c = 1;
            break;
        }
        else Diagonal = MapMatrix[MeetingPointRow - r][MeetingPointColumn + c];
        if (Diagonal > MaxDiagonal) MaxDiagonal = Diagonal;
        ++r;
        ++c;
    }
    while (true) {
        if ((MeetingPointRow + r > 9) || (MeetingPointColumn + c > 9)) {
            r = 1; c = 1;
            break;
        }
        Diagonal = MapMatrix[MeetingPointRow + r][MeetingPointColumn + c];
        if (Diagonal > MaxDiagonal) MaxDiagonal = Diagonal;
        ++r;
        ++c;
    }
    int FinalResult;
    if (abs(TaxiPoint) > MaxDiagonal) {
        EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 0.88));
        EXP2 = static_cast<int>(ceil(static_cast<double>(EXP2) * 0.88));
        HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 0.9));
        HP2 = static_cast<int>(ceil(static_cast<double>(HP2) * 0.9));
        FinalResult = TaxiPoint;
    }
    else if (abs(TaxiPoint) < MaxDiagonal) {
        EXP1 = static_cast<int>(ceil(static_cast<double>(EXP1) * 1.12));
        EXP2 = static_cast<int>(ceil(static_cast<double>(EXP2) * 1.12));
        HP1 = static_cast<int>(ceil(static_cast<double>(HP1) * 1.1));
        HP2 = static_cast<int>(ceil(static_cast<double>(HP2) * 1.1));
        checkEXP1Limit(EXP1);
        checkEXP2Limit(EXP2);
        checkHP1Limit(HP1);
        checkHP2Limit(HP2);
        FinalResult = MaxDiagonal;
    }
    return FinalResult;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string Password = s;
    string EMail = email;
    string se = EMail.substr(0, EMail.find('@'));

    if (Password.length() < 8) return -1;  // At least 8 characters
    
    else if (Password.length() > 20) return -2;  // 20 characters maximum
    
    else if (Password.length() >= 8 && Password.length() <= 20) {
        if (Password.find(se) != string::npos) {  // Not identical to email name
            int sei = Password.find(se);
            return -300 - sei;
            }  

        for (int i = 0; i < Password.length(); i++) {  // No more than 2 consecutive and identical characters
            if (Password[i] == Password[i+1] && Password[i] == Password[i+2]) {
                int sci = i;
                return -400 - sci;
            }
        }
        
        bool SpecialCharacterAvailable = false;
        for (int i = 0; i < Password.length(); i++) {  // At least 1 special character
            char Char = Password[i];
            if (Char == '@' || Char == '#' || Char == '%' || Char == '$' || Char == '!') SpecialCharacterAvailable = true;
        }
        if (SpecialCharacterAvailable == false) return -5;

        bool InvalidCharacterAvailable = false;  // Must have letters (lowercase and uppercase), numbers and given special characters
        for (int i = 0; i < Password.length(); i++) {
            char Char = Password[i];
            if (!(Char == '@' || Char == '#' || Char == '%' || Char == '$' || Char == '!' || (Char >= '0' && Char <= '9') || (Char >= 'a' && Char <= 'z') || (Char >= 'A' && Char <= 'Z'))) return i;
        }
    }
    
    return -10; // Valid password
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int PasswordCount = 0, MaxCount = 0, FinalResult = 0;
    string PasswordToScan, PasswordToCheck, TempMaxCountPassword;
    for (int i = 0; i < num_pwds; i++) {
        PasswordToScan = arr_pwds[i];
        PasswordCount = 0;
        for (int j = 0; j < num_pwds; j++) {
            PasswordToCheck = arr_pwds[j];
            if (PasswordToScan == PasswordToCheck) ++PasswordCount;
        }
        if (PasswordCount > MaxCount) {
            MaxCount = PasswordCount;
            FinalResult = i;
            TempMaxCountPassword = PasswordToScan;
        }
        else if (PasswordCount == MaxCount) {
            if (TempMaxCountPassword.length() < PasswordToScan.length()) {
                TempMaxCountPassword = PasswordToScan;
                FinalResult = i;
            }
            else continue;
        }
    }
    return FinalResult;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////