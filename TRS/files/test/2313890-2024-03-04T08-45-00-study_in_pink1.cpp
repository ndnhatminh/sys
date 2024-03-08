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
int ktdk(int v, int MIN, int MAX){
    if (v<MIN) return MIN;
    else if (v>MAX) return MAX;
    else return v;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if (E1 < 0 || E1 > 99) return -99; 
  if (E1 >= 0 && E1 <= 3) {
    if (E1 == 0) EXP2 += 29;
     else if (E1 == 1)  EXP2 += 45;
     else if (E1 == 2)  EXP2 += 75;
     else if (E1 == 3)  EXP2 += 149;
    
    int D = E1 * 3 + EXP1 * 7;
    if (D % 2 == 0)  EXP1 =ceil(EXP1 + D/ 200.00);
     else EXP1 =ceil(EXP1 - D / 100.00); 
    
  }
  if (E1 >= 4 && E1 <= 99) {
    if (E1 >= 4 && E1 <= 19)  EXP2 += ceil(E1 / 4.0) + 19;
     else if (E1 >= 20 && E1 <= 49)  EXP2 += ceil(E1 / 9.0) + 21;
     else if (E1 >= 50 && E1 <= 65)  EXP2 += ceil(E1 / 16.0) + 17;
     else if (E1 >= 66 && E1 <= 79) {
      EXP2 += ceil(E1 / 4.0) + 19;
      if (EXP2 > 200) EXP2 += ceil(E1 / 9.0) + 21;
    } 
     else if (E1 >= 80 && E1 <= 99) {
      EXP2 += ceil(E1 / 4.0) + ceil(E1 / 9.0) + 40;
      if (EXP2 > 400) {EXP2 += ceil(E1 / 16.0) + 17;
                       EXP2 += ceil(EXP2 * 0.15);}
    }
    EXP1 -= E1;
  }
    int MAX=600, MIN=0;
  EXP2 = ktdk(EXP2, MIN, MAX);
  EXP1 = ktdk(EXP1, MIN ,MAX);
  return EXP1 + EXP2;
}

// Task 2
int find(int num) {
    int can = sqrt(num);
    int square1 = can * can;
    int square2 = (can + 1) * (can + 1);
    int dis1 = abs(num - square1);
    int dis2 = abs(num - square2);
    if (dis1 < dis2) { return square1; }
    else return square2;

}
double solve(int EXP1) {
    int S = find(EXP1);
    if (EXP1 >= S) {
        return 1.0;
    }
    else {
        return (EXP1 * 1.000 / S + 80) / 123;
    }
}
double solvep3(int E2) {
    int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    return P[i] / 100.00;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    double p0 = 0, p1 = 0, p2 = 0, p3 = 0;
    int a = M1;
    EXP1 = ktdk(EXP1, 0, 600);
    HP1 = ktdk(HP1, 0, 666);
    M1 = ktdk(M1, 0, 3000);
    if (E2 < 0 || E2>99) { return -99; }
    p1 = solve(EXP1);
    bool event = true;
    if (E2 % 2 == 1) {
        while (event) {
            if (M1 * 1.0 > a * 0.5) {
                if (HP1 < 200) {
                    HP1 = HP1 * 1.3 + 0.99;
                    M1 = M1 - 150;}
                else { HP1 = HP1 * 1.1 + 0.99;
                    M1 = M1 - 70; }
                EXP1 = ktdk(EXP1, 0, 600);
                HP1 = ktdk(HP1, 0, 666);
                M1 = ktdk(M1, 0, 3000);}

            if (M1 * 1.0 > a * 0.5) {
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    EXP1 = EXP1 * 1.13 + 0.99;}
                else { M1 = M1 - 120;
                       EXP1 = EXP1 * 1.13 + 0.99;}
                EXP1 = ktdk(EXP1, 0, 600);
                HP1 = ktdk(HP1, 0, 666);
                M1 = ktdk(M1, 0, 3000);}
            if (M1 * 1.0 > a * 0.5) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    EXP1 = EXP1 * 0.9 + 0.99;}
                else { M1 = M1 - 120;
                       EXP1 = EXP1 * 0.9 + 0.99;}
                EXP1 = ktdk(EXP1, 0, 600);
                HP1 = ktdk(HP1, 0, 666);
                M1 = ktdk(M1, 0, 3000);}
            if (M1 * 1.0 <= a * 0.5) event = false;
        }
    }
    else {
        if (M1 > 0) {
            if (HP1 < 200) { HP1 = HP1 * 1.3 + 0.99;
                             M1 = M1 - 150;}
            else { HP1 = HP1 * 1.1 + 0.99;
                   M1 = M1 - 70;}
            EXP1 = ktdk(EXP1, 0, 600);
            HP1 = ktdk(HP1, 0, 666);
            M1 = ktdk(M1, 0, 3000);
        }
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 = M1 - 200;
                EXP1 = EXP1 * 1.13 + 0.99;}
            else { M1 = M1 - 120;
                   EXP1 = EXP1 * 1.13 + 0.99;}
            EXP1 = ktdk(EXP1, 0, 600);
            HP1 = ktdk(HP1, 0, 666);
            M1 = ktdk(M1, 0, 3000);
        }
        if (M1 > 0) {
            if (EXP1 < 300) { M1 = M1 - 100;
                              EXP1 = EXP1 * 0.9 + 0.99;}
            else { M1 = M1 - 120;
                   EXP1 = EXP1 * 0.9 + 0.99;}
            EXP1 = ktdk(EXP1, 0, 600);
            HP1 = ktdk(HP1, 0, 666);
            M1 = ktdk(M1, 0, 3000);
        }
    }
    HP1 = 0.83*HP1  + 0.99;
    EXP1 = 1.17*EXP1 + 0.99;
    EXP1 = ktdk(EXP1, 0, 600);
    HP1 = ktdk(HP1, 0, 666);
    M1 = ktdk(M1, 0, 3000);
    p2 = solve(EXP1);
    p3 = solvep3(E2);
    p0 = p1 + p2 + p3;
    if (p0 == 1) { EXP1 = EXP1 * 0.75 + 0.99; }
    else if (p0 < 0.5) {
        HP1 = HP1 * 0.85 + 0.99;
        EXP1 = EXP1 * 1.15 + 0.99;}
    else { HP1 = HP1 * 0.9 + 0.99;
           EXP1 = EXP1 * 1.2 + 0.99;}
    EXP1 = ktdk(EXP1, 0, 600);
    HP1 = ktdk(HP1, 0, 666);
    M1 = ktdk(M1, 0, 3000);
    
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    int x, y, sher, taxi, back ;
    x = 0;
    y = 0;
    int p[10][10];
    if (E3 < 0 || E3>99) return -99;
    EXP1 = ktdk(EXP1, 0, 600);
    HP1 = ktdk(HP1, 0, 666);
    EXP2 = ktdk(EXP2, 0, 600);
    HP2 = ktdk(HP2, 0, 666);
    //Tim gia tri tung o
     for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            p[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (p[i][j] != 0 && p[i][j] > (E3 * 2)) {
                x = x + 1;
            }
            if (p[i][j] != 0 && p[i][j] < (-E3)) {
                y = y + 1;
            }
        }
    }

    while (x >= 10) {
        x = x / 10 + x % 10;}
    while (y >= 10) {
        y = y / 10 + y % 10;}

    taxi = p[x][y];
     sher = 0;

    for (int i = 1; i <= 9; ++i) {

        if ((x + i) <= 9 && (y + i) <= 9) {
            if (p[x + i][y + i] > sher) sher = p[x + i][y + i];}

        if ((x - i) >= 0 && (y - i) >= 0) {
            if (p[x - i][y - i] > sher) sher = p[x - i][y - i];}

        if ((x - i) >= 0 && (y + i) <= 9) {
            if (p[x - i][y + i] > sher) sher = p[x - i][y + i];}

        if ((x + i) <= 9 && (y - i) >= 0) {
            if (p[x + i][y - i] > sher) sher = p[x + i][y - i];}

    }

    if (abs(taxi) > abs(sher)) {
        EXP1 = 0.88*EXP1 + 0.99;  HP1 = 0.9*HP1 + 0.99;    
        EXP2 = 0.88*EXP2 + 0.99;  HP2 = 0.9*HP2 + 0.99;
        back = taxi;}
    else {
        EXP1 = 1.12*EXP1 + 0.99; HP1 = 1.1*HP1 + 0.99;
        EXP2 = 1.12*EXP2 + 0.99; HP2 = 1.1*HP2 + 0.99;
        back = sher;}
    EXP1 = ktdk(EXP1, 0, 600);
    HP1 = ktdk(HP1, 0, 666);
    EXP2 = ktdk(EXP2, 0, 600);
    HP2 = ktdk(HP2, 0, 666);

    return back;
}

// Task 4
bool isSpecial(char c)
{
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[101]; int i = 0;
    while (email[i] != '@' && email[i] != '\0'){
      se[i] = email[i];
        i++;} se[i] = '\0';
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;
    if (strstr(s, se) != NULL) return -(300 + (strstr(s, se) - s));
    for (i = 0; i < len - 2; i++) {
     if (s[i] == s[i + 1] && s[i] == s[i + 2]) 
     return -(400+i);   
    }
    bool hasSpecial = false;
    for (i = 0; i < len; i++){
    if (isSpecial(s[i]))  {hasSpecial = true;
                           break;} 
    }
    if (!hasSpecial) return -5;
    for (i = 0; i < len; i++){
        char c = s[i];
        if (!isalnum(c) && !isSpecial(c)) return i;
    }
return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
int max_count = 0; 
int max_index = -1; 
int max_len = 0;
    for (int i = 0; i < num_pwds; i++) {
        int count = 0; 
        int len = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) count++; }
        if (count > max_count || (count == max_count && len > max_len)) {
            max_count = count;
            max_index = i;
            max_len = len;
        }
    }
    return max_index; 
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////