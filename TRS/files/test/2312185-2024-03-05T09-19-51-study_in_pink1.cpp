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
)
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
void limitcheck (int & variable, int max) {
    if (variable < 0)
    {
        variable = 0;
    }
    if (variable > max)
    {
        variable = max;
    }
}
void variableadjust (int & variable, double adjustment, int max)    {
    if (abs (adjustment - int(adjustment)) > 1e-9)  {
        adjustment = ceil (adjustment);
    }
    variable += adjustment;
    limitcheck (variable, max);
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1)
{
    //TODO: implement task
    if (E1 >= 0 && E1 <=99)   {
        if (E1<=3 && E1 >=0)    {
            switch (E1)   {
                case 0:
                EXP2 += 29;
                break;
                case 1:
                EXP2 += 45;
                break;
                case 2:
                EXP2 += 75;
                break;
                case 3:
                EXP2 += 149;
                break;
            }
            limitcheck (EXP2, 600);
            int d = E1 * 3 + EXP1 * 7;
            int temp1 = d % 2;
            switch (temp1)   {
                case 1:
                variableadjust (EXP1, -d/100.0, 600);
                break;
                case 0:
                variableadjust (EXP1, d/200.0, 600);
                break;
            }

        }
        else if (E1 <=99 && E1 >=4) {
            if (E1 >=4 && E1 <= 19) {
                variableadjust (EXP2, E1/4.0 + 19, 600);
            }
            else if (E1 >=20 && E1 <= 49)
            {
                variableadjust (EXP2, E1/9.0 + 21, 600);
            }
            else if (E1 >=50 && E1 <=65)
            {
                variableadjust (EXP2, E1/16.0 + 17, 600);
            }
            else if (E1 >=66 && E1 <= 79)
            {
                variableadjust (EXP2, E1/4.0 + 19, 600);
                if (EXP2 > 200)
                {
                    variableadjust (EXP2, E1/9.0 + 21, 600);
                }            
            }
            else {
                variableadjust (EXP2, E1/4.0 + 19, 600);                
                variableadjust (EXP2, E1/9.0 + 21, 600);                
                if (EXP2 > 400)
                {
                    variableadjust (EXP2, E1/16.0 + 17, 600);                    
                    variableadjust (EXP2, EXP2*0.15, 600);                    
                }       
            }
            EXP1 -=E1;
            limitcheck (EXP1, 600);
        }
        return EXP1 + EXP2;
    }
    else    {
        return -99;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    // TODO: Complete this function
    if (E2 >= 0 && E2 <=99)   {
        double p1;
        int s1;
        double sqrtEXP1 = sqrt(EXP1);
        int lwr1 = floor(sqrtEXP1);
        int upr1 = ceil(sqrtEXP1);
        int upd1 = (upr1*upr1) - EXP1;
        int lwd1 = EXP1 - (lwr1*lwr1);
        if (upd1 > lwd1)    {
            s1 = lwr1*lwr1;
        }
        else    {
            s1 = upr1*upr1;
        }
        if (EXP1 >= s1)  {
            p1 =100;
        }
        else    {
            p1 = (EXP1/double(s1) +80)/1.23;
        }
        if (E2 % 2 == 0) {
            if (HP1 < 200 && M1 > 0)  {
                variableadjust (HP1, 0.3 * HP1, 666);
                variableadjust (M1, -150, 3000);
            }
            else if (HP1 >= 200 && M1 > 0)    {
                variableadjust (HP1, 0.1 * HP1, 666);
                variableadjust (M1, -70, 3000);
            }
            if (M1 > 0) {
                if (EXP1 < 400)    {
                    M1 -= 200;
                }
                else    {
                    M1 -= 120;
                }
                limitcheck (M1, 3000);
                variableadjust (EXP1, EXP1 * 0.13, 600);            
            }
            if (M1 > 0) {
                if (EXP1 < 300) {
                    M1 -= 100;
                }
                else    {
                    M1 -= 120;
                }
                limitcheck (M1, 3000);
                variableadjust (EXP1, -0.1 * EXP1, 600);
            }
        }
        else    {
            double lim = M1 / 2.0;
            int spent = 0;
            do  {
                if (HP1 < 200 && spent <= lim)  {
                    variableadjust (HP1, 0.3 * HP1, 666);
                    variableadjust (M1, -150, 3000);
                    spent += 150;
                }
                else if (HP1 >= 200 && spent <= lim)    {
                    variableadjust (HP1, 0.1 * HP1, 666);
                    variableadjust (M1, -70, 3000);
                    spent += 70;
                }
                if (spent <= lim) {
                    if (EXP1 < 400)    {
                        M1 -= 200;
                        spent += 200;
                    }
                    else    {
                        M1 -= 120;
                        spent += 120;
                    }
                    limitcheck (M1, 3000);
                    variableadjust (EXP1, EXP1 * 0.13, 600);            
                }
                if (spent <= lim) {
                    if (EXP1 < 300) {
                        M1 -= 100;
                        spent += 100;
                    }
                    else    {
                        M1 -= 120;
                        spent += 120;
                    }
                    limitcheck (M1, 3000);
                    variableadjust (EXP1, -0.1 * EXP1, 600);
                }
            }
            while (spent <= lim);
            if (M1 < 0) {
            M1 = 0;
            }            
        }
        variableadjust (HP1, -0.17 * HP1, 666);
        variableadjust (EXP1, 0.17 * EXP1, 600);
        double p2;
        int s2;
        double sqrtEXP12 = sqrt(EXP1);
        int lwr2 = floor(sqrtEXP12);
        int upr2 = ceil(sqrtEXP12);
        int upd2 = (upr2*upr2) - EXP1;
        int lwd2 = EXP1 - (lwr2*lwr2);
        if (upd2 > lwd2)    {
            s2 = lwr2*lwr2;
        }
        else    {
            s2 = upr2*upr2;
        }
        if (EXP1 >= s2)  {
            p2 =100;
        }
        else    {
            p2 = (EXP1/(double)s2 +80)/1.23;
        }
        int p [10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2<10 && E2 >=1)    {
            i = E2;
        }
        else if (E2 >= 10 && E2 <= 99)
        {
            i = ((E2 / 10) + (E2 % 10)) % 10;
        }
        double p3 = p [i];
        if (p1 + p2 + double(p3) == 300.0)    
        {
            variableadjust (EXP1, -0.25*EXP1, 600);
        }
        else if (p1 + p2 + double(p3) < 150.0)    
        {
            variableadjust (EXP1, 0.15*EXP1, 600);
            variableadjust (HP1, -0.15*HP1, 666);
        }
        else{ 
            if (p1 + p2 + double(p3) > 150 )    {
                variableadjust (EXP1, 0.20*EXP1, 600);
                variableadjust (HP1, -0.1*HP1, 666);
            }
            else
            {
                variableadjust (EXP1, 0.15*EXP1, 600);
                variableadjust (HP1, -0.15*HP1, 666);
            }
            
        }
        return HP1 + EXP1 + M1;
    }
    else    {
        return -99;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    if (E3 >= 0 && E3 <= 99)    {
        limitcheck(EXP1, 600);
        limitcheck(EXP2, 600);
        limitcheck(HP1, 666);
        limitcheck(HP2, 666);
        if (E3 < 0 || E3 > 99) {
            return -99;
        }
        int arrt3 [10][10] = {0};
        int axisi = 0, axisj = 0;
        for (int i3 = 0; i3 < 10; i3++)    {
            for (int j3 = 0; j3 < 10; j3++)
            {
                arrt3 [i3][j3] = ((E3 * j3) + (i3 * 2)) * (i3 - j3);
                if (arrt3 [i3][j3] > (E3 * 2)){
                    axisi ++;
                }
                if (arrt3 [i3][j3] < -E3)   
                {
                    axisj ++;
                }
                
            }
        }
        while (axisi > 9){
            int s = axisi;
            axisi = 0;
            while (s > 0){
                axisi += s % 10;
                s /= 10;
            }
        }
        while (axisj > 9){
            int s = axisj;
            axisj = 0;
            while (s > 0){
                axisj += s % 10;
                s /= 10;
            }
        }

        int sherlockpoint = arrt3 [axisi][axisj];

        for (int pointi = axisi, pointj = axisj; pointi >= 0 && pointj >= 0; pointi--, pointj--)    {
            if (arrt3 [pointi][pointj] > sherlockpoint) {
                sherlockpoint = arrt3 [pointi][pointj];
            }
        }
        for (int pointi = axisi, pointj = axisj; pointi <=9 && pointj <=9; pointi++, pointj++)    {
            if (arrt3 [pointi][pointj] > sherlockpoint) {
                sherlockpoint = arrt3 [pointi][pointj];
            }
        }
        for (int pointi = axisi, pointj = axisj; pointi >= 0 && pointj <= 9; pointi--, pointj++)    {
            if (arrt3 [pointi][pointj] > sherlockpoint) {
                sherlockpoint = arrt3 [pointi][pointj];
            }
        }
        for (int pointi = axisi, pointj = axisj; pointi <= 9 && pointj >= 0; pointi++, pointj--)    {
            if (arrt3 [pointi][pointj] > sherlockpoint) {
                sherlockpoint = arrt3 [pointi][pointj];
            }
        }
        sherlockpoint = abs(sherlockpoint);
        int taxipoint = abs (arrt3 [axisi][axisj]);
        int superior;
        if (taxipoint > sherlockpoint)  {
            variableadjust (HP1, -HP1 * 0.1, 666);
            variableadjust (HP2, -HP2 * 0.1, 666);
            variableadjust (EXP1, -EXP1 * 0.12, 600);
            variableadjust (EXP2, -EXP2 * 0.12, 600);
            superior = arrt3 [axisi][axisj];
        }
        else
        {
            variableadjust (HP1, HP1 * 0.1, 666);
            variableadjust (HP2, HP2 * 0.1, 666);
            variableadjust (EXP1, EXP1 * 0.12, 600);
            variableadjust (EXP2, EXP2 * 0.12, 600);
            superior = sherlockpoint;
        }    
        return superior;
    }
    else
    {
        return -99;
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se ="";
    string s1 = s;
    string email1 = email;
    if (s1.size() < 8)   
    {
        return -1;
    }
    else if (s1.size() > 20)
    {
        return -2;
    }
    else
    {   
        for (int i = 0; i < email1.size(); i++)  {
            if (email1[i] == '@')
            {
                break;
            }
            else
            {
                se += email [i];
            }
        }
        
        const char *p = strstr(s, se.c_str());
        if (p != nullptr)  {
            int sei = p - s;
            return -(300 + sei);
        }
        for (int j = 0; j < s1.size() -2; j++) {
            if (s[j] == s[j+1] && s[j] == s[j+2])  {
                int sci = j;
                return - (400 + sci);
            }
        }
        int specialsymbol = 0;
        for (int k = 0; k < s1.size(); k++) {
            if (s[k] == '!'||s[k] == '@'||s[k] == '#'||s[k] == '$'||s[k] == '%')    {
                specialsymbol = 1;
                break;
            }
        }
        if (specialsymbol == 0) {
            return -5;
        }
        for (int l = 0; l < s1.size(); l++) {
            if ((s[l] <'a' || s[l] > 'z') && (s[l] <'A' || s[l] > 'Z') && s[l] != '!'&&s[l] != '@'&&s[l] != '#'&&s[l] != '$'&&s[l] != '%' && (s[l] < '0' || s[l] > '9'))   {
                return l;
            }
        }       
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    //TODO: implement task
    string arr [num_pwds];
    for (int i = 0; i < num_pwds; i++)  {
        arr[i] = arr_pwds[i];
    }
    int max = 0;
    int pwdindex = -1;
    string pwd1;
    for (int i = 0; i < num_pwds; i++)  {
        int count = 0;
        for (int j = i; j < num_pwds; j++)  {
            if (arr[j]==arr[i]) {
                count++;
            }
        }
        if (count > max)    {
            max = count;
            pwd1 = arr[i];
            pwdindex = i;
        }
        else if (count == max)   {
            string pwd2 = arr[i];
            if (pwd2.size() > pwd1.size())  {
                pwd1 = pwd2;
                pwdindex = i;
            }
        }
    }
    return pwdindex;
}

////////////////////////////////////////////////

/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////