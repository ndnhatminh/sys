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
{
    // TODO: Complete this function
    int result;
    if (e1 > 99 || e1 < 0) // TH nam ngoai doan [0, 99]
        return result = -99;
    if (e1 >= 0 && e1 <= 99) // TH nam trong doan [0, 99]
    {
        float EXP1 = (float)exp1;
        if (e1 >= 0 && e1 <= 3) // TH1
        {
            if (e1 == 0)
                exp2 += 29; // Thong tin 1
            if (e1 == 1)
                exp2 += 45; // Thong tin 2
            if (e1 == 2)
                exp2 += 75; // Thong tin 3
            if (e1 == 3)
                exp2 += 29 + 45 + 75; // Thong tin 4
            int D;                    // Quyet dinh cua Sherlock
            D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            { // Chan~
                EXP1 += (float)D / 200;
                EXP1 = ceil(EXP1);
                EXP1 = min(600, (int)EXP1);
                exp1 = (int)EXP1;
            }

            else
            { // Le~
                EXP1 -= (float)D / 100;
                EXP1 = ceil(EXP1);
                EXP1 = max(0, (int)EXP1);
                exp1 = (int)EXP1;
            }
        }

        if (e1 >= 4 && e1 <= 99) // TH2
        {
            float EXP2 = (float)exp2;
            if (e1 >= 4 && e1 <= 19)
            {
                EXP2 += ((float)e1 / 4 + 19);
                EXP2 = ceil(EXP2);
                EXP2 = min(600, (int)EXP2);
            } // Thong tin 1
            if (e1 >= 20 && e1 <= 49)
            {
                EXP2 += ((float)e1 / 9 + 21);
                EXP2 = ceil(EXP2);
                EXP2 = min(600, (int)EXP2);
            } // Thong tin 2
            if (e1 >= 50 && e1 <= 65)
            {
                EXP2 += ((float)e1 / 16 + 17);
                EXP2 = ceil(EXP2);
                EXP2 = min(600, (int)EXP2);
            }                         // Thong tin 3
            if (e1 >= 66 && e1 <= 79) // Thong tin 4
            {
                EXP2 += ((float)e1 / 4 + 19); // Giai thich thong tin 1
                EXP2 = ceil(EXP2);
                EXP2 = min(600, (int)EXP2);
                if (EXP2 > 200)
                {
                    EXP2 += ((float)e1 / 9 + 21); // Giai thich thong tin 2
                    EXP2 = ceil(EXP2);
                    EXP2 = min(600, (int)EXP2);
                }
            }
            if (e1 >= 80 && e1 <= 99) // Thong tin 5
            {
                EXP2 += ((float)e1 / 4 + 19); // Giai thich thong tin 1 & 2
                EXP2 = ceil(EXP2);
                EXP2 = min(600, (int)EXP2);
                EXP2 += ((float)e1 / 9 + 21);
                EXP2 = ceil(EXP2);
                EXP2 = min(600, (int)EXP2);
                if (EXP2 > 400)
                {
                    EXP2 += ((float)e1 / 16 + 17); // Giai thich thong tin 3
                    EXP2 = ceil(EXP2);
                    EXP2 = min(600, (int)EXP2);
                    EXP2 += EXP2 * (float)15 / 100; // Giai thich ca 3 thong tin nen cong them 15% exp hien tai
                    EXP2 = ceil(EXP2);
                    EXP2 = min(600, (int)EXP2);
                }
            }
            exp1 -= e1; // Bi tru exp
            exp1 = max(0, exp1);
            exp2 = (int)EXP2;
        }

        exp1 = min(600, exp1);
        exp1 = max(0, exp1);
        exp2 = min(600, exp2);
        exp2 = max(0, exp2);

        return result = exp1 + exp2;
    }
    return result;
}

////////////////////////////////////////////////////////
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E3)
{
    // TODO: Complete this function
    float P1, P2;
    int P_trungbinh, P3, result;
    float hp1 = (float)HP1, exp1 = (float)EXP1;

    if (E3 > 99 || E3 < 0) // TH nam ngoai doan [0, 99]
        return result = -99;

    if (E3 >= 0 && E3 <= 99) // TH nam trong doan [0, 99]
    {
        /*Con duong 1*/
        float S;                       // So chinh phuong gan EXP1 nhat
        S = pow(round(sqrt(EXP1)), 2); // Tim S
        // float P1;                      // Xac suat o con duong 1
        if (EXP1 >= (int)S)
            P1 = 100;
        else
            P1 = ((exp1 / S + 80) / 123) * 100;

        /*Con duong 2*/
        // float P2;   // Xac suat o con duong 2
        int M2 = 0; // So tien chi tra
        int MaxMoney = M1;
        if (E3 % 2 != 0) // E2 le~
        {
            if (MaxMoney != 0)
            {
                do
                {
                    if (M2 > ((float)1 / 2 * MaxMoney))
                        break;

                    if (hp1 < 200) // Mua thuc an va nuoc uong
                    {
                        hp1 += hp1 * (float)30 / 100;
                        hp1 = ceil(hp1);
                        hp1 = min(666, (int)hp1);
                        M2 += 150;
                        M1 -= 150;
                        M1 = max(0, M1);
                    }
                    else // Mua nuoc uong
                    {
                        hp1 += hp1 * (float)10 / 100;
                        hp1 = ceil(hp1);
                        hp1 = min(666, (int)hp1);
                        M2 += 70;
                        M1 -= 70;
                    }
                    if (M2 > ((float)1 / 2 * MaxMoney))
                        break;

                    if (exp1 < 400) // Thue Taxi
                    {
                        M2 += 200;
                        M1 -= 200;
                        M1 = max(0, M1);
                        exp1 += exp1 * (float)13 / 100;
                        exp1 = ceil(exp1);
                        exp1 = min(600, (int)exp1);
                    }
                    else
                    { // Thue xe ngua
                        M2 += 120;
                        M1 -= 120;
                        M1 = max(0, M1);
                        exp1 += exp1 * (float)13 / 100;
                        exp1 = ceil(exp1);
                        exp1 = min(600, (int)exp1);
                    }
                    if (M2 > ((float)1 / 2 * MaxMoney))
                        break;

                    if (exp1 < 300)
                    { // m = 100
                        M2 += 100;
                        M1 -= 100;
                        M1 = max(0, M1);
                        exp1 -= exp1 * (float)10 / 100;
                        exp1 = ceil(exp1);
                        exp1 = max(0, (int)exp1);
                    }

                    else
                    { // m = 120
                        M2 += 120;
                        M1 -= 120;
                        M1 = max(0, M1);
                        exp1 -= exp1 * (float)10 / 100;
                        exp1 = ceil(exp1);
                        exp1 = max(0, (int)exp1);
                    }
                } while (M2 <= ((float)1 / 2 * MaxMoney)); // Neu tien chi tieu <= nua so tien ban dau thi thuc hien lap lai
            }
            hp1 -= hp1 * (float)17 / 100;
            hp1 = ceil(hp1);
            hp1 = max(0, (int)hp1);
            exp1 += exp1 * (float)17 / 100;
            exp1 = ceil(exp1);
            exp1 = min(600, (int)exp1);
        }
        else
        { // E2 chan~
            if (M1 != 0)
            { // Neu M1 khac 0 thuc hien hanh dong 1
                if (hp1 < 200)
                {
                    hp1 += hp1 * (float)30 / 100;
                    hp1 = ceil(hp1);
                    hp1 = min(666, (int)hp1);
                    M2 += 150;
                    M1 -= 150;
                }
                else
                {
                    hp1 += hp1 * (float)10 / 100;
                    hp1 = ceil(hp1);
                    hp1 = min(666, (int)hp1);
                    M2 += 70;
                    M1 -= 70;
                }

                M1 = max(0, M1);
                if (M1 == 0)
                    goto skip;
                else if (M1 != 0)
                { // Neu M1 khac 0 thuc hien hanh dong 2
                    if (exp1 < 400)
                    {
                        M2 += 200;
                        M1 -= 200;
                        exp1 += exp1 * (float)13 / 100;
                        exp1 = ceil(exp1);
                        exp1 = min(600, (int)exp1);
                    }
                    else
                    {
                        M2 += 120;
                        M1 -= 120;
                        exp1 += exp1 * (float)13 / 100;
                        exp1 = ceil(exp1);
                        exp1 = min(600, (int)exp1);
                    }
                    M1 = max(0, M1);

                    if (M1 == 0)
                        goto skip;
                    else if (M1 != 0)
                    { // Neu M1 khac 0 thuc hien hanh dong 3

                        if (exp1 < 300)
                        {
                            M2 += 100;
                            M1 -= 100;
                            exp1 -= exp1 * (float)10 / 100;
                            exp1 = ceil(exp1);
                            exp1 = max(0, (int)exp1);
                            M1 = max(0, M1);
                        }
                        else
                        {
                            M2 += 120;
                            M1 -= 120;
                            exp1 -= exp1 * (float)10 / 100;
                            exp1 = ceil(exp1);
                            exp1 = max(0, (int)exp1);
                            M1 = max(0, M1);
                        }
                    }
                }
            }

        skip: // Neu M1 = 0 thi nhay toi diem nay
            hp1 -= hp1 * (float)17 / 100;
            hp1 = ceil(hp1);
            hp1 = max(0, (int)hp1);
            exp1 += exp1 * (float)17 / 100;
            exp1 = ceil(exp1);
            exp1 = min(600, (int)exp1);
        }
        S = pow(round(sqrt(exp1)),2);
        if (exp1 >= S) // Xac suat con duong 2
            P2 = 100;
        else
            P2 = ((float)(exp1 / S + 80) / 123) * 100;

        /*Con duong 3*/

        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Mang gom 10 phan tu xac suat
        int i;

        if (E3 < 10) // Neu E2 1 chu so thi lay gia tri E2 gan vao i
            i = E3;
        else if (E3 >= 10 && E3 <= 99) // Neu E2 2 chu so thi lay tong 2 chu so xong lay chu so hang don vi gan vao i
            i = ((E3 / 10 + E3 % 10)) % 10;
        P3 = P[i]; // Xac suat con duong 3

        /*Trung binh*/
        if (P1 == 100 && P2 == 100 && P3 == 100)
        { // TH ca 3 xac suat deu bang 100 thi tru exp
            exp1 -= exp1 * (float)25 / 100;
            exp1 = ceil(exp1);
            exp1 = max(0, (int)exp1);
        }
        else
        { // TH ca 3 xac suat khong cung bang 100

            P_trungbinh = (float)(P1 + P2 + P3) / 3;

            if (P_trungbinh < 50)
            { // P trung binh < 50
                hp1 -= hp1 * (float)15 / 100;
                hp1 = ceil(hp1);
                hp1 = max(0, (int)hp1);
                exp1 += exp1 * (float)15 / 100;
                exp1 = ceil(exp1);
                exp1 = min(600, (int)exp1);
            }
            else
            { // P trung binh >= 50
                hp1 -= hp1 * (float)10 / 100;
                hp1 = ceil(hp1);
                hp1 = max(0, (int)hp1);
                exp1 += exp1 * (float)20 / 100;
                exp1 = ceil(exp1);
                exp1 = min(600, (int)exp1);
            }
        }
        HP1 = (int)hp1;
        EXP1 = (int)exp1;

        EXP1 = min(600, EXP1);
        EXP1 = max(0, EXP1);
        HP1 = min(666, HP1);
        HP1 = max(0, HP1);
        M1 = min(3000, M1);
        M1 = max(0, M1);

        return result = HP1 + EXP1 + M1;
    }
    return result;
}

////////////////////////////////////////////////////////////////
// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function
    int i, j, Max, result;
    int count1 = 0, count2 = 0;
    float hp1 = (float)HP1, exp1 = (float)EXP1, hp2 = (float)HP2, exp2 = (float)EXP2;
    int Map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // Ma tran luu diem ma taxi di qua
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; //

    int Save[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // Ma tran luu diem lon nhat tren 2 duong cheo trai va phai cua diem bat ki ma taxi di qua
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; //

    if (E3 > 99 || E3 < 0) // TH nam ngoai doan [0, 99]
        return result = -99;

    if (E3 >= 0 && E3 <= 99) // TH nam trong doan [0, 99]
    {
        for (i = 0; i < 10; i++)
        { // Duong di cua taxi (di ngang)
            for (j = 0; j < 10; j++)
            {
                Map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (Map[i][j] > (E3 * 2) && Map[i][j] >= 0)
                    count1++; // So gia tri diem cua taxi lon hon E3 * 2
                else if (Map[i][j] < (-E3))
                    count2++; // So gia tri diem cua taxi nho hon -E3
            }
        }
        for (j = 0; j < 10; j++)
        { // Duong di cua Sherlock va Watson (di doc)
            for (i = 0; i < 10; i++)
            {
                int startRow, startCol, Max = 0;
                for (startRow = i, startCol = j; startRow >= 0 && startCol >= 0; startRow--, startCol--)
                { // Duyet duong cheo trai theo huong di len va sang trai
                    Max = max(Max, Map[startRow][startCol]);
                }
                for (startRow = i, startCol = j; startRow < 10 && startCol < 10; startRow++, startCol++)
                { // Duyet duong cheo trai theo huong di xuong va sang phai
                    Max = max(Max, Map[startRow][startCol]);
                }
                for (startRow = i, startCol = j; startRow < 10 && startCol >= 0; startRow++, startCol--)
                { // Duyet duong cheo phai theo huong di xuong va sang trai
                    Max = max(Max, Map[startRow][startCol]);
                }
                for (startRow = i, startCol = j; startRow >= 0 && startCol < 10; startRow--, startCol++)
                { // Duyet duong cheo phai theo huong di len va sang phai
                    Max = max(Max, Map[startRow][startCol]);
                }
                Save[i][j] = Max;
            }
        }

        if (count1 >= 10)
        { // Tim diem xe ma o do taxi se gap Sherlock va Watason
            i = ((count1 / 10) + (count1 % 10));
            while (i >= 10)
            { // Neu i co 2 chu so thi cong 2 chu so cho den khi i con 1 chu so
                i = ((i / 10) + (i % 10));
            }
        }
        else if (count1 < 10) // Neu i co 1 chu so thi lay gia tri count1 lam gia tri cua i
            i = count1;

        if (count2 >= 10)
        { // Neu j co 2 chu so thi cong 2 chu so cho den khi j con 1 chu so
            j = ((count2 / 10) + (count2 % 10));
            while (j >= 10)
            {
                j = ((j / 10) + (j % 10));
            }
        }
        else if (count2 < 10) // Neu j co 1 chu so thi lay gia tri count2 lam gia tri cua j
            j = count2;

        if (abs(Map[i][j]) <= Save[i][j])
        { // Neu |Map[i][j]| <= Save[i][j] thi tang exp va hp tuong ung
            exp1 += exp1 * (float)12 / 100;
            exp1 = ceil(exp1);
            exp1 = min(600, (int)exp1);
            hp1 += hp1 * (float)10 / 100;
            hp1 = ceil(hp1);
            hp1 = min(666, (int)hp1);
            exp2 += exp2 * (float)12 / 100;
            exp2 = ceil(exp2);
            exp2 = min(600, (int)exp2);
            hp2 += hp2 * (float)10 / 100;
            hp2 = ceil(hp2);
            hp2 = min(666, (int)hp2);
            result = Save[i][j];
        }
        else
        { // Neu |Map[i][j]| > Save[i][j] thi giam exp va hp tuong ung
            exp1 -= exp1 * (float)12 / 100;
            exp1 = ceil(exp1);
            exp1 = max(0, (int)exp1);
            hp1 -= hp1 * (float)10 / 100;
            hp1 = ceil(hp1);
            hp1 = max(0, (int)hp1);
            exp2 -= exp2 * (float)12 / 100;
            exp2 = ceil(exp2);
            exp2 = max(0, (int)exp2);
            hp2 -= hp2 * (float)10 / 100;
            hp2 = ceil(hp2);
            hp2 = max(0, (int)hp2);

            result = Map[i][j];
        }

        EXP1 = (int)exp1;
        HP1 = (int)hp1;
        EXP2 = (int)exp2;
        HP2 = (int)hp2;

        EXP1 = min(600, EXP1);
        EXP1 = max(0, EXP1);
        EXP2 = min(600, EXP2);
        EXP2 = max(0, EXP2);
        HP1 = min(666, HP1);
        HP1 = max(0, HP1);
        HP2 = min(666, HP2);
        HP2 = max(0, HP2);
    }
    return result;
}

//////////////////////////////////////////////////////
// Task 4
bool isntSpecialChar(const char s[], const char spch)
{ // Neu co ky tu spch trong chuoi s thi tra ve false nguoc lai tra ve true
    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == spch)
            return false;
    }
    return true;
}
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function
    int atPos = 0; // Vi tri cua '@' trong chuoi email
    char se[100];  // Khai bao chuoi se voi do dai toi da 100 ky tu
    while (email[atPos] != '\0' && email[atPos] != '@')
    { // Tim vi tri cua ki tu '@' trong email
        atPos++;
    } // Neu ky tu thu aPos cua email khac '\0 (ky tu ket thuc chuoi) va khac @ thi tang atPos len 1 don vi
    for (int i = 0; i < atPos; i++)
    {
        se[i] = email[i]; // Nhap ky tu vao chuoi se
    }
    se[atPos] = '\0'; // Dat ky tu cuoi cung la '\0' de dam bao ket thuc chuoi

    if (strlen(s) < 8)
        return -1; // Neu do dai cua s < 8 ky tu thi tra ve -1

    if (strlen(s) > 20)
        return -2; // Neu do dai cua s > 20 ky tu thi tra ve -2

    if (strlen(s) >= strlen(se))
    { // Chi xet trong truong hop s dai hon hoac bang se
        for (int i = 0; i <= strlen(s) - strlen(se); i++)
        { // Neu xuat hien chuoi se trong s thi tra ve -(300 + sei) voi sei la vi tri dau tien xuat hien cua chuoi se
            int sei = i, count = i;
            for (int j = 0; j < strlen(se); ++j)
            { // Dung thuat toan Brute Force de tim se trong s
                if (s[count] != se[j])
                {
                    break;
                }
                count++;
                if (j == strlen(se) - 1)
                    return -(300 + sei);
            }
        }
    }

    for (int i = 0; i < strlen(s) - 1; i++)
    { // Neu xuat hien 3 ky tu lien tiep thi tra ve -(400 + sci) voi sci la vi tri dau tien xuat hien ky tu do
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
        {
            int sci = i;
            return -(400 + sci);
        }
    }

    if (isntSpecialChar(s, '@') && isntSpecialChar(s, '#') && isntSpecialChar(s, '%') && isntSpecialChar(s, '$') && isntSpecialChar(s, '!'))
        return -5; // Neu khong co cac ky tu dac biet nhu yeu cau thi tra ve -5

    for (int i = 0; i <= strlen(s); i++)
    {
        if ((int)s[i] == 32 || (int)s[i] == 34 || ((int)s[i] >= 38 && (int)s[i] <= 47) || ((int)s[i] >= 58 && (int)s[i] <= 63) || ((int)s[i] >= 91 && (int)s[i] <= 96) || ((int)s[i] >= 123 && (int)s[i] <= 126))
            return i;
    } // Neu xuat hien cac ky tu khong giong yeu cau thi tra ve vi tri dau tien xuat hien ky tu do

    return -10; // Neu dung yeu cau thi tra ve -10
    // return atPos;
}

//////////////////////////////////////////////////////////////
// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int max_occurrences = 0, max_length = 0, correctPos = -1;
    for (int i = 0; i < num_pwds; i++)
    { // Duyet mang tim chuoi ky tu lam mau
        int occurrences = 0, length = strlen(arr_pwds[i]);
        for (int j = 0; j < num_pwds; j++)
        { // Duyet mang lan nua de so sanh tung chuoi voi chuoi mau
            if (strcmp(arr_pwds[j], arr_pwds[i]) == 0)
                occurrences++;
        }
        if (occurrences > max_occurrences || (occurrences == max_occurrences) && (length > max_length))
        { // Neu So lan xuat hien nhieu hon hoac neu so lan xuat hien bang nhau va do dai lon hon thi thay the so lan xuat hien nhieu nhat va do dai dai nhat
            max_occurrences = occurrences;
            max_length = length;
            correctPos = i; // Luu vi tri dau tien xuat hien cua mat khau dung
        }
    }
    return correctPos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////