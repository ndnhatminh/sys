#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const float eps = 0.001;
const int MAXHP = 666, MAXEXP = 600, MAXM = 3000;
class ValHandle {
   private:
    int &val;
    int const &MAXVAL;

   public:
    ValHandle(int &Val, int const &MaxVal) : val(Val), MAXVAL(MaxVal) {
        if (val > MAXVAL)
            val = MAXVAL;
        else if (val < 0)
            val = 0;
    }

    void operator+=(int x) {
        val += x;
        if (val > MAXVAL) val = MAXVAL;
    }
    void operator-=(int x) {
        val -= x;
        if (val < 0) val = 0;
    }
    void operator+=(double x) {
        *this += int(ceil(x));
    }
    void operator-=(double x) {
        *this -= int(floor(x));
    }
    void operator*=(double x) {
        const float ans = val * x;
        val = ans;
        if (ans - val > eps) val++;
        if (val > MAXVAL) val = MAXVAL;
    }
};

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    if (e1 > 99 || e1 < 0) return -99;

    ValHandle EXP1(exp1, MAXEXP), EXP2(exp2, MAXEXP);

    if (e1 <= 3) {
        if (e1 == 0)
            EXP2 += 29;
        else if (e1 == 1)
            EXP2 += 45;
        else if (e1 == 2)
            EXP2 += 75;
        else
            EXP2 += 29 + 45 + 75;

        const int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            EXP1 += D / 200.0;
        else
            EXP1 -= D / 100.0;
    } else {
        if (e1 <= 19)
            EXP2 += e1 / 4.0 + 19;
        else if (e1 <= 49)
            EXP2 += e1 / 9.0 + 21;
        else if (e1 <= 65)
            EXP2 += e1 / 16.0 + 17;
        else if (e1 <= 79) {
            EXP2 += e1 / 4.0 + 19;
            if (exp2 > 200)
                EXP2 += e1 / 9.0 + 21;
        } else {
            EXP2 += e1 / 4.0 + 19;
            EXP2 += e1 / 9.0 + 21;
            if (exp2 > 400) {
                EXP2 += e1 / 16.0 + 17;
                EXP2 *= 1.15;
            }
        }

        EXP1 -= e1;
    }

    return exp1 + exp2;
}

// Task 2
float CalculateP(int &exp1) {
    int s = round(sqrt(exp1));
    s *= s;
    return (exp1 >= s) ? 1 : ((exp1 * 1.0 / s + 80) / 123.0);
}

bool RunEvent2(int &hp1, int &exp1, int &m1,
               ValHandle &HP1, ValHandle &EXP1, ValHandle &M1,
               const int MINM1) {
    if (m1 <= MINM1) return false;
    if (hp1 < 200) {
        HP1 *= 1.3;
        M1 -= 150;
    } else {
        HP1 *= 1.1;
        M1 -= 70;
    }

    if (m1 <= MINM1) return false;
    M1 -= (exp1 < 400) ? 200 : 120;
    EXP1 *= 1.13;

    if (m1 <= MINM1) return false;
    M1 -= (exp1 < 300) ? 100 : 120;
    EXP1 *= (1 - 0.1);

    return true;
}

int traceLuggage(int &hp1, int &exp1, int &m1, int e2) {
    if (e2 > 99 || e2 < 0) return -99;

    ValHandle HP1(hp1, MAXHP),
        EXP1(exp1, MAXEXP),
        M1(m1, MAXM);

    // Road 1
    const float p1 = CalculateP(exp1);

    // Road 2
    if (m1 != 0) {
        if (e2 % 2 == 1) {
            const int MINM1 = m1 / 2 - (m1 % 2 == 0);
            while (RunEvent2(hp1, exp1, m1, HP1, EXP1, M1, MINM1))
                ;
        } else
            RunEvent2(hp1, exp1, m1, HP1, EXP1, M1, 0);
    }
    HP1 *= (1 - 0.17);
    EXP1 *= 1.17;
    const float p2 = CalculateP(exp1);

    // Road 3
    const float p[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11},
                p3 = p[(e2 % 10 + e2 / 10) % 10];

    // End
    if (p1 == 1 && p2 == 1 && p3 == 1)
        EXP1 *= (1 - 0.25);
    else if (p1 + p2 + p3 < 1.5) {
        HP1 *= (1 - 0.15);
        EXP1 *= 1.15;
    } else {
        HP1 *= (1 - 0.1);
        EXP1 *= 1.2;
    }

    return hp1 + exp1 + m1;
}

// Task 3
void Convert(int &x) {
    if (x == 0) return;
    const int y = x % 9;
    if (y == 0)
        x = 9;
    else
        x = y;
}

int chaseTaxi(int &hp1, int &exp1, int &hp2, int &exp2, int e3) {
    if (e3 > 99 || e3 < 0) return -99;

    int TaxiScore[10][10], x = 0, y = 0, i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            TaxiScore[i][j] = (e3 * j + i * 2) * (i - j);
            x += (TaxiScore[i][j] > e3 * 2);
            y += (TaxiScore[i][j] < -e3);
        }
    }

    Convert(x);
    Convert(y);

    int SherlockScore = TaxiScore[x][y];

    i = x + 1, j = y + 1;
    while (i <= 9 && j <= 9) {
        const int CurrentScore = TaxiScore[i][j];
        if (CurrentScore > SherlockScore) SherlockScore = CurrentScore;
        i++;
        j++;
    }
    i = x + 1, j = y - 1;
    while (i <= 9 && j >= 0) {
        const int CurrentScore = TaxiScore[i][j];
        if (CurrentScore > SherlockScore) SherlockScore = CurrentScore;
        i++;
        j--;
    }
    i = x - 1, j = y + 1;
    while (i >= 0 && j <= 9) {
        const int CurrentScore = TaxiScore[i][j];
        if (CurrentScore > SherlockScore) SherlockScore = CurrentScore;
        i--;
        j++;
    }

    ValHandle HP1(hp1, MAXHP), EXP1(exp1, MAXEXP),
        HP2(hp2, MAXHP), EXP2(exp2, MAXEXP);
    if (abs(TaxiScore[x][y]) > SherlockScore) {
        HP1 *= (1 - 0.1);
        HP2 *= (1 - 0.1);
        EXP1 *= (1 - 0.12);
        EXP2 *= (1 - 0.12);
        return TaxiScore[x][y];
    }
    HP1 *= 1.1;
    HP2 *= 1.1;
    EXP1 *= 1.12;
    EXP2 *= 1.12;
    return SherlockScore;
}

// Task 4
bool IsSpecChar(char c) {
    return (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}

int checkPassword(const char *s2, const char *email2) {
    string s = s2, email = email2;
    int sLength = s.length();

    if (sLength < 8) return -1;
    if (sLength > 20) return -2;

    const size_t place = s.find(email.substr(0, email.find('@')));
    if (place != string::npos) return -(300 + int(place));

    bool HasSpecChar = IsSpecChar(s[sLength - 1]) | IsSpecChar(s[sLength - 2]);
    for (int i = 0; i < sLength - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
        HasSpecChar |= IsSpecChar(s[i]);
    }
    if (!HasSpecChar) return -5;

    for (int i = 0; i < sLength; i++) {
        const char c = s[i];
        if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '@' || c == '#' || c == '%' || c == '$' || c == '!'))
            return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds2[], int num_pwds) {
    string arr_pwds[num_pwds];
    for (int i = 0; i < num_pwds; i++)
        arr_pwds[i] = arr_pwds2[i];

    int Pos = 0, MaxAppearTime = 0, MaxLen = 0;
    bool IsChecked[num_pwds] = {};

    for (int i = 0; i < num_pwds; i++) {
        if (IsChecked[i]) continue;
        IsChecked[i] = true;

        int AppearTime = 0;
        for (int j = i + 1; j < num_pwds; j++)
            if (arr_pwds[i] == arr_pwds[j]) {
                AppearTime++;
                IsChecked[j] = true;
            }

        if (AppearTime >= MaxAppearTime) {
            const int Len = arr_pwds[i].length();
            if (AppearTime == MaxAppearTime && Len <= MaxLen) continue;

            MaxAppearTime = AppearTime;
            MaxLen = Len;
            Pos = i;
        }
    }

    return Pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////