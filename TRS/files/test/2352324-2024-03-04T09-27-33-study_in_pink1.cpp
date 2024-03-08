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

int limitHP1(int& hp1) {
    if (hp1 > 666) {
        hp1 = 666;
    }
    if (hp1 < 0) {
        hp1 = 0;
    }
    return hp1;
}
int limitHP2(int& hp2) {
    if (hp2 > 666) {
        hp2 = 666;
    }
    if (hp2 < 0) {
        hp2 = 0;
    }
    return hp2;
}
int limitEXP1(int& exp1) {
    if (exp1 > 600) {
        exp1 = 600;
    }
    if (exp1 < 0) {
        exp1 = 0;
    }
    return exp1;
}
int limitEXP2(int& exp2) {
    if (exp2 > 600) {
        exp2 = 600;
    }
    if (exp2 < 0) {
        exp2 = 0;
    }
    return exp2;
}

int limitM1(int& m1) {
    if (m1 > 3000) {
        m1 = 3000;
    }
    if (m1 < 0) {
        m1 = 0;
    }
    return m1;
}
int limitM2(int& m2) {
    if (m2 > 3000) {
        m2 = 3000;
    }
    if (m2 < 0) {
        m2 = 0;
    }
    return m2;
}

int my_ceil(float a)
{
    int temp = (int)a;
    if (a == temp) {
        return a;
    }
    return temp + 1;
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

    if (e1 >= 0 && e1 <= 3) {
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
            exp2 += 149;
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = exp1 + my_ceil(D / 200.0);
        }
        else {
            exp1 = exp1 - my_ceil(D / 100);
        }



    }
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) {
            exp2 += my_ceil(e1 / 4.0) + 19;
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += my_ceil(e1 / 9.0) + 21;
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += my_ceil(e1 / 16.0) + 17;
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += my_ceil(e1 / 4.0) + 19;
            if (exp2 > 200) {
                exp2 += my_ceil(e1 / 9.0) + 21;
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = exp2 + my_ceil(e1 / 4.0) + 19 + my_ceil(e1 / 9.0) + 21;
            if (exp2 > 400) {
                exp2 += my_ceil(e1 / 16.0) + 17;
                exp2 = exp2 + my_ceil(exp2 * 15.0 / 100.0);
            }

        }
        exp1 -= e1;

    }

    else {
        return -99;
    }


    limitEXP1(exp1);
    limitEXP2(exp2);

    return exp1 + exp2;
}



// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    double   ceilexp1 = EXP1;

    if (E2 >= 0 && E2 <= 99) {



        //******************************************************//    
        int sqrt_exp1 = round(sqrt(EXP1));
        int lower_square = sqrt_exp1 * sqrt_exp1;
        int upper_square = (sqrt_exp1 + 1) * (sqrt_exp1 + 1);
        int nearest_square;

        if (EXP1 - lower_square <= upper_square - EXP1) {
            nearest_square = lower_square;
        }
        else {
            nearest_square = upper_square;
        }
        int s1 = nearest_square;

        //********* KIEM TRA SO CHINH PHUONG GAN NHAT **********//


        //con duong 1:
        double p1, p2, p3;
        if (EXP1 >= s1) {
            p1 = 1.0;
        }
        else {
            p1 = (ceilexp1 / s1 + 80) / 123.0;
        }


        //con duong 2:
        int totalCost = 0, M2 = M1;
        do {
            //phase 1:
            if (HP1 < 200) {
                HP1 = my_ceil(HP1 * 1.3);       limitHP1(HP1);
                M1 -= 150;    limitM1(M1);
                totalCost += 150;
            }
            else {
                HP1 = my_ceil(HP1 * 1.1);       limitHP1(HP1);
                M1 -= 70;    limitM1(M1);
                totalCost += 70;
            }
            if ((E2 % 2 != 0 && totalCost > M2 * 0.5) || E2 % 2 == 0 && M1 <= 0) {
                break;
            }


            //phase 2:
            if (EXP1 < 400) {
                M1 -= 200;    limitM1(M1);
                totalCost += 200;

            }
            else {
                M1 -= 120;    limitM1(M1);
                totalCost += 120;

            }
            EXP1 = my_ceil(EXP1 * 1.13);       limitEXP1(EXP1);
            if ((E2 % 2 != 0 && totalCost > M2 * 0.5) || E2 % 2 == 0 && M1 <= 0) {
                break;
            }


            //phase 3:
            if (EXP1 < 300) {
                M1 -= 100;    limitM1(M1);
                totalCost += 100;

            }
            else {
                M1 -= 120;    limitM1(M1);
                totalCost += 120;

            }
            EXP1 = my_ceil(EXP1 * 0.9);       limitEXP1(EXP1);

            if ((E2 % 2 != 0 && totalCost > M2 * 0.5) || E2 % 2 == 0 && M1 <= 0) {
                break;
            }
        } while (E2 % 2 != 0);


        HP1 = my_ceil(HP1 * 0.83);       limitHP1(HP1);
        EXP1 = my_ceil(EXP1 * 1.17);       limitEXP1(EXP1);




        //******************************************************//    
        sqrt_exp1 = round(sqrt(EXP1));
        lower_square = sqrt_exp1 * sqrt_exp1;
        upper_square = (sqrt_exp1 + 1) * (sqrt_exp1 + 1);

        if (EXP1 - lower_square <= upper_square - EXP1) {
            nearest_square = lower_square;
        }
        else {
            nearest_square = upper_square;
        }
        int s2 = nearest_square;
        ceilexp1 = EXP1;
        //********* KIEM TRA SO CHINH PHUONG GAN NHAT **********//
        if (EXP1 >= s2) {
            p2 = 1.0;
        }
        else {
            p2 = (ceilexp1 / s2 + 80) / 123.0;
        }


        //con duong 3:

            // Xác định chỉ số giá trị xác suất Pi
        int i = 0;
        if (E2 < 10) {
            i = E2;
        }
        else {
            int sum = E2 / 10 + E2 % 10;
            i = sum % 10;
        }

        // Tính toán xác suất tìm thấy vali trên con đường 3
        switch (i) {
        case 0:
            p3 = 0.32;
            break;
        case 1:
            p3 = 0.47;
            break;
        case 2:
            p3 = 0.28;
            break;
        case 3:
            p3 = 0.79;
            break;
        case 4:
            p3 = 1.0;
            break;
        case 5:
            p3 = 0.5;
            break;
        case 6:
            p3 = 0.22;
            break;
        case 7:
            p3 = 0.83;
            break;
        case 8:
            p3 = 0.64;
            break;
        case 9:
            p3 = 0.11;
            break;
        }


        // Kiểm tra điều kiện tất cả các con đường đều có xác suất 100%
        double avgP = 0.0;
        if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0) {

            EXP1 = my_ceil(EXP1 * 0.75);       limitEXP1(EXP1);
        }

        else {
            avgP = (p1 + p2 + p3) / 3.0;
            if (avgP < 0.5) {
                HP1 = my_ceil(HP1 * 0.85);       limitHP1(HP1);
                EXP1 = my_ceil(EXP1 * 1.15);       limitEXP1(EXP1);

            }
            else {
                HP1 = my_ceil(HP1 * 0.9);
                EXP1 = my_ceil(EXP1 * 1.2);

            }
        }

    }
    else {
        return -99;
    }




    limitHP1(HP1);
    limitEXP1(EXP1);
    limitM1(M1);
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function


    if (E3 >= 0 && E3 <= 99) {

        int map[10][10];



        // Tính điểm cho từng vị trí trên bản đồ của taxi
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        //print the matrix

        /*for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << setw(7) << map[i][j]<<setw(5);
            }
            cout << endl;
        }*/


        int countPlus = 0;
        int meet_i;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] > E3 * 2) {
                    countPlus++;
                }
            }
        }
        do {
            meet_i = countPlus / 10 + countPlus % 10;
            countPlus = meet_i;
        } while (meet_i > 9);



        int meet_j;
        int countMinus = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] < -E3) {
                    countMinus++;
                }
            }
        }
        do {
            meet_j = countMinus / 10 + countMinus % 10;
            countMinus = meet_j;
        } while (meet_j > 9);





        int finalValue = map[meet_i][meet_j];


        for (int i = meet_i, j = meet_j; i >= 0 && j >= 0; i--, j--) {
            if (map[i][j] > finalValue) {
                finalValue = map[i][j];
            }
        }

        for (int i = meet_i, j = meet_j; i < 10 && j >= 0; i++, j--) {
            if (map[i][j] > finalValue) {
                finalValue = map[i][j];
            }
        }

        for (int i = meet_i, j = meet_j; i < 10 && j < 10; i++, j++) {
            if (map[i][j] > finalValue) {
                finalValue = map[i][j];
            }
        }

        for (int i = meet_i, j = meet_j; i >= 0 && j < 10; i--, j++) {
            if (map[i][j] > finalValue) {
                finalValue = map[i][j];
            }
        }

        if (finalValue < 0) {
            finalValue = abs(finalValue);
        }



        if (abs(map[meet_i][meet_j]) > finalValue) {
            HP1 = my_ceil(HP1 * 0.9);
            HP2 = my_ceil(HP2 * 0.9);
            EXP1 = my_ceil(EXP1 * 0.88);
            EXP2 = my_ceil(EXP2 * 0.88);
            finalValue = map[meet_i][meet_j];
        }
        else {
            HP1 = my_ceil(HP1 * 1.1);
            HP2 = my_ceil(HP2 * 1.1);
            EXP1 = my_ceil(EXP1 * 1.12);
            EXP2 = my_ceil(EXP2 * 1.12);

        }




        limitHP1(HP1);
        limitHP2(HP2);
        limitEXP1(EXP1);
        limitEXP2(EXP2);

        return finalValue;
    }
    else {
        return -99;
    }
}



// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    //Find se
    char se[100];

    int atPos = -1;
    for (int i = 0; email[i] != '\0'; ++i) {
        if (email[i] == '@') {
            atPos = i;
            break;
        }
    }

    if (atPos != -1) {
        for (int i = 0; i < atPos; ++i) {
            se[i] = email[i];
        }
    }
    se[atPos] = '\0'; // Null-terminate the string

    //Length?
    if (strlen(s) < 8) {
        return -1;
    }
    if (strlen(s) > 20) {
        return -2;
    }

    // s has se
    for (int i = 0; s[i] != '\0'; ++i) {
        bool found = true;
        for (int j = 0; se[j] != '\0'; ++j) {
            if (s[i + j] != se[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return -(300 + i);
        }
    }


    // more than 2 char repeat
    for (int i = 0; i < strlen(s) - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    // have specialChar?
    bool specialChar = false;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialChar = true;
        }
    }
    // if yes return
    if (!specialChar) {
        return -5;
    }
    // valid pass have 0-9 a-z A-Z specChar
    for (int i = 0; i < strlen(s); i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }

    return -10;
}


int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxSize = 0;
    int firstPos = -1;
    string correctPass;

    for (int i = 0; i < num_pwds; ++i) {
        string pass = arr_pwds[i];
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (pass == arr_pwds[j]) {
                count++;
            }
        }

        if (count > maxCount || (count == maxCount && pass.size() > maxSize)) {
            correctPass = pass;
            maxCount = count;
            maxSize = pass.size();
            firstPos = i;
        }
    }

    return firstPos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////