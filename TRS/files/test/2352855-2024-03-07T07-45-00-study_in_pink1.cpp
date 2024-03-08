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
    // TODO: Complete this function
 //start case 1  
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 = 29 + exp2;
        if (e1 == 1)
            exp2 = 45 + exp2;
        if (e1 == 2)
            exp2 = 75 + exp2;
        if (e1 == 3)
            exp2 = 29 + 45 + 75 + exp2;
        int D;
        float exp = 0;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp = exp1 + D/ 200.0;
        }
        else
            exp = exp1 - D/ 100.0;
        exp1 = ceil(exp);
        if (exp1>600)
        {
            exp1 = 600;
        }
        else
        {
            if (exp1<0)
            {
                exp1 = 0;
            }
        }
        if (exp2 > 600)
        {
            exp2 = 600;
        }
        else
        {
            if (exp2 < 0)
            {
                exp2 = 0;
            }
        }
    }
//end case 1
//start case 2
    float ws = exp2;
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            ws = exp2 + (e1 / 4.0 + 19);
            ws = ceil(ws);
        }
        if (e1 >= 20 && e1 <= 49)
        {
            ws = exp2 + (e1 / 9.0 + 21);
            ws = ceil(ws);
        }
        if (e1 >= 50 && e1 <= 65)
        {
            ws = exp2 + (e1 / 16.0 + 17);
            ws = ceil(ws);
        }
        if (e1 >= 66 && e1 <= 79)
        {
            ws = exp2 + (e1 / 4.0 + 19);
            ws = ceil(ws);
            if (ws > 200)
            {
                ws = exp2 + (e1 / 9.0 + 21);
                ws = ceil(ws);
            }
        }
        if (e1 >= 80 && e1 <= 99)
        {
            ws = exp2 + (e1 / 4.0 + 19);
            ws = ceil(ws);
            ws = ws + (e1 / 9.0 + 21);
            ws = ceil(ws);
            if (ws > 400)
            {
                ws = ws + (e1 / 16.0 + 17);
                ws = ceil(ws);
                ws = ws * 1.15;
                ws = ceil(ws);
                
            }

        }
        exp2 = ws;
        if (exp2 > 600)
            exp2 = 600;
        else
        {
            if (exp2<0)
            {
                exp2 = 0;
            }
        }
        exp1 = exp1 - e1;
        if (exp1 < 0)
        {
            exp1 = 0;
        }
        if (exp1>600)
        {
            exp1 = 600;
        }
    }
//end case 2
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
//start case 1
    int S = 0;
    float P1 = 0;
    S = round(sqrt(EXP1));
    S = pow(S, 2);
    if (EXP1 >= S)
    {
        P1 = 1;
    }
    else
        P1 = (EXP1 / static_cast<float>(S) + 80) / 123;
    //end case 1
    //start case 2
    float hp = HP1;
    float exp = EXP1;
    int half = M1 * 0.5;
    if (M1 == 0)
    {
    }
    else
    {
        if (E2 % 2 != 0)
        {
            for (int i = 0; i < 100; i++)
            {
                //case 2.1
                if (HP1 < 200)
                {
                    hp = HP1 * 1.3;
                    HP1 = ceil(hp);
                    M1 = M1 - 150;
                }
                else
                {
                    hp = HP1 * 1.1;
                    HP1 = ceil(hp);
                    M1 = M1 - 70;
                }
                if (M1 < half)
                {
                    break;
                }
                //case 2.2
                if (EXP1 < 400)
                {
                    M1 = M1 - 200;
                }
                else
                {
                    M1 = M1 - 120;
                }
                exp = EXP1 * 1.13;
                EXP1 = ceil(exp);
                if (M1 < half)
                {
                    break;
                }
                //cas 2.3
                if (EXP1 < 300.0)
                {
                    M1 = M1 - 100;
                }
                else
                {
                    M1 = M1 - 120;
                }
                exp = EXP1 * 0.9;
                EXP1 = ceil(exp);
                if (M1 < half)
                {
                    break;
                }
            }
            hp = HP1 * 0.83;
            exp = EXP1 * 1.17;
            HP1 = ceil(hp);
            EXP1 = ceil(exp);
        }
        else
        {
            //case 2.1
            if (HP1 < 200)
            {
                hp = HP1 * 1.3;
                HP1 = ceil(hp);
                M1 = M1 - 150;

            }
            else
            {
                hp = HP1 * 1.1;
                HP1 = ceil(hp);
                M1 = M1 - 70;
            }
            if (M1 > 0)
            {
                //case 2.2
                if (EXP1 < 400)
                {
                    M1 = M1 - 200;
                }
                else
                {
                    M1 = M1 - 120;
                }
                exp = EXP1 * 1.13;
                EXP1 = ceil(exp);
                if (M1 > 0)
                {
                    //cas 2.3
                    if (EXP1 < 300.0)
                    {
                        M1 = M1 - 100;
                    }
                    else
                    {
                        M1 = M1 - 120;
                    }
                    exp = EXP1 * 0.9;
                    EXP1 = ceil(exp);
                }
            }
            hp = HP1 * 0.83;
            exp = EXP1 * 1.17;
            HP1 = ceil(hp);
            EXP1 = ceil(exp);
        }
        float P2 = 0;
        S = round(sqrt(EXP1));
        S = pow(S, 2);
        if (EXP1 >= S)
        {
            P2 = 1;
        }
        else
            P2 = (EXP1 / static_cast<float>(S) + 80) / 123;
        //end case 2
        //start case 3
        string P = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        float P3 = 0;
        if (E2 >= 0 && E2 <= 9)
        {
            int i = E2;
            P3 = P[i];
        }
        else
        {
            int A = 0;
            int B = 0;
            int C = 0;
            int i = 0;
            A = E2 % 10;
            B = (E2 / 10) % 10;
            C = A + B;
            i = C % 10;
            P3 = P[i];
        }
        //end case 3
        float sum = P1 + P2 + P3 / 100;
        float aver = (sum / 3) * 100;
        if (sum == 3)
        {
            exp = EXP1 * 0.75;
        }
        else
        {
            if (aver < 50)
            {
                hp = HP1 * 0.85;
                HP1 = ceil(hp);
                exp = EXP1 * 1.15;
                EXP1 = ceil(exp);
            }
            else
            {
                hp = HP1 * 0.9;
                HP1 = ceil(hp);
                exp = EXP1 * 1.2;
                EXP1 = ceil(exp);
            }
        }
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (EXP1 < 0)
        EXP1 = 0;
    if (M1 < 0)
    {
        M1 = 0;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int matrix[10][10]{};
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }   
    int counti = 0;
    int countj = 0;
    int A = 0, B = 0, C = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrix[i][j] > E3 * 2)
            {
                counti = counti + 1;
            }
            if (matrix[i][j] < -E3)
            {
                countj = countj + 1;
            }
        }
    }
        if (counti > 9)
        {
            A = counti % 10;
            B = (counti / 10) % 10;
            C = A + B;
            if (C > 9)
            {
                A = C % 10;
                B = (C / 10) % 10;
                C = A + B;
                counti = C;
            }
            else
            {
                counti = C;
            }
        }
        if (countj > 9)
        {
            A = countj % 10;
            B = (countj / 10) % 10;
            C = A + B;
            if (C > 9)
            {
                A = C % 10;
                B = (C / 10) % 10;
                C = A + B;
                countj = C;
            }
            else
            {
                countj = C;
            }
        }
        int shws[counti][countj]{};
        int Max = matrix[counti][countj];
        for (int i = 0; i < 10; i++)
        {
            if (counti + i > 9 || countj + i > 9 || counti + i < -9 || countj + i < -9 )
            {
                
            }
            else
            {
                if (matrix[counti + i][countj + i] > Max)
                {
                    Max = matrix[counti + i][countj + i];
                }
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (counti + i > 9 || countj - i > 9 || counti + i < -9 || countj - i < -9)
            {

            }
            else
            {
                if (matrix[counti + i][countj - i] > Max)
                {
                    Max = matrix[counti + i][countj - i];
                }
            }
        }
        shws[counti][countj] = abs(Max);
        float exp1 = 0, exp2 = 0, hp1 = 0, hp2 = 0;
        if (abs(matrix[counti][countj]) > shws[counti][countj])
        {
            exp1 = EXP1 * 0.88;
            EXP1 = ceil(exp1);
            exp2 = EXP2 * 0.88;
            EXP2 = ceil(exp2);
            hp1 = HP1 * 0.9;
            HP1 = ceil(hp1);
            hp2 = HP2 * 0.9;
            HP2 = ceil(hp2);
            return matrix[counti][countj];
        }
        else
        {
            exp1 = EXP1 * 1.12;
            EXP1 = ceil(exp1);
            exp2 = EXP2 * 1.12;
            EXP2 = ceil(exp2);
            hp1 = HP1 * 1.1;
            HP1 = ceil(hp1);
            hp2 = HP2 * 1.1;
            HP2 = ceil(hp2);
            return shws[counti][countj];
        }
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        if (EXP2 > 600)
        {
            EXP2 = 600;
        }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int s_length = strlen(s);
    int length = strlen(email);
    char targetChar = '@';
    int position = 0;
    for (int i = 0; i < length; ++i) 
    {
        if (email[i] == targetChar) 
        {
            position = i;
        }
    }
    char se[100];
    strncpy(se, email, position);

    if (s_length < 8)
        return -1;
    if (s_length > 20)
        return -2;              
    int sei = 0;    
        for (int i = 0; i < 100; i++)
        {
            if (se[0] = s[i] && se[1] = s[i+1] && se[2] = s[i+2] && se[3] = s[i+3])
            {
                                sei = i; 
                                break;
            }
        }
            return -(300 + sei);
        
        bool hasSpecialChar = false;
        for (int i = 0; i < s_length; i++) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                hasSpecialChar = true;
                break;
            }
        }
        if (hasSpecialChar == false)
            return -5;
        for (int i = 0; i < s_length - 2; i++)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                return -(400 + i);
                break;
            }
        }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {    
    int maxCount = 0;
    int maxLength = 0;
    int correctPasswordIndex = 0;   
    for (int i = 0; i < num_pwds; ++i) 
    {
        const char* currentPassword = arr_pwds[i];
        int currentCount = 0;
        int currentLength = strlen(currentPassword);        
        for (int j = 0; j < num_pwds; ++j) 
        {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                currentCount++;
            }
        }       
        if (currentCount > maxCount || (currentCount == maxCount && currentLength > maxLength)) 
        {
            maxCount = currentCount;
            maxLength = currentLength;
            correctPasswordIndex = i;
        }
    }
    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////