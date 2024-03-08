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

int process_hp(double hp) {
    if (hp - int(hp) > 1e-5) hp = ceil(hp);
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
    return hp;
}

int process_exp(double exp) {
    if (exp - int(exp) > 1e-5)exp = ceil(exp);
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
    return exp;
}

int process_money(double money) {
    if (money - int(money) > 1e-5) money = ceil(money);
    if (money > 3000) money = 3000;
    if (money < 0) money = 0;
    return money;
}

int nearestSquare(int n){
    int ans = sqrt(double(n));
    if (n - ans*ans < (ans+1)*(ans+1) - n) return ans*ans;
    return (ans+1)*(ans+1);
}

void task_2_road_2_event_1(int & HP1, int & EXP1, int & moneySpent) {
    if (HP1 < 200) {
        HP1 = process_hp(HP1 * 1.3);
        moneySpent += 150;
    }
    else {
        HP1 = process_hp(HP1 * 1.1);
        moneySpent += 70;
    }
}
void task_2_road_2_event_2(int & HP1, int & EXP1, int & moneySpent) {
    if (EXP1 < 400) moneySpent += 200;
    else moneySpent += 120;
    EXP1 = process_exp(EXP1 * 1.13);
}

void task_2_road_2_event_3(int & HP1, int & EXP1, int & moneySpent) {
    if (EXP1 < 300) moneySpent += 100;
    else moneySpent += 120;
    EXP1 = process_exp(EXP1 * 0.9);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // cout << "EXP1: " << exp1 << ", EXP2: " << exp2 << ", E1: " << e1 << endl;
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;

    exp1 = process_exp(exp1);
    exp2 = process_exp(exp2);
    // CASE 1
    if (e1 >= 0 && e1 <= 3){
        switch (e1)
        {
        case 0:
            exp2 = process_exp(exp2+29);
            break;
        case 1:
            exp2 = process_exp(exp2 + 45);
            break;
        case 2:
            exp2 = process_exp(exp2 + 75);
            break;   
        case 3:
            exp2 = process_exp(exp2 + 29 + 45 + 75);
            break;
        default:
            break;
        }
        int D = e1*3 + exp1*7; // Sherlock's decision
        // cout<<D<<endl;
        if (D % 2 == 0) exp1 = process_exp(exp1 + double(D) / 200);
        else exp1 = process_exp(exp1 - double(D) / 100);
    }
    // CASE 2
    else if (e1 >= 4 && e1 <= 99){
        if (e1 >= 4 && e1 <= 19) exp2 = process_exp(exp2 + double(e1)/4+19);
        else if (e1 >= 20 && e1 <= 49) exp2 = process_exp(exp2 + double(e1)/9+21);
        else if (e1 >= 50 && e1 <= 65) exp2 = process_exp(exp2 + double(e1)/16+17);
        else if (e1 >= 66 && e1 <= 79){
            exp2 = process_exp(exp2 + double(e1)/4+19);
            if (exp2 > 200) exp2 = process_exp(exp2 + double(e1)/9+21);
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = process_exp(exp2 + double(e1)/4+19);
            exp2 = process_exp(exp2 + double(e1)/9+21);
            if (exp2 > 400) {
                exp2 = process_exp(exp2 + double(e1)/16+17);
                exp2 = process_exp(exp2 * 1.15);
            }
        }
        exp1 = process_exp(exp1 - e1);
    }
    // Case not in range
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // cout<<"HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", E2: "<< E2<<endl;
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;

    // Process data
    HP1 = process_hp(HP1);
    EXP1 = process_exp(EXP1);
    M1 = process_money(M1);

    double P1 = 1, P2 = 1, P3 = 1, P;
    int S, moneySpent;

    moneySpent = 0;
    // Road 1
    S = nearestSquare(EXP1);
    // cout<<"S = "<<S<<endl;
    if (EXP1 >= S) P1 = 1;
    else P1 = (double(EXP1)/S + 80)/123;
    // cout<<"P1 = "<<P1<<endl;

    // Road 2
    if (M1 == 0) {
        // do nothing lmao
    }
    else if (E2 % 2 == 1) {
        while (moneySpent <= M1 / 2.0){
            task_2_road_2_event_1(HP1, EXP1, moneySpent);
            if (moneySpent > M1 / 2.0) break;
            task_2_road_2_event_2(HP1, EXP1, moneySpent);
            // cout<<"After event 2: "<<HP1<<' '<<EXP1<<' '<<M1<<endl;
            if (moneySpent > M1 / 2.0) break;
            task_2_road_2_event_3(HP1, EXP1, moneySpent);
            if (moneySpent > M1 / 2.0) break;
        }
    }
    else {
        task_2_road_2_event_1(HP1, EXP1, moneySpent);
        if (moneySpent < M1) {
            task_2_road_2_event_2(HP1, EXP1, moneySpent);
            // cout<<"After event 2: "<<HP1<<' '<<EXP1<<' '<<M1<<endl;
            if (moneySpent < M1) task_2_road_2_event_3(HP1, EXP1, moneySpent);
        }
    }
    M1 = process_money(M1 - moneySpent);
    HP1 = process_hp(HP1 * 0.83);
    EXP1 = process_exp(EXP1 * 1.17);

    S = nearestSquare(EXP1);
    // cout<<"S = "<<S<<endl;
    if (EXP1 >= S) P2 = 1;
    else P2 = (double(EXP1)/S + 80)/123;
    // cout<<HP1<<' '<<EXP1<<' '<<M1<<endl;
    // cout<<"P2 = "<<P2<<endl;

    // Road 3
    double a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) P3 = a[E2] / 100;
    else P3 = a[(E2 / 10 + E2 % 10) % 10] / 100;
    // cout<<"P3 = "<<P3<<endl;

    // cout<<"P1 = "<<P1<<" P2 = "<<P2<<" P3 = "<<P3<<endl;
    if (P1 == 1 && P2 == 1 && P3 == 1) EXP1 = process_exp(EXP1 * 0.75);
    else {
        P = (P1 + P2 + P3) / 3;
        // cout<<"P = "<<P<<endl;
        if (P < 0.5) {
            HP1 = process_hp(HP1 * 0.85);
            EXP1 = process_exp(EXP1 * 1.15);
        }
        else {
            HP1 = process_hp(HP1 * 0.9);
            EXP1 = process_exp(EXP1 * 1.2);
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // cout<<"HP1: " << HP1 << ", EXP1: " << EXP1 <<"HP2: " << HP2 << ", EXP2: " << EXP2 << "E3: "<< E3<<endl;
    // TODO: Complete this function
    // Edge case
    if (E3 < 0 || E3 > 99) return -99;
    HP1 = process_hp(HP1);
    HP2 = process_hp(HP2);
    EXP1 = process_exp(EXP1);
    EXP2 = process_exp(EXP2);

    int gradeTaxiMatrix[10][10], gradeTaxi, gradeSW, i = 0, j = 0;
    // Taxi's point
    for (int i1 = 0; i1 < 10; i1++) {
        for (int j1 = 0; j1 < 10; j1++) {
            gradeTaxiMatrix[i1][j1] = (E3*j1 + i1*2) * (i1-j1);
            // cout<<gradeTaxiMatrix[i1][j1]<<' ';
        }
        // cout<<endl;
    }
    for (int i1 = 0; i1 < 10; i1++) {
        for (int j1 = 0; j1 < 10; j1++) {
            if (gradeTaxiMatrix[i1][j1] > E3 * 2) i++;
            if (gradeTaxiMatrix[i1][j1] < 0 - E3) j++;
        }
    }
    while (i >= 10) {
        i = i / 10 + i % 10;
    }
    while (j >= 10) {
        j = j / 10 + j % 10;
    }
    // cout<<i<<' '<<j<<endl;
    gradeTaxi = gradeTaxiMatrix[i][j];

    // S & W's point
    gradeSW = gradeTaxiMatrix[i][j];
    // Left diagonal
    for (int m = 0; i-m >= 0 && j-m >= 0; m++) {
        if (gradeTaxiMatrix[i-m][j-m] > gradeSW) gradeSW = gradeTaxiMatrix[i-m][j-m];
    }
    for (int m = 0; i+m < 10 && j+m < 10; m++) {
        if (gradeTaxiMatrix[i+m][j+m] > gradeSW) gradeSW = gradeTaxiMatrix[i+m][j+m];
    }
    // Right diagonal
    for (int m = 0; i-m >= 0 && j+m < 10; m++) {
        if (gradeTaxiMatrix[i-m][j+m] > gradeSW) gradeSW = gradeTaxiMatrix[i-m][j+m];
    }
    for (int m = 0; i+m < 10 && j-m >= 0; m++) {
        if (gradeTaxiMatrix[i+m][j-m] > gradeSW) gradeSW = gradeTaxiMatrix[i+m][j-m];
    }
    gradeSW = abs(gradeSW);

    // See if S&W catches the taxi
    if (abs(gradeTaxi) > gradeSW) {
        EXP1 = process_exp(EXP1 * 0.88);
        EXP2 = process_exp(EXP2 * 0.88);
        HP1 = process_hp(HP1 * 0.9);
        HP2 = process_hp(HP2 * 0.90);
        return gradeTaxi;
    }
    else {
        EXP1 = process_exp(EXP1 * 1.12);
        EXP2 = process_exp(EXP2 * 1.12);
        HP1 = process_hp(HP1 * 1.1);
        HP2 = process_hp(HP2 * 1.1);
        return gradeSW;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // cout<<s<<' '<<email<<endl;
    size_t len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;
    int tmp = 0;
    string se = "";
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') break;
        se = se + email[i];
    }
    // cout<<se<<endl;
    bool contain_in_email;
    if (se.size() <= len) {
        for (int i = 0; i < len - se.size() + 1; i++) {
        // if (email[0] == '@') break;
        // if (s[i] == email[tmp]) tmp++;
        // else tmp = 0;
        // if (email[tmp] == '@') return 0-(300 + i - tmp + 1); // If asked, idk what to say lol
        tmp = i;
        contain_in_email = true;
        for (int j = 0; j < se.size(); j++) {
            if (s[tmp] != email[j]) {
                contain_in_email = false;
                break;
            }
            tmp++;
        }
        if (contain_in_email) return 0-(300+i);
    }
    }
    for (int i = 1; i < len - 1; i++) {
        if (s[i] == s[i-1] && s[i] == s[i+1]) return 0-(400+ (i-1));
    }
    bool specialChar = false;
    for (int i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            specialChar = true;
            break;
        }
    }
    if (specialChar == false) return -5;
    for (int i = 0; i < len; i++) {
        if (! ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')){
            return i;
        }
    }

    // Valid password
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // for (int i = 0; i < num_pwds; i++) {
    //     cout<<arr_pwds[i]<<' ';
    // }
    // cout<<endl;
    // TODO: Complete this function
    int count[num_pwds];
    for (int i = 0; i < num_pwds; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < num_pwds; i++) {
        for (int j = i; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) count[i]++;
        }
    }
    // for (int i = 0; i < num_pwds; i++) {
    //     cout<<count[i]<<' ';
    // }
    // cout<<endl;
    int mostFrequentPwdIndex = 0;
    for (int i = 1; i < num_pwds; i++) {
        if (count[i] > count[mostFrequentPwdIndex]) {
            mostFrequentPwdIndex = i;
        }
        else if (count[i] == count[mostFrequentPwdIndex] && strlen(arr_pwds[i]) > strlen(arr_pwds[mostFrequentPwdIndex])){
            mostFrequentPwdIndex = i;
        }
    }

    return mostFrequentPwdIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////