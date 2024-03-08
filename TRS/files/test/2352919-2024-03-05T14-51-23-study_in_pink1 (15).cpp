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

// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{if ((e1 < 0) || (e1 > 99))
    {
        return -99;
    }
    if(exp1>600) {
exp1=600;
    }
    if(exp1<0){
exp1=0;
    }
    if(exp2>600) {
exp2=600;
    }
    if(exp2<0) {
        exp2=0;
    }
    
    if (e1 <= 3)
    {
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
            exp2 += 29 + 45 + 75;
        }
        if ((e1 * 3 + exp1 * 7) % 2 != 0)
        {
            exp1 = ceil(exp1 - (float)(e1 * 3 + exp1 * 7) / 100.0);
        }
        else if ((e1 * 3 + exp1 * 7) % 2 == 0)
        {
            exp1 = ceil(exp1 + (float)(e1 * 3 + exp1 * 7) / 200.0);
        }
    }
    if (e1 >= 4)
    {
        if ((e1 >= 4) && (e1 <= 19))
        {
            exp2 = ceil(exp2 + (float)(e1) / 4.0 + 19);
        }
        else if ((e1 >= 20) && (e1 <= 49))
        {
            exp2 = ceil(exp2 + (float)(e1) / 9.0 + 21);
        }
        else if ((e1 >= 50) && (e1 <= 65))
        {
            exp2 = ceil(exp2 + (float)(e1) / 16.0 + 17);
        }
        else if ((e1 >= 66) && (e1 <= 79))
        {
            exp2 = ceil(exp2 + (float)(e1) / 4.0 + 19);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (float)(e1) / 9.0 + 21);
            }
        }
        else if ((e1 >= 80) && (e1 <= 99))
        {
            exp2 = ceil(exp2 + (float)(e1) / 4.0 + 19);
            exp2 = ceil(exp2 + (float)(e1) / 9.0 + 21);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + (float)(e1) / 16.0 + 17);
                exp2 = ceil((float)(exp2) * 1.15);
            }
        }
        exp1 -= e1;
    }
    if (exp2 > 600)
    {
        exp2 = 600;
    }
    if (exp2 < 0)
    {
        exp2 = 0;
    }
    if (exp1 > 600)
    {
        exp1 = 600;
    }
    if (exp1 < 0)
    {
        exp1 = 0;
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // first way
    if (E2 < 0)
    {
        return -99;
    }
    if (E2 > 99)
    {
        return -99;
    }
     if(EXP1>600) {
EXP1=600;
    }
    if(EXP1<0){
EXP1=0;
    }
    if(HP1>666){
        HP1=666;
    }
    if(HP1<0){
        HP1=0;
    }
    if(M1>3000){
        M1=3000;
    }
    if(M1<0){
        M1=0;
    }
    float P1, S1;
    if (abs(pow(ceil((float)(sqrt(EXP1))), 2) - EXP1) <= abs(pow(floor((float)(sqrt(EXP1))), 2) - EXP1))
    {
        S1 = pow(ceil((float)(sqrt(EXP1))), 2);
    }
    else
    {
        S1 = pow(floor((float)(sqrt(EXP1))), 2);
    }
    if (EXP1 >= S1)
    {
        P1 = 1;
    }
    else
    {
        P1 = (EXP1 / S1 + 80) / 123;
    }
    // Second way
    if(M1!=0) { 
    float money = M1;
    if (E2 % 2 == 1)
    {
        while (M1 >= (money / 2))
        {
            if ((M1 < 150) && (HP1 < 200))
            {
                HP1 = ceil((float)(HP1 * 1.3));
                if (HP1 > 666)
            {
                HP1 = 666;
            }
                M1 = 0;
                break;
            }
            else if ((M1 < 70) && (HP1 > 200))
            {
                HP1 = ceil((float)(HP1 * 1.1));
                if (HP1 > 666)
            {
                HP1 = 666;
            }
                M1 = 0;
                break;
            }
            if ((HP1 < 200) && (M1 >= (money / 2)))
            {
                M1 -= 150;
                HP1 = ceil((float)(HP1 * 1.3));
                if (HP1 > 666)
            {
                HP1 = 666;
            }
            }
            else if ((HP1 >= 200) && (M1 >= (money / 2)))
            {
                M1 -= 70;
                HP1 = ceil((float)(HP1 * 1.1));
                if (HP1 > 666)
            {
                HP1 = 666;
            }
            }
            if ((EXP1 < 400) && (M1 >= (money / 2)))
            {
                M1 -= 200;
                EXP1 = ceil((float)(EXP1 * 1.13));
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
            }
            else if ((EXP1 >= 400) && (M1 >= (money / 2)))
            {
                M1 -= 120;
                EXP1 = ceil((float)(EXP1 * 1.13));
                if (EXP1 > 600)
                {
                    EXP1 = 600;
                }
            }
            if ((EXP1 < 300) && (M1 >= (money / 2)))
            {
                M1 -= 100;
                EXP1 = ceil((float)(EXP1 * 0.9));
            }
            else if ((EXP1 >= 300) && (M1 >= (money / 2)))
            {
                M1 -= 120;
                EXP1 = ceil((float)(EXP1 * 0.9));
            }
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
    }
    if (E2 % 2 == 0)
    {
        if ((money > 0) && (HP1 < 200))
        {
            M1 -= 150;
            HP1 = ceil((float)(HP1 * 1.3));
        }
        else if ((money > 0) && (HP1 >= 200))
        {
            M1 -= 70;
            HP1 = ceil((float)(HP1 * 1.1));
        }
        if (HP1 > 666)
        {
            HP1 = 666;
        }
        if ((EXP1 < 400) && (M1 > 0))
        {
            M1 -= 200;
            EXP1 = ceil((float)(EXP1 * 1.13));
        }
        else if ((EXP1 >= 400) && (M1 > 0))
        {
            M1 -= 120;
            EXP1 = ceil((float)(EXP1 * 1.13));
        }
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        if ((EXP1 < 300) && (M1 > 0))
        {
            M1 -= 100;
            EXP1 = ceil((float)(EXP1 * 0.9));
        }
        else if ((EXP1 >= 300) && (M1 > 0))
        {
            M1 -= 120;
            EXP1 = ceil((float)(EXP1 * 0.9));
        }
        if (M1 < 0)
        {
            M1 = 0;
        }
    }
    }
    HP1 = ceil((float)(HP1 * 0.83));
    EXP1 = ceil((float)(EXP1 * 1.17));
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    float P2, S2;
    if (abs(pow(ceil((float)(sqrt(EXP1))), 2) - EXP1) <= abs(pow(floor((float)(sqrt(EXP1))), 2) - EXP1))
    {
        S2 = pow(ceil((float)(sqrt(EXP1))), 2);
    }
    else
    {
        S2 = pow(floor((float)(sqrt(EXP1))), 2);
    }
    if (EXP1 >= S2)
    {
        P2 = 1;
    }
    else
    {
        P2 = (EXP1 / S2 + 80) / 123;
    }
    // third way
    float P3;
    int t;
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 <= 9)
    {
        P3 = (float)(arr[E2] / 100.0);
    }
    else if (E2 >= 10)
    {
        t = (E2 / 10 + E2 % 10) % 10;
        P3 = (float)(arr[t] / 100.0);
    }
    if ((P1 == 1) && (P2 == 1) && (P3 == 1))
    {
        EXP1 = ceil((float)(EXP1 * 0.75));
    }
    if (ceil((float)((P1 + P2 + P3) / 3.0 < 0.5)))
    {
        HP1 = ceil((float)(HP1 * 0.85));
        EXP1 = ceil((float)(EXP1 * 1.15));
    }
    if (((P1 + P2 + P3) != 3.0) && ((P1 + P2 + P3) / 3.0 > 0.5))
    {
        HP1 = ceil((float)(HP1 * 0.9));
        EXP1 = ceil((float)(EXP1 * 1.2));
    }
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    if (HP1 < 0)
    {
        HP1 = 0;
    }
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    if (M1 < 0)
    {
        M1 = 0;
    }
    if (M1 > 3000)
    {
        M1 = 3000;
    }
    return HP1 + EXP1 + M1;

}
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if((E3<0)||(E3>99)) {
        return -99;
    }
    if(HP1>666){
        HP1=666;
    }
    if(HP1<0){
        HP1=0;
    }
    if(HP2>666){
        HP2=666;
    }
    if(HP2<0){
        HP2=0;
    }
    if(EXP1>600){
        EXP1=600;
    }
    if(EXP1<0){
        EXP1=0;
    }
    if(EXP2>600){
        EXP2=600;
    }
    if(EXP2<0){
        EXP2=0;
    }
    
    int count1 = 0, count2 = 0, x, y;
    int arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] > (2 * E3))
            {
                count1 += 1;
            }
            if (arr[i][j] < (-E3))
            {
                count2 += 1;
            }
        }
    }
    x = count1 / 10 + count1 % 10;
    if (x >= 10)
    {
        x = x / 10 + x % 10;
    }

    y = count2 / 10 + count2 % 10;
    if (y >= 10)
    {
        x = x / 10 + x % 10;
    }
    int max = arr[x][y];
    // left slash
    int x0 = x;
    int y0 = y;
    for (; (x0 < 11)|| (y0 < 11); x0++, y0++)
    {
        if (arr[x0][y0] > max)
        {
            max = arr[x0][y0];
        }
        if ((x0 == 9) || (y0 == 9))
        {
            break;
        }
    }
    // left slash
    x0 = x;
    y0 = y;
    for (; (x0 > -1)|| (y0 > -1); x0--, y0--)
    {
        if (arr[x0][y0] > max)
        {
            max = arr[x0][y0];
        }
        if ((x0 == 0) || (y0 == 0))
        {
            break;
        }
    }
    // right slash
    x0 = x;
    y0 = y;
    for (; (x0 > -1)||( y0 < 11); x0--, y0++)
    {
        if (arr[x0][y0] > max)
        {
            max = arr[x0][y0];
        }
        if ((x0 == 0) || (y0 == 9))
        {
            break;
        }
    }
    // right slash
    x0 = x;
    y0 = y;
    for (; (x0<11) || (y0> - 1); x0++, y0--)
    {
        if (arr[x0][y0] > max)
        {
            max = arr[x0][y0];
        }
        if ((x0 == 9) || (y0 == 0))
        {
            break;
        }
    }

    if (abs(max) < abs(arr[x][y]))
    {
        EXP1 = ceil((float)(EXP1 * 0.88));
        EXP2 = ceil((float)(EXP2 * 0.88));
        HP1 = ceil((float)(HP1 * 0.9));
        HP2 = ceil((float)(HP2 * 0.9));
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        if (EXP2 > 600)
        {
            EXP2 = 600;
        }
        if (EXP2 < 0)
        {
            EXP2 = 0;
        }
        if (HP1 < 0)
        {
            HP1 = 0;
        }

        if (HP1 > 666)
        {
            HP1 = 666;
        }
        if (HP2 < 0)
        {
            HP2 = 0;
        }

        if (HP2 > 666)
        {
            HP2 = 666;
        }
        return arr[x][y];
    }
    else
    {
        EXP1 = ceil((float)(EXP1 * 1.12));
        EXP2 = ceil((float)(EXP2 * 1.12));
        HP1 = ceil((float)(HP1 * 1.1));
        HP2 = ceil((float)(HP2 * 1.1));
        if (EXP1 > 600)
        {
            EXP1 = 600;
        }
        if (EXP1 < 0)
        {
            EXP1 = 0;
        }
        if (EXP2 > 600)
        {
            EXP2 = 600;
        }
        if (EXP2 < 0)
        {
            EXP2 = 0;
        }
        if (HP1 < 0)
        {
            HP1 = 0;
        }

        if (HP1 > 666)
        {
            HP1 = 666;
        }
        if (HP2 < 0)
        {
            HP2 = 0;
        }

        if (HP2 > 666)
        {
            HP2 = 666;
        }
        return max;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string password(s);
    string se(email);
   se = se.erase(se.find('@'), se.length() - se.find('@'));
    if (password.length() < 8)
    {
        return -1;
    }
    if (password.length() > 20)
    {
        return -2;
    }
    if(se.length()==0) {
        return -300;
    }
    if (password.find(se) != string::npos)
    {
        return -(300 + password.find(se));
    }
    for (int i = 0; i < password.length(); i++)
    {

        if ((password[i] == password[i + 1]) && (password[i] == password[i + 2]))
        {
            return -(400 + i);
        }
    }
    if ((password.find("@") == string::npos) && (password.find("#") == string::npos) && (password.find("%") == string::npos) && (password.find("$") == string::npos) && (password.find("!") == string::npos))
    {
        return -5;
    }
    for (int k = 0; k < password.length(); k++)
    {
        bool valid = isdigit(password[k]) || islower(password[k]) || isupper(password[k]) || password[k] == '@' || password[k] == '#' || password[k] == '%' || password[k] == '$' || password[k] == '!';
        if (!valid)
        {
            return k;
        }
    }

    return -10;
}
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    string pass[num_pwds];
    for (int i = 0; i < num_pwds; i++)
    {
        pass[i] = arr_pwds[i];
    }
    int direction = 0;
    int max = 0;
    int max0=0;
    int count0=0;
    for (int i = 0; i < num_pwds; i++)
    {
        int count = 1;
        for (int j = i + 1; j < num_pwds; j++)
        {
            if (pass[i] == pass[j])
            {
                count += 1;
                if (count > max)
                {
                    direction = i;
                    max = count;
                }
                if (count == max)
                {
                    if (pass[i].length() > pass[direction].length())
                    {
                        direction = i;
                    }
                }
            }
            else {
                count0+=1;
            }
        }
    }
    if(count0==(num_pwds-1)*num_pwds/2) {
                for (int j = 0; j < num_pwds; j++) {
                    if(pass[j].length()>max0) {
                        direction=j;
                        max0=pass[j].length();
                    }
                }
            }

    return direction;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////