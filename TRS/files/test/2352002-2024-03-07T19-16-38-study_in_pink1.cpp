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
    // DO NOT MODIFY THIS FUNCTION
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

int reset_HP (int & HP) {
    if (HP > 666)
        return 666;
    if (HP < 0)
        return 0;
    return HP;
}
int reset_EXP (int & EXP) {
    if (EXP > 600)
        return 600;
    if (EXP < 0)
        return 0;
    return EXP;
}
int reset_M (int & M){
    if (M > 3000)
        return 3000;
    if (M < 0)
        return 0;
    return M;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;
    float k,m,n,o,r,q;
    if (e1 < 0 || e1 > 99)
        return -99;
    else
        if (e1 < 4) {
            if (e1 == 0) {
                exp2 += 29;
                exp2 = reset_EXP(exp2);
            }
            if (e1 == 1) {
                exp2 += 45;
                exp2 = reset_EXP(exp2);
            }
            if (e1 == 2) {
                exp2 += 75;
                exp2 = reset_EXP(exp2);
            }
            if (e1 == 3) {
                exp2 = exp2 + 29 + 75 + 45;
                exp2 = reset_EXP(exp2);
            }
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
                k = float (exp1) + float (D) / 200;
            else
                k = float (exp1) - float (D) / 100;
            exp1 = ceil(k);
            exp1 = reset_EXP(exp1);//Thêm hàm làm tròn, hàm giới hạn
    }
        else {
            if (e1 <= 19) {
                m = float (exp2) + float(e1) / 4 + 19;
                exp2 = ceil(m);
                exp2 = reset_EXP(exp2);
            }
            else
                if (e1 <= 49) {
                    n = float (exp2) + float (e1) / 9 + 21;
                    exp2 = ceil(n);
                    exp2 = reset_EXP(exp2);
                }
                else
                    if (e1 <= 65) {
                        o = float (exp2) + float (e1) / 16 + 17;
                        exp2 = ceil(o);
                        exp2 = reset_EXP(exp2);
                    }
                    else
                        if (e1 <= 79) {
                            m = float (exp2) + float (e1) / 4 + 19;
                            exp2 = ceil(m);
                            exp2 = reset_EXP(exp2);//Thêm hàm làm tròn, hàm giới hạn
                            if (exp2 > 200) {
                                n = float (exp2) + float (e1) / 9 + 21;
                                exp2 = ceil(n);
                                exp2 = reset_EXP(exp2);//Thêm hàm làm tròn, hàm giới hạn
                            }
                        }
                        else {
                            m = float (exp2) + float (e1) / 4 + 19;
                            exp2 = ceil(m);
                            exp2 = reset_EXP(exp2);//Thêm hàm làm tròn, hàm giới hạn
                            n = float (exp2) + float (e1) / 9 + 21;
                            exp2 = ceil(n);
                            exp2 = reset_EXP(exp2);//Thêm hàm làm tròn, hàm giới hạn
                            if (exp2 > 400) {
                                o = float (exp2) + float (e1) / 16 + 17;
                                exp2 = ceil(o);
                                exp2 = reset_EXP(exp2);//Thêm hàm làm tròn, hàm giới hạn
                                r = float (exp2) + float (exp2) * 15 / 100;
                                exp2 = ceil(r);
                                exp2 = reset_EXP(exp2);//Thêm hàm làm tròn, hàm giới hạn
                            }
                        }
                        q = float (exp1) - e1;
                        exp1 = ceil(q);
                        exp1 = reset_EXP(exp1);
    }
    return exp1 + exp2;
}

int SoChinhPhuong (int n) {
    int scp = 1, i;
    for ( i = 1 ; scp < n ; i++ ){
        scp = i*i;
    }
    int scp1 = (i-2) * (i-2);
    if (abs(scp1 - n) > abs(scp - n))
        return scp;
    else
        return scp1;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    int S = SoChinhPhuong ( EXP1);
    float P1,P2;
    //Con duong 01
    if (EXP1 >= S)
        P1 = float (100/100);
    else
        P1 = (float (EXP1) / float (S) + 80) / 123;
    //Con duong 02;
    int m1 = M1;
    float deltaM;
    const float m_1 = float (M1) * 0.5;
    float m,o,p,q,r;
    if ((E2 % 2) > 0) {
        while (true) { //Di toi khi tien lon hon 50 phan tram.
            if (HP1 < 200) {
                m = float (HP1) + float (HP1) * 0.3;
                HP1 = ceil(m);
                HP1 = reset_HP(HP1);
                M1 = M1 - 150;
            } else {
                m = float (HP1) + float (HP1) * 0.1;
                HP1 = ceil(m);
                HP1 = reset_HP(HP1);
                M1 = M1 - 70;
            }
            deltaM = float(m1) - float(M1);
            if (deltaM > m_1)
                break;

            if (EXP1 < 400)
                M1 = M1 - 200;
            else
                M1 = M1 - 120;
            o = float(EXP1) + float(EXP1) * 0.13;
            EXP1 = ceil(o);
            EXP1 = reset_EXP(EXP1);
            deltaM = float(m1) - float(M1);
            if (deltaM > m_1)
                break;

            if (EXP1 < 300)
                M1 = M1 - 100;
            else
                M1 = M1 - 120;
            q = float(EXP1) - float(EXP1) * 0.1;
            EXP1 = ceil(q);
            EXP1 = reset_EXP(EXP1);
            deltaM = float(m1) - float(M1);
            if (deltaM > m_1)
                break;
        }
    }
    else {
        if (HP1 < 200) {
            m = float(HP1) + float(HP1) * 0.3;
            HP1 = ceil(m);
            HP1 = reset_HP(HP1);
            M1 = M1 - 150;
        }
        else {
            m = float(HP1) + float(HP1) * 0.1;
            HP1 = ceil(m);
            HP1 = reset_HP(HP1);
            M1 = M1 - 70;
        }
        if (M1 > 0) {
            if (EXP1 < 400)
                M1 = M1 - 200;
            else
                M1 = M1 - 120;
            o = float(EXP1) + float(EXP1) * 0.13;
            EXP1 = ceil(o);
            EXP1 = reset_EXP(EXP1);

            if (M1 > 0) {
                if (EXP1 < 300)
                    M1 = M1 - 100;
                else
                    M1 = M1 - 120;
                q = float(EXP1) - float(EXP1) * 0.1;
                EXP1 = ceil(q);
                EXP1 = reset_EXP(EXP1);
            }
        }
    }

    p = float (HP1) - float (HP1) * 0.17;
    HP1 = ceil(p);
    HP1 = reset_HP(HP1);
    r = float (EXP1) + float (EXP1) * 0.17;
    EXP1 = ceil(r);
    EXP1 = reset_EXP(EXP1);

    M1 = reset_M(M1);
    int S2 = SoChinhPhuong(EXP1);
    if (EXP1 >= S2)
        P2 = 100/100;
    else
        P2 = (float (EXP1) / float (S2) + 80) / 123;
    //Con duong 03
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i,P3;
    if ( E2 < 10)
        i = E2;
    else {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    P3 = P[i];
    //Ket luan
    float s,t,u,Ptb;
    if (P1 == 1 && P2 == 1 && P3 == 100){
        s = float (EXP1) - float (EXP1) * 0.25;
        EXP1 = ceil(s);
        EXP1 = reset_EXP(EXP1);
    }
    else {
        Ptb = (P1 + P2 + float(P3)/100) / 3;
        if (Ptb < 0.5 ){
            t = float (HP1) - float (HP1) * 0.15;
            HP1 = ceil(t);
            HP1 = reset_HP(HP1);
            u = float (EXP1) + float (EXP1) * 0.15;
            EXP1 = ceil(u);
            EXP1 = reset_EXP(EXP1);
        }
        else {
            t = float (HP1) - float (HP1) * 0.1;
            HP1 = ceil(t);
            HP1 = reset_HP(HP1);
            u = float (EXP1) + float (EXP1) * 0.2;
            EXP1 = ceil(u);
            EXP1 = reset_EXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    int A[10][10];//Diem cua taxi
    int x = 0,y = 0,s;
    float k,l,p,q;
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            A[i][j] = ( (E3 * j) + (i * 2) ) * (i - j);
            if ( A[i][j] > (E3 * 2) )
                x = x + 1;
            if ( A[i][j] < (-E3) )
                y = y + 1;
        }
    }
    int m = x,n = y;

    if ( m > 10)
        while (true){
            m = m/10 + m%10;
            if ( m < 10)
                break;
        }

    if ( n > 10)
        while (true){
            n = n/10 + n%10;
            if ( n < 10)
                break;
        }

    int Max = A[m][n];
    int d = n - m;
    for ( int i = 0 ; i < 10 ; i++){
        if ((i + d) >= 0) {
            if (A[i][i + d] >= Max)
                Max = A[i][i + d];
            if ((i + d) == 9)
                break;
        }
    }
    int f = m + n;
    for ( int i = 0 ; i < 10 ; i++){
        if ((f - i) < 10) {
            if (A[i][f - i] >= Max)
                Max = A[i][f - i];
            if (i == 9)
                break;
        }
    }
    if ( abs (Max) < abs(A[m][n]) ){
        k = float (HP1) - float (HP1) * 0.1;
        HP1 = ceil(k);
        HP1 = reset_HP(HP1);
        p = float (HP2) - float (HP2) * 0.1;
        HP2 = ceil(p);
        HP2 = reset_HP(HP2);
        l = float (EXP1) - float (EXP1) * 0.12;
        EXP1 = ceil(l);
        EXP1 = reset_EXP(EXP1);
        q = float (EXP2) - float (EXP2) * 0.12;
        EXP2 = ceil(q);
        EXP2 = reset_EXP(EXP2);
        s = A[m][n];
    }
    else {
        k = float (HP1) + float (HP1) * 0.1;
        HP1 = ceil(k);
        HP1 = reset_HP(HP1);
        p = float (HP2) + float (HP2) * 0.1;
        HP2 = ceil(p);
        HP2 = reset_HP(HP2);
        l = float (EXP1) + float (EXP1) * 0.12;
        EXP1 = ceil(l);
        EXP1 = reset_EXP(EXP1);
        q = float (EXP2) + float (EXP2) * 0.12;
        EXP2 = ceil(q);
        EXP2 = reset_EXP(EXP2);
        s = abs(Max);
    }
    return s;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int k = 0,sci,u = 0,t = 0,r=0;
    char se[1000];
    const char *sei;
    string n = s;
    for ( int i = 0 ; i < 1000 ; i++) {
        if ( email[i] == 64 ) {
            se[i] = '\0';
            break;
        }
        se[i] = email[i];
    }
    string m = se;
    sei = strstr(s,se);
    //a = n.find(m);//Vi tri dau tien se xuat hien trong s
    size_t size = strlen(s);
    for ( int i = 0 ; i < size ; i++){
        if ( s[i] == 64 || s[i] == 35 || s[i] == 37 || s[i] == 36 || s[i] == 33 )
            k = k + 1;
    }
    for ( int i = 0 ; i < size ; i++) {
        if ( (s[i] > 37 && s[i] < 48) || (s[i] > 57 && s[i] < 63) || (s[i] > 90 && s[i] < 97) || (s[i] > 122) ) {
            t = t + 1;
            u = i;
            break;
        }
    }
    for ( int  i = 0 ; i < size ; i++) {
        if ((n[i] == n[i + 1]) && (n[i + 1] == n[i + 2])) {
            r = r + 1;
            sci = i;
            break;
        }
    }
    if (size < 8)
        return -1;
    else
        if (size > 20)
            return -2;
        else
            if ( sei != nullptr) {
                int p = -(300 + (sei - s));
                return p;
            }
            else
                if (r > 0)
                    return -(400 + sci);
                else
                    if (k == 0)
                        return -5;
                    else
                        if (t > 0)
                            return u;
                        else
                            return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    string a[1000];
    int b[1000][2];
    for ( int i = 0 ; i < num_pwds ; i++){
        a[i] = arr_pwds[i];
    }
    for ( int i = 0 ; i < num_pwds ; i++) {
        int s = strlen(arr_pwds[i]);
        b[i][1] = s;
    }
    for ( int i = 0 ; i < num_pwds ; i++){
        int x = 1;
        for ( int k = 0 ; k < num_pwds ; k++){
            if ( (a[i] == a[k]) && (i != k) )
                x = x + 1;
        }
        b[i][0] = x;
    }

    int Xhnn = b[0][0];

    for ( int i = 0 ; i < num_pwds ; i++){
        if ( b[i][0] >= Xhnn)
            Xhnn = b[i][0];
    }

    string pws;
    int g = 0;
    for ( int i = 0 ; i < num_pwds ; i++){
        if ( b[i][0] == Xhnn ){
            pws = a[i];
            for ( int j = 0 ; j < num_pwds; j++){
                if ( b[j][0] == Xhnn && ( i != j)){
                    if (b[j][1] > b[i][1] )
                        pws = a[j];
                }
            }
        }
    }

    for ( int i = 0 ; i < num_pwds ; i++){
        if (a[i] == pws){
            g = i;
            break;
        }
    }


    return g;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////