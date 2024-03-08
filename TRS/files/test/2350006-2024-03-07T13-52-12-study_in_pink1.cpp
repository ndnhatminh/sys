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
int checkHP (double HP){
    int a = ceil(HP);
    if (a > 666) return 666;
    else if (a < 0) return 0;
    else return a;
}

int checkEXP (double EXP){
    int a = ceil(EXP);
    if (a > 600) return 600;
    else if (a < 0) return 0;
    else return a;
}

int checkM (double M){
    int a = ceil(M);
    if (a > 3000) return 3000;
    else if (a < 0) return 0;
    else return a;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if (e1 > 99 || e1 < 0) return -99;
    else {
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
      if (e1 < 4)
    {
        if (e1 == 3) exp2 += (29 + 45 +75);
            else if (e1 == 2) exp2 += 75;
                else if (e1 == 1) exp2 += 45;
                    else exp2 += 29;
        exp2 = checkEXP(exp2);

    int D = e1*3 + exp1*7;
        if (D%2==0)         exp1 = checkEXP(exp1 + (D*1.0)/200);
        else                exp1 = checkEXP(exp1 - (D*1.0)/100);
    }
    else
    {
        if (e1 < 20)
            exp2 = checkEXP(exp2 + (e1*1.0/4) + 19);
        else if (e1 < 50)
            exp2 = checkEXP(exp2 + (e1*1.0/9) + 21);
        else if (e1 < 66)
            exp2 = checkEXP(exp2 + (e1*1.0/16) + 17);
        else if (e1 < 80) {
            exp2 = checkEXP(exp2 + (e1*1.0/4) + 19);
            if (exp2 > 200)
                exp2 = checkEXP(exp2 + (e1*1.0/9) + 21);
        }
        else {
            exp2 = checkEXP(exp2 + (e1*1.0/4) + 19);
            exp2 = checkEXP(exp2 + (e1*1.0/9) + 21);
            if (exp2 > 400){
                exp2 = checkEXP(exp2 + (e1*1.0/16) + 17);
                exp2 = checkEXP(exp2*115.0/100);
            }
        }
        exp1 = checkEXP(exp1-e1);
    }
        }
            return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    else {
        HP1 = checkHP(HP1);
        M1 = checkM(M1);
        EXP1 = checkEXP(EXP1);
        double p1, p2, p3, p;
        int s = round((double)sqrt(EXP1));
        if (EXP1 >= s*s)
            p1 = 1.0;
        else
            p1 = ((double)(EXP1/(s*s))+80)/123;

        if (E2%2 == 1){
            double m0 = (M1/2.0);
            int money = 0;
            while (M1>0){
                if (HP1 < 200) {
                    HP1 = checkHP(HP1*13.0/10);
                    M1 = checkM(M1-150);
                    money+=150;
                } else{
                    HP1 = checkHP(HP1*11.0/10);
                    M1 = checkM(M1-70);
                    money += 70;
                }       if (money > m0) break;

                if (EXP1 < 400) {
                    M1 = checkM(M1-200);
                    EXP1 = checkEXP(EXP1*113.0/100);
                    money += 200;
                } else{
                    M1 = checkM(M1-120);
                    EXP1 = checkEXP(EXP1*113.0/100);
                    money += 120;
                }       if (money > m0) break;
                if (EXP1 < 300) {
                    M1 = checkM(M1-100);
                    EXP1 = checkEXP(EXP1*9.0/10);
                    money += 100;
                } else{
                    M1 = checkM(M1-120);
                    EXP1 = checkEXP(EXP1*9.0/10);
                    money += 120;
                }        if (money > m0) break;
            };
        }
        else {
            do{
                if (M1 <= 0) break;
                if (HP1 < 200){
                    HP1 = checkHP(HP1*13.0/10);
                    M1 = checkM(M1-150);
                } else{
                    HP1 = checkHP(HP1*11.0/10);
                    M1 = checkM(M1-70);
                }      if (M1 <= 0) break;
                if (EXP1 < 400){
                    M1 = checkM(M1-200);
                    EXP1 = checkEXP(EXP1*113.0/100);
                } else{
                    M1 = checkM(M1-120);
                    EXP1 = checkEXP(EXP1*113.0/100);
                }       if (M1 <= 0) break;
                if (EXP1 < 300){
                    M1 = checkM(M1-100);
                    EXP1 = checkEXP(EXP1*0.9);
                } else{
                    M1 = checkM(M1-120);
                    EXP1 = checkEXP(EXP1*0.9);
                }       if (M1 <= 0) break;
            } while(0);
        }
        HP1 = checkHP(HP1*83.0/100);
        EXP1  = checkEXP(EXP1*117.0/100);
        int a = round((double)sqrt(EXP1));
        if (EXP1 >= a*a)
            p2 = 1.0;
        else
            p2 = ((double)(EXP1/(a*a))+80)/123;

        double P[10]={0.32,0.47,0.28,0.79,1.0,0.5,0.22,0.83,0.64,0.11};
        if (E2<10) p3 = P[E2];
            else p3 = P[(E2%10 + E2/10)%10];

        //CONCLUDE:
        if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0)
            EXP1 = checkEXP(EXP1*0.75);
        else {
            p = (p1 + p2 + p3)/3.0;
            if (p < 0.5){
                HP1 = checkHP(HP1*85.0/100);
                EXP1 = checkEXP(EXP1*115.0/100);
            }
            else{
                HP1 = checkHP(HP1*9.0/10);
                EXP1 = checkEXP(EXP1*12.0/10);
            }
        }

        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) return -99;
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    EXP2 = checkEXP(EXP2);
    HP2 = checkHP(HP2);
    int arr[10][10];
    int a = 0, b=0;
  for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > (E3 * 2)) a++;
            if (arr[i][j] < (0-E3)) b++;
        }
    while(a > 9) a = (a/10) + (a%10);
    while(b > 9) b = (b/10) + (b%10);
    int tpoint= arr[a][b];
    int spoint = arr[a][b];
    for (int i = 0; i < 10; i++)
      {
        if ( 0 <= 0+i && 0+i <= 9 && 0<= a+b-i && a+b-i <= 9 ) {
        if (arr[0+i][a+b-i] > spoint) spoint = arr[0+i][a+b-i];
        }
      }
    for (int i = 0; i < 10; i++)
      {
        if ( 0 <= 0+i && 0+i <=9 && 0<= 0-(a-b)+i && 0-(a-b)+i <= 9 ) {
        if (arr[0+i][0-(a-b)+i] > spoint) spoint = arr[0+i][0-(a-b)+i];
        }
      }

    if (abs(tpoint) > abs(spoint)){
        HP1 = checkHP(HP1*9.0/10);
        HP2 = checkHP(HP2*9.0/10);
        EXP1 = checkEXP(EXP1*88.0/100);
        EXP2 = checkEXP(EXP2*88.0/100);
        return tpoint;
    } else {
        HP1 = checkHP(HP1*11.0/10);
        HP2 = checkHP(HP2*11.0/10);
        EXP1 = checkEXP(EXP1*112.0/100);
        EXP2 = checkEXP(EXP2*112.0/100);
        return spoint;
    }


}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100];
    strncpy(se, email, strchr(email, '@') - email);
    se[strchr(email, '@') - email] = '\0';
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    if (strstr(s, se) != nullptr) return -(300 + strstr(s, se) - s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i + 1] && s[i + 2] == s[i + 1]) {
            return -(400 + i);
            break;
        }
    }

    bool special = false;
    for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
        special = true;
        break;
        }
    }
    if (!special) return -5;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!((s[i] >= '0' && s[i] <= '9') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int position = -1;
  int max_frequency = 0;
  int current_frequency;
  int pwds_len;

  for (int i = 0; i < num_pwds; i++) {
    current_frequency = 1;
    pwds_len = strlen(arr_pwds[i]);

    for (int j = i + 1; j < num_pwds; j++) {
      if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
        current_frequency++;
      }
    }

    if (current_frequency > max_frequency) {
      max_frequency = current_frequency;
      position = i;
    } else if (current_frequency == max_frequency) {
      if (pwds_len > strlen(arr_pwds[position])) {
        position = i;
      }
    }
  }

  return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
