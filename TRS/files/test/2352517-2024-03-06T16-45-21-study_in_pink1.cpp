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
//ham lam tron len
int lamtronlen(float x) {
    int y;
    y = x + 0.999;
    return y;
}
//ham kiem tra
int kiemtraHP(int x) {
    if (x < 0) {
        return 0;
    }
    else if (x > 666) {
        return 666;
    }
    else {
        return x;
    }
}
int kiemtraEXP(int x) {
    if (x < 0) {
        return 0;
    }
    else if (x > 600) {
        return 600;
    }
    else {
        return x;
    }
}
int kiemtraM(int x) {
    if (x < 0) {
        return 0;
    }
    else if (x > 3000) {
        return 3000;
    }
    else {
        return x;
    }
}
int combine(int x) {
    int alpha, beta, rs;
    alpha = x % 10;
    beta = (x - alpha) / 10;
    rs = alpha + beta;
    return rs;
}
int anuong(int& HP1, int& M1) {
    float sub = 0;
    if (HP1 < 200) {
        sub = HP1;
        sub = sub * 1.3;
        HP1 = lamtronlen(sub);
        M1 = M1 - 150;
        return 150;
    }
    else {
        sub = HP1;
        sub = sub * 1.1;
        HP1 = lamtronlen(sub);
        M1 = M1 - 70;
        return 70;
    }

}
int dixe(int& M1, int& EXP1) {
    float sub = 0;
    if (EXP1 < 400) {
        M1 = M1 - 200;
        sub = EXP1;
        sub = sub * 1.13;
        EXP1 = lamtronlen(sub);
        return 200;
    }
    else {
        M1 = M1 - 120;
        sub = EXP1;
        sub = sub * 1.13;
        EXP1 = lamtronlen(sub);
        return 120;
    }
}
int chotien(int& M1, int& EXP1) {
    float sub = 0;
    if (EXP1 < 300) {
        M1 = M1 - 100;
        sub = EXP1;
        sub = sub * 0.9;
        EXP1 = lamtronlen(sub);
        return 100;
    }
    else {
        M1 = M1 - 120;
        sub = EXP1;
        sub = sub * 0.9;
        EXP1 = lamtronlen(sub);
        return 120;
    }
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    int check = 0, D=0;
    float sub=0, subE1, subD;
    subE1 = E1;
    

    if (E1 < 0 || E1 >99) {
        return -99;
    }
    else {
        EXP1 = kiemtraEXP(EXP1);
        EXP2 = kiemtraEXP(EXP2);
        if (E1 < 4) {
            if (E1 == 0) {
                EXP2 = EXP2 + 29;
                EXP2 = kiemtraEXP(EXP2);
            }
            else if (E1 == 1) {
                
                EXP2 = EXP2 + 45;
                EXP2 = kiemtraEXP(EXP2);
            }
            else if (E1 == 2) { 
                
                EXP2 = EXP2 + 75;
                EXP2 = kiemtraEXP(EXP2);
            }
            else if (E1 == 3) {
               
                EXP2 = EXP2 + 29 + 45 + 75;
                EXP2 = kiemtraEXP(EXP2);
            }
            D = (E1 * 3) + (EXP1 * 7);
            if (D % 2 == 0) {
                sub = EXP1;
                subD = D;
                sub = sub + (subD / 200);
                EXP1 = lamtronlen(sub);
                EXP1 = kiemtraEXP(EXP1);
            }
            else {
                sub = EXP1;
                subD = D;
                sub = sub - (subD / 100);
                EXP1 = lamtronlen(sub);
                EXP1 = kiemtraEXP(EXP1);
            }
        }
        else {
            if (E1 < 20) {
                sub = EXP2;
                sub = sub + ((subE1 / 4) + 19);
               
                EXP2 = lamtronlen(sub);
                EXP2 = kiemtraEXP(EXP2);
                //1
            }
            else if (E1 < 50) {
                sub = EXP2;
                sub = sub + ((subE1 / 9) + 21);
                EXP2 = lamtronlen(sub);
                EXP2 = kiemtraEXP(EXP2);
                //2
            }
            else if (E1 < 66) {
                sub = EXP2;
                sub = sub + ((subE1 / 16) + 17);
                EXP2 = lamtronlen(sub);
                EXP2 = kiemtraEXP(EXP2);
                //3
            }
            else if (E1 < 80) {
                sub = EXP2;
                sub = sub + ((subE1 / 4) + 19);
                EXP2 = lamtronlen(sub);
                EXP2 = kiemtraEXP(EXP2);
                if (EXP2 > 200) {
                    sub = EXP2;
                    sub = sub + ((subE1 / 9) + 21);
                    EXP2 = lamtronlen(sub);
                    EXP2 = kiemtraEXP(EXP2);
                }
            }
            else if (E1 < 100) {
                sub = EXP2;
                sub = sub + ((subE1 / 4) + 19);
                EXP2 = lamtronlen(sub);
                EXP2 = kiemtraEXP(EXP2);
                sub = EXP2;
                sub = sub + ((subE1 / 9) + 21);
                EXP2 = lamtronlen(sub);
                EXP2 = kiemtraEXP(EXP2);
                if (EXP2 > 400) {
                    sub = EXP2;
                    sub = EXP2 + ((subE1 / 16) + 17);
                    EXP2 = lamtronlen(sub);
                    EXP2 = kiemtraEXP(EXP2);
                    check = 3;
                }
            }
            if (check == 3) {
                sub = EXP2;
               sub = sub * 1.15;
               EXP2 = lamtronlen(sub);
               EXP2 = kiemtraEXP(EXP2);
            }
            
            EXP1 = EXP1 - E1;
            EXP1 = kiemtraEXP(EXP1);
        }
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
   
    if (E2 < 0 || E2 >99) {
        return -99;
    }
    else {
        EXP1 = kiemtraEXP(EXP1);
        HP1 = kiemtraHP(HP1);
        M1 = kiemtraM(M1);
        int check = 0, a = 0, b = 0, c = 0, tieu = 0, noti = 1;
        float S1 = 0, P1 = 0, P2 = 0, P3 = 0, S2 = 0, S = 0, sub = 0, ave = 0, test = 0;
        sub = EXP1;
        S1 = sqrt(sub);
        S2 = round(S1);
        S = pow(S2, 2);
        //Road 1
        if (sub < S) {

            P1 = ((sub / S) + 80) / 123;
        }
        else {
            P1 = 1;
        }
        //Road 2
        test = M1;
        test = test * 0.5;
        check = test;
        if (E2 % 2 == 0) {
            if (M1 > 0) {
                a = anuong(HP1, M1);
                HP1 = kiemtraHP(HP1);
                M1 = kiemtraM(M1);
                noti = 0;

                if (M1 > 0) {

                    b = dixe(M1, EXP1);
                    noti = 0;
                    M1 = kiemtraM(M1);
                    EXP1 = kiemtraEXP(EXP1);

                    if (M1 > 0) {

                        c = chotien(M1, EXP1);
                        noti = 1;
                        M1 = kiemtraM(M1);
                        EXP1 = kiemtraEXP(EXP1);
                    }
                    else {
                        noti = 1;
                    }

                }
                else {
                    noti = 1;
                }
            }
            else {
                noti = 1;
            }
        }
        else if (E2 == 0) {
            noti = 1;
        }
        else {
            while ((tieu < check || tieu == check) && M1 > 0) {
                if (tieu < check || tieu == check) {

                    a = anuong(HP1, M1);
                    tieu = tieu + a;

                    HP1 = kiemtraHP(HP1);
                    M1 = kiemtraM(M1);

                    if (tieu < check || tieu == check) {

                        b = dixe(M1, EXP1);
                        tieu = tieu + b;

                        EXP1 = kiemtraEXP(EXP1);
                        M1 = kiemtraM(M1);


                        if (tieu < check || tieu == check) {

                            c = chotien(M1, EXP1);
                            tieu = tieu + c;

                            EXP1 = kiemtraEXP(EXP1);
                            M1 = kiemtraM(M1);

                        }
                        else {
                            noti = 1;
                        }
                    }
                    else {
                        noti = 1;
                    }
                }
                else {
                    noti = 1;
                }
            }
            noti = 1;
        }
        if (noti == 1) {
            sub = HP1;
            sub = sub * 0.83;
            HP1 = lamtronlen(sub);
            HP1 = kiemtraHP(HP1);
            sub = EXP1;
            sub = sub * 1.17;
            EXP1 = lamtronlen(sub);
            EXP1 = kiemtraEXP(EXP1);
        }
        sub = EXP1;
        S1 = sqrt(sub);
        S2 = round(S1);
        S = pow(S2, 2);

        if (sub < S) {
            P2 = ((sub / S) + 80) / 123;
        }
        else {
            P2 = 1;
        }
        //Road 3
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int Bri = 0, Cal = 0, Culate = 0;
        if (E2 < 10) {
            Bri = E2;
        }
        else {
            Cal = E2 % 10;
            Culate = (E2 - Cal) / 10;
            Bri = Cal + Culate;
            if (Bri > 9) {
                Bri = Bri % 10;
            }
        }
        P3 = P[Bri];
        P3 = P3 / 100;
        if (P1 == 1 && P2 == 1 && P3 == 1) {
            sub = EXP1;
            sub = sub * 0.75;
            EXP1 = lamtronlen(sub);
            EXP1 = kiemtraEXP(EXP1);
        }
        else {
            ave = (P1 + P2 + P3) / 3;
            if (ave < 0.5) {
                sub = HP1;
                sub = sub * 0.85;
                HP1 = lamtronlen(sub);
                HP1 = kiemtraHP(HP1);
                sub = EXP1;
                sub = sub * 1.15;
                EXP1 = lamtronlen(sub);
                EXP1 = kiemtraEXP(EXP1);

            }
            else {
                sub = HP1;
                sub = sub * 0.9;
                HP1 = lamtronlen(sub);
                HP1 = kiemtraHP(HP1);
                sub = EXP1;
                sub = sub * 1.2;
                EXP1 = lamtronlen(sub);
                EXP1 = kiemtraEXP(EXP1);//29

            }

        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    else {
        HP1 = kiemtraHP(HP1);
        EXP1 = kiemtraEXP(EXP1);
        HP2 = kiemtraHP(HP2);
        EXP2 = kiemtraEXP(EXP2);
        int Number[10][10];
        int i, j, count = 0, check = 0, checkp = 0, checkne = 0, checkvalp, checkvalne, meet = -99999, j1, i1, Sherlock;
        float sub;
        checkvalp = 2 * E3;
        checkvalne = -E3;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                count = i * 10 + j;
                Number[i][j] = ((E3 * j) + (i * 2)) * (i - j);

                if (Number[i][j] > checkvalp) {
                    checkp++;
                }
                else if (Number[i][j] < checkvalne) {
                    checkne++;
                }
            }

        }
        while (checkp > 9) {
            checkp = combine(checkp);
        }
        while (checkne > 9) {
            checkne = combine(checkne);
        }

        i1 = checkp;
        j1 = checkne;
        //cheo trai di xuong
        while (i1 < 10) {
            if (j1 < 10) {
                if (Number[i1][j1] > meet) {
                    meet = Number[i1][j1];
                }
            }
            i1++;
            j1++;
        }

        //cheo phai di xuong
        i1 = checkp;
        j1 = checkne;
        while (i1 < 10) {
            if (j1 >= 0) {
                if (Number[i1][j1] > meet) {
                    meet = Number[i1][j1];
                }
            }
            i1++;
            j1--;
        }
        //cheo trai di len
        i1 = checkp;
        j1 = checkne;
        while (i1 >= 0) {
            if (j1 >= 0) {
                if (Number[i1][j1] > meet) {
                    meet = Number[i1][j1];
                }
            }
            i1--;
            j1--;

        }

        //cheo phai di len
        i1 = checkp;
        j1 = checkne;
        while (i1 >= 0) {
            if (j1 < 10) {
                if (Number[i1][j1] > meet) {
                    meet = Number[i1][j1];
                }
            }
            i1--;
            j1++;

        }
        Sherlock = Number[checkp][checkne];
        sub = abs(Sherlock);

        if (sub > meet) {
            sub = EXP1;
            sub = sub * 0.88;
            EXP1 = lamtronlen(sub);
            EXP1 = kiemtraEXP(EXP1);
            sub = EXP2;
            sub = sub * 0.88;
            EXP2 = lamtronlen(sub);
            EXP2 = kiemtraEXP(EXP2);
            sub = HP1;
            sub = sub * 0.9;
            HP1 = lamtronlen(sub);
            HP1 = kiemtraHP(HP1);
            sub = HP2;
            sub = sub * 0.9;
            HP2 = lamtronlen(sub);
            HP2 = kiemtraHP(HP2);
            
            return Sherlock;

        }
        else {
            sub = EXP1;
            sub = sub * 1.12;
            EXP1 = lamtronlen(sub);
            EXP1 = kiemtraEXP(EXP1);
            sub = EXP2;
            sub = sub * 1.12;
            EXP2 = lamtronlen(sub);
            EXP2 = kiemtraEXP(EXP2);
            sub = HP1;
            sub = sub * 1.1;
            HP1 = lamtronlen(sub);
            HP1 = kiemtraHP(HP1);
            sub = HP2;
            sub = sub * 1.1;
            HP2 = lamtronlen(sub);
            HP2 = kiemtraHP(HP2);
            
            return meet;
        }

    }
        
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    string subse;
    string hehe;
    int read, dodai, check, i, j, rap, lmao = 0, acong = 0, final = 0;
    check = 0;
    read = strlen(email);
    dodai = strlen(s);
    for (int i = 0; i < read; i++) {
        if (email[i] == '@') {
            acong = i;
        }
    }
    for (int i = 0; i < acong; i++) {
        se = se + email[i];
    }
    for (i = 0; i < dodai; i++) {
        hehe = hehe + s[i];
    }

    rap = se.length();
   
    //kiem tra do dai
    if (dodai < 8) {
        return -1;
    }
    else if (dodai > 20) {
        return -2;
    }
    //kiem tra se
    for (i = 0; i < dodai; i++) {
        subse = hehe.substr(i, rap);

        if (subse == se) {
            return -(300 + i);
        }

    }
    //trung hon 2 ky tu
    for (i = 0; i < dodai; i++) {
        if (s[i] == s[i + 1]) {
            if (s[i + 1] == s[i + 2]) {
                return -(400 + i);
            }
        }
    }
    //ky tu dac biet


    for (i = 0; i < dodai; i++) {
        if (hehe[i] == '@' || hehe[i] == '#' || hehe[i] == '$' || hehe[i] == '!' || hehe[i] == '%') {
            lmao++;
        }
    }
    if (lmao == 0) {
        return -5;
    }
    for (int i = 0; i < dodai; i++) {
        if (hehe[i] != '@' && hehe[i] != '#' && hehe[i] != '%' && hehe[i] != '$' && hehe[i] != '!') {
            if (hehe[i] < '0' || hehe[i]>'9' && hehe[i] < 'A' || hehe[i]>'Z' && hehe[i] < 'a' || hehe[i] >'z') {
                return i;
            }
        }
    }
   





    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string hihi;
    int check = 0, poit = 0, tee = 0, achu = 0, athu = 0;
    //poit: so lan lap nhieu nhat
    for (int i = 0; i < num_pwds; i++) {
        hihi = arr_pwds[i];
        for (int j = i; j < num_pwds; j++) {
            if (hihi == arr_pwds[j]) {
                check++;
            }
        }
        if (check >= poit) {
            poit = check;
            tee = i;
        }
        check = 0;
        hihi.erase(0);
    }
    check = 0;
    for (int i = 0; i < num_pwds; i++) {
        hihi = arr_pwds[i];
        for (int j = i; j < num_pwds; j++) {
            if (hihi == arr_pwds[j]) {
                check++;
            }
        }

        if (check == poit) {
            athu = hihi.length();
            if (athu > achu) {
                achu = athu;
                tee = i;
            }
        }
        check = 0;
        hihi.erase(0);
    }


    return tee;


}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

