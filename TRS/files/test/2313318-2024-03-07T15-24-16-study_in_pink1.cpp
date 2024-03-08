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

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

    //E1 out range
    if (e1 < 0 || e1>99) return -99;
    if (exp1 < 0) exp1 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp2 > 600) exp2 = 600;


    //E1 thuoc [0;3]
    if (e1 >= 0 && e1 <= 3) {

        if (e1 == 0) {
            exp2 += 29;
        }

        else if (e1 == 1) {
            exp2 += 45;
        }

        else if (e1 == 2) {
            exp2 += 75;
        }

        else {
            exp2 += 29 + 45 + 75;
        }

        //Check exp2
        if (exp2 > 600) exp2 = 600;

        // Du doan
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = (int)((double)exp1 + (double)D / 200 + 0.999);
        else exp1 = (int)((double)exp1 - (double)D / 100 + 0.999);

        // Check exp
        if (exp1 < 0) exp1 = 0;
        else if (exp1 > 600) exp1 = 600;

    }
    // E1 thuoc [4;99]   
    else {
        if (e1 >= 4 && e1 <= 19) exp2 = (int)((double)exp2 + (double)e1 / 4 + 19 + 0.999);
        else if (e1 <= 49) exp2 = (int)((double)exp2 + (double)e1 / 9 + 21 + 0.999);
        else if (e1 <= 65) exp2 = (int)((double)exp2 + (double)e1 / 16 + 17 + 0.999);
        else if (e1 <= 79) {
            exp2 = (int)(exp2 + (double)e1 / 4 + 19 + 0.999);
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 200) exp2 = (int)((double)exp2 + (double)e1 / 9 + 21 + 0.999);
            if (exp2 > 600) exp2 = 600;
        }
        else {
            exp2 = (int)((double)exp2 + (double)e1 / 4 + 19 + 0.999);
            //Check exp2
            if (exp2 > 600) exp2 = 600;
            exp2 = (int)((double)exp2 + (double)e1 / 9 + 21 + 0.999);
            //Check exp2
            if (exp2 > 600) exp2 = 600;
            if (exp2 > 400) {
                exp2 = (int)((double)exp2 + (double)e1 / 16 + 17 + 0.999);
                //Check exp2
                if (exp2 > 600) exp2 = 600;
                exp2 = (int)((double)exp2 * 1.15 + 0.999);
                //Check exp2
                if (exp2 > 600) exp2 = 600;
            }

        }
        if (exp2 > 600) exp2 = 600;

        exp1 -= e1;
        if (exp1 < 0) exp1 = 0;


    }



    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function

    //E2 out range
    if (E2 < 0 || E2>99) return -99;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;

    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;

    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;

    //con duong 1
    double P1;
    int S = (abs((int)sqrt(EXP1) * (int)sqrt(EXP1) - EXP1) < abs(((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1) - EXP1)) ? ((int)sqrt(EXP1) * (int)sqrt(EXP1)) : (((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1));

    if (EXP1 >= S) P1 = 1;
    else P1 = (((double)EXP1 / S) + 80) / 123;

    //con duong 2
    if (M1 == 0) {
        HP1 = (int)(0.83 * HP1 + 0.999);
        EXP1 = (int)(1.17 * EXP1 + 0.999);
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }
    else if (E2 % 2 == 1) {
        double halfOfM1 = (double)M1 / 2;
        while (1) {
            //mua thua an va nuoc uong
            if (HP1 < 200) {
                HP1 = (int)(1.3 * HP1 + 0.999);
                M1 -= 150;
            }
            else {
                HP1 = (int)(1.1 * HP1 + 0.999);
                M1 -= 70;
            }

            //Check HP1, M1
            if (HP1 > 666) HP1 = 666;
            if (M1 < 0) M1 = 0;


            // Check M1
            if (M1 < halfOfM1) {
                HP1 = (int)(0.83 * HP1 + 0.999);
                EXP1 = (int)(1.17 * EXP1 + 0.999);
                if (HP1 < 0) HP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                break;
            }

            //thue taxi or xe ngua
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = (int)(1.13 * EXP1 + 0.999);


            //check EXP1, M1
            if (EXP1 > 600) EXP1 = 600;
            if (M1 < 0) M1 = 0;

            // Check M1
            if (M1 < halfOfM1) {
                HP1 = (int)(0.83 * HP1 + 0.999);
                EXP1 = (int)(1.17 * EXP1 + 0.999);
                if (HP1 < 0) HP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                break;
            }

            //gap nguoi vo gia cu
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            EXP1 = (int)(0.9 * EXP1 + 0.999);

            //Check EXP1, M1
            if (EXP1 < 0) EXP1 = 0;
            if (M1 < 0) M1 = 0;

            // Check M1
            if (M1 < halfOfM1) {
                HP1 = (int)(0.83 * HP1 + 0.999);
                EXP1 = (int)(1.17 * EXP1 + 0.999);
                if (HP1 < 0) HP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                break;
            }
        }

    }
    else {
        //mua thua an va nuoc uong
        if (HP1 < 200) {
            HP1 = (int)(1.3 * HP1 + 0.999);
            M1 -= 150;
        }
        else {
            HP1 = (int)(1.1 * HP1 + 0.999);
            M1 -= 70;
        }

        //Check HP1,M1
        if (HP1 > 666) HP1 = 666;
        if (M1 < 0) M1 = 0;

        //Check M1
        if (M1 > 0) {
            //thue taxi or xe ngua
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = (int)(1.13 * EXP1 + 0.999);

            //Check EXP1,M1
            if (EXP1 > 600) EXP1 = 600;
            if (M1 < 0) M1 = 0;

            //M1
            if (M1 > 0) {
                //gap nguoi vo gia cu
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = (int)(0.9 * EXP1 + 0.999);
                //Check EXP1
                if (EXP1 < 0) EXP1 = 0;
            }
            //Check M1  
            if (M1 < 0) M1 = 0;
        }

        //Di toi cuoi duong
        HP1 = (int)(0.83 * HP1 + 0.999);
        EXP1 = (int)(1.17 * EXP1 + 0.999);

        //Check HP1, EXP1
        if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;


    }
    //check M1
    if (M1 < 0) M1 = 0;

    //tinh P2
    double P2;
    int SS = (abs((int)sqrt(EXP1) * (int)sqrt(EXP1) - EXP1) < abs(((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1) - EXP1)) ? ((int)sqrt(EXP1) * (int)sqrt(EXP1)) : (((int)sqrt(EXP1) + 1) * ((int)sqrt(EXP1) + 1));
    if (EXP1 >= SS) P2 = 1;
    else P2 = (((double)EXP1 / SS) + 80) / 123;

    //con duong 3
    int arr[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int P3;
    if (E2 <= 9) P3 = arr[E2];
    else P3 = arr[(E2 % 10 + E2 / 10) % 10];

    //KT sau khi di qua 3 con duong
    if (P1 == 1 && P2 == 1 && P3 == 100) {
        EXP1 = (int)(0.75 * EXP1 + 0.999);

        //Check EXP1
        if (EXP1 < 0) EXP1 = 0;
    }
    else {
        double eP = ((double)P1 + (double)P2 + (double)P3 / 100) / 3;
        if (eP < 0.5) {
            HP1 = (int)(0.85 * HP1 + 0.999);
            EXP1 = (int)(1.15 * EXP1 + 0.999);

            //Check HP1, EXP1
            if (HP1 < 0) HP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
        }
        else {
            HP1 = (int)(0.9 * HP1 + 0.999);
            EXP1 = (int)(1.2 * EXP1 + 0.999);

            //Check HP1, EXP1
            if (HP1 < 0) HP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
        }
    }



    return HP1 + EXP1 + M1;

}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function

    //E3 out range
    if (E3 < 0 || E3>99) return -99;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    int map[10][10];
    int rowMeet = 0, colMeet = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            map[i][j] = ((E3 * j) + (2 * i)) * (i - j);
            if (map[i][j] > E3 * 2) rowMeet++;
            else if (map[i][j] < (0 - E3)) colMeet++;
        }

    //Dieu chinh rowMeet, colMeet
    while (rowMeet >= 10) rowMeet = (rowMeet % 10) + (rowMeet / 10);
    while (colMeet >= 10) colMeet = (colMeet % 10) + (colMeet / 10);

    //Tinh diem cua Sherlock va Watson tai diem gap nhau
    int maxi = map[rowMeet][colMeet], k, h;
    k = rowMeet; h = colMeet;
    while (k >= 0 && h >= 0) maxi = max(maxi, map[k--][h--]);
    k = rowMeet; h = colMeet;
    while (k >= 0 && h < 10) maxi = max(maxi, map[k--][h++]);
    k = rowMeet; h = colMeet;
    while (k < 10 && h >= 0) maxi = max(maxi, map[k++][h--]);
    k = rowMeet; h = colMeet;
    while (k < 10 && h < 10) maxi = max(maxi, map[k++][h++]);

    if (abs(maxi) >= abs(map[rowMeet][colMeet])) {
        EXP1 = (int)(1.12 * EXP1 + 0.999);
        HP1 = (int)(1.1 * HP1 + 0.999);
        EXP2 = (int)(1.12 * EXP2 + 0.999);
        HP2 = (int)(1.1 * HP2 + 0.999);


        //Check
        if (EXP1 > 600) EXP1 = 600;
        if (HP1 > 666) HP1 = 666;
        if (EXP2 > 600) EXP2 = 600;
        if (HP2 > 666) HP2 = 666;

        return maxi;
    }

    else {
        EXP1 = (int)(0.88 * EXP1 + 0.999);
        HP1 = (int)(0.9 * HP1 + 0.99);
        EXP2 = (int)(0.88 * EXP2 + 0.99);
        HP2 = (int)(0.9 * HP2 + 0.99);


        return map[rowMeet][colMeet];

    }



    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function


    string se = "";
    int sizeOfs = 0;
    int UnvalidChar;
    bool checkPreChar = false;
    bool validCharacter = true;
    bool hasASpecialChar = false;
    int idxprechar = 0;

    //tim size cua s 
    sizeOfs = strlen(s);

    //Find se
    for (int i = 0; i < 100; i++) {
        if (email[i] != '@') {
            se += email[i];
        }
        else break;
    }

    for (int i = 0; i < sizeOfs; i++) {

        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' ||
            (s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') hasASpecialChar = true;
            if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2] && checkPreChar == false) {
                checkPreChar = true;
                idxprechar = i - 2;

            }

        }
        else if (validCharacter) {
            validCharacter = false;
            UnvalidChar = i;
        }



    }

    bool isContain_se = false;
    int idx;

    for (int i = 0; i < sizeOfs; i++) {
        if (isContain_se) break;
        if (s[i] == se[0]) {
            if (se.length() == 1) {
                isContain_se = true;
                idx = i;
            }
            for (int j = 1; j < se.length(); j++) {
                if (i + j >= sizeOfs || s[i + j] != se[j]) {
                    break;
                }
                if (j == se.length() - 1) {
                    isContain_se = true;
                    idx = i;
                }

            }
        }
    }


    if (sizeOfs >= 8 && sizeOfs <= 20 && !checkPreChar && validCharacter && hasASpecialChar && !isContain_se) return -10;
    if (sizeOfs < 8) return -1;
    if (sizeOfs > 20) return -2;
    if (isContain_se) return -(300 + idx);
    if (checkPreChar) return -(400 + idxprechar);
    if (!hasASpecialChar) return -5;
    if (!validCharacter) return UnvalidChar;




    return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int maxi = 0, count, anssize = 0, idx = 0;

    for (int i = 0; i < num_pwds; i++) {
        count = 1;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0 && i != j) count++;
        }
        if (maxi < count) {
            maxi = count;
            idx = i;
            anssize = strlen(arr_pwds[i]);

        }
        else if (maxi == count) {
            if (strlen(arr_pwds[i]) > anssize)
            {
                idx = i;
                anssize = strlen(arr_pwds[i]);
            }

        }

    }

    return idx;

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////