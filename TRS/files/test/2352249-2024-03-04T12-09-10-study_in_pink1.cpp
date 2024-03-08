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

// conditions
// hp conditions
int hp_con(int hp)
{
    if (hp < 0)
    {
        hp = 0;
    }
    else if (hp > 666)
    {
        hp = 666;
    }
    return hp;
}
// exp conditions
int exp_con(int exp)
{
    if (exp < 0)
    {
        exp = 0;
    }
    else if (exp > 600)
    {
        exp = 600;
    }
    return exp;
}
// money conditions
int money_con(int M1)
{
    if (M1 < 0)
    {
        M1 = 0;
    }
    else if (M1 > 3000)
    {
        M1 = 3000;
    }
    return M1;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // check exp1, exp2, e1 conditions
    if (e1 < 0 or e1 > 99)
    {
        e1 = -99;
        return -99;
    }

    exp1 = exp_con(exp1);
    exp2 = exp_con(exp2);

// first case
    double D;
    if (e1 == 3)
    {
        exp2 += + 29 + 45 + 75;
        D = e1 * 3 + exp1 * 7;
    }
    else if (e1 == 2)
    {
        exp2 += + 75;
        D = e1 * 3 + exp1 * 7;
    }
    else if (e1 == 1)
    {
        exp2 += + 45;
        D = e1 * 3 + exp1 * 7;
    }
    else if (e1 == 0)
    {
        exp2 = exp2 + 29;
        D = e1 * 3 + exp1 * 7;
    }
    exp2 = exp_con(exp2);

    //checking if D is odd or even
    if (e1 >= 0 && e1 <=3)
    {
        if ( static_cast<int>(D) % 2 == 0 )
        {
            exp1 = ceil(exp1 + D/200);
        }
        else
        {
            exp1 = ceil(exp1 - D/100);
        }
    }

    // checking the result
    exp1 = exp_con(exp1);
    exp2 = exp_con(exp2);

    //second case
    if (e1 >= 4 and e1 <= 99)
    {
    if (e1 >= 4 && e1 <= 19)
    {
        exp2 = ceil(exp2 + (static_cast<double>(e1)/4 + 19));
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2 = ceil(exp2 + (static_cast<double>(e1)/9 + 21));
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp2 = ceil(exp2 + (static_cast<double>(e1)/16 + 17));
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = ceil(exp2 + (static_cast<double>(e1)/4 + 19));
        exp2 = exp_con(exp2);
        if (exp2 > 200)
        {
            exp2 = ceil(exp2 + (static_cast<double>(e1)/9 + 21));
            exp2 = exp_con(exp2);
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp2 = ceil(exp2 + (static_cast<double>(e1)/4 + 19));
        exp2 = exp_con(exp2);
        exp2 = ceil(exp2 + (static_cast<double>(e1)/9 + 21));
        exp2 = exp_con(exp2);
        if (exp2 > 400)
        {
            exp2 = ceil(exp2 + (static_cast<double>(e1)/16 + 17));
            exp2 = exp_con(exp2);
            exp2 = ceil(exp2 + 0.15 * exp2);
            exp2 = exp_con(exp2);
        }
    }
    exp1 -= e1;
    exp1 = exp_con(exp1);
    exp2 = exp_con(exp2);
    }
    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // check HP1, EXP1, M1, E2 conditions
    if (E2 < 0 or E2 > 99)
    {
        E2 = -99;
        return -99;
    }
    HP1 = hp_con(HP1);
    EXP1 = exp_con(EXP1);
    M1 = money_con(M1);

    //road 1
    int S = EXP1;
    double P1;
    while (!(sqrt(S) == trunc(sqrt(S)))){S++;} //find the nearest perfect square S compare to EXP1
    if (S <= EXP1)
    {
        P1 = 1;
    }
    else
    {
        P1 = ((static_cast<double>(EXP1) / S) + 80) / 123;
    }

    //initialize total money spent
    int moneyspend = 0;
    int halfstartmoney = ceil(static_cast<double>(M1)*0.5);

    //road 2
    //E2 is odd
    if (E2 % 2 != 0 && M1 > 0)
    {
    while (moneyspend <= (halfstartmoney)) 
    {
        if (HP1 < 200) 
        {
            HP1 = ceil(static_cast<double>(HP1) * 1.3);
            M1 -= 150;
            moneyspend += 150;
        } 
        else 
        {
            HP1 = ceil(static_cast<double>(HP1) * 1.1);
            M1 -= 70;
            moneyspend += 70;
        }
        HP1 = hp_con(HP1);
        M1 = money_con(M1);

        if (M1 <= 0 || moneyspend >= (halfstartmoney)) 
        {
            break;
        }

        if (EXP1 < 400) 
        {
            M1 -= 200;
            moneyspend += 200;
        } 
        else 
        {
            M1 -= 120;
            moneyspend += 120;
        }
        EXP1 = ceil(static_cast<double>(EXP1)*1.13);
        M1 = money_con(M1);
        EXP1 = exp_con(EXP1);


        if (M1 <= 0 || moneyspend >= (halfstartmoney)) 
        {
            M1 = money_con(M1);
            break;
        }

        if (EXP1 < 300) 
        {
            M1 -= 100;
            moneyspend += 100;
        } 
        else 
        {
            M1 -= 120;
            moneyspend += 120;
        }
        EXP1 = ceil(static_cast<double>(EXP1)*0.9);
        EXP1 = exp_con(EXP1);
        M1 = money_con(M1);

        if (M1 <= 0 || moneyspend >= (halfstartmoney)) 
        {
            break;
        }
    }
    }
    
    // E2 is even
    else if (E2 % 2 == 0 && M1 > 0)
    {
        while (M1 > 0)
        {
        if (HP1 < 200) 
        {
            HP1 = ceil(static_cast<double>(HP1)*1.3);
            M1 -= 150;
        } 
        else 
        {
            HP1 = ceil(static_cast<double>(HP1)*1.1);
            M1 -= 70;
        }
        HP1 = hp_con(HP1);
        M1 = money_con(M1);

        if (M1 <= 0) 
        {
            break;
        }

        if (EXP1 < 400) 
        {
            M1 -= 200;
        } 
        else 
        {
            M1 -= 120;
        }

        EXP1 = ceil(static_cast<double>(EXP1)*1.13);
        M1 = money_con(M1);
        EXP1 = exp_con(EXP1);

        if (M1 <= 0) 
        {
            break;
        }

        if (EXP1 < 300) 
        {
            M1 -= 100;
        } 
        else 
        {
            M1 -= 120;
        }
        EXP1 = ceil(static_cast<double>(EXP1)*0.9);
        EXP1 = exp_con(EXP1);

        if (M1 <= 0) 
        {
            break;
        }

        break;
        }
    }

    HP1 = hp_con(HP1);
    M1 = money_con(M1);

    //update HP and EXP at the end
    HP1 = ceil(static_cast<double>(HP1) * 0.83);
    EXP1 = ceil(static_cast<double>(EXP1) * 1.17);
    HP1 = hp_con(HP1);
    EXP1 = exp_con(EXP1);
    
    //calculate P2
    double P2;
    int a = EXP1;
    while (!(sqrt(a) == trunc(sqrt(a)))){a++;}
    if (a <= EXP1)
    {
        P2 = 1;
    }
    else
    {
        P2 = ((static_cast<double>(EXP1) / a) + 80) / 123;
    }

    //road 3
    const double P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    double Pavg;
    if (E2 < 10)
    {
        i = E2;
    }
    else
    {
        int a = E2 / 10; 
        int b = E2 % 10; 
        int all = a + b;
        i = all % 10;
    }
    double P3 = P[i] / 100 ;

    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil(static_cast<double>(EXP1) * 0.75);
    }
    else
    {
        Pavg = (P1 + P2 + P3) / 3;
        EXP1 = exp_con(EXP1);
    if (Pavg < 0.5)
    {
        HP1 = ceil(static_cast<double>(HP1) * 0.85);
        EXP1 = ceil(static_cast<double>(EXP1) * 1.15);
    }
    else
    {
        HP1 = ceil(static_cast<double>(HP1) * 0.9);
        EXP1 = ceil(static_cast<double>(EXP1) * 1.2);
    }
    }
    HP1 = hp_con(HP1);
    EXP1 = exp_con(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //check HP1, EXP1, HP2, EXP2, E3 conditions
    if (E3 < 0 or E3 > 99)
    {
        E3 = -99;
        return -99;
    }
    HP1 = hp_con(HP1);
    HP2 = hp_con(HP2);
    EXP1 = exp_con(EXP1);
    EXP2 = exp_con(EXP2);

    int matrix[10][10] = {0};

    //taxi's matrix
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    
    //calculate left and right diagonals, store max score for Sherlock and Watson
    int maxs1 = INT_MIN;
    int maxs2 = INT_MIN;

    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            //left diagonal
            int ld_value = (i + j < 10) ? matrix[i + j][j] : matrix[9 - j][9 - (i + j - 9)];
            maxs1 = max(maxs1, ld_value);
            maxs2 = max(maxs2, ld_value);

            //right diagonal
            int rd_value = (i + j < 10) ? matrix[j][i + j] : matrix[9 - (i + j - 9)][9 - j];
            maxs1 = max(maxs1, rd_value);
            maxs2 = max(maxs2, rd_value);
        }
    }

    //meeting point coordinates
    int i = 0, j = 0;
    for (int row = 0; row < 10; ++row) 
    {
        for (int col = 0; col < 10; ++col)
        {
            if (matrix[row][col] > E3 * 2)
            {
                ++i;
            }
            if (matrix[row][col] < -E3) 
            {
                ++j;
            }
        }
    }

    //mormalize i and j to single digits
    while (i > 9) 
    {
        i = i % 10 + i / 10;
    }
    while (j > 9) 
    {
        j = j % 10 + j / 10;
    }

    //if Sherlock and Watson catch the taxi or not
    bool catch_taxi = abs(matrix[i][j]) <= max(maxs1, maxs2);

    //adjust HP and EXP
    if (catch_taxi) 
    {
        HP1 = ceil(1.1 * static_cast<double>(HP1));
        HP2 = ceil(1.1 * static_cast<double>(HP2));
        EXP1 = ceil(1.12 * static_cast<double>(EXP1));
        EXP2 = ceil(1.12 * static_cast<double>(EXP2));
    } 
    else 
    {
        HP1 = ceil(0.9 * static_cast<double>(HP1));
        HP2 = ceil(0.9 * static_cast<double>(HP2));
        EXP1 = ceil(0.88 * static_cast<double>(EXP1));
        EXP2 = ceil(0.88 * static_cast<double>(EXP2));
    }
    HP1 = hp_con(HP1);
    HP2 = hp_con(HP2);
    EXP1 = exp_con(EXP1);
    EXP2 = exp_con(EXP2);

    return matrix[i][j];
    return chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se(email); //convert email to string
    size_t pos = se.find('@'); //find position of '@'
    string seSub = se.substr(0, pos); //extract characters before '@'

    //check if s is shorter than the minimum length
    if (strlen(s) < 8) return -1;

    //check if s is longer than the maximum length
    if (strlen(s) > 20) return -2;

    //check if s contains se
    const char *found = strstr(s, seSub.c_str());
    if (found != nullptr) return -(300 + (found - s));

    //check if s contains more than 2 consecutive and identical characters
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i);
    }

    //check if s does not contain special characters
    const char *specialChars = "@#%$!";
    bool hasSpecialChar = false;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;

    //check for characters violating validity requirements
    for (int i = 0; s[i] != '\0'; ++i) 
    {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
              (c >= '0' && c <= '9') || strchr(specialChars, c) != nullptr)) 
        {
            return i;
        }
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int maxFrequency = 0;
    int maxLength = 0;
    int correctPasswordIndex = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        int frequency = 0;
        int length = 0;
        for (const char* c = arr_pwds[i]; *c != '\0'; ++c)
        {
            ++length;
        }

        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                ++frequency;
            }
        }

        if (frequency > maxFrequency || (frequency == maxFrequency && length > maxLength))
        {
            maxFrequency = frequency;
            maxLength = length;
            correctPasswordIndex = i;
        }
    }

    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////