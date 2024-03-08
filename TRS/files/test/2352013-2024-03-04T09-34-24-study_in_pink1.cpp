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

// Redefines ceil function

int ceill(double a){
 int a0 = a;

 if (a < 0) return a0;

 if (abs(a - a0) <= 0.000001) return a0;
  else return (a0+1);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // Calibration
    if ((e1 < 0) || (e1 > 99)) return -99;
    exp1 = min(600, max(exp1, 0));
    exp2 = min(600, max(exp2, 0));

    if (e1 < 4)
    { switch (e1){
        case 3:
            exp2 += 74;
        case 2:
            exp2 += 30;
        case 1:
            exp2 += 16;
        default:
            exp2 += 29;
            exp2 = min(exp2, 600);
        };

      int D = 3*e1 + 7*exp1;

      if (D % 2) {exp1 -= D/100;}
      else {
            exp1 += ceill(D*1.0/200);
            exp1 = min(exp1, 600);
        }
    }
    else
    { if (e1 < 20) {exp2 += 19 + ceill(e1*0.25);}
      else if (e1 < 50) {exp2 += 21 + ceill(e1*1.0/9);}
        else if (e1 < 66) {exp2 += 17 + ceill(e1*1.0/16);}
         else if (e1 < 80)
            { exp2 += 19 + ceill(e1*1.0/4);
              if (exp2 > 200) {exp2 += 21 + ceill(e1*1.0/9);}
            }
      else
        { exp2 += 40 + ceill(e1*1.0/4) + ceill(e1*1.0/9);
          if (exp2 > 400)
            { exp2 += 17 + ceill(e1*1.0/16);
              exp2 = ceill(1.15*exp2);
            }
        }

      exp1 -= e1;
      exp1 = max(exp1, 0);
      exp2 = min(exp2, 600);
    }

    return exp1 + exp2;
}

// Task 2
bool road2(int & HP1, int & EXP1, int & M1, int Mbreak) {
 if (!M1) return 0;

 // event 1
 if (HP1 < 200) {HP1 = ceill(1.3*HP1); M1 -= 150;}
  else {HP1 = ceill(1.1*HP1); M1 -= 70;}
 if (M1 <= Mbreak) return 0;

 // event 2
 if (EXP1 < 400) M1 -= 200;
  else M1 -= 120;
 EXP1 = min(ceill(1.13*EXP1), 600);
 if (M1 <= Mbreak) return 0;

 // event 3
 if (EXP1 < 300) M1 -= 100;
  else M1 -= 120;
 EXP1 = ceill(0.9*EXP1);
 if (M1 <= Mbreak) return 0;

 return 1;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // Calibration
    if ((E2 < 0) || (E2 > 99)) return -99;
    HP1 = min(666, max(HP1, 0));
    EXP1 = min(600, max(EXP1, 0));
    M1 = min(3000, max(M1, 0));

    int S = round(sqrt(EXP1));
    double P1, P2;
    S *= S;
    P1 = (EXP1 >= S) ? 100 : (100*(EXP1*1.0/S + 80)/123);

    if (E2 % 2)
     { S = (M1-1)/2;
       while (road2(HP1, EXP1, M1, S)) {};
     }
    else {road2(HP1, EXP1, M1, 0);}

    HP1 = min(HP1, 666); M1 = max(M1, 0);
    HP1 = ceill(0.83*HP1); EXP1 = min(ceill(1.17*EXP1), 600);
    S = round(sqrt(EXP1)); S *= S;
    P2 = (EXP1 >= S) ? 100 : (100*(EXP1*1.0/S + 80)/123);

    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    P1 = (P1 + P2 + P[(E2/10 + E2 % 10) % 10])/3;

    if (P1 == 100) {EXP1 = ceill(0.75*EXP1);}
     else if (P1 < 50) {HP1 = ceill(0.85*HP1); EXP1 = min(ceill(1.15*EXP1), 600);}
        else {HP1 = ceill(0.9*HP1); EXP1 = min(ceill(1.2*EXP1), 600);};

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // Calibration
    if ((E3 < 0) || (E3 > 99)) return -99;
    HP1 = min(666, max(HP1, 0));
    EXP1 = min(600, max(EXP1, 0));
    HP2 = min(666, max(HP2, 0));
    EXP2 = min(600, max(EXP2, 0));

    int pt_taxi[10][10], pt_HW[10][10], i, j, loci, locj;

    for (i=0; i<10; i++)
     for (j=0; j<10; j++)
      pt_taxi[i][j] = ((E3*j) + 2*i)*(i-j);

    int i1, j1;
    for (i=0; i<10; i++)
      for (j=0; j<10; j++)
       { pt_HW[i][j] = pt_taxi[i][j];

         i1 = i-1; j1 = j-1;
         while ((i1 + 1) && (j1 + 1))
          { pt_HW[i][j] = max(pt_HW[i][j], pt_taxi[i1][j1]);
            i1--; j1--;
          }

         i1 = i+1; j1 = j+1;
         while ((i1 < 10) && (j1 < 10))
          { pt_HW[i][j] = max(pt_HW[i][j], pt_taxi[i1][j1]);
            i1++; j1++;
          }

         i1 = i+1; j1 = j-1;
         while ((i1 < 10) && (j1 + 1))
          { pt_HW[i][j] = max(pt_HW[i][j], pt_taxi[i1][j1]);
            i1++; j1--;
          }

         i1 = i-1; j1 = j+1;
         while ((i1 + 1) && (j1 < 10))
          { pt_HW[i][j] = max(pt_HW[i][j], pt_taxi[i1][j1]);
            i1--; j1++;
          }

         pt_HW[i][j] = abs(pt_HW[i][j]);
       }

    i1 = (E3 == 0) ? 9 : (45 + (E3 < 4) - ceill(sqrt(E3+1)));
    j1 = (E3 == 0) ? 9 : 8;
    while (i1/10)
     i1 = (i1 % 10) + (i1/10);

    if (abs(pt_taxi[i1][j1]) <= pt_HW[i1][j1])
     { EXP1 = ceill(1.12*EXP1); EXP2 = ceill(1.12*EXP2);
       HP1 = ceill(1.1*HP1); HP2 = ceill(1.1*HP2);
       HP1 = min(666, HP1); EXP1 = min(600, EXP1);
       HP2 = min(666, HP2); EXP2 = min(600, EXP2);
       return pt_HW[i1][j1];
     }
    else
     { EXP1 = ceill(0.88*EXP1); EXP2 = ceill(0.88*EXP2);
       HP1 = ceill(0.9*HP1); HP2 = ceill(0.9*HP2);
       return pt_taxi[i1][j1];
     }

    return -1;
}

// Task 4
bool unclear(char c){
 if ((c == 35) || (c == 37) || (c == 36) || (c == 33)) return 0; // special character exclude @
 if ((c >= 48) && (c <= 57)) return 0; // 0 to 9
 if ((c >= 64) && (c <= 90)) return 0; // @, A to Z
 if ((c >= 97) && (c <= 122)) return 0; // a to z
 return 1;
}

int checkPassword(const char * s, const char * email) {
    string se, p = "", special = "@#%$!";
    int lp = 0, i=0, j;
    bool t = 0;

    p = s; lp = p.length(); // sidenote: '\0' is the empty character

    while (email[i] != '@')
     {se += email[i]; i++;}

    if (lp < 8) return -1;

    if (lp > 20) return -2;

    if (p.find(se) != string::npos) return -(300 + p.find(se)); // str.find() returns value npos if found no match

    for (i=2; i<lp; i++)
     if ((p[i] == p[i-1]) && (p[i-1] == p[i-2])) return -(398 + i);

    for (i=0; i<lp; i++)
     { for (j=0; j<5; j++)
        if (p[i] == special[j]) {t = 1; break;}
       if (t) break;
     }
    if (!t) return -5;

    for (i=0; i<lp; i++)
     if (unclear(s[i])) return i;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string s[51]; bool found;
    int appear[51], pos[51], c = 0;

    for (int i=0; i<num_pwds; i++)
     { found = 0;
       for (int j=1; j<=c; j++)
        if (arr_pwds[i] == s[j])
         { appear[j]++; found = 1;
           break;
         }
       if (!found)
        { c++; s[c] = arr_pwds[i];
          appear[c] = 1; pos[c] = i;
        }
     }

    int res = 1;
    for (int i=2; i<=c; i++)
     { if (appear[i] < appear[res]) continue;
       if (appear[i] == appear[res])
        { if (s[i].length() < s[res].length()) continue;
          if ((s[i].length() == s[res].length()) && (pos[i] > pos[res])) continue;
        }
       res = i;
     }

    return pos[res];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
