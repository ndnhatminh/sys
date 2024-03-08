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

int firstMeet(int &exp1, int &exp2, int e1)
{
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }

    exp1 = exp1 > 600 ? 600 : std::ceil(exp1);
    exp2 = exp2 > 600 ? 600 : std::ceil(exp2);
    exp1 = exp1 < 0 ? 0 : std::ceil(exp1);
    exp2 = exp2 < 0 ? 0 : std::ceil(exp2);

    // Case1
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
    if (e1 >= 0 && e1 <= 3)
    {
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = ceil(double(exp1 + float(D) / 200) - 1e-10);
            exp1 = exp1 > 600 ? 600 : std::ceil(exp1);
            exp2 = exp2 > 600 ? 600 : std::ceil(exp2);
            exp1 = exp1 < 0 ? 0 : std::ceil(exp1);
            exp2 = exp2 < 0 ? 0 : std::ceil(exp2);
        }
        else if (D % 2 != 0)
        {
            exp1 = ceil(double(exp1 - float(D) / 100) - 1e-10);
            exp1 = exp1 > 600 ? 600 : std::ceil(exp1);
            exp2 = exp2 > 600 ? 600 : std::ceil(exp2);
            exp1 = exp1 < 0 ? 0 : std::ceil(exp1);
            exp2 = exp2 < 0 ? 0 : std::ceil(exp2);
        }
    }

    // Case 2
    if (e1 >= 4 && e1 <= 19)
    {
        exp1 = exp1 - e1;
        exp2 = std::ceil(exp2 + (double(e1) / 4 + 19));
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp1 = exp1 - e1;
        exp2 = std::ceil(exp2 + (double(e1) / 9 + 21));
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp1 = exp1 - e1;
        exp2 = std::ceil(exp2 + (double(e1) / 16 + 17));
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp1 = exp1 - e1;
        exp2 = std::ceil(exp2 + (double(e1) / 4 + 19));
        if (exp2 > 200)
        {
            exp2 = std::ceil(exp2 + ((double(e1) / 9 + 21)));
        }
    }
    else if (e1 >= 80 && e1 <= 99)
    {
        exp1 = exp1 - e1;
        exp2 = std::ceil(exp2 + (double(e1) / 4 + 19));
        exp2 = std::ceil(exp2 + (double(e1) / 9 + 21));
        if (exp2 > 400)
        {
            exp2 = std::ceil(exp2 + ((double(e1) / 16 + 17)));
            exp2 = std::ceil(exp2 + 0.15 * exp2);
        }
    }

    // Check the condition again
    exp1 = exp1 > 600 ? 600 : std::ceil(exp1);
    exp2 = exp2 > 600 ? 600 : std::ceil(exp2);
    exp1 = exp1 < 0 ? 0 : std::ceil(exp1);
    exp2 = exp2 < 0 ? 0 : std::ceil(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    double XS1, XS2, XS3;
    // CHECKING THE CONDITION
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
    M1 = M1 > 3000 ? 3000 : ceil(M1 - 1e-10);
    M1 = M1 < 0 ? 0 : ceil(M1 - 1e-10);

    // CHECKING PERFECT SQUARE AND ROAD 01
    double CBH1 = sqrt(EXP1);
    int CBH_DOWN1 = pow(floor(CBH1), 2);
    int CBH_UP1 = pow(floor(CBH1) + 1, 2);
    int KCTREN1 = CBH_UP1 - EXP1;
    int KCDUOI1 = EXP1 - CBH_DOWN1;
    if (KCTREN1 > KCDUOI1)
    {
        XS1 = 100.00;
    }
    else
    {
        XS1 = (double(EXP1) / CBH_UP1 + 80) / 123 * 100;
    }

    // ROAD 02
    while (E2 % 2 == 0)
    {
        if (M1 == 0)
        {
            EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
            HP1 = ceil(double(HP1 * 0.83 - 1e-10));
            HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
            HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
            EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
            EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
            break;
        }
        if (HP1 < 200)
        {
            HP1 = ceil(double(HP1 * 1.3 - 1e-10));
            M1 -= 150;
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
        else if (HP1 >= 200)
        {
            HP1 = ceil(double(HP1 * 1.1 - 1e-10));
            M1 -= 70;
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
        HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
        HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
        EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
        EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
        if (M1 == 0)
        {
            EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
            HP1 = ceil(double(HP1 * 0.83 - 1e-10));
            HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
            HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
            EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
            EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
            break;
        }

        if (EXP1 < 400)
        {
            M1 -= 200;
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
        else if (EXP1 >= 400)
        {
            M1 -= 120;
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
        EXP1 = ceil(double(EXP1 * 1.13 - 1e-10));

        HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
        HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
        EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
        EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
        if (M1 == 0)
        {
            EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
            HP1 = ceil(double(HP1 * 0.83 - 1e-10));
            HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
            HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
            EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
            EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
            break;
        }
        if (EXP1 < 300)
        {
            M1 -= 100;
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
        else if (EXP1 >= 300)
        {
            M1 -= 120;
            if (M1 < 0)
            {
                M1 = 0;
            }
        }
        EXP1 = ceil(double(EXP1 * 0.9 - 1e-10));
        if (M1 == 0)
        {
            EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
            HP1 = ceil(double(HP1 * 0.83 - 1e-10));
            HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
            HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
            EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
            EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
            break;
        }
        HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
        HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
        EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
        EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
        EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
        HP1 = ceil(double(HP1 * 0.83 - 1e-10));
        HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
        HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
        EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
        EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
        break;
    }

    while (E2 % 2 != 0)
    {
        double HAN_MUC = double(M1) * 0.5;
        double M3 = 0.0;
        if (M1 == 0)
        {
            EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
            HP1 = ceil(double(HP1 * 0.83 - 1e-10));
            HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
            HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
            EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
            EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);

            break;
        }

        double temp = 0.0;
        while (temp <= HAN_MUC)
        {
            M3 = M1;
            if (HP1 < 200)
            {
                HP1 = ceil(double(HP1 * 1.3 - 1e-10));
                temp += 150;
                HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);

                if (temp > HAN_MUC)
                {
                    M3 = M3 - temp;
                    M1 = M3;
                    EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
                    HP1 = ceil(double(HP1 * 0.83 - 1e-10));
                    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                    break;
                }
            }
            else
            {
                HP1 = ceil(double(HP1 * 1.1 - 1e-10));
                temp += 70;
                HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);

                if (temp > HAN_MUC)
                {
                    M3 = M3 - temp;
                    M1 = M3;
                    EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
                    HP1 = ceil(double(HP1 * 0.83 - 1e-10));
                    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                    break;
                }
            }

            if (EXP1 < 400)
            {
                EXP1 = ceil(double(EXP1 * 1.13 - 1e-10));
                temp += 200;
                HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);

                if (temp > HAN_MUC)
                {
                    M3 = M3 - temp;
                    M1 = M3;
                    EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
                    HP1 = ceil(double(HP1 * 0.83 - 1e-10));
                    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                    break;
                }
            }
            else
            {
                EXP1 = ceil(double(EXP1 * 1.13 - 1e-10));
                temp += 120;
                HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                if (temp > HAN_MUC)
                {
                    M3 = M3 - temp;
                    M1 = M3;
                    EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
                    HP1 = ceil(double(HP1 * 0.83 - 1e-10));
                    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                    break;
                }
            }

            if (EXP1 < 300)
            {
                EXP1 = ceil(double(EXP1 * 0.9 - 1e-10));
                temp += 100;
                HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);

                if (temp > HAN_MUC)
                {
                    M3 = M3 - temp;
                    M1 = M3;
                    EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
                    HP1 = ceil(double(HP1 * 0.83 - 1e-10));
                    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                    break;
                }
            }
            else
            {
                EXP1 = ceil(double(EXP1 * 0.9 - 1e-10));
                temp += 120;
                HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                if (temp > HAN_MUC)
                {
                    M3 = M3 - temp;
                    M1 = M3;
                    EXP1 = ceil(double(EXP1 * 1.17 - 1e-10));
                    HP1 = ceil(double(HP1 * 0.83 - 1e-10));
                    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
                    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
                    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
                    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
                    break;
                }
            }
        }
        if (temp > HAN_MUC)
            break;
    }
    double CBH2 = sqrt(EXP1);
    int CBH_DOWN2 = pow(floor(CBH2), 2);
    int CBH_UP2 = pow(floor(CBH2) + 1, 2);
    int KCTREN2 = CBH_UP2 - EXP1;
    int KCDUOI2 = EXP1 - CBH_DOWN2;
    if (KCTREN2 > KCDUOI2)
    {
        XS2 = 100;
    }
    else
    {
        XS2 = (double(EXP1) / CBH_UP2 + 80) / 123 * 100;
    }
    // ROAD 03
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int chiso = E2;
    if (chiso < 10)
    {
        XS3 = P[chiso];
    }
    else
    {
        int sum = 0;
        while (chiso != 0)
        {
            sum += chiso % 10;
            chiso = chiso / 10;
        }
        XS3 = P[sum % 10];
    }
    double TONGXACSUAT = (XS1 + XS2 + XS3) / 3;
    double Tong = XS1 + XS2 + XS3;

    if (Tong == 300.0)
    {
        EXP1 = ceil(double(EXP1 * 0.75 - 1e-10));
    }
    if (TONGXACSUAT < 50.00)
    {
        HP1 = ceil(double(HP1 * 0.85 - 1e-10));
        EXP1 = ceil(double(EXP1 * 1.15 - 1e-10));
    }
    else if (TONGXACSUAT > 50.00 && TONGXACSUAT != 100)
    {
        HP1 = ceil(double(HP1 * 0.9 - 1e-10));
        EXP1 = ceil(double(EXP1 * 1.2 - 1e-10));
    }
    // CHECKING THE CONDITION AGAIN
    HP1 = HP1 > 666 ? 666 : ceil(HP1 - 1e-10);
    HP1 = HP1 < 0 ? 0 : ceil(HP1 - 1e-10);
    EXP1 = EXP1 > 600 ? 600 : ceil(EXP1 - 1e-10);
    EXP1 = EXP1 < 0 ? 0 : ceil(EXP1 - 1e-10);
    M1 = M1 > 3000 ? 3000 : ceil(M1 - 1e-10);
    M1 = M1 < 0 ? 0 : ceil(M1 - 1e-10);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // CHECKING THE CONDTION
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    HP1 = HP1 > 666 ? 666 : std::ceil(HP1 - 1e-10);
    HP1 = HP1 < 0 ? 0 : std::ceil(HP1 - 1e-10);
    EXP1 = EXP1 > 600 ? 600 : std::ceil(EXP1 - 1e-10);
    EXP1 = EXP1 < 0 ? 0 : std::ceil(EXP1 - 1e-10);
    HP2 = HP2 > 666 ? 666 : std::ceil(HP2 - 1e-10);
    HP2 = HP2 < 0 ? 0 : std::ceil(HP2 - 1e-10);
    EXP2 = EXP2 > 600 ? 600 : std::ceil(EXP2 - 1e-10);
    EXP2 = EXP2 < 0 ? 0 : std::ceil(EXP2 - 1e-10);

    // chaseTaxi
    int array[10][10]; // Initializing all elements to 0
    int am = 0;
    int duong = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (array[i][j] < -E3)
            {
                am++;
            }
            else if (array[i][j] > (E3 * 2))
            {
                duong++;
            }
        }
    }
    /*cout << am << " " << duong << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }*/
    while (am >= 10)
    {
        am = am / 10 + am % 10;
    }
    while (duong >= 10)
    {
        duong = duong / 10 + duong % 10;
    }

    int m, n;
    m = duong; // hang row
    n = am;    // cot column
    int toida = array[m][n];
    int toida_trai = 0;
    int toida_phai = array[m][n];
    int a = m;
    int b = n;
    int y = m;
    int z = n;
    int a1 = m, a2 = m;
    int b1 = n, b2 = n;
    while (abs(a - b) < 10 && a >= 0 && a <= 9 && b >= 0 && b <= 9)
    {
        array[a][b] > array[m][n] ? toida_trai = array[a][b] : toida_trai = array[m][n];
        a++;
        b++;
    }
    while (abs(y - z) < 10 && y >= 0 && y <= 9 && z >= 0 && z <= 9)
    {
        array[y][z] > array[m][n] ? toida_trai = array[y][z] : toida_trai = array[m][n];
        y--;
        z--;
    }

    for (int k = 1; a2 + k < 10 && b2 + k < 10; k++)
    {
        toida_phai = (toida_phai > array[a2 + k][b2 + k]) ? toida_phai : array[a2 + k][b2 + k];
    }

    for (int k = 1; a2 - k >= 0 && b2 - k >= 0; k++)
    {
        toida_phai = (toida_phai > array[a2 - k][b2 - k]) ? toida_phai : array[a2 - k][b2 - k];
    }

    for (int k = 1; a2 - k >= 0 && b2 + k < 10; k++)
    {
        toida_phai = (toida_phai > array[a2 - k][b2 + k]) ? toida_phai : array[a2 - k][b2 + k];
    }

    for (int k = 1; a2 + k < 10 && b2 - k >= 0; k++)
    {
        toida_phai = (toida_phai > array[a2 + k][b2 - k]) ? toida_phai : array[a2 + k][b2 - k];
    }
    int diemsw;
    if (abs(toida_phai) > abs(toida_trai))
    {
        diemsw = abs(toida_phai);
    }
    else
    {
        diemsw = abs(toida_trai);
    }
    if (abs(toida) > abs(diemsw))
    {
        HP1 = std::ceil(double(HP1 * 0.9 - 1e-10));
        EXP1 = std::ceil(double(EXP1 * 0.88 - 1e-10));
        EXP2 = std::ceil(double(EXP2 * 0.88 - 1e-10));
        HP2 = std::ceil(double(HP2 * 0.9 - 1e-10));
        HP1 = HP1 > 666 ? 666 : std::ceil(HP1 - 1e-10);
        HP1 = HP1 < 0 ? 0 : std::ceil(HP1 - 1e-10);
        EXP1 = EXP1 > 600 ? 600 : std::ceil(EXP1 - 1e-10);
        EXP1 = EXP1 < 0 ? 0 : std::ceil(EXP1 - 1e-10);
        HP2 = HP2 > 666 ? 666 : std::ceil(HP2 - 1e-10);
        HP2 = HP2 < 0 ? 0 : std::ceil(HP2 - 1e-10);
        EXP2 = EXP2 > 600 ? 600 : std::ceil(EXP2 - 1e-10);
        EXP2 = EXP2 < 0 ? 0 : std::ceil(EXP2 - 1e-10);
        return toida;
    }
    else if (abs(toida) == abs(diemsw) || abs(toida) < abs(diemsw))
    {
        HP1 = std::ceil(double(HP1 * 1.1 - 1e-10));
        HP2 = std::ceil(double(HP2 * 1.1 - 1e-10));
        EXP1 = std::ceil(double(EXP1 * 1.12 - 1e-10));
        EXP2 = std::ceil(double(EXP2 * 1.12 - 1e-10));
        HP1 = HP1 > 666 ? 666 : std::ceil(HP1 - 1e-10);
        HP1 = HP1 < 0 ? 0 : std::ceil(HP1 - 1e-10);
        EXP1 = EXP1 > 600 ? 600 : std::ceil(EXP1 - 1e-10);
        EXP1 = EXP1 < 0 ? 0 : std::ceil(EXP1 - 1e-10);
        HP2 = HP2 > 666 ? 666 : std::ceil(HP2 - 1e-10);
        HP2 = HP2 < 0 ? 0 : std::ceil(HP2 - 1e-10);
        EXP2 = EXP2 > 600 ? 600 : std::ceil(EXP2 - 1e-10);
        EXP2 = EXP2 < 0 ? 0 : std::ceil(EXP2 - 1e-10);

        return diemsw;
    }
    // Checking the condition again
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string password(s);
    string se(email);
    // email se duoi 100 ky tu. da duoc tra loi tren forum. cau 71 tren sheet

    size_t truoc = se.find('@');
    se = se.substr(0, truoc);
    truoc = password.find(se);
    if (password.length() < 8)
    {
        return -1;
    }
    else if (password.length() > 20)
    {
        return -2;
    }

    if (truoc != string::npos)
    {
        return -(300 + static_cast<int>(truoc));
    }

    for (size_t i = 0; i < password.length() - 2; i++)
    {
        if (password[i] == password[i + 1] && password[i] == password[i + 2])
        {
            return -(400 + static_cast<int>(i));
        }
    }

    string dacbiet = "@#%$!";
    truoc = password.find_first_of(dacbiet);
    if (truoc == string::npos)
    {
        return -5;
    }
    for (int i = 0; i < password.length(); i++)
    {
        char dkcuoi = password[i];
        if (!isdigit(dkcuoi) && !isalpha(dkcuoi) && string("@#%$!").find(dkcuoi) == string::npos)
        {
            return i;
        }
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int dem = 0;
    int dai_toida = 0;
    int chisodung = -1;
    // Check cai matkhau dau tien
    for (int i = 0; i < num_pwds; i++)
    {
        int dem_lap = 0;
        string matkhau = (arr_pwds[i]);
        // Check tansuat
        for (int j = 0; j < num_pwds; j++)
        {
            if (matkhau == arr_pwds[j])
            {
                dem_lap++;
            }
        }
        if (dem_lap > dem || (dem_lap == dem && matkhau.length() > dai_toida))
        {
            dem = dem_lap;
            dai_toida = matkhau.length();
            chisodung = i;
        }
    }
    return chisodung;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////