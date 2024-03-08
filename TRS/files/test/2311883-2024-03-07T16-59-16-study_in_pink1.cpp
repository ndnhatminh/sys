#include "study_in_pink1.h"
using namespace std; bool readFile(
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
    // This function is used to  read the input file,
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
int Find_S(int n);
int valid_value_M(int n)
{
    if (n < 0) return 0;
    if (n > 3000) return 3000;
    else return n;
}
int valid_value_HP(int n)
{
    if (n < 0) return 0;
    if (n > 666) return 666;
    else return n;
}
int valid_value_EXP(int n)
{
    if (n < 0) return 0;
    if (n > 600) return 600;
    else return n;
}
// Task 1//luu y lam task 2 thi sua lai cho ham firstmeet k hoat dong
int firstMeet(int& exp1, int& exp2, int e1) {
    if (e1 < 0 || e1>99) return -99;
    // TODO: Complete this function
    exp1 = valid_value_EXP(exp1);
    exp2 = valid_value_EXP(exp2);

    if (e1 == 0)
    {
        exp2 += 29;
        exp2 = valid_value_EXP(exp2);
    }
    else if (e1 == 1)
    {
        exp2 += 45;
        exp2 = valid_value_EXP(exp2);
    }

    else if (e1 == 2)
    {
        exp2 += 75;
        exp2 = valid_value_EXP(exp2);
    }
    else if (e1 == 3)
    {
        exp2 += 149;
        exp2 = valid_value_EXP(exp2);
    }
    //xet D chan le
    if (0 <= e1 && e1 <= 3)
    {
        int D = e1 * 3 + exp1 * 7;
        //Check that D even or odd
        if (D % 2 == 0) // Afghanistan
        {
            exp1 = ceil((float)exp1 + float(D) / 200);
            exp1 = valid_value_EXP(exp1);

        }
        else // Iraq 
        {
            exp1 = ceil((float)exp1 - float(D) / 100);
            exp1 = valid_value_EXP(exp1);
        }
    }
    if (4 <= e1 && e1 <= 19)
    {
        exp2 = ceil((float)exp2 + 19 + float(e1) / 4);
        exp2 = valid_value_EXP(exp2);
    }
    else if (20 <= e1 && e1 <= 49)
    {
        exp2 = ceil((float)exp2 + 21 + float(e1) / 9);
        exp2 = valid_value_EXP(exp2);
    }
    else if (50 <= e1 && e1 <= 65)
    {
        exp2 = ceil((float)exp2 + 17 + float(e1) / 16);
        exp2 = valid_value_EXP(exp2);
    }
    else if (66 <= e1 && e1 <= 79)
    {
        exp2 = ceil((float)exp2 + 19 + float(e1) / 4);
        exp2 = valid_value_EXP(exp2);
        if (exp2 > 200)
        {
            exp2 = ceil((float)exp2 + 21 + float(e1) / 9);
            exp2 = valid_value_EXP(exp2);
        }
    }
    else if (80 <= e1 && e1 <= 99)
    {
        exp2 = ceil((float)exp2 + 19 + float(e1) / 4);
        exp2 = valid_value_EXP(exp2);
        exp2 = ceil((float)exp2 + 21 + float(e1) / 9);
        exp2 = valid_value_EXP(exp2);
        if (exp2 > 400)
        {
            exp2 = ceil((float)exp2 + 17 + float(e1) / 16);
            exp2 = valid_value_EXP(exp2);
            exp2 = ceil((float)exp2 * 1.15);
            exp2 = valid_value_EXP(exp2);
        }
    }
    if (4 <= e1 && e1 <= 99) exp1 -= e1;
    exp1 = valid_value_EXP(exp1);


    return exp1 + exp2;
}

// Task 2 //luu y lam task 2 thi sua lai cho ham firstmeet k hoat dong
//Ham tim S gan EXP1 nhat :
int Find_S(int n);
int position(int n);
int p(int EXP, int S)
{
    float x= (80 + float(EXP) / float(S)) / 123;
    if (EXP >= S) return 1;
    else return x;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    float p1, p2, p3;
    HP1 = valid_value_HP(HP1);
    EXP1 = valid_value_EXP(EXP1);
    M1 = valid_value_M(M1);
    int cost = 0;
    float half_of_M1 = float(M1 / 2);
    int S1 = Find_S(EXP1);
    if (EXP1 >= S1) p1 = 1; else p1 = (80 + float(EXP1) / float(S1)) / 123;
    
    //way2
    if (E2 % 2 != 0) //ODD OR EVEN
        //ODD
    {
        while (cost <= half_of_M1 && M1 != 0)
        {
            
                //ACT 1 
                if (HP1 < 200)
                {
                    HP1 = ceil(float(HP1 * 1.3));
                    HP1 = valid_value_HP(HP1);
                    M1 -= 150;
                    M1 = valid_value_M(M1);
                    cost += 150;
                    cout << cost << endl;
                }
                else
                {
                    HP1 = ceil(float(HP1 * 1.1));
                    HP1 = valid_value_HP(HP1);
                    M1 -= 70;
                    M1 = valid_value_M(M1);
                    cost += 70;
                }
                //to do ACT 2, we need to make sure that cost < half_of_M1
                if (cost <= half_of_M1)
                {
                    //ACT2 take TAXI or HORSE
                    if (EXP1 < 400)//Ttake TAXI
                    {
                        M1 -= 200;
                        M1 = valid_value_M(M1);
                        cost += 200;
                        cout << cost << endl;
                    }
                    else //take HORSE
                    {
                        M1 -= 120;
                        M1 = valid_value_M(M1);
                        cost += 120;
                    }
                    EXP1 = ceil(float(EXP1 * 1.13));
                    EXP1 = valid_value_EXP(EXP1);
                    //to do ACT 3, we need to make sure that cost < half_of_M1
                    if (cost <= half_of_M1)
                    {
                        //trust or follow homeless
                        if (EXP1 < 300)
                        {
                            M1 -= 100;
                            M1 = valid_value_M(M1);    //trust
                            cost += 100;
                            cout << cost << endl;
                        }
                        else
                        {
                            M1 -= 120;
                            M1 = valid_value_M(M1);
                            cost += 120;
                        }
                        EXP1 = ceil(float(EXP1 * 0.9));
                        EXP1 = valid_value_EXP(EXP1);
                    }
                }            
        }//UPDATE HP1 & EXP1

        HP1 = ceil(float(HP1 * 0.83));
        HP1 = valid_value_HP(HP1);
        EXP1 = ceil(float(EXP1) * 1.17);
        EXP1 = valid_value_EXP(EXP1);
    }
    else // EVEN
    {
        if (M1 > 0)
        {
            //act1
            if (HP1 < 200)
            {
                HP1 = ceil(float(HP1 * 1.3));
                HP1 = valid_value_HP(HP1);
                M1 -= 150;
                M1 = valid_value_M(M1);
                
            }
            else
            {
                HP1 = ceil(float(HP1 * 1.1));
                HP1 = valid_value_HP(HP1);
                M1 -= 70;
                M1 = valid_value_M(M1);
            }
            //to do act2, we need to make sure that M1>0
            if (M1 > 0)
            {
                //ACT 2
                if (EXP1 < 400)//Take TAXI
                {
                    M1 -= 200;
                    M1 = valid_value_M(M1);
                }
                else //take HORSE
                {
                    M1 -= 120;
                    M1 = valid_value_M(M1);
                }
                EXP1 = ceil(float(EXP1 * 1.13));
                EXP1 = valid_value_EXP((float)EXP1);
                //TO DO ACT3 WE NEED TO MAKE SURE THAT M1>0
                if (M1 > 0)
                {
                    //trust or follow homeless
                    if (EXP1 < 300)
                    {
                        M1 -= 100;
                        M1 = valid_value_M(M1);//TRUST
                    }
                    else
                    {
                        M1 -= 120;
                        M1 = valid_value_M(M1);
                    }
                    EXP1 = ceil(float(EXP1 * 0.9)); 
                    EXP1 = valid_value_EXP(EXP1);                    
                }
            }          
        }
        //UPDATE HP1 && EXP1
        HP1 = ceil(float(HP1 * 0.83));
        HP1 = valid_value_HP(HP1);
        EXP1 = ceil(float(EXP1 * 1.17));
        EXP1 = valid_value_EXP(EXP1);
        
    }
    //CALCULATE P2
    int S2 = Find_S(EXP1);
    if (EXP1 >= S2) p2 = 1; else p2 = (80 + float(EXP1) / float(S2)) / 123;
    //FIND P3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int dozen_1, dozen_2, unit_1, unit_2;
    dozen_1 = E2 / 10;
    unit_1 = E2 - 10 * dozen_1;
    int sum_1 = dozen_1 + unit_1;
    dozen_2 = sum_1 / 10;
    unit_2 = sum_1 - 10 * dozen_2 ;
    p3 =(float) P[unit_2] / 100;
    float p_average = (p1 + p2 + p3) / 3;
    if (p_average == 1)
    {
        EXP1 = ceil(float(EXP1 * 0.75));
        EXP1 = valid_value_EXP(EXP1);
    }
    else if (p_average >= 0.5)
    {
        HP1 = ceil(float(HP1 * 0.9));
        HP1 = valid_value_HP(HP1);
        EXP1 = ceil(float(EXP1 * 1.2));
        EXP1 = valid_value_EXP(EXP1);
    }
    else
    {
        HP1 = ceil(float(HP1 * 0.85));
        HP1 = valid_value_HP(HP1);
        EXP1 = ceil(float(EXP1 * 1.15));
        EXP1 = valid_value_EXP(EXP1);
    }
   int RESULT = HP1 + EXP1 + M1;
    return RESULT;
}
//chase task3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    int POINTSW;
    int x_check, y_check;
    int a[10][10];
    int duong = 0, am = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (a[i][j] > 0 && a[i][j] > 2 * E3) duong += 1;
            if (a[i][j] < 0 && a[i][j] < -1 * E3) am += 1;
        }
    int x = position(duong);
    int y = position(am);
    // Tim so diem cua Sherlock & Watson
    int max1 = a[x][y];
    int max2 = a[x][y];
    int MAX_1 = a[x][y];
    int MAX_2 = a[x][y];
    // Tim theo duong cheo huong len
    for (int count = 0; count < 2; count++)
    {
        x_check = x;
        y_check = y;
        //tim len
        while (x_check > -1 && y_check < 10)
        {
            x_check--; y_check++;
            if (a[x_check][y_check] > max1) max1 = a[x_check][y_check];
        }
        //tim xuong
        while (x_check<10 && y_check>-1)
        {
            x_check++; y_check--;
            if (a[x_check][y_check] > max2) max2 = a[x_check][y_check];
        }
    }
    if (max1 > max2) MAX_1 = max1; else MAX_1 = max2;
    // Tim theo duong cheo huong xuong
    for (int count = 0; count < 2; count++)
    {
        x_check = x;
        y_check = y;
        //tim len
        while (x_check > -1 && y_check > -1)
        {
            x_check--; y_check--;
            if (a[x_check][y_check] > max1) max1 = a[x_check][y_check];
        }
        //tim xuong
        while (x_check < 10 && y_check < 10)
        {
            x_check++; y_check++;
            if (a[x_check][y_check] > max2) max2 = a[x_check][y_check];
        }
    }
    if (max1 > max2) MAX_2 = max1; else MAX_2 = max2;
    if (MAX_1 > MAX_2) POINTSW = MAX_1; else POINTSW = MAX_2;
    int value_taxi;
    int RESULT;
    if (a[x][y] > 0) value_taxi = a[x][y]; else value_taxi = -1 * a[x][y];
    if (value_taxi > POINTSW)//KHONG DUOI KIP TAXI
    {
        EXP1 = ceil(float(EXP1 * 0.88));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));
        HP2 = ceil(float(HP2 * 0.9));
        RESULT = a[x][y];
    }
    else
    {
        EXP1 = ceil(float(POINTSW * 1.12));
        EXP2 = ceil(float(POINTSW * 1.12));
        HP1 = ceil(float(HP1 * 1.1));
        HP2 = ceil(float(HP2 * 1.1));
        RESULT = POINTSW;
    }
    if (value_taxi > POINTSW) return a[x][y];
    else return POINTSW;
    
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    int position;
    string s1 = s;
    string email1 = email;
    //Tim se
    for (int i = 0; i < email1.length(); i++)
    {
        if (email1[i] == '@')
        {
            position = i;
        }
    }
    //xet xem co chua ky tu dac biet k
    int position_sc = 0;
    int count_1 = 0;
    while (count_1 < s1.length() && position_sc < 2)
    {
        if ((int)s[count_1] == 33 || (int)s[count_1] == 35 || (int)s[count_1] == 36 || (int)s[count_1] == 37 || (int)s[count_1] == 64)
        {
            position_sc++;
        }
        count_1++;
    }

    //xet cac th con lai
    int position_except = -1;
    for (int i = 0; i < s1.length(); i++)
    {
        if ((int)s[i] == 32 && (int)s[i] == 34)
            if ((int)s[i] > 37 && (int)s[i] < 48)
                if ((int)s[i] > 57 && (int)s[i] < 65)
                    if ((int)s[i] > 90 && (int)s[i] < 97)
                        if ((int)s[i] > 122 && (int)s[i] < 128)
                            position_except = i;


    }
    //tim vi tri 2 thang ky tu giong nhau
    int position_loop = -1;
    int count = 0;
    int toggle = 0;
    while (count < s1.length() - 1 && toggle != 1)
    {
        if (s1[count] == s1[count + 1])
        {
            position_loop = count;
            toggle = 1;
        }
        count++;
    }
    string se = email1.substr(0, position);
    int position_se = s1.find(se);
    //xet mat khau roi tra ve gia tri
    if (s1.length() < 8) return -1;
    else if (s1.length() > 20) return -2;
    else if (s1.find(se) > 0 && s1.find(se) < s1.length()) return -(300 + position_se);
    else if (toggle == 1) return -(400 + position_loop);
    else if (position_sc == 0) return -5;
    else if (position_except != -1) return position_except;
    else return -10;
}

// Task 5
void count_loop_time(string* a, int size, int& loop_max)
{
    int count, max = 0;
    for (int i = 0; i < size - 1; i++)
    {

        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j]) count++;
        }
        if (count >= max) max = count;
    }
    loop_max = max;
}
void filter(string* a, int size, string*& b, int& size_b, int loop_max)
{
    int count;
    size_b = 0;
    for (int i = 0; i < size - 1; i++)
    {

        count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j]) count++;
        }
        if (count == loop_max)
        {
            b[size_b] = a[i];
            size_b++;
        }
    }
}
int Maximus(string word1, string word2)
{
    if (word1.length() > word2.length())
        return 1; else if (word1.length() < word2.length()) return -1; else return 0;
}
void findTheCorrectPassword(string* b, int size_b, string& PASSWORD)
{
    string max;
    if (size_b == 1)
    {
        PASSWORD = b[0];
    }
    else
    {
        for (int i = 0; i < size_b - 1; i++)
        {
            for (int j = i + 1; j < size_b; j++)
            {
                if (Maximus(b[i], b[j]) == 1 || Maximus(b[i], b[j]) == 0) max = b[i];
                else if (Maximus(b[i], b[j]) == -1) max = b[j];
            }
        }
        PASSWORD = max;
    }

}
int position1(string* a, int size, string PASSWORD)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == PASSWORD) return i;
    }
    return -1;
}
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    //chuyen arr ve string a
    string* a = new string[num_pwds];
    for (int i = 0; i < num_pwds; i++)
        a[i] = arr_pwds[i];
    int size_of_a = num_pwds;
    int number_of_repetitions, size_of_b;
    string the_Correct_Password;
    //find number of repetitions
    count_loop_time(a, size_of_a, number_of_repetitions);
    string* b = new string[30];
    //Find the most repetitions passwords
    filter(a, size_of_a, b, size_of_b, number_of_repetitions);
    //find the correct password
    findTheCorrectPassword(b, size_of_b, the_Correct_Password);
    //find the position of the correct password
    int x = position1(a, size_of_a, the_Correct_Password);
    return x;
}

int position(int n)
{
    while ((n / 10) != 0)
    {
        n = n / 10 + n - 10 * (n / 10);
    }
    return n;
}
int Find_S(int n)
{
    int s;
    if (sqrt(n) > (int(sqrt(n)) + 0.5))
    {
        s = int(sqrt(n)) + 1;
    }
    else s = int(sqrt(n));
    int S = pow(s, 2);
    return S;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////