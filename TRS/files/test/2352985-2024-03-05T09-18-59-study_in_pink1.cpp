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
int checkexp(int &exp)
{
    if (exp > 600)
    {
        exp = 600;
    }
    else if (exp < 0)
    {
        exp = 0;
    }
    return exp;
}
int checkhp(int &hp)
{
    if (hp < 0)
    {
        hp = 0;
    }
    if (hp > 666)
    {
        hp = 666;
    }
    return hp;
}
int checkmoney(int &m)
{
    if (m < 0)
    {
        m = 0;
    }
    if (m > 3000)
    {
        m = 3000;
    }
    return m;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    int D;
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    checkexp(exp1);
    checkexp(exp2);
    // situation1
    if (e1 >= 0 && e1 <= 3)
    {
        if (e1 == 0)
        {
            exp2 += 29.0;
            checkexp(exp2);
        }
        else if (e1 == 1)
        {
            exp2 += 45.0;
            checkexp(exp2);
        }
        else if (e1 == 2)
        {
            exp2 += 75.0;
            checkexp(exp2);
        }
        else if (e1 == 3)
        {
            exp2 += 29.0 + 45.0 + 75.0;
            checkexp(exp2);
        }
        D = (e1 * 3) + (exp1 * 7);
        if (D % 2 == 0)
        {
            exp1 = ceil(double(exp1 + (D / 200.0) - 0.0000001));
            checkexp(exp1);
        }
        else
        {
            exp1 = ceil(double(exp1 - (D / 100.0) - 0.0000001));
            checkexp(exp1);
        }
    }
    // situation2
    if (e1 >= 4 && e1 <= 99)
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(double(exp2 + (e1 / 4.0) + 19.0));
            checkexp(exp2);
        }
        if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(double(exp2 + (e1 / 9.0) + 21.0));
            checkexp(exp2);
        }
        if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(double(exp2 + (e1 / 16.0) + 17.0));
            checkexp(exp2);
        }
        if (66 <= e1 && e1 <= 79)
        {
            exp2 = ceil(double(exp2 + (e1 / 4.0) + 19.0));
            checkexp(exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(double(exp2 + (e1 / 9.0) + 21.0));
                checkexp(exp2);
            }
        }
        if (80 <= e1 && e1 <= 99)
        {
            exp2 = ceil(double(exp2 + e1 / 4.0 + 19.0));
            checkexp(exp2);
            exp2 = ceil(double(exp2 + e1 / 9.0 + 21.0));
            checkexp(exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(double(exp2 + e1 / 16.0 + 17.0));
                checkexp(exp2);
                exp2 = ceil(double(exp2 + 0.15 * exp2));
                checkexp(exp2);
            }
        }
        exp1 = exp1 - e1;
        checkexp(exp1);
    }
    return exp1 + exp2;
}
void feeding(int &HP1, int &M1)
{
    checkhp(HP1);
    checkmoney(M1);
   if (HP1<200)
   {
     HP1= ceil(double(HP1)+ double(HP1)*0.3);
     checkhp(HP1);
     M1-=150;
     checkmoney(M1);
   }
   else
   {
     HP1= ceil(double(HP1)+ double(HP1)*0.1);
     checkhp(HP1);
     M1-=70;
     checkmoney(M1);
   }
}
void get_vehicle(int &EXP1, int &M1)
{
    checkexp(EXP1);
    checkmoney(M1);
    if (EXP1 < 400)
    {
        M1 -= 200;
        checkmoney(M1);
    }
    else
    {
        M1 -= 120;
        checkmoney(M1);
    }
    EXP1 = ceil(double(EXP1) + (0.13 * double(EXP1)));
    checkexp(EXP1);
}
void meet_homeless(int &EXP1, int &M1)
{
    checkexp(EXP1);
    checkmoney(M1);
    if (EXP1 < 300)
    {
        M1 -= 100;
        checkmoney(M1);
    }
    else if (EXP1 >= 300)
    {
        M1 -= 120;
        checkmoney(M1);
    }
    EXP1 = ceil(double(EXP1) - (0.1 * double(EXP1)));
    checkexp(EXP1);
}
void updatedata (int & HP1, int & EXP1 )
    {
        HP1 = ceil(double(HP1) - 0.17 * double(HP1));
        checkhp(HP1);
        EXP1 = ceil(double(EXP1) + double(0.17 * EXP1));
        checkexp(EXP1);
    }
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    checkexp(EXP1);
    checkhp(HP1);
    checkmoney(M1);
    // road1
    double p1;
    int S = 0;
    double a = sqrt(double(EXP1));
    double squarenum1 = floor(a) * floor(a);
    double squarenum2 = ceil(a) * ceil(a);
    if (abs(EXP1 - squarenum1) < abs(EXP1 - squarenum2))
    {
        S = squarenum1;
    }
    else if (abs(EXP1 - squarenum1) > abs(EXP1 - squarenum2))
    {
        S = squarenum2;
    }
    double break_point = double(M1) / 2.0;
    if (EXP1 >= S)
    {
        p1 = 1;
    }
    else
    {
        p1 = (double(EXP1) / S + 80) / 123.0;
    }
    // road2
    if (E2 % 2 != 0)
    {
        while (M1 > break_point)
        {
            if (M1 > break_point)
                feeding(HP1, M1);
                checkhp(HP1);
                checkmoney(M1);
            if (M1 > break_point)
                get_vehicle(EXP1, M1);
                checkexp(EXP1);
                checkmoney(M1);
            if (M1 > break_point)
                meet_homeless(EXP1, M1);
                checkexp(EXP1);
                checkmoney(M1);
        }
        updatedata(HP1 , EXP1);
        checkhp(HP1);
        checkexp(EXP1);
    }
    else if (E2 % 2 == 0)
    {
        if (M1 != 0)
        {
            feeding(HP1, M1);
            checkmoney(M1);
            checkhp(HP1);
        }
        if (M1 != 0)
        {
            get_vehicle(EXP1, M1);
            checkmoney(M1);
            checkexp(EXP1);
        }
        if (M1 != 0)
        {
            meet_homeless(EXP1, M1);
            checkmoney(M1);
            checkexp(EXP1);
        }
        updatedata(HP1, EXP1);
        checkexp(EXP1);
        checkhp(HP1);
    }
    //calculate P2
    int L = 0;
    double z = sqrt(double(EXP1));
    double squarenum3 = floor(z) * floor(z);
    double squarenum4 = ceil(z) * ceil(z);
    if (abs(EXP1 - squarenum3) < abs(EXP1 - squarenum4))
    {
        L = squarenum3;
    }
    else if (abs(EXP1 - squarenum3) > abs(EXP1 - squarenum4))
    {
        L = squarenum4;
    }
    double p2;
    if (EXP1 > L)
    {
        p2 = 1;
    }
    else
    {
        p2 = (double(EXP1) / L + 80) / 123.0;
    }
    // road3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10 && E2 > 0)
    {
        i = E2;
    }
    else if (E2 >= 10 && E2 <= 99)
    {
        i = E2 % 10 + E2 / 10;
        if (i >= 10)
        {
            i = i % 10;
        }
    }
    double p3 = double(P[i]) / 100;
    if (p1 == 1 && p2 == 1 && p3 == 1)
    {
        EXP1 = ceil(double(EXP1) - double(0.25 * EXP1));
        checkexp(EXP1);
    }
    else
    {
        double Pvg = double((p1 + p2 + p3)) / 3;
        if (Pvg < 0.5)
        {
            HP1 = ceil(double(HP1) - double(0.15 * HP1));
            checkhp(HP1);
            EXP1 = ceil(double(EXP1) + double(0.15 * EXP1));
            checkexp(EXP1);
        }
        else
        {
            HP1 = ceil(double(HP1) - 0.1 * double(HP1));
            checkhp(HP1);
            EXP1 = ceil(double(EXP1) + 0.2 * double(EXP1));
            checkexp(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    checkexp(EXP1);
    checkexp(EXP2);
    checkhp(HP2);
    checkhp(HP1);

    int counti = 0;
    int countj = 0;
    int sumi;
    int sumj;
    int matrix[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrix[i][j] > (E3 * 2))
            {
                counti++;
            }
            if (matrix[i][j] < (-E3))
            {
                countj++;
            }
        }
    }
    if (counti >= 10 && counti <= 99)
    {
        sumi = counti % 10 + counti / 10;
        if (sumi >= 10)
        {
            sumi = sumi % 10 + sumi / 10;
        }
    }
    if (countj >= 10 && countj <= 99)
    {
        sumj = countj % 10 + countj / 10;
        if (sumj >= 10)
        {
            sumj = sumj % 10 + sumj / 10;
        }
    }
    int max = matrix[sumi][sumj];
    for (int k = 0; k < 10; k++)
    {
        if (sumi + k <= 9 && sumj + k <= 9)
        {
            if (matrix[sumi + k][sumj + k] > max)
            {
                max = matrix[sumi + k][sumj + k];
            }
        }
        if (sumi - k >= 0 && sumj - k >= 0)
        {
            if (matrix[sumi - k][sumj - k] > max)
            {
                max = matrix[sumi - k][sumj - k];
            }
        }
        if (sumi + k <= 9 && sumj - k >= 0)
        {
            if (matrix[sumi + k][sumj - k] > max)
            {
                max = matrix[sumi + k][sumj - k];
            }
        }
        if (sumi - k >= 0 && sumj + k <= 9)
        {
            if (matrix[sumi - k][sumj + k] > max)
            {
                max = matrix[sumi - k][sumj + k];
            }
        }
    }
    if (abs(matrix[sumi][sumj]) > abs(max))
        {
            EXP1 = ceil(EXP1 - 0.12 * EXP1);
            checkexp(EXP1);
            EXP2 = ceil(EXP2 - 0.12 * EXP2);
            checkexp(EXP2);
            HP1 = ceil(HP1 - 0.1 * HP1);
            checkhp(HP1);
            HP2 = ceil(HP2 - 0.1 * HP2);
            checkhp(HP2);
        }
    else
        {
            EXP1 = ceil(EXP1 + 0.12 * EXP1);
            checkexp(EXP1);
            EXP2 = ceil(EXP2 + 0.12 * EXP2);
            checkexp(EXP2);
            HP1 = ceil(HP1 + 0.1 * HP1);
            checkhp(HP1);
            HP2 = ceil(HP2 + 0.1 * HP2);
            checkhp(HP2);
        }
    if (abs(matrix[sumi][sumj]) > abs(max))
    {
        max = matrix[sumi][sumj];
    }
    return max;
}
// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
string pass= s, mail = email;
 size_t l = pass.length();
 if (l < 8)
    {
        return -1;
    }
 if (l> 20)
    {
        return -2;
    }
 int a= mail.find('@');  
 string se;
 se = mail.substr(0,a);
 size_t check = pass.find(se) ;
 if (check != string::npos)
 {
    return -(300 + int(check));
 }
  for (int i=0; i< (l-2) ; i++)
  {
    if (pass[i] == pass[i+1] && pass[i+1] == pass[i+2])
    {
        return -(400+i);
    }
  }
  int countspecial=0;
for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] =='@' || s[i]== '%' || s[i] == '#' || s[i]== '!' || s[i] == '$')
       {
         countspecial++ ;
       }
      
    }
       if (countspecial==0)
        {
            return -5;
        }
for (int i = 0; i < strlen(s); i++)
    {
        if (
            (s[i] !='@' && s[i] != '%' && s[i] != '#' && s[i]!= '!' && s[i] != '$') &&
            (s[i] < 'a' || s[i] > 'z') && 
            (s[i] < 'A' || s[i] > 'Z') &&
            (s[i] < '0' || s[i] > '9') 
        )
        {
            return i;
        }
        
    }
    return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int countpass=0;
    int maxcount=0;
    int position=0;
    int maxlength=0;
    //check so lan xuat hien cua tung mat khau khac nhau va kiem tra trung nhau
 for (int i=0; i< num_pwds ; i++)
 {
   countpass = 1;
   for (int j= i+1; j< num_pwds; j++)
   {
     if (strcmp( arr_pwds[i] , arr_pwds[j] ) == 0 )
        {
            countpass++;
        }
   }
   if (countpass> maxcount)
   {
     maxcount = countpass;
     position =i;
     maxlength= strlen(arr_pwds[i]);
   }
   else if (countpass == maxcount && strlen(arr_pwds[i]) > maxlength)
   {
     maxlength= strlen(arr_pwds[i]);
     position=i;
   }
 }
    return position ; 
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////