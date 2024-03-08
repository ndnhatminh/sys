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

void checkHP(int & HP) {
    if (HP > 666) HP=666; 
        else if (HP < 0) HP=0;
}

void checkEXP(int & EXP) {
    if (EXP > 600) EXP=600; 
        else if (EXP < 0) EXP=0;
}

void checkM(int & M) {
    if (M > 3000) M=3000; 
        else if (M < 0) M=0;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {

    if (E1 < 0 || E1 > 99) return -99;

    if (E1 >= 0 && E1 <= 3) {       
        if (E1 == 0) EXP2 += 29;
            else if (E1 == 1) EXP2 += 45;
            else if (E1 == 2) EXP2 += 75;
            else EXP2 += (29+45+75);
            checkEXP(EXP2);
            int D;
            D = E1*3 + EXP1*7;
            if (D%2) {
                EXP1 -= floor((D/100.0));
            }   
                else EXP1 += ceilff((D/200.0));
            checkEXP(EXP1);
    }   
    else {
        if (E1 >= 4 && E1 <= 19) EXP2 += ceilf((E1 / 4.0) + 19);
        else if (E1 >= 20 && E1 <= 49) EXP2 += ceilf((E1 / 9.0) + 21);
        else if (E1 >= 50 && E1 <= 65) EXP2 += ceilf((E1 / 16.0) + 17);
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += ceilf((E1 / 4.0) + 19);checkEXP(EXP2);
            if (EXP2 > 200) EXP2 += ceilf((E1 / 9.0) + 21);
        }
        else {
            EXP2 += ceilf((E1 / 4.0) + 19);checkEXP(EXP2);
            EXP2 += ceilf((E1 / 9.0) + 21);checkEXP(EXP2);
            if (EXP2 > 400) {
                EXP2 += ceilf((E1 / 16.0) + 17);checkEXP(EXP2);
                EXP2 = static_cast<int>(ceilf(static_cast<double>(EXP2)*1.15));
            }
        }
        EXP1 -= E1;
    }
    checkEXP(EXP1);checkEXP(EXP2);
    return (EXP1 + EXP2);
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 <0 || E2 > 99) return -99;

    //ConDuong1
    int Smax, Smin,S,P3;
    double P1,P2,Ptb,halfM,Mspent;

    halfM = M1/2.0;
    Mspent =0;

    Smax = pow((floor(sqrt(EXP1)) + 1), 2);
    Smin = pow(floor(sqrt(EXP1)), 2);
    if ((Smax - EXP1) < (EXP1 -Smin)) S = Smax; else S = Smin;
    if (EXP1 >= S) P1 = 100; 
        else P1 = (((EXP1*1.0/S) + 80)/123)*100;

    //ConDuong2   
    if (E2%2) { //E2 le
        while(Mspent < halfM) { 
            if (M1 > 0) {   //sk1
            if (HP1 < 200) {
                HP1 = ceilf(HP1*13.0/10);
                M1 -= 150; Mspent += 150;
            } else {
                HP1 = ceilf(HP1*11.0/10);
                M1 -= 70; Mspent += 70;
            }  
            checkHP(HP1);checkM(M1);         
        }           
            if (Mspent > halfM) break;if (M1 <= 0) break;
        
        if (M1 > 0) {   //sk2
            if (EXP1 < 400) {M1 -= 200; Mspent += 200;} else {M1 -= 120; Mspent += 120;}
            EXP1 = ceilf(EXP1*113.0/100);
            checkEXP(EXP1);checkM(M1);
        }   
            if (Mspent > halfM) break;if (M1 <= 0) break;
        if (M1 > 0) {   //sk3
            if (EXP1 < 300) {M1 -= 100; Mspent += 100;} else {M1 -= 120; Mspent += 120;}
            EXP1 = ceilf(EXP1*9.0/10);
            checkEXP(EXP1);checkM(M1);
        }
            if (Mspent > halfM) break;if (M1 <= 0) break;
        }
        HP1 = ceilf(HP1*83.0/100);
        EXP1 = ceilf(EXP1*117.0/100);
        checkHP(HP1);checkEXP(EXP1);checkM(M1);
    }
    else {  //E2 chan
        if (M1 > 0) {   //sk1
            if (HP1 < 200) {
                HP1 = ceilf(HP1*13.0/10);
                M1 -= 150;
            } else {
                HP1 = ceilf(HP1*11.0/10);
                M1 -= 70;
            }
            checkHP(HP1);checkM(M1);
        }
        if (M1 > 0) {   //sk2
            if (EXP1 < 400) M1 -= 200; else M1 -= 120;
            EXP1 = ceilf(EXP1*113.0/100);  
            checkEXP(EXP1);checkM(M1);
        }
        if (M1 > 0) {   //sk3
            if (EXP1 < 300) M1 -= 100; else M1 -= 120;
            EXP1 = ceilf(EXP1*9.0/10);   
            checkEXP(EXP1);checkM(M1);
        }
        HP1 = ceilf(HP1*83.0/100);
        EXP1 = ceilf(EXP1*117.0/100);
        checkHP(HP1);checkEXP(EXP1);checkM(M1);
    }
    Smax = pow((floor(sqrt(EXP1)) + 1), 2);
    Smin = pow(floor(sqrt(EXP1)), 2);
    if ((Smax - EXP1) < (EXP1 - Smin)) S = Smax; else S = Smin;
    if (EXP1 >= S) P2 = 100; 
        else P2 = (((EXP1*1.0/S) + 80)/123)*100;
    //ConDuong3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    if (E2 < 10) P3=P[E2];
        else {
            int E2temp;
            E2temp = ((E2/10+E2%10)%10);
            P3=P[E2temp];
        }
    Ptb=(P1+P2+P3)/3.0;
    if (Ptb == 100) EXP1 = ceilf(EXP1*75.0/100);
        else {
            if (Ptb < 50) {
                HP1 = ceilf(HP1*85.0/100);
                EXP1 = ceilf(EXP1*115.0/100);
            } else {
                HP1 = ceilf(HP1*9.0/10);
                EXP1 = ceilf(EXP1*12.0/10);
            }
        }
    checkEXP(EXP1);checkHP(HP1);
    return (HP1+EXP1+M1);
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;

    int taxiMax = 0,taxiMin = 0;
    int taxi[10][10] = {};

    for (int i=0; i < 10; i++) {    
        for (int j=0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i-j);
            if (taxi[i][j] > (E3*2)) taxiMax++;
            if (taxi[i][j] < -E3) taxiMin++;
        }
    }
    while (taxiMax >= 10) {
        taxiMax = ((taxiMax/10) + (taxiMax%10));
    }
    while (taxiMin >= 10) {
        taxiMin = ((taxiMin/10) + (taxiMin%10));
    }
    int sherlockMax;
    sherlockMax = taxi[taxiMax][taxiMin];

    for (int i=taxiMax, j=taxiMin; i < 10 && j>=0; i++,j--) {       //di cheo ve goc duoi ben trai
        if (taxi[i][j] > sherlockMax) sherlockMax = taxi[i][j];
    }           
    for (int i=taxiMax, j=taxiMin; i < 10 && j<10; i++,j++) {       //di cheo ve goc duoi ben phai
        if (taxi[i][j] > sherlockMax) sherlockMax = taxi[i][j];
    }
    for (int i=taxiMax, j=taxiMin; i>=0 && j>=0; i--,j--) {         //di cheo ve goc tren ben trai
        if (taxi[i][j] > sherlockMax) sherlockMax = taxi[i][j];
    }
    for (int i=taxiMax, j=taxiMin; i>=0 && j<10; i--,j++) {         //di cheo ve goc tren ben phai
        if (taxi[i][j] > sherlockMax) sherlockMax = taxi[i][j];
    }
    if (abs(sherlockMax) >= abs(taxi[taxiMax][taxiMin])) {
        EXP1 = ceilf(EXP1*112.0/100);checkEXP(EXP1);
        EXP2 = ceilf(EXP2*112.0/100);checkEXP(EXP2);
        HP1 = ceilf(HP1*11.0/10);checkHP(HP1);
        HP2 = ceilf(HP2*11.0/10);checkHP(HP2);
        return abs(sherlockMax);
    }   
    else {
        EXP1 = ceilf(EXP1*88.0/100);checkEXP(EXP1);
        EXP2 = ceilf(EXP2*88.0/100);checkEXP(EXP2);
        HP1 = ceilf(HP1*9.0/10);checkHP(HP1);
        HP2 = ceil(HP2*9.0/10);checkHP(HP2);
        return taxi[taxiMax][taxiMin];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[101];
    int i=0;
    while (email[i] != '@' && i<100) {      //chuoi se
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';       //ket thuc chuoi se

    if (strlen(s) < 8) return -1;   //chuoi s ngan hon 8
    if (strlen(s) >20) return -2;   //chuoi s dai hon 20

    const char* se_in_s;
    se_in_s = strstr(s,se);     //tim se trong s
    int vitri = se_in_s - s;
    if (se_in_s != NULL) return (-300 - vitri);     //return vi tri se neu co

    for (int i=0;i < strlen(s); i++) {
        if ((s[i] == s[i+1]) && (s[i] == s[i+2])) return (-400 - i);        //return vi tri 3 ki tu giong nhau lien tiep
    }
    i=0;
    bool checkKituDB = false;
    while (i <= strlen(s)) {
        if ((s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')) {
            checkKituDB = true;
            break;
        }
        i++;
    }
    if (!checkKituDB) return -5;    //check co it nhat 1 ki tu dac biet

    i=0;
    while(i < strlen(s)) {
        if ( !((s[i] >= '0' && s[i] <= '9')     //kiem tra co phai so 
        || ((s[i] >= 'a') && (s[i] <= 'z'))     //kiem tra chu cai thuong
        || ((s[i] >= 'A') && (s[i] <= 'Z'))     //kiem tra chu cai in hoa
        || (s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')))      //kiem tra ki tu dac biet
        {
            return i;
        }          
        i++;
    }

    return -10; //s la mot mat khau hop le
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    
    int index=0;
    int freq=0;
    int max_freq=0;
    int max_length=0;


    for (int i=0;i < num_pwds;i++) {
        freq = 0;
        for (int j=0;j < num_pwds;j++) {
            if (strcmp(arr_pwds[i],arr_pwds[j]) == 0) freq++;
        }
        if ((freq > max_freq) || ((freq == max_freq) && (strlen(arr_pwds[i]) > max_length)))  {
            max_freq=freq;
            max_length=strlen(arr_pwds[i]);
            index=i;
        } 
    } 
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////