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
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
    double result1, result2;
    result1 = EXP1;
    result2 = EXP2;
    if (E1 < 0 || E1>99)
        return -99;

    if (E1 >= 0 && E1 <= 3)
    {
        switch (E1)
        {
        case 0:
        {
            result2 = result2 + 29;
            break;
        }
        case 1:
        {
            result2 = result2 + 45;
            break;
        }
        case 2:
        {
            result2 = result2 + 75;
            break;
        }
        case 3:
        {
            result2 = result2 + 29 + 45 + 75;
            break;
        }
        default:
            break;
        }
        int D = E1 * 3 + result1 * 7;
        if (D % 2 == 0)
            result1 = result1 + (D / 200.0);
        else
            result1 = result1 - (D / 100.0);
    }
    if (E1 >= 4 && E1 <= 99)
    {
        if (E1 >= 4 && E1 <= 19)
            result2 = result2 + ((E1 / 4.0) + 19);
        else if (E1 >= 20 && E1 <= 49)
            result2 = result2 + ((E1 / 9.0) + 21);
        else if (E1 >= 50 && E1 <= 65)
            result2 = result2 + ((E1 / 16.0) + 17);
        else if (E1 >= 66 && E1 <= 79)
        {
            result2 = result2 + ((E1 / 4.0) + 19);
            if (result2 > 200)
                result2 = (int)result2 + (result2 - (int)result2 > 0) + ((E1 / 9.0) + 21);
        }
        else
        {
            result2 = result2 + ((E1 / 4.0) + 19);
            result2 = (int)result2 + (result2 - (int)result2 > 0) + ((E1 / 9.0) + 21);
            if (result2 > 400)
            {
                result2 = (int)result2 + (result2 - (int)result2 > 0) + ((E1 / 16.0) + 17);
                result2 = ((int)result2 + (result2 - (int)result2 > 0)) * 1.15;
            }
        }

        result1 = result1 - E1;
        if (result2 > 600)
            result2 = 600;

    }
    EXP1 = (int)result1 + (result1 - (int)result1 > 0);
    EXP2 = (int)result2 + (result2 - (int)result2 > 0);
    if (EXP1 <= 0)
        EXP1 = 0;
    if (EXP2 <= 0)
        EXP2 = 0;

    if (EXP1 > 600)
        EXP1 = 600;
    if (EXP2 > 600)
        EXP2 = 600;
    return EXP1 + EXP2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
       //con đường 1
    if (E2 < 0 || E2>99)
        return -99;
    if (EXP1 <= 0)
        EXP1 = 0;
    if (HP1 <= 0)
        HP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 > 666)
        HP1 = 666;

    int s, s1, s2;
    double result1 = EXP1;
    float resulthp1 = HP1;
    int M1bandau = M1;
    for (int i = EXP1;i > 1;i--)
    {
        if (i == (int)sqrt(i) * (int)sqrt(i))
        {
            s1 = i;
            break;
        }
    }
    for (int i = EXP1;i < 10000;i++)
    {
        if (i == (int)sqrt(i) * (int)sqrt(i))
        {
            s2 = i;
            break;
        }
    }
    if ((s2 - EXP1) >= (EXP1 - s1))
        s = s1;
    else
        s = s2;

    double p1;
    if (EXP1 >= s)
        p1 = 100 / 100;
    else
        p1 = ((EXP1 / (s * 1.0)) + 80) / 123.0;
    p1 = round(p1 * 100) / 100;

    //con đường 2:
    int nuatienbandau = (int)(0.5 * M1bandau) + (0.5 * M1bandau - (int)(0.5 * M1bandau) > 0);
    if (E2 % 2 != 0)
    {
        while (1)
        {

            if (HP1 < 200)
            {
                resulthp1 = resulthp1 * 1.3;
                M1 = M1 - 150;
            }
            else
            {
                resulthp1 = resulthp1 * 1.1;
                M1 = M1 - 70;
            }
            HP1 = (int)resulthp1 + (resulthp1 - (int)resulthp1 > 0);
            resulthp1 = HP1;
            if (EXP1 <= 0)
                EXP1 = 0;
            if (HP1 <= 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
            if ((M1bandau - M1) > nuatienbandau)
                break;

            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else
            {
                M1 = M1 - 120;
            }
            result1 = result1 * 1.13;
            EXP1 = (int)result1 + (result1 - (int)result1 > 0);
            result1 = EXP1;
            if (EXP1 <= 0)
                EXP1 = 0;
            if (HP1 <= 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
            if ((M1bandau - M1) > nuatienbandau)
                break;

            if (EXP1 < 300)
            {
                M1 = M1 - 100;

            }
            else
            {
                M1 = M1 - 120;
            }
            result1 = result1 * 0.9;
            EXP1 = (int)result1 + (result1 - (int)result1 > 0);
            result1 = EXP1;
            resulthp1 = HP1;
            if (EXP1 <= 0)
                EXP1 = 0;
            if (HP1 <= 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;

            if ((M1bandau - M1) > nuatienbandau)
                break;
        }
        resulthp1 = resulthp1 * 0.83;
        result1 = result1 * 1.17;
        EXP1 = (int)result1 + (result1 - (int)result1 > 0);
        result1 = EXP1;
        HP1 = (int)resulthp1 + (resulthp1 - (int)resulthp1 > 0);
        resulthp1 = HP1;
        if (EXP1 <= 0)
            EXP1 = 0;
        if (HP1 <= 0)
            HP1 = 0;
        if (EXP1 > 600)
            EXP1 = 600;
        if (HP1 > 666)
            HP1 = 666;
    }
    else
    {
        do
        {

            if (HP1 < 200)
            {
                resulthp1 = resulthp1 * 1.3;
                M1 = M1 - 150;
            }
            else
            {
                resulthp1 = resulthp1 * 1.1;
                M1 = M1 - 70;
            }
            HP1 = (int)resulthp1 + (resulthp1 - (int)resulthp1 > 0);
            resulthp1 = HP1;
            if (EXP1 <= 0)
                EXP1 = 0;
            if (HP1 <= 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
            if (M1 <= 0)
                break;

            if (EXP1 < 400)
            {
                M1 = M1 - 200;
            }
            else
            {
                M1 = M1 - 120;
            }
            result1 = result1 * 1.13;
            EXP1 = (int)result1 + (result1 - (int)result1 > 0);
            result1 = EXP1;
            if (EXP1 <= 0)
                EXP1 = 0;
            if (HP1 <= 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
            if (M1 <= 0)
                break;

            if (EXP1 < 300)
            {
                M1 = M1 - 100;

            }
            else
            {
                M1 = M1 - 120;
            }
            result1 = result1 * 0.9;
            EXP1 = (int)result1 + (result1 - (int)result1 > 0);
            result1 = EXP1;
            if (EXP1 <= 0)
                EXP1 = 0;
            if (HP1 <= 0)
                HP1 = 0;
            if (EXP1 > 600)
                EXP1 = 600;
            if (HP1 > 666)
                HP1 = 666;
            resulthp1 = HP1;
            if (M1 <= 0)
                break;
        } while (0);
        resulthp1 = resulthp1 * 0.83;
        result1 = result1 * 1.17;
        EXP1 = (int)result1 + (result1 - (int)result1 > 0);
        result1 = EXP1;
        HP1 = (int)resulthp1 + (resulthp1 - (int)resulthp1 > 0);
        resulthp1 = HP1;
        if (EXP1 <= 0)
            EXP1 = 0;
        if (HP1 <= 0)
            HP1 = 0;
        if (EXP1 > 600)
            EXP1 = 600;
        if (HP1 > 666)
            HP1 = 666;
    }
    for (int i = EXP1;i > 1;i--)
    {
        if (i == (int)sqrt(i) * (int)sqrt(i))
        {
            s1 = i;
            break;
        }
    }
    for (int i = EXP1;i < 10000;i++)
    {
        if (i == (int)sqrt(i) * (int)sqrt(i))
        {
            s2 = i;
            break;
        }
    }
    if ((s2 - EXP1) >= (EXP1 - s1))
        s = s1;
    else
        s = s2;

    double p2;
    if (EXP1 >= s)
        p2 = 100 / 100;
    else
        p2 = ((EXP1 / (s * 1.0)) + 80) / 123.0;
    p2 = round(p2 * 100) / 100;

    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    double p3;
    if (E2 < 10)
        p3 = P[E2] / 100.0;
    if (E2 >= 10)
        p3 = P[(E2 % ((E2 / 10) * 10) + E2 / 10) % 10] / 100.0;

    //sau đi 3 đường
    resulthp1 = HP1;
    result1 = EXP1;
    double tb = (p1 + p2 + p3) / 3;
    if (p1 == 100 / 100 && p2 == 100 / 100 && p3 == 100 / 100)
        result1 = result1 * 0.75;
    else
    {

        if (tb < 0.5)
        {
            resulthp1 = resulthp1 * 0.85;
            result1 = result1 * 1.15;
        }
        else
        {
            resulthp1 = resulthp1 * 0.9;
            result1 = result1 * 1.2;
        }
    }

    EXP1 = (int)result1 + (result1 - (int)result1 > 0);
    HP1 = (int)resulthp1 + (resulthp1 - (int)resulthp1 > 0);
    if (EXP1 <= 0)
        EXP1 = 0;
    if (HP1 <= 0)
        HP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 > 666)
        HP1 = 666;
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99)
        return -99;
    if (EXP1 <= 0)
        EXP1 = 0;
    if (HP1 <= 0)
        HP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP2 <= 0)
        EXP2 = 0;
    if (HP2 <= 0)
        HP2 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
    if (HP2 > 666)
        HP2 = 666;
    double result1, resulthp1, result2, resulthp2;
    result1 = EXP1;
    result2 = EXP2;
    resulthp1 = HP1;
    resulthp2 = HP2;
    int mang[10][10] = { 0 };

    for (int i = 0;i < 10;++i)
    {
        for (int j = 0;j < 10;++j)
        {
            mang[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    
    int gtd = 0;
    int gta = 0;

    for (int i = 0;i < 10;++i)
    {
        for (int j = 0;j < 10;++j)
        {
            if (mang[i][j] > (E3 * 2))
                gtd = gtd+1;
            if (mang[i][j] < (-E3))
            {
                gta = gta+1;
            }
        }
  
    }
   
    while (gtd >= 10)
    {
        gtd = gtd / 10 + gtd % 10;
    }
    while (gta >= 10)
    {
        gta = gta / 10 + gta % 10;
    }
   
    int diemtaxi = mang[gtd][gta];
    
    int max = diemtaxi;
    int dem = 0;
    while (!(gtd - dem < 0 || gtd - dem>9 || gta - dem < 0 || gta - dem>9))
    {
        if (mang[gtd - dem][gta - dem] > max)
            max = mang[gtd - dem][gta - dem];
        dem++;
    }
    dem = 0;
    while (!(gtd + dem < 0 || gtd + dem>9 || gta + dem < 0 || gta + dem>9))
    {
        if (mang[gtd + dem][gta + dem] > max)
            max = mang[gtd + dem][gta + dem];
        dem++;
    }
    dem = 0;
    while (!(gtd + dem < 0 || gtd + dem>9 || gta - dem < 0 || gta - dem>9))
    {

        if (mang[gtd + dem][gta - dem] > max)
            max = mang[gtd + dem][gta - dem];
        dem++;
    }
    dem = 0;
    while (!(gtd - dem < 0 || gtd - dem>9 || gta + dem < 0 || gta + dem>9))
    {
        if (mang[gtd - dem][gta + dem] > max)
            max = mang[gtd - dem][gta + dem];
        dem++;
    }

    if (abs(diemtaxi) > max)
    {
        result1 = result1 * 0.88;
        resulthp1 = resulthp1 * 0.9;
        result2 = result2 * 0.88;
        resulthp2 = resulthp2 * 0.9;
    }
    else
    {
        result1 = result1 * 1.12;
        resulthp1 = resulthp1 * 1.1;
        result2 = result2 * 1.12;
        resulthp2 = resulthp2 * 1.1;
    }
    EXP1 = (int)result1 + (result1 - (int)result1 > 0);
    HP1 = (int)resulthp1 + (resulthp1 - (int)resulthp1 > 0);
    EXP2 = (int)result2 + (result2 - (int)result2 > 0);
    HP2 = (int)resulthp2 + (resulthp2 - (int)resulthp2 > 0);


    if (EXP1 <= 0)
        EXP1 = 0;
    if (HP1 <= 0)
        HP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP2 <= 0)
        EXP2 = 0;
    if (HP2 <= 0)
        HP2 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
    if (HP2 > 666)
        HP2 = 666;
    if (abs(diemtaxi) > abs(max))
        return diemtaxi;
    else
        return max;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100];
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    bool chuso = false;
    bool chuthuong = false;
    bool chuhoa = false;
    bool dacbiet = false;
    for (int i = 0;i < strlen(email);i++)
    {

        if (email[i] == '@')
        {
            se[i] = '\0';
            break;
        }
        se[i] = email[i];

    }

    for (int i = 0;i < strlen(s);i++)
    {
        if (isdigit(s[i]))
            chuso = true;
        if (islower(s[i]))
            chuthuong = true;
        if (isupper(s[i]))
            chuhoa = true;
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            dacbiet = true;
    }
    bool laplai = false;
    int vitrilaplai = 0;
    for (int i = 1;i < strlen(s);i++)
    {
        if ((s[i] == s[i + 1]) && (s[i] == s[i - 1]))
        {
            laplai = true;
            vitrilaplai = i - 1;
        }
    }
   
    int vitrichua = 0;
    bool chua = false;
    for (int i = 0;i < strlen(s);i++)
    {
        int j;
        for (j = 0;j < strlen(se);j++)
        {
            if (s[i + j] != se[j])

                break;
        }

        if (j == strlen(se))
        {
            vitrichua = i;
            chua = true;
            break;

        }
    }
    
    if (strlen(s) >= 8 && strlen(s) <= 20)
        if (chuso && chuthuong && chuhoa && dacbiet)
            if (!chua)
                if (!laplai)
                    if (dacbiet)
                        return -10;
    if (chua)
        return -(300 + vitrichua);
    if (laplai)
        return -(400 + vitrilaplai);
    if (!dacbiet)
        return -5;
    if (strlen(s) < 8)
        return strlen(s);
    if (strlen(s) > 20)
        return 20;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr[30];
    for (int i = 0;i < num_pwds;i++)
    {
        arr[i] = arr_pwds[i];
    }
    int dem[30] = { 0 };

    for (int i = 0;i < num_pwds;i++)
    {
        if (arr[i] != "")
            dem[i] = 1;
        for (int j = 0;j < num_pwds;j++)
        {

            if (i != j)
            {

                if (arr[i] == arr[j] && arr[j] != "" && arr[i] != "")
                {
                    dem[i] = dem[i]+1;
                    arr[j] = "";
                }
            }
        }
    }
    int max = dem[0], idx = 0;
    for (int i = 0;i < num_pwds;i++)
    {
        if (dem[i] > max)
        {
            max = dem[i];
            idx = i;
        }
    }
    int maxlength = 0;
    string longlength = "";
    for (int i = 0;i < num_pwds;i++)
    {
        if (dem[i] != max)
            arr[i] = "";
    }
    for (int i = 0;i < num_pwds;i++)
    {

        for (const string& str : arr)
        {
            if (str.length() > maxlength)
            {
                maxlength = str.length();
                longlength = str;
            }
        }
    }
    for (int i = 0;i < num_pwds;i++)
    {
        if (longlength == arr[i])
            return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////