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
void kiemtradieukientask1(int &a, int &b) 
{
    // Kiem tra dieu kien cua EXP1
    if (a < 0) a = 0;
    if (a > 600) a = 600;
    // Kiem tra dieu kien cua EXP2
    if (b < 0) b = 0;
    if (b > 600) b = 600;
}
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // Truong hop 1
    if (e1 >= 0 && e1 <= 3) 
    {
        // Thong tin 1
        if (e1 ==0) exp2 = exp2 + 29;
        // Thong tin 2
        if (e1 ==1) exp2 = exp2 + 45;
        // Thong tin 3
        if (e1 ==2) exp2 = exp2 + 75;
        // Giai thich ca 3 thong tin
        if (e1 ==3) exp2 = exp2 + (29 + 45 + 75);
        kiemtradieukientask1(exp1, exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) 
        {
            // Nghieng ve Afghanistan
            exp1 = ceil(exp1 + D / 200.0);
            kiemtradieukientask1(exp1, exp2);
        }
        else 
        {
            // Nghieng ve Iraq
            exp1 = ceil(exp1 - D / 100.0); 
            kiemtradieukientask1(exp1, exp2);      
        } 
    }
    // Truong hop 2
    else if (e1 >=4 && e1 <=99) 
    {
        // Bat ngo truoc thong tin Harry la chi gai cua Watson
        exp1 = ceil(exp1 - e1);
        kiemtradieukientask1(exp1, exp2);
        if (e1 >= 4 && e1 <= 19) 
        {
            // Thong tin 1
            exp2 = ceil(exp2 + e1 / 4.0 + 19);
            kiemtradieukientask1(exp1, exp2);
        } 
        else if (e1 >= 20 && e1 <= 49) 
        {
            // Thong tin 2
            exp2 = ceil(exp2 + e1 / 9.0 + 21);
            kiemtradieukientask1(exp1, exp2);
        } 
        else if (e1 >= 50 && e1 <= 65) 
        {
            // Thong tin 3
            exp2 = ceil(exp2 + e1 / 16.0 + 17);
            kiemtradieukientask1(exp1, exp2);
        } 
        else if (e1 >= 66 && e1 <= 79) 
        {
            // Thong tin 4
            exp2 = ceil(exp2 + e1 / 4.0 + 19); // Giai thich thong tin 1
            kiemtradieukientask1(exp1, exp2);
            if (exp2 > 200) 
            {
                exp2 = ceil(exp2 + e1 / 9.0 + 21);// Giai thich thong tin 2
                kiemtradieukientask1(exp1, exp2);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            // Thong tin 5
            exp2 = ceil(exp2 + e1 / 4.0 + 19);// Giai thich thong tin 1
            kiemtradieukientask1(exp1, exp2);
            exp2 = ceil(exp2 + e1 / 9.0 + 21);// Giai thich thong tin 2
            kiemtradieukientask1(exp1, exp2);
            if (exp2 > 400) 
            {
                exp2 = ceil(exp2 + e1 / 16.0 + 17);// Giai thich thong tin 3
                kiemtradieukientask1(exp1, exp2);
                exp2 = ceil(exp2 * 1.15);// Giai thich ca 3 thong tin
                kiemtradieukientask1(exp1, exp2);
            }
    }
    }
    else
    {
        // Gia tri cua E nam ngoai khoang [0,99]
        return -99;
    }

    return exp1 + exp2;
}

// Task 2
void kiemtradieukientask2(int &a, int &b, int &c) 
{
    // Kiem tra dieu kien cua EXP1
    if (a < 0) a = 0;
    if (a > 600) a = 600;
    // Kiem tra dieu kien cua HP1
    if (b < 0) b = 0;
    if (b > 666) b = 666;
    // Kiem tra dieu kien cua M1
    if (c < 0) c = 0;
    if (c > 3000) c = 3000;
}
int timsochinhphuonggannhat(int exp){
    int S;
    // So chinh phuong can tren
    int chinhphuong1 = pow(ceil(sqrt(exp)), 2);
    // So chinh phuong can duoi
    int chinhphuong2 = pow(floor(sqrt(exp)), 2);
    // So sanh voi exp chon so co khoang cach nho nhat
    if (abs(chinhphuong1 - exp) > abs(chinhphuong2 - exp))
    {
        S = chinhphuong2;
    }
    else
    {
        S = chinhphuong1;
    }
    return S;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
if (E2 >= 0 && E2 <= 99)
{
    double result;
    // Khoi tao gia tri xac xuat cua 3 duong
    double P1, P2, P3;
    // Duong 1
    int S1 = timsochinhphuonggannhat(EXP1);
    // Tinh P1
    if (EXP1 >= S1) {
        P1 = 1.0;
    } else {
        P1 = (EXP1 / S1 + 80.0) / 123.0;
    }
    // Duong 2
    double tienbandau = M1;
    int n = 0;
    while ((M1 < tienbandau * 0.5) && (E2 % 2 != 0) || n < 1 ) {
        // Su kien 1
        // Mua thuc an va nuoc uong
        if (HP1 < 200) {
            HP1 = ceil(HP1 * float(1.3));
            M1 = M1 - 150;
            kiemtradieukientask2(EXP1, HP1, M1);
            // Voi E2 le thi lap cac su kien cho toi khi so tien tieu >50% co luc dau, voi E2 chan thi lap 1 lan
            if (((M1 < tienbandau * 0.5) && (E2 % 2 != 0)) || M1 <= 0 )
            {
                HP1 = ceil(HP1 * float(0.83));
                EXP1 = ceil(EXP1 * 1.17);
                kiemtradieukientask2(EXP1, HP1, M1);
                break;
            }
        // Chi mua nuoc uong
        } else {
            HP1 = ceil(HP1 * float(1.1));
            M1 = M1 - 70;
            kiemtradieukientask2(EXP1, HP1, M1);
            if (((M1 < tienbandau * 0.5) && (E2 % 2 != 0)) || M1 <= 0 ) // Thoat vong lap khi khi so tien tieu >50% co luc dau voi E2 le, hoac voi M<=0 voi E2 chan
            {
                HP1 = ceil(HP1 * float(0.83));
                EXP1 = ceil(EXP1 * 1.17);
                kiemtradieukientask2(EXP1, HP1, M1);
                break;
            }
        }

        // Su kien 2
        if (EXP1 < 400) 
        {
            // Di taxi
            M1 = M1 - 200;
            EXP1 = ceil(EXP1 * float(1.13));
            kiemtradieukientask2(EXP1, HP1, M1);
            if (((M1 < tienbandau * 0.5) && (E2 % 2 != 0)) || M1 <= 0 ) // Thoat vong lap khi khi so tien tieu >50% co luc dau voi E2 le, hoac voi M<=0 voi E2 chan
            {
                HP1 = ceil(HP1 * float(0.83));
                EXP1 = ceil(EXP1 * 1.17);
                kiemtradieukientask2(EXP1, HP1, M1);
                break;
            }
        
        } else 
        {
            // Di xe ngua
            M1 = M1 - 120;
            EXP1 = ceil(EXP1 * 1.13);
            kiemtradieukientask2(EXP1, HP1, M1);
            if (((M1 < tienbandau * 0.5) && (E2 % 2 != 0)) || M1 <= 0 ) // Thoat vong lap khi khi so tien tieu >50% co luc dau voi E2 le, hoac voi M<=0 voi E2 chan
            {
                HP1 = ceil(HP1 * float(0.83));
                EXP1 = ceil(EXP1 * 1.17);
                kiemtradieukientask2(EXP1, HP1, M1);
                break;
            }
        }

        // Su kien 3
        int m; // So tien giup do nguoi vo gia cu
        if (EXP1 < 300)
        {
            m = 100; // Giup do nguoi vo gia cu M=100
        }
        else
        {
            m = 120; // Giup do nguoi vo gia cu M=120
        }
        M1 = M1 - m;
        EXP1 = ceil(EXP1 *0.9);
        kiemtradieukientask2(EXP1, HP1, M1);
        if (((M1 < tienbandau * 0.5) && (E2 % 2 != 0)) || M1 <= 0 ) // Thoat vong lap khi khi so tien tieu >50% co luc dau voi E2 le, hoac voi M<=0 voi E2 chan
            {
                HP1 = ceil(HP1 * float(0.83));
                EXP1 = ceil(EXP1 * 1.17);
                kiemtradieukientask2(EXP1, HP1, M1);
                break;
            }

        if (E2 % 2 == 0 ) // voi E2 chan thoat vong lap va cap nhap HP1 va EXP1
        {
            HP1 = ceil(HP1 * float(0.83));
            EXP1 = ceil(EXP1 * 1.17);
            kiemtradieukientask2(EXP1, HP1, M1);
            n++;
        }
    }
    // Tinh P2
    int S2 = timsochinhphuonggannhat(EXP1);
    if (EXP1 >= S2) {
        P2 = 1.0;
    } else {
        P2 = (EXP1 / S2 + 80.0) / 123.0;
    }

    // Duong 3
    int P[10] ={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    // Tinh P3
    if (E2 < 10) 
    {
        // E2 so co 1 chu so
        P3 = P[E2] / 100.0;
    } 
    else 
    {
        // E2 so co 2 chu so
        int sum = E2 / 10 + E2 % 10;
        int i = sum % 10;
        P3 = P[i]/ 100.0;
    }

    // P trung binh =(P1 + P2 + P3)/3
    double xacxuattrungbinh = (P1 + P2 + P3) / 3.0;
// tinh lai HP1, EXP1
    // Tat ca xac xuat cua cac duong deu bang 1
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) 
    {
        EXP1 = ceil(EXP1 * 0.75);
        kiemtradieukientask2(EXP1, HP1, M1);
    } 
    else 
    {
        // P trung binh  < 0.5
        if (xacxuattrungbinh < 0.5) 
        {
            HP1 = ceil(HP1 * float(0.85));
            EXP1 = ceil(EXP1 * 1.15);
            kiemtradieukientask2(EXP1, HP1, M1);
        } 
        // P trung binh >=0.5
        else 
        {
            HP1 = ceil(HP1 * float(0.9));
            EXP1 = ceil(EXP1 * 1.2);
            kiemtradieukientask2(EXP1, HP1, M1);
        }
    }

    result = HP1 + EXP1 + M1;
    return result;
}
else
    return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    if (E3 >= 0 && E3 <= 99)
    {
    // Khoi tao mang 2 chieu 10x10 va nap gia tri cua tung phan tu theo cong thuc ((E3 * j) + (i * 2)) * (i - j) cho diem cua Taxi
    int matrixtaxi[10][10];
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            matrixtaxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    // Xac dinh vi tri gap Taxi
    int i = 0, j = 0;
    for (int r = 0; r < 10; ++r) // Chay qua tat ca cac phan tu cua mang 2 chieu 10x10
    {
        for (int c = 0; c < 10; ++c) 
        {
            // Xac dinh i la so diem co gia tri > E3 * 2
            if (matrixtaxi[r][c] > E3 * 2) {
                ++i;
            }
            // Xac dinh j la so diem co gia tri < -E3
            if (matrixtaxi[r][c] < -E3) {
                ++j;
            }
        }
    }
    // tong chu so cua 2 chu so cho den khi <9 cua i
    while (i >= 10) 
    {
        i = i / 10 + i % 10;
    }
    // tong chu so cua 2 chu so cho den khi <9 cua j
    while (j >= 10) 
    {
        j = j / 10 + j % 10;
    }

    // Vi tri gap nhau r, c
    int r = i;
    int c = j;
    // Khoi tao ma tran diem so cua Sherlochome va Watson khi di chuyen tren ma tran
    int matrixmaxSherlockWatsonPoint[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) 
        {
            int maxSherlockWatsonPoint = matrixtaxi[i][j]; // Khoi tao gia tri ngay tai tam duong cheo
            // duongcheottraidilen
            for (int k = 1; i - k >= 0 && j - k >= 0; ++k) 
            {
                if (matrixtaxi[i - k][j - k] > maxSherlockWatsonPoint) 
                {
                    maxSherlockWatsonPoint = matrixtaxi[i - k][j - k]; // Gan gia tri lon nhat
                }
            }
            // duongcheophaidilen
            for (int k = 1; i - k >= 0 && j + k < 10; ++k) 
            {
                if (matrixtaxi[i - k][j + k] > maxSherlockWatsonPoint) 
                {
                    maxSherlockWatsonPoint = matrixtaxi[i - k][j + k]; // Gan gia tri lon nhat
                }
            }
            // duongcheotraidixuong
            for (int k = 1; i + k < 10 && j - k >= 0; ++k) 
            {
                if (matrixtaxi[i + k][j - k] > maxSherlockWatsonPoint) 
                {
                    maxSherlockWatsonPoint = matrixtaxi[i + k][j - k]; // Gan gia tri lon nhat
                }
            }
            // duongcheophaidixuong
            for (int k = 1; i + k < 10 && j + k < 10; ++k) 
            {
                if (matrixtaxi[i + k][j + k] > maxSherlockWatsonPoint) // Gan gia tri lon nhat
                {
                maxSherlockWatsonPoint = matrixtaxi[i + k][j + k];
                }
            }  
            matrixmaxSherlockWatsonPoint[i][j] = maxSherlockWatsonPoint; // Tra ve gia tri lon nhat gan vao ma tran diem so cua Sherlochome va Watson
        }
}
// Gia tri diem so cua Sherlochome va Watson tai vi tri gap Taxi
int maxSherlockWatsonSkillPoint = abs(matrixmaxSherlockWatsonPoint[r][c]);
// Gia tri diem so cua Taxi
int taxipoint = matrixtaxi[r][c];
int result;
// Duoi khong kip taxi
if (abs(taxipoint) > maxSherlockWatsonSkillPoint) 
{
    result = taxipoint;
    EXP1 = ceil(EXP1 * float(0.88));
    HP1 = ceil(HP1 * float(0.9));
    EXP2 = ceil(EXP2 * float(0.88));
    HP2 = ceil(HP2 * float(0.9));
}
// Duoi kip taxi
else 
{
    result = maxSherlockWatsonSkillPoint;
    EXP1 = ceil(EXP1 * float(1.12));
    HP1 = ceil(HP1 * float(1.1));
    EXP2 = ceil(EXP2 * float(1.12));
    HP2 = ceil(HP2 * float(1.1));
}
// Kiem tra dieu kien ban dau voi cac gia tri exp, hp
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 = 600;
    if (HP2 < 0) HP2 = 0;
    if (HP2 > 666) HP2 = 666;
return result;
}
else
{
  return -99;  
}
}

// Task 4
int checkPassword(const char * s, const char * email) 
{
    // Chuyen ki tu email thanh chuoi
    string chuoimail(email);
    // Loc vi tri truoc dau @ luu vao bien se
    string se = chuoimail.substr(0, chuoimail.find('@'));
    // Chieu dai chuoi mat khau
    int chieudaichuoimk = strlen(s);
    // Kiem tra dieu kien chieu dai mat khau
    if (chieudaichuoimk < 8) return -1;
    if (chieudaichuoimk > 20) return -2;
    // Chuyen ky tu s thanh chuoi
    string chuoimatkhau(s);
    // Tim vi tri cua bien se trong chuoi mat khau
    size_t pos = chuoimatkhau.find(se);
    // Khong tin thay se tra ve string::npos con neu tim thay thi bao loi -(300 + pos)
    if (pos != string::npos) return -(300 + pos);
    // Kiem tra mat khau co bi trung 2 ky tu lien tiep
    for (int i = 0; i < chieudaichuoimk - 2; ++i) 
    {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            return -(400 + i);
        }
    }
    // Kiem tra mat khau phai co cac ky tu dac biet
    int check = 0;
    for (int i = 0; i < chieudaichuoimk; ++i) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            check = 1;
            break;
        }
    }
    if (check == 0) return -5;
    // Tra ve vi tri ky tu khong thoa yeu cau hop le dau tien
    for (int i = 0; i < chieudaichuoimk; ++i) {
        char ch = s[i];
        if (!(isdigit(ch) || isalpha(ch) || ch == '@' || ch == '#' || ch == '%' || ch == '$' || ch == '!')) 
        {
            return i;
        }
    }
    // Mat khau hop le
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) 
{
    // Khoi tao bien so lan xuat hien nhieu nhat cua mat khau
    int max_soluong = 0;
    // Khoi tao bien chieu dai lon nhat cua mat khau
    int max_chieudai = 0;
    // Khoi tao gia tri mat khau so lan xuat hien nhieu nhat va dai nhat
    string mkdung;
    // Su dung vong lap de luu bien mkdung ung voi so lan xuat nhien nhieu nhat va dai nhat
    for (int i = 0; i < num_pwds; ++i) 
    {
        // Khoi tao bien mk cho chay cac phan tu trong array arr_pwds dem so lan xuat hien
        string mk = arr_pwds[i];
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) 
        {
            if (arr_pwds[j] == mk) {
                count++;
            }
        }
        // Gan lai gia tri max_soluong tuong ung voi mat khau xuat hien nhieu nhat va so sanh chieu dai de dat lai gia tri cua max_chieudai cua mat khau tuong ung mk
        if (count > max_soluong || (count == max_soluong && mk.length() > max_chieudai)) 
        {
            max_soluong = count;
            max_chieudai = mk.length();
            // Tra ve gia tri cua mkdung
            mkdung = mk;
        }
    }
    // Tra ve vi tri dau tien cua mat khau dung
    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == mkdung) {
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////