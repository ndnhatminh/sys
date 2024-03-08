#include "study_in_pink1.h"

#define cexp2 check_exp(exp2)
#define cExp2 check_exp(EXP2)
#define cExp1 check_exp(EXP1)
#define cexp1 check_exp(exp1)
#define cHp1 check_hp(HP1)
#define cHp2 check_hp(HP2)
#define cm1 check_money(M1)
#define REP(i, a, b) for (int i = a; i < b; i++)

// misc functions to support writting
// check all conditions
void check_hp(int & hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0; 
}

void check_exp(int & exp) {
    if (exp > 600) exp = 600; 
    if (exp < 0) exp = 0; 
}

void check_money(int & M) {
    if (M > 3000) M = 3000; 
    if (M < 0) M = 0; 
}

void check_e(int & e) {
    if (e > 99 || e < 0) e = -99;  
}

bool check_square(int n) {
    if ((sqrt(n) - floor(sqrt(n))) != 0) {return false;}
    return true;
}

void event_1(int & HP1, int & M1, int & spent) {
    if (HP1 < 200) {
        HP1 += ceil(HP1*0.3);
        cHp1; 
        M1 -= 150;
        spent += 150; 
        cm1; 
    } else {
        HP1 += ceil(HP1*0.1);
        cHp1;
        M1 -= 70;
        spent += 70; 
        cm1; 
    }
}

void event_2(int & EXP1, int & M1, int & spent) {
    if (EXP1 < 400) {
        M1 -= 200; 
        spent += 200; 
        cm1; 
    } else {
        M1 -= 120;
        spent += 120; 
        cm1; 
    } 
    EXP1 = ceil(EXP1 + EXP1 * 0.13);
    cExp1; 
}

void event_3(int & EXP1, int & M1, int & spent) {
    if (EXP1 < 300) {
        M1 -= 100; 
        spent += 100; 
        cm1; 
    } else {
        M1 -= 120;
        spent += 120; 
        cm1;  
    }
    EXP1 = ceil(EXP1 - EXP1 * 0.1); 
}

int get_lowest_square(int n) {
    if (check_square(n)) return n; 
    else {
        int above = -1, below = -1;
        int na = n + 1; 
        while (true) {
            if (check_square(na)) {
                above = na; 
                break; 
            } else na++; 
        }
        int nb = n - 1; 
        while (true) {
            if (check_square(nb)) {
                below = nb; 
                break; 
            } else nb--; 
        }
        int d1 = abs(n - above);
        int d2 = abs(n - below); 
        if (d1 > d2) return below; 
        else return above; 
    }
}

double get_prob(int EXP1) {
    int P1; 
    double S = get_lowest_square(EXP1); 
    if (EXP1 >= S) {return 1;}
    else {
        P1 = ceil(((EXP1/S + 80)/123) * 100); 
        
    }
    return P1/100.0; 
}

int reduce_num(int a) {
    int i; 
    if (a < 10) i = a % 100;  
    else if (10 <= a && a < 100) {
        while (10 <= a && a < 100) {
            a = (a % 10 + a/10); 
        }
        i = a; 
    }
    return i; 
}

int find_max(int M[][10], int a, int b) {
    int max = M[a][b]; 
    int la = a, lb = b, ra = a, rb = b; 

    // the left diagonal 
    while (0 < a && a < 10 && 0 < b && b > 10) {
        la -= 1;
        lb -= 1; 
    }
    for (int i = la, j = lb; i < 10 && j < 10; i++, j++) {
        if (M[i][j] > max) max = M[i][j]; 
    }

    // the right diagonal 
    while (0 < a && a < 10 && 0 < b && b > 10) {
        ra -= 1; 
        rb += 1; 
    }

    for (int i = ra, j = rb; i < 10 && j > 0; i++, j--) {
        if (M[i][j] > max) max = M[i][j];    
    }
    return max; 
}

int count_c(string arr_pwds[], int num_pwds, string char_find, int i) {
    int c = 0; 
    REP(j, i, num_pwds) {
        if (arr_pwds[j] == char_find) c++; 
    }
    return c; 
}

// read file
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
    check_e(e1); if (e1 == -99) return e1; 
    if (0 <= e1 && e1 <= 3) {
        int D = 0;
        switch (e1) {
            case 0: 
                exp2 += 29;
                cexp2; 
                break; 
            case 1: 
                exp2 += 45;
                cexp2; 
                break; 
            case 2: 
                exp2 += 75;
                cexp2; 
                break; 
            case 3: 
                exp2 += 29 + 45 + 75; 
                cexp2; 
                break; 
        }
        D = e1 * 3 + exp1 * 7; 
        if (D % 2 == 0) {exp1 += ceil(D/200.0); cexp1;} 
        else {exp1 = ceil(exp1 - D/100.0); cexp1;}
    } else if (4 <= e1 && e1 <= 99) {
        if (4 <= e1 && e1 <= 19) {exp2 += ceil(e1/4.0 + 19); cexp2;} 
        else if (20 <= e1 && e1 <= 49) {exp2 += ceil(e1/9.0 + 21); cexp2;}
        else if (50 <= e1 && e1 <= 65) {exp2 += ceil(e1/16.0 + 17); cexp2;}
        else if (66 <= e1 && e1 <= 79) {
            exp2 += ceil(e1/4.0 + 19); 
            cexp2; 
            if (exp2 > 200) {exp2 += ceil(e1/9.0 + 21); cexp2;} 
        } else if (80 <= e1 && e1 <= 99) {
            exp2 += ceil(e1/4.0 + 19); cexp2; 
            exp2 += ceil(e1/9.0 + 21); cexp2; 
            if (exp2 > 400) {
                exp2 += ceil(e1/16.0 + 17); cexp2;
                exp2 += ceil(exp2 * 0.15); cexp2; 
            }
        }
        exp1 -= e1; cexp1; 
    } 
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    check_e(E2); if (E2 == -99) return E2; 
    // temp variables
    int a = HP1, b = EXP1, c = M1;

    // Path 1: 
    double P1 = get_prob(EXP1); 

    // Path 2:
    int spent = 0; 
    double m_2i = M1 * 0.5; 
    if (E2 % 2 != 0) {
        while (true) {
            // first event;
            event_1(HP1, M1, spent); 
            if (spent > m_2i) {break;}

            // second event; 
            event_2(EXP1, M1, spent);
            if (spent > m_2i) {break;}  
            
            // third event; 
            event_3(EXP1, M1, spent); 
            if (spent > m_2i) {break;}  
        }
        HP1 = ceil(HP1 - HP1 * 0.17); EXP1 = ceil(EXP1 + EXP1 * 0.17); cExp1;
    } else {
        int t = 1;
        while (t) {
            event_1(HP1, M1, spent); 
            if (M1 <= 0) break; 
            event_2(EXP1, M1, spent);
            if (M1 <= 0) break; 
            event_3(EXP1, M1, spent); 
            if (M1 <= 0) break;
            t--; 
        }
        HP1 = ceil(HP1 - HP1 * 0.17); EXP1 = ceil(EXP1 + EXP1 * 0.17); cExp1;
    }
    double P2 = get_prob(EXP1); 
    
    // Path 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i; 
    if (E2 < 10) i = E2; 
    else if (10 <= E2 && E2 < 100) i = (E2 % 10 + E2/10) % 10; 
    double P3 = P[i]/100.0; 

    // Final assessment
    int P_f;     
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = ceil(EXP1 - EXP1 * 0.25); 
    } else {
        P_f = ceil((P1 + P2 + P3)/3.0 * 100);
        if (P_f/100.0 < 0.5) {
            HP1 = ceil(HP1 - HP1 * 0.15); 
            EXP1 = ceil(EXP1 + EXP1 * 0.15); cExp1; 
        } else {
            HP1 = ceil(HP1 - HP1 * 0.1); 
            EXP1 = ceil(EXP1 + EXP1 * 0.2); cExp1; 
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    check_e(E3); if (E3 == -99) return E3; 
    int T[10][10] = {0};
    int count_r = 0; 
    int count_c = 0; 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            T[i][j] = ((E3 * j) + (i * 2)) * (i - j); 
            if (T[i][j] > E3 * 2) count_r += 1;
            if (T[i][j] < -E3) count_c += 1; 
        }
    }
    
    int i_met = reduce_num(count_r); 
    int j_met = reduce_num(count_c); 

    int ppos = (find_max(T, i_met, j_met)); 
    int tpos = (T[i_met][j_met]);
    if (abs(ppos) >= abs(tpos)) {
        EXP1 += ceil(EXP1 * 0.12); cExp1; 
        EXP2 += ceil(EXP2 * 0.12); cExp2;
        HP1 += ceil(HP1 * 0.1); cHp1; 
        HP2 += ceil(HP2 * 0.1); cHp2; 
    } else {
        EXP1 = ceil(EXP1 * 0.88);   
        EXP2 = ceil(EXP2 * 0.88); 
        HP1 = ceil(HP1 * 0.9); 
        HP2 = ceil(HP2 * 0.9); 
    }
    return (abs(ppos) >= abs(tpos)) ? ppos : tpos; 
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int i = 0; 
    string se = ""; 
    while (email[i] != '@') {
        se += email[i];
        i++; 
    }
    
    // check len
    int ns = strlen(s), nse = se.length(); 
    std::string sx = ""; 
    for (int i = 0; i < ns; i++) {
        sx += s[i];  
    }

    if (8 <= ns && ns <= 20) {}
    else if (ns < 8) return -1; 
    else return -2; 
    
    // check contain
    i = 0; int j = 0, sj = 0; 
    bool check = sx.find(se) != string::npos; 
    if (check) return -(300 + sx.find(se)); 
    
    // check consecutive
    for (i = 0; i < ns - 2; i++) {
        if (sx[i] == sx[i + 1] && sx[i] == sx[i + 2]) return -(400 + i); 
    }
    
    // check special 
    bool check_special = false; 
    for (int i = 0; i < ns; i++) {
        if (sx[i] == '@' || sx[i] == '#' || sx[i] == '%' || sx[i] == '$' || sx[i] == '!') {
            check_special = true; 
        } 
    }
    if (check_special) {} else return -5; 
    
    // the other type
    for (int i = 0; i < ns; i++) {
        if ('a' <= sx[i] && sx[i] <= 'z' || 'A' <= sx[i] && sx[i] <= 'Z' || '0' <= sx[i] && sx[i] <= '9' || 
        sx[i] == '@' || sx[i] == '#' || sx[i] == '%' || sx[i] == '$' || sx[i] == '!') {
        } else return i; 
    }
    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string s[num_pwds]; 
    REP(i, 0, num_pwds) {
        string t = arr_pwds[i]; 
        s[i] = t;
    }
    int max = 0, cmax = 0;  
    REP(i, 0, num_pwds) {
        int c = count_c(s, num_pwds, s[i], i); 
        if (c > max) {
            max = c;
            cmax = 1; 
        } else if (c == max) {
            cmax++; 
        }
    }
    int lmax = 0;
    REP(i, 0, num_pwds) {
        int c = count_c(s, num_pwds, s[i], i); 
        if (c == max && cmax == 1) {return i;}
        if (c == max && cmax > 1) {
            if (s[i].length() > lmax) lmax = s[i].length(); 
        }
    }

    REP(i, 0, num_pwds) {
        int c = count_c(s, num_pwds, s[i], i); 
        if (c == max && s[i].length() == lmax) {return i;}
    }
    return 0; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////