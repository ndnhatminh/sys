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

int max_val1(int (*arr)[10], int i, int j)
{
    int result = (*arr)[j];
    // left diagonal going up
    int b = j - 1;
    int start_r = 0;
    int max_left = (*arr + j)[i];
    int max_right = (*arr + j)[i];

    for (int a = i - 1; a >= 0 && b >= 0; a--)
    {
        if (max_left < arr[a][b])
        {
            max_left = arr[a][b];
        }
        b--;
    }
    b = j;
    for (int a = i; a <= 9 && b <= 9; a++)
    {
        if (max_left < arr[a][b])
        {
            max_left = arr[a][b];
        }
        b++;
    }
    b = j - 1;
    for (int a = i + 1; a <= 9 && b >= 0; a++)
    {
        if (max_right < arr[a][b])
        {
            max_right = arr[a][b];
        }
        b--;
    }

    b = j + 1;
    for (int a = i - 1; a >= 0 && b <= 9; a--)
    {
        if (max_right < arr[a][b])
        {
            max_right = arr[a][b];
        }
        b++;
    }

    result = max_right;
    if (max_left > max_right)
    {
        result = max_left;
    }

    return result;
}

int fceil(double num)
{
    int result = num;
    int nint = num;
    float zero = (int)num - num;
    if (zero == 0)
        return result;
    else
    {
        result = ceil(num);
    }
    return result;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    float exp1f = exp1, exp2f = exp2, e1f = e1;
    if (e1f >= 0 && e1f <= 3)
    {
        switch (e1)
        {
        case 3:
        {
            exp2f = set(3, exp2f + 29 + 45);
        }
        case 2:
        {
            exp2f = set(3, exp2f + 30);
        }
        case 1:
        {
            exp2f = set(3, exp2f + 16);
        }
        case 0:
        {
            exp2f = set(3, exp2f + 29);
        }
        }
        int D = e1f * 3 + exp1f * 7;
        float Df = D;
        bool is_even = (D % 2 == 0);
        if (is_even)
        {

            exp1f = set(3, exp1f + fceil(Df / 200));
        }
        else
        {
            exp1f = set(3, fceil(exp1f - Df / 100));
        }
    }
    else if (e1f >= 4 && e1f <= 19)
    {
        exp2f = set(3, fceil(exp2f + e1f / 4 + 19)); // explain info 1
            exp1f = exp1f - e1f; // Harriet is the sister

    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2f = set(3, exp2f + fceil(e1f / 9 + 21)); // explain info 2
            exp1f = exp1f - e1f; // Harriet is the sister

    }
    else if (e1f >= 50 && e1f <= 65)
    {
        exp2f = set(3, fceil(exp2f + e1f / 16 + 17)); // explain info 3
        cout << exp2f << endl;
            exp1f = exp1f - e1f; // Harriet is the sister

    }
    else if (e1f >= 66 && e1f <= 79)
    {                                               // CASE 1 AND 2
        exp2f = set(3, fceil(exp2f + e1f / 4 + 19)); // explain info 1
        if (exp2f > 200)
        {
            exp2f = set(3, fceil(exp2f + e1f / 9 + 21)); // explain info 2
        }
            exp1f = exp1f - e1f; // Harriet is the sister

    }
    else if (e1f >= 80 && e1f <= 99)
    {                                               // ALL 3 CASES
        exp2f = set(3, fceil(exp2f + e1f / 4 + 19)); // explain info 1

        exp2f = set(3, fceil(exp2f + e1f / 9 + 21)); // explain info 2
        if (exp2f > 400)
        {
            exp2f = set(3, fceil(exp2f + e1f / 16 + 17)); // explain info 3
        }
        exp2f = set(3, (int)fceil(exp2f * 1.15)); // explain all 3 information
            exp1f = exp1f - e1f; // Harriet is the sister

    }
    else
    {
        return -99;
    }
    exp1 = exp1f;
    exp2 = exp2f;
    return exp1f + exp2f;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    int half_M1_begin = 0;
    float HP1f = HP1;
    float P_arr[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float Prob = 0;
    int num = 0;

    int money_spent = 0;
    float M1f = M1;
    float P1 = 0, P2 = 0, P3 = 0; // P is probability to find luggage
    float EXP1f = EXP1 ;
    bool flag_found = false; // flag to recalculate or not
try_again:
    // THE FIRST PATH
    if (EXP1 >= find_nearest(EXP1))
    {
        P1 = 100;
    }
    else
    {
        P1 = (EXP1f / find_nearest(EXP1) + 80) / 123;
    }
// THE SECOND PATH
    half_M1_begin = fceil(M1f / 2);

path2:
    
    if (M1 != 0) // EVENT 1
    {
        if (HP1 < 200)
        { // BUY FOOD AND DRINK
            HP1 = set(2, fceil(HP1 * 1.3));
            M1 = set(1, M1 - 150);
            money_spent = money_spent + 150;
        }
        else
        {
            HP1 = set(2, fceil(HP1 * 1.1));
            M1 = set(1, M1 - 70);
            money_spent = money_spent + 70;
        }
    }
    if (money_spent > half_M1_begin)
    { // if money spent is larger than half of the starting money then walk
        HP1 = set(2, fceil(HP1 * 0.83));
        EXP1 = set(3, fceil(EXP1 * 1.17));
        goto path3;
    }

    if (M1 != 0) // EVENT 2
    {
        if (EXP1 < 400)
        {
            M1 = set(1, M1 - 200); // CHOOSE TAXI
            money_spent += 200;
        }
        else
        {
            M1 = set(1, M1 - 120); // CHOOSE HORSE
            money_spent += 120;
        }
        EXP1 = set(3, fceil(EXP1 * 1.13)); // EXP1 INCREASE AFTER TAKING TAXI OR HORSE
    }
    if (money_spent > half_M1_begin)
    { // if money spent is larger than half of the starting money then walk
        HP1 = set(2, fceil(HP1 * 0.83));
        EXP1 = set(3, fceil(EXP1 * 1.17));
        goto path3;
    }

    if (M1 != 0) //EVENT 3
    {
        if (EXP1 < 300)
        {
            M1 = set(1, M1 - 100);
            money_spent += 100;
        }
        else
        {
            M1 = set(1, M1 - 120);
            money_spent += 120;
        }
        EXP1 = set(3, fceil(EXP1 * 0.9)); // EXP1 DECREASE AFTER HELPING HOMELESS PPL
    }
    if (money_spent > half_M1_begin)
    { // if money spent is larger than half of the starting money then walk
        HP1 = set(2, fceil(HP1 * 0.83));
        EXP1 = set(3, fceil(EXP1 * 1.17));
        goto path3;
    }

    
    if (E2 % 2 == 1)
    {
        if(M1==0) goto path3 ;
        else goto path2 ;
        
        
        
    }
    else
    {
        HP1 = set(2, fceil(HP1 * 0.83));
        EXP1 = set(3, fceil(EXP1 * 1.17));
        goto path3;
    }
    
// THE THIRD PATH
path3:
    EXP1f = EXP1 ;
    if (EXP1 >= find_nearest(EXP1))
    {
        P2 = 100;
    }
    else
    {
        P2 = (EXP1f / find_nearest(EXP1) + 80) / 123;
    }
    if (E2 < 10 && E2 >= 0)
    {
        P3 = P_arr[E2] / 100;
    }
    else if (E2 > 9 && E2 < 100)
    {
        num = E2 / 10 + E2 % 10;
        num = num % 10;
        P3 = P_arr[num] / 100;
    }

    // END OF 3 PATH
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = set(3, fceil(EXP1 * 0.75)); // giảm EXP sherlock và tính toán lại (đi lại các cung đường)
        goto try_again;
    }
    else
    {
        Prob = (P1 + P2 + P3) / 3;
    }
    if (Prob < 0.5)
    {
        HP1 = set(2, fceil(HP1 * 0.85));              // decrease HP1 15%
        EXP1 = set(3, EXP1 + fceil(EXP1 / 100 * 15)); // increase EXP1 15%
    }
    else
    {
        HP1 = set(2, fceil(HP1 * 0.9));   // decrease HP1 10%
        EXP1 = set(3, fceil(EXP1 * 1.2)); // increase EXP1 20%
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this funct
    int num;
    int arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }


    int arrSher[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int number = max_val1(arr, i, j);
            arrSher[i][j] = number;
        }
    }



    int count_l = E3 * 2;
    int count_pos = 0, count_neg = 0;
    int neg = -E3;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] > count_l)
            {
                count_pos++;
            }
            if (arr[i][j] < neg)
            {
                count_neg++;
            }
        }
    }


    int row = count_pos / 10 + count_pos % 10;
    int col = count_neg / 10 + count_neg % 10;
    if(row>9) row = row / 10 + row % 10;
    if(col>9) col = col / 10 + col % 10;
    int taxi_p = arr[row][col];
    int guy_p = arrSher[row][col];
    if (abs(taxi_p) > abs(guy_p))
    {
        EXP1 = set(3, fceil(EXP1 * 0.88));
        HP1 = set(2,fceil(HP1 * 0.9));

        EXP2 = set(3, fceil(EXP2 * 0.88));
        HP2 = set(2, fceil(HP2 * 0.9));
    }
    else
    {
        EXP1 = set(3,fceil(EXP1 * 1.12));
        HP1 = set(2,fceil(HP1 * 1.1));

        EXP2 = set(3, fceil(EXP2 * 1.12));
        HP2 = set(3, fceil(HP2 * 1.1));
    }

    return (abs(taxi_p) > abs(guy_p))? taxi_p : guy_p;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    char const at[2] = "@";
    string s_cpy = "";
    string se = "";
    int size_e = strlen(email);
    int size_s = strlen(s);
    int i = 0;
    while (email[i] != '\0')
    {
        if (email[i] == *at)
        {
            break;
        }

        se += email[i];
        i++;
    }
    string s1 = s;
    int sei = s1.find(se);
    if (size_s < 8)
    {
        return -1;
    }
    else if (size_s > 20)
    {
        return -2;
    }
    else if (sei > -1)
    {
        return -(300 + sei);
    }
    else if (duplicate(s) != -1)
    {
        int sci = duplicate(s);
        return -(400 + sci);
    }
    else if (!contain_S(s))
    {
        return -5;
    }
    else if (contain_other(s) != -1)
    {
        int index = contain_other(s);
        return index;
    }

    cout << se << endl;
    cout << s << endl;
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int size = num_pwds;

    string arr[num_pwds];
    int rep[size];
    int idx = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        bool flag = true;
        const char *current_pwd = arr_pwds[i];
        for (int a = 0; a < size; a++)
        {
            if (current_pwd == arr[a])
            {
                flag = false;
            }
        }
        if (flag)
        {
            arr[idx] = current_pwd;

            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (current_pwd == arr_pwds[j])
                {
                    count++;
                }
            }
            rep[idx] = count;
            idx++;
        }
    }
    size = idx;
    int max = rep[0];
    string max_string = arr[0];
    for (int b = 0; b < size; b++)
    {
        if (rep[b] == max)
        {
            int s1 = max_string.length(), s2 = arr[b].length();
            if (s1 < s2)
            {
                max = rep[b];
                max_string = arr[b];
            }
        }
        else if (rep[b] > max)
        {
            max = rep[b];
            max_string = arr[b];
        }
    }

    int id;
    for (int i = 0; i < num_pwds; i++)
    {
        if (max_string == arr_pwds[i])
        {
            id = i;
            break;
        }
    }

    return id;
}

int set(int id, float num)// 1 - money, 2 - HP, 3 - EXP
{ 
    if (id == 3)
    { // SET EXP
        if (num > 600)
        {
            num = 600;
        }
        else if (num < 0)
        {
            num = 0;
        }
    }
    else if (id == 2)
    { // SET HP
        if (num > 666)
        {
            num = 666;
        }
        else if (num < 0)
        {
            num = 0;
        }
    }
    else if (id == 1)
    { // SET MONEY
        if (num > 3000)
        {
            num = 3000;
        }
        else if (num < 0)
        {
            num = 0;
        }
    }
    return num;
}

int find_nearest(int EXP)
{
    int i = 0;
    int num1 = i * i;
    int num2 = (i + 1) * (i + 1);
    while (!(num1 < EXP && num2 > EXP))
    {
        i++;
        num1 = num2;
        num2 = i * i;
    }
    if (abs(num2 - EXP) > abs(num1 - EXP))
    {
        return num1;
    }
    else
        return num2;
}

int contain_other(const char *s)
{
    int size = strlen(s);
    for (int i = 0; i < size; i++)
    {
        if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == *"@" || s[i] == *"!" || s[i] == *"#" || s[i] == *"$" || s[i] == *"%")
        {
        }
        else
        {
            return i;
            break;
        }
    }
    return -1;
}

int duplicate(string s)
{
    bool found = false;
    int idx = -1;
    char current_char = s[0];
    int size = s.length();
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        if (s[i] == current_char)
        {
            count++;
            idx = i;
            if (count == 2)
            {
                idx = i - 2;
                found = true;
                break;
            }
        }
        else
        {
            count = 0;
            current_char = s[i];
        }
    }
    if (found)
        return idx;
    else
        return -1;
}

bool contain_S(string s)
{
    int size = s.length();
    int find1 = s.find("@");
    int find2 = s.find("#");
    int find3 = s.find("%");
    int find4 = s.find("$");
    int find5 = s.find("!");
    if (find1 > -1 || find2 > -1 || find3 > -1 || find4 > -1 || find5 > -1)
    {
        return true;
    }
    else
        return false;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////