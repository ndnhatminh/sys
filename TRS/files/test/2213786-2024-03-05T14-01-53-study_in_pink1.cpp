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
//O(1)
int limitHP(int hp) {return (hp > 666)? 666 : (hp < 0)? 0 : hp;} //Limited HP1 and HP2
int limitEXP(int exp) {return (exp > 600)? 600 : (exp < 0)? 0 : exp;} //Limited EXP1 and EXP2
int limitMoney(int m) {return (m > 3000)? 3000 : (m < 0)? 0 : m;} //Limited M1 and M2
bool checkEvent(int e) {return (e > 99 || e < 0)? 0 : 1;} //Limited E1, E2 and E3
// Task 1
//O(1)
int infor1CaseTwoFirstMeet(int exp2, int e1) {return limitEXP((exp2 + e1/4.0 + 19) + 0.999);}
int infor2CaseTwoFirstMeet(int exp2, int e1) {return limitEXP((exp2 + e1/9.0 + 21) + 0.999);}
int infor3CaseTwoFirstMeet(int exp2, int e1) {return limitEXP((exp2 + e1/16.0 + 17) + 0.999);}
int CaseOneFirstMeet(int e1) { //Calculate EXP2 will be add much EXP (+0.5pts)
    if (e1 == 0) return 29;
    else if (e1 == 1) return 45;
    else if (e1 == 2) return 75;
    return 149;
}
void CaseTwoFirstMeet(int & exp2, int e1, bool & checkInfo5CaseTwoFirstMeet) { //Calculate EXP2 will be add much EXP (+1pt)
    if (e1 < 20) exp2 = infor1CaseTwoFirstMeet(exp2, e1);
    else if (e1 < 50) exp2 = infor2CaseTwoFirstMeet(exp2, e1);
    else if (e1 < 66) exp2 = infor3CaseTwoFirstMeet(exp2, e1);
    else if (e1 < 80) {
        exp2 = infor1CaseTwoFirstMeet(exp2, e1);
        if (exp2 > 200) exp2 = infor2CaseTwoFirstMeet(exp2, e1);
    } 
    else {
        exp2 = infor1CaseTwoFirstMeet(exp2, e1);
        exp2 = infor2CaseTwoFirstMeet(exp2, e1);
        if (exp2 > 400) {
            checkInfo5CaseTwoFirstMeet = 1;
            exp2 = infor3CaseTwoFirstMeet(exp2, e1);
        }
    }
}
int firstMeet(int & exp1, int & exp2, int e1) { //MISSION 1 (1.5pts)
    // TODO: Complete this function
    if (!checkEvent(e1)) return -99; //Check E1 has identify
    exp1 = limitEXP(exp1);
    exp2 = limitEXP(exp2);
    if (e1 < 4) {
        exp2 = limitEXP(exp2 + CaseOneFirstMeet(e1));
        int D = e1*3 + exp1*7;
        if (D % 2 == 0) exp1 = limitEXP((exp1 + D/200.0) + 0.999);
        else exp1 = limitEXP((exp1 - D/100.0) + 0.999);
    }
    else {
        bool checkInfor5CaseTwoFirstMeet = false;
        CaseTwoFirstMeet(exp2, e1, checkInfor5CaseTwoFirstMeet);
        if (checkInfor5CaseTwoFirstMeet) exp2 = limitEXP((exp2 * 1.15) + 0.999); //Check there are 3 information be used for bonus 15% total EXP2
        exp1 = limitEXP(exp1 - e1);
    }
    return exp1 + exp2;
}
// Task 2

//O(1)
int event1Way2TraceLuggage(int & HP1, int & M1) {
    if (HP1 < 200) {
        HP1 = limitHP((HP1 * 1.3) + 0.999), M1 = limitMoney(M1 - 150);
        return 150;
    }
    HP1 = limitHP((HP1 * 1.1) + 0.999), M1 = limitMoney(M1 - 70);
    return 70;
}
int event2Way2TraceLuggage(int & EXP1, int & M1) {
    int cost = 200;
    if (EXP1 < 400) M1 = limitMoney(M1 - 200);
    else {M1 = limitMoney(M1 - 120), cost = 120;}
    EXP1 = limitEXP((EXP1 * 1.13) + 0.999);
    return cost;
}
int event3Way2TraceLuggage(int & EXP1, int & M1) {
    int cost = 100;
    if (EXP1 < 300) M1 = limitMoney(M1 - 100);
    else {M1 = limitMoney(M1 - 120), cost = 120;}
    EXP1 = limitEXP((EXP1 * 0.9) + 0.999);
    return cost;
}
double Way1TraceLuggage(int EXP1) {
    double SquareNum = sqrt(EXP1);
    int SNum = int(SquareNum);
    if (SquareNum - SNum >= 0.5) SNum += 1;
    //else if (EXP1 == 0) SNum = 1;
    SNum *= SNum;
    return (EXP1 < SNum)? (EXP1 / SNum + 80)/ 123.0 : 1;
}
//O(N)
double Way2TraceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int cost = 0;
    if (E2 % 2 == 1) {
        double Half_M1 = M1 * 0.5;
        if (M1 != 0) 
            do {
                cost += event1Way2TraceLuggage(HP1, M1);
                //cout << "HP:" << HP1 << ", cost: " << cost << endl;
                if (cost > Half_M1) break;
                cost += event2Way2TraceLuggage(EXP1, M1);
                //cout << "cost:" << cost << endl; 
                if (cost > Half_M1) break;
                cost += event3Way2TraceLuggage(EXP1, M1);
                //cout << "cost3: " << cost << endl;
            } while(cost <= Half_M1);
    }
    else {
        if (M1 != 0) cost = event1Way2TraceLuggage(HP1, M1);
        if (M1 != 0) cost = event2Way2TraceLuggage(EXP1, M1);
        if (M1 != 0) cost = event3Way2TraceLuggage(EXP1, M1);
    }
    HP1 = limitHP((HP1 * 0.83) + 0.999), EXP1 = limitEXP((EXP1 * 1.17) + 0.999);
    return Way1TraceLuggage(EXP1);
}
//O(1)
int Way3TraceLuggage(int E2) {
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    while (E2 >= 10) E2 = (E2 % 10 + E2 / 10) % 10;
    return P[E2];
}
//O(N)
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) { //MISSION 2 (2.5pts)
    // TODO: Complete this function
    if (!checkEvent(E2)) return -99; //Check E2 has identify
    HP1 = limitHP(HP1);
    EXP1 = limitEXP(EXP1);
    M1 = limitMoney(M1);
    double P1 = Way1TraceLuggage(EXP1);
    double P2 = Way2TraceLuggage(HP1, EXP1, M1, E2);
    int P3 = Way3TraceLuggage(E2);
    //cout << "P1: " << P1 << ", P2: " << P2 << ", P3: " << P3 << endl; 
    if (P1 == P2 && P3 == 100 && P1 == 1) EXP1 = limitEXP((EXP1 * 0.75) + 0.999);
    else {
        double P = (P1 + P2 + P3 * 0.01) / 3.0;
        if (P < 0.5) {HP1 = limitHP((HP1 * 0.85) + 0.999), EXP1 = limitEXP((EXP1 * 1.15) + 0.999);}
        else {HP1 = limitHP((HP1 * 0.9) + 0.999), EXP1 = limitEXP((EXP1 * 1.2) + 0.999);}
    }
    return HP1 + EXP1 + M1;
}

// Task 3

//O(log(N))
void findIndex(int & row) {while (row >= 10) row = row / 10 + row % 10;} //Find index Taxi meets Holmes
//O(N^2)
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) { //MISSION 3 (3pts)
    // TODO: Complete this function
    if (!checkEvent(E3)) return -99;
    HP1 = limitHP(HP1);
    EXP1 = limitEXP(EXP1);
    HP2 = limitHP(HP2);
    EXP2 = limitEXP(EXP2);
    int matrix[10][10], row = 0, col = 0; //Make matrix and find index (i, j)
    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j) matrix[i][j] = (E3*j + i*2) * (i - j);
    for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] > E3*2) ++row;
            if (matrix[i][j] < -E3) ++col;
        }
    findIndex(row), findIndex(col);
    int maxValue = matrix[row][col]; //Find max value of both diagonal line in matrix
    for (int i = row + 1, j = col + 1; i < 10 && j < 10; ++i, ++j)
        if (matrix[i][j] > maxValue) maxValue = matrix[i][j]; 
    for (int i = row + 1, j = col - 1; i < 10 && j >= 0; ++i, --j)
        if (matrix[i][j] > maxValue) maxValue = matrix[i][j]; 
    for (int i = row - 1, j = col + 1; i >= 0 && j < 10; --i, ++j)
        if (matrix[i][j] > maxValue) maxValue = matrix[i][j]; 
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (matrix[i][j] > maxValue) maxValue = matrix[i][j]; 
    //cout << maxValue << endl;
    if (abs(maxValue) >= abs(matrix[row][col])) { //Case Holmes meeets the Taxi
        EXP1 = limitEXP((EXP1 * 1.12) + 0.999), EXP2 = limitEXP((EXP2 * 1.12) + 0.999);
        HP1 = limitHP((HP1 * 1.1) + 0.999), HP2 = limitHP((HP2 * 1.1) + 0.999);
        return maxValue;
    }
    EXP1 = limitEXP((EXP1 * 0.88) + 0.999), EXP2 = limitEXP((EXP2 * 0.88) + 0.999);
    HP1 = limitHP((HP1 * 0.9) + 0.999), HP2 = limitHP((HP2 * 0.9) + 0.999);
    return matrix[row][col];
}

// Task 4
//O(N)
int checkSEinS(string S, string se, int sizeS, int sizeSE) { //Find first index in string S has substring sample string se
    for (int i = 0; i < sizeS; ++i) if (se == S.substr(i, sizeSE)) return i;
    return -1;
}
int checkSampleInit(string S, int sizeS) { //Find first index in string S has least 3 sample inits 
    for (int i = 0; i < sizeS - 2; ++i) if (S[i] == S[i + 1] && S[i] == S[i + 2]) return i;
    return -1;
}
bool checkSpecialInit(string S, int sizeS) { //Check in string S hasn't special init
    for (int i = 0; i < sizeS; ++i) 
        if (S[i] == '@' || 
            S[i] == '#' || 
            S[i] == '%' || 
            S[i] == '$' || 
            S[i] == '!'
        ) return true;
    return false;
}
int checkNumAndInitIdentify(string S, int sizeS) { //Find first index in string S hasn't Number, Special, Upper and Lower init
    for (int i = 0; i < sizeS; ++i)
        if (!(S[i] >= '0' && S[i] <= '9') && 
            !(S[i] >= 'a' && S[i] <= 'z') && 
            !(S[i] >= 'A' && S[i] <= 'Z') &&
            S[i] != '@' && 
            S[i] != '#' && 
            S[i] != '%' && 
            S[i] != '$' && 
            S[i] != '!'
        ) return i;
    return -1;
}
int checkPassword(const char * s, const char * email) { //MISSION 4 (1.5pts)
    // TODO: Complete this function
    int sizeEmail = strlen(email), sizeS = strlen(s);
    string S(s), Email(email), se = "";
    for (int i = 0; i < sizeEmail; ++i) //Find string se
        if (email[i] == '@') se = Email.substr(0, i);
    if (sizeS < 8) return -1; //Violate 1
    if (sizeS > 20) return -2; //Violate 2
    int sizeSE = se.length(), firstIndexSEinS = checkSEinS(S, se, sizeS, sizeSE);
    if (firstIndexSEinS >= 0) return -(300 + firstIndexSEinS); //Violate 3
    int firstIndexSampleInit = checkSampleInit(S, sizeS);
    if (firstIndexSampleInit >= 0) return -(400 + firstIndexSampleInit); //Violate 4
    if (!checkSpecialInit(S, sizeS)) return -5; //Violate 5
    int firstIndexNumAndInitNotIdentify = checkNumAndInitIdentify(S, sizeS);
    if (firstIndexNumAndInitNotIdentify >= 0) return firstIndexNumAndInitNotIdentify; //Violate 6
    return -10; //Not Violate
}
// Task 5

//O(N)
int findMaxLength(char *arr_pwds[], int num_pwds) { //Find max length in array of string
    int max_length = static_cast<int>(strlen(arr_pwds[0]));
    for (int i = 1; i < num_pwds; ++i) {
        int current_length = static_cast<int>(strlen(arr_pwds[i]));
        if (current_length > max_length) max_length = current_length;
    }
    return max_length;
}
//O(N^2)
int * findArrayDuplicate(char *arr_pwds[], int num_pwds, int &max_duplicate) { //Find array number of duplicate in array of string
    int *count = new int[num_pwds](); // Initialize array to all zeros
    for (int i = 0; i < num_pwds; ++i) for (int j = i; j < num_pwds; ++j)
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++count[i];
                if (count[i] > max_duplicate) max_duplicate = count[i];
            }
    return count;
}
//O(N)
char ** maxStringDuplicate(char *arr_pwds[], int num_pwds, int array_duplicate[], int max_duplicate, int & size) { //Find array of string has max duplicate
    char **max_dup = new char*[num_pwds]; // Maximum possible size
    for (int i = 0; i < num_pwds; ++i)
        if (array_duplicate[i] == max_duplicate) {
            max_dup[size] = new char[static_cast<int>(strlen(arr_pwds[i])) + 1];
            strcpy(max_dup[size], arr_pwds[i]);
            ++size;
        }
    char **maxDup = new char*[size];
    for (int i = 0; i < size; ++i) {
        maxDup[i] = new char[static_cast<int>(strlen(max_dup[i])) + 1];
        strcpy(maxDup[i], max_dup[i]);
    }
    //for (int i = 0; i < num_pwds; ++i) delete[] max_dup[i];
    delete[] max_dup;
    return maxDup;
}
bool checkMaxElement(char * maxDup, char * element) { //Check max element in array of string
    int len = static_cast<int>(strlen(maxDup));
    int length = static_cast<int>(strlen(element));
    if (len != length) return false;
    for (int i = 0; i < len; ++i) 
        if (maxDup[i] != element[i]) return false;
    return true;
}
//O(N^2)
int findCorrectPassword(const char *arr_pwds[], int num_pwds) { //MISSION 5 (1.5pts)
    // TODO: Complete this function
    int size = 0, max_duplicate = 1;
    char ** arr = new char*[num_pwds]; //Create array of char*
    for (int i = 0; i < num_pwds; ++i) {
        arr[i] = new char[static_cast<int>(strlen(arr_pwds[i])) + 1]; 
        strcpy(arr[i], arr_pwds[i]);
    }
    int * array_max_duplicate = findArrayDuplicate(arr, num_pwds, max_duplicate);
    char ** maxDup = maxStringDuplicate(arr, num_pwds, array_max_duplicate, max_duplicate, size);
    int max_length = findMaxLength(maxDup, size);
    if (size == 1) {
        for (int i = 0; i < num_pwds; ++i) 
            if (array_max_duplicate[i] == max_duplicate) {
                delete[] array_max_duplicate;
                for (int j = 0; j < size; ++j) {
                    delete[] maxDup[j];
                    delete[] arr[j];
                }
                delete[] maxDup;
                delete[] arr;
                return i;
            }
    }
    char * maxDuplicate;
    for (int i = 0; i < size; ++i) //Find max element in array of string has max duplicate
        if (static_cast<int>(strlen(maxDup[i])) == max_length) {
            maxDuplicate = maxDup[i];
            break;
        }
    for (int i = 0; i < num_pwds; ++i) 
        if (checkMaxElement(maxDuplicate, arr[i])) {
            //delete maxDuplicate;
            delete[] array_max_duplicate;
            for (int j = 0; j < size; ++j) {
                delete[] maxDup[j];
                delete[] arr[j];
            }
            delete[] maxDup;
            delete[] arr;
            return i;
        }
    //delete maxDuplicate;
    delete[] array_max_duplicate;
    for (int j = 0; j < size; ++j) {
        delete[] maxDup[j];
        delete[] arr[j];
    }
    delete[] maxDup;
    delete[] arr;
    return -1; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////