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
    if (E1 < 0 || E1 > 99) return -99;
    if (E1 <= 3)
    {
        switch (E1)
        {
        case 0: EXP2 += 29; break;
        case 1: EXP2 += 45; break;
        case 2: EXP2 += 75; break;
        case 3: EXP2 += 149; break;
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0 ) EXP1 += std::ceil(double(D / 200.0));
        else EXP1 -= std::floor(double(D / 100.0));
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 > 600) EXP2 = 600; 
    }
    else
    {
        if (E1 <= 19) EXP2 += std::ceil(double(E1 / 4.0)) + 19;
        if (E1 > 19 && E1 <= 49) EXP2 += std::ceil(double(E1 / 9.0)) + 21;
        if (E1 > 49 && E1 <= 65) EXP2 += std::ceil(double(E1 / 16.0)) + 17;
        if (E1 > 65 && E1 <= 79)
        {
            EXP2 += std::ceil(double(E1 / 4.0)) + 19;
            if (EXP2 > 200) EXP2 += std::ceil(double(E1 / 9.0)) + 21;
        }
        if (E1 > 79)
        {
            EXP2 += std::ceil(double(E1 / 4.0)) + std::ceil(double(E1 / 9.0)) + 40;
            if ( EXP2 > 400)
            {
                EXP2 += std::ceil(double (E1 / 16.0)) + 17;
                EXP2 = std::ceil(double(EXP2 * 1.15));
            }
        }
        EXP1 -= E1;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
    }
    return EXP1 + EXP2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    int P1, P2, P3;
    //Road 01
    int S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S) P1 = 100;
    else P1 = double((EXP1 / S + 80) / 1.23);
    //Road 02
    if (E2 % 2 != 0)
    {
        int Event = 0;
        do
        {
            switch (++Event)
            {
            case 0: 
                if (HP1 < 200)
                {
                    HP1 = ceil(double(HP1 * 1.3));
                    M1 -= 150;
                }
                else
                {
                    HP1 = ceil(double(HP1 * 1.1));
                    M1 -= 70;
                }
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                break;
            case 1: 
                if (EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = ceil(double(EXP1 * 1.13));
                if (EXP1 > 600) EXP1 = 600;
                if (M1 < 0) M1 = 0;
                break;
            case 2: 
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = ceil(double(EXP1 * 0.9));
                if (M1 < 0) M1 = 0;
                break;
            }
        } while (M1 != 0 && Event != 3);
    }
    else
    {
        int Spent = 0, Event = 2, Fund = M1 * 0.5;
        while (Spent <= Fund)
        {
            switch (Event++ )
            {
            case 0: 
                if (HP1 < 200)
                {
                    HP1 = ceil(double(HP1 * 1.3));
                    M1 -= 150;
                    Spent += 150;
                }
                else
                {
                    HP1 = ceil(double(HP1 * 1.1));
                    M1 -= 70;
                    Spent += 70;
                }
                if (HP1 > 666) HP1 = 666;
                if (M1 < 0) M1 = 0;
                break;
            case 1: 
                if (EXP1 < 400)
                {
                    EXP1 = ceil(double(EXP1 * 1.13));
                    M1 -= 200;
                    Spent += 200;
                }
                else
                {
                    EXP1 = ceil(double(EXP1 * 1.13));
                    M1 -= 120;
                    Spent += 120;
                }
                if (EXP1 > 600) EXP1 = 600;
                if (M1 < 0) M1 = 0;
                break;
            case 2: 
                if (EXP1 < 300)
                {
                    EXP1 = ceil(double(EXP1 * 0.9));
                    M1 -= 100;
                    Spent += 100;
                }
                else
                {
                    EXP1 = ceil(double(EXP1 * 0.9));
                    M1 -= 120;
                    Spent += 120;
                }
                if (M1 < 0) M1 = 0;
                
            }
        }
    }
    HP1 = ceil(double(HP1 * 0.83));
    EXP1 = ceil(double(EXP1 * 1.17));
    S = pow(round(sqrt(EXP1)), 2);
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 >= S) P2 = 100;
    else P2 = double((EXP1 / S + 80) / 1.23);
    //Road 03
    int i = (E2 / 10 + E2 % 10) % 10;
    int probability[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    P3 = probability[i];
    if (P1 == 100 && P2 == 100 && P3 == 100) 
        EXP1 = ceil(double(EXP1 * 0.75));
    int P = double((P1 + P2 + P3) / 3);
    if (P < 50)
    {
        HP1 = ceil(double(HP1 * 0.85));
        EXP1 = ceil(double(EXP1 * 1.15));
    }
    else
    {
        HP1 = ceil(double(HP1 * 0.9));
        EXP1 = ceil(double(EXP1 * 1.2));
    }
    if (EXP1 > 600) EXP1 = 600;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    const int size = 10;
    int Taxi[size][size] = {};
    int Sherlock[size][size] = {};
    int Left[19] = {};
    int Right[19] = {};
    int x = 0, y = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            Left[i - j + 9] = std::max(Left[i - j + 9], Taxi[i][j]);
            Right[i + j] = std::max(Right[i + j], Taxi[i][j]);

            if (Taxi[i][j] > E3 * 2) {
                ++x;
            }
            if (Taxi[i][j] < -E3) {
                ++y;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Sherlock[i][j] = std::abs(std::max(Left[i - j + 9], Right[i + j]));
        }
    }

    while (x > 9) {
        x = x / 10 + x % 10;
    }
    while (y > 9) {
        y = y / 10 + y % 10;
    }

    if (std::abs(Taxi[x][y]) > Sherlock[x][y]) {
        EXP1 = std::ceil(EXP1 * 0.88);
        HP1 = std::ceil(HP1 * 0.90);
        EXP2 = std::ceil(EXP2 * 0.88);
        HP2 = std::ceil(HP2 * 0.90);
        return Taxi[x][y];
    }
    else {
        EXP1 = std::ceil(EXP1 * 1.12);
        HP1 = std::ceil(HP1 * 1.10);
        EXP2 = std::ceil(EXP2 * 1.12);
        HP2 = std::ceil(HP2 * 1.10);

        EXP1 = std::min(EXP1, 600);
        HP1 = std::min(HP1, 666);
        EXP2 = std::min(EXP2, 600);
        HP2 = std::min(HP2, 666);

        return Sherlock[x][y];
    }
}


// Task 4
int checkPassword(const char* password, const char* email) {
    int passwordLength = strlen(password);
    char emailV[101];
    int emailVLength = 0;

    while (email[emailVLength] != '@') {
        emailV[emailVLength] = email[emailVLength];
        emailVLength++;
    }
    emailV[emailVLength] = '\0';

    if (passwordLength < 8) return -1;
    if (passwordLength > 20) return -2;

    bool SpecialChar = false;
    for (int i = 0; i < passwordLength; i++) {
        if (password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$' || password[i] == '!') {
            SpecialChar = true;
            break;
        }
    }
    if (!SpecialChar) return -5;

    for (int i = 0; i < passwordLength - emailVLength + 1; i++) {
        if (strncmp(password + i, emailV, emailVLength) == 0) {
            return -(300 + i);
        }
    }

    for (int i = 0; i < passwordLength - 2; i++) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
            return -(400 + i);
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) 
{
    int maxCount = 0, maxLength = 0, index = -99;

    for (int i = 0; i < num_pwds; i++) 
    {
        int currentCount = 0;
        for (int j = 0; j < num_pwds; j++) 
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                currentCount++;
            }
        }
        int currentLength = strlen(arr_pwds[i]);
        if (currentCount > maxCount || (currentCount == maxCount && currentLength > maxLength)) 
        {
            maxCount = currentCount;
            maxLength = currentLength;
            index = i;
        }
    }

    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////