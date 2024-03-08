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

void checkmoney(int& M) {
    if (M < 0) { M = 0; }
    else if (M > 3000) {
        M = 3000;
    }
}
void checkexp(int& EXP) {
    if (EXP < 0) { EXP = 0; }
    else if (EXP > 600) {
        EXP = 600;
    }
}
void checkhp(int& HP) {
    if (HP <0) { HP = 0; }
    else if (HP > 666) {
        HP=666;
    }
}
  

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    
   
    if (e1 < 0 || e1>99) {
        return -99;
    }
    checkexp(exp1);
    checkexp(exp2);
    if (e1 <= 3 && e1 >= 0) {
        switch (e1) {
        case 0:
            exp2 += 29;
             checkexp(exp2);
             break;
           
        case 1:
            exp2 += 45;
            checkexp(exp2);
            break;
        case 2:
            exp2 += 75;
            checkexp(exp2);
            break;
        case 3:
            exp2 += 149;
            checkexp(exp2);
            break;
        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + (D/ 200.0));
            checkexp(exp1);
        }
        else {
            exp1 = ceil(exp1- (D/ 100.0));
            checkexp(exp1);
        }
    }
    //Case 2
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 =ceil(exp2+ (e1 / 4.0) + 19);
            checkexp(exp2);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
            checkexp(exp2);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2 + (e1 / 16.0) + 17);
            checkexp(exp2);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2+ (e1 / 4.0) + 19);
            checkexp(exp2);
            if (exp2 > 200) {
                exp2 +=ceil( (e1 / 9.0) + 21);
                checkexp(exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil((e1 / 4.0) + 19);
            checkexp(exp2);
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
            checkexp(exp2);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 / 16.0) + 17);
                checkexp(exp2);
                exp2 = ceil(exp2 * 115.0/100);
                checkexp(exp2);
            }
        }
        exp1 = exp1 - e1;
        checkexp(exp1);
    }
    //Output:
    return exp1 + exp2;
}
 
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    
    if (E2 < 0 || E2>99) {
        return -99;
    }
    
    checkhp(HP1);
    checkexp(EXP1);
    checkmoney(M1);
    // Road 1
    int S;
    float P1, P2;
    int initialM1 = M1;
    float sqrexp1;
    sqrexp1 = sqrtf(EXP1 * 1.0);
    S = pow((round(sqrexp1)), 2);
    if (EXP1 >= S) {
        P1 = 1;
    }
    else {
        P1 = (((EXP1 / static_cast<float>(S)) + 80) / 123);
    }


    //Road 2
    if (M1 > 0) {
        if (E2 % 2 == 0) {
            if (HP1 < 200 && M1 > 0) {
                HP1 = ceil(HP1 * 1.0 + HP1 * 0.3);
                checkhp(HP1);
                M1 -= 150;
                checkmoney(M1);
            }
            else if (M1 > 0) {
                HP1 = ceil(0.1 * HP1 + 1.0 * HP1);
                M1 -= 70;
                checkhp(HP1);
                checkmoney(M1);
            }
            if (EXP1 < 400 && M1 >0) {
                M1 -= 200;
                EXP1 = ceil(EXP1 * 1.0 + 0.13 * EXP1);
                checkexp(EXP1);
                checkmoney(M1);
            }
            else if (M1 > 0) {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.0 + 0.13 * EXP1);
                checkexp(EXP1);
                checkmoney(M1);
            }

            if (EXP1 < 300 && M1 > 0) {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 1.0 - 0.1 * EXP1);
                checkexp(EXP1);
                checkmoney(M1);
            }
            else if (M1 > 0) {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 1.0 - 0.1 * EXP1);
                checkhp(HP1);
                checkmoney(M1);
            }
        }
        if (E2 % 2 == 1) {
            while (M1 * 1.0 >= (initialM1 / 2.0)) {
                if (HP1 < 200 ) {
                    HP1 = ceil(HP1 + HP1 * 0.3);
                    checkhp(HP1);
                    M1 -= 150;
                    checkmoney(M1);
                }
                else {
                    HP1 = ceil(HP1 + HP1 * 0.1);
                    M1 -= 70;
                    checkhp(HP1);
                    checkmoney(M1);
                }
                if (M1 * 1.0 < (initialM1 / 2.0)) break;
                if (EXP1 < 400 ) {
                    M1 -= 200;
                    checkmoney(M1);
                    EXP1 = ceil(EXP1 + EXP1 * 0.13);
                    checkexp(EXP1);

                }
                else  {
                    M1 -= 120;
                    checkmoney(M1);
                    EXP1 = ceil(EXP1 + EXP1 * 0.13);
                    checkexp(EXP1);
                }
                if (M1 * 1.0 < (initialM1 / 2.0)) break;
                if (EXP1 * 1.0 < 300 ) {
                    M1 -= 100;
                    EXP1 = ceil(EXP1 - 0.1 * EXP1);
                    checkexp(EXP1);
                    checkmoney(M1);
                }
                else  {
                    M1 -= 120;
                    EXP1 = ceil(EXP1 - 0.1 * EXP1);
                    checkexp(EXP1);
                    checkmoney(M1);
                }

            }

        }
    }
     HP1 = ceil(HP1- HP1*0.17);
     EXP1 = ceil(EXP1 + EXP1* 0.17);
     checkhp(HP1);
     checkexp(EXP1);
        S = pow((round(sqrt(EXP1))),2);
        if (EXP1 >= S) {
            P2 = 1;
        }
        else {
            P2 = (((EXP1 / static_cast<float>(S)) + 80) / 123);

        }
       

        //Road 3
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        const int SIZE = 10;
        float P3;
        int i, sum;
        int a = 0;
        if (E2 >= 10 && E2 <= 99) {
            sum = (E2 / 10) + (E2 % 10);
            i = sum % 10;
            a = P[i];

        }
        else if (E2>=0 && E2<10 ){
            i = E2;
            a = P[i];
            
        }
       P3 = a / static_cast<float>(100);
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = ceil (EXP1 - EXP1* 0.25);
            checkexp(EXP1);
        }
        else {
            float avg;
            avg = (P1 + P2 + P3) / 3;
            if (avg < 0.5) {
                HP1 = ceil(HP1- HP1*0.15);
                EXP1 = ceil(EXP1 + EXP1 * 0.15);
                checkexp(EXP1);
                checkhp(HP1);
            }
            else {
                HP1 = ceil( HP1 - HP1*0.1);
                EXP1 = ceil(EXP1+EXP1*0.2);
                checkexp(EXP1);
                checkhp(HP1);
            }

        }

  return HP1+ EXP1+M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    const int size = 10;
    int i, j;
    int matrix[size][size];
    if (E3 < 0 || E3>99) {
        return -99;
    }
    checkhp(HP1);
    checkexp(EXP1);
    checkhp(HP2);
    checkexp(EXP2);

    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; ++b) {
            matrix[a][b] = ((E3 * b) + (a * 2)) * (a - b);
        }
    }
    int sumpositive = 0;
    int sumnegative = 0;
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; ++b) {
            if (matrix[a][b] > (E3 * 2)) {
                sumpositive += 1;
            }
        }
    }
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; ++b) {
            if (matrix[a][b] < (-E3)) {
                sumnegative += 1;
            }
        }
    }
   
    while (sumpositive >= 10 && sumpositive <= 99) {
       sumpositive = (sumpositive / 10) + (sumpositive % 10);  
    }
    i = sumpositive;
    while (sumnegative >= 10 && sumnegative <= 99) {
        sumnegative = (sumnegative / 10) + (sumnegative % 10);
    }
    j = sumnegative;
   //EXP sherlock
        int a = i;
        int b = j;
        int taxi;
        int max = matrix[i][j];
        //right:
        while (a > 0 && b < size) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a -= 1;
            b += 1;
        }

        a = i;
        b = j;
        while (a < size && b > 0) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a += 1;
            b -= 1;
        }
       //left:

        a = i;
        b = j;
        while (a <size && b < size) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a += 1;
            b += 1;
        }

        a = i;
        b = j;
        while (a >0 && b > 0) {
            if (matrix[a][b] > max) {
                max = matrix[a][b];
            }
            a -= 1;
            b -= 1;
        }
        taxi = abs(matrix[i][j]);
        int result;
        
  
        if (taxi <= max) {
            HP1 = HP1*1.1+0.999;
            EXP1 = EXP1 * 1.12 + 0.999;
            HP2 = HP2 * 1.1 + 0.999;
            EXP2 = EXP2 * 1.12 + 0.999;
            result = max;
        }
        else {
            HP1 = HP1 * 0.9 + 0.999;
            EXP1 = EXP1 * 0.88 + 0.999;
            HP2 = HP2 * 0.9 + 0.999;
            EXP2 = EXP2 * 0.88 + 0.999;
            result = matrix[i][j];
        }
        checkhp(HP1);
        checkexp(EXP1);
        checkhp(HP2);
        checkexp(EXP2);
        
    return result;
}

// Task 4
int checkPassword(const char* s, const char* email) {
string se(email);
    int  pos = se.find('@');
    se = se.substr(0, pos);
    int emailLength = strlen(email);

    if ( strlen(s) < 8 || strlen(s) > 20) {
        return (strlen(s) < 8) ? -1 : -2;
    }
    auto  a = strstr(s, se.c_str());
    bool b =a  != NULL;
    if (b) {
        size_t sei = strstr(s, se.c_str()) - s ;
        int seii = static_cast<int>(sei);
        return -(300 + seii);
    }

    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            int sci = i;
            return -(400 + sci);
        }
    }
    int special = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' ||
            s[i] == '%' || s[i] == '$' || s[i] == '!') {
            special += 1;
        }
    }
    if (special == 0) {
        return -5;
    }

    for (int i = 0; i < strlen(s); i++) {
        
        if (!isalnum(s[i]) && s[i]!= '@' && s[i] != '#' &&
            s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i;
        }
    }
        return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    
    int countmax = 0;
    int lengthmax = 0;
    const char* password{};
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        const char* current = arr_pwds[i];
        int length = strlen(current);
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(current, arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > countmax) {
            lengthmax = length;
            countmax = count;
            password = current;
        }
        else if (count == countmax && length > lengthmax) {
            lengthmax = length;
            countmax = count;
            password = current;
        }
    }

    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], password) == 0) {
            return i;
        }
    }
    return -1;
}

