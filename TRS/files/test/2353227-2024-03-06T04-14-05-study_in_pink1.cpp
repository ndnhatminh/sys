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
        ifs >> HP1 >> HP2 >>
            EXP1 >> EXP2 >>
            M1 >> M2 >>
            E1 >> E2 >> E3;
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

// Task 1
void correct(int & variable, int firstLimit, int secondLimit) {
    variable = (variable <= firstLimit) ? firstLimit : (variable >= secondLimit) ? secondLimit : variable;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    correct(exp1, 0, 600);
    correct(exp2, 0, 600);
    if (e1 < 0 || e1 > 99) return -99;
    // TODO: Complete this function
    if (e1 < 4) {
        switch (e1) {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += 149;
        }
        correct(exp2, 0, 600);
        int D;
        D = e1 * 3 + exp1 * 7;
        float d = D;
        exp1 = (D % 2 == 0) ? ceil(exp1 + d / 200) : ceil(exp1 - d / 100);
        correct(exp1, 0, 600);
        return exp1 + exp2;
    } else {
        float E1 = e1;
        switch (e1) {
        case 4 ... 19:
            exp2 += ceil(E1 / 4) + 19;
            break;
        case 20 ... 49:
            exp2 += ceil(E1 / 9) + 21;
            break;
        case 50 ... 65:
            exp2 += ceil(E1 / 16) + 17;
            break;
        case 66 ... 79:
            exp2 += ceil(E1 / 4) + 19;
            correct(exp2, 0, 600);
            if (exp2 > 200) {
                exp2 += ceil(E1 / 9) + 21;
            }
            break;
        case 80 ... 99:
            exp2 += ceil(E1 / 4) + 19 + ceil(E1 / 9) + 21;
            if (exp2 > 400) {
                exp2 += ceil(E1 / 16 + 17);
                correct(exp2, 0, 600);
                exp2 = ceil(exp2 * 1.15);
            }
            break;
        }
    }
    exp1 -= e1;
    correct(exp1, 0, 600);
    correct(exp2, 0, 600);
    return exp1 + exp2;
}

// Task 2
int findSquare(int num) {
    if ((pow(ceil(float(sqrt(num))), 2) - num) > (num - pow(floor(float(sqrt(num))), 2)))
        return pow(floor(float(sqrt(num))), 2);
    else return pow(ceil(float(sqrt(num))), 2);
}
float findPropability(int exp1, int s) {
    float P = (s <= exp1) ? 1.0 : (((float(exp1)) / float(s) + float(80) )/ float(123));
    return P;
}
bool moneyRequirement(int M1, int spent, int initial, int E2) {
    return ((E2%2 == 0) && M1 == 0) or ((E2%2 != 0) && (2*spent > initial));
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //Road 1
    if (E2 < 0 || E2 > 99) return -99;
    correct(EXP1, 0, 600);
    correct(HP1, 0, 666);
    correct(M1, 0, 3000);
    int S1 = findSquare(EXP1);
    float P1 = findPropability(EXP1, S1);
    //Road 2
    int initial = M1;
    int spent = 0;
    int count = 0;
    do {

        if (HP1 < 200) {
            HP1 = ceil(HP1 * float(1.3));
            M1 -= 150;
            spent += 150;
        } else {
            HP1 = ceil(HP1 * float(1.1));
            M1 -= 70;
            spent += 70;
        }
        correct(HP1, 0, 666);
        correct(M1, 0, 3000);
        if (moneyRequirement(M1, spent, initial, E2) == true)
            break;

        if (EXP1 < 400) {
            M1 -= 200;
            spent += 200;
        } else {
            M1 -= 120;
            spent += 120;

        }
        EXP1 = ceil(EXP1 * float(1.13));
        correct(M1, 0, 3000);
        correct(EXP1, 0, 600);
        if (moneyRequirement(M1, spent, initial, E2) == true)
            break;
        if (EXP1 < 300) {
            M1 -= 100;
            spent += 100;
        } else {
            M1 -= 120;
            spent += 120;
            
        }
        EXP1 = ceil(EXP1 * float(0.9));
        correct(M1, 0, 3000);
        if (moneyRequirement(M1, spent, initial, E2) == true)
            break;
        count++;

    } while ((count < 1) or E2 % 2 != 0);
    HP1 = ceil(HP1 * float(0.83));
    correct(HP1, 0, 666);
    EXP1 = ceil(EXP1 * float(1.17));
    correct(EXP1, 0, 600);
    int S2 = findSquare(EXP1);
    float P2 = findPropability(EXP1, S2);
    //Road 3
    const float P[10] = {
        0.32,
        0.47,
        0.28,
        0.79,
        1.0,
        0.50,
        0.22,
        0.83,
        0.64,
        0.11
    };
    int sum = 0;
    while (E2 != 0) {
        sum = sum + E2 % 10;
        E2 = E2 / 10;
    }
    sum = sum % 10;
    float P3 = P[sum];
    float averageP = (P1 + P2 + P3) / float(3.0);
    if (P1 == float(1.0) and P2 == float(1.0) and P3 == float(1.0)) {
        EXP1 = ceil(EXP1 * float(0.75));
    } else if (averageP < 0.5) {
        EXP1 = ceil(EXP1 * float(1.15));
        HP1 = ceil(HP1 * float(0.85));
    } else {
        EXP1 = ceil(EXP1 * 1.2);
        HP1 = ceil(HP1 * float(0.9));
    }
    correct(HP1, 0, 666);
    correct(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}

// Task 3
int digitSum(int n) {
    while (n > 9) {
        n = n % 10 + (n / 10);
    }
    return n;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    correct(HP1, 0, 666);
    correct(EXP1, 0, 600);
    correct(HP2, 0, 666);
    correct(EXP2, 0, 600);
    if (E3 < 0 || E3 > 99) return -99;
    int matrix[10][10];
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > (2 * E3)) {
                count1++;
            }
            if (matrix[i][j] < ((-1) * E3)) {
                count2++;
            }
           
        }
        
    }
    int diagonalMatrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            diagonalMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int n = min((10 - i), (10 - j));
            int m = min((10 - i), (j + 1));
            for (int k = 0; k < n; k++) {
                diagonalMatrix[i][j] = max(diagonalMatrix[i][j], matrix[i + k][j + k]);
            }
            for (int l = 0; l < m; l++) {
                diagonalMatrix[i][j] = max(diagonalMatrix[i][j], matrix[i + l][j - l]);
            }
        }
    }
    
    int coords1 = digitSum(count1);
    int coords2 = digitSum(count2);
    if (abs(matrix[coords1][coords2]) > diagonalMatrix[coords1][coords2]) {
        EXP1 = ceil(EXP1 * float(0.88));
        EXP2 = ceil(EXP2 * float(0.88));
        HP1 = ceil(HP1 * float(0.9));
        HP2 = ceil(HP2 * float(0.9));
    } else {
        EXP1 = ceil(EXP1 * float(1.12));
        EXP2 = ceil(EXP2 * float(1.12));
        HP1 = ceil(HP1 * float(1.1));
        HP2 = ceil(HP2 * float(1.1));
    }
    correct(HP1, 0, 666);
    correct(EXP1, 0, 600);
    correct(HP2, 0, 666);
    correct(EXP2, 0, 600);
    if (abs(matrix[coords1][coords2]) > diagonalMatrix[coords1][coords2]) {
        return matrix[coords1][coords2];
    } else return diagonalMatrix[coords1][coords2];
}

// Task 4
int find(const char * s, int stringCount,
    const char * se, int seCount) {
    for (int c = 0; c <= (stringCount - seCount); c++) {
        bool found = true;
        for (int d = 0; d < seCount; d++) {
            if (s[c + d] != se[d]) found = false;
        }
        if (found) return c;
    }
    return -1;
}
int checkPassword(const char * s,
    const char * email) {
    // TODO: Complete this function
    char * se = (char * ) malloc(101);
    int seCount = 0;
    while (email[seCount] != '@') {
        se[seCount] = email[seCount];
        seCount++;
    }
    se[seCount + 1] = '\0';
    int stringCount = 0;
    while (s[stringCount] != '\0') {
            stringCount++;
    }
    //Error 1/2
    if (stringCount < 8) {
        return -1;
    } else if (stringCount > 20) {
        return -2;
    }
    //Error 3
    int index = find(s, stringCount, se, seCount);
    if (index != -1)
        return -(300 + index);
    //Error 4
    for (int e = 0; e < (stringCount - 2); e++) {
        if ((s[e] == s[e + 1]) && (s[e + 1] == s[e + 2])) {
            return -(400 + e);
        }
    }
    //Error 5

    for (int f = 0; f <= stringCount; f++) {
        if (s[f] == '!' || s[f] == '@' || s[f] == '#' || s[f] == '$' || s[f] == '%') {
            break;
        }
        if (f == stringCount) {
            return -5;
        }
    }
    //Error 6
    bool found = false;
    char Allowed[67] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        '@','#','%','$','!',
        '1','2','3','4','5','6','7','8','9','0'
    };
    for (int g = 0; g < stringCount; g++) {
        for (int h = 0; h < 58; h++) {
            if (s[g] == Allowed[h])
                found = true;
        }
        if (found == false) {
            return g;
        }
        found = false;
    }

    return -10;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int length=0;
    int repeatedCount=0;
    int cancelled[num_pwds];
    int repeatedIndex[num_pwds];
    int lengthIndex[num_pwds];
    string placeholder[num_pwds];
    for (int i=0; i<num_pwds;i++) {
        placeholder[i]=arr_pwds[i];
    }
    for (int i=0; i<num_pwds;i++) {
        cancelled[i]=0;
        repeatedIndex[i]=0;
        lengthIndex[i]=0;
    }
    
    
    for (int i=0;i<num_pwds;i++) {
        length=0;
        for (int k=0;k<20;k++) {
            if(placeholder[i][k]!='\0')
            {   
                length++;
                lengthIndex[i]=length;
            }
            else {
                break;
            }
        }
        if (cancelled[i]!=-1) {
            for (int j=0;j<num_pwds;j++) {
                if (placeholder[i]==placeholder[j]){
                repeatedCount++;
                cancelled[j]=-1;
                repeatedIndex[i]=repeatedCount;
            }
            }
        }
        repeatedCount=0;
    }
    int maxIndex=repeatedIndex[0];
    
    for (int i=0;i<(num_pwds-1);i++) {
        if (repeatedIndex[i+1]>maxIndex)
        {maxIndex=repeatedIndex[i+1];}
        else continue;
    }
    for (int i = 0; i<num_pwds;i++) {
  
        if (repeatedIndex[i]!=maxIndex){
            lengthIndex[i]=-1;
        }
    }

    int longestIndex=-3;
    int position=0;
    for (int i = (num_pwds-1); i>=0;i--) {
        if (lengthIndex[i]>=longestIndex) {
        longestIndex=lengthIndex[i];
        position = i;
        }
    }
    
 return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////