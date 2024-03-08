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

//Additional functions

void checkHP(int& hp) {
    if ( hp < 0 ) hp = 0;
    else if ( hp > 666 ) hp = 666;
}

void checkEXP(int& exp) {
    if ( exp < 0 ) exp = 0;
    else if ( exp > 600 ) exp = 600;
}

void checkM(int& m) {
    if ( m < 0 ) m = 0;
    else if ( m > 3000 ) m = 3000;
}

int divRound(char c, int a, int b) {
    if ( c == '+' && a%b != 0 ) return a/b + 1;
    return a/b;
}

int multiRound(int a, double b) {
    double multi = a*b;
    int res = round(multi);
    if ( multi - res > 0.0000001 ) {
        res++;
    }
    return res;
}




/// Task 1 /////////////////////////////////////////////////////////////////////////////////////
int firstMeet_1(int & exp1, int & exp2, int e1) {
    checkEXP(exp1); checkEXP(exp2);

    if ( e1 == 0 ) {
        exp2 += 29;                                     //TT 1
    }
    else if ( e1 == 1 ) {
        exp2 += 45;                                     //TT 2
    }
    else if ( e1 == 2 ) {
        exp2 += 75;                                     //TT 3
    }
    else {
        exp2 += 149;                                    //TT 4
    }
    checkEXP(exp2);

    int d = e1 * 3 + exp1 * 7;
    if ( d % 2 == 0 ) {
        exp1 += divRound('+',d,200);                   //Tra loi dung
    }
    else {
        exp1 -= divRound('-',d,100);                    //Tra loi sai
    }
    checkEXP(exp1);

    return exp1 + exp2;
}

int firstMeet_2(int& exp1, int& exp2, int e1) {
    checkEXP(exp1); checkEXP(exp2);

    if ( e1 <= 19 ) {
        exp2 += divRound('+',e1,4) + 19;                        //TT 1
    }
    else if ( e1 <= 49 ) {
        exp2 += divRound('+',e1,9) + 21;                        //TT 2
    }
    else if ( e1 <= 65 ) {
        exp2 += divRound('+',e1,16) + 17;                       //TT 3
    }
    else if ( e1 <= 79 ) {
        exp2 += divRound('+',e1,4) + 19;
        if ( exp2 > 200 ) exp2 += divRound('+',e1,9) + 21;      //TT 4
    }
    else {
        exp2 += divRound('+',e1,4) + 19;
        exp2 += divRound('+',e1,9) + 21;
        if ( exp2 > 400 ) {
            exp2 += divRound('+',e1,16) + 17;
            exp2 = multiRound(exp2,1.15);
        }
    }
    checkEXP(exp2);

    exp1 -= e1;
    checkEXP(exp1);

    return exp1 + exp2;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    if ( e1 >= 0 && e1 <= 3 ) return firstMeet_1(exp1,exp2,e1);             //TH 1
    else if ( e1 >= 4 && e1 <= 99 ) return firstMeet_2(exp1,exp2,e1);       //TH 2
    else return -99;                                                        //TH Loi, return -99
}
/// ////////////////////////////////////////////////////////////////////////////////////////////



/// Task 2////////////////////////////////////////////////////////////////////////////////////
double traceLuggage_1(int &hp1, int& exp1, int& m1, int e2) {
    checkEXP(exp1);

    int i = 1;
    while ( (i+1)*(i+1) <= exp1 ) {
        i++;
    }

    if ( exp1 - i*i <= (i+1)*(i+1) - exp1 ) return 100;
    double s = (i+1)*(i+1);
    return (exp1/s + 80.0)/1.23;
}

void eventInTraceLuggage_2(int &hp1, int& exp1, int& m1, int whichEvent) {
    if ( whichEvent == 1 ) {
        if ( hp1 < 200 ) {
            hp1 = multiRound(hp1, 1.3);
            m1 -= 150;
        }
        else {
            hp1 = multiRound(hp1, 1.1);
            m1 -= 70;
        }
    }
    else if ( whichEvent == 2 ) {
        if ( exp1 < 400 ) m1 -= 200;
        else m1 -= 120;

        exp1 = multiRound(exp1,1.13);
    }
    else {
        if ( exp1 < 300 ) m1 -= 100;
        else m1 -= 120;

        exp1 = multiRound(exp1,0.9);
    }

    checkHP(hp1); checkEXP(exp1); checkM(m1);
}

double traceLuggage_2(int &hp1, int& exp1, int& m1, int e2) {
    checkHP(hp1); checkEXP(exp1); checkM(m1);

    if ( e2 % 2 == 0 ) {
        int whichEvent = 1;
        while ( m1 > 0 && whichEvent <= 3 ) {
            eventInTraceLuggage_2(hp1,exp1,m1,whichEvent);
            whichEvent++;
        }
    }
    else {
        int budget = multiRound(m1,0.5), whichEvent = 1;
        while ( m1 >= budget ) {
            eventInTraceLuggage_2(hp1,exp1,m1,(whichEvent-1) % 3 + 1);
            whichEvent++;
        }
    }
    hp1 = multiRound(hp1,0.83);
    exp1 = multiRound(exp1,1.17);

    checkHP(hp1); checkEXP(exp1); checkM(m1);

    return traceLuggage_1(hp1,exp1,m1,e2);
}

double traceLuggage_3(int &hp1, int& exp1, int& m1, int e2) {
    int p[10] = {32,47,28,79,100,50,22,83,64,11};

    if ( e2 / 10 == 0 ) {
        return p[e2];
    }
    return p[(e2/10+e2%10)%10];
}


int traceLuggage(int & hp1, int & exp1, int & m1, int e2) {
    // TODO: Complete this function
    if ( e2 < 0 || e2 > 99 ) {
        return -99;
    }

    double p1 = traceLuggage_1(hp1,exp1,m1,e2);
    double p2 = traceLuggage_2(hp1,exp1,m1,e2);
    double p3 = traceLuggage_3(hp1,exp1,m1,e2);

    if ( p1 == 100 && p2 == 100 && p3 == 100 ) exp1 = multiRound(exp1,0.75);        //Sherlock tinh sai
    else {
        double temp = (p1+p2+p3) / 3;
        if ( temp < 50 ) {
            hp1 = multiRound(hp1,0.85);
            exp1 = multiRound(exp1,1.15);
        }
        else {
            hp1 = multiRound(hp1,0.9);
            exp1 = multiRound(exp1,1.2);
        }
    }

    checkEXP(exp1); checkHP(hp1); checkM(m1);

    return hp1 + exp1 + m1;
}
/// ////////////////////////////////////////////////////////////////////////////////////////



/// Task 3/////////////////////////////////////////////////////////////////////////////////
int chaseTaxi(int & hp1, int & exp1, int & hp2, int & exp2, int e3) {
    // TODO: Complete this function

    if ( e3 >= 0 && e3 <= 99 ) {

        int roadMap[10][10];
        for ( int i = 0; i < 10; i++ ) {
            for ( int j = 0; j < 10; j++ ) {
                roadMap[i][j] = 0;
            }
        }

        int greaterCount = 0, lessCount = 0;
        for ( int i = 0; i < 10; i++ ) {
            for ( int j = 0; j < 10; j++ ) {
                roadMap[i][j] = ( e3 * j + i * 2 ) * ( i - j );
                if ( roadMap[i][j] > e3 * 2 ) {
                    greaterCount++;
                }
                else if ( roadMap[i][j] < -e3 ){
                    lessCount++;
                }
            }
        }

        int iMeet = greaterCount/10 + greaterCount%10; iMeet = iMeet/10 + iMeet%10;
        int jMeet = lessCount/10 + lessCount%10; jMeet = jMeet/10 + jMeet%10;

        int taxiPoint = roadMap[iMeet][jMeet], sherlockPoint = roadMap[iMeet][jMeet];
        for ( int i = 1; i <= 9; i++ ) {

            if ( iMeet - i >= 0 && jMeet - i >= 0 && roadMap[iMeet-i][jMeet-i] > sherlockPoint ) {
                sherlockPoint = roadMap[iMeet-i][jMeet-i];
            }           //Duong cheo trai, phia tren

            if ( iMeet + i <= 9 && jMeet + i <= 9 && roadMap[iMeet+i][jMeet+i] > sherlockPoint ) {
                sherlockPoint = roadMap[iMeet+i][jMeet+i];
            }           // Duong cheo trai, phia duoi

            if ( iMeet - i >= 0 && jMeet + i <= 9 && roadMap[iMeet-i][jMeet+i] > sherlockPoint ) {
                sherlockPoint = roadMap[iMeet-i][jMeet+i];
            }           // Duong cheo phai, phia tren

            if ( iMeet + i <= 9 && jMeet - i >= 0 && roadMap[iMeet+i][jMeet-i] > sherlockPoint ) {
                sherlockPoint = roadMap[iMeet+i][jMeet-i];
            }           // Duong cheo phai, phia duoi

        } sherlockPoint = abs(sherlockPoint);

        checkHP(hp1); checkHP(hp2); checkEXP(exp1); checkEXP(exp2);
        if ( sherlockPoint < abs(taxiPoint) ) {
            hp1 = multiRound(hp1,0.9);
            hp2 = multiRound(hp2,0.9);
            exp1 = multiRound(exp1,0.88);
            exp2 = multiRound(exp2,0.88);
            checkHP(hp1); checkHP(hp2); checkEXP(exp1); checkEXP(exp2);
            return taxiPoint;
        }
        else {
            hp1 = multiRound(hp1,1.1);
            hp2 = multiRound(hp2,1.1);
            exp1 = multiRound(exp1,1.12);
            exp2 = multiRound(exp2,1.12);
            checkHP(hp1); checkHP(hp2); checkEXP(exp1); checkEXP(exp2);
            return sherlockPoint;
        }
    }
    else return -99;
}
/// ///////////////////////////////////////////////////////////////////////////////////////



/// Task 4////////////////////////////////////////////////////////////////////////////////
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    string pass = s;
    string mail = email;
    int i = 0;

    if ( pass.length() < 8 ) return -1;                                 //pass ngan
    if ( pass.length() > 20 ) return -2;                                //pass dai

    {
    string se = "";                                                     //chua se
    while ( i < mail.length() && mail[i] != '@' ) {
        se += mail[i];
        i++;
    }
    if ( se.length() <= pass.length() ) {
        for ( i = 0; i < pass.length() - se.length() + 1; i++ ) {
            bool flagCheck = true; int j = 0;
            while ( j < se.length() && flagCheck ) {
                if ( se[j] != pass[i+j] ) flagCheck = false;
                j++;
            }
            if ( flagCheck ) return -(300+i);
        }
    }
    } //xoa se

    for ( i = 0; i < pass.length() - 2; i++ ) {                             //chua ky tu lien tiep giong nhau
        if ( pass[i] == pass[i+1] && pass[i] == pass[i+2] ) return -(400+i);
    }

    i = 0; bool flagCheck = false;                                          //khong chua ! @ # $ %
    while ( i < pass.length() && !flagCheck ) {
        if ( pass[i] == 33 || (pass[i] >= 35 && pass[i] <= 37) || pass[i] == 64 ) flagCheck = true;
        i++;
    }
    if ( !flagCheck ) return -5;

    for ( i = 0; i < pass.length(); i++ ) {
        bool isNum = (pass[i] >= 48 && pass[i] <= 57);
        bool isLowAlpha = (pass[i] >= 97 && pass[i] <= 122);
        bool isUpAlpha = (pass[i] >= 65 && pass[i] <= 90);
        bool isSpecial = (pass[i] == 33 || (pass[i] >= 35 && pass[i] <= 37) || pass[i] == 64);

        flagCheck = ( isNum || isLowAlpha || isUpAlpha || isSpecial );
        if ( !flagCheck ) return i;
    }

    return -10;

}
/// /////////////////////////////////////////////////////////////////////////////////////



/// Task 5///////////////////////////////////////////////////////////////////////////////
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int numOfPass[50];
    int lengthOfPass[50];
    for ( int i = 0; i < 50; i++ ) {
        numOfPass[i] = 0;
        lengthOfPass[i] = 0;
    }

    int markPass[num_pwds];
    for ( int i = 0; i < num_pwds; i++ ) markPass[i] = 0;

    int k = 1, i = 0;
    bool flagCheck = true;
    while ( flagCheck ) {
        while ( i < num_pwds && markPass[i] != 0 ) i++;

        if ( i == num_pwds ) flagCheck = false;
        else {
            string temp = arr_pwds[i];
            lengthOfPass[k] = temp.length();

            for ( i; i < num_pwds; i++ ) {
                if ( arr_pwds[i] == temp ) {
                    markPass[i] = k;
                    numOfPass[k]++;
                }
            }
            k++; i = 0;
        }
    }
    int maxNum = numOfPass[1];
    for ( i = 0; i < k; i++ ) {
        maxNum = max(maxNum,numOfPass[i]);
    }

    int maxLength = 0, mark = -1;
    for ( i = 0; i < k; i++ ) {
        if ( numOfPass[i] == maxNum && lengthOfPass[i] > maxLength ) {
            maxLength = lengthOfPass[i];
            mark = i;
        }
    }

    int res = 0;
    while ( markPass[res] != mark ) res++;

    return res;
}
/// /////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
