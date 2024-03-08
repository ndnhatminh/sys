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

int custom_ceil(float num) {
    return ceil(round(num * 100) / 100);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) {
        return -99;
    }
    if (e1 <= 3 && e1 >= 0) {
        if (e1 == 0) {
            exp2 += 29;
        }
        else if (e1 == 1) {
            exp2 += 45;
            
        }
        else if (e1 == 2) {
            exp2 += 75    ;
            
        }
        else if (e1 == 3) {
            exp2 += 29 + 45 + 75;
            
        }
        if (exp2 > 600) {
            exp2 = 600;
        } 
        int D = e1 * 3 + exp1 * 7;
        if( D % 2 == 0) {
            exp1 = custom_ceil(exp1 + float(D) / 200);
            if (exp1 > 600) {
                exp1 = 600;
            } 
        }
        else {
            exp1 = custom_ceil(exp1 - float(D) / 100);
            if (exp1 > 600) {
                exp1 = 600;
            } 
        } 
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) {
            exp2 += custom_ceil(float(e1) /4 + 19);
            
        }
        else if (e1 <= 49) {
            exp2 += custom_ceil(float(e1) /9 + 21);
            
        }
        else if (e1 <= 65) {
            exp2 += custom_ceil(float(e1) /16 + 17);
            
        }
        else if (e1 <= 79) {
            exp2 += custom_ceil(float(e1) /4 + 19);
            if (exp2 > 600) {
                exp2 = 600;
            } 
            if (exp2 > 200) {
                exp2 += custom_ceil(float(e1) /9 + 21);
            }
        }
        else {
            exp2 += custom_ceil(float(e1) /4 + 19);
            if (exp2 > 600) {
                exp2 = 600;
            } 
            exp2 += custom_ceil(float(e1) /9 + 21);
            if (exp2 > 600) {
                exp2 = 600;
            } 
            if (exp2 > 400) {
                exp2 += custom_ceil(float(e1) /16 + 17);
                if (exp2 > 600) {
                    exp2 = 600;
                } 
                exp2 += custom_ceil(exp2 * 0.15);
            }
        }
        if (exp2 > 600) {
            exp2 = 600;
        } 
        exp1 -= e1;
        if (exp1 < 0) {
            exp1 = 0;
        }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    // TODO: Complete this function
    float P1, P2, P3, P;
    // Road 1
    int root1 = round(sqrt(EXP1));
    int S1 = root1 * root1;
    if (EXP1 >= S1) {
        P1 = 1;
    }
    else {
        P1 = (float(EXP1) / S1 + 80) / 123;
    }
    // Road 2  
    if (E2 % 2 == 1) {
        int halfM1 = M1/2;
        while (true) {
            if (HP1 < 200) {
                HP1 += custom_ceil(HP1 * 0.3);
                M1 -= 150;
            }
            else {
                HP1 += custom_ceil(HP1 * 0.1);
                M1 -= 70;
            }
            if (HP1 > 666) {HP1 = 666;}
            if (M1 < 0) {M1 = 0;}
            if (M1 < halfM1) {break;}

            if (EXP1 > 400) {
                M1 -= 120;
            }
            else {
                M1 -= 200;
            }
            EXP1 += custom_ceil(EXP1 * 0.13);
            if (EXP1 > 600) {EXP1 = 600;}
            if (M1 < 0) {M1 = 0;}
            if (M1 < halfM1) {break;}

            if (EXP1 < 300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }
            EXP1 = custom_ceil(float(EXP1) * 0.9);
            if (M1 < 0) {M1 = 0;}
            if (M1 < halfM1) {break;}
        }
    }
    else {
        if (HP1 < 200) {
            HP1 += custom_ceil(HP1 * 0.3);
            M1 -= 150;
        }
        else {
            HP1 += custom_ceil(HP1 * 0.1);
            M1 -= 70;
        }
        if (HP1 > 666) {HP1 = 666;}
        if (M1 > 0) {
            if (EXP1 < 400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EXP1 += custom_ceil(EXP1 * 0.13);
            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1 -= 100;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = custom_ceil(EXP1 * 0.9);
                if (M1 < 0){M1 = 0;}
            }
            else { M1 = 0; }
        }
        else { M1 = 0; }
    }
    HP1 = custom_ceil(HP1*0.83);
    EXP1 = custom_ceil(EXP1*1.17);
    if (EXP1 > 600) {EXP1 = 600;}
    int root2 = round(sqrt(EXP1));
    int S2 = root2 * root2;
    if (EXP1 >= S2) {
        P2 = 1;
    }
    else {
        P2 = (float(EXP1) / S2 + 80) / 123;
    }
    
    // Road 3
    float Ps[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 <= 9 && E2 >= 0) {
        P3 = Ps[E2] / 100;
    }
    else if (E2 <= 99) {
        P3 = Ps[(E2 / 10 + E2 %10) % 10] / 100;
        
    }
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = custom_ceil(EXP1 * 0.75);
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = custom_ceil(HP1 * 0.85);
            EXP1 = custom_ceil(EXP1 * 1.15);
        }
        else {
            HP1 = custom_ceil(HP1 * 0.9);
            EXP1 = custom_ceil(EXP1 * 1.2);
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        } 
    }
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        // TODO: Complete this function
        int met_row = 0;
        int met_col = 0;
        if (E3 < 0 || E3 > 99) {
            return -99;
        }
        int taxi_map[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxi_map[i][j] = (E3 * j + 2 * i ) * (i - j);
                if (taxi_map[i][j] > 2 * E3) {
                    met_row++;
                }
                else if (taxi_map[i][j] < -E3) {
                    met_col++;
                }
            }
        }
        
        while (met_row > 9) {
            met_row = met_row / 10 + met_row % 10;
        }
        while (met_col > 9) {
            met_col = met_col / 10 + met_col % 10;
        }
        
        int max = 0;
        int col = met_col;
        int row = met_row;
        int sherlock = taxi_map[met_row][met_col];
        // Main diagonal
        
        while (true) {
            row--;
            col--;
            if (col < 0 || row < 0) {
                break;
            }
            if ( taxi_map[row][col] > sherlock) {
                sherlock = taxi_map[row][col];
            }
        }
        col = met_col;
        row = met_row;
        while (true) {
            row++;
            col++;
            if (col > 9 || row > 9) {
                break;
            }
            if ( taxi_map[row][col] > sherlock) {
                sherlock = taxi_map[row][col];
            }
        }
        col = met_col;
        row = met_row;
        // Anti diagonal
        while (true) {
            row++;
            col--;
            if (col < 0 | row > 9) {
                break;
            }
            if ( taxi_map[row][col] > sherlock) {
                sherlock = taxi_map[row][col];
            }
        }
        col = met_col;
        row = met_row;
        while (true) {
            row--;
            col++;
            if (col > 9 || row < 0) {
                break;
            }
            if ( taxi_map[row][col] > sherlock) {
                sherlock = taxi_map[row][col];
            }
        }
        col = met_col;
        row = met_row;
        
        if (abs(taxi_map[met_row][met_col]) <= sherlock) {
            EXP1 = custom_ceil(EXP1 * 1.12);
            if(EXP1 > 600) {EXP1 = 600;}; 
            EXP2 = custom_ceil(EXP2 * 1.12);
            if(EXP2 > 600) {EXP2 = 600;}; 
            HP1 = custom_ceil(HP1 * 1.1);
            if(HP1 > 666) {HP1 = 666;}; 
            HP2 = custom_ceil(HP2 * 1.1);
            if(HP2 > 666) {HP2 = 666;}; 
            return sherlock;
        }
        else {
            EXP1 = custom_ceil(EXP1 * 0.88);
            EXP2 = custom_ceil(EXP2 * 0.88);
            HP1 = custom_ceil(HP1 * 0.9);
            HP2 = custom_ceil(HP2 * 0.9);
            return taxi_map[met_row][met_col];
        }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    std::string str_s(s);
    std::string str_email(email);
    char se[100];
    strcpy(se, email); 
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            se[i] = '\0';
        }
    }
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    } 

    // Finding if domain is in password
    size_t sei = str_s.find(se);
    if (sei != std::string::npos) {
        return 0-(300 + int(sei));
    }

    int count = 1;
    for (size_t i = 0; i < strlen(s); i++) {
        if (str_s[i] == str_s[i + 1]) {
            count++; // Increment count if current character is same as the next one
            if (count > 2) {
                return -(400 + i - 1);
            }
        } else {
            count = 1; // Reset count if subsequent characters are not the same
        }
    }

    for (size_t i = 0; i < strlen(s); i++) {
        if (str_s[i] == '@' || str_s[i] == '#' || str_s[i] == '%' || str_s[i] == '!' || str_s[i] == '$') {
            for (size_t j = 0; j < strlen(s); j++) {
                if (!std::isalnum(str_s[j]) && str_s[j] != '@' && str_s[j] != '#' && str_s[j] != '%' && str_s[j] != '!' && str_s[j] != '$') {
                    return j;
                }
            }
            return -10;
        }
    }
    return -5;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int counts[300] = {0};
    int lengths[300] = {0};
    std::string individuals[300] = {""};
    for (int i = 0; i < num_pwds; i++) {
        bool existed = false;
        for (int j = 0; j < 300; j++) {
            if (arr_pwds[i] == individuals[j]) {
                counts[j] ++;
                existed = true;
                break;
            }
        }
        if (!existed) {
            counts[i] = 1;
            individuals[i] = std::string(arr_pwds[i]);
        }
    }
    int max_count = 0;
    for (int i = 0; i < 300; i++) {
        if (max_count < counts[i]) {
            max_count = counts[i];
        }
    }
    int max_length = 0;
    for (int i = 0; i < 300; i++) {
        if (counts[i] == max_count) {
            lengths[i] = individuals[i].length();
            if (lengths[i] > max_length) {
                max_length = lengths[i];
            }
        }
    }
    for (int i = 0; i < 300; i++) {
        if (lengths[i] == max_length) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////