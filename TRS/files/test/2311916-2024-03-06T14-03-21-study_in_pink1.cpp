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
        int &E3
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
    } else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void checkhp(int &hp)
{
    if(hp > 666)
        hp = 666;
    if(hp < 0)
        hp = 0;
}
void checkexp(int &exp)
{
    if(exp > 600)
        exp = 600;
    if(exp < 0)
        exp = 0;
}
void checkm(int &m)
{
    if(m > 3000)
        m = 3000;
    if(m < 0)
        m = 0;
}
bool checke(int e)
{
    if(e > 99 || e < 0)
    {
        return 0;
    }
    return 1;
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    //check e
    if(checke(E1) == 0)
        return -99;
    //case 1
    checkexp(EXP1);
    checkexp(EXP2);
    if(E1 >= 0 && E1 <= 3)
    {
        switch (E1)
        {
        case 0://truong hop 1
            EXP2 += 29;
            break;

        case 1://truong hop 2
            EXP2 += 45;
            break;

        case 2://truong hop 3
            EXP2 += 75;
            break;

        case 3://truong hop 4
            EXP2 += (29 + 45 + 75);
            break;
        }

        long int D;
        D = E1 * 3 + EXP1 * 7;
        if(D % 2 == 0)
        {
            EXP1 = ceil((EXP1+ D/200.0)-0.0000001);
        }
        else
        {
            EXP1 = ceil( (EXP1 - D/100.0) - 0.0000001);
        }
    }
    else //case 2
    {
        if(E1 >= 4 && E1 <= 19)//truong hop 1
        {
            EXP2 += ceil(((E1 /4.0) - 0.0000001) + 19);
        }

        if(E1 >= 20 && E1 <= 49)//truong hop 2
        {
            EXP2 += ceil(((E1 /9.0) - 0.0000001) + 21);
        }

        if(E1 >= 50 && E1 <= 65)//truong hop 3
        {
            EXP2 += ceil(((E1 /16.0) - 0.0000001) + 17);
        }
        
        if(E1 >= 66 && E1 <= 79)//truong hop 4
        {
            EXP2 += ceil(((E1 /4.0) - 0.0000001) + 19);
            if(EXP2 > 200)
                EXP2 += ceil(((E1 /9.0) - 0.0000001) + 21);
        }

        if(E1 >= 80 && E1 <= 99)//truong hop 5
        {
            EXP2 += ceil(((E1 /4.0) - 0.0000001) + 19);
            EXP2 += ceil(((E1 /9.0) - 0.0000001) + 21);

            if(EXP2 > 400)
            {
                EXP2 += ceil(((E1 /16.0) - 0.0000001) + 17);
                EXP2 = ceil(EXP2*1.15 - 0.0000001);
            }
        }
        EXP1 -= E1;
    }
    checkexp(EXP1);
    checkexp(EXP2);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //check e
    if(checke(E2)==0)
        return -99;
    //check hp
    checkhp(HP1);
    //check exp
    checkexp(EXP1);
    //check m 
    checkm(M1);
    
    //Road 1
    int S1;
    float P1;
    S1 = pow(round(sqrt(EXP1)),2);
    if(EXP1 >= S1)
    {
        P1 = 1.0;
    }
    else
    {
        P1 = (((EXP1/S1) + 80.0) / 123.0);
    }

    //Road 2
    int initial_money = M1/2;
    int money = 0; //used money
    if(M1!=0)
    {
        if(E2 % 2 == 1) 
        {
            while(money <= initial_money) 
            {
        //eating
                if(HP1 < 200)
                {
                    HP1 = ceil((HP1*1.3) - 0.00000001);
                    M1 -= 150;
                    money += 150;
                }
                else
                {
                    HP1 = ceil((HP1*1.1) - 0.00000001);
                    M1 -= 70;
                    money += 70;
                }
                checkhp(HP1);
                checkm(M1);
                if(money > initial_money)
                    break;

        //transporting
                if(EXP1 < 400)
                {
                    M1 -= 200;
                    money += 200;
                }
                else
                {
                    M1 -= 120;
                    money += 120;
                }
                EXP1 = ceil((EXP1*1.13) - 0.00000001);
                checkexp(EXP1);
                checkm(M1);
                if(money > initial_money)
                    break;

        //meeting homeless
                if(EXP1 < 300)
                {
                    M1 -= 100;
                    money += 100;
                }
                else
                {
                    M1 -= 120;
                    money += 120;
                }
                EXP1 = ceil((EXP1*0.9) - 0.00000001);
                checkexp(EXP1);
                checkm(M1);
                if(money > initial_money)
                    break;
            }
            HP1 = ceil((HP1 * 0.83) - 0.00000001);
            checkhp(HP1);
            EXP1 = ceil((EXP1 * 1.17) - 0.00000001);
            checkexp(EXP1);
        }
        else
        {
        //eating
        if(M1>0)
        {
        if(HP1 < 200)
        {
        HP1 = ceil((HP1*1.3) - 0.00000001);
        M1 -= 150;
        }
        else
        {
        HP1 = ceil((HP1*1.1) - 0.00000001);
        M1 -= 70;
        }
        }
        checkhp(HP1);
        checkm(M1);
        //transporting
        if(M1>0)
        {
        if(EXP1 < 400)
        {
        M1 -= 200;
        }
        else
        {
        M1 -= 120;
        }
        EXP1 = ceil((EXP1*1.13) - 0.00000001);
        }
        checkexp(EXP1);
        checkm(M1);
        //meeting homeless
        if(M1>0)
        {
        if(EXP1 < 300)
        {
        M1 -= 100;
        }
        else
        {
        M1 -= 120;
        }
        EXP1 = ceil((EXP1*0.9) - 0.00000001);
        }
        checkexp(EXP1);
        checkm(M1);
        HP1 = ceil((HP1 * 0.83) - 0.00000001);
        checkhp(HP1);
        EXP1 = ceil((EXP1 * 1.17) - 0.00000001);
        checkexp(EXP1);
        }
    } 
    else
    {
    HP1 = ceil((HP1 * 0.83) - 0.00000001);
    checkhp(HP1);
    EXP1 = ceil((EXP1 * 1.17) - 0.00000001);
    checkexp(EXP1);
    }
    int S2;
    S2 = pow(round(sqrt(EXP1)),2);
    float P2;
    if(EXP1 >= S2)
    {
        P2 = 1.0;
    }
    else
    {
        P2 = (((EXP1/S2) + 80.0) / 123.0);
    }

    //Road 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};//given by the question
    int i = 0;
    if((E2 / 10) != 0)
    {
        i = ((E2 / 10) + (E2 % 10)) % 10;
    }
    else i = E2;
    float P3 = P[i] / 100.0;

    //conclusion
    float avgP = (P1 + P2 + P3) / 3.0;
    if(P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = ceil((EXP1 * 0.75) - 0.00000001);
    }
    else if(avgP < 0.5)
    {
        HP1 = ceil((HP1 * 0.85) - 0.00000001);
        EXP1 = ceil((EXP1 * 1.15) - 0.00000001);
    }
    else
    {
        HP1 = ceil((HP1 * 0.90) - 0.00000001);
        EXP1 = ceil((EXP1 * 1.20) - 0.00000001);
    }
    checkexp(EXP1);
    checkhp(HP1);
    return  M1 + HP1 + EXP1;
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //check e
    if(checke(E3) == 0)
        return -99;

    checkhp(HP1);
    checkhp(HP2);
    checkexp(EXP1);
    checkexp(EXP2);
    //make matrix
    int arr[10][10] = {};
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    //find i j
    int i1 = 0;
    int j1 = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(arr[i][j] > (E3 * 2))
                i1++;
            if(arr[i][j] < -E3 )
                j1++;
        }
    }
    while(i1 >= 10)
    {
        i1 = ((i1 / 10) + (i1 % 10));
    }
    while(j1 >= 10)
    {
        j1 = ((j1 / 10) + (j1 % 10));
    }
    //taxi
    int taxi = arr[i1][j1];
    //Sherlock and Watson
    int right_d = i1 + j1;
    int left_d = i1 - j1;
    int SW = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if( i + j == right_d || i - j == left_d)
            {
                int num = arr[i][j];
                if(num > SW)
                    SW = num;
            }
        }
    }

    //compare
    if(abs(taxi) > SW)
    {
        EXP1 = ceil((EXP1) * 0.88 - 0.000000001);
        EXP2 = ceil((EXP2) * 0.88 - 0.000000001);
        HP1 = ceil((HP1) * 0.9 - 0.000000001);
        HP2 = ceil((HP2) * 0.9 - 0.000000001);
        return taxi;
    }
    else
    {
        EXP1 = ceil((EXP1) * 1.12 - 0.000000001);
        EXP2 = ceil((EXP2) * 1.12 - 0.000000001);
        HP1 = ceil((HP1) * 1.1 - 0.000000001);
        HP2 = ceil((HP2) * 1.1 - 0.000000001);
        checkexp(EXP1);
        checkexp(EXP2);
        checkhp(HP1);
        checkhp(HP2);
        return SW;
    }
}

// Task 4
int checkpass(string s, string se)
{
    // Check if password length is more than 20
    if(s.length() > 20)
        return -2;

    // Check if password length is less than 8
    if(s.length() < 8)
        return -1;

    // Check if password contains the email substring
    if(s.find(se) < s.length())
        return -300 - s.find(se);

    // Check for more than two consecutive identical characters
    for(int i = 0; i < s.length() - 2; i++)
    {
        if(s[i] == s[i+1] && s[i] == s[i+2]) // Changed condition to check for more than two consecutive identical characters
            return -400 - i;
    }

    // Check for at least one special character
    bool hasSpecialChar = false;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 33 || (s[i] >= 35 && s[i] <= 37) || s[i] == 64 || s[i] == 36) // Added checks for '@' and '$'
            hasSpecialChar = true;
    }
    if(!hasSpecialChar && s.length() >= 8)
        return -5;

    // Check for valid characters in password
    for(int i = 0; i < s.length(); i++) // Changed from s.length() - 2 to s.length()
    {
        if((s[i] >= 48 && s[i] <= 57) || // Added check for numbers
           (s[i] >= 65 && s[i] <= 90) || 
           (s[i] >= 97 && s[i] <= 122) || 
           s[i] == 33 || 
           (s[i] >= 35 && s[i] <= 37) || 
           s[i] == 64 || 
           s[i] == 36)
            continue;
        else return i;
    }

    // If all checks pass, return -10 indicating a valid password
    return -10;
}




// Wrapper function to convert C-style strings to C++ strings and call the checkPasswordValidity function
int checkPassword(const char * s, const char * email) {
    string _email = email;
    string se;
    string _s = s;

    // Extract the substring before '@' in the email
    se = _email.substr(0,_email.find('@'));

    // Check the validity of the password
    return checkpass(_s, se);
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int number[num_pwds] = {0};//times the password appear
    string pass[num_pwds] = {" "};//string to write down pass with the same max appearance
    for(int i = 0; i < num_pwds; i++)//finding the times that the pass appear
    {
        for(int j = 0; j <= i; j++)
        {
            if(arr_pwds[i] == arr_pwds[j])
            {
                number[j]++;
                break;
            }
        }
    }

    int num_max = 0;//max time they appear
    for(int i = 0; i < num_pwds; i++)
        {
            if(number[i] > num_max)
            {
                num_max = number[i];
            }
        }

    for(int i = 0; i < num_pwds; i++)//which of them appear
    {
        if(num_max == number[i])
            pass[i] = arr_pwds[i];
    }

    int index = 0, length = 0;//compare there length if they have the same amount of time
    for(int i = 0; i < num_pwds - 1; i++)
    {
        if(pass[i].length() > length)
            {
                index = i;
                length = pass[i].length();
            }
    }
    //return the value
    return index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////