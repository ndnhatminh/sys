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
// Initial functions
        // For Input
        // Limit the Health Point
        void limitHP(int &HP)
    {
        if (HP < 0) HP = 0;
        else if (HP > 666) HP = 666;
    }
        // Limit the EXP
        void limitEXP(int &EXP)
    {
        if (EXP < 0) EXP = 0;
        else if (EXP > 600) EXP = 600;
    }
        // Limit the Money
        void limitM(int &M)
    {
        if (M < 0) M = 0;
        else if (M > 3000) M = 3000;
    }
    // Task 1
    //Second case
        // calculate info 1
        void info1(int &exp2,float e1)
        {
            exp2 = ceil(exp2 + (e1 / 4 + 19));
            limitEXP(exp2);
        } 
        // calculate info 2
        void info2(int &exp2,float e1)
        {
            exp2 = ceil(exp2 + (e1 / 9 + 21));
            limitEXP(exp2);
        } 
        // calculate info 3
        void info3(int &exp2,float e1)
        {
            exp2 = ceil(exp2 + (e1 / 16 + 17));
            limitEXP(exp2);
        } 
    // Task 2
        // Check if it is perfect square or not
        bool checksqrt(int exp1)
        {
            if (sqrt(exp1) - floor(sqrt(exp1)) == 0) return true;
            else return false;
        }
        // Finding the nearest perfect square
        void findsqrt(int EXP1, int &S)
        {
        int top, bot, n; 
        if (checksqrt(EXP1) == false) 
        {
        n  = EXP1 + 1;
        while (!checksqrt(n)) n++;
        top = n;
        n = EXP1 - 1;
        while (!checksqrt(n)) n--;
        bot = n;
        if (top-EXP1 <= EXP1-bot ) S = top;
        else S = bot;
        }
        else S = EXP1;
        }
        // Calculate the chance
        void chance(float EXP1,float S,float &P)
        {
        if (EXP1 >= S) P = 100;
        else P = (((EXP1 / S) + 80) / 123) * 100;
        }
    // Path 2
        // Eat and drink for healing up
        void eat(int &HP1, int &M1, int &charge)
        {
            if (HP1 < 200) // eat and drink something
            {
                HP1 = ceil(HP1 + HP1 * 0.3);
                limitHP(HP1);
                M1 -= 150;
                charge += 150;
                limitM(M1);
            }
            else // only get something to drink
            {
                HP1 = ceil(HP1 + HP1 * 0.1);
                limitHP(HP1);
                M1 -= 70;
                charge += 70;
                limitM(M1);
            }
        }
        // Wander by Transportations
        void wander(int &EXP1, int &M1, int &charge)
        {
            if (EXP1 < 400) // choose taxi
            {
                M1 -= 200;
                charge += 200;
                limitM(M1);
            }
            else // horse cart
            {
                M1 -= 120;
                charge += 120;
                limitM(M1);
            }
            EXP1 = ceil(EXP1 + EXP1 * 0.13);
            limitEXP(EXP1);
        }
        // Trust The Homeless
        void trust( int &EXP1,int &M1, int &charge)
        {
            if (EXP1 < 300)
            {
                M1 -= 100;
                charge += 100;
                limitM(M1);
            }
            else 
            {
                M1 -= 120;
                charge += 120;
                limitM(M1);
            }
            EXP1 = ceil(EXP1 - EXP1 * 0.1);
            limitEXP(EXP1); 
        }
        // Update EXP and HP after all events in Path 2
        void upstat( int &EXP1,int &HP1)
        {
            HP1 = ceil(HP1 - HP1 * 0.17);
            limitHP(HP1);
            EXP1 = ceil(EXP1 + EXP1 * 0.17);
            limitEXP(EXP1);
        }
///////////////////////////////////////////////////////////////////
// Functions
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // First Check
    limitEXP(exp1);
    limitEXP(exp2);
    if (e1 <= 3 && e1 >= 0) // in first case
    {
        switch (e1) 
        {
            case 0: // information 1
                    exp2 += 29;
                    limitEXP(exp2);
                    break;
            case 1: // information 2
                    exp2 += 45;
                    limitEXP(exp2);
                    break;
            case 2: // information 3
                    exp2 += 75;
                    limitEXP(exp2);
                    break;
            case 3: //information 4
                    exp2 = exp2 + 29 + 45 + 75;
                    limitEXP(exp2);
                    break;
        }
    // calculate the D and exp for Sherlock
        int D;
        D = e1 * 3 + exp1 * 7;
        if ( D % 2 == 0) exp1 = ceil(exp1 + (D * 0.005));
            else exp1 = ceil(exp1 - (D * 0.01));
        limitEXP(exp1);
    }
        else if (e1 >= 4 && e1 <= 99) // in second case
        {
            switch (e1)
            {
                case 4 ... 19: // information 1
                    info1(exp2, e1);
                    break;
                case 20 ... 49: // information 2
                    info2(exp2, e1);
                    break;
                case 50 ... 65: // information 3
                    info3(exp2, e1);
                    break;
                case 66 ... 79: // information 4 
                    info1(exp2, e1);
                    if (exp2 > 200) info2(exp2, e1);
                    break;
                case 80 ... 99: // information 5
                    info1(exp2, e1);
                    info2(exp2, e1);
                    if (exp2 > 400) 
                        {
                        info3(exp2, e1);
                        exp2 = ceil(exp2 + exp2 * 0.15); // when Watson heard all 3 infos
                        limitEXP(exp2);
                        }
                    break;
            }
    // calculate Sherlock's Exp
            exp1 = exp1 - e1;
            limitEXP(exp1);
        }
            else return -99; // out of range e1
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // First Check
    limitHP(HP1);
    limitEXP(EXP1);
    limitM(M1);
    if (E2 < 0 || E2 > 99) return -99; // out of range E2
    float P1, P2, P3;
    int S = 0;
    // Path 1
    // Find P1
    findsqrt(EXP1, S);
    chance(EXP1, S, P1);
    // Path 2
    int counter = 0;
    int charge = 0; // the charge for every event happened
    if (E2 % 2 == 0) // even case (break when M1<=0)
    {
        while (counter<1) // all events only run one time except break condition
        {
        if (M1 == 0) break;
        eat(HP1, M1, charge);
        if (M1 == 0) break;
        wander(EXP1, M1, charge);
        if (M1 == 0) break;
        trust(EXP1, M1, charge);
        if (M1 == 0) break;
        counter += 1;
        }
    }
        else // odd case (break when the charge is higher than 50% of initial M1 (M0) )
    {
        if (M1 != 0) // only do if Money is higher than 0
        {
            int M0 = M1; // save the initial value of M1 to M0
            while (true) // all events will repeat repetitionally until break condition
                {
                    if (charge > M0 * 0.5) break;
                    eat(HP1,M1,charge);
                    if (charge > M0 * 0.5) break;
                    wander(EXP1,M1,charge);
                    if (charge > M0 * 0.5) break;
                    trust(EXP1,M1,charge);
                }
        }
    }
    upstat(EXP1, HP1); // update stat for Sherlock after all events
    // find the P2
    findsqrt(EXP1, S);
    chance(EXP1, S, P2);
    // Path 3
    int i = 0;
    float P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    // find i position of array P
    if (E2 < 10) i = E2; // is already pass the condition
        else i = (E2 % 10 + E2 / 10) % 10; // plus itself
    if (P1 == P2 && P2 == P[i] && P[i] == 100) // when all P are equal 100%
    {
        EXP1 = ceil(EXP1 - EXP1 * 0.25);
        limitEXP(EXP1);
    }
        else
        {
            if (((P1 + P2 + P[i]) / 3) < 50) // the average of them is below 50%
            {
                HP1 = ceil(HP1 - HP1 * 0.15);
                limitHP(HP1);
                EXP1 = ceil(EXP1 + EXP1 * 0.15);
                limitEXP(EXP1);
            }
                else // the average of them is equal or above 50%
                {
                    HP1 = ceil(HP1 - HP1 * 0.1);
                    limitHP(HP1);
                    EXP1 = ceil(EXP1 + EXP1 * 0.2);
                    limitEXP(EXP1);
                }
        }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // First Check
    limitEXP(EXP1);
    limitEXP(EXP2);
    limitHP(HP1);
    limitHP(HP2);
    if (E3 < 0 || E3 > 99) return -99; // out range of E3
    int taxi[10][10] = {0}; // matrix for taxi
    // create the value matrix for taxi
    int i,j; // i for row and j for column
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            taxi[i][j] = ((E3 * j) + (i * 2))*(i - j);
        }
    }
    // find the taxi's position
    int up = 0,down = 0; // up and down will demonstrate i and j
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            if (taxi[i][j] > (E3 * 2)) up++; // the positive one
            if (taxi[i][j] < (0 - E3)) down++; // the negative one
        }
    }
    // plus itself to find position
    while ((up / 10) != 0)
    {
        up = (up % 10 + up / 10);
    }
    while ((down / 10) != 0)
    {
        down = (down % 10 + down / 10);
    }
    // Cross the position
    int max = taxi[up][down];
    // Divide the cross into 4 directions based on the compass
    // North West
    i = up;
    j = down;
    while (true)
    {
        i--;
        j--;
        if ( i < 0 || j < 0) break;
        if(max < taxi[i][j]) max = taxi[i][j];
    }
    // North East
    i = up;
    j = down;
    while (true)
    {
        i--;
        j++;
        if (i < 0 || j > 9) break;
        if(max < taxi[i][j]) max = taxi[i][j];
    }
    // South West
    i = up;
    j = down;
    while (true)
    {
        i++;
        j--;
        if (i > 9 || j < 0) break;
        if(max < taxi[i][j]) max = taxi[i][j];
    }
    // South East
    i = up;
    j = down;
    while (true)
    {
        i++;
        j++;
        if (i > 9 || j > 9) break;
        if(max < taxi[i][j]) max = taxi[i][j];
    }
    // check if they can catch the taxi
    if ( abs(taxi[up][down]) > abs(max)) // cannot catch Taxi
    {
        EXP1 = ceil(EXP1 - EXP1 * 0.12);
        limitEXP(EXP1);
        EXP2 = ceil(EXP2 - EXP2 * 0.12);
        limitEXP(EXP2);
        HP1 = ceil(HP1 - HP1 * 0.1);
        limitHP(HP1);
        HP2 = ceil(HP2 - HP2 * 0.1);
        limitHP(HP2);
        max = taxi[up][down]; // since the value of taxi is higher
    }
    else
    {
        EXP1 = ceil(EXP1 + EXP1 * 0.12);
        limitEXP(EXP1);
        EXP2 = ceil(EXP2 + EXP2 * 0.12);
        limitEXP(EXP2);
        HP1 = ceil(HP1 + HP1 * 0.1);
        limitHP(HP1);
        HP2 = ceil(HP2 + HP2 * 0.1);
        limitHP(HP2);
        // max is not changed since their value is higher than taxi
    }
    return max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100]; // max length 100 characters
    // Find the string in front of @ in email
    const char* location = strchr (email, '@'); 
    int length = location - email;
     // Set special digits
    const char* specialdigit = "!@#$%";
    /// Copy the string founded to se
    strncpy(se, email, length);
    se[length] = '\0';
    // Length check for password need to be checked
    int lengthp = strlen(s); // for the length of password
    if (lengthp < 8)
    {
        return -1; // if it less than 8 char
    } 
    else if (lengthp > 20)
    {
        return -2; // if it more than 20 char
    }
    // Check if the password is included in the email
    const char* sei = strstr(s, se); // find password in se
    if (sei != nullptr)
    {
        return -(300 + (sei - s));
    } 
    // Check if there is a letter is repeated more than twice next to itself
    for (int i = 0; i < lengthp; i++)
    {
        if (s[i] == s[i+1] && s[i] == s[i+2])
        {
            int sci = i;
            return -(400 + sci);  
        }   
    }
    // Check for the special digits
    for (int i = 0; i < lengthp; i++)
    {
        if (strpbrk(s, specialdigit) == nullptr)
        {
            return -5;
        }
    }
    // Check the other cases
    for (int i = 0; i < lengthp; i++)
    {
        char check = s[i];
        if (!(isdigit(check) || islower(check) || isupper(check) || check == '@' || check == '#' || check == '%' || check == '$' || check == '!'))
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Initial declare
    int counter = 0; // for the loop
    int *length = new int[num_pwds](); // for containing the length of each password
    int *freq = new int[num_pwds](); // for containing the frequency of each password 
    // Find the length and frequency of each password
    while (counter < num_pwds)
    { 
        const char * password = arr_pwds[counter]; // typed password
        length[counter] = strlen(password); // length of password is typed
        freq[counter] = 1; // start with frequency equal 1 because all passwords appear at leasts once
        for (int j = counter; j < num_pwds; j++)
        {
            if (strcmp(password, arr_pwds[j]) == 0) freq[counter]++; // Check frequency of each password
        }
        counter++;
    }
    //Reset counter for next loop
    counter = 0;
    // Find the correct password
    int max_length = 0; // max length of the one that maybe the correct one
    int max_freq = 0; // max frequency of the one that maybe the correct one
    int correct_password = 0; // first position of correct one
    while (counter < num_pwds) // loop to check each one
    {
        if (freq[counter] > max_freq)// the one has largest frequency will be the correct password.
        { 
            max_freq = freq[counter];
            max_length = length[counter];
            correct_password = counter;
        }
        else if (freq[counter] == max_freq && length[counter] > max_length)
        // Since there maybe more than one have highest frequency so the longest is the correct
        {
            max_freq = freq[counter];
            max_length = length[counter];
            correct_password = counter;
        }
        counter++;
    }
    return correct_password;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
