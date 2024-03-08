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
void check_HP(int& HP)
{
    if (HP < 0) { HP = 0; }
    if (HP > 666) { HP = 666; }
}

void check_EXP(int& EXP)
{
    if (EXP < 0) { EXP = 0; }
    if (EXP > 600) { EXP = 600; }
}

void check_M_2(int& M)
{
    if (M < 0) { M = 0; }
    if (M > 3000) { M = 3000; }
}

bool check_M(int& M)
{
    if (M < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Task 1
int firstMeet(int& exp1, int& exp2, int e1)
{
    if ((e1 < 0) || (e1 > 99)) { return -99; } //Kiem tra dieu kien E1
    else {
        //TH1
        check_EXP(exp1);
        check_EXP(exp2);
        if ((e1 >= 0) && (e1 <= 3))
        {
            if (e1 == 0) { exp2 += 29; }
            else if (e1 == 1) { exp2 += 45; }
            else if (e1 == 2) { exp2 += 75; }
            else { exp2 += 29 + 45 + 75; }
            int D = e1 * 3 + exp1 * 7;
            if (D % 2 == 0)
            {
                double a1 = (D / 200.0);
                exp1 = ceil(exp1 + a1);
            }
            else
            {
                double a1 = D / 100.0;
                exp1 = ceil(exp1 - a1);
            }

            check_EXP(exp1);
            check_EXP(exp2);
        }

        //TH2
        else if ((e1 >= 4) && (e1 <= 99))
        {
            double a1 = (e1 / 4.0) + 19;
            double a2 = (e1 / 9.0) + 21;
            double a3 = (e1 / 16.0) + 17;
            if ((e1 >= 4) && (e1 <= 19))
            {
                exp2 += ceil(a1);
            }
            else if ((e1 >= 20) && (e1 <= 49)) { exp2 += ceil(a2); }
            else if ((e1 >= 50) && (e1 <= 65)) { exp2 += ceil(a3); }
            else if ((e1 >= 66) && (e1 <= 79))
            {
                exp2 += ceil(a1);
                if (exp2 > 200) { exp2 += ceil(a2); }
            }
            else
            {
                exp2 += ceil(a1);
                exp2 += ceil(a2);
                if (exp2 > 400)
                {
                    exp2 += ceil(a3);
                    //long double l = 1.15 * exp2;
                    exp2 = exp2 * 1.15 + 0.999;
                }
            }
            exp1 -= e1;
        }
        check_EXP(exp1);
        check_EXP(exp2);
        return exp1 + exp2;
    }
}

//Task 2

//Find nearest square num:
int Find_nsqrnum(int& EXP1)
{
    int sqrt_EXP1 = sqrt(EXP1);
    int lowerS = pow(sqrt_EXP1, 2);
    int higherS = pow(sqrt_EXP1 + 1, 2);
    if (abs(EXP1 - lowerS) < abs(higherS - EXP1))
    {
        return lowerS;
    }
    else
    {
        return higherS;
    }
}

//Su kien 1
void Event1(int& HP1, int& M1, int& M_require)
{
    if (HP1 < 200)
    {
        double box = HP1 * 130.0 / 100.0;
        HP1 = ceil(box);
        M1 -= 150;
        M_require += 150;
    }
    else
    {
        double box = HP1 * 110.0 / 100.0;
        HP1 = ceil(box);
        M1 -= 70;
        M_require += 70;
    }
    check_HP(HP1); //loi nua thi bo dong nay luon thu

}

//Su kien 2 
void Event2(int& EXP1, int& M1, int& M_require)
{
    if (EXP1 < 400)
    {
        M1 -= 200;
        M_require += 200;
    }
    else
    {
        M1 -= 120;
        M_require += 120;
    }
    //EXP1=EXP1*113/100.0;
    EXP1 = ceil(EXP1 * 113 / 100.0);
    check_EXP(EXP1); //loi nua thi bo dong nay luon thu
}
//Su kien 3
void Event3(int& EXP1, int& M1, int& M_require)

{
    if (EXP1 < 300)
    {
        M1 -= 100;
        M_require += 100;
    }
    else
    {
        M1 -= 120;
        M_require += 120;
    }
    //EXP1=EXP1*90/100.0;
    EXP1 = ceil(EXP1 * 90 / 100.0);
    check_EXP(EXP1); //loi nua thi bo dong nay luon thu
}

void dibo(int& HP1, int& EXP1)
{
    double e = HP1 * 83 / 100.0;
    HP1 = ceil(e);
    double f = EXP1 * 117 / 100.0;
    EXP1 = ceil(f);
    check_EXP(EXP1);
    check_HP(HP1);
}

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
    double P1 = 0, P2 = 0, P = 0;
    int M_require = 0;
    int M1_original = M1;
    if ((E2 < 0) || (E2 > 99)) { return -99; } //Kiem tra dieu kien E2
    else
    {
        //check_M_2(M1);

        //Con duong 01
        int S1 = Find_nsqrnum(EXP1);
        if (EXP1 >= S1) { P1 = 1; }
        else (P1 = ((EXP1 / S1 * 1.0) + 80.0) / 123.0);

        //Con duong 02
        if (M1 == 0) { dibo(HP1, EXP1); }// Neu tu dau M1=0
        else
        {
            //Truong hop E2 chan 
            if (E2 % 2 == 0)
            {
                Event1(HP1, M1, M_require);
                if (check_M(M1))
                {
                    Event2(EXP1, M1, M_require);
                    if (check_M(M1))
                    {
                        Event3(EXP1, M1, M_require);
                    }
                }
                dibo(HP1, EXP1);
            }

            //Truong hop E2 le
            else
            {
                while (M_require <= (0.5 * M1_original))
                {
                    Event1(HP1, M1, M_require);
                    if (M_require <= (0.5 * M1_original))
                    {
                        Event2(EXP1, M1, M_require);
                        if (M_require <= (0.5 * M1_original))
                        {
                            Event3(EXP1, M1, M_require);
                            if (M_require > (0.5 * M1_original))
                            {
                                dibo(HP1, EXP1);
                            }
                        }
                        else { dibo(HP1, EXP1); }
                    }
                    else { dibo(HP1, EXP1); }
                }
            }

        }
        if (M1 < 0) M1 = 0;

        int S2 = Find_nsqrnum(EXP1);
        if (EXP1 >= S2) { P2 = 1; }
        else (P2 = ((EXP1 / (S2 * 1.0)) + 80.0) / 123.0);

        //Con duong 03
        //Truong hop E2 chi co 1 chu so
        int i = 0;
        if (E2 < 10)
        {
            i = E2;
        }
        //Truong hop E2 co 2 chu so
        else
        {
            int hangdonvi = E2 % 10;
            int hangchuc = E2 / 10;
            int tong = hangdonvi + hangchuc;
            i = tong % 10;
        }
        double arP[10] = { 0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11 };
        double P3 = arP[i];

        //Sau khi xong ca 3 duong
        if (P1 == 1 && P2 == 1 && P3 == 1)
        {
            double k = EXP1 * 75 / 100.0;
            EXP1 = ceil(k);
        }
        else
        {
            P = (P1 + P2 + P3) / 3;
            if (P < 0.5)
            {
                double g = HP1 * 85 / 100.0;
                HP1 = ceil(g);
                double h = EXP1 * 115 / 100.0;
                EXP1 = ceil(h);
            }
            else
            {
                double g = HP1 * 90 / 100.0;
                HP1 = ceil(g);
                double h = EXP1 * 120 / 100.0;
                EXP1 = ceil(h);
            }
        }
        check_EXP(EXP1);
        check_HP(HP1);
        return HP1 + EXP1 + M1;
    }
}

//So hai chu so thanh mot chu so
int hai_thanh_motchuso(int num)
{
    while (num > 10)
    {
        for (int i = 0; ; i++) {
            int hangdonvi = num % 10;
            int hangchuc = num / 10;
            int tong = hangdonvi + hangchuc;
            num = tong;
            if (tong < 10) break;
        }
    }
    return num;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    if ((E3 < 0) || (E3 > 99)) return -99;
    else {
        int map[10][10] = {};
        int result = -1;
        //Tinh diem Taxi va xac dinh toa do diem gap
        int m = 0; // so diem lon hon E3*2
        int n = 0; // so diem nho hon -E3
        for (int i = 0; i < 10; i++) //i la so hang
        {
            for (int j = 0; j < 10; j++) //j la so cot
            {
                map[i][j] = (((E3 * j) + (i * 2)) * (i - j));
                if (map[i][j] > E3 * 2)
                {
                    m++;
                }
                if (map[i][j] < -E3)
                {
                    n++;
                }
            }
        }
        int toado_hang = hai_thanh_motchuso(m);
        int toado_cot = hai_thanh_motchuso(n);
        int diem_taxi = map[toado_hang][toado_cot];
        //Tinh diem Sherlock va Watson
        int i = 0;
        int Max = map[toado_hang][toado_cot];
        while (((toado_hang + i) <= 9) && ((toado_cot + i) <= 9))
        {
            if (Max < map[toado_hang + i][toado_cot + i])
                Max = map[toado_hang + 1][toado_cot + 1];
            i++;
        }
        i = 0;
        while (((toado_hang - i) >= 0) && ((toado_cot + i) <= 9))
        {
            if (Max < map[toado_hang - i][toado_cot + i])
                Max = map[toado_hang - i][toado_cot + i];
            i++;
        }
        i = 0;
        while (((toado_hang - i) >= 0) && ((toado_cot - i) >= 0))
        {
            if (Max < map[toado_hang - i][toado_cot - i])
                Max = map[toado_hang - i][toado_cot - i];
            i++;
        }
        i = 0;
        while (((toado_cot - i) >= 0) && ((toado_hang + i) <= 9))
        {
            if (Max < map[toado_hang + i][toado_cot - i])
                Max = map[toado_hang + i][toado_cot - i];
            i++;
        }

        int diem_SW = abs(Max);
        double a1 = EXP1 * 88 / 100.0;
        double a2 = EXP2 * 88 / 100.0;
        double a3 = EXP1 * 112 / 100.0;
        double a4 = EXP2 * 112 / 100.0;
        double b1 = HP1 * 90 / 100.0;
        double b2 = HP2 * 90 / 100.0;
        double b3 = HP1 * 110 / 100.0;
        double b4 = HP2 * 110 / 100.0;

        if (abs(diem_taxi) > diem_SW)
        {
            EXP1 = ceil(a1);
            EXP2 = ceil(a2);
            HP1 = ceil(b1);
            HP2 = ceil(b2);
            result = diem_taxi;
        }
        else
        {
            EXP1 = ceil(a3);
            EXP2 = ceil(a4);
            HP1 = ceil(b3);
            HP2 = ceil(b4);
            result = diem_SW;
        }
        check_EXP(EXP1);
        check_HP(HP1);
        check_EXP(EXP2);
        check_HP(HP2);
        return result;
    }
}



// Task 4
int checkPassword(const char* s, const char* email)
{
    string chuoi_s = s;
    string chuoi_email = email;

    //Tim chuoi se tu chuoi email
    size_t index = chuoi_email.find('@');
    string chuoi_conlai(chuoi_email, index);
    string chuoi_se = chuoi_email.substr(0, chuoi_email.length() - chuoi_conlai.length());

    //Do dai
    if (strlen(s) < 8)
    {
        return -1;
    }
    else if (strlen(s) > 20)
    {
        return -2;
    }
    
    //Truong hop se=0
    if (chuoi_se.length() == 0) return -300;

    //s chua chuoi se
    int M = chuoi_se.length();
    int N = chuoi_s.length();
    if (M <= N)
    {
        for (int i = 0; i <= N - M; i++)
        {
            int j;
            for (j = 0; j < M; j++)
                if (chuoi_s[i + j] != chuoi_se[j])
                    break;
            if (j == M)
                return -(300 + i);
        }
    }

    //s chua nhieu hon 2 ki tu lien tiep giong nhau
    if (true)
    {
        for (int i = 0; i < chuoi_s.length() - 2; i++)
        {
            if ((chuoi_s[i] == chuoi_s[i + 1]) && (chuoi_s[i + 1] == chuoi_s[i + 2]))
            {
                return -(400 + i);
                break;
            }
        }
    }

    //s chua it nhat 1 ki tu dac biet
    bool flag_cokitudacbiet = false;
    int vitri_vipham = -99;

    for (int i = 0; i < chuoi_s.length(); i++)
    {
        if ((chuoi_s[i] == '@') || (chuoi_s[i] == '#') || (chuoi_s[i] == '%') || (chuoi_s[i] == '$') || (chuoi_s[i] == '!'))
        {
            flag_cokitudacbiet = true;
        }
    }

    for (int i = 0; i < chuoi_s.length(); i++)
    {
        if ((chuoi_s[i] == '@') || (chuoi_s[i] == '#') || (chuoi_s[i] == '%') || (chuoi_s[i] == '$') || (chuoi_s[i] == '!'))
        {
            flag_cokitudacbiet = true;
            continue;
        }
        if ((chuoi_s[i] >= 'a' && chuoi_s[i] <= 'z') || (chuoi_s[i] >= 'A' && chuoi_s[i] <= 'Z')) { continue; }
        if (isdigit(chuoi_s[i])) { continue; }
        vitri_vipham = i;
        break;
    }

    if (!flag_cokitudacbiet)
    {
        return -5;
    }
    else if (vitri_vipham != -99)
    {
        return vitri_vipham;
    }


    /*   for (int i = 0; i < chuoi_s.length(); i++)
         {
             if (chuoi_s[i] != '@' && chuoi_s[i] != '#' && chuoi_s[i] != '%' && chuoi_s[i] != '$' && chuoi_s[i] != '!')
             {
                 if (!(chuoi_s[i] >= 'a' && chuoi_s[i] <= 'z') || (chuoi_s[i] >= 'A' && chuoi_s[i] <= 'Z'))
                 {
                     if (!isdigit(chuoi_s[i]))
                     {
                         return i;
                         break;
                     }
                 }
             }
         }*/

    return -10; //Mat khau dung
}

// Dem so lan xuat hien
int count_Occurence(string a[], int n, string x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
        {
            count++;
        }
    return count;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds)
{
    string* arr = new string[num_pwds];

    for (int i = 0; i < num_pwds; i++) {
        arr[i] = arr_pwds[i];
    }

    //Gia su mat khau dau tien xuat hien nhieu nhat va dai nhat
    string matkhau_dung = arr[0];
    int count_Occur_matkhaudung = count_Occurence(arr, num_pwds, arr[0]);
    int result = 0;

    //So sanh lan luot cac mat khau
    for (int i = 1; i < num_pwds; i++)
    {
        if (matkhau_dung == arr[i]) continue; //Neu giong mk dau tien thi khong can so sanh
        if (count_Occurence(arr, num_pwds, arr[i])> count_Occur_matkhaudung)
        {
            matkhau_dung = arr[i];
            count_Occur_matkhaudung = count_Occurence(arr, num_pwds, arr[i]);
            result = i;
        }
        else if ((count_Occur_matkhaudung == count_Occurence(arr, num_pwds, arr[i])) && (matkhau_dung.length() < arr[i].length()))
        {
                matkhau_dung = arr[i];
                result = i;
        }
    }
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////