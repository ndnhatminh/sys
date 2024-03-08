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
int find_point(int a){
    while(a / 10 >= 1){
        a = (a/10) + (a%10);
    }
    return a;
}
int round_up_exp(float a){
    if(a >= 0 && a <= 600){
        return ceil(a);
    } else if( a < 0){
        return 0;
    } else {
        return 600;
    }
    
}
int round_up_hp(float a){
     if(a >= 0 && a <= 666){
        return ceil(a);
    } else if( a < 0){
        return 0;
    } else {
        return 666;
    }
}
int round_m(int a){
    if(a >= 0 && a <= 3000){
        return a;
    } else if( a < 0){
        return 0;
    } else {
        return 3000;
    }
}


int Square(int n){

    int sqrtN = sqrt(n);
    if(sqrtN * sqrtN == n){
        return n;
    }

    int lowerSquare = sqrtN * sqrtN;
    int upperSquare = (sqrtN + 1) * (sqrtN + 1);

    if(n - lowerSquare <= upperSquare - n){
        return lowerSquare;
    }
    else {
        return upperSquare;
    }

}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //check variable
    exp1 = round_up_exp(exp1);
    exp2 = round_up_exp(exp2);
    if(e1 >= 0 && e1 <= 99){
    } else {
        return -99;
    }


    if((e1 >= 0) && (e1 <= 3)){
        int D;
        switch(e1){
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
        D = e1*3 + exp1*7;

        if(D % 2 == 0){
            exp1 = round_up_exp(exp1 + D/200.0);
            
        } else {
            exp1 = round_up_exp(exp1 - D/100.0);

        }

            
    }
    else if( (e1 >= 4) && (e1 <= 99)){
        if(e1 <= 19){
            
            exp2 = round_up_exp(exp2 + (e1/4.0 + 19));
        }
        else if(e1 <= 49){
            
            exp2 = round_up_exp(exp2 + (e1/9.0 + 21));
            //cout << exp2;
        }
        else if(e1 <=65){
            exp2 += (e1/16 + 17);
            exp2 = round_up_exp(exp2 + (e1/16.0 + 17));
        }
        else if(e1 < 79){
            
            exp2 = round_up_exp(exp2 + (e1/4.0 + 19));
            if(exp2 > 200){
                
                exp2 = round_up_exp(exp2 + (e1/9.0 + 21));
            }
        }
        else if(e1 < 99){
            float a = exp2 + (e1/4 + 19 + e1/9.0 + 21);
            exp2 = round_up_exp(a);
            if(exp2 > 400){
                //cout << exp2 << endl;
                exp2 = round_up_exp(exp2 + (e1/16.0 + 17));
                //cout << exp2 << endl;
                
                exp2 = round_up_exp(exp2 * 1.15);
                //cout << exp2;
            }

            
        }
        exp1 -= e1;
    }
        
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //check variable
    HP1 = round_up_hp(HP1);
    EXP1 = round_up_exp(EXP1);
    M1 = round_m(M1);

    //road1

    //P1
    int S = Square(EXP1);
 
    double P1, P2, P3;
    if(EXP1 >= S){
        P1 = 100;
    } else {
        P1 = ((((EXP1 * 1.0)/S + 80) * 1.0)/123) * 100.0;
    }
 

    //P2
    if(E2 % 2 != 0){
        float K = M1 / 2.0;//1 nua so tien bat dau
        int C = 0; //cost

        while(true){
            //1
            if(HP1 < 200){
                HP1 = round_up_hp(HP1 * 1.3);
                M1 = round_m(M1 - 150);
                C += 150;
                if( C > K){
                    break;
                }    
            }
            else {
                HP1 = round_up_hp(HP1 * 1.1);
                M1 = round_m(M1 - 70);
                C += 70;
                if(C > K){
                    break;
                }
            }
            //2
            if(EXP1 < 400){
                M1 = round_m(M1 - 200);
                EXP1 = round_up_exp(EXP1 * 1.13);
                C += 200;
                if(C > K){
                    break;
                }
            } else {
                M1 = round_m(M1 - 120);
                EXP1 = round_up_exp(EXP1 * 1.13);
                C += 120;
                if(C > K){
                    break;
                }
            }
            //3
            if(EXP1 < 300){
                M1 = round_m(M1 - 100);
                EXP1  = round_up_exp(EXP1 * 0.9);
                C += 100;
                if( C > K){
                    break;
                }
            } else {
                M1 = round_m(M1 - 120);
                EXP1 = round_up_exp(EXP1 * 0.9);
                C += 120;
                if(C > K){
                    break;
                }
            }
        }
        //cout << "HP1: " << HP1 << " " << "EXP1: " << EXP1 << endl;
        HP1 = round_up_hp(HP1 * 0.83);
        EXP1 = round_up_exp(EXP1 * 1.17);
        //cout << "HP1: " << HP1 << " " << "EXP1: " << EXP1 << endl;
    } else {
        
        for(int i = 0; i < 1; i++){
            if(HP1 < 200){
                HP1 = round_up_hp(HP1 * 1.3);
                M1 = round_m(M1 - 150);
                if(M1 <= 0){
                    break;
                } 
            }
            else {
                HP1 = round_up_hp(HP1 * 1.1);
                M1 = round_m(M1 - 70);
                if(M1 <= 0){
                    break;
                } 
                
               
            }
            //2
            if(EXP1 < 400){
                M1 = round_m(M1 - 200);
                EXP1 = round_up_exp(EXP1 * 1.3);
                if(M1 <= 0){
                    break;
                } 
                
            } else {
                M1 = round_m(M1 - 120);
                EXP1 = round_up_exp(EXP1 * 1.3);
                if(M1 <= 0){
                    break;
                } 
                
            }
            //3
            if(EXP1 < 300){
                M1 = round_m(M1 - 100);
                EXP1 = round_up_exp(EXP1 * 0.9);
                if(M1 <= 0){
                    break;
                } 
                
            } else {
                M1 = round_m(M1 - 120);
                EXP1 = round_up_exp(EXP1 * 0.9);
                if(M1 <= 0){
                    break;
                } 
               
            }
           

        }
        
        HP1 = round_up_hp(HP1 * 0.83);
        EXP1 = round_up_exp(EXP1 * 1.17);
        

    }
    S = Square(EXP1);
    
    if(EXP1 >= S){
        P2 = 100;
    } else {
        P2 = (EXP1/S + 80)/123;
    }
   

    //P3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 < 10){
        P3 = P[E2];
    } else {
        int x = (((E2 % 10) + int(E2 / 10)) % 10);
       
        P3 = P[x];
    }
    
    double P12 = P1;
    //final
    double P0;
    if(P1 = P2 && P2 == P3 && P3 == 100){
        EXP1 = round_up_exp(EXP1 * 0.75);
    } else {

       
        P0 = (P12 + P2 + P3) / 3;
       

    }
   

    if(P0 < 50){
        HP1 = round_up_hp(HP1 * 0.85);
        EXP1 = round_up_exp(EXP1 * 1.15);
    } else {
        HP1 = round_up_hp(HP1 * 0.9);
        EXP1 = round_up_exp(EXP1 * 1.2);
    } 
   
    
    
    return HP1 + EXP1 + M1;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    // khoi tao ma tran
    int M[10][10] = {0};
    int x = 0, y = 0;//vi tri taxi;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            M[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if(M[i][j] > E3*2){
                x++;
            }
            if(M[i][j] < -E3){
                y++;
            }
        }
    }
    //vi tri taxi
    x = find_point(x);
    y = find_point(y);

    //diem cua taxi

    int grace_taxi = M[x][y];

    //tim diem cua sherlock va watson
    int max_diagonal = M[x][y];
    //tim gia tri lon nhat tren duong cheo chinh
    int k = 0;
    while(((x + k) >= 0 && (x + k) <= 9) && ((y + k) >= 0 && (y + k) <= 9)){
        
        max_diagonal = max(max_diagonal, M[x + k][y + k]);
        k++;
    }
    k = 0;

    while(((x - k) >= 0 && (x - k) <= 9) && ((y - k) >= 0 && (y - k) <= 9)){
        
        max_diagonal = max(max_diagonal, M[x - k][y - k]);
        k++;
    }
    k = 0;


    // tim gia tri lon nhat tren duong cheo phu

    while(((x + k) >= 0 && (x + k) <= 9) && ((y - k) >= 0 && (y - k) <= 9)){
        
        max_diagonal = max(max_diagonal, M[x + k][y - k]);
        k++;
    }
    k = 0;

    while(((x - k) >= 0 && (x - k) <= 9) && ((y + k) >= 0 && (y + k) <= 9)){
        
        max_diagonal = max(max_diagonal, M[x - k][y - k]);
        k++;
    }

    //kiem tra xem serlock va watson co duoi kip taxi khong
    if(abs(grace_taxi) > max_diagonal){
        EXP1 = round_up_exp(EXP1*0.88);
        EXP2 = round_up_exp(EXP2*0.88);
        HP1 = round_up_hp(HP1*0.9);
        HP2 = round_up_hp(HP2*0.9);
        return grace_taxi;
    } else {
        EXP1 = round_up_exp(EXP1*1.12);
        EXP2 = round_up_exp(EXP2*1.12);
        HP1 = round_up_hp(HP1*1.1);
        HP2 = round_up_hp(HP2*1.1);
        return max_diagonal;
    }

    return -1;
}

// Task 4
int findConsecutiveCharacters(const char * str) {
  int n = strlen(str);
  for (int i = 0; i < n - 2; i++) {
    if (str[i] == str[i + 1] && str[i + 1] == str[i + 2]) {
      return i;
    }
  }
  return -1;
}

bool isPasswordValid(const char * password, const char * se){
    //kiem tra do dai mat khau
    if(strlen(password) < 8 || strlen(password) > 20){
        return false;
    }
    // kiem tra loai ky tu

    bool validChar = false;
    bool hasSpecialChar = false;
    bool nothas_se = true;
    bool notConsecutiveCharacter = (findConsecutiveCharacters(password) == -1 ? true : false); 
    for(int i = 0; i < strlen(password); i++){
        if(isdigit(password[i]) || islower(password[i]) || isupper(password[i])){
            validChar = true;
        } else if(password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$' || password[i] == '!'){
            hasSpecialChar = true;

        } else {
            return false;
        }
    }
    if(strstr(password, se) != NULL){
        nothas_se = false;
    }
    return validChar && hasSpecialChar && notConsecutiveCharacter && nothas_se;
}

int checkPassword(const char * s, const char * email) {
    
    string Email = email;
    
    
    
    int atPos = strchr(email, '@') - email;
   
    char* se = new char[atPos];
    //char se[atPos];

    for(int i = 0; i < atPos; i++){
        se[i] = email[i];
    }
    
    bool hasspecialChar = false;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            hasspecialChar = true;
        }
    }
    if(isPasswordValid(s, se)){
        return -10;
    } else if(strlen(s) < 8){
        return -1;
    } else if(strlen(s) > 20){
        return -2;
    } else if(strstr(s, se) != NULL){
        return -(300 + (strstr(s, se) - s));
    } else if(findConsecutiveCharacters(s) != -1){
        return -(400 + findConsecutiveCharacters(s));
    } else if(hasspecialChar == false){
        return -5;
    }

    return -99;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int n = num_pwds;

    int count[n] = {0}; // Initialize count array with zeros

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count[i]++;
            }
        }
    }
    int max_count_pwds = -1;
    int index_max_count_pwds = -1;
    for (int i = 0; i < n; ++i) {
        if(count[i] > max_count_pwds){
            max_count_pwds = count[i];
            index_max_count_pwds = i;
        }
    }
    int i = index_max_count_pwds + 1;
    while(i < n){
        if((count[i] == max_count_pwds) && (strlen(arr_pwds[i]) > strlen(arr_pwds[index_max_count_pwds]))){
            index_max_count_pwds = i;
        }
        
        i++;
    }
    return index_max_count_pwds;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////