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
void testHP(int& HP)
{

    if (HP > 666)
    {
        HP = 666;
    }
    if (HP < 0)
    {
        HP = 0;
    }
}
void testEXP(int& EXP)
{
    if (EXP > 600)
    {
        EXP = 600;
    }
    if (EXP < 0)
    {
        EXP = 0;
    }
}
void testM(int& M)
{
    if (M > 3000)
    {
        M = 3000;
    }
    if (M < 0)
    {
        M = 0;
    }
}
bool testInteger(int N)
{
    if ((sqrt(N) - floor(sqrt(N))) != 0)
    {
        return false;
    }
    return true;
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {

    if (E1 < 0 || E1 > 99)
    {
        return -99;
    }
    else if (E1 >= 0 && E1 <= 3) //Case 1
    {
            testEXP(EXP1);
            testEXP(EXP2);
        switch (E1)
        {
        case 0: //Info 1
            EXP2 = EXP2 + 29;
            testEXP(EXP2);
            break;
        case 1: //Info 2
            EXP2 = EXP2 + 45;
            testEXP(EXP2);
            break;
        case 2: //Info 3
            EXP2 = EXP2 + 75;
            testEXP(EXP2);
        case 3:
            EXP2 = EXP2 + 29 + 45 + 75;
            testEXP(EXP2);
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
        {
            EXP1 = static_cast<int>(ceil(EXP1 + (float)D / 200)) ;
            testEXP(EXP1);
        }
        else
        {
            EXP1 = static_cast<int>(ceil(EXP1 - (float)D / 100));
            testEXP(EXP1);
        }
        return EXP1 + EXP2;
    }
    else if (E1 >= 4 && E1 <= 99) //Case 2
    {
            testEXP(EXP1);
            testEXP(EXP2);
        if (E1 >= 4 && E1 <= 19) //Info 1
        {
            EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 4 + 19)));
            testEXP(EXP2);
        }
        else if (E1 >= 20 && E1 <= 49) //Info 2
        {
            EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 9 + 21)));
            testEXP(EXP2);
        }
        else if (E1 >= 50 && E1 <= 65) //Info 3
        {
            EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 16 + 17))) ;
            testEXP(EXP2);
        }
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 4 + 19))) ;
            testEXP(EXP2);
            if (EXP2 > 200)
            {
                EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 9 + 21)))  ;
                testEXP(EXP2);
            }
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 4 + 19)));
            testEXP(EXP2);
            EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 9 + 21))) ;
            testEXP(EXP2);
            if (EXP2 > 400)
            {
                EXP2 = static_cast<int>(ceil(EXP2 + ((float)E1 / 16 + 17))) ;
                testEXP(EXP2);
                EXP2 = static_cast<int>(ceil(EXP2 + (float)0.15 * EXP2)) ;
                testEXP(EXP2);
            }
        }
        EXP1 = EXP1 - E1;
        testEXP(EXP1);
        return EXP1 + EXP2;
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    if(E2 <0 || E2 >99)
    {
        return -99;
    }
    else
    {//Road 01
    int S1;
    if (testInteger(EXP1)) {
        S1 = EXP1;
    }
    int above1, below1;
    int n1;
    n1 = EXP1 + 1;
    while (true) {
        if (testInteger(n1)) {
            above1 = n1;
            break;
        }
        else
            n1++;
    }
    n1 = EXP1 - 1;
    while (true) {
        if (testInteger(n1))
        {
            below1 = n1;
            break;
        }
        else
        {
            n1--;
        }
    }
    int diff1 = above1 - EXP1;
    int diff2 = EXP1 - below1;

    if (diff1 > diff2)
    {
        S1 = below1;
    }
    else
    {
        S1 = above1;
    }
    double P1;
    if (EXP1 >= S1)
    {
        P1 = 1.0;
    }
    else
    {
        P1 = ((EXP1 / S1) + 80.0) / 123.0;
    }
    //Road 02
    int paid = 0;
    if (E2 % 2 != 0)
    {
        int M0 = M1;
        while (paid <= (0.5 * M0))
        {
            //Event 1
            if (HP1 < 200)
            {
                HP1 = HP1 + ceil(0.3 * HP1);
                testHP(HP1);
                M1 = M1 - 150;
                testM(M1);
                paid = paid + 150;
            }
            else
            {
                HP1 = HP1 + ceil(0.1 * HP1);
                testHP(HP1);
                M1 = M1 - 70;
                testM(M1);
                paid = paid + 70;
            }
            if (paid > (0.5 * M0))
            {
                break;
            }
            //Event 2
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                testM(M1);
                paid = paid + 200;
            }
            else
            {
                M1 = M1 - 120;
                testM(M1);
                paid = paid + 120;
            }
            EXP1 = EXP1 + ceil(0.13 * EXP1);
            testEXP(EXP1);
            if (paid > (0.5 * M0))
            {
                break;
            }
            //Event 3
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                testM(M1);
                paid = paid + 100;
            }
            else
            {
                M1 = M1 - 120;
                testM(M1);
                paid = paid + 120;
            }
            EXP1 = EXP1 - ceil(0.1 * EXP1);
            testEXP(EXP1);
            if (paid > (0.5 * M0))
            {
                break;
            }
        }
        HP1 = HP1 - 0.17 * HP1 + 0.999;
        testHP(HP1);
        EXP1 = EXP1 + ceil(0.17 * EXP1) ;
        testEXP(EXP1);

    }
    else
    {
        while (M1 != 0)
        {
            //Event 1
            if (HP1 < 200)
            {
                HP1 = HP1 + ceil(0.3 * HP1) ;
                testHP(HP1);
                M1 = M1 - 150;
                testM(M1);
                paid = paid + 150;
            }
            else
            {
                HP1 = HP1 + ceil(0.1 * HP1) ;
                testHP(HP1);
                M1 = M1 - 70;
                testM(M1);
                paid = paid + 70;
            }
            if (M1 == 0)
            {
                break;
            }
            //Event 2
            if (EXP1 < 400)
            {
                M1 = M1 - 200;
                testM(M1);
                paid = paid + 200;
            }
            else
            {
                M1 = M1 - 120;
                testM(M1);
                paid = paid + 120;
            }
            EXP1 = EXP1 + ceil(0.13 * EXP1);
            testEXP(EXP1);
            if (M1 == 0)
            {
                break;
            }
            //Event 3
            if (EXP1 < 300)
            {
                M1 = M1 - 100;
                testM(M1);
                paid = paid + 100;
            }
            else
            {
                M1 = M1 - 120;
                testM(M1);
                paid = paid + 120;
            }
            EXP1 = EXP1 - ceil(0.1 * EXP1);
            testEXP(EXP1);
            if (M1 == 0)
            {
                break;
            }
        }
        HP1 = HP1 - ceil(0.17 * HP1);
        testHP(HP1);
        EXP1 = EXP1 + ceil(0.17 * EXP1) ;
        testEXP(EXP1);
    }
    int S2;
    if (testInteger(EXP1)) {
        S2 = EXP1;
    }
    int above2, below2;
    int n2;
    n2 = EXP1 + 1;
    while (true) {
        if (testInteger(n2)) {
            above2 = n2;
            break;
        }
        else
            n2++;
    }
    n2 = EXP1 - 1;
    while (true) {
        if (testInteger(n2))
        {
            below2 = n2;
            break;
        }
        else
        {
            n2--;
        }
    }
    int diff3 = above2 - EXP1;
    int diff4 = EXP1 - below2;

    if (diff3 > diff4)
    {
        S2 = below2;
    }
    else
    {
        S2 = above2;
    }
    double P2;
    if (EXP1 >= S1)
    {
        P2 = 1.0;
    }
    else
    {
        P2 = ((EXP1 / S2) + 80.0) / 123.0;
    }
    //Road 03
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    float P3;
    if (E2 < 10)
    {
        P3 = P[E2] * 0.01;
    }
    else
    {
        int sum;
        int u = E2 % 10;
        int m = E2 / 10;
        sum = u + m;
        int n = sum % 10;
        P3 = P[n] * 0.01;
    }
    //Summary
    if (P1 == P2 && P2 == P3 && P3 == 1)
    {
        EXP1 = ceil(float(EXP1 - 0.25 * EXP1));
        testEXP(EXP1);
    }
    else
    {
        float P = (P1 + P2 + P3) / 3.0;
        if (P < 0.5)
        {
            HP1 = ceil(float(HP1 - 0.15 * HP1));
            testHP(HP1);
            EXP1 = ceil(float(EXP1 + 0.15 * EXP1));
            testEXP(EXP1);
        }
        else
        {
            HP1 = ceil(float(HP1 - 0.1 * HP1));
            testHP(HP1);
            EXP1 = ceil(float(EXP1 + 0.2 * EXP1));
            testEXP(EXP1);
        }
    }
    return HP1 + EXP1 + M1;}
}



// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    int way[10][10];
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            way[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (way[i][j] > 0 && way[i][j] > (E3 * 2))
            {
                count1 = count1 + 1;
            }
            if (way[i][j] < 0 && way[i][j] < (-E3))
            {
                count2 = count2 + 1;
            }
        }
    }

    while (count1 >= 10)
    {
        int sum1 = 0;
        int m = count1 / 10;
        int n = count1 % 10;
        sum1 = m + n;
        count1 = sum1;
    }

    while (count2 >= 10)
    {
        int sum2 = 0;
        int x = count2 / 10;
        int y = count2 % 10;
        sum2 = x + y;
        count2 = sum2;
    }
    //way[count1][count2] is the meeting location
    int max = way[count1][count2];
    //The left diagonal of the point
    int i = count1;
    int j = count2;
    while (i >= 0 || j >= 0)
    {
        if (way[i][j] > max)
        {
            max = way[i][j];
        }
        i--;
        j--;
    }
    i=count1;
    j=count2;
    while (i <= 9 || j <= 9)
    {
        if (way[i][j] > max)
        {
            max = way[i][j];
        }
        i++;
        j++;
    }
    //The right diagonal of the point
    i=count1;
    j=count2;
    while ( i>= 0 || j <= 9)
    {
        if (way[i][j] > max)
        {
            max = way[i][j];
        }
        i--;
        j++;
    }
    i=count1;
    j=count2;
    while (i <= 9 || j >= 0)
    {
        if (way[i][j] > max)
        {
            max = way[i][j];
        }
        i++;
        j--;
    }
    //Comparision
    if (abs(way[count1][count2]) > max) //Not catched the taxi
    {
        EXP1 = ceilf(EXP1 - 0.12 * EXP1);
        testEXP(EXP1);
        EXP2 = ceilf(EXP2 - 0.12 * EXP2);
        testEXP(EXP2);
        HP1 = ceilf(HP1 - 0.1 * HP1);
        testHP(HP1);
        HP2 = ceilf(HP2 - 0.1 * HP2);
        testHP(HP2);
        return way[count1][count2];
    }
    else //Catched the taxi
    {
        EXP1 = ceilf(EXP1 + 0.12 * EXP1);
        testEXP(EXP1);
        EXP2 = ceilf(EXP2 + 0.12 * EXP2);
        testEXP(EXP2);
        HP1 = ceilf(HP1 + 0.1 * HP1);
        testHP(HP1);
        HP2 = ceilf(HP2 + 0.1 * HP2);
        testHP(HP2);
        return max;
    }
}
// Task 4
int checkPassword(const char* s, const char* email) {
    string str(email);
    string se;
    string special = "@#$%!";
    string pass(s);

    size_t pos = str.find('@');
    if (pos != string::npos) {
        se = str.substr(0, pos);
    }

    if (pass.size() < 8)
    {
        return -1;
    }
    else if (pass.size() > 20)
    {
        return -2;
    }
    if (pass.find(se) != string::npos)
    {
        return -(300 + pass.find(se));
    }
    for (int i = 0; i < pass.size(); i++) {
        if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2]) {
            return -400 + i;
        }
    }
    for (int i = 0; i < pass.size(); i++)
    {
        char c = pass[i];
        if (special.find(c) == string::npos)
        {
            return -5;
        }
    }
    for (int i = 0; i < pass.size(); i++)
    {
        char c = pass[i];
        if (!isalnum(c) && special.find(c) == string::npos)
        {
            return i;
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    const char* pwd_list[30];
    int count_list[30] = { 0 };
    int length_list[30] = { 0 };
    int count = 0;

    for (int i = 0; i < num_pwds; i++) {
        int j;
        for (j = 0; j < count; j++) {
            if (strcmp(pwd_list[j], arr_pwds[i]) == 0) {
                count_list[j]++;
                break;
            }
        }
        if (j == count) {
            pwd_list[count] = arr_pwds[i];
            count_list[count] = 1;
            length_list[count] = strlen(arr_pwds[i]);
            count++;
        }
    }

    int max_count = 0, max_length = 0, correct_index = -1;
    for (int i = 0; i < count; ++i) {
        if (count_list[i] > max_count || (count_list[i] == max_count && length_list[i] > max_length)) {
            max_count = count_list[i];
            max_length = length_list[i];
            correct_index = i;
        }
    }

    const char* correct_pwd = pwd_list[correct_index];

    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correct_pwd) == 0) {
            return i;
        }
    }

    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////