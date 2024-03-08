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

// Task 1 9h 7/3/2024
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99 ) return -99;
    else {
            if ( exp1 > 600 ) exp1 = 600;
            if ( exp1 < 0 ) exp1 = 0;
            if ( exp2 > 600 ) exp2 = 600;
            if ( exp2 < 0 ) exp2 = 0;
            if ( e1 <= 3 && e1 >= 0 ) {
                switch (e1)
                {
                case 0:
                    exp2 += 29;
                    break;
                case 1:
                    exp2 += 45;
                    break;
                case 2:
                    exp2 += 75;
                    break;
                default: exp2 += 29 + 45 + 75;
                    break;
                }
                if (exp2 > 600) exp2 = 600;
                if (exp2 < 0) exp2 = 0;
                int D = e1*3 + exp1*7;
                if ( D % 2 == 0 ) exp1 = ceil( exp1 + D/200.0);
                else exp1 = ceil( exp1 - D/100.0);
                if (exp1 > 600) exp1 = 600;
                if (exp1 < 0) exp1 = 0;

            }
            else {
               if ( exp1 > 600 ) exp1 = 600;
                if ( exp1 < 0 ) exp1 = 0;
                if ( exp2 > 600 ) exp2 = 600;
                if ( exp2 < 0 ) exp2 = 0;
               if ( e1 >= 4 && e1 <= 19) exp2 = ceil(exp2 + e1/4.0 + 19.0);
               if ( e1 >= 20 && e1 <= 49) exp2 = ceil(exp2 + e1/9.0 + 21.0);
               if ( e1 >= 50 && e1 <= 65) exp2 = ceil(exp2 + e1/16.0 + 17.0);
               if ( e1 >= 66 && e1 <= 79) {
                    exp2 = ceil(exp2 +  e1/4.0 + 19.0);
                    if ( exp2 > 600 ) exp2 = 600;
                    if ( exp2 < 0 ) exp2 = 0;
                    if ( exp2 > 200 ) exp2 =ceil(exp2 + e1/9.0 + 21.0);
               }              
               if ( e1 >= 80 && e1 <= 99) {
                    exp2 =ceil(exp2 + e1/4.0 + 19.0)  + ceil(e1/9.0 + 21.0);
                    if ( exp2 > 600 ) exp2 = 600;
                    if ( exp2 < 0 ) exp2 = 0;
                    if ( exp2 > 400 ) {
                        exp2 =ceil(exp2 + e1/16.0 + 17.0);
                        if ( exp2 > 600 ) exp2 = 600;
                        if ( exp2 < 0 ) exp2 = 0;
                        exp2 = ceil(exp2 +  static_cast<double> (exp2) * 15.0/100.0);
                    }
               }            
               exp1 = exp1 - e1;

            }   
            if ( exp1 > 600 ) exp1 = 600;
            if ( exp1 < 0 ) exp1 = 0;
            if ( exp2 > 600 ) exp2 = 600;
            if ( exp2 < 0 ) exp2 = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    } 
    return exp1 + exp2;
}       
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
//the way 01
    if (E2 < 0 || E2 > 99 ) return -99;
    int S, lowersquare, uppersquare;
    double P1, P2;
    lowersquare = floor( sqrt(EXP1) );
    uppersquare = ceil( sqrt(EXP1) );
    lowersquare = pow( lowersquare, 2);
    uppersquare = pow( uppersquare, 2);
    if ( abs(EXP1 - lowersquare) < abs( EXP1 - uppersquare) ) S = lowersquare;
    else S = uppersquare;
    if (EXP1 >= S)  P1 = 1.0;
    else P1 = (static_cast<double>(EXP1) / S + 80.0) / 123.0;
// the way 02 
   double nuaMbd = M1/2;
    if ( E2 % 2 != 0) {  
        int Mused = 0;  
        while (Mused <= nuaMbd) {
            if (HP1 < 200){
                HP1 = ceil(HP1 + 30*HP1/100.0);
                M1 -= 150;
                Mused += 150;
                if (HP1 > 666 ) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (M1 < 0) M1 = 0;
            }
            else {
                HP1 = ceil(HP1 + 10*HP1/100.0);
                M1 -= 70;
                Mused += 70;
                if (HP1 > 666 ) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (M1 < 0) M1 = 0;
            }
            if (Mused > nuaMbd) break;
            else {
                if ( EXP1 < 400) {
                    M1 -= 200;
                    Mused += 200;
                    if (M1 > 3000) M1 = 3000;
                    if (M1 < 0) M1 = 0;
                    EXP1 = ceil(EXP1 + 13*EXP1/100.0);
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
                else { 
                    M1 -= 120;
                    Mused += 120;
                    if (M1 > 3000) M1 = 3000;
                    if (M1 < 0) M1 = 0;
                    EXP1 = ceil(EXP1 + 13*EXP1/100.0);
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
            }
            if ( Mused > nuaMbd) break;
            else {
                if (EXP1 < 300) {
                    M1 -= 100;
                    if (M1 > 3000) M1 = 3000;
                    if (M1 < 0) M1 = 0;
                    Mused += 100;
                    EXP1 = ceil(EXP1 - 10*EXP1/100.0);
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
                else {
                    M1 -= 120;
                    if (M1 > 3000) M1 = 3000;
                    if (M1 < 0) M1 = 0;
                    Mused += 120;
                    EXP1 = ceil(EXP1 - 10*EXP1/100.0);
                    if (EXP1 > 600) EXP1 = 600;
                    if (EXP1 < 0) EXP1 = 0;
                }
            }
            if (Mused > nuaMbd) break;
        }      
    }
    else {
            if (HP1 < 200){
                HP1 = ceil(HP1 + 30*HP1/100.0);
                M1 -= 150;
                if (M1 > 3000) M1 = 3000;
                if (M1 < 0) M1 = 0;
                if (HP1 > 666 ) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
            }
            else {
                HP1 = ceil(HP1 + 10*HP1/100.0);
                M1 -= 70;
                if (M1 > 3000) M1 = 3000;
                if (M1 < 0) M1 = 0;
                if (HP1 > 666 ) HP1 = 666;
                if (HP1 < 0) HP1 = 0;
            }
            if ( M1 > 0) {            
                if ( EXP1 < 400) M1 -= 200;
                else M1 -= 120;
                EXP1 = ceil(EXP1 + 13*EXP1/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (M1 < 0) M1 = 0;

            }
            else M1 =0;
            if ( M1 > 0) {
                if (EXP1 < 300) M1 -= 100;
                else M1 -= 120;
                EXP1 = ceil(EXP1 - 10*EXP1/100.0);
                if (EXP1 > 600) EXP1 = 600;
                if (EXP1 < 0) EXP1 = 0;
                if (M1 > 3000) M1 = 3000;
                if (M1 < 0) M1 = 0;
            }
            else M1 = 0;             
    } 
    EXP1 = ceil(EXP1 + 17*EXP1/100.0);
    HP1 = ceil(HP1 - 17*HP1/100.0);
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666 ) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    lowersquare = floor( sqrt(EXP1) );
    uppersquare = ceil( sqrt(EXP1) );
    lowersquare = pow( lowersquare, 2);
    uppersquare = pow( uppersquare, 2);
    if ( abs(EXP1 - lowersquare) < abs( EXP1 - uppersquare) ) S = lowersquare;
    else S = uppersquare;
    if (EXP1 >= S)  P2 = 1.0;
    else P2 = (static_cast<double>(EXP1) / S + 80.0) / 123.0;
//the way 03 
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int t, tong2chuso, hangchuc, hangdonvi;
    if ( E2 < 10 ) t = E2;
    else {
        hangchuc = E2/10;
        hangdonvi = E2 % (hangchuc*10);
        tong2chuso = hangchuc + hangdonvi;
        t = tong2chuso % 10; 
    }
    double P3 = P[t]/100.0;
//conclusion
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0 ) { 
        EXP1 = ceil(EXP1 - 25*EXP1/100);
        if (EXP1 > 600) EXP1 = 600;
        if (EXP1 < 0) EXP1 = 0;
    }
    else {
        double Ptb = (P1 + P2 + P3)/3.0;
        if (Ptb < 0.5) {
            HP1 = ceil(HP1 - 15*HP1/100.0);
            EXP1 = ceil(EXP1 + 15*EXP1/100.0);
            if (HP1 > 666 ) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
        }
        else {
            HP1 = ceil(HP1 - 10*HP1/100.0);
            EXP1 = ceil(EXP1 + 20*EXP1/100.0);
            if (HP1 > 666 ) HP1 = 666;
            if (HP1 < 0) HP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (EXP1 < 0) EXP1 = 0;
        }
    }
        
    return HP1 + EXP1 + M1; 
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99 ) return -99;
    int i, j;
    int arroftaxi[10][10];
    for ( i = 0; i < 10; i++) {
        for ( j = 0; j < 10; j++) {
            arroftaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int arrofSW[10][10];
    for ( j = 0; j < 10; j++) {
        for ( i = 0; i < 10; i++) {
            int max = arroftaxi[i][j];
            for (int n = 0; n < 10; n++) {
                if ( i - n >= 0 && j - n >=0) 
                    if (arroftaxi[i - n][j - n] > max) max = arroftaxi[i - n][j - n];
            }
            for (int n = 0; n < 10; n++) {
                if (i + n <= 9 && j + n <= 9)
                    if (arroftaxi[i + n][j + n] > max) max = arroftaxi[i + n][j + n];
             }
             for (int n = 0; n < 10; n++) {
                if (i + n <= 9 && j - n >= 0)
                    if (arroftaxi[i + n][j - n] > max) max = arroftaxi[i + n][j - n];
             }
             for (int n = 0; n < 10; n++) {   
                if (i - n >= 0 && j + n <= 9 )
                    if (arroftaxi[i - n][j + n] > max) max = arroftaxi[i - n][j + n];
            }
            arrofSW[i][j] = abs(max);
        }
    }  
    int h = 0, k = 0;
    for (i = 0; i < 10; i++) {
        for ( j = 0; j < 10; j++) {
            if (arroftaxi[i][j] > E3*2) h += 1;
            if (arroftaxi[i][j] < -E3) k += 1;
        }
    }
    while (h >= 10)  h =( (h / 10) + (h % 10) ); 
    while (k >= 10)  k = (k / 10) + (k % 10);

    if (abs(arroftaxi[h][k]) > arrofSW[h][k]) {
        EXP1 = ceil(EXP1 - 12 * EXP1 / 100.0);
        HP1 = ceil(HP1 - 10 * HP1 / 100.0);
        EXP2 = ceil(EXP2 - 12 * EXP2 / 100.0);
        HP2 = ceil(HP2 - 10 * HP2 / 100.0);
    } else {
        EXP1 = ceil(EXP1 + 12 * EXP1 / 100.0);
        HP1 = ceil(HP1 + 10 * HP1 / 100.0);
        EXP2 = ceil(EXP2 + 12 * EXP2 / 100.0);
        HP2 = ceil(HP2 + 10 * HP2 / 100.0);
    }

    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP2 > 666) HP2 = 666;
    if (HP1 < 0) HP1 = 0;
    if (HP2 < 0) HP1 = 0;
    int result;
    if (abs(arroftaxi[h][k]) > abs(arrofSW[h][k])) result = arroftaxi[h][k];
    if ( abs(arroftaxi[h][k]) < abs(arrofSW[h][k]) ) result = arrofSW[h][k];
    if ( abs(arroftaxi[h][k]) == abs(arrofSW[h][k]) ) return result = arrofSW[h][k];
    return result;
}
// Task 4
int checkcharacters(const char *s) {
    string str(s);
    int flag1 = 0;
    if ( str.find("@") != string::npos ) flag1 += 1;
    if ( str.find("#") != string::npos ) flag1 += 1;
    if ( str.find("%") != string::npos ) flag1 += 1;
    if ( str.find("$") != string::npos ) flag1 += 1;
    if ( str.find("!") != string::npos ) flag1 += 1;
    return flag1;
}
bool isSpecialCharacter(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%');
}

int findDifferentCharacterPosition(const char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        char c = str[i];
        
        if (!isalnum(c) && !isSpecialCharacter(c)) {
            return i;
        }
    }
  
    return -1;
} 

int findse(const char *s1, const char *s2) {
    string str1(s1), str2(s2);
    int sei = str1.find(str2);
    return sei;
}

int doublecharater(const char *str) {
    int sci = -1; 
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        if (str[i] == str[i + 1] && str[i+1] == str[i+2]) {
            sci = i;
            break;
        }
    }
    return sci;
}
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int flag = 0; 
    string str(s); 
    
    const char *p = strstr(email, "@");
 
    
    char se[p-email+1]; 
    strncpy(se, email, p-email); 
    se[p-email] = '\0'; 
    int length = str.length();
    if ( length >= 8 && length <= 20 ) flag += 1;
    else {        
        if (length < 8 ) return -1;
        if (length > 20) return -2;
    }
 
    int sei = findse(s, se);
    if (sei != string::npos && sei < 21) return -(300 + sei);
    else flag += 1;

    int k = doublecharater(s);
    if (k == -1 ) flag += 1;
    else return -(400 + k);

    if (checkcharacters(s) != 0) flag += 1;
    else return -5;

    int l = findDifferentCharacterPosition(s);
    if (l != -1) return l;

    if (flag == 4) return -10;
    return 0; 
}
// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxFrequency = 0;
    int maxLength = 0;
    int firstOccurrenceIndex ;

   
    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int frequency = 1;
        int length = 0;
        
       
        while (pwd[length] != '\0') {
            length++;
        }

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], pwd) == 0) {
                frequency++;
            }
        }

     
        if (frequency > maxFrequency || (frequency == maxFrequency && length > maxLength)) {
            maxFrequency = frequency;
            maxLength = length;
            firstOccurrenceIndex = i;
        }
    }

    return firstOccurrenceIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////