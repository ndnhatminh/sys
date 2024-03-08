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
inline int checkInRange(int lastNum, int &num)
{
    if (num <= 0)
        num = 0;
    else if (num > lastNum)
        num = lastNum;
    return num;
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    
    if (e1 < 0 || e1 > 99)
        return -99;

    checkInRange(600, exp1);
    checkInRange(600, exp2);

    if (e1 == 0)
    {
        exp2 += 29;
    }
    else if (e1 == 1)
    {
        exp2 += 45;
    }
    else if (e1 == 2)
    {
        exp2 += 75;
    }
    else if (e1 == 3)
    {
        exp2 += 149;
    }   

    checkInRange(600, exp1);
    checkInRange(600, exp2);
   
    if (e1 <= 3 && e1 >= 0)
    {
        int d = e1 * 3 + exp1 * 7;
        float d1 = d;
        if (d % 2 == 0)
        {
            exp1 =  ceil( exp1 -1e-7 + d*1.0f/200);
        }
        else
        {
            exp1 =  ceil( exp1 -1e-7 - d*1.0f/100);
        }
    }
   
    checkInRange(600, exp1);
    checkInRange(600, exp2);

    if (e1 >= 4 && e1 <= 19)
    {
        exp2 = ceil(exp2 - 1e-7 + e1*1.0f/4 ) ;
        exp2 += 19;
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2 = ceil(exp2 -1e-7+ e1*1.0f/ 9  ) ;
        exp2 += 21;
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp2 = ceil(exp2 -1e-7 + e1*1.0f / 16 ) ;
        exp2 += 17;
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = ceil(exp2 -1e-7 + e1*1.0f / 4 ) ;
        exp2 += 19;

        if (exp2 > 200)
        {
            exp2 = ceil(exp2 -1e-7 + e1*1.0f / 9 ) ;
            exp2 += 21;
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp2 = ceil( exp2 -1e-7 +e1*1.0f / 4 ) ;
        exp2 += 19;

        exp2 = ceil( exp2 -1e-7 +e1*1.0f / 9 ) ;
        exp2 +=21;
        
        if (exp2 > 400)
        {
            exp2 = ceil( exp2 -1e-7 +e1*1.0f / 16 ) ;
            exp2 += 17;

            exp2 = ceil(exp2 -1e-7 + exp2*1.0f /100 * 15 );
            
        }
    }

    checkInRange(600, exp1);
    checkInRange(600, exp2);
    if (e1 > 3)
    {
        exp1 -= e1;
    }
    checkInRange(600, exp1);

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    float pTong = 0;
    if (E2 < 0 || E2 > 99)
        return -99;
    checkInRange(666, HP1);
    checkInRange(600, EXP1);
    checkInRange(3000, M1);
    // road 1

    float p1;
    int a = round(sqrt(EXP1));
    int aaa = a * a;

    if ((aaa) <= EXP1)
        p1 = 1.00;
    else
        p1 = ((float)EXP1 / (aaa) + 80) / 123;

    // road 2
    if (E2 % 2 != 0)
    {
        float tongChi = 0;
        float nuatien = (float)M1*0.5;
        
        while (tongChi <= nuatien && M1 !=0)
        {
            if (HP1 < 200)
            {
                HP1 = std::ceil(HP1*1.3- 1e-9);
                M1 -= 150;
                tongChi += 150;
            }
            else
            {
                HP1 = std::ceil(HP1*1.1 - 1e-9);
                M1 -= 70;
                tongChi += 70;
            }
            checkInRange(666, HP1);
            checkInRange(3000, M1);
            if (tongChi > nuatien) break;
            if (EXP1 < 400)
            {
                M1 -= 200;
                tongChi += 200;              
                EXP1 = std::ceil(EXP1*1.13 - 1e-9);
            }
            else
            {
                M1 -= 120;
                tongChi += 120;             
                EXP1 = std::ceil(EXP1*1.13 - 1e-9);
            }
            checkInRange(3000, M1);
            checkInRange(600, EXP1);
            if (tongChi > nuatien) break;            
            if (EXP1 < 300)
            {
                M1 -= 100;
                tongChi += 100;
                EXP1 = std::ceil(EXP1*0.9 - 1e-9);
            }
            else
            {
                M1 -= 120;
                tongChi += 120;
                EXP1 = std::ceil(EXP1*0.9 - 1e-9);
            }
            checkInRange(3000, M1);
        }
    }
        // so chan e2
    else
    {    
        do{
            if (M1 == 0) break;
            if (HP1 < 200)
            {
                HP1 = std::ceil(HP1*1.3 - 1e-9);
                M1 -= 150;
            }
            else
            {
                HP1 = std::ceil(HP1*1.1 - 1e-9);
                M1 -= 70;
            }
            checkInRange(666, HP1);
            checkInRange(3000, M1);
            if (M1 == 0) break;
            if (EXP1 < 400)
            {
                M1 -= 200; 
                EXP1 = std::ceil(EXP1*1.13 - 1e-9);
            }
            else
            {
                M1 -= 120; 
                EXP1 = std::ceil(EXP1*1.13 - 1e-9);
            }
            checkInRange(3000, M1);
            checkInRange(600, EXP1);
            if (M1 == 0) break;
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = std::ceil(EXP1*0.9 - 1e-9);
            }
            else if (EXP1 > 300)
            {
                M1 -= 120;              
                EXP1 = std::ceil(EXP1*0.9 - 1e-9);
            }
            checkInRange(3000, M1);
        } while(false);
    }   
    HP1 = std::ceil(HP1*0.83 - 1e-9);
    EXP1 = std::ceil(EXP1*1.17 - 1e-9);
    checkInRange(600, EXP1);

    float p2 = 0;
    a = round(sqrt(EXP1));
    aaa= a*a;

    if (aaa <= EXP1)
        p2 = 1.00;
    else
        p2 = (float)(EXP1 / aaa + 80) / 123;
    // road 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3 = 0;
    if (E2 < 10 && E2 >= 0)
    {
        p3 = (float)P[E2]/100;
    }
    else
    {
        p3 = (float)P[(E2/10+E2%10)%10]/100;
    }
    if (p1 == 1.00 && p2 == 1.00 && p3 == 1.00)
    {
        EXP1 = std::ceil(EXP1*0.75 - 1e-9);
    }
    else
    {
        pTong = (p1 + p2 + p3) / 3;
        if (pTong < 0.50)
        {
            HP1 = std::ceil(HP1*0.85 - 1e-9);
            EXP1 = std::ceil(EXP1*1.15 - 1e-9);
        }
        else
        {
            HP1 = std::ceil(HP1*0.9 - 1e-9);
            EXP1 = std::ceil(EXP1*1.2 - 1e-9);
        }
    }
    checkInRange(600, EXP1);

    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
        return -99;
        checkInRange(666, HP1);
        checkInRange(666, HP2);
        checkInRange(600, EXP1);
        checkInRange(600, EXP2);
    int Map[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int soI = 0;
    int soJ = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (Map[i][j] > E3 * 2)
                soI++;
            if (Map[i][j] < -E3)
                soJ++;
        }
    }
    int firstNum1_task3 = 0;
    int SecNum1_task3 = 0;
    while (soI >= 10)
    {
        firstNum1_task3 = soI / 10;
        SecNum1_task3 = soI % 10;
        soI = firstNum1_task3 + SecNum1_task3;
    }
    while (soJ >= 10)
    {
        firstNum1_task3 = soJ / 10;
        SecNum1_task3 = soJ % 10;
        soJ = firstNum1_task3 + SecNum1_task3;
    }   
    int x = soI;
    int y = soJ;
    int array1[18];
    int numm = 0;
    while (x >= 0 && y >= 0)
    {
        array1[numm] = Map[x][y];
        x--;
        y--;
        numm++;
    }
    x = soI + 1;
    y = soJ + 1;
    while (x < 10 && y < 10)
    {
        array1[numm] = Map[x][y];
        x++;
        y++;
        numm++;
    }
    x = soI-1;
    y = soJ+1;
    while (x >= 0 && y < 10)
    {
        array1[numm] = Map[x][y];
        x--;
        y++;
        numm++;
    }
    x = soI + 1;
    y = soJ - 1;
    while (x < 10 && y >= 0)
    {
        array1[numm] = Map[x][y];
        x++;
        y--;
        numm++;
    }
    int bigg = array1[0];
    for (int i = 1; i < numm; i++)
    {
        if (bigg < array1[i])
            bigg = array1[i];
    }
    if (bigg >= abs(Map[soI][soJ]))
    {
        EXP1 = ceil(EXP1 * 1.12 - 0.000001);
        HP1 = ceil(HP1 * 1.1 - 0.000001);
        EXP2 = ceil(EXP2 * 1.12 - 0.000001);
        HP2 = ceil(HP2 * 1.1 - 0.000001);

    }
    else
    {
        EXP1 = ceil(EXP1 * 0.88 - 0.000001);
        HP1 = ceil(HP1 * 0.9 - 0.000001);
        EXP2 = ceil(EXP2 * 0.88 - 0.000001);
        HP2 = ceil(HP2 * 0.9 - 0.000001);
    }
        checkInRange(666, HP1);
        checkInRange(666, HP2);
        checkInRange(600, EXP1);
        checkInRange(600, EXP2);
    if (bigg >= abs(Map[soI][soJ]))
    {
          return bigg   ;
    }else   return  Map[soI][soJ];
}
// Task 4
int checkPassword(const char *s, const char *email) {
    int pasMin = 8;
    int pasMax = 20;
    int pasleng = strlen(s);

   
    string seii = "";
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            break;
        }
        seii += email[i];
    }

    
    if (pasleng < pasMin) {
        return -1;
    } else if (pasleng > pasMax) {
        return -2;
    }

    
    int seipoint = 99;
    std::string ss = s;
    for (int i = 0; i <= ss.length() - seii.length(); ++i) {
        int j=0;
        for (j =0; j < seii.length(); ++j) {
            if (ss[i + j] != seii[j]) {
                break;  
            }
        }
        if (j == seii.length()) {
            seipoint = i;  
            break;
        }
    }

    int doublepoint = 99;
    for (int i = 0; i < pasleng - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            doublepoint = i;
            return -(400 + i);
        }
    }

    int specialpoint = 99;
    for (int i = 0; i < pasleng; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            specialpoint = i;
            break;  
        }
    }

    for (int i = 0; i < pasleng; i++) {
        if (s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}') {
            return i;
        }
    }
 
    if(specialpoint ==99) return -5;
    if (doublepoint < seipoint && doublepoint != 99) {
        return -(400 + doublepoint);
    } else if (seipoint != 99 && seipoint < doublepoint) {
        return -(300 + seipoint);
    }
    
    return -10;
}
// Task 5
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: implement task
    int maxcount = 0;
    int maxleng = 0;

    string pass = " ";
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (i == j)
                continue;
            if (arr_pwds[i] == arr_pwds[j])
                count++;
        }
        if (count > maxcount || count == maxcount && strlen(arr_pwds[i]) > maxleng)
        {
            maxcount = count;
            maxleng = strlen(arr_pwds[i]);
            pass = arr_pwds[i];
        }
    }

    int point = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] == pass)
        {
            point = i;
            break;
        }
    }
   
    return point;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////