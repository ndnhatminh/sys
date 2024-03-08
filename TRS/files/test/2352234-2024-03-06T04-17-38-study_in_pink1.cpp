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

// 1 hp, 2 exp, 3 m
int standard(int id, int value) {
    value = max(0, value);
    switch (id)
    {
    case 1:
        value = min(666, value);
        break;
    case 2:
        value = min(600, value);
        break;
    case 3:
        value = min(3000, value);
        break;
    }
    return value;
}

//find the closest prime number
int closestPrime(int num) {
    int fl = sqrt(num);
    int ce = fl + 1;
    fl = fl * fl;
    ce = ce * ce;
    if ((num - fl) < (ce - num))
        return fl;
    return ce;
}

//mission 2, con duong 1
double calPecent(int exp) {
    int S = closestPrime(exp);
    double p;
    if (exp >= S)
        p = 100;
    else 
        p = ((exp * 1.0 / S + 80) / 123.0) * 100;
    return p;
}


// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;

    //case 1
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0)
            exp2 = standard(2, exp2 + 29);
        else if (e1 == 1)
            exp2 = standard(2, exp2 + 45);
        else if (e1 == 2)
            exp2 = standard(2, exp2 + 75);
        else if (e1 == 3)
            exp2 = standard(2, exp2 + 149);
        int D = e1 * 3 + exp1 * 7;

        if (D % 2)
            exp1 = standard(2, ceil(exp1 - D / 100.0));
        else
            exp1 = standard(2, ceil(exp1 + D / 200.0));
    }
    else {
        if (e1 < 20)
            exp2 = standard(2, ceil(exp2 + e1 / 4.0 + 19));
        else if (e1 < 50)
            exp2 = standard(2, ceil(exp2 + e1 / 9.0 + 21));
        else if (e1 < 66)
            exp2 = standard(2, ceil(exp2 + e1 / 16.0 + 17));
        else if (e1 < 80) {
            exp2 = standard(2, ceil(exp2 + e1 / 4.0 + 19));
            if (exp2 > 200) 
                exp2 = standard(2, ceil(exp2 + e1 / 9.0 + 21));
        }
        else if (e1 < 100) {
            exp2 = standard(2, ceil(exp2 + e1 / 4.0 + 19));
            exp2 = standard(2, ceil(exp2 + e1 / 9.0 + 21));
            if (exp2 > 400) {
                exp2 = standard(2, ceil(exp2 + e1 / 16.0 + 17));
                exp2 = standard(2, ceil(exp2 + exp2 * 0.15));
            }
        }
        exp1 = standard(2, exp1 - e1);

    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;

    //road 01
    double p1 = calPecent(EXP1);
    //road 02
    int isValid = E2 % 2; // E2 is a odd or even
    // condition for exit
    float st;
    if (isValid) {
        st = M1 / 2.0;
    }
    else
        st = 1;
    do {
        //event 1
        if (HP1 < 200) {
            HP1 = standard(1, ceil(HP1 + HP1 * 0.3));
            M1 = standard(3, M1 - 150);
        }
        else {
            HP1 = standard(1, ceil(HP1 + HP1 * 0.1));
            M1 = standard(3, M1 - 70);
        }
        if (M1 < st)
        {
            break;
        }

        //event 2
        if (EXP1 < 400) {
            M1 = standard(3, M1 - 200);
        }
        else
            M1 = standard(3, M1 - 120);
        EXP1 = standard(2, ceil(EXP1 + EXP1 * 0.13));
        if (M1 < st) {
            break;
        }
        //event 3
        if (EXP1 < 300)
            M1 = standard(3, M1 - 100);
        else
            M1 = standard(3, M1 - 120);
        EXP1 = standard(2, ceil(EXP1 - EXP1 * 0.1));
        if (M1 < st)
            break;
    } while (isValid);

    //if sherlock choose to end this road not passing other event
    HP1 = standard(1, ceil(HP1 - HP1 * 0.17));
    EXP1 = standard(2, ceil(EXP1 + EXP1 * 0.17));
    
    double p2 = calPecent(EXP1);

    //road 3
    int pr3[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    double p3;
    if (E2 / 10 == 0)
        p3 = pr3[E2];
    else
    {
        int a = (E2 % 10) + E2 / 10;
        p3 = pr3[a % 10];
    }

    //sum up
    if (p1 == 100 && p2 == 100 && p3 == 100)
        EXP1 = standard(2, ceil(EXP1 - EXP1 * 0.25));
    else
    {
        double ptotal = (p1 + p2 + p3) / 3.0;
        if (ptotal < 50) {
            HP1 = standard(1, ceil(HP1 - HP1 * 0.15));
            EXP1 = standard(2, ceil(EXP1 + EXP1 * 0.15));
        }
        else
        {
            HP1 = standard(1, ceil(HP1 - HP1 * 0.1));
            EXP1 = standard(2, ceil(EXP1 + EXP1 * 0.2));
        }
    }
    return HP1 + EXP1 + M1;
}

//tong 2 don vi 1 so
int sumOfInt(int value) {
    int result = (value / 10) + (value % 10);
    if (result / 10)
        result = sumOfInt(result);
    return result;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;

    int posBiggerthanvalue = 0; //how many number that is bigger than 
    int negSmallerthanvalue = 0;
    int taxiMatrix[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiMatrix[i][j] = (E3 * j + i * 2) * (i - j);
            if (taxiMatrix[i][j] > E3 * 2)
                posBiggerthanvalue++;
            else if (taxiMatrix[i][j] < -E3)
                negSmallerthanvalue++;
        }
    }
    //cordinate meeting position
    int i = sumOfInt(posBiggerthanvalue);
    int j = sumOfInt(negSmallerthanvalue);

    // find sherlock point 
    int max = taxiMatrix[i][j];
    for (int a = 0; a < 10; a++) {
        if (i + a < 10 && j + a < 10)
            max = ((taxiMatrix[i + a][j + a] > max) ? taxiMatrix[i + a][j + a] : max);
        if (i + a < 10 && j - a >= 0)
            max = ((taxiMatrix[i + a][j - a] > max) ? taxiMatrix[i + a][j - a] : max);
        if (i - a >= 0 && j + a < 10)
            max = ((taxiMatrix[i - a][j + a] > max) ? taxiMatrix[i - a][j + a] : max);
        if (i - a >= 0 && j - a >= 0)
            max = ((taxiMatrix[i - a][j - a] > max) ? taxiMatrix[i - a][j - a] : max);
    }

    int sherpoint = abs(max);
    int taxipoint = abs(taxiMatrix[i][j]);
    if (taxipoint > sherpoint) {
        EXP1 = standard(2, ceil(EXP1 - EXP1 * 0.12));
        HP1 = standard(1, ceil(HP1 - HP1 * 0.1));
        EXP2 = standard(2, ceil(EXP2 - EXP2 * 0.12));
        HP2 = standard(1, ceil(HP2 - HP2 * 0.1));
    }
    else {
        EXP1 = standard(2, ceil(EXP1 + EXP1 * 0.12));
        HP1 = standard(1, ceil(HP1 + HP1 * 0.1));
        EXP2 = standard(2, ceil(EXP2 + EXP2 * 0.12));
        HP2 = standard(1, ceil(HP2 + HP2 * 0.1));
    }
    return ((taxipoint > sherpoint) ? taxiMatrix[i][j] : max);
}

string convertToString(const char* s, char exit) {
    string result = "";
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == exit)
            return result;
        result += s[i];
    }
    return result;
}

// check if character is valid (is alpha or number or valid special character
bool isValidChar(char b) {
    if ((b >= 48 && b <= 57) || (b >= 65 && b <= 90)
        || (b >= 97 && b <= 122) || b == 64 || b == 35 || b == 37 || b == 36 || b == '!')
        return 1;
    return 0;
}

int isValidString(const string s) {
    int isSpecialChar = -5;

    int isCon = 0;// check if consecutive
    for (isCon; isCon < s.length(); isCon++) {
        // check if cons
        if (isCon < s.length() - 2)
            if (s[isCon] == s[isCon + 1] && s[isCon] == s[isCon + 2])
                return -(400 + isCon);
        if (s[isCon] == '@' || s[isCon] == '#' || s[isCon] == '%' || s[isCon] == '$' || s[isCon] == '!')
            isSpecialChar = -1;
    }
    return isSpecialChar;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    string seInString = convertToString(email, '@');
    string sInString = convertToString(s, '\0');

    if (sInString.length() < 8) return -1;
    else if (sInString.length() > 20) return -2;
    int valid = 0;

    valid = sInString.find(seInString);
    if (valid != -1)
        return -(300 + valid);

    valid = isValidString(sInString);
    if (valid != -1)
        return valid;
    
    for (int i = 0; i < sInString.length(); i ++){
        if (!isValidChar(sInString[i]))
            return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int numsIndex[2][100];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < num_pwds; j++)
            numsIndex[i][j] = 0;

    int po1 = 0, po2;
    int maxIndex = 0;
    for (; po1 < num_pwds; po1++) {
        if (numsIndex[0][po1] != 0) continue;
        numsIndex[0][po1]++;
        numsIndex[1][po1] = strlen(arr_pwds[po1]);
        for (po2 = po1 + 1; po2 < num_pwds; po2++) {
            if (numsIndex[0][po2] == 0 && strcmp(arr_pwds[po2], arr_pwds[po1]) == 0) {
                numsIndex[0][po1]++;
                numsIndex[0][po2] = -1;
            }
        }

        if (numsIndex[0][po1] > numsIndex[0][maxIndex] ||
            (numsIndex[0][po1] == numsIndex[0][maxIndex] &&
                numsIndex[1][po1] > numsIndex[1][maxIndex]))
            maxIndex = po1;
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER 2352234
////////////////////////////////////////////////