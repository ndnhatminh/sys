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

void checkforexp (int &exp){
    if (exp > 600) {
        exp = 600;
    }
    else if (exp <0) {
        exp = 0;
    }
}
void checkforhp (int &HP){
    if (HP > 666) {
        HP = 666;
    }
    else if (HP <0) {
        HP = 0;
    }
}
void checkformoney (int &money){
    if (money > 3000) {
        money = 3000;
    }
    else if (money < 0) {
        money = 0;
    }
}
bool checkforE (int E) {
  return (E >= 0 && E <= 99);
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    // TODO: Complete this function
    //Check input for task 1:
    if(!checkforE(e1)){
        return -99;
    }
    checkforexp(exp1);
    checkforexp(exp2);
    // Case 1:
    if (e1 >= 0 && e1 <= 3) {
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
                break;
        }
        checkforexp(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = ceil(exp1+static_cast<double>(D) / 200.0);
        } else {
            exp1 = ceil(exp1-static_cast<double>(D) / 100.0);
        }
        checkforexp(exp1);
    } 
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 <= 19) {
            exp2 = ceil(exp2+static_cast<double>(e1) / 4.0 + 19);
        } 
        else if (e1 >= 20 && e1 <= 49) {
            exp2 = ceil(exp2+static_cast<double>(e1) / 9.0 + 21);
        } 
        else if (e1 >= 50 && e1 <= 65) {
            exp2 = ceil(exp2+static_cast<double>(e1) / 16.0 + 17);
        } 
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = ceil(exp2+static_cast<double>(e1) / 4.0 + 19);
            if (exp2 > 200) {
                exp2 = ceil(exp2+static_cast<double>(e1) / 9.0 + 21);
            }
        } 
        else if (e1 >= 80 && e1 <= 99) {
            exp2 = ceil(exp2+static_cast<double>(e1) / 4.0 + 19 );
            exp2 = ceil(exp2+static_cast<double>(e1) / 9.0 +21 );
            if (exp2 > 400) {
                exp2 = ceil(exp2+static_cast<double>(e1) / 16.0 + 17);
                exp2 = ceil(1.15 * exp2);
            }
        }
        checkforexp(exp2);
        exp1 -= e1;
        checkforexp(exp1);
    } 
    return exp1 + exp2;
}
    
// Task 2
// Define functions
 int closestsqrt(int exp){
  int closest = 0;
  int min_difference = INT_MAX;
    for (int i = 0; i <= 24; i++) {
        int square = i * i;
        int difference = abs(square - exp);
        if (difference < min_difference) {
            min_difference = difference;
            closest = square;
        }
    }
    return closest;
 }
int event1(int & HP1) {
    int spending = 0;
    if (HP1 < 200) {
        HP1 = 1.3 * HP1 + 0.999;
        spending += 150;
    } else if (HP1 >= 200) {
        HP1 = 1.1 * HP1 + 0.999;
        spending += 70;
    }
    checkforhp(HP1);
    return spending;
}

int event2(int & EXP1) {
    int spending = 0;
    if (EXP1 < 400) {
        spending += 200;
    } else {
        spending += 120;
    }
    EXP1 = 1.13 * EXP1 + 0.999;
    checkforexp(EXP1);
    return spending;
}
int event3 (int & EXP1) {
    int spending = 0;
    if (EXP1 < 300) {
        spending += 100;
    }
    else if (EXP1 >= 300) {
        spending += 120;
    }
    EXP1 = 0.9*EXP1 + 0.999;
    checkforexp(EXP1);
    return spending;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
// Check input for task 2: 
if(!checkforE(E2)){
    return -99;
}
checkforexp(EXP1);
checkforhp(HP1);
checkformoney(M1);
    // P for 3 events: 
    double P1;
    double P2;
    double P3;
    // Road 1:
    // The closest square number to exp1:
    int S = closestsqrt(EXP1); 
    if (EXP1 >= S) {
        P1 = 1;
    } else {
        P1 = (static_cast<double>(EXP1) / static_cast<double>(S) + 80) / 123;
    }

    // Road 2:
    // Check E2 condition
    int spent =0 ;
    if (E2 % 2 != 0) {
        do {
            if (M1 ==0) {
                break;
            }
            spent += event1(HP1);
            if (spent > (0.5 * M1+ 0.999)) {
                break; }
            spent += event2(EXP1);
            if (spent > (0.5 * M1+ 0.999)) {
                break; }
            spent += event3(EXP1);
            if (spent > (0.5 * M1+ 0.999)) {
                break; }
        } while (true);
        HP1 = 0.83*HP1 +0.999;
        M1 -= spent;
        EXP1 = 1.17*EXP1 +0.999;
    }else if (E2 %2 ==0) {
            if (M1 != 0) {
                M1 -= event1(HP1);
                checkformoney(M1);
            }
            if (M1 != 0) {
                M1 -= event2(EXP1);
                checkformoney(M1);
            }
           
            if (M1 != 0) {
               M1 -= event3(EXP1);
                checkformoney(M1);
            }
            HP1 = 0.83*HP1 +0.999;
            EXP1 = 1.17*EXP1 +0.999;
    }
        checkforhp(HP1);
        checkforexp(EXP1);
        checkformoney(M1);
int S2 = closestsqrt(EXP1); 
    if (EXP1 >= S2) {
        P2 = 1;
    } else {
        P2 = (static_cast<double>(EXP1) / static_cast<double>(S2) + 80) / 123;
    }
//Road 3 
double P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    int i; 
    if (E2 >= 0 && E2 <= 9) {
        i = P[E2];
    } else if (E2 >= 10 && E2 <= 99) {
        int sumdigits = (E2 / 10) + (E2 % 10);
        i = P[sumdigits % 10];
    } 
    P3 = i/100.0;
    //Conclusions
    if (P1 ==1 && P2 ==1 && P3 ==1){
        EXP1 = 0.75*EXP1+0.999;
    }else {
        double Ptotal =0 ;
        Ptotal = (P1+P2+P3)/3;
        if (Ptotal < 0.5){
            HP1 = 0.85*HP1 +0.999;
            EXP1= 1.15*EXP1 +0.999;
        }else {
            HP1 = 0.9*HP1 +0.999;
            EXP1= 1.2*EXP1 +0.999;
        }
        checkforhp(HP1);
        checkforexp(EXP1);
        checkformoney(M1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int MaxDiagonal(int matrix[10][10], int i, int j) {
    //  First diagonal
    int Left1 = matrix[i][j];
    for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
        Left1 = max(Left1, matrix[i - k][j - k]);
    }
    int Right1 = matrix[i][j];
    for (int k = 1; i + k <=9 && j + k <= 9; ++k) {
        Right1 = max(Right1, matrix[i + k][j + k]);
    }
    // Second diagonal
    int Left2 = matrix[i][j];
    for (int k = 1; i - k >= 0 && j + k <= 9; ++k) {
        Left2 = max(Left2, matrix[i - k][j + k]);
    }
    int Right2 = matrix[i][j];
    for (int k = 1; i + k <=9 && j - k >= 0; ++k) {
        Right2 = max(Right2, matrix[i + k][j - k]);
    }
    // Return abs max value 
   return abs(max(max(Right1, Left1), max(Right2, Left2)));

}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(!checkforE(E3)){
        return -99;
    }
    //check for intput 
    checkforexp(EXP1);
    checkforexp(EXP2);
    checkforhp(HP1);
    checkforhp(HP2);
    int taximatrix [10][10] ={{0}};
    for (int i =0 ; i <10 ; i++) {
        for (int j =0 ; j <10;  j++) {
            taximatrix[i][j] = ((E3*j)+(i*2))*(i-j) ;
        }
    }

    int chasematrix [10][10] ={{0}};
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            chasematrix[i][j] = MaxDiagonal(taximatrix,i,j);
        }
    }
    int i =0;
    int j = 0;
    for (int m =0 ; m <10 ; m++) {
        for (int n =0 ; n <10;  n++) {
          if (taximatrix[m][n] > (E3*2)){
            i++;
          }
          if (taximatrix[m][n] < (-1)*E3){
            j++;
          } 
        }
    }
    while (i>=10){
        i= i/10 + i%10;
    }
    while (j>=10){
        j= j/10 + j%10;
    }
    if (abs(taximatrix[i][j]) <= chasematrix[i][j]){
        EXP1 = 1.12*EXP1+0.999;
        EXP2 = 1.12*EXP2+0.999;
        HP1 = 1.1*HP1+0.999;
        HP2 = 1.1*HP2+0.999;
            checkforexp(EXP1);
            checkforexp(EXP2);
            checkforhp(HP1);
            checkforhp(HP2);
            cout << EXP2 << endl;
            return chasematrix[i][j];
    }else {
        EXP1 = 0.88*EXP1+0.999;
        EXP2 = 0.88*EXP2+0.999;
        HP1 = 0.9*HP1+0.999;
        HP2 = 0.9*HP2+0.999; 
            checkforexp(EXP1);
            checkforexp(EXP2);
            checkforhp(HP1);
            checkforhp(HP2);
        return taximatrix[i][j];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    size_t i = 0;
    string email_str(email);
    string se = email_str.substr(0, email_str.find('@'));
    string s_str(s);
    // Check password length
    size_t passwordlength = s_str.length();
    if(passwordlength < 8){
        return -1;
    }
    else if ( passwordlength >20){
        return -2;
    }
    //Serch string and return the position of it. 
 
    if (s_str.find(se) != string::npos) {
        return -(300 + s_str.find(se)); 
    }
     //Check for repeated characters
    for (int i=0 ; i < s_str.length()-2 ; i++) {
        if (s_str[i] == s_str[i+1] && s_str[i+1] == s_str[i+2]) {
            return -(400+i);
        }
    }
        //Check for special characters
    bool checkspecialchar = false;
    for (int i = 0; i < s_str.length(); i++){
        if (s_str[i] == '@' || s_str[i] == '#' || s_str[i] == '%' || s_str[i] == '$' || s_str[i] == '!'){
            checkspecialchar = true; 
            break;
        }
    }
      if(!checkspecialchar){
            return -5;
        }
   
    //Check for valid characters
        for (i = 0; i < s_str.length(); ++i) {
        if (!(iswdigit(s_str[i]) || iswalpha(s_str[i])|| s_str[i] == '@' || s_str[i] == '#' || s_str[i] == '%' || s_str[i] == '$' || s_str[i] == '!')) {
            return i; 
        }
    }
    return -10;
}


/// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //Convert to string
    string str_arr_pwds[num_pwds];
    for(int i = 0; i < num_pwds; i++) {
        str_arr_pwds[i] = string(arr_pwds[i]);
    }
    // Create an array : with the even index store the index of passwords and the odd index to store the occurence time.
    string temp_password="";
    int arr[2*num_pwds];
    //Initialize the array 
    for (int i = 0; i < 2*num_pwds; i++) {
        arr[i] = 0;
    }
    for(int i=0; i<num_pwds; i++) {
        temp_password=str_arr_pwds[i];
        int count= 1;
        for (int j=i+1; j<num_pwds; j++){
            if(str_arr_pwds[j]==temp_password){
                count++;
            }
        }
        arr[2*i]=i;
        arr[2*i+1]= count;
    }
    //Find the max value of occurence time in array and return the index of it 
    int max_index=0;
    int max_count = arr[1];
  for (int i=1; i<=2*num_pwds; i+=2) {
    int index = arr[i-1];
        if(arr[i] > max_count){
            max_count = arr[i];
            max_index = (i-1)/2;
    } else if(arr[i]==max_count && strlen(arr_pwds[index]) > strlen(arr_pwds[max_index])){
            max_count = arr[i];
            max_index = (i-1)/2;
    }
  }
    return max_index;
}
   
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////