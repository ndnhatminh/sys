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

////////////////////////////////////////////////////////////////////////
//========================= HELPER FUNCTIONS ==========================/
////////////////////////////////////////////////////////////////////////
bool isPerfect(int n)
{
    if ((sqrt(n) - floor(sqrt(n))) != 0)
        return false;
    return true;
}
int ClosestPerfectSquare(int xp)
{
    if (xp <= 0)
        return 1;
    
    if (isPerfect(xp)){
        return xp;
    }

    // Variables to store first perfect
    // square number
    // above and below N
    int aboveN = -1, belowN = -1;
    int n1;

    // Finding first perfect square
    // number greater than N
    n1 = xp + 1;
    while (true)
    {
        if (isPerfect(n1)){
            aboveN = n1;
            break;
        }
        else
            n1++;
    }

    // Finding first perfect square
    // number less than N
    n1 = xp - 1;
    while (true)
    {
        if (isPerfect(n1)){
            belowN = n1;
            break;
        }
        else
            n1--;
    }

    // Variables to store the differences
    int diff1 = aboveN - xp;
    int diff2 = xp - belowN;

    if (diff1 > diff2)
        return belowN;
    else
        return aboveN;
}

//HP is in [0,666] range
//EXP is in [0,600] range
//MONEY is in [0,3000] range
const int MAX_HP = 666;
const int MIN_HP = 0;
const int MAX_EXP = 600;
const int MIN_EXP = 0;
const int MAX_MONEY = 3000;
const int MIN_MONEY = 0;

int RegulateEXP(int exp)
{
    return (exp > MAX_EXP) ? MAX_EXP : ((exp < MIN_EXP) ? MIN_EXP : exp);
}
int RegulateHP(int hp)
{
    return (hp > MAX_HP) ? MAX_HP : ((hp < MIN_HP) ? MIN_HP : hp);
}
int RegulateMoney(int m)
{
    return (m > MAX_MONEY) ? MAX_MONEY : ((m < MIN_MONEY) ? MIN_MONEY : m);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    // event code must be valid for the mission to happen
    if (e1 < 0 || e1 > 99) return -99;

    // regulate EXPs to be within bounds
    // in case if the inputs are out of range
    exp1 = RegulateEXP(exp1);
    exp2 = RegulateEXP(exp2);

    if (e1 >= 0 && e1 <= 3){
        // Sherlock begins explaining Watson's life, changing Watson's EXP
        switch (e1){
            //info 1
            case 0:
                exp2 += 29;
                break;
            //info 2
            case 1:
                exp2 += 45;
                break;
            //info 3
            case 2:
                exp2 += 75;
                break;
            //info 1, 2 and 3
            case 3:
                //increases Watson's EXP by 29, 45, and 75 simultaneously
                exp2 += 149;
                break;
            default:
                //do nothing
                break;
        }
        // Sherlock begins his prediction in favor of either 2 countries
        // Afganistan (correct) or Iraq (incorrect)
        int D = e1 * 3 + exp1*7; // Sherlock's Decision:tm:
        // if D is a even number
        if (D % 2 == 0){
            exp1 += ceil(float(D/200));
        }
        // D is an odd number
        else{
            exp1 -= ceilf(float(D/100));
        }       

    // regulate EXPs to be within bounds
    exp1 = RegulateEXP(exp1);
    exp2 = RegulateEXP(exp2);

    return exp1 + exp2;
    }
    else if (e1 >= 4 && e1 <= 99){
        // Sherlock explains why he knows Watson has a brother
        //info 1
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 += (e1/4.0 + 19) + 0.999;
        }

        //info 2
        else if (e1 >= 20 && e1 <= 49)
        { 
            exp2 += (e1/9.0 + 21) + 0.999;
        }
        
        //info 3
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 += (e1/16.0 + 17) + 0.999;
        }
        
        //info 1 and 2
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 += (e1/4.0 + 19) + 0.999;
            if (exp2 > 200)
            {
                exp2 += (e1/9.0 + 21) + 0.999;
            }
        }
        
        //info 1, 2 and 3
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 += (e1/4.0 + 19) + 0.999;

            exp2 += (e1/9.0 + 21) + 0.999;
            
            if (exp2 > 400)
            {
                exp2 += (e1/16.0 + 17) + 0.999;
                //15% XP bonus
                exp2 = exp2 + exp2 * 0.15 + 0.999;
            }
        }

        //reduce Sherlock's EXP
        exp1 -= e1;

        // regulate EXPs to be within bounds
        exp1 = RegulateEXP(exp1);
        exp2 = RegulateEXP(exp2);

        return exp1 + exp2;
    } else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //E3 must be valid for the mission to happen
    if (E2 < 0 || E2 > 99) return -99;

    //set Sherlock's money to be within range in case if the 
    //input exceeds them
    M1 = RegulateMoney(M1);
    EXP1 = RegulateEXP(EXP1);
    HP1 = RegulateHP(HP1);

    // road 1
    int S = ClosestPerfectSquare(EXP1);
    double P1Temp;
    int P1;
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1Temp = ((EXP1/S + 80.0) / 123.0) * 100.0;
        P1 = static_cast<int>(P1Temp);
    }
    
    //road 2
    //number of paid money for comparison
    int paidCash = 0;
    int budget = M1;

    //go through the whole road only once if
    //E2 is even
    if (E2 % 2 == 0)
    {
        //check if Sherlock's HP is less than 200
        if(HP1 < 200 && M1 > 0)
        {
            //restores 30% of HP
            HP1 = ceil(float(HP1 * 1.3));
            M1 -= 150;
            paidCash += 150;
            if (M1 <= MIN_MONEY)
            {
                //reduce Sherlock's HP by 17% and increases his EXP by 17%
                // and set his money to 0
                M1 = MIN_MONEY;
            }
        }
        else if(M1 > 0)
        {
            //restore 10% of HP otherwise
            HP1 = ceil(float(HP1 * 1.1));
            M1 -= 70;
            paidCash += 70;
            if (M1 <= MIN_MONEY)
            {
                M1 = MIN_MONEY;
            }
        }

        //check if Sherlock's EXP is less than 400
        if(EXP1 < 400 && M1 > 0)
        {
            //take a taxi, costs $200
            M1 -= 200;
            paidCash += 200;
            if (M1 <= MIN_MONEY)
            {
                M1 = MIN_MONEY;
            }
        }
        else if(M1 > 0)
        {
            //take the carriage, costs $120
            M1 -= 120;
            paidCash += 120;
            if (M1 <= MIN_MONEY)
            {
                M1 = MIN_MONEY;
            }
        }
        
        //increases Sherlock's EXP by 13% afterwards
        EXP1 = ceil(float(EXP1 * 1.13));

        //check if Sherlock's EXP is less than 300
        if (EXP1 < 300 && M1 > 0)
        {
            //gives $100 to homeless person
            M1 -= 100;
            paidCash += 100;
            if (M1 <= MIN_MONEY)
            {
                M1 = MIN_MONEY;
            }
        }
        //check of Sherlock's EXP is 300 or more
        else if(M1 > 0)
        {
            //gives $120
            M1 -= 120;
            paidCash += 120;
            if (M1 <= MIN_MONEY)
            {
                M1 = MIN_MONEY;
            }
        }
        //reduce Sherlock's HP by 17% and increases his EXP by 17%
        HP1 = ceil(float(HP1 * 0.83));
        EXP1 = ceil(float(EXP1 * 1.17));
    }
    //E2 is odd
    else 
    {
        do
        {
            //check if Sherlock's HP is less than 200
            if(HP1 < 200)
            {
                //restores 30% of HP
                HP1 = ceil(float(HP1 * 1.3));
                M1 -= 150;
                paidCash += 150;
                if (paidCash > (budget/2.0))
                {
                    //break out of the loop if paidCash is greater than half of the inital budget
                    //reduce Sherlock's HP by 17% and increases his EXP by 17%
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }
            else
            {
                //restore 10% of HP otherwise
                HP1 = ceil(float(HP1 * 1.1));
                M1 -= 70;
                paidCash += 70;
                if (paidCash > (budget/2.0))
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }

            //check if Sherlock's EXP is less than 400
            if(EXP1 < 400)
            {
                //take a taxi, costs $200
                M1 -= 200;
                paidCash += 200;
                if (paidCash > (budget/2.0))
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }
            else
            {
                //take the carriage, costs $120
                M1 -= 120;
                paidCash += 120;
                if (paidCash > (budget/2.0))
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }
            
            //increases Sherlock's EXP by 13% afterwards
            EXP1 = ceil(float(EXP1 * 1.13));

            //check if Sherlock's EXP is less than 300
            if (EXP1 < 300)
            {
                //gives $100 to homeless person
                M1 -= 100;
                paidCash += 100;
                if (paidCash > (budget/2.0))
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }
            //check of Sherlock's EXP is 300 or more
            else
            {
                //gives $120
                M1 -= 120;
                paidCash += 120;
                if (paidCash > (budget/2.0))
                {
                    HP1 = ceil(float(HP1 * 0.83));
                    EXP1 = ceil(float(EXP1 * 1.17));
                    break;
                }
            }
            
            //reduces Sherlock's EXP by 10%
            EXP1 = ceil(float(EXP1 * 0.9));

        } while (E2 % 2 == 1); //repeat the process if the event is an odd number
    }

    EXP1 = RegulateEXP(EXP1);
    HP1 = RegulateHP(HP1);
    M1 = RegulateMoney(M1);

    double P2Temp = ((EXP1/S + 80.0) / 123.0)*100.0;
    int P2 = static_cast<int>(P2Temp);

    //route 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;

    //if E3 is a one-digit number, set E3 as index for P[]
    if (E2 < 10) P3 = P[E2];
    //if E3 is 2-digits, calculate sum of 2 digits and use it as index for P[]
    else if (E2 > 10)
    {
        int sum = 0;
        int n = E2;
        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
        //in case if sum is still a 2 digit number
        //and n returns 0
        if (sum > 10)
        {
            n = sum;
            sum = 0;
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
        }
        P3 = P[sum];
    }

    //check if all 3 probabilities of all 3 routes are 100%
    //reduce Sherlock's EXP by 25% if true
    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        double temp = EXP1 - (EXP1 * 0.25);
        if (temp - static_cast<int>(temp) > 0) EXP1 = temp + 1;
    }
    
    //calculate average probability otherwise
    else
    {
        int avgP = (P1 + P2 + P3) / 3;

        //check if the average prob is less than or greater/equal to 50
        if (avgP < 50)
        {
            //reduce Sherlock's HP by 15% and increase his EXP by 15%
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        }
        else if (avgP >= 50)
        {
            //reduce Sherlock's HP by 10% and increase his EXP by 20%
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        }
    }

    //regulate HP and EXP values
    EXP1 = RegulateEXP(EXP1);
    HP1 = RegulateHP(HP1);
    M1 = RegulateMoney(M1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    //check if event code is valid or not
    //before proceeding with the mission
    if (E3 < 0 || E3 > 99) return -99;

    //regulate HP and EXP values
    //in case of out of bounds input
    EXP1 = RegulateEXP(EXP1);
    HP1 = RegulateHP(HP1);
    EXP2 = RegulateEXP(EXP2);
    HP2 = RegulateHP(HP2);

    //map of the taxi chase sequence (10x10)
    //value of each elements represents skill score of taxi at that element
    const int rows = 10, cols = 10;
    int map[rows][cols] = {0};

    //loop calculating the taxi's movement
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //calculate skill scores for Sherlock and Watson
    int max = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //calculate max score from left and right diagonals of taxi's path
            int leftDiag = i + j;
            int rightDiag = cols - 1 - j + i;
            int score = std::max(map[i][leftDiag], map[i][rightDiag]);
            //check if score is negative or positive
            if (score < 0)
            {
                //take absolute value if negative
                score = std::abs(score);
            }
            //update max score
            if (score > max)
            {
                max = score;
            }
        }
    }

    //calculate meeting point of taxi and Sherlock/Watson
    //based on the values on the map
    int MeetPointI = 0, MeetPointJ = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] > E3 * 2)
                MeetPointI++;
            if (map[i][j] < -E3)
                MeetPointJ++;
        }
    }

    //Reduce meeting point to single digits
    if (MeetPointI > 9)
        MeetPointI = MeetPointI % 10 + MeetPointI / 10;
    if (MeetPointJ > 9)
        MeetPointJ = MeetPointJ % 10 + MeetPointJ / 10;
    
    //Compare aboslute values of taxi and Sherlocck/Waton's scores
    int taxiScore = map[MeetPointI][MeetPointJ];
    int result = std::max(taxiScore, max);
    if (result < 0) result = std::abs(result);
    if (std::abs(taxiScore) > max)
    {
        //taxi is not caught
        //decrease EXP by 12% and HP by 10%
        EXP1 *= 0.88;
        EXP2 *= 0.88;
        HP1 *= 0.9;
        HP2 *= 0.9;

        //regulate HP and EXP values
        EXP1 = RegulateEXP(EXP1);
        HP1 = RegulateHP(HP1);
        EXP2 = RegulateEXP(EXP2);
        HP2 = RegulateHP(HP2);
    }
    else
    {
        //taxi is caught
        //increase EXP by 12% and HP by 10%
        EXP1 *= 1.12;
        EXP2 *= 1.12;
        HP1 *= 1.1;
        HP2 *= 1.1;

        //regulate HP and EXP values
        EXP1 = RegulateEXP(EXP1);
        HP1 = RegulateHP(HP1);
        EXP2 = RegulateEXP(EXP2);
        HP2 = RegulateHP(HP2);
    }

    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //string of character before the "@"
    string se;

    //initailise max length for email string 
    int max_email_length = 100;
    if (strlen(email) < 1 || strlen(email) > max_email_length) return -99;

    for (const char *c = email; *c != '@'; ++c)
    {
        se += *c;
    }

    if (se.length() == 0) return -99;
    //initialise max and min length for password string
    int max_pass_length = 20, min_pass_length = 8;

    if (strlen(s) < min_pass_length) return -1;
    if (strlen(s) > max_pass_length) return -2;

    //conditions for password check
    bool WithinRange = false, HasAllowedChars = false;
    bool HasAtLeastOneSpecialChar = false;

    //check password conditions
    //password must be within range of 8 and 20 character
    WithinRange = true;

    //Each char can only be a number, lowercase letter, uppercase letter, or special characters
    //allowed special characters are: '@', '#', '%', '$', '!'.
    for (const char *c = s; *c != '\0'; c++)
    {
        if (isalnum(*c) || *c == '@' || *c == '#' || *c == '%' || *c == '$' || *c == '!')
        {
            HasAllowedChars = true;
            if (*c == '@' || *c == '#' || *c == '%' || *c == '$' || *c == '!')
                HasAtLeastOneSpecialChar = true;
        }
        else
        {
            //returns the position of the invalid char in the string
            return c - s;
        }
    }

    //password must not contain 'se' string
    int pass_length = strlen(s);
    
    //loop iterating through the password string
    for (int i = 0; i <= pass_length - se.length(); ++i) {
        //flag to check if 'se' is found starting at i
        bool found = true;

        //nested loop to compare chars of 'se' with chars of 's'
        for (int j = 0; j < se.length(); ++j) {
            //compare chars of 'se' at j with chars of 's' at (i + j)
            if (s[i + j] != se[j]) {
                //set found as false if the characters don't match
                found = false;
                break;
            }
        }
        // if found then return -(300+<sei>), where <sei> is the first occurrence of se.
        // i is the position of 'se' in 's'.
        if (found) {
            return -(300 + i);
        }
    }

    //password must not contain more than 2 consecutive chars
    //loop iterating through the password string
    for (int i = 0; s[i] != '\0'; ++i)
    {
        //check if the first character is the same as the second character
        if (s[i] == s[i+1] && s[i+1] == s[i+2])
        {
            //return -(400 + <sci>), where <sci> is the first position of the first string
            //containing more than 2 consecutive and identical characters
            return -(400 + i);
        }
    }

    //password must contain at least 1 special character
    if (HasAtLeastOneSpecialChar == false) return -5;

    //final check to see if all of the conditions are met
    if (WithinRange && HasAllowedChars && HasAtLeastOneSpecialChar) return -10;
    else return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //max = maximum occurrance of a password
    //maxLength = maximum length of the correct password
    //(for comparison in case it has the same ammount of occurrance as the other passwords)
    //correctIndex = position of the correct password in the password array
    int max = 0, maxLength = 0, correctIndex = -1;

    for (int i = 0; i < num_pwds; i++)
    {
        //save password at position i into a variable
        const char *currentPass = arr_pwds[i];
        int count = 0;

        //loop counting the occurrance of the saved password
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(currentPass, arr_pwds[j]) == 0) count++;
        }

        //check if the saved password is counted the most
        //or is the longest string
        if (count > max || (count == max && strlen(currentPass) > maxLength))
        {
            //update max and maxLength to compare to the other passwords in the array
            max = count;
            maxLength = strlen(currentPass);
            correctIndex = i;
        }
    }
    return correctIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////