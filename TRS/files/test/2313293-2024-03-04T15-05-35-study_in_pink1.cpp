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

//---------------------------LAM TRON LEN CAC SO---------------------------
int round_up(float d){
    d = (d - (int) d > 0.5) || (d - (int) d == 0) ? d : d + 0.5;
    return round(d);
}

//----------------------------DIEU CHINH CHI SO----------------------------
void fix_HPstatus (int & HP)
{
    HP = HP > 666 ? 666 : (HP < 0 ? 0 : HP);
}

void fix_EXPstatus (int & EXP)
{
    EXP = EXP > 600 ? 600 : (EXP < 0 ? 0 : EXP);
}

void fix_MONEYstatus (int & M1)
{
    M1 = M1 > 3000 ? 3000 : (M1 < 0 ? 0 : M1);
}
// Task 1

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99)
    {
        return -99;
    }
    //----------KIEM TRA TRUONG HOP E NAM TRONG DOAN [0;3]----------
    if (e1 <= 3){
            switch (e1) {
                case 0: {
                    exp2 += 29; //  Cong 29 EXP
                }
                break;
                case 1: {
                    exp2 += 45; //  Cong 45 EXP
                }
                break;
                case 2: {
                    exp2 += 75; //  Cong 75 EXP
                }
                break;
                case 3: {
                    exp2 += (29 + 45 + 75); // Cong gia tri EXP tuong ung voi tong cua 3 thong tin tren
                }
                break;
            }
        int d = e1 * 3 + exp1 * 7;  // Thiet lap quyet dinh D cua Sherlock
        if (d % 2) {
            exp1 = round_up(exp1 - (float)d/100);  //  Giam EXP neu Sherlock dua ra lua chon dung
            fix_EXPstatus(exp1);
        }
        else {
            exp1 = round_up(exp1 + (float)d/200);  //  Tang EXP neu Sherlock dua ra lua chon sai
            fix_EXPstatus(exp1);
        }
    }
    //----------KIEM TRA TRUONG HOP E NAM TRONG DOAN [4;99]----------

    else {
        float exp_earn_1 = ((float)e1/4 + 19);      //EXP nhan duoc neu Sherlock giai thich thong tin 1
        float exp_earn_2 = ((float)e1/9 + 21);      //EXP nhan duoc neu Sherlock giai thich thong tin 2
        float exp_earn_3 = ((float)e1/16 + 17);     //EXP nhan duoc neu Sherlock giai thich thong tin 3
        if (e1 <= 19){
            exp2 = round_up(exp2 + exp_earn_1);
        }
        else if (e1 <= 49){
            exp2 = round_up(exp2 + exp_earn_2);
        }
        else if (e1 <= 65){
            exp2 = round_up(exp2 + exp_earn_3);
        }
        else if (e1 <= 79){
            if (round_up(exp2 + exp_earn_1) > 200){
                exp2 = round_up(round_up(exp2 + exp_earn_1) + exp_earn_2);
            }
            else exp2 = round_up(exp2 + exp_earn_1);
        }
        else {
            if (round_up(round_up(exp2 + exp_earn_1) + exp_earn_2) > 400){
                exp2 = round_up(round_up(round_up(round_up(exp2 + exp_earn_1) + exp_earn_2) + exp_earn_3) * 1.15);  //Tang 15% EXP neu giai thich du ca 3 thong tin
            }
            else exp2 = round_up(round_up(exp2 + exp_earn_1) + exp_earn_2);
        }
        fix_EXPstatus(exp2);

        exp1 -= e1; //Sherlock bi tru di E1 EXP
        fix_EXPstatus(exp1);
    }

    return exp1 + exp2;
}

// Task 2

//--------------------TIM SO CHINH PHUONG GAN EXP1 NHAT--------------------
int Nearest_sq_probability (int EXP1){
    int sq_num = sqrt(EXP1);

    // Xac suat de tim thay vali
    float p = abs(EXP1 - sq_num * sq_num) < abs(EXP1 - (sq_num + 1) * (sq_num + 1)) ? 100 : ((((float)EXP1 / ((sq_num + 1) * (sq_num + 1))) + 80) / 123 * 100);

    return p;
}

//--------------------SHERLOCK DI QUA HET CAC SU KIEN--------------------
void Event(int & HP1, int & EXP1, int & M1, int E2)
{
    int Money_used = 0;                 // So tien da dung
    int Intital_Money = M1;             // So tien ban dau
    bool check_Even_E2 = !(E2 % 2);     //Kiem tra xem E2 la so chan hay khong
    do
    {
        //---------------------------Su kien 1---------------------------
        if (HP1 < 200)
        {
            HP1 = round_up((float)HP1 * 1.3);
            M1 -= 150;
        }
        else
        {
            HP1 = round_up((float)HP1 * 1.1);
            M1 -= 70;
        }
        Money_used = Intital_Money - M1;

        fix_HPstatus(HP1);
        fix_MONEYstatus(M1);

        if (((Money_used > Intital_Money * 0.5) && (!check_Even_E2)) || ((M1 == 0)&& (check_Even_E2)))
        {
            break;
        }

        //---------------------------Su kien 2---------------------------
        M1 = EXP1 < 400 ? M1 - 200 : M1 - 120;
        EXP1 = round_up((float)EXP1 * 1.13);
        Money_used = Intital_Money - M1;

        fix_HPstatus(HP1);
        fix_MONEYstatus(M1);

        if (((Money_used > Intital_Money * 0.5) && (!check_Even_E2)) || ((M1 == 0)&& (check_Even_E2)))
        {
            break;
        }

        //---------------------------Su kien 3---------------------------
        M1 = EXP1 < 300 ? M1 - 100 : M1 - 120;
        EXP1 = round_up((float)EXP1 * 0.9);
        Money_used = Intital_Money - M1;

        fix_HPstatus(HP1);
        fix_MONEYstatus(M1);

        if (((Money_used > Intital_Money * 0.5) && (!check_Even_E2)) || ((M1 == 0)&& (check_Even_E2)))
        {
            break;
        }
    }
    while (!check_Even_E2);
}

//-----------------TINH GIA TRI XAC SUAT CUA CON DUONG 3-----------------
int probability_3(int E2)
{
    int probability[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int sum_digit = 0;

    while (E2)
    {
        sum_digit += (E2 % 10);
        E2 /= 10;
    }
    sum_digit %= 10;
    return probability[sum_digit];
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99)
    {
        return -99;
    }
    //--------------------------Con duong 1--------------------------
    float P1 = Nearest_sq_probability (EXP1);   //Tinh xac suat P1

    //--------------------------Con duong 2--------------------------

    Event(HP1, EXP1, M1, E2);

    HP1 = round_up((float)HP1 * 0.83);
    EXP1 = round_up((float)EXP1 * 1.17);

    fix_HPstatus(HP1);
    fix_EXPstatus(EXP1);

    float P2 = Nearest_sq_probability (EXP1);   //Tinh xac suat P2

    //--------------------------Con duong 3--------------------------
    float P3 = probability_3(E2);           //Tinh xac suat P3

    //------------------Gia tri xac suat trung binh------------------
    float P_mean = (P1 + P2 + P3) / 3;
    if (P_mean == 100)  //Neu ca ba lan xac suat deu la 100
    {
        EXP1 = round_up(EXP1 * 0.75);
    }
    else if (P_mean < 50)
    {
        HP1 = round_up((float)HP1 * 0.85);
        EXP1 = round_up((float)EXP1 * 1.15);
    }
    else
    {
        HP1 = round_up((float)HP1 * 0.9);
        EXP1 = round_up((float)EXP1 * 1.2);
    }

    fix_HPstatus(HP1);
    fix_EXPstatus(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int digitReduce(int a)
{
    while (a >= 10)
    {
        int sum_digit = 0;
        while (a)
        {
            sum_digit += a % 10;
            a /= 10;
        }
        a = sum_digit;
    }
    return a;
}

int Diagonal(int TaxiEXP[][10], int row, int column)
{
    int sum = row + column;
    int diff = row - column;
    int i = row;
    int j = column;
    int Max_point = TaxiEXP [column][row];

    //Quet tat ca cac gia tri tren duong cheo phai
    do{
        ++i; --j;

        if ((i > sum) || (i > 9)){
            swap(--i, ++j);
        }
        if (Max_point < TaxiEXP[i][j]){
            Max_point = TaxiEXP[i][j];
        }
    }
    while (i != row);

    //Quet tat ca cac gia tri tren duong cheo trai
    do{
        ++i; ++j;

        if ((j > 9) || (i > 9)){
            if (diff > 0){
                i -= j;
                j = 0;
            }
            else{
                j -= i;
                i = 0;
            }
        }

        if (Max_point < TaxiEXP[i][j]){
            Max_point = TaxiEXP[i][j];
        }
    }
    while (i != row);

    //Tra ve gia tri diem lon nhat
    return Max_point;
}

bool Chase(int E3, int &Point)
{
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }

    int TaxiEXP [10][10] = { };
    int Pos_count = 0;      //So gia tri diem lon hon E3 * 2
    int Neg_count = 0;      //So gia tri diem nho hon - E3
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            TaxiEXP[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (TaxiEXP[i][j] > E3 * 2)
            {
                ++Pos_count;
            }
            else if (TaxiEXP[i][j] < - E3)
            {
                ++Neg_count;
            }
        }
    }

    int columnTaxi = digitReduce(Pos_count);                        //Thiet lap chi so i
    int rowTaxi = digitReduce(Neg_count);                           //Thiet lap chi so j
    int Taxi_point = TaxiEXP[columnTaxi][rowTaxi];                  //Diem so cua Taxi tai diem (i,j)
    int Sherlock_point = Diagonal(TaxiEXP, columnTaxi, rowTaxi);    //Diem so cua Sherlock

    Point = Sherlock_point >= abs(Taxi_point) ? Sherlock_point : Taxi_point;
    return Sherlock_point >= abs(Taxi_point);        //Kiem tra xem ai co diem so cao hon
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int Point;
    int sign = Chase(E3, Point) ? 1 : -1;

    HP1 = round_up((float) HP1 + sign * 0.1 * (float)HP1);
    HP2 = round_up((float) HP2 + sign * 0.1 * (float)HP2);
    EXP1 = round_up((float) EXP1 + sign * 0.12 * (float)EXP1);
    EXP2 = round_up((float) EXP2 + sign * 0.12 * (float)EXP2);

    fix_EXPstatus(EXP1);
    fix_EXPstatus(EXP2);
    fix_HPstatus(HP1);
    fix_HPstatus(HP2);

    return Point;
}

// Task 4

//--------------------KIEM TRA XEM MAT KHAU CO CHUA SE-------------------
bool checkContain(int i, string se, string pass_check, int Index_address)
{
    string contain = pass_check.substr(i, Index_address);
    return (contain == se);
}

//--------------KIEM TRA XEM MAT KHAU CHUA 2 KI TU LIEN TIEP-------------
bool checkConsecutive(int i, string pass_check)
{
    return ((pass_check[i] == pass_check[i + 1]) && (pass_check[i] == pass_check[i + 2]));
}

//---------------KIEM TRA XEM MAT KHAU CHUA KI TU DAC BIET---------------
bool checkSpecialCharacter(int i, string pass_check)
{
    return (pass_check[i] == '@' || pass_check[i] == '%' || pass_check[i] == '#' || pass_check[i] == '$' || pass_check[i] == '!');
}

//----------------KIEM TRA XEM MAT KHAU CHUA KI TU HOP LE----------------
bool checkInvalidCharacter(int i, string pass_check)
{
    return !(((int)pass_check[i] >= 48 && (int)pass_check[i] <= 57) ||((int)pass_check[i] >= 65 && (int)pass_check[i] <= 90) || ((int)pass_check[i] >= 97 && (int)pass_check[i] <= 122) || checkSpecialCharacter(i, pass_check));
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int Index_address = 0;
    string email_check = email;
    string pass_check = s;

    //------------------Tach chuoi ki tu truoc '@'-------------------
    while (email[Index_address] != '@')
    {
        ++Index_address;
    }
    string se = email_check.substr(0, Index_address);

    //---------------Kiem tra tinh hop le cua mat khau---------------
    if (pass_check.size() < 8)          //Mat khau it hon 8 ki tu
    {
        return -1;                                  //Tra ve gia tri -1
    }
    else if (pass_check.size() > 20)    //Mat khau nhieu hon 20 ki tu
    {
        return -2;                                  //Tra ve gia tri -2
    }
    else
    {
        bool Contain = 0;       //Kiem tra mat khau chua chuoi se?
        bool Consecutive = 0;   //Kiem tra mat khau co nhieu hon hai ki tu lien tiep?
        bool Special = 0;       //Kiem tra mat khau chua ki tu dac biet?
        bool Invalid = 0;       //Kiem tra mat khau chua ki tu khong hop le?

        int Contain_Position;       //Vi tri dau tien chua chuoi se
        int Consecutive_Position;   //Vi tri dau tien co hai ki tu lien tiep
        int Invaild_Position;       //Vi tri dau tien ki tu khong hop le

        for (int i = pass_check.size() - 1 ; i >= 0; i--)
        {
            if (checkContain(i, se, pass_check, Index_address))
            {
                Contain = 1;                        //Mat khau co chua chuoi se
                Contain_Position = -(300 + i);      //Cap nhat vi tri
            }
            else if (checkConsecutive(i, pass_check))
            {
                Consecutive = 1;                    //Mat khau co nhieu hon hai ki tu lien tiep
                Consecutive_Position = -(400 + i);  //Cap nhat vi tri
            }
            else if (checkInvalidCharacter(i, pass_check))
            {
                Invalid = 1;                        //Mat khau co chua ki tu khong hop le
                Invaild_Position = i;               //Cap nhat vi tri
            }
            if (checkSpecialCharacter(i, pass_check))
            {
                Special = 1;                        //Mat khau co chua ki tu dac biet
            }
        }

        if (Contain)
        {
            return Contain_Position;                //Tra ve gia tri -(300 + <sei>)
        }
        else if (Consecutive)
        {
            return Consecutive_Position;            //Tra ve gia tri -(400 + <sei>)
        }
        else if (!Special)
        {
            return -5;                             //Tra ve gia tri -10
        }
        else if (Invalid)
        {
            return Invaild_Position;                //Tra ve gia tri Invaild_Character
        }
        else return -10;                             //Tra ve gia tri -5
    }

}

// Task 5
//--------------------------SO SANH VA CAP NHAT--------------------------
void Compare(int Count , int & Max_Frequency, int Index_Check, int & Index_result, const char * arr_pwds[])
{
    //So sanh do dai cua chuoi nhieu so lan xuat hien hai chuoi bang nhau
    if (Count == Max_Frequency)
    {
        Index_result = strlen(arr_pwds[Index_Check]) > strlen(arr_pwds[Index_result]) ? Index_Check : Index_result;
    }
    //So sanh so lan xuat hien hai chuoi
    else if (Count > Max_Frequency)
    {
        Max_Frequency = Count;
        Index_result = Index_Check;
    }
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int Max_Frequency = 0;  //So lan xuat hien cua chuoi xuat hien nhieu nhat
    int Index_result = 0;   //Vi tri dau tien cua chuoi xuat hien nhieu nhat

    for (int i = 0; i < num_pwds; i++)
    {
        if (arr_pwds[i] != "")          //Kiem tra chuoi da kiem tra chua?
        {
            int Count = 1;              //So lan chuoi xuat hien
            int Index_Check = i;        //Vi tri dau tien cua chuoi

            for (int j = i + 1; j < num_pwds; j++)
            {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)                      //Kiem tra hai chuoi co bang nhau hay khong?
                {
                    Count++;                                                    //Tang so lan xuat hien chuoi
                    arr_pwds[j] = "";                                           //Chuoi nay da kiem tra
                }
            }
            Compare(Count, Max_Frequency, Index_Check, Index_result, arr_pwds); //So sanh va cap nhat chi so
        }
    }
    return Index_result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
