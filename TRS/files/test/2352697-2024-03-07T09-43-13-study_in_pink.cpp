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
int checkEXP1(int& EXP1) {
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    return EXP1;
}
int checkEXP2(int& EXP2) {
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    return EXP2;
}
int checkhp1(int& HP1) {
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    return HP1;
}
int checkhp2(int& HP2) {
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
    return HP2;
}
int checkmoney1(int& M1) {
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    return M1;
}
int checkmoney2(int& M2) {
    if (M2 > 3000) M2 = 3000;
    if (M2 < 0) M2 = 0;
    return M2;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    //case1
    checkEXP1(EXP1);
    checkEXP2(EXP2);
    int D = 0;
    if (E1 <= 0 || E1 >= 99) {
        return -99;
    }
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else if (E1 == 3) EXP2 = EXP2 + 29 + 45 + 75;
        checkEXP2(EXP2);
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) EXP1 += ceil((double)D / 200);
        else EXP1 -= D / 100;
        checkEXP1(EXP1);
    }
    //case2
    if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil((double)E1 / 4 + 19);
        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil((double)E1 / 9 + 21);
        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil((double)E1 / 16 + 17);
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil((double)E1 / 4 + 19);
            if (EXP2 > 200) {
                EXP2 += ceil((double)E1 / 9 + 21);
            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil((double)E1 / 4 + 19);
            EXP2 += ceil((double)E1 / 9 + 21);
            if (EXP2 > 400) {
                EXP2 += ceil((double)E1 / 16 + 17);
                //ca 3 truong hop, + exp2
                EXP2 += ceil((double)EXP2 * (15 / 100));
            }
            

        }
        //5 truog hop, Sherlock tru exp
        EXP1 -= E1;
        checkEXP1(EXP1);
        checkEXP2(EXP2);
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    //road 01
    /*float S = 0;
    float P1 = 0;
    S = sqrt(EXP1);
    S = round(S);
    S = pow(S, 2);
    if (EXP1 >= S) P1 = 100;
    else P1 = (EXP1 / S + 80) / 123;
    return HP1 + EXP1 + M1;
    //road 02
    //water
    int M0;
    M0 = M1;
    if (E2 % 2 != 0) {
        while (M1 <= 0.5 * M0) do {
            if (HP1 < 200) {
                HP1 += HP1 * (30 / 100);
                HP1 = ceil(HP1);
                M1 -= 150;
            }
            else {
                HP1 += HP1 * (10 / 100);
                HP1 = ceil(HP1);
                M1 -= 70;
            }
            checkhp1(HP1);
            checkmoney1(M1);
            //taxi
            if (EXP1 < 400) M1 -= 120;
            else M1 -= 200;
            EXP1 += EXP1 * (13 / 100);
            checkEXP1(EXP1);
            checkmoney1(M1);
            //homelessperson
            if (EXP1 < 300) M1 -= 100;
            else M1 -= 200;
            EXP1 -= EXP1 * (10 / 100);
            EXP1 = ceil(EXP1);
            checkEXP1(EXP1);
        }*/
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////