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




int check_HP(int HP) {
    if (HP < 0)
        return 0;
    else if (HP > 666)
        return 666;
    else
        return HP;
}

int check_EXP(int EXP) {
    if (EXP > 600)
        return 600;
    else if (EXP < 0)
        return 0;
    else
        return EXP;
}

int check_M(int M) {
    if (M < 0)
        return 0;
    else if (M > 3000)
        return 3000;
    else
        return M;
}





// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int D;//quyet dinh
    double EXP1 = exp1;
    double EXP2 = exp2;
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    if (e1 < 0 || e1>99)
        return -99;
    //TH1
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 29+45+75;
            break;
        }
        D = e1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {  //dung 
            EXP1 = ceil(EXP1 + (double)D / 200);
        }
        else {    //sai
            EXP1 = ceil(EXP1 - (double)D / 100);
         
        }
    }
   //TH2
    else {
        if (e1 <= 19) {//tt1
            EXP2 += ceil((double)e1 / 4 + 19);
        }
        else if (e1 <= 49) {//tt2
            EXP2 += ceil((double)e1 / 9 + 21);

        }
        else if (e1 <= 65) {//tt3
            EXP2 += ceil((double)e1 / 16 + 17);
        }
        else if (e1 <= 79) {
            EXP2 += ceil((double)e1 / 4 + 19);
            if (EXP2 > 200) {
                EXP2 +=ceil( (double)e1 / 9 + 21);
            }
        }
        else {
            EXP2 += ceil((double)e1 / 4 + 19);
            EXP2 += ceil((double)e1 / 9 + 21);
            if (EXP2 > 400) {
                EXP2 += ceil((double)e1 / 16 + 17);
                EXP2 += ceil((double)EXP2 * 15 / 100);
            }
        }
        EXP1 -= e1;
    }
    // ham ceil() dung de lam tron so 
    EXP1 = check_EXP(EXP1);
    EXP2 = check_EXP(EXP2);
    exp1 = EXP1;
    exp2 = EXP2;
    return EXP1 + EXP2;
}

// Task 2
int chinh_phuong(int exp1) {//so chinh phuong gan nhat
    double cp1,cp2;
    cp1 = pow((int)sqrt(exp1), 2);
    cp2 = pow((int)sqrt(exp1)+1, 2);
    if (abs(cp1 - exp1) < abs(cp2 - exp1) ){
        
        return cp1;
    }
    else {
        
        return cp2;
    }
}


double duong1(int exp) {
    long long s;//so chinh phuong gan nhat   
    double p;
    s = chinh_phuong(exp);
    if (exp >= s)
        p = 1;
    else
        p = ((double)exp / s + 80) / 123;
    return p;
}


double duong2_le(int & HP1,int & EXP1,int & M1,int E3) {
    bool hople = false;
    int Mtra = 0;
    int Mdau = M1;
    double p;
    do {
        if (M1 == 0) {
            break;
        }
        //an uong
        if (HP1 < 200) {
            HP1 += ceil((double)HP1 * 30 / 100);
            M1 -= 150;
            Mtra += 150;
        }//2.6 ->3
        else {
            HP1 += ceil((double)HP1 * 10 / 100);
            M1 -= 70;
            Mtra += 70;
        }
        M1 = check_M(M1);
        HP1 = check_HP(HP1);
        if (Mtra * 2 > Mdau) {// >50%
            break;
        }
        //thue xe
        if (EXP1 < 400) {//di taxi
            M1 -= 200;
            Mtra += 200;
        }
        else {
            M1 -= 120;
            Mtra += 120;
        }
        M1 = check_M(M1);
        EXP1 = ceil((double)EXP1 * 113 / 100);
        EXP1 = check_EXP(EXP1);
        if (Mtra * 2 > Mdau) {// >50%
            break;
        }
        // gap nguoi vo gia cu
        if (EXP1 < 300) {
            M1 -= 100;
            Mtra += 100;
        }
        else {
            M1 -= 120;
            Mtra += 120;
        }
        M1 = check_M(M1);
        EXP1 = ceil((double)EXP1 * 90 / 100);
        if (Mtra * 2 > Mdau) {// >50%
            break;
        }
        
    } while (true);
    HP1 = ceil((double)HP1 * 83 / 100);
    EXP1 = ceil((double)EXP1 * 117 / 100);
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    
    return duong1(EXP1);
   
}

double duong2_chan(int& HP1, int& EXP1, int& M1, int E3) {
    bool hople = true;
    int Mtra = 0;
    int Mdau = M1;
    
    while (hople) {
        //an uong
        if (M1 == 0) {
            break;
        }
        if (HP1 < 200) {
            HP1 += ceil((double)HP1 * 30 / 100);
            M1 -= 150;
            Mtra += 150;
        }
        else {
            HP1 += ceil((double)HP1 * 10 / 100);
            M1 -= 70;
            Mtra += 70;
        }
        M1 = check_M(M1);
        HP1 = check_HP(HP1);
        if (M1 == 0) {//het tien
            hople = false;
        }
        //thue xe
        if (hople) {
            if (EXP1 < 400) {//di taxi
                M1 -= 200;
                Mtra += 200;
            }
            else {
                M1 -= 120;
                Mtra += 120;
            }
            M1 = check_M(M1);
            EXP1 += ceil((double)EXP1 * 13 / 100);
            EXP1 = check_EXP(EXP1);
        }
        if (M1==0) {
            hople = false;
        }
        // gap nguoi vo gia cu
        if (hople) {
            if (EXP1 < 300) {
                M1 -= 100;
                Mtra += 100;
            }
            else {
                M1 -= 120;
                Mtra += 120;
            }
            M1 = check_M(M1);
            EXP1 = ceil((double)EXP1 * 90 / 100);
        }
        
        hople = false;

    }
    
    HP1 = ceil((double)HP1 * 83 / 100);
    EXP1 = ceil((double)EXP1 * 117 / 100);
    EXP1 = check_EXP(EXP1);
    return duong1(EXP1);
}

double duong3(int E3) {
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = 0;
    if (E3 < 10)
        return (double)P[E3]/100;
    else {
        i = E3 / 10 + E3 % 10;
        i = i % 10;
        return (double)P[i]/100;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
    double xacsuat1, xacsuat2, xacsuat3, xacsuatcuoi;
    bool hople = false;
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    M1 = check_M(M1);
    if (E3 < 0 || E3>99)
        return -99;
    xacsuat1 = duong1(EXP1);
    if (E3 % 2 == 1)
        xacsuat2 = duong2_le(HP1, EXP1, M1, E3);
    else
        xacsuat2 = duong2_chan(HP1, EXP1, M1, E3);
    xacsuat3 = duong3(E3);
    if ((xacsuat1 + xacsuat2 + xacsuat3) / 3 == 1) {
        EXP1 = ceil((double)EXP1 * 75 / 100);
        EXP1 = check_EXP(EXP1);
        return HP1 + EXP1 + M1;
    }
   
    xacsuatcuoi = (xacsuat1 + xacsuat2 + xacsuat3) / 3;
    if (xacsuatcuoi * 100 < 50) {
        HP1 = ceil((double)HP1 * 85 / 100);
        EXP1 = ceil((double)EXP1 * 115 / 100);
        
    }
    else
    {
        HP1 = ceil((double)HP1 * 90 / 100);
        EXP1 = ceil((double)EXP1 * 120 / 100);

    }
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);


    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3>99)
        return -99;
    // TODO: Complete this function
    int a=0, b=0;// (a,b) vi tri gap nhau
    int I1, I2, J1, J2;
    int T[10][10], S[10][10];
    //tao ma tran
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
           T[i][j] = 0;
           S[i][j] = 0;
        }
    }
    //Taxi
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            T[i][j] = (E3 * j + i * 2) * (i - j);
        }
    }
    
    //Sherlock 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bool hople = true;
            I1 = I2 = i; J1 = J2 = j;

            while (hople) {//tu 1 diem toa theo 4 huong
                if (I1 >= 0 && J1 >= 0) {
                    if(S[i][j] < T[I1][J1])
                        S[i][j] = T[I1][J1];

                }
                if (I1 >= 0 && J2 < 10) {
                    if(S[i][j] < T[I1][J2])
                        S[i][j] = T[I1][J2];
                }
                if (I2 < 10 && J1 >= 0) {
                    if(S[i][j] < T[I2][J1])
                        S[i][j] = T[I2][J1];

                }
                if (I2 < 10 && J2 < 10) {
                    if(S[i][j] < T[I2][J2])
                        S[i][j] = T[I2][J2];
                }
                I1--; I2++; J2++; J1--;
                if (I1 < 0 && I2>9 && J1 < 0 && J2>9)//dieu kien dung
                    hople = false;
            }


        }
    }
    
    // coi sherlock >0 chua
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            S[i][j] = abs(S[i][j]);
        }
    }
    //tim diem gap nhau
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (T[i][j] > (E3 * 2)) {
                a++;
            }
            if (T[i][j] < (-E3)) {
                b++;
            }
        }
    }
    //check xem con 1 chu so chua
    while (a >= 10) {
        a = a / 10 + a % 10;
    }
    while (b >= 10) {
        b = b / 10 + b % 10;
    }
    //gap nhau
    if (abs(T[a][b]) <=S[a][b]) {// kip
        HP1 = ceil((double)HP1 * 110/100);
        EXP1 = ceil((double)EXP1 * 112/100);
        HP2 = ceil((double)HP2 * 110/100);
        EXP2 = ceil((double)EXP2 * 112/100);
        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);
        HP2 = check_HP(HP2);
        EXP2 = check_EXP(EXP2);

        return S[a][b];
    }
    else {//ko kip
        EXP1 = ceil((double)EXP1 * 88/100);
        HP1 = ceil((double)HP1 * 90/100);
        EXP2 = ceil((double)EXP2 * 88/100);
        HP2 = ceil((double)HP2 * 90/100);
        HP1 = check_HP(HP1);
        EXP1 = check_EXP(EXP1);
        HP2 = check_HP(HP2);
        EXP2 = check_EXP(EXP2);
        return T[a][b];
    }
    return -1;
}

// Task 4
string check_se(string a) {// loc se tu email
    string se;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '@') {
            break;
        }
        se += a[i];
    }
    return se;
}

int mk_hople(string mk) {

    char kytuhople[] = { 'a','b','c','d','e','f','g','h', 'i','j','k','l', 'm','n','o','p', 'q','r','s','t', 'u','v','w','x','y','z',
                        'A','B','C','D','E','F','G','H', 'I','J','K','L', 'M','N','O','P', 'Q','R','S','T', 'U','V','W','X','Y','Z',
                        '0','1','2','3','4','5','6','7', '8','9','@','#', '%','$','!' };

    for (int i = 0; i < mk.length(); i++) {// dk2
        bool trung = false;
        for (int j = 0; j < 67; j++) {
            if ((int)mk[i] == (int)kytuhople[j])
                trung = true;
        }
        if (trung == false) {
            return i;
        }
    }

    return -100;
}

int chua_se(string mk, string se) {
    int j;
    int sei = -1000;
    bool trung = false;
    if (se.length() == 0) {
        return -300;
    }
    if (mk.length() < se.length()) {
        return 1;
    }
    for (int i = 0; i < mk.length(); i++) {//213 sdafsafaf
        j = i;
        if (trung) {//neu da trung thi thoat vong lap tranh trung lan 2
            break;
        }
        while ((int)mk[j] == (int)se[j - i]) {//trung 
            j++;
            if (j - i == se.length()) {
                sei = i;
                trung = true;
                break;
            }
            if ((int)mk[j] != (int)se[j - i]) {// khac
                break;
            }
        }
    }
    return -(300+sei);
}

int kytu_lientiep(string mk) {
    int j, sci = -1000;
    bool trung = false;
    for (int i = 0; i < mk.length() - 2; i++) {
        j = i;
        int a = 1;
        if (trung) {
            break;
        }
        while ((int)mk[j] == (int)mk[j + 1]) {
            a++;
            j++;
            if (a == 3) {// trung 3 lan tro len
                sci = i;
                trung = true;
                break;
            }
        }
    }
    return -(400 + sci);
}

int kytu_dacbiet(string mk) {
    bool trung = false;
    char ktdb[] = { '@','#','%','$','!' };
    for (int i = 0; i < mk.length(); i++) {
        for (int j = 0; j < 5; j++) {
            if (mk[i] == ktdb[j]) {
                trung = true;
            }
        }
    }
    if (!trung)//ko trung
        return -5;
    else
        return 0;//
}


int checkPassword(const char * s, const char * email) {//s la mat khau
    // TODO: Complete this function
    string se;
    int check;
    string k[1] = { s };
    string h[1] = { email };
    string mk = k[0];
    string em = h[0];
    
    se = check_se(em);
    if (mk.length() < 8) {// dk 1 | yc 1
        return -1;
    }

    if (mk.length() > 20) {// dk 2 | yc 1
        return -2;
    }
    check = chua_se(mk, se);
    if (check <0) {// dk 3 | yc 3 
        return check;
    }
    
    check = kytu_lientiep(mk);
    if (check < 0) {// dk 4 | yc 4
        return check;
    }
   
    check = kytu_dacbiet(mk);
    if (check == -5) {// dk 5 | yc 5
        return check;
    }
    // yc ham
    check = mk_hople(mk);//yc 2
    if (check != -100) {
        return check;
    }
    return -10;// mat khau hop le
    
}


// task 5 
int count(string a[], int num_pwds, string pass) {
    int cnt = 0;
    for (int i = 0; i < num_pwds; i++) {
        if (a[i] == pass) {
            cnt++;
        }
    }

    return cnt;
}


int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string a[100];
    for (int i = 0; i < num_pwds; i++) {
        a[i] = arr_pwds[i];
    }
    int max_length = 0;
    int max_cnt = 0;
    string passhientai;
    string pass_dung ;

    for (int i = 0; i < num_pwds; i++) {
        passhientai = a[i];
        int solanxuathien = count(a, num_pwds, passhientai);
        if (solanxuathien > max_cnt || (solanxuathien == max_cnt && passhientai.length() > max_length)) {
            max_cnt = solanxuathien;
            max_length = passhientai.length();
            pass_dung = passhientai;
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (a[i] == pass_dung) {
            return i;
        }
    }
    return -1;
}





////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////