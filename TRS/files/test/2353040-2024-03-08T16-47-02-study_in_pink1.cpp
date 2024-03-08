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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Truong hp 1
    if(e1 < 0 || e1 > 99) return -99;
    if (exp1 > 600) {
        exp1 = 600;
    } else if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp2 > 600) {
        exp2 = 600;
    } else if (exp2 < 0) {
        exp2 = 0;
    }
    if(e1 < 0) {
      e1 = 0;
    }
    else if(e1 > 99) {
        e1 = 99;        
    }   
    double ex2;
    double ex1;
    int EXP=0;
    if( e1 >= 0 && e1 <= 3) {
        if( e1 == 0) {
            exp2 += 29;
        }
        else if( e1 == 1 ) {
            exp2 += 45;
        }
        else if( e1 == 2 ) {
            exp2 += 75;
        }
        else if( e1 == 3 ) {
            exp2 = exp2 + 29 + 45 + 75;
        }
        int D = e1 * 3 + exp1 * 7;
        if( D % 2 == 0) {
            ex1 =exp1 + (double(D)/200) + 0.999;
            exp1=ex1;
        }
        else {
            ex1 =exp1 - (double(D)/100) + 0.999;
            exp1=ex1;
        }
    }

    // Truong hop 2
    else if ( e1 >= 4 && e1 <= 99 ) {
        if( e1 >= 4 && e1 <= 19 ) {
            ex2 =exp2 + (double(e1)/4 + 19) + 0.999;
            exp2=ex2;
            exp1 -= e1;
        }
        else if( e1 >= 20 && e1 <= 49 ) {
            ex2 = exp2 + (double(e1)/9 + 21) + 0.999;
            exp2=ex2;
            exp1 -= e1;
        }
        else if( e1 >= 50 && e1 <= 65 ) {
            ex2 = exp2 + (double(e1)/16 + 17) + 0.999 ;
            exp2=ex2;
            exp1 -= e1;
        }
        else if( e1 >= 66 && e1 <= 79 ) {
            ex2 =exp2 + (double(e1)/4 + 19) + 0.999;
            exp2=ex2;
            exp1 -= e1;
            if( exp2 > 200) {
                ex2 =exp2 + (double(e1)/9 + 21) + 0.999;
                exp2=ex2;
            }
        }
        else if( e1 >= 80 && e1 <= 99 ) {
            ex2 = exp2 + (double(e1)/4 + 19)  +0.999;
            exp2=ex2;
            ex2 = exp2 +  (double(e1)/9 + 21) +0.999;
            exp2=ex2;
            exp1 -= e1;
            if( exp2 > 400) {
                ex2 = exp2 + (double(e1)/16 + 17) + 0.999;
                exp2=ex2;
                ex2 = (exp2 * 1.15) + 0.999; 
                exp2=ex2;
            }
        }
    }
    if (exp1 > 600) {
        exp1 = 600;
    } else if (exp1 < 0) {
        exp1 = 0;
    }
    if (exp2 > 600) {
        exp2 = 600;
    } else if (exp2 < 0) {
        exp2 = 0;
    }
    
    return exp1+exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //con duong 1
    if(E2< 0 || E2 > 99) return -99;
    //EXP1
    if (EXP1 > 600) {
        EXP1 = 600; 
    } 
    else if (EXP1 < 0) {
        EXP1 = 0;
    }
    //HP1
    if (HP1 > 666) {
        HP1 = 666;
    } 
    else if (HP1 < 0) {
        HP1 = 0;
    }
    //M1
    if (M1 > 3000) {
        M1 = 3000;
    } 
    else if (M1 < 0) {
        M1 = 0;
    }

    int S;
    int squareRoot = static_cast<int>(sqrt(EXP1));
    int smallerSquare = squareRoot * squareRoot;
    int largerSquare = (squareRoot + 1) * (squareRoot + 1);
    if (abs(EXP1 - smallerSquare) <= abs(EXP1 - largerSquare)) {
        S=smallerSquare;
    }
    else {
        S=largerSquare;
    }
    double P1;
    if(EXP1 >= S) {
        P1=1.0;
    }
    else {
        P1=((double)EXP1/(double)S + 80) / 123 ;
    }
    //Con duong 2
    double H1;
    double EX1;
    int pay = 0;
    if (E2 % 2 ==1) {
        double m = 0.5*(double)M1;
        while (pay <= m) {
            if(M1==0) break;
            if(HP1<200) {
                H1 = HP1 * 1.3 + 0.999;
                HP1 = H1;
                M1 -= 150;
                pay += 150;
            }
            else {
                H1 = HP1 * 1.1 + 0.999;
                HP1 = H1;
                M1 -= 70;
                pay += 70;
            } 
            if(HP1 > 666) HP1=666;
            if(pay > m) {
                break;
            }
            if(EXP1<400) {
                M1 -= 200;
                pay += 200;
                EX1 = EXP1 * 1.13 + 0.999;
                EXP1 =EX1;
            }
            else {
                M1 -= 120;
                pay += 120;
                EX1 = EXP1 * 1.13 + 0.999;
                EXP1 =EX1;
            }
            if(EXP1 > 600) EXP1=600;
            if(pay > m) {
                break;
            }
            if(EXP1<300) {
                M1 -= 100;
                pay += 100;
                EX1 = EXP1 * 0.9 + 0.999;
                EXP1 =EX1;
            }
            else {
                M1 -= 120;
                pay += 120;
                EX1 = EXP1 * 0.9 + 0.999;
                EXP1 =EX1;
            }  
            if(EXP1 > 600) EXP1=600;
        }
        H1 = HP1 * 0.83 + 0.999;
        HP1 = H1;
        EX1 = EXP1 * 1.17 + 0.999;
        EXP1 =EX1;
        if(EXP1 > 600) EXP1=600;
        if(HP1 > 666) HP1=666;
        if(M1 < 0) M1=0;
    }
    
    else {
        if(M1 > 0) {
            if(HP1<200) {
                H1 = HP1 * 1.3 + 0.999;
                M1 -= 150;
            }
            else {
                H1 = HP1 * 1.1 + 0.999;
                M1 -= 70; 
            }
            HP1 = H1;
        }
        if(M1<0) M1=0;
        if(HP1 > 666) HP1=666;

        if(M1 >0) {
            if(EXP1<400) {
                M1 -= 200;
            }
            else {
                M1 -= 120;
            }
            EX1 = EXP1 * 1.13 + 0.999;
            EXP1 =EX1;
        }
        if(EXP1 > 600) EXP1=600;
        if(M1<0) M1=0;
    
        if(M1 > 0) {
            if(EXP1<300) {
                M1 -= 100;
            }
            else {
                M1 -= 120;
            }  
            EX1 = EXP1 * 0.9 + 0.999;
            EXP1 = EX1;  
            if(EXP1 > 600) EXP1=600;
        }
        H1 = HP1 * 0.83 + 0.999;
        HP1 = H1;
        EX1 = EXP1 * 1.17 + 0.999;
        EXP1 =EX1;
        if(EXP1 > 600) EXP1=600;
        if(HP1 > 666) HP1=666;
        if(M1 < 0) M1=0;
    }

    squareRoot = static_cast<int>(sqrt(EXP1));
    smallerSquare = squareRoot * squareRoot;
    largerSquare = (squareRoot + 1) * (squareRoot + 1);
    if (abs(EXP1 - smallerSquare) <= abs(EXP1 - largerSquare)) {
        S=smallerSquare;
    }
    else {
        S=largerSquare;
    }
    double P2;
    if(EXP1 >= S) {
        P2=1.0;
    }
    else {
        P2=((double)EXP1/(double)S + 80) / 123 ;
    }
    
    // Con duong 3
    double P3[10];
    P3[0] = 0.32;
    P3[1] = 0.47;
    P3[2] = 0.28;
    P3[3] = 0.79;
    P3[4] = 1;
    P3[5] = 0.5;
    P3[6] = 0.22;
    P3[7] = 0.83;
    P3[8] = 0.64;
    P3[9] = 0.11;
    int i = 0;
    if (E2<10) {
        i=E2;
    }
    else {
        int sum = (E2 / 10) + (E2 % 10);
        i= sum % 10;
    }
    double P;
    P=( P1 + P2 + P3[i]) / 3;
    if (P == 1){
        EX1 = EXP1 * 0.75 + 0.999;
        EXP1 =EX1;
        if (EXP1 > 600) EXP1 = 600; 
    }
    else {
        if(P < 0.5) {
            H1 = HP1 * 0.85 + 0.999;
            EX1 = EXP1 * 1.15 + 0.999;
        }
        else {
            H1 = HP1 * 0.9 + 0.999;
            EX1 = EXP1 * 1.20 + 0.999;
        }
        EXP1 =EX1;
        HP1 = H1;
        if (EXP1 > 600) EXP1 = 600; 
        if (HP1 > 666) HP1 = 666; 

    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3< 0 || E3 > 99) return -99;
    //EXP1
    if (EXP1 > 600) {
        EXP1 = 600;
    } 
    else if (EXP1 < 0) {
        EXP1 = 0;
    }
    //EXP2
    if (EXP2 > 600) {
        EXP2 = 600;
    } 
    else if (EXP2 < 0) {
        EXP2 = 0;
    }
    //HP1
    if (HP1 > 666) {
        HP1 = 666;
    } 
    else if (HP1 < 0) {
        HP1 = 0;
    }
    //HP2
    if (HP2 > 666) {
        HP2 = 666;
    }
    else if (HP2<0) {
        HP2 = 0;
    }

    int M[10][10] = {0};
    int di = 0, dj = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            M[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (M[i][j] > E3 * 2) di++;
            if (M[i][j] < E3 * (-1)) dj++;
        }
    }

    while (di >= 10) {
        di = (di % 10) + (di / 10);
    }
    while (dj >= 10) {
        dj = (dj % 10) + (dj / 10);
    }    
    int TX = M[di][dj], SW = M[di][dj];
    for (int i = 0; i < 10; i++) { 
        if (i + (dj - di) >= 0 && i + (dj - di) < 10) {
            if (M[i][i + (dj - di)] > SW) {
                SW = M[i][i + (dj - di)];
            }
        }
    }

    for (int i = 0; i < 10; i++) { 
        if (dj + (di - i) >= 0 && dj + (di - i) < 10) {
            if (M[i][dj + (di - i)] > SW){ 
                SW = M[i][dj + (di - i)];
            }
        }
    }

    double H1, H2, EX1, EX2;
    if (abs(TX) > abs(SW)) {
        H1 = HP1 * 0.9 + 0.999;
        HP1 = H1;
        H2 = HP2 * 0.9 + 0.999;
        HP2 = H2;
        EX1 = EXP1 * 0.88 + 0.999;
        EXP1 =EX1;
        EX2 = EXP2 * 0.88 + 0.999;
        EXP2 =EX2;
        //EXP1
        if (EXP1 > 600) EXP1 = 600;
        //EXP2
        if (EXP2 > 600) EXP2 = 600;
        //HP1
        if (HP1 > 666) HP1 = 666;
        //HP2
        if (HP2 > 666) HP2 = 666;
        return TX;
    } 
    else {
        H1 = HP1 * 1.10 + 0.999;
        HP1 = H1;
        H2 = HP2 * 1.10 + 0.999;
        HP2 = H2;
        EX1 = EXP1 * 1.12 + 0.999;
        EXP1 =EX1;
        EX2 = EXP2 * 1.12 + 0.999;
        EXP2 =EX2;
        //EXP1
        if (EXP1 > 600) EXP1 = 600;
        //EXP2
        if (EXP2 > 600) EXP2 = 600;
        //HP1
        if (HP1 > 666) HP1 = 666;
        //HP2
        if (HP2 > 666) HP2 = 666;
        return SW;
    }
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int i=0;
    while (email[i] != '@')
    {
        se = se + email[i];
        i++;
    }
    
    
    int sLength = strlen(s);
    if (sLength < 8) return -1; 
    if (sLength > 20) return -2;
    
    
    int sei = 0;
    for (int i = 0; i < sLength; i++) {
        if (s[i] == se[0]) {
            for (int j = 0; j < se.length(); j++) {
                if (s[j + i] == se[j])
                    sei += 1;
            }
            if (sei == se.length())
                return  -(300+i);
        }
    }
    
    
    for (int i = 0; i < sLength - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }


    int cout = 0;
    for (int i = 0; i < sLength; i++) {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!'))
            cout += 1;
    }
    if (cout == 0) return -5;
    
    
    for (int i = 0; i < sLength; i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || 
              (s[i] >= 'A' && s[i] <= 'Z') || 
              (s[i] >= '0' && s[i] <= '9') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            return i; 
        }
    }
    return -10;
} 

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
        int xhMax = 0;
    int STT = 0;
    int xh = 0;
    for (int i=0; i<num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                xh++;
            }
        }
        if (xh > xhMax) {
            xhMax = xh;
            STT=i;
        }
        else if(xh == xhMax && strlen(arr_pwds[i]) > strlen(arr_pwds[STT])) {
            xhMax = xh;
            STT=i;
        }
        xh=0;
    }
    
    return STT;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////