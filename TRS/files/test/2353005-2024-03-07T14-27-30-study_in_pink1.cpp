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


void limit_exp(int& exp)
{
    if (exp > 600)
        exp = 600;
    else if (exp < 0)
        exp = 0;
}

void limit_hp(int& HP)
{
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
}
void limit_m(int& M)
{
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    if ((e1 >= 0) && (e1 <= 3))
    {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = (exp1 + (double)D / 200.0) + 0.999999;
            limit_exp(exp1);
        }
        else
        {
            exp1 = (exp1 - (double)D / 100.0) + 0.999990;
            limit_exp(exp1);
        }
        if (e1 == 0)
        {
            exp2 += 29;
            limit_exp(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45;
            limit_exp(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75;
            limit_exp(exp2);
        }
        else if (e1 == 3)
        {
            {
                exp2 = exp2 + 29 + 45 + 75;
                limit_exp(exp2);
            }
        }
    }

    if ((e1 >= 4) && (e1 <= 99))
    {

        if ((e1 >= 4) && (e1 <= 19))

        {
            exp2 += (e1 / 4.0) + 19.0 + 0.99999;
        }
        else if ((e1 >= 20) && (e1 <= 49))
        {

            exp2 += (e1 / 9.0) + 21.0 + 0.999990;
        }
        else if ((e1 >= 50) && (e1 <= 65))
        {

            exp2 += (e1 / 16.0) + 17.0 + 0.999990;
        }
        else if ((e1 >= 66) && (e1 <= 79))
        {

            exp2 += (e1 / 4.0) + 19.0 + 0.999999;
            if (exp2 > 200)
            {
                exp2 += (e1 / 9.0) + 21.0 + 0.999999;
            }
            limit_exp(exp1);
            limit_exp(exp2);
        }

        else if ((e1 >= 80) && (e1 <= 99))
        {

            exp2 += (e1 / 4.0) + 19.0 + 0.999999;
            exp2 += (e1 / 9.0) + 21.0 + 0.99999;
            limit_exp(exp2);
            if (exp2 > 400)
            {
                exp2 = (exp2 + ((e1 / 16.0) + 17.0)) + 0.999999;
                exp2 = (exp2 * 1.15) + 0.999999;
                limit_exp(exp2);
            }
        }
        exp1 = exp1 - e1;
        limit_exp(exp1);
        limit_exp(exp2);
    }
    return exp1 + exp2;
}

int squareNumber(int EXP1)
{
    int low = sqrt(EXP1);
    int high = low + 1;
    int lowcase = EXP1 - (low * low);
    int highcase = (high * high) - EXP1;
    if (lowcase < highcase)
        return low * low;
    else
        return high * high;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int numbers = squareNumber(EXP1);
    if (E2 < 0 || E2 > 99)
        return - 99;
    // Way 1
    float P1;
    if (EXP1 >= numbers) {
        P1 = 1;
    }
    else {
        P1 = ((EXP1 / numbers) + 80.0) / 123.0;
    }

    // Way 2
    int cash = M1 * 0.5;
    int M1after = 0;
    if (E2 % 2 != 0) {
        do
        {
            if (HP1 < 200) {
                HP1 = (HP1 * 13.0 / 10.0) + 0.999;
                M1 -= 150;
                M1after += 150;
                limit_hp(HP1);
                limit_m(M1);
            }
            else {
                HP1 = (HP1 * 11.0 / 10.0) + 0.999;
                M1 -= 70;
                M1after += 70;
                limit_hp(HP1);
                limit_m(M1);
            }
            if (M1after > cash) {
                break;
            }

            if (EXP1 < 400) {
                EXP1 = (EXP1 * 113.0 / 100.0) + 0.999;
                M1 -= 200;
                M1after += 200;
                limit_exp(EXP1);
                limit_m(M1);
            }
            else {
                EXP1 = (EXP1 * 113.0 / 100.0) + 0.999;
                M1 -= 120;
                M1after += 120;
                limit_exp(EXP1);
                limit_m(M1);
            }
            if (M1after > cash) {
                break;
            }

            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = (EXP1 * 90.0/100.0) + 0.999;
                M1after += 100;
                limit_exp(EXP1);
                limit_m(M1);
            }
            else {
                M1 -= 120;
                EXP1 = (EXP1 * 90.0/100.0) + 0.999;
                M1after += 120;
                limit_exp(EXP1);
                limit_m(M1);
            }
            if (M1after > cash) {
                break;
            }
        } while (M1after < cash);

    }
    else {
        while (M1 > M1after) {
            if (HP1 < 200) {
                HP1 = (HP1 * 13.0 / 10.0) + 0.999;
                M1 -= 150;
                M1after += 150;
                limit_hp(HP1);
                limit_m(M1);
            }
            else {
                HP1 = (HP1 * 11.0 / 10.0) + 0.999;
                M1 -= 70;
                M1after += 70;
                limit_hp(HP1);
                limit_m(M1);
            }
            if ((M1 == 0) || (M1 < 0)) {
                M1 = 0;
                break;
            }
            if (EXP1 < 400) {
                EXP1 = (EXP1 * 113.0 / 100.0) + 0.999;
                M1 -= 200;
                M1after += 200;
                limit_exp(EXP1);
                limit_m(M1);
            }
            else {
                EXP1 = (EXP1 * 113.0 / 100.0) + 0.999;
                M1 -= 120;
                M1after += 120;
                limit_exp(EXP1);
                limit_m(M1);
            }
            if ((M1 == 0) || (M1 < 0)) {
                M1 = 0;
                break;
            }
            if (EXP1 < 300) {
                M1 -= 100;
                EXP1 = (EXP1 * 90.0/100.0) + 0.999;
                limit_exp(EXP1);
                limit_m(M1);
            }
            else {
                M1 -= 120;
                EXP1 = (EXP1 * 90.0/100.0) + 0.999;
                M1after += 120;
                limit_exp(EXP1);
                limit_m(M1);
            }
            if ((M1 == 0) || (M1 < 0)) {
                M1 = 0;
                break;
            }
            if (M1 > 0) {
                break;
            }
        }
    }
    EXP1 = (EXP1 * 117.0/100.0) + 0.999;
    HP1 = (HP1 * 83.0/100.0) + 0.999;
    limit_exp(EXP1);
    limit_hp(HP1);

    double P2;
    numbers = squareNumber(EXP1);
    if (EXP1 >= numbers) {
        P2 = 1;
    }
    else {
        P2 = ((EXP1 / numbers) + 80.0) / 123.0;
    }

    //Way 3
    int number[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    double P3;
    if (E2 < 10) {
        i = E2;
    }
    else if ((E2 >= 10) && (E2 <= 99)) {
        int s1 = E2 / 10;
        int s2 = E2 % 10;
        i = s1 + s2;
        if (i < 10) {
            i = i + 0;
        }
        else {
            i = i % 10;
        }
    }
    P3 = number[i];
    P3 /= 100.0;

    if ((P1 == 1) && (P2 == 1) && (P3 == 1)) {
        EXP1 = ceil(EXP1 * 75.0/100.0) ;
        limit_exp(EXP1);
    }
    else {
        double Ptb = (P1 + P2 + P3) / 3.0;
        if (Ptb < 0.5) {
            HP1 = ceil(HP1 * 85.0/100.0) ;
            EXP1 = ceil(EXP1 * 115.0/100.0) ;
            limit_exp(EXP1);
            limit_hp(HP1);
        }
        else {
            HP1 = ceil(HP1 * 90.0/100.0) ;
            EXP1 = ceil(EXP1 * 12.0/10.0) ;
            limit_exp(EXP1);
            limit_hp(HP1);
        }
    }


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    int a = 0, b = 0;
    int i = 0, j = 0;
    int matrix[10][10];
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            matrix[a][b] = ((E3 * b) + (a * 2)) * (a - b);
        }
    }
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            if (matrix[a][b] > (E3 * 2)) {
                i += 1;
            }
            else if (matrix[a][b] < (-E3)) {
                j += 1;
            }
        }
    }
    if ((i > 10) && (i < 99)) {
        do {
            int s1 = i / 10;
            int s2 = i % 10;
            i = s1 + s2;
        } while (i >= 10);
    }
    if ((j > 10) && (j < 99)) {
        do {
            int s3 = j / 10;
            int s4 = j % 10;
            j = s3 + s4;
        } while (j >= 10);
    }
    int max1, max2, max3, max4;
    max1 = max2 = max3 = max4 = matrix[i][j];
    int x, y, z, t, g, h, c, d;
    x = z = g = c = i;
    y = t = h = d = j;
    while ((x >= 0) && (x <= 9) && (y >= 0) && (y <= 9))
    {

        if (matrix[x][y] >= max1) {
            max1 = matrix[x][y];
        }
        x--;
        y--;
    }
    while ((z >= 0) && (z <= 9) && (t >= 0) && (t <= 9))
    {

        if (matrix[z][t] >= max2) {
            max2 = matrix[z][t];
        }
        z++;
        t--;
    }
    while ((g >= 0) && (g <= 9) && (h >= 0) && (h <= 9))
    {

        if (matrix[g][h] >= max3) {
            max3 = matrix[g][h];
        }
        g--;
        h++;
    }
    while ((c >= 0) && (c <= 9) && (d >= 0) && (d <= 9))
    {

        if (matrix[c][d] >= max4) {
            max4 = matrix[c][d];
        }
        c++;
        d++;
    }
    int maxtaxi;
    int maxSW;
    int maxsw;
    maxsw = max(max(max1, max2), max(max3, max4));

    if (maxsw < 0) {
        maxSW = abs(maxsw);
    }
    else {
        maxSW = maxsw;
    }
    if (matrix[i][j] <= 0) {
        maxtaxi = abs(matrix[i][j]);
    }
    else {
        maxtaxi = matrix[i][j];
    }
    if (maxSW >= maxtaxi) {
        EXP1 = ceil(EXP1 * 112.0 / 100.0);
        EXP2 = ceil(EXP2 * 112.0 / 100.0);
        HP1 = ceil(HP1 * 11.0 / 10.0);
        HP2 = ceil(HP2 * 11.0 / 10.0);
        limit_exp(EXP1);
        limit_exp(EXP2);
        limit_hp(HP1);
        limit_hp(HP2);
        return maxsw;
    }
    else {
        EXP1 = ceil(EXP1 * 0.88);
        EXP2 = ceil(EXP2 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        HP2 = ceil(HP2 * 0.9);
        limit_exp(EXP1);
        limit_exp(EXP2);
        limit_hp(HP1);
        limit_hp(HP2);
        return matrix[i][j];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
   
    string s1 = email;
    string s2 = s;
    string se;
    int slength = s2.length();
    int emaillength = s1.length();
    se = s1.erase(s1.find("@"));

    if (slength < 8)
        return -1;
    if (slength > 20)
        return -2;

    if (s2.find(se) != string::npos) {
        int sei = s2.find(se);
        return -(300 + sei);
    }
    for (int i = 0; i < slength; i++) {
        if ((s[i] == s[i + 1]) && (s[i] == s[i + 2])) {
            return -(400 + i);
        }
    }
    char findspec[] = "@#%$!";
    bool existspec = false;
    for (int i = 0; i < slength; i++) {
        for (int j = 0; j < strlen(findspec); j++) {
            if (s[i] == findspec[j])
                existspec = true;
        }
    }
    if (!existspec) {
        return -5;
    }
    for (int i = 0; i < slength; i++) {
        if (!(( s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == 33 || (s[i] >= 35 && s[i] <= 37) || s[i] == 64 )) {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
       
    int appearance[num_pwds] = {};
    int demso = 0;
    int mostapp = appearance[0];
    int position = 0;
    int i;

    for (int a = 0; a < num_pwds; a++) {
        for (int b = 0; b < num_pwds; b++) {
            if ( strcmp(arr_pwds[a],arr_pwds[b]) == 0) {
                demso++;
            }
        }
        appearance[a] = demso;
        demso = 0;
    }
    
    for (int a = 0; a < num_pwds; a++) {
        if (appearance[a] > mostapp) {
            mostapp = appearance[a];
        }
    }

    int pwds_length[num_pwds] = {};
    int longest = pwds_length[0];

    for (int a = 0; a < num_pwds; a++) {
        if (appearance[a] == mostapp) {
            pwds_length[a] = strlen(arr_pwds[a]);
        }
    
        if (pwds_length[a] > longest) {
            longest = pwds_length[a];
            position = a;
        }
    }
    
    for (i = 0; i < num_pwds; i++) {
        if ( strcmp(arr_pwds[i],arr_pwds[position]) == 0)  {
            break;
        }
    }
    return i;
}

 

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////