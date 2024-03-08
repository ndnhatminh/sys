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
int firstMeet(int& EXP1, int& EXP2, int E1)
{
    if (E1 < 0 || E1>99) {
        return -99;
    }
    else {






        if (EXP2 > 600) { EXP2 = 600; }
        else if (EXP2 < 0) { EXP2 = 0; }
        if (EXP1 > 600) { EXP1 = 600; }
        else if (EXP1 < 0) { EXP1 = 0; }

        switch (E1) {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 29 + 45 + 75;
            break;

        }

        if (E1 >= 0 && E1 <= 3) {
            int D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0) {
                EXP1 = ceilf(EXP1 + (D / 200.0));
            }
            else {
                EXP1 = ceilf(EXP1 - (D / 100.0));
            }
        }
        if (E1 >= 4) {
            EXP1 -= E1; // Giảm EXP1 dựa trên E1
        }

        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(E1 / 4.0 + 19);

        }
        else if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil(E1 / 9.0 + 21);

        }
        else if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(E1 / 16.0 + 17);

        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceil(E1 / 4.0 + 19);

            if (EXP2 > 200) {
                EXP2 += ceil(E1 / 9.0 + 21);

            }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += ceil(E1 / 4.0 + 19);

            EXP2 += ceil(E1 / 9.0 + 21);

            if (EXP2 > 400) {
                EXP2 += ceil(E1 / 16.0 + 17);

            }
        }

        if (E1 >= 80 && E1 <= 99 && EXP2 > 400) {
            EXP2 = ceil((1.15 * EXP2) * 1.0);
        }

        if (EXP1 > 600) EXP1 = 600; else if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600; else if (EXP2 < 0) EXP2 = 0;
        return EXP1 + EXP2;
    }
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2>99) {
        return -99;
    }
    else {
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;

        double s, S, P1;
        s = sqrt(EXP1);
        if (s - floor(s) >= 0.5) {
            s = floor(s) + 1;
        }
        else {
            s = floor(s);
        }
        S = s * s;
        if (EXP1 >= S) {
            P1 = 100;
        }
        else {
            P1 = ((EXP1 / S) + 80) / 123.0;
            P1 = P1 * 100;
        }


        float t;
        t = M1;


        if (E2 % 2 != 0) {
            if (M1 > 0) {
                while (true) {
                    if (HP1 < 200) {
                        HP1 = ceilf(1.3 * HP1);
                        M1 -= 150;
                    }
                    else {
                        HP1 = ceilf(1.1 * HP1);
                        M1 -= 70;
                    }


                    if (t - M1 > t / 2.0) break;
                    if (HP1 > 666) HP1 = 666;
                    else if (HP1 < 0) HP1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    else if (M1 < 0) M1 = 0;


                    if (EXP1 > 600) EXP1 = 600;
                    else if (EXP1 < 0) EXP1 = 0;
                    if (EXP1 < 400) {
                        M1 -= 200;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 = ceilf(1.13 * EXP1);


                    if (t - M1 > t / 2.0) break;
                    if (HP1 > 666) HP1 = 666;
                    else if (HP1 < 0) HP1 = 0;
                    if (M1 > 3000) M1 = 3000;
                    else if (M1 < 0) M1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                    else if (EXP1 < 0) EXP1 = 0;


                    if (EXP1 < 300) {
                        M1 -= 100;
                    }
                    else {
                        M1 -= 120;
                    }
                    EXP1 = ceilf(0.9 * EXP1);


                    if ((t - M1) > t / 2.0) break;
                }
                if (HP1 > 666) HP1 = 666;
                else if (HP1 < 0) HP1 = 0;
                if (M1 > 3000) M1 = 3000;
                else if (M1 < 0) M1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                else if (EXP1 < 0) EXP1 = 0;
            }
            HP1 = ceilf(HP1 * 0.83);
            EXP1 = ceilf(EXP1 * 1.17);
        }
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (E2 % 2 == 0) {
            if (M1 > 0) {
                if (HP1 < 200) {
                    HP1 = ceilf(1.3 * HP1);
                    M1 -= 150;
                }
                else {
                    HP1 = ceilf(1.1 * HP1);
                    M1 -= 70;
                }
            }
            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            else if (EXP1 < 0) EXP1 = 0;
            if (M1 > 0) {
                if (EXP1 < 400) {
                    M1 -= 200;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = ceilf(1.13 * EXP1);
            }
            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            else if (EXP1 < 0) EXP1 = 0;
            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1 -= 100;
                }
                else {
                    M1 -= 120;
                }
                EXP1 = ceilf(0.9 * EXP1);
            }
            if (HP1 > 666) HP1 = 666;
            else if (HP1 < 0) HP1 = 0;
            if (M1 > 3000) M1 = 3000;
            else if (M1 < 0) M1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            else if (EXP1 < 0) EXP1 = 0;
            HP1 = ceilf(HP1 * 0.83);
            EXP1 = ceilf(EXP1 * 1.17);
        }
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        double v, V, P2;
        v = sqrt(EXP1);
        if (v - floor(v) >= 0.5) {
            v = floor(v) + 1;
        }
        else {
            v = floor(v);
        }
        V = v * v;
        if (EXP1 >= V) {
            P2 = 100;
        }
        else {
            P2 = ((EXP1 / V) + 80) / 123.0;
            P2 = P2 * 100;
        }


        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };


        int i;
        if (E2 < 10) {
            i = E2;
        }
        else {
            i = (E2 / 10 + E2 % 10) % 10;
        }
        if (P[i] == 100 && P1 == 100 && P2 == 100) {
            EXP1 = ceilf(EXP1 * 0.75);
        }
        else {
            if (((P[i] + P1 + P2) / 3) < 50) {
                EXP1 = ceilf(EXP1 * 1.15);
                HP1 = ceilf(HP1 * 0.85);
            }
            else {
                EXP1 = ceilf(EXP1 * 1.2);
                HP1 = ceilf(HP1 * 0.9);
            }
        }
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        return HP1 + EXP1 + M1;
    }
}



// Task 3

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    if (E3 < 0 || E3>99) {
        return -99;
    }
    else {
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;
        int map[10][10];
        int swMap[10][10] = { 0 };
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }


        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {

                int leftMax = map[i][j];
                int rightMax = map[i][j];

                for (int k = 1; k < 10; ++k) {
                    int di = i - k, dj = j - k;
                    if (di < 0 || dj < 0) break;
                    leftMax = max(leftMax, map[di][dj]);
                }

                for (int k = 1; k < 10; ++k) {
                    int di = i + k, dj = j + k;
                    if (di >= 10 || dj >= 10) break;
                    leftMax = max(leftMax, map[di][dj]);
                }

                for (int k = 1; k < 10; ++k) {
                    int di = i - k, dj = j + k;
                    if (di < 0 || dj >= 10) break;
                    rightMax = max(rightMax, map[di][dj]);
                }

                for (int k = 1; k < 10; ++k) {
                    int di = i + k, dj = j - k;
                    if (di >= 10 || dj < 0) break;
                    rightMax = max(rightMax, map[di][dj]);
                }
                swMap[i][j] = max(leftMax, rightMax);
            }
        }
        int countGreaterThanE3Times2 = 0, countLessThanMinusE3 = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (map[i][j] > E3 * 2) countGreaterThanE3Times2++;
                if (map[i][j] < -E3) countLessThanMinusE3++;
            }
        }


        int i_meet = 0, j_meet = 0;


        while (countGreaterThanE3Times2 > 0) {
            i_meet += countGreaterThanE3Times2 % 10;
            countGreaterThanE3Times2 /= 10;
        }
        while (i_meet > 9) {
            int temp = 0;
            while (i_meet > 0) {
                temp += i_meet % 10;
                i_meet /= 10;
            }
            i_meet = temp;
        }


        while (countLessThanMinusE3 > 0) {
            j_meet += countLessThanMinusE3 % 10;
            countLessThanMinusE3 /= 10;
        }
        while (j_meet > 9) {
            int temp = 0;
            while (j_meet > 0) {
                temp += j_meet % 10;
                j_meet /= 10;
            }
            j_meet = temp;
        }
        int meetScoreTaxi = map[i_meet][j_meet];
        int meetScoreSW = swMap[i_meet][j_meet];


        bool caughtUp = abs(meetScoreSW) >= abs(meetScoreTaxi);


        if (caughtUp) {

            HP1 = ceilf(1.1 * HP1);
            EXP1 = ceilf(1.12 * EXP1);
            HP2 = ceilf(1.1 * HP2);
            EXP2 = ceilf(1.12 * EXP2);
        }
        else {

            HP1 = ceilf(0.9 * HP1);
            EXP1 = ceilf(0.88 * EXP1);
            HP2 = ceilf(0.9 * HP2);
            EXP2 = ceilf(0.88 * EXP2);
        }
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (HP2 > 666) HP2 = 666;
        else if (HP2 < 0) HP2 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (EXP2 > 600) EXP2 = 600;
        else if (EXP2 < 0) EXP2 = 0;

        return (abs(meetScoreTaxi) > abs(meetScoreSW)) ? meetScoreTaxi : meetScoreSW;
    }
}

// Task 4
int checkPassword(const char* s, const char* email) {

    const char* atPos = strchr(email, '@');
    int seLength = atPos - email;
    char se[101];
    strncpy(se, email, seLength);
    se[seLength] = '\0';

    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;
    const char* foundSe = strstr(s, se);
    if (foundSe != nullptr) {
        return -(300 + (foundSe - s));
    }

    bool hasSpecialChar = false;
    int consecutiveCount = 1;
    char prevChar = 0;

    for (int i = 0; i < length; ++i) {
        char c = s[i];

        if (!(isalnum(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }

        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
        }

        if (i > 0 && c == prevChar) {
            consecutiveCount++;
            if (consecutiveCount > 2) {
                return -(400 + i - 2);
            }
        }
        else {
            consecutiveCount = 1;
        }

        prevChar = c;
    }

    if (!hasSpecialChar) return -5;

    return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int index = -1;
    for (int i = 0; i < num_pwds; ++i) {
        int count = 1;
        int length = strlen(arr_pwds[i]);
        if (length == 0) continue;

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count;
            }
        }

        if ((count > maxCount) || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            index = i;
        }
    }
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////