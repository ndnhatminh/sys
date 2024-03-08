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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 == 0){                                   //Case 1 - find exp2
        exp2 += 29;
    } else if (e1 == 1){
        exp2 += 45;
    } else if (e1 == 2){
        exp2 += 75;
    } else if (e1 == 3){                       
        exp2 = exp2 + 29 + 45 + 75;
    } else if (e1 >= 4 && e1 <= 19){                //Case 2 - find exp1 and exp2
        exp2 = ceil(exp2 + ((float)e1/4 + 19));
        exp1 = exp1 - e1;
    } else if (e1 >= 20 && e1 <= 49){
        exp2 = ceil(exp2 + ((float)e1/9 + 21)) ;
        exp1 = exp1 - e1;
    } else if (e1 >= 50 && e1 <= 65){
        exp2 = ceil(exp2 + ((float)e1/16 + 17));
        exp1 = exp1 - e1;
    } else if (e1 >= 66 && e1 <= 79){
        exp2 = ceil(exp2 + ((float)e1/4 + 19));
        if (exp2 > 200){
            exp2 = ceil(exp2 + ((float)e1/9 + 21));
        }
        exp1 = exp1 - e1;
    } else if (e1 >= 80 && e1 <= 99){
        exp2 = ceil(exp2 + ((float)e1/4 + 19));
        exp2 = ceil(exp2 + ((float)e1/9 + 21));
        if (exp2 > 400){
            exp2 = ceil(exp2 + ((float)e1/16 + 17));
            exp2 = ceil(exp2 * 1.15);
        }
        exp1 = exp1 - e1;
    } else {
        return -999;
    }
    
    
    //find exp1 for case 1
    if (e1 >= 0 && e1 <= 3){
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0){
            exp1 += D/200;
        } else {
            exp1 -= D/100;
        }
    }
    
    if (exp2 > 600){
        exp2 = 600;
    }
    if (exp2 < 0){
        exp2 = 0;
    }
    if (exp1 > 600){
        exp1 = 600;
    }
    if (exp1 < 0){
        exp1 = 0;
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
   if (E2 < 0 || E2 > 99){
    return -999;
   }
   //Path 1
   int S;
   float P1, P2, P3;
   int Difference;
   int minDifference = 99999999;
    for (int i = 1; i <= EXP1; i++){
        Difference = abs(EXP1 - (i*i));
        if (Difference < minDifference){        //find the smallest difference
            minDifference = Difference;
            S = i * i;                          
        }
    }

    if (S <= EXP1){
        P1 = 100;
    } else {
        P1 = (((float)EXP1/S + 80)/123) * 100;
    }

    //Path 2
    int expenditure1, expenditure2, expenditure3;
    int TotalExpenditure = 0;
    int MoneyLeft = M1;
    int DifferencePath2;
    int S2;
   
    
    
    if (E2 % 2 == 0){                //E2 even                                           
            //-----event 1-----
        while(true){
            if (HP1 < 200){
                HP1 = ceil(HP1 * 1.3);                
                MoneyLeft = MoneyLeft - 150;           
            } else {
                HP1 = ceil(HP1 * 1.1);
                MoneyLeft = MoneyLeft - 70;
            }
            if (MoneyLeft <= 0){
                MoneyLeft = 0;
                break;
            }

            //-----event 2-----
            if (EXP1 < 400){
                MoneyLeft = MoneyLeft - 200;
            } else {
                MoneyLeft = MoneyLeft - 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (MoneyLeft <= 0){
                MoneyLeft = 0;
                break;
            }

            //-----event 3-----
            if (EXP1 < 300){
                MoneyLeft = MoneyLeft - 100;
            } else {
                MoneyLeft = MoneyLeft - 120;
            }
            EXP1 = ceil(EXP1 * 0.9);
            if (MoneyLeft <= 0){
                MoneyLeft = 0;
                break;
            }
            break;
        }
        HP1  = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    } else {                            //E2 odd
        while (true){
    
            //-----event 1-----
            if (HP1 < 200){
                HP1 = ceil(HP1 * 1.3);
                MoneyLeft = MoneyLeft - 150;
                expenditure1 = 150;
            } else {
                HP1 = ceil(HP1 * 1.1);
                MoneyLeft = MoneyLeft - 70;
                expenditure1 = 70;
            }
            
            TotalExpenditure += expenditure1; 
            
            if (TotalExpenditure > (M1/2)){
                break;
            }

            //-----event 2-----
            if (EXP1 < 400){
                MoneyLeft = MoneyLeft - 200;
                expenditure2 = 200;
            } else {
                MoneyLeft = MoneyLeft - 120;
                expenditure2 = 120;
            }
            EXP1 = ceil(EXP1 * 1.13);

            TotalExpenditure += expenditure2;

            if (TotalExpenditure > (M1/2)){
                break;
            }

            //-----event 3-----
            if (EXP1 < 300){
                MoneyLeft = MoneyLeft - 100;
                expenditure3 = 100;
            } else {
                MoneyLeft = MoneyLeft - 120;
                expenditure3 = 120;
            }
            EXP1 = ceil(EXP1 * 0.9);

            TotalExpenditure += expenditure3;

            if (TotalExpenditure > (M1/2)){
                break;
            }
        }
        HP1  = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);
    }
    //Find square number
    int minDifferencePath2 = 99999999;
    for (int i = 1; i <= EXP1; i++){
        DifferencePath2 = abs(EXP1 - (i*i));
        if (DifferencePath2 < minDifferencePath2){        //find the smallest difference
            minDifferencePath2 = DifferencePath2;
            S2 = i * i;                          
        }
    }

    if (S2 <= EXP1){
        P2 = 100;
    } else {
        P2 = (((float)EXP1/S2 + 80)/123) * 100;
    }
    
    //Path 3
    int Probability[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int UnitsDigit, TensDigit, TotalUnitsTens, Index;

        if (E2 >= 0 && E2 <= 9){
            P3 = Probability[E2];
        } else {
            UnitsDigit = E2 % 10;
            TensDigit  = E2 / 10;
            TotalUnitsTens = UnitsDigit + TensDigit;
            Index = TotalUnitsTens % 10;
            P3 = Probability[Index];
        }
    //End of 3 paths
    M1 = MoneyLeft;
    float AverageP;
    if (P1 == 100 && P2 == 100 && P3 == 100){
        EXP1 = ceil(EXP1 * 0.75);
    } else {
        AverageP = (P1 + P2 + P3)/3;
        if (AverageP < 50){
            HP1  = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        } else {
            HP1  = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
    }

    if (EXP1 < 0){
        EXP1 = 0;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }

    if (HP1 < 0){
        HP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
    }

    if (M1 < 0){
        M1 = 0;
    }
    if (M1 > 3000){
        M1 = 3000;
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99){
        return -999;
    }

    int TaxiPoint[10][10] = {0};
    int SherlockAndWatsonPoint[10][10];
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            TaxiPoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    
    //Find Sherlock and Watson Point
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int row = i, col = j;
            int MaxLeftDiagonal = -99999999;
            int MaxRightDiagonal = -99999999; 

            //Left diagonal
            while (row >= 0 && col >= 0) {
                if (TaxiPoint[row][col] > MaxLeftDiagonal) {
                    MaxLeftDiagonal = TaxiPoint[row][col];
                }
                row--;
                col--;
            }
            row = i + 1;
            col = j + 1;
            while (row < 10 && col < 10) {
                if (TaxiPoint[row][col] > MaxLeftDiagonal) {
                    MaxLeftDiagonal = TaxiPoint[row][col];
                }
                row++;
                col++;
            }

            //Right diagonal
            row = i;
            col = j;
            while (row >= 0 && col < 10) {
                if (TaxiPoint[row][col] > MaxRightDiagonal) {
                    MaxRightDiagonal = TaxiPoint[row][col];
                }
                row--;
                col++;
            }
            row = i + 1;
            col = j - 1;
            while (row < 10 && col >= 0) {
                if (TaxiPoint[row][col] > MaxRightDiagonal) {
                    MaxRightDiagonal = TaxiPoint[row][col];
                }
                row++;
                col--;
            }

            if (MaxRightDiagonal > MaxLeftDiagonal){
                SherlockAndWatsonPoint[i][j] = abs(MaxRightDiagonal);
            } else {
                SherlockAndWatsonPoint[i][j] = abs(MaxLeftDiagonal);
            }
            
        }
    }
    
    int cntPositive = 0;
    int cntNegative = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (TaxiPoint[i][j] > (E3 * 2) && TaxiPoint[i][j] > 0){
                cntPositive += 1;
            }
        }
    }
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (TaxiPoint[i][j] < (-E3) && TaxiPoint[i][j] < 0){
                cntNegative += 1;
            }
        }
    }
    
    //Find the row i that Sherlock and Taxi met
    while (true){
        if (cntPositive > 9){
            cntPositive = (cntPositive % 10) + (cntPositive / 10);
        } else {
            break;
        }
    }
    int Value_i = cntPositive;
    
    //Find the Column that Sherlock and Taxi met
    while (true){
        if (cntNegative > 9){
            cntNegative = (cntNegative % 10) + (cntNegative / 10);
        } else {
            break;
        }
    }
    int Value_j = cntNegative;
    
    //Can SherlockAndWatson meet the Taxi ? 
    if (abs(TaxiPoint[Value_i][Value_j]) > SherlockAndWatsonPoint[Value_i][Value_j]){
        EXP1 = EXP1 * 0.88;
        EXP2 = EXP2 * 0.88;
        HP1 = HP1 * 0.9;
        HP2 = HP2 * 0.9;
        
    } else {
        EXP1 = EXP1 * 1.12;
        EXP2 = EXP2 * 1.12;
        HP1 = HP1 * 1.1;
        HP2 = HP1 * 1.1;
    }

    if (HP1 < 0){
        HP1 = 0;
    }
    if (HP1 > 666){
        HP1 = 666;
    }
    if (EXP1 < 0){
        EXP1 = 0;
    }
    if (EXP1 > 600){
        EXP1 = 600;
    }
    if (HP2 < 0){
        HP2 = 0;
    }
    if (HP2 > 666){
        HP2 = 666;
    }
    if (EXP2 < 0){
        EXP2 = 0;
    }
    if (EXP2 > 600){
        EXP2 = 600;
    }

    
    if (abs(TaxiPoint[Value_i][Value_j]) > SherlockAndWatsonPoint[Value_i][Value_j]){
        return TaxiPoint[Value_i][Value_j];
    } else {
        return SherlockAndWatsonPoint[Value_i][Value_j];
    }
    
    return -1;
}

// Task 4
bool checkPasswordSize(const char * s){                                     //Check if the password size valid or not
    if (strlen(s) >= 8 && strlen(s) <= 20){
        return true;
    }
    return false;
}
//-------------------------------------------------------------------
bool checkIf_s_Contain_se(const char * s, const char * email){              //Check if password contain string before '@'
    int s_length = strlen(s);
    bool Contain_se = false;
    char se[100];
    int se_length = 0;
    while (email[se_length] != '@'){                //Find se string of char before '@'
        se[se_length] = email[se_length];
        se_length++;                                
    }
    int sei;
    for (int i = 0; i < s_length; i++){
        bool CharFound = true;
        for (int j = 0; j < se_length; j++){
            if (s[i+j] != se[j]){
                CharFound = false;
                break;
            }
        }
        if (CharFound == true){
            sei = i;
            Contain_se = true;
            break;              //when se found in s -> out loop
        }
    }
    return Contain_se;
}
//-------------------------------------------------------------------
bool checkAtleastOneSpecialChar(const char * s){                            //Check at least 1 special character
    for (int i = 0; i < strlen(s); i++){                                    
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] =='!'){
            return true;
        }   
    }
    return false;
}
//-------------------------------------------------------------------
bool checkNumLowerUpercaseChar(const char * s, const char * email){         //Check if it contain only number, lowercase and uppercase letter
    for (int i = 0; i < strlen(s); i++){    
        if ((s[i] >= '0' && s[i] <= '9') && (s[i] >= 'A' && s[i] <= 'Z') && (s[i] >= 'a' && s[i] <= 'z')){
            return true;
        }
    }
    return false;
}

//-------------------------------------------------------------------
bool checkConsecutiveSpecialChar(const char * s, const char * email){       //Check if special character is consecutive
    for (int i = 0; i < strlen(s); i++){
        if ((s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '!') &&     
            (s[i+1] == '@'|| s[i+1] == '#' || s[i+1] == '%' || s[i+1] == '!')){
                return true;
            }
        }
        return false;
}

//-------------------------------------------------------------------
int checkPassword(const char * s, const char * email) {
    char se[100];
    int s_length = strlen(s);
    int se_length = 0;

    while (email[se_length] != '@'){                //Find se string of char before '@'
        se[se_length] = email[se_length];
        se_length++;                                
    }

    //Valid password check
    if ((checkPasswordSize(s) == true) && 
        (checkAtleastOneSpecialChar(s) == true) &&
        (checkIf_s_Contain_se(s, email) == false) &&
        (checkNumLowerUpercaseChar(s, email) == true) &&
        (checkConsecutiveSpecialChar(s, email) == false))       {
            return -10;                                                         //Valid password
        } else if (checkPasswordSize(s) == false && strlen(s) < 8){
            return -1;                                                          //Password size less than 8
        } else if (checkPasswordSize(s) == false && strlen(s) > 20){
            return -2;                                                          //Password size more than 20
        } else if (checkIf_s_Contain_se(s, email) == true){
            int sei;
            for (int i = 0; i < s_length; i++){
                bool CharFound = true;
                for (int j = 0; j < se_length; j++){
                    if (s[i+j] != se[j]){
                        CharFound = false;
                        break;
                    }
                }
                if (CharFound == true){
                    sei = i;
                    break;              //when se found in s -> out loop
                }
            }
            return -(300 + sei);                                                //s contains se
        } else if (checkConsecutiveSpecialChar(s, email) == true){
            int sci;
            for (int i = 0; i < strlen(s); i++){
                if (s[i] == '@' || s[i] == '%' || s[i] == '#' || s[i] == '!'){
                    sci = i;
                    break;
                }
            }
            return -(400 + sci);
        } else if (checkAtleastOneSpecialChar(s) == false) {
            return -5;
        } else if (checkNumLowerUpercaseChar(s, email) == false) {
            bool CharCheck;
            int ReturnValue;
            for (int i = 0; i < strlen(s); i++){    
                if ((s[i] >= '0' && s[i] <= '9') && (s[i] >= 'A' && s[i] <= 'Z') && (s[i] >= 'a' && s[i] <= 'z')){
                    CharCheck = true;
                } else {
                    CharCheck = false;
                    ReturnValue = i;
                    break;
                }
            }
            return ReturnValue;
        }

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int Max_Count = -999;
    int Max_Length = -999;
    int ReturnPosition;

    for (int i = 0; i < num_pwds; i++){
        const char* CurrentPassword = arr_pwds[i];
        int  CurrentPasswordLength = strlen(CurrentPassword);
        int  CurrentPasswordCount = 1;
        
        //Count each distinct password              
        for (int j = i + 1; j < num_pwds; j++){                                                 //Compare the current password with the next password and so on
            if (strcmp(CurrentPassword, arr_pwds[j]) == 0){         
                CurrentPasswordCount++;                                                         //if current password same as next -> count++                       
            }
        }

        if (CurrentPasswordCount > Max_Count){                                                   //Only one Max_count
            Max_Count = CurrentPasswordCount;
            ReturnPosition = i;
        } else if ((CurrentPasswordCount == Max_Count) && (CurrentPasswordLength > Max_Length)){    //Two Max_count -> consider the Max_Length next
            Max_Count = CurrentPasswordCount;
            Max_Length = CurrentPasswordLength;
            ReturnPosition = i;
        }
    }
    return ReturnPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////