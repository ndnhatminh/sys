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

void adjustEXP(int &EXP1, int &EXP2) {
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    else if (EXP2 < 0) EXP2 = 0;
}

void adjustHP(int &HP1, int &HP2) {
    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (HP2 > 666) HP2 = 666;
    else if (HP2 < 0) HP2 = 0;
}

void adjustM(int &M1, int &M2) {
     if (M1 > 3000) M1 = 3000;
    else if (M1 < 0) M1 = 0;
    if (M2 > 3000) M2 = 3000;
    else if (M2 < 0) M2 = 0;
}
// Task 1
void firstMeet_Case1(int &EXP1, int &EXP2, int E1) {
    switch(E1){
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 149;
            break;
    }
    int D;
    D = E1 * 3 + EXP1 * 7;
    if (D%2 == 0)
        EXP1 = ceil(EXP1 + D / 200.0);
    else
        EXP1 = ceil(EXP1 - D / 100.0);

    adjustEXP(EXP1, EXP2);
}

void firstMeet_Case2(int &EXP1, int &EXP2, int E1) {
    if (E1 >= 4 && E1 <= 19){
            EXP2 += ceil(E1/4.0 + 19);
        }
        else if (E1 <= 49) {
            EXP2 += ceil(E1/9.0 + 21);
        }
        else if (E1 <= 65) {
            EXP2 += ceil(E1/16.0 + 17);
        }
        else if (E1 <= 79) {
            EXP2 += ceil(E1/4.0 + 19);
            if (EXP2 >= 200){
               EXP2 += ceil(E1/9.0 + 21); 
            }
        }
        else {
            EXP2 += ceil(E1/4.0 + 19);
            EXP2 += ceil(E1/9.0 + 21);
            if (EXP2 >= 400){
                EXP2 += ceil(E1/16.0 + 17);
                EXP2 += ceil(EXP2 * 0.15);
            }
        }
        EXP1 -= E1;
    adjustEXP(EXP1, EXP2);
}

int firstMeet(int &EXP1, int &EXP2, int E1) {
    if (E1 <= 3 && E1 >= 0) firstMeet_Case1(EXP1, EXP2, E1);
    else if (E1 >= 4 && E1 <= 99) firstMeet_Case2(EXP1, EXP2, E1);
    else return -99;
    return EXP1 + EXP2;
}

// Task 2
int SoChinhPhuongGanNhat(int X) {
    int N = sqrt(X);
    int Sn = floor(N);
    int S1 = Sn * Sn;
    int S2 = (Sn + 1) * (Sn + 1);
    if (abs(S1 - X) < abs(S2 - X)) return S1;
    else return S2;
    
}

double traceLuggage_Street1(int EXP1) {
    int S = SoChinhPhuongGanNhat(EXP1);
    if (EXP1 >= S) return 100;
    else return ((EXP1 / S + 80) / 123.0) * 100;
}

double traceLuggage_Street2(int &HP1, int &EXP1, int &M1, int E2) {
    double M = M1 * 0.5;
    while (true)
    {
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 13.0 / 10);
            M1 -= 150;
        } else if (HP1 >= 200) {
            HP1 = ceil(HP1 * 11.0 / 10);
            M1 -= 70;
        }
        adjustHP(HP1, HP1); 
        adjustM(M1, M1);    
        if (E2%2 == 1 && M1 < M) {
            EXP1 = ceil(EXP1 * 11.7 / 10);
            HP1 = ceil(HP1 * 8.3 / 10);
            adjustEXP(EXP1, EXP1); 
            adjustHP(HP1, HP1);   
            break;
        } else if (E2%2 == 0 && M1 == 0) {
            EXP1 = ceil(EXP1 * 11.7 / 10);
            HP1 = ceil(HP1 * 8.3 / 10);
            adjustEXP(EXP1, EXP1); 
            adjustHP(HP1, HP1);   
            break;
        }

        
        if (EXP1 < 400) M1 -= 200;
        else if (EXP1 >= 400) M1 -= 120;
        EXP1 = ceil(EXP1 * 11.3 / 10);
        adjustEXP(EXP1, EXP1); 
        adjustM(M1, M1);       
        if (E2%2 == 1 && M1 < M) {
            EXP1 = ceil(EXP1 * 11.7 / 10);
            HP1 = ceil(HP1 * 8.3 / 10);
            adjustEXP(EXP1, EXP1); 
            adjustHP(HP1, HP1);    
            break;
        } else if (E2%2 == 0 && M1 == 0) {
            EXP1 = ceil(EXP1 * 11.7 / 10);
            HP1 = ceil(HP1 * 8.3 / 10);
            adjustEXP(EXP1, EXP1); 
            adjustHP(HP1, HP1);    
            break;
        }

        
        if (EXP1 < 300) M1 -= 100;
        else if (EXP1 >= 300) M1 -= 120;
        EXP1 = ceil(EXP1 * 9.0 / 10);
        adjustEXP(EXP1, EXP1); 
        adjustM(M1, M1);      
        if (E2%2 == 1 && M1 <= M) {
            EXP1 = ceil(EXP1 * 11.7 / 10);
            HP1 = ceil(HP1 * 8.3 / 10);
            adjustEXP(EXP1, EXP1); 
            adjustHP(HP1, HP1);    
            break;
        } else if (E2%2 == 0) {
            EXP1 = ceil(EXP1 * 11.7 / 10);
            HP1 = ceil(HP1 * 8.3 / 10);
            adjustEXP(EXP1, EXP1); 
            adjustHP(HP1, HP1); 
            break;
        }
    }
    return traceLuggage_Street1(EXP1);
}

double traceLuggage_Street3(int E2) {
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    return P[i];
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;
    double P1 = traceLuggage_Street1(EXP1);
    double P2 = traceLuggage_Street2(HP1, EXP1, M1, E2);
    double P3 = traceLuggage_Street3(E2);

    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = ceil(EXP1 * 7.5 / 10);
    else {
        double P = (P1 + P2 + P3) / 3;
        if (P < 50) {
            HP1 = ceil(HP1 * 8.5 / 10);
            EXP1 = ceil(EXP1 * 11.5 / 10 );
        } else {
            HP1 = ceil(HP1 * 9.0 / 10);
            EXP1 = ceil(EXP1 * 12.0 / 10);
        }
    }
    adjustEXP(EXP1, EXP1); 
    adjustHP(HP1, HP1);    

    return HP1 + EXP1 + M1;
}

// Task 3
int TinhDiem(int E3, int i, int j) {
    return ((E3 * j) + (i * 2)) * (i - j);
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
        return -99;

    int DiemTaxi[10][10] = {0};
    int DiemSherlock[10][10] = {0};
    int DiemToiDa = 0;


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            DiemTaxi[i][j] = TinhDiem(E3, i, j);
        }
    }


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int DuongCheoTrai = DiemTaxi[i][j];
            for (int k = 0; k < std::min(i, j); ++k) {
                DuongCheoTrai = std::max(DuongCheoTrai, DiemTaxi[i - k][j - k]);
            }

            int DuongCheoPhai = DiemTaxi[i][j];
            for (int k = 0; k < std::min(10 - i, j); ++k) {
                DuongCheoPhai = std::max(DuongCheoPhai, DiemTaxi[i + k][j - k]);
            }

            DiemSherlock[i][j] = std::max(DuongCheoTrai, DuongCheoPhai);
            DiemSherlock[i][j] = std::abs(DiemSherlock[i][j]);
        }
    }


    int I = 0, J = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (DiemTaxi[i][j] > E3 * 2) I++;
            if (DiemTaxi[i][j] < -E3) J++;
        }
    }


    while (I >= 10 || J >= 10) {
        if (I >= 10) I = I / 10 + I % 10;
        if (J >= 10) J = J / 10 + J % 10;
    }


    if (std::abs(DiemTaxi[I][J]) > DiemSherlock[I][J]) {
        EXP1 = ceilf(EXP1 * 8.8 / 10);
        HP1 = ceilf(HP1 * 9.0 / 10);
        EXP2 = ceilf(EXP2 * 8.8 / 10);
        HP2 = ceilf(HP2 * 9.0 / 10);
        DiemToiDa = DiemTaxi[I][J];
    } else {
        EXP1 = ceilf(EXP1 * 11.2 / 10);
        HP1 = ceilf(HP1 * 11.0 / 10);
        EXP2 = ceilf(EXP2 * 11.2 / 10);
        HP2 = ceilf(HP2 * 11.0 / 10);
        DiemToiDa = DiemSherlock[I][J];
    }
    adjustEXP(EXP1, EXP2); 
    adjustHP(HP1, HP2);    
    return DiemToiDa;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    std::string password(s);
    std::string userEmail(email);
    std::size_t pos = userEmail.find('@');
    std::string se = userEmail.substr(0, pos); 


    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;

    if (password.find(se) != std::string::npos) return -(300 + password.find(se));

    for (int i = 0; i < password.length() - 2; i++) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2])
            return -(400 + i);
    }


    std::string KiTuDacBiet = "@#%$!";
    bool chuaKiTuDacBiet = false;
    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (KiTuDacBiet.find(c) != std::string::npos) {
            chuaKiTuDacBiet = true;
            break;
        }
    }

    if (!chuaKiTuDacBiet)
        return -5;

    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (!std::isdigit(c) && !std::isalpha(c) && KiTuDacBiet.find(c) == std::string::npos)
            return password.find(c);
    }

    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int TanSoMax = 0, DoDaiMax = 0, ViTri = 0;
        for (int i = 0; i < num_pwds; ++i) {
            int TanSo = 0, DoDai = std::strlen(arr_pwds[i]);
            for (int j = 0; j < num_pwds; ++j) {
                if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) TanSo++;
            }
            if (TanSo > TanSoMax || (TanSo == TanSoMax && DoDai > DoDaiMax)) {
                TanSoMax = TanSo;
                DoDaiMax = DoDai;
                ViTri = i;
            }
        }
    return ViTri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////