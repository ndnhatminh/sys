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
// Check range
void checkValue(int &val1, int &val2, int limit)
{

    val1 = (val1 > limit) ? limit : ((val1 < 0) ? 0 : val1);
    val2 = (val2 > limit) ? limit : ((val2 < 0) ? 0 : val2);
}

void expRange(int &EXP1, int &EXP2)
{
    checkValue(EXP1, EXP2, 600);
}

void hpRange(int &HP1, int &HP2)
{
    checkValue(HP1, HP2, 666);
}

void mRange(int &M1, int &M2)
{
    checkValue(M1, M2, 3000);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    // Case 1
    if (e1 <= 3 && e1 >= 0) {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else
            exp2 += 149; 

        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
            exp1 = static_cast<int>(std::ceil(exp1 + (D / 200.0) - 0.001)); // Làm tròn lên
        else
            exp1 = static_cast<int>(std::ceil(exp1 - (D / 100.0) - 0.001)); // Làm tròn lên     
    }
 
    // Case 2
    else if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19)
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
        else if (e1 >= 20 && e1 <= 49)
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
        else if (e1 >= 50 && e1 <= 65)
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 16.0 + 17) - 0.001));
        else if (e1 >= 66 && e1 <= 79) {
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
            if (exp2 > 200)
                exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
        } else {
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 4.0 + 19) - 0.001));
            exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 9.0 + 21) - 0.001));
            if (exp2 > 400) {
                exp2 = static_cast<int>(std::ceil(exp2 + (e1 / 16.0 + 17) - 0.001));
                exp2 = static_cast<int>(std::ceil(exp2 * 1.15 - 0.001));
            }
        }

        exp1 -= e1;
    }
    
    expRange(exp1, exp2); 
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
   if (E2 < 0 || E2 > 99)
        return -99;

    double P1, P2, P3;

    // firstStreet 
    int S = sqrt(EXP1);
    if (EXP1 >= S)
        P1 = 100;
    else
        P1 = ((EXP1 / S + 80) / 123.0) * 100;

    // secondStreet 
    double initialM = M1 * 0.5;
    while (true)
    {
        // Event 1
        if (HP1 < 200)
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 1.3 - 0.001));
            M1 -= 150;
        }
        else if (HP1 >= 200)
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 1.1 - 0.001));
            M1 -= 70;
        }
        hpRange(HP1, HP1); 
        mRange(M1, M1);    
        if (E2 % 2 == 1 && M1 < initialM)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            expRange(EXP1, EXP1);
            hpRange(HP1, HP1);   
            P2 = 100;
            break;
        }
        else if (E2 % 2 == 0 && M1 == 0)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            expRange(EXP1, EXP1); 
            hpRange(HP1, HP1);  
            P2 = 100;
            break;
        }

        // Event 2
        if (EXP1 < 400)
            M1 -= 200;
        else if (EXP1 >= 400)
            M1 -= 120;
        EXP1 = static_cast<int>(std::ceil(EXP1 * 1.13 - 0.001));
        expRange(EXP1, EXP1); 
        mRange(M1, M1);      
        if (E2 % 2 == 1 && M1 < initialM)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            expRange(EXP1, EXP1); 
            hpRange(HP1, HP1);   
            P2 = 100;
            break;
        }
        else if (E2 % 2 == 0 && M1 == 0)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            P2 = 100;
            break;
        }

  
        if (EXP1 < 300)
            M1 -= 100;
        else if (EXP1 >= 300)
            M1 -= 120;
        EXP1 = static_cast<int>(std::ceil(EXP1 * 0.9 - 0.001));
        if (E2 % 2 == 1 && M1 <= initialM)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            P2 = 100;
            break;
        }
        else if (E2 % 2 == 0)
        {
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.17 - 0.001));
            HP1 = static_cast<int>(std::ceil(HP1 - HP1 * 0.17 - 0.001));
            P2 = 100;
            break;
        }
    }

    // thirdStreet 
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        i = (E2 / 10 + E2 % 10) % 10;
    }
    P3 = P[i];

    double Psum = (P1 + P2 + P3) / 3;

    if (Psum == 100)
        EXP1 = static_cast<int>(std::ceil(EXP1 * 0.75 - 0.001));
    else
    {
        if (Psum < 50)
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 0.85 - 0.001));
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.15 - 0.001));
        }
        else
        {
            HP1 = static_cast<int>(std::ceil(HP1 * 0.9 - 0.001));
            EXP1 = static_cast<int>(std::ceil(EXP1 * 1.2 - 0.001));
        }
    }
    expRange(EXP1, EXP1); 
    hpRange(HP1, HP1);    

    return HP1 + EXP1 + M1;
}

// Task 3
int calculateDiagonalMax(int i, int j, int size, int taxiMap[10][10]) {
    int diagonalMax = taxiMap[i][j];
    
    // Check left diagonal
    for (int k = 0; k < std::min(i, j); k++) {
        diagonalMax = std::max(diagonalMax, taxiMap[i - k][j - k]);
    }

    // Check right diagonal
    for (int k = 0; k < std::min(size - i, j); k++) {
        diagonalMax = std::max(diagonalMax, taxiMap[i + k][j - k]);
    }

    return diagonalMax;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
   if (E3 < 0 || E3 > 99)
        return -99;

    const int size = 10;
    int taxiMap[size][size] = {0};
    int sherlockWatsonMap[size][size] = {0};

    // taxiMap
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // sherlockWatsonMap
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sherlockWatsonMap[i][j] = calculateDiagonalMax(i, j, size, taxiMap);
            sherlockWatsonMap[i][j] = abs(sherlockWatsonMap[i][j]);
        }
    }

    //meeting position
    int I = 0, J = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (taxiMap[i][j] > E3 * 2)
                I++;
            if (taxiMap[i][j] < -E3)
                J++;
        }
    }

    //multidigit numbers
    while (I >= 10 || J >= 10) {
        if (I >= 10)
            I = I / 10 + I % 10;
        if (J >= 10)
            J = J / 10 + J % 10;
    }
    int maxScore; 
    bool taxiCaught = abs(taxiMap[I][J]) <= abs(sherlockWatsonMap[I][J]);
    if (taxiCaught) {
        EXP1 = static_cast<int>(std::ceil(EXP1 * 1.12 - 0.001));
        HP1 = static_cast<int>(std::ceil(HP1 * 1.1 - 0.001));
        EXP2 = static_cast<int>(std::ceil(EXP2 * 1.12 - 0.001));
        HP2 = static_cast<int>(std::ceil(HP2 * 1.1 - 0.001));
        maxScore = sherlockWatsonMap[I][J];
    } else {
        EXP1 = static_cast<int>(std::ceil(EXP1 * 0.88 - 0.001));
        HP1 = static_cast<int>(std::ceil(HP1 * 0.9 - 0.001));
        EXP2 = static_cast<int>(std::ceil(EXP2 * 0.88 - 0.001));
        HP2 = static_cast<int>(std::ceil(HP2 * 0.9 - 0.001));
        maxScore = taxiMap[I][J];
    }


    return maxScore;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    std::string pass(s);
    std::string Email(email);
    std::string userPrefix = Email.substr(0, Email.find('@'));

    if (pass.length() < 8 || pass.length() > 20) {
        return (pass.length() < 8) ? -1 : -2;
    }

    size_t prefixPos = pass.find(userPrefix);
    if (prefixPos != std::string::npos) {
        return -(300 + static_cast<int>(prefixPos));
    }
    for (size_t i = 0; i < pass.length() - 2; ++i) {
        if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
    }

    const char specialChars[] = "@#%$!";
    bool containsSpecialChar = false;
    for (char c : pass) {
        if (std::strchr(specialChars, c) != nullptr) {
            containsSpecialChar = true;
            break;
        }
    }
    if (!containsSpecialChar) {
        return -5;
    }
    for (char c : pass) {
        if (!std::isalnum(c) && std::strchr(specialChars, c) == nullptr) {
            return static_cast<int>(pass.find(c));
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int maxCount = 0, maxLength = 0, firstPos = 0;

    for (int i = 0; i < num_pwds; ++i) {
        int count = 0, length = std::strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; ++j) {
            if (std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            firstPos = i;
        }
    }

    return firstPos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////