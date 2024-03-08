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
void updateEXP(int& exp) {
    if (exp > 600) {
        exp = 600;
    }
    else if (exp < 0) {
        exp = 0;
    }
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    updateEXP(exp1);
    updateEXP(exp2);
    if (e1 < 0 || e1>99)   return -99;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1)
        {
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
            return -99;
        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1 + (float)D / 200);
            
        }
        else exp1 = ceil(exp1 - (float)D / 100);

        updateEXP(exp1);
        updateEXP(exp2);
    }
    else {
        if (e1 <= 19) {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
        }
        else if (e1 <= 49) {
            exp2 = ceil(exp2 + (float)e1 / 9 + 21);
        }
        else if (e1 <= 65) {
            exp2 = ceil(exp2 + (float)e1 / 16 + 17);
        }
        else if (e1 <= 79) {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
            if (exp2 > 200) {
                exp2 = ceil(exp2 + (float)e1 / 9 + 21);
            }
        }
        else if (e1 <= 99) {
            exp2 = ceil(exp2 + (float)e1 / 4 + 19);
            exp2 = ceil(exp2 + (float)e1 / 9 + 21);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (float)e1 / 16 + 17);
                exp2 += ceil(exp2 * 0.15);
            }
        }
        updateEXP(exp2);
        exp1 = exp1 - e1;
        updateEXP(exp1);
    }
    return exp1 + exp2;
}
// Task 2
int nearestPerfectSquare(int n) {
    int lower = sqrt(n);
    int upper = lower + 1; 

    int diffLower = n - (lower * lower);
    int diffUpper = (upper * upper) - n;

    if (diffLower <= diffUpper) {
        return lower * lower;
    }
    else {
        return upper * upper;
    }
}
void updateMoney(int& money) {
    if (money > 3000) {
        money = 3000;
    }
    else if (money < 0) {
        money = 0;
    }
}
void updateHP(int& hp) {
    if (hp > 666) {
        hp = 666;
    }
    else if (hp < 0) {
        hp = 0;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //road 1
    updateEXP(EXP1);
    updateMoney(M1);
    updateHP(HP1);
    if (E2 < 0 || E2>99)   return -99;
    float P1, P2, P3 = 0;
    int S = nearestPerfectSquare(EXP1);
    if (EXP1 >= S) {
        P1 = 1;
    }
    else {
        P1 = ((float)EXP1 / S + 80) / 123;
    }
    int halfM1 = M1 / 2;
    int usedMoney = 0;
    //road 2
    if (E2 % 2 == 1) {
        while (true) {
            if (HP1 < 200) {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
                usedMoney += 150;
            }
            else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
                usedMoney += 70;
            }
            updateMoney(M1);
            updateHP(HP1);
            if (usedMoney > halfM1)   break;

            if (EXP1 < 400) {
                M1 -= 200;
                usedMoney += 200;
            }
            else {
                M1 -= 120;
                usedMoney += 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            updateMoney(M1);
            updateEXP(EXP1);
            if (usedMoney > halfM1)   break;

            if (EXP1 < 300) {
                M1 -= 100;
                usedMoney += 100;
            }
            else {
                M1 -= 120;
                usedMoney += 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            if (usedMoney > halfM1)   break;
        }

    }
    else {

        //1
        if (M1 != 0) {

            if (HP1 < 200) {
                HP1 = ceil(HP1*1.3);
                M1 -= 150;
            }
            else {
                HP1 = ceil(HP1*1.1);
                M1 -= 70;
            }
            updateMoney(M1);
            updateHP(HP1);
        }
        //2
        if (M1 != 0) {

            if (EXP1 < 400) {
                M1 -= 200;
            } 
            else {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            updateMoney(M1);
            updateEXP(EXP1);
        }
        //3
        if (M1 != 0) {

            if (EXP1 < 300) {
                M1 -= 100;
            }
            else M1 -= 120;
            EXP1 = ceil(EXP1 * 0.9);
            updateMoney(M1);
            updateEXP(EXP1);
        }
    }
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    updateEXP(EXP1);
    updateHP(HP1);
    S = nearestPerfectSquare(EXP1);
    if (EXP1 >= S) {
        P2 = 1;
    }
    else {
        P2 = ((float)EXP1 / S + 80) / 123;
    }

    //road 3
    int arr[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i;
    if (E2 < 10) {
        i = E2;
    }
    else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    P3 = (float)arr[i] / 100;
    if ( (P1 == 1) && (P2 == 1) && (P3 == 1)) {
        EXP1 = ceil(EXP1 * 0.75);
        updateEXP(EXP1);
    }
    else
    {
        if ((P1 + P2 + P3) / 3 < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
            updateHP(HP1);
            updateEXP(EXP1);
        }
        else {
            HP1 = ceil(HP1 * 0.90);
            EXP1 = ceil(EXP1 * 1.20);
            updateHP(HP1);
            updateEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int calculateMaxPoint(int map[10][10], int i, int j) {
    int maxPoint = 0;

    int row = i, col = j;
    while (row > 0 && col > 0) {
        row--;
        col--;
    }

    while (row < 10 && col < 10) {
        maxPoint = max(maxPoint, map[row][col]);
        row++;
        col++;
    }

    row = i;
    col = j;
    while (row > 0 && col < 9) {
        row--;
        col++;
    }

    while (row < 10 && col >= 0) {
        maxPoint = max(maxPoint, map[row][col]);
        row++;
        col--;
    }

    return maxPoint;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int map[10][10];
    int sherlock[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sherlock[i][j] = abs(calculateMaxPoint(map, i, j));
        }
    }
    int count1, count2;
    count1 = count2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (map[i][j] > E3 * 2)
                count1++;
            if (map[i][j] < E3 * -1) {
                count2++;
            }
        }
    }
    int i, j;
    if (count1 < 10) {
        i = count1;
    }
    else {
        int temp = count1;
        while (temp >= 10) {
            temp = temp / 10 + temp % 10;
        }
        i = temp;
    }
    if (count2 < 10) {
        j = count2;
    }
    else {
        int temp = count2;
        while (temp >= 10) {
            temp = temp / 10 + temp % 10;
        }
        j = temp;
    }
    int taxiPoint = map[i][j];
    int diff = taxiPoint - sherlock[i][j];
    if (abs(taxiPoint)>sherlock[i][j]) {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        return taxiPoint;
    }
    else {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        return sherlock[i][j];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int sLength = strlen(s);
    if (sLength < 8) {
        return -1; 
    }
    if (sLength > 20) {
        return -2; 
    }

	int sePos = strchr(email, '@') - email;
	char se[255];
	strncpy_s(se, email, sePos);
	se[sePos] = '\0';
	const char* sePtr = strstr(s, se);
	if (sePtr != nullptr) {
	    int position = sePtr - s;
	    return -(300 + position); 
	}

    for (int i = 0; i < sLength - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }

    bool hasSpecialChar = false;
    for (int i = 0; i < sLength; i++) {
        char c = s[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        return -5; 
    }


    for (int i = 0; i < sLength; i++) {
        char c = s[i];
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!') {
            return i; 
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const char* max_count_password = nullptr;
    int max_count = 0;
    int max_length = 0;
    int correct_password_index = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* current_password = arr_pwds[i];
        int current_length = strlen(current_password);
        int current_count = 0;

        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], current_password) == 0) {
                current_count++;
            }
        }

        if (current_count > max_count) {
            max_count = current_count;
            max_count_password = current_password;
            max_length = current_length;
        }
        else if (current_count == max_count && current_length > max_length) {
            max_count_password = current_password;
            max_length = current_length;
        }
    }

    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], max_count_password) == 0) {
            correct_password_index = i;
            break;
        }
    }

    return correct_password_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////