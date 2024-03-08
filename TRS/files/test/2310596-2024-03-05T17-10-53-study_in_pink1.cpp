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
int tinhDoDaiChuoi(const char * chuoi) {
    int doDai = 0;
    while (chuoi[doDai] != '\0') {
        doDai++;
    }
    return doDai;
}


int kiemtra_haichuso(int e)
{
    if (e - 10 < 0) return e;
    else
    {
        int E1 = e / 10;
        int E2 = e % 10;
        int S = E1 + E2;
        return S;
    }
}


int trituyet(int x) {
    if (x < 0)
        return -x;
    return x;
}
int maxnumber(int a, int b) {
    if (a > b)
        return a;
    return b;
}


int roundnumber(double c) { 
    return int(c) + (c > int(c));
}

double sochinhphuong_xacsuat(int k) {

    double t;
    int r, r1, r2;
    r = 0;

    while (r * r <= k)
    {

        r=r+1;
    }
     
     r2 = r * r;
     r1 = (r - 1) * (r - 1);
    if ((k - r1) < (r2 - k)) t = 1; //100%
    else
    {
        t = ((k * 1 / r2) + 80) / 123.0;
    }
    return t;
}

void kiemtra_kinhnghiem(int& c)
{
    if ( c < 0 ) c = 0;
    if (c > 600) c = 600;
    
}
void kiemtra_tien(int& s)
{
    if (s < 0) s = 0;
    if (s > 3000) s = 3000;
    
}

void kiemtra_mau(int& l)
{
    if (l < 0) l = 0;
    if (l > 666) l = 666;
    
}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    kiemtra_kinhnghiem(EXP1);
    kiemtra_kinhnghiem(EXP2);
    if (E1 >= 0 && E1 <= 3) 
    {
        int D;
        D = E1 * 3 + EXP1 * 7;

        if (E1 == 0) EXP2 = EXP2 + 29;
        else if (E1 == 1) EXP2 = EXP2 + 45;
        else if (E1 == 2) EXP2 = EXP2 + 75;
        else if (E1 == 3) EXP2 = EXP2 + 29 + 45 + 75;
        kiemtra_kinhnghiem(EXP2);
        
        if (D % 2 == 0)
        {
            EXP1 = roundnumber(EXP1 + (D / 200));
            
        }
        else 
        {
            EXP1 = roundnumber(EXP1 - roundnumber(D / 100));
            
        }
    }
    else if (E1 >= 4 && E1 <= 99) 
    {
        if (E1 <= 19) EXP2 = EXP2 + roundnumber(E1 / 4.0 + 19);
        else if (E1 >= 20 && E1 <= 49) 
            EXP2 = EXP2 + roundnumber(E1 / 9.0 + 21); 

        else if (E1 >= 50 && E1 <= 65)  EXP2 = EXP2 + roundnumber(E1 /16.0 + 17);
        else if (E1 >= 66 && E1 <= 79)
        {
            EXP2 = EXP2 + roundnumber(E1 / 4.0 + 19);
            kiemtra_kinhnghiem(EXP2);
            if (EXP2 > 200)  EXP2 = EXP2 + roundnumber(E1 / 9.0 + 21);
            kiemtra_kinhnghiem(EXP2);
        }
        else if (E1 >= 80 && E1 <= 99)
        {
            EXP2 = EXP2 + roundnumber(E1 /4.0 + 19);
            EXP2 = EXP2 + roundnumber(E1 / 9.0 + 21);
            kiemtra_kinhnghiem(EXP2);
            if (EXP2 > 400)
            {
                EXP2 = EXP2 + roundnumber(E1 / 16.0 + 17);
                
                EXP2 = roundnumber(EXP2 * 115/100.0);
                kiemtra_kinhnghiem(EXP2);
                
            }
        }
        EXP1 = EXP1 - E1;
        kiemtra_kinhnghiem(EXP1);
    }
    else return -99; 
    kiemtra_kinhnghiem(EXP2);
    kiemtra_kinhnghiem(EXP1);
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    kiemtra_kinhnghiem(EXP1);
    kiemtra_tien(M1);
    kiemtra_mau(HP1);

    if (E2 > 99 || E2 < 0)
        return -99;
    double o = M1 * 0.5;
    //truong hop P1
    double P1;
    P1 = sochinhphuong_xacsuat(EXP1);



    //Tim P2
    if (E2 % 2 == 0) //TH1 cua P2
    {
        if (HP1 < 200)
        {
            HP1 = roundnumber(HP1 * 130/100.0);
            M1 = M1 - 150;
            kiemtra_mau(HP1);


        }
        else
        {
            HP1 = roundnumber(HP1 * 110/100.0);
            M1 = M1 - 70;
            kiemtra_mau(HP1);


        }
        if (M1 < 0)
        {
            M1 = 0;
        }
        else if (EXP1 < 400)
        {
            M1 = M1 - 200;
            EXP1 = roundnumber(EXP1 * 113/100.0);
            kiemtra_kinhnghiem(EXP1);


        }
        else {
            M1 = M1 - 120;
            EXP1 = roundnumber(EXP1 * 113/100.0);
            kiemtra_kinhnghiem(EXP1);


        }
        if (M1 < 0)
        {
            M1 = 0;
        }
        else if (EXP1 < 300)
        {
            M1 = M1 - 100;
            EXP1 = roundnumber(EXP1 * 90/100.0);
            kiemtra_kinhnghiem(EXP1);
        }
        else
        {
            M1 = M1 - 120;
            EXP1 = roundnumber(EXP1 * 90/100.0);
            kiemtra_kinhnghiem(EXP1);
        }
    }

    else // TH2 cua P2 
    {
        while (M1 >= o)
        {
            if (HP1 < 200)
            {
                HP1 = roundnumber(HP1 * 130/100.0);
                M1 = M1 - 150;
                kiemtra_mau(HP1);


            }
            else
            {
                HP1 = roundnumber(HP1 * 110/100.0);
                M1 = M1 - 70;
                kiemtra_mau(HP1);


            }
            if (M1 < o) break;
            else if (EXP1 < 400)
            {
                M1 = M1 - 200;
                EXP1 = roundnumber(EXP1 * 113/100.0);
                kiemtra_kinhnghiem(EXP1);


            }
            else {
                M1 = M1 - 120;
                EXP1 = roundnumber(EXP1 * 113/100.0);
                kiemtra_kinhnghiem(EXP1);


            }
            if (M1 < o) break;
            else if (EXP1 < 300)
            {
                M1 = M1 - 100;
                EXP1 = roundnumber(EXP1 * 90/100.0);
                kiemtra_kinhnghiem(EXP1);
            }
            else
            {
                M1 = M1 - 120;
                EXP1 = roundnumber(EXP1 * 90/100.0);
                kiemtra_kinhnghiem(EXP1);
            }
        }
    }
    EXP1 = roundnumber(EXP1 * 1.17);
    HP1 = roundnumber(HP1 * 0.83);
    kiemtra_kinhnghiem(EXP1);
    kiemtra_mau(HP1);


    double P2 = sochinhphuong_xacsuat(EXP1);

    //Tim P3
    double d[10] = { 0.32,0.47,0.28,0.79,1,0.5,0.22,0.83,0.64,0.11 };
    double P3;
    int i;
    if (E2 - 10 < 0) i = E2;
    else {
        i = (E2 / 10 + (E2 % 10));
        i = i % 10;
    }

    P3 = d[i];



    double trungbinh;
    if (P1 == 1 && P2 == 1 && P3 == 1)
    {
        EXP1 = roundnumber(EXP1 * 75/100.0);

    }
    else {
        trungbinh = (P1 + P2 + P3) / 3;
        if (trungbinh < 0.5)
        {
            HP1 = roundnumber(HP1 * 85/100.0);
            EXP1 = roundnumber(EXP1 * 115/100.0);
        }
        else
        {
            HP1 = roundnumber(HP1 * 90/100.0);
            EXP1 = roundnumber(EXP1 * 120/100.0);
        }
    }
    kiemtra_kinhnghiem(EXP1);
    
    kiemtra_mau(HP1);
    kiemtra_tien(M1);
    
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int taxi[10][10];
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // Tính điểm cho ma trận Sherlock và Watson
    int swaston[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int max_duongcheo = 0;
            for (int k = 0; k < 10; k++) {
                //Đường chéo trái
                if (0 <= i - k && i - k < 10 && 0 <= j - k && j - k < 10) {
                    max_duongcheo = maxnumber(max_duongcheo, taxi[i - k][j - k]);
                }
                // Đường chéo phải
                if (0 <= i + k && i + k < 10 && 0 <= j + k && j + k < 10) {
                    max_duongcheo = maxnumber(max_duongcheo, taxi[i + k][j + k]);
                }
                // Đường chéo trên
                if (0 <= i - k && i - k < 10 && 0 <= j + k && j + k < 10) {
                    max_duongcheo = maxnumber(max_duongcheo, taxi[i - k][j + k]);
                }
                // Đường chéo dưới
                if (0 <= i + k && i + k < 10 && 0 <= j - k && j - k < 10) {
                    max_duongcheo = maxnumber(max_duongcheo, taxi[i + k][j - k]);
                }
            }
            swaston[i][j] = trituyet(max_duongcheo);
        }
    }
    // Kiem tra i1, j1

    int i1, j1, j2, i2;
    j1 = 0;
    j2 = 0;
    i1 = 0;
    i2 = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            if (taxi[i][j] > E3 * 2) i1 = i1 + 1;
            if (taxi[i][j] < (-1) * E3) j1 = j1 + 1;


        }
    }

    i2 = kiemtra_haichuso(i1);
    j2 = kiemtra_haichuso(j1);
    i2 = kiemtra_haichuso(i2);
    j2 = kiemtra_haichuso(j2);
    // Tìm vị trí gặp nhau so sánh điểm số và cập nhật EXP và HP
    //cout<<i2<<" "<<j2;

    if (E3 >= 0 && E3 <= 99)
    {
        if (trituyet(taxi[i2][j2]) > trituyet(swaston[i2][j2]))
        {
            EXP2 = roundnumber(EXP2 * 88/100.0);
            EXP1 = roundnumber(EXP1 * 88/100.0);



            HP1 = roundnumber(HP1 * 90/100.0);

            HP2 = roundnumber(HP2 * 90/100.0);
            kiemtra_kinhnghiem(EXP1);
            kiemtra_kinhnghiem(EXP2);
            kiemtra_mau(HP1);
            kiemtra_mau(HP2);

            return taxi[i2][j2];
        }
        else {
            EXP1 = roundnumber(EXP1 * 112/100.0);

            EXP2 = roundnumber(EXP2 * 112 / 100.0);
            HP2 = roundnumber(HP2 * 110/100.0);
            HP1 = roundnumber(HP1 * 110/100.0);
            kiemtra_kinhnghiem(EXP1);
            kiemtra_kinhnghiem(EXP2);
            kiemtra_mau(HP1);
            kiemtra_mau(HP2);

            return swaston[i2][j2];


        }
        
    }
    else return -99;
    kiemtra_kinhnghiem(EXP1);
    kiemtra_kinhnghiem(EXP2);
    kiemtra_mau(HP1);
    kiemtra_mau(HP2);
    
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int viTriSe = 0;
    while (email[viTriSe] != '@') {
        viTriSe++;
    }

    char se[viTriSe + 1];
    for (int i = 0; i < viTriSe; i++) {
        se[i] = email[i];
    }
    se[viTriSe] = '\0';

    int doDai = tinhDoDaiChuoi(s);

    int soKiTuDacBiet = 0;
    const char kiTuDacBiet[] = "@#%$!";
    for (int i = 0; i < doDai; i++) {
        for (int j = 0; j < sizeof(kiTuDacBiet); j++) {
            if (s[i] == kiTuDacBiet[j]) {
                soKiTuDacBiet++;
                break;
            }
        }
    }

    if (doDai < 8) return -1;
    if (doDai > 20) return -2;
    if (doDai >= 8 && doDai <= 20)
    {
        
        if (viTriSe == 0) return -300;


        else if (viTriSe != 0)
        {
            for (int i = 0; i < doDai - (viTriSe - 1); i++) {
                if (strncmp(&s[i], se, viTriSe) == 0)
                {
                    return -(300 + i);
                    break;
                }
            }
        }
        
            for (int i = 0; i < doDai - 2; i++) {
                if (s[i + 1] == s[i] && s[i + 2] == s[i])
                {
                    return -(400 + i);
                }
            }
        

        if (soKiTuDacBiet == 0) return -5;
        else if (soKiTuDacBiet != 0)
        {
            for (int i = 0; i < doDai; i++) {
                if (!(isalnum(s[i]) || s[i] == ' ' || strchr(kiTuDacBiet, s[i])))
                {
                    return i;
                }
            }
        }
    }
     return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string b[30];
    string now;
    int a[30] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }, i, k;

    // Dem so lan xuat hien cua tung thanh phan trong mang
    for (i = 0; i < num_pwds; i++) {
        for (k = 1; k < num_pwds; k++) {
            if (i == 0) {
                if (strcmp(arr_pwds[i], arr_pwds[i + k]) == 0) a[0] = a[0] + 1;
            }
            else if (i == (num_pwds - 1)) {
                if (strcmp(arr_pwds[i], arr_pwds[i - k]) == 0) a[num_pwds - 1] = a[num_pwds - 1] + 1;
            }
            else if (i != 0 && i != (num_pwds - 1)) {
                if (i + k < num_pwds && strcmp(arr_pwds[i], arr_pwds[i + k]) == 0) {
                    a[i] = a[i] + 1;
                }
                if (i - k >= 0 && strcmp(arr_pwds[i], arr_pwds[i - k]) == 0) {
                    a[i] = a[i] + 1;
                }
            }
        }
    }

    int max = 0;
    for (i = 0; i < num_pwds; i++) {
        if (a[i] > max) max = a[i];
    }

    int s = 0;
    k = 0;
    int c = 0; // b[c] mang cua nhung chuoi co so lan xuat hien >= max
    for (i = 0; i < num_pwds; i++) {
        if (a[i] == max) {
            b[k] = arr_pwds[i];
            k++;
        }
    }

    for (c = 0; c < k - 1; c++) {
        if (b[c].length() > b[c + 1].length()) now = b[c];
        else now = b[c + 1];
    }

    for (i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], now.c_str()) == 0) {
            s = i;
            break;
        }
    }

    return s;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////