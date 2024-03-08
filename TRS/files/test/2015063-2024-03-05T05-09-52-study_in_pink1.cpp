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

////////////////--------------------- function check------------------------/////////////////////////////

//--------------Check HP------------------//
int checkHP(float HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    if (HP < 0)
    {
        HP = 0;
    }
    return ceil(HP);
}

//--------------Check EXP------------------//
int checkEXP(float EXP)
{
    if (EXP > 600)
    {
        EXP = 600;
    }
    if (EXP < 0)
    {
        EXP = 0;
    }
    return ceil(EXP);
}

//--------------Check M------------------//
int checkM(float M)
{
    if (M > 3000)
    {
        M = 3000;
    }
    if (M < 0)
    {
        M = 0;
    }
    return ceil(M);
}

//--------------Check E------------------//
bool checkE(int E)
{
    if (E > 99 || E < 0)
    {
        return false;
    }
    return true;
}

// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    // TODO: Complete this function

    if (!checkE(E1))
    {
        return -99;
    }

    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);

    //---------------Option 1-----------------//
    if (E1 >= 0 && E1 <= 3)
    {
        int D = 0;
        float tamE1 = EXP1;
        if (E1 == 0)
        {
            EXP2 += 29;
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
        }
        else if (E1 == 2)
        {
            EXP2 += 75;
        }
        else if (E1 == 3)
        {
            EXP2 += 29 + 45 + 75;
        }

        EXP2 = checkEXP(EXP2);
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
        {
            tamE1 += float(D) / 200;
            EXP1 = checkEXP(tamE1);
        }
        else
        {
            tamE1 -= float(D) / 100;
            EXP1 = checkEXP(tamE1);
        }
    }
    //-----------------------------Option 2------------------------------------//
    else
    {
        float tamE2 = EXP2;
        if (E1 >= 4 && E1 <= 19)
        {
            tamE2 += float(E1) / 4 + 19;
        }
        else if (E1 >= 20 && E1 <= 49)
        {
            tamE2 += float(E1) / 9 + 21;
        }
        else if (E1 >= 50 && E1 <= 65)
        {
            tamE2 += float(E1) / 16 + 17;
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            tamE2 += float(E1) / 4 + 19;
            EXP2 = checkEXP(tamE2);
            tamE2 = EXP2;
            if (tamE2 > 200)
            {
                tamE2 += float(E1) / 9 + 21;
                EXP2 = checkEXP(tamE2);
                tamE2 = EXP2;
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            tamE2 += float(E1) / 4 + 19;
            EXP2 = checkEXP(tamE2);
            tamE2 = EXP2;
            tamE2 += float(E1) / 9 + 21;
            EXP2 = checkEXP(tamE2);
            tamE2 = EXP2;
            if (tamE2 > 400)
            {
                tamE2 += float(E1) / 16 + 17;
                EXP2 = checkEXP(tamE2);
                tamE2 = EXP2;
                tamE2 *= 1.15;
                EXP2 = checkEXP(tamE2);
                tamE2 = EXP2;
            }
        }
        EXP2 = checkEXP(tamE2);
        EXP1 -= E1;
        EXP1 = checkEXP(EXP1);
    }

    return EXP1 + EXP2;
}

// Task 2
int findSquareNumber(int EXP1)
{
    int sq_tam = sqrt(EXP1);
    int S = 0;
    if (sq_tam * sq_tam == EXP1)
    {
        return EXP1;
    }

    int tam_above = sq_tam * sq_tam;
    int tam_below = (sq_tam + 1) * (sq_tam + 1);

    if (abs(tam_above - EXP1) < abs(tam_below - EXP1))
    {
        S = tam_above;
    }
    else
    {
        S = tam_below;
    }
    return S;
}

bool checkMoney(int de_M, int res_M)
{
    if (de_M < res_M)
    {
        return true;
    }
    return false;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (!checkE(E2))
    {
        return -99;
    }
    if (M1 == 0)
    {
        return HP1 + EXP1 + M1;
    }

    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkM(M1);

    //----------------------------- Path 1 ---------------------------------//
    float P_1;
    // int sq_tam = sqrt(EXP1);
    int S = 0;
    S = findSquareNumber(EXP1);
    if (EXP1 >= S)
    {
        P_1 = 100;
    }
    else
    {
        P_1 = float((float(float(EXP1) / S) + 80) / 123) * 100;
    }

    //------------------------------- Path 2 --------------------------//

    float P_2;
    float tam_HP1 = HP1;
    float tam_EXP1 = EXP1;
    float de_M = 0;
    int res_M = 0;
    if (E2 % 2 != 0)
    {
        de_M = float(M1 * 0.5);
        while (true)
        {
            //------------------------------- Path 2.1 --------------------------//
            if (HP1 < 200)
            {
                tam_HP1 = tam_HP1 * 1.3;
                res_M += 150;
            }
            else
            {
                tam_HP1 = tam_HP1 * 1.1;
                res_M += 70;
            }
            HP1 = checkHP(tam_HP1);
            tam_HP1 = HP1;
            //---------------check M---------------//
            if (checkMoney(de_M, res_M))
            {
                break;
            }

            //------------------------------- Path 2.2 --------------------------//
            if (EXP1 < 400)
            {
                res_M += 200;
                tam_EXP1 = tam_EXP1 * 1.13;
            }
            else
            {
                res_M += 120;
                tam_EXP1 = tam_EXP1 * 1.13;
            }
            EXP1 = checkHP(tam_EXP1);
            tam_EXP1 = EXP1;
            //---------------check M---------------//
            if (checkMoney(de_M, res_M))
            {
                break;
            }

            //------------------------------- Path 2.2 --------------------------//
            if (EXP1 < 300)
            {
                res_M += 100;
            }
            else
            {
                res_M += 120;
            }
            tam_EXP1 = tam_EXP1 * 0.9;
            EXP1 = checkHP(tam_EXP1);
            tam_EXP1 = EXP1;
            //---------------check M---------------//
            if (checkMoney(de_M, res_M))
            {
                break;
            }
        }
    }
    else
    {
        de_M = M1;
        //------------------------------- Path 2.1 --------------------------//
        if (HP1 < 200)
        {
            tam_HP1 = tam_HP1 * 1.3;
            res_M += 150;
        }
        else
        {
            tam_HP1 = tam_HP1 * 1.1;
            res_M += 70;
        }
        HP1 = checkHP(tam_HP1);
        tam_HP1 = HP1;
        //---------------check M---------------//
        if (!checkMoney(de_M, res_M))
        {
            //------------------------------- Path 2.2 --------------------------//
            if (EXP1 < 400)
            {
                res_M += 200;
                tam_EXP1 = tam_EXP1 * 1.13;
            }
            else
            {
                res_M += 120;
                tam_EXP1 = tam_EXP1 * 1.13;
            }
            EXP1 = checkHP(tam_EXP1);
            tam_EXP1 = EXP1;
            //---------------check M---------------//
            if (!checkMoney(de_M, res_M))
            {
                //------------------------------- Path 2.2 --------------------------//
                if (EXP1 < 300)
                {
                    res_M += 100;
                }
                else
                {
                    res_M += 120;
                }
                tam_EXP1 = tam_EXP1 * 0.9;
                EXP1 = checkHP(tam_EXP1);
                tam_EXP1 = EXP1;
            }
        }
    }
    M1 = M1 - res_M;
    M1 = checkM(M1);
    tam_HP1 = HP1 * 0.83;
    HP1 = checkHP(tam_HP1);
    tam_EXP1 = EXP1 * 1.17;
    EXP1 = checkEXP(tam_EXP1);
    tam_EXP1 = EXP1;
    S = findSquareNumber(EXP1);
    if (EXP1 >= S)
    {
        P_2 = 100;
    }
    else
    {
        P_2 = float((float(float(EXP1) / S) + 80) / 123) * 100;
    }

    //------------------------------- Path 3 --------------------------//
    float P_3 = 0;
    int P_3_array[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum_i = 0;
    if (E2 >= 10)
    {
        sum_i = (E2 / 10 + E2 % 10) % 10;
    }
    else
    {
        sum_i = E2;
    }
    P_3 = P_3_array[sum_i];

    //------------------------------- res ------------------------------//
    if (P_1 + P_2 + P_3 == 300)
    {
        tam_EXP1 *= 0.75;
        EXP1 = checkEXP(tam_EXP1);
        // return traceLuggage(HP1, EXP1, M1, E2);
    }
    else
    {
        float res_P = float((P_1 + P_2 + P_3) / 3);
        tam_HP1 = HP1;
        tam_EXP1 = EXP1;
        if (res_P >= 50)
        {
            tam_HP1 *= 0.9;
            tam_EXP1 *= 1.2;
        }
        else
        {
            tam_HP1 *= 0.85;
            tam_EXP1 *= 1.15;
        }
        EXP1 = checkEXP(tam_EXP1);
        HP1 = checkHP(tam_HP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int res_number(int E3)
{
    int res = 0;
    while (E3)
    {
        res += E3 % 10;
        E3 = E3 / 10;
        if (E3 == 0 && res >= 10)
        {
            E3 = res;
            res = 0;
        }
    }
    return res;
}
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (!checkE(E3))
    {
        return -99;
    }
    int array_2D[10][10];
    int lo_i = 0;
    int lo_j = 0;
    int tam = 1;
    float tam_HP1 = HP1;
    float tam_EXP1 = EXP1;
    float tam_HP2 = HP2;
    float tam_EXP2 = EXP2;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array_2D[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (array_2D[i][j] > (E3 * 2))
            {
                lo_i++;
            }
            if (array_2D[i][j] < (-E3))
            {
                lo_j++;
            }
        }
    }
    lo_i = res_number(lo_i);
    lo_j = res_number(lo_j);
    int val_taxi = array_2D[lo_i][lo_j];
    int val_two = array_2D[lo_i][lo_j];
    for (int tam = 1; tam < 10; tam++)
    {
        if (lo_i + tam <= 9 && lo_j + tam <= 9)
        {
            if (array_2D[lo_i + tam][lo_j + tam] > val_two)
            {
                val_two = array_2D[lo_i + tam][lo_j + tam];
            }
        }
        if (lo_i + tam <= 9 && lo_j - tam >= 0)
        {
            if (array_2D[lo_i + tam][lo_j - tam] > val_two)
            {
                val_two = array_2D[lo_i + tam][lo_j - tam];
            }
        }
        if (lo_i - tam >= 0 && lo_j + tam <= 9)
        {
            if (array_2D[lo_i - tam][lo_j + tam] > val_two)
            {
                val_two = array_2D[lo_i - tam][lo_j + tam];
            }
        }
        if (lo_i - tam >= 0 && lo_j - tam >= 0)
        {
            if (array_2D[lo_i - tam][lo_j - tam] > val_two)
            {
                val_two = array_2D[lo_i - tam][lo_j - tam];
            }
        }
    }
    if (val_two < abs(val_taxi))
    {
        tam_HP1 *= 0.9;
        tam_EXP1 *= 0.88;
        tam_HP2 *= 0.9;
        tam_EXP2 *= 0.88;
    }
    else
    {
        tam_HP1 *= 1.1;
        tam_EXP1 *= 1.12;
        tam_HP2 *= 1.1;
        tam_EXP2 *= 1.12;
    }
    HP1 = checkHP(tam_HP1);
    EXP1 = checkEXP(tam_EXP1);
    HP2 = checkHP(tam_HP2);
    EXP2 = checkEXP(tam_EXP2);

    if (val_two < abs(val_taxi))
    {
        return val_taxi;
    }
    else
    {
        return val_two;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    if (strlen(s) < 8)
    {
        return -1;
    }
    if (strlen(s) > 20)
    {
        return -2;
    }

    string first_str = "";
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] != '@')
        {
            first_str += email[i];
        }
        else
        {
            break;
        }
    }
    int tam = 0;
    int tam_ky_tu = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '@' or s[i] == '#' or s[i] == '%' or s[i] == '$' or s[i] == '!')
        {
            tam_ky_tu++;
        }
        if (s[i] == first_str[tam])
        {
            tam++;
            if (tam == first_str.length())
            {
                return -(300 + i - tam + 1);
            }
        }
        else
        {
            tam = 0;
        }
    }

    for (int i = 2; i < strlen(s); i++)
    {
        if (s[i] == s[i - 1] && s[i - 1] == s[i - 2])
        {
            return -(400 + i - 1);
        }
    }
    if (tam_ky_tu == 0)
    {
        return -5;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        int v = s[i]; // ASCII Val converted
        if (!((s[i] >= 48 && s[i] <= 57) or (s[i] >= 65 && s[i] <= 90) or (s[i] >= 97 && s[i] <= 122) or s[i] == '#' or s[i] == '@' or s[i] == '%' or s[i] == '$' or s[i] == '!'))
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_count = 0;
    int max_length = 0;
    string correct_password;
    int correct_password_index = -1;

    for (int i = 0; i < num_pwds; ++i)
    {
        string password = arr_pwds[i];
        int count = 0;
        for (int j = i + 1; j < num_pwds; ++j)
        {
            if (arr_pwds[j] == password)
            {
                count++;
            }
        }

        if (count > max_count || (count == max_count && password.length() > max_length))
        {
            max_count = count;
            max_length = password.length();
            correct_password = password;
        }
    }

    for (int i = 0; i < num_pwds; ++i)
    {
        if (arr_pwds[i] == correct_password)
        {
            correct_password_index = i;
            break;
        }
    }
    return correct_password_index;
}

//////////////////////////////////////////////
// / END OF STUDENT'S ANSWER
//     //////////////////////////////////////////////