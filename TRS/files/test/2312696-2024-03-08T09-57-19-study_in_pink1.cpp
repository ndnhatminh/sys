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


//kiemtra EXP//
void checkEXP1(int &EXP1)
{    
    if(EXP1 > 600)
        EXP1 = 600;
    else if(EXP1 < 0)
        EXP1 = 0;
}
void checkEXP2(int &EXP2)
{
    if(EXP2 > 600)
        EXP2 = 600;
    else if(EXP2 < 0)
        EXP2 = 0;
}
//kiemtra HP//
void checkHP1 (int &HP1)
{
    if(HP1 > 666)
        HP1 = 666;
    else if(HP1 < 0)
        HP1 = 0;   
}
void checkHP2(int &HP2)
{
    if(HP2 > 666)        
        HP2 = 666;
    else if(HP2 < 0)
        HP2 = 0; 
}
//kiem tra M //
void checkM1(int &M1)
{
    if(M1 > 3000)
        M1 = 3000;
    else if(M1 < 0)
        M1 = 0;
}

void checkM2(int &M2)
{
    if(M2 > 3000)
        M2 = 3000;
    else if(M2 < 0)
        M2 = 0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D = 0;
    float temp;
    double KN1, KN2, E;
    KN1=exp1;
    KN2=exp2;
    E=e1;
    switch (e1)
    {
        case 0 ... 3:
            if(e1 == 0)
            KN2 = KN2 + 29;if(KN2 >600)KN2=600;else if(KN2 < 0)KN2 = 0;
            else if(e1 == 1)
            KN2 = KN2 + 45;if(KN2 >600)KN2=600;else if(KN2 < 0)KN2 = 0;
            else if(e1 == 2)
            KN2 = KN2 + 75;if(KN2 >600)KN2=600;else if(KN2 < 0)KN2 = 0;
            else if(e1 == 3)
            KN2 = KN2 + 149;if(KN2 >600)KN2=600;else if(KN2 < 0)KN2 = 0;

            D = e1 * 3 + exp1 * 7;
            temp = D;
            if (D % 2 == 0)
            {
                KN1 = exp1 + temp/200;
                KN1 = ceil(KN1);if(KN1>600)KN1=600;else if(KN1 < 0)KN1=0;
            }else
            {
                KN1 = exp1 - temp/100;
                KN1 = ceil(KN1);if(KN1>600)KN1=600;else if(KN1 < 0)KN1=0;
            }
        break;
        case 4 ... 99:
            if(e1 >= 4 && e1 <= 19)
                {
                KN2 = KN2 + E/4 + 19;
                KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                }
            else if(e1 >= 20 && e1 <= 49)
                {
                KN2 = KN2 + E/9 + 21;
                KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                }
            else if(e1 >= 50 && e1 <= 65)
                {
                KN2 = KN2 + E/16 + 17;
                KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                }
            else if(e1 >= 66 && e1 <= 79)
                {
                KN2 = KN2 + E/4 + 19;
                KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                if(KN2 > 200)
                    {
                        KN2 = KN2 + E/9 + 21;
                        KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                    }
                }
            else if(e1 >= 80 && e1 <= 99)
                {
                KN2 = KN2 + E/4 + 19;
                KN2 = ceil(KN2);
                if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                KN2 = KN2 + E/9 + 21;KN2 = ceil(KN2);
                if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                    if(KN2 > 400)
                    {
                        KN2 = KN2 + E/16 + 17;
                        KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                        KN2 = KN2 + KN2 * 0.15;
                        KN2 = ceil(KN2);if(KN2>600)KN2=600;else if(KN2 < 0)KN2=0;
                    }
                }                   
            KN1 = KN1 - e1;
            if(KN1>600)KN1=600;else if(KN1 < 0)KN1=0;
        break;
        default:
            return -99;
    }
    exp1 = KN1;
    exp2 = KN2;
    return exp1 + exp2;
}

// Task 2
// street 1//
double traceLuggage_S1(int EXP1)
{
    double x, P1;
    x = sqrt(EXP1);
    int y = round(x);
    if(EXP1 > pow(y,2))
        {
            P1 = 1;
        }else P1 = (EXP1/pow(y,2) + 80)/123;
    return P1;
}
//street 2//
double traceLuggage_S2(int & HP1, int & EXP1, int & M1, int E2)
{
    int m = M1;
    double HP, KN;
    HP = HP1;
    KN = EXP1;
    int temp = ceil(m/2);
    if(E2 % 2 != 0)
    {
        while(temp <= M1)
        {
            //hanh dong1//
            if(HP < 200)
            {
                HP += 0.3 * HP;
                int x = ceil(HP);
                checkHP1(x);
                HP = x;
                M1 -= 150;
                checkM1(M1);
            }else if(HP >= 200)
            {
                HP += 0.1 * HP;
                int x = ceil(HP);
                checkHP1(x);
                HP = x;
                M1 -= 70;
                checkM1(M1);
            }
            if(temp > M1){break;}
            //hanh dong 2//
            if(KN < 400)
            {
                M1 -= 200;
                checkM1(M1);
            }else if(KN >= 400)
            {
                M1 -= 120;
                checkM1(M1);
            }
            KN += 0.13 * KN;
            int y = ceil(KN);
            checkEXP1(y);
            KN = y;
            if(temp > M1){break;}
            //hanh dong 3//
            if(KN < 300)
            {
                M1 -= 100;
                checkM1(M1);
            }else if(KN >= 300)
            {
                M1 -= 120;
                checkM1(M1);
            }
            KN -= 0.1 * KN;
            int z = ceil(KN);
            checkEXP1(z);
            KN = z;
            if(temp > M1){break;}
        }
        HP -= 0.17 * HP;
        int a = ceil(HP);
        checkHP1(a);
        HP = a;
        KN += 0.17 * KN;
        int b = ceil(KN);
        checkEXP1(b);
        KN = b;
    }else
        {
            for(int i =0; i< 1; i++)
            {       
                //hanh dong 1//
                if(HP1 < 200)
                {
                    HP += 0.3 * HP;
                    int x = ceil(HP);
                    checkHP1(x);
                    HP = x;
                    M1 -= 150;
                }else if(HP1 >= 200)
                {
                    HP += 0.1 * HP;
                    int x = ceil(HP);
                    checkHP1(x);
                    HP = x;
                    M1 -= 70;
                }
                if(M1 <=0){M1=0;break;}
                //hanh dong 2//
                if(EXP1 < 400)
                {
                    M1 -= 200;
                }else if(EXP1 >= 400)
                {
                    M1 -= 120;
                }
                KN += 0.13 * KN;
                int y = ceil(KN);
                checkEXP1(y);
                KN = y;
                if(M1 <=0){M1=0;break;}
                //hanh dong 3 //
                if(KN < 300)
                {
                    M1 -= 100;
                }else if(KN >= 300)
                {
                    M1 -= 120;
                }
                KN -= 0.1 * KN;
                int z = ceil(KN);
                checkEXP1(z);
                KN = z;
                if(M1 <=0){M1=0;break;}
            }
        HP -= 0.17 * HP;
        int a = ceil(HP);
        checkHP1(a);
        HP = a;
        KN += 0.17 * KN;
        int b = ceil(KN);
        checkEXP1(b);
        KN = b;
        }
    HP1=HP;
    EXP1=KN;
        return traceLuggage_S1(EXP1);
}
//street 3//
double traceLuggage_S3(int E2)
{
    double P3;
    float arr[10] = {0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
    if(E2 / 10 == 0)
    {
        P3 = arr[E2];
    }else if(E2 / 10 != 0)
    {
        int arrNum[2];
        arrNum[0] = E2 % 10;
        arrNum[1] = E2 /10;
        int sum = arrNum[0] + arrNum[1];
        P3 = arr[sum % 10];
    }
    return P3;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    double mau;
    double kinhnghiem;
    if(E2< 0 || E2 > 99)
    {
        return -99;
    }else 
    {
        float P1 = traceLuggage_S1(EXP1);
        float P2 = traceLuggage_S2(HP1, EXP1, M1, E2);
        float P3 = traceLuggage_S3(E2);
        if(P1==P2 && P1==P3)
        {
            EXP1 = EXP1 - EXP1 * 0.25;
            checkEXP1(EXP1);
        }else 
        {
            float avrP = (P1 + P2 + P3)/3;
            if(avrP < 0.5)
            {
                mau = HP1;
                mau = mau - mau * 0.15;
                int x = ceil(mau);
                checkHP1(x);
                HP1 = x;
                kinhnghiem = EXP1;
                kinhnghiem = kinhnghiem + kinhnghiem * 0.15;
                int y = ceil(kinhnghiem);
                checkEXP1(y);
                EXP1 = y;
            }else
            {
                mau = HP1;
                mau = mau - mau * 0.1;
                int x = ceil(mau);
                checkHP1(x);
                HP1 = x;
                kinhnghiem = EXP1;
                kinhnghiem = kinhnghiem + kinhnghiem * 0.2;
                int y = ceil(kinhnghiem);
                checkEXP1(y);
                EXP1 = y;
            }
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    const int ROWS = 10;
    const int COLS = 10;
    int matrix[ROWS][COLS];
    int x, y;
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int count = 0;
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            if(matrix[i][j] > E3*2)
            {
                count ++;
            }
        }
    }
    int matrixi;
    int matrixj;
    if(count / 10 != 0)
    {
        while(count / 10 != 0)
        {
            int x = count % 10;
            int y = count / 10;
            matrixi = x + y;
            count = matrixi;
        }
    }else matrixi = count;
    
    int countdiff = 0;
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            if(matrix[i][j] < -E3)
            {
                countdiff ++;
            }
        }
    }
    
    if(countdiff / 10 != 0)
    {
        while(countdiff / 10 != 0)
        {
            int x = countdiff % 10;
            int y = countdiff / 10;
            matrixj = x + y;
            countdiff = matrixj;
        }
    }else matrixj = countdiff;

    int index1 = 0;
    int index2 = 0;
    int a = matrixi;
    int b = matrixi;
    int c = matrixj;
    int d = matrixj;
    
    int e = matrixi;
    int f = matrixi;
    int g = matrixj;
    int h = matrixj;
    //////////
    int ptLeft = 0;
    while(a > 0 && c > 0)
    {
        a = a - 1;
        c = c - 1;
        ptLeft ++;
    }

    while(b < 9 && d < 9)
    {
        b = b + 1;
        d = d + 1;
        ptLeft ++;
    }
    int ptRight = 0;
    while(e > 0 && g < 9)
    {
        e = e - 1;
        g = g + 1;
        ptRight++;
    }

    while(f < 9 && h > 0)
    {
        f = f + 1;
        h = h - 1;
        ptRight++;
    }
    /////////
    int Left[ptLeft];
    int Right[ptRight];
    a = matrixi;
    b = matrixi;
    c = matrixj;
    d = matrixj;
    
    e = matrixi;
    f = matrixi;
    g = matrixj;
    h = matrixj;
    //cheo trai//
    //di len//
    while(a > 0 && c > 0)
    {
        a = a - 1;
        c = c - 1;
        Left[index1++] = matrix[a][c];
    }
    //di xuong
    while(b < 9 && d < 9)
    {
        b = b + 1;
        d = d + 1;
        Left[index1++] = matrix[b][d];
    }
    //cheo phai//
    //di len//
    while(e > 0 && g < 9)
    {
        e = e - 1;
        g = g + 1;
        Right[index2++] = matrix[e][g];
    }
    //di xuong//
    while(f < 9 && h > 0)
    {
        f = f + 1;
        h = h - 1;
        Right[index2++] = matrix[f][h];
    }
    
    int max = matrix[matrixi][matrixj];
    int pointtaxi = max;

    //max trong Right//
    for(int i = 0; i < ptRight; i++)
    {
        if(Right[i] > max)
        {
            max = Right[i];
        }
    }
    //max trong Left//
    for(int i = 0; i<ptLeft; i++)
    {
        if(Left[i] > max)
        {   
            max = Left[i];    
        }
    }
    int pointSherlock = max;
    if(abs(pointtaxi) > pointSherlock)
    {
        HP1 = HP1 * 0.9 + 0.999;
        checkHP1(HP1);
        HP2 = HP2 * 0.9 + 0.999;
        checkHP1(HP2);
        EXP1 = EXP1 * 0.88 + 0.999;
        checkEXP2(EXP1);
        EXP2 = EXP2 * 0.88 + 0.999;
        checkEXP2(EXP2);
        
    }else
    {
        HP1 = HP1 * 1.1 + 0.999;
        checkHP1(HP1);
        HP2 = HP2 * 1.1 + 0.999;
        checkHP1(HP2);
        EXP1 = EXP1 * 1.12 + 0.999;
        checkEXP2(EXP1);
        EXP2 = EXP2 * 1.12 + 0.999;
        checkEXP2(EXP2);
    }
    
    int resuilt = 0;
    if(abs(pointtaxi) > pointSherlock)
    {
        resuilt = pointtaxi;
    }else
    {
        resuilt = pointSherlock;
    }
    return resuilt;
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    // TODO: Complete this function
    // kiemtra do dai
    if (strlen(s) < 8) 
    {
        return -1;
    }
    if (strlen(s) > 20) 
    {
        return -2; 
    }

    // kiemtra se
    string sStr(s);
    string emailStr(email);
    string se = emailStr.substr(0, emailStr.find('@'));

    size_t pos = sStr.find(se);
    if (pos != string::npos) 
    {
        return -(300 + pos); 
    }

    // kiemtra chuoi lien tiep
    for (int i = 0; i < strlen(s) - 2; ++i)
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) 
        {
            return -(400 + i); 
        }
    }

    // kiem tra ki tu dac biet
    bool hasSpecialChar = false;
    for (const char *ptr = s; *ptr != '\0'; ++ptr) 
    {
        if (*ptr == '@' || *ptr == '#' || *ptr == '%' || *ptr == '$' || *ptr == '!') 
        {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) 
    {
        return -5; 
    }

    // kiem tra cac ki tu
    for (int i = 0; i < strlen(s); ++i) 
    {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) 
        {
            return i; 
        }
    }

    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;  
    int maxLength = 0; 
    int maxIndex = -1; 

    for (int i = 0; i < num_pwds; ++i) 
    {
        if (arr_pwds[i] == nullptr) continue;
        int count = 1; 
        int length = std::strlen(arr_pwds[i]); 
        for (int j = i + 1; j < num_pwds; ++j) 
        {
            if (arr_pwds[j] != nullptr && std::strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
            {
                count++;
                arr_pwds[j] = nullptr; 
            }
        }
        if (count > maxCount || (count == maxCount && length > maxLength)) 
        {
            maxCount = count;
            maxLength = length;
            maxIndex = i;
        }
    }

    return maxIndex; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////