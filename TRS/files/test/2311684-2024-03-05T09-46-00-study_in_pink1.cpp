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

void testEXP(int & x) {
    if(x < 0) x = 0;
    else if(x > 600) x = 600;
}

void testM(int & x) {
    if(x < 0) x = 0;
    else if(x > 3000) x = 3000;
}

void testHP(int & x) {
    if(x < 0) x = 0;
    else if(x > 666) x = 666;
}

void event1(
    int & HP1,
    int & EXP1,
    int & M1,
    float & spend,
    float & max
) {
    testEXP(EXP1);
    testHP(HP1);
    testM(M1);

    if(HP1 < 200) {
            HP1 = ceil((130*HP1)/100.0);
            M1 -= 150;
            spend += 150;
        }
    else {
        HP1 = ceil((110*HP1)/100.0);
        M1 -= 70;
        spend += 70;
    }
    testHP(HP1); testM(M1);
}

void event2(
    int & HP1,
    int & EXP1,
    int & M1,
    float & spend,
    float & max
) {
    testEXP(EXP1);
    testHP(HP1);
    testM(M1);

    if(EXP1 < 400) {
        M1 -= 200;
        spend += 200;
    }
    else {
        M1 -= 120;
        spend += 120;
    }
    testM(M1);
    EXP1 = ceil(EXP1*1.13);
    testEXP(EXP1);
}
    
void event3(
    int & HP1,
    int & EXP1,
    int & M1,
    float & spend,
    float & max
) {
    testEXP(EXP1);
    testHP(HP1);
    testM(M1);

    if(EXP1 < 300) {
        M1 -= 100;
        spend += 100;
    }
    else {
        M1 -= 120;
        spend += 120;
    }
    testM(M1);
    EXP1 = ceil((EXP1*90)/100.0);
    testEXP(EXP1);
}

double probab(int & EXP1) {
    int s = (int(sqrt(EXP1)+0.5))*(int(sqrt(EXP1)+0.5));
    if(EXP1 >= s) return 1;
    else return (double(EXP1)/double(s) + 80)/123.0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    testEXP(exp1);
    testEXP(exp2);

    if(e1 >= 0 && e1 <= 3) {
        switch(e1) {
            case 0: {
                exp2 += 29;
                break;
            }
            case 1: {
                exp2 += 45;
                break;
            }
            case 2: {
                exp2 += 75;
                break;
            }
            case 3: {
                exp2 += 149;
                break;
            }
        }
        testEXP(exp2);
        int d = e1 * 3 + exp1 * 7;
        if(d % 2 == 0) {
            exp1 = ceil(exp1 + (d/200.0));
        }
        else {
            exp1 = ceil(exp1 - (d/100.0));
        }
        testEXP(exp1);
    }
    else if(e1 >= 4 && e1 <= 99) {
        if(e1 >= 4 && e1 <= 19) {
            exp2 += ceil(e1/4.0 + 19);
        }
        else if(e1 >= 20 && e1 <= 49) {
            exp2 += ceil(e1/9.0 + 21);
        }
        else if(e1 >= 50 && e1 <= 65) {
            exp2 += ceil(e1/16.0 + 17);
        }
        else if(e1 >= 66 && e1 <= 79) {
            exp2 += ceil(e1/4.0 + 19);
            testEXP(exp2);
            if(exp2 > 200) {
                exp2 += ceil(e1/9.0 + 21);
            }
        }
        else if(e1 >= 80 && e1 <= 99) {
            exp2 += ceil(e1/4.0 + 19);
            testEXP(exp2);
            exp2 += ceil(e1/9.0 + 21);
            testEXP(exp2);
            if(exp2 > 400) {
                exp2 += ceil(e1/16.0 + 17);
                testEXP(exp2);
                exp2 += ceil(exp2 * 0.15);
                testEXP(exp2);
            }
        }
        exp1 -= e1;
        testEXP(exp1); testEXP(exp2);
    }
    else return -99;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    testEXP(EXP1); 
    testHP(HP1); 
    testM(M1);
    if(E2 < 0 || E2 > 99) return -99;

    //track 1
    double p1 = probab(EXP1);

    //track 2
    if(E2 % 2 != 0) {
        float budget = float(M1/2.0);
        float spend = 0;
        while(spend <= budget) {
            event1(HP1, EXP1, M1, spend, budget);
            if(spend > budget) break;
            event2(HP1, EXP1, M1, spend, budget);
            if(spend > budget) break;
            event3(HP1, EXP1, M1, spend, budget);
        }
        HP1 = ceil((HP1*83)/100.0);
        EXP1 = ceil((EXP1*117)/100.0);
        testHP(HP1); testEXP(EXP1);
    }
    else if(E2 % 2 == 0) {
        float max = M1;
        float t = 0;
        event1(HP1, EXP1, M1, t, max);
        if(M1 == 0) goto skip;
        event2(HP1, EXP1, M1, t, max);
        if(M1 == 0) goto skip;
        event3(HP1, EXP1, M1, t, max);
        skip:
        HP1 = ceil((HP1*83)/100.0);
        EXP1 = ceil((EXP1*117)/100.0);
        testHP(HP1); testEXP(EXP1);
    }
    double p2 = probab(EXP1);

    //track 3
    int P3[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double p3;
    if(E2/10 == 0) {
        p3 = P3[E2]/100.0;
    }
    else {
        int sum = (E2/10) + (E2%10);
        int index = sum%10;
        p3 = P3[index]/100.0;
    }
    //end
    if(p1 == 1 && p2 == 1 && p3 == 1) {
        EXP1 = ceil((EXP1*75)/100.0);
        testEXP(EXP1);
    }
    else {
        double p = (p1 + p2 + p3)/3.0;
        if(p < 0.5) {
            HP1 = ceil((HP1*85)/100.0);
            EXP1 = ceil((EXP1*115)/100.0);
        }
        else {
            HP1 = ceil((HP1*90)/100.0);
            EXP1 = ceil((EXP1*120)/100.0);
        }
        testHP(HP1); testEXP(EXP1);
    }
 return HP1 + EXP1 + M1;
}

// Task 3
int findMax(int taxi[][10], int row, int col) {
    int max = taxi[row][col];
    //DOWN LEFT 
    int a = row+1, b = col+1; 
    while(a <= 9 && b <= 9) {
        if(taxi[a][b] > max) max = taxi[a][b];
        a++;
        b++;
    }
    //UP LEFT
    a = row-1;
    b = col-1;
    while(a >= 0 && b >= 0) {
        if(taxi[a][b] > max) max = taxi[a][b];
        a--;
        b--;
    }
    //DOWN RIGHT
    a = row+1;
    b = col-1;
    while(a <= 9 && b >= 0) {
        if(taxi[a][b] > max) max = taxi[a][b];
        a++;
        b--;
    }
    //UP RIGHT
    a = row-1;
    b = col+1;
    while(a >= 0 && b <= 9) {
        if(taxi[a][b] > max) max = taxi[a][b];
        a--;
        b++;
    }
    if(max < 0) max = abs(max);
    return max;
}

int check(int x) {
    if(x / 10 != 0) {
        x = (x / 10) + (x % 10);
    }
    else {
        return x;
    }
    return check(x);
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    testEXP(EXP1); testEXP(EXP2);
    testHP(HP1); testHP(HP2);
    if(E3 < 0 || E3 > 99) return -99;

    int sw;
    int taxi[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            taxi[i][j] = 0;
        }
    }

    //taxi's arr
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3*j) + (i*2)) * (i-j);
        }
    }

    //meet point
    int row = 0;
    for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(taxi[i][j] > E3*2) {
                    row++;
                }
            }
    }
    row = check(row);
    int col = 0;
    for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(taxi[i][j] < -E3) {
                    col++;
                }
            }
    }
    col = check(col);

    //sherlock & watson's point at meet point
    sw = findMax(taxi, row, col);

    if(abs(sw) >= abs(taxi[row][col])) {
        EXP1 = ceil((EXP1*112)/100.0);
        EXP2 = ceil((EXP2*112)/100.0);
        HP1 = ceil((HP1*110)/100.0);
        HP2 = ceil((HP2*110)/100.0);
        testEXP(EXP1); testEXP(EXP2);
        testHP(HP1); testHP(HP2);
        return sw;
    }
    else {
        EXP1 = ceil((EXP1*88)/100.0);
        EXP2 = ceil((EXP2*88)/100.0);
        HP1 = ceil((HP1*90)/100.0);
        HP2 = ceil((HP2*90)/100.0);
        testEXP(EXP1); testEXP(EXP2);
        testHP(HP1); testHP(HP2);
        return taxi[row][col];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string e = email;
    string str = s;
    string spcChar = "@#%$!";
    int index = e.find("@");
    string se = e.substr(0, index);
    int size = str.length();
    if(size < 8) {
        return -1;
    }
    else if(size > 20) {
        return -2;
    }
    else { 
        if(str.find(se)+1) return -(300+str.find(se));

        for(int i = 0; i < str.length()-1; i++) {
            if(str[i] != str[i+1]) continue;
            else {
                int count = 0;
                for(int j = i; j < i+3; j++) {
                    if(str[i] != str[j+1]) break;
                    else count++;
                }
                if(count >= 2) return -(400+i);
            }
        }

        bool containSpcChar = false;
        bool containStrangeChar = false;
        int indexStrangeChar = 20;
        for(int i = 0; i < str.length(); i++) {
            if(
                //check if str[i] is a normal character
                str[i] >= 'A' && str[i] <= 'Z' ||
                str[i] >= 'a' && str[i] <= 'z' ||
                str[i] >= '0' && str[i] <= '9'
            ) {
                continue;
            }
            else {
                //check if str[i] is a special character
                if(spcChar.find(str[i])+1) {
                    containSpcChar = true;
                }
                //else str[i] is a strange character
                else  {
                    containStrangeChar = true;
                    if(i < indexStrangeChar) indexStrangeChar = i;
                }
            }
        }
        if(!containSpcChar) return -5;
        else if(containStrangeChar) {
            return indexStrangeChar;
        }
        else {
            return -10;
        }
    }
    return -99;
}

// Task 5
const int flag_unprocessed = 0;
const int flag_processed = 1;

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxRepeat = 0;
    int maxLength = strlen(arr_pwds[0]);;
    int index = -1;
    int flag[num_pwds];

    for(int i = 0; i < num_pwds; i++) {
        flag[i] = flag_unprocessed;
    }

    for(int i = 0; i < num_pwds; i++) {
        if(flag[i] == flag_unprocessed) {
            int count = 1;
            int length = strlen(arr_pwds[i]);
            for(int j = i + 1; j < num_pwds; j++) {
                if(flag[j] == flag_unprocessed && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    count++;
                    flag[j] = flag_processed;
                }
            }
            if(count > maxRepeat || (count == maxRepeat && length > maxLength)) {
                maxRepeat = count;
                maxLength = length;
                index = i;
            }
        }
    }
    if(index != -1) return index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////