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
int reEXP(int& exp)
{
    if (exp < 0)
    {
        exp = 0;
    }
    else if (exp > 600)
    {
        exp = 600;
    }
    return exp;
}
int reHP(int& hp)
{
    if (hp < 0)
    {
        hp = 0;
    }
    else if (hp > 666)
    {
        hp = 666;
    }
    return hp;
}
int reM(int& m)
{
    if (m < 0)
    {
        m = 0;
    }
    else if (m > 3000)
    {
        m = 3000;
    }
    return m;
}
int SoChinhPhuong(int value){
    float upper = pow(ceil(sqrt(value)),2);
    float lower = pow(floor(sqrt(value)),2);
    if ( abs(value - lower) < abs(value - upper) ) return lower;
    else return upper;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int d;
    if (e1 < 0 || e1>99) {return -99;}
    else {if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
        {
            exp2 = exp2 + 29;
            break;
        }
        case 1:
        {
            exp2 = exp2 + 45;
            break;
        }
        case 2:
        {
            exp2 = exp2 + 75;
            break;
        }
        case 3:
        {
            exp2 = exp2 + 149;
            break;
        }
        }
        d = e1 * 3 + exp1 * 7;
        if (d % 2 == 0) {
            exp1 = ceil(exp1 + (1.00 * d / 200.00));
        }
        else {
            exp1 = ceil(exp1 - (1.00 * d / 100.00));
        }
        reEXP(exp1);
        reEXP(exp2);
        
    }
    else if (e1 >= 4 && e1 <= 99)
    {
        if (e1 <= 19)
        {
            exp2 = exp2 + ceil(1.00 * e1 / 4) + 19;
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = exp2 + ceil(1.00 * e1 / 9) + 21;
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = exp2 + ceil(1.00 * e1 / 16) + 17;
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = exp2 + ceil(1.00 * e1 / 4) + 19;
            if (exp2 > 200)
            {
                exp2 = exp2 + ceil(1.00 * e1 / 9) + 21;
            }
        }
        else if (e1 >= 80)
        {
            exp2 = exp2 + ceil(1.00 * e1 / 4) + 19;
            exp2 = exp2 + ceil(1.00 * e1 / 9) + 21;
            if (exp2 > 400) {
                exp2 = exp2 + ceil(1.00 * e1 / 16) + 17;
                exp2 = ceil(1.00 * exp2 * 1.15);
            }
        }
        exp1 = exp1 - e1;
        reEXP(exp1);
        reEXP(exp2);
       
    }
    return exp1 + exp2;
}
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double p1, p2, p3, avg;
    int a, b;
    int MF = ceil(1.00 * M1 / 2), MP = 0;
    int k;
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };

    reEXP(EXP1);
    reHP(HP1);
    reM(M1);

    if (E2 < 0 || E2 > 99) {
        return -99;
    } else {
        a = SoChinhPhuong(EXP1);

        if (EXP1 >= a) {
            p1 = 1.0;
        } else {
            p1 = (1.0 * EXP1 / a + 80) / 123;
        }

        if (M1 == 0) {
            HP1 = ceil(0.83 * HP1);
            EXP1 = ceil(1.13 * EXP1);
            reHP(HP1);
            reEXP(EXP1);
        } else {
            if (E2 % 2 == 0) {
                while (MP <= MF) {
                    if (HP1 < 200) {
                        HP1 += ceil(0.3 * HP1);
                        M1 -= 150;
                    } else {
                        HP1 += ceil(0.1 * HP1);
                        M1 -= 70;
                    }
                    reHP(HP1);
                    reM(M1);

                    if (M1 > 0) {
                        if (EXP1 < 400) {
                            M1 -= 200;
                        } else {
                            M1 -= 120;
                        }
                        EXP1 += ceil(0.13 * EXP1);
                        reM(M1);
                        reEXP(EXP1);
                    }

                    if (M1 > 0) {
                        if (EXP1 < 300) {
                            M1 -= 100;
                        }
                        if (EXP1 >= 300) {
                            M1 -= 120;
                        }
                        EXP1 = ceil(0.9 * EXP1);
                        reM(M1);
                        reEXP(EXP1);
                    }

                    HP1 = ceil(0.83 * HP1);
                    EXP1 = ceil(1.13 * EXP1);
                    reHP(HP1);
                    reEXP(EXP1);
                }
            } else {
                while (MP <= MF) {
                    if (HP1 < 200) {
                        HP1 += ceil(0.3 * HP1);
                        M1 -= 150;
                        MP += 150;
                    } else {
                        HP1 += ceil(0.1 * HP1);
                        M1 -= 70;
                        MP += 70;
                    }
                    reM(M1);
                    reHP(HP1);

                    if (MP > MF) {
                        break;
                    }

                    if (EXP1 < 400) {
                        M1 -= 200;
                        MP += 200;
                    } else {
                        M1 -= 120;
                        MP += 120;
                    }
                    EXP1 += ceil(0.13 * EXP1);
                    reM(M1);
                    reEXP(EXP1);

                    if (MP > MF) {
                        break;
                    }

                    if (EXP1 < 300) {
                        M1 -= 100;
                        MP += 100;
                        EXP1 = ceil(0.9 * EXP1);
                        reM(M1);
                        reEXP(EXP1);
                    } else {
                        M1 -= 120;
                        MP += 120;
                        EXP1 = ceil(0.9 * EXP1);
                        reM(M1);
                        reEXP(EXP1);
                    }
                }
                HP1 = ceil(0.83 * HP1);
                EXP1 = ceil(1.17 * EXP1);
                reHP(HP1);
                reEXP(EXP1);
            }
        }

        b = SoChinhPhuong(EXP1);

        if (EXP1 >= b) {
            p2 = 1.0;
        } else {
            p2 = (1.0 * EXP1 / b + 80) / 123;
        }

        if (E2 < 10) {
            k = E2;
        } else {
            while (E2 >= 10) {
                int sum = 0;
                while (E2 > 0) {
                    sum += E2 % 10;
                    E2 /= 10;
                }
                E2 = sum;
                k = E2;
            }
        }

        p3 = P[k] / 100.0;
        avg = (p1 + p2 + p3) / 3;

        if (p1 == 1.0 && p2 == 1.0 && p3 == 1.0) {
            EXP1 = ceil(EXP1 * 0.75);
        } else if (avg < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        } else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }

        reHP(HP1);
        reEXP(EXP1);
        reM(M1);

        return HP1 + EXP1 + M1;
    }
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
        // TODO: Complete this function
    int M[10][10];
    int a = 0, b = 0;
    int taxiP = 0;
    int r;
    int sherlockP = 0, sherlockP1 = 0, sherlockP2 = 0;
    reHP(HP1);
    reHP(HP2);
    reEXP(EXP1);
    reEXP(EXP2);
    if (E3 < 0 || E3>99) return -99;
    else {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                M[i][j] = 0;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                M[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (M[i][j] > 0 && M[i][j] > E3 * 2) {
                    a++;
                }

                if (M[i][j] < 0 && M[i][j] < (-E3)) {
                    b++;
                }
            }
        }
        while (a >= 10) {
            int sum = 0;
            while (a > 0) {
                sum += a % 10;
                a /= 10;
            }
            a = sum;
        }
        while (b >= 10) {
            int sum = 0;
            while (b > 0) {
                sum += b % 10;
                b /= 10;
            }
            b = sum;
        }
        taxiP = M[a][b];
        int startRowLeft = max(0, a - b);
        int startColLeft = max(0, b - a);
        int endRowLeft = min(9, a + 9 - b);
        int endColLeft = min(9, b + 9 - a);
        for (int i = startRowLeft; i <= endRowLeft; i++) {
            for (int j = startColLeft; j <= endColLeft; j++) {
                if ((i == startRowLeft && j == startColLeft) || (i == startRowLeft + 1 && j == startColLeft + 1) || (i == endRowLeft && j == endColLeft))
                {
                    sherlockP1 = max(sherlockP1, M[i][j]);
                    startRowLeft++;
                    startColLeft++;
                }
            }
        }
        int startRowRight = max(0, a + b - 9);
        int startColRight = min(9, a + b);
        int endRowRight = min(9, a + b);
        int endColRight = max(0, a + b - 9);
        for (int i = startRowRight; i <= endRowRight; i++) {
            for (int j = startColRight; j >= endColRight; j--) {
                if ((i == startRowRight && j == startColRight) || (i == startRowRight + 1 && j == startColRight - 1) || (i == endRowRight && j == endColRight))
                {
                    sherlockP2 = max(sherlockP2, M[i][j]);
                    startRowRight++;
                    startColRight--;
                }
            }
        }
        sherlockP = max(sherlockP1, sherlockP2);
        if (abs(taxiP) > sherlockP) {
            EXP1 = ceil(EXP1 * 0.88);
            EXP2 = ceil(EXP2 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            HP2 = ceil(HP2 * 0.9);
            reEXP(EXP1);
            reEXP(EXP2);
            reHP(HP1);
            reHP(HP2);
            r = taxiP;
        }
        else if (abs(taxiP) < sherlockP) {
            EXP1 = ceil(EXP1 * 1.12);
            EXP2 = ceil(EXP2 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            HP2 = ceil(HP2 * 1.1);
            reEXP(EXP1);
            reEXP(EXP2);
            reHP(HP1);
            reHP(HP2);
            r = sherlockP;
        }
        return r;
    }
}

// Task 4
int checkPassword(const char *s, const char *email) {

    const char *position = strchr(email, '@');
    char se[100];
    int seLength = position - email;
    strncpy(se, email, seLength);
    se[seLength] = '\0';
    int sLength = strlen(s);
    if (sLength < 8) {
        return -1;
    } else if (sLength > 20) {
        return -2;
    }
    const char *sePosition = strstr(s, se);
    if (sePosition) {
        return -(300 + (sePosition - s));
    }
    for (int i = 0; i < sLength - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }
    for (int i = 0; i < sLength; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            return -10;
        }
    }
    return -5;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int correctPassIndex = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char* currentPass = arr_pwds[i];
        int count = 1;  
        int length = strlen(currentPass);
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(currentPass, arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            correctPassIndex = i;
        }
    }
     return correctPassIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////