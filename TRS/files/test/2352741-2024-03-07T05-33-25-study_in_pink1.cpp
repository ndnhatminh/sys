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
int checkHP(int HP){
    if (HP < 0)
    {
        HP = 0;
    } else if (HP > 666)
    {
        HP = 666;
    } 
    return HP;
}
int checkEXP(int exp){
    if (exp < 0)
    {
        exp = 0;
    } else if (exp > 600)
    {
        exp = 600;
    } 
    return exp;
}
int checkM(int M){
    if (M < 0)
    {
        M = 0;
    } else if (M > 3000)
    {
        M = 3000;
    } 
    return M;
}
int NearestSquare(int N){
    if ((sqrt(N) - floor(sqrt(N))) == 0)
    {
        return N;
    } else
    {
        int N1 = sqrt(N);
        int below_diff = N - (N1*N1), above_diff = ((N1+1)*(N1+1)) - N;
        if (below_diff > above_diff)
        {
            return ((N1+1)*(N1+1));
        } else
        {
            return (N1*N1);
        }
    }
}
int sumOfDigits(int n) {
    while (n >= 10) 
    {
        n = (n/10) + (n % 10);
    }
    return n;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    // TODO: Complete this function
    if (e1 >= 0 && e1 <=3) //case 1
    {
        switch (e1)
        {
        case 0: //info 1
            exp2 += 29;
            break;
        case 1: //info 2
            exp2 += 45;
            break;
        case 2: //info 3
            exp2 += 75;
            break;
        case 3: //info 4
            exp2 += (29 + 45 + 75);
            break;
        }
        int D = e1*3 + exp1*7; //decision integer
        float exp1_float;
        if (D % 2)
        {
            exp1_float = float(exp1) - float(D)/100;
        } else {
            exp1_float = float(exp1) + float(D)/200;
        }
        exp1 = ceil(exp1_float);
        exp1 = checkEXP(exp1);
        exp2 = checkEXP(exp2);
        return exp1 + exp2;
    } 
    else if (e1 >= 4 && e1 <= 19) // case 2: info 1
    {
        exp2 += ceil((float(e1)/4.0f + 19));
    } 
    else if (e1 >= 20 && e1 <= 49) //info 2
    {
        exp2 += ceil((float(e1)/9.0f + 21));
    } 
    else if (e1 >= 50 && e1 <= 65) //info 3
    {
        exp2 += ceil((float(e1)/16.0f + 17));
    } 
    else if (e1 >= 66 && e1 <= 79) //info 4
    {
        exp2 += ceil((float(e1)/4.0f + 19));
        if (exp2 > 200) //sherlock interpret info 2
        {
            exp2 += ceil((float(e1)/9.0f + 21));
        } 
    } 
    else if (e1 >= 80 && e1 <= 99) //info 5
    {
        exp2 += ceil((float(e1)/4.0f + 19));
        exp2 += ceil((float(e1)/9.0f + 21));
        if (exp2 > 400) //sherlock interpret info 3
        {
            exp2 += ceil((float(e1)/16.0f + 17));
            exp2 += ceil(exp2*1.15f); //bonus 15% when all 3 info is interpreted
        } 
    } else {
        return -99;
    }
    exp1 -= e1;   // sherlock mistake
    exp1 = checkEXP(exp1);
    exp2 = checkEXP(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    HP1 = checkHP(HP1);
    EXP1 = checkEXP(EXP1);
    M1 = checkM(M1);
    int S = NearestSquare(EXP1); //probability of route 1
    float P1 = 0;
    if (EXP1 >= S) //route 1
    {
        P1 = 1;
    } else
    {
        P1 = (float(EXP1/S) + 80.0f)/123.0f;
    }
    int paid_money = 0; //Route 2
    int start_money = M1;
    while (true) //repeat when E2 is odd
    {
        if (E2 % 2) //E2 is odd
        {
            if (HP1 < 200) //first event
            {
                HP1 = ceil(HP1*1.3f);
                HP1 = checkHP(HP1);
                M1 -= 150; // buy food
                paid_money += 150;
                M1 = checkM(M1);
            } else
            {
                HP1 = ceil(HP1*1.1f);
                HP1 = checkHP(HP1);
                M1 -= 70; //buy water
                paid_money += 70;
                M1 = checkM(M1);
            }
            if (paid_money >= ceil(0.5f*start_money)) //stop condition
                break;
            if (EXP1 < 400) //second event
            {
                M1 -= 200; 
                paid_money += 200;
                M1 = checkM(M1);
            } else
            {
                M1 -= 120;
                paid_money += 120;
                M1 = checkM(M1);
            }
            EXP1 = ceil(EXP1*1.13f);
            EXP1 = checkEXP(EXP1);
            if (paid_money >= ceil(0.5f*start_money)) //stop condition
                break;
            if (EXP1 < 300) //third event
            {
                M1 -= 100;
                paid_money += 100;
                M1 = checkM(M1);
            } else 
            {
                M1 -= 120;
                paid_money += 120;
                M1 = checkM(M1);
            }
            EXP1 = ceil(EXP1*0.9f);
            EXP1 = checkEXP(EXP1);
            if (paid_money >= ceil(0.5f*start_money)) //stop condition
                break;
        } else // E2 is even
        {
            if (HP1 < 200) //first event
            {
                HP1 = ceil(HP1*1.3);
                HP1 = checkHP(HP1);
                M1 -= 150; // buy food
                M1 = checkM(M1);
            } else
            {
                HP1 = ceil(HP1*1.1f);
                HP1 = checkHP(HP1);
                M1 -= 70; //buy water
                M1 = checkM(M1);
            }
            if (M1 == 0) //stop condition
                break;
            if (EXP1 < 400) //second event
            {
                M1 -= 200; // taxi
                M1 = checkM(M1);
            } else
            {
                M1 -= 120; //horse
                M1 = checkM(M1);
            }
            EXP1 = ceil(EXP1*1.13);
            EXP1 = checkEXP(EXP1);
            if (M1 == 0) //stop condition
                break;
            if (EXP1 < 300) //third event
            {
                M1 -= 100;
                M1 = checkM(M1);
            } else 
            {
                M1 -= 120;
                M1 = checkM(M1);
            }
            EXP1 = ceil(EXP1*0.9);
            EXP1 = checkEXP(EXP1);
            break; //always stop after one round
        }
    }
    HP1 = ceil(HP1*0.83); //walk to end of road
    HP1 = checkHP(HP1);
    EXP1 = ceil(EXP1*1.17);
    EXP1 = checkEXP(EXP1);
    int S2 = NearestSquare(EXP1); //probability of route 2
    float P2;
    if (EXP1 >= S2) 
    {
        P2 = 1;
    } else
    {
        P2 = (float(EXP1/S2) + 80.0f)/123.0f;
    }
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; //route 3
    float P3;
    if (E2 < 10) //find probability of route 3
    {
        int i = E2;
        P3 = float(P[i])/100.0f;
    } else
    {
        int i = ((E2/10) + (E2 % 10)) % 10;
        P3 = float(P[i])/100.0f;
    }
    cout << P1 << " " << P2 << " " << P3 << endl;
    if (P1 == 1 && P2 == 1 && P3 == 1) // mistake
    {
        EXP1 = ceil(0.75*EXP1);
    } else // average probability
    {
        float P_avg = (P1 + P2 + P3)/3.0f;
        if (P_avg < 0.5)
        {
            HP1 = ceil(0.85*HP1);
            HP1 = checkHP(HP1);
            EXP1 = ceil(1.15*EXP1);
            EXP1 = checkEXP(EXP1);
        } else
        {
            HP1 = ceil(0.9*HP1);
            HP1 = checkHP(HP1);
            EXP1 = ceil(1.2*EXP1);
            EXP1 = checkEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    HP1 = checkHP(HP1);
    HP2 = checkHP(HP2);
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);

    int taxi_map[10][10]; //initialize 10x10 matrix
    int i_points = 0, j_points = 0; //use to count 
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            taxi_map[i][j] = ((E3 * j) + (i * 2)) * (i - j); //taxi's score
            if (taxi_map[i][j] > (E3*2))
            {
                i_points ++;
            } else if (taxi_map[i][j] < (-E3))
            {
                j_points ++;
            }
        }
    }
    int a = sumOfDigits(i_points);
    int b = sumOfDigits(j_points);

    int SW_score = taxi_map[a][b]; // set their score at the meeting point
    for (int i = a - min(a,b), j = b - min(a,b); i < 10 && j < 10; i++, j++ )// left diagonal: start searching from top left
    {
        if (taxi_map[i][j] > SW_score)
        {
            SW_score = taxi_map[i][j];
        }
    } 
    for (int i = a - min(a, 10 - b - 1), j = b + min(a, 10 - b - 1); i < 10 && j < 10; i++, j-- )// right diagonal: start searching from top right
    {
        if (taxi_map[i][j] > SW_score)
        {
            SW_score = taxi_map[i][j];
        }
    } 
    if (SW_score >= abs(taxi_map[a][b])) //condition for catching the taxi
    {
        EXP1 = ceil(1.12f*EXP1);
        EXP2 = ceil(1.12f*EXP2);
        HP1 = ceil(1.1f*HP1);
        HP2 = ceil(1.1f*HP2);
        HP1 = checkHP(HP1);
        HP2 = checkHP(HP2);
        EXP1 = checkEXP(EXP1);
        EXP2 = checkEXP(EXP2);
        return SW_score;
    } else 
    {
        EXP1 = ceil(0.88f*EXP1);
        EXP2 = ceil(0.88f*EXP2);
        HP1 = ceil(0.9f*HP1);
        HP2 = ceil(0.9f*HP2);
        HP1 = checkHP(HP1);
        HP2 = checkHP(HP2);
        EXP1 = checkEXP(EXP1);
        EXP2 = checkEXP(EXP2);
        return taxi_map[a][b];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //find se
    const char * pos = strchr(email,'@'); // find position of the @ character and returns a pointer
    char se[100]; //Allocate memory 
    if (pos != nullptr)
    {
        size_t length = pos - email; //the length of the substring from the position of @ to the start of the email string
        strncpy(se, email, length); //copy "length" characters from email into se
        se[length] = '\0'; //Null character added to terminate the string
    }
    if (strlen(s) < 8) // length shorten than minimum length
    {
        return -1;
    } else if (strlen(s) > 20)// length longer than maximum length
    {
        return -2;
    } else if (strstr(s,se) != nullptr) // s contains se
    {
        return -(300 + (strstr(s,se) - s));
    }
    int ccs = 1; //use to count consecutive characters
    bool hasSpecialChar = false;
    int nonValidChar = 999;
    for (int i = 0; i < strlen(s); i++) 
    {
        if (s[i] == s[i + 1]) 
        {
            ccs++;
            if (ccs > 2) // if more than 2 consecutive characters are identical
            {
                return -(400 + i - 1); // i - 1 is the first appearance of the violation
            }
        } else 
        {
            ccs = 1;
        }
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            hasSpecialChar = true;
        }
        if (!((s[strlen(s) - i - 1] >= 'a' && s[strlen(s) - i - 1] <= 'z') || 
       (s[strlen(s) - i - 1] >= 'A' && s[strlen(s) - i - 1] <= 'Z') ||
       (s[strlen(s) - i - 1] >= '0' && s[strlen(s) - i - 1] <= '9') || 
        s[strlen(s) - i - 1] == '!' ||
        s[strlen(s) - i - 1] == '@' ||
        s[strlen(s) - i - 1] == '#' ||
        s[strlen(s) - i - 1] == '$' ||
        s[strlen(s) - i - 1] == '%'))
        {
            nonValidChar = strlen(s) - i - 1; // position of the non valid character
        }
    }
    if (!hasSpecialChar) // check if the password has special characters
    {
        return -5;
    } else if (nonValidChar <= strlen(s) - 1)
    {
        return nonValidChar;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[100], int num_pwds) {
    int correctIndex = -1; //index to return
    int mostFreq = 0; //store most frequently occuring passes
    int maxLength = 0; //store the longest length passes

    for (int i = 0; i < num_pwds; i++)
    {
        const char * currentP = arr_pwds[i];
        int currentF = 1; //store frequency of current password
        int currentL = strlen(currentP); //store length of current password
        for (int j = i + 1; j < num_pwds; j++) // second loop to compare all the next passwords with the current one
        {
            if (strcmp(arr_pwds[j],currentP) == 0) // if the 2 passes are identical then strcmp returns 0
            {
                currentF++;
            }
        }
        if ((currentF > mostFreq) || (currentF == mostFreq && currentL > maxLength))
        {
            mostFreq = currentF;
            maxLength = currentL;
            correctIndex = i;
        }
    }
    return correctIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////