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

int KiemtraEXP(int exp){
     if (exp >  600) {
        exp = 600;
    }

    if (exp < 0) {
        exp = 0;
    }
    return exp;
}

int KiemtraHP(int HP){
    if (HP > 666){
        HP = 666;
    }
    
    if (HP < 0){
        HP = 0;
    }
    return HP;
}

int KiemtraM(int M){
     if (M > 3000){
        M = 3000;
    }

    if (M < 0){
        M = 0;
    }
    return M;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
  int D;
  if (e1 < 0 || e1 > 99) {
        return -99;
    }
    if (e1 >= 0 && e1 < 4) {
        switch (e1) {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += 29 + 45 + 75;
            break;
        default:
            break;
        }
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0){
            exp1 += ceil(D/200.0);
        }
        else {
            exp1 = ceil(exp1 - D/100.0);
        }
}

else {
    if (e1 >= 4 && e1 <= 19) {
        exp2 += ceil((e1 / 4.0) + 19.0);
        exp1 -= e1;
    }
    else if (e1 >= 20 && e1 <= 49) {
        exp2 += ceil((e1 / 9.0) + 21.0);
        exp1 -= e1;
    }
    else if (e1 >= 50 && e1 <= 65) {
        exp2 += ceil((e1 / 16.0) + 17.0);
        exp1 -= e1;
    }
    else if (e1 >= 66 && e1 <= 79) {
        exp2 += ceil((e1 / 4.0) + 19.0);
        if (exp2 > 200) {
            exp2 += ceil((e1 / 9.0) + 21.0);
        }
        exp1 -= e1;
    }
    else {
        exp2 += ceil((e1 / 4.0) + 19.0 + (e1 / 9.0) + 21.0);
        if (exp2 > 400) {
            exp2 += ceil((e1 / 16.0) + 17.0);
            exp2 += ceil(0.15 * exp2);
            exp1 -= e1;
        }
    }
}
    exp1 = KiemtraEXP(exp1);
    exp2 = KiemtraEXP(exp2);

    return exp1 + exp2;
}

// Task 2

int KiemTraSCP(int EXP1) {
    int p;
    int s = (int)sqrt(EXP1);
    int previous = s + 1;
    
    if ((EXP1 - s * s < previous * previous - EXP1) || EXP1 > 576) {
        p = 100;
    }
    else {
        p = ((EXP1 / (previous * previous)) + 80.0) / 123.0 * 100.0;
    }
    return p;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0){
        return -99;
    }
    //CON DUONG 01
    int p1;
    p1 = KiemTraSCP(EXP1);

    //CON DUONG 02
    int half_money = (int)(0.5 * M1);
    int spend_money = 0;
    if (E3 % 2 != 0) {
        while (spend_money < half_money) {
            if (HP1 < 200) {
                HP1 += ceil(0.3 * HP1);
                M1 -= 150;
                spend_money += 150;
                if (spend_money >= half_money) {
                  break;
                }
            }
            else {
                HP1 += ceil(0.10 * HP1);
                M1 -= 70;
                spend_money += 70;
                if (spend_money >= half_money) {
                    break;
                }
            }
            if (EXP1 >= 400) {
                M1 -= 120;
                spend_money += 120;
                EXP1 += ceil(0.13 * EXP1);
                if (spend_money >= half_money) {
                    break;
                }
            }
            else {
                M1 -= 200;
                EXP1 += ceil(0.13 * EXP1);
                spend_money += 200;
                if (spend_money >= half_money) {
                    break;
                }
            }
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = ceil(0.9 * EXP1);
                spend_money += 100;
                if (spend_money >= half_money) {
                   break;
                }
            }
             else {
                 M1 -= 120;
                EXP1 = ceil(0.9 * EXP1);
                spend_money += 120;
                if (spend_money >= half_money) {
                   break;
                }
            }
    }
    HP1 = ceil(0.83 * HP1);
    EXP1 += ceil(0.17 * EXP1);
}
else {
    while (M1 >= 0) {
        if (HP1 < 200) {
            HP1 += ceil(0.3 * HP1);
            M1 -= 150;
            if (M1 <= 0){
                break;
            }
        }
        else {
            HP1 += ceil(0.1 * HP1);
            M1 -= 70;
            if (M1 <= 0){
                break;
            }
        }

        if (EXP1 >= 400) {
            M1 -= 120;
            EXP1 += ceil(0.13 * EXP1);
            if (M1 <= 0){
                break;
            }
        }
        else {
            M1 -= 200;
            EXP1 += ceil(0.13 * EXP1);
            if (M1 <= 0){
                break;
            }
        }

        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 = ceil(0.9 * EXP1);
            if (M1 <= 0){
                break;
            }
        }
        else {
            M1 -= 120;
            EXP1 = ceil(0.9 * EXP1);
            if (M1 <= 0){
                break;
            }
        }
    }
    HP1 = ceil(0.83 * HP1);
    EXP1 += ceil(0.17 * EXP1);
}

    int p2;
    p2 = KiemTraSCP(EXP1);

    //CON DUONG 03

    int percentage[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    int p3;
    int sum;
    if (E3 >= 0 && E3 <= 9) {
        switch (E3) {
            case 0:
                p3 = percentage[0];
                break;
            case 1:
                p3 = percentage[1];
                break;
            case 2:
                p3 = percentage[2];
                break;
            case 3:
                p3 = percentage[3];
                break;
            case 4:
                p3 = percentage[4];
                break;
            case 5:
                p3 = percentage[5];
                break;
            case 6:
                p3 = percentage[6];
                break;
            case 7:
                p3 = percentage[7];
                break;
            case 8:
                p3 = percentage[8];
                break;
            case 9:
                p3 = percentage[9];
                break;
            default:
                break;
    }
}
else {
    sum = (E3 / 10) + (E3 % 10);
    sum = sum%10;
    p3 = percentage[sum];
}


   double ave;

if (p1 == 100 && p2 == 100 && p3 == 100) {
    EXP1 = ceil(0.75 * EXP1);
} else {
    ave = ((p1 + p2 + p3) / 3.0) / 100.0; 
    if (ave >= 0.5) {
        HP1 = ceil(0.9 * HP1);
        EXP1 += ceil(0.2 * EXP1);
    } 
    else { 
        HP1 = ceil(0.85 * HP1);
        EXP1 += ceil(0.15 * EXP1);
    }
}

   HP1 = KiemtraHP(HP1);
   EXP1 = KiemtraEXP(EXP1);
   M1 = KiemtraM(M1);

    return HP1+M1+EXP1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3 < 0 || E3 > 99){
        return -99;
    }
    
    int fastest_way[10][10];
    int score[10][10];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            score[i][j] = ((E3*j) + (i * 2)) * (i - j);
        }
    }

    int max_right_diagonal[10][10];
    int max_left_diagonal[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            max_left_diagonal[i][j] = score[i][j];
            max_right_diagonal[i][j] = score[i][j];
        }
    }

   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        int x = i;
        int y = j;
        while(x >= 0 && y >= 0 && x < 10 && y < 10){
            if(max_left_diagonal[i][j] < score[x][y]){
                max_left_diagonal[i][j] = score[x][y];
            }
            x++;
            y++;
            if (x >= 10 || y >= 10){
                break;
            }
        }
    }
}

for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        int x = i;
        int y = j;
        while(x >= 0 && y >= 0 && x < 10 && y < 10){
            if(max_right_diagonal[i][j] < score[x][y]){
                max_right_diagonal[i][j] = score[x][y];
            }
            x++;
            y--;
            if (x >= 10 || y < 0){
                break;
            }
        }
    }
}


    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            fastest_way[i][j] = max(max_left_diagonal[i][j],max_right_diagonal[i][j]);
        }
    }
    
    int positive = 0;
    int negative = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (score[i][j] > E3*2){
                positive++;
            }
            else if (score[i][j] < (-E3)){
                negative++;
            }
        }
    }
    int sum_positive = 0;
    if (positive < 10){
        sum_positive = positive;
    }
    else{
        while (positive>=10){
        sum_positive = positive/10 + positive%10;
        if (sum_positive == 10){
            sum_positive = sum_positive/10 + sum_positive%10;
        }
        positive /= 10;
    }
    }
    int sum_negative = 0;
    if (negative < 10){
        sum_negative = negative;
    }
    else{
        while (negative >= 10){
        sum_negative = negative/10 + negative % 10;
        if (sum_negative == 10){
            sum_negative = sum_negative/10 + sum_negative%10;
        }
        negative /= 10;
    }
    }
    int answer;


    if (abs(score[sum_positive][sum_negative]) < fastest_way[sum_positive][sum_negative]){
        EXP1 += ceil(0.12*EXP1);
        HP1 += ceil(0.1*HP1);
        EXP2 += ceil(0.12*EXP2);
        HP2 += ceil(0.1*HP1);
        answer = fastest_way[sum_positive][sum_negative];
    }
    else {
        EXP1 = ceil(0.88*EXP1);
        HP1 = ceil(0.9*HP1);
        EXP2 = ceil(0.88*EXP2);
        HP2 = ceil(0.9*HP2);
        answer = score[sum_positive][sum_negative];
    }

    return answer;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100];
    int len = strlen(s);
    int previous_len = 0;
    while (email[previous_len] != '@'){
        previous_len++;
    }
    for (int i = 0; i < previous_len; i++){
        se[i] = email[i];
    }
    int index;
    for (int i = 0; i <= len - previous_len; i++){
        bool match = true;
        for (int j = 0; j < previous_len; j++){
            if (s[i+j] != se[j]){
                match = false;
                break;
            }
        }
        if (match) {
            index = i;
            return -(300+index);
        }
    }

    if (len < 8){
        return -1;
    }
    if (len > 20){
        return -2;
    }
    bool special_value = false;
    for (int i = 0; i < len; i++){
       if (s[i] == '@' || s[i] == '#' || s[i] == '%'  || s[i] == '$' || s[i] == '!'){
        special_value = true;
        break;
       }
    }
    if(!special_value){
        return -5;
    }

    for (int i = 0; i < len-2; i++){
        if (s[i] == s[i+1] && s[i+1] == s[i+2]){
            return -(400+i);
        }
    }

    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int max_repeat = 1;
    int index = 0;
    for (int i = 0; i < num_pwds; i++) {
        int repeat = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                repeat++;
                if (repeat > max_repeat) {
                    max_repeat = repeat;
                    index = i; 
            }
            else if (repeat == max_repeat && strlen(arr_pwds[i]) > strlen(arr_pwds[index])) {
                index = i; 
            }
        }
    }
}
    return index;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
