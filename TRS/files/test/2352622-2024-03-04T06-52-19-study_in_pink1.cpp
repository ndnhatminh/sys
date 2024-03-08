#include "study_in_pink1.h"

bool readFile(
        const string &filename,
        int &HP1,
        int &HP2,
        int &EXP1,
        int &EXP2,
        int &M1,
        int &M2,
        int &E1,
        int &E2,
        int &E3
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
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkEXP(int &EXP) {
    if (EXP < 0) {
        EXP = 0;
    } else if (EXP > 600) {
        EXP = 600;
    }
}

void checkHP(int &HP) {
    if (HP < 0) {
        HP = 0;
    } else if (HP > 666) {
        HP = 666;
    }
}

void checkM(int &M) {
    if (M < 0) {
        M = 0;
    } else if (M > 3000) {
        M = 3000;
    }
}

// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1) {
    if (E1 < 0 || E1 > 99) {
        return -99;}
    checkEXP(EXP1);
    checkEXP(EXP2);
    if (E1 >= 0 && E1 <= 3) {
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1=ceil(EXP1 + D / 200.0);
            checkEXP(EXP1);
        } else if (D % 2 == 1) {
            EXP1 = ceil (EXP1- (D) / 100.0);
            checkEXP(EXP1);
        }
        if (E1 == 0) {
            EXP2 += 29;
            checkEXP(EXP2);
        } else if (E1 == 1) {
            EXP2 += 45;
            checkEXP(EXP2);
        } else if (E1 == 2) {
            EXP2 += 75;
            checkEXP(EXP2);
        } else if (E1 == 3) {
            EXP2 += 29 + 45 + 75;
            checkEXP(EXP2);
        }
    }else if (E1 >= 4 && E1 <= 99) {
        EXP1 -= E1;
        checkEXP(EXP1);
        if (E1 >= 4 && E1 <= 19) {
            EXP2 = ceil(EXP2 +E1 / 4.0 + 19);
            checkEXP(EXP2);
        } else if (E1 >= 20 && E1 <= 49) {
            EXP2 = ceil(EXP2+ E1 / 9.0 + 21);
            checkEXP(EXP2);
        } else if (E1 >= 50 && E1 <= 65) {
            EXP2 = ceil(EXP2+E1 / 16.0 + 17);
            checkEXP(EXP2);
        } else if (E1 >= 66 && E1 <= 79) {
            EXP2 = ceil(EXP2 + E1 / 4.0 + 19);
            checkEXP(EXP2);
            if (EXP2 > 200) {
                EXP2 = ceil(EXP2 + E1 / 9.0 + 21);
                checkEXP(EXP2);
            }
        } else if (E1 >= 80 && E1 <= 99) {
            EXP2 = ceil(EXP2+ E1/4.0 + 19);
            checkEXP(EXP2);
            EXP2 = ceil(EXP2 +E1/9.0 + 21);
            checkEXP(EXP2);
            if (EXP2 > 400) {
                EXP2 = ceil(EXP2 +E1/ 16.0 + 17);
                checkEXP(EXP2);
                EXP2 = ceil (EXP2 * 1.15);
                checkEXP(EXP2);
            }
        }
    }
   
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) {
        return -99;}
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    double P1, P2, P3;
    int S;
    int IM = M1;
    S = int(sqrt(EXP1) + 0.5);
    S = S * S;

    if (EXP1 >= S) {
        P1 = 1;
    } else {
        P1 = ((static_cast<double>(EXP1)/ S) + 80) / 123.0;
    }
   
if (E2 % 2 == 1) {
     int moneyspend=0;
        do {if(moneyspend<=0.5*IM && IM!=0){
            if (HP1 < 200) {
                HP1 = ceil(HP1+HP1 * 0.30);
                checkHP(HP1);
                M1 -= 150;
                checkM(M1);
                moneyspend+=150;
            } else if(HP1>=200) {
                HP1 = ceil(HP1+HP1 * 0.10);
                checkHP(HP1);
                M1 -= 70;
                checkM(M1);
                moneyspend+=70;
            }}else break;
            if(moneyspend<=0.5*IM && IM!=0){
            if (EXP1 < 400) {
                M1 -= 200;
                checkM(M1);
                moneyspend+=200;
            } else if(EXP1>=400) {
                M1 -= 120;
                moneyspend+=120;
                checkM(M1);
            }
            EXP1 = ceil(EXP1+EXP1 * 0.13);
            checkEXP(EXP1);
                
            }else break;
            
if(moneyspend<=0.5*IM && IM!=0){

            if (EXP1 < 300) {
                M1 -= 100;
                checkM(M1);
                moneyspend+=100;
                EXP1 = ceil(EXP1-EXP1 * 0.1);
                checkEXP(EXP1);
            } else if(EXP1>=300) {
                M1 -= 120;
                checkM(M1);
                moneyspend+=120;
                EXP1 = ceil(EXP1-EXP1 * 0.1);
                checkEXP(EXP1);
            }}else break;cout<<EXP1;
            
        }
            while(true);
        HP1 = ceil(HP1-HP1 * 0.17);
        checkHP(HP1);
        EXP1 = ceil(EXP1+EXP1 * 0.17);
        checkEXP(EXP1);

    }
    

   if (E2 % 2 == 0) {
   if (HP1 < 200) {
            if (M1 == 0) {
               
            } else {
                M1 = M1 -= 150;;
                HP1 = ceil(HP1+HP1 * 0.30);
                
            }
        } else {
            if (M1 == 0) {
               
            } else {
               M1 -= 70;
               HP1 = ceil(HP1+HP1 * 0.10);
               
            }
        }  checkHP(HP1);
           checkM(M1);
        if (EXP1 < 400) {
            if (M1 <= 0) {
               
            } else {
                M1 -= 200;
               EXP1 = ceil(EXP1+EXP1 * 0.13);
               checkEXP(EXP1);
            }
        } else {
            if (M1 <= 0) {
               
            } else {
               M1 -= 120;
               EXP1 = ceil(EXP1+EXP1 * 0.13);
               checkEXP(EXP1);
            }
            checkM(M1);
        }
        if (EXP1 < 300) {
            if (M1 <= 0) {
               
            } else {
                M1 -= 100;
               EXP1 = ceil(EXP1-EXP1 * 0.1);
               checkEXP(EXP1);
               checkM(M1);
            }
        } else {
            if (M1 <= 0) {
              
            } else {
                M1 -= 120;
                EXP1 = ceil(EXP1-EXP1 * 0.1);
                checkEXP(EXP1);
                checkM(M1);
            } 
        }
        HP1 = ceil(HP1-HP1 * 0.17);
        checkHP(HP1);
        EXP1 = ceil(EXP1+EXP1 * 0.17);
        checkEXP(EXP1);
        
    }
      
            
        S = sqrt(EXP1) + 0.5;
        S = S * S;
        if (EXP1 >= S) {
            P2 = 1;
        } else {
            P2 = ((static_cast<double>(EXP1) / S) + 80) / 123.0;
        }
    
    
    int i;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    int sum = E2 / 10 + E2 % 10;
    if (sum < 10)
        i = sum;
    else
        i = sum % 10;

    P3 = P[i] / 100.0;

    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 =ceil(EXP1* 0.75);
    } else {
        double Average = (P1 + P2 + P3) / 3;
        if (Average >= 0.5) {
            HP1 =ceil(HP1-HP1* 0.1);
            checkHP(HP1);
            EXP1 =ceil(EXP1+EXP1* 0.2);
            checkEXP(EXP1);
        } else {
            HP1 =ceil(HP1-HP1* 0.15);
            checkHP(HP1);
            EXP1 =ceil(EXP1+EXP1* 0.15);
            checkEXP(EXP1);
        }
    }

    checkHP(HP1);
    checkEXP(EXP1);
    checkM(M1);

    return HP1+EXP1+M1 ;
}

// Task 3
int coordinates(int num) {
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int computeGrade(int i, int j, int E3) {
    return ((E3 * j) + (i * 2)) * (i - j);
}


int maxDiagonalGrade(int i, int j, int taxiMap[10][10]) {
    int maxGrade = 0;

    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
        maxGrade = max(maxGrade, taxiMap[x][y]);
    }
    for (int x = i, y = j; x < 10 && y < 10; x++, y++) {
        maxGrade = max(maxGrade, taxiMap[x][y]);
    }

    for (int x = i, y = j; x >= 0 && y < 10; x--, y++) {
        maxGrade = max(maxGrade, taxiMap[x][y]);
    }
    for (int x = i, y = j; x < 10 && y >= 0; x++, y--) {
        maxGrade = max(maxGrade, taxiMap[x][y]);
    }

    return maxGrade;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
     if (E3 < 0 || E3 > 99) {
        return -99;}
    checkEXP(EXP2);
    checkEXP(EXP1);
    checkHP(HP2);
    checkHP(HP1);
    int taxiMap[10][10];
    int sherlockWay[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            taxiMap[i][j] = computeGrade(i, j, E3);
        }
    }


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            sherlockWay[i][j] = maxDiagonalGrade(i, j, taxiMap);
        }
    }

    int taxi_greater_count = 0;
    int taxi_less_count = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (taxiMap[i][j] > E3 * 2) {
                taxi_greater_count++;
            }
            if (taxiMap[i][j] < -E3) {
                taxi_less_count++;
            }
        }
    }

    int meeting_i = coordinates(taxi_greater_count);
    int meeting_j = coordinates(taxi_less_count);

    int taxiGrade = taxiMap[meeting_i][meeting_j];
    int sherlockGrade = sherlockWay[meeting_i][meeting_j];

   if (abs(taxiGrade) > sherlockGrade) {
        HP1 =HP1* 0.9+0.999;
        EXP1 =EXP1* 0.88+0.999;
        HP2 = HP2*0.9+0.999;
        EXP2 =EXP2* 0.88+0.999;
    } else {
        HP1 =HP1* 1.1+0.999;
        EXP1 =EXP1*1.12+0.999;
        HP2 = HP2*1.1+0.999;
        EXP2 =EXP2* 1.12+0.999;
    }
    checkEXP(EXP2);
    checkEXP(EXP1);
    checkHP(HP2);
    checkHP(HP1);
   
    return (abs(taxiGrade) > sherlockGrade) ? taxiGrade : sherlockGrade;


    return -1;
}

// Task 4
int Checklength(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}


const char* Checksubstring(const char *s, const char* se) {
    if (*se == '\0') return s;

    for (int i = 0; s[i] != '\0'; i++) {
        bool found = true;
        for (int j = 0; se[j] != '\0'; j++) {
            if (s[i + j] == '\0' || s[i + j] != se[j]) {
                found = false;
                break;
            }
        }
        if (found) return s+i;
    }
    return nullptr;
}


const char* Checkemail(const char* s, int c) {
    while (*s != '\0') {
        if (*s == c) return s;
        s++;
    }
    return nullptr;
}

int checkPassword(const char* s, const char* email) {
    
    const char* atPos = Checkemail(email, '@');
    if (atPos == nullptr) return -1;
    int seLength = atPos - email;
    char se[101];
    
    for (int i = 0; i < seLength; ++i) {
        se[i] = email[i];
    }
    se[seLength] = '\0';
    int length =Checklength(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    const char* substring = Checksubstring(s, se);
    if (substring != nullptr) {
    int position = substring - s;
    return -(300 + position);}

    for (int i = 0; i < length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }
    
    
      bool containsSpecial = false;
    for (int i = 0; i < length; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            containsSpecial = true;
            break;
        }
    }
    if (!containsSpecial) return -5;
    
    for (int i = 0; i < length; ++i) {
        if (!isalpha(s[i]) && !isdigit(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i;
        }
    }


    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
   int countMax = 0;
    size_t maxLength = 0;
    int firstpos = -1;

    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        size_t currentLength = strlen(arr_pwds[i]);
        if ((count > countMax) || (count == countMax && currentLength > maxLength)) {
            countMax = count;
            maxLength = currentLength;
            firstpos = i;
        }
    }

    return firstpos; 
    return -1;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////