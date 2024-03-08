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

int clampEXP(int points) {
    return max(0, min(points, 600));
}

int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (E1 < 0 || E1 > 99) return -99;
    EXP1 = clampEXP(EXP1);
    EXP2 = clampEXP(EXP2);
    // Case 1: E1 is in [0, 3]
    if (E1 >= 0 && E1 <= 3) {
        int D = E1 * 3 + EXP1 * 7; 
        switch (E1) {
            case 0: EXP2 += 29; break;
            case 1: EXP2 += 45; break;
            case 2: EXP2 += 75; break;
            case 3: EXP2 += 29 + 45 + 75; break;
            default: break; 
        }
        EXP1 = clampEXP(EXP1);
        EXP2 = clampEXP(EXP2);
        if (D % 2 == 0) { // D is even
            EXP1 = ceil(EXP1 + static_cast<double>(D) / 200.0);
            EXP1 = clampEXP(EXP1);
        } else { // D is odd
            EXP1 = ceil(EXP1 - static_cast<double>(D) / 100.0);
            EXP1 = clampEXP(EXP1);
        }
        return EXP1 + EXP2;

    }

    // Case 2: E1 is in [4, 99]

    if (E1 >= 4 && E1 <= 19) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19));
        EXP2 = clampEXP(EXP2);

        EXP1 -= E1;
        EXP1 = clampEXP(EXP1);
    }

    if (E1 >= 20 && E1 <= 49) {
        EXP2 = ceil(EXP2 + (E1 / 9.0 + 21));
        EXP2 = clampEXP(EXP2);

        EXP1 -= E1;
        EXP1 = clampEXP(EXP1);
    }
    if (E1 >= 50 && E1 <= 65) {
        EXP2 = ceil(EXP2 + (E1 / 16.0 + 17));
        EXP2 = clampEXP(EXP2);

        EXP1 -= E1;
        EXP1 = clampEXP(EXP1);
    }
    if (E1 >= 66 && E1 <= 79) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19));
        EXP2 = clampEXP(EXP2);

        EXP1 -= E1;
        EXP1 = clampEXP(EXP1);

        if (EXP2 > 200) {
            EXP2 = ceil(EXP2 + (E1 / 9.0 + 21));
            EXP2 = clampEXP(EXP2);
        }
    }

    if (E1 >= 80 && E1 <= 99) {
        EXP2 = ceil(EXP2 + (E1 / 4.0 + 19));
        EXP2 = clampEXP(EXP2);

        EXP2 = ceil(EXP2 + (E1 / 9.0 + 21));
        EXP2 = clampEXP(EXP2);

        EXP1 -= E1;
        EXP1 = clampEXP(EXP1);

        if (EXP2 > 400) {
            EXP2 = ceil(EXP2 + (E1 / 16.0 + 17));
            EXP2 = clampEXP(EXP2);

            EXP2 = ceil(EXP2 * 1.15);
            EXP2 = clampEXP(EXP2);
        }
    }
    return EXP1 + EXP2;
}
    
// Task 2
void lim(int& HP, int& EXP, int& M) {
    HP = max(0, min(HP, 666));
    EXP = max(0, min(EXP, 600));
    M = max(0, min(M, 3000));
}

// Function to determine the nearest perfect square to the given number
int nearestPerfectSquare(int num) {
    int root = static_cast<int>(sqrt(num));
    // Check which square is closer to num, root^2 or (root+1)^2
    return num - root*root <= (root+1)*(root+1) - num ? root*root : (root+1)*(root+1);
}

int clamp(int a, int b, int c)
{
    if (a < b)
        return b;
    if (a > c)
        return c;
    return a;
}

// Main function to describe Sherlock's luggage searching process

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    lim(HP1, EXP1, M1); 

    // Calculate the probability P1
    int S = nearestPerfectSquare(EXP1);
    double P1 = EXP1 >= S ? 1.0 : (static_cast<double>(EXP1) / (S) + 80)/123.0;

    // Calculate the probability P2 for Road 02
    double P2 = 0;
    // Road 02 logic
    bool isE2Odd = E2 % 2 != 0; 
    int initialM = M1; 
    int debugCounter = 0;
    while (M1>0) {

        // Event: Grocery store or water
        M1 = clamp(HP1 < 200 ? M1 - 150 : M1 - 70, 0, 3000);
        HP1 = clamp(ceil(HP1 < 200 ? HP1 * 130 / 100.0 : HP1 * 110 / 100.0), 0, 666);

        if (isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) { 
            break; 
        } else if (!isE2Odd && !M1) { 
            break; 
        }

        // Event: Renting a taxi or carriage
        M1 = clamp(EXP1 < 400 ? M1 - 200 : M1 - 120, 0, 3000);
        EXP1 = clamp(ceil(EXP1 * 113 / 100.0), 0, 600);

        if (isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) {
            break; 
        } else if (!isE2Odd && !M1) { 
            break;
        }

        // Event: Help a homeless person
        M1 = clamp(EXP1 < 300 ? M1 - 100 : M1 - 120, 0, 3000);
        EXP1 = clamp(ceil(EXP1 * 90 / 100.0), 0, 600);

        if (isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) { 
            break; 
        } else if (!isE2Odd && !M1) { 
            break; 
        }

        debugCounter++;
        if (!isE2Odd) { 
            break;
        }
        if (isE2Odd && (M1 < ceil(initialM / 2.0) || !M1)) { 
            break; 
        }
    }

    HP1 = clamp(ceil(HP1 * 83 / 100.0), 0, 666);
    EXP1 = clamp(ceil(EXP1 * 117 / 100.0), 0, 600);


    // Calculate the probability P2 for Road 02
    // Similar logic to P1 with the nearest perfect square to EXP1
    int S2 = nearestPerfectSquare(EXP1);
    P2 = EXP1 >= S2 ? 1.0 : (static_cast<double>(EXP1) / S2 + 80)/123.0;
    P2 = max(0.0, min(P2, 1.0));

    // Calculate the probability P3 for Road 03
    const int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2 > 9) ? (E2 / 10 + E2 % 10) % 10 : E2;
    double P3 = P[i] / 100.0; 

    double averageP = (P1 + P2 + P3) / 3;
    if(averageP == 1.0) {
        EXP1 = ceil(EXP1 * 0.75);

    } else {
        HP1 = ceil(averageP < 0.5 ? HP1 * 85 / 100.0 : HP1 * 90 / 100.0);
        EXP1 = ceil(averageP < 0.5 ? EXP1 * 115 / 100.0 : EXP1 * 120 / 100.0);
    }

    lim(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}


// Task 3
// Calculate the maximum value from both the left diagonal and right diagonal of the matrix
int maxValue(int maxtrix[10][10],int row,int collumn) {
    int max = 0;
    for (int i = row, j = collumn; i >= 0 && j >= 0 && i < 10 && j < 10; i--, j--) {
        if (maxtrix[i][j] > max) {
            max = maxtrix[i][j];
        }
    }
    for (int i = row, j = collumn; i >= 0 && j >= 0 && i < 10 && j < 10; i--, j++) {
        if (maxtrix[i][j] > max) {
            max = maxtrix[i][j];
        }
    }
    for (int i = row, j = collumn; i >= 0 && j >= 0 && i < 10 && j < 10; i++, j--) {
        if (maxtrix[i][j] > max) {
            max = maxtrix[i][j];
        }
    }
    for (int i = row, j = collumn; i >= 0 && j >= 0 && i < 10 && j < 10; i++, j++) {
        if (maxtrix[i][j] > max) {
            max = maxtrix[i][j];
        }
    }
    return max;
}

void lim(int& HP, int& EXP){
	HP = max(0, min(HP, 666));
    EXP = max(0, min(EXP, 600));
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;
    lim(HP1,EXP1);
    lim(HP2,EXP2);
    E3 = max(0, min(E3, 99));
    // Initialize the coordinates of the taxi when Taxi would meet Sherlock and Watson at a point (x, y).
    int x = 0, y = 0;
    // TODO: Complete this function
	int matrix[10][10];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j){
		
			matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (matrix[i][j] > E3 * 2)
                x++;
            if (matrix[i][j] < -E3)
                y++;
		}
	}
	// Calculate the final point where the taxi would meet Sherlock and Watson
    while (x > 9){
        x = x % 10 + x / 10; // Calculate the sum of digits of x until x is less than 10
    }
    while (y > 9){
        y = y % 10 + y / 10; // Calculate the sum of digits of y until y is less than 10
    }
    // Calculate the final score of the taxi
    int taxiScore = matrix[x][y];
    // Calculate the final score of Sherlock and Watson
    int sherlockScore = maxValue(matrix, x, y);
    bool isTaxiHigher = abs(taxiScore) > sherlockScore;
    double newEXP1 = isTaxiHigher ? EXP1 * 88 / 100.0 : EXP1 * 112 / 100.0;
	double newEXP2 = isTaxiHigher ? EXP2 * 88 / 100.0 : EXP2 * 112 / 100.0;
	EXP1 = clamp(ceil(newEXP1), 0, 600);
	EXP2 = clamp(ceil(newEXP2), 0, 600);
	double newHP1 = isTaxiHigher ? HP1 * 90 / 100.0 : HP1 * 110 / 100.0;
	double newHP2 = isTaxiHigher ? HP2 * 90 / 100.0 : HP2 * 110 / 100.0;
	HP1 = clamp(ceil(newHP1), 0, 666);
	HP2 = clamp(ceil(newHP2), 0, 666);
	// Return the larger score between taxiScore and sherlockScore
	return abs(taxiScore) > abs(sherlockScore) ? taxiScore : sherlockScore;
	    return -1;
	}

// Task 4
#include <ctype.h>

int checkPassword(const char * s, const char * email) {
    char se[101];
    int i = 0;
	// Store <se> 
    while(email[i] != '@' && email[i] != '\0') {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0'; 
	// Store length of s  
    int len_s = 0;
    while(s[len_s] != '\0') {
        len_s++;
    }
	// check the condition
    if(len_s < 8) {
        return -1;
    } else if(len_s > 20) {
        return -2;
    }
	// check if <se> is in <s>
    int j, k;
    for(i = 0; i < len_s; i++) {
        for(j = i, k = 0; se[k] != '\0' && s[j] == se[k]; j++, k++);

        if(k > 0 && se[k] == '\0') {
            return -(300 + i);
        }
    }
 	// check 2 consecutive
    for(i = 0; i < len_s - 2; i++) {
        if(s[i] == s[i+1] && s[i] == s[i+2]) {
            return -(400 + i);
        }
    }
	// check special character in <s>
    bool specialCharFound = false;
    for(i = 0; i < len_s; i++) {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialCharFound = true;
            break;
        }
    }
    // check condition
    if(!specialCharFound) {
        return -5;
    }

    for(i = 0; i < len_s; i++) {
        if(!(isalpha(s[i]) || isdigit(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }

    	return -10;
    
    return -99; 
}


// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int firstOccurrence[30] = {0};
    int count[30] = {0};
    int length[30] = {0};
    int maxCount = 0, maxLength = 0;
    int correctPwdIndex = -1;
    // Loop over all passwords
    for (int i = 0; i < num_pwds; i++) {
    	// Get the length of the current password
        int len = strlen(arr_pwds[i]);
        bool found = false;
        // Loop over the previous password
        for (int j = 0; j < i; j++) {
        	// compare the current one with the previous
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count[j]++;
                length[j] = len;
                found = true;
                break;
            }
        }
        // if it appear first time
        if (!found) {
            firstOccurrence[i] = i;
            count[i] = 1;
            length[i] = len;
        }
    }
	// Loop over all passwords again
    for (int i = 0; i < num_pwds; i++) {
    	// Check if it appear more or longer 
        if (count[i] > maxCount || (count[i] == maxCount && length[i] > maxLength)) {
            maxCount = count[i];
            maxLength = length[i];
            correctPwdIndex = firstOccurrence[i];
        }
    }
	// return the correct pass
    return correctPwdIndex;
    
return -1; 
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
