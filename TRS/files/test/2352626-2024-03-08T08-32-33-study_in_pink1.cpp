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

// TODO: implement task
// int ceil(float &a)
// {
//     int b = a;
//     if (a - (float)b > 0)
//     {
//         b = b + 1;
//     }
//     return b;
// }
int lamtronso(float a)
{
    int b = a;
    if (a - b > 0)
    {
        b = b + 1;
    }
    return b;
}

int CheckHP(int a)
{
    if (a < 0)
    {
        a = 0;
        return a;
    }
    else if (a > 666)
    {
        a = 666;
        return a;
    }
    else
    {
        return a;
    }
}

int CheckEXP(int a)
{
    if (a < 0)
    {
        a = 0;
        return a;
    }
    else if (a > 600)
    {
        a = 600;
        return a;
    }
    else
    {
        return a;
    }
}

int CheckM(int a)
{
    if (a < 0)
    {
        a = 0;
        return a;
    }
    else if (a > 3000)
    {
        a = 3000;
        return a;
    }
    else
    {
        return a;
    }
}

int CheckE(int a)
{
    if (a >= 0 && a <= 99)
    {
        return a;
    }
    else
    {
        return -99;
    }
}

int Sochinhphuonggannhat(int b)
{
    int a = sqrt(b);

    int Chinhphuong1 = a * a;
    int Chinhphuong2 = (a + 1) * (a + 1);

    int distance1 = b - Chinhphuong1;
    int distance2 = Chinhphuong2 - b;

    if (distance1 < distance2)
    {
        return Chinhphuong1;
    }
    else
        return Chinhphuong2;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function

    int D = e1 * 3 + exp1 * 7;

    exp1 = CheckEXP(exp1);
    exp2 = CheckEXP(exp2);
    e1 = CheckE(e1);
    if (e1 == -99)
    {
        return -99;
    }

    if (e1 <= 3 && e1 >= 0)
    {
        if (e1 == 0)
        {
            exp2 = exp2 + 29;
            exp2 = CheckEXP(exp2);
        }
        else if (e1 == 1)
        {
            exp2 = exp2 + 45;
            exp2 = CheckEXP(exp2);
        }
        else if (e1 == 2)
        {
            exp2 = exp2 + 75;
            exp2 = CheckEXP(exp2);
        }
        else
        {
            exp2 = exp2 + 29 + 45 + 75;
            exp2 = CheckEXP(exp2);
        }

        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + D / 200.0);
            exp1 = CheckEXP(exp1);
        }
        else
        {
            exp1 = ceil(exp1 - D / 100.0);
            exp1 = CheckEXP(exp1);
        }
    }

    else
    {
        if (e1 <= 19 && e1 >= 4)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = CheckEXP(exp2);
        }
        else if (e1 <= 49 && e1 >= 20)
        {
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            exp2 = CheckEXP(exp2);
        }
        else if (e1 <= 65 && e1 >= 50)
        {
            exp2 = ceil(exp2 + e1 / 16.0 + 17);
            exp2 = CheckEXP(exp2);
        }
        else if (e1 <= 79 && e1 >= 66)
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            exp2 = CheckEXP(exp2);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);
                exp2 = CheckEXP(exp2);
            }
        }
        else
        {
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            // std::cout << exp2 << std::endl;
            exp2 = CheckEXP(exp2);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            // std::cout << exp2 << std::endl;
            exp2 = CheckEXP(exp2);
            if (exp2 > 400)
            {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);
                exp2 = CheckEXP(exp2);
                // std::cout << exp2 << std::endl;

                exp2 = ceil(exp2 * (115 / 100.0));
                exp2 = CheckEXP(exp2);
                // std::cout << exp2 << std::endl;
            }
        }

        exp1 = exp1 - e1;
        exp1 = CheckEXP(exp1);
    }

    return exp1 + exp2;
    // std::cout<< exp1 + exp2 << std::endl;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    float TienBanDau = (float)M1 / 2;
    float TienCanChi = 0;

    HP1 = CheckHP(HP1);
    EXP1 = CheckEXP(EXP1);
    M1 = CheckM(M1);
    E2 = CheckE(E2);

    if (E2 == -99)
    {
        return -99;
    }

    float P1, P2, P3;
    int S = Sochinhphuonggannhat(EXP1);
    if (EXP1 >= S)
    {
        P1 = 100 / 100;
    }
    else
    {
        P1 = (((float)EXP1 / (float)S) + 80) / 123;
    }

    // Chặng 2
    // std::cout << "M1 ban đầu: " << M1 << std::endl;
    if (E2 % 2 == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * (130 / 100.0));
                HP1 = CheckHP(HP1);
                M1 = M1 - 150;
                M1 = CheckM(M1);
                // std::cout << "M1 lần 1: " << M1 << std::endl;
                TienCanChi = TienCanChi + 150;
            }
            else
            {
                HP1 = lamtronso(HP1 * (110 / 100.0));
                HP1 = CheckHP(HP1);
                M1 = M1 - 70;
                M1 = CheckM(M1);
                // std::cout << "M1 lần 1: " << M1 << std::endl;
                TienCanChi = TienCanChi + 70;
            }
            if (TienCanChi > TienBanDau)
            {
                // std::cout << TienCanChi << std::endl;
                break;
            }
            else
            {
                // std::cout << TienCanChi << std::endl;
            }
            if (EXP1 < 400)
            {
                EXP1 = ceil(EXP1 * (113 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 200;
                M1 = CheckM(M1);
                // std::cout << "M1 lần 2: " << M1 << std::endl;
                TienCanChi = TienCanChi + 200;
            }
            else
            {
                EXP1 = ceil(EXP1 * (113 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 120;
                M1 = CheckM(M1);
                // std::cout << "M1 lần 2: " << M1 << std::endl;
                TienCanChi = TienCanChi + 120;
            }
            if (TienCanChi > TienBanDau)
            {
                // std::cout << TienCanChi << std::endl;
                break;
            }
            else
            {
                // std::cout << TienCanChi << std::endl;
            }
            if (EXP1 < 300)
            {
                EXP1 = ceil(EXP1 * (90 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 100;
                M1 = CheckM(M1);
                // std::cout << "M1 lần 3: " << M1 << std::endl;
                TienCanChi = TienCanChi + 100;
            }
            else
            {
                EXP1 = ceil(EXP1 * (90 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 120;
                M1 = CheckM(M1);
                // std::cout << "M1 lần 3: " << M1 << std::endl;
                TienCanChi = TienCanChi + 120;
            }
            if (TienCanChi > TienBanDau)
            {
                // std::cout << TienCanChi << std::endl;
                break;
            }
            else
            {
                // std::cout << TienCanChi << std::endl;
            }
            // std::cout << i << std::endl;
        }
        HP1 = ceil(HP1 * (83 / 100.0));
        HP1 = CheckHP(HP1);
        EXP1 = ceil(EXP1 * (117 / 100.0));
        EXP1 = CheckEXP(EXP1);
    }

    else
    {
        if (HP1 < 200)
        {
            if (M1 != 0)
            {
                HP1 = ceil(HP1 * (130 / 100.0));
                HP1 = CheckHP(HP1);
                M1 = M1 - 150;
                M1 = CheckM(M1);
            }
        }
        else
        {
            if (M1 != 0)
            {
                HP1 = lamtronso(HP1 * (110 / 100.0));
                HP1 = CheckHP(HP1);
                M1 = M1 - 70;
                M1 = CheckM(M1);
            }
        }

        if (EXP1 < 400)
        {
            if (M1 != 0)
            {
                EXP1 = ceil(EXP1 * (113 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 200;
                M1 = CheckM(M1);
            }
        }
        else
        {
            if (M1 != 0)
            {
                EXP1 = ceil(EXP1 * (113 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 120;
                M1 = CheckM(M1);
            }
        }

        if (EXP1 < 300)
        {
            if (M1 != 0)
            {
                EXP1 = ceil(EXP1 * (90 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 100;
                M1 = CheckM(M1);
            }
        }
        else
        {
            if (M1 != 0)
            {
                EXP1 = ceil(EXP1 * (90 / 100.0));
                EXP1 = CheckEXP(EXP1);
                M1 = M1 - 120;
                M1 = CheckM(M1);
            }
        }

        HP1 = ceil(HP1 * (83 / 100.0));
        HP1 = CheckHP(HP1);
        EXP1 = ceil(EXP1 * (117 / 100.0));
        EXP1 = CheckEXP(EXP1);
    }

    int S2 = Sochinhphuonggannhat(EXP1);
    if (EXP1 >= S2)
    {
        P2 = 100 / 100;
    }
    else
    {
        P2 = (((float)EXP1 / S2) + 80) / 123;
    }
    // Chặng đường 3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if ((float)E2 / 10 < 1.0)
    {
        P3 = (float)P[E2] / 100.0;
    }
    else
    {
        int i = E2 % 10;
        int k = E2 / 10;
        int j = i + k;
        if ((float)j / 10 > 1)
        {
            P3 = (float)P[j % 10] / 100.0;
        }
        else
        {
            P3 = (float)P[j] / 100.0;
        }
    }
    float P_average = (P1 + P2 + P3) / 3;
    if (P_average == 1)
    {
        EXP1 = ceil(EXP1 * 75 / 100.0);
        EXP1 = CheckEXP(EXP1);
    }
    else if (P_average < 0.5)
    {
        HP1 = ceil(HP1 * (85 / 100.0));
        HP1 = CheckHP(HP1);
        EXP1 = ceil(EXP1 * 115 / 100.0);
        EXP1 = CheckEXP(EXP1);
    }
    else
    {
        HP1 = ceil(HP1 * (90 / 100.0));
        HP1 = CheckHP(HP1);
        EXP1 = ceil(EXP1 * (120 / 100.0));
        EXP1 = CheckEXP(EXP1);
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    E3 = CheckE(E3);
    if (E3 == -99)
    {
        return -99;
    }
    HP1 = CheckHP(HP1);
    EXP1 = CheckEXP(EXP1);
    HP2 = CheckHP(HP2);
    EXP2 = CheckEXP(EXP2);

    int new_i = 0;
    int new_j = 0;
    int fake_E3 = E3 * 2;
    int real_E3 = -E3;

    int matrix[10][10] = {0};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = (E3 * j + i * 2) * (i - j);
            // std::cout << matrix[i][j] << " ";
            if (matrix[i][j] > fake_E3)
            {
                new_i++;
            }
            if (matrix[i][j] < real_E3)
            {
                new_j++;
            }
        }
        // std::cout << std::endl;
    }
    // xử lí i, j 2 chữ số

    for (int i = 0; i < 2; i++)
    {
        if ((float)new_i / 10 > 0)
        {
            new_i = (new_i % 10) + (new_i / 10);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if ((float)new_j / 10 > 0)
        {
            new_j = (new_j % 10) + (new_j / 10);
        }
    }

    // int Tongdiemcheotrai = duongcheotrai(new_i, new_j, E3);
    // int Tongdiemcheophai = duongcheophai(new_i, new_j, E3);
    int dem = 1;
    int maximum = matrix[new_i][new_j];

    while (dem < 10)
    {
        if ((new_i - dem >= 0) && (new_j - dem >= 0))
        {
            maximum = max(maximum, matrix[new_i - dem][new_j - dem]);
        }
        if ((new_i + dem < 10) && (new_j + dem < 10))
        {
            maximum = max(maximum, matrix[new_i + dem][new_j + dem]);
        }
        if ((new_i - dem >= 0) && (new_j + dem < 10))
        {
            maximum = max(maximum, matrix[new_i - dem][new_j + dem]);
        }
        if ((new_i + dem < 10) && (new_j - dem >= 0))
        {
            maximum = max(maximum, matrix[new_i + dem][new_j - dem]);
        }
        dem++;
    }

    int DiemTaxi = matrix[new_i][new_j];

    if (abs(DiemTaxi) > maximum)
    {
        EXP1 = ceil(EXP1 * 88 / 100.0);
        EXP2 = ceil(EXP2 * 88 / 100.0);
        HP1 = ceil(HP1 * 90 / 100.0);
        HP2 = ceil(HP2 * 90 / 100.0);
        EXP1 = CheckEXP(EXP1);
        EXP2 = CheckEXP(EXP2);
        HP1 = CheckHP(HP1);
        HP2 = CheckHP(HP2);
        // std::cout << DiemTaxi << std::endl;
        return DiemTaxi;
    }
    else
    {
        EXP1 = ceil(EXP1 * 112 / 100.0);
        EXP2 = ceil(EXP2 * 112 / 100.0);
        HP1 = ceil(HP1 * 110 / 100.0);
        HP2 = ceil(HP2 * 110 / 100.0);
        EXP1 = CheckEXP(EXP1);
        EXP2 = CheckEXP(EXP2);
        HP1 = CheckHP(HP1);
        HP2 = CheckHP(HP2);
        // std::cout << maximum << std::endl;
        return maximum;
    }
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    string se;
    char Checker;
    bool checkCharType = true, VitritrungdautienCheck = false;
    int s_length = 0, i = 0, New_Post = -100, Vitritrungdautien = 1, StrangePos = 100, Checking = 0;
    while (*email != '@')
    {
        int i = 0;
        se += email[i];
        i++;
    }
    char None = '\0';

    while ((*s != None) && (s_length < 21))
    {
        Checker = *s;
        //Check có kí tự đặc biệt
        if ((*s == '@') || (*s == '#') || (*s == '$') || (*s == '!') || (*s == '%'))
        {
            Checking++;
        }
        //Check có kí tự ngoài
        else if (((*s < '0') || (*s > '9')) && ((*s < 'a') || (*s > 'z')) && ((*s < 'A') || (*s > 'Z')) && (StrangePos == 100))
        {
            StrangePos = s_length;
        }

        if (New_Post < 0)
        {
            if (se[0] == None)
            {
                New_Post = 0;
            }
            else
            {
                while (se[i] != None)
                {
                    if (*(s + i) != se[i])
                    {
                        break;
                    }
                    if (se[i + 1] == None)
                    {
                        New_Post = s_length;
                    }
                    i++;
                }
                i = 0;
            }
        }

        s_length++;
        s++;

        if ((Checker == *s) && (!VitritrungdautienCheck))
        {
            Vitritrungdautien++;
        }
        else if ((Vitritrungdautien > 2) && (!VitritrungdautienCheck))
        {
            Vitritrungdautien = s_length - Vitritrungdautien;
            VitritrungdautienCheck = true;
        }
        else if (!VitritrungdautienCheck)
        {
            Vitritrungdautien = 1;
        }
        
        
    }
    //Đầu ra
    if (s_length < 8)
    {
        return -1;
    }
    else if (s_length > 20)
    {
        return -2;
    }
    else if (New_Post >= 0)
    {
        return -(300 + New_Post);
    }
    else if (VitritrungdautienCheck)
    {
        return -(400 + Vitritrungdautien);
    }
    else if (Checking == 0)
    {
        return -5;
    }
    else if (StrangePos != 100)
    {
        return StrangePos;
    }
    else
    {
        return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int Vitri = 0, k = 0, length = 0, order = 0, MaxLength = 0, Mostappearance = 0, MostVitri = 0;
    
    std::string Pass[30] = {};

    int Table[30][3] = {};
    // line 1: solanxuathien - chieudai - vitri

    while (Vitri < num_pwds)
    {
        // Số lần xuất hiện
        while (k < order + 1)
        {
            if (arr_pwds[Vitri] == Pass[k])
            {
                Table[k][1]++;
                break;
            }
            else if (k == order)
            {
                Pass[order] = arr_pwds[Vitri];
                Table[order][1]++;
                Table[order][3] = Vitri;

                //tính chiều dài
                k = 0;
                while (arr_pwds[Vitri][k] != '\0')
                {
                    length++;
                    k++;
                }

                Table[order][2] = length;
                //set lại vị trí ban đầu
                length = 0;
                order++;
                k = 0;
                break;
            }
            k++;
        }
        Vitri++;
        k = 0;
    }

    // Chọn giữa các phần tử bằng nhau
    while (k < order)
    {
        if (Table[k][1] > Mostappearance)
        {
            Mostappearance = Table[k][1];
            MaxLength = Table[k][2];
            MostVitri = Table[k][3];
        }
        else if (Table[k][1] == Mostappearance)
        {
            if (Table[k][2] > MaxLength)
            {
                MaxLength = Table[k][2];
                MostVitri = Table[k][3];
            }
        }
        k++;
    }
    return MostVitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////