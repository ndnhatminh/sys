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
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    double u = static_cast<double>(e1);
    double exp01 = static_cast<double>(exp1);
    double exp02 = static_cast<double>(exp2);

    if (exp01 > 600)
    {
        exp01 = 600;
    }
    else if (exp01 < 0)
    {
        exp01 = 0;
    }
    if (exp02 > 600)
    {
        exp02 = 600;
    }
    else  if (exp02 < 0)
    {
        exp02 = 0;
    }

    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    else if (e1 == 0)
    {
        exp02 = exp02 + 29;

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 == 1)
    {
        exp02 = exp02 + 45;

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 == 2)
    {
        exp02 = exp02 + 75;

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 == 3)
    {
        exp02 = exp02 + 29 + 45 + 75;

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 >= 4 && e1 <= 19)
    {
        exp02 = u / 4 + 19 + exp02;
        exp02 = ceil(exp02);

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp02 = u * 1 / 9 + 21 + exp02;
        exp02 = ceil(exp02);

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp02 = u / 16 + 17 + exp02;
        exp02 = ceil(exp02);

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp02 = u / 4 + 19 + exp02 + exp02;
        exp02 = ceil(exp02);

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }

        if (exp02 > 200)
        {
            exp02 = u / 9 + 21 + exp02;
            exp02 = ceil(exp02);

            if (exp02 > 600)
            {
                exp02 = 600;
            }
            else  if (exp02 < 0)
            {
                exp02 = 0;
            }
        }
        else
        {
            exp02 = ceil(exp02);

            if (exp02 > 600)
            {
                exp02 = 600;
            }
            else  if (exp02 < 0)
            {
                exp02 = 0;
            }
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp02 = u / 4 + 19 + e1 / 9 + 21 + exp02;
        exp2 = ceil(exp02);

        if (exp02 > 600)
        {
            exp02 = 600;
        }
        else  if (exp02 < 0)
        {
            exp02 = 0;
        }

        if (exp02 > 400)
        {
            exp02 = u / 16 + 17 + exp02 + exp02 * 3 / 20;
            exp02 = ceil(exp02);

            if (exp02 > 600)
            {
                exp02 = 600;
            }
            else  if (exp02 < 0)
            {
                exp02 = 0;
            }
        }
        else
        {
            exp02 = exp02;
            exp02 = ceil(exp02);

            if (exp02 > 600)
            {
                exp02 = 600;
            }
            else  if (exp02 < 0)
            {
                exp02 = 0;
            }
        }
    }
    if (e1 >= 4 && e1 <= 99)
    {
        exp01 = exp01 - u;

        if (exp01 > 600)
        {
            exp01 = 600;
        }
        else if (exp01 < 0)
        {
            exp01 = 0;
        }
    }
    else if (e1 >= 0 && e1 <= 3)
    {
        double d = u * 3 + exp01 * 7;
        int c = e1 * 3 + exp01 * 7;
        if (c % 2 == 0)
        {
            exp01 = exp01 + d / 200;
            exp01 = ceil(exp01);

            if (exp01 > 600)

                exp01 = 600;

            else if (exp01 < 0)

                exp01 = 0;

        }
        else
        {
            exp01 = exp01 - d / 100;
            exp01 = ceil(exp01);

            if (exp01 > 600)

                exp01 = 600;

            else if (exp01 < 0)

                exp01 = 0;

        }
    }

    exp1 = static_cast<int>(exp01);
    exp2 = static_cast<int>(exp02);

    cout << exp1 << endl << exp2 << endl;

    return exp1 + exp2;
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function

    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }

    double hp01 = static_cast<double>(HP1);
    double exp01 = static_cast<double>(EXP1);

    if (hp01 > 666)
    {
        hp01 = 666;
    }
    else if (hp01 < 0)
    {
        hp01 = 0;
    }
    if (exp01 > 600)
    {
        exp01 = 600;
    }
    else if (exp01 < 0)
    {
        exp01 = 0;
    }

    //Con duong 01
    //Tim so chinh phuong gan nhat
    int square = (int)sqrt(EXP1);
    int S1;
    if (EXP1 == square * square)
    {
        S1 = EXP1;
    }
    else
    {
        int lower = EXP1 - square * square;
        int upper = (square + 1) * (square + 1) - EXP1;
        if (lower < upper)
        {
            S1 = square * square;
        }
        else  S1 = (square + 1) * (square + 1);
    }
    //Tim P1
    double P1;
    if (EXP1 >= S1)
    {
        P1 = 1.0;
    }
    else P1 = ((exp01 / S1 + 80) / 123);


    //Con duong 02
    if (M1 == 0)
    {

        hp01 = 0.83 * hp01;
        hp01 = ceil(hp01);

        exp01 = 1.17 * exp01;
        exp01 = ceil(exp01);

        if (exp01 > 600)
        {
            exp01 = 600;
        }
        else if (exp01 < 0)
        {
            exp01 = 0;
        }
        if (hp01 > 666)
        {
            hp01 = 666;
        }
        else if (hp01 < 0)
        {
            hp01 = 0;
        }
    }


    if (E2 % 2 == 0)
    {
        if (hp01 < 200)
        {
            hp01 = 1.3 * hp01;
            hp01 = ceil(hp01);

            M1 = M1 - 150;

            if (hp01 > 666)
            {
                hp01 = 666;
            }
            else if (hp01 < 0)
            {
                hp01 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
        }
        else if (hp01 >= 200)
        {
            hp01 = 1.1 * hp01;
            hp01 = ceil(hp01);

            M1 = M1 - 70;

            if (hp01 > 666)
            {
                hp01 = 666;
            }
            else if (hp01 < 0)
            {
                hp01 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
        }

        if (exp01 < 400 && M1 > 0)
        {
            M1 = M1 - 200;

            exp01 = exp01 * 1.13;
            exp01 = ceil(exp01);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
        }
        else if (exp01 >= 400 && M1 > 0)
        {
            M1 = M1 - 120;

            exp01 = exp01 * 1.13;
            exp01 = ceil(exp01);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
        }


        if (exp01 < 300 && M1 > 0)
        {
            M1 = M1 - 100;

            exp01 = exp01 * 0.9;
            exp01 = ceil(exp01);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
        }
        else if (exp01 >= 300 && M1 > 0)
        {
            M1 = M1 - 120;

            exp01 = exp01 * 0.9;
            exp01 = ceil(exp01);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
            if (M1 > 3000)
            {
                M1 = 3000;
            }
            else if (M1 < 0)
            {
                M1 = 0;
            }
        }
        hp01 = 0.83 * hp01;
        hp01 = ceil(hp01);

        exp01 = 1.17 * exp01;
        exp01 = ceil(exp01);

        if (exp01 > 600)
        {
            exp01 = 600;
        }
        else if (exp01 < 0)
        {
            exp01 = 0;
        }
        if (hp01 > 666)
        {
            hp01 = 666;
        }
        else if (hp01 < 0)
        {
            hp01 = 0;
        }
    }
    else if (E2 % 2 != 0)
    {
        double check = M1 * 1 / 2;
        check = ceil(check);
        while (M1 >= check)
        {
            if (hp01 < 200 && M1 >= check)
            {
                hp01 = 1.3 * hp01;
                hp01 = ceil(hp01);

                M1 = M1 - 150;

                if (hp01 > 666)
                {
                    hp01 = 666;
                }
                else if (hp01 < 0)
                {
                    hp01 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }
            else if (hp01 >= 200 && M1 >= check)
            {
                hp01 = 1.1 * hp01;
                hp01 = ceil(hp01);

                M1 = M1 - 70;

                if (hp01 > 666)
                {
                    hp01 = 666;
                }
                else if (hp01 < 0)
                {
                    hp01 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }

            if (exp01 < 400 && M1 >= check)
            {
                M1 = M1 - 200;

                exp01 = exp01 * 1.13;
                exp01 = ceil(exp01);

                if (exp01 > 600)
                {
                    exp01 = 600;
                }
                else if (exp01 < 0)
                {
                    exp01 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }
            else if (exp01 >= 400 && M1 >= check)
            {
                M1 = M1 - 120;

                exp01 = exp01 * 1.13;
                exp01 = ceil(exp01);

                if (exp01 > 600)
                {
                    exp01 = 600;
                }
                else if (exp01 < 0)
                {
                    exp01 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }

            if (exp01 < 300 && M1 >= check)
            {
                M1 = M1 - 100;

                exp01 = exp01 * 0.9;
                exp01 = ceil(exp01);

                if (exp01 > 600)
                {
                    exp01 = 600;
                }
                else if (exp01 < 0)
                {
                    exp01 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }
            else if (exp01 >= 300 && M1 >= check)
            {
                M1 = M1 - 120;

                exp01 = exp01 * 0.9;
                exp01 = ceil(exp01);

                if (exp01 > 600)
                {
                    exp01 = 600;
                }
                else if (exp01 < 0)
                {
                    exp01 = 0;
                }
                if (M1 > 3000)
                {
                    M1 = 3000;
                }
                else if (M1 < 0)
                {
                    M1 = 0;
                }
            }
        }
        hp01 = 0.83 * hp01;
        hp01 = ceil(hp01);

        exp01 = 1.17 * exp01;
        exp01 = ceil(exp01);

        if (exp01 > 600)
        {
            exp01 = 600;
        }
        else if (exp01 < 0)
        {
            exp01 = 0;
        }
        if (hp01 > 666)
        {
            hp01 = 666;
        }
        else if (hp01 < 0)
        {
            hp01 = 0;
        }

    }
    //Tim S2
    double square2 = sqrt(exp01);
    square2 = round(square2);
    double S2;
    if (exp01 == square2 * square2)
    {
        S2 = exp01;
    }
    else
    {
        double lower = exp01 - square2 * square2;
        double upper = (square2 + 1) * (square2 + 1) - exp01;
        if (lower < upper)
        {
            S2 = square2 * square2;
        }
        else  S2 = (square2 + 1) * (square2 + 1);
    }
    //Tim P2
    double P2;
    if (exp01 >= S2)
    {
        P2 = 1.0;
    }
    else P2 = ((exp01 / S2 + 80) / 123);

    //Con duong 03
    double P3;
    double P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    if (E2 % 10 == 0)
    {
        P3 = P[E2];
    }
    else
    {
        int chiso = (E2 % 10 + E2 / 10) % 10;
        P3 = P[chiso] / 100;
    }

    //Sau 3 con duong
    if (P1 == P2 && P2 == P3 && P1 == 1)
    {
        exp01 = exp01 * 0.75;
        exp01 = ceil(exp01);

        if (exp01 > 600)
        {
            exp01 = 600;
        }
        else if (exp01 < 0)
        {
            exp01 = 0;
        }
    }
    else
    {
        double tongP = (P1 + P2 + P3) / 3;
        tongP = ceil(tongP * 100);
        if (tongP < 50)
        {
            hp01 = 0.85 * hp01;
            hp01 = ceil(hp01);

            exp01 = 1.15 * exp01;
            exp01 = ceil(exp01);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
            if (hp01 > 666)
            {
                hp01 = 666;
            }
            else if (hp01 < 0)
            {
                hp01 = 0;
            }
        }
        else
        {
            hp01 = 0.9 * hp01;
            hp01 = ceil(hp01);

            exp01 = 1.2 * exp01;
            exp01 = ceil(exp01);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
            if (hp01 > 666)
            {
                hp01 = 666;
            }
            else if (hp01 < 0)
            {
                hp01 = 0;
            }
        }
    }

    HP1 = static_cast<int>(hp01);
    EXP1 = static_cast<int>(exp01);

    cout << E2 << endl << HP1 << endl << EXP1 << endl << M1 << endl;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
    {
        if (E3 < 0 || E3 > 99)
        {
            return -99;
        }

        int taxi[10][10] = { 0 };
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }


        int lon = 0; int nho = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (taxi[i][j] > E3 * 2)
                    lon++;
                if (taxi[i][j] < -E3)
                    nho++;
            }
        }
        int hang = lon;
        if (lon < 10)
        {
            hang = lon;
        }
        else
        {
            hang = lon % 10 + lon / 10;
        }
        if (hang > 9)
        {
            hang = hang % 10 + hang / 10;
        }

        int cot = nho;
        if (cot < 10)
        {
            cot = nho;
        }
        else
        {
            cot = nho % 10 + nho / 10;
        }
        if (cot > 9)
        {
            cot = cot % 10 + cot / 10;
        }


        int SW[10][10] = { 0 };
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {

                int cheo1 = taxi[i][j];
                for (int n = 0; n < min(i, j); n++)
                {
                    if (cheo1 <= taxi[i - n][j - n])
                        cheo1 = taxi[i - n][j - n];
                }


                int cheo2 = taxi[i][j];
                for (int n = 0; n < min(10 - i, j); n++)
                {
                    if (cheo2 <= taxi[i + n][j - n])
                        cheo2 = taxi[i + n][j - n];
                }
                if (cheo1 > cheo2)
                {
                    SW[i][j] = cheo1;
                }
                else
                {
                    SW[i][j] = cheo2;
                }
                SW[i][j] = abs(SW[i][j]);
            }
        }


        double exp01 = static_cast<double>(EXP1);
        double exp02 = static_cast<double>(EXP2);
        double hp01 = static_cast<double>(HP1);
        double hp02 = static_cast<double>(HP2);

        if (SW[hang][cot] >= abs(taxi[hang][cot]))
        {
            exp01 = exp01 * 1.12;
            exp01 = ceil(exp01);

            exp02 = exp02 * 1.12;
            exp02 = ceil(exp02);

            hp01 = hp01 * 1.1;
            hp01 = ceil(hp01);

            hp02 = hp02 * 1.1;
            hp02 = ceil(hp02);

            if (exp01 > 600)
            {
                exp01 = 600;
            }
            else if (exp01 < 0)
            {
                exp01 = 0;
            }
             if (exp02 > 600)
                {
                    exp02 = 600;
                }
                else  if (exp02 < 0)
                {
                    exp02 = 0;
                }
                if (hp01 > 666)
                {
                    hp01 = 666;
                }
                else if (hp01 < 0)
                {
                    hp01 = 0;
                }
                if (hp02 > 666)
                {
                    hp02 = 666;
                }
                else if (hp02 < 0)
                {
                    hp02 = 0;
                }
            
        }
        else
        {
            exp01 = exp01 * 0.88;
            exp01 = ceil(exp01);

            exp02 = exp02 * 0.88;
            exp02 = ceil(exp02);

            hp01 = hp01 * 0.9;
            hp01 = ceil(hp01);

            hp02 = hp02 * 0.9;
            hp02 = ceil(hp02);

            if (exp02 > 600)
            {
                exp02 = 600;
            }
            else  if (exp02 < 0)
            {
                exp02 = 0;
            }
            if (hp01 > 666)
            {
                hp01 = 666;
            }
            else if (hp01 < 0)
            {
                hp01 = 0;
            }
            if (hp02 > 666)
            {
                hp02 = 666;
            }
            else if (hp02 < 0)
            {
                hp02 = 0;
            }
        }

        EXP1 = static_cast<int>(exp01);
        EXP2 = static_cast<int>(exp02);
        HP1 = static_cast<int>(hp01);
        HP2 = static_cast<int>(hp02);

        if (SW[hang][cot] >= abs(taxi[hang][cot]))
        {
            return SW[hang][cot];
        }
        else return taxi[hang][cot];
    }


// Task 4
int checkPassword(const char * s, const char * email) {
    string pass(s);
    string mail(email);
    string se = mail.substr(0, mail.find("@"));

    if (pass.size() < 8)
    {
        return -1;
    }
    if (pass.size() > 20)
    {
        return -2;
    }

    if (pass.find(se) != string::npos)
    {
        return -(300 + pass.find(se));
    }

    for (int i = 0; i < (pass.size() - 2); i++)
    {
        if (pass[i] == pass[i + 1] && pass[i + 1] == pass[i + 2])
            return -(400 + i);
    }

    string dacbiet = "@#%$!";
    for (int i = 0; i < dacbiet.length(); i++)
    {
        for (int j = 0; j < pass.length(); j++)
        {
            if (dacbiet[i] != pass[j])
                return -5;
        }
    }

    for (char x : pass)
    {
        if (isdigit(x) == 0 || isalpha(x) == 0)
        {
            return x;
        }
    }
    return -10;

}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int nhieunhat = 0;
    int dainhat = 0;
    int pass = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        int lan = 0; 
        int dai = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                lan++;
        }
        if (lan > nhieunhat )
        {
            nhieunhat = lan;
            dainhat = dai;
            pass = i;
        }
        else if (lan == nhieunhat && dai > dainhat)
        {
            nhieunhat = lan;
            dainhat = dai;
            pass = i;
        }
    }
    return pass;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////