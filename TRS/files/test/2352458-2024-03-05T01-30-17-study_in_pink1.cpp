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

int correctHP (float a) { return (ceil (a) > 666) ? 666 : ((ceil (a) < 0) ? 0 : ceil (a)); }
int correctEXP (float a) { return (ceil (a) > 600) ? 600 : ((ceil (a) < 0) ? 0 : ceil (a)); }
int correctM (float a) { return (ceil (a) > 3000) ? 3000 : ((ceil (a) < 0) ? 0 : ceil (a)); }
int plusDigit (int n) { return ((n < 10) ? n : (plusDigit((n / 10) + (n % 10)))); }
int arrayFind (int num, string arr[], string value)
{
    for (int i = 0; i < num; ++i)
    {
        cout << "DB" << i << " " << arr[i] << " " << value << endl;
        if (arr[i] == value)
        {
            return i;
        } 
    }
    return -1;
}

// Task 1
int firstMeet (int & exp1, int & exp2, int e1)
{
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) 
    {
        return -99;
    }
    exp1 = correctEXP(exp1);
    exp2 = correctEXP(exp2);

    /* 4.1.1 */
    if (e1 >=0 && e1 <= 3)
    {
        exp2 = correctEXP (exp2 + ((e1 == 0) ? 29 : ((e1 == 1) ? 45 : ((e1 == 2) ? 75 : (29 + 45 + 75)))));
        int d = (e1 * 3 + exp1 * 7);
        exp1 = correctEXP (exp1 + ((d % 2 == 0) ? (float)d/200 : (float)-d/100));
    }

    /* 4.1.2 */
    else if (e1 >= 4 && e1 <= 99)
    {
        exp2 = correctEXP (exp2 + ((e1 >= 4 && e1 <= 19) ? ((float)e1 / 4 + 19) : ((e1 >= 20 && e1 <= 49) ? ((float)e1 / 9 + 21) : ((e1 >= 50 && e1 <= 65) ? ((float)e1/16 + 17) : 0))));
        if (e1 >= 66 && e1 <= 79) 
        {
            exp2 = correctEXP (exp2 + ((float)e1 / 4 + 19));
            exp2 = correctEXP (exp2 + ((exp2 > 200) ? ((float)e1 / 9 + 21) : 0));
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = correctEXP (exp2 + ((float)e1 / 4 + 19));
            exp2 = correctEXP (exp2 + ((float)e1 / 9 + 21));
            if (exp2 > 400){
                exp2 = correctEXP (exp2 + ((float)e1 / 16 + 17));
                exp2 = correctEXP (exp2 + ((float)exp2 * 15 / 100));
            }
        }
        exp1 = correctEXP (exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage (int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
   
    if (E2 < 0 || E2 > 99) 
    {
        return -99;
    }
    EXP1 = correctEXP(EXP1);
    HP1 = correctHP(HP1);
    M1 = correctM(M1);

     /* 4.2.1 */
    float max, min, p1, p2, p3;
    max = ceil (sqrt (EXP1)) * ceil (sqrt (EXP1));
    min = floor (sqrt (EXP1)) * floor (sqrt (EXP1));
    p1 = (EXP1 >= ((abs (max - EXP1) < abs (min - EXP1)) ? max : min)) ? 1 : ((((float)(EXP1) / ((abs (max - EXP1) < abs (min - EXP1)) ? max : min)) + 80) / 123);

    /* 4.2.2 */
    float tempM = M1;
    for(;;)
    {
        if (E2 % 2 == 1)
        {
            if (M1 < (tempM * 50 / 100))
            {
                break;
            }
        }
        if (M1 <= 0)
        {
            break;
        }

        /* event 1 */
        M1 = correctM (M1 - ((HP1 < 200) ? 150 : 70));
        HP1 = correctHP (HP1 + ((float)HP1 * ((HP1 < 200) ? 30 : 10) / 100));

        if (E2 % 2 == 1)
        {
            if (M1 < (tempM * 50 / 100))
            {
                break;
            }
        }
        if (M1 <= 0)
        {
            break;
        }

        /* event 2 */
        M1 = correctM (M1 - ((EXP1 < 400) ? 200 : 120));
        EXP1 = correctEXP (EXP1 + ((float) EXP1 * 13 / 100));

        if (E2 % 2 == 1)
        {
            if (M1 < (tempM * 50 / 100)) 
            {
                break;
            }
        }
        if (M1 <= 0)
        {
            break;
        }

        /* event 3 */
        M1 = correctM (M1 - ((EXP1 < 300) ? 100 : 120));
        EXP1 = correctEXP (EXP1 - ((float) EXP1 * 10 / 100));


        if (E2 % 2 == 1)
        {
            if (M1 < (tempM * 50 / 100)) 
            {
                break;
            }
        }
        if (M1 <= 0)
        {
            break;
        }

        if (E2 % 2 == 0)
        {
            break;
        }
    }
    HP1 = correctHP (HP1 - ((float) HP1 * 17 / 100));
    EXP1 = correctEXP (EXP1 + ((float) EXP1 * 17 / 100));

    max = ceil (sqrt (EXP1)) * ceil (sqrt (EXP1));
    min = floor (sqrt (EXP1)) * floor (sqrt (EXP1));
    p2 = (EXP1 >= ((abs (max - EXP1) < abs (min - EXP1)) ? max : min)) ? 1 : ((((float)(EXP1) / ((abs (max - EXP1) < abs (min - EXP1)) ? max : min)) + 80) / 123);
    /* 4.2.3 */
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    p3 = ((float)P[((E2 < 10) ? E2 : ((E2 / 10 + E2 % 10) % 10))]) / 100;

    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        EXP1 = correctEXP (EXP1 - ((float) EXP1 * 25 / 100));
    }
    else
    {
        HP1 = correctHP (HP1 - ((float) HP1 * ((((p1 + p2 + p3) / 3) < 0.5) ? 15 : 10) / 100));
        EXP1 = correctEXP (EXP1 + ((float) EXP1 *((((p1 + p2 + p3) / 3) < 0.5) ? 15 : 20) / 100));
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi (int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) {
        return -99;
    }
    EXP1 = correctEXP(EXP1);
    EXP2 = correctEXP(EXP2);
    HP1 = correctHP(HP1);
    HP2 = correctHP(HP2);

    int taxiMatrix[10][10], minNum, maxNum, interceptorRow, interceptorCol, max;
    minNum = 0;
    maxNum = 0;
    
    for (int row = 0; row < 10; ++row)
    {
        for (int col = 0; col < 10; ++col)
        {
            taxiMatrix[row][col] = ((E3 * col) + (row * 2)) * (row - col);
            if (taxiMatrix[row][col] > (E3 * 2))
            {
                maxNum++;
            }
            else if (taxiMatrix[row][col] < (0 - E3))
            {
                minNum++;
            }
        }
    }
    interceptorRow = plusDigit (maxNum);
    interceptorCol = plusDigit (minNum);

    int eng;
    bool check;
    eng = 0;
    max = taxiMatrix[interceptorRow][interceptorCol];

    for (;;){
        eng++;
        check = true;
        if (((interceptorRow + eng) < 10) && ((interceptorCol + eng) < 10)){
            check = false;
            if (max < taxiMatrix[(interceptorRow + eng)][(interceptorCol + eng)]) { max = taxiMatrix[(interceptorRow + eng)][(interceptorCol + eng)]; }
        }
        if (((interceptorRow - eng) >= 0) && ((interceptorCol - eng) >= 0)){
            check = false;
            if (max < taxiMatrix[(interceptorRow - eng)][(interceptorCol - eng)]) { max = taxiMatrix[(interceptorRow - eng)][(interceptorCol - eng)]; }
        }
        if (((interceptorRow + eng) < 10) && ((interceptorCol - eng) >= 0)){
            check = false;
            if (max < taxiMatrix[(interceptorRow + eng)][(interceptorCol - eng)]) { max = taxiMatrix[(interceptorRow + eng)][(interceptorCol - eng)]; }
        }
        if (((interceptorRow - eng) >= 0) && ((interceptorCol + eng) < 10)){
            check = false;
            if (max < taxiMatrix[(interceptorRow - eng)][(interceptorCol + eng)]) { max = taxiMatrix[(interceptorRow - eng)][(interceptorCol + eng)]; }
        }
        if (check)
        {
            break;
        }

    }

    EXP1 = correctEXP (EXP1 + ((float) ((abs (taxiMatrix[interceptorRow][interceptorCol]) > max) ? - EXP1 : EXP1) * 12 / 100));
    EXP2 = correctEXP (EXP2 + ((float) ((abs (taxiMatrix[interceptorRow][interceptorCol]) > max) ? - EXP2 : EXP2) * 12 / 100));
    HP1 = correctHP (HP1 + ((float) ((abs (taxiMatrix[interceptorRow][interceptorCol]) > max) ? - HP1 : HP1) * 10 / 100));
    HP2 = correctHP (HP2 + ((float) ((abs (taxiMatrix[interceptorRow][interceptorCol]) > max) ? - HP2 : HP2) * 10 / 100));

    return (abs(taxiMatrix[interceptorRow][interceptorCol]) > max) ? (taxiMatrix[interceptorRow][interceptorCol]) : max;
}

// Task 4
int checkPassword (const char * s, const char * email) {
    // TODO: Complete this function

    string Pass (s);
    string Email (email);

    if (Pass.length() < 8){
        return -1;
    }

    if (Pass.length() > 20){
        return -2;
    }

    string se = Email.substr (0, Email.find ('@'));
    if (Pass.find (se) != string::npos)
    {
        return - (300 + Pass.find (se));
    }

    for (int i = 0; i + 2 <= Pass.length(); ++i)
    {
        if (Pass[i + 1] == Pass[i] && Pass[i + 2] == Pass[i])
        {
            return - (400 + i);
        }
    }

    if (Pass.find ('@') == string::npos && Pass.find ('#') == string::npos && Pass.find ('%') == string::npos && Pass.find ('$') == string::npos && Pass.find ('!') == string::npos)
    {
        return -5;
    }

    for (int o = 0; o < Pass.length(); ++o)
    {
        if (!islower (Pass[o]) && !isupper (Pass[o]) && Pass[o] != '@' && Pass[o] != '#' && Pass[o] != '%' && Pass[o] != '$' && Pass[o] != '!')
        {
            return o;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword (const char * arr_pwds[], int num_pwds) 
{
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    int index;

    for (int i = 0; i < num_pwds; ++i)
    {
        if (arr_pwds[i] != nullptr){
            int current = 1;
            int length = strlen (arr_pwds[i]);

            for (int o = i + 1; o < num_pwds; ++o)
            {
                if (arr_pwds[o] != nullptr && strcmp (arr_pwds[i], arr_pwds[o]) == 0)
                {
                    arr_pwds[o] = nullptr;
                    ++current;
                }
            }


            if (current > maxCount || (current == maxCount && length > maxLength))
            {
                maxCount = current;
                maxLength = length;
                index = i;
            }
        }
    }

    return index;
}

//REMEMBER TO DELETE THIS AFTER ALL

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////