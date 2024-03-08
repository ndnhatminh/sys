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
void EXPchecking(int &EXP1, int&EXP2) {
    if (EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
            EXP1 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
    else if (EXP2 < 0)
            EXP2 = 0;
}

void HPchecking(int &HP1, int &HP2) {
    if (HP1 > 666)
        HP1 = 666;
    else if (HP1 < 0)
            HP1 = 0;
    if (HP2 > 666)
        HP2 = 666;
    else if (HP2 < 0)
            HP2 = 0;
}

void Mchecking(int &M1, int &M2) {
    if (M1 > 3000)
        M1 = 3000;
    else if (M1 < 0)
        M1 = 0;
    if (M2 > 3000)
        M2 = 3000;
    else if (M2 < 0)
        M2 = 0;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function

    if (E1 >= 0 && E1 <= 99) {
        if (E1 >= 0 && E1 <= 3) {
    	    if (E1 == 0) {
                EXP2 += 29; }
            else if (E1 == 1) {
                EXP2 += 45; }
            else if (E1 == 2) {
                EXP2 += 75; }
                else if (E1 == 3) {
                EXP2 += 29 + 45 + 75; }
        int D = E1 * 3.0 + EXP1 * 7.0;
        if (D % 2 == 0) {
                EXP1 = ceil(EXP1 + (D*1.0)/200); }
            else { EXP1 = ceil(EXP1 - (D*1.0)/100);
            }
        EXPchecking(EXP1, EXP2);
        }

        if (E1 >= 4 && E1 <= 99) {
            if (E1 >= 4 && E1 <= 19) {
                EXP2 += ceil(E1 / 4.0 + 19); }
            else if (E1 >= 20 && E1 <= 49) {
                EXP2 += ceil(E1 / 9.0 + 21); }
            else if (E1 >=50 && E1 <= 65) {
                EXP2 += ceil(E1 / 16.0 + 17); }
            else if (E1 >= 66 && E1 <= 79) {
                EXP2 += ceil(E1 / 4.0 + 19); 
                if ( EXP2 > 200) {
                        EXP2 += ceil(E1 /9.0 + 21); 
                        EXPchecking(EXP1, EXP2);
                }}
            else if (E1 >= 80 && E1 <= 99) {
                EXP2 = ceil(EXP2 + (E1/ 4.0) + 19);
                EXP2 = ceil(EXP2 + (E1/ 9.0) + 21);
                EXPchecking(EXP1, EXP2);
                if (EXP2 > 400) {
                        EXP2 = ceil(EXP2 + (E1 / 16.0) + 17);
                        EXP2 = ceil(EXP2 + 0.15*EXP2);
                        EXPchecking(EXP1, EXP2);} }
        EXP1 = EXP1 - E1;
        EXPchecking(EXP1, EXP2);
    }} else {

        return -99;
    }
    return EXP1 + EXP2;
}



int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    double P1;
    double P2 = 0;
    int S1 = round(sqrt(EXP1));

    if (EXP1 >= S1 * S1)
    {
        P1 = 100;
    }
    else
    {
        P1 = 100 * ((EXP1 * 1.0) / (S1 * S1) + 80) / 123.0;
    }
    int Mpay = 0;
    int Mint = M1;
    while (true)
    {
        if (E2 % 2 == 0)
        {
            if (M1 <= 0)
                break;
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + 0.3 * HP1);
                M1 = M1 - 150;
                Mchecking(M1, M1);
                HPchecking(HP1, HP1);
            }
            else
            {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 = M1 - 70;
                Mchecking(M1, M1);
                HPchecking(HP1, HP1);
            }

            if (M1 <= 0)
                break;
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                EXP1 = ceil(EXP1 + 0.13 * EXP1);
                Mchecking(M1, M1);
                EXPchecking(EXP1, EXP1);
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 + 0.13 * EXP1);
                Mchecking(M1, M1);
                EXPchecking(EXP1, EXP1);
            }
            if (M1 <= 0)
                break;
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                Mchecking(M1, M1);
                EXPchecking(EXP1, EXP1);
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                Mchecking(M1, M1);
                EXPchecking(EXP1, EXP1);
            }

            break;
        }

        if (E2 % 2 != 0)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 + 0.3 * HP1);
                M1 = M1 - 150;
                Mpay = Mpay + 150;
                Mchecking(M1, M1);
                HPchecking(HP1, HP1);
            }
            else
            {
                HP1 = ceil(HP1 + 0.1 * HP1);
                M1 = M1 - 70;
                Mpay = Mpay + 70;
                Mchecking(M1, M1);
                HPchecking(HP1, HP1);
            }

            if (Mpay > 0.5 * Mint)
            {

                break;
            }

            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                Mchecking(M1, M1);
                Mpay = Mpay + 200;
                EXP1 = ceil(EXP1 + 0.13 * EXP1);
                EXPchecking(EXP1, EXP1);
            }
            else
            {
                M1 = M1 - 120;
                Mchecking(M1, M1);
                Mpay = Mpay + 120;
                EXP1 = ceil(EXP1 + 0.13 * EXP1);
                EXPchecking(EXP1, EXP1);
            }

            if (Mpay > 0.5 * Mint)
            {

                break;
            }

            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                Mchecking(M1, M1);
                Mpay = Mpay + 100;
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                EXPchecking(EXP1, EXP1);
            }
            else
            {
                M1 = M1 - 120;
                Mchecking(M1, M1);
                Mpay = Mpay + 120;
                EXP1 = ceil(EXP1 - 0.1 * EXP1);
                EXPchecking(EXP1, EXP1);
            }
            if (Mpay > 0.5 * Mint)
            {

                break;
            }
        }
    }
    HP1 = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1);
    EXPchecking(EXP1, EXP1);
    HPchecking(HP1, HP1);
    int S = round(sqrt(EXP1));
    if (EXP1 >= S * S)
    {
        P2 = 100;
    }
    else
    {
        P2 = 100 * ((EXP1 * 1.0) / (S * S) + 80) / 123.0;
    }
    double P3;
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10)
    {
        i = E2;
        P3 = P[i];
    }
    else
    {
        int unit = E2 % 10;
        int tens = (E2 / 10);
        i = (unit + tens) % 10;

        P3 = (P[i]);
    }
    double Pavag;
    Pavag = (P1 + P2 + P3) / 3.0;

    if (Pavag == 100)
    {
        EXP1 = ceil(EXP1 - 0.25 * EXP1);
        EXPchecking(EXP1, EXP1);
    }
    else if (Pavag < 100)
    {
        if (Pavag < 50)
        {
            HP1 = ceil(HP1 - 0.15 * HP1);
            EXP1 = ceil(EXP1 + 0.15 * EXP1);
            EXPchecking(EXP1, EXP1);
            HPchecking(HP1, HP1);
        }
        else
        {
            HP1 = ceil(HP1 - 0.1 * HP1);
            EXP1 = ceil(EXP1 + 0.2 * EXP1);
            EXPchecking(EXP1, EXP1);
            HPchecking(HP1, HP1);
        }
    }
    return HP1 + EXP1 + M1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) {
        return -99;
        }
        
        int arr[10][10] = {0};

        int axispA = 0, axispB = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                arr[i][j] = (((E3 * j) + (i * 2)) * (i - j));
                if (arr[i][j] > (E3 * 2)){
                    axispA++;
                }
                if (arr[i][j] < -E3) {
                    axispB++;
                }
            }
        }

        while (axispA >= 10) {
            axispA = axispA / 10 + axispA % 10;
        }
        while (axispB >= 10) {
            axispB = axispB / 10 + axispB % 10;
        }

        int axispA1 = axispA, axispA2 = axispA, axispA3 = axispA, axispA4 = axispA;
        int axispB1 = axispB, axispB2 = axispB, axispB3 = axispB, axispB4 = axispB;
        int encounterp = arr[axispA][axispB], temp = INT_MIN, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;

            if (encounterp > temp)
            {
                temp = encounterp;
            }
        
        while (axispA1 >= 0 && axispB1 >= 0) {
            if (arr[axispA1][axispB1] > temp) {
                temp = arr[axispA1][axispB1];
            }
            if (temp > max1) {
                max1 = temp;
            }
            axispA1--;
            axispB1--;
        } 

        while (axispA2  < 10 && axispB2 >= 0) {
            if (arr[axispA2][axispB2] > temp) {
                temp = arr[axispA2][axispB2];
            }
            if (temp > max2) {
                max2 = temp;
            }
            axispA2++;
            axispB2--;
        } 

        while (axispA3 < 10 && axispB3 < 10) {
            if (arr[axispA3][axispB3] > temp) {
                temp = arr[axispA3][axispB3];
            }
            if (temp > max3) {
                max3 = temp;
            }
            axispA3++;
            axispB3++;

        } 

        while (axispA4  >= 0 && axispB4 < 10) {
            if (arr[axispA4][axispB4] > temp) {
                temp = arr[axispA4][axispB4];
            }
            if (temp > max4) {
                max4 = temp;
            }
            axispA4--;
            axispB4++;
        } 

        int SherlockP = max1;
        if (max2 > SherlockP){
            SherlockP = max2;
        } else if (max3 > SherlockP) {
            SherlockP = max3;
        } else if (max4 > SherlockP) {
            SherlockP = max4;
        }

        if (abs(encounterp) > abs(SherlockP)) {
            EXP1 = ceil(EXP1 - 0.12 * EXP1);
            EXP2 = ceil(EXP2 - 0.12 * EXP2);
            HP1 = ceil(HP1 - 0.1 * HP1);
            HP2 = ceil(HP2 - 0.1 * HP2);
            HPchecking(EXP1, EXP2);
            EXPchecking(EXP1, EXP2);
            return encounterp;
        } else {
            EXP1 = ceil(EXP1 + 0.12 * EXP1);
            EXP2 = ceil(EXP2 + 0.12 * EXP2);
            HP1 = ceil(HP1 + 0.1 * HP1);
            HP2 = ceil(HP2 + 0.1 * HP2);
            HPchecking(EXP1, EXP2);
            EXPchecking(EXP1, EXP2);
            return abs(SherlockP);
        }
    return -1;
}

int checkPassword(const char *s, const char *email)
{
        const int arraySize = 101;
        char se[arraySize];
        int lengthS = strlen(s), i = 0, length = 0, maxSize = arraySize, position = 0; 
        while (email[i] != '\0' && email[i] != '@' && i < maxSize - 1) {
            se[i] = email[i];
            i++;
        }
        se[i] = '\0';

        if (lengthS < 8) {
            return -1;
        } else if (lengthS > 20) {
            return -2;
        }

        const char* pos = strstr(s, se); 
        if (pos != nullptr) {
            return -(300 + (pos - s));
        }

        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] == s[i + 1]) {
                length++;
  
            if (length >= 2) {
                position = i - length + 1;
                return -(400 + position);
                }
            } else {
                length = 0;
            }
        }

        bool SpecialChar = false;
        for (int i = 0; i < lengthS; ++i) {
            if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
                SpecialChar = true;
                break;
            }
        }

        for (int i = 0; i < lengthS; ++i) {
            if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
                if (SpecialChar) {
                    return i; 
                } else {
                    return -5; 
                }
            }
        }

        if (!SpecialChar) {
            return -5; 
        } else {
            return -10; 
        }

    return 1;
}
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int freq = 0, pos = -1;
    for (int i = 0; i < num_pwds; i++) {
            int count = 0;
            for (int j = 0; j < num_pwds; j++) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                    if (i <= j) {
                        count++;
                    } else break;
                }
            }
            if (freq < count || (freq == count && strlen(arr_pwds[i]) > strlen(arr_pwds[pos]))){
                freq = count;
                pos = i;
            }
    }
    return pos;

    return 1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////