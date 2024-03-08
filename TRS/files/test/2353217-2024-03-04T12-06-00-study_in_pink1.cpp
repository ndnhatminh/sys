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
/// Delete the following functions
/// DO NOT look at the functions.
////////////////////////////////////////////////////////////////////////

void fix(int & a, int b) {
    a = a < 0 ? 0 : (a < b ? a : b);
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // Never trust user input
    if (e1 < 0 || e1 > 99) return -99;
    fix(exp1, 600); fix(exp2, 600);
    
    if (e1 < 4) {
        int d = e1 * 3 + exp1 * 7, exp[] = {29,45,75,149};
        exp1 += (d & 1) ? -d / 100 : (d + 199) / 200; // Ceiling function
        exp2 += exp[e1];
    } else {
        exp1 -= e1;
        if (e1 < 20 || e1 > 65) exp2 += (e1 + 3) / 4 + 19;
        // If information 5 or 2 or (4 with enough EXP) is given
        if (e1 > 79 || e1 > 19 && e1 < 50 || e1 > 65 && e1 < 80 && exp2 > 200) 
            exp2 += (e1 + 8) / 9 + 21;
        if (e1 > 49 && e1 < 66 || e1 > 79 && exp2 > 400) 
            exp2 += (e1 + 15) / 16 + 17;
        if (e1 > 79 && exp2 > 417 + (e1 + 15) / 16)
            exp2 += (exp2 * 3 + 19) / 20;
    }
    
    //Also used before subtracting >600 or adding <0
    fix(exp1, 600); fix(exp2, 600);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & hp1, int & exp1, int & m1, int e2) {
    if (e2 < 0 || e2 > 99) return -99;
    fix(hp1, 666); fix(exp1, 600); fix(m1, 3000);
    
    int i[] = {32,47,28,79,100,50,22,83,64,11}, s = sqrt(exp1), m0 = m1;
    int p = s * (s + 1) < exp1 ? 66 : 100; // 0.75 <= P1 / S < 1
    
    // Event
    if (m1) do {
        m1  -= hp1 < 200 ? 150 : 70;
        hp1 += (hp1 * 2 * (hp1 < 200) + hp1 + 9) / 10;
        if (m1 < 1 || e2 & 1 && m1 << 1 < m0) break;
        m1  -= exp1 < 400 ? 200 : 120;
        exp1 += (exp1 * 13 + 99) / 100; fix(exp1, 600);
        if (m1 < 1 || e2 & 1 && m1 << 1 < m0) break;
        m1 -= exp1 < 300 ? 100 : 120; exp1 -= exp1 / 10;
    } while (e2 & 1 && m1 << 1 >= m0);
    
    // End of the route
    fix(hp1, 666); hp1 -= hp1 * 17 / 100;
    exp1 += (exp1 * 17 + 99) / 100; fix(exp1, 600);
    m1 = m1 < 0 ? 0 : m1;
    
    s = sqrt(exp1);
    p += s * (s + 1) < exp1 ? 66 : 100;
    p += i[(e2 + e2 / 10) % 10];
    
    hp1  -= p - 300 ? (hp1 * (p < 150) + hp1 * 2) / 20 : 0;
    exp1 += p - 300 ? (exp1 * 4 - exp1 * (p < 150) + 19) / 20 : -exp1 / 4;
    
    fix(exp1, 600);
    return hp1 + exp1 + m1;
}

// Task 3
int chaseTaxi(int & hp1, int & exp1, int & hp2, int & exp2, int e3) {
    if (e3 < 0 || e3 > 99) return -99;
    fix(hp1, 666); fix(hp2, 666); fix(exp1, 600); fix(exp2, 600);
    
    int i, j, a = 0, b = 0, grade = 0, x[10][10] = {0};
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            x[i][j] = (e3 * j + (i << 1)) * (i - j);
            a += (x[i][j] > e3 << 1); b += (x[i][j] < -e3);
        }
    }
    a = 1 + (a - 1) % 9; b = 1 + (b - 1) % 9; // Digital root
    
    // Only check left diagonal if contains positive values
    if (a > b) for (i = 0, j = a - b; j < 10; i++, j++) 
        grade = grade < x[i][j] ? x[i][j] : grade;
    for (i = (a + b + 1) >> 1, j = (a + b) >> 1; i < 10 && j + 1; i++, j--)
        grade = grade < x[i][j] ? x[i][j] : grade;
    
    bool ans = grade < abs(x[a][b]);
    hp1  += ans ? -hp1      / 10 : (hp1 + 9)       / 10;
    hp2  += ans ? -hp2      / 10 : (hp2 + 9)       / 10;
    exp1 += ans ? -exp1 * 3 / 25 : (exp1 * 3 + 24) / 25;
    exp2 += ans ? -exp2 * 3 / 25 : (exp2 * 3 + 24) / 25;
    fix(hp1, 666); fix(hp2, 666); fix(exp1, 600); fix(exp2, 600);
    
    return ans ? x[a][b] : grade;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    auto valid = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%";
    int m = strspn(s, valid), n = strlen(s);
    if (n < 8 ) return -1;
    if (n > 20) return -2;
    
    char se[101] = {'\0'};
    // If s contains se, made of the initial part of email not containing "@"
    if (auto i = strstr(s, strncpy(se, email, strcspn(email, "@"))))
        return s - i - 300;   
    
    for (auto i = s + 2; *i; i++) if (*i == *(i - 1) && *i == *(i - 2))
        return s - i - 398; // NOTE: started at s + 2
    
    return strcspn(s, "!@#$%") - n ? (m - n ? m : -10) : -5; // 3 return results
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // <ordered_map>
    std::string ans = "", pass[31] = {""};
    int i, m = 1, num = 0, loc[31] = {0}, count[31] = {0};
    
    for (i = 0; i < num_pwds; i++) {
        int j = 0;
        while (j < num && pass[j] != arr_pwds[i]) j++;
        
        count[j]++;
        if (j - num) m = m < count[j] ? count[j] : m;
        else {
            loc[j] = i;pass[num++] = arr_pwds[i];
        }
    }
    
    for (i = 31; i--;) ans = count[i] - m || ans.size() > pass[i].size() ? ans : pass[i];
    for (i = 31; i--;) if (pass[i] == ans) return loc[i];
    return -1; // Shouldn't reach here
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////