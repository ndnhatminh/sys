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

//Task 1 + 2 + 3
void roundUpExp(double &t){
    if (t  - int(t) >= 0.000000005)
    t = int(t) + 1;
    if (t > 600) t = 600;
    else if (t < 0) t = 0;
}
void roundUpHP(double &h){
    if (h  - int(h) >= 0.000000005)
    h = int(h) + 1;

    if (h > 666) h = 666;
    else if (h < 0) h = 0;
}
void roundUpM(double &m){
    if (m  - int(m) >= 0.000000005)
    m = int(m) + 1;
    if (m > 3000) m = 3000;
    else if (m < 0) m = 0;
}
//Task 2
int check_M1_greater_than_50(double half_M1, double expense){
    if (expense > half_M1)
        return 0;
    return 99;
}

//Task 3
int Diagonal(const int initial_x, const int initial_y, double taxi_score[10][10]){
    int sherlock_watson_score = 0, temp_max = 0;
    int x = initial_x, y = initial_y, i = initial_x, j = initial_y;
    //Left diagonal down
    for (int h = 0; h <= 9; h++){
        if ((x == 10) || (y == -1)) break;

        temp_max = taxi_score[x][y];
        if (sherlock_watson_score < temp_max) sherlock_watson_score = temp_max;
        x++;
        y--;
    }
    //Left diagonal Up
    for (int h = 0; h <= 9; h++){
        if ((i == -1) || (j == 10)) break;
        temp_max = taxi_score[i][j];
        if (sherlock_watson_score < temp_max) sherlock_watson_score = temp_max;
        i--;
        j++;
    }
    x = initial_x, y = initial_y, i = initial_x, j = initial_y;

    //Right diagonal down
    for (int h = 0; h <= 9; h++) {
        if ((x == 10) || (y == 10)) break;
        temp_max = taxi_score[x][y];
        if (sherlock_watson_score < temp_max) sherlock_watson_score = temp_max;
        x++;
        y++;
    }
    //Right diagonal up
    for (int h = 0; h <= 9; h++) {
        if ((x == -1) || (y == -1)) break;
        temp_max = taxi_score[i][j];
        if (sherlock_watson_score < temp_max) sherlock_watson_score = temp_max;
        x--;
        y--;
    }

    return sherlock_watson_score;
}

//Task 4
string findSE(string mail){
    string se = "";
    for (char i : mail){
        if (i != '@') {
            se += i;
        }
        else break;
    }
    return se;
}

int findRepetition(string pass){
    int counter = 1, repetition = 1;
    for (int i = 1; i <= pass.length(); i++){
        if (pass[i] == pass[i-1]) {
            counter++;
            if (repetition < counter) repetition = counter;
            if (repetition > 2) {
                return (i - 2);
            }
        }
        else {
            counter = 1;
        }
    }
    return -1;
}

int invalidChar(string pass){
    string valid_char = "qwertyuiopasdfghjklzxcvbnm1234567890!@#$%QWERTYUIOPASDFGHJKLZXCVBNM";
    for (int i = 0 ; i < pass.length() ; i++){
        if (valid_char.find(pass[i]) == string::npos) return i;
    }
    return -1;
}




// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99))
        return -99;
    double EXP1 = exp1, EXP2 = exp2, E1 = e1;
    roundUpExp(EXP1); roundUpExp(EXP2); 


    //Case 1
    if ((E1 >= 0) && (E1 <= 3)){
        //Information 1
        if (E1 == 0) {
            EXP2 += 29;
            roundUpExp(EXP2);
        }
        //Information 2
        else if (E1 == 1) {
            EXP2 += 45;
            roundUpExp(EXP2);
        }
        //Information 3
        else if (E1 == 2) {
            EXP2 += 75;
            roundUpExp(EXP2);
        }
        //Information 4
        else if (E1 == 3) {
                EXP2 += 149;
                roundUpExp(EXP2);
        }
        //Sherlock's decision
        double D = E1 * 3 + EXP1 * 7;
        if (int(D) % 2 == 0){
            EXP1 += D/200;
            roundUpExp(EXP1);

        }
        else {
            EXP1 -= D/100;
            roundUpExp(EXP1);
        }
    }
    //Case 2
    else if ((E1 >= 4) && (E1 <= 99)){
        //Information 1
        if ((E1 >= 4 ) && (E1 <= 19)){
            EXP2 += E1/4 + 19;
            roundUpExp(EXP2);
        }
        //Information 2
        else if ((E1 >= 20 ) && (E1 <= 49)){
            EXP2 += E1/9 + 21;
            roundUpExp(EXP2);
        }
        //Information 3
        else if ((E1 >= 50 ) && (E1 <= 65)){
            EXP2 += E1/16 + 17;
            roundUpExp(EXP2);
        }
        //Information 4
        else if ((E1 >= 66 ) && (E1 <= 79)){
            //Sherlock explain information 1
            EXP2 += E1/4 + 19;
            roundUpExp(EXP2);
            if (EXP2 > 200) {
                EXP2 += E1/9 + 21;
                roundUpExp(EXP2);
            }
        }
        //Information 5
        else if ((E1 >= 80 ) && (E1 <= 99)){
            //Sherlock explain information 1
            EXP2 += E1/4 + 19;
            roundUpExp(EXP2);
            //Sherlock explain information 2
            EXP2 += E1/9 + 21;
            roundUpExp(EXP2);
            //Sherlock explain information 3
            if (EXP2 > 400) {
                EXP2 += E1/16 + 17;
                roundUpExp(EXP2);
                //Bonus EXP for explain all 3 information
                EXP2 += EXP2 * 0.15;
                roundUpExp(EXP2);
            }
        }
        //Shock for Harry is Watson's sister
        EXP1 -= E1;
        roundUpExp(EXP1);

    }
    exp1 = EXP1; exp2 = EXP2;

    return EXP1 + EXP2;



}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
   if ((E2 >=0) && (E2 <= 99)){

    double hp1 = HP1, exp1 = EXP1, m1 = M1, e2 = E2, S, P1;
    roundUpHP(hp1); roundUpExp(exp1); roundUpM(m1);

    P1 = 0, S = round(sqrt(exp1));

    //Path1
    if (exp1 >= S*S){
        P1 = 1;
    }
    else {
        P1 = (exp1/(S*S) + 80) / 123;
    }
    //Path 2
    if (m1 != 0) { //Happen only M1 > 0
    // e2 is odd
    if (int(e2) % 2 != 0) {
    double total_expenses = 0, half_M1 = m1 / 2;
    int counter = 99;
    counter = check_M1_greater_than_50(half_M1, total_expenses);
    for (int i = 0; i < counter; i++ ){
            //Buy food & drinks
        if ((hp1 < 200) && (counter != 0)) {
            hp1 *= 1.3; roundUpHP(hp1);
            total_expenses += 150;
            m1 -= 150; roundUpM(m1);
            counter = check_M1_greater_than_50(half_M1, total_expenses);


        }
        else if ((hp1 >= 200) && (counter != 0)) {
            hp1 *= 1.1; roundUpHP(hp1);
            total_expenses += 70;
            m1 -= 70; roundUpM(m1); counter = check_M1_greater_than_50(half_M1, total_expenses);


        }
            //Hire transportation
        if ((exp1 < 400) && (counter != 0)) {
            total_expenses += 200;
            exp1 *= 1.13; roundUpExp(exp1);
            m1 -= 200; roundUpM(m1); counter = check_M1_greater_than_50(half_M1, total_expenses);

        }
        else if ((exp1 >= 400) && (counter != 0))
        {
            total_expenses += 120;
            m1 -= 120; roundUpM(m1); counter = check_M1_greater_than_50(half_M1, total_expenses);
            exp1 *= 1.13; roundUpExp(exp1);
        }

            //Meet a homeless guy
        if ((exp1 < 300) && (counter != 0)) {
            total_expenses += 100;

            m1 -= 100; roundUpM(m1); counter = check_M1_greater_than_50(half_M1, total_expenses);

            exp1 *= 0.9; roundUpExp(exp1);
        }
        else if ((exp1 >= 300) && (counter != 0) ){
            total_expenses += 120;
            m1 -= 120; roundUpM(m1); counter = check_M1_greater_than_50(half_M1, total_expenses);

            exp1 = 0.9*exp1; roundUpExp(exp1);
        }

            // Just walk till the end
                if (counter == 0) {
                hp1 *= 0.83; roundUpHP(hp1);
                exp1*= 1.17; roundUpExp(exp1);

            }

    }
    }
    //e2 is even
    else {
            //Buy food & drinks
        if ((hp1 < 200) && (m1 > 0)) {
            hp1 += hp1 * 0.3; roundUpHP(hp1);
            m1 -= 150; roundUpM(m1);

        }

        else if ((hp1 >= 200) && (m1 > 0)) {
            hp1 += hp1 * 0.1; roundUpHP(hp1);
            m1 -= 70; roundUpM(m1);
        }

            //Hire transportation

        if ((exp1 < 400) && (m1 > 0)) {
            m1 -= 200; roundUpM(m1);
            exp1 *= 1.13; roundUpExp(exp1);
        }
        else if ((exp1 >= 400) && (m1 > 0))
        {
            m1 -= 120; roundUpM(m1);
            exp1 *= 1.13; roundUpExp(exp1);
        }

            //Meet a homeless guy

        if ((exp1 < 300) && (m1 > 0)) {
            m1 -= 100; roundUpM(m1);
            exp1 *= 0.9; roundUpExp(exp1);
        }

        else if ((exp1 >= 300) && (m1 > 0)){
            m1 -= 120; roundUpM(m1);
            exp1 = 0.9*exp1; roundUpExp(exp1);
        }

            // Just walk till the end
            hp1 *= 0.83; roundUpHP(hp1);
            exp1*= 1.17; roundUpExp(exp1);
    }



    }
    else {
            hp1 *= 0.83; roundUpHP(hp1);
            exp1*= 1.17; roundUpExp(exp1);

    }
    //Calculate P2
    double P2;
    S = round(sqrt(exp1)); 
    if (exp1 >= S*S){
        P2 = 1;
    }
    else {
        P2 = (exp1/(S*S) + 80) / 123;
    }
    //Path 3
    double P[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    int i = 0;
    if (e2 <  10){
            i = e2;
        }
    else {
        i = int(e2) % 10;
        i += int(e2) / 10;
        i %= 10;
    }
    double P3 = P[i];
    if ((P1 == 1) && (P2 == 1) && (P3 == 1)){
        exp1 *= 0.75; roundUpExp(exp1);
    }
    else {
        double P_avg =(P1 + P2 + P3) / 3;
        if (P_avg < 0.5){
            hp1 *= 0.85; roundUpHP(hp1);
            exp1 *= 1.15; roundUpExp(exp1);
        }
        else if (P_avg >= 0.5){
            hp1 *= 0.9; roundUpHP(hp1);
            exp1 *= 1.2; roundUpExp(exp1);
        }
    }
    HP1 = hp1; EXP1 = exp1; M1 = m1;
    return hp1 + exp1 + m1;
    }
    return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 < 0) || (E3 > 99))
        return -99;
    double hp1 = HP1, exp1 = EXP1, hp2 = HP2, exp2 = EXP2, e3 = E3, holder = 0;
    roundUpHP(hp1); roundUpHP(hp2); roundUpExp(exp1); roundUpExp(exp2);

    //Taxi score
    double taxi_score[10][10];
    int i_meet_point = 0, j_meet_point = 0;


    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            taxi_score[i][j] = (e3*j + i*2)*(i-j);
            if (taxi_score[i][j] > e3 * 2) {
                i_meet_point++;
            }
            else if (taxi_score[i][j] < -e3){
                j_meet_point++;
            }
        }
    }

    //At meeting point
    while ((i_meet_point >= 10 || (j_meet_point >= 10))) {
        i_meet_point = i_meet_point/10 + i_meet_point%10;
        j_meet_point = j_meet_point/10 + j_meet_point%10;
    }
    int sherlock_watson_score = Diagonal(i_meet_point, j_meet_point, taxi_score);

    //Compare the 2 scores
    if (abs(taxi_score[i_meet_point][j_meet_point]) > sherlock_watson_score){
        hp1 *= 0.9; roundUpHP(hp1);
        hp2 *= 0.9; roundUpHP(hp2);
        exp1 *= 0.88; roundUpExp(exp1);
        exp2 *= 0.88; roundUpExp(exp2);
        HP1 = hp1; EXP1 = exp1; HP2 = hp2; EXP2 = exp2;

        return int(taxi_score[i_meet_point][j_meet_point]);

    }
    else {
        hp1 *= 1.1; roundUpHP(hp1);
        hp2 *= 1.1; roundUpHP(hp2);
        exp1 *= 1.12; roundUpExp(exp1);
        exp2 *= 1.12; roundUpExp(exp2);
        HP1 = hp1; EXP1 = exp1; HP2 = hp2; EXP2 = exp2;
        return sherlock_watson_score;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string password = s, victim_email = email, se = "";

    // 1st Condition: length [8, 20]
    int pass_length = password.length();
    if (pass_length < 8) return -1;
    else if (pass_length > 20) return -2;

    // 2nd Condition: Contains se
    se = findSE(victim_email);
    int se_position = password.find(se);
    if (se_position != string::npos) {
        return -(300 + se_position);
    }
    // 3rd Condition: Repetitive char
    int repeat_pos = findRepetition(password);
    if (repeat_pos != -1) {
        return -(400 + repeat_pos);
    }

    // 4th Condition: Contains special char
    string special_char = "@#%$!";
    int special_char_count = 0;
    for (char i : special_char){
        if (password.find(i) != string::npos){
            special_char_count++;
        }
    }
    if (special_char_count == 0) {
        return -5;
    }
    // 5th Condition: Invalid character
    int invalid_char_pos = invalidChar(password);
    if (invalid_char_pos != -1) {
        return invalid_char_pos;
    }


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    string repeat_pass_holder = "", current_pass;
    int unique_pass_num = 0, counter = 0, max_count = 0;
    string repeat_pass_arr[100] = {"first"};
    for (int i = 1; i < num_pwds; i++){
        repeat_pass_arr[i] = "none";
    }
    //Find unique password & their amount
    for (int i = 0; i < num_pwds; i++){
            current_pass = arr_pwds[i];
            for (int j = 0 ; j < num_pwds ; j++){
                if (repeat_pass_arr[j] == "none") break;
                else if (repeat_pass_arr[j] == current_pass){
                    break;
            }
                else {
                    repeat_pass_arr[j] = current_pass;
                    repeat_pass_holder = repeat_pass_holder + current_pass + " ";
                    unique_pass_num++;
                }
        }
    }
    int repeat_times[unique_pass_num];
    //Find max repetition & each unique pass repeat time
    string most_repeat_pass[unique_pass_num], target;
    istringstream iss(repeat_pass_holder);
    for (int i = 0; i < unique_pass_num; i++){
        iss >> target; 
        for (int i = 0; i < num_pwds; i++){

            if (arr_pwds[i] == target){
                counter++;
                if (max_count < counter)
                    max_count = counter;
            }
        }
        repeat_times[i] = counter;
        counter = 0;
    }
    // Find max repeat passwords
    for (int i = 0; i < unique_pass_num; i++)
    counter = 0;
    string str_holder;
    istringstream iss2(repeat_pass_holder);
    for (int i = 0; i < unique_pass_num; i++){
        iss2 >> str_holder;

        if (repeat_times[i] == max_count){
            most_repeat_pass[counter] = str_holder;
            counter++;
        }
    }
    //Find longest length among highest repetition
    int max_length = most_repeat_pass[0].length(), current_length = 0;
        //Find max length
    for (string i : most_repeat_pass){
        if (max_length < i.length()) {
            max_length = i.length();
        }
    }
        //Find correct pass
    string correct_pass = "";
    for (string i : most_repeat_pass){
        if (max_length == i.length()){
            correct_pass = i;
            break;
        }
    }
    //Return the correct pass position
    for (int i = 0; i < num_pwds; i++){
        if (correct_pass == arr_pwds[i]){
            return i;
        }
    }
    return -1;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////