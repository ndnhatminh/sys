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

// Helper Function
int nearestNum(int &EXP1)
{
    int nearest = round(sqrt(EXP1));
    return nearest * nearest;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    double dvd;
    if (e1 < 0 || e1 > 99)
        return -99;
    // Case 1
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 3)
            exp2 += 149;
        if (e1 == 2)
            exp2 += 75;
        if (e1 == 1)
            exp2 += 45;
        if (e1 == 0)
            exp2 += 29;
        int D;
        D = e1 * 3 + exp1 * 7;
        // D+=50;// cho nay can phai xem lai !
        if (D % 2 == 0)
        {
            dvd = D;
            exp1 = ceilf(exp1 + (dvd / 200));
        }
        else if (D % 2 == 1)
        {
            dvd = D;
            exp1 = ceilf(exp1 - (dvd / 100));
        }
    }

    // Case 2
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            dvd = e1;
            exp2 = ceilf(exp2 + (dvd / 4) + 19);
        }
        if (e1 >= 20 && e1 <= 49)
        {
            dvd = e1;
            exp2 = ceilf(exp2 + (dvd / 9) + 21);
        }
        if (e1 >= 50 && e1 <= 65)
        {
            dvd = e1;
            exp2 = ceilf(exp2 + (dvd / 16) + 17);
        }
        if (e1 >= 66 && e1 <= 79)
        {
            dvd = e1;
            exp2 = ceilf(exp2 + (dvd / 4) + 19);
            if (exp2 > 200)
                exp2 = ceilf(exp2 + (dvd / 9) + 21);
        }
        if (e1 >= 80 && e1 <= 99)
        {
            dvd = e1;
            exp2 = ceilf(exp2 + (dvd / 4) + 19);

            exp2 = ceilf(exp2 + (dvd / 9) + 21);

            if (exp2 > 400)
            {
                exp2 = ceilf(exp2 + (dvd / 16) + 17);

                exp2 = ceilf(exp2 * 1.15); // Explain all, 15% more EXP
            }
        }
        exp1 -= e1;
    }

    if (exp1 > 600)
        exp1 = 600; // Update EXP1
    if (exp2 > 600)
        exp2 = 600; // Update EXP2
    if (exp1 < 0)
        exp1 = 0;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
        return -99;
    float P1, P2, P3;
    float exp1, s1;
    // PATH 1
    int S1 = nearestNum(EXP1);
    if (EXP1 >= S1)
        P1 = 1;
    if (EXP1 < S1)
    {
        exp1 = EXP1;
        s1 = S1;
        P1 = ((exp1 / s1) + 80) / 123;
    }

    //  PATH 2
    float half = M1 * 0.5;
    int cost = 0;
    bool buyfoodanddrink = true;
    bool taxiorhorse = true;
    bool homelessguy = true;
    if (E2 % 2 == 1)
    {
        while (E2 % 2 == 1)
        { // TH E2 la so le
            if (HP1 < 200 && buyfoodanddrink)
            {
                buyfoodanddrink = false;
                float a = HP1;
                HP1 = ceilf(a * 1.3);
                M1 -= 150;
                cost += 150;
                if (HP1 > 666)
                    HP1 = 666;
                if (cost > half)
                {
                    float hp = HP1;
                    float exp = EXP1;
                    HP1 = ceilf(hp * 0.83);
                    EXP1 = ceilf(exp * 1.17);
                    if (EXP1 > 600)
                        EXP1 = 600;
                    break;
                }
            }
            if (HP1 >= 200 && buyfoodanddrink)
            {
                buyfoodanddrink = false;
                float a = HP1;
                HP1 = ceilf(a * 1.1);
                M1 -= 70;
                cost += 70;
                if (HP1 > 666)
                    HP1 = 666;
                if (cost > half)
                {
                    float hp = HP1;
                    float exp = EXP1;
                    HP1 = ceilf(hp * 0.83);
                    EXP1 = ceilf(exp * 1.17);
                    if (EXP1 > 600)
                        EXP1 = 600;
                    break;
                }
            }
            if (EXP1 < 400 && taxiorhorse)
            {
                taxiorhorse = false;
                M1 -= 200;
                float a = EXP1;
                EXP1 = ceilf(a * 1.13);
                if (EXP1 > 600)
                    EXP1 = 600;
                cost += 200;

                if (cost > half)
                {
                    float hp = HP1;
                    float exp = EXP1;
                    HP1 = ceilf(hp * 0.83);
                    EXP1 = ceilf(exp * 1.17);
                    if (EXP1 > 600)
                        EXP1 = 600;
                    break;
                }
            }
            if (EXP1 >= 400 && taxiorhorse)
            {
                taxiorhorse = false;
                M1 -= 120;
                float a = EXP1;
                EXP1 = ceilf(a * 1.13);
                if (EXP1 > 600)
                    EXP1 = 600;
                cost += 120;

                if (cost > half)
                {
                    float hp = HP1;
                    float exp = EXP1;
                    HP1 = ceilf(hp * 0.83);
                    EXP1 = ceilf(exp * 1.17);
                    if (EXP1 > 600)
                        EXP1 = 600;
                    break;
                }
            }
            if (EXP1 < 300 && homelessguy)
            {
                homelessguy = false;
                M1 -= 100;
                float a = EXP1;
                EXP1 = ceilf(a * 0.9);
                cost += 100;

                if (cost > half)
                {
                    float hp = HP1;
                    float exp = EXP1;
                    HP1 = ceilf(hp * 0.83);
                    EXP1 = ceilf(exp * 1.17);
                    if (EXP1 > 600)
                        EXP1 = 600;
                    break;
                }
            }
            if (EXP1 >= 300 && homelessguy)
            {
                homelessguy = false;
                M1 -= 120;
                float a = EXP1;
                EXP1 = ceilf(a * 0.9);
                cost += 120;

                if (cost > half)
                {
                    float hp = HP1;
                    float exp = EXP1;
                    HP1 = ceilf(hp * 0.83);
                    EXP1 = ceilf(exp * 1.17);
                    if (EXP1 > 600)
                        EXP1 = 600;
                    break;
                }
            }
            buyfoodanddrink = true;
            taxiorhorse = true;
            homelessguy = true;
        }
    }
    bool walking = false;
    if (E2 % 2 == 0)
    { // TH E2 la so chan

        if (HP1 < 200 && M1 > 0 && buyfoodanddrink)
        {
            buyfoodanddrink = false;
            float a = HP1;
            HP1 = ceilf(a * 1.3);
            M1 -= 150;
            cost += 150;
            if (HP1 > 666)
                HP1 = 666;
            if (M1 <= 0)
            {
                walking = true;
                M1 = 0;
                float hp = HP1;
                float exp = EXP1;
                HP1 = ceilf(hp * 0.83);
                EXP1 = ceilf(exp * 1.17);
                if (EXP1 > 600)
                    EXP1 = 600;
            }
        }
        if (HP1 >= 200 && M1 > 0 && buyfoodanddrink)
        {
            buyfoodanddrink = false;
            float a = HP1;
            HP1 = ceilf(a * 1.1);
            M1 -= 70;
            cost += 70;
            if (HP1 > 666)
                HP1 = 666;
            if (M1 <= 0)
            {
                walking = true;
                M1 = 0;
                float hp = HP1;
                float exp = EXP1;
                HP1 = ceilf(hp * 0.83);
                EXP1 = ceilf(exp * 1.17);
                if (EXP1 > 600)
                    EXP1 = 600;
            }
        }
        if (EXP1 < 400 && M1 > 0 && taxiorhorse)
        {
            taxiorhorse = false;
            M1 -= 200;
            float a = EXP1;
            EXP1 = ceilf(a * 1.13);
            cost += 200;
            if (EXP1 > 600)
                EXP1 = 600;
            if (M1 <= 0)
            {
                walking = true;
                M1 = 0;
                float hp = HP1;
                float exp = EXP1;
                HP1 = ceilf(hp * 0.83);
                EXP1 = ceilf(exp * 1.17);
                if (EXP1 > 600)
                    EXP1 = 600;
            }
        }
        if (EXP1 >= 400 && M1 > 0 && taxiorhorse)
        {
            taxiorhorse = false;
            M1 -= 120;
            float a = EXP1;
            EXP1 = ceilf(a * 1.13);
            cost += 120;
            if (EXP1 > 600)
                EXP1 = 600;
            if (M1 <= 0)
            {
                walking = true;
                M1 = 0;
                float hp = HP1;
                float exp = EXP1;
                HP1 = ceilf(hp * 0.83);
                EXP1 = ceilf(exp * 1.17);
                if (EXP1 > 600)
                    EXP1 = 600;
            }
        }
        if (EXP1 < 300 && M1 > 0 && homelessguy)
        {
            homelessguy = false;
            M1 -= 100;
            float a = EXP1;
            EXP1 = ceilf(a * 0.9);
            cost += 100;

            if (M1 <= 0)
            {
                walking = true;
                M1 = 0;
                float hp = HP1;
                float exp = EXP1;
                HP1 = ceilf(hp * 0.83);
                EXP1 = ceilf(exp * 1.17);
                if (EXP1 > 600)
                    EXP1 = 600;
            }
        }
        if (EXP1 >= 300 && M1 > 0 && homelessguy)
        {
            homelessguy = false;
            M1 -= 120;
            float a = EXP1;
            EXP1 = ceilf(a * 0.9);
            cost += 120;

            if (M1 <= 0)
            {
                walking = true;
                M1 = 0;
                float hp = HP1;
                float exp = EXP1;
                HP1 = ceilf(hp * 0.83);
                EXP1 = ceilf(exp * 1.17);
                if (EXP1 > 600)
                    EXP1 = 600;
            }
        }
        if (!walking)
        {
            float hp = HP1;
            float exp = EXP1;
            HP1 = ceilf(hp * 0.83);
            EXP1 = ceilf(exp * 1.17);
            if (EXP1 > 600)
                EXP1 = 600;
        }
    }

    int Y = nearestNum(EXP1);
    float y;
    if (EXP1 >= Y)
        P2 = 1;
    if (EXP1 < Y)
    {
        y = Y;
        exp1 = EXP1;
        P2 = ((exp1 / Y) + 80) / 123;
    }

    // PATH 3
    float P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
    if (E2 < 10)
        P3 = P[E2];
    if (E2 >= 10)
    {
        int n = E2;
        n = n % 10 + n / 10;
        P3 = P[n % 10];
    }

    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        float dvd = EXP1;
        EXP1 = ceilf(dvd * 0.75);
    }
    else
    {
        float AvGP = ((P1 + P2 + P3) / 3);
        float hp = HP1;
        float exp = EXP1;
        if (AvGP < 0.5)
        {

            HP1 = ceilf(hp * 0.85);
            EXP1 = ceilf(exp * 1.15);
        }
        else
        {
            HP1 = ceilf(hp * 0.9);
            EXP1 = ceilf(exp * 1.2);
        }
    }
    if (EXP1 > 600)
        EXP1 = 600;
    if (M1 < 0)
        M1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    int taxiscore[10][10] = {0};
    int a = 0;
    int b = 0;
    // Taxi Score
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxiscore[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxiscore[i][j] > E3 * 2)
                a++;
            if (taxiscore[i][j] < -E3)
                b++;
        }
    }
    // Sum of a and b until 1 digit left
    while (a >= 10)
    {
        a = a / 10 + a % 10;
    }

    while (b >= 10)
    {
        b = b / 10 + b % 10;
    }

    // Sherlock and Watson Score
    int sherlock_score = 0;
    int watson_score = 0;
    int Sherlock_Watson_score[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int LeftMax = taxiscore[i][j];
            int RightMax = taxiscore[i][j];

            // Left Max
            for (int k = 1; i + k < 10 && j + k < 10; k++)
            {
                LeftMax = max(LeftMax, taxiscore[i + k][j + k]);
            }

            // Right Max
            for (int k = 1; i + k < 10 && j - k >= 0; k++)
            {
                RightMax = max(RightMax, taxiscore[i + k][j - k]);
            }

            Sherlock_Watson_score[i][j] = max(LeftMax, RightMax);
        }
    }

    if (abs(taxiscore[a][b]) > Sherlock_Watson_score[a][b])
    {
        float hp1 = HP1;
        float hp2 = HP2;
        float exp1 = EXP1;
        float exp2 = EXP2;
        HP1 = ceilf(hp1 * 0.9);
        HP2 = ceilf(hp2 * 0.9);
        EXP1 = ceilf(exp1 * 0.88);
        EXP2 = ceilf(exp2 * 0.88);
        return taxiscore[a][b];
    }
    if (abs(taxiscore[a][b]) <= Sherlock_Watson_score[a][b])
    {
        float hp1 = HP1;
        float hp2 = HP2;
        float exp1 = EXP1;
        float exp2 = EXP2;
        HP1 = ceilf(hp1 * 1.1);
        HP2 = ceilf(hp2 * 1.1);
        EXP1 = ceilf(exp1 * 1.12);
        EXP2 = ceilf(exp2 * 1.12);
        if (EXP1 > 600)
            EXP1 = 600;
        if (EXP2 > 600)
            EXP2 = 600;
        if (HP1 > 666)
            HP1 = 666;
        if (HP2 > 666)
            HP2 = 666;
        return Sherlock_Watson_score[a][b];
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string pass(s);
    string userEmail(email);
    string se = userEmail.substr(0, userEmail.find('@'));
    int length = pass.length();
    int i = 0;
    if (length < 8) // Min Length
        return -1;
    if (length > 20) // Max Length
        return -2;
    int found = pass.find(se); // Exist se
    if (found != -1)
        return -(300 + found);
    for (int i = 0; i < length - 2; i++)
    {
        if (pass[i] == pass[i + 1] && pass[i] == pass[i + 2]) //  > 2 Consecutive Chars
            return -(400 + i);
    }
    bool specialChar = false;
    for (char c : pass)
    {
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') // Special Chars
            specialChar = true;
    }
    if (!specialChar)
        return -5;
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') // First Invalid Position
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
    int count = 0;
    int maxcount = 0;
    string correctPass;
    for (int i = 0; i < num_pwds; i++)
    {
        string password = arr_pwds[i];
        for (int j = 0; j < num_pwds; j++)
        {
            if (arr_pwds[j] == password)
                count++;
        }

        if (count > maxcount || count == maxcount && password.length() > correctPass.length())
        {
            maxcount = count;
            correctPass = password;
        }
        count = 0;

    } // Find the correct Pass
    for (int i = 0; i < num_pwds; i++)
    {
        if (string(arr_pwds[i]) == correctPass)
        {
            return i;
        }
    } // Return the position of the correct Pass

    return -1; // No Correct Pass
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////