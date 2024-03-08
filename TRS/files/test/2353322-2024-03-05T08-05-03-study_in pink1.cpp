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

// Check
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
int firstMeet(int &EXP1, int &EXP2, int E1) {
    // Case 1
    if (E1 <= 3 && E1 >= 0) {
        if (E1 == 0)
            EXP2 += 29;
        else if (E1 == 1)
            EXP2 += 45;
        else if (E1 == 2)
            EXP2 += 75;
        else
            EXP2 += 149; 

        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
            EXP1 = static_cast<int>(std::ceil(EXP1 + (D / 200.0) - 0.001)); // Làm tròn lên
        else
            EXP1 = static_cast<int>(std::ceil(EXP1 - (D / 100.0) - 0.001)); // Làm tròn lên     
    }
 
    // Case 2
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19)
            EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 4.0 + 19) - 0.001));
        else if (E1 >= 20 && E1 <= 49)
            EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 9.0 + 21) - 0.001));
        else if (E1 >= 50 && E1 <= 65)
            EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 16.0 + 17) - 0.001));
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 4.0 + 19) - 0.001));
            if (EXP2 > 200)
                EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 9.0 + 21) - 0.001));
        } else {
            EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 4.0 + 19) - 0.001));
            EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 9.0 + 21) - 0.001));
            if (EXP2 > 400) {
                EXP2 = static_cast<int>(std::ceil(EXP2 + (E1 / 16.0 + 17) - 0.001));
                EXP2 = static_cast<int>(std::ceil(EXP2 * 1.15 - 0.001));
            }
        }

        EXP1 -= E1;
    }
    
    expRange(EXP1, EXP2); 
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) 
{
    return HP1 + HP2;
}
// Task 4
int checkPassword(const char* password, const char* email) {
    return -10;
}


// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    return 0;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////