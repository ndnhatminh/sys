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
void limit(int& value, int lowerLimit, int upperLimit) {
    value = max(lowerLimit, min(upperLimit, value));
}
// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1>99)return -99;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
        case 0: exp2 += 29;
            break;
        case 1: exp2 += 45;
            break;
        case 2: exp2 += 75;
            break;
        case 3: exp2 += 149;
            break;
        }
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) exp1 = ceil(exp1 + float(D / 200));
        else exp1 = ceil(exp1 - float(D / 100));

    }
    else {
        if (e1 >= 4 && e1 <= 19) exp2 += ceil(double(e1 / 4.0 + 19));
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil(double(e1 / 9.0 + 21));

        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil(double(e1 / 16.0 + 17));

        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil(double(e1 / 4 + 19));
            if (exp2 > 200) exp2 += ceil(double(e1 / 9.0 + 21));

        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil(double(e1 / 4 + 19)) + ceil(double(e1 / 9 + 21));
            if (exp2 > 400) exp2 += ceil(double(e1 / 16.0 + 17));
            exp2 = exp2 * 1.15;

        }exp1 -= e1;
    }
    limit(exp1, 0, 600);
    limit(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& hp1, int& exp1, int& m1, int e2) {
    // TODO: Complete this function
    if (e2 < 0 || e2 > 99) return -99;
    // Road1
    int p1, p2, p3;
    int n = round(sqrt(exp1));
    n = n * n;
    if (exp1 >= n) p1 = 100;
    else p1 = (float(exp1 / (n)+80) / 123) * 100;
    // Road2 
    if (e2 % 2 != 0)
    {
        int event = 2;
        int M1initial = m1;

        while (m1 > M1initial / 2)

        {
            switch (++event % 3)
            {
            case 0:
                if (hp1 < 200) {
                    hp1 = ceil(float(hp1 * 1.3));
                    m1 -= 150;
                    limit(hp1, 0, 666);
                    limit(m1, 0, 3000);
                }
                else {
                    hp1 = ceil(float(hp1 * 1.1));
                    m1 -= 70;
                    limit(hp1, 0, 666);
                    limit(m1, 0, 3000);
                }
                break;
            case 1:
                if (exp1 < 400) {
                    exp1 = ceil(float(exp1 * 1.13));
                    m1 -= 200;
                    limit(hp1, 0, 666);
                    limit(m1, 0, 3000);
                }
                else {
                    exp1 = ceil(float(exp1 * 1.13));
                    m1 -= 120;
                    limit(hp1, 0, 666);
                    limit(m1, 0, 3000);
                }
                break;
            case 2:
                if (exp1 < 300) {
                    exp1 = ceil(float(exp1 * 0.9));
                    m1 -= 100;
                    limit(hp1, 0, 666);
                    limit(m1, 0, 3000);
                }
                else {
                    exp1 = ceil(float(exp1 * 0.9));
                    m1 -= 120;
                    limit(hp1, 0, 666);
                    limit(m1, 0, 3000);
                }

            }


        }
    }
    else
    {

        int event = 0;
        while (m1 != 0 && event != 3) {
            switch (event++)
            {
            case 0:
                if (hp1 < 200) {
                    hp1 = ceil(float(hp1 * 1.3));
                    m1 -= 150;
                }
                else {
                    hp1 = ceil(float(hp1 * 1.1));
                    m1 -= 70;
                }
                limit(hp1, 0, 666);
                limit(m1, 0, 3000);
                break;
            case 1:
                if (exp1 < 400) {
                    m1 -= 200;
                }
                else m1 -= 120;
                exp1 = ceil(float(exp1 * 1.13));
                limit(m1, 0, 3000);
                limit(exp1, 0, 600);
                break;
            case 2:
                if (exp1 < 300) {
                    m1 -= 100;
                }
                else m1 -= 120;
                exp1 = ceil(float(exp1 * 0.9));
                limit(m1, 0, 3000);
                limit(exp1, 0, 600);
                break;

            }
        }
    }
    hp1 = ceil(float(hp1 * 0.83));
    exp1 = ceil(float(exp1 * 1.17));
    limit(exp1, 0, 600);
    if ((exp1 - n) >= 0) p2 = 100;
    else p2 = (float(exp1 / (n)+80) / 123) * 100;
    //Road 3
    int P[] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    i = e2 % 10;
    if (e2 >= 10) {
        i = (e2 / 10 + e2 % 10) % 10;
    }
    p3 = P[i];
    //End
    int pfinal;
    pfinal = (p1 + p2 + p3) / 3;
    if (pfinal == 100) exp1 = ceil(float(exp1 * 0.75));
    if (pfinal < 0.5 * pfinal) {
        hp1 = ceil(float(hp1 * 0.85));
        exp1 = ceil(float(exp1 * 1.15));
    }
    else {
        hp1 = ceil(float(hp1 * 0.9));
        exp1 = ceil(float(exp1 * 1.2));
    }

    limit(hp1, 0, 666);
    limit(m1, 0, 3000);
    limit(exp1, 0, 600);

    return hp1 + exp1 + m1;
}



// Task 3
int chaseTaxi(int& hp1, int& exp1, int& hp2, int& exp2, int e3) {
    // TODO: Complete this function
    int V[10][10] = { 0 };
    int x = 0, y = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == 0 && j == 0) {
                V[i][j] = 0;
            }
            else {
                V[i][j] = (e3 * j + i * 2) * (i - j);
                if (V[i][j] > 0 && V[i][j] > e3 * 2) ++x;
                if (V[i][j] < 0 && V[i][j] < -e3) ++y;
            }
        }
    }
    while (x > 9) {
        x = (x / 10) + (x % 10);
    }
    while (y > 9) {
        y = (y / 10) + (y % 10);
    }
    int meetingPoint = V[x][y];
    int z = 0;
    while ((x + z) < 9 && (y + z) < 9) {
        z++;
        if (V[x + z][y + z] > meetingPoint) {
            meetingPoint = V[x + z][y + z];
        }
    }
    while (x + z < 9 && y - z > 0) {
        z++;
        if (V[x + z][y - z] > meetingPoint) {
            meetingPoint = V[x + z][y - z];
        }
    }
    while (x - z > 0 && y + z < 9) {
        z++;
        if (V[x - z][y + z] > meetingPoint) {
            meetingPoint = V[x - z][y + z];
        }
    }
    while (x - z > 0 && y - z > 0) {
        if (V[x - z][y - z] > meetingPoint) {
            meetingPoint = V[x - z][y - z];
        }
    }
    if (abs(V[x][y]) > meetingPoint) {
        exp1 = ceil((double)exp1 * 0.88);
        hp1 = ceil((double)hp1 * 0.9);
        exp2 = ceil((double)exp2 * 0.88);
        hp2 = ceil((double)hp2 * 0.9);
        limit(exp1, 0, 600);
        limit(exp2, 0, 600);
        limit(hp1, 0, 666);
        limit(hp2, 0, 666);
        return V[x][y];
    }
    else {
        exp1 = ceil((double)exp1 * 1.2);
        hp1 = ceil((double)hp1 * 1.1);
        exp2 = ceil((double)exp2 * 1.2);
        hp2 = ceil((double)hp2 * 1.1);
        limit(exp1, 0, 600);
        limit(exp2, 0, 600);
        limit(hp1, 0, 666);
        limit(hp2, 0, 666);
        return meetingPoint;
    }
}
int checkPassword(const char* s, const char* email) {
    string password(s);
    string emailStr(email);
    string se = emailStr.substr(0, emailStr.find('@'));

    if (password.length() < 8) {
        return -1;
    }
    if (password.length() > 20) {
        return -2;
    }

    int pos = password.find(se);
    if (pos != string::npos) {
        return -(300 + pos);
    }

    for (int i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
            return -(400 + i);
        }
    }

    bool hasSpecialChar = false;
    string specialChars = "@#%$!";
    for (int i = 0; i < specialChars.length(); ++i) {
        if (password.find(specialChars[i]) != string::npos) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        return -5;
    }

    return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int correctPwdIndex = -1;
    int maxCount = 0;
    int maxLength = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        int len = strlen(arr_pwds[i]);
        if (count > maxCount || (count == maxCount && len > maxLength)) {
            maxCount = count;
            maxLength = len;
            correctPwdIndex = i;
        }
    }

    return correctPwdIndex;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////