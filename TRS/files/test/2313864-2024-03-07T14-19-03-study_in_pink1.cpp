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


void check_hp(float &t) {
    if (t!=int(t)) t = int(t) + 1;
    if (t > 666) t = 666;
    if (t < 0) t = 0;
}
void check_exp(float& t) {
    if (t != int(t)) t = int(t) + 1;
    if (t > 600) t = 600;
    if (t < 0) t = 0;
}
void check_m(float& t) {
    if (t != int(t)) t = int(t) + 1;
    if (t > 3000) t = 3000;
    if (t < 0) t = 0;
}

//Task1 functions
void i1(float &b,float r) {
    b += r / 4 + 19;
}
void i2(float &b, float r) {
    b += r / 9 + 21;
}
void i3(float& b, float r) {
    b += r / 16 + 17;
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function

    //declaration
    float a = exp1, b = exp2, r = e1;
    float d;
    
    //case1
    if (e1 >= 0 && e1 <= 3) {
        //exp2
        if (e1 == 0) {
            b += 29;
        }
        else if (e1 == 1) {
            b += 45;
        }
        else if (e1 == 2) {
            b += 75;
        }
        else b = b + 29 + 45 + 75;
        check_exp(b);

        //exp1
        float d = e1 * 3 + a * 7;
        if (int(d) % 2 == 0) a += d / 200;
        else a -= d / 100;
        check_exp(a);
    }

    //case2
    else if (e1 >= 4 && e1 <= 99) {
        //exp2
        if (e1>=4 && e1<=19) {
            i1(b,r);
        }
        else if (e1>=20 && e1<=49) {
            i2(b,r);
        }
        else if (e1>=50 && e1<=65) {
            i3(b,r);
        }
        else if (e1>=66 && e1<=79) {
            i1(b,r);
            check_exp(b);
            if (b > 200) i2(b,r);
        }
        else {
            i1(b,r);
            check_exp(b);
            i2(b, r);
            check_exp(b);
            if (b > 400) {
                i3(b, r);
                check_exp(b);
                b *= 1.15;
            }
        }
        check_exp(b);

        //exp1
        a -= e1;
        check_exp(a);
    }
    else return -99;

    //conclude
    exp1 = a;
    exp2 = b;

    return exp1 + exp2;
}


//Task2 functions
int findS(float a) {
    float s1, s2, s;

    s1 = pow(int(sqrt(a)), 2);
    s2 = pow(int(sqrt(a)) + 1, 2);

    if (a - s1 <= s2 - a) s = s1;
    else s = s2;

    return s;
}

int a1(float& x, float& m) {
    int tm;
    if (x < 200) {
        x *= 1.3;
        m -= 150;
        tm = 150;
    }
    else {
        x *= 1.1;
        m -= 70;
        tm = 70;
    }
    check_hp(x);
    check_m(m);
    return tm;
}

int a2(float& a, float& m) {
    int tm;
    if (a < 400) {
        m -= 200;
        tm = 200;
    }
    else {
        m -= 120;
        tm = 120;
    }
    a *= 1.13;
    check_exp(a);
    check_m(m);
    return tm;
}

int a3(float& a, float& m) {
    int tm;
    if (a < 300) {
        m -= 100;
        tm = 100;
    }
    else {
        m -= 120;
        tm = 120;
    }
    a -= a * 0.1;
    check_exp(a);
    check_m(m);
    return tm;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2>99) return -99;

    //declaration
    float a = EXP1, x = HP1, m = M1, r = E2;
    float p1, p2, p3, p;
    float s;

    //road1
    s = findS(a);
    if (a >= s) p1 = 1;
    else p1 = (a / s + 80) / 123;

    //road2
    float hm = 0.5*m;
    int tm=0;

    if (int(r) % 2 != 0) {
        while (1) {
            tm += a1(x, m);
            if (tm > hm) break;
            tm += a2(a, m);
            if (tm > hm) break;
            tm += a3(a, m);
            if (tm > hm) break;
        }
    }
    else {
        a1(x, m);
        if (m != 0) {
            a2(a, m);
            if (m != 0) {
                a3(a, m);
            }
        }
    }

    x -= x * 0.17;
    a *= 1.17;
    check_hp(x);
    check_exp(a);

    s = findS(a);
    if (a >= s) p2 = 1;
    else p2 = (a / s + 80) / 123;

    //road3
    float P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    if (r < 10) i = r;
    else {
        int t1 = r / 10;
        int t2 = int(r) % 10;
        int t = t1 + t2;
        if (t < 10) i = t;
        else i = t % 10;
    }
    p3 = P[i]/100;

    //conclude
    if (p1 == p2 && p2 == p3 && p3 == 1) a -= a * 0.25;
    else {
        p = (p1 + p2 + p3) / 3;
        if (p < 0.5) {
            x -= x * 0.15;
            a *= 1.15;
        }
        else {
            x -= x * 0.1;
            a *= 1.2;
        }
    }
    check_hp(x);
    check_exp(a);

    HP1 = x;
    EXP1 = a;
    M1 = m;

    return HP1 + EXP1 + M1;
}


//Task3 functions
int maxleft(float im, float jm, int taxi[10][10]) {
    int it = im, jt = jm;
    int max = taxi[it][jt];

    if (it <= jt) {
        jt -= it;
        it = 0;
    }
    else {
        it -= jt;
        jt = 0;
    }

    for (int i = it, j = jt; i < 10, j < 10; i++, j++) {
        if (taxi[it][jt] > max) max = taxi[it][jt];
    }
    return max;
}

int maxright(float im, float jm, int taxi[10][10]) {
    int it = im, jt = jm;
    int max = taxi[it][jt];

    if (it <= 9 - jt) {
        jt += it;
        it = 0;
    }
    else {
        it -= 9 - jt;
        jt = 9;
    }
    for (int i = it, j = jt; i < 10 && j >= 0; i++, j--) {
        if (taxi[i][j] > max) max = taxi[i][j];
    }

    return max;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;

    //declaration
    float a = EXP1, b = EXP2, x = HP1, y = HP2, r = E3;
    int taxi[10][10] = { 0 };
    float im = 0, jm = 0;
    int maxl, maxr, max;
    int d;
    bool win;

    //matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((r * j) + (2 * i)) * (i - j);
            if (taxi[i][j] > r * 2) im++;
            if (taxi[i][j] < -r) jm++;
        }
    }

    while (im >= 10) im = int(im / 10) + int(im) % 10;
    while (jm >= 10) jm = int(jm / 10) + int(jm) % 10;

    maxl = maxleft(im, jm, taxi);
    maxr = maxright(im, jm, taxi);
    if (maxl >= maxr) max = maxl;
    else max = maxr;
    if (max < 0) max = abs(max);

    //conclude
    win = abs(taxi[int(im)][int(jm)]) <= max;

    if (win) {
        a *= 1.12;
        b *= 1.12;
        x *= 1.1;
        y *= 1.1;
    }
    else {
        a -= a * 0.12;
        b -= b * 0.12;
        x -= x * 0.1;
        y -= y * 0.1;
    }
    check_exp(a);
    check_exp(b);
    check_hp(x);
    check_hp(y);

    EXP1 = a;
    EXP2 = b;
    HP1 = x;
    HP2 = y;

    if (win == 1) return max;
    else return taxi[int(im)][int(jm)];
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function

    //Declaration
    string p = s, em = email, se;
    int pl = p.size(), sel;

    //se
    for (int i = 0; i < em.size(); i++) {
        if (em[i] == '@') {
            for (int j = 0; j < i; j++) {
                se += em[j];
            }
            break;
        }
    }
    sel = em.size();

    //check
    //check length
    if (pl < 8) return -1;
    else if (pl > 20) return -2;

    //check se
    int fse = p.find(se, 0);
    if (fse != -1) return -(300 + fse);

    //check consecutive characters
    for (int i = 0; i < pl - 2; i++){
        if (p[i] == p[i + 1] && p[i + 1] == p[i + 2]) return -(400 + i);
    }

    //check special characters
    bool spe = 0;
    for (int i = 0; i < pl; i++) {
        if (p[i] == '!' || p[i] == '@' || p[i] == '#' || p[i] == '$' || p[i] == '%') spe = 1;
    }
    if (spe == 0) return -5;

    //check invalid characters
    for (int i = 0; i < pl; i++) {
        int d = int(p[i]);
        if (d == 33 || d >= 35 && d <= 37 || d >= 64 && d <= 90 || d >= 97 && d <= 122 || d >= 48 && d <= 57) {}
        else return i;
    }

    //valid
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    //Declaration
    int n = num_pwds;
    string p[100];
    for (int i = 0; i < n; i++) {
        p[i] = arr_pwds[i];
    }
    int c[100] = { 0 };
    string l[100];

    //checkarr
    for (int i = 0; i < n; i++) {
        string t = p[i];
        for (int j = 0; j < n; j++) {
            if (p[j] == t) c[i]++;
        }
    }

    //find most found
    int maxf = 0, cm = 0;
    for (int i = 0; i < 100; i++) {
        if (c[i] > maxf) maxf = c[i];
    }
    for (int i = 0; i < 100; i++) {
        if (c[i] == maxf) cm++;
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (c[i] == maxf) {
            l[j] = p[i];
            j++;
        }
    }

    //compare length
    int maxl = l[0].size(), maxp = 0;
    for (int i = 0; i < cm; i++) {
        if (l[i].size() > maxl) {
            maxl = l[i].size();
            maxp = i;
        }
    }

    //find position
    int po = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == l[maxp]) {
            po = i;
            break;
        }
    }
    return po;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////