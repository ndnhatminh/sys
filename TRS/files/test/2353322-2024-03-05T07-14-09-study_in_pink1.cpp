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
int firstMeet(int &EXP1, int &EXP2, int E1) {
  if (E1 >= 0 && E1 <= 3) {
    int expWatson = 0;
    switch (E1) {
      case 1:
        expWatson += 29;
        break;
      case 2:
        expWatson += 45;
        break;
      case 3:
        expWatson += 75;
        break;
    }
    expWatson += (E1 * 3 + EXP1 * 7) / 200;
    EXP1 = (E1 * 3 + EXP1 * 7) % 2 == 0 ? EXP1 + expWatson : EXP1 - expWatson;
    EXP2 += expWatson;
    return EXP1 + EXP2;
  }

  if (E1 >= 4 && E1 <= 99) {
    int expWatson = 0;
    switch (E1 / 10) {
      case 0:
        expWatson += (E1 / 4 + 19);
        break;
      case 2:
        expWatson += (E1 / 9 + 21);
        break;
      case 5:
        expWatson += (E1 / 16 + 17);
        break;
      case 6:
        expWatson += (E1 / 4 + 19);
        if (EXP2 > 200) {
          expWatson += (E1 / 9 + 21);
        }
        break;
      case 8:
        expWatson += (E1 / 4 + 19);
        if (EXP2 > 400) {
          expWatson += (E1 / 9 + 21);
          expWatson += (E1 / 16 + 17);
        }
        break;
    }
    expWatson *= 1.15;
    expWatson = expWatson > 600 ? 600 : expWatson;
    EXP1 -= E1;
    EXP2 = expWatson;
    return EXP1 + EXP2;
  }

  return -99;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // Con đường 01
    int S = sqrt(EXP1);
    double P1;
    if (EXP1 >= S) {
        P1 = 100;
    } else {
        P1 = ceil((EXP1 / S + 80) / 123.0); // Làm tròn lên với ceil()
    }
    
    // Con đường 02
    if (HP1 < 200) {
        HP1 += HP1 * 0.3; // Tăng HP1 lên 30%
        M1 -= 150;
    } else {
        HP1 += HP1 * 0.1; // Tăng HP1 lên 10%
        M1 -= 70;
    }
    
    if (EXP1 < 400) {
        M1 -= 200; // Chi phí thuê taxi
        EXP1 += 13;
    } else {
        M1 -= 120; // Chi phí thuê xe ngựa
    }
    
    int m;
    if (EXP1 < 300) {
        m = 100;
        EXP1 -= 10;
    } else {
        m = 120;
    }
    
    if (E2 % 2 == 1) {
        // Nếu E2 là số lẻ
        while (M1 > M1 * 0.5) {
            if (HP1 < 200) {
                HP1 -= HP1 * 0.17;
                EXP1 += EXP1 * 0.17;
            } else {
                HP1 -= HP1 * 0.17;
                EXP1 += EXP1 * 0.17;
            }
        }
    } else {
        // Nếu E2 là số chẵn
        if (M1 < 200) {
            HP1 -= HP1 * 0.17;
            EXP1 += EXP1 * 0.17;
        } else {
            HP1 -= HP1 * 0.17;
            EXP1 += EXP1 * 0.17;
        }
    }
    
    double P2 = ceil((EXP1 / S + 80) / 123.0); // Làm tròn lên với ceil()
    
    // Con đường 03
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    double P3 = P[i];
    
    // Tính trung bình cộng
    double average = (P1 + P2 + P3) / 3;
    
    // Cập nhật EXP1 và HP1
    if (average < 50) {
        HP1 -= HP1 * 0.15;
        EXP1 += EXP1 * 0.15;
    } else {
        HP1 -= HP1 * 0.10;
        EXP1 += EXP1 * 0.20;
    }
    
    // Trả về kết quả
    return HP1 + EXP1 + M1;
}

// Task 3
tuple<int, int, int, int, int> chaseTaxi(int HP1, int EXP1, int HP2, int EXP2, int E3) {
    const int SIZE = 10;
    int taxiMap[SIZE][SIZE] = {0};
    int sherlockWatsonMap[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int maxDiagonal = 0;
            int k = i, l = j;
            while (k >= 0 && l >= 0) {
                maxDiagonal = max(maxDiagonal, taxiMap[k][l]);
                k--;
                l--;
            }
            k = i + 1; l = j + 1;
            while (k < SIZE && l < SIZE) {
                maxDiagonal = max(maxDiagonal, taxiMap[k][l]);
                k++;
                l++;
            }
            k = i; l = j;
            while (k >= 0 && l < SIZE) {
                maxDiagonal = max(maxDiagonal, taxiMap[k][l]);
                k--;
                l++;
            }
            k = i + 1; l = j - 1;
            while (k < SIZE && l >= 0) {
                maxDiagonal = max(maxDiagonal, taxiMap[k][l]);
                k++;
                l--;
            }
            sherlockWatsonMap[i][j] = abs(maxDiagonal);
        }
    }

    int i = 0, j = 0;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (taxiMap[row][col] > E3 * 2) i++;
            if (taxiMap[row][col] < -E3) j++;
        }
    }
    while (i > 9) i = i / 10 + i % 10;
    while (j > 9) j = j / 10 + j % 10;

    bool taxiCaught = abs(taxiMap[i][j]) <= abs(sherlockWatsonMap[i][j]);

    if (taxiCaught) {
        EXP1 = round(EXP1 * 1.12); // Increase EXP1 by 12%
        HP1 = round(HP1 * 1.1); // Increase HP1 by 10%
        EXP2 = round(EXP2 * 1.12); // Increase EXP2 by 12%
        HP2 = round(HP2 * 1.1); // Increase HP2 by 10%
    } else {
        EXP1 = round(EXP1 * 0.88); // Decrease EXP1 by 12%
        HP1 = round(HP1 * 0.9); // Decrease HP1 by 10%
        EXP2 = round(EXP2 * 0.88); // Decrease EXP2 by 12%
        HP2 = round(HP2 * 0.9); // Decrease HP2 by 10%
        
    }

    return make_tuple(HP1, EXP1, HP2, EXP2, taxiCaught ? sherlockWatsonMap[i][j] : taxiMap[i][j]);
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////