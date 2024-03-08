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

// Function for validating stats value
void validate(int& stat, int max) {
    if (stat < 0)
        stat = 0;
    else if (stat > max)
        stat = max;
}

// Function for rounding
int round_up(double x) {
    if (x-int(x) > 0.0001)
        return int(x) + 1;
    return int(x);
}

// Function for locating a substring
int locate(string str1, string str2) {
    bool found = false;
    int n;
    for (n = 0; n <= str1.size() - str2.size(); n++) {
        if (str1.substr(n, str2.size()) == str2) {
            found = true;
            break;
        }
    }
    if (found) return n;
    return -1;
}

// Funtion for locating an element
int find(string array[], string element, int num) {
    bool found = false;
    int n;
    for (n = 0; n <= num - 1; n++) {
        if (array[n] == element) {
            found = true;
            break;
        }
    }
    if (found) return n;
    return -1;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    //4.1.1: Case 1
    if (e1 <= 3) {
        int points[] = {29, 45, 75, 29+45+75}; //list of points exp2 gains for every information explained
        exp2 += points[e1];
        int D = e1*3 + exp1*7;
        (D % 2 == 0) ? (exp1 += round_up(D/200.0)) : (exp1 = round_up(exp1 - D/100.0)); //points exp1 gains/loses as the guess is correct/incorrect
    //4.1.2: Case 2
    } else {
        if (e1 <= 19)
            exp2 += round_up(e1/4.0 + 19);
        else if (e1 <= 49)
            exp2 += round_up(e1/9.0 + 21);
        else if (e1 <= 65)
            exp2 += round_up(e1/16.0 + 17);
        else if (e1 <= 79) {
            exp2 += round_up(e1/4.0 + 19);
            if (exp2 > 200)
                exp2 += round_up(e1/9.0 + 21);
        } else {
            exp2 += round_up(e1/4.0 + 19);
            exp2 += round_up(e1/9.0 + 21);
            if (exp2 > 400)
                exp2 = round_up(1.15*round_up(exp2 + e1/16.0 + 17));
        }
        exp1 -= e1;
    }
    validate(exp1, 600);
    validate(exp2, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    //4.2.1: Road 1
    int S = pow(round(sqrt(EXP1)), 2);
    double P1;
    (EXP1 >= S) ? (P1 = 100) : (P1 = 100*(double(EXP1/S) + 80)/123);
    //4.2.2: Road 2
    bool odd;
    (E2 % 2 != 0) ? (odd = true) : (odd = false);
    if (M1 != 0) {
        int M1_0 = M1; //record the initial value of M1 for comparision later on
        do {
            //go to grocery store
            if (HP1 < 200) {
                HP1 = round_up(1.3*HP1);
                M1 -= 150;
            } else {
                HP1 = round_up(1.1*HP1);
                M1 -= 70;
            }
            if ((odd && M1_0 - 2*M1 > 0) || (!odd && M1 <= 0)) break;
            //rent a vehicle
            (EXP1 < 400) ? (M1 -= 200) : (M1 -= 120);
            EXP1 = round_up(1.13*EXP1);
            if ((odd && M1_0 - 2*M1 > 0) || (!odd && M1 <= 0)) break;
            //trust a homeless
            (EXP1 < 300) ? (M1 -= 100) : (M1 -= 120);
            EXP1 = round_up(0.9*EXP1);
            if ((odd && M1_0 - 2*M1 > 0) || (!odd && M1 <= 0)) break;
        } while (odd);
    }
    validate(HP1, 666);
    HP1 = round_up(0.83*HP1);
    EXP1 = round_up(1.17*EXP1);
    validate(EXP1, 600);
    S = pow(round(sqrt(EXP1)), 2);
    double P2;
    (EXP1 >= S) ? (P2 = 100) : (P2 = 100*(double(EXP1/S) + 80)/123);
    //4.2.3: Road 3
    int P3[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2/10 + E2%10) % 10;
    //Overall probality & Final stats
    if (P1 + P2 + P3[i] == 300)
        EXP1 = round_up(0.75*EXP1);
    else {
        if (P1 + P2 + P3[i] < 150) {
            HP1 = round_up(0.85*HP1);
            EXP1 = round_up(1.15*EXP1);
        } else {
            HP1 = round_up(0.9*HP1);
            EXP1 = round_up(1.2*EXP1);
        }
        validate(EXP1, 600);
    }
    validate(M1, 3000);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int i, j, n;
    // Chase map & Meeting location
    int taxi[10][10];
    int row = 0, col = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            taxi[i][j] = ((E3*j) + (i*2)) * (i-j);
            if (taxi[i][j] > E3*2)
                row++;
            else if (taxi[i][j] < -E3)
                col++;
        }
    }
    while (row > 9)
        row = row/10 + row%10;
    while (col > 9)
        col = col/10 + col%10;
    // Left diagonal
    int st_row, st_col, en_row, en_col;
    if (col > row) {
        st_row = 0;
        en_row = 9 - (col-row);
        st_col = col-row;
        en_col = 9;
    } else {
        st_row = -(col-row);
        en_row = 9;
        st_col = 0;
        en_col = 9 + (col-row);
    }
    int max = taxi[st_row][st_col];
    for (i = st_row + 1, j = st_col + 1; i <= en_row, j <= en_col; i++, j++)
        if (max < taxi[i][j])
            max = taxi[i][j];
    // Right diagonal
    if (col < -row + 9) {
        st_row = 0;
        en_row = col+row;
        st_col = col+row;
        en_col = 0;
    } else {
        st_row = (col+row) - 9;
        en_row = 9;
        st_col = 9;
        en_col = (col+row) - 9;
    }
    for (i = st_row, j = st_col; i <= en_row, j >= en_col; i++, j--)
        if (max < taxi[i][j])
            max = taxi[i][j];
    // Will they catch the taxi?
    int guys = abs(max);
    if (abs(taxi[row][col]) > guys) {
        EXP1 = round_up(0.88*EXP1);
        EXP2 = round_up(0.88*EXP2);
        HP1 = round_up(0.9*HP1);
        HP2 = round_up(0.9*HP2);
        return taxi[row][col];
    } else {
        EXP1 = round_up(1.12*EXP1);
        validate(EXP1, 600);
        EXP2 = round_up(1.12*EXP2);
        validate(EXP2, 600);
        HP1 = round_up(1.1*HP1);
        validate(HP1, 666);
        HP2 = round_up(1.1*HP2);
        validate(HP2, 666);
        return guys;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s0 = s;
    string email0 = email;
    // Less than Min
    if (s0.size() < 8)
        return -1;
    // More than Max
    if (s0.size() > 20)
        return -2;
    // Contains se
    int n = locate(email0, "@");
    string se = email0.substr(0, n);
    if (locate(s0, se) != -1)
        return -(300 + locate(s0, se));
    // Have more than 2 identical characters next to each other
    for (int i = 0; i <= s0.size() - 3; i++)
        if ((s0[i] == s0[i+1]) && (s0[i] == s0[i+2]))
            return -(400 + i);
    // Does not contain special characters
    if (strpbrk(s, "@#%$!") == NULL)
        return -5;
    // Other violations
    for (int i = 0; i <= s0.size() - 1; i++)
        if (!isalpha(s0[i]) && !isdigit(s0[i]) && (strchr("@#%$!", s[i]) == NULL))
            return i;
    // Valid
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int n = num_pwds;
    string pwds[n];
    for (int i = 0; i <= n-1; i++)
        pwds[i] = arr_pwds[i];
    // Record all distinct passwords
    int distinct = 0;
    string record[30];
    for (int i = 0; i <= n-1; i++)
        if (find(record, pwds[i], distinct) == -1) {
            record[distinct] = pwds[i];
            distinct++;
        }
    // Count passwords' occurence & find its max
    int count;
    int occur_max = 0;
    int occur[distinct];
    for (int i = 0; i <= distinct-1; i++) {
        count = 0;
        for (int j = 0; j <= n-1; j++)
            if (record[i] == pwds[j])
                count++;
        occur[i] = count;
        if (occur_max < occur[i])
            occur_max = occur[i];
    }
    // Find the longest password
    int len_max = 0;
    int index;
    for (int i = 0; i <= distinct-1; i++) {
        if (occur[i] == occur_max && len_max < record[i].size()) {
            len_max = record[i].size();
            index = i;
        }
    }
    int correct = find(pwds, record[index], n);
    return correct;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////