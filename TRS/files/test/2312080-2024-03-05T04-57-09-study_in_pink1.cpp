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

// id = 0: hp, id = 1: exp, id = 2: m
int standard(int id, int x) {
    x = max(0, x);
    switch (id)
    {
    case 0: /* hp */
        x = min(666, x);
        break;

    case 1: /* exp */
        x = min(600, x);
        break;

    case 2: /* m */
        x = min(3000, x);
        break;
    }
    return x;
}

// Task 1:
int firstMeet(int& exp1, int& exp2, int e1) {
    // e out of range
    if (e1 < 0 || e1 > 99)
        return -99;

    exp1 = standard(1, exp1);
    exp2 = standard(1, exp2);

    // e1 in [0;3]
    if (e1 <= 3) {
        int added_exp[] = { 29, 45, 75, 149 };
        exp2 = standard(1, exp2 + added_exp[e1]);

        int D = e1 * 3 + exp1 * 7;
        exp1 = standard(1, ceil (exp1 + D / ((D % 2 == 0) ? 200.0 : -100.0)));

    }
    // e1 in [4;99]
    else {
        if (e1 <= 19) exp2 = standard(1, ceil (exp2 + e1 / 4.0 + 19));
        else if (e1 <= 49) exp2 = standard(1, ceil (exp2 + e1 / 9.0 + 21));
        else if (e1 <= 65) exp2 = standard(1, ceil (exp2 + e1 / 16.0 + 17));
        // e1 in [66;99]
        else {
            exp2 = standard(1, ceil (exp2 + e1 / 4.0 + 19));
            if (exp2 > 200 || e1 >= 80) {
                exp2 = standard(1, ceil (exp2 + e1 / 9.0 + 21));
                if (e1 >= 80 && exp2 > 400) {
                    exp2 = standard(1, ceil (exp2 + e1 / 16.0 + 17));
                    exp2 = standard(1, ceil(exp2 + exp2 * 0.15));
                }
            }
        }
        exp1 = standard(1, exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
// unit: %
double calProbability(int EXP) {
    int S = round(sqrt(EXP)); S = S * S;
    return (EXP >= S) ? 100 : (EXP * 1.0 / S + 80) * 100 / 123;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;

    HP1 = standard(0, HP1);
    EXP1 = standard(1, EXP1);
    M1 = standard(2, M1);

    // Path 1:
    double P1 = calProbability(EXP1);

    // Path 2:
    bool isLoop = (E2 % 2 != 0);
    double baseline = M1 / 2;
    int used_money = 0;

    do {
        // Ev1: Food and drink:
        M1 = standard(2, M1 - ((HP1 < 200) ? 150 : 70));
        used_money += ((HP1 < 200) ? 150 : 70);
        HP1 = standard(0, ceil (HP1 + HP1 * ((HP1 < 200) ? 0.3 : 0.1)));

        // Checkpoint
        if ((used_money > baseline && isLoop) || (M1 == 0 && !isLoop))
            break;
        
        // Ev2: Taxi or horse:
        M1 = standard(2, M1 - ((EXP1 < 400) ? 200 : 120));
        used_money += ((EXP1 < 400) ? 200 : 120);
        EXP1 = standard(1, ceil (EXP1 + EXP1 * 0.13));

        // Checkpoint
        if ((used_money > baseline && isLoop) || (M1 == 0 && !isLoop)) 
            break;
        
        // Ev3 :Homeless:
        M1 = standard(2, M1 - ((EXP1 < 300) ? 100 : 120));
        used_money += ((EXP1 < 300) ? 100 : 120);
        EXP1 = standard(1, ceil (0.9 * EXP1));

        // Checkpoint
        if ((used_money > baseline && isLoop) || (M1 == 0 && !isLoop)) 
            break;

    } while (isLoop);

    HP1 = standard(0, ceil (0.83 * HP1));
    EXP1 = standard(1, ceil (1.17 * EXP1));

    double P2 = calProbability(EXP1);

    // path 3:
    int prob[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int P3 = prob[(E2 < 10) ? E2 : ((E2 % 10 + E2 / 10) % 10)];

    if (P1 == 100 && P2 == 100 && P3 == 100) 
        EXP1 = standard(1, ceil (EXP1 * 0.75));
    else {
        double P = (P1 + P2 + P3) / 3.0;
        HP1 = standard(0, ceil (HP1 - HP1 * ((P < 50) ? 0.15 : 0.1)));
        EXP1 = standard(1, ceil (EXP1 + EXP1 * ((P < 50) ? 0.15 : 0.2)));
    }


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;

    HP1 = standard(0, HP1);
    EXP1 = standard(1, EXP1);
    HP2 = standard(0, HP2);
    EXP2 = standard(1, EXP2);

    int taxi_matrix[10][10] = {};

    // right-cross: row + col; = const, left-cross: row - col = const
    const int inf = 1e9;

    // initial value for easy to find min-max
    int max_left[50], max_right[50];
    for (int i = 0; i < 50; i++)
        max_left[i] = max_right[i] = -inf;

    int meet_i = 0, meet_j = 0;

    // Init taxi matrix 
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {

            taxi_matrix[i][j] = ((E3 * j) + i * 2) * (i - j);
            max_right[i + j] = max(max_right[i + j], taxi_matrix[i][j]);
            max_left[j - i + 10] = (max_left[j - i + 10], taxi_matrix[i][j]);

            if (taxi_matrix[i][j] > E3 * 2)
                meet_i++;
            if (taxi_matrix[i][j] < -E3)
                meet_j++;
        }

    // Process meeting point i and j
    while (meet_i >= 10)
        meet_i = meet_i % 10 + meet_i / 10;
    while (meet_j >= 10)
        meet_j = meet_j % 10 + meet_j / 10;

    int sher_point = abs(max(max_right[meet_i + meet_j], max_left[meet_j - meet_i + 10]));

    EXP1 = standard(1, ceil (EXP1 + EXP1 * 0.12 * ((abs(taxi_matrix[meet_i][meet_j]) > sher_point) ? -1 : 1)));
    EXP2 = standard(1, ceil (EXP2 + EXP2 * 0.12 * ((abs(taxi_matrix[meet_i][meet_j]) > sher_point) ? -1 : 1)));
    HP1 = standard(0, ceil (HP1 + HP1 * 0.1 * ((abs(taxi_matrix[meet_i][meet_j]) > sher_point) ? -1 : 1)));
    HP2 = standard(0, ceil (HP2 + HP2 * 0.1 * ((abs(taxi_matrix[meet_i][meet_j]) > sher_point) ? -1 : 1)));

    return (abs(taxi_matrix[meet_i][meet_j]) > sher_point) ? taxi_matrix[meet_i][meet_j] : sher_point;
}

// Task 4
bool isValidChar(char ch) {
    if (isalpha(ch) || isdigit(ch) || ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!')
        return true;
    return false;
}

int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    // Covert to string to handle
    string str = "", se = "";
    for (int i = 0; i < strlen(s); i++)
        str += s[i];

    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@')
            break;
        se += email[i];
    }

    if (str.length() < 8)
        return -1;
    if (str.length() > 20)
        return -2;

    if (se.length() == 0)
        return -300;

    int special_char = 0;
    int number_of_same = 0;

    for (int i = 0; i < str.length(); i++) 
        if (str[i] == se[0]) 
            if (str.substr(i, se.length()) == se) {
                return -(300 + i);
            }
        
    for (int i = 0 ; i < str.length() ; i ++)
        if (i > 0 && str[i] == str[i - 1]) {
            number_of_same++;
            if (number_of_same == 2)
                return -(400 + i - 2);
        }
        else
            number_of_same = 0;

    for (int i = 0 ; i < str.length() ; i ++)
        if (str[i] == '@' || str[i] == '#' || str[i] == '%' || str[i] == '$' || str[i] == '!')
            special_char++;

    if (!special_char)
        return -5;

    for (int i = 0 ; i < str.length() ; i ++) {
        if (!isValidChar(str[i]))
            return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    int cnt[100] = {};

    for (int i = 0 ; i < num_pwds ; i ++) {
        for (int j = 0 ; j < num_pwds ; j ++)
            if (!strcmp(arr_pwds[i], arr_pwds[j]))
                cnt[i] ++;
    }
    
    int index = 0;

    for (int i = 1 ; i < num_pwds ; i ++) 
        if ((cnt[i] > cnt[index]) || cnt[i] == cnt[index] && strlen(arr_pwds[i]) > strlen(arr_pwds[index]))
            index = i;
    
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////