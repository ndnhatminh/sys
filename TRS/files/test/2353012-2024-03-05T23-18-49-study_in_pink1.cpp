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
int betceil(double x) {
       if (abs(x - (int)x) < 1e-4)
               return x;
       return x + 1;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
       if (e1 < 0 || e1 > 99) return -99;
        betceil(exp1);
        betceil(exp2);
       if (exp1 > 600) exp1 = 600;
       if (exp1 < 0) exp1 = 0;
       if (exp2 < 0) exp2 = 0;
       if (e1 >= 0 && e1 <= 3) {
              switch(e1) {
                      case 0:
                             exp2 += 29;
                             break;
                      case 1:
                             exp2 += 45;
                             break;
                      case 2:
                             exp2 += 75;
                             break;
                      case 3:
                             exp2 += 149;
                             break;
              }
               int d1 = e1 * 3 + exp1 * 7;
              if (d1 % 2 == 0) exp1 = betceil(exp1 + d1 / 200.0);
              else exp1 = betceil(exp1 - d1 / 100.0);
       }
       if (e1 >=4 && e1 <= 90) {
              if (e1 >= 4 && e1 <= 19) exp2 = betceil(exp2 + e1 / 4.0) + 19;
              if (e1 >= 20 && e1 <= 49) exp2 = betceil(exp2 + e1 / 9.0) + 21; 
              if (e1 >= 50 && e1 <= 65) exp2 = betceil(exp2 + e1 / 16.0) + 17;
              if (e1 >= 66 && e1 <= 79) {
                      exp2 = betceil(exp2 + e1 / 4.0) + 19;
                     if (exp2 > 600) exp2 = 600;
                     if (exp2 > 200) exp2 = betceil(exp2 + e1 / 9.0) + 21;
              }        
              if (e1 >= 80 && e1 <= 99) {
                      exp2 = betceil(exp2 + e1 / 4.0) + 19;
                      exp2 = betceil(exp2 + e1 / 9.0) + 21;
                     if (exp2 > 600) exp2 = 600;
                     if (exp2 > 400) {
                      exp2 = betceil(exp2 + e1 / 16.0) + 17;
                      exp2 = betceil(exp2 * 1.15);   
                     }
              }
               exp1 -= e1;
       }
       if (exp1 < 0) exp1 = 0;
       if (exp2 > 600) exp2 = 600;

       return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
       if (E2 < 0 || E2 > 99) return -99;
        double p1, p2, p3;
       if (EXP1 > 600) EXP1 = 600;
       if (EXP1 < 0)  EXP1 = 0;
        betceil(EXP1);
       if (HP1 > 666) HP1 = 666;
       if (HP1 < 0) HP1 = 0;
        betceil(HP1);
       if (M1 > 3000) M1 = 3000;
       if (M1 < 0) M1 = 0;
        betceil(M1);
        int sqnum = pow(betceil(sqrt(EXP1)),2);
       if (EXP1 >= sqnum) p1 = 1.0;
       else p1 = (EXP1 * 1.0 / sqnum + 80 ) / 123.0;
       if (E2 % 2 == 1) {
               int M0 = M1;
              if (M1 > 0) {
                     while(1) {
                            if (HP1 < 200) {
                                    HP1 = betceil(HP1 * 1.3);
                                    M1 -= 150;
                            }
                            else {
                                    HP1 = betceil(HP1 * 1.1);
                                    M1 -= 70;
                            }
                            if (M1 < 0 ) M1 = 0;
                            if (HP1 > 666) HP1 = 666;
                            if (2 * M1 < M0) break;                        
                            if (EXP1 < 400 ) M1 -= 200;
                            else M1 -= 120;
                             EXP1 = betceil(EXP1 * 1.13);
                            if (EXP1 > 600) EXP1 = 600;
                            if (M1 < 0) M1 = 0;
                            if (2 * M1 < M0) break;
                            if (EXP1 < 300) M1 -= 100;
                            else M1 -= 120;
                             EXP1 = betceil(EXP1 * 0.9);
                            if (M1 < 0) M1 = 0;
                            if (EXP1 < 0) EXP1 = 0;
                            if (2 * M1 < M0) break;
                     }
              }
               HP1 = betceil(HP1 * 0.83);
               EXP1 = betceil(EXP1 * 1.17);
              if (HP1 < 0) HP1 = 0;
              if (EXP1 > 600) EXP1 = 600;
       }
       else {
              if (HP1 < 200) {
                      HP1 = betceil(HP1 * 1.3);
                      M1 -= 150;
              }
              else {
                      HP1 = betceil(HP1 * 1.1);
                      M1 -= 70;
              }
              if (HP1 > 666) HP1 = 666;
              if (M1 < 0) M1 = 0;
              if (M1 > 0) {
                     if (EXP1 < 400 ) M1 -= 200;
                     else M1 -= 120;
                      EXP1 = betceil(EXP1 * 1.13);
                     if (M1 < 0) M1 = 0;
                     if (EXP1 > 600) EXP1 = 600;
                     if (M1 > 0) {
                            if (EXP1 < 300) M1 -= 100;
                            else M1 -= 120;
                             EXP1 = betceil(EXP1 * 0.9);
                            if (M1 < 0) M1 = 0;
                            if (EXP1 < 0) EXP1 = 0;
                     }
              }
               HP1 = betceil(HP1 * 0.83);
               EXP1 = betceil(EXP1 * 1.17);
              if (HP1 < 0) HP1 = 0;
              if (EXP1 > 600) EXP1 = 600;
       }
        sqnum = pow(betceil(sqrt(EXP1)),2);
       if (EXP1 >= sqnum) p2 = 1.0;
       else p2 = (EXP1 * 1.0 / sqnum + 80 ) / 123.0;
        const double P[] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.5, 0.22, 0.83, 0.64, 0.11};
       if (E2 / 10 == 0) p3 = P[E2];
       else p3 = P[((E2 / 10) + (E2 % 10)) % 10];
       if (p1 == 1 && p2 == 1 && p3 == 1) EXP1 = betceil(EXP1 * 0.75);
       else {
               double aver = (p1 + p2 + p3) / 3.0;
              if (aver < 0.5) {
                   HP1 = betceil(HP1 * 0.85);
                   EXP1 = betceil(EXP1 * 1.15);
              }
              else {
                   HP1 = betceil(HP1 * 0.9);
                   EXP1 = betceil(EXP1 * 1.2);
              }
              if (HP1 < 0) HP1 = 0;
              if (EXP1 > 600) EXP1 = 600;
       }                 
        return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
       if (E3 < 0 || E3 > 99) return -99;
        int carp[10][10] , i = 0, j = 0, E32 = 0;
        E32 -= E3;
        int sherp = carp[i][j];
       if (HP1 > 666) HP1 = 666;
       if (HP1 < 0) HP1 = 0;
       if (EXP1 > 600) EXP1 = 600;
       if (EXP1 < 0) EXP1 = 0;
       if (HP2 > 666) HP2 = 666;
       if (HP2 < 0) HP2 = 0;
       if (EXP2 > 600) EXP2 = 600;
       if (EXP2 < 0) EXP2 = 0;
        betceil(HP1);
        betceil(EXP1);
        betceil(HP2);
        betceil(EXP2);
       for (int x = 0; x < 10; x++) {
              for (int y = 0; y < 10; y++) {
                      carp[x][y] = (E3 * y + x * 2) * (x - y);
                     if (carp[x][y] > 2 * E3) i++;
                     if (carp[x][y] < E32) j++;
              }
       }
       while (i > 9) i = i / 10 + i % 10;
       while (j > 9)  j = j / 10 + j % 10;
       for (int r = 1; r < min(i, j); r++ ) 
              if (sherp > carp[i - r][j - r]) sherp = sherp;
              else sherp = carp[i - r][j - r];
       for (int r1 = 1; r1 <= min(9 - i, 9 - j); r1++)
              if (sherp > carp[i + r1][j + r1]) sherp = sherp;
              else sherp = carp[i + r1][j + r1];
       for (int r2 = 1; r2 <= min(i, 9 - j); r2++)\
              if (sherp > carp[i - r2][j + r2]) sherp = sherp;
              else sherp = carp[i - r2][j + r2];
       for (int r3 = 1; r3 <= min(9 - i, j); r3++)
              if (sherp > carp[i + r3][j - r3]) sherp = sherp;
              else sherp = carp[i + r3][j - r3];
       if (sherp >= abs(carp[i][j])) {
               EXP1 = betceil(EXP1 * 1.12);
               HP1 = betceil(HP1 * 1.1);
               EXP2 = betceil(EXP2 * 1.12);
               HP2 = betceil(HP2 * 1.1);
              if (EXP1 > 600) EXP1 = 600;
              if (EXP2 > 600) EXP2 = 600;
              if (HP1 > 666) HP1 = 666;
              if (HP2 > 666) HP2 = 666;
              return sherp;
       }
       else {
               EXP1 = betceil(EXP1 * 0.88);
               HP1 = betceil(HP1 * 0.9);
               EXP2 = betceil(EXP2 * 0.88);
               HP2 = betceil(HP2 * 0.9);
              if (EXP1 < 0) EXP1 = 0;
              if (EXP2 < 0) EXP2 = 0;
              if (HP1 < 0) HP1 = 0;
              if (HP2 < 0) HP2 = 0;
              return carp[i][j];
      }
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