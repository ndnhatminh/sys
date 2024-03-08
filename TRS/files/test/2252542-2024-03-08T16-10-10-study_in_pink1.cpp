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

void setEXP(int &exp) {
    exp = max(0, min(exp, 600));
}

void setHP(int &hp) {
    hp = min(666, max(0, hp));
}

void setM(int &m) {
    m = min(3000, max(0, m));
}

int nearestSquareNumber(int N) {
    int sqrtN = floor(sqrt(N));
    int lowerSquare = pow(sqrtN, 2);
    int upperSquare = pow(sqrtN + 1, 2);

    if (N - lowerSquare <= upperSquare - N) {
        return lowerSquare;
    } else {
        return upperSquare;
    }
}

int firstMeet(int &EXP1, int &EXP2, int E1) {
    // case 1: E = [0,3]
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else if (E1 == 3) EXP2 += (29 + 45 + 75);

        // Sherlock's decision (D)
        int D = E1 * 3 + EXP1 * 7;

        // If D is even, increase EXP1
        if (D % 2 == 0) EXP1 += static_cast<int>(ceilf(D / 200.0));
        // If D is odd, decrease EXP1
        else {
            int temp= ceilf(EXP1 - (D/100.0));
            EXP1 = temp;
        }   

        setEXP(EXP1);
        setEXP(EXP2);

        return EXP1 + EXP2;
    } 
    
    else if (E1 >= 4 && E1 <= 99) {
        // case 2: E1 = [4,99]
        if (E1 >= 4 && E1 <= 19) EXP2 += static_cast<int>(ceilf((E1 / 4.0) + 19));

        else if (E1 >= 20 && E1 <= 49) EXP2 += static_cast<int>(ceilf((E1 / 9.0) + 21));

        else if (E1 >= 50 && E1 <= 65) EXP2 += static_cast<int>(ceilf((E1 / 16.0) + 17));

        else if (E1 >= 66 && E1 <= 79) {
            EXP2 += static_cast<int>(ceilf((E1 / 4.0) + 19));
            if (EXP2 > 200) EXP2 += static_cast<int>(ceilf((E1 / 9.0) + 21));
        } 

        else if (E1 >= 80 && E1 <= 99) {
            EXP2 += static_cast<int>(ceilf((E1 / 4.0) + 19));
            EXP2 += static_cast<int>(ceilf((E1 / 9.0) + 21));
            if (EXP2 > 400) EXP2 += static_cast<int>(ceilf((E1 / 16.0) + 17));
            
            // increase EXP2 15%
            int additionalEXP = static_cast<int>(ceilf(0.15 * EXP2));
            EXP2 += additionalEXP;
            setEXP(EXP1);
            setEXP(EXP2);        
        }
    EXP1 -= E1;
    return EXP1 + EXP2;
    }

    return -99;

}


int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;

    //  Nearest square number
    int S1 = nearestSquareNumber(EXP1);

    // Path 01
    double P1;
    if (EXP1 >= S1) {
        P1 = 1.0; // 100%
    } 
    else {
        P1 = (EXP1 * 1.0 / S1 + 80) / 123;
    }

    // Path 02
    int money_spent = 0;
    int initial_money = M1;

    // Even for odd E2
    if (E2 % 2 == 1) {
        while (money_spent <= 0.5 * initial_money) {
            // Event 1
            if (HP1 < 200) {
                HP1 = ceilf(HP1 * (13.0/10));
                setHP(HP1);
                M1 -= 150;
                setM(M1);
                money_spent += 150;
            } 
            else {
                HP1 = ceilf(HP1 * 1.1);
                setHP(HP1);
                M1 -= 70;
                setM(M1);
                money_spent += 70;
            }

            // Event 2
            if (money_spent <= 0.5 * initial_money) {   
                if (EXP1 < 400) {
                    EXP1 = ceilf(EXP1 * 1.13);
                    setEXP(EXP1);
                    M1 -= 200;
                    setM(M1);
                    money_spent += 200;
                } 
                else {
                    EXP1 = ceilf(EXP1 * 1.13);
                    setEXP(EXP1);
                    M1 -= 120;
                    setM(M1);
                    money_spent += 120;
                }
            }
            else break;

            // Event 3
            if (money_spent <= 0.5 * initial_money) { 
                if (EXP1 < 300) {
                    EXP1 = ceilf(EXP1 * 0.9);
                    setEXP(EXP1);
                    M1 -= 100;
                    setM(M1);
                    money_spent += 100;
                } 
                else {
                    EXP1 = ceilf(EXP1 * 0.9);
                    setEXP(EXP1);
                    M1 -= 120;
                    setM(M1);
                    money_spent += 120;
                }
            }
            else break;
        }
        HP1 = ceilf(HP1*(8.30/10));
        setHP(HP1);
        EXP1 = ceilf(EXP1*(11.7/10));
        setEXP(EXP1);
    } 
    
    else {
        // Event for even E2
        // Event 1
        if (M1 > 0) {
            if (HP1 < 200) {                    
                HP1 = ceilf(HP1 * 1.3);     
                setHP(HP1);                 
                M1 -= 150;
                setM(M1);                                  
                money_spent += 150;
            } 
            else {
                HP1 = ceilf(HP1 * 1.1);
                setHP(HP1);
                M1 -= 70;
                setM(M1);
                money_spent += 70;                                  
            }
        }

        // Event 2
        if (M1 > 0) {
            if (EXP1 < 400) {                       
                EXP1 = ceilf(EXP1 * 1.13);
                setEXP(EXP1);                      
                M1 -= 200;
                setM(M1);                                         
                money_spent += 200;
            } 
            else {
                EXP1 = ceilf(EXP1 * 1.13);
                setEXP(EXP1);
                M1 -= 120;
                setM(M1);
                money_spent += 120;
            }
        }

        // Event 3
        if (M1 > 0) {
            if (EXP1 < 300) {
                EXP1 = ceilf(EXP1 * 0.9);
                setEXP(EXP1);
                M1 -= 100;
                setM(M1);
                money_spent += 100;
            } 
            else {
                EXP1 = ceilf(EXP1 * 0.9);
                setEXP(EXP1);
                M1 -= 120;
                setM(M1);
                money_spent += 120;
            }
        }
        HP1 = ceilf(HP1*(8.30/10));
        setHP(HP1);
        EXP1 = ceilf(EXP1*(11.7/10));
        setEXP(EXP1);
    }

    // Calculate P2
    int S2 = nearestSquareNumber(EXP1);
    double P2 = 0.0;
    if (EXP1 >= S2) {
        P2 = 1.0; // 100%
    } else {
        P2 = (EXP1 * 1.0 / S2 + 80) / 123;
    }

    // Path 03
    int P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sumDigits = (E2 / 10 + E2 % 10) % 10;
        i = sumDigits;
    }

    double P3_result = P3[i] * 0.01;

    // Final calculations
    double finalProbability = (P1 + P2 + P3_result) / 3;
    if (finalProbability == 1) {
        EXP1 = ceilf(EXP1 * (7.5/10));
        setEXP(EXP1);
    }
    else if (finalProbability < 0.5) {
        HP1 = ceilf(HP1 * (8.5/10));
        setHP(HP1);
        EXP1 = ceilf(EXP1 * (11.5/10));
        setEXP(EXP1);
    } else {
        HP1 = ceilf(HP1 * (9.0/10));
        setHP(HP1);
        EXP1 = ceilf(EXP1 * (12.0/10));
        setEXP(EXP1);
    }

    // Update values within boundaries
    setHP(HP1);
    setEXP(EXP1);
    setM(M1);

    return HP1 + EXP1 + M1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) return -99;

    setEXP(EXP1);
    setEXP(EXP2);
    setHP(HP1);
    setHP(HP2);

    if (E3 < 0 || E3 > 99) return -99;
    int arr[10][10];
    int bigger = 0, smaller = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > (2 * E3))
                bigger++;
            if (arr[i][j] < (-E3))
                smaller++;
        }
    }

    //Find meeting place
    int posI = 0;
    int posJ = 0;
    while (bigger >= 10) {
        bigger = bigger/10 + bigger%10;
    }
    posI = bigger;
    
    while (smaller >= 10) {
        smaller = smaller/10 + smaller%10;
    }
    posJ = smaller;

    int taxiPoint = arr[posI][posJ]; // taxi point

    // Find maxPoint of Sherlock and Watson
    int maxPoint = arr[posI][posJ];


    int i_for_loop = posI;
    int j_for_loop = posJ;                                    
    
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop -= 1;
        j_for_loop -=1;
        
        if (maxPoint < arr[i_for_loop][j_for_loop]) {
            maxPoint = arr[i_for_loop][j_for_loop];
        }
    }
    

    i_for_loop = posI;
    j_for_loop = posJ;
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop -= 1;
        j_for_loop +=1;
        
        if (maxPoint < arr[i_for_loop][j_for_loop]) {
            maxPoint = arr[i_for_loop][j_for_loop];
        }
    }
    

    i_for_loop = posI;
    j_for_loop = posJ;
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop += 1;
        j_for_loop -=1;
        
        if (maxPoint < arr[i_for_loop][j_for_loop]) {
            maxPoint = arr[i_for_loop][j_for_loop];
        }
    }
    

    i_for_loop = posI;
    j_for_loop = posJ;
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop += 1;
        j_for_loop +=1;
        
        if (maxPoint < arr[i_for_loop][j_for_loop]){
             maxPoint = arr[i_for_loop][j_for_loop];
        }
    }


    int result = 0;
    if (abs(taxiPoint) > maxPoint)
    {
        EXP1 = ceil(EXP1 - 0.12*EXP1);
        HP1 = ceil(HP1 - 0.1*HP1);
        EXP2 = ceil(EXP2 - 0.12*EXP2);
        HP2 = ceil(HP2 - 0.1*HP2);
        result = arr[posI][posJ];
    }
    else if (abs(arr[posI][posJ]) <= maxPoint)
    {
        EXP1 = ceil(EXP1 + 0.12*EXP1);
        HP1 = ceil(HP1 + 0.1*HP1);
        EXP2 = ceil(EXP2 + 0.12*EXP2);
        HP2 = ceil(HP2 + 0.1*HP2);
        result = maxPoint;
    }
        
    setEXP(EXP1);
    setEXP(EXP2);
    setHP(HP1);
    setHP(HP2);

    return result;
}


int checkPassword(const char *s, const char *email)
{
    const int min_length = 8;
    const int max_length = 20;
    const char special_chars[] = "@#$!%";
    
    // Find se before @ in email     
    char se[101];
    size_t at_position = strcspn(email, "@");
    strncpy(se, email, at_position);
    se[at_position] = '\0';

    // Check length of password (8 < s < 20)
    size_t s_length = strlen(s);
    if (s_length < min_length) return -1;
    if (s_length > max_length) return -2;

    // Check s contains se
    const char *se_occurrence = strstr(s, se);
    if (se_occurrence != nullptr) {
        size_t sei = se_occurrence - s;
        return -(300 + static_cast<int>(sei));
    }

    // Check consecutive characters
    for (size_t i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
    }

    // Check special characters
    if (strpbrk(s, special_chars) == nullptr) {
        return -5;
    }

    // Check other condition
    for (size_t i = 0; i < s_length; ++i) {
        if (!(isalnum(s[i]) || strchr(special_chars, s[i]))) {
            return static_cast<int>(i);
        }
    }

    return -10;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxFreq = 0;  // max frequency
    int maxLength = 0;  // longest password
    int pos = -1;  // first position of correct password

    for (int i = 0; i < num_pwds; ++i) {
        int currentFreq = 0;  // currnt frequency
        int currentLength = strlen(arr_pwds[i]);  // length of current password

        for (int j = 0; j < num_pwds; ++j) {
            if (strstr(arr_pwds[i], arr_pwds[j]) != nullptr && strlen(arr_pwds[i]) == strlen(arr_pwds[j])) { 
                currentFreq++;
            }
        }

        // compare password
        if ((currentFreq > maxFreq) || (currentFreq == maxFreq && currentLength > maxLength)) {
            maxFreq = currentFreq;
            maxLength = currentLength;
            pos = i;
        }
    }

    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////