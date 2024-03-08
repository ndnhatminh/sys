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

// int round_up(int num) { 
//     return num + 0.999;
// }

int setHP(int HP) {
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
    return HP;
}

int setEXP(int EXP) {
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;
    return EXP;
}

int setM(int M) {
    if (M > 3000)
        M = 3000;
    else if (M < 0) 
        M = 0;
    return M;
}

bool mission_invaid(int E) {
    if (E < 0 || E > 99)
        return true;
    else
        return false;
}

bool used_half_money(int o_money, int used_money) {

    if (used_money > o_money / 2.00)
        return true;
    else 
        return false;
}

bool is_end(int x, int y) {
    if (x < 0 || y < 0 || x > 9 || y > 9)
        return true;
    return false;
}

int firstAction(int & HP1, int & M1) {
    if (HP1 < 200) {
        HP1 = setHP(ceil(HP1 + HP1 * 0.3));
        M1 = setM(ceil(M1 - 150));
        return 150;
    }
    else {
        HP1 = setHP(ceil(HP1 + HP1 * 0.1));
        M1 = setM(ceil(M1 - 70));
        return 70;
    }
}

int secondAction(int & EXP1, int & M1) {
    if (EXP1 < 400) {
        EXP1 = setEXP(ceil(EXP1 + EXP1 * 0.13));
        M1 = setM(ceil(M1 - 200));
        return 200;
    }
    else {
        EXP1 = setEXP(ceil(EXP1 + EXP1 * 0.13));
        M1 = setM(ceil(M1 - 120));
        return 120;
    }
}

int thirdAction (int & EXP1, int & M1) {
    if (EXP1 < 300) {
        EXP1 = setEXP(ceil(EXP1 - EXP1 * 0.1));
        M1 = setM(ceil(M1 - 100));\
        return 100;
    }
    else {
        EXP1 = setEXP(ceil(EXP1 - EXP1 * 0.1));
        M1 = setM(ceil(M1 - 120));
        return 120;
    }
}

int finalLoc(int num) {
    if (to_string(num).length() == 1) {
        return num;
    }
    num = (num / 10 + num % 10);
    return finalLoc(num);    
}

int threeConsec(string text) {
    for (int i = 0; i < text.length() - 2; i++) {
        if (text[i + 1] == text[i] && text[i+2] == text[i])
            return i;
    }
    return 0;
}

bool noSpecialCharacter(string text) {
    string temp;
    for (int i = 0; i < text.length(); i++) {
        temp = text[i];
        if (temp == "@" || temp == "#" || temp == "%" || temp == "$" || temp == "!")
            return false;
    }
    return true;
}

int notUnderstand(string text) {
    int count = 0;
    int temp;
    char alphabet[67] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 
    'H', 'I', 'J', 'K', 'L', 'M', 'N', 
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
    'V', 'W', 'X', 'Y', 'Z', 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 
    'o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z', 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    '@', '#', '%', '$', '!'};
    for (int i = 0; i < text.length(); i++) {
        temp = count;
        //Dò coi có trùng thì +1 count
        for (int j = 0; j < 67; j++) {
            if (text[i] == alphabet[j]) {
                count++;
                break;
            }
        }
        if (count == temp) return i; //Không trùng với alphabet -> ký tự lạ -> not understand
    }
    return -1;
}

int max(int array[], int num) {
    int max = array[0];
    for (int i = 1; i < num; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int min(int array[], int num) {
    int min = array[0];
    for (int i = 1; i < num; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (mission_invaid(e1))
        return -99;
    else if (e1 >= 0 && e1 <= 3) {
        //Inference
        if (e1 == 0)
            exp2 = setEXP(exp2 + 29);
        else if (e1 == 1)
            exp2 = setEXP(exp2 + 45);
        else if (e1 == 2)
            exp2 = setEXP(exp2 + 75);
        else //(e1 == 3) 
            exp2 = setEXP(exp2 + 29 + 45 + 75);

        //Guess between 2 countries
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = setEXP(ceil(exp1 + D / 200.0));
        else 
            exp1 = setEXP(ceil(exp1 - D / 100.0));        
    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19)
            exp2 = setEXP(ceil(exp2 + e1/4.0 + 19));
        else if (e1 <= 49)
            exp2 = setEXP(ceil(exp2 + e1/9.0 + 21));
        else if (e1 <= 65)
            exp2 = setEXP(ceil(exp2 + e1/16.0 + 17));
        else if (e1 <= 79) {
            exp2 = setEXP(ceil(exp2 + e1/4.0 + 19));
            if (exp2 > 200)
                exp2 = setEXP(ceil(exp2 + e1/9.0 + 21));
        }
        else {
            exp2 = setEXP(ceil(exp2 + e1/4.0 + 19));
            exp2 = setEXP(ceil(exp2 + e1/9.0 + 21));
            if (exp2 > 400)
                exp2 = setEXP(ceil(exp2 + e1/16.0 + 17));
                exp2 = setEXP(ceil(exp2 + exp2 * 1.15)); //coi lai
        }
        exp1 = setEXP(exp1 - e1);
    }
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // cout << "Mission 2: (E2 = " << E2 << ")"<< endl;
    // cout << "(*) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl;
    if (mission_invaid(E2))
        return -99;
        
    //ROAD 1 - P1
    int square_nums[25] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576};
    int s_nearest;
    for (int i = 0; i < 24; i++) {
        if (square_nums[i] <= EXP1 && EXP1 <= square_nums[i+1]) {
            int s1 = abs(EXP1 - square_nums[i]);
            int s2 = abs(EXP1 - square_nums[i + 1]);
            if (s1 <= s2) {
                s_nearest = square_nums[i];
                break;
            }
            else {
                s_nearest = square_nums[i + 1];
                break;
            }
        }
        else if (EXP1 >= 576 && EXP1 <= 600) {
            s_nearest = 576; //nearist still be 576 if EXP1 = 600
            break;
        }
    }
    float P1;
    if (EXP1 >= s_nearest) {
        P1 = 1;
        // cout << "P1: " << P1 << endl;
    }
    else {
        P1 = (EXP1 / static_cast<float>(s_nearest) + 80.0) / 123.0;
        // cout << "P1: " << P1 << endl;
    }
    
    //ROAD 2
    //E2 odd
    if (E2 % 2 == 1) {
        int o_money = M1;
        int used_money = 0;
        while (true) {
            if (used_half_money(o_money, used_money)) {
                break;
            }
            used_money += firstAction(HP1, M1);
            // cout << "(1) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", used: " << used_money << endl;
            
            if (used_half_money(o_money, used_money)) {
                break;
            }
            used_money += secondAction(EXP1, M1);
            // cout << "(2) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", used: " << used_money << endl;
            
            if (used_half_money(o_money, used_money)) {
                break;
            }
            used_money += thirdAction(EXP1, M1);
            // cout << "(3) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", used: " << used_money << endl;
        }
        
    }
    //E2 even
    else {
        for (int i = 0; i < 1; i++) {
            if (M1 <= 0) {
                break;
            }
            firstAction(HP1, M1);
            // cout << "(1) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl;
            
            if (M1 <= 0) {
                break;
            }
            secondAction(EXP1, M1);
            // cout << "(2) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl;
            
            if (M1 <=0) {
                break;
            }
            thirdAction(EXP1, M1);
            // cout << "(3) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl; 
        } 
        
    }
    HP1 = setHP(ceil(HP1 - HP1 * 0.17));
    EXP1 = setEXP(ceil(EXP1 + EXP1 * 0.17));
    // cout << "(*) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl;
    //P2
    s_nearest = 0;
    for (int i = 0; i < 24; i++) {
        if (square_nums[i] <= EXP1 && EXP1 <= square_nums[i+1]) {
            int s1 = abs(EXP1 - square_nums[i]);
            int s2 = abs(EXP1 - square_nums[i + 1]);
            if (s1 <= s2) {
                s_nearest = square_nums[i];
                break;
            }
            else {
                s_nearest = square_nums[i + 1];
                break;
            }
        }
        else if (EXP1 >= 576 && EXP1 <= 600) {
            s_nearest = 576; //nearist still be 576 if EXP1 = 600
            break;
        }
    }
    float P2;
    if (EXP1 >= s_nearest) {
        P2 = 1;
        // cout << "P1: " << P1 << endl;
    }
    else {
        P2 = (EXP1 / static_cast<float>(s_nearest) + 80.0) / 123.0;
        // cout << "P1: " << P1 << endl;
    }
    // cout << "Nearest: " << s_nearest << " P2: " << P2;

    //ROAD 3 - P3
    int P_set[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int pos;
    if (to_string(E2).length() == 2) {
        pos = (E2 / 10 + E2 % 10) % 10;
    }
    else {
        pos = E2;
    }
    float P3 = P_set[pos] / 100.0;

    //Finally
    // cout << "P1: " << P1 << " P2: " << P2 << " P3: " << P3 << endl;
    float P_final;
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = setEXP(ceil(EXP1 - EXP1 * 0.25));
    }
    else {
        P_final = (P1 + P2 + P3) / 3.0;
        if (P_final < 0.5) {
            HP1 = setHP(ceil(HP1 - HP1 * 0.15));
            EXP1 = setEXP(ceil(EXP1 + EXP1 * 0.15));
        }
        else {
            HP1 = setHP(ceil(HP1 - HP1 * 0.1));
            EXP1 = setEXP(ceil(EXP1 + EXP1 * 0.2));
        }
    }
    // cout << "(*) HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl;
    // cout << "P_final: " << P_final << ", Result: " << HP1 + EXP1 + M1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (mission_invaid(E3))
        return -99;
    //TAXI MATRIX
    int x_meet = 0;
    int y_meet = 0;
    int taxi_matrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi_matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi_matrix[i][j] > E3 * 2) {
                x_meet++;
            }
            if (taxi_matrix[i][j] < -E3) {
                y_meet++;
            }
            
        }
    }
    //FOR COUT
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << taxi_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }    
    // cout << x_meet << " " << y_meet << endl;
    x_meet = finalLoc(x_meet);
    y_meet = finalLoc(y_meet);
    // cout << x_meet << " " << y_meet << endl;

    //SHERLOCK MATRIX
    int max;
    int x_test;
    int y_test;
    int sh_matrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            max = taxi_matrix[i][j];
            x_test = i;
            y_test = j;
            while (true) {
                x_test++;
                y_test++;
                if (is_end(x_test, y_test)) {
                    x_test = i;
                    y_test = j;
                    break;
                }
                if (taxi_matrix[x_test][y_test] > max) {
                    max = taxi_matrix[x_test][y_test];
                }
            }
            while (true) {
                x_test++;
                y_test--;
                if (is_end(x_test, y_test)) {
                    x_test = i;
                    y_test = j;
                    break;
                }
                if (taxi_matrix[x_test][y_test] > max) {
                    max = taxi_matrix[x_test][y_test];
                }
            }
            while (true) {
                x_test--;
                y_test++;
                if (is_end(x_test, y_test)) {
                    x_test = i;
                    y_test = j;
                    break;
                }
                if (taxi_matrix[x_test][y_test] > max) {
                    max = taxi_matrix[x_test][y_test];
                }
            }
            while (true) {
                x_test--;
                y_test--;
                if (is_end(x_test, y_test)) {
                    x_test = i;
                    y_test = j;
                    break;
                }
                if (taxi_matrix[x_test][y_test] > max) {
                    max = taxi_matrix[x_test][y_test];
                }
            }
            sh_matrix[i][j] = max;
            // if (i == x_meet && j == y_meet)
            //     cout << max;
        }
    }
    
    if (abs(taxi_matrix[x_meet][y_meet]) > sh_matrix[x_meet][y_meet]) {
        EXP1 = setEXP(ceil(EXP1 - EXP1 * 0.12));
        EXP2 = setEXP(ceil(EXP2 - EXP2 * 0.12));
        HP1 = setHP(ceil(HP1 - HP1 * 0.1));
        HP2 = setHP(ceil(HP2 - HP2 * 0.1));
        return taxi_matrix[x_meet][y_meet];
    }
    else {
        EXP1 = setEXP(ceil(EXP1 + EXP1 * 0.12));
        EXP2 = setEXP(ceil(EXP2 + EXP2 * 0.12));
        HP1 = setHP(ceil(HP1 + HP1 * 0.1));
        HP2 = setHP(ceil(HP2 + HP2 * 0.1));
        return sh_matrix[x_meet][y_meet];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string newS = s;
    string newEmail = email;
    size_t seIndex = newEmail.find("@");
    string se = newEmail.substr(0, seIndex);
    // int fail_count = 0;
    // cout << se << endl;
    // cout << string::npos << endl; npos is the largest number
    if (newS.length() < 8) return -1;
    else if (newS.length() > 20) return -2;
    else if (newS.find(se) < (100)) return -(300 + newS.find(se));
    else if (threeConsec(newS) != 0) return -(400 + threeConsec(newS));
    else if (noSpecialCharacter(newS)) return -5;
    else if (notUnderstand(newS) != -1) return notUnderstand(newS);
    else return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //Change data type of pass_raw
    string pass_raw[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        pass_raw[i] = arr_pwds[i];
    }

    //Pass list setup
    string pass_list[30];
    pass_list[0] = pass_raw[0]; //["first"]

    //Common list setup
    int common_list[30];
    for (int i = 0; i < 30; i++) {
        common_list[i] = 0;
    }
    common_list[0]++; //[1, 0, 0, ...]

    //Implement
    int where_to_pass = 1; // = array length
    string temp;
    for (int i = 1; i < num_pwds; i++) {
        for (int j = 0; j < where_to_pass; j++) {
            if (pass_raw[i] == pass_list[j]) {
                temp = pass_list[j];
                common_list[j]++;
                break;
            }
        }
        if (pass_raw[i] == temp) continue;
        pass_list[where_to_pass] = pass_raw[i];
        common_list[where_to_pass]++;
        where_to_pass++;
    }
    //Where to pass -> size of all main arrays
    //Length list
    int length_list[where_to_pass];
    for (int i = 0; i < where_to_pass; i++) {
        length_list[i] = pass_list[i].length();
        // cout << length_list[i] << " ";
    }
    //First list
    int first_list[where_to_pass];
    for (int i = 0; i < where_to_pass; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (pass_raw[j] == pass_list[i]) {
                first_list[i] = j;
                break;
            }
        }
    }
    //Common
    int max_common = max(common_list, where_to_pass);
    for (int i = 0; i < where_to_pass; i++) {
        if (common_list[i] != max_common) {
            pass_list[i] = "None";
            length_list[i] = -1;
        }
    }
    //Length
    int max_length = max(length_list, where_to_pass);
    for (int i = 0; i < where_to_pass; i++) {
        if (length_list[i] != max_length) {
            pass_list[i] = "None";
            first_list[i] = num_pwds;
        }
    }
    //First
    int min_first = min(first_list, where_to_pass);
    for (int i = 0; i < where_to_pass; i++) {
        if (first_list[i] != min_first) {
            pass_list[i] = "None";
        }
    }
    //Return value
    int correctPosition;
    for (int i = 0; i < where_to_pass; i++) {
        if (pass_list[i] != "None") {
            correctPosition = first_list[i];
        }
    }
    return correctPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////