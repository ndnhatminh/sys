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
void checkHP(int &hp){
    if(hp<0) hp=0; else if(hp>666) hp=666;
}
void checkEXP(int &exp){
    if(exp<0) exp=0; else if(exp>600) exp=600;
}
void checkM(int &M){
    if(M<0) M=0; else if(M>3000) M=3000;
}
bool checkE(int &E){
    if(E<0 || E>99) return false;
    return true;
}
void round1(double &a){
    double b=a-static_cast<int>(a);
    b>0 ? static_cast<int>(a)+1 : a;
}
int findNearestPerfectSquare(int number) {
    int lower = sqrt(number);
    int higher = lower + 1;

    int lowerSquare = pow(lower, 2);
    int higherSquare = pow(higher, 2);

    if (abs(number - lowerSquare) <= abs(number - higherSquare)) {
        return lowerSquare;
    } else {
        return higherSquare;
    }
}
int count1(int u){
    if(u==0) return 0;
    int count=0;
    while(u!=0){
        u/=10;
        count++;
    }
    return count;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(!checkE(e1)) return -99;
    checkEXP(exp1);
    checkEXP(exp2);
    // TODO: Complete this function
    if(e1 >= 0 && e1 <=3){
        int D;
        switch(e1){
            case 0:
                exp2+=29;
                break;
            case 1:
                exp2+=45;
                break;
            case 2:
                exp2+=75;
                break;
            case 3:
                exp2=exp2 + 29 + 45 + 75;
                break;
            default:
                break;
        }
        checkEXP(exp2);
        D=e1*3 + exp1*7;
        if(D%2==0){
            double result = exp1 + static_cast<double>(D) / 200;
            exp1=static_cast<int>(ceil(result));
        } else {
            double result =exp1 - static_cast<double>(D) / 100;
            exp1=static_cast<int>(ceil(result));
        }
        checkEXP(exp1);
    }
    if(e1 >=4 && e1<=99){
        if(e1>=4 && e1<=19){
            double result =exp2 + static_cast<double>(e1) / 4 + 19;
            exp2=static_cast<int>(ceil(result));
        }else if(e1>=20 && e1<=49){
            double result =exp2 + static_cast<double>(e1) / 9 + 21;
            exp2=static_cast<int>(ceil(result));
        }else if(e1>=50 && e1<=65){
            double result = exp2 + static_cast<double>(e1) /16 + 17;
            exp2=static_cast<int>(ceil(result));
        }else if(e1>=66 && e1<=79){
            double result = exp2 + static_cast<double>(e1) / 4 + 19;
            exp2=static_cast<int>(ceil(result));
            checkEXP(exp2);
            if(exp2>200) {
                double result2 = exp2 + static_cast<double>(e1) / 9 + 21;
                exp2=static_cast<int>(ceil(result2));
            }
        }else{
            double result = exp2 + static_cast<double>(e1) / 4 + 19;
            exp2=static_cast<int>(ceil(result));
            double result2 = exp2 + static_cast<double>(e1) / 9 + 21;
            exp2=static_cast<int>(ceil(result2));
            checkEXP(exp2);
            if(exp2>400) {
                double result3 = exp2 + static_cast<double>(e1) / 16 + 17;
                exp2=static_cast<int>(ceil(result3));
                double result4 = exp2 + static_cast<double>(exp2) * 0.15;
                exp2=static_cast<int>(ceil(result4));
            }
        }
        checkEXP(exp2);
        exp1-=e1;
        checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(!checkE(E2)) return -99;
    checkHP(HP1); checkEXP(EXP1); checkM(M1);
    float p1,p2,p3;
    do{
        int S=findNearestPerfectSquare(EXP1);
        if(EXP1>=S) p1=100; else {
            p1=(static_cast<float>(EXP1) / S + 80) / 123;
            p1*=100;
        }
    int half=static_cast<int>(ceil(static_cast<float>(M1)/2));
    int count=0;
    int decide;
    if(E2%2==0) decide=0; else decide=1;
    do{
        if(HP1<200){
            float result=HP1+static_cast<float>(HP1)*0.3;
            HP1=static_cast<int>(ceil(result));
            count+=150;
            M1-=150;
            checkM(M1);
            checkHP(HP1);
        } else{
            float result=HP1+static_cast<float>(HP1)*0.1;
            HP1=static_cast<int>(ceil(result));
            count+=70;
            M1-=70;
            checkM(M1);
            checkHP(HP1);
        }
        if(count>half || M1==0) break;
        if(EXP1<400){
            float result=EXP1+static_cast<float>(EXP1)*0.13;
            EXP1=static_cast<int>(ceil(result));
            count+=200;
            M1-=200;
            checkM(M1);
            checkEXP(EXP1);
        }else{
            float result=EXP1+static_cast<float>(EXP1)*0.13;
            EXP1=static_cast<int>(ceil(result));
            count+=120;
            M1-=120;
            checkM(M1);
            checkEXP(EXP1);
        }
        if(count>half || M1==0) break;
        if(EXP1<300){
            float result=static_cast<float>(EXP1)*0.9;
            EXP1=static_cast<int>(ceil(result));
            count+=100;
            M1-=100;
            checkM(M1);
            checkEXP(EXP1);
        }else{
            float result=static_cast<float>(EXP1)*0.9;
            EXP1=static_cast<int>(ceil(result));
            count+=120;
            M1-=120;
            checkM(M1);
            checkEXP(EXP1);
        }
        if(decide==0) break;
    } while(count<=half && M1>0);
    float result=static_cast<float>(HP1)*0.83;
    HP1=static_cast<int>(ceil(result));
    float result2=EXP1+static_cast<float>(EXP1)*0.17;
    EXP1=static_cast<int>(ceil(result2));
    checkHP(HP1);
    checkEXP(EXP1);
    S=findNearestPerfectSquare(EXP1);
    if(EXP1>=S) p2=100; else {
        p2=(static_cast<float>(EXP1) / S + 80) / 123;
        p2*=100;
        p2=static_cast<int>(ceil(p2));
    }
    int array[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2>=0 && E2<=9) p3=array[E2];
    else{
        int m=0;
        int s=count1(E2);
        for(int i=0; i<s;i++){
            m+=E2%10;
            E2/=10;
        }
        m%=10;
        p3=array[m];
    }
        if(p1== p2 && p2==p3 && p3==100) EXP1=static_cast<int>(ceil(static_cast<float>(EXP1)*0.75));
    }while(p1== p2 && p2==p3 && p3==100);
    float p= (p1+p2+p3)/3;
    if(p<50){
        HP1=static_cast<int>(ceil(static_cast<float>(HP1)*0.85));
        EXP1=EXP1+static_cast<int>(ceil(static_cast<float>(EXP1)*0.15));
    }else{
        HP1=static_cast<int>(ceil(static_cast<float>(HP1)*0.9));
        EXP1=EXP1+static_cast<int>(ceil(static_cast<float>(EXP1)*0.2));
    }
    checkHP(HP1);
    checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}
int getMaxValue(int matrix[10][10], int row, int col) {
    int maxLeftDiagonal = matrix[row][col];
    int maxRightDiagonal = matrix[row][col];

    // Tính giá trị lớn nhất trên đường chéo trái
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        maxLeftDiagonal = max(maxLeftDiagonal, matrix[i][j]);
        i--;
        j--;
    }
    i = row + 1, j = col + 1;
    while (i < 10 && j < 10) {
        maxLeftDiagonal = max(maxLeftDiagonal, matrix[i][j]);
        i++;
        j++;
    }

    // Tính giá trị lớn nhất trên đường chéo phải
    i = row - 1, j = col + 1;
    while (i >= 0 && j < 10) {
        maxRightDiagonal = max(maxRightDiagonal, matrix[i][j]);
        i--;
        j++;
    }
    i = row + 1, j = col - 1;
    while (i < 10 && j >= 0) {
        maxRightDiagonal = max(maxRightDiagonal, matrix[i][j]);
        i++;
        j--;
    }

    return max(maxLeftDiagonal, maxRightDiagonal);
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(!checkE(E3)) return -99;
    checkHP(HP1); checkEXP(EXP1); checkHP(HP2); checkEXP(EXP2);
    int bigger=0;
    int smaller=0;
    int arr[10][10],arr2[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(arr[i][j]>(E3*2)) bigger++;
            else if(arr[i][j]<(-E3)) smaller++;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr2[i][j] = getMaxValue(arr,i,j);
            if(arr2[i][j]<0) arr2[i][j]*=-1;
        }
    }
    while (bigger > 9 || (bigger >= 10 && bigger <= 99)) {
        int sum = 0;
        if (bigger >= 10 && bigger <= 99) {
            sum = (bigger / 10) + (bigger % 10);
        } else {
            while (bigger != 0) {
                sum += bigger % 10;
                bigger /= 10;
            }
        }
    bigger = sum;
    }
    while (smaller > 9 || (smaller >= 10 && smaller <= 99)) {
        int sum = 0;
        if (smaller >= 10 && smaller <= 99) {
            sum = (smaller / 10) + (smaller % 10);
        } else {
            while (smaller != 0) {
                sum += smaller % 10;
                smaller /= 10;
            }
        }
        smaller = sum;
    }
    int value1=arr[bigger][smaller];
    int value2=arr2[bigger][smaller];
    if(abs(value1)>value2){
        HP1=static_cast<int>(ceil(static_cast<float>(HP1)*0.9));
        EXP1=static_cast<int>(ceil(static_cast<float>(EXP1)*0.88));
        HP2=static_cast<int>(ceil(static_cast<float>(HP2)*0.9));
        EXP2=static_cast<int>(ceil(static_cast<float>(EXP2)*0.88));
    }else{
        HP1=HP1+static_cast<int>(ceil(static_cast<float>(HP1)*0.1));
        EXP1=EXP1+static_cast<int>(ceil(static_cast<float>(EXP1)*0.12));
        HP2=HP2+static_cast<int>(ceil(static_cast<float>(HP2)*0.1));
        EXP2=EXP2+static_cast<int>(ceil(static_cast<float>(EXP2)*0.12));
    }
    checkHP(HP1); checkEXP(EXP1); checkHP(HP2); checkEXP(EXP2);
    if(abs(value1)>value2) return value1;
    return value2;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string message=email;
    string password=s;
    int pos=message.find("@");
    string se=message.substr(0,pos);
    if(password.size()<8) return -1;
    else if(password.size()>20) return -2;
    if(password.find(se) != string::npos) return -(300+password.find(se));
    int Count = 1;
    char currentChar = password[0];
    int Start = -1;
    for (int i = 1; i<password.size(); i++) {
        if (password[i] == currentChar) {
            Count++;
            if (Count > 2 && Start == -1) {
                Start = i - Count + 1;
                return -(400 + Start);
            }
        } else {
            Count = 1;
            currentChar = password[i];
        }
    }
    if(password.find('@') == string::npos && password.find('#') == string::npos && password.find('%') == string::npos && password.find('$') == string::npos && password.find('!') == string::npos) return -5;
    for(int i=0;i<password.size();i++) if(!(isalnum(password[i]) || password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$' || password[i] == '!')) return i;
    return -10;
}

// Task 5
struct Password1 {
    string password;
    int count;
    int length;
};
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string arr_pwds1[num_pwds];
    for(int i=0;i<num_pwds;i++){
        arr_pwds1[i]=arr_pwds[i];
    }
    // TODO: Complete this function
    Password1 CorrectPassword = {"", 0, 0};
    int firstPosition = -1;
    for (int i = 0; i < num_pwds; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr_pwds[i] == arr_pwds[j]) {
                break;
            }
        }
        if (j != i) {
            continue;
        }
        int count = 1;
        int length = arr_pwds1[i].length();
        for (int k = i + 1; k < num_pwds; k++) {
            if (arr_pwds1[k] == arr_pwds1[i]) {
                count++;
            }
        }
        if (count > CorrectPassword.count || (count == CorrectPassword.count && length > CorrectPassword.length)) {
            CorrectPassword = {arr_pwds1[i], count, length};
            firstPosition = i;
        }
    }
    return firstPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////