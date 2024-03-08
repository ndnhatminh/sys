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

// Task 1

int checkinput(int n, int a, int b)
{
    int x;
    if (n >= a && n <= b)
    {
        x = n;
    }
    else if (n < a)
    {
        x = a;
    }
    else
    {
        x = b;
    }
    return x;
}
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 > 99 || e1 < 0)
        return -99;
    exp1 = checkinput(exp1, 0, 600);
    exp2 = checkinput(exp2, 0, 600);
    if (e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 = exp2 + 29;
              exp2 = checkinput(exp2, 0, 600);
            break;
        case 1:
            exp2 = exp2 + 45;
              exp2 = checkinput(exp2, 0, 600);
            break;
        case 2:
            exp2 = exp2 + 75;
              exp2 = checkinput(exp2, 0, 600);
            break;
        case 3:
            exp2 = exp2 + 149;
              exp2 = checkinput(exp2, 0, 600);
            break;
        }
        int D;
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 = exp1 + D / 200.0+0.999;
        }
        else
        {
            exp1 = exp1 - D / 100.0+0.999;
             
        }

    exp1 = checkinput(exp1, 0, 600);
    }
    else
    {
        if (e1 >= 4 && e1 <= 19)
        {
            exp2 =(int )( exp2 + e1 /4.0 + 19+0.999);
        }
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2 = (int )( exp2 + e1 / 9.0 + 21+0.999);
        }
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2 = (int )( exp2 + e1 / 16.0 + 17+0.999);
        }
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2 = (int )( exp2 + e1 / 4.0 + 19+0.999);
            if (exp2 > 200)
            {
                exp2 = (int )( exp2 + e1 / 9.0 + 21+0.999);
            }
        }
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2 = (int )( exp2 + e1 / 4.0 + 19+0.999);
            exp2 = (int )( exp2 + e1 / 9.0 + 21+0.999);
            if (exp2 > 400)
            {
                exp2 = (int )( exp2 + e1 / 16.0 + 17+0.999);
                exp2 = (int )( exp2 * 1.15+0.999);

            }
        }
        exp1 = exp1 - e1;
        exp1 = checkinput(exp1, 0, 600);
         exp2 = checkinput(exp2, 0, 600);
    }


    return exp1 + exp2;
}

// Task 2

bool cp(int n) {
    int a = 0;
    while (a * a <= n) {
        if (a * a == n) {
            return true;
        }
        a++;
    }
    return false;
}

int scp(int n) {
    int a = n - 1;
    int b = n + 1;
    while (1) {
        if (cp(a)) {
            return a;
        }
        else if (cp(b)) {
            return b;
        }
        a--;
        b++;
    }
}


int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    EXP1 = checkinput(EXP1, 0, 600);
    HP1 = checkinput(HP1, 0, 666);
    M1 = checkinput(M1, 0, 3000);
    //Tinh p1
    int S1;
    int M = M1;
    S1 = scp(EXP1);
    double P1;
    if (S1 <= EXP1)
        P1 = 1;
    else
        P1 = (1.0*EXP1 / S1 + 80) / 123.0;
    int CHI = 0;
    if (E2 % 2 != 0)
    {
        while (CHI <= 0.5 * M)
        {
            if (CHI <= 0.5 * M)
            {
                if (HP1 < 200)
                {
                    HP1 = (int)(1.3 * HP1 + 0.99);
                    M1 = M1 - 150;
                    CHI = CHI + 150;
                    EXP1 = checkinput(EXP1, 0, 600);
                    HP1 = checkinput(HP1, 0, 666);
                    M1 = checkinput(M1, 0, 3000);
                }
                else {
                    HP1 = (int)(1.1 * HP1 + 0.99);
                    M1 = M1 - 70;
                    CHI = CHI + 70;
                    EXP1 = checkinput(EXP1, 0, 600);
                    HP1 = checkinput(HP1, 0, 666);
                    M1 = checkinput(M1, 0, 3000);

                }
            }
            if (CHI <= 0.5 * M)
            {
                if (EXP1 < 400)
                {
                    EXP1 = (int)(1.13 * EXP1 + 0.999);
                    M1 = M1 - 200;
                    CHI = CHI + 200;
                    EXP1 = checkinput(EXP1, 0, 600);
                    HP1 = checkinput(HP1, 0, 666);
                    M1 = checkinput(M1, 0, 3000);
                }
                else {
                    EXP1 = (int)(1.13 * EXP1 + 0.999);
                    M1 = M1 - 120;
                    CHI = CHI + 120;
                    EXP1 = checkinput(EXP1, 0, 600);
                    HP1 = checkinput(HP1, 0, 666);
                    M1 = checkinput(M1, 0, 3000);
                }
            }
            if (CHI < 0.5 * M)
            {
                if (EXP1 < 300)
                {
                    EXP1 = (int)(0.9 * EXP1 + 0.999);
                    M1 = M1 - 100;
                    CHI = CHI + 100;
                    EXP1 = checkinput(EXP1, 0, 600);
                    HP1 = checkinput(HP1, 0, 666);
                    M1 = checkinput(M1, 0, 3000);
                }
                else {
                    EXP1 = (int)(0.9 * EXP1 + 0.999);
                    M1 = M1 - 120;
                    CHI = CHI + 120;
                    EXP1 = checkinput(EXP1, 0, 600);
                    HP1 = checkinput(HP1, 0, 666);
                    M1 = checkinput(M1, 0, 3000);
                }
            }
        }
    }
    else{
        if (M1 != 0)
        {
            if (HP1 < 200)
            {
                HP1 = (int)(1.3 * HP1 + 0.999);
                M1 = M1 - 150;
                EXP1 = checkinput(EXP1, 0, 600);
                HP1 = checkinput(HP1, 0, 666);
                M1 = checkinput(M1, 0, 3000);
            }
            else {
                HP1 = (int)(1.1 * HP1 + 0.999);
                M1 = M1 - 70;
                EXP1 = checkinput(EXP1, 0, 600);
                HP1 = checkinput(HP1, 0, 666);
                M1 = checkinput(M1, 0, 3000);
            }
        }
        if (M1 != 0)
        {
            if (EXP1 < 400)
            {
                EXP1 = (int)(1.13 * EXP1+0.999);
                M1 = M1 - 200;
                EXP1 = checkinput(EXP1, 0, 600);
                HP1 = checkinput(HP1, 0, 666);
                M1 = checkinput(M1, 0, 3000);
            }
            else {
                EXP1 = (int)(1.13 * EXP1+0.999);
                M1 = M1 - 120;
                EXP1 = checkinput(EXP1, 0, 600);
                HP1 = checkinput(HP1, 0, 666);
                M1 = checkinput(M1, 0, 3000);
            }
        }
        if (M1 != 0)
        {
            if (EXP1 < 300)
            {
                EXP1 = (int)(0.9 * EXP1 + 0.99);
                M1 = M1 - 100;
                EXP1 = checkinput(EXP1, 0, 600);
                HP1 = checkinput(HP1, 0, 666);
                M1 = checkinput(M1, 0, 3000);
            }
            else {
                EXP1 = (int)(0.9 * EXP1 + 0.99);
                M1 = M1 - 120;
                EXP1 = checkinput(EXP1, 0, 600);
                HP1 = checkinput(HP1, 0, 666);
                M1 = checkinput(M1, 0, 3000);
            }
        }
    }
    HP1 = (int)(0.83 * HP1 + 0.99);
    EXP1 = (int)(1.17 * EXP1 + 0.999);
    EXP1 = checkinput(EXP1, 0, 600);
    HP1 = checkinput(HP1, 0, 666);
    M1 = checkinput(M1, 0, 3000);

    int S2;
    S2 = scp(EXP1);
    double P2;
    if (S2 <= EXP1)
        P2 = 1.0;
    else
        P2 = (1.0*EXP1 / S2 + 80) / 123.0;
    int i = 0;
    if (E2 < 10)
        i = E2;
    else
    {
        int donvi = E2 % 10;
        int chuc = E2 /10;
        i = donvi + chuc;
        if (i > 9)
            i = i % 10;
    }
    int P[10] = { 32,47,28,79,100,50,22,83,64,11 };
    double P3, PTB;
    P3 = P[i] / 100.0;
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0)
    {
        EXP1 = 0.75 * EXP1 + 0.99;
        EXP1 = checkinput(EXP1, 0, 600);
    }
    else
    {
        PTB = 1.0*(P1 + P2 + P3) / 3;
        if (PTB < 0.5)
        {
            HP1 = int(0.85 * HP1 + 0.99);
            EXP1 = int(1.15 * EXP1 + 0.99);
            EXP1 = checkinput(EXP1, 0, 600);
            HP1 = checkinput(HP1, 0, 666);
        }
        else {
            HP1 = int (0.9 * HP1 + 0.99);
            EXP1 = int (1.2 * EXP1 + 0.99);
            EXP1 = checkinput(EXP1, 0, 600);
            HP1 = checkinput(HP1, 0, 666);

        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int tongso(int a)
{
    if (a >=10)
    {
        int dv1, hc1;
        dv1 = a % 10;
        hc1 = a / 10;
        if (dv1 + hc1 > 9)
        {
        return (dv1+hc1)/10 + (dv1+ hc1)%10;
        }
        else
       {return (dv1+ hc1);}
    }
    return a;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function

    if (E3 > 99 || E3 < 0)
        return -99;
    EXP1 = checkinput(EXP1, 0, 600);
    EXP2 = checkinput(EXP2, 0, 600);
    HP1 = checkinput(HP1, 0, 666);
    HP2 = checkinput(HP2, 0, 666);

    int taxi[10][10];
    long long thamtu = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    int dem1 = 0, dem2 = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (taxi[i][j] > E3 * 2)
                dem1 = dem1 + 1;
            if (taxi[i][j] < -E3)
                dem2 = dem2 + 1;
        }
    }
    dem1 = tongso(dem1);
    dem2 = tongso(dem2);
    long long ta = taxi[dem1][dem2];
    if ((dem1 - dem2) <= 0) {
        for (int i = 0; i <= 9 - (dem2 - dem1); i++) {
            if (thamtu < taxi[i][i + dem1 - dem2]) thamtu = taxi[i][i + dem1 - dem2];
        }
    }
    else {
        for (int i = 0; i <= 9-(dem1 - dem2); i++) {
            if (thamtu < taxi[i + dem1 - dem2][i]) thamtu = taxi[i + dem1 - dem2][i];
        }
    }
    if ((dem1+ dem2) <= 9) {
        for (int i = 0; i <= (dem1 + dem2); i++) {
            if (thamtu < taxi[i][dem1 + dem2 - i]) thamtu = taxi[i][dem1 + dem2 - i];
        }
    }
    else {
        for (int i = (dem1 + dem2)-9; i<=9; i++) {
            if (thamtu < taxi[i][dem1 + dem2 - i]) thamtu = taxi[i][dem1 + dem2 - i];
        }
    }
    int k = ta; if(ta<0) k = -ta;
    if (k > thamtu)
    {

        EXP1 = (int)(EXP1 * 0.88 + 0.99);
        HP1 = (int)(HP1 * 0.9 + 0.99);
        EXP2 = (int)(EXP2 * 0.88 + 0.99);
        HP2 = (int)(HP2 * 0.9 + 0.99);
        EXP1 = checkinput(EXP1, 0, 600);
        EXP2 = checkinput(EXP2, 0, 600);
        HP1 = checkinput(HP1, 0, 666);
        HP2 = checkinput(HP2, 0, 666);
        return ta;
    }
    else {

        EXP1 = (int)(EXP1 * 1.12 + 0.99);
        HP1 = (int)(HP1 * 1.1 + 0.99);
        EXP2 = (int)(EXP2 * 1.12 + 0.99);
        HP2 = (int)(HP2 * 1.1 + 0.99);
        EXP1 = checkinput(EXP1, 0, 600);
        EXP2 = checkinput(EXP2, 0, 600);
        HP1 = checkinput(HP1, 0, 666);
        HP2 = checkinput(HP2, 0, 666);
        return thamtu;
    }

    return -1;
}
// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    //chuyen s,email sang string
string pw(s);
string em(email);
//substr de cat chuoi, find de tim vi tri xuat hien
string se=em.substr(0,em.find('@'));
    if (pw.length() < 8) {
        return -1;
    }
    if (pw.length() > 20) {
    
        return -2;
    }
    //string::npos la vi tri khong ton tai hoac o rat xa trong bo nho
    if (pw.find(se) != string::npos) {

        return -(300 + pw.find(se));
    }

    for (int i = 0; i < pw.length(); i++) {
        if (pw[i] == pw[i+1] && pw[i] == pw[i+2]) {
        
            return -(400 + i);
        }
    }
 
    // mat khau chua it nhat mot ki tu dac biet
    const char* nhieu= "@#%$!";//khai bao con tro toi chuoi ky tu dac biet
    bool cochuadb = false;//xet xem co chua mot ky tu dac biet
    for (char c : pw) {
        bool ladb = false;//xet xem co phai mot ky tu dac biet
        for (const char* mot = nhieu; *mot != '\0'; mot++)// \0 là ket thuc chuoi
         {
            if (c == *mot) {
                ladb = true;
                break;
            }
        }
        if (ladb) {
            cochuadb = true;
            break;
        }
    }
    if (!cochuadb) {
        return -5;
    }
    
    // kiem tra tung ky tu cua mat khau
    for (int i = 0; i < pw.length(); i++) {
        char c = pw[i];
        if (!isalnum(c)) {
            bool ladb = false;
            for (const char* mot = nhieu; *mot != '\0'; mot++) {
                if (c == *mot) {
                    ladb = true;
                    break;
                }
            }
            if (!ladb) {
                return i;
            }
        }
    }
    
    return -10;
   
    }

    //Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    
    string matkhaudung;
    int nhieunhat = 0;
    int dainhat = 0;
    //mat khau hien tai la cai gi do
    for (int i = 0; i < num_pwds; i++) {
        string matkhauhientai = arr_pwds[i];
        int dem5= 0;

       //so lan xuat hien cua matkhauhientai
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[j] == matkhauhientai) {
                dem5++;
            }
        }

        //xem thu cai nao xuat hien nhieu nhat neu so lan bang nhau thi so sanh chieu dai
        if (dem5 > nhieunhat || (dem5 == nhieunhat && matkhauhientai.length() > dainhat)) {
            nhieunhat = dem5;
           dainhat = matkhauhientai.length();
            matkhaudung = matkhauhientai;
        }
    }

    // vi tri dau tien cua mat khau dung
    for (int i = 0; i < num_pwds; i++) {
        if (arr_pwds[i] == matkhaudung) {
            return i;//co return khong can break vi gap return la tra ve va thoat ra
            break;
        }
    }
    return -1;

}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////