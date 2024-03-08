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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    if (e1 >= 0 && e1 <= 3)
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
            exp2 += (29 + 45 + 75);
            break;
        default:
            return -99;
        }
        int decision = e1 * 3 + exp1 * 7;
        exp2 = std::max(0, std::min(600, exp2));

        if (decision % 2 == 0)
        {
            exp1 = (exp1 + decision / 200) + ((exp1 + decision) % 200 > 0);
        }
        else
        {
             exp1 = (exp1 - decision / 100) + ((exp1 - decision) % 100 > 0);
        }
        exp1 = std::max(0, std::min(600, exp1));
    }
   else if (e1 >= 4 && e1 <= 99)
{
    
    if (e1 >= 4 && e1 <= 19)
    {
        exp2 = ceil(exp2 + (e1 / 4.0 + 19));
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2 = (ceil)(exp2 + (e1 / 9.0 + 21));
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp2 = (ceil)(exp2 + (e1 / 16.0 + 17));
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = (ceil)(exp2 + (e1 / 4.0 + 19));

        if (exp2 > 200)
        {
            exp2 = (ceil)(exp2 + (e1 / 9.0 + 21));
        }
    }
    else
    {
        exp2 = (ceil)(exp2 + (e1 / 4.0 + 19));

        exp2 = (ceil)(exp2 + (e1 / 9.0 + 21));

        if (exp2 > 400)
        {
            exp2 = (ceil)(exp2 + (e1 / 16.0 + 17));
            exp2 = (ceil)(exp2 + exp2 *0.15);
        }
    }

    exp1 -= e1;

    exp1 = std::max(0, std::min(600, exp1));
    exp2 = std::max(0, std::min(600, exp2));
}
 
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    float P1, P2, P3;
    //CHANG DUONG 1
    int num1 = static_cast<int>(std::round(std::sqrt(EXP1)));
    int S1 = num1*num1;
    if (EXP1 >= S1) 
    {
        P1 = 1.00;
    } else {
        P1 = (EXP1/S1 + 80.0)/123.0;
    }
    
    //CHANG DUONG 2
    int M1_shopping;
    
    /// TRUONG HOP E2 LA SO LE
    int M1_start = ceil(0.5 * M1);
    bool completed_event = false;
    if (E2 % 2 == 1){
    
    for(int num = 0; !completed_event;) {
        if (HP1 < 200)
        {
        M1_shopping = M1 - 150;
        num += 150;
        if (M1_shopping > 0 && M1_start >= num) {
            M1 = M1_shopping;
            HP1 = ceil(HP1 + 0.3*HP1);
        } else if (M1_shopping > 0 && M1_start < num )
        {
            M1 = M1_shopping;
            HP1 = ceil(HP1 + 0.3*HP1);
            completed_event = true;
            break;
        }
            else
        {
            M1 = 0;
            HP1 = ceil(HP1 + 0.3*HP1);
            completed_event = true;
            break;
        }
        HP1 = std::max(0, std::min(666, HP1));
            
        } else {
            M1_shopping = M1 - 70;
            num += 70;
            if (M1_shopping > 0 && M1_start >= num) 
            {
                M1 = M1_shopping;
                HP1 = ceil(HP1 + 0.1*HP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                HP1 = ceil(HP1 + 0.1*HP1);
                completed_event = true;
                HP1 = std::max(0, std::min(666, HP1));
                break;
            }
                else
            {
                M1 = 0;
                HP1 = ceil(HP1 + 0.1*HP1);
                completed_event = true;
                HP1 = std::max(0, std::min(666, HP1));
                break;
            }
            HP1 = std::max(0, std::min(666, HP1));
        }

        if (EXP1 < 400){
            
            M1_shopping = M1 - 200;
            num += 200;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
        } else {
            M1_shopping = M1 - 120;
            num += 120;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }

        if (EXP1 < 300){
            M1_shopping = M1 - 100;
            num += 100;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        } else {
            M1_shopping = M1 - 120;
            num += 120;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }
    }
    HP1 = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1);

    EXP1 = std::max(0, std::min(600, EXP1));
    HP1 = std::max(0, std::min(666, HP1));
    
} 
 
//TRUONG HOP E2 LA SO CHAN
    else {
    bool keepwalking = true;
    if (HP1 < 200)
        {
        M1_shopping = M1 - 150;
        if (M1_shopping > 0) {
            M1 = M1_shopping;
            HP1 = ceil(HP1 + 0.3*HP1);
        } 
            else
        {
            M1 = 0;
            HP1 = ceil(HP1 + 0.3*HP1);
            
            keepwalking = false;
        }
        HP1 = std::max(0, std::min(666, HP1));
            
        } else{
            M1_shopping = M1 - 70;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                HP1 = ceil(HP1 + 0.1*HP1);
            } 
                else
            {
                M1 = 0;
                HP1 = ceil(HP1 + 0.1*HP1);
                keepwalking = false;
            }
            HP1 = std::max(0, std::min(666, HP1));
        }

        if (keepwalking && EXP1 < 400){
            
            M1_shopping = M1 - 200;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                
                keepwalking = false;
            }
        } else if (keepwalking && EXP1 >= 400) {
            M1_shopping = M1 - 120;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                
                keepwalking = false;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }

        if (keepwalking && EXP1 < 300){
            M1_shopping = M1 - 100;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                
                keepwalking = false;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        } else if (keepwalking && EXP1 >= 300) {
            M1_shopping = M1 - 120;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }

    HP1 = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1);

    EXP1 = std::max(0, std::min(600, EXP1));
    HP1 = std::max(0, std::min(666, HP1));
}


    int num2 = static_cast<int>(std::round(std::sqrt(EXP1)));
    int S2 = num2*num2;
    if (EXP1 >= S2) 
    {
        P2 = 1.00;
    } else {
        P2 = (EXP1/S2 + 80.0)/123.0;
    }

    //CHANG DUONG 3
   float P[] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sumDigits = (E2 / 10) + (E2 % 10);
        i = sumDigits % 10;
    }
    P3 = P[i];
    if (P1 == 1 && P2 == 1 && P3 == 1) {
   
    EXP1 = ceil(EXP1 - 0.25 * EXP1);

    EXP1 = std::max(0, std::min(600, EXP1));
    
} else {
    
    float avgProbability = (P1 + P2 + P3) / 3.00;

    if (avgProbability < 0.50) {
        HP1 = ceil(HP1 - 0.15 * HP1);
        EXP1 = ceil(EXP1 + 0.15 * EXP1);

        EXP1 = std::max(0, std::min(600, EXP1));
        HP1 = std::max(0, std::min(666, HP1));
    } else {
        HP1 = ceil(HP1 - 0.10 * HP1);
        EXP1 = ceil(EXP1 + 0.20 * EXP1);

        EXP1 = std::max(0, std::min(600, EXP1));
        HP1 = std::max(0, std::min(666, HP1));
    }
}   

    return HP1 + EXP1 + M1;
}
    

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
   
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }

    int taxi_arr[10][10] = {0};

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            
            taxi_arr[i][j] =  ((E3 * j) + (i * 2))* (i - j);
        }
    }
     
    int iCount = 0;
    int iGreeter = E3 * 2;
    for(int i = 0; i < 10; i++)
    {
        for(int j =0 ; j <10 ; j++)
        {
            if(taxi_arr[i][j] > iGreeter)
            {
                iCount++;
            }
        }
    }
    while(iCount >= 10)
    {
        int sum = 0;
        while(iCount != 0)
        {
            sum += iCount%10;
            iCount /= 10;
        }
        iCount = sum;
    }
   
    int jCount = 0;
    int jSmaller = -E3;
    for(int i = 0; i < 10; i++)
    {
        for(int j =0 ; j <10 ; j++)
        {
            if(taxi_arr[i][j] < jSmaller)
            {
                jCount++;
            }
        }
    }
    while(jCount >= 10)
    {
        int sum = 0;
        while(jCount != 0)
        {
            sum += jCount%10;
            jCount /= 10;
        }
        jCount = sum;
    }
   
    int sherlockNWatsonPoint = taxi_arr[iCount][jCount];
    if (jCount > iCount){
        int j = jCount - iCount;
        for(int i = 0; i < 10; ++i) 
        {
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);
            
            ++j;
            if(j == 10)
            {
                break;
            }
        }
    }

    if (iCount > jCount){
        int i = iCount - jCount;
        for(int j = 0; j < 10; ++j)
        {
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);
            
            ++i;
            if(i == 10)
            {
                break;
            }
        }
    }
    if ((iCount + jCount) < 9){
        int j = iCount + jCount;
        for(int i = 0; i < 10; ++i)
        {
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);

            --j;
            if(j == -1)
            {
                break;
            }
        }
    }

    if ((iCount + jCount) > 9){
        int i = ((iCount + jCount )/10 + (iCount + jCount)%10);
        for(int j = 9; j > 0; --j)
        {
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);

            i++;
            if(i == 10)
            {
                break;
            }
        }
    }
    
    if(sherlockNWatsonPoint <0)
    {
        sherlockNWatsonPoint = -sherlockNWatsonPoint;
    }

    int result = 0;
    int absTaxi = taxi_arr[iCount][jCount];
    if (absTaxi < 0)
    {
        absTaxi = -absTaxi;
    }
    
    if (sherlockNWatsonPoint >= absTaxi)
    {
        EXP1 = 1.12*EXP1 + 0.999;
        EXP1 = std::max(0, std::min(600, EXP1));

        HP1 = 1.1*HP1 + 0.999;
        HP1 = std::max(0, std::min(666, HP1));

        EXP2 = 1.12*EXP2 + 0.999;
        EXP2 = std::max(0, std::min(600, EXP2));

        HP2 = 1.1*HP2 + 0.999;
        HP2 = std::max(0, std::min(666, HP2)); 
        result = sherlockNWatsonPoint;
    }
    else
    {
        EXP1 = 0.88*EXP1 + 0.999;
        EXP1 = std::max(0, std::min(600, EXP1));

        HP1 = 0.9*HP1 + 0.999;
        HP1 = std::max(0, std::min(666, HP1));

        EXP2 = 0.88*EXP2 + 0.999;
        EXP2 = std::max(0, std::min(600, EXP2));

        HP2 = 0.9*HP2 + 0.999;
        HP2 = std::max(0, std::min(666, HP2));
        result = taxi_arr[iCount][jCount];
    }

     return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[101];
    int i = 0;
    while (email[i] != '@') {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;

    const char *found = strstr(s, se);
    if (found != NULL) {
        int sei = found - s;
        return -(300 + sei);
    }

    for (i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            int start = i;
            while (i < len - 1 && s[i] == s[i + 1]) {
                i++;
            }
            return -(400 + start);
        }
    }

    bool hasSpecialChar = false;
    for (i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;


    for (i = 0; i < len; i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' ||
              s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int correctIndex = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char *password = arr_pwds[i];
        int count = 1; 

        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(password, arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > maxCount || (count == maxCount && strlen(password) > maxLength)) {
            maxCount = count;
            maxLength = strlen(password);
            correctIndex = i;
        }
    }

    return correctIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////