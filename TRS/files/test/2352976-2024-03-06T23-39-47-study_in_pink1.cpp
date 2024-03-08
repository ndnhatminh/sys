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
int checkValidExp(float variable) {
    variable = ceil(variable);
    variable = variable > 600 ? 600 : variable;
    variable = variable < 0 ? 0 : variable;
    return static_cast<int>(variable);
}

int checkValidHp(float variable) {
    variable = ceil(variable);
    variable = variable > 666 ? 666 : variable;
    variable = variable < 0 ? 0 : variable;
    return static_cast<int>(variable);
}

int checkValidMoney(float variable) {
    variable = ceil(variable);
    variable = variable > 3000 ? 3000 : variable;
    variable = variable < 0 ? 0 : variable;
    return static_cast<int>(variable);
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99;
    } else {
        exp1 = checkValidExp(exp1);
        exp2 = checkValidExp(exp2);
        int d = 0;
        if (e1 >= 0 && e1 <= 3) {
            if (e1 == 0) {
                exp2 = checkValidExp(exp2 + 29);
            } else if (e1 == 1) {
                exp2 = checkValidExp(exp2 + 45);
            } else if (e1 == 2) {
                exp2 = checkValidExp(exp2 + 75);
            } else if (e1 == 3) {
                exp2 = checkValidExp(exp2 + 29 + 45 + 75);
            }
            d = e1 * 3 + exp1 * 7;
            if (int(d) % 2 == 0) {
                exp1 = checkValidExp(float(exp1) + float(d) / 200);
            } else {
                exp1 = checkValidExp(float(exp1) - float(d) / 100);
            }
        }

        if (e1 >= 4 && e1 <= 99) {
            if (e1 <= 19) exp2 = checkValidExp(float(exp2) + (float(e1) / 4 + 19));
            if (e1 >= 20 && e1 <= 49) {
                exp2 = checkValidExp(float(exp2) + (float(e1) / 9 + 21));
            }
            if (e1 >= 50 && e1 <= 65) exp2 = checkValidExp(float(exp2) + (float(e1) / 16 + 17));
            if (e1 >= 66 && e1 <= 79) {
                exp2 = checkValidExp(float(exp2) + (float(e1) / 4 + 19));
                if (exp2 > 200) exp2 = checkValidExp(float(exp2) + (float(e1) / 9 + 21));
            }
            if (e1 >= 80) {
                exp2 = checkValidExp(float(exp2) + (float(e1) / 4 + 19));
                exp2 = checkValidExp(float(exp2) + (float(e1) / 9 + 21));
                if (exp2 > 400) {
                    exp2 = checkValidExp(float(exp2) + (float(e1) / 16 + 17));
                    exp2 = checkValidExp(float(exp2 * 1.15));
                }
            }
            exp1 = checkValidExp(exp1 - e1);

        }
//    cout << "EXP1_TEST:" << exp1 << endl;
//    cout << "E_1:" << e1 << endl;
//    cout << "EXP2_TEST:" << exp2 << endl;
        return exp1 + exp2;
    }
}

// Task 2
int road3check(int n) {
    if (n / 10 == 0) {
        return n;
    } else {
        return ((n % 10) + (n / 10)) % 10;
    }
}
int chinhPhuong(int n)
{
    float sqrt_n = sqrt(n);
    int floor_sqrt_n = pow(floor(float(sqrt_n)),2);
    int ceil_sqrt_n = pow(ceil(float(sqrt_n)),2);
    if (n - floor_sqrt_n >= n - ceil_sqrt_n)
    {
        return ceil_sqrt_n;
    }
    else return floor_sqrt_n;
}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {

    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99;
    } else {
        EXP1 = checkValidExp(EXP1);
        M1 = checkValidMoney(M1);
        HP1 = checkValidHp(HP1);
        float P1 = 0;
        int s = round(sqrt(EXP1)) * round(sqrt(EXP1));
        if (int(EXP1) >= s) {
            P1 = 1;
        } else {
            P1 = float((float(EXP1) / s + 80) / 123);
        }
        int cost = 0;
        int initial_cost = M1;
        if (E2 % 2 != 0) {

            do {
                if (initial_cost == 0) break;
                if (HP1 < 200) {
                    HP1 = checkValidHp(float(HP1 * 1.3));
                    M1 = checkValidMoney(float(M1) - 150);
                    cost += 150;
                } else {
                    HP1 = checkValidHp(float(HP1 * 1.1));
                    M1 = checkValidMoney(float(M1) - 70);
                    cost += 70;
                }
                if (cost > 0.5 * initial_cost) break;
                if (EXP1 < 400) {
                    M1 = checkValidMoney(float(M1) - 200);
                    EXP1 = checkValidExp(float(EXP1 * 1.13));
                    cost += 200;
                } else {
                    M1 = checkValidMoney(float(M1) - 120);
                    EXP1 = checkValidExp(float(EXP1 * 1.13));
                    cost += 120;
                }
                if (cost > 0.5 * initial_cost) break;
                if (EXP1 < 300) {
                    M1 = checkValidMoney(float(M1) - 100);
                    EXP1 = checkValidExp(float(EXP1 * 0.9));
                    cost += 100;
                } else {
                    M1 = checkValidMoney(float(M1) - 120);
                    EXP1 = checkValidExp(float(EXP1 * 0.9));
                    cost += 120;
                }
                if (cost > 0.5 * initial_cost) break;
            } while (cost <= 0.5 * initial_cost);
            EXP1 = checkValidExp(EXP1 * 1.17);
            HP1 = checkValidHp(HP1 * 0.83);
        } else {
            do {
                if (initial_cost == 0) break;
                if (HP1 < 200) {
                    HP1 = checkValidHp(float(HP1 * 1.3));
                    M1 = checkValidMoney(float(M1) - 150);
                    if (M1 <= 0) break;
                } else {
                    HP1 = checkValidHp(float(HP1 * 1.1));
                    M1 = checkValidMoney(float(M1) - 70);
                    if (M1 <= 0) break;
                }
                if (EXP1 < 400) {
                    M1 = checkValidMoney(float(M1) - 200);
                    EXP1 = checkValidExp(float(EXP1 * 1.13));
                    if (M1 <= 0) break;
                } else {
                    M1 = checkValidMoney(float(M1) - 120);
                    EXP1 = checkValidExp(float(EXP1 * 1.13));
                    if (M1 <= 0) break;
                }
                if (EXP1 < 300) {
                    M1 = checkValidMoney(float(M1) - 100);
                    EXP1 = checkValidExp(float(EXP1 * 0.9));
                    if (M1 <= 0) break;
                } else {
                    M1 = checkValidMoney(float(M1) - 120);
                    EXP1 = checkValidExp(float(EXP1 * 0.9));
                    if (M1 <= 0) break;
                }
                break;
            } while (M1 > 0);
            EXP1 = checkValidExp(EXP1 * 1.17);
            HP1 = checkValidHp(HP1 * 0.83);
        }
        float P2 = 0;
        int s2 = round(sqrt(EXP1)) * round(sqrt(EXP1));
        if (int(EXP1) >= s2) {
            P2 = 1;
        } else {
            P2 = float((float(EXP1) / s2 + 80) / 123);
        }

        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        float P3 = P[road3check(E2)];
        P3 = float(P3 / 100);
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = checkValidExp(EXP1 * 0.75);
        } else {
            float average = (P1 + P2 + P3) / 3;
            if (average < 0.5) {
                HP1 = checkValidHp(HP1 * 0.85);
                EXP1 = checkValidExp(EXP1 * 1.15);
            } else {
                HP1 = checkValidHp(HP1 * 0.9);
                EXP1 = checkValidExp(EXP1 * 1.2);
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int sum4(int n) {
    int x =  (n % 10) + (n / 10);
    return (x % 10) + (x / 10);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if (E3 < 0 || E3 > 99) {
        return -99;
    } else {
        EXP1 = checkValidExp(EXP1);
        EXP2 = checkValidExp(EXP2);
        HP1 = checkValidHp(HP1);
        HP2 = checkValidHp(HP2);
        int map[10][10] = {};
        int max_diagonal[10][10] = {};
        int sher_wat_point = 0;
        int count_positive = 0;
        int count_negative = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (map[i][j] > E3 * 2) count_positive++;
                if (map[i][j] < E3 * (-1)) count_negative++;
            }
        }
        int row = sum4(count_positive);
        int col = sum4(count_negative);
        int left_up_row = row, right_up_row = row, left_down_row = row, right_down_row = row;
        int left_up_col = col, right_up_col = col, left_down_col = col, right_down_col = col;
        long long max = -10000000000000;
        if ( map[row][col] > max) max = map[row][col];
        while (left_up_col > 0 && left_up_row > 0) {
            left_up_col -= 1;
            left_up_row -= 1;
            if (map[left_up_row][left_up_col] > max) max = map[left_up_row][left_up_col];
        }
        while (right_up_row > 0 && right_up_col < 9) {
            right_up_row -= 1;
            right_up_col += 1;
            if (map[right_up_row][right_up_col] > max) max = map[right_up_row][right_up_col];
        }
        while (left_down_row < 9 && left_down_col > 0) {
            left_down_col -= 1;
            left_down_row += 1;
            if (map[left_down_row][left_down_col] > max) max = map[left_down_row][left_down_col];
        }
        while (right_down_col < 9 && right_down_row < 9) {
            right_down_col += 1;
            right_down_row += 1;
            if (map[right_down_row][right_down_col] > max) max = map[right_down_row][right_down_col];
        }
        if (abs(map[row][col]) > abs(max)) {
            EXP1 = checkValidExp(float(EXP1 * 0.88));
            HP1 = checkValidHp(float(HP1 * 0.9));
            EXP2 = checkValidExp(float(EXP2 * 0.88));
            HP2 = checkValidHp(float(HP2 * 0.9));
        } else {
            EXP1 = checkValidExp(float(EXP1 * 1.12));
            HP1 = checkValidHp(float(HP1 * 1.1));
            EXP2 = checkValidExp(float(EXP2 * 1.12));
            HP2 = checkValidHp(float(HP2 * 1.1));
        }
        if (abs(map[row][col]) > abs(max)) {
            return map[row][col];
        } else {
            return max;
        }
    }
}

// Task 4
int emailValid(const string &email)
{
    int count = 0;
    int index = 0;
    if ( email.length() <= 100)
    {
        for (int i = 0; i < email.length() ; i++)
        {
            if ( email[i] == '@') {
                count++;
                if (index == 0) index = i;
            }
        }
        if ( count != 1) return -1;
        else return index;
    }
    else return -1;
}
int contain_se(const string &se, const string &pass_processed) {
    if (se.empty()) {
        return 0; // Indicate not found or not applicable.
    }

    size_t index = pass_processed.find(se);
    if (index != string::npos) {
        return static_cast<int>(index); // Found the substring, return its index.
    } else {
        return -1; // Indicate not found with -1.
    }
}
int contain_duplicate(const string &pass_processed)
{
    int flag = 0;
    for ( int i = 0; i < pass_processed.length()-2;i++)
    {
        if (( pass_processed[i] == pass_processed[i+1] ) && (pass_processed[i+1] == pass_processed[i+2])) {
            return i;
        }
        else flag += 1;
    }
    if ( flag != 0 ) return -1;
    return 0;
}
int contain_special(const string& pass_processed) {
    int count = 0;
    for (size_t i = 0; i < pass_processed.length(); i++) {
        if (pass_processed[i] == '@' || pass_processed[i] == '#' ||
            pass_processed[i] == '%' || pass_processed[i] == '$' ||
            pass_processed[i] == '!') {
            count++;
        }
    }
    if (count == 0)
    {
        return -5;
    }
    else return -1;
}

int passValid2(const string& pass_processed) {
    for (size_t i = 0; i < pass_processed.length(); ++i) {
        char c = pass_processed[i];
        if (!(isdigit(c) || isupper(c) || islower(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return static_cast<int>(i);
        }
    }
    return -1;
}
int checkPassword(const char * s, const char * email) { //Yeu cau là tuần tự
    // TODO: Complete this function
    string email_processed = email;
    string pass_processed = s;
    int flag = 0;
    if (emailValid(email_processed) != -1)
    {
        string se = email_processed.substr(0, emailValid(email_processed));
        if ( pass_processed.length() < 8) return -1;
        if ( pass_processed.length() > 20) return -2;
        if (contain_se(se,pass_processed) != -1 ) return -(300 + contain_se(se,pass_processed));
        if (contain_duplicate(pass_processed) != -1) return -(400+ contain_duplicate(pass_processed));
        if (contain_special(pass_processed) != -1) return contain_special(pass_processed);
        if ( passValid2(pass_processed) != -1 ) return passValid2(pass_processed);
        else return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max = 0;
    int max_index = -1;
    int max_string_length = 0;
    string string_max_freq;
    string string_max_length;
    for (int i = 0; i < num_pwds; i++) {
        int hz = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                hz++;
            }
        }
        if ( hz > max || (hz == max && max_string_length < strlen(arr_pwds[i])))
        {
            max = hz;
            max_string_length = strlen(arr_pwds[i]);
            max_index = i;
        }
    }
    return max_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////