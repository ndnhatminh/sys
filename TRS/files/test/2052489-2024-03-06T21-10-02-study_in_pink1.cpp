#include "study_in_pink1.h"

bool readFile(const string& filename,
              int& HP1,
              int& HP2,
              int& EXP1,
              int& EXP2,
              int& M1,
              int& M2,
              int& E1,
              int& E2,
              int& E3) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Utility functions
int check_hp(int HP) {
    if (HP < 0)
        return 0;
    if (HP > 666)
        return 666;
    return HP;
}

int check_exp(int EXP) {
    if (EXP < 0)
        return 0;
    if (EXP > 600)
        return 600;
    return EXP;
}

int check_m(int M) {
    if (M < 0)
        return 0;
    if (M > 3000)
        return 3000;
    return M;
}

int find_nearest_square(int n) {
    double sq_num = sqrt((float)n);
    int lower = floor(sq_num);
    int upper = ceil(sq_num);

    lower *= lower;
    upper *= upper;

    if ((n - lower) < (upper - n))
        return lower;
    return upper;
}

int find_left_diag_max(int x, int y, int mat[10][10]) {
    if (x < 0 || x > 10 || y < 0 || y > 10)
        return 0;
    int i, j, ret = mat[x][y];
    i = x, j = y;
    while (i >= 0 && j >= 0) {
        ret = max(ret, mat[i][j]);
        i--;
        j--;
    }

    i = x, j = y;
    while (i < 10 && j < 10) {
        ret = max(ret, mat[i][j]);
        i++;
        j++;
    }
    return ret;
}

int find_right_diag_max(int x, int y, int mat[10][10]) {
    if (x < 0 || x > 10 || y < 0 || y > 10)
        return 0;
    int i, j, ret = mat[x][y];

    i = x, j = y;
    while (i >= 0 && j <= 9) {
        ret = max(ret, mat[i][j]);
        i--;
        j++;
    }

    i = x, j = y;
    while (i <= 9 && j >= 0) {
        ret = max(ret, mat[i][j]);
        i++;
        j--;
    }
    return ret;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    // Check input
    if (e1 < 0 || e1 > 99)
        return -99;
    exp1 = check_exp(exp1);
    exp2 = check_exp(exp2);

    if (e1 >= 0 && e1 <= 3) {
        // Case 1
        int exp2_add_amount[] = {29, 45, 75};

        if (e1 != 3) {
            exp2 += exp2_add_amount[e1];
            exp2 = check_exp(exp2);
        } else {
            // Information 1
            exp2 += ceil(exp2_add_amount[0]);
            exp2 = check_exp(exp2);

            // Information 2
            exp2 += ceil(exp2_add_amount[1]);
            exp2 = check_exp(exp2);

            // Information 3
            exp2 += ceil(exp2_add_amount[2]);
            exp2 = check_exp(exp2);
        }

        int d = e1 * 3 + exp1 * 7;
        exp1 += (d % 2 == 0 ? ceil((float)d / 200) : ceil((float)-d / 100));
        exp1 = check_exp(exp1);
    }
    // Case 2
    if (e1 >= 4 && e1 <= 19) {
        // Information 1
        exp2 += ceil((float)e1 / 4 + 19);
        exp2 = check_exp(exp2);
    }
    if (e1 >= 20 && e1 <= 49) {
        // Information 2
        exp2 += ceil((float)e1 / 9 + 21);
        exp2 = check_exp(exp2);
    }
    if (e1 >= 50 && e1 <= 65) {
        // Information 3
        exp2 += ceil((float)e1 / 16 + 17);
        exp2 = check_exp(exp2);
    }
    if (e1 >= 66 && e1 <= 79) {
        // Information 4
        //
        // Information 1
        exp2 += ceil((float)e1 / 4 + 19);
        exp2 = check_exp(exp2);

        if (exp2 > 200) {
            // Information 2
            exp2 += ceil((float)e1 / 9 + 21);
            exp2 = check_exp(exp2);
        }
    }
    if (e1 >= 80 && e1 <= 99) {
        // Information 5
        //
        // Information 1
        exp2 += ceil((float)e1 / 4 + 19);
        exp2 = check_exp(exp2);

        // Information 2
        exp2 += ceil((float)e1 / 9 + 21);
        exp2 = check_exp(exp2);

        if (exp2 > 400) {
            // Information 3
            exp2 += ceil((float)e1 / 16 + 17);
            exp2 = check_exp(exp2);

            // Bonus 15% exp2
            exp2 += ceil((float)exp2 * 0.15);
            exp2 = check_exp(exp2);
        }
    }
    if (e1 > 3) {
        exp1 -= e1;
        exp1 = check_exp(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    // Check input
    if (E2 < 0 || E2 > 99)
        return -99;

    HP1 = check_hp(HP1);
    EXP1 = check_exp(EXP1);
    M1 = check_m(M1);
    // Probabilities for each Road
    double P1, P2, P3;
    int temp_HP1 = HP1;
    int temp_M1 = M1;

start_mission:

    int temp_EXP1 = EXP1;

    // Road 1
    int s = find_nearest_square(EXP1);
    if (EXP1 >= s)
        P1 = 1.0;
    else
        P1 = (float)((float)EXP1 / s + 80) / 123;

    // Road 2
    int M1_threshold = ceil((float)M1 / 2);

start_route:
    // Grocery
    if (HP1 < 200) {
        HP1 += ceil((float)HP1 * 0.3);
        HP1 = check_hp(HP1);

        M1 -= 150;
        M1 = check_m(M1);
    } else {
        HP1 += ceil((float)HP1 * 0.1);
        HP1 = check_hp(HP1);

        M1 -= 70;
        M1 = check_m(M1);
    }
    if ((E2 % 2 != 0 && M1 < M1_threshold) || (E2 % 2 == 0 && M1 == 0))
        goto end_route;

    // Transportation
    if (EXP1 < 400) {
        // Taxi Cost
        M1 -= 200;
        M1 = check_m(M1);
    } else {
        // Horse Carriage Cost
        M1 -= 120;
        M1 = check_m(M1);
    }
    EXP1 += ceil((float)EXP1 * 0.13);
    EXP1 = check_exp(EXP1);
    if ((E2 % 2 != 0 && M1 < M1_threshold) || (E2 % 2 == 0 && M1 == 0))
        goto end_route;

    // Homeless Guide
    if (EXP1 < 300) {
        M1 -= 100;
        M1 = check_m(M1);
    } else {
        M1 -= 120;
        M1 = check_m(M1);
    }
    EXP1 += ceil((float)-EXP1 * 0.1);
    EXP1 = check_exp(EXP1);
    if ((E2 % 2 != 0 && M1 < M1_threshold) || (E2 % 2 == 0 && M1 == 0))
        goto end_route;

    if (E2 % 2 != 0 && M1 > M1_threshold)
        goto start_route;
end_route:
    HP1 += ceil((float)-HP1 * 0.17);
    HP1 = check_hp(HP1);

    EXP1 += ceil((float)EXP1 * 0.17);
    EXP1 = check_exp(EXP1);

    // Probability of road 2
    s = find_nearest_square(EXP1);
    if (EXP1 >= s) {
        P2 = 1.0;
    } else {
        P2 = (float)((float)EXP1 / s + 80) / 123;
    }

    // Road 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int index;
    if (E2 >= 0 && E2 <= 9)
        index = E2;
    else {
        index = (int)(E2 / 10) + (int)(E2 % 10);
        index = (int)(index % 10);
    }
    P3 = (float)P[index] / 100;

    if (P1 + P2 + P3 == 3.0) {
        // HP1 = temp_HP1;
        // M1 = temp_M1;
        // EXP1 = temp_EXP1;

        // Sherlock made mistake
        EXP1 += ceil((float)-EXP1 * 0.25);
        EXP1 = check_exp(EXP1);

        // goto ?
        // goto start_mission;  // Recalculate

    } else {
        float prob = (P1 + P2 + P3) / 3;
        if (prob < 0.5) {
            HP1 += ceil((float)-HP1 * 0.15);
            HP1 = check_hp(HP1);

            EXP1 += ceil((float)EXP1 * 0.15);
            EXP1 = check_exp(EXP1);
        } else {
            HP1 += ceil((float)-HP1 * 0.1);
            HP1 = check_hp(HP1);

            EXP1 += ceil((float)EXP1 * 0.2);
            EXP1 = check_exp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    // Check input
    if (E3 < 0 || E3 > 99)
        return -99;
    HP1 = check_hp(HP1);
    EXP1 = check_exp(EXP1);
    HP2 = check_hp(HP2);
    EXP2 = check_exp(EXP2);

    // Initialize grade matrix
    int map[10][10];
    int x, y;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            x += map[i][j] > (E3 * 2) ? 1 : 0;
            y += map[i][j] < (-E3) ? 1 : 0;
        }

    while (x >= 10 || y >= 10) {
        if (x >= 10)
            x = (int)(x / 10) + (int)(x % 10);
        if (y >= 0)
            y = (int)(y / 10) + (int)(y % 10);
    }

    int taxi_grade = map[x][y];
    int sw_grade =
        max(find_left_diag_max(x, y, map), find_right_diag_max(x, y, map));

    if (abs(taxi_grade) > abs(sw_grade)) {
        // fail taxi catch
        EXP1 += ceil((float)-EXP1 * 0.12);
        EXP1 = check_exp(EXP1);

        HP1 += ceil((float)-HP1 * 0.1);
        HP1 = check_hp(HP1);

        EXP2 += ceil((float)-EXP2 * 0.12);
        EXP2 = check_exp(EXP2);

        HP2 += ceil((float)-HP2 * 0.1);
        HP2 = check_hp(HP2);
    } else {
        // successful taxi catch
        EXP1 += ceil((float)EXP1 * 0.12);
        EXP1 = check_exp(EXP1);

        HP1 += ceil((float)HP1 * 0.1);
        HP1 = check_hp(HP1);

        EXP2 += ceil((float)EXP2 * 0.12);
        EXP2 = check_exp(EXP2);

        HP2 += ceil((float)HP2 * 0.1);
        HP2 = check_hp(HP2);
    }
    return (abs(taxi_grade) > abs(sw_grade) ? taxi_grade : sw_grade);
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string str_s(s), str_email(email);
    string se = str_email.substr(0, str_email.find("@"));
    int sei = str_s.find(se);

    if (str_s.length() < 8)
        return -1;
    if (str_s.length() > 20)
        return -2;
    if (sei != -1)
        return -(300 + sei);

    for (int i = 0; i < str_s.length() - 2; i++)
        if (str_s[i] == str_s[i + 1] && str_s[i] == str_s[i + 2]) {
            // Duplicate char
            return -(400 + i);
        }

    bool ur_my_special = false;  // JJK ref I guess
    char curr;
    for (int i = 0; i < str_s.length(); i++) {
        curr = str_s[i];
        if (curr == '@' || curr == '#' || curr == '%' || curr == '$' ||
            curr == '!')
            break;
        if (i == str_s.length() - 1)
            return -5;
    }

    for (int i = 0; i < str_s.length(); i++) {
        curr = str_s[i];
        if (!((curr >= 48 && curr <= 57) || (curr >= 65 && curr <= 90) ||
              (curr >= 97 && curr <= 122) || curr == '@' || curr == '#' ||
              curr == '%' || curr == '$' || curr == '!')) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int MAX_ELE = 30;
    bool visited[num_pwds];
    for (int i = 0; i < num_pwds; i++)
        visited[i] = false;

    int count_mat[num_pwds];
    for (int i = 0; i < num_pwds; i++)
        count_mat[i] = 0;

    for (int i = 0; i < num_pwds; i++) {
        if (visited[i] == false) {
            int count = 1;
            for (int j = i + 1; j < num_pwds; j++) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    count++;
                    visited[j] = true;
                }
            }
            count_mat[i] = count;
        }
    }

    int idx = 0;
    int max_length = strlen(arr_pwds[idx]);
    for (int i = 0; i < num_pwds; i++) {
        if (count_mat[i] > count_mat[idx]) {
            idx = i;
            max_length = strlen(arr_pwds[i]);
        }
        if (count_mat[i] == count_mat[idx] &&
            strlen(arr_pwds[i]) > strlen((arr_pwds[idx]))) {
            idx = i;
            max_length = strlen(arr_pwds[i]);
        }
    }
    return idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
