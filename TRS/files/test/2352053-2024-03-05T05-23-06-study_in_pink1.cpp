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
    // DO NOT MODIFY THIS FUNCTION
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

//Minimize unit to 1-digit number
int minimize_Unit(int a) {
    while (a >= 10) {
        int tens, units;
        units = a % 10;
        tens = (a - units) / 10;
        a = tens + units;
    }
    return a;
}

//Check if the character in the password is valid or not
bool checkValidCharacter(char c) {
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)
    || (c == '@') || (c == '#') || (c == '%') || (c == '$') || (c == '!'))
        return true;

    return false;
}

//Check if EXP is a valid value
void standardized_EXP(int &exp) {
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
}

//Check if HP is a valid value
void standardize_HP(int &hp) {
    if (hp > 666)
        hp = 666;
    else if (hp < 0)
        hp = 0;
}

//Check if money is a valid value
void standardize_Money(int &m) {
    if (m > 3000)
        m = 3000;
    else if (m < 0)
        m = 0;
}

bool valid_E(int e) {
    if (e > 99 || e < 0)
        return false;
    return true;
}

//Find the nearest perfect square
int nearest_Perfect_Square(int EXP) {
    if (sqrt(EXP) == floor(sqrt(EXP)))
        return EXP;
    else {
        int tmp1 = floor(sqrt(EXP));
        int tmp2 = ceil(sqrt(EXP));

        tmp1 = tmp1 * tmp1;
        tmp2 = tmp2 * tmp2;

        if(abs(tmp1 - EXP) > abs(tmp2 - EXP))
            return tmp2;
        else
            return tmp1;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (!valid_E(e1))
        return -99;

    standardized_EXP(exp1);
    standardized_EXP(exp2);
    //Case 1
    if (e1 <= 3) {
    //Watson exp
        switch(e1) {
            case 0: {
                exp2 += 29;
                standardized_EXP(exp2);
                break;
            }
            case 1: {
                exp2 += 45;
                standardized_EXP(exp2);
                break;
            }
            case 2: {
                exp2 += 75;
                standardized_EXP(exp2);
                break;
            }
            case 3: {
                exp2 = exp2 + 29 + 45 + 75;
                standardized_EXP(exp2);
                break;
            }
            default: {
                break;
            }
        }
        //Sherlock exp
        //Compute D
        int D = e1 * 3 + exp1 * 7;

        //D is odd
        if (D & 1) {
            exp1 = ceil((double) exp1 - double(D) / 100.00);
        }
        //D is even
        else
            exp1 = ceil((double)exp1 + double(D) / 200.00);
        standardized_EXP(exp1);
    }


    //----------------------------------------------
    //Case 2
    else if (e1 >= 4) {
        //Information 1
        if (e1 <= 19) {
            exp2 += ceil((double)e1 / 4.00 + 19);
            standardized_EXP(exp2);
        }
        //Information 2
        else if (20 <= e1 && e1 <= 49) {
            exp2 += ceil((double)e1 / 9.0 + 21);
            standardized_EXP(exp2);
        }
        //Information 3
        else if (50 <= e1 && e1 <= 65) {
            exp2 += ceil((double)e1 / 16.00 + 17);
            standardized_EXP(exp2);
        }

        //Information 4
        else if (66 <= e1 && e1 <= 79) {
            exp2 += ceil((double)e1 / 4.00 + 19);
            standardized_EXP(exp2);
            if (exp2 > 200)
                exp2 += ceil((double)e1 / 9.00 + 21);
            standardized_EXP(exp2);
        }
        //Information 5
        else {
            exp2 += ceil((double)e1 / 4.00 + 19);
            standardized_EXP(exp2);
            exp2 += ceil((double)e1 / 9.00 + 21);
            standardized_EXP(exp2);
            if (exp2 > 400) {
                exp2 += ceil((double)e1 / 16.00 + 17);
                standardized_EXP(exp2);
                exp2 = ceil(exp2 * 1.15);
                standardized_EXP(exp2);
            }
        }
        //Update Sherlock exp
        exp1 = exp1 - e1;
        standardized_EXP(exp1);
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function'
    //Check if E2 is valid
    if(!valid_E(E2))
        return -99;
    standardized_EXP(EXP1);
    standardize_HP(HP1);
    standardize_Money(M1);
    //Road 01:
    double P1;
    int S;
    //Find the nearest perfect of EXP1
    S = nearest_Perfect_Square(EXP1);
    //Compute the probability for Sherlock to find the suitcase on this route
    if (EXP1 >= S)
        P1 = 1.00;
    else
        P1 = (double(EXP1) / S + 80.0) / 123.0;
    //-----------------------------------------------
    //Road 2:

    double P2;
    int initial_money = static_cast<int>(M1 * 0.5);
    int paid_money = 0;
    bool check = false;
    //Check the parity of E2
    if (E2 % 2 == 0)
        check = true;
    do {
        if (M1 == 0)
            break;
        //The case when Sherlock get into a grocery store to buy food
        if (HP1 < 200) {
            HP1 = ceil((double(HP1 * 1.30 - 0.00000000001)));
            M1 -= 150;
            paid_money += 150;
        }
        //The case when Sherlock get into a grocery store to buy water
        else {
            HP1 = ceil(static_cast<double>(HP1 * 1.1 - 0.00000000001));
            M1 -= 70;
            paid_money += 70;
        }
        standardize_HP(HP1);
        standardize_Money(M1);

        //Money = 0 in the even case
        if (M1 == 0)
            break;
        //If paid money > 50% of initial money in the odd cases
        if (!check && paid_money > initial_money)
            break;

        //Rent a taxi
        if (EXP1 < 400) {
            M1 -= 200;
            paid_money += 200;
        }
        //Rent a carriage
        else {
            M1 -= 120;
            paid_money += 120;
        }
        standardize_Money(M1);

        EXP1 = ceil(double(EXP1 * 1.13 - 0.000000001));
        standardized_EXP(EXP1);
        //Money = 0 in the even case
        if (M1 == 0)
            break;
        //If paid money > 50% of initial money in the odd cases

        if (!check && paid_money > initial_money)
            break;

        //Meet the homeless person
        if (EXP1 < 300) {
            M1 -= 100;
            paid_money += 100;
        }
        else {
            M1 -= 120;
            paid_money += 120;
        }
        EXP1 = ceil((double(EXP1 * 0.9 - 0.00000001)));
        standardize_Money(M1);

        //Money = 0 in the even case
        if (M1 == 0)
            break;
        //If paid money > 50% of initial money in the odd cases
        if (!check && paid_money > initial_money)
            break;
    } while (!check);
    //Sherlock walk till the end of this road
    HP1 = ceil(double(HP1 * 0.83 - 0.00000001));
    EXP1 = ceil(double(EXP1 * 1.17 - 0.00000001));
    standardize_HP(HP1);
    standardized_EXP(EXP1);
    //Compute the probability of find the suitcase on road 2
    S = nearest_Perfect_Square(EXP1);
    if (EXP1 >= S)
        P2 = 1.0;
    else
        P2 = (double(EXP1) / S + 80.0) / 123.0;

    //-----------------------------------
    //Road 3
    double P3;
    int P[10] = {32, 47, 28, 79,100, 50,22, 83, 64, 11};

    int unit = E2 % 10;
    int ten = (E2 - unit) / 10;
    int index = (unit + ten) % 10;

    P3 = static_cast<double>(P[index]) / 100.0;
    if (P1 == P2 && P2 == P3 && P3 == 1.0) {
        EXP1 = ceil((double)EXP1 * 0.75 - 0.0000000001);
    }
    else {
        double average_P = (P1 + P2 + P3) / 3;
        if (average_P < 0.5) {
            HP1 = ceil((double)HP1 * 0.85 - 0.0000000001);
            EXP1 = ceil((double)EXP1 * 1.15 - 0.000000001);
        }
        else {
            HP1 = ceil((double)HP1 * 0.9 - 0.000000001);
            EXP1 = ceil((double)EXP1 * 1.2 - 0.00000001);
        }
    }
    standardized_EXP(EXP1);
    standardize_HP(HP1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(!valid_E(E3))
        return -99;

    standardized_EXP(EXP1);
    standardized_EXP(EXP2);
    standardize_HP(HP1);
    standardize_HP(HP2);

    int y = 0;
    int x = 0;
    int taxi[100][100];

    for (int i = 0; i < 10 ; i++)
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > (E3 * 2))
                x++;
            else if (taxi[i][j] < -(E3))
                y++;
        }

    x = minimize_Unit(x);
    y = minimize_Unit(y);

    int max_left_diag = -100000000;
    int max_right_diag = -100000000;

    //Find the maximum value of the left diagonal
    if (x == y)
        max_left_diag = 0;
    else if (x < y) {
        int row = abs(x - y);
        int col = 0;
        while ((row < 10) && (col < 10)) {
            if (taxi[row][col] > max_left_diag)
                max_left_diag = taxi[row][col];
            row++;
            col++;
        }
    }
    else {
        int row = 0;
        int col = x - y;
        while (row < 10 && col < 10) {
            if(taxi[row][col] > max_left_diag)
                max_left_diag = taxi[row][col];
            row++;
            col++;
        }
    }

    //Find the maximum value of the right diagonal
    if (x + y == 9) {
        int row = 0;
        int col = 9;
        while (row < 10 && col >= 0) {
            if(taxi[row][col] > max_right_diag)
                max_right_diag = taxi[row][col];
            row++;
            col--;
        }
    }
    else if (x + y > 9) {
        int col = 9;
        int row = x + y - 9;
        while (row < 10 && col >= 0) {
            if(taxi[row][col] > max_right_diag)
                max_right_diag = taxi[row] [col];
            row++;
            col--;
        }
    }
    else {
        int col = x + y;
        int row = 0;
        while (row < 10 && col >= 0) {
            if(taxi[row][col] > max_right_diag)
                max_right_diag = taxi[row][col];
            row++;
            col--;
        }
    }

    int detective_point = max(max_right_diag, max_left_diag);
    if (abs(detective_point) >= abs(taxi[x][y])) {
        EXP1 = ceil(EXP1 * 1.12 - 0.000000001);
        EXP2 = ceil(EXP2 * 1.12 - 0.000000001);
        HP1 = ceil(HP1 * 1.1 - 0.000000001);
        HP2 = ceil(HP2 * 1.1 - 0.000000001);

        standardized_EXP(EXP1);
        standardized_EXP(EXP2);
        standardize_HP(HP1);
        standardize_HP(HP2);

        return detective_point;
    }
    else {
        EXP1 = ceil(EXP1 * 0.88 - 0.000000001);
        EXP2 = ceil(EXP2 * 0.88 - 0.000000001);
        HP1 = ceil(HP1 * 0.9 - 0.000000001);
        HP2 = ceil(HP2 * 0.9 - 0.000000001);

        standardized_EXP(EXP1);
        standardized_EXP(EXP2);
        standardize_HP(HP1);
        standardize_HP(HP2);

        return taxi[x][y];
    }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se_temp;
    string se;
    se_temp = email;
    int index_se = 0;

    for (int i = 0; i < se_temp.length(); i++) {
        if (se_temp[i] != '@')
            se.push_back(se_temp[i]);
        else
            break;
    }

    string password;
    int index_password = 0;
    password = s;

    //Check if the password have valid length
    if (password.length() < 8)
        return -1;
    else if (password.length() > 20)
        return -2;

    unsigned long len = password.length() - 1;
    bool contain_special_character = false;
    bool contain_invalid_character = false;
    int index_of_first_invalid_char;
    while (index_password <= len) {
        //Check if se is a subset of password
        if (password[index_password] == se[index_se]) {
            unsigned  long se_length = se.length() - 1;
            bool is_se_subset_password = true;
            for (int i = 1; i <= se_length; i++) {
                if (password[index_password + i] != se[index_se + i]) {
                    is_se_subset_password = false;
                    break;
                }
            }
            if (is_se_subset_password)
                return -(300 + index_password);
        }
        //Check if password contains more than 2 consecutive character
        if(password[index_password] == password[index_password + 1]
        && password[index_password] == password[index_password + 2])
            return -(400 + index_password);

        //Check if password contains special character
        if(password[index_password] == '@' || password[index_password] == '#' || password[index_password] == '%'
        || password[index_password] == '$' || password[index_password] == '!')
            contain_special_character = true;
        if(!checkValidCharacter(password[index_password]) && !contain_invalid_character) {
            contain_invalid_character = true;
            index_of_first_invalid_char = index_password;
        }
        index_password++;
    }
    if (!contain_special_character)
        return -5;

    else if (contain_invalid_character)
        return index_of_first_invalid_char;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_appearance = 0;
    unsigned long length_of_latest_max_appearance = 0;
    int index_of_first_appearance;
    for (int i = 0; i < num_pwds; i++) {
        int appearance = 1;
        string cur_password = arr_pwds[i];
        unsigned long length = cur_password.length();
        for (int j = i + 1; j < num_pwds; j++) {
            string checking_password = arr_pwds[j];
            if (cur_password == checking_password)
                appearance++;
        }
        //Check for optimal password
        if (appearance > max_appearance) {
            length_of_latest_max_appearance = length;
            index_of_first_appearance = i;
            max_appearance = appearance;
        }
        else if (appearance == max_appearance) {
            if (length > length_of_latest_max_appearance) {
                length_of_latest_max_appearance = length;
                index_of_first_appearance = i;
            }
        }
    }
    return index_of_first_appearance;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////