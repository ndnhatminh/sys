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
// 
// 
// FUNCTIONS TO SUPPORT TASKS
///
//input exp check function
void initialExpCheck(int& a) {
    if (a > 600) a = 600;
    if (a < 0) a = 0;
}
void expCheck(float& a) {
    if (a > 600) a = 600;
    if (a < 0) a = 0;
}
//Health check
void healthCheck(int& a) {
    if (a > 666) a = 666;
    if (a < 0) a = 0;
}
void healthCheck(float& a) {
    if (a > 666) a = 666;
    if (a < 0) a = 0;
}
//roundUp up function
float roundUp(float a) {
    int b = a;
    float c = b;
    if (a > b) c += 1;
    return c;
}
//money check
void moneyCheck(int& a) {
    if (a > 3000) a = 3000;
    if (a < 0) a = 0;
}
void moneyCheck(float& a) {
    if (a > 3000) a = 3000;
    if (a < 0) a = 0;
}
// find closet perfect square
int closetPerfectSquare(int k) {
    float a = sqrt(k);
    int b = sqrt(k);
    int c;
    if ((a - b) > 0.5) c = (b + 1) * (b + 1);
    else if ((a - b) < 0.5) c = b * b;
    return c;
}
// check if spent money is more than 50%
bool overpay(float a, int b) {
    float c = b * 0.5;
    if (a > c) return true;
    else return false;
}
// sum of 2 digit of a 2-digit number????????
int sumOfTwoDigit(float a) {
    int b = a / 10;
    int c = a - b * 10;
    if (b + c < 10) return b + c;
    else {
        int k = (b + c) / 10;
        return (b + c) - k * 10;
    }
}
// check more than 2 same char successively
int threeSameChar(string s) {
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return i;
    }
    return -999;
}
// check no special character
bool noSpecialChar(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') return false;
    }
    return true;
}
// a password include: lower(upper)case letter, number, special char.
int isValidString(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') return i;
    }
    return -999;
}
// find metting point
int stageSum(int x) {
    if (x >= 10) {
        int y = 0;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        return stageSum(y);
    }
    else if (x == 100) return 1;
    else return x;
}

/////////////////////////////////////////////////////////


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1>99) return -99;
    initialExpCheck(exp1);
    initialExpCheck(exp2);
    float D_float;
    float exp1_float = exp1;
    float exp2_float = exp2;
    float e1_float = e1;
    //Case 1
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) {
            exp2_float += 29;
            expCheck(exp2_float);
        }// e1=0 exp watson increase by 29
        if (e1 == 1) {
            exp2_float += 45;
            expCheck(exp2_float);
        }// 
        if (e1 == 2) {
            exp2_float += 75;
            expCheck(exp2_float);
        }
        if (e1 == 3) {
            exp2_float += 149;//29+45+75
            expCheck(exp2_float);
        }

        int D = e1 * 3 + exp1_float * 7; // D parameter which decide Sherlock's exp
        D_float = D;
        if (D % 2 == 0) {
            exp1_float += (D_float / 200);
            exp1_float = roundUp(exp1_float);
            expCheck(exp1_float);
            exp1 = exp1_float;
        }
        else if (D % 2 == 1) {
            exp1_float -= (D_float / 100); // da test 1 tc
            exp1_float = roundUp(exp1_float);
            expCheck(exp1_float);
            exp1 = exp1_float;
        }
        exp2 = roundUp(exp2_float);
    }

    //Case 2:
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2_float += (e1_float / 4 + 19);// information 1
            exp2_float = roundUp(exp2_float);
            expCheck(exp2_float);
        }
        if (e1 >= 20 && e1 <= 49) {
            exp2_float += (e1_float / 9 + 21);// information 2
            exp2_float = roundUp(exp2_float);
            expCheck(exp2_float);
        }
        if (e1 >= 50 && e1 <= 65) {
            exp2_float += (e1_float / 16 + 17);// information 3
            exp2_float = roundUp(exp2_float);
            expCheck(exp2_float);
        }
        //Informations 4 and 5 are complicated than the informations before. 
        if (e1 >= 66 && e1 <= 79) {
            exp2_float += (e1_float / 4 + 19); //Sherlock explain infor 1
            exp2_float = roundUp(exp2_float);
            expCheck(exp2_float);
            if (exp2_float > 200) {
                exp2_float += (e1_float / 9 + 21);
                exp2_float = roundUp(exp2_float);
            }
        }// information 4

        if (e1 >= 80 && e1 <= 99) {
            exp2_float += (e1_float / 4 + 19);
            exp2_float = roundUp(exp2_float);
            expCheck(exp2_float);
            exp2_float += (e1_float / 9 + 21);// sherlock explain infor 1 and 2
            exp2_float = roundUp(exp2_float);
            expCheck(exp2_float);
            if (exp2_float > 400) {
                exp2_float += (e1_float / 16 + 17);// exp >400
                exp2_float = roundUp(exp2_float);
                expCheck(exp2_float);
                exp2_float = exp2_float * 1.15;// sherlock explain infor 1 2 3
                exp2_float = roundUp(exp2_float);
                expCheck(exp2_float);
            }

        }
        exp1_float -= e1_float; // Harry is Harriet
        exp1 = roundUp(exp1_float);
        initialExpCheck(exp1);
        exp2 = roundUp(exp2_float);
        initialExpCheck(exp2);
    }


    return exp1 + exp2;
} // SAI TESTCASE DAU TIEN TREN WEB TRUONG


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    // E check
    if (E2 < 0 || E2>99) return -99;
    moneyCheck(M1);// input money check
    initialExpCheck(EXP1);// input exp check
    float EXP1_float = EXP1;// following 3 lines convert int to float
    float HP1_float = HP1;
    float M1_float = M1;
    float P1;// Probability of finding luggage each road
    float P2;
    float P3;
    //road 1
    int S = closetPerfectSquare(EXP1);
    if (EXP1_float >= S) P1 = 1; // EXP1 >= S
    else P1 = ((EXP1_float / S) + 80) / 123;


    //road 2
    float M1_spent = 0;// keep track on spent money
    if (E2 % 2 == 1) {
        while (E2 % 2 == 1) {// E is an odd number
            if (M1 == 0) break;// if money = 0 -> walk
            // event 1 of road 2
            if (HP1_float < 200) { // HP >200
                HP1_float = HP1_float + 0.3 * HP1_float;
                HP1_float = roundUp(HP1_float);
                healthCheck(HP1_float);
                M1_float -= 150;
                M1_spent += 150;
                moneyCheck(M1_float);
                if (overpay(M1_spent, M1) == true) break;
            }
            else { // HP >= 200
                HP1_float += 0.1 * HP1_float;
                HP1_float = roundUp(HP1_float);
                healthCheck(HP1_float);
                M1_float -= 70;
                M1_spent += 70;
                moneyCheck(M1_float);
                if (overpay(M1_spent, M1) == true) break;
            }
            // event 2 of road 2
            if (EXP1_float < 400) {// Sherlock travel by taxi
                M1_float -= 200;
                M1_spent += 200;
                moneyCheck(M1_float);
                EXP1_float += 0.13 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                if (overpay(M1_spent, M1) == true) break;
            }
            else {// SHerlock travels by horse
                M1_float -= 120;
                M1_spent += 120;
                moneyCheck(M1_float);
                EXP1_float += 0.13 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                if (overpay(M1_spent, M1) == true) break;
            }
            //event 3 of road 2
            if (EXP1_float < 300) { // m=100
                M1_float -= 100;
                M1_spent += 100;
                moneyCheck(M1_float);
                EXP1_float -= 0.1 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                if (overpay(M1_spent, M1) == true) break;
            }
            else { // m=120
                M1_float -= 120;
                M1_spent += 120;
                moneyCheck(M1_float);
                EXP1_float -= 0.1 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                if (overpay(M1_spent, M1) == true) break;
            }
        }
    }

    else if (E2 % 2 == 0) {// E2 is even
        for (int i = 0; i < 1; i++) {
            if (M1 == 0) break;
            // event 1 of road 2
            if (HP1_float < 200) { // HP >200
                HP1_float = HP1_float + 0.3 * HP1_float;
                HP1_float = roundUp(HP1_float);
                healthCheck(HP1_float);
                M1_float -= 150;
                moneyCheck(M1_float);
                int m1 = M1_float;
                if (m1 == 0) break;
            }
            else { // HP >= 200
                HP1_float += 0.1 * HP1_float;
                HP1_float = roundUp(HP1_float);
                healthCheck(HP1_float);
                M1_float -= 70;
                moneyCheck(M1_float);
                int m1 = M1_float;
                if (m1 == 0) break;
            }
            // event 2 of road 2
            if (EXP1_float < 400) {// Sherlock travel by taxi
                M1_float -= 200;
                moneyCheck(M1_float);
                EXP1_float += 0.13 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                int m1 = M1_float;
                if (m1 == 0) break;
            }
            else {// SHerlock travels by horse
                M1_float -= 120;
                moneyCheck(M1_float);
                EXP1_float += 0.13 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                int m1 = M1_float;
                if (m1 == 0) break;
            }
            //event 3 of road 2
            if (EXP1_float < 300) { // m=100
                M1_float -= 100;
                moneyCheck(M1_float);
                EXP1_float -= 0.1 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                int m1 = M1_float;
                if (m1 == 0) break;
            }
            else { // m=120
                M1_float -= 120;
                moneyCheck(M1_float);
                EXP1_float -= 0.1 * EXP1_float;
                EXP1_float = roundUp(EXP1_float);
                expCheck(EXP1_float);
                int m1 = M1_float;
                if (m1 == 0) break;
            }
        }
    }
    ///////////////
    HP1_float -= 0.17 * HP1_float; // after overpay, Sherlock walks.
    HP1_float = roundUp(HP1_float);
    healthCheck(HP1_float);
    EXP1_float += 0.17 * EXP1_float;
    EXP1_float = roundUp(EXP1_float);
    expCheck(EXP1_float); 
    // return value to integer
    HP1 = HP1_float;
    EXP1 = EXP1_float;
    M1 = M1_float;
    // Probability for road 2
    if (EXP1_float >= closetPerfectSquare(EXP1_float)) P2 = 1;
    else P2 = (((EXP1_float) / S) + 80) / 123;


    // road 3
    float array[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
    if (E2 >= 0 && E2 <= 9) P3 = array[E2]; // E2 has 1 digit
    else P3 = array[sumOfTwoDigit(E2)]; // E2 has 2 digit
    // comparing 3 probability
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1_float -= 0.25 * EXP1_float;
        EXP1_float = roundUp(EXP1_float);
        expCheck(EXP1_float);
    }
    else {
        float overall_P = (P1 + P2 + P3) / 3;
        if (overall_P < 0.5) {
            HP1_float -= 0.15 * HP1_float;
            HP1_float = roundUp(HP1_float);
            healthCheck(HP1_float);
            EXP1_float += 0.15 * EXP1_float;
            EXP1_float = roundUp(EXP1_float);
            expCheck(EXP1_float);
        }
        else {
            HP1_float -= 0.1 * HP1_float;
            HP1_float = roundUp(HP1_float);
            healthCheck(HP1_float);
            EXP1_float += 0.2 * EXP1_float;
            EXP1_float = roundUp(EXP1_float);
            expCheck(EXP1_float);
        }
    }
    HP1 = HP1_float;
    EXP1 = EXP1_float;
    M1 = M1_float;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    initialExpCheck(EXP1);// input exp check
    initialExpCheck(EXP2);
    healthCheck(HP1);
    healthCheck(HP2);
    float EXP1_float = EXP1;
    float EXP2_float = EXP2;
    float HP1_float = HP1;
    float HP2_float = HP2;
    // create taxi's matrix
    int taxi[10][10]; // taxi matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // right and left diagonal
    int right_diagonal[19];
    int left_diagonal[19];
    int right_diagonal_max[19]{ 0 };
    int left_diagonal_max[19]{ 0 };
    // find max diagonal
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            right_diagonal_max[i + j] = max(right_diagonal_max[i + j], taxi[i][j]);
            left_diagonal_max[j + 9 - i] = max(left_diagonal_max[j + 9 - i], taxi[i][j]);
            if (right_diagonal_max[i + j] < 0) right_diagonal_max[i + j] = abs(right_diagonal_max[i + j]);
            if (left_diagonal_max[i + j] < 0) left_diagonal_max[i + j] = abs(left_diagonal_max[i + j]);

        }
    // create Sherlock and Watson matrix
    int SH[10][10];
    for (int j = 0; j < 10; j++)
        for (int i = 0; i < 10; i++) {
            SH[i][j] = max(right_diagonal_max[i + j], left_diagonal_max[j + 9 - i]);
        }
    // find meeting point
    int count_pos = 0;// num of val larger than 2*e3
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] > (E3 * 2)) count_pos++;
        }
    int count_neg = 0; // num of neg val smaller than 
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (taxi[i][j] < -(E3)) count_neg++;
        }
    int z = stageSum(count_pos);
    int t = stageSum(count_neg);
    if (abs(taxi[z][t]) > SH[z][t]) { // cant catch up with taxi
        EXP1_float -= EXP1_float * 0.12;
        EXP1_float = roundUp(EXP1_float);
        expCheck(EXP1_float);
        EXP2_float -= EXP2_float * 0.12;
        EXP2_float = roundUp(EXP2_float);
        expCheck(EXP2_float);
        HP1_float -= HP1_float * 0.1;
        HP1_float = roundUp(HP1_float);
        healthCheck(HP1_float);
        HP2_float -= HP2_float * 0.1;
        HP2_float = roundUp(HP2_float);
        healthCheck(HP2_float);
        EXP1 = EXP1_float;
        EXP2 = EXP2_float;
        HP1 = HP1_float;
        HP2 = HP2_float;
        return taxi[z][t];
    }
    else {
        EXP1_float += EXP1_float * 0.12;
        EXP1_float = roundUp(EXP1_float);
        expCheck(EXP1_float);
        EXP2_float += EXP2_float * 0.12;
        EXP2_float = roundUp(EXP2_float);
        expCheck(EXP2_float);
        HP1_float += HP1_float * 0.1;
        HP1_float = roundUp(HP1_float);
        healthCheck(HP1_float);
        HP2_float += HP2_float * 0.1;
        HP2_float = roundUp(HP2_float);
        healthCheck(HP2_float);
        EXP1 = EXP1_float;
        EXP2 = EXP2_float;
        HP1 = HP1_float;
        HP2 = HP2_float;
        return SH[z][t];
    }
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    if (strlen(s) < 8) return -1;// s is too short
    if (strlen(s) > 20) return -2; // s is too long
    // s has se
    string str_email(email); // const char * to string
    int pos = str_email.find('@');
    string username = str_email.substr(0, pos); // username in front of @, still in string
    const char* se = username.c_str(); // se is fine
    const char* found = strstr(s, se);
    if (found != nullptr) {
        int sei = found - s;
        return -(300 + sei);
    }
    // s has more than 2 same chars successively
    string str_s(s); // convert s from const char * to string
    int sci;
    if (threeSameChar(str_s) != -999) {
        sci = threeSameChar(s);
        return -(400 + sci);
    }
    // s has no special char
    if (noSpecialChar(str_s) == true) return -5;
    // s is a digit, letter or special char
    if (isValidString(str_s) != -999) return isValidString(str_s);
    else return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq = 0;
    string res;
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0) count++;
        }
        if (count > freq) {
            res = arr_pwds[i];
            freq = count;
        }
        else if (count == freq) {
            if (res.length() < strlen(arr_pwds[i])) res = arr_pwds[i];
            else res = res;
        }
        else res = res;
    }
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], res.c_str()) == 0) return i;
    }
    return -99;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////