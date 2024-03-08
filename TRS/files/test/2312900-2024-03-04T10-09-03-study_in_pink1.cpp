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
int kiemTraSucKhoe(int &HP)
{
    if (HP > 666)
    {
        HP = 666;
    }
    else if (HP < 0)
    {
        HP = 0;
    }
    return HP;
}
int kiemTraKinhNghiem(int &EXP)
{
    if (EXP > 600)
    {
        EXP = 600;
    }
    else if (EXP < 0)
    {
        EXP = 0;
    }
    return EXP;
}
int kiemTraMoney(int &M)
{
    if (M > 3000)
    {
        M = 3000;
    }
    else if (M < 0)
    {
        M = 0;
    }
    return M;
}
int kiemTraChinhPhuong(int &EXP1)
{
    double i = sqrt(EXP1);
    i  = round(i);
    return i*i;
}

//! Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    if (e1 < 0 || e1 > 99) return -99;
    if (e1 >= 0 && e1 <= 3)
    {
        int D = ((e1 * 3) + (exp1 * 7));
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 = exp2 + 29 + 45 + 75;
            break;
        default:
            break;
        }
        if (D % 2 == 0)
        {
            exp1 = ceil(exp1 + D / 200.0);
        }
        else exp1 = ceil(exp1 - D / 100.0);
    }
    else
    {
        exp1 -= e1;
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (e1 / 9.0) + 21);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (e1 / 16.0) + 17);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (e1 / 4.0) + 19);
            if (exp2 > 200)
            {
                exp2 = ceil(exp2 + (e1 / 9.0) + 21);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            int A = ceil(exp2 + (e1 / 4.0) + 19);
            exp2 = ceil(A + (e1 / 9.0) + 21);
            if (exp2 > 400)
            {
                int B = ceil(exp2 + (e1 / 16.0) + 17);
                exp2 = ceil(B*115.0/100);
            }
        }
    }
        exp1 = kiemTraKinhNghiem(exp1);
        exp2 = kiemTraKinhNghiem(exp2);
        return exp1 + exp2;
}
// Task 2
int chuSoCuoiCungE2(int E2)
{
    int i;
    int temp = E2;
    int sumDigit = 0;
    while (temp > 0)
    {
        sumDigit += temp % 10;
        temp /= 10;
    }
    i = sumDigit % 10;
    return i;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double scp = kiemTraChinhPhuong(EXP1);
    double P1,P2,P3;
    // path 1

    if (EXP1 >= scp)
    {
        P1 = 100/100.0;
    }
    else P1 = ((EXP1 / scp) + 80) / 123;

    // path 2

    if (E2%2 != 0){
        int const A = M1;
        for(int i = 0; i <= A/2; i = M1){
            if (HP1 > 200){
                HP1 = ceil(HP1*110.0/100);
                M1 = M1 - 70;
                M1 = kiemTraMoney(M1);
                HP1 = kiemTraSucKhoe(HP1);
            }

            if (EXP1 < 400){
                M1 = M1 - 200;
                M1 = kiemTraMoney(M1);
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = kiemTraKinhNghiem(EXP1);
            }
            else {
                M1 = M1 - 120;
                M1 = kiemTraMoney(M1);
                EXP1 = ceil(EXP1*113.0/100);
                EXP1 = kiemTraKinhNghiem(EXP1);       
            }

            if (EXP1 < 300){
                M1 = M1 - 100;
                M1= kiemTraMoney(M1);
                EXP1 = ceil(EXP1*110.0/100);
                EXP1 = kiemTraKinhNghiem(EXP1);
            }
            else {
                M1 = M1 - 120;
                M1= kiemTraMoney(M1);
                EXP1 = ceil(EXP1*110.0/100);
                EXP1 = kiemTraKinhNghiem(EXP1);
            }
        }

        HP1 = ceil(HP1*117.0/100);
        HP1 = kiemTraSucKhoe(HP1);
        EXP1 = ceil(EXP1*117.0/100);
        EXP1 = kiemTraKinhNghiem(EXP1);
        if (EXP1 >= scp)
        {
            P2 = 100;
        }
            else
        P2 = ((EXP1 / scp) + 80) / 123;

    }

    if (E2%2 == 0){
        if (HP1 > 200){
            HP1 = ceil(HP1*110.0/100);
            M1 = M1 - 70;
            M1 = kiemTraMoney(M1);
            HP1 = kiemTraSucKhoe(HP1);
        }

        if (EXP1 < 400 && M1 > 0){
            M1 = M1 - 200;
            M1 = kiemTraMoney(M1);
            EXP1 = ceil(EXP1*113.0/100);
            EXP1 = kiemTraKinhNghiem(EXP1);
        }

        if (EXP1 > 400 && M1 > 0) {
            M1 = M1 - 120;
            M1 = kiemTraMoney(M1);
            EXP1 = ceil(EXP1*113.0/100);
            EXP1 = kiemTraKinhNghiem(EXP1);       
        }

        if (EXP1 < 300 && M1 > 0){
            M1 = M1 - 100;
            M1= kiemTraMoney(M1);
            EXP1 = ceil(EXP1*110.0/100);
            EXP1 = kiemTraKinhNghiem(EXP1);
        }

        if (EXP1 > 300 && M1 > 0) {
            M1 = M1 - 120;
            M1= kiemTraMoney(M1);
            EXP1 = ceil(EXP1*110.0/100);
            EXP1 = kiemTraKinhNghiem(EXP1);
        }

        HP1 = ceil(HP1*117.0/100);
        HP1 = kiemTraSucKhoe(HP1);
        EXP1 = ceil(EXP1*117.0/100);
        EXP1 = kiemTraKinhNghiem(EXP1);
        if (EXP1 >= scp)
        {
            P2 = 100/100.0;
        }
            else
        P2 = ((EXP1 / scp) + 80) / 123;
    }

    // path 3

    double p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3 = p[chuSoCuoiCungE2(E2)];

    // tong ket
    double proportion;
    proportion = (P1 + P2 + P3)/3;
    if (proportion == 1) EXP1 = ceil(EXP1*75.0/100);
    
    if (proportion < 1/2)
    {
        HP1 = ceil(HP1*85.0/100);
        EXP1 = ceil(EXP1*115.0/100);
        EXP1 = kiemTraKinhNghiem(EXP1);
    }

    if (proportion >= 1/2)
    {
        HP1 = ceil(HP1*90.0/100);
        EXP1 = ceil(EXP1*20.0/100);   
        EXP1 = kiemTraKinhNghiem(EXP1);     
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int reduceToSingleDigit(int num)
{
    while (num >= 10)
    {
        num = sumOfDigits(num);
    }
    return num;
}
int giaTriToaDo(int &toado)
{
    int td = reduceToSingleDigit(toado);
    return td;
}
int tinhDiemSo(int &E3, int i, int j) {
    int D = ((E3 * j) + (i * 2)) * (i - j);
    return D;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int arr[10][10];
    int toaDoX = 0;
    int toaDoY = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int diem = tinhDiemSo(E3,i,j);
            arr[i][j] = diem;
            if (diem > (E3 * 2))
            {
                toaDoX += 1;
            }
            if (diem < (-E3))
            {
                toaDoY += 1;
            }
        }
    }
    toaDoX = giaTriToaDo(toaDoX);
    toaDoY = giaTriToaDo(toaDoY);
    int diemTaxi = tinhDiemSo(E3, toaDoX, toaDoY);

// tinh diem so cua Sherlock va Watson
    int leftDiagonalScore = 0;
    int row = toaDoX, col = toaDoY;
    while (row >= 0 && col >= 0) {
        leftDiagonalScore = fmax(leftDiagonalScore, arr[row][col]);
        row--;
        col--;
    }

    row = toaDoX, col = toaDoY;
    while (row < 10 && col < 10) {
        leftDiagonalScore = fmax(leftDiagonalScore, arr[row][col]);
        row++;
        col++;
    }

    // tinh diem so duong cheo phai
    int rightDiagonalScore = 0;
    row = toaDoX, col = toaDoY;
    while (row >= 0 && col < 9) {
        rightDiagonalScore = fmax(rightDiagonalScore, arr[row][col]);
        row--;
        col++;
    }

    row = toaDoX, col = toaDoY;
    while (row < 9 && col >= 0) {
        rightDiagonalScore = fmax(rightDiagonalScore, arr[row][col]);
        row++;
        col--;
    }

    // diem so cua sherlock va watson
    int score = fmax(leftDiagonalScore, rightDiagonalScore);
    if (score >= abs(diemTaxi))
    {
        EXP1 *= 1.12;
        EXP2 *= 1.12;
        HP1 *= 1.1;
        HP2 *= 1.1;
    }
    else 
    {
        EXP1 *= 0.88;
        EXP2 *= 0.88;
        HP1 *= 0.9;
        HP2 *= 0.9;
    }
    EXP1 = kiemTraKinhNghiem(EXP1);
    EXP2 = kiemTraKinhNghiem(EXP2);
    HP1 = kiemTraSucKhoe(HP1);
    HP2 = kiemTraSucKhoe(HP2);
    if (score >= abs(diemTaxi))
    {
        return score;
    }
    else return diemTaxi;
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // lay ra chuoi se
    const char *pos = strchr(email, '@');
    if (pos == NULL)
    {
        return -1;
    }
    int seLength = pos - email;
    char se[seLength + 1];
    strncpy(se, email, seLength);

    // check length pass
    int passLength = strlen(s);
    if (passLength < 8)
    {
        return -1;
    }
    else if (passLength > 20)
    {
        return -2;
    }

    // check s voi se
    const char *found = strstr(s,se); // tim vi tri s trong se
    if (found != NULL)
    {
        return -(300+(found-s));
    }
    
    // check ky tu lien tiep giong nhau
    for (int i = 0; i < passLength-2; i++)
    {
        if (s[i]==s[i+1] && s[i+1]==s[i+2])
        {
            return -(400 + i); 
        }
    }
    
    // kiem tra ky tu dac biet
    bool hasSpecialChar = false;
    for (int i = 0; i < passLength; i++)
    {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')
        {
            return -5;
        }
        if (!hasSpecialChar && (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
        {
            hasSpecialChar = true;
        }
    }
    if (!hasSpecialChar)
    {
        return -5;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////