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
void checkingRangeNum(int& number, int lower, int upper){
    if (number < lower) {
        number = lower;
    } else if (number > upper) {
        number = upper;
    }
}


// Task 1 
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(EXP2, 0, 600);
    
    float a, b ,c;
     a = static_cast<float>(E1)/4 +19;
     b = static_cast<float>(E1)/9 + 21;
     c = static_cast<float>(E1)/16 + 17;
     if (E1 >=0 && E1 <=99){
    int Case;
    if (E1>=0 && E1 <= 3) Case = 0;
    else if (E1>3 && E1 <= 99) Case = 1;
    // Case 1
    if (Case == 0){
    switch (E1){
        case 0:
        EXP2 += 29; break;
        case 1:
        EXP2 += 45; break;
        case 2:
        EXP2 += 75; break;
        case 3:
        EXP2 = EXP2 +29 + 45 + 75; break;
    }
        int D;
        D = E1*3 + EXP1*7;
        if (D%2==0) EXP1 += ceil(static_cast<double>(D)/200);
        else {EXP1 -= D/100;}
        EXP1 = ceil(EXP1);
        checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(EXP2, 0, 600);
        return EXP1 + EXP2 ;
    }
    // Case 2   
    else if (Case == 1){
    int type;
    if (E1>3 && E1 < 20) type = 1;
    else if (E1 >= 20 && E1 <= 49) type = 2;
    else if (E1 > 49 && E1<= 65) type = 3;
    else if (E1 > 65 && E1<= 79) type = 4;
    else if (E1 > 79 && E1 <= 99) type = 5;
    switch (type) {
        case 1 : 
            EXP2 = EXP2 + ceil(a) ; break;
        case 2 : 
            EXP2 = EXP2 + ceil(b) ; break;
        case 3 :
            EXP2 = EXP2 + ceil(c) ; break;
        case 4 :
            EXP2 = EXP2 + ceil(a) ;
            if (EXP2 > 200) EXP2 = EXP2 + ceil(b) ; break;
        case 5 :
            EXP2 = EXP2 + ceil(a) + ceil(b);
            if (EXP2 > 400){ 
            EXP2 = ceil(static_cast<double>(EXP2) + c) ; 
            EXP2 = ceil(EXP2 + ceil(static_cast<double>(EXP2) * 0.15)) ;
            } break;
    }
        EXP1 = EXP1 - E1;
        
    }
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(EXP2, 0, 600);
     return EXP1 + EXP2 ;}
    else {return -99;}
    }
;


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(HP1, 0, 666);
    checkingRangeNum(M1, 0, 3000);
    if (E2 >=0 && E2 <=99){
    //Road1
    double S1, P1;
    S1= pow(round(sqrt(EXP1)), 2);
    if (EXP1 >= S1) P1 = 100;
    else P1 = static_cast<double>(((EXP1 / S1 + 80) / 123) * 100);
    

    //Road2
    int halfM = M1 * 0.5; 
    int M=0;
    int count = 0;
    // so le
    if (E2 % 2 != 0){
      do {
        // Mua food or drink
         if (HP1 < 200) {
          HP1 = ceil(static_cast<double>(HP1) + HP1*0.3);
          M1 -= 150; M +=150;
    }
         else {
          HP1 = ceil(static_cast<double>(HP1) + HP1*0.1);
        M1 -= 70; M+=70;
    }  
    checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(M1, 0, 3000);
        
        if (M > halfM) break;
    // Taxi or horse
        int taxi = 200;
        int horse = 120;
        if (EXP1 < 400 ) {M1 -= taxi ; M+=taxi;}
        else 
        {M1 -= horse ; M += horse;}
         EXP1 = ceil(static_cast<double>(EXP1) + EXP1*0.13);
         checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(M1, 0, 3000);
        
         if (M > halfM) break;
    
    // homeless and clue
        if (EXP1 < 300) {M1 -= 100; M+= 100;}
        else {
        M1 -= 120; M+=120;}
        EXP1 = ceil(static_cast<double>(EXP1) - EXP1*0.1);
        checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(M1, 0, 3000);
        
     if (M > halfM) break;
    }   while (M < halfM ); 
    
    }
    // so chan
    else {
        int cong = 0 ;
         do {
         // Mua food or drink
        if (HP1 < 200) {
          HP1 = ceil(static_cast<double>(HP1) + HP1*0.3);
          M1 = M1- 150; 
    } 
        else {
          HP1 = ceil(static_cast<double>(HP1) + HP1*0.1);
          M1 = M1- 70; }
          checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(M1, 0, 3000);
        
       if (M1 ==0 ) break;
    // Taxi or horse
        int taxi = 200;
        int horse = 120;
        if (EXP1 < 400 ) M1 -= taxi ;
        else {
         M1 -= horse ;}
         EXP1 = ceil(static_cast<double>(EXP1) + EXP1*0.13);
         checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(M1, 0, 3000);
        
     if (M1 ==0 ) break;
    // homeless and clue
    
        if (EXP1 < 300) M1 -= 100;
        else {
        M1 -= 120;}
        EXP1 = ceil(static_cast<double>(EXP1) - EXP1*0.1);
        checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(M1, 0, 3000);
        
     if (M1 ==0 ) break;
     }   while ( cong == 1 ); cong ++;
    }
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(HP1, 0, 666);
    checkingRangeNum(M1, 0, 3000);
    
    

    HP1 = ceil(static_cast<double>(HP1) - HP1*0.17);
    EXP1 = ceil(static_cast<double>(EXP1) + EXP1*0.17);  
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(HP1, 0, 666);
    checkingRangeNum(M1, 0, 3000);
    
    // xac suat P2
    double S2, P2;
    S2= pow(round(sqrt(EXP1)), 2); 
    if (EXP1 >= S2) P2 = 100;
    else P2 = static_cast<double>(((EXP1 / S2 + 80) / 123) * 100); 

    //road3
    double P3;
    int P[] = {32,47,28,79,100,50,22,83,64,11};
    int i; 
    if (E2 < 10) i = E2;
    else {
        int all = (E2 / 10) + (E2 % 10);
        i = all % 10;
    }
    P3 = P[i]; 

    // after 3 road
    double p;       
    if (P1 == 100 && P2 == 100 && P3 == 100) EXP1 = ceil(static_cast<double>(EXP1) - EXP1*0.25);
    else {
        p = (static_cast<double>(P1 + P2 + P3) / 3) ; 
    } 
    

    if (p > 0 && p < 50) {
        HP1 = ceil(static_cast<double>(HP1) - HP1*0.15);
        EXP1 = ceil(static_cast<double>(EXP1) + EXP1*0.15);
    } else if (p >= 50 && p < 100) {
        HP1 = ceil(static_cast<double>(HP1) - HP1*0.1); 
        EXP1 = ceil(static_cast<double>(EXP1) + EXP1*0.2);
    } 
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(HP1, 0, 666);
    checkingRangeNum(M1, 0, 3000);
     
    return HP1 + EXP1 + M1;}
    else return -99;

}

// Task 3
const int row = 10; 
const int col = 10;


int countpos(int arr[row][col],int n ){
    int countp = 0;
    for (int i = 0; i < 10 ; ++i){
        for (int j = 0; j < 10; ++j){
        if (arr[i][j]>n){
            countp ++;
        } 
    } 
}return countp ++;
}
int countneg(int arr[row][col],int n ){
    int countn = 0;
    for (int i = 0; i < 10 ; ++i){
        for (int j = 0; j < 10; ++j){
        if (arr[i][j]<n){
            countn ++;
        } 
    }} 
    return countn ++;
}

int checkMax(int arr[10][10], int rowsA, int colsA) {
    int maxi = arr[rowsA][colsA];

    for (int i = rowsA, j = colsA; i < 10 && j < 10; i++, j++) {
        if (arr[i][j] > maxi) {
            maxi = arr[i][j];
        } 
    }

    for (int i = rowsA, j = colsA; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j] > maxi) {
            maxi = arr[i][j];
        }
    }
    for (int i = rowsA, j = colsA; i < 10 && j >= 0; i++, j--) {
        if (arr[i][j] > maxi) {
            maxi = arr[i][j];
        }
    }
     for (int i = rowsA, j = colsA; i >= 0 && j < 10; i--, j++) {
        if (arr[i][j] > maxi) {
            maxi = arr[i][j];
        }
    }
    return maxi;
}
int sumsingle(int n) {
    while (n > 9) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    checkingRangeNum(EXP1, 0, 600);
    checkingRangeNum(HP1, 0, 666);
    checkingRangeNum(HP2, 0, 666);
    checkingRangeNum(EXP2, 0, 600);
    if (E3 < 0 || E3 > 99) {
        return -99; 
    }
    // make matrix taxi
     int taxi[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] =  ((E3 * j) + (i * 2)) * (i - j);
    }}
    
    int A = E3 * 2;
    int B = -E3;
    int x = countpos ( taxi, A );
    int y = countneg (taxi,B); 
    int i,j;
    i = sumsingle (x);
    j = sumsingle (y);
    
    int taxiN = taxi[i][j];
    int sherN = checkMax(taxi,i,j);

    if (abs (taxiN) > abs(sherN)){
        EXP1 = ceil(static_cast<double>(EXP1) - EXP1*0.12);
        EXP2 = ceil(static_cast<double>(EXP2) - EXP2*0.12);
        HP1 = ceil(static_cast<double>(HP1) - HP1*0.1);
        HP2 = ceil(static_cast<double>(HP2) - HP2*0.1);  
        return taxiN;
    } else if (abs (taxiN) <= abs(sherN)){
        EXP1 = ceil(static_cast<double>(EXP1) + EXP1*0.12);
        EXP2 = ceil(static_cast<double>(EXP2) + EXP2*0.12);
        HP1 = ceil(static_cast<double>(HP1) + HP1*0.1);
        HP2 = ceil(static_cast<double>(HP2) + HP2*0.1); 
        checkingRangeNum(EXP1, 0, 600);
        checkingRangeNum(HP1, 0, 666);
        checkingRangeNum(EXP2, 0, 600);
        checkingRangeNum(HP2, 0, 666); 
        return sherN;
    }



    
    return -1;
}

// Task 4

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
string newemail (email);
string se = newemail.substr(0, newemail.find('@'));
string news (s);
// check s length
int length = news.length();
if (length <8) return -1;
else if (length >20) {return -2;}
// tim vi tri dau tien cua chuoi se
size_t look = news.find(se)  ;
if (look != string::npos) { 
return -(300 + look);
}
for (int i = 0; i < news.length() - 2; ++i) {
        if (s[i] == news[i+1] && s[i] == s[i+2]) {
            return -(400 + i);
        }
    }

int k =0;
for (int i = 0; i < news.size(); i++) {
    if (news[i] == '@'||news[i] == '!'||news[i] == '#'||news[i] == '$'||news[i] == '%') 
        k ++;
} if (k ==0) return -5;

for (size_t i = 0; i < length; ++i) {
        char c = news[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }
}

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int app = 0; // xuat hien
    int longu = 0;// do dai
    int yes = -1; // mat khau thay dau tien

    for (int i = 0; i < num_pwds; ++i) {
        int frequency = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                frequency++;
            }
        }
        if (frequency > app || (frequency == app && strlen(arr_pwds[i]) > longu)) {
            app = frequency;
            longu = strlen(arr_pwds[i]);
            yes = i;
        }
    }
    return yes;
}
 


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////