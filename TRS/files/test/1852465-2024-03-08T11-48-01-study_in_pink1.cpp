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
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkExpOutOfRange(int &exp) { 
    if(exp < 0) { 
        exp = 0;
    }
    else if(exp > 600) { 
        exp = 600;
    }
}
void checkHPOutOfRange(int &HP) { 
    if(HP < 0) { 
        HP = 0;
    }
    else if(HP > 666) { 
        HP = 666;
    }
}
void checkMoneyOutOfRange(int &M) { 
    if(M > 3000) { 
        M = 3000;
    }
    else if(M < 0) { 
        M = 0;
    }
}
//! Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    checkExpOutOfRange(exp1);
    checkExpOutOfRange(exp2);
    
    // TH1:
    if(e1 >= 0 && e1 <= 3) { 
        if(e1 == 0) { 
            exp2 += 29;
        }
        else if(e1 == 1) { 
            exp2 += 45;
        }
        else if(e1 == 2) { 
            exp2 += 75;
        }
        else if(e1 == 3) { 
            exp2 += 149;
        }

        int D = e1 * 3 + exp1 * 7;

        if(D % 2 == 0) { // afghanistan
            exp1 = ceilf(exp1 + (D/200.0));
        }
        else { // iraq 
            exp1 = ceilf(exp1 - (D/100.0));
        }
    }
    // TH2:
    else if(e1 >= 0 && e1 < 100) { 
        if(e1 >= 4 && e1 <= 19) { 
            exp2 += ceilf(e1 / 4.0) + 19;
        }
        else if(e1 >= 20 && e1 <= 49) { 
            exp2 += ceilf(e1 / 9.0) + 21;
        }
        else if(e1 >= 50 && e1 <= 65) { 
            exp2 += ceilf(e1 / 16.0) + 17;
        }
        else if(e1 >= 66 && e1 <= 79) { 
            exp2 += ceilf(e1 / 4.0) + 19;

            if(exp2 > 200) { 
                exp2 += ceilf(e1 / 9.0) + 21;
            }
        }
        else if(e1 >= 80 && e1 <= 99) { 
            exp2 += ceilf(e1 / 4.0) + 19;
            exp2 += ceilf(e1 / 9.0) + 21;

            if(exp2 > 400) { 
                exp2 += ceilf(e1 / 16.0) + 17;

                // exp2 gets bonus 15% current exp
                exp2 += ceilf(exp2 * 0.15);
            }
        }
        // Harriet not Harry
        exp1 -= e1;
    }
    else return -99;

    checkExpOutOfRange(exp1);
    checkExpOutOfRange(exp2);
    return exp1 + exp2;
}


void event1(int &HP1, int &EXP1, int &M) { 
    if(HP1 < 200) { 
        HP1 = ceilf(HP1 * 1.3);
        M += 150;
    }
    else { 
        HP1 = ceilf(HP1 * 11.0/10);
        M += 70;
    }
}
void event2(int &HP1, int &EXP1, int &M) { 
    if(EXP1 < 400) { 
        M += 200;
    }
    else { 
        M += 120;
    }

    // EXP1 *= 1.13;
    EXP1 = ceilf(EXP1 * 1.13);
}
void event3(int &HP1, int &EXP1, int &M) { 
    if(EXP1 < 300) { 
        M += 100;
    }
    else { 
        M += 120;
    }

    // EXP1 *= 0.9;
    EXP1 = ceilf(EXP1 * 0.9);
}
int findNearestSquareNum(int EXP) { 
    double n = floor(sqrt(EXP));
    int a = EXP - n*n;
    int b = pow(n + 1, 2) - EXP;
    
    if(a >= b) { 
        return pow(n + 1, 2);
    }
    else return n*n;
}

//! task2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{

// TODO: Complete this function
    if (E2 > 99 || E2 < 0) { 
        return -99;
    }
    
    // Con duong 1
    // find nearest square number
    int S = findNearestSquareNum(EXP1);
    float P1 = 1;
    if(EXP1 < S) { 
        P1 = (EXP1 / S + 80) / 123.0;
    }

    // Con duong 2
    int limit_M1 = ceilf(M1 / 2.0); 
    int M = 0; // money to pay
    if(E2 % 2 != 0 && M1 > 0) { 
        while(M <= limit_M1) { 
            // Su kien #1
            event1(HP1, EXP1, M); 
            checkHPOutOfRange(HP1);
            if(M > limit_M1) break;
            // Su kien #2
            event2(HP1, EXP1, M); 
            checkExpOutOfRange(EXP1);
            if(M > limit_M1) break;
            // Su kien #3
            event3(HP1, EXP1, M); 
            checkExpOutOfRange(EXP1);
            if(M > limit_M1) break;
        }
    }
    else { 
        while(M1 > 0) { 
            event1(HP1, EXP1, M);
            checkHPOutOfRange(HP1);
            if(M >= M1) break;
            event2(HP1, EXP1, M);
            checkExpOutOfRange(EXP1);
            if(M >= M1) break;
            event3(HP1, EXP1, M);
            checkExpOutOfRange(EXP1);
            break;
        }
    }
    
    M1 -= M; 
    if(M1 < 0) { 
        M1 = 0;
    }

    HP1 = ceilf(HP1 * 0.83); 
    // checkHPOutOfRange(HP1);
    EXP1 = ceilf(EXP1 * 1.17);
    checkExpOutOfRange(EXP1);

    // find P2
    float P2 = 1;
    S = findNearestSquareNum(EXP1);

    if(EXP1 < S) { 
        P2 = (EXP1 / S + 80) / 123.0;
    }

    
    // Con duong 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    float P3 = -1;
    if(E2 < 10) { 
        i = E2;
    }
    else { 
        i = (E2 / 10 + E2 % 10) % 10;
    }

    P3 = P[i] * 0.01;

    // end of 3 Con duong
    if(P1 == 1 && P2 == 1 && P3 == 1) { 
        EXP1 = ceilf(EXP1 * 0.75);
    }
    else { 
        float avgP = (P1 + P2 + P3) / 3;

        if(avgP < 0.5) { 
            HP1 = ceilf(HP1 * 0.85);
            EXP1 = ceilf(EXP1 * 1.15);
        }
        else { 
            HP1 = ceilf(HP1 * 0.9);
            EXP1 = ceilf(EXP1 * 1.2);
        }
        // checkHPOutOfRange(HP1);
    }
    checkExpOutOfRange(EXP1);
    // cout << "\nHP1 = " << HP1;
    // cout << "\nEXP1 = " << EXP1;
    // cout << "\nM1 = " << M1 << endl;
    return HP1 + EXP1 + M1;
}

void trimNumber(int &num) {
    if(num < 10) { 
        return;
    }
    
    int newNum = num;
    while(newNum >= 10) { 
        newNum = (newNum / 10) + (newNum % 10);
    }

    num = newNum;
}
//! Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if(E3 < 0 || E3 > 99) { 
        return -99;
    }
    //TODO: create a 10x10 matrix for taxi's skill values
    int matrix[10][10];
    for(int i = 0; i < 10; ++i) { 
        for(int j = 0; j < 10; ++j) { 
            matrix[i][j] = (((E3 * j) + (i * 2)) * (i - j));
        }
    }
    
    //TODO: find confronting coordinates (i & j)
    int i = 0, j = 0;
    for(int r = 0; r < 10; ++r) { 
        for(int c = 0; c < 10; ++c) { 
            if(matrix[r][c] > E3 * 2) { 
                ++i;
            }
            else if(matrix[r][c] < -E3) { 
                ++j;
            }
        }
    }

    trimNumber(i);
    trimNumber(j);

    //TODO: find Sherlock & Watson' skill value at matrix[i][j] (maximum of 2 diagonals)
    // step #1: check upward left diagonal
    int maxValue = matrix[i][j];
    int r = i - 1, c = j - 1;
    while(r < 10 && r >= 0 && c >= 0 && c < 10) { 
        if(matrix[r][c] > maxValue) { 
            maxValue = matrix[r][c];
        }
        --r;
        --c;
    }
    // step #2: check downward left diagonal
    r = i + 1;
    c = j + 1;
    while(r < 10 && r >= 0 && c >= 0 && c < 10) { 
        if(matrix[r][c] > maxValue) { 
            maxValue = matrix[r][c];
        }
        ++r;
        ++c;
    }
    // step #3: check upward right diagonal
    r = i - 1;
    c = j + 1;
    while(r < 10 && r >= 0 && c >= 0 && c < 10) { 
        if(matrix[r][c] > maxValue) { 
            maxValue = matrix[r][c];
        }
        ++r;
        --c;
    }
    // step #4: check downward right diagonal
    r = i + 1;
    c = j - 1;
    while(r < 10 && r >= 0 && c >= 0 && c < 10) {
        if(matrix[r][c] > maxValue) { 
            maxValue = matrix[r][c];
        }
        ++r;
        --c;
    }

    //TODO: compare taxi's skill value with Sherlock and Watson' skill value
    int taxiValue = abs(matrix[i][j]);
    if(taxiValue > maxValue) { // Sherlock and Watson failed to pursue the taxi
        EXP1 = ceilf(EXP1 * 0.88);
        EXP2 = ceilf(EXP2 * 0.88);
        checkExpOutOfRange(EXP1);
        checkExpOutOfRange(EXP2);

        HP1 = ceilf(HP1 * 0.9);
        HP2 = ceilf(HP2 * 0.9);
        checkHPOutOfRange(HP1);
        checkHPOutOfRange(HP2);
    }
    else { 
        EXP1 = ceilf(EXP1 * 112.0/100);
        EXP2 = ceilf(EXP2 * 112.0/100);
        checkExpOutOfRange(EXP1);
        checkExpOutOfRange(EXP2);


        HP1 = ceilf(HP1 * 11.0/10);
        HP2 = ceilf(HP2 * 11.0/10);

        checkHPOutOfRange(HP1);
        checkHPOutOfRange(HP2);
    }
    
    
    // cout << "\nTaxi value = " << taxiValue;
    // cout << "\nCar value = " << maxValue << endl;
    return taxiValue > maxValue ? matrix[i][j] : maxValue;
}

//! Task 4
int checkPassword(const char *s, const char *email)
{
    string se;

    // get username before '@'
    for(int i = 0; i < strlen(email); ++i) { 
        if(email[i] == '@') { 
            break;
        }
        se += email[i];
    }

    // check password validation
    int pwrd_Len = strlen(s);
    if(pwrd_Len < 8) { 
        return -1;
    }
    if(pwrd_Len > 20) { 
        return -2;
    } 
    // check if password contains username
    if(se.size() == 0) { 
        return -300;
    }
    for(int i = 0; i < pwrd_Len; ++i) { 
        if(s[i] == se[0]) { 
            int se_Len = se.size();
            bool containsUsrname = true;
            if(pwrd_Len - i < se_Len) { 
                continue;
            }
            for(int j = 1; j < se_Len; ++j) { 
                if(s[i + j] != se[j]){
                    containsUsrname = false;
                    break;
                }
            }
            if(containsUsrname) { 
                return -(300 + i);
            }
        }
    }
    // check if there are more than 2 same consecutive words
    for(int i = 0; i < pwrd_Len - 2; ++i) { 
        if(s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    }
    // check if there exists a special keyword ('@', '!', '#', '$', '%') or invalid keywords
    int countSpecialKeyWord = 0;
    int invalidIndex = -1;
    for(int i = 0; i < pwrd_Len; ++i) { 
        if(s[i] == '@' || s[i] == '!' || s[i] == '#' || s[i] == '$' || s[i] == '%') { 
            ++countSpecialKeyWord;
        }
        else if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '1' || s[i] > '9')) { 
            if(invalidIndex == -1) { 
                invalidIndex = i;
            }
        }
    }  
    
    // if no special keywords found
    if(countSpecialKeyWord == 0) { 
        return -5;
    }
    else if(invalidIndex != -1) {
        return invalidIndex;
    }

    // valid password
    return -10;
}


//! Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // vector<string> v(num_pwds);

    // for(int i = 0; i < num_pwds; ++i) { 
    //     string s(arr_pwds[i]);
    //     v[i] = s;
    // }

    int maxCnt = 0;
    int idx = 0;
    int maxLength = 0;
    for(int i = 0; i < num_pwds; ++i) { 
        int cnt = 1;
        // int Len = v[i].length();
        int Len = strlen(arr_pwds[i]);
        for(int j = i + 1; j < num_pwds; ++j) { 
            if(strcmp(arr_pwds[j], arr_pwds[i]) == 0) { 
                ++cnt;
            }
        }

        if(cnt > maxCnt) { 
            maxCnt = cnt;
            idx = i;
            maxLength = Len;
        }
        else if(cnt == maxCnt) { 
            if(Len > maxLength) { 
                maxLength = Len;
                maxCnt = cnt;
                idx = i;
            }            
        }
    }

    return idx;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////