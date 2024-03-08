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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    int KC1 = (e1 + 3) / 4 + 19 ,
    KC2 = (e1 + 8) / 9 + 21,
    KC3 = (e1 + 15) / 16 + 17;

    if (e1 < 4){
        int E[3] = {29 , 45 , 75};

        if (e1 == 3){
            exp2 += E[0] + E[1] + E[2];
        } else exp2 += E[e1];

        int D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) exp1 += (D + 199) / 200;
        else exp1 -= (D - 1) / 100;

    }
    else if (e1 < 20)
        exp2 += KC1;
    else if (e1 < 50)
        exp2 += KC2;
    else if (e1 < 66)
        exp2 += KC3;
    else if (e1 < 80){
        exp2 += KC1;
        if (exp2 > 200) exp2 += KC2;
    } else if (e1 < 100){
        exp2 += KC1 + KC2 ;
        if (exp2 > 400) exp2 = min (600 , exp2 + KC3) , exp2 = (exp2 * 23 + 19) / 20;
    }
    if (e1 > 3) exp1 -= e1;

    exp1 = min(600 , max(exp1 , 0));
    exp2 = min(600 , max(exp2 , 0));

    return exp1 + exp2;
}

//Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    double P1 = 0 , P2 = 0 , P3 = 0;
    for (int i = 1 , vtr = 0; i < 26 ; i++){
        if (abs(EXP1 - i * i) < EXP1 - vtr) vtr = i * i;

        if (i == 25){
            if (vtr <= EXP1) P1 = 100;
            else  P1 = ((double)EXP1 / vtr + 80) / 123 * 100;
        }
    }

    int Coins = 0 , Check = M1 / 2;

    while (true){
        if (HP1 < 200){
            Coins += 150;
            HP1 = min(666 , (HP1 * 13 + 9) / 10);
        } else {
            Coins += 70;
            HP1 = min(666 , (HP1 * 11 + 9) / 10);
        }

        if (E2 % 2 == 1 && Coins > Check) break;
        if (E2 % 2 == 0 && Coins >= M1) break;

        if (EXP1 < 400){
            Coins += 200;
        } else Coins += 120;
        EXP1 = min(600 , (EXP1 * 113 + 99) / 100);
        if (E2 % 2 == 1 && Coins > Check) break;
        if (E2 % 2 == 0 && Coins >= M1) break;

        if (EXP1 < 300){
            Coins += 100;
        } else Coins += 120;
        EXP1 = max(0 , (EXP1 * 9 + 9) / 10);
        if (E2 % 2 == 1 && Coins > Check) break;
        if (E2 % 2 == 0) break;
    }
    //cout << EXP1 << '\n';
    HP1 = max(0 , (HP1 * 83 + 99) / 100) , EXP1 = min(600 , (EXP1 * 117 + 99) / 100) , M1 = max(0 , M1 - Coins);

    //cout << EXP1 << '\n';
    for (int i = 1 , vtr = 0; i < 26 ; i++){
        if (abs(EXP1 - i * i) < EXP1 - vtr) vtr = i * i;

        if (i == 25){
            if (vtr <= EXP1) P2 = 100;
            else if (!EXP1) P2 = (double)(80) / 123 * 100;
            else  P2 = ((double)EXP1 / vtr + 80) / 123 * 100;
        }
    }

    double Val[10] = {32 , 47 , 28 , 79 , 100, 50, 22, 83 , 64 , 11};
    int D = E2 / 10 + E2 % 10;
    //cout << E2 / 10 << ' ' << E2 % 10 << '\n';
    P3 = Val[D % 10];

    //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';
    //cout << fixed << setprecision(2) << P1 << ' ' << P2 << ' ' << P3 << '\n';
    int TBC = (P1 + P2 + P3 + 2) / 3;

    //TBC = 50;

    if (TBC == 100) EXP1 = max(0 , (EXP1 * 3 + 3) / 4);
    else if (TBC < 50) HP1 = max(0 , (HP1 * 17 + 19) / 20) , EXP1 = min(600 , (EXP1 * 23 + 19) / 20);
    else HP1 = max(0 , (HP1 * 9 + 9) / 10) , EXP1 = min(600 , (EXP1 * 6 + 4) / 5);

    //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;

    int u = 0, v = 0;
    int Matrix[10][10] , n = 10;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++){
            Matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);

            if (Matrix[i][j] > E3 * 2) u++;
            if (Matrix[i][j] < -E3) v++;
        }
    /*for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++)
            cout << Matrix[i][j] << ' ';
        cout << '\n';
    }*/

    while (u > 9){
        u = u / 10 + u % 10;
    }
    while (v > 9){
        v = v / 10 + v % 10;
    }



    int X[4] = {1 , 1 , -1 , -1};
    int Y[4] = {-1 , 1 , -1 , 1};

    int Max = Matrix[u][v];

    for (int i = 0 ; i < 4 ; i++){
        int l = u + X[i] , r = v + Y[i];
        while (l >= 0 && l < n && r < n && r >= 0){
            Max = max(Max , Matrix[l][r]);
            l += X[i] , r += Y[i];
        }
    }
    Max = abs(Max);
    //cout << Max << ' ' << abs(Matrix[u][v]) << '\n';

    if (abs(Matrix[u][v]) <= Max){
        EXP1 = min(600 , (EXP1 * 112 + 99) / 100);
        EXP2 = min(600 , (EXP2 * 112 + 99) / 100);
        HP1 = min(666 , (HP1 * 11 + 9) / 10);
        HP2 = min(666 , (HP2 * 11 + 9) / 10);
        cout << HP1 << ' ' << EXP1 << ' ' << HP2 << ' ' << EXP2 << '\n';
        return Max;
    } else
    {
        EXP1 = max(0 , (EXP1 * 88 + 99) / 100);
        EXP2 = max(0 , (EXP2 * 88 + 99) / 100);
        HP1 = max(0 , (HP1 * 9 + 9) / 10);
        HP2 = max(0 , (HP2 * 9 + 9) / 10);
        //cout << HP1 << ' ' << EXP1 << ' ' << HP2 << ' ' << EXP2 << '\n';
        return Matrix[u][v];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string Email = "";
    for (int i = 0 ; email[i] != '@' ; i++)
        Email = Email + email[i];

    if (strlen(s) < 8){
        return -1;
    }

    if (strlen(s) > 20){
        return -2;
    }

    string Check = "";
    for (int i = 0 ; i < min(Email.size() , strlen(s)) ; i++)
        Check = Check + s[i];

    if (Check == Email) return -(300);

    for (int i = Email.size() ; i < strlen(s) ; i++){
        Check.erase(0 , 1);
        Check = Check + s[i];
        if (Check == Email) return -(300 + i - Email.size() + 1);
    }

    for (int i = 0 ; i < strlen(s) - 2 ; i ++){
        if (s[i] == s[i + 1] && s[i] == s[i + 2]){
            return -(400 + i);
        }
    }

    bool ktr = false; int Haha = 1000000;
    for (int i = 0 ; i < strlen(s) - 1 ; i++){
        if (s[i] == 33 || s[i] == 64 || (34 < s[i] && s[i] < 38))
            ktr = true;
        else if ( ('0' > s[i] || s[i] > '9') && ('a' > s[i] || s[i] > 'z') && ('A' > s[i] || s[i] > 'Z')) Haha = min(Haha , i);

    }
    {
        int i = strlen(s) - 1;
        if (s[i] == 33 || s[i] == 64 || (34 < s[i] && s[i] < 38))
            ktr = true;
        else if ( ('0' > s[i] || s[i] > '9') && ('a' > s[i] || s[i] > 'z') && ('A' > s[i] || s[i] > 'Z')) Haha = min(Haha , i);
    }
    if (!ktr) return -5;

    if (Haha != 1000000) return Haha;

    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {

    int ID = 0 , sl = 0;

    for (int i = 0 ; i < num_pwds ; i++){
        int tmp = 1;
        for (int j = i + 1 ; j < num_pwds ; j++)
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) tmp++;

        if (sl < tmp) sl = tmp , ID = i;
        else if (sl == tmp && strlen(arr_pwds[ID]) < strlen(arr_pwds[i])) ID = i;
    }
    return ID;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
