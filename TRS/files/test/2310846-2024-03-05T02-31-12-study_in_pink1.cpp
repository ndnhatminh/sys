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
bool checkMst(int E) {
    if((E > 99) || (E < 0))
        return true;
    else
        return false;
}

int roundUp(double val) {
    if (val == int(val))
        return val;
    else {
        val = val + 0.99999;
        return int(val);
    }
}

void check(int & value, char inf) {

    if (value < 0) value = 0;
    else {
        switch (inf)
        {
        case 'H':
            if (value > 666) value = 666;
            break;
        case 'E':
            if (value > 600) value = 600;
            break;
        case 'M':
            if (value > 3000) value = 3000;
            break;
        default:
            break;
        }
    }
}

double eventTask2(int EXP) {
    double P = 0.0;
    //cout << round(sqrt(EXP)) << endl;
    double S = round(sqrt(EXP)) * round(sqrt(EXP));
    //cout << S << endl;
    if (EXP >= S) P = 1;
    else P = ((EXP / S) + 80) / 123;
    //cout << P << endl;
    //cout << endl;
    return P;
}

void event1(int & HP1, int & M1) {
    //Food and bervage
    if (HP1 < 200) {
        HP1 = roundUp(HP1*1.3);
        M1 -= 150;
    }
    else {
        HP1 = roundUp(HP1*1.1);
        M1 -= 70;
    }
    check(HP1, 'H');
    check(M1, 'M');
}

void event2(int & EXP1, int & M1) {    
    //Transportation
    if (EXP1 < 400) {
        M1 -= 200;
    }
    else {
        M1 -= 120;
    }
    EXP1 = roundUp(EXP1*1.13);
    check(EXP1, 'E');
    check(M1, 'M');
}

void event3(int & EXP1, int & M1) {
    //Meet a homless person
    if (EXP1 < 300) {
        M1 -= 100;
    }
    else {
        M1 -= 120;
    }
    EXP1 = roundUp(EXP1*0.9);
    check(EXP1, 'E');
    check(M1, 'M');
}

int findMax(int num1, int num2) {
    if (num1 > num2) return num1;
    else return num2;
}

void mergeNum(int & num){
    while (num/10 != 0) {
        num = (num/10) + (num%10);
    }
}

//if check == 2 means s has more than 2 characters which has the same value in a row. 
//At first check = 0;
bool checkSCI(const char * s, int & sci) {
    for(int i = 0; i < strlen(s) - 2; i++) {
        if((s[i] == s[i+1]) && (s[i] == s[i+2])) {
            sci = i;
            return true;
        }
    }
    return false;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (checkMst(e1)) {
        return -99;
    }
    else {
        check(exp1, 'E');
        check(exp2, 'E');
        if (e1 < 4) { //4.1.1
            //Watson
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
            case 3:
                exp2 += (29 + 45 + 75);
                break;
            }
            
            //Sherlock
            double D = e1*3 + exp1*7;
            if (int(D) % 2 == 0) exp1 = roundUp(exp1 + (D/200));
            else exp1 = roundUp(exp1 - (D/100));
        }
        else { // 4.1.2
            //Watson
            if  (e1 < 20) exp2 = roundUp(exp2 + (e1/4.0 + 19));
            else if (e1 < 50) exp2 = roundUp(exp2 + (e1/9.0 + 21));
            else if (e1 < 66) exp2 = roundUp(exp2 + (e1/16.0 + 17));
            else if (e1 < 80) {
                exp2 = roundUp(exp2 + (e1/4.0 + 19));
                if (exp2 > 200) exp2 = roundUp(exp2 + (e1/9.0 + 21));
            }
            else {
                exp2 = roundUp(exp2 + (e1/4.0 + 19));
                exp2 = roundUp(exp2 + (e1/9.0 + 21));
                if (exp2 > 400) {
                    exp2 = roundUp(exp2 + (e1/16.0 + 17));
                    exp2 = roundUp(exp2*1.15);
                }
            }

            //Sherlock
            exp1 -= e1;
        }
        check(exp1, 'E');
        check(exp2, 'E');
        return exp1 + exp2;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (checkMst(E2)) {
        return -99;
    }
    else {
        check(HP1, 'H');
        check(EXP1, 'E');
        check(M1, 'M');
        double P1, P2;
        int P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        
        //Road 1
        P1 = eventTask2(EXP1);

        //Road 2
        if (M1 != 0) {
            if ((E2 % 2 != 0)) {
                int totalM1 = M1;
                while (true) {
                    event1(HP1, M1);
                    if(0.5*totalM1 > M1) break;
                    event2(EXP1, M1);
                    if(0.5*totalM1 > M1) break;
                    event3(EXP1, M1);
                    if(0.5*totalM1 > M1) break;
                }
            }
            else {
                event1(HP1, M1);
                if(M1 != 0) {
                    event2(EXP1, M1);
                    if(M1 != 0) {
                        event3(EXP1, M1);
                    }
                }
            }
        }
        HP1 = roundUp(HP1*0.83);
        EXP1 = roundUp(EXP1*1.17);
        check(HP1, 'H');
        check(EXP1, 'E');
        P2 = eventTask2(EXP1);

        //Road 3
        int i;
        if(int(E2/10) == 0) i = E2;
        else {
            int val1 = E2/10;
            int val2 = E2%10;
            i = (val1 + val2)%10;
        }
        double sP = (P1 + P2 + (P3[i]/100.0))/3.0;
        //cout << sP << endl;
        //After going through 3 routes
        if(sP == 1.0) {
            EXP1 = roundUp(EXP1*0.75);
        }
        else if(sP < 0.5) {
            HP1 = roundUp(HP1*0.85);
            check(HP1, 'H');
            EXP1 = roundUp(EXP1*1.15);
        }
        else {
            HP1 = roundUp(HP1*0.90);
            check(HP1, 'H');
            EXP1 = roundUp(EXP1*1.20); 
        }
        check(EXP1, 'E');

        return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (checkMst(E3)) {
        return -99;
    }
    else {
        check(HP1, 'H');
        check(EXP1, 'E');
        check(HP2, 'H');
        check(EXP2, 'E');
        int map[10][10], chasingMap[10][10];
        int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int maxValue, i1 = 0, j1 = 0;
        
        //Draw the map of the chased taxi
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                map[i][j] = ((E3*j) + (i*2))*(i - j);
                if(map[i][j] > E3*2) i1++;
                if(map[i][j] < -E3) j1++;
                //cout << map[i][j] << "\t";
            }
            //cout << endl;
        }
        //cout << endl;

        //Draw another map for Sherlock and his colleague
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                maxValue = map[i][j];
                int k = 0;
                while((i + k < 10) && (j + k < 10)) {
                    maxValue = findMax(maxValue, map[i + k][j + k]);
                    k++;
                }
                k = 0;
                while((i - k >= 0) && (j - k >= 0)) {
                    maxValue = findMax(maxValue, map[i - k][j - k]);
                    k++;
                }
                k = 0;
                while((i + k < 10) && (j - k >= 0)) {
                    maxValue = findMax(maxValue, map[i + k][j - k]);
                    k++;
                }
                k = 0;
                while((i - k >= 0) && (j + k < 10)) {
                    maxValue = findMax(maxValue, map[i - k][j + k]);
                    k++;
                }
                chasingMap[i][j] = maxValue;
                //cout << chasingMap[i][j] << "\t";
            }
            //cout << endl;
        }

        //Update stats
        mergeNum(i1);
        mergeNum(j1);
        if (abs(map[i1][j1]) > chasingMap[i1][j1]) {
            HP1 = roundUp(HP1*0.9);
            EXP1 = roundUp(EXP1*0.88);
            HP2 = roundUp(HP2*0.9);
            EXP2 = roundUp(EXP2*0.88);
            check(HP1, 'H');
            check(HP2, 'H');
            check(EXP1, 'E');
            check(EXP2, 'E');
            return map[i1][j1];
        }
        else {
            HP1 = roundUp(HP1*1.1);
            EXP1 = roundUp(EXP1*1.12);
            HP2 = roundUp(HP2*1.1);
            EXP2 = roundUp(EXP2*1.12);
            check(HP1, 'H');
            check(HP2, 'H');
            check(EXP1, 'E');
            check(EXP2, 'E');
            return chasingMap[i1][j1];
        }
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) //case 1
        return -1;
    else if (strlen(s) > 20) //case 2
        return -2;
    else {
        int sci = 0; 
        int matchChar;
        const char * at = strrchr(email, '@');
        const int lenofse = strlen(email) - strlen(at);
        char se[lenofse];
        strncpy(se, email, lenofse); //extract the string before @
        se[lenofse] = '\0';
        const char * sei = strstr(s, se); //finding if password s contains se or not.
        if (sei) //case 3
            return -(300 + sei - s);
        else if (checkSCI(s, sci)) //case 4
            return -(400 + sci);
        else { //case 5
            int result1 = 0;
            for(int i = 0; i < strlen(s); i++) {
                if((s[i] == 33) || ((s[i] >= 35) && (s[i] <= 37)) || (s[i] == 64))
                    break;
                else 
                    result1 = i + 1;
            }
            if(result1 == strlen(s))
                return -5;
            else { //case 6
                int result = 0;
                for(int i = 0; i < strlen(s); i++) {
                    if((s[i] == 33) || ((s[i] >= 35) && (s[i] <= 37)) || ((s[i] >= 64) && (s[i] <= 90)) || ((s[i] >= 97) && (s[i] <= 122)) || ((s[i] >= 48) && (s[i] <= 57)))
                        result = i + 1;
                    else 
                        break;
                }
                if(result != strlen(s))
                    return result;
                else //valid password
                    return -10;
            }
        }
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int shortList[num_pwds*3];
    int reList[num_pwds], reMax = 1, reLen = 0;;
    int k = 0, result = 0;

    for (int i = 0; i < num_pwds; i++) {
        shortList[3*i] = i;                             // its position
        shortList[3*i + 1] = strlen(arr_pwds[i]);       // its length
        shortList[3*i + 2] = 1;
        for (int j = i + 1; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                shortList[3*i + 2]++;                   // the number of repetitions
        }
    }
    
    for (int i = 2; i < (num_pwds*3); i+=3) {
        if(reMax <  shortList[i])
            reMax =  shortList[i];
    }

    while (true) {
        for (int i = 0; i < num_pwds; i++) {
            if (shortList[3*i + 2] ==  reMax) {
                reList[k]= shortList[3*i];
                k++;
            }
        }
        break;
    }

    for (int i = 0; i < k; i++) {
        if(reLen <  shortList[3*reList[i] + 1]) {
            reLen =  shortList[3*reList[i] + 1];
        }
    }
    
    for (int i = 0; i < k; i++) {
        if(reLen ==  shortList[3*reList[i] + 1]) {
            result =  shortList[3*reList[i]];
            break;
        }
    }
    
    return result;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////