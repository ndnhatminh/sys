#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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
////////////////////////////////////////////////////////////////////////\

//Important Functions
//Side-function for task 1
void explimit(int& exp1, int& exp2)
{
    if (exp1 < 0)
        exp1 = 0;
    else if (exp1 > 600)
        exp1 = 600;
    if (exp2 < 0)
        exp2 = 0;
    else if (exp2 > 600)
        exp2 = 600;
}

//Side-function for task 2
void task2limit(int& HP1, int& EXP1, int& M1)
{
    if (HP1 < 0)
        HP1 = 0;
    else if (HP1 > 666)
        HP1 = 666;

    if (EXP1 < 0)
        EXP1 = 0;
    else if (EXP1 > 600)
        EXP1 = 600;

    if (M1 < 0)
        M1 = 0;
    else if (M1 > 3000)
        M1 = 3000;
}

// Task 1
//side function to check the input values of exp1 and exp2

int firstMeet(int& exp1, int& exp2, int e1) {

    //Checking input limit of exp1 and exp2
    explimit(exp1, exp2);

    // Invalid case
    if (e1 < 0 || e1 > 99)
        return -99;

    //Case I
    if (e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 = exp2 + (29 + 45 + 75);
            break;
        }
        explimit(exp1, exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + D / 200.0);
            explimit(exp1, exp2);
        }
        else
        {
            exp1 = ceil(exp1 - D / 100.0);
            explimit(exp1, exp2);
        }
    }


    //Case II
    if (e1 >= 4) {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            explimit(exp1, exp2);
        }
        if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            explimit(exp1, exp2);
        }
        if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + e1 / 16.0 + 17);
            explimit(exp1, exp2);
        }
        if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            explimit(exp1, exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (e1 / 9.0 + 21));
                explimit(exp1, exp2);
            }
        }
        if (e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + (e1 / 4.0 + 19));
            exp2 = ceil(exp2 + (e1 / 9.0 + 21));
            explimit(exp1, exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (e1 / 16.0 + 17));
                explimit(exp1, exp2);
                exp2 = ceil(exp2 + exp2 * 0.15);
                explimit(exp1, exp2);
            }
        }
        exp1 = exp1 - e1;
        explimit(exp1, exp2);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{

    //Invalid case of E2's value
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }

    //Checking if inputs are in their limit
    task2limit(HP1, EXP1, M1);

    //Frist road
    //S1 is the nearest perfectsquare number to EXP1 value
    //P1 is the probability for Sherlock to find the suitcase on this route
    //s11 is the squareroot number of EXP1
    //s12 is the round-up value of sqrt EXP1
    int S1;
    double P1;
    int s11;
    s11 = floor(sqrt(EXP1)); //round-down the value of sqrt EXP1
    int s12 = s11 + 1;

    //Find S
    if (EXP1 - pow(s11, 2) > pow(s12, 2) - EXP1)
    {
        S1 = pow(s12, 2);
    }
    else if (EXP1 - pow(s11, 2) < pow(s12, 2) - EXP1)
    {
        S1 = pow(s11, 2);
    }

    //Find P1
    if (EXP1 >= S1)
    {
        P1 = 1.00;
    }
    else
    {
        P1 = (EXP1 / S1 + 80) / 123.0;
    }

    //Second road
    int M11 = 0.5 * M1; //M11 is a half of initial Sherlock's money
    int i2 = 0; //Side variable to process the case E2 is even
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //E2 is odd
    if (E2 % 2 != 0)
    {
        while (true)
        {

            //Event 1
            if (HP1 < 200 && M1 > 0)
            {
                HP1 = ceil(HP1 + HP1 * 0.30 - 1e-5);
                M1 = M1 - 150;
            }
            else if (HP1 >= 200 && M1 > 0)
            {
                HP1 = ceil(HP1 + HP1 * 0.10 - 1e-5);
                M1 = M1 - 70;
            }
            else
            {
                break;
            }
            task2limit(HP1, EXP1, M1);
            if (2 * M11 - M1 > M11)
            {
                break;
            }

            //Event 2
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else
            {
                M1 = M1 - 120;
            }
            EXP1 = ceil(EXP1 + EXP1 * 0.13 - 1e-5);
            task2limit(HP1, EXP1, M1);
            if (2 * M11 - M1 > M11)
            {
                break;
            }

            //Event 3
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 - EXP1 * 0.10 - 1e-5);
            task2limit(HP1, EXP1, M1);
            if (2 * M11 - M1 > M11)
            {
                break;
            }
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //E2 is even
    else {
        while (i2 == 0)
        {
            //Event 1
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.30 - 1e-5);
                M1 = M1 - 150;
            }

            else if (HP1 >= 200)
            {
                HP1 = ceil(HP1 * 1.10 - 1e-5);
                M1 = M1 - 70;
            }
            task2limit(HP1, EXP1, M1);
            if (M1 == 0)
            {
                break;
            }

            //Event 2
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else
            {
                M1 = M1 - 120;
            }
            EXP1 = ceil(EXP1 * 1.13 - 1e-5);
            task2limit(HP1, EXP1, M1);
            if (M1 == 0)
            {
                break;
            }

            //Event 3
            if (EXP1 < 300)
            {
                M1 -= 100;
            }
            else
            {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 - EXP1 * 0.10 - 1e-5);
            task2limit(HP1, EXP1, M1);
            i2++;
        }
    }

    ///Update after road 2 event
    HP1 = ceil(HP1 - (HP1 * 0.17) - 1e-5);
    EXP1 = ceil(EXP1 + (EXP1 * 0.17) - 1e-5);
    task2limit(HP1, EXP1, M1);

    //Value of P2
    //S2 is the nearest perfectsquare number to EXP1 value
    //P2 is the probability for Sherlock to find the suitcase on this route
    //s21 is the squareroot number of EXP1
    //s22 is the round-up value of sqrt EXP1
    int S2;
    double P2;
    int s21;
    s21 = floor(sqrt(EXP1)); //round-down the value of sqrt EXP1
    int s22 = s21 + 1;

    //Find S
    if (EXP1 - pow(s21, 2) > pow(s22, 2) - EXP1)
    {
        S2 = pow(s22, 2);
    }
    else if (EXP1 - pow(s21, 2) < pow(s22, 2) - EXP1)
    {
        S2 = pow(s21, 2);
    }

    //Find P2
    if (EXP1 >= S2)
    {
        P2 = 1.00;
    }
    else
    {
        P2 = (EXP1 / S2 + 80) / 123.0;
    }

    //Third road
    int Pi[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i, i1;
    //i1 are side-variable

    //if E2 has one letter
    if (E2 >= 0 && E2 <= 9)
    {
        i = E2;
    }

    //If E2 have two letters
    else if (E2 >= 10 && E2 <= 99)
    {
        i1 = floor(E2 / 10.0);
        i = (i1 + (E2 % 10)) % 10;
    }
    double P3 = (Pi[i]) / 100.00;

    //Caculate the rate
    double P;
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil(EXP1 * 0.75 - 1e-5);
        task2limit(HP1, EXP1, M1);
    }
    else
    {
        P = (P1 + P2 + P3) / 3;
        if (P < 0.5)
        {
            HP1 = ceil(HP1 * 0.85 - 1e-5);
            EXP1 = ceil(EXP1 * 1.15 - 1e-5);
        }
        else
        {
            HP1 = ceil(HP1 * 0.9 - 1e-5);
            EXP1 = ceil(EXP1 * 1.20 - 1e-5);
        }
        task2limit(HP1, EXP1, M1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    return -1;
}

// Task 4
int checkPassword(const char* s, const char* email)
{
    ///find the location of "@"
    char se[100];
    const char* location = strchr(email, '@');
    int length = location - email;
    const char* specialdigit = "!@#$%";

    //Copy the string before @ to se
    strncpy(se, email, length);
    se[length] = '\0';

    //length checking
    int length1 = strlen(s);
    if (length1 < 8)
    {
        return -1;
    }
    else if (length1 > 20)
    {
        return -2;
    }

    //se in s?
    const char* seins = strstr(s, se);
    if (seins != nullptr)
    {
        return -(300 + (seins - s));
    }

    ///////checking if there is a string repeats a letter more than twice
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            int position = i;
            return -(400 + position);
        }
    }

    ///////checking if there is no special digit
    for (int i = 0; i < strlen(s); i++) {
        if (strpbrk(s, specialdigit) == nullptr)
        {
            return -5;
        }
    }

    //////checking if there is any letter that is invalid
    for (int i = 0; i < strlen(s); i++)
    {
        char charchecking = s[i];
        if (!(isdigit(charchecking) || islower(charchecking) || isupper(charchecking) || charchecking == '@' || charchecking == '#' || charchecking == '%' || charchecking == '$' || charchecking == '!'))
        {
            int position = i;
            return i;
        }
    }
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    //Variables to store the frequency and the length of each password
    int* frequen = new int[num_pwds]();
    int* length = new int[num_pwds]();

    ////Find the frequency and length

    //Find the length of each password with strlen syntax
    for (int i = 0; i < num_pwds; i++)
    {
        const char* password = arr_pwds[i]; //set input as typed password
        length[i] = strlen(password); //count the number of letter of the typed password

        // Start with frequency as 1 because each password appear at leasts once 
        frequen[i] = 1;

        //compare password in each location in array to find the times of each written password
        for (int j = i; j < num_pwds; j++)
        {
            if (strcmp(password, arr_pwds[j]) == 0) {
                frequen[i]++;
            }
        }
    }

    //// Find the correct password
    int max_frequen = 0; //set initial value for max frequency
    int max_length = 0; //set initial value for max length
    int correct_password_position;
    ///////////////////////////////////////////////////////////////////////finding processing//////////////////////////////////////////////////////////

    //if the chosen password has the largest frequency, it will be the correct password.
    for (int i = 0; i < num_pwds; ++i)
    {
        if (frequen[i] > max_frequen)
        {
            max_frequen = frequen[i];
            max_length = length[i];
            correct_password_position = i;
        }

        //if the chosen password has the longest length and it has the largest frequency also, it will be the correct password.
        else if (frequen[i] == max_frequen && length[i] > max_length)
        {
            max_frequen = frequen[i];
            max_length = length[i];
            correct_password_position = i;
        }
    }
    return correct_password_position;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////