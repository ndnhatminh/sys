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

void hpCheck(int& HP) {
    if (HP>666) {
        HP=666;
    }
    if (HP<0) {
        HP=0;
    }
}

void expCheck(int& EXP) {
    if (EXP>600) {
        EXP=600;
    }
    if (EXP<0) {
        EXP=0;
    }
}

void moneyCheck(int& M) {
    if (M>3000) {
        M=3000;
    }
    if (M<0) {
        M=0;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1<0 || e1>99) {
        return -99;
    } else {
    expCheck(exp1);
    expCheck(exp2);
    // Case 1
    if (e1>=0 && e1<=3) {
        if (e1==0) {
            exp2 += 29;
        } else if (e1==1) {
            exp2 += 45;
        } else if (e1==2) {
            exp2 += 75;
        } else if (e1==3) {
            exp2 += 149;
        }
        int D;
        D = e1*3 + exp1*7;
        if (D%2==0) {
            exp1 += ceil((D/200.0)-0.00000000001);
        } else {
            exp1 -= floor((D/100.0)-0.00000000001);
        }
    }
    // Case 2
    if (e1>=4 && e1<=99) {
        if (e1>=4 && e1<=19) {
            exp2 += ceil((e1/4.0)-0.00000000001)+19;
        } else if (e1>=20 && e1<=49) {
            exp2 += ceil((e1/9.0)-0.00000000001)+21;
        } else if (e1>=50 && e1<=65) {
            exp2 += ceil((e1/16.0)-0.00000000001)+17;
        } else if (e1>=66 && e1<=79) {
            exp2 += ceil((e1/4.0)-0.00000000001)+19;
            if (exp2>200) {
                exp2 += ceil((e1/9.0)-0.00000000001)+21;
            }
        } else if (e1>=80 && e1<=99) {
            exp2 += ceil((e1/4.0)-0.00000000001)+19;
            exp2 += ceil((e1/9.0)-0.00000000001)+21;
            if (exp2>400) {
                exp2 += ceil((e1/16.0)-0.00000000001)+17;
                exp2 = ceil((exp2*1.15)-0.00000000001);
            }
        }
        exp1 -= e1;
    }
    expCheck(exp1);
    expCheck(exp2);
    return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2<0 || E2>99) {
        return -99;
    } else {
    hpCheck(HP1);
    expCheck(EXP1);
    moneyCheck(M1);
    // Road 1
    int S1 = pow(round(sqrt(EXP1)),2);
    double P1;
    if (EXP1>=S1) {
        P1 = 1.0;
    } else {
        P1 = ((EXP1/S1)+80.0)/123.0;
    }
    // Road 2
    int initialMoney = M1/2, paidMoney = 0;
    if (M1!=0) {
        if (E2%2==1) {
            while (paidMoney<=initialMoney) {
                if (HP1<200) {
                    HP1 = ceil((HP1*1.3)-0.00000000001);
                    M1 -= 150;
                    paidMoney += 150;
                } else {
                    HP1 = ceil((HP1*1.1)-0.00000000001);
                    M1 -= 70;
                    paidMoney += 70;//
                }
                hpCheck(HP1);
                moneyCheck(M1);
                if (paidMoney>initialMoney) {
                    break;
                }
                if (EXP1<400) {
                    M1 -= 200;
                    paidMoney += 200;
                } else {
                    M1 -= 120;
                    paidMoney += 120;
                }
                EXP1 = ceil((EXP1*1.13)-0.00000000001);
                moneyCheck(M1);
                expCheck(EXP1);
                if (paidMoney>initialMoney) {
                    break;
                }
                if (EXP1<300) {
                    M1 -= 100;
                    paidMoney += 100;
                } else {
                    M1 -= 120;
                    paidMoney += 120;
                }
                EXP1 = ceil((EXP1*0.9)-0.00000000001);
                moneyCheck(M1);
                expCheck(EXP1);
                if (paidMoney>initialMoney) {
                    break;
                }
            }
            HP1 = ceil((HP1*0.83)-0.00000000001);
            EXP1 = ceil((EXP1*1.17)-0.00000000001);
            hpCheck(HP1);
            expCheck(EXP1);
        } else {
            if (M1>0) {
                if (HP1<200) {
                    HP1 = ceil((HP1*1.3)-0.00000000001);
                    M1 -= 150;
                } else {
                    HP1 = ceil((HP1*1.1)-0.00000000001);
                    M1 -= 70;
                }
            }
            hpCheck(HP1);
            moneyCheck(M1);
            if (M1>0) {
                if (EXP1<400) {
                    M1 -= 200;
                } else {
                    M1 -= 120;
                }
                EXP1 = ceil((EXP1*1.13)-0.00000000001);
            }
            moneyCheck(M1);
            expCheck(EXP1);
            if (M1>0) {
                if (EXP1<300) {
                    M1 -= 100;
                } else {
                    M1 -= 120;
                }
                EXP1 = ceil((EXP1*0.9)-0.00000000001);
            }
            moneyCheck(M1);
            expCheck(EXP1);
            HP1 = ceil((HP1*0.83)-0.00000000001);
            EXP1 = ceil((EXP1*1.17)-0.00000000001);
            hpCheck(HP1);
            expCheck(EXP1);
        }
    } else {
        HP1 = ceil((HP1*0.83)-0.00000000001);
        EXP1 = ceil((EXP1*1.17)-0.00000000001);
        hpCheck(HP1);
        expCheck(EXP1);
    }
    int S2 = pow(round(sqrt(EXP1)),2);
    double P2;
    if (EXP1>=S2) {
        P2 = 1.0;
    } else {
        P2 = ((EXP1/S2)+80.0)/123.0;
    }
    // Road 3
    const int P[10] = {32,47,28,79,100,50,22,83,64,11};
    int i = (E2%10 + E2/10)%10;
    double P3 = P[i]/100.0;
    double finalP = (P1+P2+P3)/3.0;
    // Final
    if (P1==1 && P2==1 && P3==1) {
        EXP1 = ceil((EXP1*0.75)-0.00000000001);
    } else if (finalP<0.5) {
        HP1 = ceil((HP1*0.85)-0.00000000001);
        EXP1 = ceil((EXP1*1.15)-0.00000000001);
    } else {
        HP1 = ceil((HP1*0.9)-0.00000000001);
        EXP1 = ceil((EXP1*1.2)-0.00000000001);
    }
    hpCheck(HP1);
    expCheck(EXP1);
    return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0 || E3>99) {
        return -99;
    } else {
    hpCheck(HP1);
    hpCheck(HP2);
    expCheck(EXP1);
    expCheck(EXP2);
    int a[10][10] = {};
    int row=0, column=0;
    // Taxi Point
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            a[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    // Meet Location
    for (int i = 0; i< 10; i++) {
        for (int j=0; j<10; j++) {
            if (a[i][j] > E3*2) {
                row++;
            }
            if (a[i][j] < (-E3)) {
                column++;
            }
        }
    }
    while (row>9) {
        row = row/10 + row%10;
    }
    while (column>9) {
        column = column/10 + column%10;
    }
    // Sherlock and Watson Point
    int max=0;
    int i=row, m=row, j=column, n=column;
    while (i>=0 && j>=0) {
        if (a[i][j]>max) {
            max = a[i][j];
        }
        i--;
        j--;
    }
    i = row + 1, j = column + 1;
    while (i<10 && j<10) {
        if (a[i][j]>max) {
            max = a[i][j];
        }
        i++;
        j++;
    }
    while (m<10 && n>=0) {
        if (a[m][n]>max) {
            max = a[m][n];
        }
        m++;
        n--;
    }
    m = row - 1, n = column + 1;
    while (m>=0 && n<10) {
        if (a[m][n]>max) {
            max = a[m][n];
        }
        m--;
        n++;
    }
    // Final
    if (abs(max)>=abs(a[row][column])) {
        EXP1 = ceil((EXP1*1.12)-0.00000000001);
        EXP2 = ceil((EXP2*1.12)-0.00000000001);
        HP1 = ceil((HP1*1.1)-0.00000000001);
        HP2 = ceil((HP2*1.1)-0.00000000001);
        expCheck(EXP1);
        expCheck(EXP2);
        hpCheck(HP1);
        hpCheck(HP2);
        return max;
    } else {
        EXP1 = ceil((EXP1*0.88)-0.00000000001);
        EXP2 = ceil((EXP2*0.88)-0.00000000001);
        HP1 = ceil((HP1*0.9)-0.00000000001);
        HP2 = ceil((HP2*0.9)-0.00000000001);
        expCheck(EXP1);
        expCheck(EXP2);
        hpCheck(HP1);
        hpCheck(HP2);
        return a[row][column];
    }
    return -1;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    // Create se
    string se;
    for (int i=0; i<strlen(email); i++) {
        if (email[i]=='@') {
            break;
        }
        se += email[i];
    }
    // Find se in s
    string S=s;
    size_t find = S.find(se);
    // Find duplication
    int duplicate = -1;
    for (int i=0; i<strlen(s); i++) {
        if (s[i]==s[i+1] && s[i]==s[i+2]) {
            duplicate = i;
            break;
        }
    }
    // Find valid special char
    int valid=0, invalid=0;
    int index;
    for (int i=0; i<strlen(s); i++) {
        if (!isalnum(s[i])) {
                if (s[i]=='!' || s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%') {
                    valid++;
                    break;
                }
        }
    }
    // Find invalid special char
    for (index=0; index<strlen(s); index++) {
        if (!isalnum(s[index])) {
                if (s[index]!='!' && s[index]!='@' && s[index]!='#' && s[index]!='$' && s[index]!='%') {
                    invalid++;
                    break;
                }
        }
    }
    // Results
    if (strlen(s)<8) {
        return -1;
    } else if (strlen(s)>20) {
        return -2;
    } else if (find!=string::npos) {
        return -(300+find);
    } else if (duplicate!=-1) {
        return -(400+duplicate);
    } else if (valid==0) {
        return -5;
    } else if (invalid!=0) {
        return index;
    } else {
        return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int index=0, freq=0, length=0;
    for (int i=0; i<num_pwds; i++) {
        int count = 0;
        for (int j=0; j<num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }
        if (count > freq || (count == freq && strlen(arr_pwds[i]) > length)) {
            freq = count;
            length = strlen(arr_pwds[i]);
            index = i;
        }
    }
    return index;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////