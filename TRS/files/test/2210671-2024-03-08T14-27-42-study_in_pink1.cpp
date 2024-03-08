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

///External Class Clarification
class maxPass{
public:
    string data;
    maxPass *head, *next;
    int fre = 0, fstIdx;
    maxPass(){
        head = nullptr;
        next = nullptr;
    }
    void processing(string s, int idx){
        if (!head){
            maxPass *newPass = new maxPass;
            newPass->data = s;
            newPass->fre = 1;
            newPass->fstIdx = idx;
            newPass->next = nullptr;
            head = newPass;
            return;
        }
        maxPass *passChecking = check(s);
        if (passChecking->data == s){
            ++passChecking->fre;
        }
        else{
            maxPass *newPass = new maxPass;
            newPass->data = s;
            newPass->fre = 1;
            newPass->fstIdx = idx;
            newPass->next = nullptr;
            passChecking->next = newPass;
        }
    }
    maxPass *check(string s){
        maxPass *temp = head, *prev = head;
        if (temp->data == s)
            return temp;
        temp = temp->next;
        while (temp){
            if (temp->data == s)
                break;
            prev = prev->next;
            temp = temp->next;
        }
        return (!temp)? prev : temp;
    }
    int idxMaxPass(){
        if (!head)
            return -1;
        maxPass *temp = head;
        int idx = 0, maxIdx = 0, maxChar = temp->data.length(), maxFre = temp->fre;
        temp = temp->next;
        while (temp){
            if (temp->fre > maxFre){
                maxFre = temp->fre;
                maxChar = temp->data.length();
                maxIdx = temp->fstIdx;
            }
            else if (temp->fre == maxFre && (temp->data).length() > maxChar){
                maxChar = temp->data.length();
                maxIdx = temp->fstIdx;
            }
            idx++;
            temp = temp->next;
        }
        return maxIdx;
    }
    ~maxPass(){
        while(head){
            maxPass *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

///External Function
inline void checkHp(int &HP){
    if (HP < 0)
        HP = 0;
    else if (HP > 666)
        HP = 666;
}

inline void checkMoney(int &money){
    if (money < 0)
        money = 0;
    if (money > 3000)
        money = 3000;
}

inline void checkEXP(int &EXP){
    if (EXP < 0)
        EXP = 0;
    if (EXP > 600)
        EXP = 600;
}

inline bool checkIdent(const char *s, const char *se, int index, int size){
    for (int i = 0; i < strlen(s); i++){
        if (i >= size)
            break;
        if (s[index] != se[i])
            return false;
        index++;
    }
    return true;
}

inline int maxPointDiagnal(int matrix[10][10], int row, int col){
    int max = matrix[row][col];
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        max = (matrix[i][j] > max)? matrix[i][j] : max;
    }
    for (int i = row, j = col; i < 10 && j < 10; i++, j++){
        max = (matrix[i][j] > max)? matrix[i][j] : max;
    }
    for (int i = row, j = col; i >= 0 && j < 10; i--, j++){
        max = (matrix[i][j] > max)? matrix[i][j] : max;
    }
    for (int i = row, j = col; i < 10 && j >= 0; i++, j--){
        max = (matrix[i][j] > max)? matrix[i][j] : max;
    }
    return max;
}

inline int findNearestSquareNumber(int num){
    if (sqrt(num) - floor(sqrt(num)) >= 0.5)
        return pow(ceil(sqrt(num)),2);
    return pow(floor(sqrt(num)), 2);
}

inline double roundTwoDigit(double num){
    return ((num*100.0 - floor(num*100.0)) > 0.5)? ceil(num*100)/100.0 : floor(num*100)/100.0;
}

inline double firstRoad(int EXP1){
    return (EXP1 >= findNearestSquareNumber(EXP1))? 1.0: ((double)EXP1/findNearestSquareNumber(EXP1) + 80)/123;
}

double secondRoad(int &EXP1, int &HP1, int &M1, int &spending, double M1_Before, bool isOdd){
    //Làm hành động 1
    M1 -= (HP1 < 200)? 150 : 70;
    spending += (HP1 < 200)? 150 : 70;
    float x = HP1*1.3 , y = HP1 * 1.1;
    HP1 = (HP1 < 200)? ceil(x) : ceil(y);
    checkHp(HP1);
    checkMoney(M1);
//    cout << "Action 1: HP1: " << HP1 << " M1: " << M1 << " spend: " << spending << endl;
    if (M1 == 0 || spending > M1_Before && isOdd) {
        x = HP1*0.83; y = EXP1*1.17;
        HP1 = ceil(x);
        EXP1 = ceil(y);
        checkHp(HP1);
        checkEXP(EXP1);
        return (EXP1 >= findNearestSquareNumber(EXP1))? 1.0 : ((float)EXP1/findNearestSquareNumber(EXP1) + 80)/123.0;//Hết tiền return -1
    }
    //Làm hành động thứ 2
    M1 -= (EXP1 < 400)? 200 :  120;
    spending += (EXP1 < 400)? 200 :  120;
    x = EXP1*1.13;
    EXP1 = ceil(x);
    checkMoney(M1);
    checkEXP(EXP1);
//    cout << "Action 2: EXP1: " << EXP1 << " M1: " << M1 << " spend: " << spending << endl;
    if (M1 == 0 || spending > M1_Before && isOdd) {
        x = HP1*0.83;
        y = EXP1*1.17;
        HP1 = ceil(x);
        EXP1 = ceil(y);
        checkEXP(EXP1);
        return (EXP1 >= findNearestSquareNumber(EXP1))? 1.0 : ((float)EXP1/findNearestSquareNumber(EXP1) + 80)/123;//Hết tiền return -1
    }
    //Làm hành động 3
    M1 -= (EXP1 < 300)? 100 : 120;
    spending += (EXP1 < 300)? 100 : 120;
    x = EXP1*0.9;
    EXP1 = ceil(x);
    checkMoney(M1);
//    cout << "Action 3: EXP1: " << EXP1 << " M1: " << M1 << " spend: " << spending << endl;
    if (M1 == 0 || spending > M1_Before && isOdd || !isOdd) {
        x = HP1*0.83;
        y = EXP1*1.17;
        HP1 = ceil(x);
        EXP1 = ceil(y);
        checkEXP(EXP1);
        return (EXP1 >= findNearestSquareNumber(EXP1))? 1.0 : ((float)EXP1/findNearestSquareNumber(EXP1) + 80)/123;//Hết tiền return -1
    }
    return (EXP1 >= findNearestSquareNumber(EXP1))? 1.0 : ((float)EXP1/findNearestSquareNumber(EXP1) + 80)/123;
}

inline double thirdRoad(int E2){
    double P[] = {0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11};
    return P[(E2%10 + (int)floor(E2/10))%10];
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
        return -99;
    bool other = false;
    switch (e1){
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
            break;
        default:
            other = true;
            if (e1 >= 4 && e1 <= 19)                exp2 = ceil(exp2 + e1/4.0) + 19;
            else if (e1 >= 20 && e1 <= 49)          exp2 = ceil(exp2 + e1/9.0) + 21;
            else if (e1 >= 50 && e1 <= 65)          exp2 = ceil(exp2 + e1/16.0) + 17;
            else if (e1 >= 66 && e1 <= 79){
                exp2 = ceil(exp2 + e1/4.0 + 19);
                if (exp2 > 200)
                    exp2 = ceil(exp2 + e1/9.0 + 21);
            } else{
                exp2 = ceil(ceil(exp2 + e1/4.0) + 19 + e1/9.0) + 21;
                if (exp2 > 400){
                    exp2 = ceil( exp2 + e1/16.0 + 17);
                    exp2 = ceil(exp2 * 1.15);
                }
            }
            exp1 -= e1;
    }
    checkEXP(exp1);
    checkEXP(exp2);
    if (!other){
        int D = e1 * 3 + exp1 * 7;
        if (D%2)            exp1 = ceil( exp1 -D/100.0);
        else                exp1 = ceil(exp1 + D/200.0);
        checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    double P1 = roundTwoDigit(firstRoad(EXP1)), P2, P3, P;
    double M1_Before = 0.5*M1;
    int spending = 0;
    if (E2%2) {
        while (spending <= M1_Before) {
            P2 = roundTwoDigit(secondRoad(EXP1, HP1, M1, spending, M1_Before, 1));
        }
    } else {
        P2 = roundTwoDigit(secondRoad(EXP1, HP1, M1, spending, M1_Before, 0));
    }
    P3 = thirdRoad(E2);
    if (P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil( EXP1 * 0.75);
        checkEXP(EXP1);
    }
    else {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        } else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
        checkEXP(EXP1);
        checkHp(HP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
    int taxiPoint[10][10], maxPoint, row = 0, col = 0;
//    memset(taxiPoint, 0, sizeof(taxiPoint));
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++)
            taxiPoint[i][j] = ((E3*j) + (2*i)) * (i - j);
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            if (taxiPoint[i][j] > 2 * E3)                   row++;
            if (taxiPoint[i][j] < -E3)                      col++;
        }
    }
    while (row > 9){
        string num = to_string(row);
        row = 0;
        for (int i = 0; i < num.length(); i++){
            row += (num[i] - '0');
        }
    }
    while (col > 9){
        string num = to_string(col);
        col = 0;
        for (int i = 0; i < num.length(); i++){
            col += (num[i] - '0');
        }
    }
    maxPoint = abs(maxPointDiagnal(taxiPoint, row, col));
    float x;
    if (abs(taxiPoint[row][col]) > maxPoint)            {x = EXP1*0.88; EXP1 = ceil(x); x = EXP2*0.88; EXP2 = ceil(x); x = HP1*0.9; HP1 = ceil(x); x = HP2*0.9; HP2 = ceil(x);}
    else                                                   {x = EXP1*1.12; EXP1 = ceil(x); x = EXP2*1.12; EXP2 = ceil(x); x = HP1*1.1; HP1 = ceil(x); x = HP2*1.1; HP2 = ceil(x);}
    checkHp(HP1);
    checkHp(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    return (abs(taxiPoint[row][col]) > maxPoint)? taxiPoint[row][col] : maxPoint;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    bool hasSpecialChar = false;
    int count = 0, warningPos = -1;
    if (strlen(s) < 8)                      return -1;
    if (strlen(s) > 20)                     return -2;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@')
            break;
        count++;
    }
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == email[0] || count == 0)
            if (checkIdent(s,email, i, count) || count == 0) {
                return -(300 + i);
            }
    }
    for (int i = 0; i < strlen(s) - 2; i++)
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i);
        }
    for (int i = 0; i < strlen(s); i++) {
        //Nếu ký tự không thuộc điều kiện thỏa th thoát ra ktra
        if (s[i] >= 'A' && s[i] <= 'Z' ||
            s[i] >= 'a' && s[i] <= 'z' ||
            s[i] >= '0' && s[i] <= '9' ||
            s[i] >= '#' && s[i] <= '%' ||
            s[i] == '!' || s[i] == '@') {
            if (s[i] >= '#' && s[i] <= '%' || s[i] == '!' || s[i] == '@')
                hasSpecialChar = true;
        } else if (warningPos == -1){
            warningPos = i;
        }
        if (i == strlen(s) - 1) {
            if (hasSpecialChar && warningPos == -1) return -10;//Nếu ktra đến cuối hợp lệ hết thì hoàn tất
            else if(!hasSpecialChar) return -5;//Chuỗi không có ký tự đặc biệt
        }
    }
    return warningPos;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    if (num_pwds <= 0)
        return -1;
    maxPass maxPassElement;
    for (int i = 0; i < num_pwds; i++){
        maxPassElement.processing(arr_pwds[i], i);
    }
    return maxPassElement.idxMaxPass();
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////