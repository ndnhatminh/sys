#include "study_in_pink1.h"

bool readFile(
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
void checkEXP(int& EXP1, int& EXP2)
{
    EXP1 = (EXP1 > 600) ? 600 : (EXP1 < 0) ? 0 : EXP1;
    EXP2 = (EXP2 > 600) ? 600 : (EXP2 < 0) ? 0 : EXP2;
}

void checkHP(int& HP1, int& HP2)
{
    HP1 = (HP1 > 666) ? 666 : (HP1 < 0) ? 0 : HP1;
    HP2 = (HP2 > 666) ? 666 : (HP2 < 0) ? 0 : HP2;
}

void checkM(int& M1, int& M2)
{
    M1 = (M1 > 3000) ? 3000 : (M1 < 0) ? 0 : M1;
    M2 = (M2 > 3000) ? 3000 : (M2 < 0) ? 0 : M2;
}
// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1)
{
    if (E1 < 0 || E1 > 99)
    {
        return -99;
    }
    else
    {
        // Truong hop 01
        if (E1 >= 0 && E1 <= 3)
        {
            if (E1 == 0)
            {
                EXP2 += 29;
            }
            else if (E1 == 1)
            {
                EXP2 += 45;
            }
            else if (E1 == 2)
            {
                EXP2 += 75;
            }
            else if (E1 == 3)
            {
                EXP2 += 29 + 45 + 75;
            }
            int D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0)
            {
                EXP1 = ceil((EXP1 + (double)D / 200));
            }
            else
            {
                EXP1 = ceil((EXP1 - (double)D / 100));
            }
            checkEXP(EXP1, EXP2);
        }
        // Truong hop 02
        if (E1 >= 4 && E1 <= 99)
        {
            if (E1 >= 4 && E1 <= 19)
            {
                EXP2 = ceil((EXP2 + (double)E1 / 4 + 19));
            }
            else if (E1 >= 20 && E1 <= 49)
            {
                EXP2 = ceil((EXP2 + (double)E1 / 9 + 21));

            }
            else if (E1 >= 50 && E1 <= 65)
            {
                EXP2 = ceil(EXP2 + (double)E1 / 16 + 17);

            }
            else if (E1 >= 66 && E1 <= 79)
            {
                EXP2 = ceil(EXP2 + (double)E1 / 4 + 19);

                if (EXP2 > 200)
                {
                    EXP2 = ceil(EXP2 + (double)E1 / 9 + 21);

                }
            }
            else if (E1 >= 80 && E1 <= 99)
            {
                EXP2 = ceil(EXP2 + (double)E1 / 4 + 19);
                EXP2 = ceil(EXP2 + (double)E1 / 9 + 21);
                if (EXP2 > 400)
                {
                    EXP2 = ceil(EXP2 + (double)E1 / 16 + 17);
                    EXP2 = ceil(EXP2 + (double)0.15 * EXP2);

                }
            }

        }
    }
    checkEXP(EXP1, EXP2);
    if (E1 >= 4 && E1 <= 99) EXP1 -= E1;
    checkEXP(EXP1, EXP2);
    return EXP1 + EXP2;
}
// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    if (E2 < 0 || E2>99)
    {
        return -99;
    }
    else
    {
        // Xu li con duong 01
        double P1 = 0.0;
        int S = sqrt(EXP1);
        int S1 = S + 1;
        int m = S * S;
        int n = S1 * S1;
        int squarenumber1;
        if (abs(EXP1 - n) < abs(EXP1 - m))
        {
            squarenumber1 = n;
        }
        else
        {
            squarenumber1 = m;
        }
        if (EXP1 >= squarenumber1) P1 = 1.00;
        else P1 = (double)((EXP1 / squarenumber1) + 80) / 123.00;
        //Xu li Con duong 02
        if (E2 % 2 == 0)
        {
            //Mua thuc an va nuoc uong
            if (HP1 < 200)
            {
                HP1 = ceil((double)HP1 * 1.3);
                M1 -= 150;
                //Kiem tra dieu kien
                if (M1 <= 0)
                {
                    goto point;
                    M1 = 0;
                }
            }
            else
            {
                HP1 = ceil((double)HP1 * 1.1);
                M1 -= 70;
                //Kiem tra dieu kien
                if (M1 <= 0)
                {
                    goto point;
                    M1 = 0;
                }
            }
            checkEXP(EXP1, EXP1);
            checkHP(HP1, HP1);
            checkM(M1, M1);
            //Di taxi hoac xe ngua
            if (EXP1 < 400)
            {
                M1 -= 200;
                EXP1 = ceil((double)EXP1 * 1.13);
                //Kiem tra dieu kien
                if (M1 <= 0)
                {
                    goto point;
                    M1 = 0;
                }
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil((double)EXP1 * 1.13);
                //Kiem tra dieu kien
                if (M1 <= 0)
                {
                    goto point;
                    M1 = 0;
                }
            }
            checkEXP(EXP1, EXP1);
            checkHP(HP1, HP1);
            checkM(M1, M1);
            //Giup do nguoi vo gia cu
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil((double)EXP1 * 0.9);
                //Kiem tra dieu kien
                if (M1 <= 0)
                {
                    goto point;
                    M1 = 0;
                }
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil((double)EXP1 * 0.9);
                //Kiem tra dieu kien
                if (M1 <= 0)
                {
                    goto point;
                    M1 = 0;
                }
            }

            checkEXP(EXP1, EXP1);
            checkHP(HP1, HP1);
            checkM(M1, M1);
            goto point;
        }
        else
        {
            int temp_M1 = M1 / 2;
            bool ContinueEvent = true;
            int totalspent = 0;
            while (ContinueEvent)
            {
                //Mua thuc an va nuoc uong
                if (HP1 < 200)
                {
                    HP1 = ceil((double)HP1 * 1.3);
                    M1 -= 150;
                    totalspent += 150;
                }
                else
                {
                    HP1 = ceil((double)HP1 * 1.1);
                    M1 -= 70;
                    totalspent += 70;
                }
                //Kiem tra dieu kien
                if (totalspent > temp_M1)
                {
                    goto point;
                }
                checkEXP(EXP1, EXP1);
                checkHP(HP1, HP1);
                checkM(M1, M1);
                //Di taxi hoac xe ngua
                if (EXP1 < 400)
                {
                    M1 -= 200;
                    totalspent += 200;
                    EXP1 = ceil((double)EXP1 * 1.13);
                }
                else
                {
                    M1 -= 120;
                    totalspent += 120;
                    EXP1 = ceil((double)EXP1 * 1.13);
                }
                //Kiem tra dieu kien
                if (totalspent > temp_M1)
                {
                    goto point;
                }
                checkEXP(EXP1, EXP1);
                checkHP(HP1, HP1);
                checkM(M1, M1);
                //Giup do nguoi vo gia cu
                if (EXP1 < 300)
                {
                    M1 -= 100;
                    totalspent += 100;
                    EXP1 = ceil((double)EXP1 * 0.9);
                }
                else
                {
                    M1 -= 120;
                    totalspent += 120;
                    EXP1 = ceil((double)EXP1 * 0.9);
                }
                //Kiem tra dieu kien
                if (totalspent > temp_M1)
                {
                    goto point;
                }
                checkEXP(EXP1, EXP1);
                checkHP(HP1, HP1);
                checkM(M1, M1);

            }
        }
    point:
        HP1 = ceil((double)HP1 * 0.83);
        EXP1 = ceil((double)EXP1 * 1.17);
        checkEXP(EXP1, EXP1);
        checkHP(HP1, HP1);
        checkM(M1, M1);
        double P2 = 0.00;
        int S2 = sqrt(EXP1);
        int S3 = S2 + 1;
        int p = S2 * S2;
        int q = S3 * S3;
        int squarenumber2;
        if (abs(q - EXP1) < abs(p - EXP1))
        {
            squarenumber2 = q;
        }
        else
        {
            squarenumber2 = p;
        }
        if (EXP1 >= squarenumber2) P2 = 1.00;
        else P2 = (double)(EXP1 / squarenumber2 + 80) / 123.00;
        // Xu li con duong 03 
        int P[] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
        int i;
        if (E2 < 10)
        {
            i = E2;
        }
        else
        {
            int a = E2 / 10 + E2 % 10;
            i = a % 10;
        }
        double P3 = P[i] / 100.00;
        // Neu xac suat bang 1.0
        if (P1 == 1.00 && P2 == 1.00 && P3 == 1.00)
        {
            EXP1 = ceil((double)EXP1 * 0.75);
        }
        else
        {
            double avg_P = (P1 + P2 + P3) / 3.00;
            if (avg_P < 0.5)
            {
                // Neu xac suat nho hon 0.5
                HP1 = ceil((double)HP1 * 0.85);
                EXP1 = ceil((double)EXP1 * 1.15);
            }
            else
            {
                // Neu xac suat lon hon hoac bang 0.5
                HP1 = ceil((double)HP1 * 0.9);
                EXP1 = ceil((double)EXP1 * 1.2);
            }
        }
    }
    checkEXP(EXP1, EXP1);
    checkHP(HP1, HP1);
    checkM(M1, M1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    int result = 0;
    if (E3 < 0 || E3>99)
    {
        return -99;
    }
    else
    {

        // Khoi tao ma tran 10x10 voi gia tri 0
        int taxiMatrix[10][10] = { 0 };
        // Tinh diem so cho moi o trong ma tran
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                taxiMatrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        // Tim diem gap nhau cua taxi voi Sherlock va Watson
        int meetPoint;
        int a = 0;
        int b = 0;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (taxiMatrix[i][j] > 2 * E3)
                {
                    a += 1;  //So gia tri duong lon hon 2*E3
                }
                if (taxiMatrix[i][j] < -E3)
                {
                    b += 1;  //So gia tri am nho hon -E3
                }
            }
        }
        while (a > 9)
        {
            a = (a % 10) + (a - (a % 10)) / 10;
        }
        while (b > 9)
        {
            b = (b % 10) + (b - (b % 10)) / 10;
        }
        //Diem gap nhau cua Taxi voi Sherlock va Waston  
        meetPoint = taxiMatrix[a][b];
        //Tim diem cua Sherlcok va Waston
        int max = taxiMatrix[a][b];
        int x1 = a, x2 = a, x3 = a, x4 = a;
        int y1 = b, y2 = b, y3 = b, y4 = b;
        while (x1 < 9 && y1 < 9)
        {
            x1++; y1++;
            if (taxiMatrix[x1][y1] > max)
            {
                max = taxiMatrix[x1][y1];
            }
        }
        while (x2 > 0 && y2 > 0)
        {
            x2--; y2--;
            if (taxiMatrix[x2][y2] > max)
            {
                max = taxiMatrix[x2][y2];
            }
        }
        while (x3 > 0 && y3 < 9)
        {
            x3--; y3++;
            if (taxiMatrix[x3][y3] > max)
            {
                max = taxiMatrix[x3][y3];
            }
        }
        while (x4 < 9 && y4 > 0)
        {
            x4++; y4--;
            if (taxiMatrix[x4][y4] > max)
            {
                max = taxiMatrix[x4][y4];
            }
        }
        if (abs(taxiMatrix[a][b]) > abs(max))
        {
            EXP1 = ceil((double)EXP1 * 0.88);
            EXP2 = ceil((double)EXP2 * 0.88);
            HP1 = ceil((double)HP1 * 0.9);
            HP2 = ceil((double)HP2 * 0.9);
            result = meetPoint;
        }
        else
        {
            EXP1 = ceil((double)EXP1 * 1.12);
            EXP2 = ceil((double)EXP2 * 1.12);
            HP1 = ceil((double)HP1 * 1.1);
            HP2 = ceil((double)HP2 * 1.1);
            result = max;
        }
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
    }
    return result;
}
// Task 4
int checkPassword(const char* s, const char* email)
{
    // Tinh do dai cua chuoi s
    int sLength = strlen(s);
    // Do dai toi thieu va toi da cua mat khau
    const int minLength = 8;
    const int maxLength = 20;
    // Kiem tra do dai cua chuoi s
    if (sLength < minLength)
    {
        return -1;
    }
    else if (sLength > maxLength)
    {
        return -2;
    }
    // Tim chuoi se trong email
    const char* p = strstr(email, "@");
    int a = p - email;
    char se[100];
    strncpy(se, email, a);
    se[a] = '\0';
    // Kiem tra s co chua chuoi se khong
    int b;
    if (strstr(s, se) != NULL)
    {
        b = strstr(s, se) - s;
        return -b - 300;
    }

    // Kiem tra s co chua ky tu dac biet khong
    
        if (strstr(s, "@") == NULL && strstr(s, "#") == NULL && strstr(s, "$") == NULL && strstr(s, "%") == NULL && strstr(s, "!") == NULL)
        {
            return -5;
        }
    
    // Kiem tra s co chua nhieu hon 2 ky tu lien tiep va giong nhau khong
    for (int i = 0; i < sLength - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
        {
            return -i - 400;
        }
    }
    // Mat khau hop le
    return -10;
}
// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    int password_count[30];
    int result;
    for (int i = 0; i < num_pwds; i++)
    {
        password_count[i] = 0;
    }
    for (int i = 0; i < num_pwds; i++)
    {
        for (int j = 0; j < num_pwds; j++)
        {
            if (arr_pwds[i] == arr_pwds[j])
            {
                password_count[i]++;
            }
        }
    }
    int max_count = password_count[0];
    for (int i = 1; i < num_pwds; i++)
    {
        if (password_count[i] > max_count)
        {
            max_count = password_count[i];
            result = i;
        }
    }
    int c = 0;
    for (int i = 0; i < num_pwds; i++)
    {
        if (password_count[i] == max_count)
        {
            if (strlen(arr_pwds[i]) > c)
            {
                result = i;
                c = strlen(arr_pwds[i]);
            }
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////