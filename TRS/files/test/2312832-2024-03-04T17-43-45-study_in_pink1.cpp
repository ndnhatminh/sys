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

void checkexp(int& EXP) {
    if (EXP > 600) EXP = 600;
    if (EXP < 0) EXP = 0;
}
void checkhp(int& HP) {
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
}
void checkm(int& M) {
    if (M > 3000) M=3000;
    if (M < 0) M = 0;
}



// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    int D;
    checkexp(EXP1);
    checkexp(EXP2);
    if (E1 < 0 || E1>99) return -99;

    //TRUONG HOP 1 
    if (E1 <= 3 && E1 >= 0) {
        switch (E1) {
        case 0: {
            EXP2 = EXP2 + 29;
            break;
        }
        case 1: {
            EXP2 = EXP2 + 45;
            break;
        }
        case 2: {
            EXP2 = EXP2 + 75;
            break;
        }
        case 3: {
            EXP2 = EXP2 + 29 + 45 + 75;
            break;
        }
        }
        checkexp(EXP2);


        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            if (D % 200 == 0) {
                EXP1 = EXP1 + D / 200;
                checkexp(EXP1);
            }
            else {
                EXP1 = EXP1 + D / 200 + 1;
                checkexp(EXP1);
            }
        }
        else {
            if (D % 100 == 0) {
                EXP1 = EXP1 - D / 100;
                checkexp(EXP1);
            }
            else {
                EXP1 = EXP1 - ceil(D / 100.0)+1 ;
                checkexp(EXP1);
            }
        }
    }

        //TRUONG HOP 2
    if (E1 <= 99 && E1 >= 4) {
        if (E1 <= 19 && E1 >= 4) {
            if (E1 % 4 == 0) {
                EXP2 = EXP2 + E1 / 4 + 19;
                checkexp(EXP2);
            }
            else {
                EXP2 = EXP2 + E1 / 4 + 20;
                checkexp(EXP2);
            }
        }

        if (E1 >= 20 && E1 <= 49) {
            if (E1 % 9 == 0) {
                EXP2 = EXP2 + E1 / 9 + 21;
                checkexp(EXP2);
            }
            else {
                EXP2 = EXP2 + E1 / 9 + 22;
                checkexp(EXP2);
            }
        }

        if (E1 >= 50 && E1 <= 65) {
            if (E1 % 16 == 0) {
                EXP2 = EXP2 + E1 / 16 + 17;
                checkexp(EXP2);
            }
            else {
                EXP2 = EXP2 + E1 / 16 + 18;
                checkexp(EXP2);
            }
        }

        if (E1 >= 66 && E1 <= 79) {
            if (E1 % 4 == 0) {
                EXP2 = EXP2 + E1 / 4 + 19;
                checkexp(EXP2);
            }
            else {
                EXP2 = EXP2 + E1 / 4 + 20;
                checkexp(EXP2);
            }
            if (EXP2 > 200) {
                if (E1 % 9 == 0) {
                    EXP2 = EXP2 + E1 / 9 + 21;
                    checkexp(EXP2);
                }
                else {
                    EXP2 = EXP2 + E1 / 9 + 22;
                    checkexp(EXP2);
                }
            }
        }

        if (E1 >= 80 && E1 <= 99) {
            if (E1 % 4 == 0) {
                EXP2 = EXP2 + E1 / 4 + 19;
                checkexp(EXP2);
            }
            else {
                EXP2 = EXP2 + E1 / 4 + 20;
                checkexp(EXP2);
            }
            if (E1 % 9 == 0) {
                EXP2 = EXP2 + E1 / 9 + 21;
                checkexp(EXP2);
            }
            else {
                EXP2 = EXP2 + E1 / 9 + 22;
                checkexp(EXP2);
            }
            if (EXP2 > 400) {
                if (E1 % 16 == 0) {
                    EXP2 = EXP2 + E1 / 16 + 17;
                    checkexp(EXP2);
                }
                else {
                    EXP2 = EXP2 + E1 / 16 + 18;
                    checkexp(EXP2);
                }
                if (EXP2 % 100 == 0) {
                    EXP2 = EXP2 * 1.15;
                    checkexp(EXP2);
                }
                else {
                    EXP2 = EXP2 * 1.15 + 1;
                    checkexp(EXP2);
                }
            }
        }
        EXP1 = EXP1 - E1;
        checkexp(EXP1);
    }
    

    return EXP1 + EXP2;   
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    float P1, p1, P2, p2, P3, P, X1, X2, Y1, Y2;
    int S1, S2, N, a;
    checkexp(EXP1);
    checkhp(HP1);
    checkm(M1);
    if (E2 < 0 || E2>99) return -99;


    //CON DUONG 1----------------------------
    for (int i = 1; i < EXP1 / 2; ++i) {
        int b;
        X1 = EXP1 - i;
        Y1 = EXP1 + i;
        for (int j = 1; j < EXP1 / 2; ++j) {
            if (j * j == X1 || j * j == Y1) {
                S1 = j * j;
                b = 1;
                break;
            }
        }
        if (b == 1) break;
    }
    if (EXP1 > S1) P1 = 1;
    else {
        p1 = 1.0 * EXP1 / S1;
        P1 = (p1 + 80.00) / 123.00;
    }


    //CON DUONG 2----------------------------
     N = M1 / 2 + 0.99;


    if (E2 % 2 == 0) {
        if (M1 > 0) {
            if (HP1 < 200) {
               
                HP1 = HP1 * 1.3 + 0.99;
                M1 = M1 - 150;
                checkm(M1);
            }
            else {
                
                HP1 = HP1 * 1.1 + 0.99;
                M1 = M1 - 70;
                checkhp(HP1);
                checkm(M1);
            }

            if (M1 > 0) {
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    checkm(M1);
                }
                else {
                    M1 = M1 - 120;
                    checkm(M1);
                }
                
                EXP1 = EXP1 * 1.13 + 0.99;
                checkexp(EXP1);
                
            }

            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    checkm(M1);
                }
                else {
                    M1 = M1 - 120;
                    checkm(M1);
                }
                EXP1 = EXP1 * 0.9 + 0.99;
                
            }
        }
       
        EXP1 = EXP1 * 1.17 + 0.99;
        checkexp(EXP1);
        
        
        if (HP1 % 100 == 0) {
            HP1 = HP1 - HP1 * 0.17;
        }
        else {
            HP1 = HP1 - ceil(HP1 * 0.17) + 1;
        }
    }


    if (E2 % 2 != 0) {
        if (M1 > 0) {
            while (N >= 0) {
                if (HP1 < 200) {
                    if (HP1 % 10 == 0) {
                        HP1 = HP1 * 1.3;
                        M1 = M1 - 150;
                        N = N - 150;
                    }
                    else {
                        HP1 = HP1 * 1.3 + 1;
                        M1 = M1 - 150;
                        N = N - 150;
                    }
                }
                else {
                    if (HP1 % 10 == 0) {
                        HP1 = HP1 * 1.1;
                        M1 = M1 - 70;
                        N = N - 70;
                        checkhp(HP1);
                    }
                    else {
                        HP1 = HP1 * 1.1 + 1;
                        M1 = M1 - 70;
                        N = N - 70;
                        checkhp(HP1);
                    }
                }
                if (N < 0) break;

                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    N = N - 200;
                    checkm(M1);
                }
                else {
                    M1 = M1 - 120;
                    N = N - 120;
                    checkm(M1);
                }
               
                EXP1 = EXP1 * 1.13 + 0.99;
                checkexp(EXP1);
               
                
                if (N < 0) break;

                if (EXP1 < 300) {
                    M1 = M1 - 100;
                    N = N - 100;
                    checkm(M1);
                }
                else {
                    M1 = M1 - 120;
                    N = N - 120;
                    checkm(M1);
                }
                EXP1 = EXP1 * 0.9 + 0.99;
            }

           
            EXP1 = EXP1 * 1.17 + 0.99;
            checkexp(EXP1);
            
            
            if (HP1 % 100 == 0) {
                HP1 = HP1 - HP1 * 0.17;
            }
            else {
                HP1 = HP1 - ceil(HP1 * 0.17) + 1;
            }
        }
        else {
            
            EXP1 = EXP1 * 1.17 + 0.99;
            checkexp(EXP1);
            
           
            if (HP1 % 100 == 0) {
                HP1 = HP1 - HP1 * 0.17;
            }
            else {
                HP1 = HP1 - ceil(HP1 * 0.17) + 1;
            }
        }
    }

    for (int i = 1; i < EXP1 / 2; ++i) {
        int b;
        X2 = EXP1 - i;
        Y2 = EXP1 + i;
        for (int j = 1; j < EXP1 / 2; ++j) {
            if (j * j == X2 || j * j == Y2) {
                S2 = j * j;
                b = 1;
                break;
            }
        }
        if (b == 1) break;
    }
    if (EXP1 > S2) P2 = 1;
    else {
        p2 = 1.0 * EXP1 / S2;
        P2 = (p2 + 80) / 123;
    }



    //CON DUONG 3--------------------
    float p[10] = { 32,47,28,79,100,50,22,83,64,11 };


    if (E2 < 10 && E2 >= 0) {
        P3 = p[E2];
    }
    else {
        if (E2 >= 10 && E2 <= 99) {
            a = (E2 / 10 + E2 % 10) % 10;
            P3 = p[a] / 100;
        }
    }


    if (P1 == P2 == P3 == 1) {
        EXP1 = EXP1 * 0.75 + 0.99;
        
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            
            HP1 = HP1 - HP1 * 0.15 + 0.99;
            EXP1 = EXP1 * 1.15 + 0.99;
            checkexp(EXP1);
            
        }
        else {
           
            HP1 = HP1 - HP1 * 0.1 + 0.99;
            EXP1 = EXP1 * 1.2 + 0.99;
            checkexp(EXP1);
                
        }
    }



    return HP1 + EXP1 + M1;
}





// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int dem1, dem2, Nt, Ns, re;
    dem1 = 0;
    dem2 = 0;
    int p[10][10];
    checkexp(EXP1);
    checkexp(EXP2);
    checkhp(HP1);
    checkhp(HP2);
    if (E3 < 0 || E3>99) return -99;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            p[i][j] = ((E3 * j) + (i * 2)) *(i - j);
        }
    }
     
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (p[i][j] != 0 && p[i][j] > (E3 * 2)) {
                dem1 = dem1 + 1;
            }
            if (p[i][j] != 0 && p[i][j] < (-E3)) {
                dem2 = dem2 + 1;
            }
        }
    }

    while (dem1 >= 10) {
        dem1 = dem1 / 10 + dem1 % 10;
    }

    while (dem2 >= 10) {
        dem2 = dem2 / 10 + dem2 % 10;
    }

    Nt = p[dem1][dem2];
    Ns = Nt;

    
    
    for (int i=1;i<=9;++i){

        if ((dem1 + i) <= 9 && (dem2 + i) <= 9) {
            if (p[dem1 + i][dem2 + i] > Ns) Ns = p[dem1 + i][dem2 + i];
        }
        
        if ((dem1 - i) >= 0 && (dem2 - i) >= 0) {
            if (p[dem1 - i][dem2 - i] > Ns) Ns = p[dem1 - i][dem2 - i];
        }

        if ((dem1 - i) >= 0 && (dem2 + i) <= 9) {
            if (p[dem1 - i][dem2 + i] > Ns) Ns = p[dem1 - i][dem2 + i];
        }

        if ((dem1 + i) <= 9 && (dem2 - i) >= 0) {
            if (p[dem1 + i][dem2 - i] > Ns) Ns = p[dem1 + i][dem2 - i];
        }
        
    }

    if (abs(Nt) > abs(Ns)) {
        if (EXP1 % 25 == 0) EXP1 = EXP1 * 0.88;
        else EXP1 = EXP1 * 0.88 + 1;
        if (EXP2 % 25 == 0) EXP2 = EXP2 * 0.88;
        else EXP2 = EXP2 * 0.88 + 1;
        if (HP1 % 10 == 0) HP1 = HP1 * 0.9;
        else HP1 = HP1 * 0.9 + 1;
        if (HP2 % 10 == 0) HP2 = HP2 * 0.9;
        else HP2 = HP2 * 0.9 + 1;
        re = Nt;
    }
    else {
        if (EXP1 % 25 == 0) EXP1 = EXP1 * 1.12;
        else EXP1 = EXP1 * 1.12 + 1;
        if (EXP2 % 25 == 0) EXP2 = EXP2 * 1.12;
        else EXP2 = EXP2 * 1.12 + 1;
        if (HP1 % 10 == 0) HP1 = HP1 * 1.1;
        else HP1 = HP1 * 1.1 + 1;
        if (HP2 % 10 == 0) HP2 = HP2 * 1.1;
        else HP2 = HP2 * 1.1 + 1;
        re = Ns;
    }
    checkexp(EXP1);
    checkexp(EXP2);
    checkhp(HP1);
    checkhp(HP2);

    return re;
}




// Task 4
bool recases(char a) {
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '!' || a == '@' || a == '#' || a == '$' || a == '%');
}
int checkPassword(const char* s, const char* email) {
    string pwds(s), e(email);
    string se;
    char spc[] = { '@', '#', '%', '$', '!' };
    int sei,a;
  

  
    if (pwds.length() < 8) return -1;
    if (pwds.length() > 20) return -2;

    
    se = e.substr(0, e.find('@'));
    sei = pwds.find(se);
    if (sei >=0) return -(300 + sei);
    

   
    int i = 0; 
    while (i < pwds.length()) {
        if (pwds[i] == pwds[i - 1] == pwds[i - 2]) return -(400 + i - 2);
        i++;
    }

    int n = 0;
    for (int i = 0; i < pwds.length(); i++) {
        for (int j = 0; j <= 4; j++) if (pwds[i] == spc[j]) n++;
    }
    if (n == 0) return -5;

    for (int i = 0; i < pwds.length(); ++i) {
        if (!recases(pwds[i])) return i;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxcnt = 0;
    int maxlen = 0;
    int point;

    for (int i = 0; i < num_pwds; ++i) {
        string pwds = arr_pwds[i];
        int cnt = 0;
        int len = pwds.length();
        for (int j = 0; j < num_pwds; ++j) {
            if (pwds == arr_pwds[j]) cnt = cnt + 1;
        }
        if (cnt > maxcnt || (cnt == maxcnt && len > maxlen)) {
            maxcnt = cnt;
            maxlen = len;
            point = i;
        }
    }


    return point;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////