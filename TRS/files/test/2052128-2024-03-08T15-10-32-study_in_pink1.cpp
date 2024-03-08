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

void clamp(int &value, int lower, int upper)
{
    if (value < lower)
        value = lower;
    else if (value > upper)
        value = upper;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99)
        return -99;

    clamp(exp1, 0, 600);
    clamp(exp2, 0, 600);

    // CASE 1
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
            exp2 += 29;
        else if (e1 == 1)
            exp2 += 45;
        else if (e1 == 2)
            exp2 += 75;
        else if (e1 == 3)
            exp2 += (29 + 45 + 75);

        int D = (e1 * 3) + (exp1 * 7);

        if (D % 2 == 0)
            exp1 = ceil(exp1 + (float)D / 200);
        else if (D % 2 != 0)
            exp1 = ceil(exp1 - (float)D / 100);
    }

    // CASE 2
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
            exp2 += ceil((float)e1 / 4 + 19);
        else if (e1 >= 20 && e1 <= 49)
            exp2 += ceil((float)e1 / 9 + 21);
        else if (e1 >= 50 && e1 <= 65)
            exp2 += ceil((float)e1 / 16 + 17);
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += ceil((float)e1 / 4 + 19);
            if (exp2 > 200)
                exp2 += ceil((float)e1 / 9 + 21);
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += ceil((float)e1 / 4 + 19);
            exp2 += ceil((float)e1 / 9 + 21);
            if (exp2 > 400)
            {
                exp2 += ceil((float)e1 / 16 + 17);
                exp2 += ceil((float)exp2 * 15 / 100);
            }
        }

        exp1 -= e1;
    }

    clamp(exp1, 0, 600);
    clamp(exp2, 0, 600);

    return exp1 + exp2;
}

// Task 2

int nearest_square(int n)
{
    if (n == 0)
        return 0;

    int root = 1;
    while (root * root < n)
    {
        root = root + 1;
    }

    int diff1 = root * root - n;
    int diff2 = n - (root - 1) * (root - 1);

    if (diff1 < diff2)
        return root * root;
    else
        return (root - 1) * (root - 1);
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99)
        return -99;

    clamp(M1, 0, 3000);
    clamp(EXP1, 0, 600);
    clamp(HP1, 0, 666);

    float P1, P2, P3, PResult = 0;

    // ROAD 1
    int S = nearest_square(EXP1);
    if (EXP1 >= S)
        P1 = 100;
    else
        P1 = ((((float)EXP1 / S) + 80) / 123) * 100;

    // ROAD 2
    int totalSpent = 0;

    while (true)
    {
        if (M1 == 0)
        {
            M1 -= totalSpent;
            HP1 = ceil(HP1 - (float)HP1 * 0.17);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.17);
            clamp(M1, 0, 3000);
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
            break;
        }

        // FOOD & DRINK
        if (HP1 < 200)
        {
            HP1 += ceil((float)HP1 * 0.3);
            clamp(HP1, 0, 666);
            totalSpent += 150;
        }
        else
        {
            HP1 += ceil((float)HP1 * 0.1);
            clamp(HP1, 0, 666);
            totalSpent += 70;
        }
        if ((totalSpent > M1 / 2 && E2 % 2 != 0) || (M1 - totalSpent <= 0 && E2 % 2 == 0))
        {
            M1 -= totalSpent;
            HP1 = ceil(HP1 - (float)HP1 * 0.17);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.17);
            clamp(M1, 0, 3000);
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
            break;
        }

        // TAXI & HORSE
        if (EXP1 < 400)
            totalSpent += 200;
        else
            totalSpent += 120;
        EXP1 += ceil((float)EXP1 * 0.13);
        clamp(EXP1, 0, 600);
        if ((totalSpent > M1 / 2 && E2 % 2 != 0) || (M1 - totalSpent <= 0 && E2 % 2 == 0))
        {
            M1 -= totalSpent;
            HP1 = ceil(HP1 - (float)HP1 * 0.17);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.17);
            clamp(M1, 0, 3000);
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
            break;
        }
        // HOMELESS
        if (EXP1 < 300)
            totalSpent += 100;
        else
            totalSpent += 120;
        EXP1 = ceil(EXP1 - (float)EXP1 * 0.1);
        clamp(EXP1, 0, 600);
        if ((totalSpent > M1 / 2 && E2 % 2 != 0) || (M1 - totalSpent <= 0 && E2 % 2 == 0))
        {
            M1 -= totalSpent;
            HP1 = ceil(HP1 - (float)HP1 * 0.17);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.17);
            clamp(M1, 0, 3000);
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
            break;
        }

        if (E2 % 2 == 0)
        {
            M1 -= totalSpent;
            HP1 = ceil(HP1 - (float)HP1 * 0.17);
            EXP1 = ceil(EXP1 + (float)EXP1 * 0.17);
            clamp(M1, 0, 3000);
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
            break;
        }
    }

    S = nearest_square(EXP1);
    if (EXP1 >= S)
        P2 = 100;
    else
        P2 = ((((float)EXP1 / S) + 80) / 123) * 100;

    // ROAD 3
    int PArray[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    if (E2 < 10)
        P3 = PArray[E2];
    else
        P3 = PArray[((E2 / 10) + (E2 % 10)) % 10];

    // FINAL
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(EXP1 - ((float)EXP1 * 0.25));
        clamp(EXP1, 0, 600);
    }
    else
    {
        PResult = (float)(P1 + P2 + P3) / 3;
        if (PResult < 50)
        {
            HP1 = ceil(HP1 - ((float)HP1 * 0.15));
            EXP1 = ceil(EXP1 + ((float)EXP1 * 0.15));
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
        }
        else
        {
            HP1 = ceil(HP1 - ((float)HP1 * 0.1));
            EXP1 = ceil(EXP1 + ((float)EXP1 * 0.2));
            clamp(EXP1, 0, 600);
            clamp(HP1, 0, 666);
        }
    }
    clamp(M1, 0, 3000);
    clamp(EXP1, 0, 600);
    clamp(HP1, 0, 666);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99)
        return -99;

    clamp(EXP1, 0, 600);
    clamp(HP1, 0, 666);
    clamp(EXP2, 0, 600);
    clamp(HP2, 0, 666);

    int taxiMatrix[10][10] = {0};
    int greaterPosNum = 0;
    int smallerNegNum = 0;

    int meetPoint = taxiMatrix[0][0];
    int SherlockWatsonPoint = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxiMatrix[i][j] > E3 * 2)
                greaterPosNum++;
            if (taxiMatrix[i][j] < -E3)
                smallerNegNum++;
        }
    }

    while (greaterPosNum >= 10)
        greaterPosNum = (greaterPosNum / 10) + (greaterPosNum % 10);
    while (smallerNegNum >= 10)
        smallerNegNum = (smallerNegNum / 10) + (smallerNegNum % 10);

    // if (greaterPosNum > 10)
    //     greaterPosNum = ((greaterPosNum / 10) + (greaterPosNum % 10)) % 10;
    // if (smallerNegNum > 10)
    //     smallerNegNum = ((smallerNegNum / 10) + (smallerNegNum % 10)) % 10;
    meetPoint = taxiMatrix[greaterPosNum][smallerNegNum];

    SherlockWatsonPoint = meetPoint;
    int i = greaterPosNum;
    int j = smallerNegNum;

    while (i < 10 && j >= 0)
    {
        if (taxiMatrix[i][j] > SherlockWatsonPoint)
            SherlockWatsonPoint = taxiMatrix[i][j];
        i++;
        j--;
    }

    i = greaterPosNum;
    j = smallerNegNum;

    while (i >= 0 && j < 10)
    {
        if (taxiMatrix[i][j] > SherlockWatsonPoint)
            SherlockWatsonPoint = taxiMatrix[i][j];
        i--;
        j++;
    }

    i = greaterPosNum;
    j = smallerNegNum;

    while (i < 10 && j < 10)
    {
        if (taxiMatrix[i][j] > SherlockWatsonPoint)
            SherlockWatsonPoint = taxiMatrix[i][j];
        i++;
        j++;
    }

    i = greaterPosNum;
    j = smallerNegNum;

    while (i >= 0 && j >= 0)
    {
        if (taxiMatrix[i][j] > SherlockWatsonPoint)
            SherlockWatsonPoint = taxiMatrix[i][j];
        i--;
        j--;
    }

    if (abs(taxiMatrix[greaterPosNum][smallerNegNum]) > abs(SherlockWatsonPoint))
    {
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        HP1 = ceil(HP1 - HP1 * 0.1);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
        HP2 = ceil(HP2 - HP2 * 0.1);

        clamp(EXP1, 0, 600);
        clamp(HP1, 0, 666);
        clamp(EXP2, 0, 600);
        clamp(HP2, 0, 666);

        return taxiMatrix[greaterPosNum][smallerNegNum];
    }
    else
    {
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        HP1 = ceil(HP1 + HP1 * 0.1);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
        HP2 = ceil(HP2 + HP2 * 0.1);

        clamp(EXP1, 0, 600);
        clamp(HP1, 0, 666);
        clamp(EXP2, 0, 600);
        clamp(HP2, 0, 666);

        return SherlockWatsonPoint;
    }

    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    if (strlen(s) < 8)
        return -1;
    if (strlen(s) > 20)
        return -2;

    int seLen = 0;
    for (int i = 0; email[i] != '@'; i++)
    {
        seLen++;
    }

    if (strlen(s) >= seLen)
    {
        for (int i = 0; i <= strlen(s) - seLen; i++)
        {
            int j;
            for (j = 0; j < seLen; j++)
                if (s[i + j] != email[j])
                    break;
            if (j == seLen)
                return -(300 + i);
        }
    }

    for (int i = 0; i < strlen(s) - 2; i++)
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);

    bool hasSpecial = false;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            hasSpecial = true;
        if (!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
            return i;
    }

    if (hasSpecial == false)
        return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    string correct_pass = "";
    int correct_count = 0;
    int correct_index = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        string current_pass = arr_pwds[i];
        int repeatCount = 0;

        for (int j = 0; j < num_pwds; j++)
            if (current_pass == arr_pwds[j])
                repeatCount++;

        if (repeatCount > correct_count || (repeatCount == correct_count && current_pass.length() > correct_pass.length()))
        {
            correct_pass = current_pass;
            correct_count = repeatCount;
            correct_index = i;
        }
    }

    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////